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

TNode<BoolT> IsJSArgumentsObjectWithLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Is_JSArgumentsObjectWithLength_Object_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<JSArgumentsObject> NewJSStrictArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = GetStrictArgumentsMap_0(state_, TNode<Context>{tmp0});
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject> tmp7;
    USE(tmp7);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp2});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp2);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp3);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp1);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp11}, tmp5);
    TNode<JSArgumentsObject> tmp12;
    USE(tmp12);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    ca_.Goto(&block2, tmp0, tmp1, tmp12);
  }

    TNode<Context> tmp13;
    TNode<FixedArray> tmp14;
    TNode<JSArgumentsObject> tmp15;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15);
  return TNode<JSArgumentsObject>{tmp15};
}

TNode<JSArgumentsObject> NewJSSloppyArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, JSFunction, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements, p_callee);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<JSFunction> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = GetSloppyArgumentsMap_0(state_, TNode<Context>{tmp0});
    TNode<FixedArray> tmp4;
    USE(tmp4);
    tmp4 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    TNode<HeapObject> tmp8;
    USE(tmp8);
    tmp8 = Allocate_0(state_, TNode<IntPtrT>{tmp7}, TNode<Map>{tmp3});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp3);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp10}, tmp4);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp8, tmp11}, tmp1);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp12}, tmp6);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp13}, tmp2);
    TNode<JSArgumentsObject> tmp14;
    USE(tmp14);
    tmp14 = TORQUE_CAST(TNode<HeapObject>{tmp8});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp14);
  }

    TNode<Context> tmp15;
    TNode<FixedArray> tmp16;
    TNode<JSFunction> tmp17;
    TNode<JSArgumentsObject> tmp18;
    ca_.Bind(&block2, &tmp15, &tmp16, &tmp17, &tmp18);
  return TNode<JSArgumentsObject>{tmp18};
}

TNode<JSArgumentsObject> NewJSFastAliasedArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<Smi> p_length, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, JSFunction, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements, p_length, p_callee);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Smi> tmp2;
    TNode<JSFunction> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = GetFastAliasedArgumentsMap_0(state_, TNode<Context>{tmp0});
    TNode<FixedArray> tmp5;
    USE(tmp5);
    tmp5 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    TNode<HeapObject> tmp7;
    USE(tmp7);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp4});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp4);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp5);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp1);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp11}, tmp2);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp12}, tmp3);
    TNode<JSArgumentsObject> tmp13;
    USE(tmp13);
    tmp13 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp13);
  }

    TNode<Context> tmp14;
    TNode<FixedArray> tmp15;
    TNode<Smi> tmp16;
    TNode<JSFunction> tmp17;
    TNode<JSArgumentsObject> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
  return TNode<JSArgumentsObject>{tmp18};
}

TorqueStructParameterMapIterator_0 NewParameterMapIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<IntPtrT> p_formalParameterCount, TNode<IntPtrT> p_mappedCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, IntPtrT, Uint32T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, IntPtrT, Uint32T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements, p_formalParameterCount, p_mappedCount);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<ScopeInfo>tmp5 = CodeStubAssembler(state_).LoadReference<ScopeInfo>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = LoadScopeInfoFlags_0(state_, TNode<Context>{tmp0}, TNode<ScopeInfo>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, Context::MIN_CONTEXT_SLOTS);
    TNode<BoolT>tmp8 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedScopeFlagsFields::HasContextExtensionSlotBit>(ca_.UncheckedCast<Word32T>(tmp6)));
    ca_.Branch(tmp8, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp6, tmp7);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<FixedArray> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    ca_.Goto(&block3, tmp9, tmp10, tmp11, tmp12, tmp13, tmp16);
  }

  if (block3.is_used()) {
    TNode<Context> tmp17;
    TNode<FixedArray> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Uint32T> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block3, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp19});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp20});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp17, tmp18, tmp19, tmp20, tmp17, tmp18, tmp23, tmp24, tmp25);
  }

    TNode<Context> tmp26;
    TNode<FixedArray> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<Context> tmp30;
    TNode<FixedArray> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    ca_.Bind(&block4, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
  return TorqueStructParameterMapIterator_0{TNode<Context>{tmp30}, TNode<FixedArray>{tmp31}, TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34}};
}

