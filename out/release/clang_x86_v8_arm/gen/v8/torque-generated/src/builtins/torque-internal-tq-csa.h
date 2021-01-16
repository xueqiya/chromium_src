#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<IntPtrT> AddIndexedFieldSizeToObjectSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_baseSize, TNode<IntPtrT> p_arrayLength, int32_t p_fieldSize);
TNode<IntPtrT> AlignTagged_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x);
TNode<BoolT> IsTaggedAligned_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x);
TNode<BoolT> ValidAllocationSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map);
TNode<HeapObject> Allocate_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map);
void InitializeFieldsFromIterator_char8_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator);
void InitializeFieldsFromIterator_char16_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char16_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator);
TorqueStructfloat64_or_hole_0 LoadFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r);
void StoreFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r, TorqueStructfloat64_or_hole_0 p_value);
TorqueStructReference_Object_0 UnsafeNewReference_Object_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_float64_or_hole_0 UnsafeNewReference_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TNode<IntPtrT> Convert_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TorqueStructReference_DescriptorEntry_0 UnsafeNewReference_DescriptorEntry_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_float64_0 UnsafeNewReference_float64_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_char8_0 UnsafeNewReference_char8_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_char16_0 UnsafeNewReference_char16_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_uint8_0 UnsafeNewReference_uint8_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 UnsafeNewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
TorqueStructReference_HashMapEntry_0 UnsafeNewReference_HashMapEntry_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_H_
