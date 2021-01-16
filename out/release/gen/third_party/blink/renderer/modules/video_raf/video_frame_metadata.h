// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_VIDEO_RAF_VIDEO_FRAME_METADATA_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_VIDEO_RAF_VIDEO_FRAME_METADATA_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT VideoFrameMetadata : public IDLDictionaryBase {
 public:
  static VideoFrameMetadata* Create() { return MakeGarbageCollected<VideoFrameMetadata>(); }

  VideoFrameMetadata();
  virtual ~VideoFrameMetadata();

  bool hasCaptureTime() const { return has_capture_time_; }
  double captureTime() const {
    DCHECK(has_capture_time_);
    return capture_time_;
  }
  inline void setCaptureTime(double);

  bool hasElapsedProcessingTime() const { return has_elapsed_processing_time_; }
  double elapsedProcessingTime() const {
    DCHECK(has_elapsed_processing_time_);
    return elapsed_processing_time_;
  }
  inline void setElapsedProcessingTime(double);

  bool hasExpectedPresentationTime() const { return has_expected_presentation_time_; }
  double expectedPresentationTime() const {
    DCHECK(has_expected_presentation_time_);
    return expected_presentation_time_;
  }
  inline void setExpectedPresentationTime(double);

  bool hasHeight() const { return has_height_; }
  uint32_t height() const {
    DCHECK(has_height_);
    return height_;
  }
  inline void setHeight(uint32_t);

  bool hasPresentationTime() const { return has_presentation_time_; }
  double presentationTime() const {
    DCHECK(has_presentation_time_);
    return presentation_time_;
  }
  inline void setPresentationTime(double);

  bool hasPresentationTimestamp() const { return has_presentation_timestamp_; }
  double presentationTimestamp() const {
    DCHECK(has_presentation_timestamp_);
    return presentation_timestamp_;
  }
  inline void setPresentationTimestamp(double);

  bool hasPresentedFrames() const { return has_presented_frames_; }
  uint32_t presentedFrames() const {
    DCHECK(has_presented_frames_);
    return presented_frames_;
  }
  inline void setPresentedFrames(uint32_t);

  bool hasRtpTimestamp() const { return has_rtp_timestamp_; }
  uint32_t rtpTimestamp() const {
    DCHECK(has_rtp_timestamp_);
    return rtp_timestamp_;
  }
  inline void setRtpTimestamp(uint32_t);

  bool hasWidth() const { return has_width_; }
  uint32_t width() const {
    DCHECK(has_width_);
    return width_;
  }
  inline void setWidth(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_capture_time_ = false;
  bool has_elapsed_processing_time_ = false;
  bool has_expected_presentation_time_ = false;
  bool has_height_ = false;
  bool has_presentation_time_ = false;
  bool has_presentation_timestamp_ = false;
  bool has_presented_frames_ = false;
  bool has_rtp_timestamp_ = false;
  bool has_width_ = false;

  double capture_time_;
  double elapsed_processing_time_;
  double expected_presentation_time_;
  uint32_t height_;
  double presentation_time_;
  double presentation_timestamp_;
  uint32_t presented_frames_;
  uint32_t rtp_timestamp_;
  uint32_t width_;

  friend class V8VideoFrameMetadata;
};

void VideoFrameMetadata::setCaptureTime(double value) {
  capture_time_ = value;
  has_capture_time_ = true;
}

void VideoFrameMetadata::setElapsedProcessingTime(double value) {
  elapsed_processing_time_ = value;
  has_elapsed_processing_time_ = true;
}

void VideoFrameMetadata::setExpectedPresentationTime(double value) {
  expected_presentation_time_ = value;
  has_expected_presentation_time_ = true;
}

void VideoFrameMetadata::setHeight(uint32_t value) {
  height_ = value;
  has_height_ = true;
}

void VideoFrameMetadata::setPresentationTime(double value) {
  presentation_time_ = value;
  has_presentation_time_ = true;
}

void VideoFrameMetadata::setPresentationTimestamp(double value) {
  presentation_timestamp_ = value;
  has_presentation_timestamp_ = true;
}

void VideoFrameMetadata::setPresentedFrames(uint32_t value) {
  presented_frames_ = value;
  has_presented_frames_ = true;
}

void VideoFrameMetadata::setRtpTimestamp(uint32_t value) {
  rtp_timestamp_ = value;
  has_rtp_timestamp_ = true;
}

void VideoFrameMetadata::setWidth(uint32_t value) {
  width_ = value;
  has_width_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_VIDEO_RAF_VIDEO_FRAME_METADATA_H_
