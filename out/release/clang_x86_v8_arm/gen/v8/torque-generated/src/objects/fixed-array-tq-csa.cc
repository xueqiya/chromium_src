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

void StoreFixedDoubleArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Number, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Number, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_i, p_v);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<Smi> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Branch(tmp11, &block6, &block7, tmp0, tmp1, tmp2, tmp0, tmp0, tmp3, tmp7, tmp1, tmp1, tmp8, tmp0, tmp3, tmp7, tmp8, tmp8);
  }

  if (block6.is_used()) {
    TNode<FixedDoubleArray> tmp12;
    TNode<Smi> tmp13;
    TNode<Number> tmp14;
    TNode<FixedDoubleArray> tmp15;
    TNode<FixedDoubleArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<HeapObject> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp28});
    TNode<HeapObject> tmp30;
    USE(tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp22}, TNode<IntPtrT>{tmp29}).Flatten();
    TNode<Float64T> tmp32;
    USE(tmp32);
    tmp32 = Convert_float64_Number_0(state_, TNode<Number>{tmp14});
    TNode<BoolT> tmp33;
    USE(tmp33);
    TNode<Float64T> tmp34;
    USE(tmp34);
    std::tie(tmp33, tmp34) = Convert_float64_or_hole_float64_0(state_, TNode<Float64T>{tmp32}).Flatten();
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp30}, TNode<IntPtrT>{tmp31}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp33}, TNode<Float64T>{tmp34}});
    ca_.Goto(&block9, tmp12, tmp13, tmp14);
  }

  if (block7.is_used()) {
    TNode<FixedDoubleArray> tmp35;
    TNode<Smi> tmp36;
    TNode<Number> tmp37;
    TNode<FixedDoubleArray> tmp38;
    TNode<FixedDoubleArray> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    ca_.Bind(&block7, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<FixedDoubleArray> tmp50;
    TNode<Smi> tmp51;
    TNode<Number> tmp52;
    ca_.Bind(&block9, &tmp50, &tmp51, &tmp52);
}

void StoreFixedArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_a, TNode<Smi> p_i, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_i, p_v);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<Smi> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Branch(tmp11, &block6, &block7, tmp0, tmp1, tmp2, tmp0, tmp0, tmp3, tmp7, tmp1, tmp1, tmp8, tmp0, tmp3, tmp7, tmp8, tmp8);
  }

  if (block6.is_used()) {
    TNode<FixedArray> tmp12;
    TNode<Smi> tmp13;
    TNode<Object> tmp14;
    TNode<FixedArray> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<HeapObject> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp28});
    TNode<HeapObject> tmp30;
    USE(tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp22}, TNode<IntPtrT>{tmp29}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp30, tmp31}, tmp14);
    ca_.Goto(&block9, tmp12, tmp13, tmp14);
  }

  if (block7.is_used()) {
    TNode<FixedArray> tmp32;
    TNode<Smi> tmp33;
    TNode<Object> tmp34;
    TNode<FixedArray> tmp35;
    TNode<FixedArray> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Smi> tmp39;
    TNode<Smi> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<HeapObject> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    ca_.Bind(&block7, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<FixedArray> tmp47;
    TNode<Smi> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block9, &tmp47, &tmp48, &tmp49);
}

