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

TNode<String> AllocateSeqOneByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, String> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp0}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block6, &block7, tmp0);
  }

  if (block5.is_used()) {
    TNode<Uint32T> tmp3;
    ca_.Bind(&block5, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'length <= kStringMaxLength' failed", "src/objects/string.tq", 62);
  }

  if (block4.is_used()) {
    TNode<Uint32T> tmp4;
    ca_.Bind(&block4, &tmp4);
  }

  if (block6.is_used()) {
    TNode<Uint32T> tmp5;
    ca_.Bind(&block6, &tmp5);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    ca_.Goto(&block1, tmp5, tmp6);
  }

  if (block7.is_used()) {
    TNode<Uint32T> tmp7;
    ca_.Bind(&block7, &tmp7);
    TNode<Map> tmp8;
    USE(tmp8);
    tmp8 = kOneByteStringMap_0(state_);
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp7});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp10}, kUInt8Size);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = AlignTagged_0(state_, TNode<IntPtrT>{tmp12});
    TNode<HeapObject> tmp14;
    USE(tmp14);
    tmp14 = Allocate_0(state_, TNode<IntPtrT>{tmp13}, TNode<Map>{tmp8});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp14, tmp15}, tmp8);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_uint32_constexpr_uint32_0(state_, Name::kEmptyHashField);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp14, tmp16}, tmp17);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp14, tmp18}, tmp9);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    InitializeFieldsFromIterator_char8_UninitializedIterator_0(state_, TorqueStructSlice_char8_0{TNode<HeapObject>{tmp14}, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp10}, TorqueStructUnsafe_0{}}, TorqueStructUninitializedIterator_0{});
    TNode<SeqOneByteString> tmp20;
    USE(tmp20);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{tmp14});
    ca_.Goto(&block1, tmp7, tmp20);
  }

  if (block1.is_used()) {
    TNode<Uint32T> tmp21;
    TNode<String> tmp22;
    ca_.Bind(&block1, &tmp21, &tmp22);
    ca_.Goto(&block8, tmp21, tmp22);
  }

    TNode<Uint32T> tmp23;
    TNode<String> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
  return TNode<String>{tmp24};
}

TNode<String> AllocateSeqTwoByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, String> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp0}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block6, &block7, tmp0);
  }

  if (block5.is_used()) {
    TNode<Uint32T> tmp3;
    ca_.Bind(&block5, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'length <= kStringMaxLength' failed", "src/objects/string.tq", 74);
  }

  if (block4.is_used()) {
    TNode<Uint32T> tmp4;
    ca_.Bind(&block4, &tmp4);
  }

  if (block6.is_used()) {
    TNode<Uint32T> tmp5;
    ca_.Bind(&block6, &tmp5);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    ca_.Goto(&block1, tmp5, tmp6);
  }

  if (block7.is_used()) {
    TNode<Uint32T> tmp7;
    ca_.Bind(&block7, &tmp7);
    TNode<Map> tmp8;
    USE(tmp8);
    tmp8 = kStringMap_0(state_);
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp7});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp10}, kUInt16Size);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = AlignTagged_0(state_, TNode<IntPtrT>{tmp12});
    TNode<HeapObject> tmp14;
    USE(tmp14);
    tmp14 = Allocate_0(state_, TNode<IntPtrT>{tmp13}, TNode<Map>{tmp8});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp14, tmp15}, tmp8);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_uint32_constexpr_uint32_0(state_, Name::kEmptyHashField);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp14, tmp16}, tmp17);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp14, tmp18}, tmp9);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    InitializeFieldsFromIterator_char16_UninitializedIterator_0(state_, TorqueStructSlice_char16_0{TNode<HeapObject>{tmp14}, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp10}, TorqueStructUnsafe_0{}}, TorqueStructUninitializedIterator_0{});
    TNode<SeqTwoByteString> tmp20;
    USE(tmp20);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{tmp14});
    ca_.Goto(&block1, tmp7, tmp20);
  }

  if (block1.is_used()) {
    TNode<Uint32T> tmp21;
    TNode<String> tmp22;
    ca_.Bind(&block1, &tmp21, &tmp22);
    ca_.Goto(&block8, tmp21, tmp22);
  }

    TNode<Uint32T> tmp23;
    TNode<String> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
  return TNode<String>{tmp24};
}

TNode<Int32T> LoadStringLength_0(compiler::CodeAssemblerState* state_, TNode<String> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<String> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Int32T>tmp2 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<String> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Int32T>{tmp4};
}

void StoreStringLength_0(compiler::CodeAssemblerState* state_, TNode<String> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<String, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<String> tmp0;
    TNode<Int32T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<String> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<String> LoadConsStringFirst_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ConsString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<ConsString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<String>tmp2 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<ConsString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<String>{tmp4};
}

void StoreConsStringFirst_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o, TNode<String> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<ConsString> tmp0;
    TNode<String> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<ConsString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<String> LoadConsStringSecond_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ConsString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<ConsString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<String>tmp2 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<ConsString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<String>{tmp4};
}

void StoreConsStringSecond_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o, TNode<String> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ConsString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<ConsString> tmp0;
    TNode<String> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<ConsString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<RawPtrT> LoadExternalStringResource_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ExternalString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<ExternalString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<RawPtrT>tmp2 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<ExternalString> tmp3;
    TNode<RawPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<RawPtrT>{tmp4};
}

void StoreExternalStringResource_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o, TNode<RawPtrT> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<ExternalString> tmp0;
    TNode<RawPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<ExternalString> tmp3;
    TNode<RawPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<RawPtrT> LoadExternalStringResourceData_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ExternalString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<ExternalString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<RawPtrT>tmp2 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<ExternalString> tmp3;
    TNode<RawPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<RawPtrT>{tmp4};
}

void StoreExternalStringResourceData_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o, TNode<RawPtrT> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ExternalString, RawPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<ExternalString> tmp0;
    TNode<RawPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<ExternalString> tmp3;
    TNode<RawPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<String> LoadSlicedStringParent_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SlicedString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SlicedString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<String>tmp2 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SlicedString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<String>{tmp4};
}

void StoreSlicedStringParent_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o, TNode<String> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SlicedString> tmp0;
    TNode<String> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SlicedString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadSlicedStringOffset_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SlicedString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SlicedString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SlicedString> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSlicedStringOffset_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SlicedString, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SlicedString> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SlicedString> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<String> LoadThinStringActual_0(compiler::CodeAssemblerState* state_, TNode<ThinString> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ThinString> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ThinString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<ThinString> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<String>tmp2 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<ThinString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<String>{tmp4};
}

void StoreThinStringActual_0(compiler::CodeAssemblerState* state_, TNode<ThinString> p_o, TNode<String> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<ThinString, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ThinString, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<ThinString> tmp0;
    TNode<String> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<ThinString> tmp3;
    TNode<String> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

}  // namespace internal
}  // namespace v8

