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

TNode<IntPtrT> AddIndexedFieldSizeToObjectSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_baseSize, TNode<IntPtrT> p_arrayLength, int32_t p_fieldSize) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, Int32T, Int32T, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, Int32T, Int32T, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, Int32T, Int32T, IntPtrT, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_baseSize, p_arrayLength);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = Convert_int32_intptr_0(state_, TNode<IntPtrT>{tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int32_0(state_, p_fieldSize);
    TNode<Int32T> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = CodeStubAssembler(state_).TryInt32Mul(TNode<Int32T>{tmp2}, TNode<Int32T>{tmp3}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp2, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp2);
    }
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Int32T> tmp7;
    TNode<Int32T> tmp8;
    ca_.Bind(&block5, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Int32T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Int32T> tmp13;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp13});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = CodeStubAssembler(state_).TryIntPtrAdd(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp14}, &label0);
    ca_.Goto(&block8, tmp9, tmp10, tmp11, tmp13, tmp9, tmp14, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp9, tmp10, tmp11, tmp13, tmp9, tmp14);
    }
  }

  if (block9.is_used()) {
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<Int32T> tmp18;
    TNode<Int32T> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    ca_.Bind(&block9, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block8.is_used()) {
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<Int32T> tmp24;
    TNode<Int32T> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    ca_.Bind(&block8, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block10, tmp22, tmp23, tmp28);
  }

    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    ca_.Bind(&block10, &tmp29, &tmp30, &tmp31);
  return TNode<IntPtrT>{tmp31};
}

TNode<IntPtrT> AlignTagged_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, kObjectAlignmentMask);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, (CodeStubAssembler(state_).ConstexprWordNot(kObjectAlignmentMask)));
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<IntPtrT>{tmp6};
}

TNode<BoolT> IsTaggedAligned_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, kObjectAlignmentMask);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<IntPtrT> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<BoolT>{tmp6};
}

TNode<BoolT> ValidAllocationSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, IntPtrT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, IntPtrT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, IntPtrT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_sizeInBytes, p_map);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp4;
    TNode<Map> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4, tmp5, tmp6);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp7;
    TNode<Map> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = IsTaggedAligned_0(state_, TNode<IntPtrT>{tmp7});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp9});
    ca_.Branch(tmp10, &block4, &block5, tmp7, tmp8);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp11;
    TNode<Map> tmp12;
    ca_.Bind(&block4, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp11, tmp12, tmp13);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp14;
    TNode<Map> tmp15;
    ca_.Bind(&block5, &tmp14, &tmp15);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Uint8T>tmp17 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp15, tmp16});
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, kVariableSizeSentinel);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp19});
    ca_.Branch(tmp20, &block6, &block7, tmp14, tmp15, tmp18, tmp20);
  }

  if (block6.is_used()) {
    TNode<IntPtrT> tmp21;
    TNode<Map> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<BoolT> tmp24;
    ca_.Bind(&block6, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block8, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block7.is_used()) {
    TNode<IntPtrT> tmp26;
    TNode<Map> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<BoolT> tmp29;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp30});
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp31}, TNode<IntPtrT>{tmp26});
    ca_.Goto(&block8, tmp26, tmp27, tmp28, tmp29, tmp32);
  }

  if (block8.is_used()) {
    TNode<IntPtrT> tmp33;
    TNode<Map> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<BoolT> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block8, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block1, tmp33, tmp34, tmp37);
  }

  if (block1.is_used()) {
    TNode<IntPtrT> tmp38;
    TNode<Map> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block1, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block9, tmp38, tmp39, tmp40);
  }

    TNode<IntPtrT> tmp41;
    TNode<Map> tmp42;
    TNode<BoolT> tmp43;
    ca_.Bind(&block9, &tmp41, &tmp42, &tmp43);
  return TNode<BoolT>{tmp43};
}

TNode<HeapObject> Allocate_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Map, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_sizeInBytes, p_map);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateAllowLOS(TNode<IntPtrT>{tmp0});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp3;
    TNode<Map> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ValidAllocationSize(sizeInBytes, map)' failed", "src/builtins/torque-internal.tq", 154);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<IntPtrT> tmp7;
    TNode<Map> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<HeapObject>{tmp9};
}

void InitializeFieldsFromIterator_char8_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__target.object, p__target.offset, p__target.length);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
}

void InitializeFieldsFromIterator_char16_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char16_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__target.object, p__target.offset, p__target.length);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
}

TorqueStructfloat64_or_hole_0 LoadFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_r.object, p_r.offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IsDoubleHole(TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp3});
    TNode<HeapObject> tmp5;
    USE(tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    std::tie(tmp5, tmp6) = UnsafeNewReference_float64_0(state_, TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp1}).Flatten();
    TNode<Float64T>tmp7 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp5, tmp6});
    ca_.Goto(&block2, tmp0, tmp1, tmp4, tmp7);
  }

    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<BoolT> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11);
  return TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp10}, TNode<Float64T>{tmp11}};
}

void StoreFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r, TorqueStructfloat64_or_hole_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, BoolT, Float64T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_r.object, p_r.offset, p_value.is_hole, p_value.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<BoolT> tmp2;
    TNode<Float64T> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<BoolT> tmp6;
    TNode<Float64T> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8});
    CodeStubAssembler(state_).StoreDoubleHole(TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp9});
    ca_.Goto(&block4, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<BoolT> tmp12;
    TNode<Float64T> tmp13;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<HeapObject> tmp14;
    USE(tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    std::tie(tmp14, tmp15) = UnsafeNewReference_float64_0(state_, TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp11}).Flatten();
    TNode<Float64T> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp13});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp14, tmp15}, tmp16);
    ca_.Goto(&block4, tmp10, tmp11, tmp12, tmp13);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<BoolT> tmp19;
    TNode<Float64T> tmp20;
    ca_.Bind(&block4, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block5, tmp17, tmp18, tmp19, tmp20);
  }

    TNode<HeapObject> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<BoolT> tmp23;
    TNode<Float64T> tmp24;
    ca_.Bind(&block5, &tmp21, &tmp22, &tmp23, &tmp24);
}

TorqueStructReference_Object_0 UnsafeNewReference_Object_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_Object_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_float64_or_hole_0 UnsafeNewReference_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TNode<IntPtrT> Convert_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TorqueStructReference_DescriptorEntry_0 UnsafeNewReference_DescriptorEntry_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_DescriptorEntry_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_float64_0 UnsafeNewReference_float64_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_float64_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_char8_0 UnsafeNewReference_char8_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_char8_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_char16_0 UnsafeNewReference_char16_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_char16_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_uint8_0 UnsafeNewReference_uint8_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_uint8_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 UnsafeNewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

TorqueStructReference_HashMapEntry_0 UnsafeNewReference_HashMapEntry_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_object, p_offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructReference_HashMapEntry_0{TNode<HeapObject>{tmp4}, TNode<IntPtrT>{tmp5}, TorqueStructUnsafe_0{}};
}

}  // namespace internal
}  // namespace v8

