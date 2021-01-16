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

TF_BUILTIN(PromiseResolveThenableJob, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<JSReceiver> parameter2 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, JSFunction, JSFunction, JSFunction, JSFunction, Context, Object, Context, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, JSFunction, JSFunction, JSFunction, JSFunction, Context, JSReceiver, JSReceiver, JSFunction, JSFunction, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, JSReceiver, Object, NativeContext, Object, Map, JSFunction, JSFunction, JSFunction, JSFunction, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<NativeContext> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp4}, TNode<IntPtrT>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp3}, TNode<MaybeObject>{tmp6});
    ca_.Branch(tmp9, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp8, tmp9);
  }

  if (block3.is_used()) {
    TNode<Context> tmp10;
    TNode<JSPromise> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Map> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp16});
    ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block4.is_used()) {
    TNode<Context> tmp19;
    TNode<JSPromise> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<Object> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Map> tmp25;
    TNode<BoolT> tmp26;
    ca_.Bind(&block4, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block5, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
  }

  if (block5.is_used()) {
    TNode<Context> tmp28;
    TNode<JSPromise> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<Object> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<Map> tmp34;
    TNode<BoolT> tmp35;
    TNode<BoolT> tmp36;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    ca_.Branch(tmp36, &block6, &block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp36);
  }

  if (block6.is_used()) {
    TNode<Context> tmp37;
    TNode<JSPromise> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Object> tmp40;
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<Map> tmp43;
    TNode<BoolT> tmp44;
    ca_.Bind(&block6, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<BoolT> tmp45;
    USE(tmp45);
    tmp45 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp45});
    ca_.Goto(&block8, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp46);
  }

  if (block7.is_used()) {
    TNode<Context> tmp47;
    TNode<JSPromise> tmp48;
    TNode<JSReceiver> tmp49;
    TNode<Object> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<Map> tmp53;
    TNode<BoolT> tmp54;
    ca_.Bind(&block7, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55);
  }

  if (block8.is_used()) {
    TNode<Context> tmp56;
    TNode<JSPromise> tmp57;
    TNode<JSReceiver> tmp58;
    TNode<Object> tmp59;
    TNode<NativeContext> tmp60;
    TNode<Object> tmp61;
    TNode<Map> tmp62;
    TNode<BoolT> tmp63;
    TNode<BoolT> tmp64;
    ca_.Bind(&block8, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Branch(tmp64, &block9, &block10, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp64);
  }

  if (block9.is_used()) {
    TNode<Context> tmp65;
    TNode<JSPromise> tmp66;
    TNode<JSReceiver> tmp67;
    TNode<Object> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<Map> tmp71;
    TNode<BoolT> tmp72;
    ca_.Bind(&block9, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<BoolT> tmp73;
    USE(tmp73);
    tmp73 = IsPromiseSpeciesLookupChainIntact_0(state_, TNode<NativeContext>{tmp69}, TNode<Map>{tmp71});
    ca_.Goto(&block11, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73);
  }

  if (block10.is_used()) {
    TNode<Context> tmp74;
    TNode<JSPromise> tmp75;
    TNode<JSReceiver> tmp76;
    TNode<Object> tmp77;
    TNode<NativeContext> tmp78;
    TNode<Object> tmp79;
    TNode<Map> tmp80;
    TNode<BoolT> tmp81;
    ca_.Bind(&block10, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block11, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82);
  }

  if (block11.is_used()) {
    TNode<Context> tmp83;
    TNode<JSPromise> tmp84;
    TNode<JSReceiver> tmp85;
    TNode<Object> tmp86;
    TNode<NativeContext> tmp87;
    TNode<Object> tmp88;
    TNode<Map> tmp89;
    TNode<BoolT> tmp90;
    TNode<BoolT> tmp91;
    ca_.Bind(&block11, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    ca_.Branch(tmp91, &block1, &block2, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89);
  }

  if (block1.is_used()) {
    TNode<Context> tmp92;
    TNode<JSPromise> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<NativeContext> tmp96;
    TNode<Object> tmp97;
    TNode<Map> tmp98;
    ca_.Bind(&block1, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    TNode<JSPromise> tmp99;
    USE(tmp99);
    tmp99 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp92}, TNode<Object>{tmp94});
    TNode<Oddball> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).UndefinedConstant();
    TNode<Oddball> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).UndefinedConstant();
    TNode<Object> tmp102;
    tmp102 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPerformPromiseThen, tmp92, tmp99, tmp100, tmp101, tmp93);
    USE(tmp102);
    CodeStubAssembler(state_).Return(tmp102);
  }

  if (block2.is_used()) {
    TNode<Context> tmp103;
    TNode<JSPromise> tmp104;
    TNode<JSReceiver> tmp105;
    TNode<Object> tmp106;
    TNode<NativeContext> tmp107;
    TNode<Object> tmp108;
    TNode<Map> tmp109;
    ca_.Bind(&block2, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109);
    TNode<Oddball> tmp110;
    USE(tmp110);
    tmp110 = False_0(state_);
    TNode<JSFunction> tmp111;
    USE(tmp111);
    TNode<JSFunction> tmp112;
    USE(tmp112);
    std::tie(tmp111, tmp112) = CreatePromiseResolvingFunctions_0(state_, TNode<Context>{tmp103}, TNode<JSPromise>{tmp104}, TNode<Object>{tmp110}, TNode<NativeContext>{tmp107}).Flatten();
    TNode<JSReceiver> tmp113;
    USE(tmp113);
    compiler::CodeAssemblerExceptionHandlerLabel catch114__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch114__label);
    tmp113 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp103}, TNode<Object>{tmp106});
    }
    if (catch114__label.is_used()) {
      compiler::CodeAssemblerLabel catch114_skip(&ca_);
      ca_.Goto(&catch114_skip);
      TNode<Object> catch114_exception_object;
      ca_.Bind(&catch114__label, &catch114_exception_object);
      ca_.Goto(&block15, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp111, tmp112, tmp111, tmp112, tmp103, tmp106, tmp103, catch114_exception_object);
      ca_.Bind(&catch114_skip);
    }
    TNode<Object> tmp115;
    USE(tmp115);
    compiler::CodeAssemblerExceptionHandlerLabel catch116__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch116__label);
    tmp115 = CodeStubAssembler(state_).Call(TNode<Context>{tmp103}, TNode<Object>{tmp113}, TNode<Object>{tmp105}, TNode<Object>{tmp111}, TNode<Object>{tmp112});
    }
    if (catch116__label.is_used()) {
      compiler::CodeAssemblerLabel catch116_skip(&ca_);
      ca_.Goto(&catch116_skip);
      TNode<Object> catch116_exception_object;
      ca_.Bind(&catch116__label, &catch116_exception_object);
      ca_.Goto(&block16, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp111, tmp112, tmp111, tmp112, tmp103, tmp113, tmp105, tmp111, tmp112, catch116_exception_object);
      ca_.Bind(&catch116_skip);
    }
    CodeStubAssembler(state_).Return(tmp115);
  }

  if (block15.is_used()) {
    TNode<Context> tmp117;
    TNode<JSPromise> tmp118;
    TNode<JSReceiver> tmp119;
    TNode<Object> tmp120;
    TNode<NativeContext> tmp121;
    TNode<Object> tmp122;
    TNode<Map> tmp123;
    TNode<JSFunction> tmp124;
    TNode<JSFunction> tmp125;
    TNode<JSFunction> tmp126;
    TNode<JSFunction> tmp127;
    TNode<Context> tmp128;
    TNode<Object> tmp129;
    TNode<Context> tmp130;
    TNode<Object> tmp131;
    ca_.Bind(&block15, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
    ca_.Goto(&block14, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp131);
  }

  if (block16.is_used()) {
    TNode<Context> tmp132;
    TNode<JSPromise> tmp133;
    TNode<JSReceiver> tmp134;
    TNode<Object> tmp135;
    TNode<NativeContext> tmp136;
    TNode<Object> tmp137;
    TNode<Map> tmp138;
    TNode<JSFunction> tmp139;
    TNode<JSFunction> tmp140;
    TNode<JSFunction> tmp141;
    TNode<JSFunction> tmp142;
    TNode<Context> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<JSReceiver> tmp145;
    TNode<JSFunction> tmp146;
    TNode<JSFunction> tmp147;
    TNode<Object> tmp148;
    ca_.Bind(&block16, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    ca_.Goto(&block14, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp148);
  }

  if (block14.is_used()) {
    TNode<Context> tmp149;
    TNode<JSPromise> tmp150;
    TNode<JSReceiver> tmp151;
    TNode<Object> tmp152;
    TNode<NativeContext> tmp153;
    TNode<Object> tmp154;
    TNode<Map> tmp155;
    TNode<JSFunction> tmp156;
    TNode<JSFunction> tmp157;
    TNode<JSFunction> tmp158;
    TNode<JSFunction> tmp159;
    TNode<Object> tmp160;
    ca_.Bind(&block14, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160);
    TNode<JSReceiver> tmp161;
    USE(tmp161);
    tmp161 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp149}, TNode<Object>{tmp159});
    TNode<Oddball> tmp162;
    USE(tmp162);
    tmp162 = Undefined_0(state_);
    TNode<Object> tmp163;
    USE(tmp163);
    tmp163 = CodeStubAssembler(state_).Call(TNode<Context>{tmp149}, TNode<Object>{tmp161}, TNode<Object>{tmp162}, TNode<Object>{tmp160});
    CodeStubAssembler(state_).Return(tmp163);
  }
}

}  // namespace internal
}  // namespace v8

