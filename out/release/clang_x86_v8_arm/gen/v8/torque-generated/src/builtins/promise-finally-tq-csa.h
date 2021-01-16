#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_FINALLY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_FINALLY_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<JSFunction> CreateThrowerFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_reason);
TNode<JSFunction> CreateValueThunkFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_value);
TorqueStructPromiseFinallyFunctions_0 CreatePromiseFinallyFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_onFinally, TNode<JSReceiver> p_constructor);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_FINALLY_TQ_H_
