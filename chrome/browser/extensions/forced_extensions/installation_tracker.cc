// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/forced_extensions/installation_tracker.h"

#include <set>

#include "base/bind.h"
#include "base/metrics/histogram_functions.h"
#include "base/metrics/histogram_macros.h"
#include "base/values.h"
#include "chrome/browser/extensions/external_provider_impl.h"
#include "chrome/browser/extensions/forced_extensions/installation_reporter.h"
#include "chrome/browser/profiles/profile.h"
#include "components/prefs/pref_service.h"
#include "extensions/browser/install/crx_install_error.h"
#include "extensions/browser/pref_names.h"
#include "extensions/browser/updater/extension_downloader.h"
#include "extensions/browser/updater/extension_downloader_delegate.h"
#include "extensions/common/extension_urls.h"

#if defined(OS_CHROMEOS)
#include "components/user_manager/user_manager.h"
#endif  // defined(OS_CHROMEOS)

namespace {
// Timeout to report UMA if not all force-installed extension were loaded.
constexpr base::TimeDelta kInstallationTimeout =
    base::TimeDelta::FromMinutes(5);

#if defined(OS_CHROMEOS)

extensions::InstallationTracker::SessionType GetSessionFromUserType(
    user_manager::UserType user_type) {
  switch (user_type) {
    case user_manager::USER_TYPE_REGULAR:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_REGULAR_EXISTING;
    case user_manager::USER_TYPE_GUEST:
      return extensions::InstallationTracker::SessionType::SESSION_TYPE_GUEST;
    case user_manager::USER_TYPE_PUBLIC_ACCOUNT:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_PUBLIC_ACCOUNT;
    case user_manager::USER_TYPE_SUPERVISED:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_SUPERVISED;
    case user_manager::USER_TYPE_KIOSK_APP:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_KIOSK_APP;
    case user_manager::USER_TYPE_CHILD:
      return extensions::InstallationTracker::SessionType::SESSION_TYPE_CHILD;
    case user_manager::USER_TYPE_ARC_KIOSK_APP:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_ARC_KIOSK_APP;
    case user_manager::USER_TYPE_ACTIVE_DIRECTORY:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_ACTIVE_DIRECTORY;
    case user_manager::USER_TYPE_WEB_KIOSK_APP:
      return extensions::InstallationTracker::SessionType::
          SESSION_TYPE_WEB_KIOSK_APP;
    default:
      NOTREACHED();
  }
  return extensions::InstallationTracker::SessionType::kMaxValue;
}
#endif  // defined(OS_CHROMEOS)
}  // namespace