TNode<FixedArray> ExtractFixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT, FixedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_source, p_first, p_count, p_capacity);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    TNode<UintPtrT> tmp11;
    USE(tmp11);
    tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp11});
    ca_.Branch(tmp12, &block5, &block6, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0, tmp4, tmp8, tmp0, tmp4, tmp8, tmp1, tmp9, tmp1, tmp9, tmp12);
  }

  if (block5.is_used()) {
    TNode<FixedArray> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<FixedArray> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<HeapObject> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp26});
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp27});
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp29}, TNode<UintPtrT>{tmp30});
    ca_.Goto(&block7, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp31);
  }

  if (block6.is_used()) {
    TNode<FixedArray> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<FixedArray> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<BoolT> tmp47;
    ca_.Bind(&block6, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48);
  }

  if (block7.is_used()) {
    TNode<FixedArray> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<FixedArray> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<HeapObject> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<BoolT> tmp64;
    TNode<BoolT> tmp65;
    ca_.Bind(&block7, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Branch(tmp65, &block3, &block4, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block4.is_used()) {
    TNode<FixedArray> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<FixedArray> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<HeapObject> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    ca_.Bind(&block4, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<uintptr>(endIndex) <= Convert<uintptr>(this.length) && Convert<uintptr>(startIndex) <= Convert<uintptr>(endIndex)' failed", "src/builtins/torque-internal.tq", 67);
  }

  if (block3.is_used()) {
    TNode<FixedArray> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<FixedArray> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    ca_.Bind(&block3, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<IntPtrT> tmp96;
    USE(tmp96);
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp97;
    USE(tmp97);
    tmp97 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp96});
    TNode<IntPtrT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp97});
    TNode<IntPtrT> tmp99;
    USE(tmp99);
    tmp99 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp95}, TNode<IntPtrT>{tmp99});
    TNode<IntPtrT> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp100});
    TNode<Oddball> tmp102;
    USE(tmp102);
    tmp102 = TheHole_0(state_);
    TNode<Oddball> tmp103;
    USE(tmp103);
    std::tie(tmp103) = ConstantIterator_TheHole_0(state_, TNode<Oddball>{tmp102}).Flatten();
    TNode<HeapObject> tmp104;
    USE(tmp104);
    TNode<IntPtrT> tmp105;
    USE(tmp105);
    TNode<IntPtrT> tmp106;
    USE(tmp106);
    TNode<Oddball> tmp107;
    USE(tmp107);
    std::tie(tmp104, tmp105, tmp106, tmp107) = IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TorqueStructSliceIterator_Object_0{TNode<HeapObject>{tmp89}, TNode<IntPtrT>{tmp98}, TNode<IntPtrT>{tmp101}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp103}}).Flatten();
    TNode<FixedArray> tmp108;
    USE(tmp108);
    tmp108 = NewFixedArray_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TNode<IntPtrT>{tmp85}, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{tmp104}, TNode<IntPtrT>{tmp105}, TNode<IntPtrT>{tmp106}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp107}}});
    ca_.Goto(&block8, tmp81, tmp82, tmp83, tmp84, tmp108);
  }

    TNode<FixedArray> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<FixedArray> tmp113;
    ca_.Bind(&block8, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
  return TNode<FixedArray>{tmp113};
}

