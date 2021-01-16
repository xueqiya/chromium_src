// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory_entry.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8MeasureMemoryKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "current",
    "other",
    "total",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8MeasureMemory::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MeasureMemory* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): total.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8MeasureMemoryKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> current_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&current_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (current_value.IsEmpty() || current_value->IsUndefined()) {
    // Do nothing.
  } else {
    MeasureMemoryEntry* current_cpp_value = NativeValueTraits<MeasureMemoryEntry>::NativeValue(isolate, current_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCurrent(current_cpp_value);
  }

  v8::Local<v8::Value> other_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&other_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (other_value.IsEmpty() || other_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<Member<MeasureMemoryEntry>> other_cpp_value = NativeValueTraits<IDLSequence<MeasureMemoryEntry>>::NativeValue(isolate, other_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOther(other_cpp_value);
  }

  v8::Local<v8::Value> total_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&total_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (total_value.IsEmpty() || total_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member total is undefined.");
    return;
  } else {
    MeasureMemoryEntry* total_cpp_value = NativeValueTraits<MeasureMemoryEntry>::NativeValue(isolate, total_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setTotal(total_cpp_value);
  }
}

v8::Local<v8::Value> MeasureMemory::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MeasureMemory(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MeasureMemory(const MeasureMemory* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8MeasureMemoryKeys(isolate);
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

  v8::Local<v8::Value> current_value;
  bool current_has_value_or_default = false;
  if (impl->hasCurrent()) {
    current_value = ToV8(impl->current(), creationContext, isolate);
    current_has_value_or_default = true;
  }
  if (current_has_value_or_default &&
      !create_property(0, current_value)) {
    return false;
  }

  v8::Local<v8::Value> other_value;
  bool other_has_value_or_default = false;
  if (impl->hasOther()) {
    other_value = ToV8(impl->other(), creationContext, isolate);
    other_has_value_or_default = true;
  }
  if (other_has_value_or_default &&
      !create_property(1, other_value)) {
    return false;
  }

  v8::Local<v8::Value> total_value;
  bool total_has_value_or_default = false;
  if (impl->hasTotal()) {
    total_value = ToV8(impl->total(), creationContext, isolate);
    total_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (total_has_value_or_default &&
      !create_property(2, total_value)) {
    return false;
  }

  return true;
}

MeasureMemory* NativeValueTraits<MeasureMemory>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MeasureMemory* impl = MakeGarbageCollected<MeasureMemory>();
  V8MeasureMemory::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
