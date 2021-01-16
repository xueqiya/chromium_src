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

TF_BUILTIN(PromiseValueThunkFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp2});
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseThrowerFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp2});
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrow, tmp0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }
}

TNode<JSFunction> CreateThrowerFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_reason) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_reason);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Context> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp1}, PromiseBuiltins::kPromiseValueThunkOrReasonContextLength);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp3}, TNode<IntPtrT>{tmp4}, TNode<Object>{tmp2});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp5});
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THROWER_FINALLY_SHARED_FUN_0(state_, Context::Field::PROMISE_THROWER_FINALLY_SHARED_FUN);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp8});
    TNode<SharedFunctionInfo> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp9});
    TNode<JSFunction> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp7}, TNode<SharedFunctionInfo>{tmp10}, TNode<Context>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp11);
  }

    TNode<Context> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<JSFunction> tmp15;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15);
  return TNode<JSFunction>{tmp15};
}

TF_BUILTIN(PromiseCatchFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, Object, JSFunction> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<Oddball> tmp6;
    USE(tmp6);
    tmp6 = Undefined_0(state_);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp5}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp8});
    TNode<JSFunction> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp9});
    TNode<Object> tmp11;
    tmp11 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, tmp0, tmp10, tmp7);
    USE(tmp11);
    TNode<NativeContext> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<JSFunction> tmp13;
    USE(tmp13);
    tmp13 = CreateThrowerFunction_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp12}, TNode<Object>{tmp2});
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = InvokeThen_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp12}, TNode<Object>{tmp11}, TNode<Object>{tmp13});
    TNode<Object> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp14});
    CodeStubAssembler(state_).Return(tmp15);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Object> tmp20;
    TNode<JSFunction> tmp21;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsConstructor(constructor)' failed", "src/builtins/promise-finally.tq", 67);
  }

  if (block3.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<Object> tmp26;
    TNode<JSFunction> tmp27;
    ca_.Bind(&block3, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
  }
}

TNode<JSFunction> CreateValueThunkFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Context> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp1}, PromiseBuiltins::kPromiseValueThunkOrReasonContextLength);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp3}, TNode<IntPtrT>{tmp4}, TNode<Object>{tmp2});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp5});
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_VALUE_THUNK_FINALLY_SHARED_FUN_0(state_, Context::Field::PROMISE_VALUE_THUNK_FINALLY_SHARED_FUN);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp8});
    TNode<SharedFunctionInfo> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp9});
    TNode<JSFunction> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp7}, TNode<SharedFunctionInfo>{tmp10}, TNode<Context>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp11);
  }

    TNode<Context> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<JSFunction> tmp15;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15);
  return TNode<JSFunction>{tmp15};
}

TF_BUILTIN(PromiseThenFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, Object, JSFunction> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<Oddball> tmp6;
    USE(tmp6);
    tmp6 = Undefined_0(state_);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp5}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp8});
    TNode<JSFunction> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp9});
    TNode<Object> tmp11;
    tmp11 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, tmp0, tmp10, tmp7);
    USE(tmp11);
    TNode<NativeContext> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<JSFunction> tmp13;
    USE(tmp13);
    tmp13 = CreateValueThunkFunction_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp12}, TNode<Object>{tmp2});
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = InvokeThen_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp12}, TNode<Object>{tmp11}, TNode<Object>{tmp13});
    TNode<Object> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp14});
    CodeStubAssembler(state_).Return(tmp15);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Object> tmp20;
    TNode<JSFunction> tmp21;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsConstructor(constructor)' failed", "src/builtins/promise-finally.tq", 111);
  }

  if (block3.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<Object> tmp26;
    TNode<JSFunction> tmp27;
    ca_.Bind(&block3, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
  }
}

