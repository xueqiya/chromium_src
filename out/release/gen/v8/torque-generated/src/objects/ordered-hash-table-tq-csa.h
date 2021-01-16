#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ORDERED_HASH_TABLE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ORDERED_HASH_TABLE_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

  TNode<Map> kSmallOrderedHashSetMap_0(compiler::CodeAssemblerState* state_);
TNode<SmallOrderedHashSet> AllocateSmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity);
  TNode<Map> kSmallOrderedHashMapMap_0(compiler::CodeAssemblerState* state_);
TNode<SmallOrderedHashMap> AllocateSmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity);
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o);
void StoreSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o);
void StoreSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o);
void StoreSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o);
void StoreSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o);
void StoreSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o);
void StoreSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v);
TNode<Int32T> LoadSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o);
void StoreSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Int32T> p_v);
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o);
void StoreSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o);
void StoreSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o);
void StoreSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o);
void StoreSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v);
TorqueStructConstantIterator_uint8_0 ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_value);
void InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_uint8_0 p_target, TorqueStructConstantIterator_uint8_0 p_originIterator);
void InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 p_target, TorqueStructConstantIterator_TheHole_0 p_originIterator);
TorqueStructConstantIterator_HashMapEntry_0 ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructHashMapEntry_0 p_value);
void InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_HashMapEntry_0 p_target, TorqueStructConstantIterator_HashMapEntry_0 p_originIterator);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ORDERED_HASH_TABLE_TQ_H_
