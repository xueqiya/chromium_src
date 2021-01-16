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

void EnsureWriteableFastElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Number, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp3 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp3, tmp4});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = kCOWMap_0(state_);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block6, &block7, tmp0, tmp1, tmp3);
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<JSArray> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastElementsKind(array.map.elements_kind)' failed", "src/builtins/array.tq", 20);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    ca_.Bind(&block4, &tmp10, &tmp11);
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<JSArray> tmp13;
    TNode<FixedArrayBase> tmp14;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1, tmp12, tmp13);
  }

  if (block7.is_used()) {
    TNode<Context> tmp15;
    TNode<JSArray> tmp16;
    TNode<FixedArrayBase> tmp17;
    ca_.Bind(&block7, &tmp15, &tmp16, &tmp17);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp19 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp16, tmp18});
    TNode<Smi> tmp20;
    USE(tmp20);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp20 = Cast_Smi_0(state_, TNode<Object>{tmp19}, &label0);
    ca_.Goto(&block14, tmp15, tmp16, tmp17, tmp19, tmp20);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp15, tmp16, tmp17, tmp19);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp21;
    TNode<JSArray> tmp22;
    TNode<FixedArrayBase> tmp23;
    ca_.Bind(&block11, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastSmiOrTaggedElementsKind(array.map.elements_kind)' failed", "src/builtins/array.tq", 27);
  }

  if (block10.is_used()) {
    TNode<Context> tmp24;
    TNode<JSArray> tmp25;
    TNode<FixedArrayBase> tmp26;
    ca_.Bind(&block10, &tmp24, &tmp25, &tmp26);
  }

  if (block15.is_used()) {
    TNode<Context> tmp27;
    TNode<JSArray> tmp28;
    TNode<FixedArrayBase> tmp29;
    TNode<Number> tmp30;
    ca_.Bind(&block15, &tmp27, &tmp28, &tmp29, &tmp30);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block14.is_used()) {
    TNode<Context> tmp31;
    TNode<JSArray> tmp32;
    TNode<FixedArrayBase> tmp33;
    TNode<Number> tmp34;
    TNode<Smi> tmp35;
    ca_.Bind(&block14, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp35});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArray> tmp38;
    USE(tmp38);
    tmp38 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp31}, TNode<Object>{tmp33});
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp40;
    USE(tmp40);
    tmp40 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp38}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp36});
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp32, tmp37}, tmp40);
    ca_.Goto(&block1, tmp31, tmp32);
  }

  if (block19.is_used()) {
    TNode<Context> tmp41;
    TNode<JSArray> tmp42;
    TNode<FixedArrayBase> tmp43;
    TNode<IntPtrT> tmp44;
    ca_.Bind(&block19, &tmp41, &tmp42, &tmp43, &tmp44);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.elements.map != kCOWMap' failed", "src/builtins/array.tq", 33);
  }

  if (block18.is_used()) {
    TNode<Context> tmp45;
    TNode<JSArray> tmp46;
    TNode<FixedArrayBase> tmp47;
    TNode<IntPtrT> tmp48;
    ca_.Bind(&block18, &tmp45, &tmp46, &tmp47, &tmp48);
  }

  if (block1.is_used()) {
    TNode<Context> tmp49;
    TNode<JSArray> tmp50;
    ca_.Bind(&block1, &tmp49, &tmp50);
    ca_.Goto(&block20, tmp49, tmp50);
  }

    TNode<Context> tmp51;
    TNode<JSArray> tmp52;
    ca_.Bind(&block20, &tmp51, &tmp52);
}

