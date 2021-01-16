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

TNode<String> kConstructorString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).ConstructorStringConstant();
return TNode<String>{tmp0};
}

TF_BUILTIN(PromiseResolveTrampoline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
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
    TNode<NativeContext> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<NativeContext> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "PromiseResolve");
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<NativeContext> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Object> tmp15;
    tmp15 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, tmp9, tmp14, tmp11);
    USE(tmp15);
    CodeStubAssembler(state_).Return(tmp15);
  }
}

TF_BUILTIN(PromiseResolve, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSReceiver> parameter1 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, Object, Context, JSPromise> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, JSPromise, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, NativeContext, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<NativeContext> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp4});
    TNode<JSPromise> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_JSPromise_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block2, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Object> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Context> tmp20;
    TNode<JSPromise> tmp21;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    TNode<Object> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp17}, TNode<IntPtrT>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp25 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp21, tmp24});
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject>tmp27 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp25, tmp26});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp27}, TNode<Object>{tmp23});
    ca_.Branch(tmp28, &block7, &block8, tmp14, tmp15, tmp16, tmp17, tmp18, tmp21, tmp23);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<Object> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<JSPromise> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    ca_.Goto(&block4, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

  if (block8.is_used()) {
    TNode<Context> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<Object> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<JSPromise> tmp41;
    TNode<Object> tmp42;
    ca_.Bind(&block8, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    ca_.Branch(tmp43, &block9, &block10, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block9.is_used()) {
    TNode<Context> tmp44;
    TNode<JSReceiver> tmp45;
    TNode<Object> tmp46;
    TNode<NativeContext> tmp47;
    TNode<Object> tmp48;
    TNode<JSPromise> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block9, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    ca_.Goto(&block4, tmp44, tmp45, tmp46, tmp47, tmp48);
  }

  if (block10.is_used()) {
    TNode<Context> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    TNode<NativeContext> tmp54;
    TNode<Object> tmp55;
    TNode<JSPromise> tmp56;
    TNode<Object> tmp57;
    ca_.Bind(&block10, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp55}, TNode<HeapObject>{tmp52});
    ca_.Branch(tmp58, &block11, &block12, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57);
  }

  if (block11.is_used()) {
    TNode<Context> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Object> tmp61;
    TNode<NativeContext> tmp62;
    TNode<Object> tmp63;
    TNode<JSPromise> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block11, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block4, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block12.is_used()) {
    TNode<Context> tmp66;
    TNode<JSReceiver> tmp67;
    TNode<Object> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<JSPromise> tmp71;
    TNode<Object> tmp72;
    ca_.Bind(&block12, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    CodeStubAssembler(state_).Return(tmp71);
  }

  if (block4.is_used()) {
    TNode<Context> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Object> tmp75;
    TNode<NativeContext> tmp76;
    TNode<Object> tmp77;
    ca_.Bind(&block4, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    TNode<String> tmp78;
    USE(tmp78);
    tmp78 = kConstructorString_0(state_);
    TNode<Object> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp73}, TNode<Object>{tmp75}, TNode<Object>{tmp78});
    TNode<BoolT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp79}, TNode<HeapObject>{tmp74});
    ca_.Branch(tmp80, &block13, &block14, tmp73, tmp74, tmp75, tmp76, tmp77, tmp79);
  }

  if (block13.is_used()) {
    TNode<Context> tmp81;
    TNode<JSReceiver> tmp82;
    TNode<Object> tmp83;
    TNode<NativeContext> tmp84;
    TNode<Object> tmp85;
    TNode<Object> tmp86;
    ca_.Bind(&block13, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    ca_.Goto(&block2, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block14.is_used()) {
    TNode<Context> tmp87;
    TNode<JSReceiver> tmp88;
    TNode<Object> tmp89;
    TNode<NativeContext> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    ca_.Bind(&block14, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92);
    CodeStubAssembler(state_).Return(tmp89);
  }

  if (block2.is_used()) {
    TNode<Context> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<NativeContext> tmp96;
    TNode<Object> tmp97;
    ca_.Bind(&block2, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    TNode<BoolT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp97}, TNode<HeapObject>{tmp94});
    ca_.Branch(tmp98, &block15, &block16, tmp93, tmp94, tmp95, tmp96, tmp97);
  }

  if (block15.is_used()) {
    TNode<Context> tmp99;
    TNode<JSReceiver> tmp100;
    TNode<Object> tmp101;
    TNode<NativeContext> tmp102;
    TNode<Object> tmp103;
    ca_.Bind(&block15, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
    TNode<JSPromise> tmp104;
    USE(tmp104);
    tmp104 = NewJSPromise_1(state_, TNode<Context>{tmp99});
    TNode<Object> tmp105;
    tmp105 = CodeStubAssembler(state_).CallBuiltin(Builtins::kResolvePromise, tmp99, tmp104, tmp101);
    USE(tmp105);
    CodeStubAssembler(state_).Return(tmp104);
  }

  if (block16.is_used()) {
    TNode<Context> tmp106;
    TNode<JSReceiver> tmp107;
    TNode<Object> tmp108;
    TNode<NativeContext> tmp109;
    TNode<Object> tmp110;
    ca_.Bind(&block16, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    TNode<Oddball> tmp111;
    USE(tmp111);
    tmp111 = True_0(state_);
    TNode<PromiseCapability> tmp112;
    tmp112 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp106, tmp107, tmp111));
    USE(tmp112);
    TNode<IntPtrT> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp114 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp112, tmp113});
    TNode<JSReceiver> tmp115;
    USE(tmp115);
    tmp115 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp106}, TNode<Object>{tmp114});
    TNode<Oddball> tmp116;
    USE(tmp116);
    tmp116 = Undefined_0(state_);
    TNode<Object> tmp117;
    USE(tmp117);
    tmp117 = CodeStubAssembler(state_).Call(TNode<Context>{tmp106}, TNode<Object>{tmp115}, TNode<Object>{tmp116}, TNode<Object>{tmp108});
    TNode<IntPtrT> tmp118;
    USE(tmp118);
    tmp118 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp119 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp112, tmp118});
    CodeStubAssembler(state_).Return(tmp119);
  }
}

