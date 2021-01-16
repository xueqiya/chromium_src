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

TNode<Context> CreatePromiseAllResolveElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseCapability, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseCapability, NativeContext, Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_capability, p_nativeContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<PromiseCapability> tmp1;
    TNode<NativeContext> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_NativeContextSlot_constexpr_JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_, Context::Field::JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp3});
    TNode<Map> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrConstant(0);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<JSArray> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::PACKED_ELEMENTS, TNode<Map>{tmp5}, TNode<IntPtrT>{tmp6}, TNode<Smi>{tmp7});
    TNode<Context> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp2}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiConstant(1);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp9}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp10});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp9}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot, TNode<Object>{tmp1});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp9}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot, TNode<Object>{tmp8});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp9);
  }

    TNode<Context> tmp11;
    TNode<PromiseCapability> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14);
  return TNode<Context>{tmp14};
}

TNode<JSFunction> CreatePromiseAllResolveElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_resolveElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext, Context::Field p_slotIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext, Map, SharedFunctionInfo, JSFunction> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext, Map, SharedFunctionInfo, JSFunction> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context, Smi, NativeContext, JSFunction> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_resolveElementContext, p_index, p_nativeContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Context> tmp1;
    TNode<Smi> tmp2;
    TNode<NativeContext> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp4});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_intptr_0(state_, p_slotIndex);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp3}, TNode<IntPtrT>{tmp7});
    TNode<SharedFunctionInfo> tmp9;
    USE(tmp9);
    tmp9 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp8});
    TNode<JSFunction> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp6}, TNode<SharedFunctionInfo>{tmp9}, TNode<Context>{tmp1});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11}, tmp2);
    ca_.Goto(&block14, tmp0, tmp1, tmp2, tmp3, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<Context> tmp13;
    TNode<Smi> tmp14;
    TNode<NativeContext> tmp15;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index > 0' failed", "src/builtins/promise-all.tq", 42);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<Context> tmp17;
    TNode<Smi> tmp18;
    TNode<NativeContext> tmp19;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19);
  }

  if (block9.is_used()) {
    TNode<Context> tmp20;
    TNode<Context> tmp21;
    TNode<Smi> tmp22;
    TNode<NativeContext> tmp23;
    ca_.Bind(&block9, &tmp20, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index < kPropertyArrayHashFieldMax' failed", "src/builtins/promise-all.tq", 43);
  }

  if (block8.is_used()) {
    TNode<Context> tmp24;
    TNode<Context> tmp25;
    TNode<Smi> tmp26;
    TNode<NativeContext> tmp27;
    ca_.Bind(&block8, &tmp24, &tmp25, &tmp26, &tmp27);
  }

  if (block13.is_used()) {
    TNode<Context> tmp28;
    TNode<Context> tmp29;
    TNode<Smi> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Map> tmp32;
    TNode<SharedFunctionInfo> tmp33;
    TNode<JSFunction> tmp34;
    ca_.Bind(&block13, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", "src/builtins/promise-all.tq", 53);
  }

  if (block12.is_used()) {
    TNode<Context> tmp35;
    TNode<Context> tmp36;
    TNode<Smi> tmp37;
    TNode<NativeContext> tmp38;
    TNode<Map> tmp39;
    TNode<SharedFunctionInfo> tmp40;
    TNode<JSFunction> tmp41;
    ca_.Bind(&block12, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
  }

    TNode<Context> tmp42;
    TNode<Context> tmp43;
    TNode<Smi> tmp44;
    TNode<NativeContext> tmp45;
    TNode<JSFunction> tmp46;
    ca_.Bind(&block14, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
  return TNode<JSFunction>{tmp46};
}

TNode<Context> CreatePromiseResolvingFunctionsContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, NativeContext, Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promise, p_debugEvent, p_nativeContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<Object> tmp2;
    TNode<NativeContext> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Context> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp3}, PromiseBuiltins::kPromiseContextLength);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, TNode<IntPtrT>{tmp5}, TNode<Object>{tmp1});
    TNode<Oddball> tmp6;
    USE(tmp6);
    tmp6 = False_0(state_);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, TNode<IntPtrT>{tmp7}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kDebugEventSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, TNode<IntPtrT>{tmp8}, TNode<Object>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<Context> tmp9;
    TNode<JSPromise> tmp10;
    TNode<Object> tmp11;
    TNode<NativeContext> tmp12;
    TNode<Context> tmp13;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
  return TNode<Context>{tmp13};
}

TNode<BoolT> IsPromiseThenLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Map> p_receiverMap) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Map, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiverMap);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Map> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Map> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp10});
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp11});
    ca_.Branch(tmp12, &block4, &block5, tmp8, tmp9, tmp10);
  }

  if (block4.is_used()) {
    TNode<Context> tmp13;
    TNode<NativeContext> tmp14;
    TNode<Map> tmp15;
    ca_.Bind(&block4, &tmp13, &tmp14, &tmp15);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Map> tmp19;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19);
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject>tmp21 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp19, tmp20});
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    TNode<Object> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp22});
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp21}, TNode<Object>{tmp23});
    ca_.Branch(tmp24, &block6, &block7, tmp17, tmp18, tmp19);
  }

  if (block6.is_used()) {
    TNode<Context> tmp25;
    TNode<NativeContext> tmp26;
    TNode<Map> tmp27;
    ca_.Bind(&block6, &tmp25, &tmp26, &tmp27);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<NativeContext> tmp30;
    TNode<Map> tmp31;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp32});
    ca_.Goto(&block1, tmp29, tmp30, tmp31, tmp33);
  }

  if (block1.is_used()) {
    TNode<Context> tmp34;
    TNode<NativeContext> tmp35;
    TNode<Map> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block1, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block8, tmp34, tmp35, tmp36, tmp37);
  }

    TNode<Context> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Map> tmp40;
    TNode<BoolT> tmp41;
    ca_.Bind(&block8, &tmp38, &tmp39, &tmp40, &tmp41);
  return TNode<BoolT>{tmp41};
}

TF_BUILTIN(PromiseAll, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = GeneratePromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2}, TorqueStructPromiseAllResolveElementFunctor_0{}, TorqueStructPromiseAllRejectElementFunctor_0{});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(PromiseAllSettled, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = GeneratePromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2}, TorqueStructPromiseAllSettledResolveElementFunctor_0{}, TorqueStructPromiseAllSettledRejectElementFunctor_0{});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TNode<Object> GeneratePromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Context, Object> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_iterable);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "Promise.all");
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = False_0(state_);
    TNode<PromiseCapability> tmp16;
    tmp16 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp9, tmp14, tmp15));
    USE(tmp16);
    TNode<JSReceiver> tmp17;
    USE(tmp17);
    TNode<Object> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch19__label);
    std::tie(tmp17, tmp18) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp9}, TNode<Object>{tmp11}).Flatten();
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      TNode<Object> catch19_exception_object;
      ca_.Bind(&catch19__label, &catch19_exception_object);
      ca_.Goto(&block10, tmp9, tmp10, tmp11, tmp14, tmp16, tmp11, tmp9, catch19_exception_object);
      ca_.Bind(&catch19_skip);
    }
    TNode<Object> tmp20;
    USE(tmp20);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch21__label);
    tmp20 = PerformPromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(state_, TNode<Context>{tmp9}, TNode<JSReceiver>{tmp14}, TNode<PromiseCapability>{tmp16}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp17}, TNode<Object>{tmp18}}, TorqueStructPromiseAllResolveElementFunctor_0{}, TorqueStructPromiseAllRejectElementFunctor_0{}, &label0, &result_0_0);
    }
    if (catch21__label.is_used()) {
      compiler::CodeAssemblerLabel catch21_skip(&ca_);
      ca_.Goto(&catch21_skip);
      TNode<Object> catch21_exception_object;
      ca_.Bind(&catch21__label, &catch21_exception_object);
      ca_.Goto(&block13, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, catch21_exception_object);
      ca_.Bind(&catch21_skip);
    }
    ca_.Goto(&block11, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, tmp20);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, result_0_0.value());
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<PromiseCapability> tmp26;
    TNode<Object> tmp27;
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block10, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp25, tmp26, tmp29);
  }

  if (block13.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<PromiseCapability> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<Object> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<PromiseCapability> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Object> tmp40;
    TNode<Context> tmp41;
    TNode<Object> tmp42;
    ca_.Bind(&block13, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block9, tmp30, tmp31, tmp32, tmp33, tmp34, tmp42);
  }

  if (block12.is_used()) {
    TNode<Context> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<PromiseCapability> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<Object> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<PromiseCapability> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block7, tmp43, tmp44, tmp45, tmp46, tmp47, tmp55);
  }

  if (block11.is_used()) {
    TNode<Context> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<PromiseCapability> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<PromiseCapability> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<Object> tmp66;
    TNode<Context> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block11, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    ca_.Goto(&block1, tmp56, tmp57, tmp58, tmp68);
  }

  if (block9.is_used()) {
    TNode<Context> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<PromiseCapability> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block9, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    ca_.Goto(&block7, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74);
  }

  if (block7.is_used()) {
    TNode<Context> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<JSReceiver> tmp78;
    TNode<PromiseCapability> tmp79;
    TNode<Object> tmp80;
    ca_.Bind(&block7, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<Object> tmp81;
    USE(tmp81);
    tmp81 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp75}, TNode<Object>{tmp80});
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp83 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp79, tmp82});
    TNode<Object> tmp84;
    USE(tmp84);
    tmp84 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp75}, TNode<Object>{tmp83});
    TNode<Oddball> tmp85;
    USE(tmp85);
    tmp85 = Undefined_0(state_);
    TNode<Object> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).Call(TNode<Context>{tmp75}, TNode<Object>{tmp84}, TNode<Object>{tmp85}, TNode<Object>{tmp81});
    TNode<IntPtrT> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp88 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp79, tmp87});
    ca_.Goto(&block1, tmp75, tmp76, tmp77, tmp88);
  }

  if (block1.is_used()) {
    TNode<Context> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    ca_.Bind(&block1, &tmp89, &tmp90, &tmp91, &tmp92);
    ca_.Goto(&block14, tmp89, tmp90, tmp91, tmp92);
  }

    TNode<Context> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    ca_.Bind(&block14, &tmp93, &tmp94, &tmp95, &tmp96);
  return TNode<Object>{tmp96};
}

TNode<Object> GeneratePromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object, Context, Object> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, JSReceiver, Object, JSReceiver, PromiseCapability, JSReceiver, Object, Context, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSReceiver, PromiseCapability, Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_iterable);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "Promise.all");
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = False_0(state_);
    TNode<PromiseCapability> tmp16;
    tmp16 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp9, tmp14, tmp15));
    USE(tmp16);
    TNode<JSReceiver> tmp17;
    USE(tmp17);
    TNode<Object> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch19__label);
    std::tie(tmp17, tmp18) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp9}, TNode<Object>{tmp11}).Flatten();
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      TNode<Object> catch19_exception_object;
      ca_.Bind(&catch19__label, &catch19_exception_object);
      ca_.Goto(&block10, tmp9, tmp10, tmp11, tmp14, tmp16, tmp11, tmp9, catch19_exception_object);
      ca_.Bind(&catch19_skip);
    }
    TNode<Object> tmp20;
    USE(tmp20);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch21__label);
    tmp20 = PerformPromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(state_, TNode<Context>{tmp9}, TNode<JSReceiver>{tmp14}, TNode<PromiseCapability>{tmp16}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp17}, TNode<Object>{tmp18}}, TorqueStructPromiseAllSettledResolveElementFunctor_0{}, TorqueStructPromiseAllSettledRejectElementFunctor_0{}, &label0, &result_0_0);
    }
    if (catch21__label.is_used()) {
      compiler::CodeAssemblerLabel catch21_skip(&ca_);
      ca_.Goto(&catch21_skip);
      TNode<Object> catch21_exception_object;
      ca_.Bind(&catch21__label, &catch21_exception_object);
      ca_.Goto(&block13, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, catch21_exception_object);
      ca_.Bind(&catch21_skip);
    }
    ca_.Goto(&block11, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, tmp20);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp9, tmp10, tmp11, tmp14, tmp16, tmp17, tmp18, tmp14, tmp16, tmp17, tmp18, tmp9, result_0_0.value());
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<PromiseCapability> tmp26;
    TNode<Object> tmp27;
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block10, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp25, tmp26, tmp29);
  }

  if (block13.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<PromiseCapability> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<Object> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<PromiseCapability> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Object> tmp40;
    TNode<Context> tmp41;
    TNode<Object> tmp42;
    ca_.Bind(&block13, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block9, tmp30, tmp31, tmp32, tmp33, tmp34, tmp42);
  }

  if (block12.is_used()) {
    TNode<Context> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<PromiseCapability> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<Object> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<PromiseCapability> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block7, tmp43, tmp44, tmp45, tmp46, tmp47, tmp55);
  }

  if (block11.is_used()) {
    TNode<Context> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<PromiseCapability> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<PromiseCapability> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<Object> tmp66;
    TNode<Context> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block11, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    ca_.Goto(&block1, tmp56, tmp57, tmp58, tmp68);
  }

  if (block9.is_used()) {
    TNode<Context> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<PromiseCapability> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block9, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    ca_.Goto(&block7, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74);
  }

  if (block7.is_used()) {
    TNode<Context> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<JSReceiver> tmp78;
    TNode<PromiseCapability> tmp79;
    TNode<Object> tmp80;
    ca_.Bind(&block7, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<Object> tmp81;
    USE(tmp81);
    tmp81 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp75}, TNode<Object>{tmp80});
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp83 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp79, tmp82});
    TNode<Object> tmp84;
    USE(tmp84);
    tmp84 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp75}, TNode<Object>{tmp83});
    TNode<Oddball> tmp85;
    USE(tmp85);
    tmp85 = Undefined_0(state_);
    TNode<Object> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).Call(TNode<Context>{tmp75}, TNode<Object>{tmp84}, TNode<Object>{tmp85}, TNode<Object>{tmp81});
    TNode<IntPtrT> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp88 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp79, tmp87});
    ca_.Goto(&block1, tmp75, tmp76, tmp77, tmp88);
  }

  if (block1.is_used()) {
    TNode<Context> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    ca_.Bind(&block1, &tmp89, &tmp90, &tmp91, &tmp92);
    ca_.Goto(&block14, tmp89, tmp90, tmp91, tmp92);
  }

    TNode<Context> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    ca_.Bind(&block14, &tmp93, &tmp94, &tmp95, &tmp96);
  return TNode<Object>{tmp96};
}

