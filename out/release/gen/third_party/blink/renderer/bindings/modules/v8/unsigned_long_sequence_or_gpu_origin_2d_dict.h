// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_origin_2d_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT UnsignedLongSequenceOrGPUOrigin2DDict final {
  DISALLOW_NEW();
 public:
  UnsignedLongSequenceOrGPUOrigin2DDict();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsGPUOrigin2DDict() const { return type_ == SpecificType::kGPUOrigin2DDict; }
  GPUOrigin2DDict* GetAsGPUOrigin2DDict() const;
  void SetGPUOrigin2DDict(GPUOrigin2DDict*);
  static UnsignedLongSequenceOrGPUOrigin2DDict FromGPUOrigin2DDict(GPUOrigin2DDict*);

  bool IsUnsignedLongSequence() const { return type_ == SpecificType::kUnsignedLongSequence; }
  const Vector<uint32_t>& GetAsUnsignedLongSequence() const;
  void SetUnsignedLongSequence(const Vector<uint32_t>&);
  static UnsignedLongSequenceOrGPUOrigin2DDict FromUnsignedLongSequence(const Vector<uint32_t>&);

  UnsignedLongSequenceOrGPUOrigin2DDict(const UnsignedLongSequenceOrGPUOrigin2DDict&);
  ~UnsignedLongSequenceOrGPUOrigin2DDict();
  UnsignedLongSequenceOrGPUOrigin2DDict& operator=(const UnsignedLongSequenceOrGPUOrigin2DDict&);
  void Trace(blink::Visitor*);

 private:
  enum class SpecificType {
    kNone,
    kGPUOrigin2DDict,
    kUnsignedLongSequence,
  };
  SpecificType type_;

  Member<GPUOrigin2DDict> gpu_origin_2d_dict_;
  Vector<uint32_t> unsigned_long_sequence_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongSequenceOrGPUOrigin2DDict&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8UnsignedLongSequenceOrGPUOrigin2DDict final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, UnsignedLongSequenceOrGPUOrigin2DDict&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongSequenceOrGPUOrigin2DDict&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongSequenceOrGPUOrigin2DDict& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongSequenceOrGPUOrigin2DDict& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<UnsignedLongSequenceOrGPUOrigin2DDict> : public NativeValueTraitsBase<UnsignedLongSequenceOrGPUOrigin2DDict> {
  MODULES_EXPORT static UnsignedLongSequenceOrGPUOrigin2DDict NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static UnsignedLongSequenceOrGPUOrigin2DDict NullValue() { return UnsignedLongSequenceOrGPUOrigin2DDict(); }
};

template <>
struct V8TypeOf<UnsignedLongSequenceOrGPUOrigin2DDict> {
  typedef V8UnsignedLongSequenceOrGPUOrigin2DDict Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::UnsignedLongSequenceOrGPUOrigin2DDict)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_
