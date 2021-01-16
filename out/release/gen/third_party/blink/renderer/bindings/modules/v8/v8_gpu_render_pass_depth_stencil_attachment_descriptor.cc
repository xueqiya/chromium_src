// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pass_depth_stencil_attachment_descriptor.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8GPURenderPassDepthStencilAttachmentDescriptorKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "attachment",
    "depthLoadValue",
    "depthStoreOp",
    "stencilLoadValue",
    "stencilStoreOp",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8GPURenderPassDepthStencilAttachmentDescriptor::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPURenderPassDepthStencilAttachmentDescriptor* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): attachment, depthLoadValue, depthStoreOp, stencilLoadValue, stencilStoreOp.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8GPURenderPassDepthStencilAttachmentDescriptorKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> attachment_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&attachment_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (attachment_value.IsEmpty() || attachment_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member attachment is undefined.");
    return;
  } else {
    GPUTextureView* attachment_cpp_value = V8GPUTextureView::ToImplWithTypeCheck(isolate, attachment_value);
    if (!attachment_cpp_value) {
      exception_state.ThrowTypeError("member attachment is not of type GPUTextureView.");
      return;
    }
    impl->setAttachment(attachment_cpp_value);
  }

  v8::Local<v8::Value> depth_load_value_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&depth_load_value_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (depth_load_value_value.IsEmpty() || depth_load_value_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member depthLoadValue is undefined.");
    return;
  } else {
    GPULoadOpOrFloat depth_load_value_cpp_value;
    V8GPULoadOpOrFloat::ToImpl(isolate, depth_load_value_value, depth_load_value_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDepthLoadValue(depth_load_value_cpp_value);
  }

  v8::Local<v8::Value> depth_store_op_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&depth_store_op_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (depth_store_op_value.IsEmpty() || depth_store_op_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member depthStoreOp is undefined.");
    return;
  } else {
    V8StringResource<> depth_store_op_cpp_value = depth_store_op_value;
    if (!depth_store_op_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "store",
        "clear",
    };
    if (!IsValidEnum(depth_store_op_cpp_value, kValidValues, base::size(kValidValues), "GPUStoreOp", exception_state))
      return;
    impl->setDepthStoreOp(depth_store_op_cpp_value);
  }

  v8::Local<v8::Value> stencil_load_value_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&stencil_load_value_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (stencil_load_value_value.IsEmpty() || stencil_load_value_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member stencilLoadValue is undefined.");
    return;
  } else {
    GPULoadOpOrUnsignedLong stencil_load_value_cpp_value;
    V8GPULoadOpOrUnsignedLong::ToImpl(isolate, stencil_load_value_value, stencil_load_value_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setStencilLoadValue(stencil_load_value_cpp_value);
  }

  v8::Local<v8::Value> stencil_store_op_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&stencil_store_op_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (stencil_store_op_value.IsEmpty() || stencil_store_op_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member stencilStoreOp is undefined.");
    return;
  } else {
    V8StringResource<> stencil_store_op_cpp_value = stencil_store_op_value;
    if (!stencil_store_op_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "store",
        "clear",
    };
    if (!IsValidEnum(stencil_store_op_cpp_value, kValidValues, base::size(kValidValues), "GPUStoreOp", exception_state))
      return;
    impl->setStencilStoreOp(stencil_store_op_cpp_value);
  }
}

v8::Local<v8::Value> GPURenderPassDepthStencilAttachmentDescriptor::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPURenderPassDepthStencilAttachmentDescriptor(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPURenderPassDepthStencilAttachmentDescriptor(const GPURenderPassDepthStencilAttachmentDescriptor* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8GPURenderPassDepthStencilAttachmentDescriptorKeys(isolate);
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

  v8::Local<v8::Value> attachment_value;
  bool attachment_has_value_or_default = false;
  if (impl->hasAttachment()) {
    attachment_value = ToV8(impl->attachment(), creationContext, isolate);
    attachment_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (attachment_has_value_or_default &&
      !create_property(0, attachment_value)) {
    return false;
  }

  v8::Local<v8::Value> depth_load_value_value;
  bool depth_load_value_has_value_or_default = false;
  if (impl->hasDepthLoadValue()) {
    depth_load_value_value = ToV8(impl->depthLoadValue(), creationContext, isolate);
    depth_load_value_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (depth_load_value_has_value_or_default &&
      !create_property(1, depth_load_value_value)) {
    return false;
  }

  v8::Local<v8::Value> depth_store_op_value;
  bool depth_store_op_has_value_or_default = false;
  if (impl->hasDepthStoreOp()) {
    depth_store_op_value = V8String(isolate, impl->depthStoreOp());
    depth_store_op_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (depth_store_op_has_value_or_default &&
      !create_property(2, depth_store_op_value)) {
    return false;
  }

  v8::Local<v8::Value> stencil_load_value_value;
  bool stencil_load_value_has_value_or_default = false;
  if (impl->hasStencilLoadValue()) {
    stencil_load_value_value = ToV8(impl->stencilLoadValue(), creationContext, isolate);
    stencil_load_value_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (stencil_load_value_has_value_or_default &&
      !create_property(3, stencil_load_value_value)) {
    return false;
  }

  v8::Local<v8::Value> stencil_store_op_value;
  bool stencil_store_op_has_value_or_default = false;
  if (impl->hasStencilStoreOp()) {
    stencil_store_op_value = V8String(isolate, impl->stencilStoreOp());
    stencil_store_op_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (stencil_store_op_has_value_or_default &&
      !create_property(4, stencil_store_op_value)) {
    return false;
  }

  return true;
}

GPURenderPassDepthStencilAttachmentDescriptor* NativeValueTraits<GPURenderPassDepthStencilAttachmentDescriptor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPURenderPassDepthStencilAttachmentDescriptor* impl = MakeGarbageCollected<GPURenderPassDepthStencilAttachmentDescriptor>();
  V8GPURenderPassDepthStencilAttachmentDescriptor::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
