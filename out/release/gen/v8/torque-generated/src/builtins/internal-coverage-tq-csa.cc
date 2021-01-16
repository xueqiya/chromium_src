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

TNode<FixedArray> GetCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_function, compiler::CodeAssemblerLabel* label_IfNoCoverageInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, SharedFunctionInfo, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, SharedFunctionInfo, HeapObject, Context, DebugInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, SharedFunctionInfo, DebugInfo> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, SharedFunctionInfo, DebugInfo> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, FixedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_function);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<SharedFunctionInfo>tmp3 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject>tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp4});
    TNode<DebugInfo> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_DebugInfo_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp5}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp3, tmp5, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp3, tmp5, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<JSFunction> tmp8;
    TNode<SharedFunctionInfo> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<JSFunction> tmp13;
    TNode<SharedFunctionInfo> tmp14;
    TNode<HeapObject> tmp15;
    TNode<Context> tmp16;
    TNode<DebugInfo> tmp17;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    TNode<Smi>tmp19 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp17, tmp18});
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, DebugInfo::kHasCoverageInfo);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).SmiAnd(TNode<Smi>{tmp19}, TNode<Smi>{tmp20});
    TNode<Smi> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp21}, TNode<Smi>{tmp22});
    ca_.Branch(tmp23, &block7, &block8, tmp12, tmp13, tmp14, tmp17);
  }

  if (block7.is_used()) {
    TNode<Context> tmp24;
    TNode<JSFunction> tmp25;
    TNode<SharedFunctionInfo> tmp26;
    TNode<DebugInfo> tmp27;
    ca_.Bind(&block7, &tmp24, &tmp25, &tmp26, &tmp27);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<Context> tmp28;
    TNode<JSFunction> tmp29;
    TNode<SharedFunctionInfo> tmp30;
    TNode<DebugInfo> tmp31;
    ca_.Bind(&block8, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    TNode<HeapObject>tmp33 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp31, tmp32});
    TNode<FixedArray> tmp34;
    USE(tmp34);
    tmp34 = UnsafeCast_CoverageInfo_0(state_, TNode<Context>{tmp28}, TNode<Object>{tmp33});
    ca_.Goto(&block9, tmp28, tmp29, tmp34);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfNoCoverageInfo);
  }

    TNode<Context> tmp35;
    TNode<JSFunction> tmp36;
    TNode<FixedArray> tmp37;
    ca_.Bind(&block9, &tmp35, &tmp36, &tmp37);
  return TNode<FixedArray>{tmp37};
}

TNode<Smi> SlotCount_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_coverageInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_coverageInfo);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiSar(TNode<Smi>{tmp2}, CoverageInfo::kSlotIndexCountLog2);
    ca_.Goto(&block10, tmp0, tmp3);
  }

  if (block5.is_used()) {
    TNode<FixedArray> tmp4;
    ca_.Bind(&block5, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kFirstSlotIndex == 0' failed", "src/builtins/internal-coverage.tq", 32);
  }

  if (block4.is_used()) {
    TNode<FixedArray> tmp5;
    ca_.Bind(&block4, &tmp5);
  }

  if (block9.is_used()) {
    TNode<FixedArray> tmp6;
    ca_.Bind(&block9, &tmp6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kFirstSlotIndex == (coverageInfo.length & kSlotIndexCountMask)' failed", "src/builtins/internal-coverage.tq", 33);
  }

  if (block8.is_used()) {
    TNode<FixedArray> tmp7;
    ca_.Bind(&block8, &tmp7);
  }

    TNode<FixedArray> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block10, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

TNode<Smi> FirstIndexForSlot_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_slot) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_slot);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiShl(TNode<Smi>{tmp1}, CoverageInfo::kSlotIndexCountLog2);
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kFirstSlotIndex == 0' failed", "src/builtins/internal-coverage.tq", 38);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Smi> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