TNode<Object> PerformPromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, JSReceiver, String, Context, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, JSReceiver, Object, Object, Context, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, Context> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, Context, JSReceiver> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, Map, Context> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, Map, Context, JSReceiver> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Context, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, JSReceiver, Object, Object, Context, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, JSReceiver, Context, Object> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, JSReceiver, Object, Object, Context, Object> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, String, Context, Object> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, NativeContext, Object, Object, JSReceiver, JSReceiver, Object> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, Object, Context, Object> block59(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, Object> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, Context, Object, Symbol, HeapObject, Object> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, JSReceiver, Object, Object, Context, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi, JSArray, FixedArray, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi, JSArray, FixedArray, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, Object> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_constructor, p_capability, p_iter.object, p_iter.next);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<PromiseCapability> tmp2;
    TNode<JSReceiver> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<NativeContext> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp7 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp2, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp9 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp10});
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp12, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp7, tmp9, tmp11);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<PromiseCapability> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<Object> tmp17;
    TNode<NativeContext> tmp18;
    TNode<HeapObject> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Symbol> tmp22;
    USE(tmp22);
    tmp22 = kPromiseForwardingHandlerSymbol_0(state_);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = True_0(state_);
    TNode<Object> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp13}, TNode<Object>{tmp21}, TNode<Object>{tmp22}, TNode<Object>{tmp23});
    ca_.Goto(&block4, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block4.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<PromiseCapability> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Object> tmp29;
    TNode<NativeContext> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block4, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Context> tmp34;
    USE(tmp34);
    tmp34 = CreatePromiseAllResolveElementContext_0(state_, TNode<Context>{tmp25}, TNode<PromiseCapability>{tmp27}, TNode<NativeContext>{tmp30});
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp36;
    USE(tmp36);
    tmp36 = Undefined_0(state_);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{tmp25}, TNode<NativeContext>{tmp30}, TNode<JSReceiver>{tmp26});
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp37});
    ca_.Branch(tmp38, &block7, &block8, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<PromiseCapability> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Object> tmp43;
    TNode<NativeContext> tmp44;
    TNode<HeapObject> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<Context> tmp48;
    TNode<Smi> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<String> tmp51;
    USE(tmp51);
    tmp51 = kResolveString_0(state_);
    TNode<Object> tmp52;
    USE(tmp52);
    compiler::CodeAssemblerExceptionHandlerLabel catch53__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch53__label);
    tmp52 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp39}, TNode<Object>{tmp40}, TNode<Object>{tmp51});
    }
    if (catch53__label.is_used()) {
      compiler::CodeAssemblerLabel catch53_skip(&ca_);
      ca_.Goto(&catch53_skip);
      TNode<Object> catch53_exception_object;
      ca_.Bind(&catch53__label, &catch53_exception_object);
      ca_.Goto(&block11, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, ca_.Uninitialized<Object>(), tmp40, tmp51, tmp39, catch53_exception_object);
      ca_.Bind(&catch53_skip);
    }
    TNode<JSReceiver> tmp54;
    USE(tmp54);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp54 = Cast_Callable_1(state_, TNode<Context>{tmp39}, TNode<Object>{tmp52}, &label0);
    ca_.Goto(&block15, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp52, tmp52, tmp39, tmp54);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp52, tmp52, tmp39);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp55;
    TNode<JSReceiver> tmp56;
    TNode<PromiseCapability> tmp57;
    TNode<JSReceiver> tmp58;
    TNode<Object> tmp59;
    TNode<NativeContext> tmp60;
    TNode<HeapObject> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Context> tmp64;
    TNode<Smi> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<JSReceiver> tmp68;
    TNode<String> tmp69;
    TNode<Context> tmp70;
    TNode<Object> tmp71;
    ca_.Bind(&block11, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp55}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp58}, TNode<Object>{tmp59}}, TNode<Object>{tmp71}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp71, tmp58, tmp59, tmp71, tmp55, result_0_0.value());
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<PromiseCapability> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Object> tmp76;
    TNode<NativeContext> tmp77;
    TNode<HeapObject> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<Context> tmp81;
    TNode<Smi> tmp82;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<Context> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block12, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block1, tmp90);
  }

  if (block16.is_used()) {
    TNode<Context> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<PromiseCapability> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<NativeContext> tmp96;
    TNode<HeapObject> tmp97;
    TNode<Object> tmp98;
    TNode<Object> tmp99;
    TNode<Context> tmp100;
    TNode<Smi> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<Context> tmp105;
    ca_.Bind(&block16, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp91}, MessageTemplate::kCalledNonCallable, "resolve");
  }

  if (block15.is_used()) {
    TNode<Context> tmp106;
    TNode<JSReceiver> tmp107;
    TNode<PromiseCapability> tmp108;
    TNode<JSReceiver> tmp109;
    TNode<Object> tmp110;
    TNode<NativeContext> tmp111;
    TNode<HeapObject> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<Context> tmp115;
    TNode<Smi> tmp116;
    TNode<Object> tmp117;
    TNode<Object> tmp118;
    TNode<Object> tmp119;
    TNode<Context> tmp120;
    TNode<JSReceiver> tmp121;
    ca_.Bind(&block15, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    ca_.Goto(&block8, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp121);
  }

  if (block8.is_used()) {
    TNode<Context> tmp122;
    TNode<JSReceiver> tmp123;
    TNode<PromiseCapability> tmp124;
    TNode<JSReceiver> tmp125;
    TNode<Object> tmp126;
    TNode<NativeContext> tmp127;
    TNode<HeapObject> tmp128;
    TNode<Object> tmp129;
    TNode<Object> tmp130;
    TNode<Context> tmp131;
    TNode<Smi> tmp132;
    TNode<Object> tmp133;
    ca_.Bind(&block8, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<IntPtrT> tmp134;
    USE(tmp134);
    tmp134 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    TNode<Object> tmp135;
    USE(tmp135);
    tmp135 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp127}, TNode<IntPtrT>{tmp134});
    TNode<Map> tmp136;
    USE(tmp136);
    tmp136 = UnsafeCast_Map_0(state_, TNode<Context>{tmp122}, TNode<Object>{tmp135});
    ca_.Goto(&block19, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp136);
  }

  if (block19.is_used()) {
    TNode<Context> tmp137;
    TNode<JSReceiver> tmp138;
    TNode<PromiseCapability> tmp139;
    TNode<JSReceiver> tmp140;
    TNode<Object> tmp141;
    TNode<NativeContext> tmp142;
    TNode<HeapObject> tmp143;
    TNode<Object> tmp144;
    TNode<Object> tmp145;
    TNode<Context> tmp146;
    TNode<Smi> tmp147;
    TNode<Object> tmp148;
    TNode<Map> tmp149;
    ca_.Bind(&block19, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    TNode<BoolT> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp150, &block17, &block18, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149);
  }

  if (block17.is_used()) {
    TNode<Context> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<PromiseCapability> tmp153;
    TNode<JSReceiver> tmp154;
    TNode<Object> tmp155;
    TNode<NativeContext> tmp156;
    TNode<HeapObject> tmp157;
    TNode<Object> tmp158;
    TNode<Object> tmp159;
    TNode<Context> tmp160;
    TNode<Smi> tmp161;
    TNode<Object> tmp162;
    TNode<Map> tmp163;
    ca_.Bind(&block17, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    TNode<JSReceiver> tmp164;
    USE(tmp164);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp164 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp151}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp154}, TNode<Object>{tmp155}}, TNode<Map>{tmp163}, &label0);
    ca_.Goto(&block22, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, ca_.Uninitialized<Object>(), tmp154, tmp155, tmp163, tmp151, tmp164);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block23, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, ca_.Uninitialized<Object>(), tmp154, tmp155, tmp163, tmp151);
    }
  }

  if (block23.is_used()) {
    TNode<Context> tmp165;
    TNode<JSReceiver> tmp166;
    TNode<PromiseCapability> tmp167;
    TNode<JSReceiver> tmp168;
    TNode<Object> tmp169;
    TNode<NativeContext> tmp170;
    TNode<HeapObject> tmp171;
    TNode<Object> tmp172;
    TNode<Object> tmp173;
    TNode<Context> tmp174;
    TNode<Smi> tmp175;
    TNode<Object> tmp176;
    TNode<Map> tmp177;
    TNode<Object> tmp178;
    TNode<JSReceiver> tmp179;
    TNode<Object> tmp180;
    TNode<Map> tmp181;
    TNode<Context> tmp182;
    ca_.Bind(&block23, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    ca_.Goto(&block5, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
  }

  if (block22.is_used()) {
    TNode<Context> tmp183;
    TNode<JSReceiver> tmp184;
    TNode<PromiseCapability> tmp185;
    TNode<JSReceiver> tmp186;
    TNode<Object> tmp187;
    TNode<NativeContext> tmp188;
    TNode<HeapObject> tmp189;
    TNode<Object> tmp190;
    TNode<Object> tmp191;
    TNode<Context> tmp192;
    TNode<Smi> tmp193;
    TNode<Object> tmp194;
    TNode<Map> tmp195;
    TNode<Object> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<Object> tmp198;
    TNode<Map> tmp199;
    TNode<Context> tmp200;
    TNode<JSReceiver> tmp201;
    ca_.Bind(&block22, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    TNode<Object> tmp202;
    USE(tmp202);
    tmp202 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp183}, TNode<JSReceiver>{tmp201}, TNode<Map>{tmp195});
    TNode<Smi> tmp203;
    USE(tmp203);
    tmp203 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyArray::HashField::kMax);
    TNode<BoolT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp193}, TNode<Smi>{tmp203});
    ca_.Branch(tmp204, &block24, &block25, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp202, tmp201);
  }

  if (block24.is_used()) {
    TNode<Context> tmp205;
    TNode<JSReceiver> tmp206;
    TNode<PromiseCapability> tmp207;
    TNode<JSReceiver> tmp208;
    TNode<Object> tmp209;
    TNode<NativeContext> tmp210;
    TNode<HeapObject> tmp211;
    TNode<Object> tmp212;
    TNode<Object> tmp213;
    TNode<Context> tmp214;
    TNode<Smi> tmp215;
    TNode<Object> tmp216;
    TNode<Map> tmp217;
    TNode<Object> tmp218;
    TNode<JSReceiver> tmp219;
    ca_.Bind(&block24, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219);
    compiler::CodeAssemblerExceptionHandlerLabel catch220__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch220__label);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp205}, MessageTemplate::kTooManyElementsInPromiseAll);
    }
    if (catch220__label.is_used()) {
      compiler::CodeAssemblerLabel catch220_skip(&ca_);
      TNode<Object> catch220_exception_object;
      ca_.Bind(&catch220__label, &catch220_exception_object);
      ca_.Goto(&block28, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218, tmp219, tmp205, catch220_exception_object);
    }
  }

  if (block28.is_used()) {
    TNode<Context> tmp221;
    TNode<JSReceiver> tmp222;
    TNode<PromiseCapability> tmp223;
    TNode<JSReceiver> tmp224;
    TNode<Object> tmp225;
    TNode<NativeContext> tmp226;
    TNode<HeapObject> tmp227;
    TNode<Object> tmp228;
    TNode<Object> tmp229;
    TNode<Context> tmp230;
    TNode<Smi> tmp231;
    TNode<Object> tmp232;
    TNode<Map> tmp233;
    TNode<Object> tmp234;
    TNode<JSReceiver> tmp235;
    TNode<Context> tmp236;
    TNode<Object> tmp237;
    ca_.Bind(&block28, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp221}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp224}, TNode<Object>{tmp225}}, TNode<Object>{tmp237}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block29, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp237, tmp224, tmp225, tmp237, tmp221, result_0_0.value());
    }
  }

  if (block29.is_used()) {
    TNode<Context> tmp238;
    TNode<JSReceiver> tmp239;
    TNode<PromiseCapability> tmp240;
    TNode<JSReceiver> tmp241;
    TNode<Object> tmp242;
    TNode<NativeContext> tmp243;
    TNode<HeapObject> tmp244;
    TNode<Object> tmp245;
    TNode<Object> tmp246;
    TNode<Context> tmp247;
    TNode<Smi> tmp248;
    TNode<Object> tmp249;
    TNode<Map> tmp250;
    TNode<Object> tmp251;
    TNode<JSReceiver> tmp252;
    TNode<Object> tmp253;
    TNode<JSReceiver> tmp254;
    TNode<Object> tmp255;
    TNode<Object> tmp256;
    TNode<Context> tmp257;
    TNode<Object> tmp258;
    ca_.Bind(&block29, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258);
    ca_.Goto(&block1, tmp258);
  }

  if (block25.is_used()) {
    TNode<Context> tmp259;
    TNode<JSReceiver> tmp260;
    TNode<PromiseCapability> tmp261;
    TNode<JSReceiver> tmp262;
    TNode<Object> tmp263;
    TNode<NativeContext> tmp264;
    TNode<HeapObject> tmp265;
    TNode<Object> tmp266;
    TNode<Object> tmp267;
    TNode<Context> tmp268;
    TNode<Smi> tmp269;
    TNode<Object> tmp270;
    TNode<Map> tmp271;
    TNode<Object> tmp272;
    TNode<JSReceiver> tmp273;
    ca_.Bind(&block25, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273);
    TNode<Object> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp268}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp275;
    USE(tmp275);
    tmp275 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp259}, TNode<Object>{tmp274});
    TNode<Smi> tmp276;
    USE(tmp276);
    tmp276 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp277;
    USE(tmp277);
    tmp277 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp275}, TNode<Smi>{tmp276});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp268}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp277});
    TNode<JSFunction> tmp278;
    USE(tmp278);
    tmp278 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{tmp259}, TNode<Context>{tmp268}, TNode<Smi>{tmp269}, TNode<NativeContext>{tmp264}, Context::Field::PROMISE_ALL_RESOLVE_ELEMENT_SHARED_FUN);
    TNode<IntPtrT> tmp279;
    USE(tmp279);
    tmp279 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp280 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp261, tmp279});
    TNode<JSReceiver> tmp281;
    USE(tmp281);
    tmp281 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp259}, TNode<Object>{tmp280});
    TNode<Oddball> tmp282;
    USE(tmp282);
    tmp282 = Undefined_0(state_);
    TNode<BoolT> tmp283;
    USE(tmp283);
    tmp283 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp270}, TNode<HeapObject>{tmp282});
    ca_.Branch(tmp283, &block34, &block35, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp275, tmp278, tmp281, tmp283);
  }

  if (block34.is_used()) {
    TNode<Context> tmp284;
    TNode<JSReceiver> tmp285;
    TNode<PromiseCapability> tmp286;
    TNode<JSReceiver> tmp287;
    TNode<Object> tmp288;
    TNode<NativeContext> tmp289;
    TNode<HeapObject> tmp290;
    TNode<Object> tmp291;
    TNode<Object> tmp292;
    TNode<Context> tmp293;
    TNode<Smi> tmp294;
    TNode<Object> tmp295;
    TNode<Map> tmp296;
    TNode<Object> tmp297;
    TNode<JSReceiver> tmp298;
    TNode<Smi> tmp299;
    TNode<JSReceiver> tmp300;
    TNode<JSReceiver> tmp301;
    TNode<BoolT> tmp302;
    ca_.Bind(&block34, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302);
    TNode<BoolT> tmp303;
    USE(tmp303);
    tmp303 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block36, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303);
  }

  if (block35.is_used()) {
    TNode<Context> tmp304;
    TNode<JSReceiver> tmp305;
    TNode<PromiseCapability> tmp306;
    TNode<JSReceiver> tmp307;
    TNode<Object> tmp308;
    TNode<NativeContext> tmp309;
    TNode<HeapObject> tmp310;
    TNode<Object> tmp311;
    TNode<Object> tmp312;
    TNode<Context> tmp313;
    TNode<Smi> tmp314;
    TNode<Object> tmp315;
    TNode<Map> tmp316;
    TNode<Object> tmp317;
    TNode<JSReceiver> tmp318;
    TNode<Smi> tmp319;
    TNode<JSReceiver> tmp320;
    TNode<JSReceiver> tmp321;
    TNode<BoolT> tmp322;
    ca_.Bind(&block35, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322);
    TNode<BoolT> tmp323;
    USE(tmp323);
    tmp323 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Goto(&block36, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp320, tmp321, tmp322, tmp323);
  }

  if (block36.is_used()) {
    TNode<Context> tmp324;
    TNode<JSReceiver> tmp325;
    TNode<PromiseCapability> tmp326;
    TNode<JSReceiver> tmp327;
    TNode<Object> tmp328;
    TNode<NativeContext> tmp329;
    TNode<HeapObject> tmp330;
    TNode<Object> tmp331;
    TNode<Object> tmp332;
    TNode<Context> tmp333;
    TNode<Smi> tmp334;
    TNode<Object> tmp335;
    TNode<Map> tmp336;
    TNode<Object> tmp337;
    TNode<JSReceiver> tmp338;
    TNode<Smi> tmp339;
    TNode<JSReceiver> tmp340;
    TNode<JSReceiver> tmp341;
    TNode<BoolT> tmp342;
    TNode<BoolT> tmp343;
    ca_.Bind(&block36, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343);
    ca_.Branch(tmp343, &block37, &block38, tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp343);
  }

  if (block37.is_used()) {
    TNode<Context> tmp344;
    TNode<JSReceiver> tmp345;
    TNode<PromiseCapability> tmp346;
    TNode<JSReceiver> tmp347;
    TNode<Object> tmp348;
    TNode<NativeContext> tmp349;
    TNode<HeapObject> tmp350;
    TNode<Object> tmp351;
    TNode<Object> tmp352;
    TNode<Context> tmp353;
    TNode<Smi> tmp354;
    TNode<Object> tmp355;
    TNode<Map> tmp356;
    TNode<Object> tmp357;
    TNode<JSReceiver> tmp358;
    TNode<Smi> tmp359;
    TNode<JSReceiver> tmp360;
    TNode<JSReceiver> tmp361;
    TNode<BoolT> tmp362;
    ca_.Bind(&block37, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362);
    TNode<BoolT> tmp363;
    USE(tmp363);
    tmp363 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block39, tmp344, tmp345, tmp346, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362, tmp363);
  }

  if (block38.is_used()) {
    TNode<Context> tmp364;
    TNode<JSReceiver> tmp365;
    TNode<PromiseCapability> tmp366;
    TNode<JSReceiver> tmp367;
    TNode<Object> tmp368;
    TNode<NativeContext> tmp369;
    TNode<HeapObject> tmp370;
    TNode<Object> tmp371;
    TNode<Object> tmp372;
    TNode<Context> tmp373;
    TNode<Smi> tmp374;
    TNode<Object> tmp375;
    TNode<Map> tmp376;
    TNode<Object> tmp377;
    TNode<JSReceiver> tmp378;
    TNode<Smi> tmp379;
    TNode<JSReceiver> tmp380;
    TNode<JSReceiver> tmp381;
    TNode<BoolT> tmp382;
    ca_.Bind(&block38, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382);
    TNode<BoolT> tmp383;
    USE(tmp383);
    tmp383 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    ca_.Goto(&block39, tmp364, tmp365, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp377, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383);
  }

  if (block39.is_used()) {
    TNode<Context> tmp384;
    TNode<JSReceiver> tmp385;
    TNode<PromiseCapability> tmp386;
    TNode<JSReceiver> tmp387;
    TNode<Object> tmp388;
    TNode<NativeContext> tmp389;
    TNode<HeapObject> tmp390;
    TNode<Object> tmp391;
    TNode<Object> tmp392;
    TNode<Context> tmp393;
    TNode<Smi> tmp394;
    TNode<Object> tmp395;
    TNode<Map> tmp396;
    TNode<Object> tmp397;
    TNode<JSReceiver> tmp398;
    TNode<Smi> tmp399;
    TNode<JSReceiver> tmp400;
    TNode<JSReceiver> tmp401;
    TNode<BoolT> tmp402;
    TNode<BoolT> tmp403;
    ca_.Bind(&block39, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403);
    ca_.Branch(tmp403, &block40, &block41, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp392, tmp393, tmp394, tmp395, tmp396, tmp397, tmp398, tmp399, tmp400, tmp401, tmp403);
  }

  if (block40.is_used()) {
    TNode<Context> tmp404;
    TNode<JSReceiver> tmp405;
    TNode<PromiseCapability> tmp406;
    TNode<JSReceiver> tmp407;
    TNode<Object> tmp408;
    TNode<NativeContext> tmp409;
    TNode<HeapObject> tmp410;
    TNode<Object> tmp411;
    TNode<Object> tmp412;
    TNode<Context> tmp413;
    TNode<Smi> tmp414;
    TNode<Object> tmp415;
    TNode<Map> tmp416;
    TNode<Object> tmp417;
    TNode<JSReceiver> tmp418;
    TNode<Smi> tmp419;
    TNode<JSReceiver> tmp420;
    TNode<JSReceiver> tmp421;
    TNode<BoolT> tmp422;
    ca_.Bind(&block40, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418, &tmp419, &tmp420, &tmp421, &tmp422);
    TNode<BoolT> tmp423;
    USE(tmp423);
    tmp423 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block42, tmp404, tmp405, tmp406, tmp407, tmp408, tmp409, tmp410, tmp411, tmp412, tmp413, tmp414, tmp415, tmp416, tmp417, tmp418, tmp419, tmp420, tmp421, tmp422, tmp423);
  }

  if (block41.is_used()) {
    TNode<Context> tmp424;
    TNode<JSReceiver> tmp425;
    TNode<PromiseCapability> tmp426;
    TNode<JSReceiver> tmp427;
    TNode<Object> tmp428;
    TNode<NativeContext> tmp429;
    TNode<HeapObject> tmp430;
    TNode<Object> tmp431;
    TNode<Object> tmp432;
    TNode<Context> tmp433;
    TNode<Smi> tmp434;
    TNode<Object> tmp435;
    TNode<Map> tmp436;
    TNode<Object> tmp437;
    TNode<JSReceiver> tmp438;
    TNode<Smi> tmp439;
    TNode<JSReceiver> tmp440;
    TNode<JSReceiver> tmp441;
    TNode<BoolT> tmp442;
    ca_.Bind(&block41, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433, &tmp434, &tmp435, &tmp436, &tmp437, &tmp438, &tmp439, &tmp440, &tmp441, &tmp442);
    TNode<BoolT> tmp443;
    USE(tmp443);
    tmp443 = Is_Smi_JSAny_0(state_, TNode<Context>{tmp424}, TNode<Object>{tmp437});
    ca_.Goto(&block42, tmp424, tmp425, tmp426, tmp427, tmp428, tmp429, tmp430, tmp431, tmp432, tmp433, tmp434, tmp435, tmp436, tmp437, tmp438, tmp439, tmp440, tmp441, tmp442, tmp443);
  }

  if (block42.is_used()) {
    TNode<Context> tmp444;
    TNode<JSReceiver> tmp445;
    TNode<PromiseCapability> tmp446;
    TNode<JSReceiver> tmp447;
    TNode<Object> tmp448;
    TNode<NativeContext> tmp449;
    TNode<HeapObject> tmp450;
    TNode<Object> tmp451;
    TNode<Object> tmp452;
    TNode<Context> tmp453;
    TNode<Smi> tmp454;
    TNode<Object> tmp455;
    TNode<Map> tmp456;
    TNode<Object> tmp457;
    TNode<JSReceiver> tmp458;
    TNode<Smi> tmp459;
    TNode<JSReceiver> tmp460;
    TNode<JSReceiver> tmp461;
    TNode<BoolT> tmp462;
    TNode<BoolT> tmp463;
    ca_.Bind(&block42, &tmp444, &tmp445, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452, &tmp453, &tmp454, &tmp455, &tmp456, &tmp457, &tmp458, &tmp459, &tmp460, &tmp461, &tmp462, &tmp463);
    ca_.Branch(tmp463, &block43, &block44, tmp444, tmp445, tmp446, tmp447, tmp448, tmp449, tmp450, tmp451, tmp452, tmp453, tmp454, tmp455, tmp456, tmp457, tmp458, tmp459, tmp460, tmp461, tmp463);
  }

  if (block43.is_used()) {
    TNode<Context> tmp464;
    TNode<JSReceiver> tmp465;
    TNode<PromiseCapability> tmp466;
    TNode<JSReceiver> tmp467;
    TNode<Object> tmp468;
    TNode<NativeContext> tmp469;
    TNode<HeapObject> tmp470;
    TNode<Object> tmp471;
    TNode<Object> tmp472;
    TNode<Context> tmp473;
    TNode<Smi> tmp474;
    TNode<Object> tmp475;
    TNode<Map> tmp476;
    TNode<Object> tmp477;
    TNode<JSReceiver> tmp478;
    TNode<Smi> tmp479;
    TNode<JSReceiver> tmp480;
    TNode<JSReceiver> tmp481;
    TNode<BoolT> tmp482;
    ca_.Bind(&block43, &tmp464, &tmp465, &tmp466, &tmp467, &tmp468, &tmp469, &tmp470, &tmp471, &tmp472, &tmp473, &tmp474, &tmp475, &tmp476, &tmp477, &tmp478, &tmp479, &tmp480, &tmp481, &tmp482);
    TNode<BoolT> tmp483;
    USE(tmp483);
    tmp483 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block45, tmp464, tmp465, tmp466, tmp467, tmp468, tmp469, tmp470, tmp471, tmp472, tmp473, tmp474, tmp475, tmp476, tmp477, tmp478, tmp479, tmp480, tmp481, tmp482, tmp483);
  }

  if (block44.is_used()) {
    TNode<Context> tmp484;
    TNode<JSReceiver> tmp485;
    TNode<PromiseCapability> tmp486;
    TNode<JSReceiver> tmp487;
    TNode<Object> tmp488;
    TNode<NativeContext> tmp489;
    TNode<HeapObject> tmp490;
    TNode<Object> tmp491;
    TNode<Object> tmp492;
    TNode<Context> tmp493;
    TNode<Smi> tmp494;
    TNode<Object> tmp495;
    TNode<Map> tmp496;
    TNode<Object> tmp497;
    TNode<JSReceiver> tmp498;
    TNode<Smi> tmp499;
    TNode<JSReceiver> tmp500;
    TNode<JSReceiver> tmp501;
    TNode<BoolT> tmp502;
    ca_.Bind(&block44, &tmp484, &tmp485, &tmp486, &tmp487, &tmp488, &tmp489, &tmp490, &tmp491, &tmp492, &tmp493, &tmp494, &tmp495, &tmp496, &tmp497, &tmp498, &tmp499, &tmp500, &tmp501, &tmp502);
    TNode<HeapObject> tmp503;
    USE(tmp503);
    tmp503 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp484}, TNode<Object>{tmp497});
    TNode<IntPtrT> tmp504;
    USE(tmp504);
    tmp504 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp505 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp503, tmp504});
    TNode<BoolT> tmp506;
    USE(tmp506);
    tmp506 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{tmp484}, TNode<NativeContext>{tmp489}, TNode<Map>{tmp505});
    TNode<BoolT> tmp507;
    USE(tmp507);
    tmp507 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp506});
    ca_.Goto(&block45, tmp484, tmp485, tmp486, tmp487, tmp488, tmp489, tmp490, tmp491, tmp492, tmp493, tmp494, tmp495, tmp496, tmp497, tmp498, tmp499, tmp500, tmp501, tmp502, tmp507);
  }

  if (block45.is_used()) {
    TNode<Context> tmp508;
    TNode<JSReceiver> tmp509;
    TNode<PromiseCapability> tmp510;
    TNode<JSReceiver> tmp511;
    TNode<Object> tmp512;
    TNode<NativeContext> tmp513;
    TNode<HeapObject> tmp514;
    TNode<Object> tmp515;
    TNode<Object> tmp516;
    TNode<Context> tmp517;
    TNode<Smi> tmp518;
    TNode<Object> tmp519;
    TNode<Map> tmp520;
    TNode<Object> tmp521;
    TNode<JSReceiver> tmp522;
    TNode<Smi> tmp523;
    TNode<JSReceiver> tmp524;
    TNode<JSReceiver> tmp525;
    TNode<BoolT> tmp526;
    TNode<BoolT> tmp527;
    ca_.Bind(&block45, &tmp508, &tmp509, &tmp510, &tmp511, &tmp512, &tmp513, &tmp514, &tmp515, &tmp516, &tmp517, &tmp518, &tmp519, &tmp520, &tmp521, &tmp522, &tmp523, &tmp524, &tmp525, &tmp526, &tmp527);
    ca_.Branch(tmp527, &block32, &block33, tmp508, tmp509, tmp510, tmp511, tmp512, tmp513, tmp514, tmp515, tmp516, tmp517, tmp518, tmp519, tmp520, tmp521, tmp522, tmp523, tmp524, tmp525);
  }

  if (block32.is_used()) {
    TNode<Context> tmp528;
    TNode<JSReceiver> tmp529;
    TNode<PromiseCapability> tmp530;
    TNode<JSReceiver> tmp531;
    TNode<Object> tmp532;
    TNode<NativeContext> tmp533;
    TNode<HeapObject> tmp534;
    TNode<Object> tmp535;
    TNode<Object> tmp536;
    TNode<Context> tmp537;
    TNode<Smi> tmp538;
    TNode<Object> tmp539;
    TNode<Map> tmp540;
    TNode<Object> tmp541;
    TNode<JSReceiver> tmp542;
    TNode<Smi> tmp543;
    TNode<JSReceiver> tmp544;
    TNode<JSReceiver> tmp545;
    ca_.Bind(&block32, &tmp528, &tmp529, &tmp530, &tmp531, &tmp532, &tmp533, &tmp534, &tmp535, &tmp536, &tmp537, &tmp538, &tmp539, &tmp540, &tmp541, &tmp542, &tmp543, &tmp544, &tmp545);
    TNode<JSReceiver> tmp546;
    USE(tmp546);
    compiler::CodeAssemblerExceptionHandlerLabel catch547__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch547__label);
    tmp546 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp528}, TNode<Object>{tmp529});
    }
    if (catch547__label.is_used()) {
      compiler::CodeAssemblerLabel catch547_skip(&ca_);
      ca_.Goto(&catch547_skip);
      TNode<Object> catch547_exception_object;
      ca_.Bind(&catch547__label, &catch547_exception_object);
      ca_.Goto(&block49, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp529, tmp528, catch547_exception_object);
      ca_.Bind(&catch547_skip);
    }
    TNode<Object> tmp548;
    USE(tmp548);
    compiler::CodeAssemblerExceptionHandlerLabel catch549__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch549__label);
    tmp548 = CallResolve_0(state_, TNode<Context>{tmp528}, TNode<JSReceiver>{tmp546}, TNode<Object>{tmp539}, TNode<Object>{tmp541});
    }
    if (catch549__label.is_used()) {
      compiler::CodeAssemblerLabel catch549_skip(&ca_);
      ca_.Goto(&catch549_skip);
      TNode<Object> catch549_exception_object;
      ca_.Bind(&catch549__label, &catch549_exception_object);
      ca_.Goto(&block50, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp546, tmp539, tmp541, tmp528, catch549_exception_object);
      ca_.Bind(&catch549_skip);
    }
    TNode<String> tmp550;
    USE(tmp550);
    tmp550 = kThenString_0(state_);
    TNode<Object> tmp551;
    USE(tmp551);
    compiler::CodeAssemblerExceptionHandlerLabel catch552__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch552__label);
    tmp551 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp528}, TNode<Object>{tmp548}, TNode<Object>{tmp550});
    }
    if (catch552__label.is_used()) {
      compiler::CodeAssemblerLabel catch552_skip(&ca_);
      ca_.Goto(&catch552_skip);
      TNode<Object> catch552_exception_object;
      ca_.Bind(&catch552__label, &catch552_exception_object);
      ca_.Goto(&block51, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp548, tmp548, tmp550, tmp528, catch552_exception_object);
      ca_.Bind(&catch552_skip);
    }
    TNode<Object> tmp553;
    USE(tmp553);
    compiler::CodeAssemblerExceptionHandlerLabel catch554__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch554__label);
    tmp553 = CodeStubAssembler(state_).Call(TNode<Context>{tmp533}, TNode<Object>{tmp551}, TNode<Object>{tmp548}, TNode<Object>{tmp544}, TNode<Object>{tmp545});
    }
    if (catch554__label.is_used()) {
      compiler::CodeAssemblerLabel catch554_skip(&ca_);
      ca_.Goto(&catch554_skip);
      TNode<Object> catch554_exception_object;
      ca_.Bind(&catch554__label, &catch554_exception_object);
      ca_.Goto(&block52, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp548, tmp551, tmp533, tmp551, tmp548, tmp544, tmp545, catch554_exception_object);
      ca_.Bind(&catch554_skip);
    }
    TNode<BoolT> tmp555;
    USE(tmp555);
    compiler::CodeAssemblerExceptionHandlerLabel catch556__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch556__label);
    tmp555 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch556__label.is_used()) {
      compiler::CodeAssemblerLabel catch556_skip(&ca_);
      ca_.Goto(&catch556_skip);
      TNode<Object> catch556_exception_object;
      ca_.Bind(&catch556__label, &catch556_exception_object);
      ca_.Goto(&block55, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp548, tmp551, tmp553, catch556_exception_object);
      ca_.Bind(&catch556_skip);
    }
    ca_.Branch(tmp555, &block56, &block57, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp548, tmp551, tmp553, tmp555);
  }

  if (block49.is_used()) {
    TNode<Context> tmp557;
    TNode<JSReceiver> tmp558;
    TNode<PromiseCapability> tmp559;
    TNode<JSReceiver> tmp560;
    TNode<Object> tmp561;
    TNode<NativeContext> tmp562;
    TNode<HeapObject> tmp563;
    TNode<Object> tmp564;
    TNode<Object> tmp565;
    TNode<Context> tmp566;
    TNode<Smi> tmp567;
    TNode<Object> tmp568;
    TNode<Map> tmp569;
    TNode<Object> tmp570;
    TNode<JSReceiver> tmp571;
    TNode<Smi> tmp572;
    TNode<JSReceiver> tmp573;
    TNode<JSReceiver> tmp574;
    TNode<JSReceiver> tmp575;
    TNode<Context> tmp576;
    TNode<Object> tmp577;
    ca_.Bind(&block49, &tmp557, &tmp558, &tmp559, &tmp560, &tmp561, &tmp562, &tmp563, &tmp564, &tmp565, &tmp566, &tmp567, &tmp568, &tmp569, &tmp570, &tmp571, &tmp572, &tmp573, &tmp574, &tmp575, &tmp576, &tmp577);
    ca_.Goto(&block48, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563, tmp564, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp573, tmp574, tmp577);
  }

  if (block50.is_used()) {
    TNode<Context> tmp578;
    TNode<JSReceiver> tmp579;
    TNode<PromiseCapability> tmp580;
    TNode<JSReceiver> tmp581;
    TNode<Object> tmp582;
    TNode<NativeContext> tmp583;
    TNode<HeapObject> tmp584;
    TNode<Object> tmp585;
    TNode<Object> tmp586;
    TNode<Context> tmp587;
    TNode<Smi> tmp588;
    TNode<Object> tmp589;
    TNode<Map> tmp590;
    TNode<Object> tmp591;
    TNode<JSReceiver> tmp592;
    TNode<Smi> tmp593;
    TNode<JSReceiver> tmp594;
    TNode<JSReceiver> tmp595;
    TNode<JSReceiver> tmp596;
    TNode<Object> tmp597;
    TNode<Object> tmp598;
    TNode<Context> tmp599;
    TNode<Object> tmp600;
    ca_.Bind(&block50, &tmp578, &tmp579, &tmp580, &tmp581, &tmp582, &tmp583, &tmp584, &tmp585, &tmp586, &tmp587, &tmp588, &tmp589, &tmp590, &tmp591, &tmp592, &tmp593, &tmp594, &tmp595, &tmp596, &tmp597, &tmp598, &tmp599, &tmp600);
    ca_.Goto(&block48, tmp578, tmp579, tmp580, tmp581, tmp582, tmp583, tmp584, tmp585, tmp586, tmp587, tmp588, tmp589, tmp590, tmp591, tmp592, tmp593, tmp594, tmp595, tmp600);
  }

  if (block51.is_used()) {
    TNode<Context> tmp601;
    TNode<JSReceiver> tmp602;
    TNode<PromiseCapability> tmp603;
    TNode<JSReceiver> tmp604;
    TNode<Object> tmp605;
    TNode<NativeContext> tmp606;
    TNode<HeapObject> tmp607;
    TNode<Object> tmp608;
    TNode<Object> tmp609;
    TNode<Context> tmp610;
    TNode<Smi> tmp611;
    TNode<Object> tmp612;
    TNode<Map> tmp613;
    TNode<Object> tmp614;
    TNode<JSReceiver> tmp615;
    TNode<Smi> tmp616;
    TNode<JSReceiver> tmp617;
    TNode<JSReceiver> tmp618;
    TNode<Object> tmp619;
    TNode<Object> tmp620;
    TNode<String> tmp621;
    TNode<Context> tmp622;
    TNode<Object> tmp623;
    ca_.Bind(&block51, &tmp601, &tmp602, &tmp603, &tmp604, &tmp605, &tmp606, &tmp607, &tmp608, &tmp609, &tmp610, &tmp611, &tmp612, &tmp613, &tmp614, &tmp615, &tmp616, &tmp617, &tmp618, &tmp619, &tmp620, &tmp621, &tmp622, &tmp623);
    ca_.Goto(&block48, tmp601, tmp602, tmp603, tmp604, tmp605, tmp606, tmp607, tmp608, tmp609, tmp610, tmp611, tmp612, tmp613, tmp614, tmp615, tmp616, tmp617, tmp618, tmp623);
  }

  if (block52.is_used()) {
    TNode<Context> tmp624;
    TNode<JSReceiver> tmp625;
    TNode<PromiseCapability> tmp626;
    TNode<JSReceiver> tmp627;
    TNode<Object> tmp628;
    TNode<NativeContext> tmp629;
    TNode<HeapObject> tmp630;
    TNode<Object> tmp631;
    TNode<Object> tmp632;
    TNode<Context> tmp633;
    TNode<Smi> tmp634;
    TNode<Object> tmp635;
    TNode<Map> tmp636;
    TNode<Object> tmp637;
    TNode<JSReceiver> tmp638;
    TNode<Smi> tmp639;
    TNode<JSReceiver> tmp640;
    TNode<JSReceiver> tmp641;
    TNode<Object> tmp642;
    TNode<Object> tmp643;
    TNode<NativeContext> tmp644;
    TNode<Object> tmp645;
    TNode<Object> tmp646;
    TNode<JSReceiver> tmp647;
    TNode<JSReceiver> tmp648;
    TNode<Object> tmp649;
    ca_.Bind(&block52, &tmp624, &tmp625, &tmp626, &tmp627, &tmp628, &tmp629, &tmp630, &tmp631, &tmp632, &tmp633, &tmp634, &tmp635, &tmp636, &tmp637, &tmp638, &tmp639, &tmp640, &tmp641, &tmp642, &tmp643, &tmp644, &tmp645, &tmp646, &tmp647, &tmp648, &tmp649);
    ca_.Goto(&block48, tmp624, tmp625, tmp626, tmp627, tmp628, tmp629, tmp630, tmp631, tmp632, tmp633, tmp634, tmp635, tmp636, tmp637, tmp638, tmp639, tmp640, tmp641, tmp649);
  }

  if (block55.is_used()) {
    TNode<Context> tmp650;
    TNode<JSReceiver> tmp651;
    TNode<PromiseCapability> tmp652;
    TNode<JSReceiver> tmp653;
    TNode<Object> tmp654;
    TNode<NativeContext> tmp655;
    TNode<HeapObject> tmp656;
    TNode<Object> tmp657;
    TNode<Object> tmp658;
    TNode<Context> tmp659;
    TNode<Smi> tmp660;
    TNode<Object> tmp661;
    TNode<Map> tmp662;
    TNode<Object> tmp663;
    TNode<JSReceiver> tmp664;
    TNode<Smi> tmp665;
    TNode<JSReceiver> tmp666;
    TNode<JSReceiver> tmp667;
    TNode<Object> tmp668;
    TNode<Object> tmp669;
    TNode<Object> tmp670;
    TNode<Object> tmp671;
    ca_.Bind(&block55, &tmp650, &tmp651, &tmp652, &tmp653, &tmp654, &tmp655, &tmp656, &tmp657, &tmp658, &tmp659, &tmp660, &tmp661, &tmp662, &tmp663, &tmp664, &tmp665, &tmp666, &tmp667, &tmp668, &tmp669, &tmp670, &tmp671);
    ca_.Goto(&block48, tmp650, tmp651, tmp652, tmp653, tmp654, tmp655, tmp656, tmp657, tmp658, tmp659, tmp660, tmp661, tmp662, tmp663, tmp664, tmp665, tmp666, tmp667, tmp671);
  }

  if (block56.is_used()) {
    TNode<Context> tmp672;
    TNode<JSReceiver> tmp673;
    TNode<PromiseCapability> tmp674;
    TNode<JSReceiver> tmp675;
    TNode<Object> tmp676;
    TNode<NativeContext> tmp677;
    TNode<HeapObject> tmp678;
    TNode<Object> tmp679;
    TNode<Object> tmp680;
    TNode<Context> tmp681;
    TNode<Smi> tmp682;
    TNode<Object> tmp683;
    TNode<Map> tmp684;
    TNode<Object> tmp685;
    TNode<JSReceiver> tmp686;
    TNode<Smi> tmp687;
    TNode<JSReceiver> tmp688;
    TNode<JSReceiver> tmp689;
    TNode<Object> tmp690;
    TNode<Object> tmp691;
    TNode<Object> tmp692;
    TNode<BoolT> tmp693;
    ca_.Bind(&block56, &tmp672, &tmp673, &tmp674, &tmp675, &tmp676, &tmp677, &tmp678, &tmp679, &tmp680, &tmp681, &tmp682, &tmp683, &tmp684, &tmp685, &tmp686, &tmp687, &tmp688, &tmp689, &tmp690, &tmp691, &tmp692, &tmp693);
    TNode<BoolT> tmp694;
    USE(tmp694);
    compiler::CodeAssemblerExceptionHandlerLabel catch695__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch695__label);
    tmp694 = Is_JSPromise_JSAny_0(state_, TNode<Context>{tmp672}, TNode<Object>{tmp692});
    }
    if (catch695__label.is_used()) {
      compiler::CodeAssemblerLabel catch695_skip(&ca_);
      ca_.Goto(&catch695_skip);
      TNode<Object> catch695_exception_object;
      ca_.Bind(&catch695__label, &catch695_exception_object);
      ca_.Goto(&block59, tmp672, tmp673, tmp674, tmp675, tmp676, tmp677, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp692, tmp693, tmp692, tmp672, catch695_exception_object);
      ca_.Bind(&catch695_skip);
    }
    ca_.Goto(&block58, tmp672, tmp673, tmp674, tmp675, tmp676, tmp677, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp692, tmp693, tmp694);
  }

  if (block59.is_used()) {
    TNode<Context> tmp696;
    TNode<JSReceiver> tmp697;
    TNode<PromiseCapability> tmp698;
    TNode<JSReceiver> tmp699;
    TNode<Object> tmp700;
    TNode<NativeContext> tmp701;
    TNode<HeapObject> tmp702;
    TNode<Object> tmp703;
    TNode<Object> tmp704;
    TNode<Context> tmp705;
    TNode<Smi> tmp706;
    TNode<Object> tmp707;
    TNode<Map> tmp708;
    TNode<Object> tmp709;
    TNode<JSReceiver> tmp710;
    TNode<Smi> tmp711;
    TNode<JSReceiver> tmp712;
    TNode<JSReceiver> tmp713;
    TNode<Object> tmp714;
    TNode<Object> tmp715;
    TNode<Object> tmp716;
    TNode<BoolT> tmp717;
    TNode<Object> tmp718;
    TNode<Context> tmp719;
    TNode<Object> tmp720;
    ca_.Bind(&block59, &tmp696, &tmp697, &tmp698, &tmp699, &tmp700, &tmp701, &tmp702, &tmp703, &tmp704, &tmp705, &tmp706, &tmp707, &tmp708, &tmp709, &tmp710, &tmp711, &tmp712, &tmp713, &tmp714, &tmp715, &tmp716, &tmp717, &tmp718, &tmp719, &tmp720);
    ca_.Goto(&block48, tmp696, tmp697, tmp698, tmp699, tmp700, tmp701, tmp702, tmp703, tmp704, tmp705, tmp706, tmp707, tmp708, tmp709, tmp710, tmp711, tmp712, tmp713, tmp720);
  }

  if (block57.is_used()) {
    TNode<Context> tmp721;
    TNode<JSReceiver> tmp722;
    TNode<PromiseCapability> tmp723;
    TNode<JSReceiver> tmp724;
    TNode<Object> tmp725;
    TNode<NativeContext> tmp726;
    TNode<HeapObject> tmp727;
    TNode<Object> tmp728;
    TNode<Object> tmp729;
    TNode<Context> tmp730;
    TNode<Smi> tmp731;
    TNode<Object> tmp732;
    TNode<Map> tmp733;
    TNode<Object> tmp734;
    TNode<JSReceiver> tmp735;
    TNode<Smi> tmp736;
    TNode<JSReceiver> tmp737;
    TNode<JSReceiver> tmp738;
    TNode<Object> tmp739;
    TNode<Object> tmp740;
    TNode<Object> tmp741;
    TNode<BoolT> tmp742;
    ca_.Bind(&block57, &tmp721, &tmp722, &tmp723, &tmp724, &tmp725, &tmp726, &tmp727, &tmp728, &tmp729, &tmp730, &tmp731, &tmp732, &tmp733, &tmp734, &tmp735, &tmp736, &tmp737, &tmp738, &tmp739, &tmp740, &tmp741, &tmp742);
    TNode<BoolT> tmp743;
    USE(tmp743);
    compiler::CodeAssemblerExceptionHandlerLabel catch744__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch744__label);
    tmp743 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch744__label.is_used()) {
      compiler::CodeAssemblerLabel catch744_skip(&ca_);
      ca_.Goto(&catch744_skip);
      TNode<Object> catch744_exception_object;
      ca_.Bind(&catch744__label, &catch744_exception_object);
      ca_.Goto(&block60, tmp721, tmp722, tmp723, tmp724, tmp725, tmp726, tmp727, tmp728, tmp729, tmp730, tmp731, tmp732, tmp733, tmp734, tmp735, tmp736, tmp737, tmp738, tmp739, tmp740, tmp741, tmp742, catch744_exception_object);
      ca_.Bind(&catch744_skip);
    }
    ca_.Goto(&block58, tmp721, tmp722, tmp723, tmp724, tmp725, tmp726, tmp727, tmp728, tmp729, tmp730, tmp731, tmp732, tmp733, tmp734, tmp735, tmp736, tmp737, tmp738, tmp739, tmp740, tmp741, tmp742, tmp743);
  }

  if (block60.is_used()) {
    TNode<Context> tmp745;
    TNode<JSReceiver> tmp746;
    TNode<PromiseCapability> tmp747;
    TNode<JSReceiver> tmp748;
    TNode<Object> tmp749;
    TNode<NativeContext> tmp750;
    TNode<HeapObject> tmp751;
    TNode<Object> tmp752;
    TNode<Object> tmp753;
    TNode<Context> tmp754;
    TNode<Smi> tmp755;
    TNode<Object> tmp756;
    TNode<Map> tmp757;
    TNode<Object> tmp758;
    TNode<JSReceiver> tmp759;
    TNode<Smi> tmp760;
    TNode<JSReceiver> tmp761;
    TNode<JSReceiver> tmp762;
    TNode<Object> tmp763;
    TNode<Object> tmp764;
    TNode<Object> tmp765;
    TNode<BoolT> tmp766;
    TNode<Object> tmp767;
    ca_.Bind(&block60, &tmp745, &tmp746, &tmp747, &tmp748, &tmp749, &tmp750, &tmp751, &tmp752, &tmp753, &tmp754, &tmp755, &tmp756, &tmp757, &tmp758, &tmp759, &tmp760, &tmp761, &tmp762, &tmp763, &tmp764, &tmp765, &tmp766, &tmp767);
    ca_.Goto(&block48, tmp745, tmp746, tmp747, tmp748, tmp749, tmp750, tmp751, tmp752, tmp753, tmp754, tmp755, tmp756, tmp757, tmp758, tmp759, tmp760, tmp761, tmp762, tmp767);
  }

  if (block58.is_used()) {
    TNode<Context> tmp768;
    TNode<JSReceiver> tmp769;
    TNode<PromiseCapability> tmp770;
    TNode<JSReceiver> tmp771;
    TNode<Object> tmp772;
    TNode<NativeContext> tmp773;
    TNode<HeapObject> tmp774;
    TNode<Object> tmp775;
    TNode<Object> tmp776;
    TNode<Context> tmp777;
    TNode<Smi> tmp778;
    TNode<Object> tmp779;
    TNode<Map> tmp780;
    TNode<Object> tmp781;
    TNode<JSReceiver> tmp782;
    TNode<Smi> tmp783;
    TNode<JSReceiver> tmp784;
    TNode<JSReceiver> tmp785;
    TNode<Object> tmp786;
    TNode<Object> tmp787;
    TNode<Object> tmp788;
    TNode<BoolT> tmp789;
    TNode<BoolT> tmp790;
    ca_.Bind(&block58, &tmp768, &tmp769, &tmp770, &tmp771, &tmp772, &tmp773, &tmp774, &tmp775, &tmp776, &tmp777, &tmp778, &tmp779, &tmp780, &tmp781, &tmp782, &tmp783, &tmp784, &tmp785, &tmp786, &tmp787, &tmp788, &tmp789, &tmp790);
    ca_.Branch(tmp790, &block53, &block54, tmp768, tmp769, tmp770, tmp771, tmp772, tmp773, tmp774, tmp775, tmp776, tmp777, tmp778, tmp779, tmp780, tmp781, tmp782, tmp783, tmp784, tmp785, tmp786, tmp787, tmp788);
  }

  if (block53.is_used()) {
    TNode<Context> tmp791;
    TNode<JSReceiver> tmp792;
    TNode<PromiseCapability> tmp793;
    TNode<JSReceiver> tmp794;
    TNode<Object> tmp795;
    TNode<NativeContext> tmp796;
    TNode<HeapObject> tmp797;
    TNode<Object> tmp798;
    TNode<Object> tmp799;
    TNode<Context> tmp800;
    TNode<Smi> tmp801;
    TNode<Object> tmp802;
    TNode<Map> tmp803;
    TNode<Object> tmp804;
    TNode<JSReceiver> tmp805;
    TNode<Smi> tmp806;
    TNode<JSReceiver> tmp807;
    TNode<JSReceiver> tmp808;
    TNode<Object> tmp809;
    TNode<Object> tmp810;
    TNode<Object> tmp811;
    ca_.Bind(&block53, &tmp791, &tmp792, &tmp793, &tmp794, &tmp795, &tmp796, &tmp797, &tmp798, &tmp799, &tmp800, &tmp801, &tmp802, &tmp803, &tmp804, &tmp805, &tmp806, &tmp807, &tmp808, &tmp809, &tmp810, &tmp811);
    TNode<Symbol> tmp812;
    USE(tmp812);
    tmp812 = kPromiseHandledBySymbol_0(state_);
    TNode<Object> tmp813;
    USE(tmp813);
    compiler::CodeAssemblerExceptionHandlerLabel catch814__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch814__label);
    tmp813 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp791}, TNode<Object>{tmp811}, TNode<Object>{tmp812}, TNode<Object>{tmp797});
    }
    if (catch814__label.is_used()) {
      compiler::CodeAssemblerLabel catch814_skip(&ca_);
      ca_.Goto(&catch814_skip);
      TNode<Object> catch814_exception_object;
      ca_.Bind(&catch814__label, &catch814_exception_object);
      ca_.Goto(&block61, tmp791, tmp792, tmp793, tmp794, tmp795, tmp796, tmp797, tmp798, tmp799, tmp800, tmp801, tmp802, tmp803, tmp804, tmp805, tmp806, tmp807, tmp808, tmp809, tmp810, tmp811, tmp791, tmp811, tmp812, tmp797, catch814_exception_object);
      ca_.Bind(&catch814_skip);
    }
    ca_.Goto(&block54, tmp791, tmp792, tmp793, tmp794, tmp795, tmp796, tmp797, tmp798, tmp799, tmp800, tmp801, tmp802, tmp803, tmp804, tmp805, tmp806, tmp807, tmp808, tmp809, tmp810, tmp811);
  }

  if (block61.is_used()) {
    TNode<Context> tmp815;
    TNode<JSReceiver> tmp816;
    TNode<PromiseCapability> tmp817;
    TNode<JSReceiver> tmp818;
    TNode<Object> tmp819;
    TNode<NativeContext> tmp820;
    TNode<HeapObject> tmp821;
    TNode<Object> tmp822;
    TNode<Object> tmp823;
    TNode<Context> tmp824;
    TNode<Smi> tmp825;
    TNode<Object> tmp826;
    TNode<Map> tmp827;
    TNode<Object> tmp828;
    TNode<JSReceiver> tmp829;
    TNode<Smi> tmp830;
    TNode<JSReceiver> tmp831;
    TNode<JSReceiver> tmp832;
    TNode<Object> tmp833;
    TNode<Object> tmp834;
    TNode<Object> tmp835;
    TNode<Context> tmp836;
    TNode<Object> tmp837;
    TNode<Symbol> tmp838;
    TNode<HeapObject> tmp839;
    TNode<Object> tmp840;
    ca_.Bind(&block61, &tmp815, &tmp816, &tmp817, &tmp818, &tmp819, &tmp820, &tmp821, &tmp822, &tmp823, &tmp824, &tmp825, &tmp826, &tmp827, &tmp828, &tmp829, &tmp830, &tmp831, &tmp832, &tmp833, &tmp834, &tmp835, &tmp836, &tmp837, &tmp838, &tmp839, &tmp840);
    ca_.Goto(&block48, tmp815, tmp816, tmp817, tmp818, tmp819, tmp820, tmp821, tmp822, tmp823, tmp824, tmp825, tmp826, tmp827, tmp828, tmp829, tmp830, tmp831, tmp832, tmp840);
  }

  if (block54.is_used()) {
    TNode<Context> tmp841;
    TNode<JSReceiver> tmp842;
    TNode<PromiseCapability> tmp843;
    TNode<JSReceiver> tmp844;
    TNode<Object> tmp845;
    TNode<NativeContext> tmp846;
    TNode<HeapObject> tmp847;
    TNode<Object> tmp848;
    TNode<Object> tmp849;
    TNode<Context> tmp850;
    TNode<Smi> tmp851;
    TNode<Object> tmp852;
    TNode<Map> tmp853;
    TNode<Object> tmp854;
    TNode<JSReceiver> tmp855;
    TNode<Smi> tmp856;
    TNode<JSReceiver> tmp857;
    TNode<JSReceiver> tmp858;
    TNode<Object> tmp859;
    TNode<Object> tmp860;
    TNode<Object> tmp861;
    ca_.Bind(&block54, &tmp841, &tmp842, &tmp843, &tmp844, &tmp845, &tmp846, &tmp847, &tmp848, &tmp849, &tmp850, &tmp851, &tmp852, &tmp853, &tmp854, &tmp855, &tmp856, &tmp857, &tmp858, &tmp859, &tmp860, &tmp861);
    ca_.Goto(&block46, tmp841, tmp842, tmp843, tmp844, tmp845, tmp846, tmp847, tmp848, tmp849, tmp850, tmp851, tmp852, tmp853, tmp854, tmp855, tmp856, tmp857, tmp858);
  }

  if (block48.is_used()) {
    TNode<Context> tmp862;
    TNode<JSReceiver> tmp863;
    TNode<PromiseCapability> tmp864;
    TNode<JSReceiver> tmp865;
    TNode<Object> tmp866;
    TNode<NativeContext> tmp867;
    TNode<HeapObject> tmp868;
    TNode<Object> tmp869;
    TNode<Object> tmp870;
    TNode<Context> tmp871;
    TNode<Smi> tmp872;
    TNode<Object> tmp873;
    TNode<Map> tmp874;
    TNode<Object> tmp875;
    TNode<JSReceiver> tmp876;
    TNode<Smi> tmp877;
    TNode<JSReceiver> tmp878;
    TNode<JSReceiver> tmp879;
    TNode<Object> tmp880;
    ca_.Bind(&block48, &tmp862, &tmp863, &tmp864, &tmp865, &tmp866, &tmp867, &tmp868, &tmp869, &tmp870, &tmp871, &tmp872, &tmp873, &tmp874, &tmp875, &tmp876, &tmp877, &tmp878, &tmp879, &tmp880);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp862}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp865}, TNode<Object>{tmp866}}, TNode<Object>{tmp880}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block62, tmp862, tmp863, tmp864, tmp865, tmp866, tmp867, tmp868, tmp869, tmp870, tmp871, tmp872, tmp873, tmp874, tmp875, tmp876, tmp877, tmp878, tmp879, tmp880, tmp865, tmp866, tmp880, tmp862, result_0_0.value());
    }
  }

  if (block62.is_used()) {
    TNode<Context> tmp881;
    TNode<JSReceiver> tmp882;
    TNode<PromiseCapability> tmp883;
    TNode<JSReceiver> tmp884;
    TNode<Object> tmp885;
    TNode<NativeContext> tmp886;
    TNode<HeapObject> tmp887;
    TNode<Object> tmp888;
    TNode<Object> tmp889;
    TNode<Context> tmp890;
    TNode<Smi> tmp891;
    TNode<Object> tmp892;
    TNode<Map> tmp893;
    TNode<Object> tmp894;
    TNode<JSReceiver> tmp895;
    TNode<Smi> tmp896;
    TNode<JSReceiver> tmp897;
    TNode<JSReceiver> tmp898;
    TNode<Object> tmp899;
    TNode<JSReceiver> tmp900;
    TNode<Object> tmp901;
    TNode<Object> tmp902;
    TNode<Context> tmp903;
    TNode<Object> tmp904;
    ca_.Bind(&block62, &tmp881, &tmp882, &tmp883, &tmp884, &tmp885, &tmp886, &tmp887, &tmp888, &tmp889, &tmp890, &tmp891, &tmp892, &tmp893, &tmp894, &tmp895, &tmp896, &tmp897, &tmp898, &tmp899, &tmp900, &tmp901, &tmp902, &tmp903, &tmp904);
    ca_.Goto(&block1, tmp904);
  }

  if (block33.is_used()) {
    TNode<Context> tmp905;
    TNode<JSReceiver> tmp906;
    TNode<PromiseCapability> tmp907;
    TNode<JSReceiver> tmp908;
    TNode<Object> tmp909;
    TNode<NativeContext> tmp910;
    TNode<HeapObject> tmp911;
    TNode<Object> tmp912;
    TNode<Object> tmp913;
    TNode<Context> tmp914;
    TNode<Smi> tmp915;
    TNode<Object> tmp916;
    TNode<Map> tmp917;
    TNode<Object> tmp918;
    TNode<JSReceiver> tmp919;
    TNode<Smi> tmp920;
    TNode<JSReceiver> tmp921;
    TNode<JSReceiver> tmp922;
    ca_.Bind(&block33, &tmp905, &tmp906, &tmp907, &tmp908, &tmp909, &tmp910, &tmp911, &tmp912, &tmp913, &tmp914, &tmp915, &tmp916, &tmp917, &tmp918, &tmp919, &tmp920, &tmp921, &tmp922);
    TNode<JSPromise> tmp923;
    USE(tmp923);
    tmp923 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp905}, TNode<Object>{tmp918});
    TNode<Oddball> tmp924;
    USE(tmp924);
    tmp924 = Undefined_0(state_);
    PerformPromiseThenImpl_0(state_, TNode<Context>{tmp905}, TNode<JSPromise>{tmp923}, TNode<HeapObject>{tmp921}, TNode<HeapObject>{tmp922}, TNode<HeapObject>{tmp924});
    ca_.Goto(&block46, tmp905, tmp906, tmp907, tmp908, tmp909, tmp910, tmp911, tmp912, tmp913, tmp914, tmp915, tmp916, tmp917, tmp918, tmp919, tmp920, tmp921, tmp922);
  }

  if (block46.is_used()) {
    TNode<Context> tmp925;
    TNode<JSReceiver> tmp926;
    TNode<PromiseCapability> tmp927;
    TNode<JSReceiver> tmp928;
    TNode<Object> tmp929;
    TNode<NativeContext> tmp930;
    TNode<HeapObject> tmp931;
    TNode<Object> tmp932;
    TNode<Object> tmp933;
    TNode<Context> tmp934;
    TNode<Smi> tmp935;
    TNode<Object> tmp936;
    TNode<Map> tmp937;
    TNode<Object> tmp938;
    TNode<JSReceiver> tmp939;
    TNode<Smi> tmp940;
    TNode<JSReceiver> tmp941;
    TNode<JSReceiver> tmp942;
    ca_.Bind(&block46, &tmp925, &tmp926, &tmp927, &tmp928, &tmp929, &tmp930, &tmp931, &tmp932, &tmp933, &tmp934, &tmp935, &tmp936, &tmp937, &tmp938, &tmp939, &tmp940, &tmp941, &tmp942);
    TNode<Smi> tmp943;
    USE(tmp943);
    tmp943 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp944;
    USE(tmp944);
    tmp944 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp935}, TNode<Smi>{tmp943});
    ca_.Goto(&block19, tmp925, tmp926, tmp927, tmp928, tmp929, tmp930, tmp931, tmp932, tmp933, tmp934, tmp944, tmp936, tmp937);
  }

  if (block18.is_used()) {
    TNode<Context> tmp945;
    TNode<JSReceiver> tmp946;
    TNode<PromiseCapability> tmp947;
    TNode<JSReceiver> tmp948;
    TNode<Object> tmp949;
    TNode<NativeContext> tmp950;
    TNode<HeapObject> tmp951;
    TNode<Object> tmp952;
    TNode<Object> tmp953;
    TNode<Context> tmp954;
    TNode<Smi> tmp955;
    TNode<Object> tmp956;
    TNode<Map> tmp957;
    ca_.Bind(&block18, &tmp945, &tmp946, &tmp947, &tmp948, &tmp949, &tmp950, &tmp951, &tmp952, &tmp953, &tmp954, &tmp955, &tmp956, &tmp957);
    ca_.Goto(&block5, tmp945, tmp946, tmp947, tmp948, tmp949, tmp950, tmp951, tmp952, tmp953, tmp954, tmp955, tmp956);
  }

  if (block5.is_used()) {
    TNode<Context> tmp958;
    TNode<JSReceiver> tmp959;
    TNode<PromiseCapability> tmp960;
    TNode<JSReceiver> tmp961;
    TNode<Object> tmp962;
    TNode<NativeContext> tmp963;
    TNode<HeapObject> tmp964;
    TNode<Object> tmp965;
    TNode<Object> tmp966;
    TNode<Context> tmp967;
    TNode<Smi> tmp968;
    TNode<Object> tmp969;
    ca_.Bind(&block5, &tmp958, &tmp959, &tmp960, &tmp961, &tmp962, &tmp963, &tmp964, &tmp965, &tmp966, &tmp967, &tmp968, &tmp969);
    TNode<Object> tmp970;
    USE(tmp970);
    tmp970 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp967}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp971;
    USE(tmp971);
    tmp971 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp958}, TNode<Object>{tmp970});
    TNode<Smi> tmp972;
    USE(tmp972);
    tmp972 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp973;
    USE(tmp973);
    tmp973 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp971}, TNode<Smi>{tmp972});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp967}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp973});
    TNode<Smi> tmp974;
    USE(tmp974);
    tmp974 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp975;
    USE(tmp975);
    tmp975 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp973}, TNode<Smi>{tmp974});
    ca_.Branch(tmp975, &block63, &block64, tmp958, tmp959, tmp960, tmp961, tmp962, tmp963, tmp964, tmp965, tmp966, tmp967, tmp968, tmp969, tmp973);
  }

  if (block63.is_used()) {
    TNode<Context> tmp976;
    TNode<JSReceiver> tmp977;
    TNode<PromiseCapability> tmp978;
    TNode<JSReceiver> tmp979;
    TNode<Object> tmp980;
    TNode<NativeContext> tmp981;
    TNode<HeapObject> tmp982;
    TNode<Object> tmp983;
    TNode<Object> tmp984;
    TNode<Context> tmp985;
    TNode<Smi> tmp986;
    TNode<Object> tmp987;
    TNode<Smi> tmp988;
    ca_.Bind(&block63, &tmp976, &tmp977, &tmp978, &tmp979, &tmp980, &tmp981, &tmp982, &tmp983, &tmp984, &tmp985, &tmp986, &tmp987, &tmp988);
    TNode<Object> tmp989;
    USE(tmp989);
    tmp989 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp985}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<JSArray> tmp990;
    USE(tmp990);
    tmp990 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp976}, TNode<Object>{tmp989});
    TNode<IntPtrT> tmp991;
    USE(tmp991);
    tmp991 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp992 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp990, tmp991});
    TNode<FixedArray> tmp993;
    USE(tmp993);
    tmp993 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp976}, TNode<Object>{tmp992});
    TNode<IntPtrT> tmp994;
    USE(tmp994);
    tmp994 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp993});
    TNode<IntPtrT> tmp995;
    USE(tmp995);
    tmp995 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp986});
    TNode<BoolT> tmp996;
    USE(tmp996);
    tmp996 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp994}, TNode<IntPtrT>{tmp995});
    ca_.Branch(tmp996, &block66, &block67, tmp976, tmp977, tmp978, tmp979, tmp980, tmp981, tmp982, tmp983, tmp984, tmp985, tmp986, tmp987, tmp988, tmp990, tmp993, tmp994, tmp995);
  }

  if (block66.is_used()) {
    TNode<Context> tmp997;
    TNode<JSReceiver> tmp998;
    TNode<PromiseCapability> tmp999;
    TNode<JSReceiver> tmp1000;
    TNode<Object> tmp1001;
    TNode<NativeContext> tmp1002;
    TNode<HeapObject> tmp1003;
    TNode<Object> tmp1004;
    TNode<Object> tmp1005;
    TNode<Context> tmp1006;
    TNode<Smi> tmp1007;
    TNode<Object> tmp1008;
    TNode<Smi> tmp1009;
    TNode<JSArray> tmp1010;
    TNode<FixedArray> tmp1011;
    TNode<IntPtrT> tmp1012;
    TNode<IntPtrT> tmp1013;
    ca_.Bind(&block66, &tmp997, &tmp998, &tmp999, &tmp1000, &tmp1001, &tmp1002, &tmp1003, &tmp1004, &tmp1005, &tmp1006, &tmp1007, &tmp1008, &tmp1009, &tmp1010, &tmp1011, &tmp1012, &tmp1013);
    TNode<IntPtrT> tmp1014;
    USE(tmp1014);
    tmp1014 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp1015;
    USE(tmp1015);
    tmp1015 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp1016;
    USE(tmp1016);
    tmp1016 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp1011}, TNode<IntPtrT>{tmp1015}, TNode<IntPtrT>{tmp1012}, TNode<IntPtrT>{tmp1013});
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1010, tmp1014}, tmp1016);
    ca_.Goto(&block67, tmp997, tmp998, tmp999, tmp1000, tmp1001, tmp1002, tmp1003, tmp1004, tmp1005, tmp1006, tmp1007, tmp1008, tmp1009, tmp1010, tmp1011, tmp1012, tmp1013);
  }

  if (block67.is_used()) {
    TNode<Context> tmp1017;
    TNode<JSReceiver> tmp1018;
    TNode<PromiseCapability> tmp1019;
    TNode<JSReceiver> tmp1020;
    TNode<Object> tmp1021;
    TNode<NativeContext> tmp1022;
    TNode<HeapObject> tmp1023;
    TNode<Object> tmp1024;
    TNode<Object> tmp1025;
    TNode<Context> tmp1026;
    TNode<Smi> tmp1027;
    TNode<Object> tmp1028;
    TNode<Smi> tmp1029;
    TNode<JSArray> tmp1030;
    TNode<FixedArray> tmp1031;
    TNode<IntPtrT> tmp1032;
    TNode<IntPtrT> tmp1033;
    ca_.Bind(&block67, &tmp1017, &tmp1018, &tmp1019, &tmp1020, &tmp1021, &tmp1022, &tmp1023, &tmp1024, &tmp1025, &tmp1026, &tmp1027, &tmp1028, &tmp1029, &tmp1030, &tmp1031, &tmp1032, &tmp1033);
    ca_.Goto(&block65, tmp1017, tmp1018, tmp1019, tmp1020, tmp1021, tmp1022, tmp1023, tmp1024, tmp1025, tmp1026, tmp1027, tmp1028, tmp1029);
  }

  if (block64.is_used()) {
    TNode<Context> tmp1034;
    TNode<JSReceiver> tmp1035;
    TNode<PromiseCapability> tmp1036;
    TNode<JSReceiver> tmp1037;
    TNode<Object> tmp1038;
    TNode<NativeContext> tmp1039;
    TNode<HeapObject> tmp1040;
    TNode<Object> tmp1041;
    TNode<Object> tmp1042;
    TNode<Context> tmp1043;
    TNode<Smi> tmp1044;
    TNode<Object> tmp1045;
    TNode<Smi> tmp1046;
    ca_.Bind(&block64, &tmp1034, &tmp1035, &tmp1036, &tmp1037, &tmp1038, &tmp1039, &tmp1040, &tmp1041, &tmp1042, &tmp1043, &tmp1044, &tmp1045, &tmp1046);
    TNode<Object> tmp1047;
    USE(tmp1047);
    tmp1047 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp1043}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<Object> tmp1048;
    USE(tmp1048);
    tmp1048 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp1034}, TNode<Object>{tmp1047});
    TNode<Object> tmp1049;
    USE(tmp1049);
    tmp1049 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp1034}, TNode<Object>{tmp1041});
    TNode<Oddball> tmp1050;
    USE(tmp1050);
    tmp1050 = Undefined_0(state_);
    TNode<Object> tmp1051;
    USE(tmp1051);
    tmp1051 = CodeStubAssembler(state_).Call(TNode<Context>{tmp1039}, TNode<Object>{tmp1049}, TNode<Object>{tmp1050}, TNode<Object>{tmp1048});
    ca_.Goto(&block65, tmp1034, tmp1035, tmp1036, tmp1037, tmp1038, tmp1039, tmp1040, tmp1041, tmp1042, tmp1043, tmp1044, tmp1045, tmp1046);
  }

  if (block71.is_used()) {
    TNode<Context> tmp1052;
    TNode<JSReceiver> tmp1053;
    TNode<PromiseCapability> tmp1054;
    TNode<JSReceiver> tmp1055;
    TNode<Object> tmp1056;
    TNode<NativeContext> tmp1057;
    TNode<HeapObject> tmp1058;
    TNode<Object> tmp1059;
    TNode<Object> tmp1060;
    TNode<Context> tmp1061;
    TNode<Smi> tmp1062;
    TNode<Object> tmp1063;
    TNode<Smi> tmp1064;
    ca_.Bind(&block71, &tmp1052, &tmp1053, &tmp1054, &tmp1055, &tmp1056, &tmp1057, &tmp1058, &tmp1059, &tmp1060, &tmp1061, &tmp1062, &tmp1063, &tmp1064);
    CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount == 0' failed", "src/builtins/promise-all.tq", 314);
  }

  if (block70.is_used()) {
    TNode<Context> tmp1065;
    TNode<JSReceiver> tmp1066;
    TNode<PromiseCapability> tmp1067;
    TNode<JSReceiver> tmp1068;
    TNode<Object> tmp1069;
    TNode<NativeContext> tmp1070;
    TNode<HeapObject> tmp1071;
    TNode<Object> tmp1072;
    TNode<Object> tmp1073;
    TNode<Context> tmp1074;
    TNode<Smi> tmp1075;
    TNode<Object> tmp1076;
    TNode<Smi> tmp1077;
    ca_.Bind(&block70, &tmp1065, &tmp1066, &tmp1067, &tmp1068, &tmp1069, &tmp1070, &tmp1071, &tmp1072, &tmp1073, &tmp1074, &tmp1075, &tmp1076, &tmp1077);
  }

  if (block65.is_used()) {
    TNode<Context> tmp1078;
    TNode<JSReceiver> tmp1079;
    TNode<PromiseCapability> tmp1080;
    TNode<JSReceiver> tmp1081;
    TNode<Object> tmp1082;
    TNode<NativeContext> tmp1083;
    TNode<HeapObject> tmp1084;
    TNode<Object> tmp1085;
    TNode<Object> tmp1086;
    TNode<Context> tmp1087;
    TNode<Smi> tmp1088;
    TNode<Object> tmp1089;
    TNode<Smi> tmp1090;
    ca_.Bind(&block65, &tmp1078, &tmp1079, &tmp1080, &tmp1081, &tmp1082, &tmp1083, &tmp1084, &tmp1085, &tmp1086, &tmp1087, &tmp1088, &tmp1089, &tmp1090);
    ca_.Goto(&block72, tmp1078, tmp1079, tmp1080, tmp1081, tmp1082, tmp1084);
  }

  if (block1.is_used()) {
    TNode<Object> tmp1091;
    ca_.Bind(&block1, &tmp1091);
    *label_Reject_parameter_0 = tmp1091;
    ca_.Goto(label_Reject);
  }

    TNode<Context> tmp1092;
    TNode<JSReceiver> tmp1093;
    TNode<PromiseCapability> tmp1094;
    TNode<JSReceiver> tmp1095;
    TNode<Object> tmp1096;
    TNode<Object> tmp1097;
    ca_.Bind(&block72, &tmp1092, &tmp1093, &tmp1094, &tmp1095, &tmp1096, &tmp1097);
  return TNode<Object>{tmp1097};
}

