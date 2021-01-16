// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "weblayer/browser/browser_main_parts_impl.h"

#include "base/base_switches.h"
#include "base/bind.h"
#include "base/message_loop/message_loop_current.h"
#include "base/threading/thread.h"
#include "base/threading/thread_restrictions.h"
#include "build/build_config.h"
#include "cc/base/switches.h"
#include "components/captive_portal/core/buildflags.h"
#include "components/startup_metric_utils/browser/startup_metric_utils.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/devtools_agent_host.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/common/content_switches.h"
#include "content/public/common/main_function_params.h"
#include "content/public/common/url_constants.h"
#include "services/service_manager/embedder/result_codes.h"
#include "ui/base/material_design/material_design_controller.h"
#include "ui/base/resource/resource_bundle.h"
#include "weblayer/browser/browser_process.h"
#include "weblayer/browser/webui/web_ui_controller_factory.h"
#include "weblayer/public/main.h"

#if defined(OS_ANDROID)
#include "components/crash/content/browser/child_exit_observer_android.h"
#include "components/crash/content/browser/child_process_crash_observer_android.h"
#include "components/crash/core/common/crash_key.h"
#include "net/android/network_change_notifier_factory_android.h"
#include "net/base/network_change_notifier.h"
#include "weblayer/browser/android/metrics/uma_utils.h"
#endif

#if defined(USE_X11)
#include "ui/base/x/x11_util.h"  // nogncheck
#endif
#if defined(USE_AURA) && defined(USE_X11)
#include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
#endif
#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
#include "ui/base/ime/init/input_method_initializer.h"
#endif

#if BUILDFLAG(ENABLE_CAPTIVE_PORTAL_DETECTION)
#include "weblayer/browser/captive_portal_service_factory.h"
#endif

namespace weblayer {

namespace {

// Instantiates all weblayer KeyedService factories, which is
// especially important for services that should be created at profile
// creation time as compared to lazily on first access.
static void EnsureBrowserContextKeyedServiceFactoriesBuilt() {
#if BUILDFLAG(ENABLE_CAPTIVE_PORTAL_DETECTION)
  CaptivePortalServiceFactory::GetInstance();
#endif
}

void StopMessageLoop(base::OnceClosure quit_closure) {
  for (auto it = content::RenderProcessHost::AllHostsIterator(); !it.IsAtEnd();
       it.Advance()) {
    it.GetCurrentValue()->DisableKeepAliveRefCount();
  }

  std::move(quit_closure).Run();
}

}  // namespace

BrowserMainPartsImpl::BrowserMainPartsImpl(
    MainParams* params,
    const content::MainFunctionParams& main_function_params)
    : params_(params), main_function_params_(main_function_params) {}

BrowserMainPartsImpl::~BrowserMainPartsImpl() = default;

int BrowserMainPartsImpl::PreCreateThreads() {
#if defined(OS_ANDROID)
  // The ChildExitObserver needs to be created before any child process is
  // created because it needs to be notified during process creation.
  crash_reporter::ChildExitObserver::Create();
  crash_reporter::ChildExitObserver::GetInstance()->RegisterClient(
      std::make_unique<crash_reporter::ChildProcessCrashObserver>());

  crash_reporter::InitializeCrashKeys();
#endif

  return service_manager::RESULT_CODE_NORMAL_EXIT;
}
void BrowserMainPartsImpl::PreMainMessageLoopStart() {
#if defined(USE_AURA) && defined(USE_X11)
  ui::TouchFactory::SetTouchDeviceListFromCommandLine();
#endif

#if defined(OS_ANDROID)
  startup_metric_utils::RecordMainEntryPointTime(GetMainEntryPointTimeTicks());
#endif
}

int BrowserMainPartsImpl::PreEarlyInitialization() {
  browser_process_ = std::make_unique<BrowserProcess>();

#if defined(USE_X11)
  ui::SetDefaultX11ErrorHandlers();
#endif
#if defined(USE_AURA) && defined(OS_LINUX)
  ui::InitializeInputMethodForTesting();
#endif
#if defined(OS_ANDROID)
  net::NetworkChangeNotifier::SetFactory(
      new net::NetworkChangeNotifierFactoryAndroid());
#endif
  return service_manager::RESULT_CODE_NORMAL_EXIT;
}

void BrowserMainPartsImpl::PostEarlyInitialization() {
#if defined(OS_ANDROID)
  CreateLocalState();
#endif
}

void BrowserMainPartsImpl::PreMainMessageLoopRun() {
  ui::MaterialDesignController::Initialize();
  // It's necessary to have a complete dependency graph of
  // BrowserContextKeyedServices before calling out to the delegate (which
  // will potentially create a profile), so that a profile creation message is
  // properly dispatched to the factories that want to create their services
  // at profile creation time.
  EnsureBrowserContextKeyedServiceFactoriesBuilt();

  params_->delegate->PreMainMessageLoopRun();

  content::WebUIControllerFactory::RegisterFactory(
      WebUIControllerFactory::GetInstance());

  if (main_function_params_.ui_task) {
    std::move(*main_function_params_.ui_task).Run();
    delete main_function_params_.ui_task;
    run_message_loop_ = false;
  }

#if defined(OS_ANDROID)
  // Record collected startup metrics.
  startup_metric_utils::RecordBrowserMainMessageLoopStart(
      base::TimeTicks::Now(), /* is_first_run */ false);
  memory_metrics_logger_ = std::make_unique<metrics::MemoryMetricsLogger>();
#endif
}

bool BrowserMainPartsImpl::MainMessageLoopRun(int* result_code) {
  return !run_message_loop_;
}

void BrowserMainPartsImpl::PostMainMessageLoopRun() {
  params_->delegate->PostMainMessageLoopRun();
}

void BrowserMainPartsImpl::PreDefaultMainMessageLoopRun(
    base::OnceClosure quit_closure) {
  // Wrap the method that stops the message loop so we can do other shutdown
  // cleanup inside content.
  params_->delegate->SetMainMessageLoopQuitClosure(
      base::BindOnce(StopMessageLoop, std::move(quit_closure)));
}

void BrowserMainPartsImpl::CreateLocalState() {
  DCHECK(!local_state_);
  feature_list_creator_ = std::make_unique<FeatureListCreator>();
  feature_list_creator_->CreateLocalState();
  local_state_ = feature_list_creator_->TakePrefService();
  CHECK(local_state_);
}

}  // namespace weblayer
