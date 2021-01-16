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

TNode<Object> RejectPromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Object> p_reason, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, HeapObject, Context, Object> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability, PromiseCapability, PromiseCapability, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability, Object, Context, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability, JSReceiver, Context, JSReceiver, Oddball, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promiseOrCapability, p_reason);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)))) {
      ca_.Goto(&block2, tmp0, tmp1, tmp2);
    } else {
      ca_.Goto(&block3, tmp0, tmp1, tmp2);
    }
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IsJSPromise(TNode<HeapObject>{tmp4});
    ca_.Branch(tmp6, &block5, &block6, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9);
    TNode<JSPromise> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp8});
    TNode<Oddball> tmp11;
    USE(tmp11);
    tmp11 = False_0(state_);
    TNode<Object> tmp12;
    tmp12 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRejectPromise, tmp7, tmp10, tmp9, tmp11);
    USE(tmp12);
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp12);
  }

  if (block6.is_used()) {
    TNode<Context> tmp13;
    TNode<HeapObject> tmp14;
    TNode<Object> tmp15;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15);
    TNode<PromiseCapability> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerExceptionHandlerLabel catch17__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch17__label);
    tmp16 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp13}, TNode<Object>{tmp14});
    }
    if (catch17__label.is_used()) {
      compiler::CodeAssemblerLabel catch17_skip(&ca_);
      ca_.Goto(&catch17_skip);
      TNode<Object> catch17_exception_object;
      ca_.Bind(&catch17__label, &catch17_exception_object);
      ca_.Goto(&block14, tmp13, tmp14, tmp15, tmp14, tmp13, catch17_exception_object);
      ca_.Bind(&catch17_skip);
    }
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      TNode<Object> catch19_exception_object;
      ca_.Bind(&catch19__label, &catch19_exception_object);
      ca_.Goto(&block15, tmp13, tmp14, tmp15, tmp16, tmp16, tmp16, catch19_exception_object);
      ca_.Bind(&catch19_skip);
    }
    TNode<Object>tmp20 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp16, tmp18});
    TNode<JSReceiver> tmp21;
    USE(tmp21);
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp13}, TNode<Object>{tmp20});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      TNode<Object> catch22_exception_object;
      ca_.Bind(&catch22__label, &catch22_exception_object);
      ca_.Goto(&block16, tmp13, tmp14, tmp15, tmp16, tmp20, tmp13, catch22_exception_object);
      ca_.Bind(&catch22_skip);
    }
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = Undefined_0(state_);
    TNode<Object> tmp24;
    USE(tmp24);
    compiler::CodeAssemblerExceptionHandlerLabel catch25__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch25__label);
    tmp24 = CodeStubAssembler(state_).Call(TNode<Context>{tmp13}, TNode<Object>{tmp21}, TNode<Object>{tmp23}, TNode<Object>{tmp15});
    }
    if (catch25__label.is_used()) {
      compiler::CodeAssemblerLabel catch25_skip(&ca_);
      ca_.Goto(&catch25_skip);
      TNode<Object> catch25_exception_object;
      ca_.Bind(&catch25__label, &catch25_exception_object);
      ca_.Goto(&block17, tmp13, tmp14, tmp15, tmp16, tmp21, tmp13, tmp21, tmp23, tmp15, catch25_exception_object);
      ca_.Bind(&catch25_skip);
    }
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp24);
  }

  if (block11.is_used()) {
    TNode<Context> tmp26;
    TNode<HeapObject> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block11, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsPromiseCapability(promiseOrCapability)' failed", "src/builtins/promise-reaction-job.tq", 28);
  }

  if (block10.is_used()) {
    TNode<Context> tmp29;
    TNode<HeapObject> tmp30;
    TNode<Object> tmp31;
    ca_.Bind(&block10, &tmp29, &tmp30, &tmp31);
  }

  if (block14.is_used()) {
    TNode<Context> tmp32;
    TNode<HeapObject> tmp33;
    TNode<Object> tmp34;
    TNode<HeapObject> tmp35;
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    ca_.Bind(&block14, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block13, tmp32, tmp33, tmp34, tmp37);
  }

  if (block15.is_used()) {
    TNode<Context> tmp38;
    TNode<HeapObject> tmp39;
    TNode<Object> tmp40;
    TNode<PromiseCapability> tmp41;
    TNode<PromiseCapability> tmp42;
    TNode<PromiseCapability> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block15, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    ca_.Goto(&block13, tmp38, tmp39, tmp40, tmp44);
  }

  if (block16.is_used()) {
    TNode<Context> tmp45;
    TNode<HeapObject> tmp46;
    TNode<Object> tmp47;
    TNode<PromiseCapability> tmp48;
    TNode<Object> tmp49;
    TNode<Context> tmp50;
    TNode<Object> tmp51;
    ca_.Bind(&block16, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    ca_.Goto(&block13, tmp45, tmp46, tmp47, tmp51);
  }

  if (block17.is_used()) {
    TNode<Context> tmp52;
    TNode<HeapObject> tmp53;
    TNode<Object> tmp54;
    TNode<PromiseCapability> tmp55;
    TNode<JSReceiver> tmp56;
    TNode<Context> tmp57;
    TNode<JSReceiver> tmp58;
    TNode<Oddball> tmp59;
    TNode<Object> tmp60;
    TNode<Object> tmp61;
    ca_.Bind(&block17, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block13, tmp52, tmp53, tmp54, tmp61);
  }

  if (block13.is_used()) {
    TNode<Context> tmp62;
    TNode<HeapObject> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block13, &tmp62, &tmp63, &tmp64, &tmp65);
    TNode<Object> tmp66;
    tmp66 = CodeStubAssembler(state_).CallRuntime(Runtime::kReportMessage, tmp62, tmp65); 
    USE(tmp66);
    ca_.Goto(&block1, tmp62, tmp63, tmp64, tmp66);
  }

  if (block3.is_used()) {
    TNode<Context> tmp67;
    TNode<HeapObject> tmp68;
    TNode<Object> tmp69;
    ca_.Bind(&block3, &tmp67, &tmp68, &tmp69);
    TNode<BoolT> tmp70;
    USE(tmp70);
    tmp70 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp70});
    TNode<Oddball> tmp71;
    USE(tmp71);
    tmp71 = Undefined_0(state_);
    TNode<Object> tmp72;
    tmp72 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseRejectReactionJob, tmp67, tmp69, tmp71, tmp68);
    USE(tmp72);
    ca_.Goto(&block1, tmp67, tmp68, tmp69, tmp72);
  }

  if (block1.is_used()) {
    TNode<Context> tmp73;
    TNode<HeapObject> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block1, &tmp73, &tmp74, &tmp75, &tmp76);
    ca_.Goto(&block18, tmp73, tmp74, tmp75, tmp76);
  }

    TNode<Context> tmp77;
    TNode<HeapObject> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    ca_.Bind(&block18, &tmp77, &tmp78, &tmp79, &tmp80);
  return TNode<Object>{tmp80};
}