TNode<String> kThenString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).ThenStringConstant();
return TNode<String>{tmp0};
}

TF_BUILTIN(ResolvePromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, HeapObject, Map, NativeContext, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object, Object, String, Context, Object> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Branch(tmp3, &block3, &block4, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    TNode<JSPromise> tmp5;
    TNode<Object> tmp6;
    TNode<BoolT> tmp7;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp4, tmp5, tmp6, tmp7, tmp8);
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<JSPromise> tmp10;
    TNode<Object> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp10}, TNode<Object>{tmp11});
    ca_.Goto(&block5, tmp9, tmp10, tmp11, tmp12, tmp13);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<JSPromise> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    ca_.Branch(tmp18, &block1, &block2, tmp14, tmp15, tmp16);
  }

  if (block1.is_used()) {
    TNode<Context> tmp19;
    TNode<JSPromise> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block1, &tmp19, &tmp20, &tmp21);
    TNode<Object> tmp22;
    tmp22 = CodeStubAssembler(state_).CallRuntime(Runtime::kResolvePromise, tmp19, tmp20, tmp21); 
    USE(tmp22);
    CodeStubAssembler(state_).Return(tmp22);
  }

  if (block2.is_used()) {
    TNode<Context> tmp23;
    TNode<JSPromise> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block2, &tmp23, &tmp24, &tmp25);
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = Undefined_0(state_);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp25});
    ca_.Branch(tmp27, &block10, &block11, tmp23, tmp24, tmp25, tmp26);
  }

  if (block10.is_used()) {
    TNode<Context> tmp28;
    TNode<JSPromise> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    ca_.Bind(&block10, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<Oddball> tmp32;
    tmp32 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, tmp28, tmp29, tmp30));
    USE(tmp32);
    CodeStubAssembler(state_).Return(tmp32);
  }

  if (block11.is_used()) {
    TNode<Context> tmp33;
    TNode<JSPromise> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    ca_.Bind(&block11, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<HeapObject> tmp37;
    USE(tmp37);
    tmp37 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp33}, TNode<Object>{tmp35});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp39 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp37, tmp38});
    TNode<BoolT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).IsJSReceiverMap(TNode<Map>{tmp39});
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp40});
    ca_.Branch(tmp41, &block12, &block13, tmp33, tmp34, tmp35, tmp36, tmp37, tmp39);
  }

  if (block12.is_used()) {
    TNode<Context> tmp42;
    TNode<JSPromise> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<HeapObject> tmp46;
    TNode<Map> tmp47;
    ca_.Bind(&block12, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Oddball> tmp48;
    tmp48 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, tmp42, tmp43, tmp44));
    USE(tmp48);
    CodeStubAssembler(state_).Return(tmp48);
  }

  if (block13.is_used()) {
    TNode<Context> tmp49;
    TNode<JSPromise> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<HeapObject> tmp53;
    TNode<Map> tmp54;
    ca_.Bind(&block13, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp55, &block14, &block15, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54);
  }

  if (block14.is_used()) {
    TNode<Context> tmp56;
    TNode<JSPromise> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<HeapObject> tmp60;
    TNode<Map> tmp61;
    ca_.Bind(&block14, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block9, tmp56, tmp57, tmp58, tmp59);
  }

  if (block15.is_used()) {
    TNode<Context> tmp62;
    TNode<JSPromise> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<HeapObject> tmp66;
    TNode<Map> tmp67;
    ca_.Bind(&block15, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    ca_.Branch(tmp68, &block16, &block17, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67);
  }

  if (block16.is_used()) {
    TNode<Context> tmp69;
    TNode<JSPromise> tmp70;
    TNode<Object> tmp71;
    TNode<Object> tmp72;
    TNode<HeapObject> tmp73;
    TNode<Map> tmp74;
    ca_.Bind(&block16, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    ca_.Goto(&block9, tmp69, tmp70, tmp71, tmp72);
  }

  if (block17.is_used()) {
    TNode<Context> tmp75;
    TNode<JSPromise> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<HeapObject> tmp79;
    TNode<Map> tmp80;
    ca_.Bind(&block17, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<NativeContext> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp75});
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp80});
    TNode<BoolT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp82});
    ca_.Branch(tmp83, &block18, &block19, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81);
  }

  if (block18.is_used()) {
    TNode<Context> tmp84;
    TNode<JSPromise> tmp85;
    TNode<Object> tmp86;
    TNode<Object> tmp87;
    TNode<HeapObject> tmp88;
    TNode<Map> tmp89;
    TNode<NativeContext> tmp90;
    ca_.Bind(&block18, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<IntPtrT> tmp91;
    USE(tmp91);
    tmp91 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    TNode<Object> tmp92;
    USE(tmp92);
    tmp92 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp90}, TNode<IntPtrT>{tmp91});
    TNode<BoolT> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp89}, TNode<Object>{tmp92});
    ca_.Branch(tmp93, &block28, &block29, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

  if (block23.is_used()) {
    TNode<Context> tmp94;
    TNode<JSPromise> tmp95;
    TNode<Object> tmp96;
    TNode<Object> tmp97;
    TNode<HeapObject> tmp98;
    TNode<Map> tmp99;
    TNode<NativeContext> tmp100;
    ca_.Bind(&block23, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsJSReceiverMap(resolutionMap)' failed", "src/builtins/promise-resolve.tq", 138);
  }

  if (block22.is_used()) {
    TNode<Context> tmp101;
    TNode<JSPromise> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<HeapObject> tmp105;
    TNode<Map> tmp106;
    TNode<NativeContext> tmp107;
    ca_.Bind(&block22, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
  }

  if (block27.is_used()) {
    TNode<Context> tmp108;
    TNode<JSPromise> tmp109;
    TNode<Object> tmp110;
    TNode<Object> tmp111;
    TNode<HeapObject> tmp112;
    TNode<Map> tmp113;
    TNode<NativeContext> tmp114;
    ca_.Bind(&block27, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsPromiseThenProtectorCellInvalid()' failed", "src/builtins/promise-resolve.tq", 139);
  }

  if (block26.is_used()) {
    TNode<Context> tmp115;
    TNode<JSPromise> tmp116;
    TNode<Object> tmp117;
    TNode<Object> tmp118;
    TNode<HeapObject> tmp119;
    TNode<Map> tmp120;
    TNode<NativeContext> tmp121;
    ca_.Bind(&block26, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
  }

  if (block28.is_used()) {
    TNode<Context> tmp122;
    TNode<JSPromise> tmp123;
    TNode<Object> tmp124;
    TNode<Object> tmp125;
    TNode<HeapObject> tmp126;
    TNode<Map> tmp127;
    TNode<NativeContext> tmp128;
    ca_.Bind(&block28, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    TNode<Oddball> tmp129;
    tmp129 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, tmp122, tmp123, tmp124));
    USE(tmp129);
    CodeStubAssembler(state_).Return(tmp129);
  }

  if (block29.is_used()) {
    TNode<Context> tmp130;
    TNode<JSPromise> tmp131;
    TNode<Object> tmp132;
    TNode<Object> tmp133;
    TNode<HeapObject> tmp134;
    TNode<Map> tmp135;
    TNode<NativeContext> tmp136;
    ca_.Bind(&block29, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136);
    ca_.Goto(&block9, tmp130, tmp131, tmp132, tmp133);
  }

  if (block19.is_used()) {
    TNode<Context> tmp137;
    TNode<JSPromise> tmp138;
    TNode<Object> tmp139;
    TNode<Object> tmp140;
    TNode<HeapObject> tmp141;
    TNode<Map> tmp142;
    TNode<NativeContext> tmp143;
    ca_.Bind(&block19, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
    TNode<IntPtrT> tmp144;
    USE(tmp144);
    tmp144 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    TNode<Object> tmp145;
    USE(tmp145);
    tmp145 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp143}, TNode<IntPtrT>{tmp144});
    TNode<IntPtrT> tmp146;
    USE(tmp146);
    tmp146 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject>tmp147 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp142, tmp146});
    TNode<BoolT> tmp148;
    USE(tmp148);
    tmp148 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp147}, TNode<Object>{tmp145});
    ca_.Branch(tmp148, &block31, &block32, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp145);
  }

  if (block31.is_used()) {
    TNode<Context> tmp149;
    TNode<JSPromise> tmp150;
    TNode<Object> tmp151;
    TNode<Object> tmp152;
    TNode<HeapObject> tmp153;
    TNode<Map> tmp154;
    TNode<NativeContext> tmp155;
    TNode<Object> tmp156;
    ca_.Bind(&block31, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    TNode<IntPtrT> tmp157;
    USE(tmp157);
    tmp157 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    TNode<Object> tmp158;
    USE(tmp158);
    tmp158 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp155}, TNode<IntPtrT>{tmp157});
    ca_.Goto(&block7, tmp149, tmp150, tmp151, tmp158);
  }

  if (block32.is_used()) {
    TNode<Context> tmp159;
    TNode<JSPromise> tmp160;
    TNode<Object> tmp161;
    TNode<Object> tmp162;
    TNode<HeapObject> tmp163;
    TNode<Map> tmp164;
    TNode<NativeContext> tmp165;
    TNode<Object> tmp166;
    ca_.Bind(&block32, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166);
    ca_.Goto(&block9, tmp159, tmp160, tmp161, tmp162);
  }

  if (block9.is_used()) {
    TNode<Context> tmp167;
    TNode<JSPromise> tmp168;
    TNode<Object> tmp169;
    TNode<Object> tmp170;
    ca_.Bind(&block9, &tmp167, &tmp168, &tmp169, &tmp170);
    TNode<String> tmp171;
    USE(tmp171);
    tmp171 = kThenString_0(state_);
    TNode<Object> tmp172;
    USE(tmp172);
    compiler::CodeAssemblerExceptionHandlerLabel catch173__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch173__label);
    tmp172 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp167}, TNode<Object>{tmp169}, TNode<Object>{tmp171});
    }
    if (catch173__label.is_used()) {
      compiler::CodeAssemblerLabel catch173_skip(&ca_);
      ca_.Goto(&catch173_skip);
      TNode<Object> catch173_exception_object;
      ca_.Bind(&catch173__label, &catch173_exception_object);
      ca_.Goto(&block35, tmp167, tmp168, tmp169, tmp170, tmp169, tmp171, tmp167, catch173_exception_object);
      ca_.Bind(&catch173_skip);
    }
    TNode<BoolT> tmp174;
    USE(tmp174);
    tmp174 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp172});
    ca_.Branch(tmp174, &block36, &block37, tmp167, tmp168, tmp169, tmp172);
  }

  if (block35.is_used()) {
    TNode<Context> tmp175;
    TNode<JSPromise> tmp176;
    TNode<Object> tmp177;
    TNode<Object> tmp178;
    TNode<Object> tmp179;
    TNode<String> tmp180;
    TNode<Context> tmp181;
    TNode<Object> tmp182;
    ca_.Bind(&block35, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    TNode<Oddball> tmp183;
    USE(tmp183);
    tmp183 = False_0(state_);
    TNode<Object> tmp184;
    tmp184 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRejectPromise, tmp175, tmp176, tmp182, tmp183);
    USE(tmp184);
    CodeStubAssembler(state_).Return(tmp184);
  }

  if (block36.is_used()) {
    TNode<Context> tmp185;
    TNode<JSPromise> tmp186;
    TNode<Object> tmp187;
    TNode<Object> tmp188;
    ca_.Bind(&block36, &tmp185, &tmp186, &tmp187, &tmp188);
    TNode<Oddball> tmp189;
    tmp189 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, tmp185, tmp186, tmp187));
    USE(tmp189);
    CodeStubAssembler(state_).Return(tmp189);
  }

  if (block37.is_used()) {
    TNode<Context> tmp190;
    TNode<JSPromise> tmp191;
    TNode<Object> tmp192;
    TNode<Object> tmp193;
    ca_.Bind(&block37, &tmp190, &tmp191, &tmp192, &tmp193);
    TNode<HeapObject> tmp194;
    USE(tmp194);
    tmp194 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp190}, TNode<Object>{tmp193});
    TNode<BoolT> tmp195;
    USE(tmp195);
    tmp195 = CodeStubAssembler(state_).IsCallable(TNode<HeapObject>{tmp194});
    TNode<BoolT> tmp196;
    USE(tmp196);
    tmp196 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp195});
    ca_.Branch(tmp196, &block38, &block39, tmp190, tmp191, tmp192, tmp193);
  }

  if (block38.is_used()) {
    TNode<Context> tmp197;
    TNode<JSPromise> tmp198;
    TNode<Object> tmp199;
    TNode<Object> tmp200;
    ca_.Bind(&block38, &tmp197, &tmp198, &tmp199, &tmp200);
    TNode<Oddball> tmp201;
    tmp201 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, tmp197, tmp198, tmp199));
    USE(tmp201);
    CodeStubAssembler(state_).Return(tmp201);
  }

  if (block39.is_used()) {
    TNode<Context> tmp202;
    TNode<JSPromise> tmp203;
    TNode<Object> tmp204;
    TNode<Object> tmp205;
    ca_.Bind(&block39, &tmp202, &tmp203, &tmp204, &tmp205);
    ca_.Goto(&block7, tmp202, tmp203, tmp204, tmp205);
  }

  if (block7.is_used()) {
    TNode<Context> tmp206;
    TNode<JSPromise> tmp207;
    TNode<Object> tmp208;
    TNode<Object> tmp209;
    ca_.Bind(&block7, &tmp206, &tmp207, &tmp208, &tmp209);
    TNode<NativeContext> tmp210;
    USE(tmp210);
    tmp210 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp206});
    TNode<JSReceiver> tmp211;
    USE(tmp211);
    tmp211 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp206}, TNode<Object>{tmp209});
    TNode<JSReceiver> tmp212;
    USE(tmp212);
    tmp212 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp206}, TNode<Object>{tmp208});
    TNode<PromiseResolveThenableJobTask> tmp213;
    USE(tmp213);
    tmp213 = NewPromiseResolveThenableJobTask_0(state_, TNode<Context>{tmp206}, TNode<JSPromise>{tmp207}, TNode<JSReceiver>{tmp211}, TNode<JSReceiver>{tmp212}, TNode<Context>{tmp210});
    TNode<Oddball> tmp214;
    tmp214 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp210, tmp213));
    USE(tmp214);
    CodeStubAssembler(state_).Return(tmp214);
  }
}

TNode<JSPromise> Cast_JSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSPromise> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSPromise> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSPromise_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSPromise> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSPromise> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSPromise>{tmp20};
}

}  // namespace internal
}  // namespace v8

