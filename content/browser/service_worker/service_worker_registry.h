// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_SERVICE_WORKER_SERVICE_WORKER_REGISTRY_H_
#define CONTENT_BROWSER_SERVICE_WORKER_SERVICE_WORKER_REGISTRY_H_

#include <memory>

#include "base/files/file_path.h"
#include "base/memory/scoped_refptr.h"
#include "content/browser/service_worker/service_worker_database.h"
#include "content/browser/service_worker/service_worker_registration.h"
#include "content/browser/service_worker/service_worker_storage.h"
#include "content/common/content_export.h"

namespace base {
class SequencedTaskRunner;
}

namespace storage {
class QuotaManagerProxy;
class SpecialStoragePolicy;
}  // namespace storage

namespace content {

class ServiceWorkerContextCore;
class ServiceWorkerVersion;

// This class manages in-memory representation of service worker registrations
// (i.e., ServiceWorkerRegistration) including installing and uninstalling
// registrations. The instance of this class is owned by
// ServiceWorkerContextCore and has the same lifetime of the owner.
// The instance owns ServiceworkerStorage and uses it to store/retrieve
// registrations to/from persistent storage.
// The instance lives on the core thread.
// TODO(crbug.com/1039200): Move ServiceWorkerStorage's method and fields which
// depend on ServiceWorkerRegistration into this class.
class CONTENT_EXPORT ServiceWorkerRegistry {
 public:
  using ResourceList = ServiceWorkerStorage::ResourceList;
  using RegistrationList = ServiceWorkerStorage::RegistrationList;
  using FindRegistrationCallback = base::OnceCallback<void(
      blink::ServiceWorkerStatusCode status,
      scoped_refptr<ServiceWorkerRegistration> registration)>;
  using GetRegistrationsCallback = base::OnceCallback<void(
      blink::ServiceWorkerStatusCode status,
      const std::vector<scoped_refptr<ServiceWorkerRegistration>>&
          registrations)>;
  using GetRegistrationsInfosCallback = base::OnceCallback<void(
      blink::ServiceWorkerStatusCode status,
      const std::vector<ServiceWorkerRegistrationInfo>& registrations)>;
  using GetUserDataCallback =
      base::OnceCallback<void(const std::vector<std::string>& data,
                              blink::ServiceWorkerStatusCode status)>;
  using GetUserKeysAndDataCallback = base::OnceCallback<void(
      const base::flat_map<std::string, std::string>& data_map,
      blink::ServiceWorkerStatusCode status)>;
  using GetUserDataForAllRegistrationsCallback = base::OnceCallback<void(
      const std::vector<std::pair<int64_t, std::string>>& user_data,
      blink::ServiceWorkerStatusCode status)>;
  using StatusCallback = ServiceWorkerStorage::StatusCallback;

  ServiceWorkerRegistry(
      const base::FilePath& user_data_directory,
      ServiceWorkerContextCore* context,
      scoped_refptr<base::SequencedTaskRunner> database_task_runner,
      storage::QuotaManagerProxy* quota_manager_proxy,
      storage::SpecialStoragePolicy* special_storage_policy);

  // For re-creating the registry from the old one. This is called when
  // something went wrong during storage access.
  ServiceWorkerRegistry(ServiceWorkerContextCore* context,
                        ServiceWorkerRegistry* old_registry);

  ~ServiceWorkerRegistry();

  ServiceWorkerStorage* storage() const { return storage_.get(); }

  // Creates a new in-memory representation of registration. Can be null when
  // storage is disabled. This method must be called after storage is
  // initialized.
  scoped_refptr<ServiceWorkerRegistration> CreateNewRegistration(
      blink::mojom::ServiceWorkerRegistrationOptions options);

  // Create a new instance of ServiceWorkerVersion which is associated with the
  // given |registration|. Can be null when storage is disabled. This method
  // must be called after storage is initialized.
  scoped_refptr<ServiceWorkerVersion> CreateNewVersion(
      ServiceWorkerRegistration* registration,
      const GURL& script_url,
      blink::mojom::ScriptType script_type);