TNode<Object> FuflfillPromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Object> p_result, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability, JSReceiver, Context, JSReceiver, Oddball, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promiseOrCapability, p_result);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsJSPromise(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<HeapObject> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<JSPromise> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp4}, TNode<Object>{tmp5});
    TNode<Object> tmp8;
    tmp8 = CodeStubAssembler(state_).CallBuiltin(Builtins::kResolvePromise, tmp4, tmp7, tmp6);
    USE(tmp8);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp8);
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11);
    TNode<PromiseCapability> tmp12;
    USE(tmp12);
    tmp12 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp9}, TNode<Object>{tmp10});
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp14 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp12, tmp13});
    TNode<JSReceiver> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp9}, TNode<Object>{tmp14});
    TNode<Oddball> tmp16;
    USE(tmp16);
    tmp16 = Undefined_0(state_);
    TNode<Object> tmp17;
    USE(tmp17);
    compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch18__label);
    tmp17 = CodeStubAssembler(state_).Call(TNode<Context>{tmp9}, TNode<Object>{tmp15}, TNode<Object>{tmp16}, TNode<Object>{tmp11});
    }
    if (catch18__label.is_used()) {
      compiler::CodeAssemblerLabel catch18_skip(&ca_);
      ca_.Goto(&catch18_skip);
      TNode<Object> catch18_exception_object;
      ca_.Bind(&catch18__label, &catch18_exception_object);
      ca_.Goto(&block11, tmp9, tmp10, tmp11, tmp12, tmp15, tmp9, tmp15, tmp16, tmp11, catch18_exception_object);
      ca_.Bind(&catch18_skip);
    }
    ca_.Goto(&block1, tmp9, tmp10, tmp11, tmp17);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<HeapObject> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsPromiseCapability(promiseOrCapability)' failed", "src/builtins/promise-reaction-job.tq", 64);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<HeapObject> tmp23;
    TNode<Object> tmp24;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24);
  }

  if (block11.is_used()) {
    TNode<Context> tmp25;
    TNode<HeapObject> tmp26;
    TNode<Object> tmp27;
    TNode<PromiseCapability> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Context> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Oddball> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block11, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = RejectPromiseReactionJob_0(state_, TNode<Context>{tmp25}, TNode<HeapObject>{tmp26}, TNode<Object>{tmp34}, p_reactionType);
    ca_.Goto(&block1, tmp25, tmp26, tmp27, tmp35);
  }

  if (block1.is_used()) {
    TNode<Context> tmp36;
    TNode<HeapObject> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    ca_.Bind(&block1, &tmp36, &tmp37, &tmp38, &tmp39);
    ca_.Goto(&block12, tmp36, tmp37, tmp38, tmp39);
  }

    TNode<Context> tmp40;
    TNode<HeapObject> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    ca_.Bind(&block12, &tmp40, &tmp41, &tmp42, &tmp43);
  return TNode<Object>{tmp43};
}