TNode<Object> PerformPromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, JSReceiver, String, Context, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, JSReceiver, Object, Object, Context, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, Context> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Object, Object, Context, JSReceiver> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, Map, Context> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, Map, Context, JSReceiver> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Context, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Object, JSReceiver, Object, Object, Context, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, BoolT, BoolT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, JSReceiver, Context, Object> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, JSReceiver, Object, Object, Context, Object> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, String, Context, Object> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, NativeContext, Object, Object, JSReceiver, JSReceiver, Object> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, Object, Context, Object> block59(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, Object> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, BoolT, BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object, Context, Object, Symbol, HeapObject, Object> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, Object, Object> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver, Object, JSReceiver, Object, Object, Context, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map, Object, JSReceiver, Smi, JSReceiver, JSReceiver> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Map> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi, JSArray, FixedArray, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi, JSArray, FixedArray, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, NativeContext, HeapObject, Object, Object, Context, Smi, Object, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, PromiseCapability, JSReceiver, Object, Object> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_constructor, p_capability, p_iter.object, p_iter.next);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<PromiseCapability> tmp2;
    TNode<JSReceiver> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<NativeContext> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp7 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp2, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp9 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp10});
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp12, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp7, tmp9, tmp11);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<PromiseCapability> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<Object> tmp17;
    TNode<NativeContext> tmp18;
    TNode<HeapObject> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Symbol> tmp22;
    USE(tmp22);
    tmp22 = kPromiseForwardingHandlerSymbol_0(state_);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = True_0(state_);
    TNode<Object> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp13}, TNode<Object>{tmp21}, TNode<Object>{tmp22}, TNode<Object>{tmp23});
    ca_.Goto(&block4, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block4.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<PromiseCapability> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Object> tmp29;
    TNode<NativeContext> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block4, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Context> tmp34;
    USE(tmp34);
    tmp34 = CreatePromiseAllResolveElementContext_0(state_, TNode<Context>{tmp25}, TNode<PromiseCapability>{tmp27}, TNode<NativeContext>{tmp30});
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp36;
    USE(tmp36);
    tmp36 = Undefined_0(state_);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{tmp25}, TNode<NativeContext>{tmp30}, TNode<JSReceiver>{tmp26});
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp37});
    ca_.Branch(tmp38, &block7, &block8, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<PromiseCapability> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Object> tmp43;
    TNode<NativeContext> tmp44;
    TNode<HeapObject> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<Context> tmp48;
    TNode<Smi> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<String> tmp51;
    USE(tmp51);
    tmp51 = kResolveString_0(state_);
    TNode<Object> tmp52;
    USE(tmp52);
    compiler::CodeAssemblerExceptionHandlerLabel catch53__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch53__label);
    tmp52 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp39}, TNode<Object>{tmp40}, TNode<Object>{tmp51});
    }
    if (catch53__label.is_used()) {
      compiler::CodeAssemblerLabel catch53_skip(&ca_);
      ca_.Goto(&catch53_skip);
      TNode<Object> catch53_exception_object;
      ca_.Bind(&catch53__label, &catch53_exception_object);
      ca_.Goto(&block11, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, ca_.Uninitialized<Object>(), tmp40, tmp51, tmp39, catch53_exception_object);
      ca_.Bind(&catch53_skip);
    }
    TNode<JSReceiver> tmp54;
    USE(tmp54);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp54 = Cast_Callable_1(state_, TNode<Context>{tmp39}, TNode<Object>{tmp52}, &label0);
    ca_.Goto(&block15, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp52, tmp52, tmp39, tmp54);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp52, tmp52, tmp39);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp55;
    TNode<JSReceiver> tmp56;
    TNode<PromiseCapability> tmp57;
    TNode<JSReceiver> tmp58;
    TNode<Object> tmp59;
    TNode<NativeContext> tmp60;
    TNode<HeapObject> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Context> tmp64;
    TNode<Smi> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<JSReceiver> tmp68;
    TNode<String> tmp69;
    TNode<Context> tmp70;
    TNode<Object> tmp71;
    ca_.Bind(&block11, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp55}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp58}, TNode<Object>{tmp59}}, TNode<Object>{tmp71}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp71, tmp58, tmp59, tmp71, tmp55, result_0_0.value());
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<PromiseCapability> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Object> tmp76;
    TNode<NativeContext> tmp77;
    TNode<HeapObject> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<Context> tmp81;
    TNode<Smi> tmp82;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<Context> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block12, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block1, tmp90);
  }

  if (block16.is_used()) {
    TNode<Context> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<PromiseCapability> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<NativeContext> tmp96;
    TNode<HeapObject> tmp97;
    TNode<Object> tmp98;
    TNode<Object> tmp99;
    TNode<Context> tmp100;
    TNode<Smi> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<Context> tmp105;
    ca_.Bind(&block16, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp91}, MessageTemplate::kCalledNonCallable, "resolve");
  }

  if (block15.is_used()) {
    TNode<Context> tmp106;
    TNode<JSReceiver> tmp107;
    TNode<PromiseCapability> tmp108;
    TNode<JSReceiver> tmp109;
    TNode<Object> tmp110;
    TNode<NativeContext> tmp111;
    TNode<HeapObject> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<Context> tmp115;
    TNode<Smi> tmp116;
    TNode<Object> tmp117;
    TNode<Object> tmp118;
    TNode<Object> tmp119;
    TNode<Context> tmp120;
    TNode<JSReceiver> tmp121;
    ca_.Bind(&block15, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    ca_.Goto(&block8, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp121);
  }

  if (block8.is_used()) {
    TNode<Context> tmp122;
    TNode<JSReceiver> tmp123;
    TNode<PromiseCapability> tmp124;
    TNode<JSReceiver> tmp125;
    TNode<Object> tmp126;
    TNode<NativeContext> tmp127;
    TNode<HeapObject> tmp128;
    TNode<Object> tmp129;
    TNode<Object> tmp130;
    TNode<Context> tmp131;
    TNode<Smi> tmp132;
    TNode<Object> tmp133;
    ca_.Bind(&block8, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<IntPtrT> tmp134;
    USE(tmp134);
    tmp134 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    TNode<Object> tmp135;
    USE(tmp135);
    tmp135 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp127}, TNode<IntPtrT>{tmp134});
    TNode<Map> tmp136;
    USE(tmp136);
    tmp136 = UnsafeCast_Map_0(state_, TNode<Context>{tmp122}, TNode<Object>{tmp135});
    ca_.Goto(&block19, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp136);
  }

  if (block19.is_used()) {
    TNode<Context> tmp137;
    TNode<JSReceiver> tmp138;
    TNode<PromiseCapability> tmp139;
    TNode<JSReceiver> tmp140;
    TNode<Object> tmp141;
    TNode<NativeContext> tmp142;
    TNode<HeapObject> tmp143;
    TNode<Object> tmp144;
    TNode<Object> tmp145;
    TNode<Context> tmp146;
    TNode<Smi> tmp147;
    TNode<Object> tmp148;
    TNode<Map> tmp149;
    ca_.Bind(&block19, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    TNode<BoolT> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp150, &block17, &block18, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149);
  }

  if (block17.is_used()) {
    TNode<Context> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<PromiseCapability> tmp153;
    TNode<JSReceiver> tmp154;
    TNode<Object> tmp155;
    TNode<NativeContext> tmp156;
    TNode<HeapObject> tmp157;
    TNode<Object> tmp158;
    TNode<Object> tmp159;
    TNode<Context> tmp160;
    TNode<Smi> tmp161;
    TNode<Object> tmp162;
    TNode<Map> tmp163;
    ca_.Bind(&block17, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    TNode<JSReceiver> tmp164;
    USE(tmp164);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp164 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp151}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp154}, TNode<Object>{tmp155}}, TNode<Map>{tmp163}, &label0);
    ca_.Goto(&block22, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, ca_.Uninitialized<Object>(), tmp154, tmp155, tmp163, tmp151, tmp164);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block23, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, ca_.Uninitialized<Object>(), tmp154, tmp155, tmp163, tmp151);
    }
  }

  if (block23.is_used()) {
    TNode<Context> tmp165;
    TNode<JSReceiver> tmp166;
    TNode<PromiseCapability> tmp167;
    TNode<JSReceiver> tmp168;
    TNode<Object> tmp169;
    TNode<NativeContext> tmp170;
    TNode<HeapObject> tmp171;
    TNode<Object> tmp172;
    TNode<Object> tmp173;
    TNode<Context> tmp174;
    TNode<Smi> tmp175;
    TNode<Object> tmp176;
    TNode<Map> tmp177;
    TNode<Object> tmp178;
    TNode<JSReceiver> tmp179;
    TNode<Object> tmp180;
    TNode<Map> tmp181;
    TNode<Context> tmp182;
    ca_.Bind(&block23, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    ca_.Goto(&block5, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
  }

  if (block22.is_used()) {
    TNode<Context> tmp183;
    TNode<JSReceiver> tmp184;
    TNode<PromiseCapability> tmp185;
    TNode<JSReceiver> tmp186;
    TNode<Object> tmp187;
    TNode<NativeContext> tmp188;
    TNode<HeapObject> tmp189;
    TNode<Object> tmp190;
    TNode<Object> tmp191;
    TNode<Context> tmp192;
    TNode<Smi> tmp193;
    TNode<Object> tmp194;
    TNode<Map> tmp195;
    TNode<Object> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<Object> tmp198;
    TNode<Map> tmp199;
    TNode<Context> tmp200;
    TNode<JSReceiver> tmp201;
    ca_.Bind(&block22, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    TNode<Object> tmp202;
    USE(tmp202);
    tmp202 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp183}, TNode<JSReceiver>{tmp201}, TNode<Map>{tmp195});
    TNode<Smi> tmp203;
    USE(tmp203);
    tmp203 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyArray::HashField::kMax);
    TNode<BoolT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp193}, TNode<Smi>{tmp203});
    ca_.Branch(tmp204, &block24, &block25, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp202, tmp201);
  }

  if (block24.is_used()) {
    TNode<Context> tmp205;
    TNode<JSReceiver> tmp206;
    TNode<PromiseCapability> tmp207;
    TNode<JSReceiver> tmp208;
    TNode<Object> tmp209;
    TNode<NativeContext> tmp210;
    TNode<HeapObject> tmp211;
    TNode<Object> tmp212;
    TNode<Object> tmp213;
    TNode<Context> tmp214;
    TNode<Smi> tmp215;
    TNode<Object> tmp216;
    TNode<Map> tmp217;
    TNode<Object> tmp218;
    TNode<JSReceiver> tmp219;
    ca_.Bind(&block24, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219);
    compiler::CodeAssemblerExceptionHandlerLabel catch220__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch220__label);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp205}, MessageTemplate::kTooManyElementsInPromiseAll);
    }
    if (catch220__label.is_used()) {
      compiler::CodeAssemblerLabel catch220_skip(&ca_);
      TNode<Object> catch220_exception_object;
      ca_.Bind(&catch220__label, &catch220_exception_object);
      ca_.Goto(&block28, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218, tmp219, tmp205, catch220_exception_object);
    }
  }

  if (block28.is_used()) {
    TNode<Context> tmp221;
    TNode<JSReceiver> tmp222;
    TNode<PromiseCapability> tmp223;
    TNode<JSReceiver> tmp224;
    TNode<Object> tmp225;
    TNode<NativeContext> tmp226;
    TNode<HeapObject> tmp227;
    TNode<Object> tmp228;
    TNode<Object> tmp229;
    TNode<Context> tmp230;
    TNode<Smi> tmp231;
    TNode<Object> tmp232;
    TNode<Map> tmp233;
    TNode<Object> tmp234;
    TNode<JSReceiver> tmp235;
    TNode<Context> tmp236;
    TNode<Object> tmp237;
    ca_.Bind(&block28, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp221}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp224}, TNode<Object>{tmp225}}, TNode<Object>{tmp237}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block29, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp237, tmp224, tmp225, tmp237, tmp221, result_0_0.value());
    }
  }

  if (block29.is_used()) {
    TNode<Context> tmp238;
    TNode<JSReceiver> tmp239;
    TNode<PromiseCapability> tmp240;
    TNode<JSReceiver> tmp241;
    TNode<Object> tmp242;
    TNode<NativeContext> tmp243;
    TNode<HeapObject> tmp244;
    TNode<Object> tmp245;
    TNode<Object> tmp246;
    TNode<Context> tmp247;
    TNode<Smi> tmp248;
    TNode<Object> tmp249;
    TNode<Map> tmp250;
    TNode<Object> tmp251;
    TNode<JSReceiver> tmp252;
    TNode<Object> tmp253;
    TNode<JSReceiver> tmp254;
    TNode<Object> tmp255;
    TNode<Object> tmp256;
    TNode<Context> tmp257;
    TNode<Object> tmp258;
    ca_.Bind(&block29, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258);
    ca_.Goto(&block1, tmp258);
  }

  if (block25.is_used()) {
    TNode<Context> tmp259;
    TNode<JSReceiver> tmp260;
    TNode<PromiseCapability> tmp261;
    TNode<JSReceiver> tmp262;
    TNode<Object> tmp263;
    TNode<NativeContext> tmp264;
    TNode<HeapObject> tmp265;
    TNode<Object> tmp266;
    TNode<Object> tmp267;
    TNode<Context> tmp268;
    TNode<Smi> tmp269;
    TNode<Object> tmp270;
    TNode<Map> tmp271;
    TNode<Object> tmp272;
    TNode<JSReceiver> tmp273;
    ca_.Bind(&block25, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273);
    TNode<Object> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp268}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp275;
    USE(tmp275);
    tmp275 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp259}, TNode<Object>{tmp274});
    TNode<Smi> tmp276;
    USE(tmp276);
    tmp276 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp277;
    USE(tmp277);
    tmp277 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp275}, TNode<Smi>{tmp276});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp268}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp277});
    TNode<JSFunction> tmp278;
    USE(tmp278);
    tmp278 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{tmp259}, TNode<Context>{tmp268}, TNode<Smi>{tmp269}, TNode<NativeContext>{tmp264}, Context::Field::PROMISE_ALL_SETTLED_RESOLVE_ELEMENT_SHARED_FUN);
    TNode<JSFunction> tmp279;
    USE(tmp279);
    tmp279 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{tmp259}, TNode<Context>{tmp268}, TNode<Smi>{tmp269}, TNode<NativeContext>{tmp264}, Context::Field::PROMISE_ALL_SETTLED_REJECT_ELEMENT_SHARED_FUN);
    TNode<Oddball> tmp280;
    USE(tmp280);
    tmp280 = Undefined_0(state_);
    TNode<BoolT> tmp281;
    USE(tmp281);
    tmp281 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp270}, TNode<HeapObject>{tmp280});
    ca_.Branch(tmp281, &block34, &block35, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp275, tmp278, tmp279, tmp281);
  }

  if (block34.is_used()) {
    TNode<Context> tmp282;
    TNode<JSReceiver> tmp283;
    TNode<PromiseCapability> tmp284;
    TNode<JSReceiver> tmp285;
    TNode<Object> tmp286;
    TNode<NativeContext> tmp287;
    TNode<HeapObject> tmp288;
    TNode<Object> tmp289;
    TNode<Object> tmp290;
    TNode<Context> tmp291;
    TNode<Smi> tmp292;
    TNode<Object> tmp293;
    TNode<Map> tmp294;
    TNode<Object> tmp295;
    TNode<JSReceiver> tmp296;
    TNode<Smi> tmp297;
    TNode<JSReceiver> tmp298;
    TNode<JSReceiver> tmp299;
    TNode<BoolT> tmp300;
    ca_.Bind(&block34, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300);
    TNode<BoolT> tmp301;
    USE(tmp301);
    tmp301 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block36, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301);
  }

  if (block35.is_used()) {
    TNode<Context> tmp302;
    TNode<JSReceiver> tmp303;
    TNode<PromiseCapability> tmp304;
    TNode<JSReceiver> tmp305;
    TNode<Object> tmp306;
    TNode<NativeContext> tmp307;
    TNode<HeapObject> tmp308;
    TNode<Object> tmp309;
    TNode<Object> tmp310;
    TNode<Context> tmp311;
    TNode<Smi> tmp312;
    TNode<Object> tmp313;
    TNode<Map> tmp314;
    TNode<Object> tmp315;
    TNode<JSReceiver> tmp316;
    TNode<Smi> tmp317;
    TNode<JSReceiver> tmp318;
    TNode<JSReceiver> tmp319;
    TNode<BoolT> tmp320;
    ca_.Bind(&block35, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320);
    TNode<BoolT> tmp321;
    USE(tmp321);
    tmp321 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Goto(&block36, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp320, tmp321);
  }

  if (block36.is_used()) {
    TNode<Context> tmp322;
    TNode<JSReceiver> tmp323;
    TNode<PromiseCapability> tmp324;
    TNode<JSReceiver> tmp325;
    TNode<Object> tmp326;
    TNode<NativeContext> tmp327;
    TNode<HeapObject> tmp328;
    TNode<Object> tmp329;
    TNode<Object> tmp330;
    TNode<Context> tmp331;
    TNode<Smi> tmp332;
    TNode<Object> tmp333;
    TNode<Map> tmp334;
    TNode<Object> tmp335;
    TNode<JSReceiver> tmp336;
    TNode<Smi> tmp337;
    TNode<JSReceiver> tmp338;
    TNode<JSReceiver> tmp339;
    TNode<BoolT> tmp340;
    TNode<BoolT> tmp341;
    ca_.Bind(&block36, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341);
    ca_.Branch(tmp341, &block37, &block38, tmp322, tmp323, tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp341);
  }

  if (block37.is_used()) {
    TNode<Context> tmp342;
    TNode<JSReceiver> tmp343;
    TNode<PromiseCapability> tmp344;
    TNode<JSReceiver> tmp345;
    TNode<Object> tmp346;
    TNode<NativeContext> tmp347;
    TNode<HeapObject> tmp348;
    TNode<Object> tmp349;
    TNode<Object> tmp350;
    TNode<Context> tmp351;
    TNode<Smi> tmp352;
    TNode<Object> tmp353;
    TNode<Map> tmp354;
    TNode<Object> tmp355;
    TNode<JSReceiver> tmp356;
    TNode<Smi> tmp357;
    TNode<JSReceiver> tmp358;
    TNode<JSReceiver> tmp359;
    TNode<BoolT> tmp360;
    ca_.Bind(&block37, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360);
    TNode<BoolT> tmp361;
    USE(tmp361);
    tmp361 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block39, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp348, tmp349, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361);
  }

  if (block38.is_used()) {
    TNode<Context> tmp362;
    TNode<JSReceiver> tmp363;
    TNode<PromiseCapability> tmp364;
    TNode<JSReceiver> tmp365;
    TNode<Object> tmp366;
    TNode<NativeContext> tmp367;
    TNode<HeapObject> tmp368;
    TNode<Object> tmp369;
    TNode<Object> tmp370;
    TNode<Context> tmp371;
    TNode<Smi> tmp372;
    TNode<Object> tmp373;
    TNode<Map> tmp374;
    TNode<Object> tmp375;
    TNode<JSReceiver> tmp376;
    TNode<Smi> tmp377;
    TNode<JSReceiver> tmp378;
    TNode<JSReceiver> tmp379;
    TNode<BoolT> tmp380;
    ca_.Bind(&block38, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380);
    TNode<BoolT> tmp381;
    USE(tmp381);
    tmp381 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    ca_.Goto(&block39, tmp362, tmp363, tmp364, tmp365, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp377, tmp378, tmp379, tmp380, tmp381);
  }

  if (block39.is_used()) {
    TNode<Context> tmp382;
    TNode<JSReceiver> tmp383;
    TNode<PromiseCapability> tmp384;
    TNode<JSReceiver> tmp385;
    TNode<Object> tmp386;
    TNode<NativeContext> tmp387;
    TNode<HeapObject> tmp388;
    TNode<Object> tmp389;
    TNode<Object> tmp390;
    TNode<Context> tmp391;
    TNode<Smi> tmp392;
    TNode<Object> tmp393;
    TNode<Map> tmp394;
    TNode<Object> tmp395;
    TNode<JSReceiver> tmp396;
    TNode<Smi> tmp397;
    TNode<JSReceiver> tmp398;
    TNode<JSReceiver> tmp399;
    TNode<BoolT> tmp400;
    TNode<BoolT> tmp401;
    ca_.Bind(&block39, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401);
    ca_.Branch(tmp401, &block40, &block41, tmp382, tmp383, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp392, tmp393, tmp394, tmp395, tmp396, tmp397, tmp398, tmp399, tmp401);
  }

  if (block40.is_used()) {
    TNode<Context> tmp402;
    TNode<JSReceiver> tmp403;
    TNode<PromiseCapability> tmp404;
    TNode<JSReceiver> tmp405;
    TNode<Object> tmp406;
    TNode<NativeContext> tmp407;
    TNode<HeapObject> tmp408;
    TNode<Object> tmp409;
    TNode<Object> tmp410;
    TNode<Context> tmp411;
    TNode<Smi> tmp412;
    TNode<Object> tmp413;
    TNode<Map> tmp414;
    TNode<Object> tmp415;
    TNode<JSReceiver> tmp416;
    TNode<Smi> tmp417;
    TNode<JSReceiver> tmp418;
    TNode<JSReceiver> tmp419;
    TNode<BoolT> tmp420;
    ca_.Bind(&block40, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418, &tmp419, &tmp420);
    TNode<BoolT> tmp421;
    USE(tmp421);
    tmp421 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block42, tmp402, tmp403, tmp404, tmp405, tmp406, tmp407, tmp408, tmp409, tmp410, tmp411, tmp412, tmp413, tmp414, tmp415, tmp416, tmp417, tmp418, tmp419, tmp420, tmp421);
  }

  if (block41.is_used()) {
    TNode<Context> tmp422;
    TNode<JSReceiver> tmp423;
    TNode<PromiseCapability> tmp424;
    TNode<JSReceiver> tmp425;
    TNode<Object> tmp426;
    TNode<NativeContext> tmp427;
    TNode<HeapObject> tmp428;
    TNode<Object> tmp429;
    TNode<Object> tmp430;
    TNode<Context> tmp431;
    TNode<Smi> tmp432;
    TNode<Object> tmp433;
    TNode<Map> tmp434;
    TNode<Object> tmp435;
    TNode<JSReceiver> tmp436;
    TNode<Smi> tmp437;
    TNode<JSReceiver> tmp438;
    TNode<JSReceiver> tmp439;
    TNode<BoolT> tmp440;
    ca_.Bind(&block41, &tmp422, &tmp423, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433, &tmp434, &tmp435, &tmp436, &tmp437, &tmp438, &tmp439, &tmp440);
    TNode<BoolT> tmp441;
    USE(tmp441);
    tmp441 = Is_Smi_JSAny_0(state_, TNode<Context>{tmp422}, TNode<Object>{tmp435});
    ca_.Goto(&block42, tmp422, tmp423, tmp424, tmp425, tmp426, tmp427, tmp428, tmp429, tmp430, tmp431, tmp432, tmp433, tmp434, tmp435, tmp436, tmp437, tmp438, tmp439, tmp440, tmp441);
  }

  if (block42.is_used()) {
    TNode<Context> tmp442;
    TNode<JSReceiver> tmp443;
    TNode<PromiseCapability> tmp444;
    TNode<JSReceiver> tmp445;
    TNode<Object> tmp446;
    TNode<NativeContext> tmp447;
    TNode<HeapObject> tmp448;
    TNode<Object> tmp449;
    TNode<Object> tmp450;
    TNode<Context> tmp451;
    TNode<Smi> tmp452;
    TNode<Object> tmp453;
    TNode<Map> tmp454;
    TNode<Object> tmp455;
    TNode<JSReceiver> tmp456;
    TNode<Smi> tmp457;
    TNode<JSReceiver> tmp458;
    TNode<JSReceiver> tmp459;
    TNode<BoolT> tmp460;
    TNode<BoolT> tmp461;
    ca_.Bind(&block42, &tmp442, &tmp443, &tmp444, &tmp445, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452, &tmp453, &tmp454, &tmp455, &tmp456, &tmp457, &tmp458, &tmp459, &tmp460, &tmp461);
    ca_.Branch(tmp461, &block43, &block44, tmp442, tmp443, tmp444, tmp445, tmp446, tmp447, tmp448, tmp449, tmp450, tmp451, tmp452, tmp453, tmp454, tmp455, tmp456, tmp457, tmp458, tmp459, tmp461);
  }

  if (block43.is_used()) {
    TNode<Context> tmp462;
    TNode<JSReceiver> tmp463;
    TNode<PromiseCapability> tmp464;
    TNode<JSReceiver> tmp465;
    TNode<Object> tmp466;
    TNode<NativeContext> tmp467;
    TNode<HeapObject> tmp468;
    TNode<Object> tmp469;
    TNode<Object> tmp470;
    TNode<Context> tmp471;
    TNode<Smi> tmp472;
    TNode<Object> tmp473;
    TNode<Map> tmp474;
    TNode<Object> tmp475;
    TNode<JSReceiver> tmp476;
    TNode<Smi> tmp477;
    TNode<JSReceiver> tmp478;
    TNode<JSReceiver> tmp479;
    TNode<BoolT> tmp480;
    ca_.Bind(&block43, &tmp462, &tmp463, &tmp464, &tmp465, &tmp466, &tmp467, &tmp468, &tmp469, &tmp470, &tmp471, &tmp472, &tmp473, &tmp474, &tmp475, &tmp476, &tmp477, &tmp478, &tmp479, &tmp480);
    TNode<BoolT> tmp481;
    USE(tmp481);
    tmp481 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block45, tmp462, tmp463, tmp464, tmp465, tmp466, tmp467, tmp468, tmp469, tmp470, tmp471, tmp472, tmp473, tmp474, tmp475, tmp476, tmp477, tmp478, tmp479, tmp480, tmp481);
  }

  if (block44.is_used()) {
    TNode<Context> tmp482;
    TNode<JSReceiver> tmp483;
    TNode<PromiseCapability> tmp484;
    TNode<JSReceiver> tmp485;
    TNode<Object> tmp486;
    TNode<NativeContext> tmp487;
    TNode<HeapObject> tmp488;
    TNode<Object> tmp489;
    TNode<Object> tmp490;
    TNode<Context> tmp491;
    TNode<Smi> tmp492;
    TNode<Object> tmp493;
    TNode<Map> tmp494;
    TNode<Object> tmp495;
    TNode<JSReceiver> tmp496;
    TNode<Smi> tmp497;
    TNode<JSReceiver> tmp498;
    TNode<JSReceiver> tmp499;
    TNode<BoolT> tmp500;
    ca_.Bind(&block44, &tmp482, &tmp483, &tmp484, &tmp485, &tmp486, &tmp487, &tmp488, &tmp489, &tmp490, &tmp491, &tmp492, &tmp493, &tmp494, &tmp495, &tmp496, &tmp497, &tmp498, &tmp499, &tmp500);
    TNode<HeapObject> tmp501;
    USE(tmp501);
    tmp501 = UnsafeCast_HeapObject_0(state_, TNode<Context>{tmp482}, TNode<Object>{tmp495});
    TNode<IntPtrT> tmp502;
    USE(tmp502);
    tmp502 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map>tmp503 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp501, tmp502});
    TNode<BoolT> tmp504;
    USE(tmp504);
    tmp504 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{tmp482}, TNode<NativeContext>{tmp487}, TNode<Map>{tmp503});
    TNode<BoolT> tmp505;
    USE(tmp505);
    tmp505 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp504});
    ca_.Goto(&block45, tmp482, tmp483, tmp484, tmp485, tmp486, tmp487, tmp488, tmp489, tmp490, tmp491, tmp492, tmp493, tmp494, tmp495, tmp496, tmp497, tmp498, tmp499, tmp500, tmp505);
  }

  if (block45.is_used()) {
    TNode<Context> tmp506;
    TNode<JSReceiver> tmp507;
    TNode<PromiseCapability> tmp508;
    TNode<JSReceiver> tmp509;
    TNode<Object> tmp510;
    TNode<NativeContext> tmp511;
    TNode<HeapObject> tmp512;
    TNode<Object> tmp513;
    TNode<Object> tmp514;
    TNode<Context> tmp515;
    TNode<Smi> tmp516;
    TNode<Object> tmp517;
    TNode<Map> tmp518;
    TNode<Object> tmp519;
    TNode<JSReceiver> tmp520;
    TNode<Smi> tmp521;
    TNode<JSReceiver> tmp522;
    TNode<JSReceiver> tmp523;
    TNode<BoolT> tmp524;
    TNode<BoolT> tmp525;
    ca_.Bind(&block45, &tmp506, &tmp507, &tmp508, &tmp509, &tmp510, &tmp511, &tmp512, &tmp513, &tmp514, &tmp515, &tmp516, &tmp517, &tmp518, &tmp519, &tmp520, &tmp521, &tmp522, &tmp523, &tmp524, &tmp525);
    ca_.Branch(tmp525, &block32, &block33, tmp506, tmp507, tmp508, tmp509, tmp510, tmp511, tmp512, tmp513, tmp514, tmp515, tmp516, tmp517, tmp518, tmp519, tmp520, tmp521, tmp522, tmp523);
  }

  if (block32.is_used()) {
    TNode<Context> tmp526;
    TNode<JSReceiver> tmp527;
    TNode<PromiseCapability> tmp528;
    TNode<JSReceiver> tmp529;
    TNode<Object> tmp530;
    TNode<NativeContext> tmp531;
    TNode<HeapObject> tmp532;
    TNode<Object> tmp533;
    TNode<Object> tmp534;
    TNode<Context> tmp535;
    TNode<Smi> tmp536;
    TNode<Object> tmp537;
    TNode<Map> tmp538;
    TNode<Object> tmp539;
    TNode<JSReceiver> tmp540;
    TNode<Smi> tmp541;
    TNode<JSReceiver> tmp542;
    TNode<JSReceiver> tmp543;
    ca_.Bind(&block32, &tmp526, &tmp527, &tmp528, &tmp529, &tmp530, &tmp531, &tmp532, &tmp533, &tmp534, &tmp535, &tmp536, &tmp537, &tmp538, &tmp539, &tmp540, &tmp541, &tmp542, &tmp543);
    TNode<JSReceiver> tmp544;
    USE(tmp544);
    compiler::CodeAssemblerExceptionHandlerLabel catch545__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch545__label);
    tmp544 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp526}, TNode<Object>{tmp527});
    }
    if (catch545__label.is_used()) {
      compiler::CodeAssemblerLabel catch545_skip(&ca_);
      ca_.Goto(&catch545_skip);
      TNode<Object> catch545_exception_object;
      ca_.Bind(&catch545__label, &catch545_exception_object);
      ca_.Goto(&block49, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp527, tmp526, catch545_exception_object);
      ca_.Bind(&catch545_skip);
    }
    TNode<Object> tmp546;
    USE(tmp546);
    compiler::CodeAssemblerExceptionHandlerLabel catch547__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch547__label);
    tmp546 = CallResolve_0(state_, TNode<Context>{tmp526}, TNode<JSReceiver>{tmp544}, TNode<Object>{tmp537}, TNode<Object>{tmp539});
    }
    if (catch547__label.is_used()) {
      compiler::CodeAssemblerLabel catch547_skip(&ca_);
      ca_.Goto(&catch547_skip);
      TNode<Object> catch547_exception_object;
      ca_.Bind(&catch547__label, &catch547_exception_object);
      ca_.Goto(&block50, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp537, tmp539, tmp526, catch547_exception_object);
      ca_.Bind(&catch547_skip);
    }
    TNode<String> tmp548;
    USE(tmp548);
    tmp548 = kThenString_0(state_);
    TNode<Object> tmp549;
    USE(tmp549);
    compiler::CodeAssemblerExceptionHandlerLabel catch550__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch550__label);
    tmp549 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp526}, TNode<Object>{tmp546}, TNode<Object>{tmp548});
    }
    if (catch550__label.is_used()) {
      compiler::CodeAssemblerLabel catch550_skip(&ca_);
      ca_.Goto(&catch550_skip);
      TNode<Object> catch550_exception_object;
      ca_.Bind(&catch550__label, &catch550_exception_object);
      ca_.Goto(&block51, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp546, tmp546, tmp548, tmp526, catch550_exception_object);
      ca_.Bind(&catch550_skip);
    }
    TNode<Object> tmp551;
    USE(tmp551);
    compiler::CodeAssemblerExceptionHandlerLabel catch552__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch552__label);
    tmp551 = CodeStubAssembler(state_).Call(TNode<Context>{tmp531}, TNode<Object>{tmp549}, TNode<Object>{tmp546}, TNode<Object>{tmp542}, TNode<Object>{tmp543});
    }
    if (catch552__label.is_used()) {
      compiler::CodeAssemblerLabel catch552_skip(&ca_);
      ca_.Goto(&catch552_skip);
      TNode<Object> catch552_exception_object;
      ca_.Bind(&catch552__label, &catch552_exception_object);
      ca_.Goto(&block52, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp546, tmp549, tmp531, tmp549, tmp546, tmp542, tmp543, catch552_exception_object);
      ca_.Bind(&catch552_skip);
    }
    TNode<BoolT> tmp553;
    USE(tmp553);
    compiler::CodeAssemblerExceptionHandlerLabel catch554__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch554__label);
    tmp553 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch554__label.is_used()) {
      compiler::CodeAssemblerLabel catch554_skip(&ca_);
      ca_.Goto(&catch554_skip);
      TNode<Object> catch554_exception_object;
      ca_.Bind(&catch554__label, &catch554_exception_object);
      ca_.Goto(&block55, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp546, tmp549, tmp551, catch554_exception_object);
      ca_.Bind(&catch554_skip);
    }
    ca_.Branch(tmp553, &block56, &block57, tmp526, tmp527, tmp528, tmp529, tmp530, tmp531, tmp532, tmp533, tmp534, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp546, tmp549, tmp551, tmp553);
  }

  if (block49.is_used()) {
    TNode<Context> tmp555;
    TNode<JSReceiver> tmp556;
    TNode<PromiseCapability> tmp557;
    TNode<JSReceiver> tmp558;
    TNode<Object> tmp559;
    TNode<NativeContext> tmp560;
    TNode<HeapObject> tmp561;
    TNode<Object> tmp562;
    TNode<Object> tmp563;
    TNode<Context> tmp564;
    TNode<Smi> tmp565;
    TNode<Object> tmp566;
    TNode<Map> tmp567;
    TNode<Object> tmp568;
    TNode<JSReceiver> tmp569;
    TNode<Smi> tmp570;
    TNode<JSReceiver> tmp571;
    TNode<JSReceiver> tmp572;
    TNode<JSReceiver> tmp573;
    TNode<Context> tmp574;
    TNode<Object> tmp575;
    ca_.Bind(&block49, &tmp555, &tmp556, &tmp557, &tmp558, &tmp559, &tmp560, &tmp561, &tmp562, &tmp563, &tmp564, &tmp565, &tmp566, &tmp567, &tmp568, &tmp569, &tmp570, &tmp571, &tmp572, &tmp573, &tmp574, &tmp575);
    ca_.Goto(&block48, tmp555, tmp556, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563, tmp564, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp575);
  }

  if (block50.is_used()) {
    TNode<Context> tmp576;
    TNode<JSReceiver> tmp577;
    TNode<PromiseCapability> tmp578;
    TNode<JSReceiver> tmp579;
    TNode<Object> tmp580;
    TNode<NativeContext> tmp581;
    TNode<HeapObject> tmp582;
    TNode<Object> tmp583;
    TNode<Object> tmp584;
    TNode<Context> tmp585;
    TNode<Smi> tmp586;
    TNode<Object> tmp587;
    TNode<Map> tmp588;
    TNode<Object> tmp589;
    TNode<JSReceiver> tmp590;
    TNode<Smi> tmp591;
    TNode<JSReceiver> tmp592;
    TNode<JSReceiver> tmp593;
    TNode<JSReceiver> tmp594;
    TNode<Object> tmp595;
    TNode<Object> tmp596;
    TNode<Context> tmp597;
    TNode<Object> tmp598;
    ca_.Bind(&block50, &tmp576, &tmp577, &tmp578, &tmp579, &tmp580, &tmp581, &tmp582, &tmp583, &tmp584, &tmp585, &tmp586, &tmp587, &tmp588, &tmp589, &tmp590, &tmp591, &tmp592, &tmp593, &tmp594, &tmp595, &tmp596, &tmp597, &tmp598);
    ca_.Goto(&block48, tmp576, tmp577, tmp578, tmp579, tmp580, tmp581, tmp582, tmp583, tmp584, tmp585, tmp586, tmp587, tmp588, tmp589, tmp590, tmp591, tmp592, tmp593, tmp598);
  }

  if (block51.is_used()) {
    TNode<Context> tmp599;
    TNode<JSReceiver> tmp600;
    TNode<PromiseCapability> tmp601;
    TNode<JSReceiver> tmp602;
    TNode<Object> tmp603;
    TNode<NativeContext> tmp604;
    TNode<HeapObject> tmp605;
    TNode<Object> tmp606;
    TNode<Object> tmp607;
    TNode<Context> tmp608;
    TNode<Smi> tmp609;
    TNode<Object> tmp610;
    TNode<Map> tmp611;
    TNode<Object> tmp612;
    TNode<JSReceiver> tmp613;
    TNode<Smi> tmp614;
    TNode<JSReceiver> tmp615;
    TNode<JSReceiver> tmp616;
    TNode<Object> tmp617;
    TNode<Object> tmp618;
    TNode<String> tmp619;
    TNode<Context> tmp620;
    TNode<Object> tmp621;
    ca_.Bind(&block51, &tmp599, &tmp600, &tmp601, &tmp602, &tmp603, &tmp604, &tmp605, &tmp606, &tmp607, &tmp608, &tmp609, &tmp610, &tmp611, &tmp612, &tmp613, &tmp614, &tmp615, &tmp616, &tmp617, &tmp618, &tmp619, &tmp620, &tmp621);
    ca_.Goto(&block48, tmp599, tmp600, tmp601, tmp602, tmp603, tmp604, tmp605, tmp606, tmp607, tmp608, tmp609, tmp610, tmp611, tmp612, tmp613, tmp614, tmp615, tmp616, tmp621);
  }

  if (block52.is_used()) {
    TNode<Context> tmp622;
    TNode<JSReceiver> tmp623;
    TNode<PromiseCapability> tmp624;
    TNode<JSReceiver> tmp625;
    TNode<Object> tmp626;
    TNode<NativeContext> tmp627;
    TNode<HeapObject> tmp628;
    TNode<Object> tmp629;
    TNode<Object> tmp630;
    TNode<Context> tmp631;
    TNode<Smi> tmp632;
    TNode<Object> tmp633;
    TNode<Map> tmp634;
    TNode<Object> tmp635;
    TNode<JSReceiver> tmp636;
    TNode<Smi> tmp637;
    TNode<JSReceiver> tmp638;
    TNode<JSReceiver> tmp639;
    TNode<Object> tmp640;
    TNode<Object> tmp641;
    TNode<NativeContext> tmp642;
    TNode<Object> tmp643;
    TNode<Object> tmp644;
    TNode<JSReceiver> tmp645;
    TNode<JSReceiver> tmp646;
    TNode<Object> tmp647;
    ca_.Bind(&block52, &tmp622, &tmp623, &tmp624, &tmp625, &tmp626, &tmp627, &tmp628, &tmp629, &tmp630, &tmp631, &tmp632, &tmp633, &tmp634, &tmp635, &tmp636, &tmp637, &tmp638, &tmp639, &tmp640, &tmp641, &tmp642, &tmp643, &tmp644, &tmp645, &tmp646, &tmp647);
    ca_.Goto(&block48, tmp622, tmp623, tmp624, tmp625, tmp626, tmp627, tmp628, tmp629, tmp630, tmp631, tmp632, tmp633, tmp634, tmp635, tmp636, tmp637, tmp638, tmp639, tmp647);
  }

  if (block55.is_used()) {
    TNode<Context> tmp648;
    TNode<JSReceiver> tmp649;
    TNode<PromiseCapability> tmp650;
    TNode<JSReceiver> tmp651;
    TNode<Object> tmp652;
    TNode<NativeContext> tmp653;
    TNode<HeapObject> tmp654;
    TNode<Object> tmp655;
    TNode<Object> tmp656;
    TNode<Context> tmp657;
    TNode<Smi> tmp658;
    TNode<Object> tmp659;
    TNode<Map> tmp660;
    TNode<Object> tmp661;
    TNode<JSReceiver> tmp662;
    TNode<Smi> tmp663;
    TNode<JSReceiver> tmp664;
    TNode<JSReceiver> tmp665;
    TNode<Object> tmp666;
    TNode<Object> tmp667;
    TNode<Object> tmp668;
    TNode<Object> tmp669;
    ca_.Bind(&block55, &tmp648, &tmp649, &tmp650, &tmp651, &tmp652, &tmp653, &tmp654, &tmp655, &tmp656, &tmp657, &tmp658, &tmp659, &tmp660, &tmp661, &tmp662, &tmp663, &tmp664, &tmp665, &tmp666, &tmp667, &tmp668, &tmp669);
    ca_.Goto(&block48, tmp648, tmp649, tmp650, tmp651, tmp652, tmp653, tmp654, tmp655, tmp656, tmp657, tmp658, tmp659, tmp660, tmp661, tmp662, tmp663, tmp664, tmp665, tmp669);
  }

  if (block56.is_used()) {
    TNode<Context> tmp670;
    TNode<JSReceiver> tmp671;
    TNode<PromiseCapability> tmp672;
    TNode<JSReceiver> tmp673;
    TNode<Object> tmp674;
    TNode<NativeContext> tmp675;
    TNode<HeapObject> tmp676;
    TNode<Object> tmp677;
    TNode<Object> tmp678;
    TNode<Context> tmp679;
    TNode<Smi> tmp680;
    TNode<Object> tmp681;
    TNode<Map> tmp682;
    TNode<Object> tmp683;
    TNode<JSReceiver> tmp684;
    TNode<Smi> tmp685;
    TNode<JSReceiver> tmp686;
    TNode<JSReceiver> tmp687;
    TNode<Object> tmp688;
    TNode<Object> tmp689;
    TNode<Object> tmp690;
    TNode<BoolT> tmp691;
    ca_.Bind(&block56, &tmp670, &tmp671, &tmp672, &tmp673, &tmp674, &tmp675, &tmp676, &tmp677, &tmp678, &tmp679, &tmp680, &tmp681, &tmp682, &tmp683, &tmp684, &tmp685, &tmp686, &tmp687, &tmp688, &tmp689, &tmp690, &tmp691);
    TNode<BoolT> tmp692;
    USE(tmp692);
    compiler::CodeAssemblerExceptionHandlerLabel catch693__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch693__label);
    tmp692 = Is_JSPromise_JSAny_0(state_, TNode<Context>{tmp670}, TNode<Object>{tmp690});
    }
    if (catch693__label.is_used()) {
      compiler::CodeAssemblerLabel catch693_skip(&ca_);
      ca_.Goto(&catch693_skip);
      TNode<Object> catch693_exception_object;
      ca_.Bind(&catch693__label, &catch693_exception_object);
      ca_.Goto(&block59, tmp670, tmp671, tmp672, tmp673, tmp674, tmp675, tmp676, tmp677, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp690, tmp670, catch693_exception_object);
      ca_.Bind(&catch693_skip);
    }
    ca_.Goto(&block58, tmp670, tmp671, tmp672, tmp673, tmp674, tmp675, tmp676, tmp677, tmp678, tmp679, tmp680, tmp681, tmp682, tmp683, tmp684, tmp685, tmp686, tmp687, tmp688, tmp689, tmp690, tmp691, tmp692);
  }

  if (block59.is_used()) {
    TNode<Context> tmp694;
    TNode<JSReceiver> tmp695;
    TNode<PromiseCapability> tmp696;
    TNode<JSReceiver> tmp697;
    TNode<Object> tmp698;
    TNode<NativeContext> tmp699;
    TNode<HeapObject> tmp700;
    TNode<Object> tmp701;
    TNode<Object> tmp702;
    TNode<Context> tmp703;
    TNode<Smi> tmp704;
    TNode<Object> tmp705;
    TNode<Map> tmp706;
    TNode<Object> tmp707;
    TNode<JSReceiver> tmp708;
    TNode<Smi> tmp709;
    TNode<JSReceiver> tmp710;
    TNode<JSReceiver> tmp711;
    TNode<Object> tmp712;
    TNode<Object> tmp713;
    TNode<Object> tmp714;
    TNode<BoolT> tmp715;
    TNode<Object> tmp716;
    TNode<Context> tmp717;
    TNode<Object> tmp718;
    ca_.Bind(&block59, &tmp694, &tmp695, &tmp696, &tmp697, &tmp698, &tmp699, &tmp700, &tmp701, &tmp702, &tmp703, &tmp704, &tmp705, &tmp706, &tmp707, &tmp708, &tmp709, &tmp710, &tmp711, &tmp712, &tmp713, &tmp714, &tmp715, &tmp716, &tmp717, &tmp718);
    ca_.Goto(&block48, tmp694, tmp695, tmp696, tmp697, tmp698, tmp699, tmp700, tmp701, tmp702, tmp703, tmp704, tmp705, tmp706, tmp707, tmp708, tmp709, tmp710, tmp711, tmp718);
  }

  if (block57.is_used()) {
    TNode<Context> tmp719;
    TNode<JSReceiver> tmp720;
    TNode<PromiseCapability> tmp721;
    TNode<JSReceiver> tmp722;
    TNode<Object> tmp723;
    TNode<NativeContext> tmp724;
    TNode<HeapObject> tmp725;
    TNode<Object> tmp726;
    TNode<Object> tmp727;
    TNode<Context> tmp728;
    TNode<Smi> tmp729;
    TNode<Object> tmp730;
    TNode<Map> tmp731;
    TNode<Object> tmp732;
    TNode<JSReceiver> tmp733;
    TNode<Smi> tmp734;
    TNode<JSReceiver> tmp735;
    TNode<JSReceiver> tmp736;
    TNode<Object> tmp737;
    TNode<Object> tmp738;
    TNode<Object> tmp739;
    TNode<BoolT> tmp740;
    ca_.Bind(&block57, &tmp719, &tmp720, &tmp721, &tmp722, &tmp723, &tmp724, &tmp725, &tmp726, &tmp727, &tmp728, &tmp729, &tmp730, &tmp731, &tmp732, &tmp733, &tmp734, &tmp735, &tmp736, &tmp737, &tmp738, &tmp739, &tmp740);
    TNode<BoolT> tmp741;
    USE(tmp741);
    compiler::CodeAssemblerExceptionHandlerLabel catch742__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch742__label);
    tmp741 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch742__label.is_used()) {
      compiler::CodeAssemblerLabel catch742_skip(&ca_);
      ca_.Goto(&catch742_skip);
      TNode<Object> catch742_exception_object;
      ca_.Bind(&catch742__label, &catch742_exception_object);
      ca_.Goto(&block60, tmp719, tmp720, tmp721, tmp722, tmp723, tmp724, tmp725, tmp726, tmp727, tmp728, tmp729, tmp730, tmp731, tmp732, tmp733, tmp734, tmp735, tmp736, tmp737, tmp738, tmp739, tmp740, catch742_exception_object);
      ca_.Bind(&catch742_skip);
    }
    ca_.Goto(&block58, tmp719, tmp720, tmp721, tmp722, tmp723, tmp724, tmp725, tmp726, tmp727, tmp728, tmp729, tmp730, tmp731, tmp732, tmp733, tmp734, tmp735, tmp736, tmp737, tmp738, tmp739, tmp740, tmp741);
  }

  if (block60.is_used()) {
    TNode<Context> tmp743;
    TNode<JSReceiver> tmp744;
    TNode<PromiseCapability> tmp745;
    TNode<JSReceiver> tmp746;
    TNode<Object> tmp747;
    TNode<NativeContext> tmp748;
    TNode<HeapObject> tmp749;
    TNode<Object> tmp750;
    TNode<Object> tmp751;
    TNode<Context> tmp752;
    TNode<Smi> tmp753;
    TNode<Object> tmp754;
    TNode<Map> tmp755;
    TNode<Object> tmp756;
    TNode<JSReceiver> tmp757;
    TNode<Smi> tmp758;
    TNode<JSReceiver> tmp759;
    TNode<JSReceiver> tmp760;
    TNode<Object> tmp761;
    TNode<Object> tmp762;
    TNode<Object> tmp763;
    TNode<BoolT> tmp764;
    TNode<Object> tmp765;
    ca_.Bind(&block60, &tmp743, &tmp744, &tmp745, &tmp746, &tmp747, &tmp748, &tmp749, &tmp750, &tmp751, &tmp752, &tmp753, &tmp754, &tmp755, &tmp756, &tmp757, &tmp758, &tmp759, &tmp760, &tmp761, &tmp762, &tmp763, &tmp764, &tmp765);
    ca_.Goto(&block48, tmp743, tmp744, tmp745, tmp746, tmp747, tmp748, tmp749, tmp750, tmp751, tmp752, tmp753, tmp754, tmp755, tmp756, tmp757, tmp758, tmp759, tmp760, tmp765);
  }

  if (block58.is_used()) {
    TNode<Context> tmp766;
    TNode<JSReceiver> tmp767;
    TNode<PromiseCapability> tmp768;
    TNode<JSReceiver> tmp769;
    TNode<Object> tmp770;
    TNode<NativeContext> tmp771;
    TNode<HeapObject> tmp772;
    TNode<Object> tmp773;
    TNode<Object> tmp774;
    TNode<Context> tmp775;
    TNode<Smi> tmp776;
    TNode<Object> tmp777;
    TNode<Map> tmp778;
    TNode<Object> tmp779;
    TNode<JSReceiver> tmp780;
    TNode<Smi> tmp781;
    TNode<JSReceiver> tmp782;
    TNode<JSReceiver> tmp783;
    TNode<Object> tmp784;
    TNode<Object> tmp785;
    TNode<Object> tmp786;
    TNode<BoolT> tmp787;
    TNode<BoolT> tmp788;
    ca_.Bind(&block58, &tmp766, &tmp767, &tmp768, &tmp769, &tmp770, &tmp771, &tmp772, &tmp773, &tmp774, &tmp775, &tmp776, &tmp777, &tmp778, &tmp779, &tmp780, &tmp781, &tmp782, &tmp783, &tmp784, &tmp785, &tmp786, &tmp787, &tmp788);
    ca_.Branch(tmp788, &block53, &block54, tmp766, tmp767, tmp768, tmp769, tmp770, tmp771, tmp772, tmp773, tmp774, tmp775, tmp776, tmp777, tmp778, tmp779, tmp780, tmp781, tmp782, tmp783, tmp784, tmp785, tmp786);
  }

  if (block53.is_used()) {
    TNode<Context> tmp789;
    TNode<JSReceiver> tmp790;
    TNode<PromiseCapability> tmp791;
    TNode<JSReceiver> tmp792;
    TNode<Object> tmp793;
    TNode<NativeContext> tmp794;
    TNode<HeapObject> tmp795;
    TNode<Object> tmp796;
    TNode<Object> tmp797;
    TNode<Context> tmp798;
    TNode<Smi> tmp799;
    TNode<Object> tmp800;
    TNode<Map> tmp801;
    TNode<Object> tmp802;
    TNode<JSReceiver> tmp803;
    TNode<Smi> tmp804;
    TNode<JSReceiver> tmp805;
    TNode<JSReceiver> tmp806;
    TNode<Object> tmp807;
    TNode<Object> tmp808;
    TNode<Object> tmp809;
    ca_.Bind(&block53, &tmp789, &tmp790, &tmp791, &tmp792, &tmp793, &tmp794, &tmp795, &tmp796, &tmp797, &tmp798, &tmp799, &tmp800, &tmp801, &tmp802, &tmp803, &tmp804, &tmp805, &tmp806, &tmp807, &tmp808, &tmp809);
    TNode<Symbol> tmp810;
    USE(tmp810);
    tmp810 = kPromiseHandledBySymbol_0(state_);
    TNode<Object> tmp811;
    USE(tmp811);
    compiler::CodeAssemblerExceptionHandlerLabel catch812__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch812__label);
    tmp811 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{tmp789}, TNode<Object>{tmp809}, TNode<Object>{tmp810}, TNode<Object>{tmp795});
    }
    if (catch812__label.is_used()) {
      compiler::CodeAssemblerLabel catch812_skip(&ca_);
      ca_.Goto(&catch812_skip);
      TNode<Object> catch812_exception_object;
      ca_.Bind(&catch812__label, &catch812_exception_object);
      ca_.Goto(&block61, tmp789, tmp790, tmp791, tmp792, tmp793, tmp794, tmp795, tmp796, tmp797, tmp798, tmp799, tmp800, tmp801, tmp802, tmp803, tmp804, tmp805, tmp806, tmp807, tmp808, tmp809, tmp789, tmp809, tmp810, tmp795, catch812_exception_object);
      ca_.Bind(&catch812_skip);
    }
    ca_.Goto(&block54, tmp789, tmp790, tmp791, tmp792, tmp793, tmp794, tmp795, tmp796, tmp797, tmp798, tmp799, tmp800, tmp801, tmp802, tmp803, tmp804, tmp805, tmp806, tmp807, tmp808, tmp809);
  }

  if (block61.is_used()) {
    TNode<Context> tmp813;
    TNode<JSReceiver> tmp814;
    TNode<PromiseCapability> tmp815;
    TNode<JSReceiver> tmp816;
    TNode<Object> tmp817;
    TNode<NativeContext> tmp818;
    TNode<HeapObject> tmp819;
    TNode<Object> tmp820;
    TNode<Object> tmp821;
    TNode<Context> tmp822;
    TNode<Smi> tmp823;
    TNode<Object> tmp824;
    TNode<Map> tmp825;
    TNode<Object> tmp826;
    TNode<JSReceiver> tmp827;
    TNode<Smi> tmp828;
    TNode<JSReceiver> tmp829;
    TNode<JSReceiver> tmp830;
    TNode<Object> tmp831;
    TNode<Object> tmp832;
    TNode<Object> tmp833;
    TNode<Context> tmp834;
    TNode<Object> tmp835;
    TNode<Symbol> tmp836;
    TNode<HeapObject> tmp837;
    TNode<Object> tmp838;
    ca_.Bind(&block61, &tmp813, &tmp814, &tmp815, &tmp816, &tmp817, &tmp818, &tmp819, &tmp820, &tmp821, &tmp822, &tmp823, &tmp824, &tmp825, &tmp826, &tmp827, &tmp828, &tmp829, &tmp830, &tmp831, &tmp832, &tmp833, &tmp834, &tmp835, &tmp836, &tmp837, &tmp838);
    ca_.Goto(&block48, tmp813, tmp814, tmp815, tmp816, tmp817, tmp818, tmp819, tmp820, tmp821, tmp822, tmp823, tmp824, tmp825, tmp826, tmp827, tmp828, tmp829, tmp830, tmp838);
  }

  if (block54.is_used()) {
    TNode<Context> tmp839;
    TNode<JSReceiver> tmp840;
    TNode<PromiseCapability> tmp841;
    TNode<JSReceiver> tmp842;
    TNode<Object> tmp843;
    TNode<NativeContext> tmp844;
    TNode<HeapObject> tmp845;
    TNode<Object> tmp846;
    TNode<Object> tmp847;
    TNode<Context> tmp848;
    TNode<Smi> tmp849;
    TNode<Object> tmp850;
    TNode<Map> tmp851;
    TNode<Object> tmp852;
    TNode<JSReceiver> tmp853;
    TNode<Smi> tmp854;
    TNode<JSReceiver> tmp855;
    TNode<JSReceiver> tmp856;
    TNode<Object> tmp857;
    TNode<Object> tmp858;
    TNode<Object> tmp859;
    ca_.Bind(&block54, &tmp839, &tmp840, &tmp841, &tmp842, &tmp843, &tmp844, &tmp845, &tmp846, &tmp847, &tmp848, &tmp849, &tmp850, &tmp851, &tmp852, &tmp853, &tmp854, &tmp855, &tmp856, &tmp857, &tmp858, &tmp859);
    ca_.Goto(&block46, tmp839, tmp840, tmp841, tmp842, tmp843, tmp844, tmp845, tmp846, tmp847, tmp848, tmp849, tmp850, tmp851, tmp852, tmp853, tmp854, tmp855, tmp856);
  }

  if (block48.is_used()) {
    TNode<Context> tmp860;
    TNode<JSReceiver> tmp861;
    TNode<PromiseCapability> tmp862;
    TNode<JSReceiver> tmp863;
    TNode<Object> tmp864;
    TNode<NativeContext> tmp865;
    TNode<HeapObject> tmp866;
    TNode<Object> tmp867;
    TNode<Object> tmp868;
    TNode<Context> tmp869;
    TNode<Smi> tmp870;
    TNode<Object> tmp871;
    TNode<Map> tmp872;
    TNode<Object> tmp873;
    TNode<JSReceiver> tmp874;
    TNode<Smi> tmp875;
    TNode<JSReceiver> tmp876;
    TNode<JSReceiver> tmp877;
    TNode<Object> tmp878;
    ca_.Bind(&block48, &tmp860, &tmp861, &tmp862, &tmp863, &tmp864, &tmp865, &tmp866, &tmp867, &tmp868, &tmp869, &tmp870, &tmp871, &tmp872, &tmp873, &tmp874, &tmp875, &tmp876, &tmp877, &tmp878);
    compiler::TypedCodeAssemblerVariable<Object> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    IteratorCloseOnException_0(state_, TNode<Context>{tmp860}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp863}, TNode<Object>{tmp864}}, TNode<Object>{tmp878}, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block62, tmp860, tmp861, tmp862, tmp863, tmp864, tmp865, tmp866, tmp867, tmp868, tmp869, tmp870, tmp871, tmp872, tmp873, tmp874, tmp875, tmp876, tmp877, tmp878, tmp863, tmp864, tmp878, tmp860, result_0_0.value());
    }
  }

  if (block62.is_used()) {
    TNode<Context> tmp879;
    TNode<JSReceiver> tmp880;
    TNode<PromiseCapability> tmp881;
    TNode<JSReceiver> tmp882;
    TNode<Object> tmp883;
    TNode<NativeContext> tmp884;
    TNode<HeapObject> tmp885;
    TNode<Object> tmp886;
    TNode<Object> tmp887;
    TNode<Context> tmp888;
    TNode<Smi> tmp889;
    TNode<Object> tmp890;
    TNode<Map> tmp891;
    TNode<Object> tmp892;
    TNode<JSReceiver> tmp893;
    TNode<Smi> tmp894;
    TNode<JSReceiver> tmp895;
    TNode<JSReceiver> tmp896;
    TNode<Object> tmp897;
    TNode<JSReceiver> tmp898;
    TNode<Object> tmp899;
    TNode<Object> tmp900;
    TNode<Context> tmp901;
    TNode<Object> tmp902;
    ca_.Bind(&block62, &tmp879, &tmp880, &tmp881, &tmp882, &tmp883, &tmp884, &tmp885, &tmp886, &tmp887, &tmp888, &tmp889, &tmp890, &tmp891, &tmp892, &tmp893, &tmp894, &tmp895, &tmp896, &tmp897, &tmp898, &tmp899, &tmp900, &tmp901, &tmp902);
    ca_.Goto(&block1, tmp902);
  }

  if (block33.is_used()) {
    TNode<Context> tmp903;
    TNode<JSReceiver> tmp904;
    TNode<PromiseCapability> tmp905;
    TNode<JSReceiver> tmp906;
    TNode<Object> tmp907;
    TNode<NativeContext> tmp908;
    TNode<HeapObject> tmp909;
    TNode<Object> tmp910;
    TNode<Object> tmp911;
    TNode<Context> tmp912;
    TNode<Smi> tmp913;
    TNode<Object> tmp914;
    TNode<Map> tmp915;
    TNode<Object> tmp916;
    TNode<JSReceiver> tmp917;
    TNode<Smi> tmp918;
    TNode<JSReceiver> tmp919;
    TNode<JSReceiver> tmp920;
    ca_.Bind(&block33, &tmp903, &tmp904, &tmp905, &tmp906, &tmp907, &tmp908, &tmp909, &tmp910, &tmp911, &tmp912, &tmp913, &tmp914, &tmp915, &tmp916, &tmp917, &tmp918, &tmp919, &tmp920);
    TNode<JSPromise> tmp921;
    USE(tmp921);
    tmp921 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp903}, TNode<Object>{tmp916});
    TNode<Oddball> tmp922;
    USE(tmp922);
    tmp922 = Undefined_0(state_);
    PerformPromiseThenImpl_0(state_, TNode<Context>{tmp903}, TNode<JSPromise>{tmp921}, TNode<HeapObject>{tmp919}, TNode<HeapObject>{tmp920}, TNode<HeapObject>{tmp922});
    ca_.Goto(&block46, tmp903, tmp904, tmp905, tmp906, tmp907, tmp908, tmp909, tmp910, tmp911, tmp912, tmp913, tmp914, tmp915, tmp916, tmp917, tmp918, tmp919, tmp920);
  }

  if (block46.is_used()) {
    TNode<Context> tmp923;
    TNode<JSReceiver> tmp924;
    TNode<PromiseCapability> tmp925;
    TNode<JSReceiver> tmp926;
    TNode<Object> tmp927;
    TNode<NativeContext> tmp928;
    TNode<HeapObject> tmp929;
    TNode<Object> tmp930;
    TNode<Object> tmp931;
    TNode<Context> tmp932;
    TNode<Smi> tmp933;
    TNode<Object> tmp934;
    TNode<Map> tmp935;
    TNode<Object> tmp936;
    TNode<JSReceiver> tmp937;
    TNode<Smi> tmp938;
    TNode<JSReceiver> tmp939;
    TNode<JSReceiver> tmp940;
    ca_.Bind(&block46, &tmp923, &tmp924, &tmp925, &tmp926, &tmp927, &tmp928, &tmp929, &tmp930, &tmp931, &tmp932, &tmp933, &tmp934, &tmp935, &tmp936, &tmp937, &tmp938, &tmp939, &tmp940);
    TNode<Smi> tmp941;
    USE(tmp941);
    tmp941 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp942;
    USE(tmp942);
    tmp942 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp933}, TNode<Smi>{tmp941});
    ca_.Goto(&block19, tmp923, tmp924, tmp925, tmp926, tmp927, tmp928, tmp929, tmp930, tmp931, tmp932, tmp942, tmp934, tmp935);
  }

  if (block18.is_used()) {
    TNode<Context> tmp943;
    TNode<JSReceiver> tmp944;
    TNode<PromiseCapability> tmp945;
    TNode<JSReceiver> tmp946;
    TNode<Object> tmp947;
    TNode<NativeContext> tmp948;
    TNode<HeapObject> tmp949;
    TNode<Object> tmp950;
    TNode<Object> tmp951;
    TNode<Context> tmp952;
    TNode<Smi> tmp953;
    TNode<Object> tmp954;
    TNode<Map> tmp955;
    ca_.Bind(&block18, &tmp943, &tmp944, &tmp945, &tmp946, &tmp947, &tmp948, &tmp949, &tmp950, &tmp951, &tmp952, &tmp953, &tmp954, &tmp955);
    ca_.Goto(&block5, tmp943, tmp944, tmp945, tmp946, tmp947, tmp948, tmp949, tmp950, tmp951, tmp952, tmp953, tmp954);
  }

  if (block5.is_used()) {
    TNode<Context> tmp956;
    TNode<JSReceiver> tmp957;
    TNode<PromiseCapability> tmp958;
    TNode<JSReceiver> tmp959;
    TNode<Object> tmp960;
    TNode<NativeContext> tmp961;
    TNode<HeapObject> tmp962;
    TNode<Object> tmp963;
    TNode<Object> tmp964;
    TNode<Context> tmp965;
    TNode<Smi> tmp966;
    TNode<Object> tmp967;
    ca_.Bind(&block5, &tmp956, &tmp957, &tmp958, &tmp959, &tmp960, &tmp961, &tmp962, &tmp963, &tmp964, &tmp965, &tmp966, &tmp967);
    TNode<Object> tmp968;
    USE(tmp968);
    tmp968 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp965}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<Smi> tmp969;
    USE(tmp969);
    tmp969 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp956}, TNode<Object>{tmp968});
    TNode<Smi> tmp970;
    USE(tmp970);
    tmp970 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp971;
    USE(tmp971);
    tmp971 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp969}, TNode<Smi>{tmp970});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp965}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp971});
    TNode<Smi> tmp972;
    USE(tmp972);
    tmp972 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp973;
    USE(tmp973);
    tmp973 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp971}, TNode<Smi>{tmp972});
    ca_.Branch(tmp973, &block63, &block64, tmp956, tmp957, tmp958, tmp959, tmp960, tmp961, tmp962, tmp963, tmp964, tmp965, tmp966, tmp967, tmp971);
  }

  if (block63.is_used()) {
    TNode<Context> tmp974;
    TNode<JSReceiver> tmp975;
    TNode<PromiseCapability> tmp976;
    TNode<JSReceiver> tmp977;
    TNode<Object> tmp978;
    TNode<NativeContext> tmp979;
    TNode<HeapObject> tmp980;
    TNode<Object> tmp981;
    TNode<Object> tmp982;
    TNode<Context> tmp983;
    TNode<Smi> tmp984;
    TNode<Object> tmp985;
    TNode<Smi> tmp986;
    ca_.Bind(&block63, &tmp974, &tmp975, &tmp976, &tmp977, &tmp978, &tmp979, &tmp980, &tmp981, &tmp982, &tmp983, &tmp984, &tmp985, &tmp986);
    TNode<Object> tmp987;
    USE(tmp987);
    tmp987 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp983}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<JSArray> tmp988;
    USE(tmp988);
    tmp988 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp974}, TNode<Object>{tmp987});
    TNode<IntPtrT> tmp989;
    USE(tmp989);
    tmp989 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<FixedArrayBase>tmp990 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp988, tmp989});
    TNode<FixedArray> tmp991;
    USE(tmp991);
    tmp991 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp974}, TNode<Object>{tmp990});
    TNode<IntPtrT> tmp992;
    USE(tmp992);
    tmp992 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp991});
    TNode<IntPtrT> tmp993;
    USE(tmp993);
    tmp993 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp984});
    TNode<BoolT> tmp994;
    USE(tmp994);
    tmp994 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp992}, TNode<IntPtrT>{tmp993});
    ca_.Branch(tmp994, &block66, &block67, tmp974, tmp975, tmp976, tmp977, tmp978, tmp979, tmp980, tmp981, tmp982, tmp983, tmp984, tmp985, tmp986, tmp988, tmp991, tmp992, tmp993);
  }

  if (block66.is_used()) {
    TNode<Context> tmp995;
    TNode<JSReceiver> tmp996;
    TNode<PromiseCapability> tmp997;
    TNode<JSReceiver> tmp998;
    TNode<Object> tmp999;
    TNode<NativeContext> tmp1000;
    TNode<HeapObject> tmp1001;
    TNode<Object> tmp1002;
    TNode<Object> tmp1003;
    TNode<Context> tmp1004;
    TNode<Smi> tmp1005;
    TNode<Object> tmp1006;
    TNode<Smi> tmp1007;
    TNode<JSArray> tmp1008;
    TNode<FixedArray> tmp1009;
    TNode<IntPtrT> tmp1010;
    TNode<IntPtrT> tmp1011;
    ca_.Bind(&block66, &tmp995, &tmp996, &tmp997, &tmp998, &tmp999, &tmp1000, &tmp1001, &tmp1002, &tmp1003, &tmp1004, &tmp1005, &tmp1006, &tmp1007, &tmp1008, &tmp1009, &tmp1010, &tmp1011);
    TNode<IntPtrT> tmp1012;
    USE(tmp1012);
    tmp1012 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp1013;
    USE(tmp1013);
    tmp1013 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<FixedArray> tmp1014;
    USE(tmp1014);
    tmp1014 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp1009}, TNode<IntPtrT>{tmp1013}, TNode<IntPtrT>{tmp1010}, TNode<IntPtrT>{tmp1011});
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1008, tmp1012}, tmp1014);
    ca_.Goto(&block67, tmp995, tmp996, tmp997, tmp998, tmp999, tmp1000, tmp1001, tmp1002, tmp1003, tmp1004, tmp1005, tmp1006, tmp1007, tmp1008, tmp1009, tmp1010, tmp1011);
  }

  if (block67.is_used()) {
    TNode<Context> tmp1015;
    TNode<JSReceiver> tmp1016;
    TNode<PromiseCapability> tmp1017;
    TNode<JSReceiver> tmp1018;
    TNode<Object> tmp1019;
    TNode<NativeContext> tmp1020;
    TNode<HeapObject> tmp1021;
    TNode<Object> tmp1022;
    TNode<Object> tmp1023;
    TNode<Context> tmp1024;
    TNode<Smi> tmp1025;
    TNode<Object> tmp1026;
    TNode<Smi> tmp1027;
    TNode<JSArray> tmp1028;
    TNode<FixedArray> tmp1029;
    TNode<IntPtrT> tmp1030;
    TNode<IntPtrT> tmp1031;
    ca_.Bind(&block67, &tmp1015, &tmp1016, &tmp1017, &tmp1018, &tmp1019, &tmp1020, &tmp1021, &tmp1022, &tmp1023, &tmp1024, &tmp1025, &tmp1026, &tmp1027, &tmp1028, &tmp1029, &tmp1030, &tmp1031);
    ca_.Goto(&block65, tmp1015, tmp1016, tmp1017, tmp1018, tmp1019, tmp1020, tmp1021, tmp1022, tmp1023, tmp1024, tmp1025, tmp1026, tmp1027);
  }

  if (block64.is_used()) {
    TNode<Context> tmp1032;
    TNode<JSReceiver> tmp1033;
    TNode<PromiseCapability> tmp1034;
    TNode<JSReceiver> tmp1035;
    TNode<Object> tmp1036;
    TNode<NativeContext> tmp1037;
    TNode<HeapObject> tmp1038;
    TNode<Object> tmp1039;
    TNode<Object> tmp1040;
    TNode<Context> tmp1041;
    TNode<Smi> tmp1042;
    TNode<Object> tmp1043;
    TNode<Smi> tmp1044;
    ca_.Bind(&block64, &tmp1032, &tmp1033, &tmp1034, &tmp1035, &tmp1036, &tmp1037, &tmp1038, &tmp1039, &tmp1040, &tmp1041, &tmp1042, &tmp1043, &tmp1044);
    TNode<Object> tmp1045;
    USE(tmp1045);
    tmp1045 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp1041}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    TNode<Object> tmp1046;
    USE(tmp1046);
    tmp1046 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp1032}, TNode<Object>{tmp1045});
    TNode<Object> tmp1047;
    USE(tmp1047);
    tmp1047 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp1032}, TNode<Object>{tmp1039});
    TNode<Oddball> tmp1048;
    USE(tmp1048);
    tmp1048 = Undefined_0(state_);
    TNode<Object> tmp1049;
    USE(tmp1049);
    tmp1049 = CodeStubAssembler(state_).Call(TNode<Context>{tmp1037}, TNode<Object>{tmp1047}, TNode<Object>{tmp1048}, TNode<Object>{tmp1046});
    ca_.Goto(&block65, tmp1032, tmp1033, tmp1034, tmp1035, tmp1036, tmp1037, tmp1038, tmp1039, tmp1040, tmp1041, tmp1042, tmp1043, tmp1044);
  }

  if (block71.is_used()) {
    TNode<Context> tmp1050;
    TNode<JSReceiver> tmp1051;
    TNode<PromiseCapability> tmp1052;
    TNode<JSReceiver> tmp1053;
    TNode<Object> tmp1054;
    TNode<NativeContext> tmp1055;
    TNode<HeapObject> tmp1056;
    TNode<Object> tmp1057;
    TNode<Object> tmp1058;
    TNode<Context> tmp1059;
    TNode<Smi> tmp1060;
    TNode<Object> tmp1061;
    TNode<Smi> tmp1062;
    ca_.Bind(&block71, &tmp1050, &tmp1051, &tmp1052, &tmp1053, &tmp1054, &tmp1055, &tmp1056, &tmp1057, &tmp1058, &tmp1059, &tmp1060, &tmp1061, &tmp1062);
    CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount == 0' failed", "src/builtins/promise-all.tq", 314);
  }

  if (block70.is_used()) {
    TNode<Context> tmp1063;
    TNode<JSReceiver> tmp1064;
    TNode<PromiseCapability> tmp1065;
    TNode<JSReceiver> tmp1066;
    TNode<Object> tmp1067;
    TNode<NativeContext> tmp1068;
    TNode<HeapObject> tmp1069;
    TNode<Object> tmp1070;
    TNode<Object> tmp1071;
    TNode<Context> tmp1072;
    TNode<Smi> tmp1073;
    TNode<Object> tmp1074;
    TNode<Smi> tmp1075;
    ca_.Bind(&block70, &tmp1063, &tmp1064, &tmp1065, &tmp1066, &tmp1067, &tmp1068, &tmp1069, &tmp1070, &tmp1071, &tmp1072, &tmp1073, &tmp1074, &tmp1075);
  }

  if (block65.is_used()) {
    TNode<Context> tmp1076;
    TNode<JSReceiver> tmp1077;
    TNode<PromiseCapability> tmp1078;
    TNode<JSReceiver> tmp1079;
    TNode<Object> tmp1080;
    TNode<NativeContext> tmp1081;
    TNode<HeapObject> tmp1082;
    TNode<Object> tmp1083;
    TNode<Object> tmp1084;
    TNode<Context> tmp1085;
    TNode<Smi> tmp1086;
    TNode<Object> tmp1087;
    TNode<Smi> tmp1088;
    ca_.Bind(&block65, &tmp1076, &tmp1077, &tmp1078, &tmp1079, &tmp1080, &tmp1081, &tmp1082, &tmp1083, &tmp1084, &tmp1085, &tmp1086, &tmp1087, &tmp1088);
    ca_.Goto(&block72, tmp1076, tmp1077, tmp1078, tmp1079, tmp1080, tmp1082);
  }

  if (block1.is_used()) {
    TNode<Object> tmp1089;
    ca_.Bind(&block1, &tmp1089);
    *label_Reject_parameter_0 = tmp1089;
    ca_.Goto(label_Reject);
  }

    TNode<Context> tmp1090;
    TNode<JSReceiver> tmp1091;
    TNode<PromiseCapability> tmp1092;
    TNode<JSReceiver> tmp1093;
    TNode<Object> tmp1094;
    TNode<Object> tmp1095;
    ca_.Bind(&block72, &tmp1090, &tmp1091, &tmp1092, &tmp1093, &tmp1094, &tmp1095);
  return TNode<Object>{tmp1095};
}

TNode<BoolT> Is_JSPromise_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSPromise> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSPromise_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
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
    TNode<JSPromise> tmp12;
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

}  // namespace internal
}  // namespace v8