  // Finds registration for |client_url| or |scope| or |registration_id|.
  // The Find methods will find stored and initially installing registrations.
  // Returns blink::ServiceWorkerStatusCode::kOk with non-null
  // registration if registration is found, or returns
  // blink::ServiceWorkerStatusCode::kErrorNotFound if no
  // matching registration is found.  The FindRegistrationForScope method is
  // guaranteed to return asynchronously. However, the methods to find
  // for |client_url| or |registration_id| may complete immediately
  // (the callback may be called prior to the method returning) or
  // asynchronously.
  void FindRegistrationForClientUrl(const GURL& client_url,
                                    FindRegistrationCallback callback);
  void FindRegistrationForScope(const GURL& scope,
                                FindRegistrationCallback callback);
  // These FindRegistrationForId() methods look up live registrations and may
  // return a "findable" registration without looking up storage. A registration
  // is considered as "findable" when the registration is stored or in the
  // installing state.
  void FindRegistrationForId(int64_t registration_id,
                             const GURL& origin,
                             FindRegistrationCallback callback);
  // Generally |FindRegistrationForId| should be used to look up a registration
  // by |registration_id| since it's more efficient. But if a |registration_id|
  // is all that is available this method can be used instead.
  // Like |FindRegistrationForId| this method may complete immediately (the
  // callback may be called prior to the method returning) or asynchronously.
  void FindRegistrationForIdOnly(int64_t registration_id,
                                 FindRegistrationCallback callback);

  // Returns all stored and installing registrations for a given origin.
  void GetRegistrationsForOrigin(const GURL& origin,
                                 GetRegistrationsCallback callback);

  // Returns info about all stored and initially installing registrations.
  void GetAllRegistrationsInfos(GetRegistrationsInfosCallback callback);

  ServiceWorkerRegistration* GetUninstallingRegistration(const GURL& scope);

  // Commits |registration| with the installed but not activated |version|
  // to storage, overwriting any pre-existing registration data for the scope.
  // A pre-existing version's script resources remain available if that version
  // is live. ServiceWorkerStorage::PurgeResources() should be called when it's
  // OK to delete them.
  void StoreRegistration(ServiceWorkerRegistration* registration,
                         ServiceWorkerVersion* version,
                         StatusCallback callback);

  // Deletes the registration data for |registration|. The live registration is
  // still findable via GetUninstallingRegistration(), and versions are usable
  // because their script resources have not been deleted. After calling this,
  // the caller should later:
  // - Call NotifyDoneUninstallingRegistration() to let registry know the
  //   uninstalling operation is done.
  // - If it no longer wants versions to be usable, call
  //   ServiceWorkerStorage::PurgeResources() to delete their script resources.
  // If these aren't called, on the next profile session the cleanup occurs.
  void DeleteRegistration(scoped_refptr<ServiceWorkerRegistration> registration,
                          const GURL& origin,
                          StatusCallback callback);

  // Intended for use only by ServiceWorkerRegisterJob and
  // ServiceWorkerRegistration.
  void NotifyInstallingRegistration(ServiceWorkerRegistration* registration);
  void NotifyDoneInstallingRegistration(ServiceWorkerRegistration* registration,
                                        ServiceWorkerVersion* version,
                                        blink::ServiceWorkerStatusCode status);
  void NotifyDoneUninstallingRegistration(
      ServiceWorkerRegistration* registration,
      ServiceWorkerRegistration::Status new_status);

  // Wrapper functions of ServiceWorkerStorage. These wrappers provide error
  // recovering mechanism when database operations fail.
  void UpdateToActiveState(int64_t registration_id,
                           const GURL& origin,
                           StatusCallback callback);
  void GetUserData(int64_t registration_id,
                   const std::vector<std::string>& keys,
                   GetUserDataCallback callback);
  void GetUserDataByKeyPrefix(int64_t registration_id,
                              const std::string& key_prefix,
                              GetUserDataCallback callback);
  void GetUserKeysAndDataByKeyPrefix(int64_t registration_id,
                                     const std::string& key_prefix,
                                     GetUserKeysAndDataCallback callback);
  void StoreUserData(
      int64_t registration_id,
      const GURL& origin,
      const std::vector<std::pair<std::string, std::string>>& key_value_pairs,
      StatusCallback callback);
  void ClearUserData(int64_t registration_id,
                     const std::vector<std::string>& keys,
                     StatusCallback callback);
  void ClearUserDataByKeyPrefixes(int64_t registration_id,
                                  const std::vector<std::string>& key_prefixes,
                                  StatusCallback callback);
  void ClearUserDataForAllRegistrationsByKeyPrefix(
      const std::string& key_prefix,
      StatusCallback callback);
  void GetUserDataForAllRegistrations(
      const std::string& key,
      GetUserDataForAllRegistrationsCallback callback);
  void GetUserDataForAllRegistrationsByKeyPrefix(
      const std::string& key_prefix,
      GetUserDataForAllRegistrationsCallback callback);