TNode<FixedArrayBase> ExtractFixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, FixedArrayBase> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_source, p_first, p_count, p_capacity);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    TNode<UintPtrT> tmp11;
    USE(tmp11);
    tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp11});
    ca_.Branch(tmp12, &block5, &block6, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0, tmp4, tmp8, tmp0, tmp4, tmp8, tmp1, tmp9, tmp1, tmp9, tmp12);
  }

  if (block5.is_used()) {
    TNode<FixedDoubleArray> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<FixedDoubleArray> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<HeapObject> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp26});
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp27});
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp29}, TNode<UintPtrT>{tmp30});
    ca_.Goto(&block7, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp31);
  }

  if (block6.is_used()) {
    TNode<FixedDoubleArray> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<FixedDoubleArray> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<BoolT> tmp47;
    ca_.Bind(&block6, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48);
  }

  if (block7.is_used()) {
    TNode<FixedDoubleArray> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<FixedDoubleArray> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<HeapObject> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<BoolT> tmp64;
    TNode<BoolT> tmp65;
    ca_.Bind(&block7, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Branch(tmp65, &block3, &block4, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block4.is_used()) {
    TNode<FixedDoubleArray> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<FixedDoubleArray> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<HeapObject> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    ca_.Bind(&block4, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<uintptr>(endIndex) <= Convert<uintptr>(this.length) && Convert<uintptr>(startIndex) <= Convert<uintptr>(endIndex)' failed", "src/builtins/torque-internal.tq", 67);
  }

  if (block3.is_used()) {
    TNode<FixedDoubleArray> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<FixedDoubleArray> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    ca_.Bind(&block3, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<IntPtrT> tmp96;
    USE(tmp96);
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp97;
    USE(tmp97);
    tmp97 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp96});
    TNode<IntPtrT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp97});
    TNode<IntPtrT> tmp99;
    USE(tmp99);
    tmp99 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp95}, TNode<IntPtrT>{tmp99});
    TNode<IntPtrT> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp100});
    TNode<BoolT> tmp102;
    USE(tmp102);
    TNode<Float64T> tmp103;
    USE(tmp103);
    std::tie(tmp102, tmp103) = kDoubleHole_0(state_).Flatten();
    TNode<BoolT> tmp104;
    USE(tmp104);
    TNode<Float64T> tmp105;
    USE(tmp105);
    std::tie(tmp104, tmp105) = ConstantIterator_float64_or_hole_0(state_, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp102}, TNode<Float64T>{tmp103}}).Flatten();
    TNode<HeapObject> tmp106;
    USE(tmp106);
    TNode<IntPtrT> tmp107;
    USE(tmp107);
    TNode<IntPtrT> tmp108;
    USE(tmp108);
    TNode<BoolT> tmp109;
    USE(tmp109);
    TNode<Float64T> tmp110;
    USE(tmp110);
    std::tie(tmp106, tmp107, tmp108, tmp109, tmp110) = IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{tmp89}, TNode<IntPtrT>{tmp98}, TNode<IntPtrT>{tmp101}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp104}, TNode<Float64T>{tmp105}}}).Flatten();
    TNode<FixedArrayBase> tmp111;
    USE(tmp111);
    tmp111 = NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TNode<IntPtrT>{tmp85}, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{tmp106}, TNode<IntPtrT>{tmp107}, TNode<IntPtrT>{tmp108}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp109}, TNode<Float64T>{tmp110}}}});
    ca_.Goto(&block8, tmp81, tmp82, tmp83, tmp84, tmp111);
  }

    TNode<FixedDoubleArray> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<FixedArrayBase> tmp116;
    ca_.Bind(&block8, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
  return TNode<FixedArrayBase>{tmp116};
}

TNode<Smi> LoadFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<FixedArrayBase> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<FixedArrayBase> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<FixedArrayBase> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<FixedArrayBase> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakFixedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakFixedArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<WeakFixedArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<WeakFixedArray> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakFixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakFixedArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<WeakFixedArray> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<WeakFixedArray> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<WeakArrayList> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<WeakArrayList> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<WeakArrayList> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<WeakArrayList> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<WeakArrayList> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<WeakArrayList> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<WeakArrayList, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<WeakArrayList> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<WeakArrayList> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TorqueStructConstantIterator_TheHole_0 ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value);

  if (block0.is_used()) {
    TNode<Oddball> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Oddball> tmp1;
    TNode<Oddball> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp2}};
}

TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_Object_0 p_first, TorqueStructConstantIterator_TheHole_0 p_second) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_first.object, p_first.start, p_first.end, p_second.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Oddball> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Oddball> tmp7;
    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Oddball> tmp11;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
  return TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{tmp8}, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp10}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp11}}};
}

