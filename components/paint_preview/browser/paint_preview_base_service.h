// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAINT_PREVIEW_BROWSER_PAINT_PREVIEW_BASE_SERVICE_H_
#define COMPONENTS_PAINT_PREVIEW_BROWSER_PAINT_PREVIEW_BASE_SERVICE_H_

#include <memory>

#include "base/callback.h"
#include "base/files/file_path.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "base/optional.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "build/build_config.h"
#include "components/keyed_service/core/keyed_service.h"
#include "components/paint_preview/browser/file_manager.h"
#include "components/paint_preview/browser/paint_preview_policy.h"
#include "components/paint_preview/common/file_utils.h"
#include "components/paint_preview/common/mojom/paint_preview_recorder.mojom.h"
#include "components/paint_preview/common/proto/paint_preview.pb.h"
#include "components/paint_preview/public/paint_preview_compositor_service.h"
#include "content/public/browser/web_contents.h"
#if defined(OS_ANDROID)
#include "base/android/jni_android.h"
#include "base/android/scoped_java_ref.h"
#endif  // defined(OS_ANDROID)

namespace paint_preview {

// A base KeyedService that serves as the Public API for Paint Previews.
// Features that want to use Paint Previews should extend this class.
// The KeyedService provides a 1:1 mapping between the service and a key or
// profile allowing each feature built on Paint Previews to reliably store
// necessary data to the right directory on disk.
//
// Implementations of this service should be created by implementing a factory
// that extends one of:
// - BrowserContextKeyedServiceFactory
// OR preferably the
// - SimpleKeyedServiceFactory
class PaintPreviewBaseService : public KeyedService {
 public:
  enum CaptureStatus {
    kOk = 0,
    kContentUnsupported,
    kClientCreationFailed,
    kCaptureFailed,
  };

  using OnCapturedCallback =
      base::OnceCallback<void(CaptureStatus,
                              std::unique_ptr<PaintPreviewProto>)>;

  using OnReadProtoCallback =
      base::OnceCallback<void(std::unique_ptr<PaintPreviewProto>)>;

  // Creates a service instance for a feature. Artifacts produced will live in
  // |profile_dir|/paint_preview/|ascii_feature_name|. Implementers of the
  // factory can also elect their factory to not construct services in the event
  // a profile |is_off_the_record|. The |policy| object is responsible for
  // determining whether or not a given WebContents is amenable to paint
  // preview. If nullptr is passed as |policy| all content is deemed amenable.
  PaintPreviewBaseService(const base::FilePath& profile_dir,
                          const std::string& ascii_feature_name,
                          std::unique_ptr<PaintPreviewPolicy> policy,
                          bool is_off_the_record);
  ~PaintPreviewBaseService() override;

  // Returns the file manager for the directory associated with the service.
  FileManager* GetFileManager() { return &file_manager_; }

  // Returns whether the created service is off the record.
  bool IsOffTheRecord() const { return is_off_the_record_; }

  // Acquires the PaintPreviewProto that is associated with |url| and sends it
  // to |onReadProtoCallback|. Default implementation immediately sends nullptr
  // to |onReadProtoCallback|. Implementers of this class should override this
  // function. GetCapturedPaintPreviewProtoFromFile can be used if the proto is
  // saved on disk.
  virtual void GetCapturedPaintPreviewProto(
      const GURL& url,
      OnReadProtoCallback onReadProtoCallback);

  // Asynchronously deserializes PaintPreviewProto from |file_path| and sends it
  // to |onReadProtoCallback|.
  void GetCapturedPaintPreviewProtoFromFile(
      const base::FilePath& file_path,
      OnReadProtoCallback onReadProtoCallback);

  // The following methods both capture a Paint Preview; however, their behavior
  // and intended use is different. The first method is intended for capturing
  // full page contents. Generally, this is what you should be using for most
  // features. The second method is intended for capturing just an individual
  // RenderFrameHost and its descendents. This is intended for capturing
  // individual subframes and should be used for only a few use cases.
  //
  // NOTE: |root_dir| in the following methods should be created using
  // GetFileManager()->CreateOrGetDirectoryFor(<GURL>). However, to provide
  // flexibility in managing the lifetime of created objects and ease cleanup
  // if a capture fails the service implementation is responsible for
  // implementing this management and tracking the directories in existence.
  // Data in a directory will contain:
  // - a number of SKPs listed as <guid>.skp (one per frame)
  //
  // Captures the main frame of |web_contents| (an observer for capturing Paint
  // Previews is created for web contents if it does not exist). The capture is
  // attributed to the URL of the main frame and is stored in |root_dir|. The
  // captured area is clipped to |clip_rect| if it is non-zero. On completion
  // the status of the capture is provided via |callback|.
  void CapturePaintPreview(content::WebContents* web_contents,
                           const base::FilePath& root_dir,
                           gfx::Rect clip_rect,
                           OnCapturedCallback callback);
  // Same as above except |render_frame_host| is directly captured rather than
  // the main frame.
  void CapturePaintPreview(content::WebContents* web_contents,
                           content::RenderFrameHost* render_frame_host,
                           const base::FilePath& root_dir,
                           gfx::Rect clip_rect,
                           OnCapturedCallback callback);

  // Starts the compositor service in a utility process.
  std::unique_ptr<PaintPreviewCompositorService> StartCompositorService(
      base::OnceClosure disconnect_handler);

#if defined(OS_ANDROID)
  base::android::ScopedJavaGlobalRef<jobject> GetJavaObject() {
    return java_ref_;
  }
#endif  // defined(OS_ANDROID)

 private:
  void OnCaptured(base::TimeTicks start_time,
                  OnCapturedCallback callback,
                  base::UnguessableToken guid,
                  mojom::PaintPreviewStatus status,
                  std::unique_ptr<PaintPreviewProto> proto);

  std::unique_ptr<PaintPreviewPolicy> policy_ = nullptr;
  FileManager file_manager_;
  bool is_off_the_record_;

#if defined(OS_ANDROID)
  // Points to the Java reference.
  base::android::ScopedJavaGlobalRef<jobject> java_ref_;
#endif  // defined(OS_ANDROID)

  base::WeakPtrFactory<PaintPreviewBaseService> weak_ptr_factory_{this};

  PaintPreviewBaseService(const PaintPreviewBaseService&) = delete;
  PaintPreviewBaseService& operator=(const PaintPreviewBaseService&) = delete;
};

}  // namespace paint_preview

#endif  // COMPONENTS_PAINT_PREVIEW_BROWSER_PAINT_PREVIEW_BASE_SERVICE_H_