TNode<Object> LoadElementOrUndefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_a, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_i);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp2});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Branch(tmp11, &block6, &block7, tmp0, tmp1, tmp2, tmp1, tmp1, tmp3, tmp7, tmp2, tmp2, tmp8, tmp1, tmp3, tmp7, tmp8, tmp8);
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<FixedArray> tmp13;
    TNode<Smi> tmp14;
    TNode<FixedArray> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<HeapObject> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp28});
    TNode<HeapObject> tmp30;
    USE(tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp22}, TNode<IntPtrT>{tmp29}).Flatten();
    TNode<Object>tmp32 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp30, tmp31});
    TNode<Object> tmp33;
    USE(tmp33);
    tmp33 = UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Context>{tmp12}, TNode<Object>{tmp32});
    TNode<Object> tmp34;
    USE(tmp34);
    tmp34 = ReplaceTheHoleWithUndefined_0(state_, TNode<Object>{tmp33});
    ca_.Goto(&block9, tmp12, tmp13, tmp14, tmp34);
  }

  if (block7.is_used()) {
    TNode<Context> tmp35;
    TNode<FixedArray> tmp36;
    TNode<Smi> tmp37;
    TNode<FixedArray> tmp38;
    TNode<FixedArray> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    ca_.Bind(&block7, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp50;
    TNode<FixedArray> tmp51;
    TNode<Smi> tmp52;
    TNode<Object> tmp53;
    ca_.Bind(&block9, &tmp50, &tmp51, &tmp52, &tmp53);
  return TNode<Object>{tmp53};
}

TNode<Object> LoadElementOrUndefined_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, BoolT, Float64T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, BoolT, Float64T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_i);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<Smi> tmp1;
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
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block8, &block9, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp1, tmp1, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block8.is_used()) {
    TNode<FixedDoubleArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedDoubleArray> tmp13;
    TNode<FixedDoubleArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Smi> tmp17;
    TNode<Smi> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    ca_.Bind(&block8, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp26});
    TNode<HeapObject> tmp28;
    USE(tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    std::tie(tmp28, tmp29) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp20}, TNode<IntPtrT>{tmp27}).Flatten();
    TNode<BoolT> tmp30;
    USE(tmp30);
    TNode<Float64T> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp28}, TNode<IntPtrT>{tmp29}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Branch(tmp30, &block12, &block13, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp28, tmp29, tmp30, tmp31);
  }

  if (block9.is_used()) {
    TNode<FixedDoubleArray> tmp32;
    TNode<Smi> tmp33;
    TNode<FixedDoubleArray> tmp34;
    TNode<FixedDoubleArray> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Smi> tmp38;
    TNode<Smi> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<HeapObject> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    ca_.Bind(&block9, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    TNode<FixedDoubleArray> tmp46;
    TNode<Smi> tmp47;
    TNode<FixedDoubleArray> tmp48;
    TNode<FixedDoubleArray> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Smi> tmp52;
    TNode<Smi> tmp53;
    TNode<HeapObject> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<BoolT> tmp56;
    TNode<Float64T> tmp57;
    ca_.Bind(&block12, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<Oddball> tmp58;
    USE(tmp58);
    tmp58 = Undefined_0(state_);
    ca_.Goto(&block1, tmp46, tmp47, tmp58);
  }

  if (block13.is_used()) {
    TNode<FixedDoubleArray> tmp59;
    TNode<Smi> tmp60;
    TNode<FixedDoubleArray> tmp61;
    TNode<FixedDoubleArray> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<Smi> tmp65;
    TNode<Smi> tmp66;
    TNode<HeapObject> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<BoolT> tmp69;
    TNode<Float64T> tmp70;
    ca_.Bind(&block13, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<HeapNumber> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp70});
    ca_.Goto(&block1, tmp59, tmp60, tmp71);
  }

  if (block1.is_used()) {
    TNode<FixedDoubleArray> tmp72;
    TNode<Smi> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block1, &tmp72, &tmp73, &tmp74);
    ca_.Goto(&block14, tmp72, tmp73, tmp74);
  }

    TNode<FixedDoubleArray> tmp75;
    TNode<Smi> tmp76;
    TNode<Object> tmp77;
    ca_.Bind(&block14, &tmp75, &tmp76, &tmp77);
  return TNode<Object>{tmp77};
}