TNode<FixedArray> NewFixedArray_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length, p_it.first.object, p_it.first.start, p_it.first.end, p_it.second.value);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Oddball> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Oddball> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<FixedArray> tmp12;
    USE(tmp12);
    tmp12 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp13;
    TNode<HeapObject> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Oddball> tmp17;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Map> tmp18;
    USE(tmp18);
    tmp18 = kFixedArrayMap_0(state_);
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp13});
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp19});
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp20}, kTaggedSize);
    TNode<HeapObject> tmp23;
    USE(tmp23);
    tmp23 = Allocate_0(state_, TNode<IntPtrT>{tmp22}, TNode<Map>{tmp18});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp23, tmp24}, tmp18);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp23, tmp25}, tmp19);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp23}, TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp20}, TorqueStructUnsafe_0{}}, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{tmp14}, TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp16}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp17}}});
    TNode<FixedArray> tmp27;
    USE(tmp27);
    tmp27 = TORQUE_CAST(TNode<HeapObject>{tmp23});
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp16, tmp17, tmp27);
  }

  if (block1.is_used()) {
    TNode<IntPtrT> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Oddball> tmp32;
    TNode<FixedArray> tmp33;
    ca_.Bind(&block1, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block4, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

    TNode<IntPtrT> tmp34;
    TNode<HeapObject> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Oddball> tmp38;
    TNode<FixedArray> tmp39;
    ca_.Bind(&block4, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
  return TNode<FixedArray>{tmp39};
}

TorqueStructConstantIterator_float64_or_hole_0 ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructfloat64_or_hole_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, BoolT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value.is_hole, p_value.value);

  if (block0.is_used()) {
    TNode<BoolT> tmp0;
    TNode<Float64T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp0, tmp1);
  }

    TNode<BoolT> tmp2;
    TNode<Float64T> tmp3;
    TNode<BoolT> tmp4;
    TNode<Float64T> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp4}, TNode<Float64T>{tmp5}}};
}

TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_float64_or_hole_0 p_first, TorqueStructConstantIterator_float64_or_hole_0 p_second) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_first.object, p_first.start, p_first.end, p_second.value.is_hole, p_second.value.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<BoolT> tmp3;
    TNode<Float64T> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<HeapObject> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<BoolT> tmp8;
    TNode<Float64T> tmp9;
    TNode<HeapObject> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<BoolT> tmp13;
    TNode<Float64T> tmp14;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
  return TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp13}, TNode<Float64T>{tmp14}}}};
}

TNode<FixedArrayBase> NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, FixedArrayBase> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, FixedArrayBase> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_length, p_it.first.object, p_it.first.start, p_it.first.end, p_it.second.value.is_hole, p_it.second.value.value);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<BoolT> tmp4;
    TNode<Float64T> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp6});
    ca_.Branch(tmp7, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp8;
    TNode<HeapObject> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<BoolT> tmp12;
    TNode<Float64T> tmp13;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<FixedArray> tmp14;
    USE(tmp14);
    tmp14 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp15;
    TNode<HeapObject> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<BoolT> tmp19;
    TNode<Float64T> tmp20;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Map> tmp21;
    USE(tmp21);
    tmp21 = kFixedDoubleArrayMap_0(state_);
    TNode<Smi> tmp22;
    USE(tmp22);
    tmp22 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp15});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp23}, kDoubleSize);
    TNode<HeapObject> tmp26;
    USE(tmp26);
    tmp26 = Allocate_0(state_, TNode<IntPtrT>{tmp25}, TNode<Map>{tmp21});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp26, tmp27}, tmp21);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp26, tmp28}, tmp22);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TorqueStructSlice_float64_or_hole_0{TNode<HeapObject>{tmp26}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{tmp16}, TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp19}, TNode<Float64T>{tmp20}}}});
    TNode<FixedDoubleArray> tmp30;
    USE(tmp30);
    tmp30 = TORQUE_CAST(TNode<HeapObject>{tmp26});
    ca_.Goto(&block1, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp30);
  }

  if (block1.is_used()) {
    TNode<IntPtrT> tmp31;
    TNode<HeapObject> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<BoolT> tmp35;
    TNode<Float64T> tmp36;
    TNode<FixedArrayBase> tmp37;
    ca_.Bind(&block1, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block4, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37);
  }

    TNode<IntPtrT> tmp38;
    TNode<HeapObject> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<BoolT> tmp42;
    TNode<Float64T> tmp43;
    TNode<FixedArrayBase> tmp44;
    ca_.Bind(&block4, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
  return TNode<FixedArrayBase>{tmp44};
}