void IncrementBlockCount_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_coverageInfo, TNode<Smi> p_slot) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_coverageInfo, p_slot);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FirstIndexForSlot_0(state_, TNode<Context>{tmp0}, TNode<Smi>{tmp2});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, CoverageInfo::kSlotBlockCountIndex);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<UintPtrT> tmp12;
    USE(tmp12);
    tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp10});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp12}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp14, &block10, &block11, tmp0, tmp1, tmp2, tmp3, tmp5, tmp1, tmp1, tmp6, tmp10, tmp5, tmp5, tmp11, tmp1, tmp6, tmp10, tmp11, tmp11);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<FixedArray> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'slot < SlotCount(coverageInfo)' failed", "src/builtins/internal-coverage.tq", 44);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<FixedArray> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20);
  }

  if (block10.is_used()) {
    TNode<Context> tmp21;
    TNode<FixedArray> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    TNode<FixedArray> tmp26;
    TNode<FixedArray> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<Smi> tmp30;
    TNode<Smi> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    ca_.Bind(&block10, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp39});
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp33}, TNode<IntPtrT>{tmp40}).Flatten();
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp46 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp22, tmp45});
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp46});
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp25});
    TNode<UintPtrT> tmp49;
    USE(tmp49);
    tmp49 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp48});
    TNode<UintPtrT> tmp50;
    USE(tmp50);
    tmp50 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp47});
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp49}, TNode<UintPtrT>{tmp50});
    ca_.Branch(tmp51, &block17, &block18, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp41, tmp42, tmp22, tmp22, tmp43, tmp47, tmp25, tmp25, tmp48, tmp22, tmp43, tmp47, tmp48, tmp48);
  }

  if (block11.is_used()) {
    TNode<Context> tmp52;
    TNode<FixedArray> tmp53;
    TNode<Smi> tmp54;
    TNode<Smi> tmp55;
    TNode<Smi> tmp56;
    TNode<FixedArray> tmp57;
    TNode<FixedArray> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<Smi> tmp61;
    TNode<Smi> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<HeapObject> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    ca_.Bind(&block11, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<Context> tmp69;
    TNode<FixedArray> tmp70;
    TNode<Smi> tmp71;
    TNode<Smi> tmp72;
    TNode<Smi> tmp73;
    TNode<FixedArray> tmp74;
    TNode<FixedArray> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<Smi> tmp78;
    TNode<Smi> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<FixedArray> tmp82;
    TNode<FixedArray> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<Smi> tmp86;
    TNode<Smi> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    ca_.Bind(&block17, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<IntPtrT> tmp94;
    USE(tmp94);
    tmp94 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp95;
    USE(tmp95);
    tmp95 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp93}, TNode<IntPtrT>{tmp94});
    TNode<IntPtrT> tmp96;
    USE(tmp96);
    tmp96 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp95});
    TNode<HeapObject> tmp97;
    USE(tmp97);
    TNode<IntPtrT> tmp98;
    USE(tmp98);
    std::tie(tmp97, tmp98) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp89}, TNode<IntPtrT>{tmp96}).Flatten();
    TNode<Object>tmp99 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp97, tmp98});
    TNode<Smi> tmp100;
    USE(tmp100);
    tmp100 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp69}, TNode<Object>{tmp99});
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp102;
    USE(tmp102);
    tmp102 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp100}, TNode<Smi>{tmp101});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp80, tmp81}, tmp102);
    ca_.Goto(&block20, tmp69, tmp70, tmp71);
  }

  if (block18.is_used()) {
    TNode<Context> tmp103;
    TNode<FixedArray> tmp104;
    TNode<Smi> tmp105;
    TNode<Smi> tmp106;
    TNode<Smi> tmp107;
    TNode<FixedArray> tmp108;
    TNode<FixedArray> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<Smi> tmp112;
    TNode<Smi> tmp113;
    TNode<HeapObject> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<FixedArray> tmp116;
    TNode<FixedArray> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<Smi> tmp120;
    TNode<Smi> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<HeapObject> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<IntPtrT> tmp126;
    TNode<IntPtrT> tmp127;
    ca_.Bind(&block18, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp128;
    TNode<FixedArray> tmp129;
    TNode<Smi> tmp130;
    ca_.Bind(&block20, &tmp128, &tmp129, &tmp130);
}

TF_BUILTIN(IncBlockCounter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSFunction> parameter1 = UncheckedCast<JSFunction>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, Smi, JSFunction, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, Smi, JSFunction, Context, FixedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = GetCoverageInfo_0(state_, TNode<Context>{tmp0}, TNode<JSFunction>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSFunction> tmp5;
    TNode<Smi> tmp6;
    TNode<JSFunction> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block3.is_used()) {
    TNode<Context> tmp10;
    TNode<JSFunction> tmp11;
    TNode<Smi> tmp12;
    TNode<JSFunction> tmp13;
    TNode<Context> tmp14;
    TNode<FixedArray> tmp15;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    IncrementBlockCount_0(state_, TNode<Context>{tmp10}, TNode<FixedArray>{tmp15}, TNode<Smi>{tmp12});
    TNode<Oddball> tmp16;
    USE(tmp16);
    tmp16 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp16);
  }
}

TNode<FixedArray> UnsafeCast_CoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 887);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<FixedArray> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<FixedArray>{tmp9};
}

}  // namespace internal
}  // namespace v8

