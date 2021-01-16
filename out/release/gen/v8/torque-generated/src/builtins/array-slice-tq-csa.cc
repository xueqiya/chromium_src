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

TNode<JSArray> HandleSimpleArgumentsSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<JSArgumentsObject> p_args, TNode<Smi> p_start, TNode<Smi> p_count, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArrayBase, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArray, Map, JSArray, FixedArrayBase> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, Smi, FixedArray, Map, JSArray, FixedArrayBase, FixedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, JSArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_args, p_start, p_count);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<JSArgumentsObject> tmp1;
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, FixedArray::kMaxRegularLength);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp6;
    TNode<JSArgumentsObject> tmp7;
    TNode<Smi> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp10;
    TNode<JSArgumentsObject> tmp11;
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<Smi> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp16 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp11, tmp15});
    TNode<FixedArray> tmp17;
    USE(tmp17);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp17 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp16}, &label0);
    ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp14, tmp16, tmp17);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp10, tmp11, tmp12, tmp13, tmp14, tmp16);
    }
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp18;
    TNode<JSArgumentsObject> tmp19;
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    TNode<FixedArrayBase> tmp23;
    ca_.Bind(&block6, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp24;
    TNode<JSArgumentsObject> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    TNode<Smi> tmp28;
    TNode<FixedArrayBase> tmp29;
    TNode<FixedArray> tmp30;
    ca_.Bind(&block5, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp32 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp30, tmp31});
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).SmiAbove(TNode<Smi>{tmp28}, TNode<Smi>{tmp32});
    ca_.Branch(tmp33, &block7, &block8, tmp24, tmp25, tmp26, tmp27, tmp28, tmp30);
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp34;
    TNode<JSArgumentsObject> tmp35;
    TNode<Smi> tmp36;
    TNode<Smi> tmp37;
    TNode<Smi> tmp38;
    TNode<FixedArray> tmp39;
    ca_.Bind(&block7, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp40;
    TNode<JSArgumentsObject> tmp41;
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    TNode<Smi> tmp44;
    TNode<FixedArray> tmp45;
    ca_.Bind(&block8, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<Map> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::HOLEY_ELEMENTS, TNode<NativeContext>{tmp40});
    TNode<JSArray> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::HOLEY_ELEMENTS, TNode<Map>{tmp46}, TNode<Smi>{tmp43}, TNode<Smi>{tmp43});
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp49 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp47, tmp48});
    TNode<FixedArray> tmp50;
    USE(tmp50);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp50 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp49}, &label0);
    ca_.Goto(&block9, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp49, tmp50);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp49);
    }
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp51;
    TNode<JSArgumentsObject> tmp52;
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    TNode<Smi> tmp55;
    TNode<FixedArray> tmp56;
    TNode<Map> tmp57;
    TNode<JSArray> tmp58;
    TNode<FixedArrayBase> tmp59;
    ca_.Bind(&block10, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    ca_.Goto(&block1);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp60;
    TNode<JSArgumentsObject> tmp61;
    TNode<Smi> tmp62;
    TNode<Smi> tmp63;
    TNode<Smi> tmp64;
    TNode<FixedArray> tmp65;
    TNode<Map> tmp66;
    TNode<JSArray> tmp67;
    TNode<FixedArrayBase> tmp68;
    TNode<FixedArray> tmp69;
    ca_.Bind(&block9, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<IntPtrT> tmp70;
    USE(tmp70);
    tmp70 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp62});
    TNode<IntPtrT> tmp71;
    USE(tmp71);
    tmp71 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp63});
    TNode<IntPtrT> tmp72;
    USE(tmp72);
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).CopyElements(ElementsKind::PACKED_ELEMENTS, TNode<FixedArrayBase>{tmp69}, TNode<IntPtrT>{tmp72}, TNode<FixedArrayBase>{tmp65}, TNode<IntPtrT>{tmp70}, TNode<IntPtrT>{tmp71});
    ca_.Goto(&block11, tmp60, tmp61, tmp62, tmp63, tmp67);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    TNode<NativeContext> tmp73;
    TNode<JSArgumentsObject> tmp74;
    TNode<Smi> tmp75;
    TNode<Smi> tmp76;
    TNode<JSArray> tmp77;
    ca_.Bind(&block11, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
  return TNode<JSArray>{tmp77};
}

