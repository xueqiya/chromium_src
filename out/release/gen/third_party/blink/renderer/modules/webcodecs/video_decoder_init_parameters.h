// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_PARAMETERS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_PARAMETERS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT VideoDecoderInitParameters : public IDLDictionaryBase {
 public:
  static VideoDecoderInitParameters* Create() { return MakeGarbageCollected<VideoDecoderInitParameters>(); }

  VideoDecoderInitParameters();
  virtual ~VideoDecoderInitParameters();

  bool hasCodec() const { return !codec_.IsNull(); }
  const String& codec() const {
    return codec_;
  }
  inline void setCodec(const String&);

  bool hasHeight() const { return has_height_; }
  uint32_t height() const {
    DCHECK(has_height_);
    return height_;
  }
  inline void setHeight(uint32_t);

  bool hasProfile() const { return !profile_.IsNull(); }
  const String& profile() const {
    return profile_;
  }
  inline void setProfile(const String&);

  bool hasWidth() const { return has_width_; }
  uint32_t width() const {
    DCHECK(has_width_);
    return width_;
  }
  inline void setWidth(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_height_ = false;
  bool has_width_ = false;

  String codec_;
  uint32_t height_;
  String profile_;
  uint32_t width_;

  friend class V8VideoDecoderInitParameters;
};

void VideoDecoderInitParameters::setCodec(const String& value) {
  codec_ = value;
}

void VideoDecoderInitParameters::setHeight(uint32_t value) {
  height_ = value;
  has_height_ = true;
}

void VideoDecoderInitParameters::setProfile(const String& value) {
  profile_ = value;
}

void VideoDecoderInitParameters::setWidth(uint32_t value) {
  width_ = value;
  has_width_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_PARAMETERS_H_
