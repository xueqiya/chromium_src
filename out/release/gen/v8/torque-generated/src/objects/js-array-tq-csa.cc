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

TNode<JSArray> NewJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<FixedArrayBase> p_elements) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, FixedArrayBase> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, FixedArrayBase, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_elements);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<FixedArrayBase> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject> tmp7;
    USE(tmp7);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp1});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp1);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp3);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp2);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp7, tmp11}, tmp5);
    TNode<JSArray> tmp12;
    USE(tmp12);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp12);
  }

    TNode<Context> tmp13;
    TNode<Map> tmp14;
    TNode<FixedArrayBase> tmp15;
    TNode<JSArray> tmp16;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15, &tmp16);
  return TNode<JSArray>{tmp16};
}

TNode<JSArray> NewJSArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Map> tmp1;
    USE(tmp1);
    tmp1 = GetFastPackedSmiElementsJSArrayMap_0(state_, TNode<Context>{tmp0});
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject> tmp5;
    USE(tmp5);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp2);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp5, tmp8}, tmp3);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp5, tmp9}, tmp10);
    TNode<JSArray> tmp11;
    USE(tmp11);
    tmp11 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2, tmp0, tmp11);
  }

    TNode<Context> tmp12;
    TNode<JSArray> tmp13;
    ca_.Bind(&block2, &tmp12, &tmp13);
  return TNode<JSArray>{tmp13};
}

TNode<Object> LoadElementNoHole_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, Object, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, Object, Object, Object, Oddball> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp4 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<FixedArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<JSArray> tmp7;
    TNode<Smi> tmp8;
    TNode<FixedArrayBase> tmp9;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<FixedArray> tmp14;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp18 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp18});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp12});
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp20});
    TNode<UintPtrT> tmp22;
    USE(tmp22);
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp22});
    ca_.Branch(tmp23, &block11, &block12, tmp10, tmp11, tmp12, tmp14, tmp14, tmp14, tmp15, tmp19, tmp12, tmp12, tmp20, tmp14, tmp15, tmp19, tmp20, tmp20);
  }

  if (block11.is_used()) {
    TNode<Context> tmp24;
    TNode<JSArray> tmp25;
    TNode<Smi> tmp26;
    TNode<FixedArray> tmp27;
    TNode<FixedArray> tmp28;
    TNode<FixedArray> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Smi> tmp32;
    TNode<Smi> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<HeapObject> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    ca_.Bind(&block11, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40});
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp41});
    TNode<HeapObject> tmp43;
    USE(tmp43);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    std::tie(tmp43, tmp44) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp35}, TNode<IntPtrT>{tmp42}).Flatten();
    TNode<Object>tmp45 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp43, tmp44});
    TNode<Object> tmp46;
    USE(tmp46);
    tmp46 = UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Context>{tmp24}, TNode<Object>{tmp45});
    TNode<Oddball> tmp47;
    USE(tmp47);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp47 = Cast_TheHole_0(state_, TNode<Object>{tmp46}, &label0);
    ca_.Goto(&block16, tmp24, tmp25, tmp26, tmp27, tmp46, tmp46, tmp46, tmp47);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp24, tmp25, tmp26, tmp27, tmp46, tmp46, tmp46);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp48;
    TNode<JSArray> tmp49;
    TNode<Smi> tmp50;
    TNode<FixedArray> tmp51;
    TNode<FixedArray> tmp52;
    TNode<FixedArray> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Smi> tmp56;
    TNode<Smi> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<HeapObject> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    ca_.Bind(&block12, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<Context> tmp64;
    TNode<JSArray> tmp65;
    TNode<Smi> tmp66;
    TNode<FixedArray> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    ca_.Bind(&block17, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    ca_.Goto(&block18, tmp64, tmp65, tmp66, ca_.UncheckedCast<Object>(tmp69));
  }

  if (block16.is_used()) {
    TNode<Context> tmp71;
    TNode<JSArray> tmp72;
    TNode<Smi> tmp73;
    TNode<FixedArray> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<Oddball> tmp78;
    ca_.Bind(&block16, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    ca_.Goto(label_IfHole);
  }

    TNode<Context> tmp79;
    TNode<JSArray> tmp80;
    TNode<Smi> tmp81;
    TNode<Object> tmp82;
    ca_.Bind(&block18, &tmp79, &tmp80, &tmp81, &tmp82);
  return TNode<Object>{tmp82};
}

TNode<Object> LoadElementNoHole_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase, FixedDoubleArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, BoolT, Float64T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, HeapObject, IntPtrT, BoolT, Float64T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp4 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<FixedDoubleArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<JSArray> tmp7;
    TNode<Smi> tmp8;
    TNode<FixedArrayBase> tmp9;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<FixedDoubleArray> tmp14;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp18 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp18});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp12});
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp20});
    TNode<UintPtrT> tmp22;
    USE(tmp22);
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp22});
    ca_.Branch(tmp23, &block11, &block12, tmp10, tmp11, tmp12, tmp14, tmp14, tmp14, tmp15, tmp19, tmp12, tmp12, tmp20, tmp14, tmp15, tmp19, tmp20, tmp20);
  }

  if (block11.is_used()) {
    TNode<Context> tmp24;
    TNode<JSArray> tmp25;
    TNode<Smi> tmp26;
    TNode<FixedDoubleArray> tmp27;
    TNode<FixedDoubleArray> tmp28;
    TNode<FixedDoubleArray> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Smi> tmp32;
    TNode<Smi> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<HeapObject> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    ca_.Bind(&block11, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40});
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp41});
    TNode<HeapObject> tmp43;
    USE(tmp43);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    std::tie(tmp43, tmp44) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp35}, TNode<IntPtrT>{tmp42}).Flatten();
    TNode<BoolT> tmp45;
    USE(tmp45);
    TNode<Float64T> tmp46;
    USE(tmp46);
    std::tie(tmp45, tmp46) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp43}, TNode<IntPtrT>{tmp44}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Branch(tmp45, &block15, &block16, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp43, tmp44, tmp45, tmp46);
  }

  if (block12.is_used()) {
    TNode<Context> tmp47;
    TNode<JSArray> tmp48;
    TNode<Smi> tmp49;
    TNode<FixedDoubleArray> tmp50;
    TNode<FixedDoubleArray> tmp51;
    TNode<FixedDoubleArray> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<Smi> tmp55;
    TNode<Smi> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<HeapObject> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    ca_.Bind(&block12, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp63;
    TNode<JSArray> tmp64;
    TNode<Smi> tmp65;
    TNode<FixedDoubleArray> tmp66;
    TNode<FixedDoubleArray> tmp67;
    TNode<FixedDoubleArray> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<Smi> tmp71;
    TNode<Smi> tmp72;
    TNode<HeapObject> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<BoolT> tmp75;
    TNode<Float64T> tmp76;
    ca_.Bind(&block15, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    ca_.Goto(label_IfHole);
  }

  if (block16.is_used()) {
    TNode<Context> tmp77;
    TNode<JSArray> tmp78;
    TNode<Smi> tmp79;
    TNode<FixedDoubleArray> tmp80;
    TNode<FixedDoubleArray> tmp81;
    TNode<FixedDoubleArray> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Smi> tmp85;
    TNode<Smi> tmp86;
    TNode<HeapObject> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<BoolT> tmp89;
    TNode<Float64T> tmp90;
    ca_.Bind(&block16, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<HeapNumber> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp90});
    ca_.Goto(&block17, tmp77, tmp78, tmp79, tmp91);
  }

    TNode<Context> tmp92;
    TNode<JSArray> tmp93;
    TNode<Smi> tmp94;
    TNode<Object> tmp95;
    ca_.Bind(&block17, &tmp92, &tmp93, &tmp94, &tmp95);
  return TNode<Object>{tmp95};
}

