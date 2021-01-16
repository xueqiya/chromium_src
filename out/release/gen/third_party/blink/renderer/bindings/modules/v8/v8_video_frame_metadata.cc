// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_frame_metadata.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8VideoFrameMetadataKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "captureTime",
    "elapsedProcessingTime",
    "expectedPresentationTime",
    "height",
    "presentationTime",
    "presentationTimestamp",
    "presentedFrames",
    "rtpTimestamp",
    "width",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8VideoFrameMetadata::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, VideoFrameMetadata* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): expectedPresentationTime, height, presentationTime, width.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8VideoFrameMetadataKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> capture_time_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&capture_time_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (capture_time_value.IsEmpty() || capture_time_value->IsUndefined()) {
    // Do nothing.
  } else {
    double capture_time_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, capture_time_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCaptureTime(capture_time_cpp_value);
  }

  v8::Local<v8::Value> elapsed_processing_time_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&elapsed_processing_time_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (elapsed_processing_time_value.IsEmpty() || elapsed_processing_time_value->IsUndefined()) {
    // Do nothing.
  } else {
    double elapsed_processing_time_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, elapsed_processing_time_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setElapsedProcessingTime(elapsed_processing_time_cpp_value);
  }

  v8::Local<v8::Value> expected_presentation_time_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&expected_presentation_time_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (expected_presentation_time_value.IsEmpty() || expected_presentation_time_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member expectedPresentationTime is undefined.");
    return;
  } else {
    double expected_presentation_time_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, expected_presentation_time_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setExpectedPresentationTime(expected_presentation_time_cpp_value);
  }

  v8::Local<v8::Value> height_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&height_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (height_value.IsEmpty() || height_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member height is undefined.");
    return;
  } else {
    uint32_t height_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, height_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHeight(height_cpp_value);
  }

  v8::Local<v8::Value> presentation_time_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&presentation_time_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (presentation_time_value.IsEmpty() || presentation_time_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member presentationTime is undefined.");
    return;
  } else {
    double presentation_time_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, presentation_time_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPresentationTime(presentation_time_cpp_value);
  }

  v8::Local<v8::Value> presentation_timestamp_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&presentation_timestamp_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (presentation_timestamp_value.IsEmpty() || presentation_timestamp_value->IsUndefined()) {
    // Do nothing.
  } else {
    double presentation_timestamp_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, presentation_timestamp_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPresentationTimestamp(presentation_timestamp_cpp_value);
  }

  v8::Local<v8::Value> presented_frames_value;
  if (!v8Object->Get(context, keys[6].Get(isolate)).ToLocal(&presented_frames_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (presented_frames_value.IsEmpty() || presented_frames_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t presented_frames_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, presented_frames_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPresentedFrames(presented_frames_cpp_value);
  }

  v8::Local<v8::Value> rtp_timestamp_value;
  if (!v8Object->Get(context, keys[7].Get(isolate)).ToLocal(&rtp_timestamp_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (rtp_timestamp_value.IsEmpty() || rtp_timestamp_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t rtp_timestamp_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, rtp_timestamp_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRtpTimestamp(rtp_timestamp_cpp_value);
  }

  v8::Local<v8::Value> width_value;
  if (!v8Object->Get(context, keys[8].Get(isolate)).ToLocal(&width_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (width_value.IsEmpty() || width_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member width is undefined.");
    return;
  } else {
    uint32_t width_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, width_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setWidth(width_cpp_value);
  }
}

v8::Local<v8::Value> VideoFrameMetadata::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VideoFrameMetadata(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VideoFrameMetadata(const VideoFrameMetadata* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8VideoFrameMetadataKeys(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> capture_time_value;
  bool capture_time_has_value_or_default = false;
  if (impl->hasCaptureTime()) {
    capture_time_value = v8::Number::New(isolate, impl->captureTime());
    capture_time_has_value_or_default = true;
  }
  if (capture_time_has_value_or_default &&
      !create_property(0, capture_time_value)) {
    return false;
  }

  v8::Local<v8::Value> elapsed_processing_time_value;
  bool elapsed_processing_time_has_value_or_default = false;
  if (impl->hasElapsedProcessingTime()) {
    elapsed_processing_time_value = v8::Number::New(isolate, impl->elapsedProcessingTime());
    elapsed_processing_time_has_value_or_default = true;
  }
  if (elapsed_processing_time_has_value_or_default &&
      !create_property(1, elapsed_processing_time_value)) {
    return false;
  }

  v8::Local<v8::Value> expected_presentation_time_value;
  bool expected_presentation_time_has_value_or_default = false;
  if (impl->hasExpectedPresentationTime()) {
    expected_presentation_time_value = v8::Number::New(isolate, impl->expectedPresentationTime());
    expected_presentation_time_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (expected_presentation_time_has_value_or_default &&
      !create_property(2, expected_presentation_time_value)) {
    return false;
  }

  v8::Local<v8::Value> height_value;
  bool height_has_value_or_default = false;
  if (impl->hasHeight()) {
    height_value = v8::Integer::NewFromUnsigned(isolate, impl->height());
    height_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (height_has_value_or_default &&
      !create_property(3, height_value)) {
    return false;
  }

  v8::Local<v8::Value> presentation_time_value;
  bool presentation_time_has_value_or_default = false;
  if (impl->hasPresentationTime()) {
    presentation_time_value = v8::Number::New(isolate, impl->presentationTime());
    presentation_time_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (presentation_time_has_value_or_default &&
      !create_property(4, presentation_time_value)) {
    return false;
  }

  v8::Local<v8::Value> presentation_timestamp_value;
  bool presentation_timestamp_has_value_or_default = false;
  if (impl->hasPresentationTimestamp()) {
    presentation_timestamp_value = v8::Number::New(isolate, impl->presentationTimestamp());
    presentation_timestamp_has_value_or_default = true;
  }
  if (presentation_timestamp_has_value_or_default &&
      !create_property(5, presentation_timestamp_value)) {
    return false;
  }

  v8::Local<v8::Value> presented_frames_value;
  bool presented_frames_has_value_or_default = false;
  if (impl->hasPresentedFrames()) {
    presented_frames_value = v8::Integer::NewFromUnsigned(isolate, impl->presentedFrames());
    presented_frames_has_value_or_default = true;
  }
  if (presented_frames_has_value_or_default &&
      !create_property(6, presented_frames_value)) {
    return false;
  }

  v8::Local<v8::Value> rtp_timestamp_value;
  bool rtp_timestamp_has_value_or_default = false;
  if (impl->hasRtpTimestamp()) {
    rtp_timestamp_value = v8::Integer::NewFromUnsigned(isolate, impl->rtpTimestamp());
    rtp_timestamp_has_value_or_default = true;
  }
  if (rtp_timestamp_has_value_or_default &&
      !create_property(7, rtp_timestamp_value)) {
    return false;
  }

  v8::Local<v8::Value> width_value;
  bool width_has_value_or_default = false;
  if (impl->hasWidth()) {
    width_value = v8::Integer::NewFromUnsigned(isolate, impl->width());
    width_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (width_has_value_or_default &&
      !create_property(8, width_value)) {
    return false;
  }

  return true;
}

VideoFrameMetadata* NativeValueTraits<VideoFrameMetadata>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  VideoFrameMetadata* impl = MakeGarbageCollected<VideoFrameMetadata>();
  V8VideoFrameMetadata::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