TorqueStructPromiseFinallyFunctions_0 CreatePromiseFinallyFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_onFinally, TNode<JSReceiver> p_constructor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSReceiver, JSReceiver, JSFunction, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_onFinally, p_constructor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<JSReceiver> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Context> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp1}, PromiseBuiltins::kPromiseFinallyContextLength);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, TNode<IntPtrT>{tmp5}, TNode<Object>{tmp2});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, TNode<IntPtrT>{tmp6}, TNode<Object>{tmp3});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp7});
    TNode<Map> tmp9;
    USE(tmp9);
    tmp9 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_FINALLY_SHARED_FUN_0(state_, Context::Field::PROMISE_THEN_FINALLY_SHARED_FUN);
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp10});
    TNode<SharedFunctionInfo> tmp12;
    USE(tmp12);
    tmp12 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp11});
    TNode<JSFunction> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp9}, TNode<SharedFunctionInfo>{tmp12}, TNode<Context>{tmp4});
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_CATCH_FINALLY_SHARED_FUN_0(state_, Context::Field::PROMISE_CATCH_FINALLY_SHARED_FUN);
    TNode<Object> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp14});
    TNode<SharedFunctionInfo> tmp16;
    USE(tmp16);
    tmp16 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp15});
    TNode<JSFunction> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp9}, TNode<SharedFunctionInfo>{tmp16}, TNode<Context>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp13, tmp17);
  }

    TNode<Context> tmp18;
    TNode<NativeContext> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<JSFunction> tmp22;
    TNode<JSFunction> tmp23;
    ca_.Bind(&block2, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
  return TorqueStructPromiseFinallyFunctions_0{TNode<JSFunction>{tmp22}, TNode<JSFunction>{tmp23}};
}

