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

TNode<BoolT> HasAccessCheckFailed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_promiseFun, TNode<Object> p_executor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, NativeContext, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, NativeContext, Object, Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_promiseFun, p_executor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    BranchIfAccessCheckFailed_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp1}, TNode<Object>{tmp2}, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7, tmp12);
  }

  if (block4.is_used()) {
    TNode<Context> tmp13;
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Context> tmp20;
    ca_.Bind(&block4, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp16, tmp21);
  }

  if (block1.is_used()) {
    TNode<Context> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<BoolT> tmp26;
    ca_.Bind(&block1, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block6, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

    TNode<Context> tmp27;
    TNode<NativeContext> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<BoolT> tmp31;
    ca_.Bind(&block6, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
  return TNode<BoolT>{tmp31};
}

TF_BUILTIN(PromiseConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kJSNewTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kExecutor));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction, NativeContext, Object, NativeContext, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction, NativeContext, JSReceiver, Oddball, JSFunction, JSFunction, Object> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSFunction, JSPromise, BoolT, JSFunction, JSFunction, JSFunction, JSFunction> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block1, &block2, tmp0, tmp1, tmp2, tmp3);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block1, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp6}, MessageTemplate::kNotAPromise, TNode<Object>{tmp8});
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp13});
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp14});
    ca_.Branch(tmp15, &block3, &block4, tmp10, tmp11, tmp12, tmp13);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp16}, MessageTemplate::kResolverNotAFunction, TNode<Object>{tmp19});
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    ca_.Bind(&block4, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp20}, TNode<IntPtrT>{tmp24});
    TNode<JSFunction> tmp26;
    USE(tmp26);
    tmp26 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp20}, TNode<Object>{tmp25});
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = HasAccessCheckFailed_0(state_, TNode<Context>{tmp20}, TNode<NativeContext>{tmp20}, TNode<Object>{tmp26}, TNode<Object>{tmp23});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp26);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<JSFunction> tmp32;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<Smi> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kPromiseConstructorReturnedUndefined);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp28, tmp33);
    TNode<Oddball> tmp35;
    USE(tmp35);
    tmp35 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp35);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<JSFunction> tmp40;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp40}, TNode<Object>{tmp38});
    ca_.Branch(tmp41, &block7, &block8, tmp36, tmp37, tmp38, tmp39, tmp40, ca_.Uninitialized<JSPromise>());
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<JSFunction> tmp46;
    TNode<JSPromise> tmp47;
    ca_.Bind(&block7, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<JSPromise> tmp48;
    USE(tmp48);
    tmp48 = NewJSPromise_1(state_, TNode<Context>{tmp42});
    ca_.Goto(&block9, tmp42, tmp43, tmp44, tmp45, tmp46, tmp48);
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<JSFunction> tmp53;
    TNode<JSPromise> tmp54;
    ca_.Bind(&block8, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<JSReceiver> tmp55;
    USE(tmp55);
    tmp55 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp49}, TNode<Object>{tmp51});
    TNode<JSObject> tmp56;
    USE(tmp56);
    tmp56 = ConstructorBuiltinsAssembler(state_).EmitFastNewObject(TNode<Context>{tmp49}, TNode<JSFunction>{tmp53}, TNode<JSReceiver>{tmp55});
    TNode<JSPromise> tmp57;
    USE(tmp57);
    tmp57 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp49}, TNode<Object>{tmp56});
    PromiseInit_0(state_, TNode<JSPromise>{tmp57});
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrHasAsyncEventDelegate();
    ca_.Branch(tmp58, &block10, &block11, tmp49, tmp50, tmp51, tmp52, tmp53, tmp57);
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp59;
    TNode<Object> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<JSFunction> tmp63;
    TNode<JSPromise> tmp64;
    ca_.Bind(&block10, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    TNode<Oddball> tmp65;
    USE(tmp65);
    tmp65 = Undefined_0(state_);
    TNode<Object> tmp66;
    tmp66 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseHookInit, tmp59, tmp64, tmp65); 
    USE(tmp66);
    ca_.Goto(&block11, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64);
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<JSFunction> tmp71;
    TNode<JSPromise> tmp72;
    ca_.Bind(&block11, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    ca_.Goto(&block9, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<JSFunction> tmp77;
    TNode<JSPromise> tmp78;
    ca_.Bind(&block9, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<BoolT> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp79, &block12, &block13, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp80;
    TNode<Object> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    TNode<JSFunction> tmp84;
    TNode<JSPromise> tmp85;
    TNode<BoolT> tmp86;
    ca_.Bind(&block12, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    TNode<Object> tmp87;
    tmp87 = CodeStubAssembler(state_).CallRuntime(Runtime::kDebugPushPromise, tmp80, tmp85); 
    USE(tmp87);
    ca_.Goto(&block13, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86);
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp88;
    TNode<Object> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<JSFunction> tmp92;
    TNode<JSPromise> tmp93;
    TNode<BoolT> tmp94;
    ca_.Bind(&block13, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    TNode<Oddball> tmp95;
    USE(tmp95);
    tmp95 = True_0(state_);
    TNode<JSFunction> tmp96;
    USE(tmp96);
    TNode<JSFunction> tmp97;
    USE(tmp97);
    std::tie(tmp96, tmp97) = CreatePromiseResolvingFunctions_0(state_, TNode<Context>{tmp88}, TNode<JSPromise>{tmp93}, TNode<Object>{tmp95}, TNode<NativeContext>{tmp88}).Flatten();
    TNode<JSReceiver> tmp98;
    USE(tmp98);
    compiler::CodeAssemblerExceptionHandlerLabel catch99__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch99__label);
    tmp98 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp88}, TNode<Object>{tmp91});
    }
    if (catch99__label.is_used()) {
      compiler::CodeAssemblerLabel catch99_skip(&ca_);
      ca_.Goto(&catch99_skip);
      TNode<Object> catch99_exception_object;
      ca_.Bind(&catch99__label, &catch99_exception_object);
      ca_.Goto(&block16, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp96, tmp97, tmp96, tmp97, tmp88, tmp91, tmp88, catch99_exception_object);
      ca_.Bind(&catch99_skip);
    }
    TNode<Oddball> tmp100;
    USE(tmp100);
    tmp100 = Undefined_0(state_);
    TNode<Object> tmp101;
    USE(tmp101);
    compiler::CodeAssemblerExceptionHandlerLabel catch102__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch102__label);
    tmp101 = CodeStubAssembler(state_).Call(TNode<Context>{tmp88}, TNode<Object>{tmp98}, TNode<Object>{tmp100}, TNode<Object>{tmp96}, TNode<Object>{tmp97});
    }
    if (catch102__label.is_used()) {
      compiler::CodeAssemblerLabel catch102_skip(&ca_);
      ca_.Goto(&catch102_skip);
      TNode<Object> catch102_exception_object;
      ca_.Bind(&catch102__label, &catch102_exception_object);
      ca_.Goto(&block17, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp96, tmp97, tmp96, tmp97, tmp88, tmp98, tmp100, tmp96, tmp97, catch102_exception_object);
      ca_.Bind(&catch102_skip);
    }
    ca_.Goto(&block14, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp96, tmp97, tmp96, tmp97);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<JSFunction> tmp107;
    TNode<JSPromise> tmp108;
    TNode<BoolT> tmp109;
    TNode<JSFunction> tmp110;
    TNode<JSFunction> tmp111;
    TNode<JSFunction> tmp112;
    TNode<JSFunction> tmp113;
    TNode<NativeContext> tmp114;
    TNode<Object> tmp115;
    TNode<NativeContext> tmp116;
    TNode<Object> tmp117;
    ca_.Bind(&block16, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117);
    ca_.Goto(&block15, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp117);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<Object> tmp121;
    TNode<JSFunction> tmp122;
    TNode<JSPromise> tmp123;
    TNode<BoolT> tmp124;
    TNode<JSFunction> tmp125;
    TNode<JSFunction> tmp126;
    TNode<JSFunction> tmp127;
    TNode<JSFunction> tmp128;
    TNode<NativeContext> tmp129;
    TNode<JSReceiver> tmp130;
    TNode<Oddball> tmp131;
    TNode<JSFunction> tmp132;
    TNode<JSFunction> tmp133;
    TNode<Object> tmp134;
    ca_.Bind(&block17, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
    ca_.Goto(&block15, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp134);
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp135;
    TNode<Object> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    TNode<JSFunction> tmp139;
    TNode<JSPromise> tmp140;
    TNode<BoolT> tmp141;
    TNode<JSFunction> tmp142;
    TNode<JSFunction> tmp143;
    TNode<JSFunction> tmp144;
    TNode<JSFunction> tmp145;
    TNode<Object> tmp146;
    ca_.Bind(&block15, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146);
    TNode<Oddball> tmp147;
    USE(tmp147);
    tmp147 = Undefined_0(state_);
    TNode<Object> tmp148;
    USE(tmp148);
    tmp148 = CodeStubAssembler(state_).Call(TNode<Context>{tmp135}, TNode<Object>{tmp145}, TNode<Object>{tmp147}, TNode<Object>{tmp146});
    ca_.Goto(&block14, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp149;
    TNode<Object> tmp150;
    TNode<Object> tmp151;
    TNode<Object> tmp152;
    TNode<JSFunction> tmp153;
    TNode<JSPromise> tmp154;
    TNode<BoolT> tmp155;
    TNode<JSFunction> tmp156;
    TNode<JSFunction> tmp157;
    TNode<JSFunction> tmp158;
    TNode<JSFunction> tmp159;
    ca_.Bind(&block14, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159);
    ca_.Branch(tmp155, &block18, &block19, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp160;
    TNode<Object> tmp161;
    TNode<Object> tmp162;
    TNode<Object> tmp163;
    TNode<JSFunction> tmp164;
    TNode<JSPromise> tmp165;
    TNode<BoolT> tmp166;
    TNode<JSFunction> tmp167;
    TNode<JSFunction> tmp168;
    TNode<JSFunction> tmp169;
    TNode<JSFunction> tmp170;
    ca_.Bind(&block18, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170);
    TNode<Object> tmp171;
    tmp171 = CodeStubAssembler(state_).CallRuntime(Runtime::kDebugPopPromise, tmp160); 
    USE(tmp171);
    ca_.Goto(&block19, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170);
  }

  if (block19.is_used()) {
    TNode<NativeContext> tmp172;
    TNode<Object> tmp173;
    TNode<Object> tmp174;
    TNode<Object> tmp175;
    TNode<JSFunction> tmp176;
    TNode<JSPromise> tmp177;
    TNode<BoolT> tmp178;
    TNode<JSFunction> tmp179;
    TNode<JSFunction> tmp180;
    TNode<JSFunction> tmp181;
    TNode<JSFunction> tmp182;
    ca_.Bind(&block19, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    CodeStubAssembler(state_).Return(tmp177);
  }
}

TF_BUILTIN(PromisePrototypeCatch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kOnRejected));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<NativeContext> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = InvokeThen_1(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp3}, TNode<Object>{tmp1}, TNode<Object>{tmp4}, TNode<Object>{tmp2});
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

}  // namespace internal
}  // namespace v8

