// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/vr/service/vr_service_impl.h"

#include <utility>

#include "base/bind.h"
#include "base/command_line.h"
#include "base/feature_list.h"
#include "base/metrics/histogram_macros.h"
#include "base/stl_util.h"
#include "base/trace_event/common/trace_event_common.h"
#include "chrome/browser/permissions/permission_manager.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/vr/metrics/session_metrics_helper.h"
#include "chrome/browser/vr/mode.h"
#include "chrome/browser/vr/service/browser_xr_runtime.h"
#include "chrome/browser/vr/service/xr_runtime_manager.h"
#include "chrome/common/chrome_switches.h"
#include "components/ukm/content/source_url_recorder.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/browser/render_widget_host.h"
#include "content/public/browser/render_widget_host_view.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/content_features.h"
#include "content/public/common/content_switches.h"
#include "content/public/common/origin_util.h"
#include "device/vr/buildflags/buildflags.h"
#include "device/vr/public/cpp/session_mode.h"
#include "device/vr/vr_device.h"

namespace {

device::mojom::XRRuntimeSessionOptionsPtr GetRuntimeOptions(
    device::mojom::XRSessionOptions* options) {
  device::mojom::XRRuntimeSessionOptionsPtr runtime_options =
      device::mojom::XRRuntimeSessionOptions::New();
  runtime_options->mode = options->mode;
  return runtime_options;
}

vr::XrConsentPromptLevel GetRequiredConsentLevel(
    device::mojom::XRSessionMode mode,
    const vr::BrowserXRRuntime* runtime,
    const std::set<device::mojom::XRSessionFeature>& requested_features) {
  if (base::Contains(
          requested_features,
          device::mojom::XRSessionFeature::REF_SPACE_BOUNDED_FLOOR)) {
    return vr::XrConsentPromptLevel::kVRFloorPlan;
  }

  if (base::Contains(requested_features,
                     device::mojom::XRSessionFeature::HIT_TEST)) {
    return vr::XrConsentPromptLevel::kVRFloorPlan;
  }

  // If the device supports a custom IPD and it will be exposed (via immersive),
  // we need to warn about physical features Being exposed.
  if (runtime->SupportsCustomIPD() &&
      device::XRSessionModeUtils::IsImmersive(mode)) {
    return vr::XrConsentPromptLevel::kVRFeatures;
  }

  // If local-floor is requested and the device supports a user inputted or real
  // height, we need to warn about physical features being exposed.
  // Note that while this is also the case for bounded-floor, that is covered
  // by the stricter kVRFloorPlan Prompt set above.
  if (base::Contains(requested_features,
                     device::mojom::XRSessionFeature::REF_SPACE_LOCAL_FLOOR) &&
      runtime->SupportsNonEmulatedHeight()) {
    return vr::XrConsentPromptLevel::kVRFeatures;
  }

  // In the absence of other items that need to be consented, inline does not
  // require consent.
  if (mode == device::mojom::XRSessionMode::kInline) {
    return vr::XrConsentPromptLevel::kNone;
  }

  return vr::XrConsentPromptLevel::kDefault;
}

ContentSettingsType GetRequiredPermission(device::mojom::XRSessionMode mode) {
  switch (mode) {
    case device::mojom::XRSessionMode::kInline:
      return ContentSettingsType::SENSORS;
    case device::mojom::XRSessionMode::kImmersiveVr:
      return ContentSettingsType::VR;
    case device::mojom::XRSessionMode::kImmersiveAr:
      return ContentSettingsType::AR;
  }
}

}  // namespace

