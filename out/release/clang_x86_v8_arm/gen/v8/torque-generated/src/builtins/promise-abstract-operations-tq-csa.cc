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

TNode<Context> ExtractHandlerContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler, compiler::CodeAssemblerLabel* label_NotFound) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context, JSBoundFunction> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context, JSProxy> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object, Object, Context, JSFunction> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Context> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_handler);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block5, tmp0, tmp1, tmp1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp2;
    TNode<HeapObject> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp5, &block3, &block4, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    TNode<JSBoundFunction> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = Cast_JSBoundFunction_1(state_, TNode<Context>{tmp6}, TNode<Object>{tmp8}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp8, tmp8, tmp8, tmp6, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp8, tmp8, tmp8, tmp6);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp10;
    TNode<HeapObject> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Context> tmp15;
    ca_.Bind(&block9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<JSProxy> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_JSProxy_1(state_, TNode<Context>{tmp10}, TNode<Object>{ca_.UncheckedCast<Object>(tmp13)}, &label0);
    ca_.Goto(&block12, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<Object>(tmp13), tmp10, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<Object>(tmp13), tmp10);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp17;
    TNode<HeapObject> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Context> tmp22;
    TNode<JSBoundFunction> tmp23;
    ca_.Bind(&block8, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<JSReceiver>tmp25 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp23, tmp24});
    ca_.Goto(&block6, tmp17, tmp18, tmp25, tmp20);
  }

  if (block13.is_used()) {
    TNode<Context> tmp26;
    TNode<HeapObject> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Context> tmp31;
    ca_.Bind(&block13, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<JSFunction> tmp32;
    USE(tmp32);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp32 = Cast_JSFunction_1(state_, TNode<Context>{tmp26}, TNode<Object>{ca_.UncheckedCast<Object>(tmp29)}, &label0);
    ca_.Goto(&block16, tmp26, tmp27, tmp28, tmp29, ca_.UncheckedCast<Object>(tmp29), tmp26, tmp32);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp26, tmp27, tmp28, tmp29, ca_.UncheckedCast<Object>(tmp29), tmp26);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp33;
    TNode<HeapObject> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Context> tmp38;
    TNode<JSProxy> tmp39;
    ca_.Bind(&block12, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<HeapObject>tmp41 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp39, tmp40});
    ca_.Goto(&block6, tmp33, tmp34, tmp41, tmp36);
  }

  if (block17.is_used()) {
    TNode<Context> tmp42;
    TNode<HeapObject> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    TNode<Context> tmp47;
    ca_.Bind(&block17, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    ca_.Goto(&block4, tmp42, tmp43, tmp44);
  }

  if (block16.is_used()) {
    TNode<Context> tmp48;
    TNode<HeapObject> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Context> tmp53;
    TNode<JSFunction> tmp54;
    ca_.Bind(&block16, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Context>tmp56 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp54, tmp55});
    ca_.Goto(&block18, tmp48, tmp49, tmp56);
  }

  if (block6.is_used()) {
    TNode<Context> tmp57;
    TNode<HeapObject> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block6, &tmp57, &tmp58, &tmp59, &tmp60);
    ca_.Goto(&block5, tmp57, tmp58, tmp59);
  }

  if (block4.is_used()) {
    TNode<Context> tmp61;
    TNode<HeapObject> tmp62;
    TNode<Object> tmp63;
    ca_.Bind(&block4, &tmp61, &tmp62, &tmp63);
    ca_.Goto(label_NotFound);
  }

    TNode<Context> tmp64;
    TNode<HeapObject> tmp65;
    TNode<Context> tmp66;
    ca_.Bind(&block18, &tmp64, &tmp65, &tmp66);
  return TNode<Context>{tmp66};
}

TNode<Context> ExtractHandlerContext_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_primary, TNode<HeapObject> p_secondary) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context, Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_primary, p_secondary);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    TNode<HeapObject> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Context> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = ExtractHandlerContext_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp4;
    TNode<HeapObject> tmp5;
    TNode<HeapObject> tmp6;
    TNode<HeapObject> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block7, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Context> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = ExtractHandlerContext_0(state_, TNode<Context>{tmp4}, TNode<HeapObject>{tmp6}, &label0);
    ca_.Goto(&block8, tmp4, tmp5, tmp6, tmp6, tmp4, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp4, tmp5, tmp6, tmp6, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp10;
    TNode<HeapObject> tmp11;
    TNode<HeapObject> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    TNode<Context> tmp15;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    ca_.Goto(&block1, tmp10, tmp11, tmp12, tmp15);
  }

  if (block9.is_used()) {
    TNode<Context> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    TNode<HeapObject> tmp19;
    TNode<Context> tmp20;
    ca_.Bind(&block9, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block1, tmp16, tmp17, tmp18, tmp16);
  }

  if (block8.is_used()) {
    TNode<Context> tmp21;
    TNode<HeapObject> tmp22;
    TNode<HeapObject> tmp23;
    TNode<HeapObject> tmp24;
    TNode<Context> tmp25;
    TNode<Context> tmp26;
    ca_.Bind(&block8, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block1, tmp21, tmp22, tmp23, tmp26);
  }

  if (block1.is_used()) {
    TNode<Context> tmp27;
    TNode<HeapObject> tmp28;
    TNode<HeapObject> tmp29;
    TNode<Context> tmp30;
    ca_.Bind(&block1, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block10, tmp27, tmp28, tmp29, tmp30);
  }

    TNode<Context> tmp31;
    TNode<HeapObject> tmp32;
    TNode<HeapObject> tmp33;
    TNode<Context> tmp34;
    ca_.Bind(&block10, &tmp31, &tmp32, &tmp33, &tmp34);
  return TNode<Context>{tmp34};
}

void MorphAndEnqueuePromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseReaction> p_promiseReaction, TNode<Object> p_argument, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object, HeapObject, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, PromiseReaction, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promiseReaction, p_argument);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<PromiseReaction> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
      ca_.Goto(&block2, tmp0, tmp1, tmp2, ca_.Uninitialized<HeapObject>(), ca_.Uninitialized<HeapObject>());
    } else {
      ca_.Goto(&block3, tmp0, tmp1, tmp2, ca_.Uninitialized<HeapObject>(), ca_.Uninitialized<HeapObject>());
    }
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<PromiseReaction> tmp4;
    TNode<Object> tmp5;
    TNode<HeapObject> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<HeapObject>tmp9 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<HeapObject>tmp11 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp10});
    ca_.Goto(&block4, tmp3, tmp4, tmp5, tmp9, tmp11);
  }

  if (block3.is_used()) {
    TNode<Context> tmp12;
    TNode<PromiseReaction> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<HeapObject> tmp16;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp17});
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<HeapObject>tmp19 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp13, tmp18});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<HeapObject>tmp21 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp13, tmp20});
    ca_.Goto(&block4, tmp12, tmp13, tmp14, tmp19, tmp21);
  }

  if (block4.is_used()) {
    TNode<Context> tmp22;
    TNode<PromiseReaction> tmp23;
    TNode<Object> tmp24;
    TNode<HeapObject> tmp25;
    TNode<HeapObject> tmp26;
    ca_.Bind(&block4, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<Context> tmp27;
    USE(tmp27);
    tmp27 = ExtractHandlerContext_1(state_, TNode<Context>{tmp22}, TNode<HeapObject>{tmp25}, TNode<HeapObject>{tmp26});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kSize, PromiseReactionJobTask::kSizeOfAllPromiseReactionJobTasks)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp28});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
      ca_.Goto(&block5, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
    } else {
      ca_.Goto(&block6, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp29;
    TNode<PromiseReaction> tmp30;
    TNode<Object> tmp31;
    TNode<HeapObject> tmp32;
    TNode<HeapObject> tmp33;
    TNode<Context> tmp34;
    ca_.Bind(&block5, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).PromiseFulfillReactionJobTaskMapConstant();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp30, tmp35}, tmp36);
    TNode<PromiseFulfillReactionJobTask> tmp37;
    USE(tmp37);
    tmp37 = UnsafeCast_PromiseFulfillReactionJobTask_0(state_, TNode<Context>{tmp29}, TNode<Object>{tmp30});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38}, tmp31);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp37, tmp39}, tmp34);
    TNode<Oddball> tmp40;
    tmp40 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp34, tmp37));
    USE(tmp40);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kFulfillHandlerOffset, PromiseReactionJobTask::kHandlerOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp41});
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp42});
    ca_.Goto(&block7, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34);
  }

  if (block6.is_used()) {
    TNode<Context> tmp43;
    TNode<PromiseReaction> tmp44;
    TNode<Object> tmp45;
    TNode<HeapObject> tmp46;
    TNode<HeapObject> tmp47;
    TNode<Context> tmp48;
    ca_.Bind(&block6, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp49});
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Map> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).PromiseRejectReactionJobTaskMapConstant();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp44, tmp50}, tmp51);
    TNode<PromiseRejectReactionJobTask> tmp52;
    USE(tmp52);
    tmp52 = UnsafeCast_PromiseRejectReactionJobTask_0(state_, TNode<Context>{tmp43}, TNode<Object>{tmp44});
    TNode<IntPtrT> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp52, tmp53}, tmp45);
    TNode<IntPtrT> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp52, tmp54}, tmp48);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp52, tmp55}, tmp46);
    TNode<Oddball> tmp56;
    tmp56 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp48, tmp52));
    USE(tmp56);
    TNode<BoolT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp57});
    ca_.Goto(&block7, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48);
  }

  if (block7.is_used()) {
    TNode<Context> tmp58;
    TNode<PromiseReaction> tmp59;
    TNode<Object> tmp60;
    TNode<HeapObject> tmp61;
    TNode<HeapObject> tmp62;
    TNode<Context> tmp63;
    ca_.Bind(&block7, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block8, tmp58, tmp59, tmp60);
  }

    TNode<Context> tmp64;
    TNode<PromiseReaction> tmp65;
    TNode<Object> tmp66;
    ca_.Bind(&block8, &tmp64, &tmp65, &tmp66);
}