TF_BUILTIN(PromisePrototypeFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kOnFinally));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object, BoolT, BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, NativeContext, JSReceiver, JSReceiver, Map, Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "Promise.prototype.finally");
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<NativeContext> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp9});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp16});
    TNode<JSReceiver> tmp18;
    USE(tmp18);
    tmp18 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp9}, TNode<Object>{tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp20 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp14, tmp19});
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp20});
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp21});
    ca_.Branch(tmp22, &block7, &block8, tmp9, tmp10, tmp11, tmp14, tmp15, tmp18, tmp18, tmp20, tmp22);
  }

  if (block7.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<NativeContext> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Map> tmp30;
    TNode<BoolT> tmp31;
    ca_.Bind(&block7, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block8.is_used()) {
    TNode<Context> tmp33;
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<NativeContext> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Map> tmp40;
    TNode<BoolT> tmp41;
    ca_.Bind(&block8, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = IsPromiseSpeciesLookupChainIntact_0(state_, TNode<NativeContext>{tmp37}, TNode<Map>{tmp40});
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp42});
    ca_.Goto(&block9, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp43);
  }

  if (block9.is_used()) {
    TNode<Context> tmp44;
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<NativeContext> tmp48;
    TNode<JSReceiver> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<Map> tmp51;
    TNode<BoolT> tmp52;
    TNode<BoolT> tmp53;
    ca_.Bind(&block9, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    ca_.Branch(tmp53, &block5, &block6, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51);
  }

  if (block5.is_used()) {
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<NativeContext> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Map> tmp61;
    ca_.Bind(&block5, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<JSReceiver> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{tmp54}, TNode<Object>{tmp57}, TNode<JSReceiver>{tmp59});
    ca_.Goto(&block6, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp62, tmp61);
  }

  if (block6.is_used()) {
    TNode<Context> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<JSReceiver> tmp66;
    TNode<NativeContext> tmp67;
    TNode<JSReceiver> tmp68;
    TNode<JSReceiver> tmp69;
    TNode<Map> tmp70;
    ca_.Bind(&block6, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<BoolT> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp65});
    TNode<BoolT> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp71});
    ca_.Branch(tmp72, &block16, &block17, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, ca_.Uninitialized<Object>(), ca_.Uninitialized<Object>(), tmp72);
  }

  if (block13.is_used()) {
    TNode<Context> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<JSReceiver> tmp76;
    TNode<NativeContext> tmp77;
    TNode<JSReceiver> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<Map> tmp80;
    ca_.Bind(&block13, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsConstructor(constructor)' failed", "src/builtins/promise-finally.tq", 175);
  }

  if (block12.is_used()) {
    TNode<Context> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<NativeContext> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<JSReceiver> tmp87;
    TNode<Map> tmp88;
    ca_.Bind(&block12, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
  }

  if (block16.is_used()) {
    TNode<Context> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<NativeContext> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<JSReceiver> tmp95;
    TNode<Map> tmp96;
    TNode<Object> tmp97;
    TNode<Object> tmp98;
    TNode<BoolT> tmp99;
    ca_.Bind(&block16, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<HeapObject> tmp100;
    USE(tmp100);
    tmp100 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp89}, TNode<Object>{tmp91});
    TNode<BoolT> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).IsCallable(TNode<HeapObject>{tmp100});
    ca_.Goto(&block18, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp101);
  }

  if (block17.is_used()) {
    TNode<Context> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<JSReceiver> tmp105;
    TNode<NativeContext> tmp106;
    TNode<JSReceiver> tmp107;
    TNode<JSReceiver> tmp108;
    TNode<Map> tmp109;
    TNode<Object> tmp110;
    TNode<Object> tmp111;
    TNode<BoolT> tmp112;
    ca_.Bind(&block17, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112);
    TNode<BoolT> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block18, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113);
  }

  if (block18.is_used()) {
    TNode<Context> tmp114;
    TNode<Object> tmp115;
    TNode<Object> tmp116;
    TNode<JSReceiver> tmp117;
    TNode<NativeContext> tmp118;
    TNode<JSReceiver> tmp119;
    TNode<JSReceiver> tmp120;
    TNode<Map> tmp121;
    TNode<Object> tmp122;
    TNode<Object> tmp123;
    TNode<BoolT> tmp124;
    TNode<BoolT> tmp125;
    ca_.Bind(&block18, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    ca_.Branch(tmp125, &block14, &block15, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123);
  }

  if (block14.is_used()) {
    TNode<Context> tmp126;
    TNode<Object> tmp127;
    TNode<Object> tmp128;
    TNode<JSReceiver> tmp129;
    TNode<NativeContext> tmp130;
    TNode<JSReceiver> tmp131;
    TNode<JSReceiver> tmp132;
    TNode<Map> tmp133;
    TNode<Object> tmp134;
    TNode<Object> tmp135;
    ca_.Bind(&block14, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    TNode<JSReceiver> tmp136;
    USE(tmp136);
    tmp136 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp126}, TNode<Object>{tmp128});
    TNode<JSFunction> tmp137;
    USE(tmp137);
    TNode<JSFunction> tmp138;
    USE(tmp138);
    std::tie(tmp137, tmp138) = CreatePromiseFinallyFunctions_0(state_, TNode<Context>{tmp126}, TNode<NativeContext>{tmp130}, TNode<JSReceiver>{tmp136}, TNode<JSReceiver>{tmp132}).Flatten();
    ca_.Goto(&block19, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp137, tmp138);
  }

  if (block15.is_used()) {
    TNode<Context> tmp139;
    TNode<Object> tmp140;
    TNode<Object> tmp141;
    TNode<JSReceiver> tmp142;
    TNode<NativeContext> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<JSReceiver> tmp145;
    TNode<Map> tmp146;
    TNode<Object> tmp147;
    TNode<Object> tmp148;
    ca_.Bind(&block15, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    ca_.Goto(&block19, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp141, tmp141);
  }

  if (block19.is_used()) {
    TNode<Context> tmp149;
    TNode<Object> tmp150;
    TNode<Object> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<NativeContext> tmp153;
    TNode<JSReceiver> tmp154;
    TNode<JSReceiver> tmp155;
    TNode<Map> tmp156;
    TNode<Object> tmp157;
    TNode<Object> tmp158;
    ca_.Bind(&block19, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158);
    TNode<Object> tmp159;
    USE(tmp159);
    tmp159 = InvokeThen_1(state_, TNode<Context>{tmp149}, TNode<NativeContext>{tmp153}, TNode<Object>{tmp150}, TNode<Object>{tmp157}, TNode<Object>{tmp158});
    TNode<Object> tmp160;
    USE(tmp160);
    tmp160 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp149}, TNode<Object>{tmp159});
    CodeStubAssembler(state_).Return(tmp160);
  }
}

}  // namespace internal
}  // namespace v8

