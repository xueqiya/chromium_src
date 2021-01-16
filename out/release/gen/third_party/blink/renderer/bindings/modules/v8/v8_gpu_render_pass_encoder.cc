// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pass_encoder.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_uint32_array.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_color_dict.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pipeline.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/scheduler/public/cooperative_scheduling_manager.h"
#include "third_party/blink/renderer/platform/wtf/get_ptr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo v8_gpu_render_pass_encoder_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8GPURenderPassEncoder::DomTemplate,
    nullptr,
    "GPURenderPassEncoder",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GPURenderPassEncoder.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& GPURenderPassEncoder::wrapper_type_info_ = v8_gpu_render_pass_encoder_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GPURenderPassEncoder>::value,
    "GPURenderPassEncoder inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GPURenderPassEncoder::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "GPURenderPassEncoder is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace gpu_render_pass_encoder_v8_internal {

static void SetViewportMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setViewport");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 6)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(6, info.Length()));
    return;
  }

  float x;
  float y;
  float width;
  float height;
  float min_depth;
  float max_depth;
  x = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  y = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  width = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  height = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  min_depth = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  max_depth = NativeValueTraits<IDLFloat>::NativeValue(info.GetIsolate(), info[5], exception_state);
  if (exception_state.HadException())
    return;

  impl->setViewport(x, y, width, height, min_depth, max_depth);
}

static void SetScissorRectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setScissorRect");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 4)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(4, info.Length()));
    return;
  }

  uint32_t x;
  uint32_t y;
  uint32_t width;
  uint32_t height;
  x = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  y = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  width = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  height = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  impl->setScissorRect(x, y, width, height);
}

static void SetBlendColorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setBlendColor");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  DoubleSequenceOrGPUColorDict color;
  V8DoubleSequenceOrGPUColorDict::ToImpl(info.GetIsolate(), info[0], color, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  impl->setBlendColor(color, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void SetStencilReferenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setStencilReference");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  uint32_t reference;
  reference = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setStencilReference(reference);
}

static void ExecuteBundlesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "executeBundles");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  HeapVector<Member<GPURenderBundle>> bundles;
  bundles = NativeValueTraits<IDLSequence<GPURenderBundle>>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->executeBundles(bundles);
}

static void EndPassMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  impl->endPass();
}

static void SetBindGroup1Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setBindGroup");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  uint32_t index;
  GPUBindGroup* bind_group;
  Vector<uint32_t> dynamic_offsets;
  index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  bind_group = V8GPUBindGroup::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!bind_group) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBindGroup"));
    return;
  }

  if (!info[2]->IsUndefined()) {
    dynamic_offsets = NativeValueTraits<IDLSequence<IDLUnsignedLong>>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    /* Nothing to do */;
  }

  impl->setBindGroup(index, bind_group, dynamic_offsets);
}

static void SetBindGroup2Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setBindGroup");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  uint32_t index;
  GPUBindGroup* bind_group;
  FlexibleUint32ArrayView dynamic_offsets_data;
  uint64_t dynamic_offsets_data_start;
  uint32_t dynamic_offsets_data_length;
  index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  bind_group = V8GPUBindGroup::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!bind_group) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBindGroup"));
    return;
  }

  ToFlexibleArrayBufferView(info.GetIsolate(), info[2], dynamic_offsets_data, allocateFlexibleArrayBufferViewStorage(info[2]));
  if (!dynamic_offsets_data) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(2, "Uint32Array"));
    return;
  }

  dynamic_offsets_data_start = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  dynamic_offsets_data_length = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->setBindGroup(index, bind_group, dynamic_offsets_data, dynamic_offsets_data_start, dynamic_offsets_data_length, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void SetBindGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  scheduler::CooperativeSchedulingManager::Instance()->Safepoint();

  bool is_arity_error = false;

  switch (std::min(5, info.Length())) {
    case 2:
      if (true) {
        SetBindGroup1Method(info);
        return;
      }
      break;
    case 3:
      if (true) {
        SetBindGroup1Method(info);
        return;
      }
      break;
    case 5:
      if (true) {
        SetBindGroup2Method(info);
        return;
      }
      break;
    default:
      is_arity_error = true;
  }

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setBindGroup");
  if (is_arity_error) {
    if (info.Length() < 2) {
      exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
      return;
    }
    if (info.Length() >= 2) {
      exception_state.ThrowTypeError(ExceptionMessages::InvalidArity("[2, 3, 5]", info.Length()));
      return;
    }
  }
  exception_state.ThrowTypeError("No function was found that matched the signature provided.");
}