void TriggerPromiseReactions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_reactions, TNode<Object> p_argument, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object, Object, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object, Object, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_reactions, p_argument);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = kZero_0(state_);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp3);
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block2, &block3, tmp4, tmp5, tmp6, tmp7, tmp8);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_Zero_0(state_, TNode<Object>{tmp13}, &label0);
    ca_.Goto(&block7, tmp10, tmp11, tmp12, tmp13, tmp14, tmp13, tmp13, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp10, tmp11, tmp12, tmp13, tmp14, tmp13, tmp13);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Object>tmp24 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(tmp21), tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(tmp21), tmp25}, tmp20);
    ca_.Goto(&block4, tmp16, tmp17, tmp18, tmp24, ca_.UncheckedCast<PromiseReaction>(tmp21));
  }

  if (block7.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<Smi> tmp33;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block3, tmp26, tmp27, tmp28, tmp29, tmp30);
  }

  if (block3.is_used()) {
    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block3, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    ca_.Goto(&block11, tmp34, tmp35, tmp36, tmp38, tmp38);
  }

  if (block11.is_used()) {
    TNode<Context> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    ca_.Bind(&block11, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp44, &block9, &block10, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block9.is_used()) {
    TNode<Context> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block9, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Smi> tmp50;
    USE(tmp50);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp50 = Cast_Zero_0(state_, TNode<Object>{tmp48}, &label0);
    ca_.Goto(&block14, tmp45, tmp46, tmp47, tmp48, tmp49, tmp48, tmp48, tmp50);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp45, tmp46, tmp47, tmp48, tmp49, tmp48, tmp48);
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    ca_.Bind(&block15, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<IntPtrT> tmp58;
    USE(tmp58);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Object>tmp59 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(tmp56), tmp58});
    MorphAndEnqueuePromiseReaction_0(state_, TNode<Context>{tmp51}, TNode<PromiseReaction>{ca_.UncheckedCast<PromiseReaction>(tmp56)}, TNode<Object>{tmp53}, p_reactionType);
    ca_.Goto(&block11, tmp51, tmp52, tmp53, tmp59, tmp55);
  }

  if (block14.is_used()) {
    TNode<Context> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Smi> tmp67;
    ca_.Bind(&block14, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    ca_.Goto(&block10, tmp60, tmp61, tmp62, tmp63, tmp64);
  }

  if (block10.is_used()) {
    TNode<Context> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<Object> tmp72;
    ca_.Bind(&block10, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    ca_.Goto(&block16, tmp68, tmp69, tmp70);
  }

    TNode<Context> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    ca_.Bind(&block16, &tmp73, &tmp74, &tmp75);
}

TF_BUILTIN(FulfillPromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp4 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp1, tmp6}, tmp2);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{tmp1}, Promise::PromiseState::kFulfilled);
    TriggerPromiseReactions_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5}, TNode<Object>{tmp2}, PromiseReaction::kFulfill);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<JSPromise> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'promise.Status() == PromiseState::kPending' failed", "src/builtins/promise-abstract-operations.tq", 180);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSPromise> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13);
  }
}

TF_BUILTIN(RejectPromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Oddball> parameter3 = UncheckedCast<Oddball>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<Object> tmp2;
    TNode<Oddball> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = PromiseBuiltinsAssembler(state_).IsPromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Branch(tmp4, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<JSPromise> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    TNode<BoolT> tmp9;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block4.is_used()) {
    TNode<Context> tmp11;
    TNode<JSPromise> tmp12;
    TNode<Object> tmp13;
    TNode<Oddball> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block4, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{tmp12});
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp16});
    ca_.Goto(&block5, tmp11, tmp12, tmp13, tmp14, tmp15, tmp17);
  }

  if (block5.is_used()) {
    TNode<Context> tmp18;
    TNode<JSPromise> tmp19;
    TNode<Object> tmp20;
    TNode<Oddball> tmp21;
    TNode<BoolT> tmp22;
    TNode<BoolT> tmp23;
    ca_.Bind(&block5, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Branch(tmp23, &block1, &block2, tmp18, tmp19, tmp20, tmp21);
  }

  if (block1.is_used()) {
    TNode<Context> tmp24;
    TNode<JSPromise> tmp25;
    TNode<Object> tmp26;
    TNode<Oddball> tmp27;
    ca_.Bind(&block1, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<Object> tmp28;
    tmp28 = CodeStubAssembler(state_).CallRuntime(Runtime::kRejectPromise, tmp24, tmp25, tmp26, tmp27); 
    USE(tmp28);
    CodeStubAssembler(state_).Return(tmp28);
  }

  if (block2.is_used()) {
    TNode<Context> tmp29;
    TNode<JSPromise> tmp30;
    TNode<Object> tmp31;
    TNode<Oddball> tmp32;
    ca_.Bind(&block2, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp34 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp30, tmp33});
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{tmp29}, TNode<Object>{tmp34});
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp30, tmp36}, tmp31);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{tmp30}, Promise::PromiseState::kRejected);
    TriggerPromiseReactions_0(state_, TNode<Context>{tmp29}, TNode<Object>{tmp35}, TNode<Object>{tmp31}, PromiseReaction::kReject);
    TNode<Oddball> tmp37;
    USE(tmp37);
    tmp37 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp37);
  }
}

TNode<Context> CreatePromiseCapabilitiesExecutorContext_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<PromiseCapability> p_capability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, PromiseCapability> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, PromiseCapability, Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_nativeContext, p_capability);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<PromiseCapability> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Context> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{tmp0}, PromiseBuiltins::kCapabilitiesContextLength);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kCapabilitySlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<Object>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<NativeContext> tmp4;
    TNode<PromiseCapability> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
  return TNode<Context>{tmp6};
}

