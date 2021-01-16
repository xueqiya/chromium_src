// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_sample.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8ProfilerSampleKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "stackId",
    "timestamp",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8ProfilerSample::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ProfilerSample* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): timestamp.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8ProfilerSampleKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> stack_id_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&stack_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (stack_id_value.IsEmpty() || stack_id_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t stack_id_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, stack_id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setStackId(stack_id_cpp_value);
  }

  v8::Local<v8::Value> timestamp_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&timestamp_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (timestamp_value.IsEmpty() || timestamp_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member timestamp is undefined.");
    return;
  } else {
    double timestamp_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, timestamp_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setTimestamp(timestamp_cpp_value);
  }
}

v8::Local<v8::Value> ProfilerSample::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ProfilerSample(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ProfilerSample(const ProfilerSample* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8ProfilerSampleKeys(isolate);
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

  v8::Local<v8::Value> stack_id_value;
  bool stack_id_has_value_or_default = false;
  if (impl->hasStackId()) {
    stack_id_value = v8::Number::New(isolate, static_cast<double>(impl->stackId()));
    stack_id_has_value_or_default = true;
  }
  if (stack_id_has_value_or_default &&
      !create_property(0, stack_id_value)) {
    return false;
  }

  v8::Local<v8::Value> timestamp_value;
  bool timestamp_has_value_or_default = false;
  if (impl->hasTimestamp()) {
    timestamp_value = v8::Number::New(isolate, impl->timestamp());
    timestamp_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (timestamp_has_value_or_default &&
      !create_property(1, timestamp_value)) {
    return false;
  }

  return true;
}

ProfilerSample* NativeValueTraits<ProfilerSample>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ProfilerSample* impl = MakeGarbageCollected<ProfilerSample>();
  V8ProfilerSample::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