namespace vr {

VRServiceImpl::SessionRequestData::SessionRequestData(
    device::mojom::XRSessionOptionsPtr options,
    device::mojom::VRService::RequestSessionCallback callback,
    std::set<device::mojom::XRSessionFeature> enabled_features,
    device::mojom::XRDeviceId runtime_id)
    : options(std::move(options)),
      callback(std::move(callback)),
      enabled_features(std::move(enabled_features)),
      runtime_id(runtime_id) {}

VRServiceImpl::SessionRequestData::~SessionRequestData() = default;

VRServiceImpl::SessionRequestData::SessionRequestData(SessionRequestData&&) =
    default;

VRServiceImpl::VRServiceImpl(content::RenderFrameHost* render_frame_host)
    : WebContentsObserver(
          content::WebContents::FromRenderFrameHost(render_frame_host)),
      render_frame_host_(render_frame_host),
      in_focused_frame_(render_frame_host->GetView()->HasFocus()) {
  DCHECK(render_frame_host_);
  DVLOG(2) << __func__;

  runtime_manager_ = XRRuntimeManager::GetOrCreateInstance();
  runtime_manager_->AddService(this);

  magic_window_controllers_.set_disconnect_handler(base::BindRepeating(
      &VRServiceImpl::OnInlineSessionDisconnected,
      base::Unretained(this)));  // Unretained is OK since the collection is
                                 // owned by VRServiceImpl.
}

// Constructor for testing.
VRServiceImpl::VRServiceImpl(util::PassKey<XRRuntimeManagerTest>)
    : render_frame_host_(nullptr) {
  DVLOG(2) << __func__;
  runtime_manager_ = XRRuntimeManager::GetOrCreateInstance();
  runtime_manager_->AddService(this);
}

VRServiceImpl::~VRServiceImpl() {
  DVLOG(2) << __func__;
  // Ensure that any active magic window sessions are disconnected to avoid
  // collisions when a new session starts. See https://crbug.com/1017959, the
  // disconnect handler doesn't get called automatically on page navigation.
  for (auto it = magic_window_controllers_.begin();
       it != magic_window_controllers_.end(); ++it) {
    OnInlineSessionDisconnected(it.id());
  }
  runtime_manager_->RemoveService(this);
}

void VRServiceImpl::Create(
    content::RenderFrameHost* render_frame_host,
    mojo::PendingReceiver<device::mojom::VRService> receiver) {
  DVLOG(2) << __func__;
  std::unique_ptr<VRServiceImpl> vr_service_impl =
      std::make_unique<VRServiceImpl>(render_frame_host);

  VRServiceImpl* impl = vr_service_impl.get();
  impl->receiver_ = mojo::MakeSelfOwnedReceiver(std::move(vr_service_impl),
                                                std::move(receiver));
}

void VRServiceImpl::InitializationComplete() {
  // After initialization has completed, we can correctly answer
  // supportsSession, and can provide correct display capabilities.
  DVLOG(2) << __func__;
  initialization_complete_ = true;

  ResolvePendingRequests();
}

void VRServiceImpl::SetClient(
    mojo::PendingRemote<device::mojom::VRServiceClient> service_client) {
  if (service_client_) {
    mojo::ReportBadMessage("ServiceClient should only be set once.");
    return;
  }

  DVLOG(2) << __func__;
  service_client_.Bind(std::move(service_client));
}

void VRServiceImpl::ResolvePendingRequests() {
  DVLOG(2) << __func__
           << ": pending_requests_.size()=" << pending_requests_.size();
  for (auto& callback : pending_requests_) {
    std::move(callback).Run();
  }
  pending_requests_.clear();
}

void VRServiceImpl::OnDisplayInfoChanged() {
  device::mojom::VRDisplayInfoPtr display_info =
      runtime_manager_->GetCurrentVRDisplayInfo(this);
  if (display_info) {
    for (auto& client : session_clients_)
      client->OnChanged(display_info.Clone());
  }
}

void VRServiceImpl::RuntimesChanged() {
  DVLOG(2) << __func__;
  OnDisplayInfoChanged();

  if (service_client_) {
    service_client_->OnDeviceChanged();
  }
}

void VRServiceImpl::OnWebContentsFocused(content::RenderWidgetHost* host) {
  OnWebContentsFocusChanged(host, true);
}

void VRServiceImpl::OnWebContentsLostFocus(content::RenderWidgetHost* host) {
  OnWebContentsFocusChanged(host, false);
}

void VRServiceImpl::RenderFrameDeleted(content::RenderFrameHost* host) {
  if (host != render_frame_host_)
    return;

  // Receiver should always be live here, as this is a SelfOwnedReceiver.
  // Close the receiver (and delete this VrServiceImpl) when the RenderFrameHost
  // is deleted.
  DCHECK(receiver_.get());
  receiver_->Close();
}

void VRServiceImpl::OnWebContentsFocusChanged(content::RenderWidgetHost* host,
                                              bool focused) {
  if (!render_frame_host_->GetView() ||
      render_frame_host_->GetView()->GetRenderWidgetHost() != host) {
    return;
  }

  in_focused_frame_ = focused;

  for (const auto& controller : magic_window_controllers_)
    controller->SetFrameDataRestricted(!focused);
}

// static
bool VRServiceImpl::IsXrDeviceConsentPromptDisabledForTesting() {
  static bool is_xr_device_consent_prompt_disabled_for_testing =
      base::CommandLine::ForCurrentProcess()->HasSwitch(
          switches::kDisableXrDeviceConsentPromptForTesting);
  return is_xr_device_consent_prompt_disabled_for_testing;
}

void VRServiceImpl::OnInlineSessionCreated(
    SessionRequestData request,
    device::mojom::XRSessionPtr session,
    mojo::PendingRemote<device::mojom::XRSessionController>
        pending_controller) {
  if (!session) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::UNKNOWN_RUNTIME_ERROR));
    return;
  }

  mojo::Remote<device::mojom::XRSessionController> controller(
      std::move(pending_controller));
  // Start giving out magic window data if we are focused.
  controller->SetFrameDataRestricted(!in_focused_frame_);

  auto id = magic_window_controllers_.Add(std::move(controller));
  DVLOG(2) << __func__ << ": session_id=" << id.GetUnsafeValue()
           << " runtime_id=" << request.runtime_id;

  // Note: We might be recording an inline session that was created by WebVR.
  auto* session_metrics_tracker =
      GetSessionMetricsHelper()->RecordInlineSessionStart(id.GetUnsafeValue());

  OnSessionCreated(std::move(request), std::move(session),
                   session_metrics_tracker);
}

