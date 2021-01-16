// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/unsigned_long_sequence_or_gpu_origin_3d_dict.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_iterator.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

UnsignedLongSequenceOrGPUOrigin3DDict::UnsignedLongSequenceOrGPUOrigin3DDict() : type_(SpecificType::kNone) {}

GPUOrigin3DDict* UnsignedLongSequenceOrGPUOrigin3DDict::GetAsGPUOrigin3DDict() const {
  DCHECK(IsGPUOrigin3DDict());
  return gpu_origin_3d_dict_;
}

void UnsignedLongSequenceOrGPUOrigin3DDict::SetGPUOrigin3DDict(GPUOrigin3DDict* value) {
  DCHECK(IsNull());
  gpu_origin_3d_dict_ = value;
  type_ = SpecificType::kGPUOrigin3DDict;
}

UnsignedLongSequenceOrGPUOrigin3DDict UnsignedLongSequenceOrGPUOrigin3DDict::FromGPUOrigin3DDict(GPUOrigin3DDict* value) {
  UnsignedLongSequenceOrGPUOrigin3DDict container;
  container.SetGPUOrigin3DDict(value);
  return container;
}

const Vector<uint32_t>& UnsignedLongSequenceOrGPUOrigin3DDict::GetAsUnsignedLongSequence() const {
  DCHECK(IsUnsignedLongSequence());
  return unsigned_long_sequence_;
}

void UnsignedLongSequenceOrGPUOrigin3DDict::SetUnsignedLongSequence(const Vector<uint32_t>& value) {
  DCHECK(IsNull());
  unsigned_long_sequence_ = value;
  type_ = SpecificType::kUnsignedLongSequence;
}

UnsignedLongSequenceOrGPUOrigin3DDict UnsignedLongSequenceOrGPUOrigin3DDict::FromUnsignedLongSequence(const Vector<uint32_t>& value) {
  UnsignedLongSequenceOrGPUOrigin3DDict container;
  container.SetUnsignedLongSequence(value);
  return container;
}

UnsignedLongSequenceOrGPUOrigin3DDict::UnsignedLongSequenceOrGPUOrigin3DDict(const UnsignedLongSequenceOrGPUOrigin3DDict&) = default;
UnsignedLongSequenceOrGPUOrigin3DDict::~UnsignedLongSequenceOrGPUOrigin3DDict() = default;
UnsignedLongSequenceOrGPUOrigin3DDict& UnsignedLongSequenceOrGPUOrigin3DDict::operator=(const UnsignedLongSequenceOrGPUOrigin3DDict&) = default;

void UnsignedLongSequenceOrGPUOrigin3DDict::Trace(blink::Visitor* visitor) {
  visitor->Trace(gpu_origin_3d_dict_);
}

void V8UnsignedLongSequenceOrGPUOrigin3DDict::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    UnsignedLongSequenceOrGPUOrigin3DDict& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    GPUOrigin3DDict* cpp_value = NativeValueTraits<GPUOrigin3DDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUOrigin3DDict(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    ScriptIterator script_iterator = ScriptIterator::FromIterable(
        isolate, v8_value.As<v8::Object>(), exception_state);
    if (exception_state.HadException())
      return;
    if (!script_iterator.IsNull()) {
      Vector<uint32_t> cpp_value = NativeValueTraits<IDLSequence<IDLUnsignedLong>>::NativeValue(isolate, std::move(script_iterator), exception_state);
      if (exception_state.HadException())
        return;
      impl.SetUnsignedLongSequence(cpp_value);
      return;
    }
  }

  if (v8_value->IsObject()) {
    GPUOrigin3DDict* cpp_value = NativeValueTraits<GPUOrigin3DDict>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetGPUOrigin3DDict(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(sequence<unsigned long> or GPUOrigin3DDict)'");
}

v8::Local<v8::Value> ToV8(const UnsignedLongSequenceOrGPUOrigin3DDict& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case UnsignedLongSequenceOrGPUOrigin3DDict::SpecificType::kNone:
      return v8::Null(isolate);
    case UnsignedLongSequenceOrGPUOrigin3DDict::SpecificType::kGPUOrigin3DDict:
      return ToV8(impl.GetAsGPUOrigin3DDict(), creationContext, isolate);
    case UnsignedLongSequenceOrGPUOrigin3DDict::SpecificType::kUnsignedLongSequence:
      return ToV8(impl.GetAsUnsignedLongSequence(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

UnsignedLongSequenceOrGPUOrigin3DDict NativeValueTraits<UnsignedLongSequenceOrGPUOrigin3DDict>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  UnsignedLongSequenceOrGPUOrigin3DDict impl;
  V8UnsignedLongSequenceOrGPUOrigin3DDict::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