void TorqueMoveElementsSmi_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(ElementsKind::HOLEY_SMI_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueMoveElements_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(ElementsKind::HOLEY_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueMoveElements_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(ElementsKind::HOLEY_DOUBLE_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedDoubleArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueCopyElements_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_dstElements, TNode<IntPtrT> p_dstIndex, TNode<FixedArray> p_srcElements, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_dstElements, p_dstIndex, p_srcElements, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<FixedArray> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    CodeStubAssembler(state_).CopyElements(ElementsKind::HOLEY_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<FixedArrayBase>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<FixedArray> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<FixedArray> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
}

void TorqueCopyElements_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_dstElements, TNode<IntPtrT> p_dstIndex, TNode<FixedDoubleArray> p_srcElements, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_dstElements, p_dstIndex, p_srcElements, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<FixedDoubleArray> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    CodeStubAssembler(state_).CopyElements(ElementsKind::HOLEY_DOUBLE_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<FixedArrayBase>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<FixedDoubleArray> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<FixedDoubleArray> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
}

TorqueStructFastJSArrayWitness_0 NewFastJSArrayWitness_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, JSArray, JSArray, Map, BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp2});
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp3});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IsElementsKindLessThanOrEqual(TNode<Int32T>{tmp3}, ElementsKind::HOLEY_SMI_ELEMENTS);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block2, tmp0, tmp0, tmp0, tmp5, tmp6, tmp7, tmp8);
  }

    TNode<JSArray> tmp9;
    TNode<JSArray> tmp10;
    TNode<JSArray> tmp11;
    TNode<Map> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
  return TorqueStructFastJSArrayWitness_0{TNode<JSArray>{tmp10}, TNode<JSArray>{tmp11}, TNode<Map>{tmp12}, TNode<BoolT>{tmp13}, TNode<BoolT>{tmp14}, TNode<BoolT>{tmp15}};
}

TorqueStructFastJSArrayForReadWitness_0 NewFastJSArrayForReadWitness_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, JSArray, JSArray, Map, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp2});
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp3});
    ca_.Goto(&block2, tmp0, tmp0, tmp0, tmp5, tmp6);
  }

    TNode<JSArray> tmp7;
    TNode<JSArray> tmp8;
    TNode<JSArray> tmp9;
    TNode<Map> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
  return TorqueStructFastJSArrayForReadWitness_0{TNode<JSArray>{tmp8}, TNode<JSArray>{tmp9}, TNode<Map>{tmp10}, TNode<BoolT>{tmp11}};
}

TNode<JSReceiver> LoadJSArrayIteratorIteratedObject_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<JSReceiver>tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<JSReceiver> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<JSReceiver>{tmp4};
}

void StoreJSArrayIteratorIteratedObject_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<JSReceiver> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<JSReceiver> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<JSReceiver> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadJSArrayIteratorNextIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreJSArrayIteratorNextIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadJSArrayIteratorKind_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreJSArrayIteratorKind_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArray> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArray> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<BoolT> Method_JSArray_IsEmpty_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = IsNumberEqual_0(state_, TNode<Number>{tmp2}, TNode<Number>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<JSArray> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<BoolT>{tmp6};
}

}  // namespace internal
}  // namespace v8