void VRServiceImpl::OnImmersiveSessionCreated(
    SessionRequestData request,
    device::mojom::XRSessionPtr session) {
  if (!session) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::UNKNOWN_RUNTIME_ERROR));
    return;
  }

  // Get the metrics tracker for the new immersive session
  auto* session_metrics_tracker =
      GetSessionMetricsHelper()->GetImmersiveSessionTracker();

  // If the immersive session tracker hasn't already been started, start it.
  // This only happens during certain tests, but this is ideally where we should
  // be creating the session tracker anyway so the other cases should be
  // removed.
  // TODO(https://crbug.com/1021314)
  if (!session_metrics_tracker) {
    session_metrics_tracker =
        GetSessionMetricsHelper()->RecordImmersiveSessionStart();
  }

  OnSessionCreated(std::move(request), std::move(session),
                   session_metrics_tracker);
}

void VRServiceImpl::OnInlineSessionDisconnected(
    mojo::RemoteSetElementId session_id) {
  DVLOG(2) << __func__ << ": session_id=" << session_id.GetUnsafeValue();
  // Notify metrics helper that inline session was stopped.
  auto* metrics_helper = GetSessionMetricsHelper();
  metrics_helper->RecordInlineSessionStop(session_id.GetUnsafeValue());
}

SessionMetricsHelper* VRServiceImpl::GetSessionMetricsHelper() {
  content::WebContents* web_contents =
      content::WebContents::FromRenderFrameHost(render_frame_host_);
  SessionMetricsHelper* metrics_helper =
      SessionMetricsHelper::FromWebContents(web_contents);
  if (!metrics_helper) {
    // This will only happen if we are not already in VR; set start params
    // accordingly.
    metrics_helper =
        SessionMetricsHelper::CreateForWebContents(web_contents, Mode::kNoVr);
  }

  return metrics_helper;
}

