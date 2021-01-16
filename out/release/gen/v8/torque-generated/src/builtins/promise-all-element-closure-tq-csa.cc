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

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Int32T> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Int32T>{tmp2};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Int32T> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Int32T>{tmp2};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesArraySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Int32T> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Int32T>{tmp2};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Int32T> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Int32T>{tmp2};
}

TF_BUILTIN(PromiseAllResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, TNode<JSFunction>{tmp2}, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0{});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseAllSettledResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, TNode<JSFunction>{tmp2}, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0{});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseAllSettledRejectElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, TNode<JSFunction>{tmp2}, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0{});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value, p_function);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<JSFunction> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<NativeContext> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp8});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp10, tmp12}, tmp11);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp13 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{tmp10}, &label0);
    ca_.Goto(&block15, tmp8, tmp9, tmp10, tmp11, tmp9, tmp10, tmp13);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp8, tmp9, tmp10, tmp11, tmp9, tmp10);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<JSFunction> tmp16;
    ca_.Bind(&block7, &tmp14, &tmp15, &tmp16);
    CodeStubAssembler(state_).FailAssert("Torque assert 'context.length == PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength' failed", "src/builtins/promise-all-element-closure.tq", 96);
  }

  if (block6.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<JSFunction> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  }

  if (block12.is_used()) {
    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSFunction> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    ca_.Bind(&block12, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", "src/builtins/promise-all-element-closure.tq", 107);
  }

  if (block11.is_used()) {
    TNode<Context> tmp25;
    TNode<Object> tmp26;
    TNode<JSFunction> tmp27;
    TNode<NativeContext> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block11, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
  }

  if (block16.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<JSFunction> tmp32;
    TNode<NativeContext> tmp33;
    TNode<Object> tmp34;
    TNode<JSFunction> tmp35;
    ca_.Bind(&block16, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    TNode<JSFunction> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<JSFunction> tmp41;
    TNode<IntPtrT> tmp42;
    ca_.Bind(&block15, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp42}, TNode<IntPtrT>{tmp43});
    TNode<Object> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp36}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<JSArray> tmp46;
    USE(tmp46);
    tmp46 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp36}, TNode<Object>{tmp45});
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp48 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp46, tmp47});
    TNode<FixedArray> tmp49;
    USE(tmp49);
    tmp49 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp36}, TNode<Object>{tmp48});
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp51 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp46, tmp50});
    TNode<IntPtrT> tmp52;
    USE(tmp52);
    tmp52 = Convert_intptr_Number_0(state_, TNode<Number>{tmp51});
    TNode<BoolT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp52});
    ca_.Branch(tmp53, &block21, &block22, tmp36, tmp37, tmp38, tmp39, tmp40, tmp42, tmp44, tmp46, tmp49, tmp52);
  }

  if (block20.is_used()) {
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    TNode<JSFunction> tmp56;
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block20, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", "src/builtins/promise-all-element-closure.tq", 110);
  }

  if (block19.is_used()) {
    TNode<Context> tmp60;
    TNode<Object> tmp61;
    TNode<JSFunction> tmp62;
    TNode<NativeContext> tmp63;
    TNode<Object> tmp64;
    TNode<IntPtrT> tmp65;
    ca_.Bind(&block19, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
  }

  if (block21.is_used()) {
    TNode<Context> tmp66;
    TNode<Object> tmp67;
    TNode<JSFunction> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<JSArray> tmp73;
    TNode<FixedArray> tmp74;
    TNode<IntPtrT> tmp75;
    ca_.Bind(&block21, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<IntPtrT> tmp76;
    USE(tmp76);
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp79 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp74, tmp78});
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    tmp80 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp79});
    TNode<UintPtrT> tmp81;
    USE(tmp81);
    tmp81 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp72});
    TNode<UintPtrT> tmp82;
    USE(tmp82);
    tmp82 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp80});
    TNode<BoolT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp81}, TNode<UintPtrT>{tmp82});
    ca_.Branch(tmp83, &block28, &block29, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp74, tmp74, tmp76, tmp80, tmp72, tmp72, tmp74, tmp76, tmp80, tmp72, tmp72);
  }

  if (block28.is_used()) {
    TNode<Context> tmp84;
    TNode<Object> tmp85;
    TNode<JSFunction> tmp86;
    TNode<NativeContext> tmp87;
    TNode<Object> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<JSArray> tmp91;
    TNode<FixedArray> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<FixedArray> tmp94;
    TNode<FixedArray> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<HeapObject> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<IntPtrT> tmp104;
    ca_.Bind(&block28, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<IntPtrT> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp104}, TNode<IntPtrT>{tmp105});
    TNode<IntPtrT> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp101}, TNode<IntPtrT>{tmp106});
    TNode<HeapObject> tmp108;
    USE(tmp108);
    TNode<IntPtrT> tmp109;
    USE(tmp109);
    std::tie(tmp108, tmp109) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp100}, TNode<IntPtrT>{tmp107}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp108, tmp109}, tmp88);
    ca_.Goto(&block23, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93);
  }

  if (block29.is_used()) {
    TNode<Context> tmp110;
    TNode<Object> tmp111;
    TNode<JSFunction> tmp112;
    TNode<NativeContext> tmp113;
    TNode<Object> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<JSArray> tmp117;
    TNode<FixedArray> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<FixedArray> tmp120;
    TNode<FixedArray> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<HeapObject> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    ca_.Bind(&block29, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block22.is_used()) {
    TNode<Context> tmp131;
    TNode<Object> tmp132;
    TNode<JSFunction> tmp133;
    TNode<NativeContext> tmp134;
    TNode<Object> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<JSArray> tmp138;
    TNode<FixedArray> tmp139;
    TNode<IntPtrT> tmp140;
    ca_.Bind(&block22, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    TNode<IntPtrT> tmp141;
    USE(tmp141);
    tmp141 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp142;
    USE(tmp142);
    tmp142 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp137}, TNode<IntPtrT>{tmp141});
    TNode<IntPtrT> tmp143;
    USE(tmp143);
    tmp143 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp139});
    TNode<BoolT> tmp144;
    USE(tmp144);
    tmp144 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp137}, TNode<IntPtrT>{tmp143});
    ca_.Branch(tmp144, &block31, &block32, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp142, tmp143);
  }

  if (block31.is_used()) {
    TNode<Context> tmp145;
    TNode<Object> tmp146;
    TNode<JSFunction> tmp147;
    TNode<NativeContext> tmp148;
    TNode<Object> tmp149;
    TNode<IntPtrT> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<JSArray> tmp152;
    TNode<FixedArray> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<IntPtrT> tmp156;
    ca_.Bind(&block31, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    TNode<IntPtrT> tmp157;
    USE(tmp157);
    tmp157 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp158;
    USE(tmp158);
    tmp158 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp155});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp152, tmp157}, tmp158);
    TNode<IntPtrT> tmp159;
    USE(tmp159);
    tmp159 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp160;
    USE(tmp160);
    tmp160 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp161;
    USE(tmp161);
    tmp161 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp162 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp153, tmp161});
    TNode<IntPtrT> tmp163;
    USE(tmp163);
    tmp163 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp162});
    TNode<UintPtrT> tmp164;
    USE(tmp164);
    tmp164 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp151});
    TNode<UintPtrT> tmp165;
    USE(tmp165);
    tmp165 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp163});
    TNode<BoolT> tmp166;
    USE(tmp166);
    tmp166 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp164}, TNode<UintPtrT>{tmp165});
    ca_.Branch(tmp166, &block38, &block39, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp153, tmp153, tmp159, tmp163, tmp151, tmp151, tmp153, tmp159, tmp163, tmp151, tmp151);
  }

  if (block38.is_used()) {
    TNode<Context> tmp167;
    TNode<Object> tmp168;
    TNode<JSFunction> tmp169;
    TNode<NativeContext> tmp170;
    TNode<Object> tmp171;
    TNode<IntPtrT> tmp172;
    TNode<IntPtrT> tmp173;
    TNode<JSArray> tmp174;
    TNode<FixedArray> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<IntPtrT> tmp178;
    TNode<FixedArray> tmp179;
    TNode<FixedArray> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<IntPtrT> tmp182;
    TNode<IntPtrT> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<HeapObject> tmp185;
    TNode<IntPtrT> tmp186;
    TNode<IntPtrT> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    ca_.Bind(&block38, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189);
    TNode<IntPtrT> tmp190;
    USE(tmp190);
    tmp190 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp191;
    USE(tmp191);
    tmp191 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp189}, TNode<IntPtrT>{tmp190});
    TNode<IntPtrT> tmp192;
    USE(tmp192);
    tmp192 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp186}, TNode<IntPtrT>{tmp191});
    TNode<HeapObject> tmp193;
    USE(tmp193);
    TNode<IntPtrT> tmp194;
    USE(tmp194);
    std::tie(tmp193, tmp194) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp185}, TNode<IntPtrT>{tmp192}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp193, tmp194}, tmp171);
    ca_.Goto(&block33, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178);
  }

  if (block39.is_used()) {
    TNode<Context> tmp195;
    TNode<Object> tmp196;
    TNode<JSFunction> tmp197;
    TNode<NativeContext> tmp198;
    TNode<Object> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<JSArray> tmp202;
    TNode<FixedArray> tmp203;
    TNode<IntPtrT> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<IntPtrT> tmp206;
    TNode<FixedArray> tmp207;
    TNode<FixedArray> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<IntPtrT> tmp212;
    TNode<HeapObject> tmp213;
    TNode<IntPtrT> tmp214;
    TNode<IntPtrT> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<IntPtrT> tmp217;
    ca_.Bind(&block39, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block32.is_used()) {
    TNode<Context> tmp218;
    TNode<Object> tmp219;
    TNode<JSFunction> tmp220;
    TNode<NativeContext> tmp221;
    TNode<Object> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<JSArray> tmp225;
    TNode<FixedArray> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    ca_.Bind(&block32, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229);
    TNode<IntPtrT> tmp230;
    USE(tmp230);
    tmp230 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp228});
    TNode<IntPtrT> tmp231;
    USE(tmp231);
    tmp231 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    TNode<IntPtrT> tmp232;
    USE(tmp232);
    tmp232 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp230}, TNode<IntPtrT>{tmp231});
    TNode<IntPtrT> tmp233;
    USE(tmp233);
    tmp233 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp234;
    USE(tmp234);
    tmp234 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp226}, TNode<IntPtrT>{tmp233}, TNode<IntPtrT>{tmp229}, TNode<IntPtrT>{tmp232});
    TNode<IntPtrT> tmp235;
    USE(tmp235);
    tmp235 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp236;
    USE(tmp236);
    tmp236 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp237;
    USE(tmp237);
    tmp237 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp238 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp234, tmp237});
    TNode<IntPtrT> tmp239;
    USE(tmp239);
    tmp239 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp238});
    TNode<UintPtrT> tmp240;
    USE(tmp240);
    tmp240 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp224});
    TNode<UintPtrT> tmp241;
    USE(tmp241);
    tmp241 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp239});
    TNode<BoolT> tmp242;
    USE(tmp242);
    tmp242 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp240}, TNode<UintPtrT>{tmp241});
    ca_.Branch(tmp242, &block53, &block54, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp232, tmp234, tmp234, tmp234, tmp235, tmp239, tmp224, tmp224, tmp234, tmp235, tmp239, tmp224, tmp224);
  }

  if (block44.is_used()) {
    TNode<Context> tmp243;
    TNode<Object> tmp244;
    TNode<JSFunction> tmp245;
    TNode<NativeContext> tmp246;
    TNode<Object> tmp247;
    TNode<IntPtrT> tmp248;
    TNode<IntPtrT> tmp249;
    TNode<JSArray> tmp250;
    TNode<FixedArray> tmp251;
    TNode<IntPtrT> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<IntPtrT> tmp254;
    TNode<IntPtrT> tmp255;
    ca_.Bind(&block44, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 138);
  }

  if (block43.is_used()) {
    TNode<Context> tmp256;
    TNode<Object> tmp257;
    TNode<JSFunction> tmp258;
    TNode<NativeContext> tmp259;
    TNode<Object> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<IntPtrT> tmp262;
    TNode<JSArray> tmp263;
    TNode<FixedArray> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<IntPtrT> tmp267;
    TNode<IntPtrT> tmp268;
    ca_.Bind(&block43, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268);
  }

  if (block48.is_used()) {
    TNode<Context> tmp269;
    TNode<Object> tmp270;
    TNode<JSFunction> tmp271;
    TNode<NativeContext> tmp272;
    TNode<Object> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<IntPtrT> tmp275;
    TNode<JSArray> tmp276;
    TNode<FixedArray> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<IntPtrT> tmp279;
    TNode<IntPtrT> tmp280;
    TNode<IntPtrT> tmp281;
    ca_.Bind(&block48, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281);
    CodeStubAssembler(state_).FailAssert("Torque assert 'elementsLength < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 139);
  }

  if (block47.is_used()) {
    TNode<Context> tmp282;
    TNode<Object> tmp283;
    TNode<JSFunction> tmp284;
    TNode<NativeContext> tmp285;
    TNode<Object> tmp286;
    TNode<IntPtrT> tmp287;
    TNode<IntPtrT> tmp288;
    TNode<JSArray> tmp289;
    TNode<FixedArray> tmp290;
    TNode<IntPtrT> tmp291;
    TNode<IntPtrT> tmp292;
    TNode<IntPtrT> tmp293;
    TNode<IntPtrT> tmp294;
    ca_.Bind(&block47, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294);
  }

  if (block53.is_used()) {
    TNode<Context> tmp295;
    TNode<Object> tmp296;
    TNode<JSFunction> tmp297;
    TNode<NativeContext> tmp298;
    TNode<Object> tmp299;
    TNode<IntPtrT> tmp300;
    TNode<IntPtrT> tmp301;
    TNode<JSArray> tmp302;
    TNode<FixedArray> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<IntPtrT> tmp306;
    TNode<IntPtrT> tmp307;
    TNode<FixedArray> tmp308;
    TNode<FixedArray> tmp309;
    TNode<FixedArray> tmp310;
    TNode<IntPtrT> tmp311;
    TNode<IntPtrT> tmp312;
    TNode<IntPtrT> tmp313;
    TNode<IntPtrT> tmp314;
    TNode<HeapObject> tmp315;
    TNode<IntPtrT> tmp316;
    TNode<IntPtrT> tmp317;
    TNode<IntPtrT> tmp318;
    TNode<IntPtrT> tmp319;
    ca_.Bind(&block53, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319);
    TNode<IntPtrT> tmp320;
    USE(tmp320);
    tmp320 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp321;
    USE(tmp321);
    tmp321 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp319}, TNode<IntPtrT>{tmp320});
    TNode<IntPtrT> tmp322;
    USE(tmp322);
    tmp322 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp316}, TNode<IntPtrT>{tmp321});
    TNode<HeapObject> tmp323;
    USE(tmp323);
    TNode<IntPtrT> tmp324;
    USE(tmp324);
    std::tie(tmp323, tmp324) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp315}, TNode<IntPtrT>{tmp322}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp323, tmp324}, tmp299);
    TNode<IntPtrT> tmp325;
    USE(tmp325);
    tmp325 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp302, tmp325}, tmp308);
    TNode<IntPtrT> tmp326;
    USE(tmp326);
    tmp326 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp327;
    USE(tmp327);
    tmp327 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp305});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp302, tmp326}, tmp327);
    ca_.Goto(&block33, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303, tmp304, tmp305, tmp306);
  }

  if (block54.is_used()) {
    TNode<Context> tmp328;
    TNode<Object> tmp329;
    TNode<JSFunction> tmp330;
    TNode<NativeContext> tmp331;
    TNode<Object> tmp332;
    TNode<IntPtrT> tmp333;
    TNode<IntPtrT> tmp334;
    TNode<JSArray> tmp335;
    TNode<FixedArray> tmp336;
    TNode<IntPtrT> tmp337;
    TNode<IntPtrT> tmp338;
    TNode<IntPtrT> tmp339;
    TNode<IntPtrT> tmp340;
    TNode<FixedArray> tmp341;
    TNode<FixedArray> tmp342;
    TNode<FixedArray> tmp343;
    TNode<IntPtrT> tmp344;
    TNode<IntPtrT> tmp345;
    TNode<IntPtrT> tmp346;
    TNode<IntPtrT> tmp347;
    TNode<HeapObject> tmp348;
    TNode<IntPtrT> tmp349;
    TNode<IntPtrT> tmp350;
    TNode<IntPtrT> tmp351;
    TNode<IntPtrT> tmp352;
    ca_.Bind(&block54, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Context> tmp353;
    TNode<Object> tmp354;
    TNode<JSFunction> tmp355;
    TNode<NativeContext> tmp356;
    TNode<Object> tmp357;
    TNode<IntPtrT> tmp358;
    TNode<IntPtrT> tmp359;
    TNode<JSArray> tmp360;
    TNode<FixedArray> tmp361;
    TNode<IntPtrT> tmp362;
    TNode<IntPtrT> tmp363;
    TNode<IntPtrT> tmp364;
    ca_.Bind(&block33, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364);
    ca_.Goto(&block23, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362);
  }

  if (block23.is_used()) {
    TNode<Context> tmp365;
    TNode<Object> tmp366;
    TNode<JSFunction> tmp367;
    TNode<NativeContext> tmp368;
    TNode<Object> tmp369;
    TNode<IntPtrT> tmp370;
    TNode<IntPtrT> tmp371;
    TNode<JSArray> tmp372;
    TNode<FixedArray> tmp373;
    TNode<IntPtrT> tmp374;
    ca_.Bind(&block23, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374);
    TNode<Object> tmp375;
    USE(tmp375);
    tmp375 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp365}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp376;
    USE(tmp376);
    tmp376 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp365}, TNode<Object>{tmp375});
    TNode<Smi> tmp377;
    USE(tmp377);
    tmp377 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp378;
    USE(tmp378);
    tmp378 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp376}, TNode<Smi>{tmp377});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp365}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp378});
    TNode<Smi> tmp379;
    USE(tmp379);
    tmp379 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp380;
    USE(tmp380);
    tmp380 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp378}, TNode<Smi>{tmp379});
    ca_.Branch(tmp380, &block56, &block57, tmp365, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp378);
  }

  if (block56.is_used()) {
    TNode<Context> tmp381;
    TNode<Object> tmp382;
    TNode<JSFunction> tmp383;
    TNode<NativeContext> tmp384;
    TNode<Object> tmp385;
    TNode<IntPtrT> tmp386;
    TNode<IntPtrT> tmp387;
    TNode<JSArray> tmp388;
    TNode<FixedArray> tmp389;
    TNode<IntPtrT> tmp390;
    TNode<Smi> tmp391;
    ca_.Bind(&block56, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391);
    TNode<Object> tmp392;
    USE(tmp392);
    tmp392 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp381}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    TNode<PromiseCapability> tmp393;
    USE(tmp393);
    tmp393 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp381}, TNode<Object>{tmp392});
    TNode<IntPtrT> tmp394;
    USE(tmp394);
    tmp394 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp395 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp393, tmp394});
    TNode<Object> tmp396;
    USE(tmp396);
    tmp396 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp381}, TNode<Object>{tmp395});
    TNode<Oddball> tmp397;
    USE(tmp397);
    tmp397 = Undefined_0(state_);
    TNode<Object> tmp398;
    USE(tmp398);
    tmp398 = CodeStubAssembler(state_).Call(TNode<Context>{tmp381}, TNode<Object>{tmp396}, TNode<Object>{tmp397}, TNode<Object>{tmp388});
    ca_.Goto(&block57, tmp381, tmp382, tmp383, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391);
  }

  if (block57.is_used()) {
    TNode<Context> tmp399;
    TNode<Object> tmp400;
    TNode<JSFunction> tmp401;
    TNode<NativeContext> tmp402;
    TNode<Object> tmp403;
    TNode<IntPtrT> tmp404;
    TNode<IntPtrT> tmp405;
    TNode<JSArray> tmp406;
    TNode<FixedArray> tmp407;
    TNode<IntPtrT> tmp408;
    TNode<Smi> tmp409;
    ca_.Bind(&block57, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409);
    TNode<Oddball> tmp410;
    USE(tmp410);
    tmp410 = Undefined_0(state_);
    ca_.Goto(&block1, tmp399, tmp400, tmp401, tmp410);
  }

  if (block1.is_used()) {
    TNode<Context> tmp411;
    TNode<Object> tmp412;
    TNode<JSFunction> tmp413;
    TNode<Object> tmp414;
    ca_.Bind(&block1, &tmp411, &tmp412, &tmp413, &tmp414);
    ca_.Goto(&block58, tmp411, tmp412, tmp413, tmp414);
  }

    TNode<Context> tmp415;
    TNode<Object> tmp416;
    TNode<JSFunction> tmp417;
    TNode<Object> tmp418;
    ca_.Bind(&block58, &tmp415, &tmp416, &tmp417, &tmp418);
  return TNode<Object>{tmp418};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value, p_function);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<JSFunction> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<NativeContext> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp8});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp10, tmp12}, tmp11);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp11}, TNode<IntPtrT>{tmp13});
    TNode<JSFunction> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp14});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    TNode<HeapObject>tmp17 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp15, tmp16});
    TNode<Map> tmp18;
    USE(tmp18);
    tmp18 = UnsafeCast_Map_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp17});
    TNode<JSObject> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp18});
    TNode<String> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).StringConstant("status");
    TNode<String> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).StringConstant("fulfilled");
    TNode<Object> tmp22;
    tmp22 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp8, tmp19, tmp20, tmp21);
    USE(tmp22);
    TNode<String> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).StringConstant("value");
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp8, tmp19, tmp23, tmp9);
    USE(tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp25 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{tmp10}, &label0);
    ca_.Goto(&block15, tmp8, tmp9, tmp10, tmp11, tmp19, tmp10, tmp25);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp8, tmp9, tmp10, tmp11, tmp19, tmp10);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<JSFunction> tmp28;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'context.length == PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength' failed", "src/builtins/promise-all-element-closure.tq", 96);
  }

  if (block6.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<JSFunction> tmp31;
    ca_.Bind(&block6, &tmp29, &tmp30, &tmp31);
  }

  if (block12.is_used()) {
    TNode<Context> tmp32;
    TNode<Object> tmp33;
    TNode<JSFunction> tmp34;
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    ca_.Bind(&block12, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", "src/builtins/promise-all-element-closure.tq", 107);
  }

  if (block11.is_used()) {
    TNode<Context> tmp37;
    TNode<Object> tmp38;
    TNode<JSFunction> tmp39;
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block11, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
  }

  if (block16.is_used()) {
    TNode<Context> tmp42;
    TNode<Object> tmp43;
    TNode<JSFunction> tmp44;
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<JSFunction> tmp47;
    ca_.Bind(&block16, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp48;
    TNode<Object> tmp49;
    TNode<JSFunction> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<JSFunction> tmp53;
    TNode<IntPtrT> tmp54;
    ca_.Bind(&block15, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp54}, TNode<IntPtrT>{tmp55});
    TNode<Object> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp48}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<JSArray> tmp58;
    USE(tmp58);
    tmp58 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp48}, TNode<Object>{tmp57});
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp60 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp58, tmp59});
    TNode<FixedArray> tmp61;
    USE(tmp61);
    tmp61 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp48}, TNode<Object>{tmp60});
    TNode<IntPtrT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp63 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp58, tmp62});
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    tmp64 = Convert_intptr_Number_0(state_, TNode<Number>{tmp63});
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp56}, TNode<IntPtrT>{tmp64});
    ca_.Branch(tmp65, &block21, &block22, tmp48, tmp49, tmp50, tmp51, tmp52, tmp54, tmp56, tmp58, tmp61, tmp64);
  }

  if (block20.is_used()) {
    TNode<Context> tmp66;
    TNode<Object> tmp67;
    TNode<JSFunction> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<IntPtrT> tmp71;
    ca_.Bind(&block20, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", "src/builtins/promise-all-element-closure.tq", 110);
  }

  if (block19.is_used()) {
    TNode<Context> tmp72;
    TNode<Object> tmp73;
    TNode<JSFunction> tmp74;
    TNode<NativeContext> tmp75;
    TNode<Object> tmp76;
    TNode<IntPtrT> tmp77;
    ca_.Bind(&block19, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
  }

  if (block21.is_used()) {
    TNode<Context> tmp78;
    TNode<Object> tmp79;
    TNode<JSFunction> tmp80;
    TNode<NativeContext> tmp81;
    TNode<Object> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<JSArray> tmp85;
    TNode<FixedArray> tmp86;
    TNode<IntPtrT> tmp87;
    ca_.Bind(&block21, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp89;
    USE(tmp89);
    tmp89 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp91 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp86, tmp90});
    TNode<IntPtrT> tmp92;
    USE(tmp92);
    tmp92 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp91});
    TNode<UintPtrT> tmp93;
    USE(tmp93);
    tmp93 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp84});
    TNode<UintPtrT> tmp94;
    USE(tmp94);
    tmp94 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp92});
    TNode<BoolT> tmp95;
    USE(tmp95);
    tmp95 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp93}, TNode<UintPtrT>{tmp94});
    ca_.Branch(tmp95, &block28, &block29, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp86, tmp86, tmp88, tmp92, tmp84, tmp84, tmp86, tmp88, tmp92, tmp84, tmp84);
  }

  if (block28.is_used()) {
    TNode<Context> tmp96;
    TNode<Object> tmp97;
    TNode<JSFunction> tmp98;
    TNode<NativeContext> tmp99;
    TNode<Object> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<JSArray> tmp103;
    TNode<FixedArray> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<FixedArray> tmp106;
    TNode<FixedArray> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<IntPtrT> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<HeapObject> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    ca_.Bind(&block28, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    TNode<IntPtrT> tmp117;
    USE(tmp117);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp118;
    USE(tmp118);
    tmp118 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp116}, TNode<IntPtrT>{tmp117});
    TNode<IntPtrT> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp113}, TNode<IntPtrT>{tmp118});
    TNode<HeapObject> tmp120;
    USE(tmp120);
    TNode<IntPtrT> tmp121;
    USE(tmp121);
    std::tie(tmp120, tmp121) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp112}, TNode<IntPtrT>{tmp119}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp120, tmp121}, tmp100);
    ca_.Goto(&block23, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105);
  }

  if (block29.is_used()) {
    TNode<Context> tmp122;
    TNode<Object> tmp123;
    TNode<JSFunction> tmp124;
    TNode<NativeContext> tmp125;
    TNode<Object> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<JSArray> tmp129;
    TNode<FixedArray> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<FixedArray> tmp132;
    TNode<FixedArray> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<HeapObject> tmp138;
    TNode<IntPtrT> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    ca_.Bind(&block29, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block22.is_used()) {
    TNode<Context> tmp143;
    TNode<Object> tmp144;
    TNode<JSFunction> tmp145;
    TNode<NativeContext> tmp146;
    TNode<Object> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<JSArray> tmp150;
    TNode<FixedArray> tmp151;
    TNode<IntPtrT> tmp152;
    ca_.Bind(&block22, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    TNode<IntPtrT> tmp153;
    USE(tmp153);
    tmp153 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp154;
    USE(tmp154);
    tmp154 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp149}, TNode<IntPtrT>{tmp153});
    TNode<IntPtrT> tmp155;
    USE(tmp155);
    tmp155 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp151});
    TNode<BoolT> tmp156;
    USE(tmp156);
    tmp156 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp149}, TNode<IntPtrT>{tmp155});
    ca_.Branch(tmp156, &block31, &block32, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp154, tmp155);
  }

  if (block31.is_used()) {
    TNode<Context> tmp157;
    TNode<Object> tmp158;
    TNode<JSFunction> tmp159;
    TNode<NativeContext> tmp160;
    TNode<Object> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<JSArray> tmp164;
    TNode<FixedArray> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    ca_.Bind(&block31, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    TNode<IntPtrT> tmp169;
    USE(tmp169);
    tmp169 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp170;
    USE(tmp170);
    tmp170 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp167});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp164, tmp169}, tmp170);
    TNode<IntPtrT> tmp171;
    USE(tmp171);
    tmp171 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp172;
    USE(tmp172);
    tmp172 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp174 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp165, tmp173});
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp174});
    TNode<UintPtrT> tmp176;
    USE(tmp176);
    tmp176 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp163});
    TNode<UintPtrT> tmp177;
    USE(tmp177);
    tmp177 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp175});
    TNode<BoolT> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp176}, TNode<UintPtrT>{tmp177});
    ca_.Branch(tmp178, &block38, &block39, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp165, tmp165, tmp171, tmp175, tmp163, tmp163, tmp165, tmp171, tmp175, tmp163, tmp163);
  }

  if (block38.is_used()) {
    TNode<Context> tmp179;
    TNode<Object> tmp180;
    TNode<JSFunction> tmp181;
    TNode<NativeContext> tmp182;
    TNode<Object> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<JSArray> tmp186;
    TNode<FixedArray> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<FixedArray> tmp191;
    TNode<FixedArray> tmp192;
    TNode<IntPtrT> tmp193;
    TNode<IntPtrT> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<HeapObject> tmp197;
    TNode<IntPtrT> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    ca_.Bind(&block38, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    TNode<IntPtrT> tmp202;
    USE(tmp202);
    tmp202 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp203;
    USE(tmp203);
    tmp203 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp201}, TNode<IntPtrT>{tmp202});
    TNode<IntPtrT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp198}, TNode<IntPtrT>{tmp203});
    TNode<HeapObject> tmp205;
    USE(tmp205);
    TNode<IntPtrT> tmp206;
    USE(tmp206);
    std::tie(tmp205, tmp206) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp197}, TNode<IntPtrT>{tmp204}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp205, tmp206}, tmp183);
    ca_.Goto(&block33, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190);
  }

  if (block39.is_used()) {
    TNode<Context> tmp207;
    TNode<Object> tmp208;
    TNode<JSFunction> tmp209;
    TNode<NativeContext> tmp210;
    TNode<Object> tmp211;
    TNode<IntPtrT> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<JSArray> tmp214;
    TNode<FixedArray> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<IntPtrT> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<FixedArray> tmp219;
    TNode<FixedArray> tmp220;
    TNode<IntPtrT> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<HeapObject> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    ca_.Bind(&block39, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block32.is_used()) {
    TNode<Context> tmp230;
    TNode<Object> tmp231;
    TNode<JSFunction> tmp232;
    TNode<NativeContext> tmp233;
    TNode<Object> tmp234;
    TNode<IntPtrT> tmp235;
    TNode<IntPtrT> tmp236;
    TNode<JSArray> tmp237;
    TNode<FixedArray> tmp238;
    TNode<IntPtrT> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<IntPtrT> tmp241;
    ca_.Bind(&block32, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241);
    TNode<IntPtrT> tmp242;
    USE(tmp242);
    tmp242 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp240});
    TNode<IntPtrT> tmp243;
    USE(tmp243);
    tmp243 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    TNode<IntPtrT> tmp244;
    USE(tmp244);
    tmp244 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp242}, TNode<IntPtrT>{tmp243});
    TNode<IntPtrT> tmp245;
    USE(tmp245);
    tmp245 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp246;
    USE(tmp246);
    tmp246 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp238}, TNode<IntPtrT>{tmp245}, TNode<IntPtrT>{tmp241}, TNode<IntPtrT>{tmp244});
    TNode<IntPtrT> tmp247;
    USE(tmp247);
    tmp247 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp248;
    USE(tmp248);
    tmp248 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp249;
    USE(tmp249);
    tmp249 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp250 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp246, tmp249});
    TNode<IntPtrT> tmp251;
    USE(tmp251);
    tmp251 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp250});
    TNode<UintPtrT> tmp252;
    USE(tmp252);
    tmp252 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp236});
    TNode<UintPtrT> tmp253;
    USE(tmp253);
    tmp253 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp251});
    TNode<BoolT> tmp254;
    USE(tmp254);
    tmp254 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp252}, TNode<UintPtrT>{tmp253});
    ca_.Branch(tmp254, &block53, &block54, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp244, tmp246, tmp246, tmp246, tmp247, tmp251, tmp236, tmp236, tmp246, tmp247, tmp251, tmp236, tmp236);
  }

  if (block44.is_used()) {
    TNode<Context> tmp255;
    TNode<Object> tmp256;
    TNode<JSFunction> tmp257;
    TNode<NativeContext> tmp258;
    TNode<Object> tmp259;
    TNode<IntPtrT> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<JSArray> tmp262;
    TNode<FixedArray> tmp263;
    TNode<IntPtrT> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<IntPtrT> tmp267;
    ca_.Bind(&block44, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 138);
  }

  if (block43.is_used()) {
    TNode<Context> tmp268;
    TNode<Object> tmp269;
    TNode<JSFunction> tmp270;
    TNode<NativeContext> tmp271;
    TNode<Object> tmp272;
    TNode<IntPtrT> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<JSArray> tmp275;
    TNode<FixedArray> tmp276;
    TNode<IntPtrT> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<IntPtrT> tmp279;
    TNode<IntPtrT> tmp280;
    ca_.Bind(&block43, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280);
  }

  if (block48.is_used()) {
    TNode<Context> tmp281;
    TNode<Object> tmp282;
    TNode<JSFunction> tmp283;
    TNode<NativeContext> tmp284;
    TNode<Object> tmp285;
    TNode<IntPtrT> tmp286;
    TNode<IntPtrT> tmp287;
    TNode<JSArray> tmp288;
    TNode<FixedArray> tmp289;
    TNode<IntPtrT> tmp290;
    TNode<IntPtrT> tmp291;
    TNode<IntPtrT> tmp292;
    TNode<IntPtrT> tmp293;
    ca_.Bind(&block48, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293);
    CodeStubAssembler(state_).FailAssert("Torque assert 'elementsLength < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 139);
  }

  if (block47.is_used()) {
    TNode<Context> tmp294;
    TNode<Object> tmp295;
    TNode<JSFunction> tmp296;
    TNode<NativeContext> tmp297;
    TNode<Object> tmp298;
    TNode<IntPtrT> tmp299;
    TNode<IntPtrT> tmp300;
    TNode<JSArray> tmp301;
    TNode<FixedArray> tmp302;
    TNode<IntPtrT> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<IntPtrT> tmp306;
    ca_.Bind(&block47, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306);
  }

  if (block53.is_used()) {
    TNode<Context> tmp307;
    TNode<Object> tmp308;
    TNode<JSFunction> tmp309;
    TNode<NativeContext> tmp310;
    TNode<Object> tmp311;
    TNode<IntPtrT> tmp312;
    TNode<IntPtrT> tmp313;
    TNode<JSArray> tmp314;
    TNode<FixedArray> tmp315;
    TNode<IntPtrT> tmp316;
    TNode<IntPtrT> tmp317;
    TNode<IntPtrT> tmp318;
    TNode<IntPtrT> tmp319;
    TNode<FixedArray> tmp320;
    TNode<FixedArray> tmp321;
    TNode<FixedArray> tmp322;
    TNode<IntPtrT> tmp323;
    TNode<IntPtrT> tmp324;
    TNode<IntPtrT> tmp325;
    TNode<IntPtrT> tmp326;
    TNode<HeapObject> tmp327;
    TNode<IntPtrT> tmp328;
    TNode<IntPtrT> tmp329;
    TNode<IntPtrT> tmp330;
    TNode<IntPtrT> tmp331;
    ca_.Bind(&block53, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331);
    TNode<IntPtrT> tmp332;
    USE(tmp332);
    tmp332 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp333;
    USE(tmp333);
    tmp333 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp331}, TNode<IntPtrT>{tmp332});
    TNode<IntPtrT> tmp334;
    USE(tmp334);
    tmp334 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp328}, TNode<IntPtrT>{tmp333});
    TNode<HeapObject> tmp335;
    USE(tmp335);
    TNode<IntPtrT> tmp336;
    USE(tmp336);
    std::tie(tmp335, tmp336) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp327}, TNode<IntPtrT>{tmp334}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp335, tmp336}, tmp311);
    TNode<IntPtrT> tmp337;
    USE(tmp337);
    tmp337 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp314, tmp337}, tmp320);
    TNode<IntPtrT> tmp338;
    USE(tmp338);
    tmp338 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp339;
    USE(tmp339);
    tmp339 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp317});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp314, tmp338}, tmp339);
    ca_.Goto(&block33, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318);
  }

  if (block54.is_used()) {
    TNode<Context> tmp340;
    TNode<Object> tmp341;
    TNode<JSFunction> tmp342;
    TNode<NativeContext> tmp343;
    TNode<Object> tmp344;
    TNode<IntPtrT> tmp345;
    TNode<IntPtrT> tmp346;
    TNode<JSArray> tmp347;
    TNode<FixedArray> tmp348;
    TNode<IntPtrT> tmp349;
    TNode<IntPtrT> tmp350;
    TNode<IntPtrT> tmp351;
    TNode<IntPtrT> tmp352;
    TNode<FixedArray> tmp353;
    TNode<FixedArray> tmp354;
    TNode<FixedArray> tmp355;
    TNode<IntPtrT> tmp356;
    TNode<IntPtrT> tmp357;
    TNode<IntPtrT> tmp358;
    TNode<IntPtrT> tmp359;
    TNode<HeapObject> tmp360;
    TNode<IntPtrT> tmp361;
    TNode<IntPtrT> tmp362;
    TNode<IntPtrT> tmp363;
    TNode<IntPtrT> tmp364;
    ca_.Bind(&block54, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Context> tmp365;
    TNode<Object> tmp366;
    TNode<JSFunction> tmp367;
    TNode<NativeContext> tmp368;
    TNode<Object> tmp369;
    TNode<IntPtrT> tmp370;
    TNode<IntPtrT> tmp371;
    TNode<JSArray> tmp372;
    TNode<FixedArray> tmp373;
    TNode<IntPtrT> tmp374;
    TNode<IntPtrT> tmp375;
    TNode<IntPtrT> tmp376;
    ca_.Bind(&block33, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376);
    ca_.Goto(&block23, tmp365, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374);
  }

  if (block23.is_used()) {
    TNode<Context> tmp377;
    TNode<Object> tmp378;
    TNode<JSFunction> tmp379;
    TNode<NativeContext> tmp380;
    TNode<Object> tmp381;
    TNode<IntPtrT> tmp382;
    TNode<IntPtrT> tmp383;
    TNode<JSArray> tmp384;
    TNode<FixedArray> tmp385;
    TNode<IntPtrT> tmp386;
    ca_.Bind(&block23, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386);
    TNode<Object> tmp387;
    USE(tmp387);
    tmp387 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp377}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp388;
    USE(tmp388);
    tmp388 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp377}, TNode<Object>{tmp387});
    TNode<Smi> tmp389;
    USE(tmp389);
    tmp389 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp390;
    USE(tmp390);
    tmp390 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp388}, TNode<Smi>{tmp389});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp377}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp390});
    TNode<Smi> tmp391;
    USE(tmp391);
    tmp391 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp392;
    USE(tmp392);
    tmp392 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp390}, TNode<Smi>{tmp391});
    ca_.Branch(tmp392, &block56, &block57, tmp377, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383, tmp384, tmp385, tmp386, tmp390);
  }

  if (block56.is_used()) {
    TNode<Context> tmp393;
    TNode<Object> tmp394;
    TNode<JSFunction> tmp395;
    TNode<NativeContext> tmp396;
    TNode<Object> tmp397;
    TNode<IntPtrT> tmp398;
    TNode<IntPtrT> tmp399;
    TNode<JSArray> tmp400;
    TNode<FixedArray> tmp401;
    TNode<IntPtrT> tmp402;
    TNode<Smi> tmp403;
    ca_.Bind(&block56, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403);
    TNode<Object> tmp404;
    USE(tmp404);
    tmp404 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp393}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    TNode<PromiseCapability> tmp405;
    USE(tmp405);
    tmp405 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp393}, TNode<Object>{tmp404});
    TNode<IntPtrT> tmp406;
    USE(tmp406);
    tmp406 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp407 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp405, tmp406});
    TNode<Object> tmp408;
    USE(tmp408);
    tmp408 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp393}, TNode<Object>{tmp407});
    TNode<Oddball> tmp409;
    USE(tmp409);
    tmp409 = Undefined_0(state_);
    TNode<Object> tmp410;
    USE(tmp410);
    tmp410 = CodeStubAssembler(state_).Call(TNode<Context>{tmp393}, TNode<Object>{tmp408}, TNode<Object>{tmp409}, TNode<Object>{tmp400});
    ca_.Goto(&block57, tmp393, tmp394, tmp395, tmp396, tmp397, tmp398, tmp399, tmp400, tmp401, tmp402, tmp403);
  }

  if (block57.is_used()) {
    TNode<Context> tmp411;
    TNode<Object> tmp412;
    TNode<JSFunction> tmp413;
    TNode<NativeContext> tmp414;
    TNode<Object> tmp415;
    TNode<IntPtrT> tmp416;
    TNode<IntPtrT> tmp417;
    TNode<JSArray> tmp418;
    TNode<FixedArray> tmp419;
    TNode<IntPtrT> tmp420;
    TNode<Smi> tmp421;
    ca_.Bind(&block57, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421);
    TNode<Oddball> tmp422;
    USE(tmp422);
    tmp422 = Undefined_0(state_);
    ca_.Goto(&block1, tmp411, tmp412, tmp413, tmp422);
  }

  if (block1.is_used()) {
    TNode<Context> tmp423;
    TNode<Object> tmp424;
    TNode<JSFunction> tmp425;
    TNode<Object> tmp426;
    ca_.Bind(&block1, &tmp423, &tmp424, &tmp425, &tmp426);
    ca_.Goto(&block58, tmp423, tmp424, tmp425, tmp426);
  }

    TNode<Context> tmp427;
    TNode<Object> tmp428;
    TNode<JSFunction> tmp429;
    TNode<Object> tmp430;
    ca_.Bind(&block58, &tmp427, &tmp428, &tmp429, &tmp430);
  return TNode<Object>{tmp430};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, JSFunction, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, NativeContext, Object, IntPtrT, IntPtrT, JSArray, FixedArray, IntPtrT, Smi> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value, p_function);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<JSFunction> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<JSFunction> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<NativeContext> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp8});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp10, tmp12}, tmp11);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp11}, TNode<IntPtrT>{tmp13});
    TNode<JSFunction> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp14});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    TNode<HeapObject>tmp17 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp15, tmp16});
    TNode<Map> tmp18;
    USE(tmp18);
    tmp18 = UnsafeCast_Map_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp17});
    TNode<JSObject> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp18});
    TNode<String> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).StringConstant("status");
    TNode<String> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).StringConstant("rejected");
    TNode<Object> tmp22;
    tmp22 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp8, tmp19, tmp20, tmp21);
    USE(tmp22);
    TNode<String> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).StringConstant("reason");
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp8, tmp19, tmp23, tmp9);
    USE(tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp25 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{tmp10}, &label0);
    ca_.Goto(&block15, tmp8, tmp9, tmp10, tmp11, tmp19, tmp10, tmp25);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp8, tmp9, tmp10, tmp11, tmp19, tmp10);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<JSFunction> tmp28;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'context.length == PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength' failed", "src/builtins/promise-all-element-closure.tq", 96);
  }

  if (block6.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<JSFunction> tmp31;
    ca_.Bind(&block6, &tmp29, &tmp30, &tmp31);
  }

  if (block12.is_used()) {
    TNode<Context> tmp32;
    TNode<Object> tmp33;
    TNode<JSFunction> tmp34;
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    ca_.Bind(&block12, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", "src/builtins/promise-all-element-closure.tq", 107);
  }

  if (block11.is_used()) {
    TNode<Context> tmp37;
    TNode<Object> tmp38;
    TNode<JSFunction> tmp39;
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block11, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
  }

  if (block16.is_used()) {
    TNode<Context> tmp42;
    TNode<Object> tmp43;
    TNode<JSFunction> tmp44;
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<JSFunction> tmp47;
    ca_.Bind(&block16, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp48;
    TNode<Object> tmp49;
    TNode<JSFunction> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<JSFunction> tmp53;
    TNode<IntPtrT> tmp54;
    ca_.Bind(&block15, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp54}, TNode<IntPtrT>{tmp55});
    TNode<Object> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp48}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<JSArray> tmp58;
    USE(tmp58);
    tmp58 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp48}, TNode<Object>{tmp57});
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp60 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp58, tmp59});
    TNode<FixedArray> tmp61;
    USE(tmp61);
    tmp61 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp48}, TNode<Object>{tmp60});
    TNode<IntPtrT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number>tmp63 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp58, tmp62});
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    tmp64 = Convert_intptr_Number_0(state_, TNode<Number>{tmp63});
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp56}, TNode<IntPtrT>{tmp64});
    ca_.Branch(tmp65, &block21, &block22, tmp48, tmp49, tmp50, tmp51, tmp52, tmp54, tmp56, tmp58, tmp61, tmp64);
  }

  if (block20.is_used()) {
    TNode<Context> tmp66;
    TNode<Object> tmp67;
    TNode<JSFunction> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<IntPtrT> tmp71;
    ca_.Bind(&block20, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", "src/builtins/promise-all-element-closure.tq", 110);
  }

  if (block19.is_used()) {
    TNode<Context> tmp72;
    TNode<Object> tmp73;
    TNode<JSFunction> tmp74;
    TNode<NativeContext> tmp75;
    TNode<Object> tmp76;
    TNode<IntPtrT> tmp77;
    ca_.Bind(&block19, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
  }

  if (block21.is_used()) {
    TNode<Context> tmp78;
    TNode<Object> tmp79;
    TNode<JSFunction> tmp80;
    TNode<NativeContext> tmp81;
    TNode<Object> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<JSArray> tmp85;
    TNode<FixedArray> tmp86;
    TNode<IntPtrT> tmp87;
    ca_.Bind(&block21, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp89;
    USE(tmp89);
    tmp89 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp91 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp86, tmp90});
    TNode<IntPtrT> tmp92;
    USE(tmp92);
    tmp92 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp91});
    TNode<UintPtrT> tmp93;
    USE(tmp93);
    tmp93 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp84});
    TNode<UintPtrT> tmp94;
    USE(tmp94);
    tmp94 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp92});
    TNode<BoolT> tmp95;
    USE(tmp95);
    tmp95 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp93}, TNode<UintPtrT>{tmp94});
    ca_.Branch(tmp95, &block28, &block29, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp86, tmp86, tmp88, tmp92, tmp84, tmp84, tmp86, tmp88, tmp92, tmp84, tmp84);
  }

  if (block28.is_used()) {
    TNode<Context> tmp96;
    TNode<Object> tmp97;
    TNode<JSFunction> tmp98;
    TNode<NativeContext> tmp99;
    TNode<Object> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<JSArray> tmp103;
    TNode<FixedArray> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<FixedArray> tmp106;
    TNode<FixedArray> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<IntPtrT> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<HeapObject> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    ca_.Bind(&block28, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    TNode<IntPtrT> tmp117;
    USE(tmp117);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp118;
    USE(tmp118);
    tmp118 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp116}, TNode<IntPtrT>{tmp117});
    TNode<IntPtrT> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp113}, TNode<IntPtrT>{tmp118});
    TNode<HeapObject> tmp120;
    USE(tmp120);
    TNode<IntPtrT> tmp121;
    USE(tmp121);
    std::tie(tmp120, tmp121) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp112}, TNode<IntPtrT>{tmp119}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp120, tmp121}, tmp100);
    ca_.Goto(&block23, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105);
  }

  if (block29.is_used()) {
    TNode<Context> tmp122;
    TNode<Object> tmp123;
    TNode<JSFunction> tmp124;
    TNode<NativeContext> tmp125;
    TNode<Object> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<JSArray> tmp129;
    TNode<FixedArray> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<FixedArray> tmp132;
    TNode<FixedArray> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<HeapObject> tmp138;
    TNode<IntPtrT> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    ca_.Bind(&block29, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block22.is_used()) {
    TNode<Context> tmp143;
    TNode<Object> tmp144;
    TNode<JSFunction> tmp145;
    TNode<NativeContext> tmp146;
    TNode<Object> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<JSArray> tmp150;
    TNode<FixedArray> tmp151;
    TNode<IntPtrT> tmp152;
    ca_.Bind(&block22, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    TNode<IntPtrT> tmp153;
    USE(tmp153);
    tmp153 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp154;
    USE(tmp154);
    tmp154 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp149}, TNode<IntPtrT>{tmp153});
    TNode<IntPtrT> tmp155;
    USE(tmp155);
    tmp155 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp151});
    TNode<BoolT> tmp156;
    USE(tmp156);
    tmp156 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp149}, TNode<IntPtrT>{tmp155});
    ca_.Branch(tmp156, &block31, &block32, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp154, tmp155);
  }

  if (block31.is_used()) {
    TNode<Context> tmp157;
    TNode<Object> tmp158;
    TNode<JSFunction> tmp159;
    TNode<NativeContext> tmp160;
    TNode<Object> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<JSArray> tmp164;
    TNode<FixedArray> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    ca_.Bind(&block31, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    TNode<IntPtrT> tmp169;
    USE(tmp169);
    tmp169 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp170;
    USE(tmp170);
    tmp170 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp167});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp164, tmp169}, tmp170);
    TNode<IntPtrT> tmp171;
    USE(tmp171);
    tmp171 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp172;
    USE(tmp172);
    tmp172 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp174 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp165, tmp173});
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp174});
    TNode<UintPtrT> tmp176;
    USE(tmp176);
    tmp176 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp163});
    TNode<UintPtrT> tmp177;
    USE(tmp177);
    tmp177 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp175});
    TNode<BoolT> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp176}, TNode<UintPtrT>{tmp177});
    ca_.Branch(tmp178, &block38, &block39, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp165, tmp165, tmp171, tmp175, tmp163, tmp163, tmp165, tmp171, tmp175, tmp163, tmp163);
  }

  if (block38.is_used()) {
    TNode<Context> tmp179;
    TNode<Object> tmp180;
    TNode<JSFunction> tmp181;
    TNode<NativeContext> tmp182;
    TNode<Object> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<JSArray> tmp186;
    TNode<FixedArray> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<FixedArray> tmp191;
    TNode<FixedArray> tmp192;
    TNode<IntPtrT> tmp193;
    TNode<IntPtrT> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<HeapObject> tmp197;
    TNode<IntPtrT> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    ca_.Bind(&block38, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    TNode<IntPtrT> tmp202;
    USE(tmp202);
    tmp202 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp203;
    USE(tmp203);
    tmp203 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp201}, TNode<IntPtrT>{tmp202});
    TNode<IntPtrT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp198}, TNode<IntPtrT>{tmp203});
    TNode<HeapObject> tmp205;
    USE(tmp205);
    TNode<IntPtrT> tmp206;
    USE(tmp206);
    std::tie(tmp205, tmp206) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp197}, TNode<IntPtrT>{tmp204}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp205, tmp206}, tmp183);
    ca_.Goto(&block33, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190);
  }

  if (block39.is_used()) {
    TNode<Context> tmp207;
    TNode<Object> tmp208;
    TNode<JSFunction> tmp209;
    TNode<NativeContext> tmp210;
    TNode<Object> tmp211;
    TNode<IntPtrT> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<JSArray> tmp214;
    TNode<FixedArray> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<IntPtrT> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<FixedArray> tmp219;
    TNode<FixedArray> tmp220;
    TNode<IntPtrT> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<HeapObject> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    ca_.Bind(&block39, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block32.is_used()) {
    TNode<Context> tmp230;
    TNode<Object> tmp231;
    TNode<JSFunction> tmp232;
    TNode<NativeContext> tmp233;
    TNode<Object> tmp234;
    TNode<IntPtrT> tmp235;
    TNode<IntPtrT> tmp236;
    TNode<JSArray> tmp237;
    TNode<FixedArray> tmp238;
    TNode<IntPtrT> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<IntPtrT> tmp241;
    ca_.Bind(&block32, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241);
    TNode<IntPtrT> tmp242;
    USE(tmp242);
    tmp242 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp240});
    TNode<IntPtrT> tmp243;
    USE(tmp243);
    tmp243 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    TNode<IntPtrT> tmp244;
    USE(tmp244);
    tmp244 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp242}, TNode<IntPtrT>{tmp243});
    TNode<IntPtrT> tmp245;
    USE(tmp245);
    tmp245 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp246;
    USE(tmp246);
    tmp246 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp238}, TNode<IntPtrT>{tmp245}, TNode<IntPtrT>{tmp241}, TNode<IntPtrT>{tmp244});
    TNode<IntPtrT> tmp247;
    USE(tmp247);
    tmp247 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp248;
    USE(tmp248);
    tmp248 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp249;
    USE(tmp249);
    tmp249 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp250 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp246, tmp249});
    TNode<IntPtrT> tmp251;
    USE(tmp251);
    tmp251 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp250});
    TNode<UintPtrT> tmp252;
    USE(tmp252);
    tmp252 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp236});
    TNode<UintPtrT> tmp253;
    USE(tmp253);
    tmp253 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp251});
    TNode<BoolT> tmp254;
    USE(tmp254);
    tmp254 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp252}, TNode<UintPtrT>{tmp253});
    ca_.Branch(tmp254, &block53, &block54, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp244, tmp246, tmp246, tmp246, tmp247, tmp251, tmp236, tmp236, tmp246, tmp247, tmp251, tmp236, tmp236);
  }

  if (block44.is_used()) {
    TNode<Context> tmp255;
    TNode<Object> tmp256;
    TNode<JSFunction> tmp257;
    TNode<NativeContext> tmp258;
    TNode<Object> tmp259;
    TNode<IntPtrT> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<JSArray> tmp262;
    TNode<FixedArray> tmp263;
    TNode<IntPtrT> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<IntPtrT> tmp267;
    ca_.Bind(&block44, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 138);
  }

  if (block43.is_used()) {
    TNode<Context> tmp268;
    TNode<Object> tmp269;
    TNode<JSFunction> tmp270;
    TNode<NativeContext> tmp271;
    TNode<Object> tmp272;
    TNode<IntPtrT> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<JSArray> tmp275;
    TNode<FixedArray> tmp276;
    TNode<IntPtrT> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<IntPtrT> tmp279;
    TNode<IntPtrT> tmp280;
    ca_.Bind(&block43, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280);
  }

  if (block48.is_used()) {
    TNode<Context> tmp281;
    TNode<Object> tmp282;
    TNode<JSFunction> tmp283;
    TNode<NativeContext> tmp284;
    TNode<Object> tmp285;
    TNode<IntPtrT> tmp286;
    TNode<IntPtrT> tmp287;
    TNode<JSArray> tmp288;
    TNode<FixedArray> tmp289;
    TNode<IntPtrT> tmp290;
    TNode<IntPtrT> tmp291;
    TNode<IntPtrT> tmp292;
    TNode<IntPtrT> tmp293;
    ca_.Bind(&block48, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293);
    CodeStubAssembler(state_).FailAssert("Torque assert 'elementsLength < newElementsLength' failed", "src/builtins/promise-all-element-closure.tq", 139);
  }

  if (block47.is_used()) {
    TNode<Context> tmp294;
    TNode<Object> tmp295;
    TNode<JSFunction> tmp296;
    TNode<NativeContext> tmp297;
    TNode<Object> tmp298;
    TNode<IntPtrT> tmp299;
    TNode<IntPtrT> tmp300;
    TNode<JSArray> tmp301;
    TNode<FixedArray> tmp302;
    TNode<IntPtrT> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<IntPtrT> tmp306;
    ca_.Bind(&block47, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306);
  }

  if (block53.is_used()) {
    TNode<Context> tmp307;
    TNode<Object> tmp308;
    TNode<JSFunction> tmp309;
    TNode<NativeContext> tmp310;
    TNode<Object> tmp311;
    TNode<IntPtrT> tmp312;
    TNode<IntPtrT> tmp313;
    TNode<JSArray> tmp314;
    TNode<FixedArray> tmp315;
    TNode<IntPtrT> tmp316;
    TNode<IntPtrT> tmp317;
    TNode<IntPtrT> tmp318;
    TNode<IntPtrT> tmp319;
    TNode<FixedArray> tmp320;
    TNode<FixedArray> tmp321;
    TNode<FixedArray> tmp322;
    TNode<IntPtrT> tmp323;
    TNode<IntPtrT> tmp324;
    TNode<IntPtrT> tmp325;
    TNode<IntPtrT> tmp326;
    TNode<HeapObject> tmp327;
    TNode<IntPtrT> tmp328;
    TNode<IntPtrT> tmp329;
    TNode<IntPtrT> tmp330;
    TNode<IntPtrT> tmp331;
    ca_.Bind(&block53, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331);
    TNode<IntPtrT> tmp332;
    USE(tmp332);
    tmp332 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp333;
    USE(tmp333);
    tmp333 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp331}, TNode<IntPtrT>{tmp332});
    TNode<IntPtrT> tmp334;
    USE(tmp334);
    tmp334 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp328}, TNode<IntPtrT>{tmp333});
    TNode<HeapObject> tmp335;
    USE(tmp335);
    TNode<IntPtrT> tmp336;
    USE(tmp336);
    std::tie(tmp335, tmp336) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp327}, TNode<IntPtrT>{tmp334}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp335, tmp336}, tmp311);
    TNode<IntPtrT> tmp337;
    USE(tmp337);
    tmp337 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp314, tmp337}, tmp320);
    TNode<IntPtrT> tmp338;
    USE(tmp338);
    tmp338 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Smi> tmp339;
    USE(tmp339);
    tmp339 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp317});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp314, tmp338}, tmp339);
    ca_.Goto(&block33, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318);
  }

  if (block54.is_used()) {
    TNode<Context> tmp340;
    TNode<Object> tmp341;
    TNode<JSFunction> tmp342;
    TNode<NativeContext> tmp343;
    TNode<Object> tmp344;
    TNode<IntPtrT> tmp345;
    TNode<IntPtrT> tmp346;
    TNode<JSArray> tmp347;
    TNode<FixedArray> tmp348;
    TNode<IntPtrT> tmp349;
    TNode<IntPtrT> tmp350;
    TNode<IntPtrT> tmp351;
    TNode<IntPtrT> tmp352;
    TNode<FixedArray> tmp353;
    TNode<FixedArray> tmp354;
    TNode<FixedArray> tmp355;
    TNode<IntPtrT> tmp356;
    TNode<IntPtrT> tmp357;
    TNode<IntPtrT> tmp358;
    TNode<IntPtrT> tmp359;
    TNode<HeapObject> tmp360;
    TNode<IntPtrT> tmp361;
    TNode<IntPtrT> tmp362;
    TNode<IntPtrT> tmp363;
    TNode<IntPtrT> tmp364;
    ca_.Bind(&block54, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Context> tmp365;
    TNode<Object> tmp366;
    TNode<JSFunction> tmp367;
    TNode<NativeContext> tmp368;
    TNode<Object> tmp369;
    TNode<IntPtrT> tmp370;
    TNode<IntPtrT> tmp371;
    TNode<JSArray> tmp372;
    TNode<FixedArray> tmp373;
    TNode<IntPtrT> tmp374;
    TNode<IntPtrT> tmp375;
    TNode<IntPtrT> tmp376;
    ca_.Bind(&block33, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376);
    ca_.Goto(&block23, tmp365, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374);
  }

  if (block23.is_used()) {
    TNode<Context> tmp377;
    TNode<Object> tmp378;
    TNode<JSFunction> tmp379;
    TNode<NativeContext> tmp380;
    TNode<Object> tmp381;
    TNode<IntPtrT> tmp382;
    TNode<IntPtrT> tmp383;
    TNode<JSArray> tmp384;
    TNode<FixedArray> tmp385;
    TNode<IntPtrT> tmp386;
    ca_.Bind(&block23, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386);
    TNode<Object> tmp387;
    USE(tmp387);
    tmp387 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp377}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp388;
    USE(tmp388);
    tmp388 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp377}, TNode<Object>{tmp387});
    TNode<Smi> tmp389;
    USE(tmp389);
    tmp389 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp390;
    USE(tmp390);
    tmp390 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp388}, TNode<Smi>{tmp389});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp377}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp390});
    TNode<Smi> tmp391;
    USE(tmp391);
    tmp391 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp392;
    USE(tmp392);
    tmp392 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp390}, TNode<Smi>{tmp391});
    ca_.Branch(tmp392, &block56, &block57, tmp377, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383, tmp384, tmp385, tmp386, tmp390);
  }

  if (block56.is_used()) {
    TNode<Context> tmp393;
    TNode<Object> tmp394;
    TNode<JSFunction> tmp395;
    TNode<NativeContext> tmp396;
    TNode<Object> tmp397;
    TNode<IntPtrT> tmp398;
    TNode<IntPtrT> tmp399;
    TNode<JSArray> tmp400;
    TNode<FixedArray> tmp401;
    TNode<IntPtrT> tmp402;
    TNode<Smi> tmp403;
    ca_.Bind(&block56, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403);
    TNode<Object> tmp404;
    USE(tmp404);
    tmp404 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp393}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    TNode<PromiseCapability> tmp405;
    USE(tmp405);
    tmp405 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp393}, TNode<Object>{tmp404});
    TNode<IntPtrT> tmp406;
    USE(tmp406);
    tmp406 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp407 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp405, tmp406});
    TNode<Object> tmp408;
    USE(tmp408);
    tmp408 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp393}, TNode<Object>{tmp407});
    TNode<Oddball> tmp409;
    USE(tmp409);
    tmp409 = Undefined_0(state_);
    TNode<Object> tmp410;
    USE(tmp410);
    tmp410 = CodeStubAssembler(state_).Call(TNode<Context>{tmp393}, TNode<Object>{tmp408}, TNode<Object>{tmp409}, TNode<Object>{tmp400});
    ca_.Goto(&block57, tmp393, tmp394, tmp395, tmp396, tmp397, tmp398, tmp399, tmp400, tmp401, tmp402, tmp403);
  }

  if (block57.is_used()) {
    TNode<Context> tmp411;
    TNode<Object> tmp412;
    TNode<JSFunction> tmp413;
    TNode<NativeContext> tmp414;
    TNode<Object> tmp415;
    TNode<IntPtrT> tmp416;
    TNode<IntPtrT> tmp417;
    TNode<JSArray> tmp418;
    TNode<FixedArray> tmp419;
    TNode<IntPtrT> tmp420;
    TNode<Smi> tmp421;
    ca_.Bind(&block57, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421);
    TNode<Oddball> tmp422;
    USE(tmp422);
    tmp422 = Undefined_0(state_);
    ca_.Goto(&block1, tmp411, tmp412, tmp413, tmp422);
  }

  if (block1.is_used()) {
    TNode<Context> tmp423;
    TNode<Object> tmp424;
    TNode<JSFunction> tmp425;
    TNode<Object> tmp426;
    ca_.Bind(&block1, &tmp423, &tmp424, &tmp425, &tmp426);
    ca_.Goto(&block58, tmp423, tmp424, tmp425, tmp426);
  }

    TNode<Context> tmp427;
    TNode<Object> tmp428;
    TNode<JSFunction> tmp429;
    TNode<Object> tmp430;
    ca_.Bind(&block58, &tmp427, &tmp428, &tmp429, &tmp430);
  return TNode<Object>{tmp430};
}

}  // namespace internal
}  // namespace v8