TorqueStructParameterValueIterator_0 NewParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_mappedCount, TorqueStructArguments p_arguments) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_mappedCount, p_arguments.frame, p_arguments.base, p_arguments.length);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3, tmp0);
  }

    TNode<IntPtrT> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<RawPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
  return TorqueStructParameterValueIterator_0{TNode<IntPtrT>{tmp8}, TorqueStructArguments{TNode<RawPtrT>{tmp9}, TNode<RawPtrT>{tmp10}, TNode<IntPtrT>{tmp11}}, TNode<IntPtrT>{tmp12}};
}

TNode<JSArray> NewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argumentCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, IntPtrT, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_frame, p_argumentCount);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{tmp0});
    TNode<RawPtrT> tmp4;
    USE(tmp4);
    TNode<RawPtrT> tmp5;
    USE(tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    std::tie(tmp4, tmp5, tmp6) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}).Flatten();
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp8;
    USE(tmp8);
    tmp8 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp2}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp4}, TNode<RawPtrT>{tmp5}, TNode<IntPtrT>{tmp6}}, TNode<IntPtrT>{tmp7}});
    TNode<JSArray> tmp9;
    USE(tmp9);
    tmp9 = NewJSArray_0(state_, TNode<Context>{tmp0}, TNode<Map>{tmp3}, TNode<FixedArrayBase>{tmp8});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp9);
  }

    TNode<Context> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<JSArray> tmp13;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13);
  return TNode<JSArray>{tmp13};
}

TNode<JSArray> NewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, IntPtrT, IntPtrT, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, IntPtrT, IntPtrT, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, IntPtrT, IntPtrT, Map, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_info.frame, p_info.argument_count, p_info.formal_parameter_count);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<BInt> tmp2;
    TNode<BInt> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = Convert_intptr_bint_0(state_, TNode<BInt>{tmp2});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_bint_0(state_, TNode<BInt>{tmp3});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{tmp0});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp7, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<BInt> tmp10;
    TNode<BInt> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Map> tmp14;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<RawPtrT> tmp17;
    TNode<BInt> tmp18;
    TNode<BInt> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Map> tmp22;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21});
    ca_.Goto(&block4, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block4.is_used()) {
    TNode<Context> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<BInt> tmp26;
    TNode<BInt> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<Map> tmp30;
    TNode<IntPtrT> tmp31;
    ca_.Bind(&block4, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<RawPtrT> tmp32;
    USE(tmp32);
    TNode<RawPtrT> tmp33;
    USE(tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    std::tie(tmp32, tmp33, tmp34) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp25}, TNode<IntPtrT>{tmp28}).Flatten();
    TNode<FixedArray> tmp35;
    USE(tmp35);
    tmp35 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp31}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp32}, TNode<RawPtrT>{tmp33}, TNode<IntPtrT>{tmp34}}, TNode<IntPtrT>{tmp29}});
    TNode<JSArray> tmp36;
    USE(tmp36);
    tmp36 = NewJSArray_0(state_, TNode<Context>{tmp24}, TNode<Map>{tmp30}, TNode<FixedArrayBase>{tmp35});
    ca_.Goto(&block6, tmp24, tmp25, tmp26, tmp27, tmp36);
  }

    TNode<Context> tmp37;
    TNode<RawPtrT> tmp38;
    TNode<BInt> tmp39;
    TNode<BInt> tmp40;
    TNode<JSArray> tmp41;
    ca_.Bind(&block6, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
  return TNode<JSArray>{tmp41};
}

TNode<JSArgumentsObject> NewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_info.frame, p_info.argument_count, p_info.formal_parameter_count);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<BInt> tmp2;
    TNode<BInt> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = Convert_intptr_bint_0(state_, TNode<BInt>{tmp2});
    TNode<RawPtrT> tmp5;
    USE(tmp5);
    TNode<RawPtrT> tmp6;
    USE(tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    std::tie(tmp5, tmp6, tmp7) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp4}).Flatten();
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp9;
    USE(tmp9);
    tmp9 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp4}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp5}, TNode<RawPtrT>{tmp6}, TNode<IntPtrT>{tmp7}}, TNode<IntPtrT>{tmp8}});
    TNode<JSArgumentsObject> tmp10;
    USE(tmp10);
    tmp10 = NewJSStrictArgumentsObject_0(state_, TNode<Context>{tmp0}, TNode<FixedArray>{tmp9});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp10);
  }

    TNode<Context> tmp11;
    TNode<RawPtrT> tmp12;
    TNode<BInt> tmp13;
    TNode<BInt> tmp14;
    TNode<JSArgumentsObject> tmp15;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
  return TNode<JSArgumentsObject>{tmp15};
}

