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

int31_t GetStartOfCaptureIndex_0(compiler::CodeAssemblerState* state_, int31_t p_captureIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return (CodeStubAssembler(state_).ConstexprInt31Add(RegExpMatchInfo::kFirstCaptureIndex, (CodeStubAssembler(state_).ConstexprInt31Mul(p_captureIndex, 2))));
}

TNode<Smi> Method_RegExpMatchInfo_GetStartOfCapture_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this, int31_t p_captureIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this, p_context);

  if (block0.is_used()) {
    TNode<RegExpMatchInfo> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_constexpr_int31_0(state_, (GetStartOfCaptureIndex_0(state_, p_captureIndex)));
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<RegExpMatchInfo> tmp11;
    TNode<Context> tmp12;
    TNode<RegExpMatchInfo> tmp13;
    TNode<RegExpMatchInfo> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<HeapObject> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp24});
    TNode<HeapObject> tmp26;
    USE(tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    std::tie(tmp26, tmp27) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp18}, TNode<IntPtrT>{tmp25}).Flatten();
    TNode<Object>tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp26, tmp27});
    TNode<Smi> tmp29;
    USE(tmp29);
    tmp29 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp12}, TNode<Object>{tmp28});
    ca_.Goto(&block9, tmp11, tmp12, tmp29);
  }

  if (block7.is_used()) {
    TNode<RegExpMatchInfo> tmp30;
    TNode<Context> tmp31;
    TNode<RegExpMatchInfo> tmp32;
    TNode<RegExpMatchInfo> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block7, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<RegExpMatchInfo> tmp42;
    TNode<Context> tmp43;
    TNode<Smi> tmp44;
    ca_.Bind(&block9, &tmp42, &tmp43, &tmp44);
  return TNode<Smi>{tmp44};
}

TNode<Smi> Method_RegExpMatchInfo_GetEndOfCapture_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this, int31_t p_captureIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this, p_context);

  if (block0.is_used()) {
    TNode<RegExpMatchInfo> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add((GetStartOfCaptureIndex_0(state_, p_captureIndex)), 1)));
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<RegExpMatchInfo> tmp11;
    TNode<Context> tmp12;
    TNode<RegExpMatchInfo> tmp13;
    TNode<RegExpMatchInfo> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<HeapObject> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp24});
    TNode<HeapObject> tmp26;
    USE(tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    std::tie(tmp26, tmp27) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp18}, TNode<IntPtrT>{tmp25}).Flatten();
    TNode<Object>tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp26, tmp27});
    TNode<Smi> tmp29;
    USE(tmp29);
    tmp29 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp12}, TNode<Object>{tmp28});
    ca_.Goto(&block9, tmp11, tmp12, tmp29);
  }

  if (block7.is_used()) {
    TNode<RegExpMatchInfo> tmp30;
    TNode<Context> tmp31;
    TNode<RegExpMatchInfo> tmp32;
    TNode<RegExpMatchInfo> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block7, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<RegExpMatchInfo> tmp42;
    TNode<Context> tmp43;
    TNode<Smi> tmp44;
    ca_.Bind(&block9, &tmp42, &tmp43, &tmp44);
  return TNode<Smi>{tmp44};
}

TNode<Smi> Method_RegExpMatchInfo_NumberOfCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RegExpMatchInfo, Context, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this, p_context);

  if (block0.is_used()) {
    TNode<RegExpMatchInfo> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_constexpr_int31_0(state_, RegExpMatchInfo::kNumberOfCapturesIndex);
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<RegExpMatchInfo> tmp11;
    TNode<Context> tmp12;
    TNode<RegExpMatchInfo> tmp13;
    TNode<RegExpMatchInfo> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<HeapObject> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp24});
    TNode<HeapObject> tmp26;
    USE(tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    std::tie(tmp26, tmp27) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp18}, TNode<IntPtrT>{tmp25}).Flatten();
    TNode<Object>tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp26, tmp27});
    TNode<Smi> tmp29;
    USE(tmp29);
    tmp29 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp12}, TNode<Object>{tmp28});
    ca_.Goto(&block9, tmp11, tmp12, tmp29);
  }

  if (block7.is_used()) {
    TNode<RegExpMatchInfo> tmp30;
    TNode<Context> tmp31;
    TNode<RegExpMatchInfo> tmp32;
    TNode<RegExpMatchInfo> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block7, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<RegExpMatchInfo> tmp42;
    TNode<Context> tmp43;
    TNode<Smi> tmp44;
    ca_.Bind(&block9, &tmp42, &tmp43, &tmp44);
  return TNode<Smi>{tmp44};
}

}  // namespace internal
}  // namespace v8

