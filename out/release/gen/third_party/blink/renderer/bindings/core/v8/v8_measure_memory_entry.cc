// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory_entry.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8MeasureMemoryEntryKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "jsMemoryEstimate",
    "jsMemoryRange",
    "url",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8MeasureMemoryEntry::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MeasureMemoryEntry* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8MeasureMemoryEntryKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> js_memory_estimate_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&js_memory_estimate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (js_memory_estimate_value.IsEmpty() || js_memory_estimate_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t js_memory_estimate_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, js_memory_estimate_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setJSMemoryEstimate(js_memory_estimate_cpp_value);
  }

  v8::Local<v8::Value> js_memory_range_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&js_memory_range_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (js_memory_range_value.IsEmpty() || js_memory_range_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<uint64_t> js_memory_range_cpp_value = NativeValueTraits<IDLSequence<IDLUnsignedLongLong>>::NativeValue(isolate, js_memory_range_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setJSMemoryRange(js_memory_range_cpp_value);
  }

  v8::Local<v8::Value> url_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&url_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (url_value.IsEmpty() || url_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> url_cpp_value = url_value;
    if (!url_cpp_value.Prepare(exception_state))
      return;
    impl->setURL(url_cpp_value);
  }
}

v8::Local<v8::Value> MeasureMemoryEntry::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MeasureMemoryEntry(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MeasureMemoryEntry(const MeasureMemoryEntry* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8MeasureMemoryEntryKeys(isolate);
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

  v8::Local<v8::Value> js_memory_estimate_value;
  bool js_memory_estimate_has_value_or_default = false;
  if (impl->hasJSMemoryEstimate()) {
    js_memory_estimate_value = v8::Number::New(isolate, static_cast<double>(impl->jsMemoryEstimate()));
    js_memory_estimate_has_value_or_default = true;
  }
  if (js_memory_estimate_has_value_or_default &&
      !create_property(0, js_memory_estimate_value)) {
    return false;
  }

  v8::Local<v8::Value> js_memory_range_value;
  bool js_memory_range_has_value_or_default = false;
  if (impl->hasJSMemoryRange()) {
    js_memory_range_value = ToV8(impl->jsMemoryRange(), creationContext, isolate);
    js_memory_range_has_value_or_default = true;
  }
  if (js_memory_range_has_value_or_default &&
      !create_property(1, js_memory_range_value)) {
    return false;
  }

  v8::Local<v8::Value> url_value;
  bool url_has_value_or_default = false;
  if (impl->hasURL()) {
    url_value = V8String(isolate, impl->url());
    url_has_value_or_default = true;
  }
  if (url_has_value_or_default &&
      !create_property(2, url_value)) {
    return false;
  }

  return true;
}

MeasureMemoryEntry* NativeValueTraits<MeasureMemoryEntry>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MeasureMemoryEntry* impl = MakeGarbageCollected<MeasureMemoryEntry>();
  V8MeasureMemoryEntry::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