static void PushDebugGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("pushDebugGroup", "GPURenderPassEncoder", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> group_label;
  group_label = info[0];
  if (!group_label.Prepare())
    return;

  impl->pushDebugGroup(group_label);
}

static void PopDebugGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  impl->popDebugGroup();
}

static void InsertDebugMarkerMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("insertDebugMarker", "GPURenderPassEncoder", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> marker_label;
  marker_label = info[0];
  if (!marker_label.Prepare())
    return;

  impl->insertDebugMarker(marker_label);
}

static void SetPipelineMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPURenderPassEncoder", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  GPURenderPipeline* pipeline;
  pipeline = V8GPURenderPipeline::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!pipeline) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPURenderPassEncoder", ExceptionMessages::ArgumentNotOfType(0, "GPURenderPipeline")));
    return;
  }

  impl->setPipeline(pipeline);
}

static void SetIndexBufferMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setIndexBuffer");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  GPUBuffer* buffer;
  uint64_t offset;
  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  if (!info[1]->IsUndefined()) {
    offset = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    offset = 0;
  }

  impl->setIndexBuffer(buffer, offset);
}

static void SetVertexBufferMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "setVertexBuffer");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t slot;
  GPUBuffer* buffer;
  uint64_t offset;
  slot = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBuffer"));
    return;
  }

  if (!info[2]->IsUndefined()) {
    offset = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    offset = 0;
  }

  impl->setVertexBuffer(slot, buffer, offset);
}

static void DrawMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "draw");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 4)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(4, info.Length()));
    return;
  }

  uint32_t vertex_count;
  uint32_t instance_count;
  uint32_t first_vertex;
  uint32_t first_instance;
  vertex_count = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  instance_count = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  first_vertex = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  first_instance = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  impl->draw(vertex_count, instance_count, first_vertex, first_instance);
}

static void DrawIndexedMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "drawIndexed");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 5)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(5, info.Length()));
    return;
  }

  uint32_t index_count;
  uint32_t instance_count;
  uint32_t first_index;
  int32_t base_vertex;
  uint32_t first_instance;
  index_count = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  instance_count = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  first_index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  base_vertex = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  first_instance = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->drawIndexed(index_count, instance_count, first_index, base_vertex, first_instance);
}

static void DrawIndirectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "drawIndirect");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  GPUBuffer* indirect_buffer;
  uint64_t indirect_offset;
  indirect_buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!indirect_buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  indirect_offset = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->drawIndirect(indirect_buffer, indirect_offset);
}

static void DrawIndexedIndirectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderPassEncoder", "drawIndexedIndirect");

  GPURenderPassEncoder* impl = V8GPURenderPassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  GPUBuffer* indirect_buffer;
  uint64_t indirect_offset;
  indirect_buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!indirect_buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  indirect_offset = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->drawIndexedIndirect(indirect_buffer, indirect_offset);
}

}  // namespace gpu_render_pass_encoder_v8_internal

void V8GPURenderPassEncoder::SetViewportMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setViewport");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setViewport");

  gpu_render_pass_encoder_v8_internal::SetViewportMethod(info);
}

void V8GPURenderPassEncoder::SetScissorRectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setScissorRect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setScissorRect");

  gpu_render_pass_encoder_v8_internal::SetScissorRectMethod(info);
}

void V8GPURenderPassEncoder::SetBlendColorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setBlendColor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setBlendColor");

  gpu_render_pass_encoder_v8_internal::SetBlendColorMethod(info);
}

void V8GPURenderPassEncoder::SetStencilReferenceMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setStencilReference");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setStencilReference");

  gpu_render_pass_encoder_v8_internal::SetStencilReferenceMethod(info);
}

void V8GPURenderPassEncoder::ExecuteBundlesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.executeBundles");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_executeBundles");

  gpu_render_pass_encoder_v8_internal::ExecuteBundlesMethod(info);
}

void V8GPURenderPassEncoder::EndPassMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.endPass");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_endPass");

  gpu_render_pass_encoder_v8_internal::EndPassMethod(info);
}

void V8GPURenderPassEncoder::SetBindGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setBindGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setBindGroup");

  gpu_render_pass_encoder_v8_internal::SetBindGroupMethod(info);
}