  // TODO(crbug.com/1039200): Make this private once methods/fields related to
  // ServiceWorkerRegistration in ServiceWorkerStorage are moved into this
  // class.
  scoped_refptr<ServiceWorkerRegistration> GetOrCreateRegistration(
      const ServiceWorkerDatabase::RegistrationData& data,
      const ResourceList& resources);

 private:
  ServiceWorkerRegistration* FindInstallingRegistrationForClientUrl(
      const GURL& client_url);
  ServiceWorkerRegistration* FindInstallingRegistrationForScope(
      const GURL& scope);
  ServiceWorkerRegistration* FindInstallingRegistrationForId(
      int64_t registration_id);

  // Looks up live registrations and returns an optional value which may contain
  // a "findable" registration. See the implementation of this method for
  // what "findable" means and when a registration is returned.
  base::Optional<scoped_refptr<ServiceWorkerRegistration>>
  FindFromLiveRegistrationsForId(int64_t registration_id);

  void DidFindRegistrationForClientUrl(
      const GURL& client_url,
      int64_t trace_event_id,
      FindRegistrationCallback callback,
      blink::ServiceWorkerStatusCode status,
      std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
      std::unique_ptr<ResourceList> resources);
  void DidFindRegistrationForScope(
      FindRegistrationCallback callback,
      blink::ServiceWorkerStatusCode status,
      std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
      std::unique_ptr<ResourceList> resources);
  void DidFindRegistrationForId(
      int64_t registration_id,
      FindRegistrationCallback callback,
      blink::ServiceWorkerStatusCode status,
      std::unique_ptr<ServiceWorkerDatabase::RegistrationData> data,
      std::unique_ptr<ResourceList> resources);

  void DidGetRegistrationsForOrigin(
      GetRegistrationsCallback callback,
      const GURL& origin_filter,
      blink::ServiceWorkerStatusCode status,
      std::unique_ptr<RegistrationList> registration_data_list,
      std::unique_ptr<std::vector<ResourceList>> resources_list);
  void DidGetAllRegistrations(
      GetRegistrationsInfosCallback callback,
      blink::ServiceWorkerStatusCode status,
      std::unique_ptr<RegistrationList> registration_data_list);

  void DidStoreRegistration(
      const ServiceWorkerDatabase::RegistrationData& data,
      StatusCallback callback,
      blink::ServiceWorkerStatusCode status,
      int64_t deleted_version_id,
      const std::vector<int64_t>& newly_purgeable_resources);
  void DidDeleteRegistration(
      int64_t registration_id,
      StatusCallback callback,
      blink::ServiceWorkerStatusCode status,
      int64_t deleted_version_id,
      const std::vector<int64_t>& newly_purgeable_resources);

  void DidUpdateToActiveState(StatusCallback callback,
                              ServiceWorkerDatabase::Status status);
  void DidGetUserData(GetUserDataCallback callback,
                      const std::vector<std::string>& data,
                      ServiceWorkerDatabase::Status status);
  void DidGetUserKeysAndData(
      GetUserKeysAndDataCallback callback,
      const base::flat_map<std::string, std::string>& data_map,
      ServiceWorkerDatabase::Status status);
  void DidStoreUserData(StatusCallback callback,
                        ServiceWorkerDatabase::Status status);
  void DidClearUserData(StatusCallback callback,
                        ServiceWorkerDatabase::Status status);
  void DidGetUserDataForAllRegistrations(
      GetUserDataForAllRegistrationsCallback callback,
      const std::vector<std::pair<int64_t, std::string>>& user_data,
      ServiceWorkerDatabase::Status status);

  void ScheduleDeleteAndStartOver();

  // The ServiceWorkerContextCore object must outlive this.
  ServiceWorkerContextCore* const context_;

  std::unique_ptr<ServiceWorkerStorage> storage_;

  // For finding registrations being installed or uninstalled.
  using RegistrationRefsById =
      std::map<int64_t, scoped_refptr<ServiceWorkerRegistration>>;
  RegistrationRefsById installing_registrations_;
  RegistrationRefsById uninstalling_registrations_;

  base::WeakPtrFactory<ServiceWorkerRegistry> weak_factory_{this};
};

}  // namespace content

#endif  // CONTENT_BROWSER_SERVICE_WORKER_SERVICE_WORKER_REGISTRY_H_
