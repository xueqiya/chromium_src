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

TNode<BoolT> PromiseHasHandler_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_promise);

  if (block0.is_used()) {
    TNode<JSPromise> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSPromise> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BoolT>{tmp3};
}

void PromiseInit_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_promise);

  if (block0.is_used()) {
    TNode<JSPromise> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = kZero_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1}, tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp3}, tmp4);
    PromiseBuiltinsAssembler(state_).ZeroOutEmbedderOffsets(TNode<JSPromise>{tmp0});
    ca_.Goto(&block6, tmp0);
  }

  if (block5.is_used()) {
    TNode<JSPromise> tmp5;
    ca_.Bind(&block5, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'PromiseState::kPending == 0' failed", "src/builtins/promise-misc.tq", 35);
  }

  if (block4.is_used()) {
    TNode<JSPromise> tmp6;
    ca_.Bind(&block4, &tmp6);
  }

    TNode<JSPromise> tmp7;
    ca_.Bind(&block6, &tmp7);
}

TNode<JSPromise> InnerNewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSFunction> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSFunction> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    TNode<HeapObject>tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp5});
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<HeapObject> tmp8;
    USE(tmp8);
    tmp8 = PromiseBuiltinsAssembler(state_).AllocateJSPromise(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp7);
    TNode<JSPromise> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp8});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<FixedArray> tmp12;
    USE(tmp12);
    tmp12 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11}, tmp12);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArray> tmp14;
    USE(tmp14);
    tmp14 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp10, tmp13}, tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = kZero_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp15}, tmp16);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp17}, tmp18);
    ca_.Goto(&block6, tmp0, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp19;
    TNode<NativeContext> tmp20;
    TNode<JSFunction> tmp21;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFunctionWithPrototypeSlotMap(promiseFun.map)' failed", "src/builtins/promise-misc.tq", 45);
  }

  if (block4.is_used()) {
    TNode<Context> tmp22;
    TNode<NativeContext> tmp23;
    TNode<JSFunction> tmp24;
    ca_.Bind(&block4, &tmp22, &tmp23, &tmp24);
  }

    TNode<Context> tmp25;
    TNode<JSPromise> tmp26;
    ca_.Bind(&block6, &tmp25, &tmp26);
  return TNode<JSPromise>{tmp26};
}

TNode<PromiseReactionJobTask> NewPromiseReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<Context> p_handlerContext, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Context, Object, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Context, Object, HeapObject, HeapObject, PromiseReactionJobTask> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_handlerContext, p_argument, p_handler, p_promiseOrCapability);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<Context> tmp2;
    TNode<Object> tmp3;
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<HeapObject> tmp6;
    USE(tmp6);
    tmp6 = PromiseBuiltinsAssembler(state_).AllocatePromiseReactionJobTask(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp6, tmp7}, tmp1);
    TNode<PromiseReactionJobTask> tmp8;
    USE(tmp8);
    tmp8 = UnsafeCast_PromiseReactionJobTask_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp3);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp8, tmp10}, tmp2);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp8, tmp11}, tmp4);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp8, tmp12}, tmp5);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp8);
  }

    TNode<Context> tmp13;
    TNode<Map> tmp14;
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    TNode<PromiseReactionJobTask> tmp19;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
  return TNode<PromiseReactionJobTask>{tmp19};
}

TNode<JSPromise> NewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_parent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_parent);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    tmp2 = InnerNewJSPromise_0(state_, TNode<Context>{tmp0});
    PromiseInit_0(state_, TNode<JSPromise>{tmp2});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrHasAsyncEventDelegate();
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<JSPromise> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<Object> tmp7;
    tmp7 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseHookInit, tmp4, tmp6, tmp5); 
    USE(tmp7);
    ca_.Goto(&block3, tmp4, tmp5, tmp6);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<JSPromise> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block4, tmp8, tmp9, tmp10);
  }

    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<JSPromise> tmp13;
    ca_.Bind(&block4, &tmp11, &tmp12, &tmp13);
  return TNode<JSPromise>{tmp13};
}

TNode<JSPromise> NewJSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    tmp2 = NewJSPromise_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Context> tmp3;
    TNode<JSPromise> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<JSPromise>{tmp4};
}