void VRServiceImpl::OnSessionCreated(
    SessionRequestData request,
    device::mojom::XRSessionPtr session,
    WebXRSessionTracker* session_metrics_tracker) {
  DVLOG(2) << __func__ << ": session_runtime_id=" << request.runtime_id;

  // Not checking for validity of |session|, since that's done by
  // |OnInlineSessionCreated| and |OnImmersiveSessionCreated|.

  UMA_HISTOGRAM_ENUMERATION("XR.RuntimeUsed", request.runtime_id);

  mojo::Remote<device::mojom::XRSessionClient> client;
  session->client_receiver = client.BindNewPipeAndPassReceiver();

  session->enabled_features.clear();
  for (const auto& feature : request.enabled_features) {
    session->enabled_features.push_back(feature);
  }

  client->OnVisibilityStateChanged(visibility_state_);
  session_clients_.Add(std::move(client));

  session_metrics_tracker->RecordRequestedFeatures(*(request.options),
                                                   request.enabled_features);

  auto success = device::mojom::RequestSessionSuccess::New();
  success->session = std::move(session);
  success->metrics_recorder =
      session_metrics_tracker->BindMetricsRecorderPipe();

  std::move(request.callback)
      .Run(device::mojom::RequestSessionResult::NewSuccess(std::move(success)));
}

void VRServiceImpl::RequestSession(
    device::mojom::XRSessionOptionsPtr options,
    device::mojom::VRService::RequestSessionCallback callback) {
  DVLOG(2) << __func__;
  DCHECK(options);

  // Queue the request to get to when initialization has completed.
  if (!initialization_complete_) {
    DVLOG(2) << __func__ << ": initialization not yet complete, defer request";
    pending_requests_.push_back(
        base::BindOnce(&VRServiceImpl::RequestSession, base::Unretained(this),
                       std::move(options), std::move(callback)));
    return;
  }

  if (runtime_manager_->IsOtherClientPresenting(this)) {
    DVLOG(2) << __func__
             << ": can't create sessions while an immersive session exists";
    // Can't create sessions while an immersive session exists.
    std::move(callback).Run(
        device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::EXISTING_IMMERSIVE_SESSION));
    return;
  }

  auto* runtime = runtime_manager_->GetRuntimeForOptions(options.get());
  if (!runtime) {
    std::move(callback).Run(
        device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::NO_RUNTIME_FOUND));
    return;
  }

  // GetRuntimeForOptions should only return a device that supports all required
  // features.
  std::set<device::mojom::XRSessionFeature> requested_features;
  for (const auto& feature : options->required_features) {
    requested_features.insert(feature);
  }

  // The consent flow cannot differentiate between optional and required
  // features, but we don't need to block creation if an optional feature is
  // not supported. Add all requested features to the set of supported features.
  for (const auto& feature : options->optional_features) {
    if (runtime->SupportsFeature(feature)) {
      requested_features.insert(feature);
    }
  }

  SessionRequestData request(std::move(options), std::move(callback),
                             std::move(requested_features), runtime->GetId());

  ShowConsentPrompt(std::move(request), runtime);
}

void VRServiceImpl::ShowConsentPrompt(SessionRequestData request,
                                      BrowserXRRuntime* runtime) {
  DVLOG(2) << __func__;
  DCHECK(request.options);
  DCHECK(runtime);
  DCHECK_EQ(runtime->GetId(), request.runtime_id);

#if defined(OS_WIN)
  DCHECK_NE(request.options->mode, device::mojom::XRSessionMode::kImmersiveAr);
#endif

  bool consent_granted = false;
  XrConsentPromptLevel consent_level = GetRequiredConsentLevel(
      request.options->mode, runtime, request.enabled_features);
  if (!base::FeatureList::IsEnabled(features::kWebXrPermissionsApi)) {
    consent_granted =
        ((consent_level == XrConsentPromptLevel::kNone) ||
         IsConsentGrantedForDevice(request.runtime_id, consent_level));
  }

  // Skip the consent prompt if the user has already consented for this device,
  // or if consent is not needed.
  if (consent_granted || IsXrDeviceConsentPromptDisabledForTesting()) {
    EnsureRuntimeInstalled(std::move(request), runtime);
    return;
  }

  if (base::FeatureList::IsEnabled(features::kWebXrPermissionsApi)) {
    PermissionManager* permission_manager = PermissionManager::Get(
        Profile::FromBrowserContext(GetWebContents()->GetBrowserContext()));
    DCHECK(permission_manager);

    // Need to calculate the permission before the call below, as otherwise
    // std::move nulls options out before GetRequiredPermission runs.
    ContentSettingsType permission =
        GetRequiredPermission(request.options->mode);
    permission_manager->RequestPermission(
        permission, render_frame_host_,
        render_frame_host_->GetLastCommittedURL(), true,
        base::BindOnce(&VRServiceImpl::OnPermissionResult,
                       weak_ptr_factory_.GetWeakPtr(), std::move(request),
                       consent_level));
    return;
  }

  runtime->ShowConsentPrompt(
      render_frame_host_->GetProcess()->GetID(),
      render_frame_host_->GetRoutingID(), consent_level,
      base::BindOnce(&VRServiceImpl::OnConsentResult,
                     weak_ptr_factory_.GetWeakPtr(), std::move(request)));
}

