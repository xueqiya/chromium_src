#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ALL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ALL_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Context> CreatePromiseAllResolveElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext);
TNode<JSFunction> CreatePromiseAllResolveElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_resolveElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext, Context::Field p_slotIndex);
TNode<Context> CreatePromiseResolvingFunctionsContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext);
TNode<BoolT> IsPromiseThenLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Map> p_receiverMap);
TNode<Object> GeneratePromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor);
TNode<Object> GeneratePromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor);
TNode<Object> PerformPromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0);
TNode<Object> PerformPromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0);
TNode<BoolT> Is_JSPromise_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ALL_TQ_H_
