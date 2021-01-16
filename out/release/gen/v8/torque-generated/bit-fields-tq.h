#ifndef V8_GEN_TORQUE_GENERATED_BIT_FIELDS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_BIT_FIELDS_TQ_H_

#include "src/base/bit-field.h"

namespace v8 {
namespace internal {

enum class FunctionSyntaxKind : uint8_t;
enum class BailoutReason : uint8_t;
enum FunctionKind : uint8_t;

struct TorqueGeneratedMapBitFields1Fields {
  using HasNonInstancePrototypeBit = base::BitField<bool, 0, 1, uint8_t>;
  using IsCallableBit = base::BitField<bool, 1, 1, uint8_t>;
  using HasNamedInterceptorBit = base::BitField<bool, 2, 1, uint8_t>;
  using HasIndexedInterceptorBit = base::BitField<bool, 3, 1, uint8_t>;
  using IsUndetectableBit = base::BitField<bool, 4, 1, uint8_t>;
  using IsAccessCheckNeededBit = base::BitField<bool, 5, 1, uint8_t>;
  using IsConstructorBit = base::BitField<bool, 6, 1, uint8_t>;
  using HasPrototypeSlotBit = base::BitField<bool, 7, 1, uint8_t>;
};

struct TorqueGeneratedMapBitFields2Fields {
  using NewTargetIsBaseBit = base::BitField<bool, 0, 1, uint8_t>;
  using IsImmutablePrototypeBit = base::BitField<bool, 1, 1, uint8_t>;
  using UnusedBit = base::BitField<bool, 2, 1, uint8_t>;
  using ElementsKindBits = base::BitField<ElementsKind, 3, 5, uint8_t>;
};

struct TorqueGeneratedMapBitFields3Fields {
  using EnumLengthBits = base::BitField<int32_t, 0, 10, uint32_t>;
  using NumberOfOwnDescriptorsBits = base::BitField<int32_t, 10, 10, uint32_t>;
  using IsPrototypeMapBit = base::BitField<bool, 20, 1, uint32_t>;
  using IsDictionaryMapBit = base::BitField<bool, 21, 1, uint32_t>;
  using OwnsDescriptorsBit = base::BitField<bool, 22, 1, uint32_t>;
  using IsInRetainedMapListBit = base::BitField<bool, 23, 1, uint32_t>;
  using IsDeprecatedBit = base::BitField<bool, 24, 1, uint32_t>;
  using IsUnstableBit = base::BitField<bool, 25, 1, uint32_t>;
  using IsMigrationTargetBit = base::BitField<bool, 26, 1, uint32_t>;
  using IsExtensibleBit = base::BitField<bool, 27, 1, uint32_t>;
  using MayHaveInterestingSymbolsBit = base::BitField<bool, 28, 1, uint32_t>;
  using ConstructionCounterBits = base::BitField<int32_t, 29, 3, uint32_t>;
};

struct TorqueGeneratedSymbolFlagsFields {
  using IsPrivateBit = base::BitField<bool, 0, 1, uint32_t>;
  using IsWellKnownSymbolBit = base::BitField<bool, 1, 1, uint32_t>;
  using IsInPublicSymbolTableBit = base::BitField<bool, 2, 1, uint32_t>;
  using IsInterestingSymbolBit = base::BitField<bool, 3, 1, uint32_t>;
  using IsPrivateNameBit = base::BitField<bool, 4, 1, uint32_t>;
  using IsPrivateBrandBit = base::BitField<bool, 5, 1, uint32_t>;
};

struct TorqueGeneratedScopeFlagsFields {
  using ScopeTypeBits = base::BitField<ScopeType, 0, 4, uint32_t>;
  using SloppyEvalCanExtendVarsBit = base::BitField<bool, 4, 1, uint32_t>;
  using LanguageModeBit = base::BitField<LanguageMode, 5, 1, uint32_t>;
  using DeclarationScopeBit = base::BitField<bool, 6, 1, uint32_t>;
  using ReceiverVariableBits = base::BitField<VariableAllocationInfo, 7, 2, uint32_t>;
  using HasClassBrandBit = base::BitField<bool, 9, 1, uint32_t>;
  using HasSavedClassVariableIndexBit = base::BitField<bool, 10, 1, uint32_t>;
  using HasNewTargetBit = base::BitField<bool, 11, 1, uint32_t>;
  using FunctionVariableBits = base::BitField<VariableAllocationInfo, 12, 2, uint32_t>;
  using HasInferredFunctionNameBit = base::BitField<bool, 14, 1, uint32_t>;
  using IsAsmModuleBit = base::BitField<bool, 15, 1, uint32_t>;
  using HasSimpleParametersBit = base::BitField<bool, 16, 1, uint32_t>;
  using FunctionKindBits = base::BitField<v8::internal::FunctionKind, 17, 5, uint32_t>;
  using HasOuterScopeInfoBit = base::BitField<bool, 22, 1, uint32_t>;
  using IsDebugEvaluateScopeBit = base::BitField<bool, 23, 1, uint32_t>;
  using ForceContextAllocationBit = base::BitField<bool, 24, 1, uint32_t>;
  using PrivateNameLookupSkipsOuterClassBit = base::BitField<bool, 25, 1, uint32_t>;
  using HasContextExtensionSlotBit = base::BitField<bool, 26, 1, uint32_t>;
  using IsReplModeScopeBit = base::BitField<bool, 27, 1, uint32_t>;
  using HasLocalsBlackListBit = base::BitField<bool, 28, 1, uint32_t>;
};

struct TorqueGeneratedSharedFunctionInfoFlagsFields {
  using FunctionKindBits = base::BitField<v8::internal::FunctionKind, 0, 5, uint32_t>;
  using IsNativeBit = base::BitField<bool, 5, 1, uint32_t>;
  using IsStrictBit = base::BitField<bool, 6, 1, uint32_t>;
  using FunctionSyntaxKindBits = base::BitField<v8::internal::FunctionSyntaxKind, 7, 3, uint32_t>;
  using IsClassConstructorBit = base::BitField<bool, 10, 1, uint32_t>;
  using HasDuplicateParametersBit = base::BitField<bool, 11, 1, uint32_t>;
  using AllowLazyCompilationBit = base::BitField<bool, 12, 1, uint32_t>;
  using NeedsHomeObjectBit = base::BitField<bool, 13, 1, uint32_t>;
  using IsAsmWasmBrokenBit = base::BitField<bool, 14, 1, uint32_t>;
  using FunctionMapIndexBits = base::BitField<uint32_t, 15, 5, uint32_t>;
  using DisabledOptimizationReasonBits = base::BitField<v8::internal::BailoutReason, 20, 4, uint32_t>;
  using RequiresInstanceMembersInitializerBit = base::BitField<bool, 24, 1, uint32_t>;
  using ConstructAsBuiltinBit = base::BitField<bool, 25, 1, uint32_t>;
  using NameShouldPrintAsAnonymousBit = base::BitField<bool, 26, 1, uint32_t>;
  using HasReportedBinaryCoverageBit = base::BitField<bool, 27, 1, uint32_t>;
  using IsTopLevelBit = base::BitField<bool, 28, 1, uint32_t>;
  using IsOneshotIifeOrPropertiesAreFinalBit = base::BitField<bool, 29, 1, uint32_t>;
  using IsSafeToSkipArgumentsAdaptorBit = base::BitField<bool, 30, 1, uint32_t>;
  using PrivateNameLookupSkipsOuterClassBit = base::BitField<bool, 31, 1, uint32_t>;
};

struct TorqueGeneratedTestBitFieldStructFields {
  using ABit = base::BitField<bool, 0, 1, uint8_t>;
  using BBits = base::BitField<uint16_t, 1, 3, uint8_t>;
  using CBits = base::BitField<uint32_t, 4, 3, uint8_t>;
  using DBit = base::BitField<bool, 7, 1, uint8_t>;
};

struct TorqueGeneratedTestBitFieldStruct2Fields {
  using ABits = base::BitField<uintptr_t, 0, 5, uint32_t>;
  using BBits = base::BitField<uintptr_t, 5, 6, uint32_t>;
};

struct TorqueGeneratedTestBitFieldStruct3Fields {
  using CBit = base::BitField<bool, 0, 1, uintptr_t>;
  using DBits = base::BitField<uint32_t, 1, 9, uintptr_t>;
  using EBits = base::BitField<uintptr_t, 10, 17, uintptr_t>;
};

}  // namespace internal
}  // namespace v8
#endif  // V8_GEN_TORQUE_GENERATED_BIT_FIELDS_TQ_H_
