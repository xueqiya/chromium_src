// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_SHADER_MODULE_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_SHADER_MODULE_DESCRIPTOR_H_

#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_typed_array.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT GPUShaderModuleDescriptor : public GPUObjectDescriptorBase {
 public:
  static GPUShaderModuleDescriptor* Create() { return MakeGarbageCollected<GPUShaderModuleDescriptor>(); }

  GPUShaderModuleDescriptor();
  virtual ~GPUShaderModuleDescriptor();

  bool hasCode() const { return code_; }
  MaybeShared<DOMUint32Array> code() const {
    return code_;
  }
  inline void setCode(MaybeShared<DOMUint32Array>);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:

  Member<DOMUint32Array> code_;

  friend class V8GPUShaderModuleDescriptor;
};

void GPUShaderModuleDescriptor::setCode(MaybeShared<DOMUint32Array> value) {
  code_ = value.View();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_SHADER_MODULE_DESCRIPTOR_H_