// TODO(alcooper): Once the ConsentFlow can be removed expected_runtime_id and
// consent_level shouldn't be needed.
void VRServiceImpl::OnPermissionResult(SessionRequestData request,
                                       XrConsentPromptLevel consent_level,
                                       ContentSetting setting_value) {
  OnConsentResult(std::move(request), consent_level,
                  setting_value == ContentSetting::CONTENT_SETTING_ALLOW);
}

void VRServiceImpl::OnConsentResult(SessionRequestData request,
                                    XrConsentPromptLevel consent_level,
                                    bool is_consent_granted) {
  DVLOG(2) << __func__;
  if (!is_consent_granted) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::USER_DENIED_CONSENT));
    return;
  }

  AddConsentGrantedDevice(request.runtime_id, consent_level);

  // Re-check for another client instance after a potential user consent.
  if (runtime_manager_->IsOtherClientPresenting(this)) {
    // Can't create sessions while an immersive session exists.
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::EXISTING_IMMERSIVE_SESSION));
    return;
  }

  EnsureRuntimeInstalled(std::move(request), nullptr);
}

void VRServiceImpl::EnsureRuntimeInstalled(SessionRequestData request,
                                           BrowserXRRuntime* runtime) {
  DVLOG(2) << __func__;

  // If we were not provided the runtime, try to get it again.
  if (!runtime)
    runtime = runtime_manager_->GetRuntimeForOptions(request.options.get());

  // Ensure that it's the same runtime as the one we expect.
  if (!runtime || runtime->GetId() != request.runtime_id) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::UNKNOWN_RUNTIME_ERROR));
    return;
  }

  runtime->EnsureInstalled(
      render_frame_host_->GetProcess()->GetID(),
      render_frame_host_->GetRoutingID(),
      base::BindOnce(&VRServiceImpl::OnInstallResult,
                     weak_ptr_factory_.GetWeakPtr(), std::move(request)));
}

void VRServiceImpl::OnInstallResult(SessionRequestData request,
                                    bool install_succeeded) {
  if (!install_succeeded) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::RUNTIME_INSTALL_FAILURE));
    return;
  }

  DoRequestSession(std::move(request));
}

void VRServiceImpl::DoRequestSession(SessionRequestData request) {
  DVLOG(2) << __func__;
  // Get the runtime again, since we're running in an async context
  // and the pointer returned from `GetRuntimeForOptions` is non-owning.
  auto* runtime = runtime_manager_->GetRuntimeForOptions(request.options.get());

  // Ensure that it's the same runtime as the one we expect.
  if (!runtime || runtime->GetId() != request.runtime_id) {
    std::move(request.callback)
        .Run(device::mojom::RequestSessionResult::NewFailureReason(
            device::mojom::RequestSessionError::UNKNOWN_RUNTIME_ERROR));
    return;
  }

  TRACE_EVENT_INSTANT1("xr", "GetRuntimeForOptions", TRACE_EVENT_SCOPE_THREAD,
                       "id", request.runtime_id);

  auto runtime_options = GetRuntimeOptions(request.options.get());

#if defined(OS_ANDROID) && BUILDFLAG(ENABLE_ARCORE)
  if (request.runtime_id == device::mojom::XRDeviceId::ARCORE_DEVICE_ID) {
    runtime_options->render_process_id =
        render_frame_host_->GetProcess()->GetID();
    runtime_options->render_frame_id = render_frame_host_->GetRoutingID();
  }
#endif
  // Make the resolved enabled features available to the runtime.
  runtime_options->enabled_features.reserve(request.enabled_features.size());
  for (const auto& feature : request.enabled_features) {
    runtime_options->enabled_features.push_back(feature);
  }

  if (device::XRSessionModeUtils::IsImmersive(runtime_options->mode)) {
    GetSessionMetricsHelper()->ReportRequestPresent(*runtime_options);

    base::OnceCallback<void(device::mojom::XRSessionPtr)> immersive_callback =
        base::BindOnce(&VRServiceImpl::OnImmersiveSessionCreated,
                       weak_ptr_factory_.GetWeakPtr(), std::move(request));
    runtime->RequestSession(this, std::move(runtime_options),
                            std::move(immersive_callback));
  } else {
    base::OnceCallback<void(
        device::mojom::XRSessionPtr,
        mojo::PendingRemote<device::mojom::XRSessionController>)>
        non_immersive_callback =
            base::BindOnce(&VRServiceImpl::OnInlineSessionCreated,
                           weak_ptr_factory_.GetWeakPtr(), std::move(request));
    runtime->GetRuntime()->RequestSession(std::move(runtime_options),
                                          std::move(non_immersive_callback));
  }
}

