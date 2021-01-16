// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_SMB_CLIENT_SMBFS_SHARE_H_
#define CHROME_BROWSER_CHROMEOS_SMB_CLIENT_SMBFS_SHARE_H_

#include <memory>
#include <string>

#include "base/callback.h"
#include "base/files/file_path.h"
#include "chrome/browser/chromeos/smb_client/smb_errors.h"
#include "chromeos/components/smbfs/smbfs_host.h"
#include "chromeos/components/smbfs/smbfs_mounter.h"

class Profile;

namespace chromeos {
namespace smb_client {

// Represents an SMB share mounted using smbfs. Handles mounting, unmounting,
// registration, and IPC communication with filesystem.
// Destroying will unmount and deregister the filesystem.
class SmbFsShare : public smbfs::SmbFsHost::Delegate {
 public:
  using KerberosOptions = smbfs::SmbFsMounter::KerberosOptions;
  using MountOptions = smbfs::SmbFsMounter::MountOptions;
  using MountCallback = base::OnceCallback<void(SmbMountResult)>;
  using MounterCreationCallback =
      base::RepeatingCallback<std::unique_ptr<smbfs::SmbFsMounter>(
          const std::string& share_path,
          const std::string& mount_dir_name,
          const MountOptions& options,
          smbfs::SmbFsHost::Delegate* delegate)>;

  SmbFsShare(Profile* profile,
             const std::string& share_path,
             const std::string& display_name,
             const MountOptions& options);
  ~SmbFsShare() override;

  SmbFsShare(const SmbFsShare&) = delete;
  SmbFsShare& operator=(const SmbFsShare&) = delete;

  // Mounts the SMB filesystem with |options_| and runs |callback| when
  // completed. Must not be called while mounted or another mount request is in
  // progress.
  void Mount(MountCallback callback);

  // Returns whether the filesystem is mounted and accessible via mount_path().
  bool IsMounted() const { return bool(host_); }

  const std::string& mount_id() const { return mount_id_; }
  const std::string& share_path() const { return share_path_; }

  base::FilePath mount_path() const {
    return host_ ? host_->mount_path() : base::FilePath();
  }

  void SetMounterCreationCallbackForTest(MounterCreationCallback callback);

 private:
  // Unmounts the filesystem and cancels any pending mount request.
  void Unmount();

  // Callback for smbfs::SmbFsMounter::Mount().
  void OnMountDone(MountCallback callback,
                   smbfs::mojom::MountError mount_error,
                   std::unique_ptr<smbfs::SmbFsHost> smbfs_host);

  // smbfs::SmbFsHost::Delegate overrides:
  void OnDisconnected() override;

  Profile* const profile_;
  const std::string share_path_;
  const std::string display_name_;
  const MountOptions options_;
  const std::string mount_id_;

  MounterCreationCallback mounter_creation_callback_for_test_;
  std::unique_ptr<smbfs::SmbFsMounter> mounter_;
  std::unique_ptr<smbfs::SmbFsHost> host_;
};

}  // namespace smb_client
}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_SMB_CLIENT_SMBFS_SHARE_H_