void InitializeFieldsFromIterator_Object_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructArgumentsIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.arguments.frame, p_originIterator.arguments.base, p_originIterator.arguments.length, p_originIterator.current);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<RawPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp8});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp0, tmp1, tmp9, tmp3, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<HeapObject> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp24, &block3, &block4, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<HeapObject> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<RawPtrT> tmp35;
    TNode<RawPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    ca_.Bind(&block3, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34});
    ca_.Branch(tmp39, &block9, &block10, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<HeapObject> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<RawPtrT> tmp50;
    TNode<RawPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    ca_.Bind(&block9, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    ca_.Goto(&block4, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<RawPtrT> tmp57;
    TNode<RawPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<RawPtrT> tmp64;
    TNode<RawPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    ca_.Bind(&block10, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<HeapObject> tmp68;
    USE(tmp68);
    TNode<IntPtrT> tmp69;
    USE(tmp69);
    std::tie(tmp68, tmp69) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp61}, TNode<IntPtrT>{tmp62}).Flatten();
    TNode<IntPtrT> tmp70;
    USE(tmp70);
    tmp70 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp70});
    TNode<BoolT> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp67}, TNode<IntPtrT>{tmp66});
    ca_.Branch(tmp72, &block16, &block17, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp71, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp68, tmp69);
  }

  if (block16.is_used()) {
    TNode<HeapObject> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<RawPtrT> tmp76;
    TNode<RawPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<RawPtrT> tmp83;
    TNode<RawPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<HeapObject> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    ca_.Bind(&block16, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<HeapObject> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<RawPtrT> tmp94;
    TNode<RawPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<HeapObject> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<RawPtrT> tmp101;
    TNode<RawPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<HeapObject> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<HeapObject> tmp107;
    TNode<IntPtrT> tmp108;
    ca_.Bind(&block17, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<IntPtrT> tmp109;
    USE(tmp109);
    tmp109 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp104}, TNode<IntPtrT>{tmp109});
    TNode<Object> tmp111;
    USE(tmp111);
    tmp111 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp101}, TNode<RawPtrT>{tmp102}, TNode<IntPtrT>{tmp103}}, TNode<IntPtrT>{tmp104});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp107, tmp108}, tmp111);
    ca_.Goto(&block5, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp110);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<RawPtrT> tmp115;
    TNode<RawPtrT> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<HeapObject> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<RawPtrT> tmp122;
    TNode<RawPtrT> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    ca_.Bind(&block4, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    ca_.Goto(&block18, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118);
  }

    TNode<HeapObject> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<RawPtrT> tmp129;
    TNode<RawPtrT> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<IntPtrT> tmp132;
    ca_.Bind(&block18, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132);
}

