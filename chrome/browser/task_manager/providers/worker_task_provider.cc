// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/task_manager/providers/worker_task_provider.h"

#include "base/stl_util.h"
#include "chrome/browser/browser_process.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/browser/service_worker_running_info.h"
#include "content/public/browser/storage_partition.h"

using content::BrowserThread;

namespace task_manager {

WorkerTaskProvider::WorkerTaskProvider() = default;

WorkerTaskProvider::~WorkerTaskProvider() = default;

Task* WorkerTaskProvider::GetTaskOfUrlRequest(int child_id, int route_id) {
  return nullptr;
}

void WorkerTaskProvider::OnProfileAdded(Profile* profile) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  observed_profiles_.Add(profile);

  content::ServiceWorkerContext* context =
      content::BrowserContext::GetDefaultStoragePartition(profile)
          ->GetServiceWorkerContext();
  scoped_context_observer_.Add(context);

  // Create tasks for existing service workers.
  for (const auto& kv : context->GetRunningServiceWorkerInfos()) {
    const int64_t version_id = kv.first;
    const content::ServiceWorkerRunningInfo& running_info = kv.second;

    CreateTask(context, version_id, running_info);
  }
}

void WorkerTaskProvider::OnOffTheRecordProfileCreated(Profile* off_the_record) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  OnProfileAdded(off_the_record);
}

void WorkerTaskProvider::OnProfileWillBeDestroyed(Profile* profile) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  observed_profiles_.Remove(profile);

  content::ServiceWorkerContext* context =
      content::BrowserContext::GetDefaultStoragePartition(profile)
          ->GetServiceWorkerContext();
  scoped_context_observer_.Remove(context);
}

void WorkerTaskProvider::OnVersionStartedRunning(
    content::ServiceWorkerContext* context,
    int64_t version_id,
    const content::ServiceWorkerRunningInfo& running_info) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  CreateTask(context, version_id, running_info);
}

void WorkerTaskProvider::OnVersionStoppedRunning(
    content::ServiceWorkerContext* context,
    int64_t version_id) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  DeleteTask(context, version_id);
}

void WorkerTaskProvider::StartUpdating() {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  ProfileManager* profile_manager = g_browser_process->profile_manager();
  if (profile_manager) {
    scoped_profile_manager_observer_.Add(profile_manager);

    auto loaded_profiles = profile_manager->GetLoadedProfiles();
    for (auto* profile : loaded_profiles) {
      OnProfileAdded(profile);

      // If the incognito window is open, we have to check its profile and
      // create the tasks if there are any.
      if (profile->HasOffTheRecordProfile())
        OnProfileAdded(profile->GetOffTheRecordProfile());
    }
  }
}

void WorkerTaskProvider::StopUpdating() {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  // Stop observing profile creation and destruction.
  scoped_profile_manager_observer_.RemoveAll();
  observed_profiles_.RemoveAll();

  // Stop observing contexts.
  scoped_context_observer_.RemoveAll();

  // Delete all tracked tasks.
  service_worker_task_map_.clear();
}

void WorkerTaskProvider::CreateTask(
    content::ServiceWorkerContext* context,
    int64_t version_id,
    const content::ServiceWorkerRunningInfo& running_info) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  const ServiceWorkerTaskKey key(context, version_id);
  DCHECK(!base::Contains(service_worker_task_map_, key));

  const int render_process_id = running_info.render_process_id;
  auto* host = content::RenderProcessHost::FromID(render_process_id);
  auto result = service_worker_task_map_.emplace(
      key, std::make_unique<WorkerTask>(
               host->GetProcess().Handle(), running_info.script_url,
               Task::Type::SERVICE_WORKER, render_process_id));

  DCHECK(result.second);
  NotifyObserverTaskAdded(result.first->second.get());
}

void WorkerTaskProvider::DeleteTask(content::ServiceWorkerContext* context,
                                    int version_id) {
  const ServiceWorkerTaskKey key(context, version_id);
  auto it = service_worker_task_map_.find(key);
  DCHECK(it != service_worker_task_map_.end());

  NotifyObserverTaskRemoved(it->second.get());
  service_worker_task_map_.erase(it);
}

}  // namespace task_manager
