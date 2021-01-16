// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_EXTENT_3D_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_EXTENT_3D_DICT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_extent_3d_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT UnsignedLongSequenceOrGPUExtent3DDict final {
  DISALLOW_NEW();
 public:
  UnsignedLongSequenceOrGPUExtent3DDict();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsGPUExtent3DDict() const { return type_ == SpecificType::kGPUExtent3DDict; }
  GPUExtent3DDict* GetAsGPUExtent3DDict() const;
  void SetGPUExtent3DDict(GPUExtent3DDict*);
  static UnsignedLongSequenceOrGPUExtent3DDict FromGPUExtent3DDict(GPUExtent3DDict*);

  bool IsUnsignedLongSequence() const { return type_ == SpecificType::kUnsignedLongSequence; }
  const Vector<uint32_t>& GetAsUnsignedLongSequence() const;
  void SetUnsignedLongSequence(const Vector<uint32_t>&);
  static UnsignedLongSequenceOrGPUExtent3DDict FromUnsignedLongSequence(const Vector<uint32_t>&);

  UnsignedLongSequenceOrGPUExtent3DDict(const UnsignedLongSequenceOrGPUExtent3DDict&);
  ~UnsignedLongSequenceOrGPUExtent3DDict();
  UnsignedLongSequenceOrGPUExtent3DDict& operator=(const UnsignedLongSequenceOrGPUExtent3DDict&);
  void Trace(blink::Visitor*);

 private:
  enum class SpecificType {
    kNone,
    kGPUExtent3DDict,
    kUnsignedLongSequence,
  };
  SpecificType type_;

  Member<GPUExtent3DDict> gpu_extent_3d_dict_;
  Vector<uint32_t> unsigned_long_sequence_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongSequenceOrGPUExtent3DDict&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8UnsignedLongSequenceOrGPUExtent3DDict final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, UnsignedLongSequenceOrGPUExtent3DDict&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongSequenceOrGPUExtent3DDict&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongSequenceOrGPUExtent3DDict& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongSequenceOrGPUExtent3DDict& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<UnsignedLongSequenceOrGPUExtent3DDict> : public NativeValueTraitsBase<UnsignedLongSequenceOrGPUExtent3DDict> {
  MODULES_EXPORT static UnsignedLongSequenceOrGPUExtent3DDict NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static UnsignedLongSequenceOrGPUExtent3DDict NullValue() { return UnsignedLongSequenceOrGPUExtent3DDict(); }
};

template <>
struct V8TypeOf<UnsignedLongSequenceOrGPUExtent3DDict> {
  typedef V8UnsignedLongSequenceOrGPUExtent3DDict Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::UnsignedLongSequenceOrGPUExtent3DDict)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_EXTENT_3D_DICT_H_