namespace extensions {

InstallationTracker::InstallationTracker(
    ExtensionRegistry* registry,
    Profile* profile,
    std::unique_ptr<base::OneShotTimer> timer)
    : registry_(registry),
      profile_(profile),
      pref_service_(profile->GetPrefs()),
      start_time_(base::Time::Now()),
      timer_(std::move(timer)) {
  registry_observer_.Add(registry_);
  reporter_observer_.Add(InstallationReporter::Get(profile_));
  pref_change_registrar_.Init(pref_service_);
  pref_change_registrar_.Add(
      pref_names::kInstallForceList,
      base::BindRepeating(&InstallationTracker::OnForcedExtensionsPrefChanged,
                          base::Unretained(this)));

  timer_->Start(FROM_HERE, kInstallationTimeout,
                base::BindRepeating(&InstallationTracker::ReportResults,
                                    base::Unretained(this)));

  // Try to load list now.
  OnForcedExtensionsPrefChanged();
}

InstallationTracker::~InstallationTracker() = default;

void InstallationTracker::AddExtensionInfo(const ExtensionId& extension_id,
                                           ExtensionStatus status,
                                           bool is_from_store) {
  auto result =
      extensions_.emplace(extension_id, ExtensionInfo{status, is_from_store});
  DCHECK(result.second);
  if (result.first->second.status == ExtensionStatus::PENDING)
    pending_extensions_counter_++;
}

void InstallationTracker::ChangeExtensionStatus(const ExtensionId& extension_id,
                                                ExtensionStatus status) {
  auto item = extensions_.find(extension_id);
  if (item == extensions_.end())
    return;
  if (item->second.status == ExtensionStatus::PENDING)
    pending_extensions_counter_--;
  item->second.status = status;
  if (item->second.status == ExtensionStatus::PENDING)
    pending_extensions_counter_++;
}

void InstallationTracker::RemoveExtensionInfo(const ExtensionId& extension_id) {
  auto item = extensions_.find(extension_id);
  DCHECK(item != extensions_.end());
  if (item->second.status == ExtensionStatus::PENDING)
    pending_extensions_counter_--;
  extensions_.erase(item);
}

void InstallationTracker::OnForcedExtensionsPrefChanged() {
  const base::DictionaryValue* value =
      pref_service_->GetDictionary(pref_names::kInstallForceList);
  if (!value)
    return;

  // Store extensions in a list instead of removing them because we don't want
  // to change a collection while iterating though it.
  std::vector<ExtensionId> extensions_to_remove;
  for (const auto& extension : extensions_) {
    const ExtensionId& extension_id = extension.first;
    if (value->FindKey(extension_id) == nullptr)
      extensions_to_remove.push_back(extension_id);
  }

  for (const auto& extension_id : extensions_to_remove)
    RemoveExtensionInfo(extension_id);

  // Report if all remaining extensions were removed from policy.
  if (loaded_ && pending_extensions_counter_ == 0)
    ReportResults();

  // Load forced extensions list only once.
  if (value->empty() || loaded_) {
    return;
  }

  loaded_ = true;

  for (const auto& entry : *value) {
    const ExtensionId& extension_id = entry.first;
    std::string* update_url = nullptr;
    if (entry.second->is_dict()) {
      update_url =
          entry.second->FindStringKey(ExternalProviderImpl::kExternalUpdateUrl);
    }
    bool is_from_store =
        update_url && *update_url == extension_urls::kChromeWebstoreUpdateURL;

    AddExtensionInfo(extension_id,
                     registry_->enabled_extensions().Contains(extension_id)
                         ? ExtensionStatus::LOADED
                         : ExtensionStatus::PENDING,
                     is_from_store);
  }
  if (pending_extensions_counter_ == 0)
    ReportResults();
}

void InstallationTracker::OnShutdown(ExtensionRegistry*) {
  registry_observer_.RemoveAll();
  reporter_observer_.RemoveAll();
  pref_change_registrar_.RemoveAll();
  timer_->Stop();
}

void InstallationTracker::OnExtensionLoaded(
    content::BrowserContext* browser_context,
    const Extension* extension) {
  ChangeExtensionStatus(extension->id(), ExtensionStatus::LOADED);
  if (pending_extensions_counter_ == 0)
    ReportResults();
}

void InstallationTracker::OnExtensionInstallationFailed(
    const ExtensionId& extension_id,
    InstallationReporter::FailureReason reason) {
  ChangeExtensionStatus(extension_id, ExtensionStatus::FAILED);
  if (pending_extensions_counter_ == 0)
    ReportResults();
}

#if defined(OS_CHROMEOS)
// Returns the type of session in case extension fails to install.
InstallationTracker::SessionType InstallationTracker::GetSessionType() {
  SessionType current_session = GetSessionFromUserType(
      user_manager::UserManager::Get()->GetActiveUser()->GetType());
  // Check if it is regular user and if the user is a new one.
  if (current_session == SessionType::SESSION_TYPE_REGULAR_EXISTING &&
      user_manager::UserManager::Get()->IsCurrentUserNew())
    return SessionType::SESSION_TYPE_REGULAR_NEW;

  return current_session;
}
#endif  // defined(OS_CHROMEOS)

void InstallationTracker::ReportMetrics() {
  UMA_HISTOGRAM_COUNTS_100("Extensions.ForceInstalledTotalCandidateCount",
                           extensions_.size());
  std::set<ExtensionId> missing_forced_extensions;
  for (const auto& extension : extensions_) {
    if (extension.second.status != ExtensionStatus::LOADED)
      missing_forced_extensions.insert(extension.first);
  }
  if (missing_forced_extensions.empty()) {
    UMA_HISTOGRAM_LONG_TIMES("Extensions.ForceInstalledLoadTime",
                             base::Time::Now() - start_time_);
    // TODO(burunduk): Remove VLOGs after resolving crbug/917700 and
    // crbug/904600.
    VLOG(2) << "All forced extensions seems to be installed";
    return;
  }
  InstallationReporter* installation_reporter =
      InstallationReporter::Get(profile_);
  size_t enabled_missing_count = missing_forced_extensions.size();
  auto installed_extensions = registry_->GenerateInstalledExtensionsSet();
  for (const auto& entry : *installed_extensions)
    missing_forced_extensions.erase(entry->id());
  size_t misconfigured_extensions = 0;
  size_t installed_missing_count = missing_forced_extensions.size();

  UMA_HISTOGRAM_COUNTS_100("Extensions.ForceInstalledTimedOutCount",
                           enabled_missing_count);
  UMA_HISTOGRAM_COUNTS_100(
      "Extensions.ForceInstalledTimedOutAndNotInstalledCount",
      installed_missing_count);
  VLOG(2) << "Failed to install " << installed_missing_count
          << " forced extensions.";
  for (const auto& extension_id : missing_forced_extensions) {
    InstallationReporter::InstallationData installation =
        installation_reporter->Get(extension_id);
    UMA_HISTOGRAM_ENUMERATION(
        "Extensions.ForceInstalledFailureCacheStatus",
        installation.downloading_cache_status.value_or(
            ExtensionDownloaderDelegate::CacheStatus::CACHE_UNKNOWN));
    if (!installation.failure_reason && installation.install_stage) {
      installation.failure_reason =
          InstallationReporter::FailureReason::IN_PROGRESS;
      InstallationReporter::Stage install_stage =
          installation.install_stage.value();
      UMA_HISTOGRAM_ENUMERATION("Extensions.ForceInstalledStage",
                                install_stage);
      if (install_stage == InstallationReporter::Stage::DOWNLOADING) {
        DCHECK(installation.downloading_stage);
        ExtensionDownloaderDelegate::Stage downloading_stage =
            installation.downloading_stage.value();
        UMA_HISTOGRAM_ENUMERATION("Extensions.ForceInstalledDownloadingStage",
                                  downloading_stage);
      }
    }
    InstallationReporter::FailureReason failure_reason =
        installation.failure_reason.value_or(
            InstallationReporter::FailureReason::UNKNOWN);
    UMA_HISTOGRAM_ENUMERATION("Extensions.ForceInstalledFailureReason2",
                              failure_reason);
    if (extensions_[extension_id].is_from_store) {
      UMA_HISTOGRAM_ENUMERATION(
          "Extensions.WebStore_ForceInstalledFailureReason2", failure_reason);
    } else {
      UMA_HISTOGRAM_ENUMERATION(
          "Extensions.OffStore_ForceInstalledFailureReason2", failure_reason);
    }

    // In case of CRX_FETCH_FAILURE, report the network error code, HTTP
    // error code and number of fetch tries made.
    if (failure_reason ==
        InstallationReporter::FailureReason::CRX_FETCH_FAILED) {
      base::UmaHistogramSparse("Extensions.ForceInstalledNetworkErrorCode",
                               installation.network_error_code.value());

      if (installation.response_code) {
        base::UmaHistogramSparse("Extensions.ForceInstalledHttpErrorCode",
                                 installation.response_code.value());
      }
      UMA_HISTOGRAM_EXACT_LINEAR("Extensions.ForceInstalledFetchTries",
                                 installation.fetch_tries.value(),
                                 ExtensionDownloader::kMaxRetries);
    }

    // In case of MANIFEST_FETCH_FAILURE, report the network error code,
    // HTTP error code and number of fetch tries made.
    if (failure_reason ==
        InstallationReporter::FailureReason::MANIFEST_FETCH_FAILED) {
      base::UmaHistogramSparse(
          "Extensions.ForceInstalledManifestFetchFailedNetworkErrorCode",
          installation.network_error_code.value());

      if (installation.response_code) {
        base::UmaHistogramSparse(
            "Extensions.ForceInstalledManifestFetchFailedHttpErrorCode",
            installation.response_code.value());
      }
      UMA_HISTOGRAM_EXACT_LINEAR(
          "Extensions.ForceInstalledManifestFetchFailedFetchTries",
          installation.fetch_tries.value(), ExtensionDownloader::kMaxRetries);
    }
#if defined(OS_CHROMEOS)
        // Report type of session in case Force Installed Extensions fail to
        // install only if there is an active user. There can be extensions on
        // the login screen. There is no active user on the login screen and
        // thus we would not report in that case.
        if (user_manager::UserManager::Get()->GetActiveUser()) {
          UMA_HISTOGRAM_ENUMERATION(
              "Extensions.ForceInstalledFailureSessionType", GetSessionType());
        }
#endif  // defined(OS_CHROMEOS)
        VLOG(2) << "Forced extension " << extension_id
                << " failed to install with data="
                << InstallationReporter::GetFormattedInstallationData(
                       installation);
        if (installation.install_error_detail) {
          CrxInstallErrorDetail detail =
              installation.install_error_detail.value();
          // KIOSK_MODE_ONLY is a type of misconfiguration failure.
          if (detail == CrxInstallErrorDetail::KIOSK_MODE_ONLY)
            misconfigured_extensions++;
          UMA_HISTOGRAM_ENUMERATION(
              "Extensions.ForceInstalledFailureCrxInstallError", detail);
        }
        if (installation.unpacker_failure_reason) {
          UMA_HISTOGRAM_ENUMERATION(
              "Extensions.ForceInstalledFailureSandboxUnpackFailureReason",
              installation.unpacker_failure_reason.value(),
              SandboxedUnpackerFailureReason::NUM_FAILURE_REASONS);
        }
  }
  bool non_misconfigured_failure_occurred =
      misconfigured_extensions != missing_forced_extensions.size();
  UMA_HISTOGRAM_BOOLEAN(
      "Extensions."
      "ForceInstalledSessionsWithNonMisconfigurationFailureOccured",
      non_misconfigured_failure_occurred);
}
void InstallationTracker::ReportResults() {
  DCHECK(!reported_);
  // Report only if there was non-empty list of force-installed extensions.
  if (!extensions_.empty())
    ReportMetrics();
  reported_ = true;
  InstallationReporter::Get(profile_)->Clear();
  registry_observer_.RemoveAll();
  reporter_observer_.RemoveAll();
  pref_change_registrar_.RemoveAll();
  timer_->Stop();
}

}  //  namespace extensions