TNode<JSArgumentsObject> NewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSFunction, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSFunction, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSFunction, JSArgumentsObject> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, BInt, BInt, JSFunction, JSArgumentsObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_info.frame, p_info.argument_count, p_info.formal_parameter_count, p_callee);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<BInt> tmp2;
    TNode<BInt> tmp3;
    TNode<JSFunction> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_bint_0(state_, TNode<BInt>{tmp2});
    TNode<RawPtrT> tmp6;
    USE(tmp6);
    TNode<RawPtrT> tmp7;
    USE(tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    std::tie(tmp6, tmp7, tmp8) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp5}).Flatten();
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_intptr_bint_0(state_, TNode<BInt>{tmp3});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9);
  }

  if (block2.is_used()) {
    TNode<Context> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<BInt> tmp14;
    TNode<BInt> tmp15;
    TNode<JSFunction> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp23;
    USE(tmp23);
    tmp23 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp17}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp18}, TNode<RawPtrT>{tmp19}, TNode<IntPtrT>{tmp20}}, TNode<IntPtrT>{tmp22}});
    TNode<JSArgumentsObject> tmp24;
    USE(tmp24);
    tmp24 = NewJSSloppyArgumentsObject_0(state_, TNode<Context>{tmp12}, TNode<FixedArray>{tmp23}, TNode<JSFunction>{tmp16});
    ca_.Goto(&block1, tmp12, tmp13, tmp14, tmp15, tmp16, tmp24);
  }

  if (block3.is_used()) {
    TNode<Context> tmp25;
    TNode<RawPtrT> tmp26;
    TNode<BInt> tmp27;
    TNode<BInt> tmp28;
    TNode<JSFunction> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    ca_.Bind(&block3, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp30});
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    TNode<RawPtrT> tmp37;
    USE(tmp37);
    TNode<RawPtrT> tmp38;
    USE(tmp38);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    std::tie(tmp36, tmp37, tmp38, tmp39, tmp40) = NewParameterValueIterator_0(state_, TNode<IntPtrT>{tmp35}, TorqueStructArguments{TNode<RawPtrT>{tmp31}, TNode<RawPtrT>{tmp32}, TNode<IntPtrT>{tmp33}}).Flatten();
    TNode<FixedArray> tmp41;
    USE(tmp41);
    tmp41 = NewFixedArray_ParameterValueIterator_0(state_, TNode<IntPtrT>{tmp30}, TorqueStructParameterValueIterator_0{TNode<IntPtrT>{tmp36}, TorqueStructArguments{TNode<RawPtrT>{tmp37}, TNode<RawPtrT>{tmp38}, TNode<IntPtrT>{tmp39}}, TNode<IntPtrT>{tmp40}});
    TNode<Context> tmp42;
    USE(tmp42);
    TNode<FixedArray> tmp43;
    USE(tmp43);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    TNode<IntPtrT> tmp45;
    USE(tmp45);
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    std::tie(tmp42, tmp43, tmp44, tmp45, tmp46) = NewParameterMapIterator_0(state_, TNode<Context>{tmp25}, TNode<FixedArray>{tmp41}, TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp35}).Flatten();
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, SloppyArgumentsElements::kParameterMapStart);
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp47});
    TNode<Smi> tmp49;
    USE(tmp49);
    tmp49 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp48});
    TNode<Map> tmp50;
    USE(tmp50);
    tmp50 = kSloppyArgumentsElementsMap_0(state_);
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    tmp51 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp49});
    TNode<IntPtrT> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp53;
    USE(tmp53);
    tmp53 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp52}, TNode<IntPtrT>{tmp51}, kTaggedSize);
    TNode<HeapObject> tmp54;
    USE(tmp54);
    tmp54 = Allocate_0(state_, TNode<IntPtrT>{tmp53}, TNode<Map>{tmp50});
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp54, tmp55}, tmp50);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp54, tmp56}, tmp49);
    TNode<IntPtrT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ParameterMapIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp54}, TNode<IntPtrT>{tmp57}, TNode<IntPtrT>{tmp51}, TorqueStructUnsafe_0{}}, TorqueStructParameterMapIterator_0{TNode<Context>{tmp42}, TNode<FixedArray>{tmp43}, TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp46}});
    TNode<FixedArray> tmp58;
    USE(tmp58);
    tmp58 = TORQUE_CAST(TNode<HeapObject>{tmp54});
    TNode<Smi> tmp59;
    USE(tmp59);
    tmp59 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp30});
    TNode<JSArgumentsObject> tmp60;
    USE(tmp60);
    tmp60 = NewJSFastAliasedArgumentsObject_0(state_, TNode<Context>{tmp25}, TNode<FixedArray>{tmp58}, TNode<Smi>{tmp59}, TNode<JSFunction>{tmp29});
    ca_.Goto(&block1, tmp25, tmp26, tmp27, tmp28, tmp29, tmp60);
  }

  if (block1.is_used()) {
    TNode<Context> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<BInt> tmp63;
    TNode<BInt> tmp64;
    TNode<JSFunction> tmp65;
    TNode<JSArgumentsObject> tmp66;
    ca_.Bind(&block1, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    ca_.Goto(&block4, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66);
  }

    TNode<Context> tmp67;
    TNode<RawPtrT> tmp68;
    TNode<BInt> tmp69;
    TNode<BInt> tmp70;
    TNode<JSFunction> tmp71;
    TNode<JSArgumentsObject> tmp72;
    ca_.Bind(&block4, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
  return TNode<JSArgumentsObject>{tmp72};
}

TNode<JSArray> EmitFastNewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argc) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, IntPtrT, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_frame, p_argc);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSArray> tmp3;
    USE(tmp3);
    tmp3 = NewAllArguments_0(state_, TNode<Context>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<Context> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<JSArray> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
  return TNode<JSArray>{tmp7};
}