TNode<JSArray> HandleFastAliasedSloppyArgumentsSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<JSArgumentsObject> p_args, TNode<Smi> p_start, TNode<Smi> p_count, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArrayBase, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, Object, NativeContext> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, Object, NativeContext, FixedArray> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, FixedArray, Smi, Smi, Smi, FixedArray, Smi, Context, Map, JSArray, Smi, FixedArray, Smi, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, JSArgumentsObject, Smi, Smi, JSArray> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_args, p_start, p_count);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<JSArgumentsObject> tmp1;
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, FixedArray::kMaxRegularLength);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp6;
    TNode<JSArgumentsObject> tmp7;
    TNode<Smi> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp10;
    TNode<JSArgumentsObject> tmp11;
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp15 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp11, tmp14});
    TNode<FixedArray> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_SloppyArgumentsElements_0(state_, TNode<HeapObject>{tmp15}, &label0);
    ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp15, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp10, tmp11, tmp12, tmp13, tmp15);
    }
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<JSArgumentsObject> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<FixedArrayBase> tmp21;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp22;
    TNode<JSArgumentsObject> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    TNode<FixedArrayBase> tmp26;
    TNode<FixedArray> tmp27;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp29 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp27, tmp28});
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, SloppyArgumentsElements::kParameterMapStart);
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp29}, TNode<Smi>{tmp30});
    TNode<Smi> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp24}, TNode<Smi>{tmp25});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp36 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp27, tmp35});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp36});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = Convert_intptr_constexpr_int31_0(state_, SloppyArgumentsElements::kArgumentsIndex);
    TNode<UintPtrT> tmp39;
    USE(tmp39);
    tmp39 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp38});
    TNode<UintPtrT> tmp40;
    USE(tmp40);
    tmp40 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp37});
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.Branch(tmp41, &block11, &block12, tmp22, tmp23, tmp24, tmp25, tmp27, tmp29, tmp31, tmp32, tmp27, tmp27, tmp33, tmp37, tmp38, tmp27, tmp33, tmp37, tmp38, tmp38);
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp42;
    TNode<JSArgumentsObject> tmp43;
    TNode<Smi> tmp44;
    TNode<Smi> tmp45;
    TNode<FixedArray> tmp46;
    TNode<Smi> tmp47;
    TNode<Smi> tmp48;
    TNode<Smi> tmp49;
    TNode<FixedArray> tmp50;
    TNode<FixedArray> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<HeapObject> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block11, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<IntPtrT> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp59}, TNode<IntPtrT>{tmp60});
    TNode<IntPtrT> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp56}, TNode<IntPtrT>{tmp61});
    TNode<HeapObject> tmp63;
    USE(tmp63);
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    std::tie(tmp63, tmp64) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp55}, TNode<IntPtrT>{tmp62}).Flatten();
    TNode<Object>tmp65 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp63, tmp64});
    TNode<FixedArray> tmp66;
    USE(tmp66);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp66 = Cast_FixedArray_1(state_, TNode<Context>{tmp42}, TNode<Object>{tmp65}, &label0);
    ca_.Goto(&block14, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp65, tmp42, tmp66);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp65, tmp42);
    }
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp67;
    TNode<JSArgumentsObject> tmp68;
    TNode<Smi> tmp69;
    TNode<Smi> tmp70;
    TNode<FixedArray> tmp71;
    TNode<Smi> tmp72;
    TNode<Smi> tmp73;
    TNode<Smi> tmp74;
    TNode<FixedArray> tmp75;
    TNode<FixedArray> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    ca_.Bind(&block12, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp85;
    TNode<JSArgumentsObject> tmp86;
    TNode<Smi> tmp87;
    TNode<Smi> tmp88;
    TNode<FixedArray> tmp89;
    TNode<Smi> tmp90;
    TNode<Smi> tmp91;
    TNode<Smi> tmp92;
    TNode<Object> tmp93;
    TNode<NativeContext> tmp94;
    ca_.Bind(&block15, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp95;
    TNode<JSArgumentsObject> tmp96;
    TNode<Smi> tmp97;
    TNode<Smi> tmp98;
    TNode<FixedArray> tmp99;
    TNode<Smi> tmp100;
    TNode<Smi> tmp101;
    TNode<Smi> tmp102;
    TNode<Object> tmp103;
    TNode<NativeContext> tmp104;
    TNode<FixedArray> tmp105;
    ca_.Bind(&block14, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
    TNode<IntPtrT> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp107 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp105, tmp106});
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).SmiAbove(TNode<Smi>{tmp102}, TNode<Smi>{tmp107});
    ca_.Branch(tmp108, &block16, &block17, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp105, tmp107);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp109;
    TNode<JSArgumentsObject> tmp110;
    TNode<Smi> tmp111;
    TNode<Smi> tmp112;
    TNode<FixedArray> tmp113;
    TNode<Smi> tmp114;
    TNode<Smi> tmp115;
    TNode<Smi> tmp116;
    TNode<FixedArray> tmp117;
    TNode<Smi> tmp118;
    ca_.Bind(&block16, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    ca_.Goto(&block1);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp119;
    TNode<JSArgumentsObject> tmp120;
    TNode<Smi> tmp121;
    TNode<Smi> tmp122;
    TNode<FixedArray> tmp123;
    TNode<Smi> tmp124;
    TNode<Smi> tmp125;
    TNode<Smi> tmp126;
    TNode<FixedArray> tmp127;
    TNode<Smi> tmp128;
    ca_.Bind(&block17, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    TNode<IntPtrT> tmp129;
    USE(tmp129);
    tmp129 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp130;
    USE(tmp130);
    tmp130 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp131;
    USE(tmp131);
    tmp131 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp132 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp123, tmp131});
    TNode<IntPtrT> tmp133;
    USE(tmp133);
    tmp133 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp132});
    TNode<IntPtrT> tmp134;
    USE(tmp134);
    tmp134 = Convert_intptr_constexpr_int31_0(state_, SloppyArgumentsElements::kContextIndex);
    TNode<UintPtrT> tmp135;
    USE(tmp135);
    tmp135 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp134});
    TNode<UintPtrT> tmp136;
    USE(tmp136);
    tmp136 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp133});
    TNode<BoolT> tmp137;
    USE(tmp137);
    tmp137 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp135}, TNode<UintPtrT>{tmp136});
    ca_.Branch(tmp137, &block22, &block23, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp123, tmp123, tmp129, tmp133, tmp134, tmp123, tmp129, tmp133, tmp134, tmp134);
  }

  if (block22.is_used()) {
    TNode<NativeContext> tmp138;
    TNode<JSArgumentsObject> tmp139;
    TNode<Smi> tmp140;
    TNode<Smi> tmp141;
    TNode<FixedArray> tmp142;
    TNode<Smi> tmp143;
    TNode<Smi> tmp144;
    TNode<Smi> tmp145;
    TNode<FixedArray> tmp146;
    TNode<Smi> tmp147;
    TNode<FixedArray> tmp148;
    TNode<FixedArray> tmp149;
    TNode<IntPtrT> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<HeapObject> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<IntPtrT> tmp157;
    ca_.Bind(&block22, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157);
    TNode<IntPtrT> tmp158;
    USE(tmp158);
    tmp158 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp159;
    USE(tmp159);
    tmp159 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp157}, TNode<IntPtrT>{tmp158});
    TNode<IntPtrT> tmp160;
    USE(tmp160);
    tmp160 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp154}, TNode<IntPtrT>{tmp159});
    TNode<HeapObject> tmp161;
    USE(tmp161);
    TNode<IntPtrT> tmp162;
    USE(tmp162);
    std::tie(tmp161, tmp162) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp153}, TNode<IntPtrT>{tmp160}).Flatten();
    TNode<Object>tmp163 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp161, tmp162});
    TNode<Context> tmp164;
    USE(tmp164);
    tmp164 = UnsafeCast_Context_0(state_, TNode<Context>{tmp138}, TNode<Object>{tmp163});
    TNode<Map> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::HOLEY_ELEMENTS, TNode<NativeContext>{tmp138});
    TNode<JSArray> tmp166;
    USE(tmp166);
    tmp166 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::HOLEY_ELEMENTS, TNode<Map>{tmp165}, TNode<Smi>{tmp141}, TNode<Smi>{tmp141});
    TNode<Smi> tmp167;
    USE(tmp167);
    tmp167 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp168;
    USE(tmp168);
    tmp168 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp169 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp166, tmp168});
    TNode<FixedArray> tmp170;
    USE(tmp170);
    tmp170 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp138}, TNode<Object>{tmp169});
    TNode<Smi> tmp171;
    USE(tmp171);
    tmp171 = CodeStubAssembler(state_).SmiMin(TNode<Smi>{tmp144}, TNode<Smi>{tmp145});
    ca_.Goto(&block27, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp164, tmp165, tmp166, tmp167, tmp170, tmp171, tmp140);
  }

  if (block23.is_used()) {
    TNode<NativeContext> tmp172;
    TNode<JSArgumentsObject> tmp173;
    TNode<Smi> tmp174;
    TNode<Smi> tmp175;
    TNode<FixedArray> tmp176;
    TNode<Smi> tmp177;
    TNode<Smi> tmp178;
    TNode<Smi> tmp179;
    TNode<FixedArray> tmp180;
    TNode<Smi> tmp181;
    TNode<FixedArray> tmp182;
    TNode<FixedArray> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<IntPtrT> tmp186;
    TNode<HeapObject> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<IntPtrT> tmp191;
    ca_.Bind(&block23, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    TNode<NativeContext> tmp192;
    TNode<JSArgumentsObject> tmp193;
    TNode<Smi> tmp194;
    TNode<Smi> tmp195;
    TNode<FixedArray> tmp196;
    TNode<Smi> tmp197;
    TNode<Smi> tmp198;
    TNode<Smi> tmp199;
    TNode<FixedArray> tmp200;
    TNode<Smi> tmp201;
    TNode<Context> tmp202;
    TNode<Map> tmp203;
    TNode<JSArray> tmp204;
    TNode<Smi> tmp205;
    TNode<FixedArray> tmp206;
    TNode<Smi> tmp207;
    TNode<Smi> tmp208;
    ca_.Bind(&block27, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208);
    TNode<BoolT> tmp209;
    USE(tmp209);
    tmp209 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp208}, TNode<Smi>{tmp207});
    ca_.Branch(tmp209, &block25, &block26, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208);
  }

  if (block25.is_used()) {
    TNode<NativeContext> tmp210;
    TNode<JSArgumentsObject> tmp211;
    TNode<Smi> tmp212;
    TNode<Smi> tmp213;
    TNode<FixedArray> tmp214;
    TNode<Smi> tmp215;
    TNode<Smi> tmp216;
    TNode<Smi> tmp217;
    TNode<FixedArray> tmp218;
    TNode<Smi> tmp219;
    TNode<Context> tmp220;
    TNode<Map> tmp221;
    TNode<JSArray> tmp222;
    TNode<Smi> tmp223;
    TNode<FixedArray> tmp224;
    TNode<Smi> tmp225;
    TNode<Smi> tmp226;
    ca_.Bind(&block25, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226);
    TNode<IntPtrT> tmp227;
    USE(tmp227);
    tmp227 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp228;
    USE(tmp228);
    tmp228 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp229;
    USE(tmp229);
    tmp229 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp230 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp214, tmp229});
    TNode<IntPtrT> tmp231;
    USE(tmp231);
    tmp231 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp230});
    TNode<Smi> tmp232;
    USE(tmp232);
    tmp232 = FromConstexpr_Smi_constexpr_int31_0(state_, SloppyArgumentsElements::kParameterMapStart);
    TNode<Smi> tmp233;
    USE(tmp233);
    tmp233 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp226}, TNode<Smi>{tmp232});
    TNode<IntPtrT> tmp234;
    USE(tmp234);
    tmp234 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp233});
    TNode<UintPtrT> tmp235;
    USE(tmp235);
    tmp235 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp234});
    TNode<UintPtrT> tmp236;
    USE(tmp236);
    tmp236 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp231});
    TNode<BoolT> tmp237;
    USE(tmp237);
    tmp237 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp235}, TNode<UintPtrT>{tmp236});
    ca_.Branch(tmp237, &block33, &block34, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp214, tmp214, tmp227, tmp231, tmp233, tmp233, tmp234, tmp214, tmp227, tmp231, tmp234, tmp234);
  }

  if (block33.is_used()) {
    TNode<NativeContext> tmp238;
    TNode<JSArgumentsObject> tmp239;
    TNode<Smi> tmp240;
    TNode<Smi> tmp241;
    TNode<FixedArray> tmp242;
    TNode<Smi> tmp243;
    TNode<Smi> tmp244;
    TNode<Smi> tmp245;
    TNode<FixedArray> tmp246;
    TNode<Smi> tmp247;
    TNode<Context> tmp248;
    TNode<Map> tmp249;
    TNode<JSArray> tmp250;
    TNode<Smi> tmp251;
    TNode<FixedArray> tmp252;
    TNode<Smi> tmp253;
    TNode<Smi> tmp254;
    TNode<FixedArray> tmp255;
    TNode<FixedArray> tmp256;
    TNode<IntPtrT> tmp257;
    TNode<IntPtrT> tmp258;
    TNode<Smi> tmp259;
    TNode<Smi> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<HeapObject> tmp262;
    TNode<IntPtrT> tmp263;
    TNode<IntPtrT> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    ca_.Bind(&block33, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266);
    TNode<IntPtrT> tmp267;
    USE(tmp267);
    tmp267 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp268;
    USE(tmp268);
    tmp268 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp266}, TNode<IntPtrT>{tmp267});
    TNode<IntPtrT> tmp269;
    USE(tmp269);
    tmp269 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp263}, TNode<IntPtrT>{tmp268});
    TNode<HeapObject> tmp270;
    USE(tmp270);
    TNode<IntPtrT> tmp271;
    USE(tmp271);
    std::tie(tmp270, tmp271) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp262}, TNode<IntPtrT>{tmp269}).Flatten();
    TNode<Object>tmp272 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp270, tmp271});
    TNode<Oddball> tmp273;
    USE(tmp273);
    tmp273 = TheHole_0(state_);
    TNode<BoolT> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp272}, TNode<HeapObject>{tmp273});
    ca_.Branch(tmp274, &block36, &block37, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251, tmp252, tmp253, tmp254, tmp272);
  }

  if (block34.is_used()) {
    TNode<NativeContext> tmp275;
    TNode<JSArgumentsObject> tmp276;
    TNode<Smi> tmp277;
    TNode<Smi> tmp278;
    TNode<FixedArray> tmp279;
    TNode<Smi> tmp280;
    TNode<Smi> tmp281;
    TNode<Smi> tmp282;
    TNode<FixedArray> tmp283;
    TNode<Smi> tmp284;
    TNode<Context> tmp285;
    TNode<Map> tmp286;
    TNode<JSArray> tmp287;
    TNode<Smi> tmp288;
    TNode<FixedArray> tmp289;
    TNode<Smi> tmp290;
    TNode<Smi> tmp291;
    TNode<FixedArray> tmp292;
    TNode<FixedArray> tmp293;
    TNode<IntPtrT> tmp294;
    TNode<IntPtrT> tmp295;
    TNode<Smi> tmp296;
    TNode<Smi> tmp297;
    TNode<IntPtrT> tmp298;
    TNode<HeapObject> tmp299;
    TNode<IntPtrT> tmp300;
    TNode<IntPtrT> tmp301;
    TNode<IntPtrT> tmp302;
    TNode<IntPtrT> tmp303;
    ca_.Bind(&block34, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block36.is_used()) {
    TNode<NativeContext> tmp304;
    TNode<JSArgumentsObject> tmp305;
    TNode<Smi> tmp306;
    TNode<Smi> tmp307;
    TNode<FixedArray> tmp308;
    TNode<Smi> tmp309;
    TNode<Smi> tmp310;
    TNode<Smi> tmp311;
    TNode<FixedArray> tmp312;
    TNode<Smi> tmp313;
    TNode<Context> tmp314;
    TNode<Map> tmp315;
    TNode<JSArray> tmp316;
    TNode<Smi> tmp317;
    TNode<FixedArray> tmp318;
    TNode<Smi> tmp319;
    TNode<Smi> tmp320;
    TNode<Object> tmp321;
    ca_.Bind(&block36, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321);
    TNode<Smi> tmp322;
    USE(tmp322);
    tmp322 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp304}, TNode<Object>{tmp321});
    TNode<Object> tmp323;
    USE(tmp323);
    tmp323 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp314}, TNode<Smi>{tmp322});
    ca_.Goto(&block38, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp320, tmp321, tmp323);
  }

  if (block37.is_used()) {
    TNode<NativeContext> tmp324;
    TNode<JSArgumentsObject> tmp325;
    TNode<Smi> tmp326;
    TNode<Smi> tmp327;
    TNode<FixedArray> tmp328;
    TNode<Smi> tmp329;
    TNode<Smi> tmp330;
    TNode<Smi> tmp331;
    TNode<FixedArray> tmp332;
    TNode<Smi> tmp333;
    TNode<Context> tmp334;
    TNode<Map> tmp335;
    TNode<JSArray> tmp336;
    TNode<Smi> tmp337;
    TNode<FixedArray> tmp338;
    TNode<Smi> tmp339;
    TNode<Smi> tmp340;
    TNode<Object> tmp341;
    ca_.Bind(&block37, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341);
    TNode<IntPtrT> tmp342;
    USE(tmp342);
    tmp342 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp343;
    USE(tmp343);
    tmp343 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp344;
    USE(tmp344);
    tmp344 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp345 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp332, tmp344});
    TNode<IntPtrT> tmp346;
    USE(tmp346);
    tmp346 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp345});
    TNode<IntPtrT> tmp347;
    USE(tmp347);
    tmp347 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp340});
    TNode<UintPtrT> tmp348;
    USE(tmp348);
    tmp348 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp347});
    TNode<UintPtrT> tmp349;
    USE(tmp349);
    tmp349 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp346});
    TNode<BoolT> tmp350;
    USE(tmp350);
    tmp350 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp348}, TNode<UintPtrT>{tmp349});
    ca_.Branch(tmp350, &block44, &block45, tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp332, tmp332, tmp342, tmp346, tmp340, tmp340, tmp347, tmp332, tmp342, tmp346, tmp347, tmp347);
  }

  if (block44.is_used()) {
    TNode<NativeContext> tmp351;
    TNode<JSArgumentsObject> tmp352;
    TNode<Smi> tmp353;
    TNode<Smi> tmp354;
    TNode<FixedArray> tmp355;
    TNode<Smi> tmp356;
    TNode<Smi> tmp357;
    TNode<Smi> tmp358;
    TNode<FixedArray> tmp359;
    TNode<Smi> tmp360;
    TNode<Context> tmp361;
    TNode<Map> tmp362;
    TNode<JSArray> tmp363;
    TNode<Smi> tmp364;
    TNode<FixedArray> tmp365;
    TNode<Smi> tmp366;
    TNode<Smi> tmp367;
    TNode<Object> tmp368;
    TNode<FixedArray> tmp369;
    TNode<FixedArray> tmp370;
    TNode<IntPtrT> tmp371;
    TNode<IntPtrT> tmp372;
    TNode<Smi> tmp373;
    TNode<Smi> tmp374;
    TNode<IntPtrT> tmp375;
    TNode<HeapObject> tmp376;
    TNode<IntPtrT> tmp377;
    TNode<IntPtrT> tmp378;
    TNode<IntPtrT> tmp379;
    TNode<IntPtrT> tmp380;
    ca_.Bind(&block44, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380);
    TNode<IntPtrT> tmp381;
    USE(tmp381);
    tmp381 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp382;
    USE(tmp382);
    tmp382 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp380}, TNode<IntPtrT>{tmp381});
    TNode<IntPtrT> tmp383;
    USE(tmp383);
    tmp383 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp377}, TNode<IntPtrT>{tmp382});
    TNode<HeapObject> tmp384;
    USE(tmp384);
    TNode<IntPtrT> tmp385;
    USE(tmp385);
    std::tie(tmp384, tmp385) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp376}, TNode<IntPtrT>{tmp383}).Flatten();
    TNode<Object>tmp386 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp384, tmp385});
    ca_.Goto(&block38, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362, tmp363, tmp364, tmp365, tmp366, tmp367, tmp368, tmp386);
  }

  if (block45.is_used()) {
    TNode<NativeContext> tmp387;
    TNode<JSArgumentsObject> tmp388;
    TNode<Smi> tmp389;
    TNode<Smi> tmp390;
    TNode<FixedArray> tmp391;
    TNode<Smi> tmp392;
    TNode<Smi> tmp393;
    TNode<Smi> tmp394;
    TNode<FixedArray> tmp395;
    TNode<Smi> tmp396;
    TNode<Context> tmp397;
    TNode<Map> tmp398;
    TNode<JSArray> tmp399;
    TNode<Smi> tmp400;
    TNode<FixedArray> tmp401;
    TNode<Smi> tmp402;
    TNode<Smi> tmp403;
    TNode<Object> tmp404;
    TNode<FixedArray> tmp405;
    TNode<FixedArray> tmp406;
    TNode<IntPtrT> tmp407;
    TNode<IntPtrT> tmp408;
    TNode<Smi> tmp409;
    TNode<Smi> tmp410;
    TNode<IntPtrT> tmp411;
    TNode<HeapObject> tmp412;
    TNode<IntPtrT> tmp413;
    TNode<IntPtrT> tmp414;
    TNode<IntPtrT> tmp415;
    TNode<IntPtrT> tmp416;
    ca_.Bind(&block45, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block38.is_used()) {
    TNode<NativeContext> tmp417;
    TNode<JSArgumentsObject> tmp418;
    TNode<Smi> tmp419;
    TNode<Smi> tmp420;
    TNode<FixedArray> tmp421;
    TNode<Smi> tmp422;
    TNode<Smi> tmp423;
    TNode<Smi> tmp424;
    TNode<FixedArray> tmp425;
    TNode<Smi> tmp426;
    TNode<Context> tmp427;
    TNode<Map> tmp428;
    TNode<JSArray> tmp429;
    TNode<Smi> tmp430;
    TNode<FixedArray> tmp431;
    TNode<Smi> tmp432;
    TNode<Smi> tmp433;
    TNode<Object> tmp434;
    TNode<Object> tmp435;
    ca_.Bind(&block38, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421, &tmp422, &tmp423, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433, &tmp434, &tmp435);
    TNode<Object> tmp436;
    USE(tmp436);
    tmp436 = UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Context>{tmp417}, TNode<Object>{tmp435});
    TNode<Smi> tmp437;
    USE(tmp437);
    tmp437 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp438;
    USE(tmp438);
    tmp438 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp430}, TNode<Smi>{tmp437});
    CodeStubAssembler(state_).StoreFixedArrayElement(TNode<FixedArray>{tmp431}, TNode<Smi>{tmp430}, TNode<Object>{tmp436}, UNSAFE_SKIP_WRITE_BARRIER);
    TNode<Smi> tmp439;
    USE(tmp439);
    tmp439 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp440;
    USE(tmp440);
    tmp440 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp433}, TNode<Smi>{tmp439});
    ca_.Goto(&block27, tmp417, tmp418, tmp419, tmp420, tmp421, tmp422, tmp423, tmp424, tmp425, tmp426, tmp427, tmp428, tmp429, tmp438, tmp431, tmp432, tmp440);
  }

  if (block26.is_used()) {
    TNode<NativeContext> tmp441;
    TNode<JSArgumentsObject> tmp442;
    TNode<Smi> tmp443;
    TNode<Smi> tmp444;
    TNode<FixedArray> tmp445;
    TNode<Smi> tmp446;
    TNode<Smi> tmp447;
    TNode<Smi> tmp448;
    TNode<FixedArray> tmp449;
    TNode<Smi> tmp450;
    TNode<Context> tmp451;
    TNode<Map> tmp452;
    TNode<JSArray> tmp453;
    TNode<Smi> tmp454;
    TNode<FixedArray> tmp455;
    TNode<Smi> tmp456;
    TNode<Smi> tmp457;
    ca_.Bind(&block26, &tmp441, &tmp442, &tmp443, &tmp444, &tmp445, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452, &tmp453, &tmp454, &tmp455, &tmp456, &tmp457);
    TNode<Smi> tmp458;
    USE(tmp458);
    tmp458 = CodeStubAssembler(state_).SmiMax(TNode<Smi>{tmp447}, TNode<Smi>{tmp443});
    TNode<Smi> tmp459;
    USE(tmp459);
    tmp459 = CodeStubAssembler(state_).SmiMin(TNode<Smi>{tmp458}, TNode<Smi>{tmp448});
    TNode<Smi> tmp460;
    USE(tmp460);
    tmp460 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp448}, TNode<Smi>{tmp459});
    TNode<IntPtrT> tmp461;
    USE(tmp461);
    tmp461 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp454});
    TNode<IntPtrT> tmp462;
    USE(tmp462);
    tmp462 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp459});
    TNode<IntPtrT> tmp463;
    USE(tmp463);
    tmp463 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp460});
    CodeStubAssembler(state_).CopyElements(ElementsKind::PACKED_ELEMENTS, TNode<FixedArrayBase>{tmp455}, TNode<IntPtrT>{tmp461}, TNode<FixedArrayBase>{tmp449}, TNode<IntPtrT>{tmp462}, TNode<IntPtrT>{tmp463});
    ca_.Goto(&block47, tmp441, tmp442, tmp443, tmp444, tmp453);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    TNode<NativeContext> tmp464;
    TNode<JSArgumentsObject> tmp465;
    TNode<Smi> tmp466;
    TNode<Smi> tmp467;
    TNode<JSArray> tmp468;
    ca_.Bind(&block47, &tmp464, &tmp465, &tmp466, &tmp467, &tmp468);
  return TNode<JSArray>{tmp468};
}