TNode<JSPromise> NewJSPromise_2(compiler::CodeAssemblerState* state_, TNode<Context> p_context, Promise::PromiseState p_status, TNode<Object> p_result) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_result);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    tmp2 = InnerNewJSPromise_0(state_, TNode<Context>{tmp0});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp1);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{tmp2}, p_status);
    PromiseBuiltinsAssembler(state_).ZeroOutEmbedderOffsets(TNode<JSPromise>{tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrHasAsyncEventDelegate();
    ca_.Branch(tmp4, &block10, &block11, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'status != PromiseState::kPending' failed", "src/builtins/promise-misc.tq", 101);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block4, &tmp7, &tmp8);
  }

  if (block9.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block9, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kJSPromiseStatusShift == 0' failed", "src/builtins/promise-misc.tq", 102);
  }

  if (block8.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block8, &tmp11, &tmp12);
  }

  if (block10.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<JSPromise> tmp15;
    ca_.Bind(&block10, &tmp13, &tmp14, &tmp15);
    TNode<Oddball> tmp16;
    USE(tmp16);
    tmp16 = Undefined_0(state_);
    TNode<Object> tmp17;
    tmp17 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseHookInit, tmp13, tmp15, tmp16); 
    USE(tmp17);
    ca_.Goto(&block11, tmp13, tmp14, tmp15);
  }

  if (block11.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSPromise> tmp20;
    ca_.Bind(&block11, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block12, tmp18, tmp19, tmp20);
  }

    TNode<Context> tmp21;
    TNode<Object> tmp22;
    TNode<JSPromise> tmp23;
    ca_.Bind(&block12, &tmp21, &tmp22, &tmp23);
  return TNode<JSPromise>{tmp23};
}

TNode<PromiseReaction> NewPromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_next, TNode<HeapObject> p_promiseOrCapability, TNode<HeapObject> p_fulfillHandler, TNode<HeapObject> p_rejectHandler) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, HeapObject, PromiseReaction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_next, p_promiseOrCapability, p_fulfillHandler, p_rejectHandler);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Map> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).PromiseReactionMapConstant();
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    TNode<HeapObject> tmp7;
    USE(tmp7);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp5});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp5);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp1);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp4);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp7, tmp11}, tmp3);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp7, tmp12}, tmp2);
    TNode<PromiseReaction> tmp13;
    USE(tmp13);
    tmp13 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp13);
  }

    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    TNode<PromiseReaction> tmp19;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
  return TNode<PromiseReaction>{tmp19};
}

TNode<PromiseResolveThenableJobTask> NewPromiseResolveThenableJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promiseToResolve, TNode<JSReceiver> p_then, TNode<JSReceiver> p_thenable, TNode<Context> p_thenableContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, JSReceiver, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, JSReceiver, Context, PromiseResolveThenableJobTask> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promiseToResolve, p_then, p_thenable, p_thenableContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<JSReceiver> tmp3;
    TNode<Context> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Map> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).PromiseResolveThenableJobTaskMapConstant();
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    TNode<HeapObject> tmp7;
    USE(tmp7);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp5});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp5);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp4);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<JSPromise>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp1);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp7, tmp11}, tmp2);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp7, tmp12}, tmp3);
    TNode<PromiseResolveThenableJobTask> tmp13;
    USE(tmp13);
    tmp13 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp13);
  }

    TNode<Context> tmp14;
    TNode<JSPromise> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<Context> tmp18;
    TNode<PromiseResolveThenableJobTask> tmp19;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
  return TNode<PromiseResolveThenableJobTask>{tmp19};
}

TNode<Object> InvokeThen_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiver, p_arg);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = InvokeThen_InvokeThenOneArgFunctor_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp1}, TNode<Object>{tmp2}, TNode<Object>{tmp3}, TNode<Object>{tmp4}, TorqueStructInvokeThenOneArgFunctor_0{});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp5);
  }

    TNode<Context> tmp6;
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
  return TNode<Object>{tmp10};
}

TNode<Object> InvokeThen_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiver, p_arg1, p_arg2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = InvokeThen_InvokeThenTwoArgFunctor_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp1}, TNode<Object>{tmp2}, TNode<Object>{tmp3}, TNode<Object>{tmp4}, TorqueStructInvokeThenTwoArgFunctor_0{});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5);
  }

    TNode<Context> tmp6;
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
  return TNode<Object>{tmp11};
}