void InitializeFieldsFromIterator_Object_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterValueIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, HeapObject, IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, IntPtrT, RawPtrT, RawPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.mapped_count, p_originIterator.arguments.frame, p_originIterator.arguments.base, p_originIterator.arguments.length, p_originIterator.current);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<RawPtrT> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp9});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp0, tmp1, tmp10, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<HeapObject> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<RawPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp27, &block3, &block4, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<RawPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<HeapObject> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<RawPtrT> tmp40;
    TNode<RawPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    ca_.Bind(&block3, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    ca_.Branch(tmp44, &block9, &block10, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<RawPtrT> tmp49;
    TNode<RawPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<RawPtrT> tmp57;
    TNode<RawPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block9, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    ca_.Goto(&block4, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<RawPtrT> tmp65;
    TNode<RawPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<HeapObject> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<RawPtrT> tmp73;
    TNode<RawPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<HeapObject> tmp77;
    USE(tmp77);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    std::tie(tmp77, tmp78) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp69}, TNode<IntPtrT>{tmp70}).Flatten();
    TNode<IntPtrT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp70}, TNode<IntPtrT>{tmp79});
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{tmp72}, TNode<IntPtrT>{tmp81});
    ca_.Branch(tmp82, &block16, &block17, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp80, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp77, tmp78);
  }

  if (block16.is_used()) {
    TNode<HeapObject> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<RawPtrT> tmp87;
    TNode<RawPtrT> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<HeapObject> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<RawPtrT> tmp95;
    TNode<RawPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<HeapObject> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<HeapObject> tmp101;
    TNode<IntPtrT> tmp102;
    ca_.Bind(&block16, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    TNode<IntPtrT> tmp103;
    USE(tmp103);
    tmp103 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp103});
    TNode<Oddball> tmp105;
    USE(tmp105);
    tmp105 = TheHole_0(state_);
    ca_.Goto(&block15, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp104, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp105);
  }

  if (block17.is_used()) {
    TNode<HeapObject> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<IntPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<RawPtrT> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<HeapObject> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<RawPtrT> tmp118;
    TNode<RawPtrT> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<HeapObject> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<HeapObject> tmp124;
    TNode<IntPtrT> tmp125;
    ca_.Bind(&block17, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    TNode<BoolT> tmp126;
    USE(tmp126);
    tmp126 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp121}, TNode<IntPtrT>{tmp120});
    ca_.Branch(tmp126, &block18, &block19, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125);
  }

  if (block18.is_used()) {
    TNode<HeapObject> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<RawPtrT> tmp131;
    TNode<RawPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<HeapObject> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<RawPtrT> tmp139;
    TNode<RawPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    TNode<HeapObject> tmp143;
    TNode<IntPtrT> tmp144;
    TNode<HeapObject> tmp145;
    TNode<IntPtrT> tmp146;
    ca_.Bind(&block18, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<HeapObject> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<IntPtrT> tmp150;
    TNode<RawPtrT> tmp151;
    TNode<RawPtrT> tmp152;
    TNode<IntPtrT> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<HeapObject> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<RawPtrT> tmp159;
    TNode<RawPtrT> tmp160;
    TNode<IntPtrT> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<HeapObject> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<HeapObject> tmp165;
    TNode<IntPtrT> tmp166;
    ca_.Bind(&block19, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166);
    TNode<IntPtrT> tmp167;
    USE(tmp167);
    tmp167 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp168;
    USE(tmp168);
    tmp168 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp162}, TNode<IntPtrT>{tmp167});
    TNode<Object> tmp169;
    USE(tmp169);
    tmp169 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp159}, TNode<RawPtrT>{tmp160}, TNode<IntPtrT>{tmp161}}, TNode<IntPtrT>{tmp162});
    ca_.Goto(&block15, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp168, tmp163, tmp164, tmp165, tmp166, tmp169);
  }

  if (block15.is_used()) {
    TNode<HeapObject> tmp170;
    TNode<IntPtrT> tmp171;
    TNode<IntPtrT> tmp172;
    TNode<IntPtrT> tmp173;
    TNode<RawPtrT> tmp174;
    TNode<RawPtrT> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<HeapObject> tmp178;
    TNode<IntPtrT> tmp179;
    TNode<IntPtrT> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<RawPtrT> tmp182;
    TNode<RawPtrT> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<HeapObject> tmp186;
    TNode<IntPtrT> tmp187;
    TNode<HeapObject> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<Object> tmp190;
    ca_.Bind(&block15, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp188, tmp189}, tmp190);
    ca_.Goto(&block5, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<IntPtrT> tmp193;
    TNode<IntPtrT> tmp194;
    TNode<RawPtrT> tmp195;
    TNode<RawPtrT> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<IntPtrT> tmp198;
    TNode<HeapObject> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<RawPtrT> tmp203;
    TNode<RawPtrT> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<IntPtrT> tmp206;
    ca_.Bind(&block4, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206);
    ca_.Goto(&block20, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198);
  }

    TNode<HeapObject> tmp207;
    TNode<IntPtrT> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<RawPtrT> tmp211;
    TNode<RawPtrT> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<IntPtrT> tmp214;
    ca_.Bind(&block20, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214);
}

void InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, HeapObject, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, HeapObject, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, HeapObject, IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Oddball> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.first.object, p_originIterator.first.start, p_originIterator.first.end, p_originIterator.second.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Oddball> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp8});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp0, tmp1, tmp9, tmp3, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<HeapObject> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Oddball> tmp16;
    TNode<HeapObject> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Oddball> tmp23;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp24, &block3, &block4, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<HeapObject> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Oddball> tmp31;
    TNode<HeapObject> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<HeapObject> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Oddball> tmp38;
    ca_.Bind(&block3, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34});
    ca_.Branch(tmp39, &block9, &block10, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<HeapObject> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<Oddball> tmp46;
    TNode<HeapObject> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<HeapObject> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Oddball> tmp53;
    ca_.Bind(&block9, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    ca_.Goto(&block4, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<HeapObject> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<Oddball> tmp60;
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<HeapObject> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<Oddball> tmp67;
    ca_.Bind(&block10, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<HeapObject> tmp68;
    USE(tmp68);
    TNode<IntPtrT> tmp69;
    USE(tmp69);
    std::tie(tmp68, tmp69) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp61}, TNode<IntPtrT>{tmp62}).Flatten();
    TNode<IntPtrT> tmp70;
    USE(tmp70);
    tmp70 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp70});
    TNode<BoolT> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp65}, TNode<IntPtrT>{tmp66});
    ca_.Branch(tmp72, &block20, &block21, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp71, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp68, tmp69);
  }

  if (block20.is_used()) {
    TNode<HeapObject> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<HeapObject> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<Oddball> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<HeapObject> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<Oddball> tmp86;
    TNode<HeapObject> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    ca_.Bind(&block20, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block15, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp86);
  }

  if (block21.is_used()) {
    TNode<HeapObject> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<HeapObject> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<Oddball> tmp97;
    TNode<HeapObject> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<HeapObject> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<Oddball> tmp104;
    TNode<HeapObject> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<HeapObject> tmp107;
    TNode<IntPtrT> tmp108;
    ca_.Bind(&block21, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<HeapObject> tmp109;
    USE(tmp109);
    TNode<IntPtrT> tmp110;
    USE(tmp110);
    std::tie(tmp109, tmp110) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp101}, TNode<IntPtrT>{tmp102}).Flatten();
    TNode<IntPtrT> tmp111;
    USE(tmp111);
    tmp111 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp112;
    USE(tmp112);
    tmp112 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp102}, TNode<IntPtrT>{tmp111});
    TNode<Object>tmp113 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp109, tmp110});
    ca_.Goto(&block15, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp112, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp113);
  }

  if (block15.is_used()) {
    TNode<HeapObject> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<HeapObject> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<Oddball> tmp120;
    TNode<HeapObject> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<HeapObject> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<IntPtrT> tmp126;
    TNode<Oddball> tmp127;
    TNode<HeapObject> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<HeapObject> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<Object> tmp132;
    ca_.Bind(&block15, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp130, tmp131}, tmp132);
    ca_.Goto(&block5, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<HeapObject> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<Oddball> tmp139;
    TNode<HeapObject> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    TNode<HeapObject> tmp143;
    TNode<IntPtrT> tmp144;
    TNode<IntPtrT> tmp145;
    TNode<Oddball> tmp146;
    ca_.Bind(&block4, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146);
    ca_.Goto(&block25, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139);
  }

    TNode<HeapObject> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<HeapObject> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<Oddball> tmp153;
    ca_.Bind(&block25, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153);
}

void InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_float64_or_hole_0 p_target, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, HeapObject, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, HeapObject, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, HeapObject, IntPtrT, BoolT, Float64T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, BoolT, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.first.object, p_originIterator.first.start, p_originIterator.first.end, p_originIterator.second.value.is_hole, p_originIterator.second.value.value);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<BoolT> tmp6;
    TNode<Float64T> tmp7;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp9});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp0, tmp1, tmp10, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<HeapObject> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<BoolT> tmp17;
    TNode<Float64T> tmp18;
    TNode<HeapObject> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<HeapObject> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<BoolT> tmp25;
    TNode<Float64T> tmp26;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp27, &block3, &block4, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<HeapObject> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<BoolT> tmp34;
    TNode<Float64T> tmp35;
    TNode<HeapObject> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<HeapObject> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<BoolT> tmp42;
    TNode<Float64T> tmp43;
    ca_.Bind(&block3, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    ca_.Branch(tmp44, &block9, &block10, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<HeapObject> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<BoolT> tmp51;
    TNode<Float64T> tmp52;
    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<HeapObject> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<BoolT> tmp59;
    TNode<Float64T> tmp60;
    ca_.Bind(&block9, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    ca_.Goto(&block4, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<HeapObject> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<BoolT> tmp67;
    TNode<Float64T> tmp68;
    TNode<HeapObject> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<HeapObject> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<BoolT> tmp75;
    TNode<Float64T> tmp76;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<HeapObject> tmp77;
    USE(tmp77);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    std::tie(tmp77, tmp78) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp69}, TNode<IntPtrT>{tmp70}).Flatten();
    TNode<IntPtrT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp70}, TNode<IntPtrT>{tmp79});
    TNode<BoolT> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp73}, TNode<IntPtrT>{tmp74});
    ca_.Branch(tmp81, &block20, &block21, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp80, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp77, tmp78);
  }

  if (block20.is_used()) {
    TNode<HeapObject> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<HeapObject> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<BoolT> tmp88;
    TNode<Float64T> tmp89;
    TNode<HeapObject> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<HeapObject> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<BoolT> tmp96;
    TNode<Float64T> tmp97;
    TNode<HeapObject> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<HeapObject> tmp100;
    TNode<IntPtrT> tmp101;
    ca_.Bind(&block20, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    ca_.Goto(&block15, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp96, tmp97);
  }

  if (block21.is_used()) {
    TNode<HeapObject> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<HeapObject> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<BoolT> tmp108;
    TNode<Float64T> tmp109;
    TNode<HeapObject> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<HeapObject> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<BoolT> tmp116;
    TNode<Float64T> tmp117;
    TNode<HeapObject> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<HeapObject> tmp120;
    TNode<IntPtrT> tmp121;
    ca_.Bind(&block21, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    TNode<HeapObject> tmp122;
    USE(tmp122);
    TNode<IntPtrT> tmp123;
    USE(tmp123);
    std::tie(tmp122, tmp123) = UnsafeNewReference_float64_or_hole_0(state_, TNode<HeapObject>{tmp113}, TNode<IntPtrT>{tmp114}).Flatten();
    TNode<IntPtrT> tmp124;
    USE(tmp124);
    tmp124 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp125;
    USE(tmp125);
    tmp125 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp114}, TNode<IntPtrT>{tmp124});
    TNode<BoolT> tmp126;
    USE(tmp126);
    TNode<Float64T> tmp127;
    USE(tmp127);
    std::tie(tmp126, tmp127) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp122}, TNode<IntPtrT>{tmp123}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block15, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp125, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp126, tmp127);
  }

  if (block15.is_used()) {
    TNode<HeapObject> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<HeapObject> tmp131;
    TNode<IntPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<BoolT> tmp134;
    TNode<Float64T> tmp135;
    TNode<HeapObject> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<HeapObject> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<BoolT> tmp142;
    TNode<Float64T> tmp143;
    TNode<HeapObject> tmp144;
    TNode<IntPtrT> tmp145;
    TNode<HeapObject> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<BoolT> tmp148;
    TNode<Float64T> tmp149;
    ca_.Bind(&block15, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp146}, TNode<IntPtrT>{tmp147}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp148}, TNode<Float64T>{tmp149}});
    ca_.Goto(&block5, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<HeapObject> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<BoolT> tmp156;
    TNode<Float64T> tmp157;
    TNode<HeapObject> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<IntPtrT> tmp160;
    TNode<HeapObject> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<BoolT> tmp164;
    TNode<Float64T> tmp165;
    ca_.Bind(&block4, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165);
    ca_.Goto(&block25, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157);
  }

    TNode<HeapObject> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<HeapObject> tmp169;
    TNode<IntPtrT> tmp170;
    TNode<IntPtrT> tmp171;
    TNode<BoolT> tmp172;
    TNode<Float64T> tmp173;
    ca_.Bind(&block25, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173);
}

}  // namespace internal
}  // namespace v8