TNode<PromiseCapability> CreatePromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_promise, TNode<HeapObject> p_resolve, TNode<HeapObject> p_reject) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject, PromiseCapability> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_promise, p_resolve, p_reject);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<HeapObject> tmp1;
    TNode<HeapObject> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = kPromiseCapabilityMap_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<HeapObject> tmp5;
    USE(tmp5);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp3});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp3);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp0);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp8}, tmp1);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp9}, tmp2);
    TNode<PromiseCapability> tmp10;
    USE(tmp10);
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp10);
  }

    TNode<HeapObject> tmp11;
    TNode<HeapObject> tmp12;
    TNode<HeapObject> tmp13;
    TNode<PromiseCapability> tmp14;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14);
  return TNode<PromiseCapability>{tmp14};
}

TorqueStructPromiseResolvingFunctions CreatePromiseResolvingFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, Object, NativeContext, JSFunction, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promise, p_debugEvent, p_nativeContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<Object> tmp2;
    TNode<NativeContext> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Context> tmp4;
    USE(tmp4);
    tmp4 = CreatePromiseResolvingFunctionsContext_0(state_, TNode<Context>{tmp0}, TNode<JSPromise>{tmp1}, TNode<Object>{tmp2}, TNode<NativeContext>{tmp3});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp5});
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_CAPABILITY_DEFAULT_RESOLVE_SHARED_FUN_INDEX_0(state_, Context::Field::PROMISE_CAPABILITY_DEFAULT_RESOLVE_SHARED_FUN_INDEX);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp8});
    TNode<SharedFunctionInfo> tmp10;
    USE(tmp10);
    tmp10 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp9});
    TNode<JSFunction> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp7}, TNode<SharedFunctionInfo>{tmp10}, TNode<Context>{tmp4});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_CAPABILITY_DEFAULT_REJECT_SHARED_FUN_INDEX_0(state_, Context::Field::PROMISE_CAPABILITY_DEFAULT_REJECT_SHARED_FUN_INDEX);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp12});
    TNode<SharedFunctionInfo> tmp14;
    USE(tmp14);
    tmp14 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp13});
    TNode<JSFunction> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp7}, TNode<SharedFunctionInfo>{tmp14}, TNode<Context>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp11, tmp15);
  }

    TNode<Context> tmp16;
    TNode<JSPromise> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    TNode<JSFunction> tmp20;
    TNode<JSFunction> tmp21;
    ca_.Bind(&block2, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
  return TorqueStructPromiseResolvingFunctions{TNode<JSFunction>{tmp20}, TNode<JSFunction>{tmp21}};
}

