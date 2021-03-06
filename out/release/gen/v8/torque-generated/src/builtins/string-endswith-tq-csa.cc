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

TNode<Oddball> TryFastStringCompareSequence_0(compiler::CodeAssemblerState* state_, TNode<String> p_string, TNode<String> p_searchStr, TNode<UintPtrT> p_start, TNode<UintPtrT> p_searchLength, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, String, UintPtrT, UintPtrT, Oddball> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_string, p_searchStr, p_start, p_searchLength);

  if (block0.is_used()) {
    TNode<String> tmp0;
    TNode<String> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<String> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_DirectString_0(state_, TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<String> tmp5;
    TNode<String> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<String> tmp9;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<String> tmp10;
    TNode<String> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<UintPtrT> tmp13;
    TNode<String> tmp14;
    TNode<String> tmp15;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<String> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_DirectString_0(state_, TNode<HeapObject>{tmp11}, &label0);
    ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp15, tmp11, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp10, tmp11, tmp12, tmp13, tmp15, tmp11);
    }
  }

  if (block6.is_used()) {
    TNode<String> tmp17;
    TNode<String> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<String> tmp21;
    TNode<String> tmp22;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<String> tmp23;
    TNode<String> tmp24;
    TNode<UintPtrT> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<String> tmp27;
    TNode<String> tmp28;
    TNode<String> tmp29;
    ca_.Bind(&block5, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block9, tmp23, tmp24, tmp25, tmp26, tmp27, tmp29, tmp30, tmp25);
  }

  if (block9.is_used()) {
    TNode<String> tmp31;
    TNode<String> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<String> tmp35;
    TNode<String> tmp36;
    TNode<UintPtrT> tmp37;
    TNode<UintPtrT> tmp38;
    ca_.Bind(&block9, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp37}, TNode<UintPtrT>{tmp34});
    ca_.Branch(tmp39, &block7, &block8, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38);
  }

  if (block7.is_used()) {
    TNode<String> tmp40;
    TNode<String> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<UintPtrT> tmp43;
    TNode<String> tmp44;
    TNode<String> tmp45;
    TNode<UintPtrT> tmp46;
    TNode<UintPtrT> tmp47;
    ca_.Bind(&block7, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Int32T> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp45}, TNode<UintPtrT>{tmp46});
    TNode<Int32T> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp44}, TNode<UintPtrT>{tmp47});
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp48}, TNode<Int32T>{tmp49});
    ca_.Branch(tmp50, &block10, &block11, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47);
  }

  if (block10.is_used()) {
    TNode<String> tmp51;
    TNode<String> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<UintPtrT> tmp54;
    TNode<String> tmp55;
    TNode<String> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<UintPtrT> tmp58;
    ca_.Bind(&block10, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<Oddball> tmp59;
    USE(tmp59);
    tmp59 = False_0(state_);
    ca_.Goto(&block2, tmp51, tmp52, tmp53, tmp54, tmp59);
  }

  if (block11.is_used()) {
    TNode<String> tmp60;
    TNode<String> tmp61;
    TNode<UintPtrT> tmp62;
    TNode<UintPtrT> tmp63;
    TNode<String> tmp64;
    TNode<String> tmp65;
    TNode<UintPtrT> tmp66;
    TNode<UintPtrT> tmp67;
    ca_.Bind(&block11, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<UintPtrT> tmp68;
    USE(tmp68);
    tmp68 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp66}, TNode<UintPtrT>{tmp68});
    TNode<UintPtrT> tmp70;
    USE(tmp70);
    tmp70 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp67}, TNode<UintPtrT>{tmp70});
    ca_.Goto(&block9, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp69, tmp71);
  }

  if (block8.is_used()) {
    TNode<String> tmp72;
    TNode<String> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<UintPtrT> tmp75;
    TNode<String> tmp76;
    TNode<String> tmp77;
    TNode<UintPtrT> tmp78;
    TNode<UintPtrT> tmp79;
    ca_.Bind(&block8, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    TNode<Oddball> tmp80;
    USE(tmp80);
    tmp80 = True_0(state_);
    ca_.Goto(&block2, tmp72, tmp73, tmp74, tmp75, tmp80);
  }

  if (block2.is_used()) {
    TNode<String> tmp81;
    TNode<String> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<UintPtrT> tmp84;
    TNode<Oddball> tmp85;
    ca_.Bind(&block2, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    ca_.Goto(&block12, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

    TNode<String> tmp86;
    TNode<String> tmp87;
    TNode<UintPtrT> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<Oddball> tmp90;
    ca_.Bind(&block12, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
  return TNode<Oddball>{tmp90};
}

TF_BUILTIN(StringPrototypeEndsWith, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp7});
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.endsWith");
    TNode<String> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<String>{tmp9});
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = IsRegExp_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp6});
    ca_.Branch(tmp11, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp8, tmp10);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<NativeContext> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<String> tmp19;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp15}, MessageTemplate::kFirstArgumentNotRegExp, "String.prototype.endsWith");
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<String> tmp27;
    ca_.Bind(&block2, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<String> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp23}, TNode<Object>{tmp25});
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = LoadStringLengthAsUintPtr_0(state_, TNode<String>{tmp27});
    TNode<Oddball> tmp30;
    USE(tmp30);
    tmp30 = Undefined_0(state_);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp26}, TNode<HeapObject>{tmp30});
    ca_.Branch(tmp31, &block3, &block4, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp32;
    TNode<RawPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<String> tmp39;
    TNode<String> tmp40;
    TNode<UintPtrT> tmp41;
    ca_.Bind(&block3, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<UintPtrT> tmp42;
    USE(tmp42);
    tmp42 = ClampToIndexRange_0(state_, TNode<Context>{tmp35}, TNode<Object>{tmp38}, TNode<UintPtrT>{tmp41});
    ca_.Goto(&block5, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<String> tmp50;
    TNode<String> tmp51;
    TNode<UintPtrT> tmp52;
    ca_.Bind(&block4, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Goto(&block5, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp52);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp53;
    TNode<RawPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<NativeContext> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<String> tmp60;
    TNode<String> tmp61;
    TNode<UintPtrT> tmp62;
    TNode<UintPtrT> tmp63;
    ca_.Bind(&block5, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    TNode<UintPtrT> tmp64;
    USE(tmp64);
    tmp64 = LoadStringLengthAsUintPtr_0(state_, TNode<String>{tmp61});
    TNode<UintPtrT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp63}, TNode<UintPtrT>{tmp64});
    TNode<IntPtrT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp65});
    TNode<IntPtrT> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp66}, TNode<IntPtrT>{tmp67});
    ca_.Branch(tmp68, &block7, &block8, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<String> tmp76;
    TNode<String> tmp77;
    TNode<UintPtrT> tmp78;
    TNode<UintPtrT> tmp79;
    TNode<UintPtrT> tmp80;
    TNode<UintPtrT> tmp81;
    ca_.Bind(&block7, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<Oddball> tmp82;
    USE(tmp82);
    tmp82 = False_0(state_);
    arguments.PopAndReturn(tmp82);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp83;
    TNode<RawPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<NativeContext> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<Object> tmp89;
    TNode<String> tmp90;
    TNode<String> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<UintPtrT> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<UintPtrT> tmp95;
    ca_.Bind(&block8, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<Oddball> tmp96;
    USE(tmp96);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp96 = TryFastStringCompareSequence_0(state_, TNode<String>{tmp90}, TNode<String>{tmp91}, TNode<UintPtrT>{tmp95}, TNode<UintPtrT>{tmp94}, &label0);
    ca_.Goto(&block11, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp90, tmp91, tmp95, tmp94, tmp96);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp90, tmp91, tmp95, tmp94);
    }
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp97;
    TNode<RawPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<NativeContext> tmp100;
    TNode<Object> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<String> tmp104;
    TNode<String> tmp105;
    TNode<UintPtrT> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<UintPtrT> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<String> tmp110;
    TNode<String> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<UintPtrT> tmp113;
    ca_.Bind(&block12, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    TNode<Number> tmp114;
    USE(tmp114);
    tmp114 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp109});
    TNode<Oddball> tmp115;
    tmp115 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringCompareSequence, tmp100, tmp104, tmp105, tmp114)); 
    USE(tmp115);
    arguments.PopAndReturn(tmp115);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp116;
    TNode<RawPtrT> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<NativeContext> tmp119;
    TNode<Object> tmp120;
    TNode<Object> tmp121;
    TNode<Object> tmp122;
    TNode<String> tmp123;
    TNode<String> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<UintPtrT> tmp127;
    TNode<UintPtrT> tmp128;
    TNode<String> tmp129;
    TNode<String> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<Oddball> tmp133;
    ca_.Bind(&block11, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    arguments.PopAndReturn(tmp133);
  }
}

}  // namespace internal
}  // namespace v8

