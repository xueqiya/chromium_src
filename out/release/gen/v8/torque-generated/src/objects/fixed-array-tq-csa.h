#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

void StoreFixedDoubleArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i, TNode<Number> p_v);
void StoreFixedArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_a, TNode<Smi> p_i, TNode<Object> p_v);
TNode<FixedArray> ExtractFixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity);
TNode<FixedArrayBase> ExtractFixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity);
TNode<Smi> LoadFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o);
void StoreFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o);
void StoreWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o);
void StoreWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o);
void StoreWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v);
TorqueStructConstantIterator_TheHole_0 ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_value);
TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_Object_0 p_first, TorqueStructConstantIterator_TheHole_0 p_second);
TNode<FixedArray> NewFixedArray_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_it);
TorqueStructConstantIterator_float64_or_hole_0 ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructfloat64_or_hole_0 p_value);
TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_float64_or_hole_0 p_first, TorqueStructConstantIterator_float64_or_hole_0 p_second);
TNode<FixedArrayBase> NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_it);
void InitializeFieldsFromIterator_Object_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructArgumentsIterator_0 p_originIterator);
void InitializeFieldsFromIterator_Object_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterValueIterator_0 p_originIterator);
void InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_originIterator);
void InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_float64_or_hole_0 p_target, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_originIterator);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_H_
