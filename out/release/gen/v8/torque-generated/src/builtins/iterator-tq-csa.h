#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

void IteratorCloseOnException_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator, TNode<Object> p_exception, compiler::CodeAssemblerLabel* label_IfException, compiler::TypedCodeAssemblerVariable<Object>* label_IfException_parameter_0);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_H_