void BranchIfAccessCheckFailed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_promiseConstructor, TNode<Object> p_executor, compiler::CodeAssemblerLabel* label_IfNoAccess) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, Object, Context> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, Object, Context, JSFunction> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, JSFunction, Context, NativeContext> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, JSFunction, Context, NativeContext> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, Object, Context> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object, Object, Context, JSBoundFunction> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_promiseConstructor, p_executor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    ca_.Goto(&block9, tmp0, tmp1, tmp2, tmp3, tmp3);
  }

  if (block9.is_used()) {
    TNode<Context> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block9, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block7, &block8, tmp4, tmp5, tmp6, tmp7, tmp8);
  }

  if (block7.is_used()) {
    TNode<Context> tmp10;
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block7, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<JSFunction> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_JSFunction_1(state_, TNode<Context>{tmp10}, TNode<Object>{tmp14}, &label0);
    ca_.Goto(&block12, tmp10, tmp11, tmp12, tmp13, tmp14, tmp14, tmp14, tmp10, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp10, tmp11, tmp12, tmp13, tmp14, tmp14, tmp14, tmp10);
    }
  }

  if (block13.is_used()) {
    TNode<Context> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Context> tmp23;
    ca_.Bind(&block13, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<JSBoundFunction> tmp24;
    USE(tmp24);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp24 = Cast_JSBoundFunction_1(state_, TNode<Context>{tmp16}, TNode<Object>{ca_.UncheckedCast<Object>(tmp21)}, &label0);
    ca_.Goto(&block19, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, ca_.UncheckedCast<Object>(tmp21), tmp16, tmp24);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, ca_.UncheckedCast<Object>(tmp21), tmp16);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp25;
    TNode<NativeContext> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<Context> tmp32;
    TNode<JSFunction> tmp33;
    ca_.Bind(&block12, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Context>tmp35 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp33, tmp34});
    TNode<NativeContext> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp35});
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp26}, TNode<MaybeObject>{tmp36});
    ca_.Branch(tmp37, &block14, &block15, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp33, tmp35, tmp36);
  }

  if (block14.is_used()) {
    TNode<Context> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<JSFunction> tmp44;
    TNode<Context> tmp45;
    TNode<NativeContext> tmp46;
    ca_.Bind(&block14, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    ca_.Goto(&block3, tmp38, tmp39, tmp40, tmp41);
  }

  if (block15.is_used()) {
    TNode<Context> tmp47;
    TNode<NativeContext> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<JSFunction> tmp53;
    TNode<Context> tmp54;
    TNode<NativeContext> tmp55;
    ca_.Bind(&block15, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block6, tmp47, tmp48, tmp49, tmp50);
  }

  if (block20.is_used()) {
    TNode<Context> tmp56;
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<Context> tmp63;
    ca_.Bind(&block20, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block6, tmp56, tmp57, tmp58, tmp59);
  }

  if (block19.is_used()) {
    TNode<Context> tmp64;
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<Context> tmp71;
    TNode<JSBoundFunction> tmp72;
    ca_.Bind(&block19, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<IntPtrT> tmp73;
    USE(tmp73);
    tmp73 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<JSReceiver>tmp74 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp72, tmp73});
    ca_.Goto(&block9, tmp64, tmp65, tmp66, tmp67, tmp74);
  }

  if (block8.is_used()) {
    TNode<Context> tmp75;
    TNode<NativeContext> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    ca_.Bind(&block8, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    ca_.Goto(&block5, tmp75, tmp76, tmp77, tmp78);
  }

  if (block6.is_used()) {
    TNode<Context> tmp80;
    TNode<NativeContext> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    ca_.Bind(&block6, &tmp80, &tmp81, &tmp82, &tmp83);
    TNode<Object> tmp84;
    tmp84 = CodeStubAssembler(state_).CallRuntime(Runtime::kAllowDynamicFunction, tmp80, tmp82); 
    USE(tmp84);
    TNode<Oddball> tmp85;
    USE(tmp85);
    tmp85 = True_0(state_);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp84}, TNode<HeapObject>{tmp85});
    ca_.Branch(tmp86, &block21, &block22, tmp80, tmp81, tmp82, tmp83, tmp84);
  }

  if (block21.is_used()) {
    TNode<Context> tmp87;
    TNode<NativeContext> tmp88;
    TNode<Object> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    ca_.Bind(&block21, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    ca_.Goto(label_IfNoAccess);
  }

  if (block22.is_used()) {
    TNode<Context> tmp92;
    TNode<NativeContext> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    ca_.Bind(&block22, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96);
    ca_.Goto(&block5, tmp92, tmp93, tmp94, tmp95);
  }

  if (block5.is_used()) {
    TNode<Context> tmp97;
    TNode<NativeContext> tmp98;
    TNode<Object> tmp99;
    TNode<Object> tmp100;
    ca_.Bind(&block5, &tmp97, &tmp98, &tmp99, &tmp100);
    ca_.Goto(&block3, tmp97, tmp98, tmp99, tmp100);
  }

  if (block3.is_used()) {
    TNode<Context> tmp101;
    TNode<NativeContext> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    ca_.Bind(&block3, &tmp101, &tmp102, &tmp103, &tmp104);
    ca_.Goto(&block23, tmp101, tmp102, tmp103, tmp104);
  }

    TNode<Context> tmp105;
    TNode<NativeContext> tmp106;
    TNode<Object> tmp107;
    TNode<Object> tmp108;
    ca_.Bind(&block23, &tmp105, &tmp106, &tmp107, &tmp108);
}