TNode<JSArray> HandleFastSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p_o, TNode<Number> p_startNumber, TNode<Number> p_countNumber, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Number, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext, JSArray> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArray> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext, JSArgumentsObject> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, Object, NativeContext, JSArgumentsObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map, NativeContext, JSArgumentsObject, Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map, NativeContext, JSArgumentsObject, Smi, Smi, JSArray> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, Object, JSArgumentsObject, Map> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, JSArgumentsObject> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, JSArgumentsObject, NativeContext, JSArgumentsObject, Smi, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, Smi, Smi, JSArgumentsObject, NativeContext, JSArgumentsObject, Smi, Smi, JSArray> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Number, JSArray> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_startNumber, p_countNumber);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_Smi_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp2, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp2);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    TNode<Smi> tmp15;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Smi> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_Smi_0(state_, TNode<Object>{tmp13}, &label0);
    ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp15, tmp13, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp10, tmp11, tmp12, tmp13, tmp15, tmp13);
    }
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Number> tmp19;
    TNode<Number> tmp20;
    TNode<Smi> tmp21;
    TNode<Number> tmp22;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Number> tmp25;
    TNode<Number> tmp26;
    TNode<Smi> tmp27;
    TNode<Number> tmp28;
    TNode<Smi> tmp29;
    ca_.Bind(&block5, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<JSArray> tmp30;
    USE(tmp30);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp30 = Cast_FastJSArrayForCopy_1(state_, TNode<Context>{tmp23}, TNode<Object>{tmp24}, &label0);
    ca_.Goto(&block15, tmp23, tmp24, tmp25, tmp26, tmp27, tmp29, tmp24, tmp24, tmp23, tmp30);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp23, tmp24, tmp25, tmp26, tmp27, tmp29, tmp24, tmp24, tmp23);
    }
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Number> tmp33;
    TNode<Number> tmp34;
    TNode<Smi> tmp35;
    TNode<Smi> tmp36;
    ca_.Bind(&block10, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    CodeStubAssembler(state_).FailAssert("Torque assert 'start >= 0' failed", "src/builtins/array-slice.tq", 96);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp37;
    TNode<Object> tmp38;
    TNode<Number> tmp39;
    TNode<Number> tmp40;
    TNode<Smi> tmp41;
    TNode<Smi> tmp42;
    ca_.Bind(&block9, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp43;
    TNode<Object> tmp44;
    TNode<Number> tmp45;
    TNode<Number> tmp46;
    TNode<Smi> tmp47;
    TNode<Smi> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<NativeContext> tmp51;
    ca_.Bind(&block16, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<JSArgumentsObject> tmp52;
    USE(tmp52);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp52 = Cast_JSStrictArgumentsObject_1(state_, TNode<Context>{tmp43}, TNode<Object>{ca_.UncheckedCast<Object>(tmp49)}, &label0);
    ca_.Goto(&block21, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, ca_.UncheckedCast<Object>(tmp49), tmp43, tmp52);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block22, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, ca_.UncheckedCast<Object>(tmp49), tmp43);
    }
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp53;
    TNode<Object> tmp54;
    TNode<Number> tmp55;
    TNode<Number> tmp56;
    TNode<Smi> tmp57;
    TNode<Smi> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<NativeContext> tmp61;
    TNode<JSArray> tmp62;
    ca_.Bind(&block15, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<Smi> tmp63;
    USE(tmp63);
    tmp63 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp57}, TNode<Smi>{tmp58});
    TNode<Smi> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp62});
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).SmiAbove(TNode<Smi>{tmp63}, TNode<Smi>{tmp64});
    ca_.Branch(tmp65, &block17, &block18, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp62);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp66;
    TNode<Object> tmp67;
    TNode<Number> tmp68;
    TNode<Number> tmp69;
    TNode<Smi> tmp70;
    TNode<Smi> tmp71;
    TNode<Object> tmp72;
    TNode<JSArray> tmp73;
    ca_.Bind(&block17, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    ca_.Goto(&block1);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp74;
    TNode<Object> tmp75;
    TNode<Number> tmp76;
    TNode<Number> tmp77;
    TNode<Smi> tmp78;
    TNode<Smi> tmp79;
    TNode<Object> tmp80;
    TNode<JSArray> tmp81;
    ca_.Bind(&block18, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<JSArray> tmp82;
    tmp82 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kExtractFastJSArray, tmp74, tmp81, tmp78, tmp79));
    USE(tmp82);
    ca_.Goto(&block2, tmp74, tmp75, tmp76, tmp77, tmp82);
  }

  if (block22.is_used()) {
    TNode<NativeContext> tmp83;
    TNode<Object> tmp84;
    TNode<Number> tmp85;
    TNode<Number> tmp86;
    TNode<Smi> tmp87;
    TNode<Smi> tmp88;
    TNode<Object> tmp89;
    TNode<Object> tmp90;
    TNode<NativeContext> tmp91;
    ca_.Bind(&block22, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    TNode<JSArgumentsObject> tmp92;
    USE(tmp92);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp92 = Cast_JSSloppyArgumentsObject_1(state_, TNode<Context>{tmp83}, TNode<Object>{ca_.UncheckedCast<Object>(tmp89)}, &label0);
    ca_.Goto(&block25, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, ca_.UncheckedCast<Object>(tmp89), tmp83, tmp92);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block26, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, ca_.UncheckedCast<Object>(tmp89), tmp83);
    }
  }

  if (block21.is_used()) {
    TNode<NativeContext> tmp93;
    TNode<Object> tmp94;
    TNode<Number> tmp95;
    TNode<Number> tmp96;
    TNode<Smi> tmp97;
    TNode<Smi> tmp98;
    TNode<Object> tmp99;
    TNode<Object> tmp100;
    TNode<NativeContext> tmp101;
    TNode<JSArgumentsObject> tmp102;
    ca_.Bind(&block21, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    ca_.Goto(&block12, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp102);
  }

  if (block26.is_used()) {
    TNode<NativeContext> tmp103;
    TNode<Object> tmp104;
    TNode<Number> tmp105;
    TNode<Number> tmp106;
    TNode<Smi> tmp107;
    TNode<Smi> tmp108;
    TNode<Object> tmp109;
    TNode<Object> tmp110;
    TNode<NativeContext> tmp111;
    ca_.Bind(&block26, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111);
    ca_.Goto(&block1);
  }

  if (block25.is_used()) {
    TNode<NativeContext> tmp112;
    TNode<Object> tmp113;
    TNode<Number> tmp114;
    TNode<Number> tmp115;
    TNode<Smi> tmp116;
    TNode<Smi> tmp117;
    TNode<Object> tmp118;
    TNode<Object> tmp119;
    TNode<NativeContext> tmp120;
    TNode<JSArgumentsObject> tmp121;
    ca_.Bind(&block25, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    TNode<IntPtrT> tmp122;
    USE(tmp122);
    tmp122 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp123 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp121, tmp122});
    TNode<BoolT> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).IsFastAliasedArgumentsMap(TNode<Context>{tmp112}, TNode<Map>{tmp123});
    ca_.Branch(tmp124, &block27, &block28, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp121, tmp123);
  }

  if (block27.is_used()) {
    TNode<NativeContext> tmp125;
    TNode<Object> tmp126;
    TNode<Number> tmp127;
    TNode<Number> tmp128;
    TNode<Smi> tmp129;
    TNode<Smi> tmp130;
    TNode<Object> tmp131;
    TNode<JSArgumentsObject> tmp132;
    TNode<Map> tmp133;
    ca_.Bind(&block27, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<JSArray> tmp134;
    USE(tmp134);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp134 = HandleFastAliasedSloppyArgumentsSlice_0(state_, TNode<NativeContext>{tmp125}, TNode<JSArgumentsObject>{tmp132}, TNode<Smi>{tmp129}, TNode<Smi>{tmp130}, &label0);
    ca_.Goto(&block30, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp125, tmp132, tmp129, tmp130, tmp134);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block31, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp125, tmp132, tmp129, tmp130);
    }
  }

  if (block31.is_used()) {
    TNode<NativeContext> tmp135;
    TNode<Object> tmp136;
    TNode<Number> tmp137;
    TNode<Number> tmp138;
    TNode<Smi> tmp139;
    TNode<Smi> tmp140;
    TNode<Object> tmp141;
    TNode<JSArgumentsObject> tmp142;
    TNode<Map> tmp143;
    TNode<NativeContext> tmp144;
    TNode<JSArgumentsObject> tmp145;
    TNode<Smi> tmp146;
    TNode<Smi> tmp147;
    ca_.Bind(&block31, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147);
    ca_.Goto(&block1);
  }

  if (block30.is_used()) {
    TNode<NativeContext> tmp148;
    TNode<Object> tmp149;
    TNode<Number> tmp150;
    TNode<Number> tmp151;
    TNode<Smi> tmp152;
    TNode<Smi> tmp153;
    TNode<Object> tmp154;
    TNode<JSArgumentsObject> tmp155;
    TNode<Map> tmp156;
    TNode<NativeContext> tmp157;
    TNode<JSArgumentsObject> tmp158;
    TNode<Smi> tmp159;
    TNode<Smi> tmp160;
    TNode<JSArray> tmp161;
    ca_.Bind(&block30, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    ca_.Goto(&block2, tmp148, tmp149, tmp150, tmp151, tmp161);
  }

  if (block28.is_used()) {
    TNode<NativeContext> tmp162;
    TNode<Object> tmp163;
    TNode<Number> tmp164;
    TNode<Number> tmp165;
    TNode<Smi> tmp166;
    TNode<Smi> tmp167;
    TNode<Object> tmp168;
    TNode<JSArgumentsObject> tmp169;
    TNode<Map> tmp170;
    ca_.Bind(&block28, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170);
    TNode<BoolT> tmp171;
    USE(tmp171);
    tmp171 = CodeStubAssembler(state_).IsSloppyArgumentsMap(TNode<Context>{tmp162}, TNode<Map>{tmp170});
    ca_.Branch(tmp171, &block32, &block33, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170);
  }

  if (block32.is_used()) {
    TNode<NativeContext> tmp172;
    TNode<Object> tmp173;
    TNode<Number> tmp174;
    TNode<Number> tmp175;
    TNode<Smi> tmp176;
    TNode<Smi> tmp177;
    TNode<Object> tmp178;
    TNode<JSArgumentsObject> tmp179;
    TNode<Map> tmp180;
    ca_.Bind(&block32, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180);
    ca_.Goto(&block12, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp179);
  }

  if (block33.is_used()) {
    TNode<NativeContext> tmp181;
    TNode<Object> tmp182;
    TNode<Number> tmp183;
    TNode<Number> tmp184;
    TNode<Smi> tmp185;
    TNode<Smi> tmp186;
    TNode<Object> tmp187;
    TNode<JSArgumentsObject> tmp188;
    TNode<Map> tmp189;
    ca_.Bind(&block33, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp190;
    TNode<Object> tmp191;
    TNode<Number> tmp192;
    TNode<Number> tmp193;
    TNode<Smi> tmp194;
    TNode<Smi> tmp195;
    TNode<JSArgumentsObject> tmp196;
    ca_.Bind(&block12, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196);
    TNode<JSArray> tmp197;
    USE(tmp197);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp197 = HandleSimpleArgumentsSlice_0(state_, TNode<NativeContext>{tmp190}, TNode<JSArgumentsObject>{tmp196}, TNode<Smi>{tmp194}, TNode<Smi>{tmp195}, &label0);
    ca_.Goto(&block34, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp190, tmp196, tmp194, tmp195, tmp197);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block35, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp190, tmp196, tmp194, tmp195);
    }
  }

  if (block35.is_used()) {
    TNode<NativeContext> tmp198;
    TNode<Object> tmp199;
    TNode<Number> tmp200;
    TNode<Number> tmp201;
    TNode<Smi> tmp202;
    TNode<Smi> tmp203;
    TNode<JSArgumentsObject> tmp204;
    TNode<NativeContext> tmp205;
    TNode<JSArgumentsObject> tmp206;
    TNode<Smi> tmp207;
    TNode<Smi> tmp208;
    ca_.Bind(&block35, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208);
    ca_.Goto(&block1);
  }

  if (block34.is_used()) {
    TNode<NativeContext> tmp209;
    TNode<Object> tmp210;
    TNode<Number> tmp211;
    TNode<Number> tmp212;
    TNode<Smi> tmp213;
    TNode<Smi> tmp214;
    TNode<JSArgumentsObject> tmp215;
    TNode<NativeContext> tmp216;
    TNode<JSArgumentsObject> tmp217;
    TNode<Smi> tmp218;
    TNode<Smi> tmp219;
    TNode<JSArray> tmp220;
    ca_.Bind(&block34, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220);
    ca_.Goto(&block2, tmp209, tmp210, tmp211, tmp212, tmp220);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp221;
    TNode<Object> tmp222;
    TNode<Number> tmp223;
    TNode<Number> tmp224;
    TNode<JSArray> tmp225;
    ca_.Bind(&block2, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225);
    ca_.Goto(&block36, tmp221, tmp222, tmp223, tmp224, tmp225);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    TNode<NativeContext> tmp226;
    TNode<Object> tmp227;
    TNode<Number> tmp228;
    TNode<Number> tmp229;
    TNode<JSArray> tmp230;
    ca_.Bind(&block36, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
  return TNode<JSArray>{tmp230};
}

TF_BUILTIN(ArrayPrototypeSlice, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, NativeContext, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, NativeContext, JSReceiver, Number, Number> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, NativeContext, JSReceiver, Number, Number, JSArray> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, JSReceiver, Number> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, JSReceiver, Number> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, JSReceiver, Number, Number, Oddball> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, JSReceiver, Number, Number, Oddball> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, Number, Number, Object, Number, Number, Number, JSReceiver, Number> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<JSArray> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = Cast_FastJSArrayForCopy_1(state_, TNode<Context>{tmp10}, TNode<Object>{tmp11}, &label0);
    ca_.Goto(&block5, tmp7, tmp8, tmp9, tmp10, tmp11, tmp11, tmp11, tmp10, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp11, tmp11, tmp10);
    }
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<NativeContext> tmp20;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block2, tmp13, tmp14, tmp15, tmp16, tmp17);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<NativeContext> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<NativeContext> tmp28;
    TNode<JSArray> tmp29;
    ca_.Bind(&block5, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<JSArray> tmp30;
    tmp30 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCloneFastJSArray, tmp24, tmp29));
    USE(tmp30);
    arguments.PopAndReturn(tmp30);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<JSReceiver> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp34}, TNode<Object>{tmp35});
    TNode<Number> tmp37;
    USE(tmp37);
    tmp37 = GetLengthProperty_0(state_, TNode<Context>{tmp34}, TNode<Object>{tmp36});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp31}, TNode<RawPtrT>{tmp32}, TNode<IntPtrT>{tmp33}}, TNode<IntPtrT>{tmp38});
    TNode<Number> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp34}, TNode<Object>{tmp39});
    TNode<Number> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = NumberIsLessThan_0(state_, TNode<Number>{tmp40}, TNode<Number>{tmp41});
    ca_.Branch(tmp42, &block7, &block8, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp39, tmp40);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<Number> tmp49;
    TNode<Object> tmp50;
    TNode<Number> tmp51;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<Number> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp49}, TNode<Number>{tmp51});
    TNode<Number> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<Number> tmp54;
    USE(tmp54);
    tmp54 = Max_0(state_, TNode<Number>{tmp52}, TNode<Number>{tmp53});
    ca_.Goto(&block9, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp54);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp55;
    TNode<RawPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<NativeContext> tmp58;
    TNode<Object> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Number> tmp61;
    TNode<Object> tmp62;
    TNode<Number> tmp63;
    ca_.Bind(&block8, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    TNode<Number> tmp64;
    USE(tmp64);
    tmp64 = Min_0(state_, TNode<Number>{tmp63}, TNode<Number>{tmp61});
    ca_.Goto(&block9, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp65;
    TNode<RawPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<NativeContext> tmp68;
    TNode<Object> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<Number> tmp71;
    TNode<Object> tmp72;
    TNode<Number> tmp73;
    TNode<Number> tmp74;
    ca_.Bind(&block9, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<IntPtrT> tmp75;
    USE(tmp75);
    tmp75 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp65}, TNode<RawPtrT>{tmp66}, TNode<IntPtrT>{tmp67}}, TNode<IntPtrT>{tmp75});
    TNode<Oddball> tmp77;
    USE(tmp77);
    tmp77 = Undefined_0(state_);
    TNode<BoolT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp76}, TNode<HeapObject>{tmp77});
    ca_.Branch(tmp78, &block11, &block12, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp76);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp79;
    TNode<RawPtrT> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<NativeContext> tmp82;
    TNode<Object> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Number> tmp85;
    TNode<Object> tmp86;
    TNode<Number> tmp87;
    TNode<Number> tmp88;
    TNode<Object> tmp89;
    ca_.Bind(&block11, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    ca_.Goto(&block13, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp85);
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp90;
    TNode<RawPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<NativeContext> tmp93;
    TNode<Object> tmp94;
    TNode<JSReceiver> tmp95;
    TNode<Number> tmp96;
    TNode<Object> tmp97;
    TNode<Number> tmp98;
    TNode<Number> tmp99;
    TNode<Object> tmp100;
    ca_.Bind(&block12, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<Number> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp93}, TNode<Object>{tmp100});
    ca_.Goto(&block13, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp102;
    TNode<RawPtrT> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<NativeContext> tmp105;
    TNode<Object> tmp106;
    TNode<JSReceiver> tmp107;
    TNode<Number> tmp108;
    TNode<Object> tmp109;
    TNode<Number> tmp110;
    TNode<Number> tmp111;
    TNode<Object> tmp112;
    TNode<Number> tmp113;
    ca_.Bind(&block13, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    TNode<Number> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp115;
    USE(tmp115);
    tmp115 = NumberIsLessThan_0(state_, TNode<Number>{tmp113}, TNode<Number>{tmp114});
    ca_.Branch(tmp115, &block15, &block16, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113);
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp116;
    TNode<RawPtrT> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<NativeContext> tmp119;
    TNode<Object> tmp120;
    TNode<JSReceiver> tmp121;
    TNode<Number> tmp122;
    TNode<Object> tmp123;
    TNode<Number> tmp124;
    TNode<Number> tmp125;
    TNode<Object> tmp126;
    TNode<Number> tmp127;
    ca_.Bind(&block15, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    TNode<Number> tmp128;
    USE(tmp128);
    tmp128 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp122}, TNode<Number>{tmp127});
    TNode<Number> tmp129;
    USE(tmp129);
    tmp129 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<Number> tmp130;
    USE(tmp130);
    tmp130 = Max_0(state_, TNode<Number>{tmp128}, TNode<Number>{tmp129});
    ca_.Goto(&block17, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp130);
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp131;
    TNode<RawPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<NativeContext> tmp134;
    TNode<Object> tmp135;
    TNode<JSReceiver> tmp136;
    TNode<Number> tmp137;
    TNode<Object> tmp138;
    TNode<Number> tmp139;
    TNode<Number> tmp140;
    TNode<Object> tmp141;
    TNode<Number> tmp142;
    ca_.Bind(&block16, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142);
    TNode<Number> tmp143;
    USE(tmp143);
    tmp143 = Min_0(state_, TNode<Number>{tmp142}, TNode<Number>{tmp137});
    ca_.Goto(&block17, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp144;
    TNode<RawPtrT> tmp145;
    TNode<IntPtrT> tmp146;
    TNode<NativeContext> tmp147;
    TNode<Object> tmp148;
    TNode<JSReceiver> tmp149;
    TNode<Number> tmp150;
    TNode<Object> tmp151;
    TNode<Number> tmp152;
    TNode<Number> tmp153;
    TNode<Object> tmp154;
    TNode<Number> tmp155;
    TNode<Number> tmp156;
    ca_.Bind(&block17, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    TNode<Number> tmp157;
    USE(tmp157);
    tmp157 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp156}, TNode<Number>{tmp153});
    TNode<Number> tmp158;
    USE(tmp158);
    tmp158 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<Number> tmp159;
    USE(tmp159);
    tmp159 = Max_0(state_, TNode<Number>{tmp157}, TNode<Number>{tmp158});
    TNode<JSArray> tmp160;
    USE(tmp160);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp160 = HandleFastSlice_0(state_, TNode<NativeContext>{tmp147}, TNode<Object>{tmp149}, TNode<Number>{tmp153}, TNode<Number>{tmp159}, &label0);
    ca_.Goto(&block45, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp159, tmp147, tmp149, tmp153, tmp159, tmp160);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block46, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp159, tmp147, tmp149, tmp153, tmp159);
    }
  }

  if (block22.is_used()) {
    TNode<RawPtrT> tmp161;
    TNode<RawPtrT> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<NativeContext> tmp164;
    TNode<Object> tmp165;
    TNode<JSReceiver> tmp166;
    TNode<Number> tmp167;
    TNode<Object> tmp168;
    TNode<Number> tmp169;
    TNode<Number> tmp170;
    TNode<Object> tmp171;
    TNode<Number> tmp172;
    TNode<Number> tmp173;
    TNode<Number> tmp174;
    ca_.Bind(&block22, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    CodeStubAssembler(state_).FailAssert("Torque assert '0 <= k' failed", "src/builtins/array-slice.tq", 178);
  }

  if (block21.is_used()) {
    TNode<RawPtrT> tmp175;
    TNode<RawPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<NativeContext> tmp178;
    TNode<Object> tmp179;
    TNode<JSReceiver> tmp180;
    TNode<Number> tmp181;
    TNode<Object> tmp182;
    TNode<Number> tmp183;
    TNode<Number> tmp184;
    TNode<Object> tmp185;
    TNode<Number> tmp186;
    TNode<Number> tmp187;
    TNode<Number> tmp188;
    ca_.Bind(&block21, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
  }

  if (block26.is_used()) {
    TNode<RawPtrT> tmp189;
    TNode<RawPtrT> tmp190;
    TNode<IntPtrT> tmp191;
    TNode<NativeContext> tmp192;
    TNode<Object> tmp193;
    TNode<JSReceiver> tmp194;
    TNode<Number> tmp195;
    TNode<Object> tmp196;
    TNode<Number> tmp197;
    TNode<Number> tmp198;
    TNode<Object> tmp199;
    TNode<Number> tmp200;
    TNode<Number> tmp201;
    TNode<Number> tmp202;
    ca_.Bind(&block26, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202);
    CodeStubAssembler(state_).FailAssert("Torque assert 'k <= len' failed", "src/builtins/array-slice.tq", 179);
  }

  if (block25.is_used()) {
    TNode<RawPtrT> tmp203;
    TNode<RawPtrT> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<NativeContext> tmp206;
    TNode<Object> tmp207;
    TNode<JSReceiver> tmp208;
    TNode<Number> tmp209;
    TNode<Object> tmp210;
    TNode<Number> tmp211;
    TNode<Number> tmp212;
    TNode<Object> tmp213;
    TNode<Number> tmp214;
    TNode<Number> tmp215;
    TNode<Number> tmp216;
    ca_.Bind(&block25, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
  }

  if (block30.is_used()) {
    TNode<RawPtrT> tmp217;
    TNode<RawPtrT> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<NativeContext> tmp220;
    TNode<Object> tmp221;
    TNode<JSReceiver> tmp222;
    TNode<Number> tmp223;
    TNode<Object> tmp224;
    TNode<Number> tmp225;
    TNode<Number> tmp226;
    TNode<Object> tmp227;
    TNode<Number> tmp228;
    TNode<Number> tmp229;
    TNode<Number> tmp230;
    ca_.Bind(&block30, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    CodeStubAssembler(state_).FailAssert("Torque assert '0 <= final' failed", "src/builtins/array-slice.tq", 180);
  }

  if (block29.is_used()) {
    TNode<RawPtrT> tmp231;
    TNode<RawPtrT> tmp232;
    TNode<IntPtrT> tmp233;
    TNode<NativeContext> tmp234;
    TNode<Object> tmp235;
    TNode<JSReceiver> tmp236;
    TNode<Number> tmp237;
    TNode<Object> tmp238;
    TNode<Number> tmp239;
    TNode<Number> tmp240;
    TNode<Object> tmp241;
    TNode<Number> tmp242;
    TNode<Number> tmp243;
    TNode<Number> tmp244;
    ca_.Bind(&block29, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244);
  }

  if (block34.is_used()) {
    TNode<RawPtrT> tmp245;
    TNode<RawPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<NativeContext> tmp248;
    TNode<Object> tmp249;
    TNode<JSReceiver> tmp250;
    TNode<Number> tmp251;
    TNode<Object> tmp252;
    TNode<Number> tmp253;
    TNode<Number> tmp254;
    TNode<Object> tmp255;
    TNode<Number> tmp256;
    TNode<Number> tmp257;
    TNode<Number> tmp258;
    ca_.Bind(&block34, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258);
    CodeStubAssembler(state_).FailAssert("Torque assert 'final <= len' failed", "src/builtins/array-slice.tq", 181);
  }

  if (block33.is_used()) {
    TNode<RawPtrT> tmp259;
    TNode<RawPtrT> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<NativeContext> tmp262;
    TNode<Object> tmp263;
    TNode<JSReceiver> tmp264;
    TNode<Number> tmp265;
    TNode<Object> tmp266;
    TNode<Number> tmp267;
    TNode<Number> tmp268;
    TNode<Object> tmp269;
    TNode<Number> tmp270;
    TNode<Number> tmp271;
    TNode<Number> tmp272;
    ca_.Bind(&block33, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272);
  }

  if (block38.is_used()) {
    TNode<RawPtrT> tmp273;
    TNode<RawPtrT> tmp274;
    TNode<IntPtrT> tmp275;
    TNode<NativeContext> tmp276;
    TNode<Object> tmp277;
    TNode<JSReceiver> tmp278;
    TNode<Number> tmp279;
    TNode<Object> tmp280;
    TNode<Number> tmp281;
    TNode<Number> tmp282;
    TNode<Object> tmp283;
    TNode<Number> tmp284;
    TNode<Number> tmp285;
    TNode<Number> tmp286;
    ca_.Bind(&block38, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286);
    CodeStubAssembler(state_).FailAssert("Torque assert '0 <= count' failed", "src/builtins/array-slice.tq", 182);
  }

  if (block37.is_used()) {
    TNode<RawPtrT> tmp287;
    TNode<RawPtrT> tmp288;
    TNode<IntPtrT> tmp289;
    TNode<NativeContext> tmp290;
    TNode<Object> tmp291;
    TNode<JSReceiver> tmp292;
    TNode<Number> tmp293;
    TNode<Object> tmp294;
    TNode<Number> tmp295;
    TNode<Number> tmp296;
    TNode<Object> tmp297;
    TNode<Number> tmp298;
    TNode<Number> tmp299;
    TNode<Number> tmp300;
    ca_.Bind(&block37, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300);
  }

  if (block42.is_used()) {
    TNode<RawPtrT> tmp301;
    TNode<RawPtrT> tmp302;
    TNode<IntPtrT> tmp303;
    TNode<NativeContext> tmp304;
    TNode<Object> tmp305;
    TNode<JSReceiver> tmp306;
    TNode<Number> tmp307;
    TNode<Object> tmp308;
    TNode<Number> tmp309;
    TNode<Number> tmp310;
    TNode<Object> tmp311;
    TNode<Number> tmp312;
    TNode<Number> tmp313;
    TNode<Number> tmp314;
    ca_.Bind(&block42, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314);
    CodeStubAssembler(state_).FailAssert("Torque assert 'count <= len' failed", "src/builtins/array-slice.tq", 183);
  }

  if (block41.is_used()) {
    TNode<RawPtrT> tmp315;
    TNode<RawPtrT> tmp316;
    TNode<IntPtrT> tmp317;
    TNode<NativeContext> tmp318;
    TNode<Object> tmp319;
    TNode<JSReceiver> tmp320;
    TNode<Number> tmp321;
    TNode<Object> tmp322;
    TNode<Number> tmp323;
    TNode<Number> tmp324;
    TNode<Object> tmp325;
    TNode<Number> tmp326;
    TNode<Number> tmp327;
    TNode<Number> tmp328;
    ca_.Bind(&block41, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328);
  }

  if (block46.is_used()) {
    TNode<RawPtrT> tmp329;
    TNode<RawPtrT> tmp330;
    TNode<IntPtrT> tmp331;
    TNode<NativeContext> tmp332;
    TNode<Object> tmp333;
    TNode<JSReceiver> tmp334;
    TNode<Number> tmp335;
    TNode<Object> tmp336;
    TNode<Number> tmp337;
    TNode<Number> tmp338;
    TNode<Object> tmp339;
    TNode<Number> tmp340;
    TNode<Number> tmp341;
    TNode<Number> tmp342;
    TNode<NativeContext> tmp343;
    TNode<JSReceiver> tmp344;
    TNode<Number> tmp345;
    TNode<Number> tmp346;
    ca_.Bind(&block46, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346);
    TNode<JSReceiver> tmp347;
    USE(tmp347);
    tmp347 = CodeStubAssembler(state_).ArraySpeciesCreate(TNode<Context>{tmp332}, TNode<Object>{tmp334}, TNode<Number>{tmp342});
    TNode<Number> tmp348;
    USE(tmp348);
    tmp348 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    ca_.Goto(&block49, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp347, tmp348);
  }

  if (block45.is_used()) {
    TNode<RawPtrT> tmp349;
    TNode<RawPtrT> tmp350;
    TNode<IntPtrT> tmp351;
    TNode<NativeContext> tmp352;
    TNode<Object> tmp353;
    TNode<JSReceiver> tmp354;
    TNode<Number> tmp355;
    TNode<Object> tmp356;
    TNode<Number> tmp357;
    TNode<Number> tmp358;
    TNode<Object> tmp359;
    TNode<Number> tmp360;
    TNode<Number> tmp361;
    TNode<Number> tmp362;
    TNode<NativeContext> tmp363;
    TNode<JSReceiver> tmp364;
    TNode<Number> tmp365;
    TNode<Number> tmp366;
    TNode<JSArray> tmp367;
    ca_.Bind(&block45, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367);
    arguments.PopAndReturn(tmp367);
  }

  if (block49.is_used()) {
    TNode<RawPtrT> tmp368;
    TNode<RawPtrT> tmp369;
    TNode<IntPtrT> tmp370;
    TNode<NativeContext> tmp371;
    TNode<Object> tmp372;
    TNode<JSReceiver> tmp373;
    TNode<Number> tmp374;
    TNode<Object> tmp375;
    TNode<Number> tmp376;
    TNode<Number> tmp377;
    TNode<Object> tmp378;
    TNode<Number> tmp379;
    TNode<Number> tmp380;
    TNode<Number> tmp381;
    TNode<JSReceiver> tmp382;
    TNode<Number> tmp383;
    ca_.Bind(&block49, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383);
    TNode<BoolT> tmp384;
    USE(tmp384);
    tmp384 = NumberIsLessThan_0(state_, TNode<Number>{tmp377}, TNode<Number>{tmp380});
    ca_.Branch(tmp384, &block47, &block48, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp377, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383);
  }

  if (block47.is_used()) {
    TNode<RawPtrT> tmp385;
    TNode<RawPtrT> tmp386;
    TNode<IntPtrT> tmp387;
    TNode<NativeContext> tmp388;
    TNode<Object> tmp389;
    TNode<JSReceiver> tmp390;
    TNode<Number> tmp391;
    TNode<Object> tmp392;
    TNode<Number> tmp393;
    TNode<Number> tmp394;
    TNode<Object> tmp395;
    TNode<Number> tmp396;
    TNode<Number> tmp397;
    TNode<Number> tmp398;
    TNode<JSReceiver> tmp399;
    TNode<Number> tmp400;
    ca_.Bind(&block47, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400);
    TNode<Oddball> tmp401;
    tmp401 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kHasProperty, tmp388, tmp390, tmp394));
    USE(tmp401);
    TNode<Oddball> tmp402;
    USE(tmp402);
    tmp402 = True_0(state_);
    TNode<BoolT> tmp403;
    USE(tmp403);
    tmp403 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp401}, TNode<HeapObject>{tmp402});
    ca_.Branch(tmp403, &block50, &block51, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp392, tmp393, tmp394, tmp395, tmp396, tmp397, tmp398, tmp399, tmp400, tmp394, tmp401);
  }

  if (block50.is_used()) {
    TNode<RawPtrT> tmp404;
    TNode<RawPtrT> tmp405;
    TNode<IntPtrT> tmp406;
    TNode<NativeContext> tmp407;
    TNode<Object> tmp408;
    TNode<JSReceiver> tmp409;
    TNode<Number> tmp410;
    TNode<Object> tmp411;
    TNode<Number> tmp412;
    TNode<Number> tmp413;
    TNode<Object> tmp414;
    TNode<Number> tmp415;
    TNode<Number> tmp416;
    TNode<Number> tmp417;
    TNode<JSReceiver> tmp418;
    TNode<Number> tmp419;
    TNode<Number> tmp420;
    TNode<Oddball> tmp421;
    ca_.Bind(&block50, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421);
    TNode<Object> tmp422;
    USE(tmp422);
    tmp422 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp407}, TNode<Object>{tmp409}, TNode<Object>{tmp420});
    TNode<Object> tmp423;
    tmp423 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp407, tmp418, tmp419, tmp422);
    USE(tmp423);
    ca_.Goto(&block51, tmp404, tmp405, tmp406, tmp407, tmp408, tmp409, tmp410, tmp411, tmp412, tmp413, tmp414, tmp415, tmp416, tmp417, tmp418, tmp419, tmp420, tmp421);
  }

  if (block51.is_used()) {
    TNode<RawPtrT> tmp424;
    TNode<RawPtrT> tmp425;
    TNode<IntPtrT> tmp426;
    TNode<NativeContext> tmp427;
    TNode<Object> tmp428;
    TNode<JSReceiver> tmp429;
    TNode<Number> tmp430;
    TNode<Object> tmp431;
    TNode<Number> tmp432;
    TNode<Number> tmp433;
    TNode<Object> tmp434;
    TNode<Number> tmp435;
    TNode<Number> tmp436;
    TNode<Number> tmp437;
    TNode<JSReceiver> tmp438;
    TNode<Number> tmp439;
    TNode<Number> tmp440;
    TNode<Oddball> tmp441;
    ca_.Bind(&block51, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433, &tmp434, &tmp435, &tmp436, &tmp437, &tmp438, &tmp439, &tmp440, &tmp441);
    TNode<Number> tmp442;
    USE(tmp442);
    tmp442 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp443;
    USE(tmp443);
    tmp443 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp433}, TNode<Number>{tmp442});
    TNode<Number> tmp444;
    USE(tmp444);
    tmp444 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp445;
    USE(tmp445);
    tmp445 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp439}, TNode<Number>{tmp444});
    ca_.Goto(&block49, tmp424, tmp425, tmp426, tmp427, tmp428, tmp429, tmp430, tmp431, tmp432, tmp443, tmp434, tmp435, tmp436, tmp437, tmp438, tmp445);
  }

  if (block48.is_used()) {
    TNode<RawPtrT> tmp446;
    TNode<RawPtrT> tmp447;
    TNode<IntPtrT> tmp448;
    TNode<NativeContext> tmp449;
    TNode<Object> tmp450;
    TNode<JSReceiver> tmp451;
    TNode<Number> tmp452;
    TNode<Object> tmp453;
    TNode<Number> tmp454;
    TNode<Number> tmp455;
    TNode<Object> tmp456;
    TNode<Number> tmp457;
    TNode<Number> tmp458;
    TNode<Number> tmp459;
    TNode<JSReceiver> tmp460;
    TNode<Number> tmp461;
    ca_.Bind(&block48, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452, &tmp453, &tmp454, &tmp455, &tmp456, &tmp457, &tmp458, &tmp459, &tmp460, &tmp461);
    TNode<String> tmp462;
    USE(tmp462);
    tmp462 = kLengthString_0(state_);
    CodeStubAssembler(state_).CallBuiltin(Builtins::kSetProperty, tmp449, tmp460, tmp462, tmp461);
    arguments.PopAndReturn(tmp460);
  }
}

TNode<FixedArray> Cast_FixedArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<FixedArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<FixedArray> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<FixedArray> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<FixedArray>{tmp20};
}

TNode<Context> UnsafeCast_Context_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Context> tmp2;
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
    TNode<Context> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Context>{tmp9};
}

TNode<Object> UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = (TNode<Object>{tmp1});
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
    TNode<Object> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Object>{tmp9};
}

TNode<JSArray> Cast_FastJSArrayForCopy_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<JSArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FastJSArrayForCopy_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArray> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArray>{tmp22};
}

TNode<JSArgumentsObject> Cast_JSStrictArgumentsObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArgumentsObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArgumentsObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<JSArgumentsObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSStrictArgumentsObject_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArgumentsObject> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArgumentsObject> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArgumentsObject>{tmp22};
}

TNode<JSArgumentsObject> Cast_JSSloppyArgumentsObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArgumentsObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArgumentsObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<JSArgumentsObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSSloppyArgumentsObject_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArgumentsObject> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArgumentsObject> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArgumentsObject>{tmp22};
}

}  // namespace internal
}  // namespace v8

