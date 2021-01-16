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

TNode<BoolT> IsPromiseSpeciesLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<Map> p_promiseMap) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Map, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_nativeContext, p_promiseMap);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Map> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp3);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Map> tmp6;
    TNode<Object> tmp7;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp5, tmp6, tmp8);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp9;
    TNode<Map> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject>tmp13 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp10, tmp12});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp13}, TNode<Object>{tmp11});
    ca_.Branch(tmp14, &block4, &block5, tmp9, tmp10, tmp11);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp15;
    TNode<Map> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp15, tmp16, tmp18);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp19;
    TNode<Map> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp22});
    ca_.Goto(&block1, tmp19, tmp20, tmp23);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp24;
    TNode<Map> tmp25;
    TNode<BoolT> tmp26;
    ca_.Bind(&block1, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block6, tmp24, tmp25, tmp26);
  }

    TNode<NativeContext> tmp27;
    TNode<Map> tmp28;
    TNode<BoolT> tmp29;
    ca_.Bind(&block6, &tmp27, &tmp28, &tmp29);
  return TNode<BoolT>{tmp29};
}

TF_BUILTIN(PromisePrototypeThen, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kOnFulfilled));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kOnRejected));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, JSPromise> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, JSReceiver> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, HeapObject> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, HeapObject> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSPromise, JSFunction, HeapObject, Object, HeapObject, HeapObject> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSPromise> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_JSPromise_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Object_constexpr_string_0(state_, "Promise.prototype.then");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp5}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp11}, TNode<Object>{tmp6});
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<NativeContext> tmp17;
    TNode<JSPromise> tmp18;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp12}, TNode<IntPtrT>{tmp19});
    TNode<JSFunction> tmp21;
    USE(tmp21);
    tmp21 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp12}, TNode<Object>{tmp20});
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp23 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp18, tmp22});
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = IsPromiseSpeciesLookupChainIntact_0(state_, TNode<NativeContext>{tmp12}, TNode<Map>{tmp23});
    ca_.Branch(tmp24, &block7, &block8, tmp12, tmp13, tmp14, tmp15, tmp18, tmp21, ca_.Uninitialized<HeapObject>(), ca_.Uninitialized<Object>());
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<JSPromise> tmp29;
    TNode<JSFunction> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Object> tmp32;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block6, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp33;
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<JSPromise> tmp37;
    TNode<JSFunction> tmp38;
    TNode<HeapObject> tmp39;
    TNode<Object> tmp40;
    ca_.Bind(&block8, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<JSReceiver> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{tmp33}, TNode<Object>{tmp37}, TNode<JSReceiver>{tmp38});
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp41}, TNode<HeapObject>{tmp38});
    ca_.Branch(tmp42, &block9, &block10, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    TNode<JSPromise> tmp47;
    TNode<JSFunction> tmp48;
    TNode<HeapObject> tmp49;
    TNode<Object> tmp50;
    TNode<JSReceiver> tmp51;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    ca_.Goto(&block6, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50);
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<Object> tmp55;
    TNode<JSPromise> tmp56;
    TNode<JSFunction> tmp57;
    TNode<HeapObject> tmp58;
    TNode<Object> tmp59;
    TNode<JSReceiver> tmp60;
    ca_.Bind(&block10, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    TNode<Oddball> tmp61;
    USE(tmp61);
    tmp61 = True_0(state_);
    TNode<PromiseCapability> tmp62;
    tmp62 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp52, tmp60, tmp61));
    USE(tmp62);
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp64 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp62, tmp63});
    ca_.Goto(&block5, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp62, tmp64);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<JSPromise> tmp69;
    TNode<JSFunction> tmp70;
    TNode<HeapObject> tmp71;
    TNode<Object> tmp72;
    ca_.Bind(&block6, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<JSPromise> tmp73;
    USE(tmp73);
    tmp73 = NewJSPromise_0(state_, TNode<Context>{tmp65}, TNode<Object>{tmp69});
    ca_.Goto(&block5, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp73, tmp73);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<JSPromise> tmp78;
    TNode<JSFunction> tmp79;
    TNode<HeapObject> tmp80;
    TNode<Object> tmp81;
    ca_.Bind(&block5, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp76});
    ca_.Branch(tmp82, &block12, &block13, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<Object> tmp86;
    TNode<JSPromise> tmp87;
    TNode<JSFunction> tmp88;
    TNode<HeapObject> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block12, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<JSReceiver> tmp91;
    USE(tmp91);
    tmp91 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp83}, TNode<Object>{tmp85});
    ca_.Goto(&block14, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91);
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp92;
    TNode<Object> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<JSPromise> tmp96;
    TNode<JSFunction> tmp97;
    TNode<HeapObject> tmp98;
    TNode<Object> tmp99;
    ca_.Bind(&block13, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<Oddball> tmp100;
    USE(tmp100);
    tmp100 = Undefined_0(state_);
    ca_.Goto(&block14, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<JSPromise> tmp105;
    TNode<JSFunction> tmp106;
    TNode<HeapObject> tmp107;
    TNode<Object> tmp108;
    TNode<HeapObject> tmp109;
    ca_.Bind(&block14, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109);
    TNode<BoolT> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp104});
    ca_.Branch(tmp110, &block16, &block17, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp111;
    TNode<Object> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<JSPromise> tmp115;
    TNode<JSFunction> tmp116;
    TNode<HeapObject> tmp117;
    TNode<Object> tmp118;
    TNode<HeapObject> tmp119;
    ca_.Bind(&block16, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119);
    TNode<JSReceiver> tmp120;
    USE(tmp120);
    tmp120 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp111}, TNode<Object>{tmp114});
    ca_.Goto(&block18, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp121;
    TNode<Object> tmp122;
    TNode<Object> tmp123;
    TNode<Object> tmp124;
    TNode<JSPromise> tmp125;
    TNode<JSFunction> tmp126;
    TNode<HeapObject> tmp127;
    TNode<Object> tmp128;
    TNode<HeapObject> tmp129;
    ca_.Bind(&block17, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129);
    TNode<Oddball> tmp130;
    USE(tmp130);
    tmp130 = Undefined_0(state_);
    ca_.Goto(&block18, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp131;
    TNode<Object> tmp132;
    TNode<Object> tmp133;
    TNode<Object> tmp134;
    TNode<JSPromise> tmp135;
    TNode<JSFunction> tmp136;
    TNode<HeapObject> tmp137;
    TNode<Object> tmp138;
    TNode<HeapObject> tmp139;
    TNode<HeapObject> tmp140;
    ca_.Bind(&block18, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    PerformPromiseThenImpl_0(state_, TNode<Context>{tmp131}, TNode<JSPromise>{tmp135}, TNode<HeapObject>{tmp139}, TNode<HeapObject>{tmp140}, TNode<HeapObject>{tmp137});
    CodeStubAssembler(state_).Return(tmp138);
  }
}

}  // namespace internal
}  // namespace v8