TNode<PromiseReactionJobTask> UnsafeCast_PromiseReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseReactionJobTask> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseReactionJobTask> tmp2;
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
    TNode<PromiseReactionJobTask> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<PromiseReactionJobTask>{tmp9};
}

TNode<Object> InvokeThen_InvokeThenOneArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenOneArgFunctor_0 p_callFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiver, p_arg1, p_arg2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = Is_Smi_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block4, &block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<HeapObject> tmp13;
    USE(tmp13);
    tmp13 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp9});
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp15 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp13, tmp14});
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{tmp7}, TNode<NativeContext>{tmp8}, TNode<Map>{tmp15});
    ca_.Goto(&block6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<BoolT> tmp22;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block6.is_used()) {
    TNode<Context> tmp24;
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    ca_.Bind(&block6, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Branch(tmp30, &block2, &block3, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block2.is_used()) {
    TNode<Context> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    TNode<Object> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp32}, TNode<IntPtrT>{tmp36});
    TNode<Object> tmp38;
    USE(tmp38);
    tmp38 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp31}, TNode<Object>{tmp37});
    TNode<Object> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).Call(TNode<Context>{tmp32}, TNode<Object>{tmp38}, TNode<Object>{tmp33}, TNode<Object>{tmp34});
    ca_.Goto(&block1, tmp31, tmp32, tmp33, tmp34, tmp35, tmp39);
  }

  if (block3.is_used()) {
    TNode<Context> tmp40;
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block3, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<String> tmp45;
    USE(tmp45);
    tmp45 = kThenString_0(state_);
    TNode<Object> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp40}, TNode<Object>{tmp42}, TNode<Object>{tmp45});
    TNode<Object> tmp47;
    USE(tmp47);
    tmp47 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp40}, TNode<Object>{tmp46});
    TNode<Object> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).Call(TNode<Context>{tmp41}, TNode<Object>{tmp47}, TNode<Object>{tmp42}, TNode<Object>{tmp43});
    ca_.Goto(&block1, tmp40, tmp41, tmp42, tmp43, tmp44, tmp48);
  }

  if (block1.is_used()) {
    TNode<Context> tmp49;
    TNode<NativeContext> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    ca_.Bind(&block1, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Goto(&block10, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54);
  }

    TNode<Context> tmp55;
    TNode<NativeContext> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block10, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
  return TNode<Object>{tmp60};
}

TNode<Object> InvokeThen_InvokeThenTwoArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenTwoArgFunctor_0 p_callFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiver, p_arg1, p_arg2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = Is_Smi_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block4, &block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<HeapObject> tmp13;
    USE(tmp13);
    tmp13 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp9});
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp15 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp13, tmp14});
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{tmp7}, TNode<NativeContext>{tmp8}, TNode<Map>{tmp15});
    ca_.Goto(&block6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<BoolT> tmp22;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block6.is_used()) {
    TNode<Context> tmp24;
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    ca_.Bind(&block6, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Branch(tmp30, &block2, &block3, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block2.is_used()) {
    TNode<Context> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    TNode<Object> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp32}, TNode<IntPtrT>{tmp36});
    TNode<Object> tmp38;
    USE(tmp38);
    tmp38 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp31}, TNode<Object>{tmp37});
    TNode<Object> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).Call(TNode<Context>{tmp32}, TNode<Object>{tmp38}, TNode<Object>{tmp33}, TNode<Object>{tmp34}, TNode<Object>{tmp35});
    ca_.Goto(&block1, tmp31, tmp32, tmp33, tmp34, tmp35, tmp39);
  }

  if (block3.is_used()) {
    TNode<Context> tmp40;
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block3, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<String> tmp45;
    USE(tmp45);
    tmp45 = kThenString_0(state_);
    TNode<Object> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp40}, TNode<Object>{tmp42}, TNode<Object>{tmp45});
    TNode<Object> tmp47;
    USE(tmp47);
    tmp47 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp40}, TNode<Object>{tmp46});
    TNode<Object> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).Call(TNode<Context>{tmp41}, TNode<Object>{tmp47}, TNode<Object>{tmp42}, TNode<Object>{tmp43}, TNode<Object>{tmp44});
    ca_.Goto(&block1, tmp40, tmp41, tmp42, tmp43, tmp44, tmp48);
  }

  if (block1.is_used()) {
    TNode<Context> tmp49;
    TNode<NativeContext> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    ca_.Bind(&block1, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Goto(&block10, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54);
  }

    TNode<Context> tmp55;
    TNode<NativeContext> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block10, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
  return TNode<Object>{tmp60};
}

TNode<BoolT> Is_Smi_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

}  // namespace internal
}  // namespace v8

