#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ARGUMENTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ARGUMENTS_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<BoolT> IsJSArgumentsObjectWithLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<JSArgumentsObject> NewJSStrictArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements);
TNode<JSArgumentsObject> NewJSSloppyArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<JSFunction> p_callee);
TNode<JSArgumentsObject> NewJSFastAliasedArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<Smi> p_length, TNode<JSFunction> p_callee);
TorqueStructParameterMapIterator_0 NewParameterMapIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<IntPtrT> p_formalParameterCount, TNode<IntPtrT> p_mappedCount);
TorqueStructParameterValueIterator_0 NewParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_mappedCount, TorqueStructArguments p_arguments);
TNode<JSArray> NewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argumentCount);
TNode<JSArray> NewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info);
TNode<JSArgumentsObject> NewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info);
TNode<JSArgumentsObject> NewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info, TNode<JSFunction> p_callee);
TNode<JSArray> EmitFastNewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argc);
TNode<JSArray> EmitFastNewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f);
TNode<JSArgumentsObject> EmitFastNewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f);
TNode<JSArgumentsObject> EmitFastNewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_f);
TNode<Object> LoadJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o);
void StoreJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v);
TNode<Object> LoadJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o);
void StoreJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v);
TNode<Object> LoadJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o);
void StoreJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v);
TNode<Smi> LoadAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o);
void StoreAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o, TNode<Smi> p_v);
TNode<BoolT> Is_JSArgumentsObjectWithLength_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<FixedArray> NewFixedArray_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructArgumentsIterator_0 p_it);
TNode<FixedArray> NewFixedArray_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructParameterValueIterator_0 p_it);
void InitializeFieldsFromIterator_Object_ParameterMapIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterMapIterator_0 p_originIterator);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ARGUMENTS_TQ_H_