TNode<PromiseCapability> InnerNewPromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_constructor, TNode<Object> p_debugEvent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext, PromiseCapability, Context, SharedFunctionInfo, Map, JSFunction, JSReceiver, JSReceiver, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext, PromiseCapability, Context, SharedFunctionInfo, Map, JSFunction, JSReceiver, JSReceiver, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext, PromiseCapability, Context, SharedFunctionInfo, Map, JSFunction, JSReceiver, JSReceiver, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext, PromiseCapability, Context, SharedFunctionInfo, Map, JSFunction, JSReceiver, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, NativeContext, PromiseCapability, Context, SharedFunctionInfo, Map, JSFunction, JSReceiver, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Object, PromiseCapability> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_constructor, p_debugEvent);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
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
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp1}, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<JSPromise> tmp11;
    USE(tmp11);
    tmp11 = NewJSPromise_1(state_, TNode<Context>{tmp7});
    TNode<JSFunction> tmp12;
    USE(tmp12);
    TNode<JSFunction> tmp13;
    USE(tmp13);
    std::tie(tmp12, tmp13) = CreatePromiseResolvingFunctions_0(state_, TNode<Context>{tmp7}, TNode<JSPromise>{tmp11}, TNode<Object>{tmp9}, TNode<NativeContext>{tmp10}).Flatten();
    TNode<PromiseCapability> tmp14;
    USE(tmp14);
    tmp14 = CreatePromiseCapability_0(state_, TNode<HeapObject>{tmp11}, TNode<HeapObject>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp14);
  }

  if (block3.is_used()) {
    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<Object> tmp17;
    TNode<NativeContext> tmp18;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    TNode<Oddball> tmp20;
    USE(tmp20);
    tmp20 = Undefined_0(state_);
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = Undefined_0(state_);
    TNode<PromiseCapability> tmp22;
    USE(tmp22);
    tmp22 = CreatePromiseCapability_0(state_, TNode<HeapObject>{tmp19}, TNode<HeapObject>{tmp20}, TNode<HeapObject>{tmp21});
    TNode<Context> tmp23;
    USE(tmp23);
    tmp23 = CreatePromiseCapabilitiesExecutorContext_0(state_, TNode<NativeContext>{tmp18}, TNode<PromiseCapability>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_GET_CAPABILITIES_EXECUTOR_SHARED_FUN_0(state_, Context::Field::PROMISE_GET_CAPABILITIES_EXECUTOR_SHARED_FUN);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp24});
    TNode<SharedFunctionInfo> tmp26;
    USE(tmp26);
    tmp26 = UnsafeCast_SharedFunctionInfo_0(state_, TNode<Context>{tmp15}, TNode<Object>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    TNode<Object> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp27});
    TNode<Map> tmp29;
    USE(tmp29);
    tmp29 = UnsafeCast_Map_0(state_, TNode<Context>{tmp15}, TNode<Object>{tmp28});
    TNode<JSFunction> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp29}, TNode<SharedFunctionInfo>{tmp26}, TNode<Context>{tmp23});
    TNode<JSReceiver> tmp31;
    USE(tmp31);
    tmp31 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp15}, TNode<Object>{tmp16});
    TNode<JSReceiver> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp15}, TNode<JSReceiver>{tmp31}, TNode<Object>{tmp30});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp22, tmp33}, tmp32);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp35 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp22, tmp34});
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp35});
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp36});
    ca_.Branch(tmp37, &block7, &block8, tmp15, tmp16, tmp17, tmp18, tmp22, tmp23, tmp26, tmp29, tmp30, tmp31, tmp32, tmp37);
  }

  if (block7.is_used()) {
    TNode<Context> tmp38;
    TNode<HeapObject> tmp39;
    TNode<Object> tmp40;
    TNode<NativeContext> tmp41;
    TNode<PromiseCapability> tmp42;
    TNode<Context> tmp43;
    TNode<SharedFunctionInfo> tmp44;
    TNode<Map> tmp45;
    TNode<JSFunction> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<BoolT> tmp49;
    ca_.Bind(&block7, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50);
  }

  if (block8.is_used()) {
    TNode<Context> tmp51;
    TNode<HeapObject> tmp52;
    TNode<Object> tmp53;
    TNode<NativeContext> tmp54;
    TNode<PromiseCapability> tmp55;
    TNode<Context> tmp56;
    TNode<SharedFunctionInfo> tmp57;
    TNode<Map> tmp58;
    TNode<JSFunction> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<BoolT> tmp62;
    ca_.Bind(&block8, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp64 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp55, tmp63});
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp64});
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp65});
    ca_.Goto(&block9, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp66);
  }

  if (block9.is_used()) {
    TNode<Context> tmp67;
    TNode<HeapObject> tmp68;
    TNode<Object> tmp69;
    TNode<NativeContext> tmp70;
    TNode<PromiseCapability> tmp71;
    TNode<Context> tmp72;
    TNode<SharedFunctionInfo> tmp73;
    TNode<Map> tmp74;
    TNode<JSFunction> tmp75;
    TNode<JSReceiver> tmp76;
    TNode<JSReceiver> tmp77;
    TNode<BoolT> tmp78;
    TNode<BoolT> tmp79;
    ca_.Bind(&block9, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    ca_.Branch(tmp79, &block5, &block6, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77);
  }

  if (block5.is_used()) {
    TNode<Context> tmp80;
    TNode<HeapObject> tmp81;
    TNode<Object> tmp82;
    TNode<NativeContext> tmp83;
    TNode<PromiseCapability> tmp84;
    TNode<Context> tmp85;
    TNode<SharedFunctionInfo> tmp86;
    TNode<Map> tmp87;
    TNode<JSFunction> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<JSReceiver> tmp90;
    ca_.Bind(&block5, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp80}, MessageTemplate::kPromiseNonCallable);
  }

  if (block6.is_used()) {
    TNode<Context> tmp91;
    TNode<HeapObject> tmp92;
    TNode<Object> tmp93;
    TNode<NativeContext> tmp94;
    TNode<PromiseCapability> tmp95;
    TNode<Context> tmp96;
    TNode<SharedFunctionInfo> tmp97;
    TNode<Map> tmp98;
    TNode<JSFunction> tmp99;
    TNode<JSReceiver> tmp100;
    TNode<JSReceiver> tmp101;
    ca_.Bind(&block6, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    ca_.Goto(&block1, tmp91, tmp92, tmp93, tmp95);
  }

  if (block1.is_used()) {
    TNode<Context> tmp102;
    TNode<HeapObject> tmp103;
    TNode<Object> tmp104;
    TNode<PromiseCapability> tmp105;
    ca_.Bind(&block1, &tmp102, &tmp103, &tmp104, &tmp105);
    ca_.Goto(&block10, tmp102, tmp103, tmp104, tmp105);
  }

    TNode<Context> tmp106;
    TNode<HeapObject> tmp107;
    TNode<Object> tmp108;
    TNode<PromiseCapability> tmp109;
    ca_.Bind(&block10, &tmp106, &tmp107, &tmp108, &tmp109);
  return TNode<PromiseCapability>{tmp109};
}

TF_BUILTIN(NewPromiseCapability, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp1, tmp1, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IsConstructor(TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp7)});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp9});
    ca_.Branch(tmp10, &block5, &block6, tmp4, tmp5, tmp6, tmp7, ca_.UncheckedCast<HeapObject>(tmp7));
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp11}, MessageTemplate::kNotConstructor, TNode<Object>{tmp12});
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<HeapObject> tmp21;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp17}, MessageTemplate::kNotConstructor, TNode<Object>{tmp18});
  }

  if (block6.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<HeapObject> tmp26;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<PromiseCapability> tmp27;
    USE(tmp27);
    tmp27 = InnerNewPromiseCapability_0(state_, TNode<Context>{tmp22}, TNode<HeapObject>{tmp26}, TNode<Object>{tmp24});
    CodeStubAssembler(state_).Return(tmp27);
  }
}

