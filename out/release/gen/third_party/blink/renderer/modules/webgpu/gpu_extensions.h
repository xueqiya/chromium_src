// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_EXTENSIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_EXTENSIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT GPUExtensions : public IDLDictionaryBase {
 public:
  static GPUExtensions* Create() { return MakeGarbageCollected<GPUExtensions>(); }

  GPUExtensions();
  virtual ~GPUExtensions();

  bool hasTextureCompressionBC() const { return has_texture_compression_bc_; }
  bool textureCompressionBC() const {
    DCHECK(has_texture_compression_bc_);
    return texture_compression_bc_;
  }
  inline void setTextureCompressionBC(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_texture_compression_bc_ = false;

  bool texture_compression_bc_;

  friend class V8GPUExtensions;
};

void GPUExtensions::setTextureCompressionBC(bool value) {
  texture_compression_bc_ = value;
  has_texture_compression_bc_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_EXTENSIONS_H_
