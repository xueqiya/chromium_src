// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/service_worker/service_worker_registry.h"

#include "base/memory/ptr_util.h"
#include "base/memory/weak_ptr.h"
#include "base/stl_util.h"
#include "base/trace_event/trace_event.h"
#include "content/browser/service_worker/service_worker_context_core.h"
#include "content/browser/service_worker/service_worker_info.h"
#include "content/browser/service_worker/service_worker_registration.h"
#include "content/browser/service_worker/service_worker_version.h"
#include "content/common/service_worker/service_worker_utils.h"

namespace content {

namespace {

void RunSoon(const base::Location& from_here, base::OnceClosure closure) {
  base::ThreadTaskRunnerHandle::Get()->PostTask(from_here, std::move(closure));
}

void CompleteFindNow(scoped_refptr<ServiceWorkerRegistration> registration,
                     blink::ServiceWorkerStatusCode status,
                     ServiceWorkerRegistry::FindRegistrationCallback callback) {
  if (registration && registration->is_deleted()) {
    // It's past the point of no return and no longer findable.
    std::move(callback).Run(blink::ServiceWorkerStatusCode::kErrorNotFound,
                            nullptr);
    return;
  }
  std::move(callback).Run(status, std::move(registration));
}

void CompleteFindSoon(
    const base::Location& from_here,
    scoped_refptr<ServiceWorkerRegistration> registration,
    blink::ServiceWorkerStatusCode status,
    ServiceWorkerRegistry::FindRegistrationCallback callback) {
  RunSoon(from_here, base::BindOnce(&CompleteFindNow, std::move(registration),
                                    status, std::move(callback)));
}

}  // namespace

ServiceWorkerRegistry::ServiceWorkerRegistry(
    const base::FilePath& user_data_directory,
    ServiceWorkerContextCore* context,
    scoped_refptr<base::SequencedTaskRunner> database_task_runner,
    storage::QuotaManagerProxy* quota_manager_proxy,
    storage::SpecialStoragePolicy* special_storage_policy)
    : context_(context),
      storage_(ServiceWorkerStorage::Create(user_data_directory,
                                            context,
                                            std::move(database_task_runner),
                                            quota_manager_proxy,
                                            special_storage_policy,
                                            this)) {
  DCHECK(context_);
}

ServiceWorkerRegistry::ServiceWorkerRegistry(
    ServiceWorkerContextCore* context,
    ServiceWorkerRegistry* old_registry)
    : context_(context),
      storage_(ServiceWorkerStorage::Create(context,
                                            old_registry->storage(),
                                            this)) {
  DCHECK(context_);
}

ServiceWorkerRegistry::~ServiceWorkerRegistry() = default;

scoped_refptr<ServiceWorkerRegistration>
ServiceWorkerRegistry::CreateNewRegistration(
    blink::mojom::ServiceWorkerRegistrationOptions options) {
  int64_t registration_id = storage()->NewRegistrationId();
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId)
    return nullptr;
  return base::MakeRefCounted<ServiceWorkerRegistration>(
      std::move(options), registration_id, context_->AsWeakPtr());
}

scoped_refptr<ServiceWorkerVersion> ServiceWorkerRegistry::CreateNewVersion(
    ServiceWorkerRegistration* registration,
    const GURL& script_url,
    blink::mojom::ScriptType script_type) {
  DCHECK(registration);
  int64_t version_id = storage()->NewVersionId();
  if (version_id == blink::mojom::kInvalidServiceWorkerVersionId)
    return nullptr;
  return base::MakeRefCounted<ServiceWorkerVersion>(
      registration, script_url, script_type, version_id, context_->AsWeakPtr());
}

void ServiceWorkerRegistry::FindRegistrationForClientUrl(
    const GURL& client_url,
    FindRegistrationCallback callback) {
  // To connect this TRACE_EVENT with the callback, Time::Now() is used as a
  // trace event id.
  int64_t trace_event_id =
      base::Time::Now().ToDeltaSinceWindowsEpoch().InMicroseconds();
  TRACE_EVENT_ASYNC_BEGIN1(
      "ServiceWorker", "ServiceWorkerRegistry::FindRegistrationForClientUrl",
      trace_event_id, "URL", client_url.spec());
  storage()->FindRegistrationForClientUrl(
      client_url,
      base::BindOnce(&ServiceWorkerRegistry::DidFindRegistrationForClientUrl,
                     weak_factory_.GetWeakPtr(), client_url, trace_event_id,
                     std::move(callback)));
}

