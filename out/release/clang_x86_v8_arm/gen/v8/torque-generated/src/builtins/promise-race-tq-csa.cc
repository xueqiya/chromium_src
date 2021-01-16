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

TNode<Symbol> kPromiseForwardingHandlerSymbol_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Symbol> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).PromiseForwardingHandlerSymbolConstant();
return TNode<Symbol>{tmp0};
}

TNode<Symbol> kPromiseHandledBySymbol_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Symbol> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).PromiseHandledBySymbolConstant();
return TNode<Symbol>{tmp0};
}

TNode<String> kResolveString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).ResolveStringConstant();
return TNode<String>{tmp0};
}

TNode<BoolT> IsPromiseResolveLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_constructor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, JSFunction, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, JSFunction, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, JSFunction, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_constructor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<JSReceiver> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<NativeContext> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<NativeContext> tmp9;
    TNode<JSReceiver> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp9}, TNode<IntPtrT>{tmp11});
    TNode<JSFunction> tmp13;
    USE(tmp13);
    tmp13 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp12});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp13}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp14, &block4, &block5, tmp8, tmp9, tmp10, tmp13, tmp14);
  }

  if (block4.is_used()) {
    TNode<Context> tmp15;
    TNode<NativeContext> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<JSFunction> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).IsPromiseResolveProtectorCellInvalid();
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp20});
    ca_.Goto(&block6, tmp15, tmp16, tmp17, tmp18, tmp19, tmp21);
  }

  if (block5.is_used()) {
    TNode<Context> tmp22;
    TNode<NativeContext> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<JSFunction> tmp25;
    TNode<BoolT> tmp26;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
  }

  if (block6.is_used()) {
    TNode<Context> tmp28;
    TNode<NativeContext> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<JSFunction> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block1, tmp28, tmp29, tmp30, tmp33);
  }

  if (block1.is_used()) {
    TNode<Context> tmp34;
    TNode<NativeContext> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block1, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block7, tmp34, tmp35, tmp36, tmp37);
  }

    TNode<Context> tmp38;
    TNode<NativeContext> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<BoolT> tmp41;
    ca_.Bind(&block7, &tmp38, &tmp39, &tmp40, &tmp41);
  return TNode<BoolT>{tmp41};
}