TNode<JSArray> EmitFastNewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p__f);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<RawPtrT> tmp2;
    USE(tmp2);
    TNode<BInt> tmp3;
    USE(tmp3);
    TNode<BInt> tmp4;
    USE(tmp4);
    std::tie(tmp2, tmp3, tmp4) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<JSArray> tmp5;
    USE(tmp5);
    tmp5 = NewRestArguments_0(state_, TNode<Context>{tmp0}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp2}, TNode<BInt>{tmp3}, TNode<BInt>{tmp4}});
    ca_.Goto(&block2, tmp0, tmp1, tmp5);
  }

    TNode<Context> tmp6;
    TNode<JSFunction> tmp7;
    TNode<JSArray> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
  return TNode<JSArray>{tmp8};
}

TNode<JSArgumentsObject> EmitFastNewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p__f);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<RawPtrT> tmp2;
    USE(tmp2);
    TNode<BInt> tmp3;
    USE(tmp3);
    TNode<BInt> tmp4;
    USE(tmp4);
    std::tie(tmp2, tmp3, tmp4) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<JSArgumentsObject> tmp5;
    USE(tmp5);
    tmp5 = NewStrictArguments_0(state_, TNode<Context>{tmp0}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp2}, TNode<BInt>{tmp3}, TNode<BInt>{tmp4}});
    ca_.Goto(&block2, tmp0, tmp1, tmp5);
  }

    TNode<Context> tmp6;
    TNode<JSFunction> tmp7;
    TNode<JSArgumentsObject> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
  return TNode<JSArgumentsObject>{tmp8};
}

TNode<JSArgumentsObject> EmitFastNewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_f);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<RawPtrT> tmp2;
    USE(tmp2);
    TNode<BInt> tmp3;
    USE(tmp3);
    TNode<BInt> tmp4;
    USE(tmp4);
    std::tie(tmp2, tmp3, tmp4) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<JSArgumentsObject> tmp5;
    USE(tmp5);
    tmp5 = NewSloppyArguments_0(state_, TNode<Context>{tmp0}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp2}, TNode<BInt>{tmp3}, TNode<BInt>{tmp4}}, TNode<JSFunction>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp5);
  }

    TNode<Context> tmp6;
    TNode<JSFunction> tmp7;
    TNode<JSArgumentsObject> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
  return TNode<JSArgumentsObject>{tmp8};
}