void ServiceWorkerRegistry::FindRegistrationForScope(
    const GURL& scope,
    FindRegistrationCallback callback) {
  if (storage()->IsDisabled()) {
    RunSoon(
        FROM_HERE,
        base::BindOnce(std::move(callback),
                       blink::ServiceWorkerStatusCode::kErrorAbort, nullptr));
    return;
  }

  // Look up installing registration before checking storage.
  scoped_refptr<ServiceWorkerRegistration> installing_registration =
      FindInstallingRegistrationForScope(scope);
  if (installing_registration && !installing_registration->is_deleted()) {
    CompleteFindSoon(FROM_HERE, std::move(installing_registration),
                     blink::ServiceWorkerStatusCode::kOk, std::move(callback));
    return;
  }

  storage()->FindRegistrationForScope(
      scope, base::BindOnce(&ServiceWorkerRegistry::DidFindRegistrationForScope,
                            weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::FindRegistrationForId(
    int64_t registration_id,
    const GURL& origin,
    FindRegistrationCallback callback) {
  // Registration lookup is expected to abort when storage is disabled.
  if (storage()->IsDisabled()) {
    CompleteFindNow(nullptr, blink::ServiceWorkerStatusCode::kErrorAbort,
                    std::move(callback));
    return;
  }

  // Lookup live registration first.
  base::Optional<scoped_refptr<ServiceWorkerRegistration>> registration =
      FindFromLiveRegistrationsForId(registration_id);
  if (registration) {
    blink::ServiceWorkerStatusCode status =
        registration.value() ? blink::ServiceWorkerStatusCode::kOk
                             : blink::ServiceWorkerStatusCode::kErrorNotFound;
    CompleteFindNow(std::move(registration.value()), status,
                    std::move(callback));
    return;
  }

  storage()->FindRegistrationForId(
      registration_id, origin,
      base::BindOnce(&ServiceWorkerRegistry::DidFindRegistrationForId,
                     weak_factory_.GetWeakPtr(), registration_id,
                     std::move(callback)));
}

void ServiceWorkerRegistry::FindRegistrationForIdOnly(
    int64_t registration_id,
    FindRegistrationCallback callback) {
  // Registration lookup is expected to abort when storage is disabled.
  if (storage()->IsDisabled()) {
    CompleteFindNow(nullptr, blink::ServiceWorkerStatusCode::kErrorAbort,
                    std::move(callback));
    return;
  }

  // Lookup live registration first.
  base::Optional<scoped_refptr<ServiceWorkerRegistration>> registration =
      FindFromLiveRegistrationsForId(registration_id);
  if (registration) {
    blink::ServiceWorkerStatusCode status =
        registration.value() ? blink::ServiceWorkerStatusCode::kOk
                             : blink::ServiceWorkerStatusCode::kErrorNotFound;
    CompleteFindNow(std::move(registration.value()), status,
                    std::move(callback));
    return;
  }

  storage()->FindRegistrationForIdOnly(
      registration_id,
      base::BindOnce(&ServiceWorkerRegistry::DidFindRegistrationForId,
                     weak_factory_.GetWeakPtr(), registration_id,
                     std::move(callback)));
}

void ServiceWorkerRegistry::GetRegistrationsForOrigin(
    const GURL& origin,
    GetRegistrationsCallback callback) {
  storage()->GetRegistrationsForOrigin(
      origin,
      base::BindOnce(&ServiceWorkerRegistry::DidGetRegistrationsForOrigin,
                     weak_factory_.GetWeakPtr(), std::move(callback), origin));
}

void ServiceWorkerRegistry::GetAllRegistrationsInfos(
    GetRegistrationsInfosCallback callback) {
  storage()->GetAllRegistrations(
      base::BindOnce(&ServiceWorkerRegistry::DidGetAllRegistrations,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

ServiceWorkerRegistration* ServiceWorkerRegistry::GetUninstallingRegistration(
    const GURL& scope) {
  // TODO(bashi): Should we check state of ServiceWorkerStorage?
  for (const auto& registration : uninstalling_registrations_) {
    if (registration.second->scope() == scope) {
      DCHECK(registration.second->is_uninstalling());
      return registration.second.get();
    }
  }
  return nullptr;
}

void ServiceWorkerRegistry::StoreRegistration(
    ServiceWorkerRegistration* registration,
    ServiceWorkerVersion* version,
    StatusCallback callback) {
  DCHECK(registration);
  DCHECK(version);

  if (storage()->IsDisabled()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorAbort));
    return;
  }

  DCHECK_NE(version->fetch_handler_existence(),
            ServiceWorkerVersion::FetchHandlerExistence::UNKNOWN);
  DCHECK_EQ(registration->status(), ServiceWorkerRegistration::Status::kIntact);

  ServiceWorkerDatabase::RegistrationData data;
  data.registration_id = registration->id();
  data.scope = registration->scope();
  data.script = version->script_url();
  data.script_type = version->script_type();
  data.update_via_cache = registration->update_via_cache();
  data.has_fetch_handler = version->fetch_handler_existence() ==
                           ServiceWorkerVersion::FetchHandlerExistence::EXISTS;
  data.version_id = version->version_id();
  data.last_update_check = registration->last_update_check();
  data.is_active = (version == registration->active_version());
  if (version->origin_trial_tokens())
    data.origin_trial_tokens = *version->origin_trial_tokens();
  data.navigation_preload_state = registration->navigation_preload_state();
  data.script_response_time = version->GetInfo().script_response_time;
  for (const blink::mojom::WebFeature feature : version->used_features())
    data.used_features.insert(feature);
  data.cross_origin_embedder_policy = version->cross_origin_embedder_policy();

  ResourceList resources;
  version->script_cache_map()->GetResources(&resources);

  if (resources.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  uint64_t resources_total_size_bytes = 0;
  for (const auto& resource : resources) {
    DCHECK_GE(resource.size_bytes, 0);
    resources_total_size_bytes += resource.size_bytes;
  }
  data.resources_total_size_bytes = resources_total_size_bytes;

  storage()->StoreRegistrationData(
      data, resources,
      base::BindOnce(&ServiceWorkerRegistry::DidStoreRegistration,
                     weak_factory_.GetWeakPtr(), data, std::move(callback)));
}

void ServiceWorkerRegistry::DeleteRegistration(
    scoped_refptr<ServiceWorkerRegistration> registration,
    const GURL& origin,
    StatusCallback callback) {
  if (storage()->IsDisabled()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorAbort));
    return;
  }

  DCHECK(!registration->is_deleted())
      << "attempt to delete a registration twice";

  storage()->DeleteRegistration(
      registration->id(), origin,
      base::BindOnce(&ServiceWorkerRegistry::DidDeleteRegistration,
                     weak_factory_.GetWeakPtr(), registration->id(),
                     std::move(callback)));

  DCHECK(!base::Contains(uninstalling_registrations_, registration->id()));
  uninstalling_registrations_[registration->id()] = registration;
  registration->SetStatus(ServiceWorkerRegistration::Status::kUninstalling);
}

void ServiceWorkerRegistry::NotifyInstallingRegistration(
    ServiceWorkerRegistration* registration) {
  DCHECK(installing_registrations_.find(registration->id()) ==
         installing_registrations_.end());
  installing_registrations_[registration->id()] = registration;
}

void ServiceWorkerRegistry::NotifyDoneInstallingRegistration(
    ServiceWorkerRegistration* registration,
    ServiceWorkerVersion* version,
    blink::ServiceWorkerStatusCode status) {
  installing_registrations_.erase(registration->id());
  if (status != blink::ServiceWorkerStatusCode::kOk && version) {
    ResourceList resources;
    version->script_cache_map()->GetResources(&resources);

    std::set<int64_t> resource_ids;
    for (const auto& resource : resources)
      resource_ids.insert(resource.resource_id);
    storage()->DoomUncommittedResources(resource_ids);
  }
}

void ServiceWorkerRegistry::NotifyDoneUninstallingRegistration(
    ServiceWorkerRegistration* registration,
    ServiceWorkerRegistration::Status new_status) {
  registration->SetStatus(new_status);
  uninstalling_registrations_.erase(registration->id());
}

void ServiceWorkerRegistry::UpdateToActiveState(int64_t registration_id,
                                                const GURL& origin,
                                                StatusCallback callback) {
  storage()->UpdateToActiveState(
      registration_id, origin,
      base::BindOnce(&ServiceWorkerRegistry::DidUpdateToActiveState,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::GetUserData(int64_t registration_id,
                                        const std::vector<std::string>& keys,
                                        GetUserDataCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      keys.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback), std::vector<std::string>(),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }
  for (const std::string& key : keys) {
    if (key.empty()) {
      RunSoon(FROM_HERE,
              base::BindOnce(std::move(callback), std::vector<std::string>(),
                             blink::ServiceWorkerStatusCode::kErrorFailed));
      return;
    }
  }

  storage()->GetUserData(
      registration_id, keys,
      base::BindOnce(&ServiceWorkerRegistry::DidGetUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::GetUserDataByKeyPrefix(
    int64_t registration_id,
    const std::string& key_prefix,
    GetUserDataCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      key_prefix.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback), std::vector<std::string>(),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  storage()->GetUserDataByKeyPrefix(
      registration_id, key_prefix,
      base::BindOnce(&ServiceWorkerRegistry::DidGetUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::GetUserKeysAndDataByKeyPrefix(
    int64_t registration_id,
    const std::string& key_prefix,
    GetUserKeysAndDataCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      key_prefix.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           base::flat_map<std::string, std::string>(),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  storage()->GetUserKeysAndDataByKeyPrefix(
      registration_id, key_prefix,
      base::BindOnce(&ServiceWorkerRegistry::DidGetUserKeysAndData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::StoreUserData(
    int64_t registration_id,
    const GURL& origin,
    const std::vector<std::pair<std::string, std::string>>& key_value_pairs,
    StatusCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      key_value_pairs.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }
  for (const auto& kv : key_value_pairs) {
    if (kv.first.empty()) {
      RunSoon(FROM_HERE,
              base::BindOnce(std::move(callback),
                             blink::ServiceWorkerStatusCode::kErrorFailed));
      return;
    }
  }

  storage()->StoreUserData(
      registration_id, origin, key_value_pairs,
      base::BindOnce(&ServiceWorkerRegistry::DidStoreUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::ClearUserData(int64_t registration_id,
                                          const std::vector<std::string>& keys,
                                          StatusCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      keys.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }
  for (const std::string& key : keys) {
    if (key.empty()) {
      RunSoon(FROM_HERE,
              base::BindOnce(std::move(callback),
                             blink::ServiceWorkerStatusCode::kErrorFailed));
      return;
    }
  }

  storage()->ClearUserData(
      registration_id, keys,
      base::BindOnce(&ServiceWorkerRegistry::DidClearUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::ClearUserDataByKeyPrefixes(
    int64_t registration_id,
    const std::vector<std::string>& key_prefixes,
    StatusCallback callback) {
  if (registration_id == blink::mojom::kInvalidServiceWorkerRegistrationId ||
      key_prefixes.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }
  for (const std::string& key_prefix : key_prefixes) {
    if (key_prefix.empty()) {
      RunSoon(FROM_HERE,
              base::BindOnce(std::move(callback),
                             blink::ServiceWorkerStatusCode::kErrorFailed));
      return;
    }
  }

  storage()->ClearUserDataByKeyPrefixes(
      registration_id, key_prefixes,
      base::BindOnce(&ServiceWorkerRegistry::DidClearUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::ClearUserDataForAllRegistrationsByKeyPrefix(
    const std::string& key_prefix,
    StatusCallback callback) {
  if (key_prefix.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  storage()->ClearUserDataForAllRegistrationsByKeyPrefix(
      key_prefix,
      base::BindOnce(&ServiceWorkerRegistry::DidClearUserData,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::GetUserDataForAllRegistrations(
    const std::string& key,
    GetUserDataForAllRegistrationsCallback callback) {
  if (key.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           std::vector<std::pair<int64_t, std::string>>(),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  storage()->GetUserDataForAllRegistrations(
      key,
      base::BindOnce(&ServiceWorkerRegistry::DidGetUserDataForAllRegistrations,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

void ServiceWorkerRegistry::GetUserDataForAllRegistrationsByKeyPrefix(
    const std::string& key_prefix,
    GetUserDataForAllRegistrationsCallback callback) {
  if (key_prefix.empty()) {
    RunSoon(FROM_HERE,
            base::BindOnce(std::move(callback),
                           std::vector<std::pair<int64_t, std::string>>(),
                           blink::ServiceWorkerStatusCode::kErrorFailed));
    return;
  }

  storage()->GetUserDataForAllRegistrationsByKeyPrefix(
      key_prefix,
      base::BindOnce(&ServiceWorkerRegistry::DidGetUserDataForAllRegistrations,
                     weak_factory_.GetWeakPtr(), std::move(callback)));
}

ServiceWorkerRegistration*
ServiceWorkerRegistry::FindInstallingRegistrationForClientUrl(
    const GURL& client_url) {
  DCHECK(!client_url.has_ref());

  LongestScopeMatcher matcher(client_url);
  ServiceWorkerRegistration* match = nullptr;

  // TODO(nhiroki): This searches over installing registrations linearly and it
  // couldn't be scalable. Maybe the regs should be partitioned by origin.
  for (const auto& registration : installing_registrations_)
    if (matcher.MatchLongest(registration.second->scope()))
      match = registration.second.get();
  return match;
}

ServiceWorkerRegistration*
ServiceWorkerRegistry::FindInstallingRegistrationForScope(const GURL& scope) {
  for (const auto& registration : installing_registrations_)
    if (registration.second->scope() == scope)
      return registration.second.get();
  return nullptr;
}

ServiceWorkerRegistration*
ServiceWorkerRegistry::FindInstallingRegistrationForId(
    int64_t registration_id) {
  RegistrationRefsById::const_iterator found =
      installing_registrations_.find(registration_id);
  if (found == installing_registrations_.end())
    return nullptr;
  return found->second.get();
}

scoped_refptr<ServiceWorkerRegistration>
ServiceWorkerRegistry::GetOrCreateRegistration(
    const ServiceWorkerDatabase::RegistrationData& data,
    const ResourceList& resources) {
  scoped_refptr<ServiceWorkerRegistration> registration =
      context_->GetLiveRegistration(data.registration_id);
  if (registration)
    return registration;

  blink::mojom::ServiceWorkerRegistrationOptions options(
      data.scope, data.script_type, data.update_via_cache);
  registration = base::MakeRefCounted<ServiceWorkerRegistration>(
      options, data.registration_id, context_->AsWeakPtr());
  registration->SetStored();
  registration->set_resources_total_size_bytes(data.resources_total_size_bytes);
  registration->set_last_update_check(data.last_update_check);
  DCHECK(!base::Contains(uninstalling_registrations_, data.registration_id));

  scoped_refptr<ServiceWorkerVersion> version =
      context_->GetLiveVersion(data.version_id);
  if (!version) {
    version = base::MakeRefCounted<ServiceWorkerVersion>(
        registration.get(), data.script, data.script_type, data.version_id,
        context_->AsWeakPtr());
    version->set_fetch_handler_existence(
        data.has_fetch_handler
            ? ServiceWorkerVersion::FetchHandlerExistence::EXISTS
            : ServiceWorkerVersion::FetchHandlerExistence::DOES_NOT_EXIST);
    version->SetStatus(data.is_active ? ServiceWorkerVersion::ACTIVATED
                                      : ServiceWorkerVersion::INSTALLED);
    version->script_cache_map()->SetResources(resources);
    if (data.origin_trial_tokens)
      version->SetValidOriginTrialTokens(*data.origin_trial_tokens);

    version->set_used_features(data.used_features);
    version->set_cross_origin_embedder_policy(
        data.cross_origin_embedder_policy);
  }
  version->set_script_response_time_for_devtools(data.script_response_time);

  if (version->status() == ServiceWorkerVersion::ACTIVATED)
    registration->SetActiveVersion(version);
  else if (version->status() == ServiceWorkerVersion::INSTALLED)
    registration->SetWaitingVersion(version);
  else
    NOTREACHED();

  registration->EnableNavigationPreload(data.navigation_preload_state.enabled);
  registration->SetNavigationPreloadHeader(
      data.navigation_preload_state.header);
  return registration;
}

base::Optional<scoped_refptr<ServiceWorkerRegistration>>
ServiceWorkerRegistry::FindFromLiveRegistrationsForId(int64_t registration_id) {
  scoped_refptr<ServiceWorkerRegistration> registration =
      context_->GetLiveRegistration(registration_id);
  if (registration) {
    // The registration is considered as findable when it's stored or in
    // installing state.
    if (registration->IsStored() ||
        base::Contains(installing_registrations_, registration_id)) {
      return registration;
    }
    // Otherwise, the registration should not be findable even if it's still
    // alive.
    return nullptr;
  }
  // There is no live registration. Storage lookup is required. Returning
  // nullopt results in storage lookup.
  return base::nullopt;
}

void ServiceWorkerRegistry::DidFindRegistrationForClientUrl(
    const GURL& client_url,
    int64_t trace_event_id,
    FindRegistrationCallback callback,
    blink::ServiceWorkerStatusCode status,
    std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
    std::unique_ptr<ResourceList> resources) {
  if (status == blink::ServiceWorkerStatusCode::kErrorNotFound) {
    // Look for something currently being installed.
    scoped_refptr<ServiceWorkerRegistration> installing_registration =
        FindInstallingRegistrationForClientUrl(client_url);
    if (installing_registration) {
      blink::ServiceWorkerStatusCode installing_status =
          installing_registration->is_deleted()
              ? blink::ServiceWorkerStatusCode::kErrorNotFound
              : blink::ServiceWorkerStatusCode::kOk;
      TRACE_EVENT_ASYNC_END2(
          "ServiceWorker",
          "ServiceWorkerRegistry::FindRegistrationForClientUrl", trace_event_id,
          "Status", blink::ServiceWorkerStatusToString(status), "Info",
          (installing_status == blink::ServiceWorkerStatusCode::kOk)
              ? "Installing registration is found"
              : "Any registrations are not found");
      CompleteFindNow(std::move(installing_registration), installing_status,
                      std::move(callback));
      return;
    }
  }

  scoped_refptr<ServiceWorkerRegistration> registration;
  if (status == blink::ServiceWorkerStatusCode::kOk) {
    DCHECK(data);
    DCHECK(resources);
    registration = GetOrCreateRegistration(*data, *resources);
  }

  TRACE_EVENT_ASYNC_END1(
      "ServiceWorker", "ServiceWorkerRegistry::FindRegistrationForClientUrl",
      trace_event_id, "Status", blink::ServiceWorkerStatusToString(status));
  CompleteFindNow(std::move(registration), status, std::move(callback));
}

void ServiceWorkerRegistry::DidFindRegistrationForScope(
    FindRegistrationCallback callback,
    blink::ServiceWorkerStatusCode status,
    std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
    std::unique_ptr<ResourceList> resources) {
  scoped_refptr<ServiceWorkerRegistration> registration;
  if (status == blink::ServiceWorkerStatusCode::kOk) {
    DCHECK(data);
    DCHECK(resources);
    registration = GetOrCreateRegistration(*data, *resources);
  }

  CompleteFindNow(std::move(registration), status, std::move(callback));
}

void ServiceWorkerRegistry::DidFindRegistrationForId(
    int64_t registration_id,
    FindRegistrationCallback callback,
    blink::ServiceWorkerStatusCode status,
    std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
    std::unique_ptr<ResourceList> resources) {
  if (status == blink::ServiceWorkerStatusCode::kErrorNotFound) {
    // Look for something currently being installed.
    scoped_refptr<ServiceWorkerRegistration> installing_registration =
        FindInstallingRegistrationForId(registration_id);
    if (installing_registration) {
      CompleteFindNow(std::move(installing_registration),
                      blink::ServiceWorkerStatusCode::kOk, std::move(callback));
      return;
    }
  }

  scoped_refptr<ServiceWorkerRegistration> registration;
  if (status == blink::ServiceWorkerStatusCode::kOk) {
    DCHECK(data);
    DCHECK(resources);
    registration = GetOrCreateRegistration(*data, *resources);
  }

  CompleteFindNow(std::move(registration), status, std::move(callback));
}

void ServiceWorkerRegistry::DidGetRegistrationsForOrigin(
    GetRegistrationsCallback callback,
    const GURL& origin_filter,
    blink::ServiceWorkerStatusCode status,
    std::unique_ptr<RegistrationList> registration_data_list,
    std::unique_ptr<std::vector<ResourceList>> resources_list) {
  DCHECK(origin_filter.is_valid());

  if (status != blink::ServiceWorkerStatusCode::kOk &&
      status != blink::ServiceWorkerStatusCode::kErrorNotFound) {
    std::move(callback).Run(
        status, std::vector<scoped_refptr<ServiceWorkerRegistration>>());
    return;
  }

  DCHECK(registration_data_list);
  DCHECK(resources_list);

  // Add all stored registrations.
  std::set<int64_t> registration_ids;
  std::vector<scoped_refptr<ServiceWorkerRegistration>> registrations;
  size_t index = 0;
  for (const auto& registration_data : *registration_data_list) {
    registration_ids.insert(registration_data.registration_id);
    registrations.push_back(GetOrCreateRegistration(
        registration_data, resources_list->at(index++)));
  }

  // Add unstored registrations that are being installed.
  for (const auto& registration : installing_registrations_) {
    if (registration.second->scope().GetOrigin() != origin_filter)
      continue;
    if (registration_ids.insert(registration.first).second)
      registrations.push_back(registration.second);
  }

  std::move(callback).Run(blink::ServiceWorkerStatusCode::kOk,
                          std::move(registrations));
}

void ServiceWorkerRegistry::DidGetAllRegistrations(
    GetRegistrationsInfosCallback callback,
    blink::ServiceWorkerStatusCode status,
    std::unique_ptr<RegistrationList> registration_data_list) {
  if (status != blink::ServiceWorkerStatusCode::kOk &&
      status != blink::ServiceWorkerStatusCode::kErrorNotFound) {
    std::move(callback).Run(status,
                            std::vector<ServiceWorkerRegistrationInfo>());
    return;
  }

  DCHECK(registration_data_list);

  // Add all stored registrations.
  std::set<int64_t> pushed_registrations;
  std::vector<ServiceWorkerRegistrationInfo> infos;
  for (const auto& registration_data : *registration_data_list) {
    const bool inserted =
        pushed_registrations.insert(registration_data.registration_id).second;
    DCHECK(inserted);

    ServiceWorkerRegistration* registration =
        context_->GetLiveRegistration(registration_data.registration_id);
    if (registration) {
      infos.push_back(registration->GetInfo());
      continue;
    }

    ServiceWorkerRegistrationInfo info;
    info.scope = registration_data.scope;
    info.update_via_cache = registration_data.update_via_cache;
    info.registration_id = registration_data.registration_id;
    info.stored_version_size_bytes =
        registration_data.resources_total_size_bytes;
    info.navigation_preload_enabled =
        registration_data.navigation_preload_state.enabled;
    info.navigation_preload_header_length =
        registration_data.navigation_preload_state.header.size();
    if (ServiceWorkerVersion* version =
            context_->GetLiveVersion(registration_data.version_id)) {
      if (registration_data.is_active)
        info.active_version = version->GetInfo();
      else
        info.waiting_version = version->GetInfo();
      infos.push_back(info);
      continue;
    }

    if (registration_data.is_active) {
      info.active_version.status = ServiceWorkerVersion::ACTIVATED;
      info.active_version.script_url = registration_data.script;
      info.active_version.version_id = registration_data.version_id;
      info.active_version.registration_id = registration_data.registration_id;
      info.active_version.script_response_time =
          registration_data.script_response_time;
      info.active_version.fetch_handler_existence =
          registration_data.has_fetch_handler
              ? ServiceWorkerVersion::FetchHandlerExistence::EXISTS
              : ServiceWorkerVersion::FetchHandlerExistence::DOES_NOT_EXIST;
      info.active_version.navigation_preload_state =
          registration_data.navigation_preload_state;
    } else {
      info.waiting_version.status = ServiceWorkerVersion::INSTALLED;
      info.waiting_version.script_url = registration_data.script;
      info.waiting_version.version_id = registration_data.version_id;
      info.waiting_version.registration_id = registration_data.registration_id;
      info.waiting_version.script_response_time =
          registration_data.script_response_time;
      info.waiting_version.fetch_handler_existence =
          registration_data.has_fetch_handler
              ? ServiceWorkerVersion::FetchHandlerExistence::EXISTS
              : ServiceWorkerVersion::FetchHandlerExistence::DOES_NOT_EXIST;
      info.waiting_version.navigation_preload_state =
          registration_data.navigation_preload_state;
    }
    infos.push_back(info);
  }

  // Add unstored registrations that are being installed.
  for (const auto& registration : installing_registrations_) {
    if (pushed_registrations.insert(registration.first).second)
      infos.push_back(registration.second->GetInfo());
  }

  std::move(callback).Run(blink::ServiceWorkerStatusCode::kOk, infos);
}

void ServiceWorkerRegistry::DidStoreRegistration(
    const ServiceWorkerDatabase::RegistrationData& data,
    StatusCallback callback,
    blink::ServiceWorkerStatusCode status,
    int64_t deleted_version_id,
    const std::vector<int64_t>& newly_purgeable_resources) {
  if (status != blink::ServiceWorkerStatusCode::kOk) {
    std::move(callback).Run(status);
    return;
  }

  // Purge the deleted version's resources now if needed. This is subtle. The
  // version might still be used for a long time even after it's deleted. We can
  // only purge safely once the version is REDUNDANT, since it will never be
  // used again.
  //
  // If the deleted version's ServiceWorkerVersion doesn't exist, we can assume
  // it's effectively REDUNDANT so it's safe to purge now. This is because the
  // caller is assumed to promote the new version to active unless the deleted
  // version is doing work, and it can't be doing work if it's not live.
  //
  // If the ServiceWorkerVersion does exist, it triggers purging once it reaches
  // REDUNDANT. Otherwise, purging happens on the next browser session (via
  // DeleteStaleResources).
  if (!context_->GetLiveVersion(deleted_version_id))
    storage()->PurgeResources(newly_purgeable_resources);

  scoped_refptr<ServiceWorkerRegistration> registration =
      context_->GetLiveRegistration(data.registration_id);
  if (registration) {
    registration->SetStored();
    registration->set_resources_total_size_bytes(
        data.resources_total_size_bytes);
  }
  context_->NotifyRegistrationStored(data.registration_id, data.scope);

  std::move(callback).Run(status);
}

void ServiceWorkerRegistry::DidDeleteRegistration(
    int64_t registration_id,
    StatusCallback callback,
    blink::ServiceWorkerStatusCode status,
    int64_t deleted_version_id,
    const std::vector<int64_t>& newly_purgeable_resources) {
  if (!context_->GetLiveVersion(deleted_version_id))
    storage()->PurgeResources(newly_purgeable_resources);

  scoped_refptr<ServiceWorkerRegistration> registration =
      context_->GetLiveRegistration(registration_id);
  if (registration)
    registration->UnsetStored();

  std::move(callback).Run(status);
}

void ServiceWorkerRegistry::DidUpdateToActiveState(
    StatusCallback callback,
    ServiceWorkerDatabase::Status status) {
  if (status != ServiceWorkerDatabase::STATUS_OK &&
      status != ServiceWorkerDatabase::STATUS_ERROR_NOT_FOUND) {
    ScheduleDeleteAndStartOver();
  }
  std::move(callback).Run(
      ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::DidGetUserData(
    GetUserDataCallback callback,
    const std::vector<std::string>& data,
    ServiceWorkerDatabase::Status status) {
  if (status != ServiceWorkerDatabase::STATUS_OK &&
      status != ServiceWorkerDatabase::STATUS_ERROR_NOT_FOUND) {
    ScheduleDeleteAndStartOver();
  }
  std::move(callback).Run(
      data, ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::DidGetUserKeysAndData(
    GetUserKeysAndDataCallback callback,
    const base::flat_map<std::string, std::string>& data_map,
    ServiceWorkerDatabase::Status status) {
  if (status != ServiceWorkerDatabase::STATUS_OK &&
      status != ServiceWorkerDatabase::STATUS_ERROR_NOT_FOUND) {
    ScheduleDeleteAndStartOver();
  }
  std::move(callback).Run(
      data_map, ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::DidStoreUserData(
    StatusCallback callback,
    ServiceWorkerDatabase::Status status) {
  // |status| can be NOT_FOUND when the associated registration did not exist in
  // the database. In the case, we don't have to schedule the corruption
  // recovery.
  if (status != ServiceWorkerDatabase::STATUS_OK &&
      status != ServiceWorkerDatabase::STATUS_ERROR_NOT_FOUND) {
    ScheduleDeleteAndStartOver();
  }
  std::move(callback).Run(
      ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::DidClearUserData(
    StatusCallback callback,
    ServiceWorkerDatabase::Status status) {
  if (status != ServiceWorkerDatabase::STATUS_OK)
    ScheduleDeleteAndStartOver();
  std::move(callback).Run(
      ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::DidGetUserDataForAllRegistrations(
    GetUserDataForAllRegistrationsCallback callback,
    const std::vector<std::pair<int64_t, std::string>>& user_data,
    ServiceWorkerDatabase::Status status) {
  if (status != ServiceWorkerDatabase::STATUS_OK)
    ScheduleDeleteAndStartOver();
  std::move(callback).Run(
      user_data, ServiceWorkerStorage::DatabaseStatusToStatusCode(status));
}

void ServiceWorkerRegistry::ScheduleDeleteAndStartOver() {
  if (storage()->IsDisabled()) {
    // Recovery process has already been scheduled.
    return;
  }

  storage()->Disable();
  context_->ScheduleDeleteAndStartOver();
}

}  // namespace content