TF_BUILTIN(PromiseCapabilityDefaultReject, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSPromise, Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSPromise, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp3});
    TNode<JSPromise> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp6});
    TNode<Oddball> tmp8;
    USE(tmp8);
    tmp8 = UnsafeCast_Boolean_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp7});
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = True_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block1, &block2, tmp0, tmp1, tmp2, tmp5, tmp8);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<JSPromise> tmp14;
    TNode<Oddball> tmp15;
    ca_.Bind(&block1, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Object> tmp16;
    tmp16 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectAfterResolved, tmp11, tmp14, tmp13); 
    USE(tmp16);
    CodeStubAssembler(state_).Return(tmp16);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<JSPromise> tmp20;
    TNode<Oddball> tmp21;
    ca_.Bind(&block2, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Oddball> tmp22;
    USE(tmp22);
    tmp22 = True_0(state_);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp17}, TNode<IntPtrT>{tmp23}, TNode<Object>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kDebugEventSlot);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp17}, TNode<IntPtrT>{tmp24});
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = UnsafeCast_Boolean_0(state_, TNode<Context>{tmp17}, TNode<Object>{tmp25});
    TNode<Object> tmp27;
    tmp27 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRejectPromise, tmp17, tmp20, tmp19, tmp26);
    USE(tmp27);
    CodeStubAssembler(state_).Return(tmp27);
  }
}

TF_BUILTIN(PromiseCapabilityDefaultResolve, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kResolution));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSPromise, Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSPromise, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp3});
    TNode<JSPromise> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_JSPromise_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp6});
    TNode<Oddball> tmp8;
    USE(tmp8);
    tmp8 = UnsafeCast_Boolean_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp7});
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = True_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block1, &block2, tmp0, tmp1, tmp2, tmp5, tmp8);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<JSPromise> tmp14;
    TNode<Oddball> tmp15;
    ca_.Bind(&block1, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Object> tmp16;
    tmp16 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseResolveAfterResolved, tmp11, tmp14, tmp13); 
    USE(tmp16);
    CodeStubAssembler(state_).Return(tmp16);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<JSPromise> tmp20;
    TNode<Oddball> tmp21;
    ca_.Bind(&block2, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Oddball> tmp22;
    USE(tmp22);
    tmp22 = True_0(state_);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp17}, TNode<IntPtrT>{tmp23}, TNode<Object>{tmp22});
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallBuiltin(Builtins::kResolvePromise, tmp17, tmp20, tmp19);
    USE(tmp24);
    CodeStubAssembler(state_).Return(tmp24);
  }
}

void PerformPromiseThenImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<HeapObject> p_onFulfilled, TNode<HeapObject> p_onRejected, TNode<HeapObject> p_resultPromiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject, Map, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_promise, p_onFulfilled, p_onRejected, p_resultPromiseOrCapability);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = Method_JSPromise_Status_0(state_, TNode<JSPromise>{tmp1});
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_PromiseState_constexpr_kPending_0(state_, Promise::PromiseState::kPending);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = PromiseStateEquals_0(state_, TNode<Int32T>{tmp5}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<JSPromise> tmp9;
    TNode<HeapObject> tmp10;
    TNode<HeapObject> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp14 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp13});
    TNode<Object> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp14});
    TNode<PromiseReaction> tmp16;
    USE(tmp16);
    tmp16 = NewPromiseReaction_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp15}, TNode<HeapObject>{tmp12}, TNode<HeapObject>{tmp10}, TNode<HeapObject>{tmp11});
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp17}, tmp16);
    ca_.Goto(&block4, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp18;
    TNode<JSPromise> tmp19;
    TNode<HeapObject> tmp20;
    TNode<HeapObject> tmp21;
    TNode<HeapObject> tmp22;
    ca_.Bind(&block3, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = Undefined_0(state_);
    TNode<Int32T> tmp24;
    USE(tmp24);
    tmp24 = Method_JSPromise_Status_0(state_, TNode<JSPromise>{tmp19});
    TNode<Int32T> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_PromiseState_constexpr_kFulfilled_0(state_, Promise::PromiseState::kFulfilled);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = PromiseStateEquals_0(state_, TNode<Int32T>{tmp24}, TNode<Int32T>{tmp25});
    ca_.Branch(tmp26, &block5, &block6, tmp18, tmp19, tmp20, tmp21, tmp22, ca_.Uninitialized<Map>(), tmp23, ca_.Uninitialized<Context>());
  }

  if (block5.is_used()) {
    TNode<Context> tmp27;
    TNode<JSPromise> tmp28;
    TNode<HeapObject> tmp29;
    TNode<HeapObject> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Map> tmp32;
    TNode<HeapObject> tmp33;
    TNode<Context> tmp34;
    ca_.Bind(&block5, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<Map> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).PromiseFulfillReactionJobTaskMapConstant();
    TNode<Context> tmp36;
    USE(tmp36);
    tmp36 = ExtractHandlerContext_1(state_, TNode<Context>{tmp27}, TNode<HeapObject>{tmp29}, TNode<HeapObject>{tmp30});
    ca_.Goto(&block7, tmp27, tmp28, tmp29, tmp30, tmp31, tmp35, tmp29, tmp36);
  }

  if (block6.is_used()) {
    TNode<Context> tmp37;
    TNode<JSPromise> tmp38;
    TNode<HeapObject> tmp39;
    TNode<HeapObject> tmp40;
    TNode<HeapObject> tmp41;
    TNode<Map> tmp42;
    TNode<HeapObject> tmp43;
    TNode<Context> tmp44;
    ca_.Bind(&block6, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<Map> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).PromiseRejectReactionJobTaskMapConstant();
    TNode<Context> tmp46;
    USE(tmp46);
    tmp46 = ExtractHandlerContext_1(state_, TNode<Context>{tmp37}, TNode<HeapObject>{tmp40}, TNode<HeapObject>{tmp39});
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{tmp38});
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp47});
    ca_.Branch(tmp48, &block12, &block13, tmp37, tmp38, tmp39, tmp40, tmp41, tmp45, tmp40, tmp46);
  }

  if (block11.is_used()) {
    TNode<Context> tmp49;
    TNode<JSPromise> tmp50;
    TNode<HeapObject> tmp51;
    TNode<HeapObject> tmp52;
    TNode<HeapObject> tmp53;
    TNode<Map> tmp54;
    TNode<HeapObject> tmp55;
    TNode<Context> tmp56;
    ca_.Bind(&block11, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    CodeStubAssembler(state_).FailAssert("Torque assert 'promise.Status() == PromiseState::kRejected' failed", "src/builtins/promise-abstract-operations.tq", 434);
  }

  if (block10.is_used()) {
    TNode<Context> tmp57;
    TNode<JSPromise> tmp58;
    TNode<HeapObject> tmp59;
    TNode<HeapObject> tmp60;
    TNode<HeapObject> tmp61;
    TNode<Map> tmp62;
    TNode<HeapObject> tmp63;
    TNode<Context> tmp64;
    ca_.Bind(&block10, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
  }

  if (block12.is_used()) {
    TNode<Context> tmp65;
    TNode<JSPromise> tmp66;
    TNode<HeapObject> tmp67;
    TNode<HeapObject> tmp68;
    TNode<HeapObject> tmp69;
    TNode<Map> tmp70;
    TNode<HeapObject> tmp71;
    TNode<Context> tmp72;
    ca_.Bind(&block12, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<Object> tmp73;
    tmp73 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRevokeReject, tmp65, tmp66); 
    USE(tmp73);
    ca_.Goto(&block13, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72);
  }

  if (block13.is_used()) {
    TNode<Context> tmp74;
    TNode<JSPromise> tmp75;
    TNode<HeapObject> tmp76;
    TNode<HeapObject> tmp77;
    TNode<HeapObject> tmp78;
    TNode<Map> tmp79;
    TNode<HeapObject> tmp80;
    TNode<Context> tmp81;
    ca_.Bind(&block13, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    ca_.Goto(&block7, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81);
  }

  if (block7.is_used()) {
    TNode<Context> tmp82;
    TNode<JSPromise> tmp83;
    TNode<HeapObject> tmp84;
    TNode<HeapObject> tmp85;
    TNode<HeapObject> tmp86;
    TNode<Map> tmp87;
    TNode<HeapObject> tmp88;
    TNode<Context> tmp89;
    ca_.Bind(&block7, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<IntPtrT> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp91 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp83, tmp90});
    TNode<PromiseReactionJobTask> tmp92;
    USE(tmp92);
    tmp92 = NewPromiseReactionJobTask_0(state_, TNode<Context>{tmp82}, TNode<Map>{tmp87}, TNode<Context>{tmp89}, TNode<Object>{tmp91}, TNode<HeapObject>{tmp88}, TNode<HeapObject>{tmp86});
    TNode<Oddball> tmp93;
    tmp93 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp89, tmp92));
    USE(tmp93);
    ca_.Goto(&block4, tmp82, tmp83, tmp84, tmp85, tmp86);
  }

  if (block4.is_used()) {
    TNode<Context> tmp94;
    TNode<JSPromise> tmp95;
    TNode<HeapObject> tmp96;
    TNode<HeapObject> tmp97;
    TNode<HeapObject> tmp98;
    ca_.Bind(&block4, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    Method_JSPromise_SetHasHandler_0(state_, TNode<JSPromise>{tmp95});
    ca_.Goto(&block14, tmp94, tmp95, tmp96, tmp97, tmp98);
  }

    TNode<Context> tmp99;
    TNode<JSPromise> tmp100;
    TNode<HeapObject> tmp101;
    TNode<HeapObject> tmp102;
    TNode<HeapObject> tmp103;
    ca_.Bind(&block14, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
}

TF_BUILTIN(PerformPromiseThen, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<HeapObject> parameter2 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<HeapObject> parameter3 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<HeapObject> parameter4 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<Context, JSPromise, HeapObject, HeapObject, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSPromise> tmp1;
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    PerformPromiseThenImpl_0(state_, TNode<Context>{tmp0}, TNode<JSPromise>{tmp1}, TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp3}, TNode<HeapObject>{tmp4});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseReject, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSReceiver, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSReceiver, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kCalledOnNonObject, "PromiseReject");
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<NativeContext> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    TNode<Object> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp9}, TNode<IntPtrT>{tmp15});
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp16}, TNode<HeapObject>{tmp14});
    ca_.Branch(tmp17, &block5, &block6, tmp9, tmp10, tmp11, tmp14, tmp16);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<Object> tmp22;
    ca_.Bind(&block5, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<JSPromise> tmp23;
    USE(tmp23);
    tmp23 = NewJSPromise_2(state_, TNode<Context>{tmp18}, Promise::PromiseState::kRejected, TNode<Object>{tmp20});
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectEventFromStack, tmp18, tmp23, tmp20); 
    USE(tmp24);
    CodeStubAssembler(state_).Return(tmp23);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block6, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<Oddball> tmp30;
    USE(tmp30);
    tmp30 = True_0(state_);
    TNode<PromiseCapability> tmp31;
    tmp31 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, tmp25, tmp28, tmp30));
    USE(tmp31);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp33 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp31, tmp32});
    TNode<JSReceiver> tmp34;
    USE(tmp34);
    tmp34 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp25}, TNode<Object>{tmp33});
    TNode<Oddball> tmp35;
    USE(tmp35);
    tmp35 = Undefined_0(state_);
    TNode<Object> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).Call(TNode<Context>{tmp25}, TNode<Object>{tmp34}, TNode<Object>{tmp35}, TNode<Object>{tmp27});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<HeapObject>tmp38 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp31, tmp37});
    CodeStubAssembler(state_).Return(tmp38);
  }
}

