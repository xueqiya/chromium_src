#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadCachedTemplateObjectSlotId_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o);
void StoreCachedTemplateObjectSlotId_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o, TNode<Smi> p_v);
TNode<JSArray> LoadCachedTemplateObjectTemplateObject_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o);
void StoreCachedTemplateObjectTemplateObject_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o, TNode<JSArray> p_v);
TNode<HeapObject> LoadCachedTemplateObjectNext_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o);
void StoreCachedTemplateObjectNext_0(compiler::CodeAssemblerState* state_, TNode<CachedTemplateObject> p_o, TNode<HeapObject> p_v);
TNode<FixedArray> LoadTemplateObjectDescriptionRawStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o);
void StoreTemplateObjectDescriptionRawStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o, TNode<FixedArray> p_v);
TNode<FixedArray> LoadTemplateObjectDescriptionCookedStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o);
void StoreTemplateObjectDescriptionCookedStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o, TNode<FixedArray> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_