void StoreArrayHole_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_k) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_k);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<Smi> tmp1;
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
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp1, tmp1, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<FixedDoubleArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedDoubleArray> tmp13;
    TNode<FixedDoubleArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Smi> tmp17;
    TNode<Smi> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp26});
    TNode<HeapObject> tmp28;
    USE(tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    std::tie(tmp28, tmp29) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp20}, TNode<IntPtrT>{tmp27}).Flatten();
    TNode<BoolT> tmp30;
    USE(tmp30);
    TNode<Float64T> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = kDoubleHole_0(state_).Flatten();
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp28}, TNode<IntPtrT>{tmp29}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp30}, TNode<Float64T>{tmp31}});
    ca_.Goto(&block9, tmp11, tmp12);
  }

  if (block7.is_used()) {
    TNode<FixedDoubleArray> tmp32;
    TNode<Smi> tmp33;
    TNode<FixedDoubleArray> tmp34;
    TNode<FixedDoubleArray> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Smi> tmp38;
    TNode<Smi> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<HeapObject> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    ca_.Bind(&block7, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<FixedDoubleArray> tmp46;
    TNode<Smi> tmp47;
    ca_.Bind(&block9, &tmp46, &tmp47);
}

void StoreArrayHole_1(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_k) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_k);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<Smi> tmp1;
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
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp0, tmp0, tmp2, tmp6, tmp1, tmp1, tmp7, tmp0, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<FixedArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedArray> tmp13;
    TNode<FixedArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Smi> tmp17;
    TNode<Smi> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp26});
    TNode<HeapObject> tmp28;
    USE(tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    std::tie(tmp28, tmp29) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp20}, TNode<IntPtrT>{tmp27}).Flatten();
    TNode<Oddball> tmp30;
    USE(tmp30);
    tmp30 = TheHole_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29}, tmp30);
    ca_.Goto(&block9, tmp11, tmp12);
  }

  if (block7.is_used()) {
    TNode<FixedArray> tmp31;
    TNode<Smi> tmp32;
    TNode<FixedArray> tmp33;
    TNode<FixedArray> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<Smi> tmp37;
    TNode<Smi> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    ca_.Bind(&block7, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<FixedArray> tmp45;
    TNode<Smi> tmp46;
    ca_.Bind(&block9, &tmp45, &tmp46);
}

void EnsureArrayLengthWritable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, DescriptorArray, DescriptorArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, DescriptorArray, DescriptorArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = ConstructorBuiltinsAssembler(state_).IsDictionaryMap(TNode<Map>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<Map> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    TNode<DescriptorArray>tmp8 = CodeStubAssembler(state_).LoadReference<DescriptorArray>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Uint16T>tmp16 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp8, tmp11});
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = Convert_intptr_uint16_0(state_, TNode<Uint16T>{tmp16});
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_intptr_constexpr_int31_0(state_, JSArray::kLengthDescriptorIndex);
    TNode<UintPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp17});
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp20});
    ca_.Branch(tmp21, &block9, &block10, tmp5, tmp6, tmp8, tmp8, tmp8, tmp9, tmp17, tmp18, tmp8, tmp9, tmp17, tmp18, tmp18);
  }

  if (block9.is_used()) {
    TNode<Context> tmp22;
    TNode<Map> tmp23;
    TNode<DescriptorArray> tmp24;
    TNode<DescriptorArray> tmp25;
    TNode<DescriptorArray> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<HeapObject> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    ca_.Bind(&block9, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp35});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp31}, TNode<IntPtrT>{tmp36});
    TNode<HeapObject> tmp38;
    USE(tmp38);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    std::tie(tmp38, tmp39) = UnsafeNewReference_DescriptorEntry_0(state_, TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp37}).Flatten();
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    TNode<IntPtrT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40});
    TNode<Object>tmp42 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp38, tmp41});
    TNode<Smi> tmp43;
    USE(tmp43);
    tmp43 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp22}, TNode<Object>{tmp42});
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyDetails::kAttributesReadOnlyMask);
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).SmiAnd(TNode<Smi>{tmp43}, TNode<Smi>{tmp44});
    TNode<Smi> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp45}, TNode<Smi>{tmp46});
    ca_.Branch(tmp47, &block16, &block17, tmp22, tmp23, tmp24, tmp38, tmp39, tmp43);
  }

  if (block10.is_used()) {
    TNode<Context> tmp48;
    TNode<Map> tmp49;
    TNode<DescriptorArray> tmp50;
    TNode<DescriptorArray> tmp51;
    TNode<DescriptorArray> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<HeapObject> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block10, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp61;
    TNode<Map> tmp62;
    TNode<DescriptorArray> tmp63;
    TNode<HeapObject> tmp64;
    TNode<IntPtrT> tmp65;
    ca_.Bind(&block15, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(descriptor->key, LengthStringConstant())' failed", "src/builtins/array.tq", 76);
  }

  if (block14.is_used()) {
    TNode<Context> tmp66;
    TNode<Map> tmp67;
    TNode<DescriptorArray> tmp68;
    TNode<HeapObject> tmp69;
    TNode<IntPtrT> tmp70;
    ca_.Bind(&block14, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
  }

  if (block16.is_used()) {
    TNode<Context> tmp71;
    TNode<Map> tmp72;
    TNode<DescriptorArray> tmp73;
    TNode<HeapObject> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<Smi> tmp76;
    ca_.Bind(&block16, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    ca_.Goto(&block1);
  }

  if (block17.is_used()) {
    TNode<Context> tmp77;
    TNode<Map> tmp78;
    TNode<DescriptorArray> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<Smi> tmp82;
    ca_.Bind(&block17, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
    ca_.Goto(&block18, tmp77, tmp78);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    TNode<Context> tmp83;
    TNode<Map> tmp84;
    ca_.Bind(&block18, &tmp83, &tmp84);
}

}  // namespace internal
}  // namespace v8