TNode<Object> PromiseReactionJob_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Context, HeapObject, Context, Object> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Context, JSReceiver, Oddball, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object, HeapObject, Oddball, Object> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object, Context, HeapObject, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_argument, p_handler, p_promiseOrCapability);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
      ca_.Goto(&block5, tmp6, tmp7, tmp8, tmp9);
    } else {
      ca_.Goto(&block6, tmp6, tmp7, tmp8, tmp9);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = FuflfillPromiseReactionJob_0(state_, TNode<Context>{tmp10}, TNode<HeapObject>{tmp13}, TNode<Object>{tmp11}, p_reactionType);
    ca_.Goto(&block1, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block6.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp19});
    TNode<Object> tmp20;
    USE(tmp20);
    tmp20 = RejectPromiseReactionJob_0(state_, TNode<Context>{tmp15}, TNode<HeapObject>{tmp18}, TNode<Object>{tmp16}, p_reactionType);
    ca_.Goto(&block1, tmp15, tmp16, tmp17, tmp18, tmp20);
  }

  if (block3.is_used()) {
    TNode<Context> tmp21;
    TNode<Object> tmp22;
    TNode<HeapObject> tmp23;
    TNode<HeapObject> tmp24;
    ca_.Bind(&block3, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<JSReceiver> tmp25;
    USE(tmp25);
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp21}, TNode<Object>{tmp23});
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      TNode<Object> catch26_exception_object;
      ca_.Bind(&catch26__label, &catch26_exception_object);
      ca_.Goto(&block10, tmp21, tmp22, tmp23, tmp24, tmp21, tmp23, tmp21, catch26_exception_object);
      ca_.Bind(&catch26_skip);
    }
    TNode<Oddball> tmp27;
    USE(tmp27);
    tmp27 = Undefined_0(state_);
    TNode<Object> tmp28;
    USE(tmp28);
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch29__label);
    tmp28 = CodeStubAssembler(state_).Call(TNode<Context>{tmp21}, TNode<Object>{tmp25}, TNode<Object>{tmp27}, TNode<Object>{tmp22});
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      TNode<Object> catch29_exception_object;
      ca_.Bind(&catch29__label, &catch29_exception_object);
      ca_.Goto(&block11, tmp21, tmp22, tmp23, tmp24, tmp21, tmp25, tmp27, tmp22, catch29_exception_object);
      ca_.Bind(&catch29_skip);
    }
    TNode<Oddball> tmp30;
    USE(tmp30);
    tmp30 = Undefined_0(state_);
    TNode<BoolT> tmp31;
    USE(tmp31);
    compiler::CodeAssemblerExceptionHandlerLabel catch32__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch32__label);
    tmp31 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp24}, TNode<HeapObject>{tmp30});
    }
    if (catch32__label.is_used()) {
      compiler::CodeAssemblerLabel catch32_skip(&ca_);
      ca_.Goto(&catch32_skip);
      TNode<Object> catch32_exception_object;
      ca_.Bind(&catch32__label, &catch32_exception_object);
      ca_.Goto(&block14, tmp21, tmp22, tmp23, tmp24, tmp28, tmp24, tmp30, catch32_exception_object);
      ca_.Bind(&catch32_skip);
    }
    ca_.Branch(tmp31, &block12, &block13, tmp21, tmp22, tmp23, tmp24, tmp28);
  }

  if (block10.is_used()) {
    TNode<Context> tmp33;
    TNode<Object> tmp34;
    TNode<HeapObject> tmp35;
    TNode<HeapObject> tmp36;
    TNode<Context> tmp37;
    TNode<HeapObject> tmp38;
    TNode<Context> tmp39;
    TNode<Object> tmp40;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block9, tmp33, tmp34, tmp35, tmp36, tmp40);
  }

  if (block11.is_used()) {
    TNode<Context> tmp41;
    TNode<Object> tmp42;
    TNode<HeapObject> tmp43;
    TNode<HeapObject> tmp44;
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<Oddball> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block11, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    ca_.Goto(&block9, tmp41, tmp42, tmp43, tmp44, tmp49);
  }

  if (block14.is_used()) {
    TNode<Context> tmp50;
    TNode<Object> tmp51;
    TNode<HeapObject> tmp52;
    TNode<HeapObject> tmp53;
    TNode<Object> tmp54;
    TNode<HeapObject> tmp55;
    TNode<Oddball> tmp56;
    TNode<Object> tmp57;
    ca_.Bind(&block14, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    ca_.Goto(&block9, tmp50, tmp51, tmp52, tmp53, tmp57);
  }

  if (block12.is_used()) {
    TNode<Context> tmp58;
    TNode<Object> tmp59;
    TNode<HeapObject> tmp60;
    TNode<HeapObject> tmp61;
    TNode<Object> tmp62;
    ca_.Bind(&block12, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<Oddball> tmp63;
    USE(tmp63);
    tmp63 = Undefined_0(state_);
    ca_.Goto(&block1, tmp58, tmp59, tmp60, tmp61, tmp63);
  }

  if (block13.is_used()) {
    TNode<Context> tmp64;
    TNode<Object> tmp65;
    TNode<HeapObject> tmp66;
    TNode<HeapObject> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block13, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    TNode<Object> tmp69;
    USE(tmp69);
    compiler::CodeAssemblerExceptionHandlerLabel catch70__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch70__label);
    tmp69 = FuflfillPromiseReactionJob_0(state_, TNode<Context>{tmp64}, TNode<HeapObject>{tmp67}, TNode<Object>{tmp68}, p_reactionType);
    }
    if (catch70__label.is_used()) {
      compiler::CodeAssemblerLabel catch70_skip(&ca_);
      ca_.Goto(&catch70_skip);
      TNode<Object> catch70_exception_object;
      ca_.Bind(&catch70__label, &catch70_exception_object);
      ca_.Goto(&block16, tmp64, tmp65, tmp66, tmp67, tmp68, tmp64, tmp67, tmp68, catch70_exception_object);
      ca_.Bind(&catch70_skip);
    }
    ca_.Goto(&block1, tmp64, tmp65, tmp66, tmp67, tmp69);
  }

  if (block16.is_used()) {
    TNode<Context> tmp71;
    TNode<Object> tmp72;
    TNode<HeapObject> tmp73;
    TNode<HeapObject> tmp74;
    TNode<Object> tmp75;
    TNode<Context> tmp76;
    TNode<HeapObject> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    ca_.Bind(&block16, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    ca_.Goto(&block9, tmp71, tmp72, tmp73, tmp74, tmp79);
  }

  if (block9.is_used()) {
    TNode<Context> tmp80;
    TNode<Object> tmp81;
    TNode<HeapObject> tmp82;
    TNode<HeapObject> tmp83;
    TNode<Object> tmp84;
    ca_.Bind(&block9, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<Object> tmp85;
    USE(tmp85);
    tmp85 = RejectPromiseReactionJob_0(state_, TNode<Context>{tmp80}, TNode<HeapObject>{tmp83}, TNode<Object>{tmp84}, p_reactionType);
    ca_.Goto(&block1, tmp80, tmp81, tmp82, tmp83, tmp85);
  }

  if (block1.is_used()) {
    TNode<Context> tmp86;
    TNode<Object> tmp87;
    TNode<HeapObject> tmp88;
    TNode<HeapObject> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block1, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block17, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

    TNode<Context> tmp91;
    TNode<Object> tmp92;
    TNode<HeapObject> tmp93;
    TNode<HeapObject> tmp94;
    TNode<Object> tmp95;
    ca_.Bind(&block17, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
  return TNode<Object>{tmp95};
}

TF_BUILTIN(PromiseFulfillReactionJob, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<HeapObject> parameter2 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<HeapObject> parameter3 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = PromiseReactionJob_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp3}, PromiseReaction::kFulfill);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseRejectReactionJob, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<HeapObject> parameter2 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<HeapObject> parameter3 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = PromiseReactionJob_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp3}, PromiseReaction::kReject);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

}  // namespace internal
}  // namespace v8