void V8GPURenderPassEncoder::PushDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.pushDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_pushDebugGroup");

  gpu_render_pass_encoder_v8_internal::PushDebugGroupMethod(info);
}

void V8GPURenderPassEncoder::PopDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.popDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_popDebugGroup");

  gpu_render_pass_encoder_v8_internal::PopDebugGroupMethod(info);
}

void V8GPURenderPassEncoder::InsertDebugMarkerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.insertDebugMarker");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_insertDebugMarker");

  gpu_render_pass_encoder_v8_internal::InsertDebugMarkerMethod(info);
}

void V8GPURenderPassEncoder::SetPipelineMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setPipeline");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setPipeline");

  gpu_render_pass_encoder_v8_internal::SetPipelineMethod(info);
}

void V8GPURenderPassEncoder::SetIndexBufferMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setIndexBuffer");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setIndexBuffer");

  gpu_render_pass_encoder_v8_internal::SetIndexBufferMethod(info);
}

void V8GPURenderPassEncoder::SetVertexBufferMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.setVertexBuffer");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_setVertexBuffer");

  gpu_render_pass_encoder_v8_internal::SetVertexBufferMethod(info);
}

void V8GPURenderPassEncoder::DrawMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.draw");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_draw");

  gpu_render_pass_encoder_v8_internal::DrawMethod(info);
}

void V8GPURenderPassEncoder::DrawIndexedMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.drawIndexed");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_drawIndexed");

  gpu_render_pass_encoder_v8_internal::DrawIndexedMethod(info);
}

void V8GPURenderPassEncoder::DrawIndirectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.drawIndirect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_drawIndirect");

  gpu_render_pass_encoder_v8_internal::DrawIndirectMethod(info);
}

void V8GPURenderPassEncoder::DrawIndexedIndirectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderPassEncoder.drawIndexedIndirect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderPassEncoder_drawIndexedIndirect");

  gpu_render_pass_encoder_v8_internal::DrawIndexedIndirectMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8GPURenderPassEncoderMethods[] = {
    {"setViewport", V8GPURenderPassEncoder::SetViewportMethodCallback, 6, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setScissorRect", V8GPURenderPassEncoder::SetScissorRectMethodCallback, 4, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setBlendColor", V8GPURenderPassEncoder::SetBlendColorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setStencilReference", V8GPURenderPassEncoder::SetStencilReferenceMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"executeBundles", V8GPURenderPassEncoder::ExecuteBundlesMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"endPass", V8GPURenderPassEncoder::EndPassMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8GPURenderPassEncoderTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8GPURenderPassEncoder::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8GPURenderPassEncoder::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8GPURenderPassEncoderMethods, base::size(kV8GPURenderPassEncoderMethods));

  // Custom signature

  V8GPURenderPassEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8GPURenderPassEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install setBindGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setBindGroup", V8GPURenderPassEncoder::SetBindGroupMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install pushDebugGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"pushDebugGroup", V8GPURenderPassEncoder::PushDebugGroupMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install popDebugGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"popDebugGroup", V8GPURenderPassEncoder::PopDebugGroupMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install insertDebugMarker configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"insertDebugMarker", V8GPURenderPassEncoder::InsertDebugMarkerMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install setPipeline configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setPipeline", V8GPURenderPassEncoder::SetPipelineMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install setIndexBuffer configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setIndexBuffer", V8GPURenderPassEncoder::SetIndexBufferMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install setVertexBuffer configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setVertexBuffer", V8GPURenderPassEncoder::SetVertexBufferMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install draw configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"draw", V8GPURenderPassEncoder::DrawMethodCallback, 4, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install drawIndexed configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndexed", V8GPURenderPassEncoder::DrawIndexedMethodCallback, 5, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install drawIndirect configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndirect", V8GPURenderPassEncoder::DrawIndirectMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install drawIndexedIndirect configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndexedIndirect", V8GPURenderPassEncoder::DrawIndexedIndirectMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
}

v8::Local<v8::FunctionTemplate> V8GPURenderPassEncoder::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8GPURenderPassEncoder::GetWrapperTypeInfo()),
      InstallV8GPURenderPassEncoderTemplate);
}

bool V8GPURenderPassEncoder::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8GPURenderPassEncoder::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8GPURenderPassEncoder::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8GPURenderPassEncoder::GetWrapperTypeInfo(), v8_value);
}

GPURenderPassEncoder* V8GPURenderPassEncoder::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
