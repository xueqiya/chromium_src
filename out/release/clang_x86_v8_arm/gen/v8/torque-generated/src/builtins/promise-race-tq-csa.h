#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_RACE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_RACE_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

  TNode<Symbol> kPromiseForwardingHandlerSymbol_0(compiler::CodeAssemblerState* state_);
  TNode<Symbol> kPromiseHandledBySymbol_0(compiler::CodeAssemblerState* state_);
  TNode<String> kResolveString_0(compiler::CodeAssemblerState* state_);
TNode<BoolT> IsPromiseResolveLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_constructor);
TNode<BoolT> Is_JSPromise_JSReceiver_OR_Undefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_RACE_TQ_H_