TNode<Object> LoadJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StoreJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StoreJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StoreJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArgumentsObject> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArgumentsObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<AliasedArgumentsEntry> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<AliasedArgumentsEntry, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<AliasedArgumentsEntry> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<AliasedArgumentsEntry> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<AliasedArgumentsEntry, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<AliasedArgumentsEntry, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<AliasedArgumentsEntry> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<AliasedArgumentsEntry> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<BoolT> Is_JSArgumentsObjectWithLength_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArgumentsObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArgumentsObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSArgumentsObjectWithLength_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArgumentsObject> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<FixedArray> NewFixedArray_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructArgumentsIterator_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length, p_it.arguments.frame, p_it.arguments.base, p_it.arguments.length, p_it.current);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<FixedArray> tmp12;
    USE(tmp12);
    tmp12 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Map> tmp18;
    USE(tmp18);
    tmp18 = kFixedArrayMap_0(state_);
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp13});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp19});
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp20}, kTaggedSize);
    TNode<HeapObject> tmp23;
    USE(tmp23);
    tmp23 = Allocate_0(state_, TNode<IntPtrT>{tmp22}, TNode<Map>{tmp18});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp23, tmp24}, tmp18);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp23, tmp25}, tmp19);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ArgumentsIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp23}, TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp20}, TorqueStructUnsafe_0{}}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp14}, TNode<RawPtrT>{tmp15}, TNode<IntPtrT>{tmp16}}, TNode<IntPtrT>{tmp17}});
    TNode<FixedArray> tmp27;
    USE(tmp27);
    tmp27 = TORQUE_CAST(TNode<HeapObject>{tmp23});
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp16, tmp17, tmp27);
  }

  if (block1.is_used()) {
    TNode<IntPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<RawPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<FixedArray> tmp33;
    ca_.Bind(&block1, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block4, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

    TNode<IntPtrT> tmp34;
    TNode<RawPtrT> tmp35;
    TNode<RawPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<FixedArray> tmp39;
    ca_.Bind(&block4, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
  return TNode<FixedArray>{tmp39};
}

TNode<FixedArray> NewFixedArray_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructParameterValueIterator_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length, p_it.mapped_count, p_it.arguments.frame, p_it.arguments.base, p_it.arguments.length, p_it.current);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp6});
    ca_.Branch(tmp7, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<FixedArray> tmp14;
    USE(tmp14);
    tmp14 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<RawPtrT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Map> tmp21;
    USE(tmp21);
    tmp21 = kFixedArrayMap_0(state_);
    TNode<Smi> tmp22;
    USE(tmp22);
    tmp22 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp15});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp23}, kTaggedSize);
    TNode<HeapObject> tmp26;
    USE(tmp26);
    tmp26 = Allocate_0(state_, TNode<IntPtrT>{tmp25}, TNode<Map>{tmp21});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp26, tmp27}, tmp21);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp26, tmp28}, tmp22);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ParameterValueIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp26}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructParameterValueIterator_0{TNode<IntPtrT>{tmp16}, TorqueStructArguments{TNode<RawPtrT>{tmp17}, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp19}}, TNode<IntPtrT>{tmp20}});
    TNode<FixedArray> tmp30;
    USE(tmp30);
    tmp30 = TORQUE_CAST(TNode<HeapObject>{tmp26});
    ca_.Goto(&block1, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp30);
  }

  if (block1.is_used()) {
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<RawPtrT> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<FixedArray> tmp37;
    ca_.Bind(&block1, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block4, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37);
  }

    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<RawPtrT> tmp40;
    TNode<RawPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<FixedArray> tmp44;
    ca_.Bind(&block4, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
  return TNode<FixedArray>{tmp44};
}

