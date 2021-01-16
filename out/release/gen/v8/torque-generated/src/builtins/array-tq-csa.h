#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

void EnsureWriteableFastElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array);
TNode<Object> LoadElementOrUndefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_a, TNode<Smi> p_i);
TNode<Object> LoadElementOrUndefined_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i);
void StoreArrayHole_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_k);
void StoreArrayHole_1(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_k);
void EnsureArrayLengthWritable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, compiler::CodeAssemblerLabel* label_Bailout);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TQ_H_
