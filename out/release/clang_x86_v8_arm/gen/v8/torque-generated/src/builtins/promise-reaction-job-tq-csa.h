#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_REACTION_JOB_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_REACTION_JOB_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> RejectPromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Object> p_reason, PromiseReaction::Type p_reactionType);
TNode<Object> FuflfillPromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Object> p_result, PromiseReaction::Type p_reactionType);
TNode<Object> PromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability, PromiseReaction::Type p_reactionType);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_REACTION_JOB_TQ_H_
