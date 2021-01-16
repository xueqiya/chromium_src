#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadPropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);
void StorePropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Smi> p_v);
TNode<Object> LoadPropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);
void StorePropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);
TNode<Object> LoadPropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);
void StorePropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);
TNode<Object> LoadPropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);
void StorePropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_H_