TF_BUILTIN(PromiseRace, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, Object, Context, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, Context, Object> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, NativeContext, JSReceiver, Context, Object> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, BoolT, Object> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, JSReceiver, String, Context, Object> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Object, Object, Context, Object> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Object, Object, Context> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Object, Object, Context, JSReceiver> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Object, Context, Object> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, NativeContext, NativeContext, Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, NativeContext, Object> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Object, Context, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, Object, Map, Context, Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, Object, Map, Context> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, Object, Map, Context, JSReceiver> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, JSReceiver, Map, Context, Object> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, Context, Object> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, JSReceiver, Object, Object, Context, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, String, Context, Object> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Context, Object, Object, Object, Context, Object> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Context, Object, Object, Object, Object, Context, Object> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Context, Object, Object, Object, Object, Object> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, Object> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT, HeapObject, Context, Object> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT, BoolT, Object> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, BoolT, BoolT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object, Context, Object, Symbol, HeapObject, Object> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map, Object, Object, Object, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, NativeContext, Object, Map> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, JSReceiver, Object, Object, JSReceiver, Object, Object, Context, Object> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Object, HeapObject, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "Promise.race");
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = False_0(state_);
    TNode<PromiseCapability> tmp16;
    tmp16 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp9, tmp14, tmp15));
    USE(tmp16);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp18 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp16, tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp20 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp16, tmp19});
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp22 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp16, tmp21});
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp23, &block5, &block6, tmp9, tmp10, tmp11, tmp14, tmp16, tmp18, tmp20, tmp22);
  }

  if (block5.is_used()) {
    TNode<Context> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<JSReceiver> tmp27;
    TNode<PromiseCapability> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<HeapObject> tmp31;
    ca_.Bind(&block5, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<Symbol> tmp32;
    USE(tmp32);
    tmp32 = kPromiseForwardingHandlerSymbol_0(state_);
    TNode<Oddball> tmp33;
    USE(tmp33);
    tmp33 = True_0(state_);
    TNode<Object> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp24}, TNode<Object>{tmp30}, TNode<Object>{tmp32}, TNode<Object>{tmp33});
    ca_.Goto(&block6, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31);
  }

  if (block6.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<PromiseCapability> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<HeapObject> tmp42;
    ca_.Bind(&block6, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<JSReceiver> tmp43;
    USE(tmp43);
    TNode<Object> tmp44;
    USE(tmp44);
    compiler::CodeAssemblerExceptionHandlerLabel catch45__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch45__label);
    std::tie(tmp43, tmp44) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp35}, TNode<Object>{tmp37}).Flatten();
    }
    if (catch45__label.is_used()) {
      compiler::CodeAssemblerLabel catch45_skip(&ca_);
      ca_.Goto(&catch45_skip);
      TNode<Object> catch45_exception_object;
      ca_.Bind(&catch45__label, &catch45_exception_object);
      ca_.Goto(&block11, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, ca_.Uninitialized<JSReceiver>(), ca_.Uninitialized<Object>(), tmp37, tmp35, catch45_exception_object);
      ca_.Bind(&catch45_skip);
    }
    TNode<NativeContext> tmp46;
    USE(tmp46);
    compiler::CodeAssemblerExceptionHandlerLabel catch47__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch47__label);
    tmp46 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp35});
    }
    if (catch47__label.is_used()) {
      compiler::CodeAssemblerLabel catch47_skip(&ca_);
      ca_.Goto(&catch47_skip);
      TNode<Object> catch47_exception_object;
      ca_.Bind(&catch47__label, &catch47_exception_object);
      ca_.Goto(&block14, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp35, catch47_exception_object);
      ca_.Bind(&catch47_skip);
    }
    TNode<Oddball> tmp48;
    USE(tmp48);
    tmp48 = Undefined_0(state_);
    TNode<BoolT> tmp49;
    USE(tmp49);
    compiler::CodeAssemblerExceptionHandlerLabel catch50__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch50__label);
    tmp49 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{tmp35}, TNode<NativeContext>{tmp46}, TNode<JSReceiver>{tmp38});
    }
    if (catch50__label.is_used()) {
      compiler::CodeAssemblerLabel catch50_skip(&ca_);
      ca_.Goto(&catch50_skip);
      TNode<Object> catch50_exception_object;
      ca_.Bind(&catch50__label, &catch50_exception_object);
      ca_.Goto(&block17, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp46, tmp48, tmp46, tmp38, tmp35, catch50_exception_object);
      ca_.Bind(&catch50_skip);
    }
    TNode<BoolT> tmp51;
    USE(tmp51);
    compiler::CodeAssemblerExceptionHandlerLabel catch52__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch52__label);
    tmp51 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp49});
    }
    if (catch52__label.is_used()) {
      compiler::CodeAssemblerLabel catch52_skip(&ca_);
      ca_.Goto(&catch52_skip);
      TNode<Object> catch52_exception_object;
      ca_.Bind(&catch52__label, &catch52_exception_object);
      ca_.Goto(&block18, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp46, tmp48, tmp49, catch52_exception_object);
      ca_.Bind(&catch52_skip);
    }
    ca_.Branch(tmp51, &block15, &block16, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp46, tmp48);
  }

  if (block11.is_used()) {
    TNode<Context> tmp53;
    TNode<Object> tmp54;
    TNode<Object> tmp55;
    TNode<JSReceiver> tmp56;
    TNode<PromiseCapability> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<HeapObject> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Context> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block11, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block8, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp65);
  }

  if (block14.is_used()) {
    TNode<Context> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<JSReceiver> tmp69;
    TNode<PromiseCapability> tmp70;
    TNode<Object> tmp71;
    TNode<Object> tmp72;
    TNode<HeapObject> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Object> tmp75;
    TNode<Context> tmp76;
    TNode<Object> tmp77;
    ca_.Bind(&block14, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    ca_.Goto(&block13, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp77);
  }

  if (block17.is_used()) {
    TNode<Context> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<PromiseCapability> tmp82;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<HeapObject> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<Object> tmp87;
    TNode<NativeContext> tmp88;
    TNode<Object> tmp89;
    TNode<NativeContext> tmp90;
    TNode<JSReceiver> tmp91;
    TNode<Context> tmp92;
    TNode<Object> tmp93;
    ca_.Bind(&block17, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    ca_.Goto(&block13, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp93);
  }

  if (block18.is_used()) {
    TNode<Context> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<JSReceiver> tmp97;
    TNode<PromiseCapability> tmp98;
    TNode<Object> tmp99;
    TNode<Object> tmp100;
    TNode<HeapObject> tmp101;
    TNode<JSReceiver> tmp102;
    TNode<Object> tmp103;
    TNode<NativeContext> tmp104;
    TNode<Object> tmp105;
    TNode<BoolT> tmp106;
    TNode<Object> tmp107;
    ca_.Bind(&block18, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    ca_.Goto(&block13, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp107);
  }

  if (block15.is_used()) {
    TNode<Context> tmp108;
    TNode<Object> tmp109;
    TNode<Object> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<PromiseCapability> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<HeapObject> tmp115;
    TNode<JSReceiver> tmp116;
    TNode<Object> tmp117;
    TNode<NativeContext> tmp118;
    TNode<Object> tmp119;
    ca_.Bind(&block15, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119);
    TNode<String> tmp120;
    USE(tmp120);
    tmp120 = kResolveString_0(state_);
    TNode<Object> tmp121;
    USE(tmp121);
    compiler::CodeAssemblerExceptionHandlerLabel catch122__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch122__label);
    tmp121 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp108}, TNode<Object>{tmp111}, TNode<Object>{tmp120});
    }
    if (catch122__label.is_used()) {
      compiler::CodeAssemblerLabel catch122_skip(&ca_);
      ca_.Goto(&catch122_skip);
      TNode<Object> catch122_exception_object;
      ca_.Bind(&catch122__label, &catch122_exception_object);
      ca_.Goto(&block19, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp111, tmp120, tmp108, catch122_exception_object);
      ca_.Bind(&catch122_skip);
    }
    TNode<JSReceiver> tmp123;
    USE(tmp123);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch124__label);
    tmp123 = Cast_Callable_1(state_, TNode<Context>{tmp108}, TNode<Object>{tmp121}, &label0);
    }
    if (catch124__label.is_used()) {
      compiler::CodeAssemblerLabel catch124_skip(&ca_);
      ca_.Goto(&catch124_skip);
      TNode<Object> catch124_exception_object;
      ca_.Bind(&catch124__label, &catch124_exception_object);
      ca_.Goto(&block24, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp121, tmp121, tmp108, catch124_exception_object);
      ca_.Bind(&catch124_skip);
    }
    ca_.Goto(&block22, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp121, tmp121, tmp108, tmp123);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block23, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp121, tmp121, tmp108);
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp125;
    TNode<Object> tmp126;
    TNode<Object> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<PromiseCapability> tmp129;
    TNode<Object> tmp130;
    TNode<Object> tmp131;
    TNode<HeapObject> tmp132;
    TNode<JSReceiver> tmp133;
    TNode<Object> tmp134;
    TNode<NativeContext> tmp135;
    TNode<Object> tmp136;
    TNode<JSReceiver> tmp137;
    TNode<String> tmp138;
    TNode<Context> tmp139;
    TNode<Object> tmp140;
    ca_.Bind(&block19, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    ca_.Goto(&block13, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp140);
  }

  if (block24.is_used()) {
    TNode<Context> tmp141;
    TNode<Object> tmp142;
    TNode<Object> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<PromiseCapability> tmp145;
    TNode<Object> tmp146;
    TNode<Object> tmp147;
    TNode<HeapObject> tmp148;
    TNode<JSReceiver> tmp149;
    TNode<Object> tmp150;
    TNode<NativeContext> tmp151;
    TNode<Object> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Context> tmp155;
    TNode<Object> tmp156;
    ca_.Bind(&block24, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    ca_.Goto(&block13, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp156);
  }

  if (block23.is_used()) {
    TNode<Context> tmp157;
    TNode<Object> tmp158;
    TNode<Object> tmp159;
    TNode<JSReceiver> tmp160;
    TNode<PromiseCapability> tmp161;
    TNode<Object> tmp162;
    TNode<Object> tmp163;
    TNode<HeapObject> tmp164;
    TNode<JSReceiver> tmp165;
    TNode<Object> tmp166;
    TNode<NativeContext> tmp167;
    TNode<Object> tmp168;
    TNode<Object> tmp169;
    TNode<Object> tmp170;
    TNode<Context> tmp171;
    ca_.Bind(&block23, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171);
    compiler::CodeAssemblerExceptionHandlerLabel catch172__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch172__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp157}, MessageTemplate::kCalledNonCallable, "resolve");
    }
    if (catch172__label.is_used()) {
      compiler::CodeAssemblerLabel catch172_skip(&ca_);
      TNode<Object> catch172_exception_object;
      ca_.Bind(&catch172__label, &catch172_exception_object);
      ca_.Goto(&block25, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp157, catch172_exception_object);
    }
  }

  if (block22.is_used()) {
    TNode<Context> tmp173;
    TNode<Object> tmp174;
    TNode<Object> tmp175;
    TNode<JSReceiver> tmp176;
    TNode<PromiseCapability> tmp177;
    TNode<Object> tmp178;
    TNode<Object> tmp179;
    TNode<HeapObject> tmp180;
    TNode<JSReceiver> tmp181;
    TNode<Object> tmp182;
    TNode<NativeContext> tmp183;
    TNode<Object> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp186;
    TNode<Context> tmp187;
    TNode<JSReceiver> tmp188;
    ca_.Bind(&block22, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
    ca_.Goto(&block16, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp188);
  }

  if (block25.is_used()) {
    TNode<Context> tmp189;
    TNode<Object> tmp190;
    TNode<Object> tmp191;
    TNode<JSReceiver> tmp192;
    TNode<PromiseCapability> tmp193;
    TNode<Object> tmp194;
    TNode<Object> tmp195;
    TNode<HeapObject> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<Object> tmp198;
    TNode<NativeContext> tmp199;
    TNode<Object> tmp200;
    TNode<Object> tmp201;
    TNode<Context> tmp202;
    TNode<Object> tmp203;
    ca_.Bind(&block25, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203);
    ca_.Goto(&block13, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp203);
  }

  if (block16.is_used()) {
    TNode<Context> tmp204;
    TNode<Object> tmp205;
    TNode<Object> tmp206;
    TNode<JSReceiver> tmp207;
    TNode<PromiseCapability> tmp208;
    TNode<Object> tmp209;
    TNode<Object> tmp210;
    TNode<HeapObject> tmp211;
    TNode<JSReceiver> tmp212;
    TNode<Object> tmp213;
    TNode<NativeContext> tmp214;
    TNode<Object> tmp215;
    ca_.Bind(&block16, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215);
    TNode<IntPtrT> tmp216;
    USE(tmp216);
    compiler::CodeAssemblerExceptionHandlerLabel catch217__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch217__label);
    tmp216 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    }
    if (catch217__label.is_used()) {
      compiler::CodeAssemblerLabel catch217_skip(&ca_);
      ca_.Goto(&catch217_skip);
      TNode<Object> catch217_exception_object;
      ca_.Bind(&catch217__label, &catch217_exception_object);
      ca_.Goto(&block26, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp214, tmp214, catch217_exception_object);
      ca_.Bind(&catch217_skip);
    }
    TNode<Object> tmp218;
    USE(tmp218);
    compiler::CodeAssemblerExceptionHandlerLabel catch219__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch219__label);
    tmp218 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp214}, TNode<IntPtrT>{tmp216});
    }
    if (catch219__label.is_used()) {
      compiler::CodeAssemblerLabel catch219_skip(&ca_);
      ca_.Goto(&catch219_skip);
      TNode<Object> catch219_exception_object;
      ca_.Bind(&catch219__label, &catch219_exception_object);
      ca_.Goto(&block27, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp214, catch219_exception_object);
      ca_.Bind(&catch219_skip);
    }
    TNode<Map> tmp220;
    USE(tmp220);
    compiler::CodeAssemblerExceptionHandlerLabel catch221__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch221__label);
    tmp220 = UnsafeCast_Map_0(state_, TNode<Context>{tmp204}, TNode<Object>{tmp218});
    }
    if (catch221__label.is_used()) {
      compiler::CodeAssemblerLabel catch221_skip(&ca_);
      ca_.Goto(&catch221_skip);
      TNode<Object> catch221_exception_object;
      ca_.Bind(&catch221__label, &catch221_exception_object);
      ca_.Goto(&block28, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp218, tmp204, catch221_exception_object);
      ca_.Bind(&catch221_skip);
    }
    ca_.Goto(&block31, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp220);
  }

  if (block26.is_used()) {
    TNode<Context> tmp222;
    TNode<Object> tmp223;
    TNode<Object> tmp224;
    TNode<JSReceiver> tmp225;
    TNode<PromiseCapability> tmp226;
    TNode<Object> tmp227;
    TNode<Object> tmp228;
    TNode<HeapObject> tmp229;
    TNode<JSReceiver> tmp230;
    TNode<Object> tmp231;
    TNode<NativeContext> tmp232;
    TNode<Object> tmp233;
    TNode<NativeContext> tmp234;
    TNode<NativeContext> tmp235;
    TNode<Object> tmp236;
    ca_.Bind(&block26, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236);
    ca_.Goto(&block13, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp236);
  }

  if (block27.is_used()) {
    TNode<Context> tmp237;
    TNode<Object> tmp238;
    TNode<Object> tmp239;
    TNode<JSReceiver> tmp240;
    TNode<PromiseCapability> tmp241;
    TNode<Object> tmp242;
    TNode<Object> tmp243;
    TNode<HeapObject> tmp244;
    TNode<JSReceiver> tmp245;
    TNode<Object> tmp246;
    TNode<NativeContext> tmp247;
    TNode<Object> tmp248;
    TNode<NativeContext> tmp249;
    TNode<Object> tmp250;
    ca_.Bind(&block27, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250);
    ca_.Goto(&block13, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp250);
  }

  if (block28.is_used()) {
    TNode<Context> tmp251;
    TNode<Object> tmp252;
    TNode<Object> tmp253;
    TNode<JSReceiver> tmp254;
    TNode<PromiseCapability> tmp255;
    TNode<Object> tmp256;
    TNode<Object> tmp257;
    TNode<HeapObject> tmp258;
    TNode<JSReceiver> tmp259;
    TNode<Object> tmp260;
    TNode<NativeContext> tmp261;
    TNode<Object> tmp262;
    TNode<Object> tmp263;
    TNode<Context> tmp264;
    TNode<Object> tmp265;
    ca_.Bind(&block28, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265);
    ca_.Goto(&block13, tmp251, tmp252, tmp253, tmp254, tmp255, tmp256, tmp257, tmp258, tmp259, tmp260, tmp265);
  }

  if (block31.is_used()) {
    TNode<Context> tmp266;
    TNode<Object> tmp267;
    TNode<Object> tmp268;
    TNode<JSReceiver> tmp269;
    TNode<PromiseCapability> tmp270;
    TNode<Object> tmp271;
    TNode<Object> tmp272;
    TNode<HeapObject> tmp273;
    TNode<JSReceiver> tmp274;
    TNode<Object> tmp275;
    TNode<NativeContext> tmp276;
    TNode<Object> tmp277;
    TNode<Map> tmp278;
    ca_.Bind(&block31, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278);
    TNode<BoolT> tmp279;
    USE(tmp279);
    compiler::CodeAssemblerExceptionHandlerLabel catch280__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch280__label);
    tmp279 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch280__label.is_used()) {
      compiler::CodeAssemblerLabel catch280_skip(&ca_);
      ca_.Goto(&catch280_skip);
      TNode<Object> catch280_exception_object;
      ca_.Bind(&catch280__label, &catch280_exception_object);
      ca_.Goto(&block32, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276, tmp277, tmp278, catch280_exception_object);
      ca_.Bind(&catch280_skip);
    }
    ca_.Branch(tmp279, &block29, &block30, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276, tmp277, tmp278);
  }

  if (block32.is_used()) {
    TNode<Context> tmp281;
    TNode<Object> tmp282;
    TNode<Object> tmp283;
    TNode<JSReceiver> tmp284;
    TNode<PromiseCapability> tmp285;
    TNode<Object> tmp286;
    TNode<Object> tmp287;
    TNode<HeapObject> tmp288;
    TNode<JSReceiver> tmp289;
    TNode<Object> tmp290;
    TNode<NativeContext> tmp291;
    TNode<Object> tmp292;
    TNode<Map> tmp293;
    TNode<Object> tmp294;
    ca_.Bind(&block32, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294);
    ca_.Goto(&block13, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290, tmp294);
  }

  if (block29.is_used()) {
    TNode<Context> tmp295;
    TNode<Object> tmp296;
    TNode<Object> tmp297;
    TNode<JSReceiver> tmp298;
    TNode<PromiseCapability> tmp299;
    TNode<Object> tmp300;
    TNode<Object> tmp301;
    TNode<HeapObject> tmp302;
    TNode<JSReceiver> tmp303;
    TNode<Object> tmp304;
    TNode<NativeContext> tmp305;
    TNode<Object> tmp306;
    TNode<Map> tmp307;
    ca_.Bind(&block29, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307);
    TNode<JSReceiver> tmp308;
    USE(tmp308);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch309__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch309__label);
    tmp308 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp295}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp303}, TNode<Object>{tmp304}}, TNode<Map>{tmp307}, &label0);
    }
    if (catch309__label.is_used()) {
      compiler::CodeAssemblerLabel catch309_skip(&ca_);
      ca_.Goto(&catch309_skip);
      TNode<Object> catch309_exception_object;
      ca_.Bind(&catch309__label, &catch309_exception_object);
      ca_.Goto(&block39, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, ca_.Uninitialized<Object>(), tmp303, tmp304, tmp307, tmp295, catch309_exception_object);
      ca_.Bind(&catch309_skip);
    }
    ca_.Goto(&block37, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, ca_.Uninitialized<Object>(), tmp303, tmp304, tmp307, tmp295, tmp308);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block38, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, ca_.Uninitialized<Object>(), tmp303, tmp304, tmp307, tmp295);
    }
  }

  if (block39.is_used()) {
    TNode<Context> tmp310;
    TNode<Object> tmp311;
    TNode<Object> tmp312;
    TNode<JSReceiver> tmp313;
    TNode<PromiseCapability> tmp314;
    TNode<Object> tmp315;
    TNode<Object> tmp316;
    TNode<HeapObject> tmp317;
    TNode<JSReceiver> tmp318;
    TNode<Object> tmp319;
    TNode<NativeContext> tmp320;
    TNode<Object> tmp321;
    TNode<Map> tmp322;
    TNode<Object> tmp323;
    TNode<JSReceiver> tmp324;
    TNode<Object> tmp325;
    TNode<Map> tmp326;
    TNode<Context> tmp327;
    TNode<Object> tmp328;
    ca_.Bind(&block39, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328);
    ca_.Goto(&block34, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp320, tmp321, tmp322, tmp323, tmp328);
  }

  if (block38.is_used()) {
    TNode<Context> tmp329;
    TNode<Object> tmp330;
    TNode<Object> tmp331;
    TNode<JSReceiver> tmp332;
    TNode<PromiseCapability> tmp333;
    TNode<Object> tmp334;
    TNode<Object> tmp335;
    TNode<HeapObject> tmp336;
    TNode<JSReceiver> tmp337;
    TNode<Object> tmp338;
    TNode<NativeContext> tmp339;
    TNode<Object> tmp340;
    TNode<Map> tmp341;
    TNode<Object> tmp342;
    TNode<JSReceiver> tmp343;
    TNode<Object> tmp344;
    TNode<Map> tmp345;
    TNode<Context> tmp346;
    ca_.Bind(&block38, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346);
    CodeStubAssembler(state_).Return(tmp336);
  }

  if (block37.is_used()) {
    TNode<Context> tmp347;
    TNode<Object> tmp348;
    TNode<Object> tmp349;
    TNode<JSReceiver> tmp350;
    TNode<PromiseCapability> tmp351;
    TNode<Object> tmp352;
    TNode<Object> tmp353;
    TNode<HeapObject> tmp354;
    TNode<JSReceiver> tmp355;
    TNode<Object> tmp356;
    TNode<NativeContext> tmp357;
    TNode<Object> tmp358;
    TNode<Map> tmp359;
    TNode<Object> tmp360;
    TNode<JSReceiver> tmp361;
    TNode<Object> tmp362;
    TNode<Map> tmp363;
    TNode<Context> tmp364;
    TNode<JSReceiver> tmp365;
    ca_.Bind(&block37, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365);
    TNode<Object> tmp366;
    USE(tmp366);
    compiler::CodeAssemblerExceptionHandlerLabel catch367__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch367__label);
    tmp366 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp347}, TNode<JSReceiver>{tmp365}, TNode<Map>{tmp359});
    }
    if (catch367__label.is_used()) {
      compiler::CodeAssemblerLabel catch367_skip(&ca_);
      ca_.Goto(&catch367_skip);
      TNode<Object> catch367_exception_object;
      ca_.Bind(&catch367__label, &catch367_exception_object);
      ca_.Goto(&block40, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp365, tmp365, tmp359, tmp347, catch367_exception_object);
      ca_.Bind(&catch367_skip);
    }
    TNode<JSReceiver> tmp368;
    USE(tmp368);
    compiler::CodeAssemblerExceptionHandlerLabel catch369__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch369__label);
    tmp368 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp347}, TNode<Object>{tmp350});
    }
    if (catch369__label.is_used()) {
      compiler::CodeAssemblerLabel catch369_skip(&ca_);
      ca_.Goto(&catch369_skip);
      TNode<Object> catch369_exception_object;
      ca_.Bind(&catch369__label, &catch369_exception_object);
      ca_.Goto(&block41, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp350, tmp347, catch369_exception_object);
      ca_.Bind(&catch369_skip);
    }
    TNode<Object> tmp370;
    USE(tmp370);
    compiler::CodeAssemblerExceptionHandlerLabel catch371__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch371__label);
    tmp370 = CallResolve_0(state_, TNode<Context>{tmp347}, TNode<JSReceiver>{tmp368}, TNode<Object>{tmp358}, TNode<Object>{tmp366});
    }
    if (catch371__label.is_used()) {
      compiler::CodeAssemblerLabel catch371_skip(&ca_);
      ca_.Goto(&catch371_skip);
      TNode<Object> catch371_exception_object;
      ca_.Bind(&catch371__label, &catch371_exception_object);
      ca_.Goto(&block42, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp368, tmp358, tmp366, tmp347, catch371_exception_object);
      ca_.Bind(&catch371_skip);
    }
    TNode<String> tmp372;
    USE(tmp372);
    tmp372 = kThenString_0(state_);
    TNode<Object> tmp373;
    USE(tmp373);
    compiler::CodeAssemblerExceptionHandlerLabel catch374__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch374__label);
    tmp373 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp347}, TNode<Object>{tmp370}, TNode<Object>{tmp372});
    }
    if (catch374__label.is_used()) {
      compiler::CodeAssemblerLabel catch374_skip(&ca_);
      ca_.Goto(&catch374_skip);
      TNode<Object> catch374_exception_object;
      ca_.Bind(&catch374__label, &catch374_exception_object);
      ca_.Goto(&block43, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp370, tmp372, tmp347, catch374_exception_object);
      ca_.Bind(&catch374_skip);
    }
    TNode<Object> tmp375;
    USE(tmp375);
    compiler::CodeAssemblerExceptionHandlerLabel catch376__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch376__label);
    tmp375 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp347}, TNode<Object>{tmp352});
    }
    if (catch376__label.is_used()) {
      compiler::CodeAssemblerLabel catch376_skip(&ca_);
      ca_.Goto(&catch376_skip);
      TNode<Object> catch376_exception_object;
      ca_.Bind(&catch376__label, &catch376_exception_object);
      ca_.Goto(&block44, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp373, tmp347, tmp373, tmp370, tmp352, tmp347, catch376_exception_object);
      ca_.Bind(&catch376_skip);
    }
    TNode<Object> tmp377;
    USE(tmp377);
    compiler::CodeAssemblerExceptionHandlerLabel catch378__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch378__label);
    tmp377 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp347}, TNode<Object>{tmp353});
    }
    if (catch378__label.is_used()) {
      compiler::CodeAssemblerLabel catch378_skip(&ca_);
      ca_.Goto(&catch378_skip);
      TNode<Object> catch378_exception_object;
      ca_.Bind(&catch378__label, &catch378_exception_object);
      ca_.Goto(&block45, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp373, tmp347, tmp373, tmp370, tmp375, tmp353, tmp347, catch378_exception_object);
      ca_.Bind(&catch378_skip);
    }
    TNode<Object> tmp379;
    USE(tmp379);
    compiler::CodeAssemblerExceptionHandlerLabel catch380__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch380__label);
    tmp379 = CodeStubAssembler(state_).Call(TNode<Context>{tmp347}, TNode<Object>{tmp373}, TNode<Object>{tmp370}, TNode<Object>{tmp375}, TNode<Object>{tmp377});
    }
    if (catch380__label.is_used()) {
      compiler::CodeAssemblerLabel catch380_skip(&ca_);
      ca_.Goto(&catch380_skip);
      TNode<Object> catch380_exception_object;
      ca_.Bind(&catch380__label, &catch380_exception_object);
      ca_.Goto(&block46, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp373, tmp347, tmp373, tmp370, tmp375, tmp377, catch380_exception_object);
      ca_.Bind(&catch380_skip);
    }
    TNode<BoolT> tmp381;
    USE(tmp381);
    compiler::CodeAssemblerExceptionHandlerLabel catch382__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch382__label);
    tmp381 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch382__label.is_used()) {
      compiler::CodeAssemblerLabel catch382_skip(&ca_);
      ca_.Goto(&catch382_skip);
      TNode<Object> catch382_exception_object;
      ca_.Bind(&catch382__label, &catch382_exception_object);
      ca_.Goto(&block49, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp373, tmp379, catch382_exception_object);
      ca_.Bind(&catch382_skip);
    }
    ca_.Branch(tmp381, &block50, &block51, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp366, tmp370, tmp373, tmp379, tmp381);
  }

  if (block40.is_used()) {
    TNode<Context> tmp383;
    TNode<Object> tmp384;
    TNode<Object> tmp385;
    TNode<JSReceiver> tmp386;
    TNode<PromiseCapability> tmp387;
    TNode<Object> tmp388;
    TNode<Object> tmp389;
    TNode<HeapObject> tmp390;
    TNode<JSReceiver> tmp391;
    TNode<Object> tmp392;
    TNode<NativeContext> tmp393;
    TNode<Object> tmp394;
    TNode<Map> tmp395;
    TNode<Object> tmp396;
    TNode<JSReceiver> tmp397;
    TNode<JSReceiver> tmp398;
    TNode<Map> tmp399;
    TNode<Context> tmp400;
    TNode<Object> tmp401;
    ca_.Bind(&block40, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401);
    ca_.Goto(&block34, tmp383, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp392, tmp393, tmp394, tmp395, tmp396, tmp401);
  }

  if (block34.is_used()) {
    TNode<Context> tmp402;
    TNode<Object> tmp403;
    TNode<Object> tmp404;
    TNode<JSReceiver> tmp405;
    TNode<PromiseCapability> tmp406;
    TNode<Object> tmp407;
    TNode<Object> tmp408;
    TNode<HeapObject> tmp409;
    TNode<JSReceiver> tmp410;
    TNode<Object> tmp411;
    TNode<NativeContext> tmp412;
    TNode<Object> tmp413;
    TNode<Map> tmp414;
    TNode<Object> tmp415;
    TNode<Object> tmp416;
    ca_.Bind(&block34, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416);
    ca_.Goto(&block8, tmp402, tmp403, tmp404, tmp405, tmp406, tmp407, tmp408, tmp409, tmp416);
  }

  if (block41.is_used()) {
    TNode<Context> tmp417;
    TNode<Object> tmp418;
    TNode<Object> tmp419;
    TNode<JSReceiver> tmp420;
    TNode<PromiseCapability> tmp421;
    TNode<Object> tmp422;
    TNode<Object> tmp423;
    TNode<HeapObject> tmp424;
    TNode<JSReceiver> tmp425;
    TNode<Object> tmp426;
    TNode<NativeContext> tmp427;
    TNode<Object> tmp428;
    TNode<Map> tmp429;
    TNode<Object> tmp430;
    TNode<JSReceiver> tmp431;
    TNode<Context> tmp432;
    TNode<Object> tmp433;
    ca_.Bind(&block41, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421, &tmp422, &tmp423, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433);
    ca_.Goto(&block13, tmp417, tmp418, tmp419, tmp420, tmp421, tmp422, tmp423, tmp424, tmp425, tmp426, tmp433);
  }

  if (block42.is_used()) {
    TNode<Context> tmp434;
    TNode<Object> tmp435;
    TNode<Object> tmp436;
    TNode<JSReceiver> tmp437;
    TNode<PromiseCapability> tmp438;
    TNode<Object> tmp439;
    TNode<Object> tmp440;
    TNode<HeapObject> tmp441;
    TNode<JSReceiver> tmp442;
    TNode<Object> tmp443;
    TNode<NativeContext> tmp444;
    TNode<Object> tmp445;
    TNode<Map> tmp446;
    TNode<Object> tmp447;
    TNode<JSReceiver> tmp448;
    TNode<Object> tmp449;
    TNode<Object> tmp450;
    TNode<Context> tmp451;
    TNode<Object> tmp452;
    ca_.Bind(&block42, &tmp434, &tmp435, &tmp436, &tmp437, &tmp438, &tmp439, &tmp440, &tmp441, &tmp442, &tmp443, &tmp444, &tmp445, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452);
    ca_.Goto(&block13, tmp434, tmp435, tmp436, tmp437, tmp438, tmp439, tmp440, tmp441, tmp442, tmp443, tmp452);
  }

  if (block43.is_used()) {
    TNode<Context> tmp453;
    TNode<Object> tmp454;
    TNode<Object> tmp455;
    TNode<JSReceiver> tmp456;
    TNode<PromiseCapability> tmp457;
    TNode<Object> tmp458;
    TNode<Object> tmp459;
    TNode<HeapObject> tmp460;
    TNode<JSReceiver> tmp461;
    TNode<Object> tmp462;
    TNode<NativeContext> tmp463;
    TNode<Object> tmp464;
    TNode<Map> tmp465;
    TNode<Object> tmp466;
    TNode<Object> tmp467;
    TNode<Object> tmp468;
    TNode<String> tmp469;
    TNode<Context> tmp470;
    TNode<Object> tmp471;
    ca_.Bind(&block43, &tmp453, &tmp454, &tmp455, &tmp456, &tmp457, &tmp458, &tmp459, &tmp460, &tmp461, &tmp462, &tmp463, &tmp464, &tmp465, &tmp466, &tmp467, &tmp468, &tmp469, &tmp470, &tmp471);
    ca_.Goto(&block13, tmp453, tmp454, tmp455, tmp456, tmp457, tmp458, tmp459, tmp460, tmp461, tmp462, tmp471);
  }

  if (block44.is_used()) {
    TNode<Context> tmp472;
    TNode<Object> tmp473;
    TNode<Object> tmp474;
    TNode<JSReceiver> tmp475;
    TNode<PromiseCapability> tmp476;
    TNode<Object> tmp477;
    TNode<Object> tmp478;
    TNode<HeapObject> tmp479;
    TNode<JSReceiver> tmp480;
    TNode<Object> tmp481;
    TNode<NativeContext> tmp482;
    TNode<Object> tmp483;
    TNode<Map> tmp484;
    TNode<Object> tmp485;
    TNode<Object> tmp486;
    TNode<Object> tmp487;
    TNode<Context> tmp488;
    TNode<Object> tmp489;
    TNode<Object> tmp490;
    TNode<Object> tmp491;
    TNode<Context> tmp492;
    TNode<Object> tmp493;
    ca_.Bind(&block44, &tmp472, &tmp473, &tmp474, &tmp475, &tmp476, &tmp477, &tmp478, &tmp479, &tmp480, &tmp481, &tmp482, &tmp483, &tmp484, &tmp485, &tmp486, &tmp487, &tmp488, &tmp489, &tmp490, &tmp491, &tmp492, &tmp493);
    ca_.Goto(&block13, tmp472, tmp473, tmp474, tmp475, tmp476, tmp477, tmp478, tmp479, tmp480, tmp481, tmp493);
  }

  if (block45.is_used()) {
    TNode<Context> tmp494;
    TNode<Object> tmp495;
    TNode<Object> tmp496;
    TNode<JSReceiver> tmp497;
    TNode<PromiseCapability> tmp498;
    TNode<Object> tmp499;
    TNode<Object> tmp500;
    TNode<HeapObject> tmp501;
    TNode<JSReceiver> tmp502;
    TNode<Object> tmp503;
    TNode<NativeContext> tmp504;
    TNode<Object> tmp505;
    TNode<Map> tmp506;
    TNode<Object> tmp507;
    TNode<Object> tmp508;
    TNode<Object> tmp509;
    TNode<Context> tmp510;
    TNode<Object> tmp511;
    TNode<Object> tmp512;
    TNode<Object> tmp513;
    TNode<Object> tmp514;
    TNode<Context> tmp515;
    TNode<Object> tmp516;
    ca_.Bind(&block45, &tmp494, &tmp495, &tmp496, &tmp497, &tmp498, &tmp499, &tmp500, &tmp501, &tmp502, &tmp503, &tmp504, &tmp505, &tmp506, &tmp507, &tmp508, &tmp509, &tmp510, &tmp511, &tmp512, &tmp513, &tmp514, &tmp515, &tmp516);
    ca_.Goto(&block13, tmp494, tmp495, tmp496, tmp497, tmp498, tmp499, tmp500, tmp501, tmp502, tmp503, tmp516);
  }

  if (block46.is_used()) {
    TNode<Context> tmp517;
    TNode<Object> tmp518;
    TNode<Object> tmp519;
    TNode<JSReceiver> tmp520;
    TNode<PromiseCapability> tmp521;
    TNode<Object> tmp522;
    TNode<Object> tmp523;
    TNode<HeapObject> tmp524;
    TNode<JSReceiver> tmp525;
    TNode<Object> tmp526;
    TNode<NativeContext> tmp527;
    TNode<Object> tmp528;
    TNode<Map> tmp529;
    TNode<Object> tmp530;
    TNode<Object> tmp531;
    TNode<Object> tmp532;
    TNode<Context> tmp533;
    TNode<Object> tmp534;
    TNode<Object> tmp535;
    TNode<Object> tmp536;
    TNode<Object> tmp537;
    TNode<Object> tmp538;
    ca_.Bind(&block46, &tmp517, &tmp518, &tmp519, &tmp520, &tmp521, &tmp522, &tmp523, &tmp524, &tmp525, &tmp526, &tmp527, &tmp528, &tmp529, &tmp530, &tmp531, &tmp532, &tmp533, &tmp534, &tmp535, &tmp536, &tmp537, &tmp538);
    ca_.Goto(&block13, tmp517, tmp518, tmp519, tmp520, tmp521, tmp522, tmp523, tmp524, tmp525, tmp526, tmp538);
  }

  if (block49.is_used()) {
    TNode<Context> tmp539;
    TNode<Object> tmp540;
    TNode<Object> tmp541;
    TNode<JSReceiver> tmp542;
    TNode<PromiseCapability> tmp543;
    TNode<Object> tmp544;
    TNode<Object> tmp545;
    TNode<HeapObject> tmp546;
    TNode<JSReceiver> tmp547;
    TNode<Object> tmp548;
    TNode<NativeContext> tmp549;
    TNode<Object> tmp550;
    TNode<Map> tmp551;
    TNode<Object> tmp552;
    TNode<Object> tmp553;
    TNode<Object> tmp554;
    TNode<Object> tmp555;
    TNode<Object> tmp556;
    ca_.Bind(&block49, &tmp539, &tmp540, &tmp541, &tmp542, &tmp543, &tmp544, &tmp545, &tmp546, &tmp547, &tmp548, &tmp549, &tmp550, &tmp551, &tmp552, &tmp553, &tmp554, &tmp555, &tmp556);
    ca_.Goto(&block13, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp546, tmp547, tmp548, tmp556);
  }

  if (block50.is_used()) {
    TNode<Context> tmp557;
    TNode<Object> tmp558;
    TNode<Object> tmp559;
    TNode<JSReceiver> tmp560;
    TNode<PromiseCapability> tmp561;
    TNode<Object> tmp562;
    TNode<Object> tmp563;
    TNode<HeapObject> tmp564;
    TNode<JSReceiver> tmp565;
    TNode<Object> tmp566;
    TNode<NativeContext> tmp567;
    TNode<Object> tmp568;
    TNode<Map> tmp569;
    TNode<Object> tmp570;
    TNode<Object> tmp571;
    TNode<Object> tmp572;
    TNode<Object> tmp573;
    TNode<BoolT> tmp574;
    ca_.Bind(&block50, &tmp557, &tmp558, &tmp559, &tmp560, &tmp561, &tmp562, &tmp563, &tmp564, &tmp565, &tmp566, &tmp567, &tmp568, &tmp569, &tmp570, &tmp571, &tmp572, &tmp573, &tmp574);
    TNode<BoolT> tmp575;
    USE(tmp575);
    compiler::CodeAssemblerExceptionHandlerLabel catch576__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch576__label);
    tmp575 = Is_JSPromise_JSReceiver_OR_Undefined_0(state_, TNode<Context>{tmp557}, TNode<HeapObject>{tmp564});
    }
    if (catch576__label.is_used()) {
      compiler::CodeAssemblerLabel catch576_skip(&ca_);
      ca_.Goto(&catch576_skip);
      TNode<Object> catch576_exception_object;
      ca_.Bind(&catch576__label, &catch576_exception_object);
      ca_.Goto(&block53, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563, tmp564, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp573, tmp574, tmp564, tmp557, catch576_exception_object);
      ca_.Bind(&catch576_skip);
    }
    TNode<BoolT> tmp577;
    USE(tmp577);
    compiler::CodeAssemblerExceptionHandlerLabel catch578__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch578__label);
    tmp577 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp575});
    }
    if (catch578__label.is_used()) {
      compiler::CodeAssemblerLabel catch578_skip(&ca_);
      ca_.Goto(&catch578_skip);
      TNode<Object> catch578_exception_object;
      ca_.Bind(&catch578__label, &catch578_exception_object);
      ca_.Goto(&block54, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563, tmp564, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp573, tmp574, tmp575, catch578_exception_object);
      ca_.Bind(&catch578_skip);
    }
    ca_.Goto(&block52, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563, tmp564, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp573, tmp574, tmp577);
  }

  if (block53.is_used()) {
    TNode<Context> tmp579;
    TNode<Object> tmp580;
    TNode<Object> tmp581;
    TNode<JSReceiver> tmp582;
    TNode<PromiseCapability> tmp583;
    TNode<Object> tmp584;
    TNode<Object> tmp585;
    TNode<HeapObject> tmp586;
    TNode<JSReceiver> tmp587;
    TNode<Object> tmp588;
    TNode<NativeContext> tmp589;
    TNode<Object> tmp590;
    TNode<Map> tmp591;
    TNode<Object> tmp592;
    TNode<Object> tmp593;
    TNode<Object> tmp594;
    TNode<Object> tmp595;
    TNode<BoolT> tmp596;
    TNode<HeapObject> tmp597;
    TNode<Context> tmp598;
    TNode<Object> tmp599;
    ca_.Bind(&block53, &tmp579, &tmp580, &tmp581, &tmp582, &tmp583, &tmp584, &tmp585, &tmp586, &tmp587, &tmp588, &tmp589, &tmp590, &tmp591, &tmp592, &tmp593, &tmp594, &tmp595, &tmp596, &tmp597, &tmp598, &tmp599);
    ca_.Goto(&block13, tmp579, tmp580, tmp581, tmp582, tmp583, tmp584, tmp585, tmp586, tmp587, tmp588, tmp599);
  }

  if (block54.is_used()) {
    TNode<Context> tmp600;
    TNode<Object> tmp601;
    TNode<Object> tmp602;
    TNode<JSReceiver> tmp603;
    TNode<PromiseCapability> tmp604;
    TNode<Object> tmp605;
    TNode<Object> tmp606;
    TNode<HeapObject> tmp607;
    TNode<JSReceiver> tmp608;
    TNode<Object> tmp609;
    TNode<NativeContext> tmp610;
    TNode<Object> tmp611;
    TNode<Map> tmp612;
    TNode<Object> tmp613;
    TNode<Object> tmp614;
    TNode<Object> tmp615;
    TNode<Object> tmp616;
    TNode<BoolT> tmp617;
    TNode<BoolT> tmp618;
    TNode<Object> tmp619;
    ca_.Bind(&block54, &tmp600, &tmp601, &tmp602, &tmp603, &tmp604, &tmp605, &tmp606, &tmp607, &tmp608, &tmp609, &tmp610, &tmp611, &tmp612, &tmp613, &tmp614, &tmp615, &tmp616, &tmp617, &tmp618, &tmp619);
    ca_.Goto(&block13, tmp600, tmp601, tmp602, tmp603, tmp604, tmp605, tmp606, tmp607, tmp608, tmp609, tmp619);
  }

  if (block51.is_used()) {
    TNode<Context> tmp620;
    TNode<Object> tmp621;
    TNode<Object> tmp622;
    TNode<JSReceiver> tmp623;
    TNode<PromiseCapability> tmp624;
    TNode<Object> tmp625;
    TNode<Object> tmp626;
    TNode<HeapObject> tmp627;
    TNode<JSReceiver> tmp628;
    TNode<Object> tmp629;
    TNode<NativeContext> tmp630;
    TNode<Object> tmp631;
    TNode<Map> tmp632;
    TNode<Object> tmp633;
    TNode<Object> tmp634;
    TNode<Object> tmp635;
    TNode<Object> tmp636;
    TNode<BoolT> tmp637;
    ca_.Bind(&block51, &tmp620, &tmp621, &tmp622, &tmp623, &tmp624, &tmp625, &tmp626, &tmp627, &tmp628, &tmp629, &tmp630, &tmp631, &tmp632, &tmp633, &tmp634, &tmp635, &tmp636, &tmp637);
    TNode<BoolT> tmp638;
    USE(tmp638);
    compiler::CodeAssemblerExceptionHandlerLabel catch639__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch639__label);
    tmp638 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch639__label.is_used()) {
      compiler::CodeAssemblerLabel catch639_skip(&ca_);
      ca_.Goto(&catch639_skip);
      TNode<Object> catch639_exception_object;
      ca_.Bind(&catch639__label, &catch639_exception_object);
      ca_.Goto(&block55, tmp620, tmp621, tmp622, tmp623, tmp624, tmp625, tmp626, tmp627, tmp628, tmp629, tmp630, tmp631, tmp632, tmp633, tmp634, tmp635, tmp636, tmp637, catch639_exception_object);
      ca_.Bind(&catch639_skip);
    }
    ca_.Goto(&block52, tmp620, tmp621, tmp622, tmp623, tmp624, tmp625, tmp626, tmp627, tmp628, tmp629, tmp630, tmp631, tmp632, tmp633, tmp634, tmp635, tmp636, tmp637, tmp638);
  }

  if (block55.is_used()) {
    TNode<Context> tmp640;
    TNode<Object> tmp641;
    TNode<Object> tmp642;
    TNode<JSReceiver> tmp643;
    TNode<PromiseCapability> tmp644;
    TNode<Object> tmp645;
    TNode<Object> tmp646;
    TNode<HeapObject> tmp647;
    TNode<JSReceiver> tmp648;
    TNode<Object> tmp649;
    TNode<NativeContext> tmp650;
    TNode<Object> tmp651;
    TNode<Map> tmp652;
    TNode<Object> tmp653;
    TNode<Object> tmp654;
    TNode<Object> tmp655;
    TNode<Object> tmp656;
    TNode<BoolT> tmp657;
    TNode<Object> tmp658;
    ca_.Bind(&block55, &tmp640, &tmp641, &tmp642, &tmp643, &tmp644, &tmp645, &tmp646, &tmp647, &tmp648, &tmp649, &tmp650, &tmp651, &tmp652, &tmp653, &tmp654, &tmp655, &tmp656, &tmp657, &tmp658);
    ca_.Goto(&block13, tmp640, tmp641, tmp642, tmp643, tmp644, tmp645, tmp646, tmp647, tmp648, tmp649, tmp658);
  }

  if (block52.is_used()) {
    TNode<Context> tmp659;
    TNode<Object> tmp660;
    TNode<Object> tmp661;
    TNode<JSReceiver> tmp662;
    TNode<PromiseCapability> tmp663;
    TNode<Object> tmp664;
    TNode<Object> tmp665;
    TNode<HeapObject> tmp666;
    TNode<JSReceiver> tmp667;
    TNode<Object> tmp668;
    TNode<NativeContext> tmp669;
    TNode<Object> tmp670;
    TNode<Map> tmp671;
    TNode<Object> tmp672;
    TNode<Object> tmp673;
    TNode<Object> tmp674;
    TNode<Object> tmp675;
    TNode<BoolT> tmp676;
    TNode<BoolT> tmp677;
    ca_.Bind(&block52, &tmp659, &tmp660, &tmp661, &tmp662, &tmp663, &tmp664, &tmp665, &tmp666, &tmp667, &tmp668, &tmp669, &tmp670, &tmp671, &tmp672, &tmp673, &tmp674, &tmp675, &tmp676, &tmp677);
    ca_.Branch(tmp677, &block47, &block48, tmp659, tmp660, tmp661, tmp662, tmp663, tmp664, tmp665, tmp666, tmp667, tmp668, tmp669, tmp670, tmp671, tmp672, tmp673, tmp674, tmp675);
  }

  if (block47.is_used()) {
    TNode<Context> tmp678;
    TNode<Object> tmp679;
    TNode<Object> tmp680;
    TNode<JSReceiver> tmp681;
    TNode<PromiseCapability> tmp682;
    TNode<Object> tmp683;
    TNode<Object> tmp684;
    TNode<HeapObject> tmp685;
    TNode<JSReceiver> tmp686;
    TNode<Object> tmp687;
    TNode<NativeContext> tmp688;
    TNode<Object> tmp689;
    TNode<Map> tmp690;
    TNode<Object> tmp691;
    TNode<Object> tmp692;
    TNode<Object> tmp693;
    TNode<Object> tmp694;
    ca_.Bind(&block47, &tmp678, &tmp679, &tmp680, &tmp681, &tmp682, &tmp683, &tmp684, &tmp685, &tmp686, &tmp687, &tmp688, &tmp689, &tmp690, &tmp691, &tmp692, &tmp693, &tmp694);
    TNode<Symbol> tmp695;
    USE(tmp695);
    tmp695 = kPromiseHandledBySymbol_0(state_);
    TNode<Object> tmp696;
    USE(tmp696);
    compiler::CodeAssemblerExceptionHandlerLabel catch697__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch697__label);
    tmp696 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp678}, TNode<Object>{tmp694}, TNode<Object>{tmp695}, TNode<Object>{tmp685});
    }
    if (catch697__label.is_used()) {
      compiler::CodeAssemblerLabel catch697_skip(&ca_);
      ca_.Goto(&catch697_skip);
      TNode<Object> catch697_exception_object;
      ca_.Bind(&catch697__label, &catch697_exception_object);
      ca_.Goto(&block56, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp692, tmp693, tmp694, tmp678, tmp694, tmp695, tmp685, catch697_exception_object);
      ca_.Bind(&catch697_skip);
    }
    ca_.Goto(&block48, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp692, tmp693, tmp694);
  }

  if (block56.is_used()) {
    TNode<Context> tmp698;
    TNode<Object> tmp699;
    TNode<Object> tmp700;
    TNode<JSReceiver> tmp701;
    TNode<PromiseCapability> tmp702;
    TNode<Object> tmp703;
    TNode<Object> tmp704;
    TNode<HeapObject> tmp705;
    TNode<JSReceiver> tmp706;
    TNode<Object> tmp707;
    TNode<NativeContext> tmp708;
    TNode<Object> tmp709;
    TNode<Map> tmp710;
    TNode<Object> tmp711;
    TNode<Object> tmp712;
    TNode<Object> tmp713;
    TNode<Object> tmp714;
    TNode<Context> tmp715;
    TNode<Object> tmp716;
    TNode<Symbol> tmp717;
    TNode<HeapObject> tmp718;
    TNode<Object> tmp719;
    ca_.Bind(&block56, &tmp698, &tmp699, &tmp700, &tmp701, &tmp702, &tmp703, &tmp704, &tmp705, &tmp706, &tmp707, &tmp708, &tmp709, &tmp710, &tmp711, &tmp712, &tmp713, &tmp714, &tmp715, &tmp716, &tmp717, &tmp718, &tmp719);
    ca_.Goto(&block13, tmp698, tmp699, tmp700, tmp701, tmp702, tmp703, tmp704, tmp705, tmp706, tmp707, tmp719);
  }

  if (block48.is_used()) {
    TNode<Context> tmp720;
    TNode<Object> tmp721;
    TNode<Object> tmp722;
    TNode<JSReceiver> tmp723;
    TNode<PromiseCapability> tmp724;
    TNode<Object> tmp725;
    TNode<Object> tmp726;
    TNode<HeapObject> tmp727;
    TNode<JSReceiver> tmp728;
    TNode<Object> tmp729;
    TNode<NativeContext> tmp730;
    TNode<Object> tmp731;
    TNode<Map> tmp732;
    TNode<Object> tmp733;
    TNode<Object> tmp734;
    TNode<Object> tmp735;
    TNode<Object> tmp736;
    ca_.Bind(&block48, &tmp720, &tmp721, &tmp722, &tmp723, &tmp724, &tmp725, &tmp726, &tmp727, &tmp728, &tmp729, &tmp730, &tmp731, &tmp732, &tmp733, &tmp734, &tmp735, &tmp736);
    ca_.Goto(&block31, tmp720, tmp721, tmp722, tmp723, tmp724, tmp725, tmp726, tmp727, tmp728, tmp729, tmp730, tmp731, tmp732);
  }

  if (block30.is_used()) {
    TNode<Context> tmp737;
    TNode<Object> tmp738;
    TNode<Object> tmp739;
    TNode<JSReceiver> tmp740;
    TNode<PromiseCapability> tmp741;
    TNode<Object> tmp742;
    TNode<Object> tmp743;
    TNode<HeapObject> tmp744;
    TNode<JSReceiver> tmp745;
    TNode<Object> tmp746;
    TNode<NativeContext> tmp747;
    TNode<Object> tmp748;
    TNode<Map> tmp749;
    ca_.Bind(&block30, &tmp737, &tmp738, &tmp739, &tmp740, &tmp741, &tmp742, &tmp743, &tmp744, &tmp745, &tmp746, &tmp747, &tmp748, &tmp749);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block13.is_used()) {
    TNode<Context> tmp750;
    TNode<Object> tmp751;
    TNode<Object> tmp752;
    TNode<JSReceiver> tmp753;
    TNode<PromiseCapability> tmp754;
    TNode<Object> tmp755;
    TNode<Object> tmp756;
    TNode<HeapObject> tmp757;
    TNode<JSReceiver> tmp758;
    TNode<Object> tmp759;
    TNode<Object> tmp760;
    ca_.Bind(&block13, &tmp750, &tmp751, &tmp752, &tmp753, &tmp754, &tmp755, &tmp756, &tmp757, &tmp758, &tmp759, &tmp760);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp750}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp758}, TNode<Object>{tmp759}}, TNode<Object>{tmp760}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block57, tmp750, tmp751, tmp752, tmp753, tmp754, tmp755, tmp756, tmp757, tmp758, tmp759, tmp760, tmp758, tmp759, tmp760, tmp750, result_0_0.value());
    }
  }

  if (block57.is_used()) {
    TNode<Context> tmp761;
    TNode<Object> tmp762;
    TNode<Object> tmp763;
    TNode<JSReceiver> tmp764;
    TNode<PromiseCapability> tmp765;
    TNode<Object> tmp766;
    TNode<Object> tmp767;
    TNode<HeapObject> tmp768;
    TNode<JSReceiver> tmp769;
    TNode<Object> tmp770;
    TNode<Object> tmp771;
    TNode<JSReceiver> tmp772;
    TNode<Object> tmp773;
    TNode<Object> tmp774;
    TNode<Context> tmp775;
    TNode<Object> tmp776;
    ca_.Bind(&block57, &tmp761, &tmp762, &tmp763, &tmp764, &tmp765, &tmp766, &tmp767, &tmp768, &tmp769, &tmp770, &tmp771, &tmp772, &tmp773, &tmp774, &tmp775, &tmp776);
    ca_.Goto(&block8, tmp761, tmp762, tmp763, tmp764, tmp765, tmp766, tmp767, tmp768, tmp776);
  }

  if (block8.is_used()) {
    TNode<Context> tmp777;
    TNode<Object> tmp778;
    TNode<Object> tmp779;
    TNode<JSReceiver> tmp780;
    TNode<PromiseCapability> tmp781;
    TNode<Object> tmp782;
    TNode<Object> tmp783;
    TNode<HeapObject> tmp784;
    TNode<Object> tmp785;
    ca_.Bind(&block8, &tmp777, &tmp778, &tmp779, &tmp780, &tmp781, &tmp782, &tmp783, &tmp784, &tmp785);
    TNode<Object> tmp786;
    USE(tmp786);
    tmp786 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp777}, TNode<Object>{tmp783});
    TNode<Oddball> tmp787;
    USE(tmp787);
    tmp787 = Undefined_0(state_);
    TNode<Object> tmp788;
    USE(tmp788);
    tmp788 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp777}, TNode<Object>{tmp785});
    TNode<Object> tmp789;
    USE(tmp789);
    tmp789 = CodeStubAssembler(state_).Call(TNode<Context>{tmp777}, TNode<Object>{tmp786}, TNode<Object>{tmp787}, TNode<Object>{tmp788});
    CodeStubAssembler(state_).Return(tmp784);
  }
}

TNode<BoolT> Is_JSPromise_JSReceiver_OR_Undefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, JSPromise> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSPromise_0(state_, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    TNode<JSPromise> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

}  // namespace internal
}  // namespace v8

