#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/torque/runtime-support.h"
#include "torque-generated/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-find-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/array-from-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-map-tq-csa.h"
#include "torque-generated/src/builtins/array-of-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-some-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/bigint-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/console-tq-csa.h"
#include "torque-generated/src/builtins/data-view-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/promise-finally-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-race-tq-csa.h"
#include "torque-generated/src/builtins/promise-reaction-job-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/promise-then-tq-csa.h"
#include "torque-generated/src/builtins/promise-jobs-tq-csa.h"
#include "torque-generated/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-tq-csa.h"
#include "torque-generated/src/builtins/reflect-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/src/builtins/string-html-tq-csa.h"
#include "torque-generated/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/src/builtins/symbol-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"
#include "torque-generated/src/objects/cell-tq-csa.h"
#include "torque-generated/src/objects/code-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/data-handler-tq-csa.h"
#include "torque-generated/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/foreign-tq-csa.h"
#include "torque-generated/src/objects/free-space-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/heap-object-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-collection-tq-csa.h"
#include "torque-generated/src/objects/js-generator-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/microtask-tq-csa.h"
#include "torque-generated/src/objects/module-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/oddball-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-array-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/property-descriptor-object-tq-csa.h"
#include "torque-generated/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/scope-info-tq-csa.h"
#include "torque-generated/src/objects/script-tq-csa.h"
#include "torque-generated/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/src/objects/template-objects-tq-csa.h"
#include "torque-generated/src/objects/template-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

TNode<Map> kSmallOrderedHashSetMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashSetMapConstant();
return TNode<Map>{tmp0};
}

TNode<SmallOrderedHashSet> AllocateSmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, SmallOrderedHashSet> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_capacity);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = kSmallOrderedHashSetMap_0(state_);
    TNode<Uint8T> tmp4;
    USE(tmp4);
    tmp4 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp2});
    TNode<Uint8T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    TNode<Uint8T> tmp6;
    USE(tmp6);
    std::tie(tmp6) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp5}).Flatten();
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = TheHole_0(state_);
    TNode<Oddball> tmp8;
    USE(tmp8);
    std::tie(tmp8) = ConstantIterator_TheHole_0(state_, TNode<Oddball>{tmp7}).Flatten();
    TNode<Uint8T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    TNode<Uint8T> tmp10;
    USE(tmp10);
    std::tie(tmp10) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp9}).Flatten();
    TNode<Uint8T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    TNode<Uint8T> tmp12;
    USE(tmp12);
    std::tie(tmp12) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp11}).Flatten();
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = Convert_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp13}, kUInt8Size);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp19}, kTaggedSize);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22}, kUInt8Size);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp26});
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp27}, kUInt8Size);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = AlignTagged_0(state_, TNode<IntPtrT>{tmp28});
    TNode<HeapObject> tmp30;
    USE(tmp30);
    tmp30 = Allocate_0(state_, TNode<IntPtrT>{tmp29}, TNode<Map>{tmp3});
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp30, tmp31}, tmp3);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint8T> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp30, tmp32}, tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    TNode<Uint8T> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp30, tmp34}, tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp30, tmp36}, tmp4);
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp13}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp6}});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp19}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp8}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp10}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp27}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp12}});
    TNode<SmallOrderedHashSet> tmp39;
    USE(tmp39);
    tmp39 = TORQUE_CAST(TNode<HeapObject>{tmp30});
    ca_.Goto(&block9, tmp0, tmp39);
  }

  if (block6.is_used()) {
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<BoolT> tmp42;
    ca_.Bind(&block6, &tmp40, &tmp41, &tmp42);
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kMaxCapacity);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp41}, TNode<IntPtrT>{tmp43});
    ca_.Goto(&block8, tmp40, tmp41, tmp42, tmp44);
  }

  if (block7.is_used()) {
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<BoolT> tmp47;
    ca_.Bind(&block7, &tmp45, &tmp46, &tmp47);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp45, tmp46, tmp47, tmp48);
  }

  if (block8.is_used()) {
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<BoolT> tmp51;
    TNode<BoolT> tmp52;
    ca_.Bind(&block8, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Branch(tmp52, &block4, &block5, tmp49, tmp50);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    ca_.Bind(&block5, &tmp53, &tmp54);
    CodeStubAssembler(state_).FailAssert("Torque assert '0 <= hashTableSize && hashTableSize <= kSmallOrderedHashTableMaxCapacity' failed", "src/objects/ordered-hash-table.tq", 43);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    ca_.Bind(&block4, &tmp55, &tmp56);
  }

    TNode<IntPtrT> tmp57;
    TNode<SmallOrderedHashSet> tmp58;
    ca_.Bind(&block9, &tmp57, &tmp58);
  return TNode<SmallOrderedHashSet>{tmp58};
}

TNode<Map> kSmallOrderedHashMapMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashMapMapConstant();
return TNode<Map>{tmp0};
}

TNode<SmallOrderedHashMap> AllocateSmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, SmallOrderedHashMap> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_capacity);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = kSmallOrderedHashMapMap_0(state_);
    TNode<Uint8T> tmp4;
    USE(tmp4);
    tmp4 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp2});
    TNode<Uint8T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    TNode<Uint8T> tmp6;
    USE(tmp6);
    std::tie(tmp6) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp5}).Flatten();
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = TheHole_0(state_);
    TNode<Oddball> tmp8;
    USE(tmp8);
    tmp8 = TheHole_0(state_);
    TNode<Object> tmp9;
    USE(tmp9);
    TNode<Object> tmp10;
    USE(tmp10);
    std::tie(tmp9, tmp10) = ConstantIterator_HashMapEntry_0(state_, TorqueStructHashMapEntry_0{TNode<Object>{tmp7}, TNode<Object>{tmp8}}).Flatten();
    TNode<Uint8T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    TNode<Uint8T> tmp12;
    USE(tmp12);
    std::tie(tmp12) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp11}).Flatten();
    TNode<Uint8T> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    TNode<Uint8T> tmp14;
    USE(tmp14);
    std::tie(tmp14) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp13}).Flatten();
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = Convert_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp15}, kUInt8Size);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp19});
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp20});
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp21}, 8);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp24}, kUInt8Size);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp4});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp28});
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp29}, kUInt8Size);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = AlignTagged_0(state_, TNode<IntPtrT>{tmp30});
    TNode<HeapObject> tmp32;
    USE(tmp32);
    tmp32 = Allocate_0(state_, TNode<IntPtrT>{tmp31}, TNode<Map>{tmp3});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp32, tmp33}, tmp3);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint8T> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp32, tmp34}, tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    TNode<Uint8T> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp32, tmp36}, tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp32, tmp38}, tmp4);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp32}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp15}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp6}});
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(state_, TorqueStructSlice_HashMapEntry_0{TNode<HeapObject>{tmp32}, TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp21}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{tmp9}, TNode<Object>{tmp10}}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp32}, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp24}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp12}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp32}, TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp29}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp14}});
    TNode<SmallOrderedHashMap> tmp41;
    USE(tmp41);
    tmp41 = TORQUE_CAST(TNode<HeapObject>{tmp32});
    ca_.Goto(&block9, tmp0, tmp41);
  }

  if (block6.is_used()) {
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<BoolT> tmp44;
    ca_.Bind(&block6, &tmp42, &tmp43, &tmp44);
    TNode<IntPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kMaxCapacity);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp43}, TNode<IntPtrT>{tmp45});
    ca_.Goto(&block8, tmp42, tmp43, tmp44, tmp46);
  }

  if (block7.is_used()) {
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<BoolT> tmp49;
    ca_.Bind(&block7, &tmp47, &tmp48, &tmp49);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp47, tmp48, tmp49, tmp50);
  }

  if (block8.is_used()) {
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<BoolT> tmp53;
    TNode<BoolT> tmp54;
    ca_.Bind(&block8, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Branch(tmp54, &block4, &block5, tmp51, tmp52);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    ca_.Bind(&block5, &tmp55, &tmp56);
    CodeStubAssembler(state_).FailAssert("Torque assert '0 <= hashTableSize && hashTableSize <= kSmallOrderedHashTableMaxCapacity' failed", "src/objects/ordered-hash-table.tq", 82);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    ca_.Bind(&block4, &tmp57, &tmp58);
  }

    TNode<IntPtrT> tmp59;
    TNode<SmallOrderedHashMap> tmp60;
    ca_.Bind(&block9, &tmp59, &tmp60);
  return TNode<SmallOrderedHashMap>{tmp60};
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashSet, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashSet> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashSet> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedHashMap, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedHashMap> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedHashMap> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Int32T> LoadSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Int32T>tmp2 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Int32T>{tmp4};
}

void StoreSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    TNode<Int32T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 11);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmallOrderedNameDictionary, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmallOrderedNameDictionary> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 11);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmallOrderedNameDictionary> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TorqueStructConstantIterator_uint8_0 ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value);

  if (block0.is_used()) {
    TNode<Uint8T> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Uint8T> tmp1;
    TNode<Uint8T> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp2}};
}

void InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_uint8_0 p_target, TorqueStructConstantIterator_uint8_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T, HeapObject, IntPtrT, IntPtrT, Uint8T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T, HeapObject, IntPtrT, IntPtrT, Uint8T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T, HeapObject, IntPtrT, IntPtrT, Uint8T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T, HeapObject, IntPtrT, IntPtrT, Uint8T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T, HeapObject, IntPtrT, IntPtrT, Uint8T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Uint8T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Uint8T> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp6, tmp3);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint8T> tmp10;
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Uint8T> tmp14;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp15, &block3, &block4, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Uint8T> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Uint8T> tmp23;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    ca_.Branch(tmp24, &block9, &block10, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Uint8T> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Uint8T> tmp32;
    ca_.Bind(&block9, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block4, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Uint8T> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<Uint8T> tmp40;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_uint8_0(state_, TNode<HeapObject>{tmp37}, TNode<IntPtrT>{tmp38}).Flatten();
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp41, tmp42}, tmp40);
    ca_.Goto(&block5, tmp33, tmp34, tmp35, tmp36, tmp37, tmp44, tmp39, tmp40);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<Uint8T> tmp48;
    TNode<HeapObject> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Uint8T> tmp52;
    ca_.Bind(&block4, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Goto(&block16, tmp45, tmp46, tmp47, tmp48);
  }

    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Uint8T> tmp56;
    ca_.Bind(&block16, &tmp53, &tmp54, &tmp55, &tmp56);
}

void InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 p_target, TorqueStructConstantIterator_TheHole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Oddball> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp6, tmp3);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Oddball> tmp10;
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Oddball> tmp14;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp15, &block3, &block4, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Oddball> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Oddball> tmp23;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    ca_.Branch(tmp24, &block9, &block10, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Oddball> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Oddball> tmp32;
    ca_.Bind(&block9, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block4, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Oddball> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<Oddball> tmp40;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<HeapObject>{tmp37}, TNode<IntPtrT>{tmp38}).Flatten();
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp41, tmp42}, tmp40);
    ca_.Goto(&block5, tmp33, tmp34, tmp35, tmp36, tmp37, tmp44, tmp39, tmp40);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<Oddball> tmp48;
    TNode<HeapObject> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Oddball> tmp52;
    ca_.Bind(&block4, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Goto(&block16, tmp45, tmp46, tmp47, tmp48);
  }

    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Oddball> tmp56;
    ca_.Bind(&block16, &tmp53, &tmp54, &tmp55, &tmp56);
}

TorqueStructConstantIterator_HashMapEntry_0 ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructHashMapEntry_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value.key, p_value.value);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{tmp4}, TNode<Object>{tmp5}}};
}

void InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_HashMapEntry_0 p_target, TorqueStructConstantIterator_HashMapEntry_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object, HeapObject, IntPtrT, IntPtrT, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object, HeapObject, IntPtrT, IntPtrT, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object, HeapObject, IntPtrT, IntPtrT, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object, HeapObject, IntPtrT, IntPtrT, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object, HeapObject, IntPtrT, IntPtrT, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.value.key, p_originIterator.value.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp0, tmp1, tmp7, tmp3, tmp4);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp18, &block3, &block4, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    TNode<HeapObject> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block3, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp29, &block9, &block10, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    TNode<HeapObject> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    ca_.Bind(&block9, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    ca_.Goto(&block4, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block10, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<HeapObject> tmp50;
    USE(tmp50);
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    std::tie(tmp50, tmp51) = UnsafeNewReference_HashMapEntry_0(state_, TNode<HeapObject>{tmp45}, TNode<IntPtrT>{tmp46}).Flatten();
    TNode<IntPtrT> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp46}, TNode<IntPtrT>{tmp52});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp50, tmp51}, tmp48);
    TNode<IntPtrT> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp54});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp50, tmp55}, tmp49);
    ca_.Goto(&block5, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp53, tmp47, tmp48, tmp49);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block4, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block16, tmp56, tmp57, tmp58, tmp59, tmp60);
  }

    TNode<HeapObject> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    ca_.Bind(&block16, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
}

}  // namespace internal
}  // namespace v8

