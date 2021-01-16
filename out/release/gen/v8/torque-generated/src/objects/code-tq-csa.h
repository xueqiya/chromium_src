#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<FixedArray> LoadBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<FixedArray> p_v);
TNode<ByteArray> LoadBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<ByteArray> p_v);
TNode<HeapObject> LoadBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<HeapObject> p_v);
TNode<Int32T> LoadBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int8T> LoadBytecodeArrayOsrNestingLevel_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayOsrNestingLevel_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int8T> p_v);
TNode<Int8T> LoadBytecodeArrayBytecodeAge_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayBytecodeAge_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int8T> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_