void VRServiceImpl::SupportsSession(
    device::mojom::XRSessionOptionsPtr options,
    device::mojom::VRService::SupportsSessionCallback callback) {
  if (!initialization_complete_) {
    pending_requests_.push_back(
        base::BindOnce(&VRServiceImpl::SupportsSession, base::Unretained(this),
                       std::move(options), std::move(callback)));
    return;
  }
  runtime_manager_->SupportsSession(std::move(options), std::move(callback));
}

void VRServiceImpl::ExitPresent(ExitPresentCallback on_exited) {
  BrowserXRRuntime* immersive_runtime =
      runtime_manager_->GetCurrentlyPresentingImmersiveRuntime();
  DVLOG(2) << __func__ << ": !!immersive_runtime=" << !!immersive_runtime;
  if (immersive_runtime) {
    immersive_runtime->ExitPresent(this, std::move(on_exited));
  } else {
    std::move(on_exited).Run();
  }
}

void VRServiceImpl::SetFramesThrottled(bool throttled) {
  if (throttled != frames_throttled_) {
    frames_throttled_ = throttled;
    BrowserXRRuntime* immersive_runtime =
        runtime_manager_->GetCurrentlyPresentingImmersiveRuntime();
    if (immersive_runtime) {
      immersive_runtime->SetFramesThrottled(this, frames_throttled_);
    }
  }
}

void VRServiceImpl::OnExitPresent() {
  DVLOG(2) << __func__;

  // If the immersive session tracker hasn't already been stopped, stop it.
  // This only happens during certain tests, but this is ideally where we should
  // be stopping the session tracker anyway so the other cases should be
  // removed.
  // TODO(https://crbug.com/1021314)
  if (GetSessionMetricsHelper()->GetImmersiveSessionTracker()) {
    GetSessionMetricsHelper()->RecordImmersiveSessionStop();
  }

  for (auto& client : session_clients_)
    client->OnExitPresent();
}

void VRServiceImpl::OnVisibilityStateChanged(
    device::mojom::XRVisibilityState visiblity_state) {
  visibility_state_ = visiblity_state;
  for (auto& client : session_clients_)
    client->OnVisibilityStateChanged(visiblity_state);
}

content::WebContents* VRServiceImpl::GetWebContents() {
  return content::WebContents::FromRenderFrameHost(render_frame_host_);
}

bool VRServiceImpl::IsConsentGrantedForDevice(
    device::mojom::XRDeviceId device_id,
    XrConsentPromptLevel consent_level) {
  auto it = consent_granted_devices_.find(device_id);
  return it != consent_granted_devices_.end() && it->second >= consent_level;
}

void VRServiceImpl::AddConsentGrantedDevice(
    device::mojom::XRDeviceId device_id,
    XrConsentPromptLevel consent_level) {
  auto it = consent_granted_devices_.find(device_id);
  if (it == consent_granted_devices_.end() || it->second < consent_level) {
    consent_granted_devices_[device_id] = consent_level;
  }
}

}  // namespace vr