TF_BUILTIN(PromiseGetCapabilitiesExecutor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kResolve));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kReject));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, PromiseCapability, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, PromiseCapability, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, PromiseCapability, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, PromiseCapability> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, PromiseCapability> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kCapabilitySlot);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp4});
    TNode<PromiseCapability> tmp6;
    USE(tmp6);
    tmp6 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Object>tmp8 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Undefined_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp6, tmp10);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<PromiseCapability> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<PromiseCapability> tmp22;
    TNode<BoolT> tmp23;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Object>tmp25 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp22, tmp24});
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = Undefined_0(state_);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp25}, TNode<HeapObject>{tmp26});
    ca_.Goto(&block5, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp27);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<PromiseCapability> tmp32;
    TNode<BoolT> tmp33;
    TNode<BoolT> tmp34;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    ca_.Branch(tmp34, &block1, &block2, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<PromiseCapability> tmp39;
    ca_.Bind(&block1, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp35}, MessageTemplate::kPromiseExecutorAlreadyInvoked);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<PromiseCapability> tmp44;
    ca_.Bind(&block2, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<IntPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp44, tmp45}, tmp42);
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp44, tmp46}, tmp43);
    TNode<Oddball> tmp47;
    USE(tmp47);
    tmp47 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp47);
  }
}

TNode<Object> CallResolve_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Object> p_resolve, TNode<Object> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_constructor, p_resolve, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<JSReceiver> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Object> tmp10;
    tmp10 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, tmp6, tmp7, tmp9);
    USE(tmp10);
    ca_.Goto(&block1, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<JSReceiver> tmp15;
    USE(tmp15);
    tmp15 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp11}, TNode<Object>{tmp13});
    TNode<Object> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Call(TNode<Context>{tmp11}, TNode<Object>{tmp15}, TNode<Object>{tmp12}, TNode<Object>{tmp14});
    ca_.Goto(&block1, tmp11, tmp12, tmp13, tmp14, tmp16);
  }

  if (block1.is_used()) {
    TNode<Context> tmp17;
    TNode<JSReceiver> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block1, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block5, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

    TNode<Context> tmp22;
    TNode<JSReceiver> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
  return TNode<Object>{tmp26};
}

TF_BUILTIN(PromiseConstructorLazyDeoptContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kPromise));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kReject));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::kException));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::kResult));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, Object, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<Oddball> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_TheHole_0(state_, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp4, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp4);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Undefined_0(state_);
    TNode<Object> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Call(TNode<Context>{tmp7}, TNode<Object>{tmp10}, TNode<Object>{tmp15}, TNode<Object>{ca_.UncheckedCast<Object>(tmp13)});
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<Oddball> tmp25;
    ca_.Bind(&block3, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block1, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    ca_.Bind(&block1, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    CodeStubAssembler(state_).Return(tmp28);
  }
}

TNode<JSBoundFunction> Cast_JSBoundFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSBoundFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSBoundFunction> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSBoundFunction> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSBoundFunction_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSBoundFunction> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSBoundFunction> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSBoundFunction>{tmp20};
}

TNode<JSFunction> Cast_JSFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSFunction> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSFunction_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSFunction> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSFunction> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSFunction>{tmp22};
}

TNode<PromiseFulfillReactionJobTask> UnsafeCast_PromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseFulfillReactionJobTask> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseFulfillReactionJobTask> tmp2;
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
    TNode<PromiseFulfillReactionJobTask> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<PromiseFulfillReactionJobTask>{tmp9};
}

TNode<PromiseRejectReactionJobTask> UnsafeCast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseRejectReactionJobTask> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseRejectReactionJobTask> tmp2;
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
    TNode<PromiseRejectReactionJobTask> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<PromiseRejectReactionJobTask>{tmp9};
}

TNode<Object> UnsafeCast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = (TNode<Object>{tmp1});
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
    TNode<Object> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Object>{tmp9};
}

TNode<SharedFunctionInfo> UnsafeCast_SharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, SharedFunctionInfo> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<SharedFunctionInfo> tmp2;
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
    TNode<SharedFunctionInfo> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<SharedFunctionInfo>{tmp9};
}

TNode<JSPromise> UnsafeCast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
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
    TNode<JSPromise> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSPromise>{tmp9};
}

TNode<PromiseCapability> UnsafeCast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseCapability> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseCapability> tmp2;
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
    TNode<PromiseCapability> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<PromiseCapability>{tmp9};
}

}  // namespace internal
}  // namespace v8