void InitializeFieldsFromIterator_Object_ParameterMapIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterMapIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Context, FixedArray, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.context, p_originIterator.elements, p_originIterator.currentIndex, p_originIterator.endInterationIndex, p_originIterator.currentMapSlot);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Context> tmp3;
    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp9});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp0, tmp1, tmp10, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Context> tmp14;
    TNode<FixedArray> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<HeapObject> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Context> tmp22;
    TNode<FixedArray> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp27, &block3, &block4, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Context> tmp31;
    TNode<FixedArray> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<HeapObject> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Context> tmp39;
    TNode<FixedArray> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    ca_.Bind(&block3, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    ca_.Branch(tmp44, &block9, &block10, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<Context> tmp48;
    TNode<FixedArray> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Context> tmp56;
    TNode<FixedArray> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block9, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    ca_.Goto(&block4, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Context> tmp64;
    TNode<FixedArray> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<HeapObject> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<Context> tmp72;
    TNode<FixedArray> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<HeapObject> tmp77;
    USE(tmp77);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    std::tie(tmp77, tmp78) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp69}, TNode<IntPtrT>{tmp70}).Flatten();
    TNode<IntPtrT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp70}, TNode<IntPtrT>{tmp79});
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp76}, TNode<IntPtrT>{tmp81});
    TNode<IntPtrT> tmp83;
    USE(tmp83);
    tmp83 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp76}, TNode<IntPtrT>{tmp83});
    ca_.Branch(tmp84, &block16, &block17, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp80, tmp71, tmp72, tmp73, tmp74, tmp75, tmp82, tmp77, tmp78, tmp77, tmp78, tmp76);
  }

  if (block16.is_used()) {
    TNode<HeapObject> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<Context> tmp88;
    TNode<FixedArray> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<HeapObject> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<Context> tmp96;
    TNode<FixedArray> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<HeapObject> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<HeapObject> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<IntPtrT> tmp105;
    ca_.Bind(&block16, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
    TNode<BoolT> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp98}, TNode<IntPtrT>{tmp99});
    ca_.Branch(tmp106, &block19, &block20, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105);
  }

  if (block19.is_used()) {
    TNode<HeapObject> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<IntPtrT> tmp109;
    TNode<Context> tmp110;
    TNode<FixedArray> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<HeapObject> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<Context> tmp118;
    TNode<FixedArray> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<HeapObject> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<HeapObject> tmp125;
    TNode<IntPtrT> tmp126;
    TNode<IntPtrT> tmp127;
    ca_.Bind(&block19, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block20.is_used()) {
    TNode<HeapObject> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<Context> tmp131;
    TNode<FixedArray> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<HeapObject> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<Context> tmp139;
    TNode<FixedArray> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<HeapObject> tmp144;
    TNode<IntPtrT> tmp145;
    TNode<HeapObject> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<IntPtrT> tmp148;
    ca_.Bind(&block20, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    TNode<IntPtrT> tmp149;
    USE(tmp149);
    tmp149 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp150;
    USE(tmp150);
    tmp150 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp141}, TNode<IntPtrT>{tmp149});
    TNode<Smi> tmp151;
    USE(tmp151);
    tmp151 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp150});
    ca_.Goto(&block15, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp150, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp151);
  }

  if (block17.is_used()) {
    TNode<HeapObject> tmp152;
    TNode<IntPtrT> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<Context> tmp155;
    TNode<FixedArray> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<HeapObject> tmp160;
    TNode<IntPtrT> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<Context> tmp163;
    TNode<FixedArray> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<HeapObject> tmp168;
    TNode<IntPtrT> tmp169;
    TNode<HeapObject> tmp170;
    TNode<IntPtrT> tmp171;
    TNode<IntPtrT> tmp172;
    ca_.Bind(&block17, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172);
    TNode<IntPtrT> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp174;
    USE(tmp174);
    tmp174 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp172}, TNode<IntPtrT>{tmp173});
    ca_.Branch(tmp174, &block21, &block22, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172);
  }

  if (block21.is_used()) {
    TNode<HeapObject> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<Context> tmp178;
    TNode<FixedArray> tmp179;
    TNode<IntPtrT> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<IntPtrT> tmp182;
    TNode<HeapObject> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<Context> tmp186;
    TNode<FixedArray> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<HeapObject> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<HeapObject> tmp193;
    TNode<IntPtrT> tmp194;
    TNode<IntPtrT> tmp195;
    ca_.Bind(&block21, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195);
    ca_.Goto(&block15, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp186);
  }

  if (block22.is_used()) {
    TNode<HeapObject> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<IntPtrT> tmp198;
    TNode<Context> tmp199;
    TNode<FixedArray> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<IntPtrT> tmp203;
    TNode<HeapObject> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<IntPtrT> tmp206;
    TNode<Context> tmp207;
    TNode<FixedArray> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<HeapObject> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<HeapObject> tmp214;
    TNode<IntPtrT> tmp215;
    TNode<IntPtrT> tmp216;
    ca_.Bind(&block22, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
    ca_.Goto(&block15, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp208);
  }

  if (block27.is_used()) {
    TNode<HeapObject> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<Context> tmp220;
    TNode<FixedArray> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<HeapObject> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<Context> tmp228;
    TNode<FixedArray> tmp229;
    TNode<IntPtrT> tmp230;
    TNode<IntPtrT> tmp231;
    TNode<IntPtrT> tmp232;
    TNode<HeapObject> tmp233;
    TNode<IntPtrT> tmp234;
    TNode<HeapObject> tmp235;
    TNode<IntPtrT> tmp236;
    TNode<IntPtrT> tmp237;
    ca_.Bind(&block27, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237);
    CodeStubAssembler(state_).FailAssert("Torque assert 'currentMapSlotCopy == 1' failed", "src/objects/arguments.tq", 86);
  }

  if (block26.is_used()) {
    TNode<HeapObject> tmp238;
    TNode<IntPtrT> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<Context> tmp241;
    TNode<FixedArray> tmp242;
    TNode<IntPtrT> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<IntPtrT> tmp245;
    TNode<HeapObject> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<IntPtrT> tmp248;
    TNode<Context> tmp249;
    TNode<FixedArray> tmp250;
    TNode<IntPtrT> tmp251;
    TNode<IntPtrT> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<HeapObject> tmp254;
    TNode<IntPtrT> tmp255;
    TNode<HeapObject> tmp256;
    TNode<IntPtrT> tmp257;
    TNode<IntPtrT> tmp258;
    ca_.Bind(&block26, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258);
  }

  if (block15.is_used()) {
    TNode<HeapObject> tmp259;
    TNode<IntPtrT> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<Context> tmp262;
    TNode<FixedArray> tmp263;
    TNode<IntPtrT> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<HeapObject> tmp267;
    TNode<IntPtrT> tmp268;
    TNode<IntPtrT> tmp269;
    TNode<Context> tmp270;
    TNode<FixedArray> tmp271;
    TNode<IntPtrT> tmp272;
    TNode<IntPtrT> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<HeapObject> tmp275;
    TNode<IntPtrT> tmp276;
    TNode<HeapObject> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<Object> tmp279;
    ca_.Bind(&block15, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp277, tmp278}, tmp279);
    ca_.Goto(&block5, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp280;
    TNode<IntPtrT> tmp281;
    TNode<IntPtrT> tmp282;
    TNode<Context> tmp283;
    TNode<FixedArray> tmp284;
    TNode<IntPtrT> tmp285;
    TNode<IntPtrT> tmp286;
    TNode<IntPtrT> tmp287;
    TNode<HeapObject> tmp288;
    TNode<IntPtrT> tmp289;
    TNode<IntPtrT> tmp290;
    TNode<Context> tmp291;
    TNode<FixedArray> tmp292;
    TNode<IntPtrT> tmp293;
    TNode<IntPtrT> tmp294;
    TNode<IntPtrT> tmp295;
    ca_.Bind(&block4, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295);
    ca_.Goto(&block28, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287);
  }

    TNode<HeapObject> tmp296;
    TNode<IntPtrT> tmp297;
    TNode<IntPtrT> tmp298;
    TNode<Context> tmp299;
    TNode<FixedArray> tmp300;
    TNode<IntPtrT> tmp301;
    TNode<IntPtrT> tmp302;
    TNode<IntPtrT> tmp303;
    ca_.Bind(&block28, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303);
}

}  // namespace internal
}  // namespace v8

