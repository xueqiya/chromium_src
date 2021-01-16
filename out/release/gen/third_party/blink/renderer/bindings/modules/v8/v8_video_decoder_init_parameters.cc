// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_decoder_init_parameters.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8VideoDecoderInitParametersKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "codec",
    "height",
    "profile",
    "width",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8VideoDecoderInitParameters::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, VideoDecoderInitParameters* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8VideoDecoderInitParametersKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> codec_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&codec_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (codec_value.IsEmpty() || codec_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> codec_cpp_value = codec_value;
    if (!codec_cpp_value.Prepare(exception_state))
      return;
    impl->setCodec(codec_cpp_value);
  }

  v8::Local<v8::Value> height_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&height_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (height_value.IsEmpty() || height_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t height_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, height_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHeight(height_cpp_value);
  }

  v8::Local<v8::Value> profile_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&profile_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (profile_value.IsEmpty() || profile_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> profile_cpp_value = profile_value;
    if (!profile_cpp_value.Prepare(exception_state))
      return;
    impl->setProfile(profile_cpp_value);
  }

  v8::Local<v8::Value> width_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&width_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (width_value.IsEmpty() || width_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t width_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, width_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setWidth(width_cpp_value);
  }
}

v8::Local<v8::Value> VideoDecoderInitParameters::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VideoDecoderInitParameters(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VideoDecoderInitParameters(const VideoDecoderInitParameters* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8VideoDecoderInitParametersKeys(isolate);
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

  v8::Local<v8::Value> codec_value;
  bool codec_has_value_or_default = false;
  if (impl->hasCodec()) {
    codec_value = V8String(isolate, impl->codec());
    codec_has_value_or_default = true;
  }
  if (codec_has_value_or_default &&
      !create_property(0, codec_value)) {
    return false;
  }

  v8::Local<v8::Value> height_value;
  bool height_has_value_or_default = false;
  if (impl->hasHeight()) {
    height_value = v8::Integer::NewFromUnsigned(isolate, impl->height());
    height_has_value_or_default = true;
  }
  if (height_has_value_or_default &&
      !create_property(1, height_value)) {
    return false;
  }

  v8::Local<v8::Value> profile_value;
  bool profile_has_value_or_default = false;
  if (impl->hasProfile()) {
    profile_value = V8String(isolate, impl->profile());
    profile_has_value_or_default = true;
  }
  if (profile_has_value_or_default &&
      !create_property(2, profile_value)) {
    return false;
  }

  v8::Local<v8::Value> width_value;
  bool width_has_value_or_default = false;
  if (impl->hasWidth()) {
    width_value = v8::Integer::NewFromUnsigned(isolate, impl->width());
    width_has_value_or_default = true;
  }
  if (width_has_value_or_default &&
      !create_property(3, width_value)) {
    return false;
  }

  return true;
}

VideoDecoderInitParameters* NativeValueTraits<VideoDecoderInitParameters>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  VideoDecoderInitParameters* impl = MakeGarbageCollected<VideoDecoderInitParameters>();
  V8VideoDecoderInitParameters::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
