// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/rendering_context.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_canvas_rendering_context_2d.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_canvas_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_image_bitmap_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl2_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_rendering_context.h"

namespace blink {

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext() : type_(SpecificType::kNone) {}

CanvasRenderingContext2D* CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::GetAsCanvasRenderingContext2D() const {
  DCHECK(IsCanvasRenderingContext2D());
  return canvas_rendering_context_2d_;
}

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SetCanvasRenderingContext2D(CanvasRenderingContext2D* value) {
  DCHECK(IsNull());
  canvas_rendering_context_2d_ = value;
  type_ = SpecificType::kCanvasRenderingContext2D;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::FromCanvasRenderingContext2D(CanvasRenderingContext2D* value) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext container;
  container.SetCanvasRenderingContext2D(value);
  return container;
}

GPUCanvasContext* CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::GetAsGPUCanvasContext() const {
  DCHECK(IsGPUCanvasContext());
  return gpu_canvas_context_;
}

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SetGPUCanvasContext(GPUCanvasContext* value) {
  DCHECK(IsNull());
  gpu_canvas_context_ = value;
  type_ = SpecificType::kGPUCanvasContext;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::FromGPUCanvasContext(GPUCanvasContext* value) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext container;
  container.SetGPUCanvasContext(value);
  return container;
}

ImageBitmapRenderingContext* CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::GetAsImageBitmapRenderingContext() const {
  DCHECK(IsImageBitmapRenderingContext());
  return image_bitmap_rendering_context_;
}

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SetImageBitmapRenderingContext(ImageBitmapRenderingContext* value) {
  DCHECK(IsNull());
  image_bitmap_rendering_context_ = value;
  type_ = SpecificType::kImageBitmapRenderingContext;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::FromImageBitmapRenderingContext(ImageBitmapRenderingContext* value) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext container;
  container.SetImageBitmapRenderingContext(value);
  return container;
}

WebGL2RenderingContext* CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::GetAsWebGL2RenderingContext() const {
  DCHECK(IsWebGL2RenderingContext());
  return webgl2_rendering_context_;
}

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SetWebGL2RenderingContext(WebGL2RenderingContext* value) {
  DCHECK(IsNull());
  webgl2_rendering_context_ = value;
  type_ = SpecificType::kWebGL2RenderingContext;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::FromWebGL2RenderingContext(WebGL2RenderingContext* value) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext container;
  container.SetWebGL2RenderingContext(value);
  return container;
}

WebGLRenderingContext* CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::GetAsWebGLRenderingContext() const {
  DCHECK(IsWebGLRenderingContext());
  return webgl_rendering_context_;
}

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SetWebGLRenderingContext(WebGLRenderingContext* value) {
  DCHECK(IsNull());
  webgl_rendering_context_ = value;
  type_ = SpecificType::kWebGLRenderingContext;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::FromWebGLRenderingContext(WebGLRenderingContext* value) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext container;
  container.SetWebGLRenderingContext(value);
  return container;
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext(const CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext&) = default;
CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::~CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext() = default;
CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext& CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::operator=(const CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext&) = default;

void CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::Trace(blink::Visitor* visitor) {
  visitor->Trace(canvas_rendering_context_2d_);
  visitor->Trace(gpu_canvas_context_);
  visitor->Trace(image_bitmap_rendering_context_);
  visitor->Trace(webgl2_rendering_context_);
  visitor->Trace(webgl_rendering_context_);
}

void V8CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8CanvasRenderingContext2D::HasInstance(v8_value, isolate)) {
    CanvasRenderingContext2D* cpp_value = V8CanvasRenderingContext2D::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetCanvasRenderingContext2D(cpp_value);
    return;
  }

  if (V8GPUCanvasContext::HasInstance(v8_value, isolate)) {
    GPUCanvasContext* cpp_value = V8GPUCanvasContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetGPUCanvasContext(cpp_value);
    return;
  }

  if (V8ImageBitmapRenderingContext::HasInstance(v8_value, isolate)) {
    ImageBitmapRenderingContext* cpp_value = V8ImageBitmapRenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetImageBitmapRenderingContext(cpp_value);
    return;
  }

  if (V8WebGL2RenderingContext::HasInstance(v8_value, isolate)) {
    WebGL2RenderingContext* cpp_value = V8WebGL2RenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWebGL2RenderingContext(cpp_value);
    return;
  }

  if (V8WebGLRenderingContext::HasInstance(v8_value, isolate)) {
    WebGLRenderingContext* cpp_value = V8WebGLRenderingContext::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWebGLRenderingContext(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(CanvasRenderingContext2D or WebGLRenderingContext or WebGL2RenderingContext or ImageBitmapRenderingContext or GPUCanvasContext)'");
}

v8::Local<v8::Value> ToV8(const CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kNone:
      return v8::Null(isolate);
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kCanvasRenderingContext2D:
      return ToV8(impl.GetAsCanvasRenderingContext2D(), creationContext, isolate);
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kGPUCanvasContext:
      return ToV8(impl.GetAsGPUCanvasContext(), creationContext, isolate);
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kImageBitmapRenderingContext:
      return ToV8(impl.GetAsImageBitmapRenderingContext(), creationContext, isolate);
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kWebGL2RenderingContext:
      return ToV8(impl.GetAsWebGL2RenderingContext(), creationContext, isolate);
    case CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::SpecificType::kWebGLRenderingContext:
      return ToV8(impl.GetAsWebGLRenderingContext(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext NativeValueTraits<CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext impl;
  V8CanvasRenderingContext2DOrWebGLRenderingContextOrWebGL2RenderingContextOrImageBitmapRenderingContextOrGPUCanvasContext::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

