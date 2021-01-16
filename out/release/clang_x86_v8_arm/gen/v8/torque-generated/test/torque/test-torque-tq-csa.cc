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

TNode<BoolT> ElementsKindTestHelper1_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT16_ELEMENTS))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  if (block1.is_used()) {
    TNode<BoolT> tmp2;
    ca_.Bind(&block1, &tmp2);
    ca_.Goto(&block5, tmp2);
  }

    TNode<BoolT> tmp3;
    ca_.Bind(&block5, &tmp3);
  return TNode<BoolT>{tmp3};
}

bool ElementsKindTestHelper2_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return ((CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT16_ELEMENTS)));
}

void LabelTestHelper1_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(label_Label1);
  }
}

void LabelTestHelper2_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label2, compiler::TypedCodeAssemblerVariable<Smi>* label_Label2_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    *label_Label2_parameter_0 = tmp0;
    ca_.Goto(label_Label2);
  }
}

void LabelTestHelper3_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label3, compiler::TypedCodeAssemblerVariable<Oddball>* label_Label3_parameter_0, compiler::TypedCodeAssemblerVariable<Smi>* label_Label3_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = Null_0(state_);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    *label_Label3_parameter_1 = tmp1;
    *label_Label3_parameter_0 = tmp0;
    ca_.Goto(label_Label3);
  }
}

void TestConstexpr1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).IsFastElementsKind(ElementsKind::PACKED_SMI_ELEMENTS)));
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( IsFastElementsKind(ElementsKind::PACKED_SMI_ELEMENTS))' failed", "test/torque/test-torque.tq", 39);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

void TestConstexprIf_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT8_ELEMENTS);
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(ElementsKind::UINT8_ELEMENTS)' failed", "test/torque/test-torque.tq", 45);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT16_ELEMENTS);
    ca_.Branch(tmp1, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(ElementsKind::UINT16_ELEMENTS)' failed", "test/torque/test-torque.tq", 46);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT32_ELEMENTS);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!ElementsKindTestHelper1(ElementsKind::UINT32_ELEMENTS)' failed", "test/torque/test-torque.tq", 47);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestConstexprReturn_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT8_ELEMENTS)));
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT8_ELEMENTS))' failed", "test/torque/test-torque.tq", 52);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT16_ELEMENTS)));
    ca_.Branch(tmp1, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT16_ELEMENTS))' failed", "test/torque/test-torque.tq", 54);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT32_ELEMENTS)));
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT32_ELEMENTS))' failed", "test/torque/test-torque.tq", 56);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprBoolNot((ElementsKindTestHelper2_0(state_, ElementsKind::UINT32_ELEMENTS)))));
    ca_.Branch(tmp4, &block8, &block9);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( !ElementsKindTestHelper2(ElementsKind::UINT32_ELEMENTS))' failed", "test/torque/test-torque.tq", 58);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

TNode<Oddball> TestGotoLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper1_0(state_, &label0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = True_0(state_);
    ca_.Goto(&block5, tmp0);
  }

    TNode<Oddball> tmp1;
    ca_.Bind(&block5, &tmp1);
  return TNode<Oddball>{tmp1};
}

TNode<Oddball> TestGotoLabelWithOneParameter_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper2_0(state_, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, result_0_0.value());
    }
  }

  if (block4.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block4, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block5, &block6, tmp0);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block6, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 42' failed", "test/torque/test-torque.tq", 78);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp4;
    ca_.Bind(&block5, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = True_0(state_);
    ca_.Goto(&block7, tmp5);
  }

    TNode<Oddball> tmp6;
    ca_.Bind(&block7, &tmp6);
  return TNode<Oddball>{tmp6};
}

TNode<Oddball> TestGotoLabelWithTwoParameters_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::TypedCodeAssemblerVariable<Oddball> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_1(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper3_0(state_, &label0, &result_0_0, &result_0_1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, result_0_0.value(), result_0_1.value());
    }
  }

  if (block4.is_used()) {
    TNode<Oddball> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block4, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block5, &block6, tmp0, tmp1);
  }

  if (block6.is_used()) {
    TNode<Oddball> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block6, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o == Null' failed", "test/torque/test-torque.tq", 89);
  }

  if (block5.is_used()) {
    TNode<Oddball> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    ca_.Branch(tmp9, &block7, &block8, tmp6, tmp7);
  }

  if (block8.is_used()) {
    TNode<Oddball> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block8, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 7' failed", "test/torque/test-torque.tq", 90);
  }

  if (block7.is_used()) {
    TNode<Oddball> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block7, &tmp12, &tmp13);
    TNode<Oddball> tmp14;
    USE(tmp14);
    tmp14 = True_0(state_);
    ca_.Goto(&block9, tmp14);
  }

    TNode<Oddball> tmp15;
    ca_.Bind(&block9, &tmp15);
  return TNode<Oddball>{tmp15};
}

TF_BUILTIN(GenericBuiltinTest_JSAny_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

void TestBuiltinSpecialization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2;
    tmp2 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, tmp0, tmp1);
    USE(tmp2);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Null_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    ca_.Bind(&block3, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(c, 0) == Null' failed", "test/torque/test-torque.tq", 105);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    ca_.Bind(&block2, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    tmp8 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, tmp6, tmp7);
    USE(tmp8);
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Null_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block4, &block5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Context> tmp11;
    ca_.Bind(&block5, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(c, 1) == Null' failed", "test/torque/test-torque.tq", 106);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    ca_.Bind(&block4, &tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Undefined_0(state_);
    TNode<Object> tmp14;
    tmp14 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, tmp12, tmp13);
    USE(tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Undefined_0(state_);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block6, &block7, tmp12);
  }

  if (block7.is_used()) {
    TNode<Context> tmp17;
    ca_.Bind(&block7, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 107);
  }

  if (block6.is_used()) {
    TNode<Context> tmp18;
    ca_.Bind(&block6, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    TNode<Object> tmp20;
    tmp20 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, tmp18, tmp19);
    USE(tmp20);
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = Undefined_0(state_);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.Branch(tmp22, &block8, &block9, tmp18);
  }

  if (block9.is_used()) {
    TNode<Context> tmp23;
    ca_.Bind(&block9, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 108);
  }

  if (block8.is_used()) {
    TNode<Context> tmp24;
    ca_.Bind(&block8, &tmp24);
    ca_.Goto(&block10, tmp24);
  }

    TNode<Context> tmp25;
    ca_.Bind(&block10, &tmp25);
}

void LabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag, compiler::CodeAssemblerLabel* label_Label4, compiler::CodeAssemblerLabel* label_Label5) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((p_flag)) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(label_Label4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_Label5);
  }
}

TNode<BoolT> CallLabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    LabelTestHelper4_0(state_, p_flag, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  if (block1.is_used()) {
    TNode<BoolT> tmp2;
    ca_.Bind(&block1, &tmp2);
    ca_.Goto(&block8, tmp2);
  }

    TNode<BoolT> tmp3;
    ca_.Bind(&block8, &tmp3);
  return TNode<BoolT>{tmp3};
}

TNode<Oddball> TestPartiallyUnusedLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = CallLabelTestHelper4_0(state_, true);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CallLabelTestHelper4_0(state_, false);
    ca_.Branch(tmp0, &block4, &block5, tmp0, tmp1, tmp0);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp2;
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Goto(&block6, tmp2, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    TNode<BoolT> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6, tmp7, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp10;
    TNode<BoolT> tmp11;
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Branch(tmp13, &block2, &block3, tmp10, tmp11);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block2, &tmp14, &tmp15);
    TNode<Oddball> tmp16;
    USE(tmp16);
    tmp16 = True_0(state_);
    ca_.Goto(&block1, tmp16);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block3, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = False_0(state_);
    ca_.Goto(&block1, tmp19);
  }

  if (block1.is_used()) {
    TNode<Oddball> tmp20;
    ca_.Bind(&block1, &tmp20);
    ca_.Goto(&block8, tmp20);
  }

    TNode<Oddball> tmp21;
    ca_.Bind(&block8, &tmp21);
  return TNode<Oddball>{tmp21};
}

TNode<Object> GenericMacroTest_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_param2);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Object>{tmp2};
}

TNode<Object> GenericMacroTestWithLabels_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2, compiler::CodeAssemblerLabel* label_Y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_param2);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_Y);
  }

  if (block3.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<Object>{tmp8};
}

void TestMacroSpecialization_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Oddball> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Oddball, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Undefined_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block4, &block5, tmp0);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp5;
    ca_.Bind(&block5, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(0) == Undefined' failed", "test/torque/test-torque.tq", 166);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp6;
    ca_.Bind(&block4, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp7});
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Undefined_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp6);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp11;
    ca_.Bind(&block7, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(1) == Undefined' failed", "test/torque/test-torque.tq", 167);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp12;
    ca_.Bind(&block6, &tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Null_0(state_);
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp13});
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Null_0(state_);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block8, &block9, tmp12);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp17;
    ca_.Bind(&block9, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(Null) == Null' failed", "test/torque/test-torque.tq", 168);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp18;
    ca_.Bind(&block8, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = False_0(state_);
    TNode<Object> tmp20;
    USE(tmp20);
    tmp20 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp19});
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = False_0(state_);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.Branch(tmp22, &block10, &block11, tmp18);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block11, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(False) == False' failed", "test/torque/test-torque.tq", 169);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp24;
    ca_.Bind(&block10, &tmp24);
    TNode<Oddball> tmp25;
    USE(tmp25);
    tmp25 = True_0(state_);
    TNode<Object> tmp26;
    USE(tmp26);
    tmp26 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp25});
    TNode<Oddball> tmp27;
    USE(tmp27);
    tmp27 = True_0(state_);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block12, &block13, tmp24);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp29;
    ca_.Bind(&block13, &tmp29);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(True) == True' failed", "test/torque/test-torque.tq", 170);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp30;
    ca_.Bind(&block12, &tmp30);
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp32;
    USE(tmp32);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp32 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp31}, &label0);
    ca_.Goto(&block16, tmp30, tmp32);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp30);
    }
  }

  if (block17.is_used()) {
    TNode<Smi> tmp33;
    ca_.Bind(&block17, &tmp33);
    ca_.Goto(&block3);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block16, &tmp34, &tmp35);
    TNode<Oddball> tmp36;
    USE(tmp36);
    tmp36 = Undefined_0(state_);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp35}, TNode<HeapObject>{tmp36});
    ca_.Branch(tmp37, &block14, &block15, tmp34);
  }

  if (block15.is_used()) {
    TNode<Smi> tmp38;
    ca_.Bind(&block15, &tmp38);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "test/torque/test-torque.tq", 171);
  }

  if (block14.is_used()) {
    TNode<Smi> tmp39;
    ca_.Bind(&block14, &tmp39);
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp41;
    USE(tmp41);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp41 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp40}, &label0);
    ca_.Goto(&block20, tmp39, tmp41);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp39);
    }
  }

  if (block21.is_used()) {
    TNode<Smi> tmp42;
    ca_.Bind(&block21, &tmp42);
    ca_.Goto(&block3);
  }

  if (block20.is_used()) {
    TNode<Smi> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block20, &tmp43, &tmp44);
    TNode<Oddball> tmp45;
    USE(tmp45);
    tmp45 = Undefined_0(state_);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp44}, TNode<HeapObject>{tmp45});
    ca_.Branch(tmp46, &block18, &block19, tmp43);
  }

  if (block19.is_used()) {
    TNode<Smi> tmp47;
    ca_.Bind(&block19, &tmp47);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "test/torque/test-torque.tq", 172);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp48;
    ca_.Bind(&block18, &tmp48);
    TNode<Oddball> tmp49;
    USE(tmp49);
    tmp49 = False_0(state_);
    TNode<Object> tmp50;
    USE(tmp50);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp50 = GenericMacroTestWithLabels_Object_0(state_, TNode<Object>{tmp49}, &label0);
    ca_.Goto(&block24, tmp48, tmp49, tmp50);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp48, tmp49);
    }
  }

  if (block25.is_used()) {
    TNode<Smi> tmp51;
    TNode<Oddball> tmp52;
    ca_.Bind(&block25, &tmp51, &tmp52);
    ca_.Goto(&block22, tmp51);
  }

  if (block24.is_used()) {
    TNode<Smi> tmp53;
    TNode<Oddball> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block24, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block22, tmp53);
  }

  if (block22.is_used()) {
    TNode<Smi> tmp56;
    ca_.Bind(&block22, &tmp56);
    ca_.Goto(&block26);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block26);
}

TF_BUILTIN(TestHelperPlus1, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(TestHelperPlus2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TNode<Oddball> TestFunctionPointers_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<Smi> tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus1)), tmp0, tmp1)); 
    USE(tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 43);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus1)));
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<BuiltinPtr> tmp6;
    ca_.Bind(&block3, &tmp5, &tmp6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(context, 42) == 43' failed", "test/torque/test-torque.tq", 193);
  }

  if (block2.is_used()) {
    TNode<Context> tmp7;
    TNode<BuiltinPtr> tmp8;
    ca_.Bind(&block2, &tmp7, &tmp8);
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<Smi> tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus2)), tmp7, tmp9)); 
    USE(tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 44);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block4, &block5, tmp7, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus2)));
  }

  if (block5.is_used()) {
    TNode<Context> tmp13;
    TNode<BuiltinPtr> tmp14;
    ca_.Bind(&block5, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(context, 42) == 44' failed", "test/torque/test-torque.tq", 195);
  }

  if (block4.is_used()) {
    TNode<Context> tmp15;
    TNode<BuiltinPtr> tmp16;
    ca_.Bind(&block4, &tmp15, &tmp16);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = True_0(state_);
    ca_.Goto(&block6, tmp15, tmp17);
  }

    TNode<Context> tmp18;
    TNode<Oddball> tmp19;
    ca_.Bind(&block6, &tmp18, &tmp19);
  return TNode<Oddball>{tmp19};
}

TNode<Oddball> TestVariableRedeclaration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp1, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Context> tmp2;
    ca_.Bind(&block2, &tmp2);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    ca_.Bind(&block3, &tmp4);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block4, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<Int32T> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp8, &block6, &block7, tmp6, tmp7);
  }

  if (block6.is_used()) {
    TNode<Context> tmp9;
    TNode<Int32T> tmp10;
    ca_.Bind(&block6, &tmp9, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block8, tmp9, tmp10, tmp11);
  }

  if (block7.is_used()) {
    TNode<Context> tmp12;
    TNode<Int32T> tmp13;
    ca_.Bind(&block7, &tmp12, &tmp13);
    TNode<Int32T> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

  if (block8.is_used()) {
    TNode<Context> tmp15;
    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
    TNode<Oddball> tmp18;
    USE(tmp18);
    tmp18 = True_0(state_);
    ca_.Goto(&block10, tmp15, tmp18);
  }

    TNode<Context> tmp19;
    TNode<Oddball> tmp20;
    ca_.Bind(&block10, &tmp19, &tmp20);
  return TNode<Oddball>{tmp20};
}

TNode<Smi> TestTernaryOperator_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp5, tmp6);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block4, &tmp7, &tmp8);
    ca_.Branch(tmp8, &block6, &block7, tmp7, tmp8);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block6, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp9}, TNode<Smi>{tmp11});
    ca_.Goto(&block8, tmp9, tmp10, tmp12);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block7, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_Smi_constexpr_int31_0(state_, 100);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp13}, TNode<Smi>{tmp15});
    ca_.Goto(&block8, tmp13, tmp14, tmp16);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp17;
    TNode<BoolT> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block8, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block10, tmp17, tmp19);
  }

    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block10, &tmp20, &tmp21);
  return TNode<Smi>{tmp21};
}

void TestFunctionPointerToGeneric_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), tmp0, tmp1); 
    USE(tmp2);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Null_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_JSAny_0)));
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<BuiltinPtr> tmp6;
    TNode<BuiltinPtr> tmp7;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(c, 0) == Null' failed", "test/torque/test-torque.tq", 217);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<BuiltinPtr> tmp9;
    TNode<BuiltinPtr> tmp10;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp12 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), tmp9, tmp8, tmp11); 
    USE(tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Null_0(state_);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Branch(tmp14, &block4, &block5, tmp8, tmp9, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<BuiltinPtr> tmp16;
    TNode<BuiltinPtr> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(c, 1) == Null' failed", "test/torque/test-torque.tq", 218);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<BuiltinPtr> tmp19;
    TNode<BuiltinPtr> tmp20;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20);
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = Undefined_0(state_);
    TNode<Object> tmp22 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(4)).descriptor(), tmp20, tmp18, tmp21); 
    USE(tmp22);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = Undefined_0(state_);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp22}, TNode<HeapObject>{tmp23});
    ca_.Branch(tmp24, &block6, &block7, tmp18, tmp19, tmp20);
  }

  if (block7.is_used()) {
    TNode<Context> tmp25;
    TNode<BuiltinPtr> tmp26;
    TNode<BuiltinPtr> tmp27;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 219);
  }

  if (block6.is_used()) {
    TNode<Context> tmp28;
    TNode<BuiltinPtr> tmp29;
    TNode<BuiltinPtr> tmp30;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30);
    TNode<Oddball> tmp31;
    USE(tmp31);
    tmp31 = Undefined_0(state_);
    TNode<Object> tmp32 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(4)).descriptor(), tmp30, tmp28, tmp31); 
    USE(tmp32);
    TNode<Oddball> tmp33;
    USE(tmp33);
    tmp33 = Undefined_0(state_);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp32}, TNode<HeapObject>{tmp33});
    ca_.Branch(tmp34, &block8, &block9, tmp28, tmp29, tmp30);
  }

  if (block9.is_used()) {
    TNode<Context> tmp35;
    TNode<BuiltinPtr> tmp36;
    TNode<BuiltinPtr> tmp37;
    ca_.Bind(&block9, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 220);
  }

  if (block8.is_used()) {
    TNode<Context> tmp38;
    TNode<BuiltinPtr> tmp39;
    TNode<BuiltinPtr> tmp40;
    ca_.Bind(&block8, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block10, tmp38);
  }

    TNode<Context> tmp41;
    ca_.Bind(&block10, &tmp41);
}

TNode<BuiltinPtr> TestTypeAlias_0(compiler::CodeAssemblerState* state_, TNode<BuiltinPtr> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<BuiltinPtr> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<BuiltinPtr>{tmp2};
}

TNode<Oddball> TestUnsafeCast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_n);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Smi> tmp6;
    tmp6 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kTestHelperPlus1, tmp3, tmp5));
    USE(tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block4, &block5, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Number> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestHelperPlus1(context, m) == 11' failed", "test/torque/test-torque.tq", 234);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    TNode<Number> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = True_0(state_);
    ca_.Goto(&block1, tmp12, tmp13, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<Number> tmp17;
    ca_.Bind(&block3, &tmp16, &tmp17);
    TNode<Oddball> tmp18;
    USE(tmp18);
    tmp18 = False_0(state_);
    ca_.Goto(&block1, tmp16, tmp17, tmp18);
  }

  if (block1.is_used()) {
    TNode<Context> tmp19;
    TNode<Number> tmp20;
    TNode<Oddball> tmp21;
    ca_.Bind(&block1, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp19, tmp20, tmp21);
  }

    TNode<Context> tmp22;
    TNode<Number> tmp23;
    TNode<Oddball> tmp24;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24);
  return TNode<Oddball>{tmp24};
}

void TestHexLiteral_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = Convert_intptr_constexpr_int31_0(state_, 65535);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 65536);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(0xffff) + 1 == 0x10000' failed", "test/torque/test-torque.tq", 242);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_constexpr_int31_0(state_, -65535);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, -65535);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp6});
    ca_.Branch(tmp7, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(-0xffff) == -65535' failed", "test/torque/test-torque.tq", 243);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestLargeIntegerLiterals_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int32_0(state_, 1.07374e+09);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, 2.14748e+09);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Context> tmp3;
    ca_.Bind(&block2, &tmp3);
}

void TestMultilineAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block4, &block5, tmp0, tmp2);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block4, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.Goto(&block6, tmp3, tmp4, tmp6);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp7, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12);
    ca_.Branch(tmp12, &block2, &block3, tmp10);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp13;
    ca_.Bind(&block3, &tmp13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'someVeryLongVariableNameThatWillCauseLineBreaks > 0 && someVeryLongVariableNameThatWillCauseLineBreaks < 10' failed", "test/torque/test-torque.tq", 255);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp14;
    ca_.Bind(&block2, &tmp14);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
}

void TestNewlineInString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).Print("Hello, World!\n");
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

int31_t kConstexprConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 5;
}

TNode<IntPtrT> kIntptrConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
return TNode<IntPtrT>{tmp0};
}

TNode<Smi> kSmiConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
return TNode<Smi>{tmp0};
}

void TestModuleConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Int32Constant(5);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, kConstexprConst_0(state_));
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp0});
    ca_.Branch(tmp2, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kConstexprConst == Int32Constant(5)' failed", "test/torque/test-torque.tq", 271);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = kIntptrConst_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kIntptrConst == 4' failed", "test/torque/test-torque.tq", 272);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = kSmiConst_0(state_);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kSmiConst == 3' failed", "test/torque/test-torque.tq", 273);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestLocalConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp2}, TNode<Smi>{tmp1});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp3);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi + 1' failed", "test/torque/test-torque.tq", 282);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block2, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp10});
    ca_.Branch(tmp11, &block4, &block5, tmp9, tmp10, tmp10);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "test/torque/test-torque.tq", 284);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp16}, TNode<Smi>{tmp18});
    ca_.Branch(tmp19, &block6, &block7, tmp15, tmp16, tmp17);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == 4' failed", "test/torque/test-torque.tq", 285);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25);
    TNode<Smi> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp23}, TNode<Smi>{tmp26});
    ca_.Branch(tmp27, &block8, &block9, tmp23);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp28;
    ca_.Bind(&block9, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'xSmi == 3' failed", "test/torque/test-torque.tq", 287);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp29;
    ca_.Bind(&block8, &tmp29);
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp29});
    ca_.Branch(tmp31, &block10, &block11, tmp29);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp32;
    ca_.Bind(&block11, &tmp32);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "test/torque/test-torque.tq", 288);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp33;
    ca_.Bind(&block10, &tmp33);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
}

TNode<Smi> TestStruct1_0(compiler::CodeAssemblerState* state_, TorqueStructTestStructA_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Number, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i.indexes, p_i.i, p_i.k);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<Smi> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp1);
  }

    TNode<FixedArray> tmp3;
    TNode<Smi> tmp4;
    TNode<Number> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5, &tmp6);
  return TNode<Smi>{tmp6};
}

TorqueStructTestStructA_0 TestStruct2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    TNode<Number> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    ca_.Goto(&block2, tmp0, tmp2, tmp3, tmp4);
  }

    TNode<Context> tmp5;
    TNode<FixedArray> tmp6;
    TNode<Smi> tmp7;
    TNode<Number> tmp8;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp6}, TNode<Smi>{tmp7}, TNode<Number>{tmp8}};
}

TorqueStructTestStructA_0 TestStruct3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 13);
    TNode<Number> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    TNode<FixedArray> tmp5;
    USE(tmp5);
    TNode<Smi> tmp6;
    USE(tmp6);
    TNode<Number> tmp7;
    USE(tmp7);
    std::tie(tmp5, tmp6, tmp7) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = TestStruct1_0(state_, TorqueStructTestStructA_0{TNode<FixedArray>{tmp5}, TNode<Smi>{tmp6}, TNode<Number>{tmp7}});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<FixedArray> tmp10;
    USE(tmp10);
    tmp10 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp11;
    USE(tmp11);
    tmp11 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp10});
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    TNode<FixedArray> tmp14;
    USE(tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    TNode<Number> tmp16;
    USE(tmp16);
    std::tie(tmp14, tmp15, tmp16) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block2, tmp0, tmp2, tmp8, tmp8);
  }

    TNode<Context> tmp17;
    TNode<FixedArray> tmp18;
    TNode<Smi> tmp19;
    TNode<Number> tmp20;
    ca_.Bind(&block2, &tmp17, &tmp18, &tmp19, &tmp20);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp18}, TNode<Smi>{tmp19}, TNode<Number>{tmp20}};
}

TorqueStructTestStructC_0 TestStruct4_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    std::tie(tmp1, tmp2, tmp3) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<FixedArray> tmp4;
    USE(tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    TNode<Number> tmp6;
    USE(tmp6);
    std::tie(tmp4, tmp5, tmp6) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

    TNode<Context> tmp7;
    TNode<FixedArray> tmp8;
    TNode<Smi> tmp9;
    TNode<Number> tmp10;
    TNode<FixedArray> tmp11;
    TNode<Smi> tmp12;
    TNode<Number> tmp13;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
  return TorqueStructTestStructC_0{TorqueStructTestStructA_0{TNode<FixedArray>{tmp8}, TNode<Smi>{tmp9}, TNode<Number>{tmp10}}, TorqueStructTestStructA_0{TNode<FixedArray>{tmp11}, TNode<Smi>{tmp12}, TNode<Number>{tmp13}}};
}

void CallTestStructInLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    std::tie(tmp1, tmp2, tmp3) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block4, tmp0);
  }

    TNode<Context> tmp4;
    ca_.Bind(&block4, &tmp4);
}

void TestForLoop_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block84(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp7}, TNode<Smi>{tmp9});
    ca_.Goto(&block4, tmp8, tmp10);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block3, &tmp11, &tmp12);
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp11}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block6, &block7, tmp11);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp15;
    ca_.Bind(&block7, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 365);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp16;
    ca_.Bind(&block6, &tmp16);
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block10, tmp17, tmp18);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block10, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp20}, TNode<Smi>{tmp21});
    ca_.Branch(tmp22, &block8, &block9, tmp19, tmp20);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
    TNode<Smi> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp23}, TNode<Smi>{tmp24});
    TNode<Smi> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp24}, TNode<Smi>{tmp26});
    ca_.Goto(&block10, tmp25, tmp27);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp28;
    TNode<Smi> tmp29;
    ca_.Bind(&block9, &tmp28, &tmp29);
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp28}, TNode<Smi>{tmp30});
    ca_.Branch(tmp31, &block12, &block13, tmp28, tmp29);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp32;
    TNode<Smi> tmp33;
    ca_.Bind(&block13, &tmp32, &tmp33);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 370);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp34;
    TNode<Smi> tmp35;
    ca_.Bind(&block12, &tmp34, &tmp35);
    TNode<Smi> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block16, tmp36, tmp37);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp38;
    TNode<Smi> tmp39;
    ca_.Bind(&block16, &tmp38, &tmp39);
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp39}, TNode<Smi>{tmp40});
    ca_.Branch(tmp41, &block14, &block15, tmp38, tmp39);
  }

  if (block14.is_used()) {
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    ca_.Bind(&block14, &tmp42, &tmp43);
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp43}, TNode<Smi>{tmp44});
    TNode<Smi> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp42}, TNode<Smi>{tmp43});
    ca_.Goto(&block16, tmp46, tmp45);
  }

  if (block15.is_used()) {
    TNode<Smi> tmp47;
    TNode<Smi> tmp48;
    ca_.Bind(&block15, &tmp47, &tmp48);
    TNode<Smi> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp47}, TNode<Smi>{tmp49});
    ca_.Branch(tmp50, &block17, &block18, tmp47, tmp48);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp51;
    TNode<Smi> tmp52;
    ca_.Bind(&block18, &tmp51, &tmp52);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 375);
  }

  if (block17.is_used()) {
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    ca_.Bind(&block17, &tmp53, &tmp54);
    TNode<Smi> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block21, tmp55, tmp54, tmp56);
  }

  if (block21.is_used()) {
    TNode<Smi> tmp57;
    TNode<Smi> tmp58;
    TNode<Smi> tmp59;
    ca_.Bind(&block21, &tmp57, &tmp58, &tmp59);
    TNode<Smi> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp59}, TNode<Smi>{tmp60});
    ca_.Branch(tmp61, &block23, &block24, tmp57, tmp58, tmp59);
  }

  if (block23.is_used()) {
    TNode<Smi> tmp62;
    TNode<Smi> tmp63;
    TNode<Smi> tmp64;
    ca_.Bind(&block23, &tmp62, &tmp63, &tmp64);
    TNode<Smi> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp62}, TNode<Smi>{tmp65});
    ca_.Branch(tmp66, &block25, &block26, tmp62, tmp63);
  }

  if (block24.is_used()) {
    TNode<Smi> tmp67;
    TNode<Smi> tmp68;
    TNode<Smi> tmp69;
    ca_.Bind(&block24, &tmp67, &tmp68, &tmp69);
    TNode<Smi> tmp70;
    USE(tmp70);
    tmp70 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp67}, TNode<Smi>{tmp69});
    TNode<Smi> tmp71;
    USE(tmp71);
    tmp71 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp69}, TNode<Smi>{tmp71});
    ca_.Goto(&block21, tmp70, tmp68, tmp72);
  }

  if (block26.is_used()) {
    TNode<Smi> tmp73;
    TNode<Smi> tmp74;
    ca_.Bind(&block26, &tmp73, &tmp74);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 383);
  }

  if (block25.is_used()) {
    TNode<Smi> tmp75;
    TNode<Smi> tmp76;
    ca_.Bind(&block25, &tmp75, &tmp76);
    TNode<Smi> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block29, tmp77, tmp78);
  }

  if (block29.is_used()) {
    TNode<Smi> tmp79;
    TNode<Smi> tmp80;
    ca_.Bind(&block29, &tmp79, &tmp80);
    TNode<Smi> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp80}, TNode<Smi>{tmp81});
    ca_.Branch(tmp82, &block30, &block31, tmp79, tmp80);
  }

  if (block30.is_used()) {
    TNode<Smi> tmp83;
    TNode<Smi> tmp84;
    ca_.Bind(&block30, &tmp83, &tmp84);
    TNode<Smi> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp83}, TNode<Smi>{tmp85});
    ca_.Branch(tmp86, &block32, &block33, tmp83, tmp84);
  }

  if (block31.is_used()) {
    TNode<Smi> tmp87;
    TNode<Smi> tmp88;
    ca_.Bind(&block31, &tmp87, &tmp88);
    TNode<Smi> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp87}, TNode<Smi>{tmp88});
    TNode<Smi> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp88}, TNode<Smi>{tmp90});
    ca_.Goto(&block29, tmp89, tmp91);
  }

  if (block33.is_used()) {
    TNode<Smi> tmp92;
    TNode<Smi> tmp93;
    ca_.Bind(&block33, &tmp92, &tmp93);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 392);
  }

  if (block32.is_used()) {
    TNode<Smi> tmp94;
    TNode<Smi> tmp95;
    ca_.Bind(&block32, &tmp94, &tmp95);
    TNode<Smi> tmp96;
    USE(tmp96);
    tmp96 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp97;
    USE(tmp97);
    tmp97 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block36, tmp96, tmp95, tmp97);
  }

  if (block36.is_used()) {
    TNode<Smi> tmp98;
    TNode<Smi> tmp99;
    TNode<Smi> tmp100;
    ca_.Bind(&block36, &tmp98, &tmp99, &tmp100);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp102;
    USE(tmp102);
    tmp102 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp100}, TNode<Smi>{tmp101});
    ca_.Branch(tmp102, &block34, &block35, tmp98, tmp99, tmp100);
  }

  if (block34.is_used()) {
    TNode<Smi> tmp103;
    TNode<Smi> tmp104;
    TNode<Smi> tmp105;
    ca_.Bind(&block34, &tmp103, &tmp104, &tmp105);
    TNode<Smi> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp105}, TNode<Smi>{tmp106});
    ca_.Branch(tmp107, &block38, &block39, tmp103, tmp104, tmp105);
  }

  if (block38.is_used()) {
    TNode<Smi> tmp108;
    TNode<Smi> tmp109;
    TNode<Smi> tmp110;
    ca_.Bind(&block38, &tmp108, &tmp109, &tmp110);
    ca_.Goto(&block37, tmp108, tmp109, tmp110);
  }

  if (block39.is_used()) {
    TNode<Smi> tmp111;
    TNode<Smi> tmp112;
    TNode<Smi> tmp113;
    ca_.Bind(&block39, &tmp111, &tmp112, &tmp113);
    TNode<Smi> tmp114;
    USE(tmp114);
    tmp114 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp111}, TNode<Smi>{tmp113});
    ca_.Goto(&block37, tmp114, tmp112, tmp113);
  }

  if (block37.is_used()) {
    TNode<Smi> tmp115;
    TNode<Smi> tmp116;
    TNode<Smi> tmp117;
    ca_.Bind(&block37, &tmp115, &tmp116, &tmp117);
    TNode<Smi> tmp118;
    USE(tmp118);
    tmp118 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp117}, TNode<Smi>{tmp118});
    ca_.Goto(&block36, tmp115, tmp116, tmp119);
  }

  if (block35.is_used()) {
    TNode<Smi> tmp120;
    TNode<Smi> tmp121;
    TNode<Smi> tmp122;
    ca_.Bind(&block35, &tmp120, &tmp121, &tmp122);
    TNode<Smi> tmp123;
    USE(tmp123);
    tmp123 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp120}, TNode<Smi>{tmp123});
    ca_.Branch(tmp124, &block40, &block41, tmp120, tmp121);
  }

  if (block41.is_used()) {
    TNode<Smi> tmp125;
    TNode<Smi> tmp126;
    ca_.Bind(&block41, &tmp125, &tmp126);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 401);
  }

  if (block40.is_used()) {
    TNode<Smi> tmp127;
    TNode<Smi> tmp128;
    ca_.Bind(&block40, &tmp127, &tmp128);
    TNode<Smi> tmp129;
    USE(tmp129);
    tmp129 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp130;
    USE(tmp130);
    tmp130 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block44, tmp129, tmp130);
  }

  if (block44.is_used()) {
    TNode<Smi> tmp131;
    TNode<Smi> tmp132;
    ca_.Bind(&block44, &tmp131, &tmp132);
    TNode<Smi> tmp133;
    USE(tmp133);
    tmp133 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp132}, TNode<Smi>{tmp133});
    ca_.Branch(tmp134, &block42, &block43, tmp131, tmp132);
  }

  if (block42.is_used()) {
    TNode<Smi> tmp135;
    TNode<Smi> tmp136;
    ca_.Bind(&block42, &tmp135, &tmp136);
    TNode<Smi> tmp137;
    USE(tmp137);
    tmp137 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp138;
    USE(tmp138);
    tmp138 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp136}, TNode<Smi>{tmp137});
    ca_.Branch(tmp138, &block46, &block47, tmp135, tmp136);
  }

  if (block46.is_used()) {
    TNode<Smi> tmp139;
    TNode<Smi> tmp140;
    ca_.Bind(&block46, &tmp139, &tmp140);
    ca_.Goto(&block45, tmp139, tmp140);
  }

  if (block47.is_used()) {
    TNode<Smi> tmp141;
    TNode<Smi> tmp142;
    ca_.Bind(&block47, &tmp141, &tmp142);
    TNode<Smi> tmp143;
    USE(tmp143);
    tmp143 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp141}, TNode<Smi>{tmp142});
    ca_.Goto(&block45, tmp143, tmp142);
  }

  if (block45.is_used()) {
    TNode<Smi> tmp144;
    TNode<Smi> tmp145;
    ca_.Bind(&block45, &tmp144, &tmp145);
    TNode<Smi> tmp146;
    USE(tmp146);
    tmp146 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp147;
    USE(tmp147);
    tmp147 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp145}, TNode<Smi>{tmp146});
    ca_.Goto(&block44, tmp144, tmp147);
  }

  if (block43.is_used()) {
    TNode<Smi> tmp148;
    TNode<Smi> tmp149;
    ca_.Bind(&block43, &tmp148, &tmp149);
    TNode<Smi> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp151;
    USE(tmp151);
    tmp151 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp148}, TNode<Smi>{tmp150});
    ca_.Branch(tmp151, &block48, &block49, tmp148, tmp149);
  }

  if (block49.is_used()) {
    TNode<Smi> tmp152;
    TNode<Smi> tmp153;
    ca_.Bind(&block49, &tmp152, &tmp153);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 409);
  }

  if (block48.is_used()) {
    TNode<Smi> tmp154;
    TNode<Smi> tmp155;
    ca_.Bind(&block48, &tmp154, &tmp155);
    TNode<Smi> tmp156;
    USE(tmp156);
    tmp156 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp157;
    USE(tmp157);
    tmp157 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block52, tmp156, tmp157);
  }

  if (block52.is_used()) {
    TNode<Smi> tmp158;
    TNode<Smi> tmp159;
    ca_.Bind(&block52, &tmp158, &tmp159);
    TNode<Smi> tmp160;
    USE(tmp160);
    tmp160 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp161;
    USE(tmp161);
    tmp161 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp159}, TNode<Smi>{tmp160});
    ca_.Branch(tmp161, &block50, &block51, tmp158, tmp159);
  }

  if (block50.is_used()) {
    TNode<Smi> tmp162;
    TNode<Smi> tmp163;
    ca_.Bind(&block50, &tmp162, &tmp163);
    TNode<Smi> tmp164;
    USE(tmp164);
    tmp164 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp163}, TNode<Smi>{tmp164});
    ca_.Branch(tmp165, &block53, &block54, tmp162, tmp163);
  }

  if (block53.is_used()) {
    TNode<Smi> tmp166;
    TNode<Smi> tmp167;
    ca_.Bind(&block53, &tmp166, &tmp167);
    TNode<Smi> tmp168;
    USE(tmp168);
    tmp168 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp169;
    USE(tmp169);
    tmp169 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp167}, TNode<Smi>{tmp168});
    ca_.Goto(&block52, tmp166, tmp169);
  }

  if (block54.is_used()) {
    TNode<Smi> tmp170;
    TNode<Smi> tmp171;
    ca_.Bind(&block54, &tmp170, &tmp171);
    TNode<Smi> tmp172;
    USE(tmp172);
    tmp172 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp170}, TNode<Smi>{tmp171});
    TNode<Smi> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp174;
    USE(tmp174);
    tmp174 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp171}, TNode<Smi>{tmp173});
    ca_.Goto(&block52, tmp172, tmp174);
  }

  if (block51.is_used()) {
    TNode<Smi> tmp175;
    TNode<Smi> tmp176;
    ca_.Bind(&block51, &tmp175, &tmp176);
    TNode<Smi> tmp177;
    USE(tmp177);
    tmp177 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp175}, TNode<Smi>{tmp177});
    ca_.Branch(tmp178, &block55, &block56, tmp175, tmp176);
  }

  if (block56.is_used()) {
    TNode<Smi> tmp179;
    TNode<Smi> tmp180;
    ca_.Bind(&block56, &tmp179, &tmp180);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 421);
  }

  if (block55.is_used()) {
    TNode<Smi> tmp181;
    TNode<Smi> tmp182;
    ca_.Bind(&block55, &tmp181, &tmp182);
    TNode<Smi> tmp183;
    USE(tmp183);
    tmp183 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp184;
    USE(tmp184);
    tmp184 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block59, tmp183, tmp182, tmp184);
  }

  if (block59.is_used()) {
    TNode<Smi> tmp185;
    TNode<Smi> tmp186;
    TNode<Smi> tmp187;
    ca_.Bind(&block59, &tmp185, &tmp186, &tmp187);
    TNode<Smi> tmp188;
    USE(tmp188);
    tmp188 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp189;
    USE(tmp189);
    tmp189 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp187}, TNode<Smi>{tmp188});
    ca_.Branch(tmp189, &block61, &block62, tmp185, tmp186, tmp187);
  }

  if (block61.is_used()) {
    TNode<Smi> tmp190;
    TNode<Smi> tmp191;
    TNode<Smi> tmp192;
    ca_.Bind(&block61, &tmp190, &tmp191, &tmp192);
    ca_.Goto(&block60, tmp190, tmp191, tmp192);
  }

  if (block62.is_used()) {
    TNode<Smi> tmp193;
    TNode<Smi> tmp194;
    TNode<Smi> tmp195;
    ca_.Bind(&block62, &tmp193, &tmp194, &tmp195);
    TNode<Smi> tmp196;
    USE(tmp196);
    tmp196 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp197;
    USE(tmp197);
    tmp197 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp195}, TNode<Smi>{tmp196});
    ca_.Branch(tmp197, &block63, &block64, tmp193, tmp194, tmp195);
  }

  if (block63.is_used()) {
    TNode<Smi> tmp198;
    TNode<Smi> tmp199;
    TNode<Smi> tmp200;
    ca_.Bind(&block63, &tmp198, &tmp199, &tmp200);
    TNode<Smi> tmp201;
    USE(tmp201);
    tmp201 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp202;
    USE(tmp202);
    tmp202 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp198}, TNode<Smi>{tmp201});
    ca_.Branch(tmp202, &block65, &block66, tmp198, tmp199);
  }

  if (block64.is_used()) {
    TNode<Smi> tmp203;
    TNode<Smi> tmp204;
    TNode<Smi> tmp205;
    ca_.Bind(&block64, &tmp203, &tmp204, &tmp205);
    TNode<Smi> tmp206;
    USE(tmp206);
    tmp206 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp203}, TNode<Smi>{tmp205});
    ca_.Goto(&block60, tmp206, tmp204, tmp205);
  }

  if (block60.is_used()) {
    TNode<Smi> tmp207;
    TNode<Smi> tmp208;
    TNode<Smi> tmp209;
    ca_.Bind(&block60, &tmp207, &tmp208, &tmp209);
    TNode<Smi> tmp210;
    USE(tmp210);
    tmp210 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp211;
    USE(tmp211);
    tmp211 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp209}, TNode<Smi>{tmp210});
    ca_.Goto(&block59, tmp207, tmp208, tmp211);
  }

  if (block66.is_used()) {
    TNode<Smi> tmp212;
    TNode<Smi> tmp213;
    ca_.Bind(&block66, &tmp212, &tmp213);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 429);
  }

  if (block65.is_used()) {
    TNode<Smi> tmp214;
    TNode<Smi> tmp215;
    ca_.Bind(&block65, &tmp214, &tmp215);
    TNode<Smi> tmp216;
    USE(tmp216);
    tmp216 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp217;
    USE(tmp217);
    tmp217 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block69, tmp216, tmp217);
  }

  if (block69.is_used()) {
    TNode<Smi> tmp218;
    TNode<Smi> tmp219;
    ca_.Bind(&block69, &tmp218, &tmp219);
    TNode<Smi> tmp220;
    USE(tmp220);
    tmp220 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp221;
    USE(tmp221);
    tmp221 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp219}, TNode<Smi>{tmp220});
    ca_.Branch(tmp221, &block70, &block71, tmp218, tmp219);
  }

  if (block70.is_used()) {
    TNode<Smi> tmp222;
    TNode<Smi> tmp223;
    ca_.Bind(&block70, &tmp222, &tmp223);
    TNode<Smi> tmp224;
    USE(tmp224);
    tmp224 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp225;
    USE(tmp225);
    tmp225 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp223}, TNode<Smi>{tmp224});
    ca_.Goto(&block69, tmp222, tmp225);
  }

  if (block71.is_used()) {
    TNode<Smi> tmp226;
    TNode<Smi> tmp227;
    ca_.Bind(&block71, &tmp226, &tmp227);
    TNode<Smi> tmp228;
    USE(tmp228);
    tmp228 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp229;
    USE(tmp229);
    tmp229 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp227}, TNode<Smi>{tmp228});
    ca_.Branch(tmp229, &block72, &block73, tmp226, tmp227);
  }

  if (block72.is_used()) {
    TNode<Smi> tmp230;
    TNode<Smi> tmp231;
    ca_.Bind(&block72, &tmp230, &tmp231);
    TNode<Smi> tmp232;
    USE(tmp232);
    tmp232 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp233;
    USE(tmp233);
    tmp233 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp230}, TNode<Smi>{tmp232});
    ca_.Branch(tmp233, &block74, &block75, tmp230, tmp231);
  }

  if (block73.is_used()) {
    TNode<Smi> tmp234;
    TNode<Smi> tmp235;
    ca_.Bind(&block73, &tmp234, &tmp235);
    TNode<Smi> tmp236;
    USE(tmp236);
    tmp236 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp234}, TNode<Smi>{tmp235});
    TNode<Smi> tmp237;
    USE(tmp237);
    tmp237 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp238;
    USE(tmp238);
    tmp238 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp235}, TNode<Smi>{tmp237});
    ca_.Goto(&block69, tmp236, tmp238);
  }

  if (block75.is_used()) {
    TNode<Smi> tmp239;
    TNode<Smi> tmp240;
    ca_.Bind(&block75, &tmp239, &tmp240);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 443);
  }

  if (block74.is_used()) {
    TNode<Smi> tmp241;
    TNode<Smi> tmp242;
    ca_.Bind(&block74, &tmp241, &tmp242);
    TNode<Smi> tmp243;
    USE(tmp243);
    tmp243 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block80, tmp241, tmp243);
  }

  if (block80.is_used()) {
    TNode<Smi> tmp244;
    TNode<Smi> tmp245;
    ca_.Bind(&block80, &tmp244, &tmp245);
    TNode<Smi> tmp246;
    USE(tmp246);
    tmp246 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp247;
    USE(tmp247);
    tmp247 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp245}, TNode<Smi>{tmp246});
    TNode<Smi> tmp248;
    USE(tmp248);
    tmp248 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp249;
    USE(tmp249);
    tmp249 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp247}, TNode<Smi>{tmp248});
    ca_.Branch(tmp249, &block81, &block82, tmp244, tmp247);
  }

  if (block81.is_used()) {
    TNode<Smi> tmp250;
    TNode<Smi> tmp251;
    ca_.Bind(&block81, &tmp250, &tmp251);
    TNode<Smi> tmp252;
    USE(tmp252);
    tmp252 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp253;
    USE(tmp253);
    tmp253 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp251}, TNode<Smi>{tmp252});
    ca_.Branch(tmp253, &block83, &block84, tmp250, tmp251);
  }

  if (block82.is_used()) {
    TNode<Smi> tmp254;
    TNode<Smi> tmp255;
    ca_.Bind(&block82, &tmp254, &tmp255);
    ca_.Goto(&block80, tmp254, tmp255);
  }

  if (block84.is_used()) {
    TNode<Smi> tmp256;
    TNode<Smi> tmp257;
    ca_.Bind(&block84, &tmp256, &tmp257);
    CodeStubAssembler(state_).FailAssert("Torque assert 'j == 10' failed", "test/torque/test-torque.tq", 452);
  }

  if (block83.is_used()) {
    TNode<Smi> tmp258;
    TNode<Smi> tmp259;
    ca_.Bind(&block83, &tmp258, &tmp259);
    ca_.Goto(&block76, tmp258, tmp259);
  }

  if (block76.is_used()) {
    TNode<Smi> tmp260;
    TNode<Smi> tmp261;
    ca_.Bind(&block76, &tmp260, &tmp261);
    TNode<Smi> tmp262;
    USE(tmp262);
    tmp262 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block87, tmp260, tmp261, ca_.Uninitialized<Smi>(), tmp262);
  }

  if (block87.is_used()) {
    TNode<Smi> tmp263;
    TNode<Smi> tmp264;
    TNode<Smi> tmp265;
    TNode<Smi> tmp266;
    ca_.Bind(&block87, &tmp263, &tmp264, &tmp265, &tmp266);
    TNode<Smi> tmp267;
    USE(tmp267);
    tmp267 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp268;
    USE(tmp268);
    tmp268 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp266}, TNode<Smi>{tmp267});
    ca_.Branch(tmp268, &block85, &block86, tmp263, tmp264, tmp265, tmp266);
  }

  if (block85.is_used()) {
    TNode<Smi> tmp269;
    TNode<Smi> tmp270;
    TNode<Smi> tmp271;
    TNode<Smi> tmp272;
    ca_.Bind(&block85, &tmp269, &tmp270, &tmp271, &tmp272);
    TNode<Smi> tmp273;
    USE(tmp273);
    tmp273 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp272}, TNode<Smi>{tmp273});
    ca_.Goto(&block87, tmp269, tmp270, tmp271, tmp274);
  }

  if (block86.is_used()) {
    TNode<Smi> tmp275;
    TNode<Smi> tmp276;
    TNode<Smi> tmp277;
    TNode<Smi> tmp278;
    ca_.Bind(&block86, &tmp275, &tmp276, &tmp277, &tmp278);
    ca_.Goto(&block89);
  }

    ca_.Bind(&block89);
}

void TestSubtyping_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Smi> tmp1;
    ca_.Bind(&block2, &tmp1);
}

TNode<Int32T> TypeswitchExample_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Context, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, HeapObject, FixedArray> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{tmp1});
    TNode<FixedArray> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_FixedArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    TNode<Int32T> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block5, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<Int32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp7}, TNode<Int32T>{tmp11});
    ca_.Goto(&block2, tmp5, tmp6, tmp12, tmp8);
  }

  if (block4.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Int32T> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Context> tmp18;
    TNode<FixedArray> tmp19;
    ca_.Bind(&block4, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<Int32T> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp15}, TNode<Int32T>{tmp20});
    ca_.Goto(&block2, tmp13, tmp14, tmp21, tmp16);
  }

  if (block2.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Int32T> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block2, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Int32T> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_int32_constexpr_int31_0(state_, 10);
    TNode<Int32T> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{tmp24}, TNode<Int32T>{tmp26});
    TNode<Object> tmp28;
    USE(tmp28);
    tmp28 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{tmp23});
    TNode<Smi> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = Cast_Smi_0(state_, TNode<Object>{tmp28}, &label0);
    ca_.Goto(&block8, tmp22, tmp23, tmp27, tmp28, tmp28, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp22, tmp23, tmp27, tmp28, tmp28);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<Int32T> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block9, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<FixedArray> tmp35;
    USE(tmp35);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp35 = Cast_FixedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp33)}, &label0);
    ca_.Goto(&block12, tmp30, tmp31, tmp32, tmp33, ca_.UncheckedCast<HeapObject>(tmp33), tmp35);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp30, tmp31, tmp32, tmp33, ca_.UncheckedCast<HeapObject>(tmp33));
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    TNode<Int32T> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<Smi> tmp41;
    ca_.Bind(&block8, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Int32T> tmp42;
    USE(tmp42);
    tmp42 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp41});
    TNode<Int32T> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp38}, TNode<Int32T>{tmp42});
    ca_.Goto(&block6, tmp36, tmp37, tmp43, tmp39);
  }

  if (block13.is_used()) {
    TNode<Context> tmp44;
    TNode<Object> tmp45;
    TNode<Int32T> tmp46;
    TNode<Object> tmp47;
    TNode<HeapObject> tmp48;
    ca_.Bind(&block13, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<Int32T> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<Int32T> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp46}, TNode<Int32T>{tmp49});
    ca_.Goto(&block10, tmp44, tmp45, tmp50, tmp47);
  }

  if (block12.is_used()) {
    TNode<Context> tmp51;
    TNode<Object> tmp52;
    TNode<Int32T> tmp53;
    TNode<Object> tmp54;
    TNode<HeapObject> tmp55;
    TNode<FixedArray> tmp56;
    ca_.Bind(&block12, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<IntPtrT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp58 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp56, tmp57});
    TNode<Int32T> tmp59;
    USE(tmp59);
    tmp59 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp58});
    TNode<Int32T> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp53}, TNode<Int32T>{tmp59});
    ca_.Goto(&block10, tmp51, tmp52, tmp60, tmp54);
  }

  if (block10.is_used()) {
    TNode<Context> tmp61;
    TNode<Object> tmp62;
    TNode<Int32T> tmp63;
    TNode<Object> tmp64;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Goto(&block6, tmp61, tmp62, tmp63, tmp64);
  }

  if (block6.is_used()) {
    TNode<Context> tmp65;
    TNode<Object> tmp66;
    TNode<Int32T> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block6, &tmp65, &tmp66, &tmp67, &tmp68);
    ca_.Goto(&block14, tmp65, tmp66, tmp67);
  }

    TNode<Context> tmp69;
    TNode<Object> tmp70;
    TNode<Int32T> tmp71;
    ca_.Bind(&block14, &tmp69, &tmp70, &tmp71);
  return TNode<Int32T>{tmp71};
}

void TestTypeswitch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = TypeswitchExample_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 26);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp2}, TNode<Int32T>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    ca_.Bind(&block3, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Smi>(5)) == 26' failed", "test/torque/test-torque.tq", 509);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    ca_.Bind(&block2, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<FixedArray> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp7});
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = TypeswitchExample_0(state_, TNode<Context>{tmp6}, TNode<Object>{tmp8});
    TNode<Int32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_int32_constexpr_int31_0(state_, 13);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block4, &block5, tmp6, tmp8);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<FixedArray> tmp13;
    ca_.Bind(&block5, &tmp12, &tmp13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(a) == 13' failed", "test/torque/test-torque.tq", 511);
  }

  if (block4.is_used()) {
    TNode<Context> tmp14;
    TNode<FixedArray> tmp15;
    ca_.Bind(&block4, &tmp14, &tmp15);
    TNode<Number> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_Number_constexpr_float64_0(state_, 0.5);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = TypeswitchExample_0(state_, TNode<Context>{tmp14}, TNode<Object>{tmp16});
    TNode<Int32T> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_int32_constexpr_int31_0(state_, 27);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp17}, TNode<Int32T>{tmp18});
    ca_.Branch(tmp19, &block6, &block7, tmp14, tmp15);
  }

  if (block7.is_used()) {
    TNode<Context> tmp20;
    TNode<FixedArray> tmp21;
    ca_.Bind(&block7, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Number>(0.5)) == 27' failed", "test/torque/test-torque.tq", 512);
  }

  if (block6.is_used()) {
    TNode<Context> tmp22;
    TNode<FixedArray> tmp23;
    ca_.Bind(&block6, &tmp22, &tmp23);
    ca_.Goto(&block8, tmp22);
  }

    TNode<Context> tmp24;
    ca_.Bind(&block8, &tmp24);
}

void TestTypeswitchAsanLsanFailure_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject, JSTypedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject, JSReceiver> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_obj);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<JSTypedArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp5)}, &label0);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5), tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5));
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block2, tmp8, tmp9, tmp10);
  }

  if (block9.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<JSReceiver> tmp17;
    USE(tmp17);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp17 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp15)}, &label0);
    ca_.Goto(&block12, tmp13, tmp14, tmp15, ca_.UncheckedCast<HeapObject>(tmp15), tmp17);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp13, tmp14, tmp15, ca_.UncheckedCast<HeapObject>(tmp15));
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<HeapObject> tmp21;
    TNode<JSTypedArray> tmp22;
    ca_.Bind(&block8, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block6, tmp18, tmp19, tmp20);
  }

  if (block13.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<HeapObject> tmp26;
    ca_.Bind(&block13, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block10, tmp23, tmp24, tmp25);
  }

  if (block12.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<HeapObject> tmp30;
    TNode<JSReceiver> tmp31;
    ca_.Bind(&block12, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    ca_.Goto(&block10, tmp27, tmp28, tmp29);
  }

  if (block10.is_used()) {
    TNode<Context> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block10, &tmp32, &tmp33, &tmp34);
    ca_.Goto(&block6, tmp32, tmp33, tmp34);
  }

  if (block6.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    ca_.Bind(&block6, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block2, tmp35, tmp36, tmp37);
  }

  if (block2.is_used()) {
    TNode<Context> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    ca_.Bind(&block2, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block14, tmp38, tmp39);
  }

    TNode<Context> tmp41;
    TNode<Object> tmp42;
    ca_.Bind(&block14, &tmp41, &tmp42);
}

void TestGenericOverload_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = ExampleGenericOverload_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<Smi> tmp6;
    TNode<Object> tmp7;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ExampleGenericOverload<Smi>(xSmi) == 6' failed", "test/torque/test-torque.tq", 540);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10);
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = ExampleGenericOverload_Object_0(state_, TNode<Object>{tmp10});
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp11});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block4, &block5, tmp8, tmp9, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Smi> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(ExampleGenericOverload<Object>(xObject)) == 5' failed", "test/torque/test-torque.tq", 541);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<Smi> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block6, tmp18);
  }

    TNode<Context> tmp21;
    ca_.Bind(&block6, &tmp21);
}

void TestEquality_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp3});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = IsNumberNotEqual_0(state_, TNode<Number>{tmp2}, TNode<Number>{tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp5);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert '!notEqual' failed", "test/torque/test-torque.tq", 548);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block2, &tmp9, &tmp10);
    TNode<Float64T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp11});
    TNode<Float64T> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp13});
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = IsNumberEqual_0(state_, TNode<Number>{tmp12}, TNode<Number>{tmp14});
    ca_.Branch(tmp15, &block4, &block5, tmp9, tmp10, tmp15);
  }

  if (block5.is_used()) {
    TNode<Context> tmp16;
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block5, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).FailAssert("Torque assert 'equal' failed", "test/torque/test-torque.tq", 551);
  }

  if (block4.is_used()) {
    TNode<Context> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    ca_.Bind(&block4, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp19);
  }

    TNode<Context> tmp22;
    ca_.Bind(&block6, &tmp22);
}

TNode<BoolT> TestOrAnd_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y, p_z);

  if (block0.is_used()) {
    TNode<BoolT> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Branch(tmp0, &block6, &block7, tmp0, tmp1, tmp2, tmp0);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    TNode<BoolT> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block7.is_used()) {
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    TNode<BoolT> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block7, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Branch(tmp9, &block9, &block10, tmp8, tmp9, tmp10, tmp11, tmp9);
  }

  if (block9.is_used()) {
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block9, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp14);
  }

  if (block10.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    ca_.Bind(&block10, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block11, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22);
  }

  if (block11.is_used()) {
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    TNode<BoolT> tmp25;
    TNode<BoolT> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block11, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block8, tmp23, tmp24, tmp25, tmp26, tmp28);
  }

  if (block8.is_used()) {
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    TNode<BoolT> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block8, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Branch(tmp33, &block2, &block3, tmp29, tmp30, tmp31);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp34;
    TNode<BoolT> tmp35;
    TNode<BoolT> tmp36;
    ca_.Bind(&block2, &tmp34, &tmp35, &tmp36);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp34, tmp35, tmp36, tmp37);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp38;
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block3, &tmp38, &tmp39, &tmp40);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp38, tmp39, tmp40, tmp41);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp42;
    TNode<BoolT> tmp43;
    TNode<BoolT> tmp44;
    TNode<BoolT> tmp45;
    ca_.Bind(&block4, &tmp42, &tmp43, &tmp44, &tmp45);
    ca_.Goto(&block12, tmp42, tmp43, tmp44, tmp45);
  }

    TNode<BoolT> tmp46;
    TNode<BoolT> tmp47;
    TNode<BoolT> tmp48;
    TNode<BoolT> tmp49;
    ca_.Bind(&block12, &tmp46, &tmp47, &tmp48, &tmp49);
  return TNode<BoolT>{tmp49};
}

TNode<BoolT> TestAndOr_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y, p_z);

  if (block0.is_used()) {
    TNode<BoolT> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Branch(tmp0, &block6, &block7, tmp0, tmp1, tmp2, tmp0);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    TNode<BoolT> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, tmp6, tmp4);
  }

  if (block7.is_used()) {
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block8.is_used()) {
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Branch(tmp16, &block9, &block10, tmp12, tmp13, tmp14, tmp16);
  }

  if (block9.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    ca_.Bind(&block9, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block10.is_used()) {
    TNode<BoolT> tmp22;
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    TNode<BoolT> tmp25;
    ca_.Bind(&block10, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block11, tmp22, tmp23, tmp24, tmp25, tmp24);
  }

  if (block11.is_used()) {
    TNode<BoolT> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    ca_.Bind(&block11, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Branch(tmp30, &block2, &block3, tmp26, tmp27, tmp28);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp31, tmp32, tmp33, tmp34);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp35;
    TNode<BoolT> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block3, &tmp35, &tmp36, &tmp37);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp35, tmp36, tmp37, tmp38);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    TNode<BoolT> tmp41;
    TNode<BoolT> tmp42;
    ca_.Bind(&block4, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block12, tmp39, tmp40, tmp41, tmp42);
  }

    TNode<BoolT> tmp43;
    TNode<BoolT> tmp44;
    TNode<BoolT> tmp45;
    TNode<BoolT> tmp46;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46);
  return TNode<BoolT>{tmp46};
}

void TestLogicalOperators_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = TestAndOr_0(state_, TNode<BoolT>{tmp0}, TNode<BoolT>{tmp1}, TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, true)' failed", "test/torque/test-torque.tq", 566);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = TestAndOr_0(state_, TNode<BoolT>{tmp4}, TNode<BoolT>{tmp5}, TNode<BoolT>{tmp6});
    ca_.Branch(tmp7, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, false)' failed", "test/torque/test-torque.tq", 567);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = TestAndOr_0(state_, TNode<BoolT>{tmp8}, TNode<BoolT>{tmp9}, TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, false, true)' failed", "test/torque/test-torque.tq", 568);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = TestAndOr_0(state_, TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13}, TNode<BoolT>{tmp14});
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp15});
    ca_.Branch(tmp16, &block8, &block9);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(true, false, false)' failed", "test/torque/test-torque.tq", 569);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = TestAndOr_0(state_, TNode<BoolT>{tmp17}, TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block10, &block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, true, true)' failed", "test/torque/test-torque.tq", 570);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = TestAndOr_0(state_, TNode<BoolT>{tmp21}, TNode<BoolT>{tmp22}, TNode<BoolT>{tmp23});
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp24});
    ca_.Branch(tmp25, &block12, &block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, true, false)' failed", "test/torque/test-torque.tq", 571);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = TestAndOr_0(state_, TNode<BoolT>{tmp26}, TNode<BoolT>{tmp27}, TNode<BoolT>{tmp28});
    ca_.Branch(tmp29, &block14, &block15);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, false, true)' failed", "test/torque/test-torque.tq", 572);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = TestAndOr_0(state_, TNode<BoolT>{tmp30}, TNode<BoolT>{tmp31}, TNode<BoolT>{tmp32});
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block16, &block17);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, false, false)' failed", "test/torque/test-torque.tq", 573);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = TestOrAnd_0(state_, TNode<BoolT>{tmp35}, TNode<BoolT>{tmp36}, TNode<BoolT>{tmp37});
    ca_.Branch(tmp38, &block18, &block19);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, true)' failed", "test/torque/test-torque.tq", 574);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = TestOrAnd_0(state_, TNode<BoolT>{tmp39}, TNode<BoolT>{tmp40}, TNode<BoolT>{tmp41});
    ca_.Branch(tmp42, &block20, &block21);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, false)' failed", "test/torque/test-torque.tq", 575);
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = TestOrAnd_0(state_, TNode<BoolT>{tmp43}, TNode<BoolT>{tmp44}, TNode<BoolT>{tmp45});
    ca_.Branch(tmp46, &block22, &block23);
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, true)' failed", "test/torque/test-torque.tq", 576);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = TestOrAnd_0(state_, TNode<BoolT>{tmp47}, TNode<BoolT>{tmp48}, TNode<BoolT>{tmp49});
    ca_.Branch(tmp50, &block24, &block25);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, false)' failed", "test/torque/test-torque.tq", 577);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = TestOrAnd_0(state_, TNode<BoolT>{tmp51}, TNode<BoolT>{tmp52}, TNode<BoolT>{tmp53});
    ca_.Branch(tmp54, &block26, &block27);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(false, true, true)' failed", "test/torque/test-torque.tq", 578);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = TestOrAnd_0(state_, TNode<BoolT>{tmp55}, TNode<BoolT>{tmp56}, TNode<BoolT>{tmp57});
    TNode<BoolT> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp58});
    ca_.Branch(tmp59, &block28, &block29);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, true, false)' failed", "test/torque/test-torque.tq", 579);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp63;
    USE(tmp63);
    tmp63 = TestOrAnd_0(state_, TNode<BoolT>{tmp60}, TNode<BoolT>{tmp61}, TNode<BoolT>{tmp62});
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp63});
    ca_.Branch(tmp64, &block30, &block31);
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, true)' failed", "test/torque/test-torque.tq", 580);
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = TestOrAnd_0(state_, TNode<BoolT>{tmp65}, TNode<BoolT>{tmp66}, TNode<BoolT>{tmp67});
    TNode<BoolT> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp68});
    ca_.Branch(tmp69, &block32, &block33);
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, false)' failed", "test/torque/test-torque.tq", 581);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.Goto(&block34);
  }

    ca_.Bind(&block34);
}

TNode<Smi> TestCall_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i, compiler::CodeAssemblerLabel* label_A) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block3, &tmp3);
    ca_.Goto(&block5, tmp3, tmp3);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_A);
  }

    TNode<Smi> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Smi>{tmp6};
}

void TestOtherwiseWithCode1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = TestCall_0(state_, TNode<Smi>{tmp2}, &label0);
    ca_.Goto(&block6, tmp0, tmp1, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp0, tmp1);
    }
  }

  if (block7.is_used()) {
    TNode<Smi> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block7, &tmp4, &tmp5);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp5}, TNode<Smi>{tmp6});
    ca_.Goto(&block2, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block2, tmp8, tmp9);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block2, &tmp11, &tmp12);
    ca_.Goto(&block12);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block11, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'v == 2' failed", "test/torque/test-torque.tq", 600);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block10, &tmp15, &tmp16);
  }

    ca_.Bind(&block12);
}

void TestOtherwiseWithCode2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = TestCall_0(state_, TNode<Smi>{tmp7}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp7, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block9, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block3, tmp9, tmp10);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    TNode<Smi> tmp15;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp12}, TNode<Smi>{tmp16});
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp13}, TNode<Smi>{tmp18});
    ca_.Goto(&block4, tmp17, tmp19);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block3, &tmp20, &tmp21);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp22;
    ca_.Bind(&block13, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 's == 5' failed", "test/torque/test-torque.tq", 610);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block12, &tmp23);
  }

    ca_.Bind(&block14);
}

void TestOtherwiseWithCode3_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = TestCall_0(state_, TNode<Smi>{tmp7}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp6, tmp7, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp6, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block9, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block3, tmp9, tmp10);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block8, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp15}, TNode<Smi>{tmp17});
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp14}, TNode<Smi>{tmp19});
    ca_.Goto(&block4, tmp18, tmp20);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block3, &tmp21, &tmp22);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block13, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 's == 10' failed", "test/torque/test-torque.tq", 619);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp24;
    ca_.Bind(&block12, &tmp24);
  }

    ca_.Bind(&block14);
}

void TestForwardLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    ca_.Goto(&block10);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp1;
    ca_.Bind(&block9, &tmp1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'b == 5' failed", "test/torque/test-torque.tq", 631);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp2;
    ca_.Bind(&block8, &tmp2);
  }

    ca_.Bind(&block10);
}

void TestQualifiedAccess_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Is_JSArray_Smi_0(state_, TNode<Context>{tmp0}, TNode<Smi>{tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block3, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Is<JSArray>(s)' failed", "test/torque/test-torque.tq", 638);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    ca_.Goto(&block4, tmp6);
  }

    TNode<Context> tmp8;
    ca_.Bind(&block4, &tmp8);
}

TNode<Smi> TestCatch1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block4, tmp0, tmp1, tmp0, catch2_exception_object);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block5, tmp3, tmp7);
  }

    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

void TestCatch2Wrapper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    TestCatch2Wrapper_0(state_, TNode<Context>{tmp0});
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block4, tmp0, tmp1, tmp0, catch2_exception_object);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block5, tmp3, tmp7);
  }

    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

void TestCatch3WrapperWithLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, compiler::CodeAssemblerLabel* label__Abort) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    TestCatch3WrapperWithLabel_0(state_, TNode<Context>{tmp0}, &label0);
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, catch2_exception_object);
    }
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block7, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block3, tmp3, tmp4, tmp6);
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<Smi> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
    TNode<Smi> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch11__label);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      TNode<Object> catch11_exception_object;
      ca_.Bind(&catch11__label, &catch11_exception_object);
      ca_.Goto(&block8, tmp7, tmp8, catch11_exception_object);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block1, tmp7, tmp10);
  }

  if (block8.is_used()) {
    TNode<Context> tmp12;
    TNode<Smi> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block3, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<Context> tmp15;
    TNode<Smi> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block1, tmp15, tmp18);
  }

  if (block1.is_used()) {
    TNode<Context> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block1, &tmp19, &tmp20);
    ca_.Goto(&block9, tmp19, tmp20);
  }

    TNode<Context> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block9, &tmp21, &tmp22);
  return TNode<Smi>{tmp22};
}

void TestIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, JSReceiver, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, JSReceiver, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, Object, JSReceiver, Object, Map, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, Object, JSReceiver, Object, Map, Context, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_map);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Map> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = IteratorBuiltinsAssembler(state_).GetIteratorMethod(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    TNode<Object> tmp5;
    USE(tmp5);
    std::tie(tmp4, tmp5) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp0}, TNode<Object>{tmp1}).Flatten();
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp5, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp5, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<Map> tmp9;
    TNode<Object> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<Object> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<Object> tmp14;
    TNode<Context> tmp15;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    ca_.Goto(&block3, tmp7, tmp8, tmp9);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<Map> tmp18;
    TNode<Object> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Object> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Object> tmp23;
    TNode<Context> tmp24;
    TNode<JSReceiver> tmp25;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<JSReceiver> tmp26;
    USE(tmp26);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp26 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp16}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp20}, TNode<Object>{tmp21}}, TNode<Map>{tmp18}, &label0);
    ca_.Goto(&block6, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp25, tmp20, tmp21, tmp18, tmp16, tmp26);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp25, tmp20, tmp21, tmp18, tmp16);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Map> tmp29;
    TNode<Object> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Object> tmp35;
    TNode<Map> tmp36;
    TNode<Context> tmp37;
    ca_.Bind(&block7, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block3, tmp27, tmp28, tmp29);
  }

  if (block6.is_used()) {
    TNode<Context> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Map> tmp40;
    TNode<Object> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<JSReceiver> tmp45;
    TNode<Object> tmp46;
    TNode<Map> tmp47;
    TNode<Context> tmp48;
    TNode<JSReceiver> tmp49;
    ca_.Bind(&block6, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Object> tmp50;
    USE(tmp50);
    tmp50 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp38}, TNode<JSReceiver>{tmp39});
    TNode<Object> tmp51;
    USE(tmp51);
    tmp51 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp38}, TNode<JSReceiver>{tmp39}, TNode<Map>{tmp40});
    TNode<JSArray> tmp52;
    USE(tmp52);
    tmp52 = IteratorBuiltinsAssembler(state_).IterableToList(TNode<Context>{tmp38}, TNode<Object>{tmp41}, TNode<Object>{tmp41});
    IteratorBuiltinsAssembler(state_).IteratorCloseOnException(TNode<Context>{tmp38}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp42}, TNode<Object>{tmp43}}, TNode<Object>{tmp50});
  }

  if (block3.is_used()) {
    TNode<Context> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<Map> tmp55;
    ca_.Bind(&block3, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block8, tmp53, tmp54, tmp55);
  }

    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<Map> tmp58;
    ca_.Bind(&block8, &tmp56, &tmp57, &tmp58);
}

void TestFrame1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context, RawPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context, RawPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<RawPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadFramePointer();
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = LoadContextOrFrameTypeFromFrame_0(state_, TNode<Context>{tmp0}, TNode<RawPtrT>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_FrameType_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<Object> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<RawPtrT> tmp11;
    USE(tmp11);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp11 = Cast_StandardFrame_0(state_, TNode<Context>{tmp7}, TNode<RawPtrT>{tmp8}, &label0);
    ca_.Goto(&block16, tmp7, tmp8, tmp10, tmp8, tmp8, tmp7, tmp11);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp7, tmp8, tmp10, tmp8, tmp8, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block9, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'frameType == STUB_FRAME' failed", "test/torque/test-torque.tq", 717);
  }

  if (block8.is_used()) {
    TNode<Context> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  }

  if (block13.is_used()) {
    TNode<Context> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block13, &tmp18, &tmp19, &tmp20);
    CodeStubAssembler(state_).FailAssert("Torque assert 'f.caller == LoadParentFramePointer()' failed", "test/torque/test-torque.tq", 718);
  }

  if (block12.is_used()) {
    TNode<Context> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block12, &tmp21, &tmp22, &tmp23);
  }

  if (block17.is_used()) {
    TNode<Context> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<Smi> tmp26;
    TNode<RawPtrT> tmp27;
    TNode<RawPtrT> tmp28;
    TNode<Context> tmp29;
    ca_.Bind(&block17, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<RawPtrT> tmp30;
    USE(tmp30);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp30 = Cast_ArgumentsAdaptorFrame_0(state_, TNode<Context>{tmp24}, TNode<RawPtrT>{ca_.UncheckedCast<RawPtrT>(tmp27)}, &label0);
    ca_.Goto(&block20, tmp24, tmp25, tmp26, tmp27, ca_.UncheckedCast<RawPtrT>(tmp27), tmp24, tmp30);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp24, tmp25, tmp26, tmp27, ca_.UncheckedCast<RawPtrT>(tmp27), tmp24);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<Smi> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<RawPtrT> tmp35;
    TNode<Context> tmp36;
    TNode<RawPtrT> tmp37;
    ca_.Bind(&block16, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block21.is_used()) {
    TNode<Context> tmp38;
    TNode<RawPtrT> tmp39;
    TNode<Smi> tmp40;
    TNode<RawPtrT> tmp41;
    TNode<RawPtrT> tmp42;
    TNode<Context> tmp43;
    ca_.Bind(&block21, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block22, tmp38);
  }

  if (block20.is_used()) {
    TNode<Context> tmp44;
    TNode<RawPtrT> tmp45;
    TNode<Smi> tmp46;
    TNode<RawPtrT> tmp47;
    TNode<RawPtrT> tmp48;
    TNode<Context> tmp49;
    TNode<RawPtrT> tmp50;
    ca_.Bind(&block20, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp51;
    ca_.Bind(&block22, &tmp51);
}

void TestNew_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSArray> tmp1;
    USE(tmp1);
    tmp1 = NewJSArray_1(state_, TNode<Context>{tmp0});
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Method_JSArray_IsEmpty_0(state_, TNode<JSArray>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<JSArray> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'f.IsEmpty()' failed", "test/torque/test-torque.tq", 734);
  }

  if (block2.is_used()) {
    TNode<Context> tmp5;
    TNode<JSArray> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<Number> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp6, tmp7}, tmp8);
    ca_.Goto(&block4, tmp5);
  }

    TNode<Context> tmp9;
    ca_.Bind(&block4, &tmp9);
}

void TestStructConstructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp3, tmp1, tmp2, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<Int32T> tmp8;
    TNode<Int32T> tmp9;
    TNode<Int32T> tmp10;
    TNode<Int32T> tmp11;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.a == 5' failed", "test/torque/test-torque.tq", 759);
  }

  if (block2.is_used()) {
    TNode<Context> tmp12;
    TNode<Int32T> tmp13;
    TNode<Int32T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp14}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block4, &block5, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp19;
    TNode<Int32T> tmp20;
    TNode<Int32T> tmp21;
    TNode<Int32T> tmp22;
    TNode<Int32T> tmp23;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 6' failed", "test/torque/test-torque.tq", 760);
  }

  if (block4.is_used()) {
    TNode<Context> tmp24;
    TNode<Int32T> tmp25;
    TNode<Int32T> tmp26;
    TNode<Int32T> tmp27;
    TNode<Int32T> tmp28;
    ca_.Bind(&block4, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Int32T> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp27}, TNode<Int32T>{tmp29});
    ca_.Branch(tmp30, &block6, &block7, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Context> tmp31;
    TNode<Int32T> tmp32;
    TNode<Int32T> tmp33;
    TNode<Int32T> tmp34;
    TNode<Int32T> tmp35;
    ca_.Bind(&block7, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.y == 7' failed", "test/torque/test-torque.tq", 761);
  }

  if (block6.is_used()) {
    TNode<Context> tmp36;
    TNode<Int32T> tmp37;
    TNode<Int32T> tmp38;
    TNode<Int32T> tmp39;
    TNode<Int32T> tmp40;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<Int32T> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp40}, TNode<Int32T>{tmp41});
    ca_.Branch(tmp42, &block8, &block9, tmp36, tmp37, tmp38, tmp39, tmp40);
  }

  if (block9.is_used()) {
    TNode<Context> tmp43;
    TNode<Int32T> tmp44;
    TNode<Int32T> tmp45;
    TNode<Int32T> tmp46;
    TNode<Int32T> tmp47;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.c == 8' failed", "test/torque/test-torque.tq", 762);
  }

  if (block8.is_used()) {
    TNode<Context> tmp48;
    TNode<Int32T> tmp49;
    TNode<Int32T> tmp50;
    TNode<Int32T> tmp51;
    TNode<Int32T> tmp52;
    ca_.Bind(&block8, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<Int32T> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp53}, TNode<Int32T>{tmp54});
    ca_.Branch(tmp55, &block10, &block11, tmp48, tmp49, tmp53, tmp51, tmp52);
  }

  if (block11.is_used()) {
    TNode<Context> tmp56;
    TNode<Int32T> tmp57;
    TNode<Int32T> tmp58;
    TNode<Int32T> tmp59;
    TNode<Int32T> tmp60;
    ca_.Bind(&block11, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 1' failed", "test/torque/test-torque.tq", 764);
  }

  if (block10.is_used()) {
    TNode<Context> tmp61;
    TNode<Int32T> tmp62;
    TNode<Int32T> tmp63;
    TNode<Int32T> tmp64;
    TNode<Int32T> tmp65;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    TNode<Int32T> tmp66;
    USE(tmp66);
    tmp66 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<Int32T> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp66}, TNode<Int32T>{tmp67});
    ca_.Branch(tmp68, &block13, &block14, tmp61, tmp62, tmp66, tmp64, tmp65);
  }

  if (block14.is_used()) {
    TNode<Context> tmp69;
    TNode<Int32T> tmp70;
    TNode<Int32T> tmp71;
    TNode<Int32T> tmp72;
    TNode<Int32T> tmp73;
    ca_.Bind(&block14, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 2' failed", "test/torque/test-torque.tq", 766);
  }

  if (block13.is_used()) {
    TNode<Context> tmp74;
    TNode<Int32T> tmp75;
    TNode<Int32T> tmp76;
    TNode<Int32T> tmp77;
    TNode<Int32T> tmp78;
    ca_.Bind(&block13, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<Int32T> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp76}, TNode<Int32T>{tmp79});
    ca_.Branch(tmp80, &block15, &block16, tmp74, tmp75, tmp76, tmp77, tmp78);
  }

  if (block16.is_used()) {
    TNode<Context> tmp81;
    TNode<Int32T> tmp82;
    TNode<Int32T> tmp83;
    TNode<Int32T> tmp84;
    TNode<Int32T> tmp85;
    ca_.Bind(&block16, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.GetX() == 2' failed", "test/torque/test-torque.tq", 767);
  }

  if (block15.is_used()) {
    TNode<Context> tmp86;
    TNode<Int32T> tmp87;
    TNode<Int32T> tmp88;
    TNode<Int32T> tmp89;
    TNode<Int32T> tmp90;
    ca_.Bind(&block15, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block18, tmp86);
  }

    TNode<Context> tmp91;
    ca_.Bind(&block18, &tmp91);
}

TNode<InternalClass> NewInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, InternalClass> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).GetStructMap(INTERNAL_CLASS_TYPE);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
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
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp0);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp5, tmp8}, tmp2);
    TNode<InternalClass> tmp9;
    USE(tmp9);
    tmp9 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2, tmp0, tmp9);
  }

    TNode<Smi> tmp10;
    TNode<InternalClass> tmp11;
    ca_.Bind(&block2, &tmp10, &tmp11);
  return TNode<InternalClass>{tmp11};
}

void TestInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass, InternalClass> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass, InternalClass> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<InternalClass> tmp2;
    USE(tmp2);
    tmp2 = NewInternalClass_0(state_, TNode<Smi>{tmp1});
    compiler::CodeAssemblerLabel label0(&ca_);
    Method_InternalClass_Flip_0(state_, TNode<InternalClass>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp2, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp2, tmp2);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<InternalClass> tmp4;
    TNode<InternalClass> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<InternalClass> tmp7;
    TNode<InternalClass> tmp8;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp9});
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block6, &block7, tmp6, tmp7);
  }

  if (block7.is_used()) {
    TNode<Context> tmp13;
    TNode<InternalClass> tmp14;
    ca_.Bind(&block7, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.a == 6' failed", "test/torque/test-torque.tq", 788);
  }

  if (block6.is_used()) {
    TNode<Context> tmp15;
    TNode<InternalClass> tmp16;
    ca_.Bind(&block6, &tmp15, &tmp16);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Number>tmp18 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp16, tmp17});
    TNode<Number> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = IsNumberEqual_0(state_, TNode<Number>{tmp18}, TNode<Number>{tmp19});
    ca_.Branch(tmp20, &block8, &block9, tmp15, tmp16);
  }

  if (block9.is_used()) {
    TNode<Context> tmp21;
    TNode<InternalClass> tmp22;
    ca_.Bind(&block9, &tmp21, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.b == 5' failed", "test/torque/test-torque.tq", 789);
  }

  if (block8.is_used()) {
    TNode<Context> tmp23;
    TNode<InternalClass> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
    ca_.Goto(&block10, tmp23);
  }

    TNode<Context> tmp25;
    ca_.Bind(&block10, &tmp25);
}

void TestConstInStructs_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = Null_0(state_);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp4, tmp3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Object> tmp7;
    TNode<Int32T> tmp8;
    TNode<Object> tmp9;
    TNode<Int32T> tmp10;
    TNode<Object> tmp11;
    TNode<Int32T> tmp12;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod1() == 1' failed", "test/torque/test-torque.tq", 810);
  }

  if (block2.is_used()) {
    TNode<Object> tmp13;
    TNode<Int32T> tmp14;
    TNode<Object> tmp15;
    TNode<Int32T> tmp16;
    TNode<Object> tmp17;
    TNode<Int32T> tmp18;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Null_0(state_);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp13}, TNode<HeapObject>{tmp19});
    ca_.Branch(tmp20, &block5, &block6, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block6.is_used()) {
    TNode<Object> tmp21;
    TNode<Int32T> tmp22;
    TNode<Object> tmp23;
    TNode<Int32T> tmp24;
    TNode<Object> tmp25;
    TNode<Int32T> tmp26;
    ca_.Bind(&block6, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod2() == Null' failed", "test/torque/test-torque.tq", 811);
  }

  if (block5.is_used()) {
    TNode<Object> tmp27;
    TNode<Int32T> tmp28;
    TNode<Object> tmp29;
    TNode<Int32T> tmp30;
    TNode<Object> tmp31;
    TNode<Int32T> tmp32;
    ca_.Bind(&block5, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestParentFrameArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, RawPtrT, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, RawPtrT, Context, RawPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<RawPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadParentFramePointer();
    TNode<RawPtrT> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_StandardFrame_0(state_, TNode<Context>{tmp0}, TNode<RawPtrT>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<RawPtrT> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<Context> tmp10;
    TNode<RawPtrT> tmp11;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<RawPtrT> tmp13;
    USE(tmp13);
    TNode<RawPtrT> tmp14;
    USE(tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    std::tie(tmp13, tmp14, tmp15) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp11}, TNode<IntPtrT>{tmp12}).Flatten();
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block6, tmp7);
  }

    TNode<Context> tmp17;
    ca_.Bind(&block6, &tmp17);
}

TNode<Object> TestNewFixedArrayFromSpread_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = kFixedArrayMap_0(state_);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 5);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp3}, kTaggedSize);
    TNode<HeapObject> tmp6;
    USE(tmp6);
    tmp6 = Allocate_0(state_, TNode<IntPtrT>{tmp5}, TNode<Map>{tmp2});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp6, tmp7}, tmp2);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp8}, tmp9);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_TestIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp6}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}}, TorqueStructTestIterator_0{TNode<Smi>{tmp1}});
    TNode<FixedArray> tmp11;
    USE(tmp11);
    tmp11 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    ca_.Goto(&block2, tmp0, tmp11);
  }

    TNode<Context> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block2, &tmp12, &tmp13);
  return TNode<Object>{tmp13};
}

void TestReferences_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).GetStructMap(SMI_PAIR_TYPE);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    tmp2 = Allocate_0(state_, TNode<IntPtrT>{tmp1}, TNode<Map>{tmp0});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp0);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp4}, tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp6}, tmp7);
    TNode<SmiPair> tmp8;
    USE(tmp8);
    tmp8 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9});
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp11}, TNode<Smi>{tmp10});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp12);
    TNode<Smi>tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9});
    TNode<Smi> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp13}, TNode<Smi>{tmp14});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp15);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<HeapObject> tmp17;
    USE(tmp17);
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    std::tie(tmp17, tmp18) = Method_SmiPair_GetA_0(state_, TNode<SmiPair>{tmp8}).Flatten();
    Swap_Smi_0(state_, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp8}, TNode<IntPtrT>{tmp16}, TorqueStructUnsafe_0{}}, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp17}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp19});
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp20}, TNode<Smi>{tmp21});
    ca_.Branch(tmp22, &block2, &block3, tmp8, tmp8, tmp9);
  }

  if (block3.is_used()) {
    TNode<SmiPair> tmp23;
    TNode<HeapObject> tmp24;
    TNode<IntPtrT> tmp25;
    ca_.Bind(&block3, &tmp23, &tmp24, &tmp25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.a == 2' failed", "test/torque/test-torque.tq", 857);
  }

  if (block2.is_used()) {
    TNode<SmiPair> tmp26;
    TNode<HeapObject> tmp27;
    TNode<IntPtrT> tmp28;
    ca_.Bind(&block2, &tmp26, &tmp27, &tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi>tmp30 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp26, tmp29});
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 9);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp31});
    ca_.Branch(tmp32, &block4, &block5, tmp26, tmp27, tmp28);
  }

  if (block5.is_used()) {
    TNode<SmiPair> tmp33;
    TNode<HeapObject> tmp34;
    TNode<IntPtrT> tmp35;
    ca_.Bind(&block5, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.b == 9' failed", "test/torque/test-torque.tq", 858);
  }

  if (block4.is_used()) {
    TNode<SmiPair> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    ca_.Bind(&block4, &tmp36, &tmp37, &tmp38);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestSlices_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Map> tmp1;
    USE(tmp1);
    tmp1 = kFixedArrayMap_0(state_);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = Convert_intptr_constexpr_int31_0(state_, 3);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2}, kTaggedSize);
    TNode<HeapObject> tmp5;
    USE(tmp5);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp8);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_TestIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp5}, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}}, TorqueStructTestIterator_0{TNode<Smi>{tmp0}});
    TNode<FixedArray> tmp10;
    USE(tmp10);
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp12 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp11});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block2, &block3, tmp0, tmp10);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp15;
    TNode<FixedArray> tmp16;
    ca_.Bind(&block3, &tmp15, &tmp16);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.length == 3' failed", "test/torque/test-torque.tq", 865);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp17;
    TNode<FixedArray> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = Convert_Smi_constexpr_int31_0(state_, 123);
    TNode<IntPtrT> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp23 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp26;
    USE(tmp26);
    tmp26 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp25});
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp24});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp26}, TNode<UintPtrT>{tmp27});
    ca_.Branch(tmp28, &block8, &block9, tmp17, tmp18, tmp19, tmp18, tmp18, tmp20, tmp24, tmp25, tmp18, tmp20, tmp24, tmp25, tmp25);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp29;
    TNode<FixedArray> tmp30;
    TNode<Smi> tmp31;
    TNode<FixedArray> tmp32;
    TNode<FixedArray> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block8, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp41}, TNode<IntPtrT>{tmp42});
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp43});
    TNode<HeapObject> tmp45;
    USE(tmp45);
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    std::tie(tmp45, tmp46) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp37}, TNode<IntPtrT>{tmp44}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp45, tmp46}, tmp31);
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp50 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp30, tmp49});
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    tmp51 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp50});
    TNode<IntPtrT> tmp52;
    USE(tmp52);
    tmp52 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp53;
    USE(tmp53);
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp52});
    TNode<UintPtrT> tmp54;
    USE(tmp54);
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp51});
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block15, &block16, tmp29, tmp30, tmp31, tmp30, tmp30, tmp47, tmp51, tmp52, tmp30, tmp47, tmp51, tmp52, tmp52);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp56;
    TNode<FixedArray> tmp57;
    TNode<Smi> tmp58;
    TNode<FixedArray> tmp59;
    TNode<FixedArray> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<HeapObject> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    ca_.Bind(&block9, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Smi> tmp69;
    TNode<FixedArray> tmp70;
    TNode<Smi> tmp71;
    TNode<FixedArray> tmp72;
    TNode<FixedArray> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<HeapObject> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<IntPtrT> tmp81;
    ca_.Bind(&block15, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp81}, TNode<IntPtrT>{tmp82});
    TNode<IntPtrT> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp78}, TNode<IntPtrT>{tmp83});
    TNode<HeapObject> tmp85;
    USE(tmp85);
    TNode<IntPtrT> tmp86;
    USE(tmp86);
    std::tie(tmp85, tmp86) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp77}, TNode<IntPtrT>{tmp84}).Flatten();
    TNode<Object>tmp87 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp85, tmp86});
    TNode<BoolT> tmp88;
    USE(tmp88);
    tmp88 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp87}, TNode<MaybeObject>{tmp71});
    ca_.Branch(tmp88, &block18, &block19, tmp69, tmp70, tmp71, tmp85, tmp86);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp89;
    TNode<FixedArray> tmp90;
    TNode<Smi> tmp91;
    TNode<FixedArray> tmp92;
    TNode<FixedArray> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<HeapObject> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    ca_.Bind(&block16, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<Smi> tmp102;
    TNode<FixedArray> tmp103;
    TNode<Smi> tmp104;
    TNode<HeapObject> tmp105;
    TNode<IntPtrT> tmp106;
    ca_.Bind(&block19, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRef, oneTwoThree)' failed", "test/torque/test-torque.tq", 870);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp107;
    TNode<FixedArray> tmp108;
    TNode<Smi> tmp109;
    TNode<HeapObject> tmp110;
    TNode<IntPtrT> tmp111;
    ca_.Bind(&block18, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111);
    TNode<IntPtrT> tmp112;
    USE(tmp112);
    tmp112 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp115 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp108, tmp114});
    TNode<IntPtrT> tmp116;
    USE(tmp116);
    tmp116 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp115});
    TNode<IntPtrT> tmp117;
    USE(tmp117);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp118;
    USE(tmp118);
    tmp118 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp117});
    TNode<UintPtrT> tmp119;
    USE(tmp119);
    tmp119 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp116});
    TNode<BoolT> tmp120;
    USE(tmp120);
    tmp120 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp118}, TNode<UintPtrT>{tmp119});
    ca_.Branch(tmp120, &block23, &block24, tmp107, tmp108, tmp109, tmp110, tmp111, tmp108, tmp112, tmp116, tmp108, tmp112, tmp116, tmp117);
  }

  if (block23.is_used()) {
    TNode<Smi> tmp121;
    TNode<FixedArray> tmp122;
    TNode<Smi> tmp123;
    TNode<HeapObject> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<HeapObject> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<HeapObject> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<IntPtrT> tmp132;
    ca_.Bind(&block23, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132);
    TNode<IntPtrT> tmp133;
    USE(tmp133);
    tmp133 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp132}, TNode<IntPtrT>{tmp133});
    TNode<IntPtrT> tmp135;
    USE(tmp135);
    tmp135 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp130}, TNode<IntPtrT>{tmp134});
    TNode<HeapObject> tmp136;
    USE(tmp136);
    TNode<IntPtrT> tmp137;
    USE(tmp137);
    std::tie(tmp136, tmp137) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp129}, TNode<IntPtrT>{tmp135}).Flatten();
    TNode<Object>tmp138 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp136, tmp137});
    TNode<BoolT> tmp139;
    USE(tmp139);
    tmp139 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp138}, TNode<MaybeObject>{tmp123});
    ca_.Branch(tmp139, &block26, &block27, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp136, tmp137);
  }

  if (block24.is_used()) {
    TNode<Smi> tmp140;
    TNode<FixedArray> tmp141;
    TNode<Smi> tmp142;
    TNode<HeapObject> tmp143;
    TNode<IntPtrT> tmp144;
    TNode<HeapObject> tmp145;
    TNode<IntPtrT> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<HeapObject> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<IntPtrT> tmp150;
    TNode<IntPtrT> tmp151;
    ca_.Bind(&block24, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    TNode<Smi> tmp152;
    TNode<FixedArray> tmp153;
    TNode<Smi> tmp154;
    TNode<HeapObject> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<HeapObject> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<HeapObject> tmp160;
    TNode<IntPtrT> tmp161;
    ca_.Bind(&block27, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRefAgain, oneTwoThree)' failed", "test/torque/test-torque.tq", 874);
  }

  if (block26.is_used()) {
    TNode<Smi> tmp162;
    TNode<FixedArray> tmp163;
    TNode<Smi> tmp164;
    TNode<HeapObject> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<HeapObject> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<IntPtrT> tmp169;
    TNode<HeapObject> tmp170;
    TNode<IntPtrT> tmp171;
    ca_.Bind(&block26, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171);
    TNode<Smi> tmp172;
    USE(tmp172);
    tmp172 = Convert_Smi_constexpr_int31_0(state_, 321);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp170, tmp171}, tmp172);
    TNode<IntPtrT> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp174;
    USE(tmp174);
    tmp174 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp176 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp163, tmp175});
    TNode<IntPtrT> tmp177;
    USE(tmp177);
    tmp177 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp176});
    TNode<IntPtrT> tmp178;
    USE(tmp178);
    tmp178 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp179;
    USE(tmp179);
    tmp179 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp178});
    TNode<UintPtrT> tmp180;
    USE(tmp180);
    tmp180 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp177});
    TNode<BoolT> tmp181;
    USE(tmp181);
    tmp181 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp179}, TNode<UintPtrT>{tmp180});
    ca_.Branch(tmp181, &block34, &block35, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp163, tmp163, tmp173, tmp177, tmp178, tmp163, tmp173, tmp177, tmp178, tmp178);
  }

  if (block34.is_used()) {
    TNode<Smi> tmp182;
    TNode<FixedArray> tmp183;
    TNode<Smi> tmp184;
    TNode<HeapObject> tmp185;
    TNode<IntPtrT> tmp186;
    TNode<HeapObject> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<HeapObject> tmp190;
    TNode<IntPtrT> tmp191;
    TNode<Smi> tmp192;
    TNode<FixedArray> tmp193;
    TNode<FixedArray> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<HeapObject> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    ca_.Bind(&block34, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202);
    TNode<IntPtrT> tmp203;
    USE(tmp203);
    tmp203 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp202}, TNode<IntPtrT>{tmp203});
    TNode<IntPtrT> tmp205;
    USE(tmp205);
    tmp205 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp199}, TNode<IntPtrT>{tmp204});
    TNode<HeapObject> tmp206;
    USE(tmp206);
    TNode<IntPtrT> tmp207;
    USE(tmp207);
    std::tie(tmp206, tmp207) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp198}, TNode<IntPtrT>{tmp205}).Flatten();
    TNode<Object>tmp208 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp206, tmp207});
    TNode<BoolT> tmp209;
    USE(tmp209);
    tmp209 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp208}, TNode<MaybeObject>{tmp192});
    ca_.Branch(tmp209, &block28, &block29, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192);
  }

  if (block35.is_used()) {
    TNode<Smi> tmp210;
    TNode<FixedArray> tmp211;
    TNode<Smi> tmp212;
    TNode<HeapObject> tmp213;
    TNode<IntPtrT> tmp214;
    TNode<HeapObject> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<IntPtrT> tmp217;
    TNode<HeapObject> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<Smi> tmp220;
    TNode<FixedArray> tmp221;
    TNode<FixedArray> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<HeapObject> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    TNode<IntPtrT> tmp230;
    ca_.Bind(&block35, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block29.is_used()) {
    TNode<Smi> tmp231;
    TNode<FixedArray> tmp232;
    TNode<Smi> tmp233;
    TNode<HeapObject> tmp234;
    TNode<IntPtrT> tmp235;
    TNode<HeapObject> tmp236;
    TNode<IntPtrT> tmp237;
    TNode<IntPtrT> tmp238;
    TNode<HeapObject> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<Smi> tmp241;
    ca_.Bind(&block29, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(a.objects[0], threeTwoOne)' failed", "test/torque/test-torque.tq", 878);
  }

  if (block28.is_used()) {
    TNode<Smi> tmp242;
    TNode<FixedArray> tmp243;
    TNode<Smi> tmp244;
    TNode<HeapObject> tmp245;
    TNode<IntPtrT> tmp246;
    TNode<HeapObject> tmp247;
    TNode<IntPtrT> tmp248;
    TNode<IntPtrT> tmp249;
    TNode<HeapObject> tmp250;
    TNode<IntPtrT> tmp251;
    TNode<Smi> tmp252;
    ca_.Bind(&block28, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252);
    ca_.Goto(&block37);
  }

    ca_.Bind(&block37);
}

TNode<Oddball> TestSliceEnumeration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<FixedArray> tmp5;
    TNode<IntPtrT> tmp6;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp4, tmp5, tmp6);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<FixedArray> tmp10;
    TNode<IntPtrT> tmp11;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp14});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp15});
    TNode<UintPtrT> tmp17;
    USE(tmp17);
    tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    TNode<UintPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp17}, TNode<UintPtrT>{tmp18});
    ca_.Branch(tmp19, &block12, &block13, tmp9, tmp10, tmp11, tmp10, tmp10, tmp12, tmp16, tmp11, tmp11, tmp10, tmp12, tmp16, tmp11, tmp11);
  }

  if (block12.is_used()) {
    TNode<Context> tmp20;
    TNode<FixedArray> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<FixedArray> tmp23;
    TNode<FixedArray> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    ca_.Bind(&block12, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34});
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp35});
    TNode<HeapObject> tmp37;
    USE(tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    std::tie(tmp37, tmp38) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp36}).Flatten();
    TNode<Object>tmp39 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38});
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp20}, TNode<Object>{tmp39});
    TNode<Smi> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp40}, TNode<Smi>{tmp41});
    ca_.Branch(tmp42, &block6, &block7, tmp20, tmp21, tmp22);
  }

  if (block13.is_used()) {
    TNode<Context> tmp43;
    TNode<FixedArray> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<FixedArray> tmp46;
    TNode<FixedArray> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<HeapObject> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    ca_.Bind(&block13, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block7.is_used()) {
    TNode<Context> tmp57;
    TNode<FixedArray> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block7, &tmp57, &tmp58, &tmp59);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(fixedArray.objects[i]) == 0' failed", "test/torque/test-torque.tq", 893);
  }

  if (block6.is_used()) {
    TNode<Context> tmp60;
    TNode<FixedArray> tmp61;
    TNode<IntPtrT> tmp62;
    ca_.Bind(&block6, &tmp60, &tmp61, &tmp62);
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp66 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp61, tmp65});
    TNode<IntPtrT> tmp67;
    USE(tmp67);
    tmp67 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp66});
    TNode<UintPtrT> tmp68;
    USE(tmp68);
    tmp68 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp62});
    TNode<UintPtrT> tmp69;
    USE(tmp69);
    tmp69 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp67});
    TNode<BoolT> tmp70;
    USE(tmp70);
    tmp70 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp68}, TNode<UintPtrT>{tmp69});
    ca_.Branch(tmp70, &block19, &block20, tmp60, tmp61, tmp62, tmp61, tmp61, tmp63, tmp67, tmp62, tmp62, tmp61, tmp63, tmp67, tmp62, tmp62);
  }

  if (block19.is_used()) {
    TNode<Context> tmp71;
    TNode<FixedArray> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<FixedArray> tmp74;
    TNode<FixedArray> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    ca_.Bind(&block19, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<IntPtrT> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp84}, TNode<IntPtrT>{tmp85});
    TNode<IntPtrT> tmp87;
    USE(tmp87);
    tmp87 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp81}, TNode<IntPtrT>{tmp86});
    TNode<HeapObject> tmp88;
    USE(tmp88);
    TNode<IntPtrT> tmp89;
    USE(tmp89);
    std::tie(tmp88, tmp89) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp80}, TNode<IntPtrT>{tmp87}).Flatten();
    TNode<Smi> tmp90;
    USE(tmp90);
    tmp90 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp73});
    TNode<Smi> tmp91;
    USE(tmp91);
    tmp91 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp92;
    USE(tmp92);
    tmp92 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp90}, TNode<Smi>{tmp91});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp88, tmp89}, tmp92);
    TNode<IntPtrT> tmp93;
    USE(tmp93);
    tmp93 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp94;
    USE(tmp94);
    tmp94 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp73}, TNode<IntPtrT>{tmp93});
    ca_.Goto(&block4, tmp71, tmp72, tmp94);
  }

  if (block20.is_used()) {
    TNode<Context> tmp95;
    TNode<FixedArray> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<FixedArray> tmp98;
    TNode<FixedArray> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<HeapObject> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    ca_.Bind(&block20, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<Context> tmp109;
    TNode<FixedArray> tmp110;
    TNode<IntPtrT> tmp111;
    ca_.Bind(&block3, &tmp109, &tmp110, &tmp111);
    TNode<IntPtrT> tmp112;
    USE(tmp112);
    tmp112 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp115 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp110, tmp114});
    TNode<IntPtrT> tmp116;
    USE(tmp116);
    tmp116 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp115});
    TNode<IntPtrT> tmp117;
    USE(tmp117);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block24, tmp109, tmp110, tmp110, tmp112, tmp116, tmp117);
  }

  if (block24.is_used()) {
    TNode<Context> tmp118;
    TNode<FixedArray> tmp119;
    TNode<FixedArray> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    ca_.Bind(&block24, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123);
    TNode<BoolT> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp123}, TNode<IntPtrT>{tmp122});
    ca_.Branch(tmp124, &block22, &block23, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123);
  }

  if (block22.is_used()) {
    TNode<Context> tmp125;
    TNode<FixedArray> tmp126;
    TNode<FixedArray> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    ca_.Bind(&block22, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    TNode<UintPtrT> tmp131;
    USE(tmp131);
    tmp131 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp130});
    TNode<UintPtrT> tmp132;
    USE(tmp132);
    tmp132 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp129});
    TNode<BoolT> tmp133;
    USE(tmp133);
    tmp133 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp131}, TNode<UintPtrT>{tmp132});
    ca_.Branch(tmp133, &block29, &block30, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp130, tmp130);
  }

  if (block29.is_used()) {
    TNode<Context> tmp134;
    TNode<FixedArray> tmp135;
    TNode<FixedArray> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<IntPtrT> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    ca_.Bind(&block29, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141);
    TNode<IntPtrT> tmp142;
    USE(tmp142);
    tmp142 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp143;
    USE(tmp143);
    tmp143 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp141}, TNode<IntPtrT>{tmp142});
    TNode<IntPtrT> tmp144;
    USE(tmp144);
    tmp144 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp137}, TNode<IntPtrT>{tmp143});
    TNode<HeapObject> tmp145;
    USE(tmp145);
    TNode<IntPtrT> tmp146;
    USE(tmp146);
    std::tie(tmp145, tmp146) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp136}, TNode<IntPtrT>{tmp144}).Flatten();
    TNode<Object>tmp147 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp145, tmp146});
    TNode<Smi> tmp148;
    USE(tmp148);
    tmp148 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp134}, TNode<Object>{tmp147});
    TNode<Smi> tmp149;
    USE(tmp149);
    tmp149 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp139});
    TNode<Smi> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp151;
    USE(tmp151);
    tmp151 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp149}, TNode<Smi>{tmp150});
    TNode<BoolT> tmp152;
    USE(tmp152);
    tmp152 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp148}, TNode<Smi>{tmp151});
    ca_.Branch(tmp152, &block32, &block33, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp145, tmp146, tmp148);
  }

  if (block30.is_used()) {
    TNode<Context> tmp153;
    TNode<FixedArray> tmp154;
    TNode<FixedArray> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<IntPtrT> tmp160;
    ca_.Bind(&block30, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Context> tmp161;
    TNode<FixedArray> tmp162;
    TNode<FixedArray> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<HeapObject> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<Smi> tmp169;
    ca_.Bind(&block33, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == Convert<Smi>(i) + 3' failed", "test/torque/test-torque.tq", 901);
  }

  if (block32.is_used()) {
    TNode<Context> tmp170;
    TNode<FixedArray> tmp171;
    TNode<FixedArray> tmp172;
    TNode<IntPtrT> tmp173;
    TNode<IntPtrT> tmp174;
    TNode<IntPtrT> tmp175;
    TNode<HeapObject> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<Smi> tmp178;
    ca_.Bind(&block32, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178);
    TNode<Smi> tmp179;
    USE(tmp179);
    tmp179 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp180;
    USE(tmp180);
    tmp180 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp178}, TNode<Smi>{tmp179});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp176, tmp177}, tmp180);
    TNode<IntPtrT> tmp181;
    USE(tmp181);
    tmp181 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp182;
    USE(tmp182);
    tmp182 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp175}, TNode<IntPtrT>{tmp181});
    ca_.Goto(&block24, tmp170, tmp171, tmp172, tmp173, tmp174, tmp182);
  }

  if (block23.is_used()) {
    TNode<Context> tmp183;
    TNode<FixedArray> tmp184;
    TNode<FixedArray> tmp185;
    TNode<IntPtrT> tmp186;
    TNode<IntPtrT> tmp187;
    TNode<IntPtrT> tmp188;
    ca_.Bind(&block23, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
    TNode<IntPtrT> tmp189;
    USE(tmp189);
    tmp189 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp190;
    USE(tmp190);
    tmp190 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp187}, TNode<IntPtrT>{tmp189});
    TNode<IntPtrT> tmp191;
    USE(tmp191);
    tmp191 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp186}, TNode<IntPtrT>{tmp190});
    TNode<Smi> tmp192;
    USE(tmp192);
    tmp192 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block37, tmp183, tmp184, tmp185, tmp186, tmp187, tmp185, tmp186, tmp191, tmp192);
  }

  if (block37.is_used()) {
    TNode<Context> tmp193;
    TNode<FixedArray> tmp194;
    TNode<FixedArray> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<HeapObject> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<Smi> tmp201;
    ca_.Bind(&block37, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    TNode<BoolT> tmp202;
    USE(tmp202);
    tmp202 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp202, &block35, &block36, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201);
  }

  if (block35.is_used()) {
    TNode<Context> tmp203;
    TNode<FixedArray> tmp204;
    TNode<FixedArray> tmp205;
    TNode<IntPtrT> tmp206;
    TNode<IntPtrT> tmp207;
    TNode<HeapObject> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<Smi> tmp211;
    ca_.Bind(&block35, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211);
    TNode<BoolT> tmp212;
    USE(tmp212);
    tmp212 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp209}, TNode<IntPtrT>{tmp210});
    ca_.Branch(tmp212, &block42, &block43, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211);
  }

  if (block42.is_used()) {
    TNode<Context> tmp213;
    TNode<FixedArray> tmp214;
    TNode<FixedArray> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<IntPtrT> tmp217;
    TNode<HeapObject> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<IntPtrT> tmp220;
    TNode<Smi> tmp221;
    ca_.Bind(&block42, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221);
    ca_.Goto(&block36, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221);
  }

  if (block43.is_used()) {
    TNode<Context> tmp222;
    TNode<FixedArray> tmp223;
    TNode<FixedArray> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<HeapObject> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    TNode<Smi> tmp230;
    ca_.Bind(&block43, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    TNode<HeapObject> tmp231;
    USE(tmp231);
    TNode<IntPtrT> tmp232;
    USE(tmp232);
    std::tie(tmp231, tmp232) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp227}, TNode<IntPtrT>{tmp228}).Flatten();
    TNode<IntPtrT> tmp233;
    USE(tmp233);
    tmp233 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp234;
    USE(tmp234);
    tmp234 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp228}, TNode<IntPtrT>{tmp233});
    TNode<Object>tmp235 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp231, tmp232});
    TNode<Smi> tmp236;
    USE(tmp236);
    tmp236 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp222}, TNode<Object>{tmp235});
    TNode<Smi> tmp237;
    USE(tmp237);
    tmp237 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<Smi> tmp238;
    USE(tmp238);
    tmp238 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp230}, TNode<Smi>{tmp237});
    TNode<BoolT> tmp239;
    USE(tmp239);
    tmp239 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp236}, TNode<Smi>{tmp238});
    ca_.Branch(tmp239, &block46, &block47, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp234, tmp229, tmp230, tmp236);
  }

  if (block47.is_used()) {
    TNode<Context> tmp240;
    TNode<FixedArray> tmp241;
    TNode<FixedArray> tmp242;
    TNode<IntPtrT> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<HeapObject> tmp245;
    TNode<IntPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<Smi> tmp248;
    TNode<Smi> tmp249;
    ca_.Bind(&block47, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == count + 7' failed", "test/torque/test-torque.tq", 909);
  }

  if (block46.is_used()) {
    TNode<Context> tmp250;
    TNode<FixedArray> tmp251;
    TNode<FixedArray> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<IntPtrT> tmp254;
    TNode<HeapObject> tmp255;
    TNode<IntPtrT> tmp256;
    TNode<IntPtrT> tmp257;
    TNode<Smi> tmp258;
    TNode<Smi> tmp259;
    ca_.Bind(&block46, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259);
    TNode<Smi> tmp260;
    USE(tmp260);
    tmp260 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp261;
    USE(tmp261);
    tmp261 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp258}, TNode<Smi>{tmp260});
    ca_.Goto(&block37, tmp250, tmp251, tmp252, tmp253, tmp254, tmp255, tmp256, tmp257, tmp261);
  }

  if (block36.is_used()) {
    TNode<Context> tmp262;
    TNode<FixedArray> tmp263;
    TNode<FixedArray> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<HeapObject> tmp267;
    TNode<IntPtrT> tmp268;
    TNode<IntPtrT> tmp269;
    TNode<Smi> tmp270;
    ca_.Bind(&block36, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270);
    TNode<Smi> tmp271;
    USE(tmp271);
    tmp271 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp272;
    USE(tmp272);
    tmp272 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp270}, TNode<Smi>{tmp271});
    ca_.Branch(tmp272, &block48, &block49, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270);
  }

  if (block49.is_used()) {
    TNode<Context> tmp273;
    TNode<FixedArray> tmp274;
    TNode<FixedArray> tmp275;
    TNode<IntPtrT> tmp276;
    TNode<IntPtrT> tmp277;
    TNode<HeapObject> tmp278;
    TNode<IntPtrT> tmp279;
    TNode<IntPtrT> tmp280;
    TNode<Smi> tmp281;
    ca_.Bind(&block49, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281);
    CodeStubAssembler(state_).FailAssert("Torque assert 'count == 3' failed", "test/torque/test-torque.tq", 912);
  }

  if (block48.is_used()) {
    TNode<Context> tmp282;
    TNode<FixedArray> tmp283;
    TNode<FixedArray> tmp284;
    TNode<IntPtrT> tmp285;
    TNode<IntPtrT> tmp286;
    TNode<HeapObject> tmp287;
    TNode<IntPtrT> tmp288;
    TNode<IntPtrT> tmp289;
    TNode<Smi> tmp290;
    ca_.Bind(&block48, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290);
    TNode<BoolT> tmp291;
    USE(tmp291);
    tmp291 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp288}, TNode<IntPtrT>{tmp289});
    ca_.Branch(tmp291, &block50, &block51, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290);
  }

  if (block51.is_used()) {
    TNode<Context> tmp292;
    TNode<FixedArray> tmp293;
    TNode<FixedArray> tmp294;
    TNode<IntPtrT> tmp295;
    TNode<IntPtrT> tmp296;
    TNode<HeapObject> tmp297;
    TNode<IntPtrT> tmp298;
    TNode<IntPtrT> tmp299;
    TNode<Smi> tmp300;
    ca_.Bind(&block51, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300);
    CodeStubAssembler(state_).FailAssert("Torque assert 'it.Empty()' failed", "test/torque/test-torque.tq", 913);
  }

  if (block50.is_used()) {
    TNode<Context> tmp301;
    TNode<FixedArray> tmp302;
    TNode<FixedArray> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<HeapObject> tmp306;
    TNode<IntPtrT> tmp307;
    TNode<IntPtrT> tmp308;
    TNode<Smi> tmp309;
    ca_.Bind(&block50, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309);
    TNode<Oddball> tmp310;
    USE(tmp310);
    tmp310 = Undefined_0(state_);
    ca_.Goto(&block53, tmp301, tmp310);
  }

    TNode<Context> tmp311;
    TNode<Oddball> tmp312;
    ca_.Bind(&block53, &tmp311, &tmp312);
  return TNode<Oddball>{tmp312};
}

void TestStaticAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal((CodeStubAssembler(state_).ConstexprInt31Add(1, 2)), 3)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TF_BUILTIN(NewSmiBox, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).GetStructMap(SMI_BOX_TYPE);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<HeapObject> tmp4;
    USE(tmp4);
    tmp4 = Allocate_0(state_, TNode<IntPtrT>{tmp3}, TNode<Map>{tmp2});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5}, tmp2);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp6}, tmp1);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp7}, tmp8);
    TNode<SmiBox> tmp9;
    USE(tmp9);
    tmp9 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }
}

void TestLoadEliminationFixed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 123);
    TNode<SmiBox> tmp2;
    tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp1));
    USE(tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 999);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp5}, tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi>tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp7});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block2, &block3, tmp0, tmp2, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp11;
    TNode<SmiBox> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp14});
    ca_.Goto(&block4, tmp11, tmp12, tmp13, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<SmiBox> tmp17;
    TNode<Smi> tmp18;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp17, tmp19});
    ca_.Goto(&block4, tmp16, tmp17, tmp18, tmp20);
  }

  if (block4.is_used()) {
    TNode<Context> tmp21;
    TNode<SmiBox> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block4, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp23}, TNode<MaybeObject>{tmp24});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp25});
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp22, tmp26}, tmp27);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp29 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp22, tmp28});
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp29}, TNode<MaybeObject>{tmp30});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp31});
    ca_.Goto(&block6, tmp21);
  }

    TNode<Context> tmp32;
    ca_.Bind(&block6, &tmp32);
}

void TestLoadEliminationVariable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, Object, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<SmiBox> tmp4;
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp3));
    USE(tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp7});
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp8});
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp11 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp10});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp11});
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp12});
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp14});
    ca_.Branch(tmp15, &block6, &block7, tmp0, tmp2, tmp4, tmp2, tmp2, tmp5, tmp9, tmp11, tmp11, tmp12, tmp2, tmp5, tmp9, tmp12, tmp12);
  }

  if (block6.is_used()) {
    TNode<Context> tmp16;
    TNode<FixedArray> tmp17;
    TNode<SmiBox> tmp18;
    TNode<FixedArray> tmp19;
    TNode<FixedArray> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<HeapObject> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    ca_.Bind(&block6, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp31});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp32});
    TNode<HeapObject> tmp34;
    USE(tmp34);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    std::tie(tmp34, tmp35) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp26}, TNode<IntPtrT>{tmp33}).Flatten();
    TNode<Object>tmp36 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp34, tmp35});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp40 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp17, tmp39});
    TNode<IntPtrT> tmp41;
    USE(tmp41);
    tmp41 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp40});
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp43 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp42});
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp43}, TNode<Smi>{tmp44});
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    tmp46 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp45});
    TNode<UintPtrT> tmp47;
    USE(tmp47);
    tmp47 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp46});
    TNode<UintPtrT> tmp48;
    USE(tmp48);
    tmp48 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp41});
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp47}, TNode<UintPtrT>{tmp48});
    ca_.Branch(tmp49, &block13, &block14, tmp16, tmp17, tmp18, tmp36, tmp17, tmp17, tmp37, tmp41, tmp45, tmp45, tmp46, tmp17, tmp37, tmp41, tmp46, tmp46);
  }

  if (block7.is_used()) {
    TNode<Context> tmp50;
    TNode<FixedArray> tmp51;
    TNode<SmiBox> tmp52;
    TNode<FixedArray> tmp53;
    TNode<FixedArray> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<Smi> tmp57;
    TNode<Smi> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<HeapObject> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    ca_.Bind(&block7, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block13.is_used()) {
    TNode<Context> tmp65;
    TNode<FixedArray> tmp66;
    TNode<SmiBox> tmp67;
    TNode<Object> tmp68;
    TNode<FixedArray> tmp69;
    TNode<FixedArray> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<Smi> tmp73;
    TNode<Smi> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<HeapObject> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    ca_.Bind(&block13, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp80}, TNode<IntPtrT>{tmp81});
    TNode<IntPtrT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp77}, TNode<IntPtrT>{tmp82});
    TNode<HeapObject> tmp84;
    USE(tmp84);
    TNode<IntPtrT> tmp85;
    USE(tmp85);
    std::tie(tmp84, tmp85) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp76}, TNode<IntPtrT>{tmp83}).Flatten();
    TNode<Object>tmp86 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp84, tmp85});
    TNode<IntPtrT> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp89;
    USE(tmp89);
    tmp89 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp90 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp66, tmp89});
    TNode<IntPtrT> tmp91;
    USE(tmp91);
    tmp91 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp90});
    TNode<IntPtrT> tmp92;
    USE(tmp92);
    tmp92 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp93 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp67, tmp92});
    TNode<IntPtrT> tmp94;
    USE(tmp94);
    tmp94 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp93});
    TNode<UintPtrT> tmp95;
    USE(tmp95);
    tmp95 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp94});
    TNode<UintPtrT> tmp96;
    USE(tmp96);
    tmp96 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp91});
    TNode<BoolT> tmp97;
    USE(tmp97);
    tmp97 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp95}, TNode<UintPtrT>{tmp96});
    ca_.Branch(tmp97, &block20, &block21, tmp65, tmp66, tmp67, tmp68, tmp86, tmp66, tmp66, tmp87, tmp91, tmp93, tmp93, tmp94, tmp66, tmp87, tmp91, tmp94, tmp94);
  }

  if (block14.is_used()) {
    TNode<Context> tmp98;
    TNode<FixedArray> tmp99;
    TNode<SmiBox> tmp100;
    TNode<Object> tmp101;
    TNode<FixedArray> tmp102;
    TNode<FixedArray> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<Smi> tmp106;
    TNode<Smi> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<HeapObject> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<IntPtrT> tmp113;
    ca_.Bind(&block14, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block20.is_used()) {
    TNode<Context> tmp114;
    TNode<FixedArray> tmp115;
    TNode<SmiBox> tmp116;
    TNode<Object> tmp117;
    TNode<Object> tmp118;
    TNode<FixedArray> tmp119;
    TNode<FixedArray> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<Smi> tmp123;
    TNode<Smi> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<HeapObject> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    ca_.Bind(&block20, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    TNode<IntPtrT> tmp131;
    USE(tmp131);
    tmp131 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp132;
    USE(tmp132);
    tmp132 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp130}, TNode<IntPtrT>{tmp131});
    TNode<IntPtrT> tmp133;
    USE(tmp133);
    tmp133 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp127}, TNode<IntPtrT>{tmp132});
    TNode<HeapObject> tmp134;
    USE(tmp134);
    TNode<IntPtrT> tmp135;
    USE(tmp135);
    std::tie(tmp134, tmp135) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp126}, TNode<IntPtrT>{tmp133}).Flatten();
    TNode<Object>tmp136 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp134, tmp135});
    TNode<IntPtrT> tmp137;
    USE(tmp137);
    tmp137 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp138;
    USE(tmp138);
    tmp138 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp139;
    USE(tmp139);
    tmp139 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp140 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp115, tmp139});
    TNode<IntPtrT> tmp141;
    USE(tmp141);
    tmp141 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp140});
    TNode<IntPtrT> tmp142;
    USE(tmp142);
    tmp142 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp143 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp116, tmp142});
    TNode<Smi> tmp144;
    USE(tmp144);
    tmp144 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp145;
    USE(tmp145);
    tmp145 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp143}, TNode<Smi>{tmp144});
    TNode<IntPtrT> tmp146;
    USE(tmp146);
    tmp146 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp145});
    TNode<UintPtrT> tmp147;
    USE(tmp147);
    tmp147 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp146});
    TNode<UintPtrT> tmp148;
    USE(tmp148);
    tmp148 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp141});
    TNode<BoolT> tmp149;
    USE(tmp149);
    tmp149 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp147}, TNode<UintPtrT>{tmp148});
    ca_.Branch(tmp149, &block27, &block28, tmp114, tmp115, tmp116, tmp117, tmp118, tmp136, tmp115, tmp115, tmp137, tmp141, tmp145, tmp145, tmp146, tmp115, tmp137, tmp141, tmp146, tmp146);
  }

  if (block21.is_used()) {
    TNode<Context> tmp150;
    TNode<FixedArray> tmp151;
    TNode<SmiBox> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<FixedArray> tmp155;
    TNode<FixedArray> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<Smi> tmp159;
    TNode<Smi> tmp160;
    TNode<IntPtrT> tmp161;
    TNode<HeapObject> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<IntPtrT> tmp166;
    ca_.Bind(&block21, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    TNode<Context> tmp167;
    TNode<FixedArray> tmp168;
    TNode<SmiBox> tmp169;
    TNode<Object> tmp170;
    TNode<Object> tmp171;
    TNode<Object> tmp172;
    TNode<FixedArray> tmp173;
    TNode<FixedArray> tmp174;
    TNode<IntPtrT> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<Smi> tmp177;
    TNode<Smi> tmp178;
    TNode<IntPtrT> tmp179;
    TNode<HeapObject> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<IntPtrT> tmp182;
    TNode<IntPtrT> tmp183;
    TNode<IntPtrT> tmp184;
    ca_.Bind(&block27, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184);
    TNode<IntPtrT> tmp185;
    USE(tmp185);
    tmp185 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp186;
    USE(tmp186);
    tmp186 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp184}, TNode<IntPtrT>{tmp185});
    TNode<IntPtrT> tmp187;
    USE(tmp187);
    tmp187 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp181}, TNode<IntPtrT>{tmp186});
    TNode<HeapObject> tmp188;
    USE(tmp188);
    TNode<IntPtrT> tmp189;
    USE(tmp189);
    std::tie(tmp188, tmp189) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp180}, TNode<IntPtrT>{tmp187}).Flatten();
    TNode<Object>tmp190 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp188, tmp189});
    TNode<BoolT> tmp191;
    USE(tmp191);
    tmp191 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp170}, TNode<MaybeObject>{tmp172});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp191});
    TNode<BoolT> tmp192;
    USE(tmp192);
    tmp192 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp171}, TNode<MaybeObject>{tmp190});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp192});
    ca_.Goto(&block30, tmp167);
  }

  if (block28.is_used()) {
    TNode<Context> tmp193;
    TNode<FixedArray> tmp194;
    TNode<SmiBox> tmp195;
    TNode<Object> tmp196;
    TNode<Object> tmp197;
    TNode<Object> tmp198;
    TNode<FixedArray> tmp199;
    TNode<FixedArray> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<Smi> tmp203;
    TNode<Smi> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<HeapObject> tmp206;
    TNode<IntPtrT> tmp207;
    TNode<IntPtrT> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    ca_.Bind(&block28, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp211;
    ca_.Bind(&block30, &tmp211);
}

TNode<Smi> TestRedundantArrayElementCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2);
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<FixedArray> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp6});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp3, tmp4, tmp5);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<FixedArray> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp14});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp15});
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp11});
    TNode<UintPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp17});
    TNode<UintPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    ca_.Branch(tmp20, &block12, &block13, tmp9, tmp10, tmp11, tmp10, tmp10, tmp12, tmp16, tmp11, tmp11, tmp17, tmp10, tmp12, tmp16, tmp17, tmp17);
  }

  if (block12.is_used()) {
    TNode<Context> tmp21;
    TNode<FixedArray> tmp22;
    TNode<Smi> tmp23;
    TNode<FixedArray> tmp24;
    TNode<FixedArray> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Smi> tmp28;
    TNode<Smi> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<HeapObject> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    ca_.Bind(&block12, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp36});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp37});
    TNode<HeapObject> tmp39;
    USE(tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    std::tie(tmp39, tmp40) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp31}, TNode<IntPtrT>{tmp38}).Flatten();
    TNode<Object>tmp41 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp39, tmp40});
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = TheHole_0(state_);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp41}, TNode<HeapObject>{tmp42});
    ca_.Branch(tmp43, &block6, &block7, tmp21, tmp22, tmp23);
  }

  if (block13.is_used()) {
    TNode<Context> tmp44;
    TNode<FixedArray> tmp45;
    TNode<Smi> tmp46;
    TNode<FixedArray> tmp47;
    TNode<FixedArray> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<Smi> tmp51;
    TNode<Smi> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<HeapObject> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    ca_.Bind(&block13, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block6.is_used()) {
    TNode<Context> tmp59;
    TNode<FixedArray> tmp60;
    TNode<Smi> tmp61;
    ca_.Bind(&block6, &tmp59, &tmp60, &tmp61);
    TNode<IntPtrT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp65 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp60, tmp64});
    TNode<IntPtrT> tmp66;
    USE(tmp66);
    tmp66 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp65});
    TNode<IntPtrT> tmp67;
    USE(tmp67);
    tmp67 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp61});
    TNode<UintPtrT> tmp68;
    USE(tmp68);
    tmp68 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp67});
    TNode<UintPtrT> tmp69;
    USE(tmp69);
    tmp69 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp66});
    TNode<BoolT> tmp70;
    USE(tmp70);
    tmp70 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp68}, TNode<UintPtrT>{tmp69});
    ca_.Branch(tmp70, &block21, &block22, tmp59, tmp60, tmp61, tmp60, tmp60, tmp62, tmp66, tmp61, tmp61, tmp67, tmp60, tmp62, tmp66, tmp67, tmp67);
  }

  if (block21.is_used()) {
    TNode<Context> tmp71;
    TNode<FixedArray> tmp72;
    TNode<Smi> tmp73;
    TNode<FixedArray> tmp74;
    TNode<FixedArray> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<Smi> tmp78;
    TNode<Smi> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<HeapObject> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    ca_.Bind(&block21, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<IntPtrT> tmp86;
    USE(tmp86);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp87;
    USE(tmp87);
    tmp87 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp85}, TNode<IntPtrT>{tmp86});
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp82}, TNode<IntPtrT>{tmp87});
    TNode<HeapObject> tmp89;
    USE(tmp89);
    TNode<IntPtrT> tmp90;
    USE(tmp90);
    std::tie(tmp89, tmp90) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp81}, TNode<IntPtrT>{tmp88}).Flatten();
    TNode<Object>tmp91 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp89, tmp90});
    TNode<Oddball> tmp92;
    USE(tmp92);
    tmp92 = TheHole_0(state_);
    TNode<BoolT> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp91}, TNode<HeapObject>{tmp92});
    ca_.Branch(tmp93, &block15, &block16, tmp71, tmp72, tmp73);
  }

  if (block22.is_used()) {
    TNode<Context> tmp94;
    TNode<FixedArray> tmp95;
    TNode<Smi> tmp96;
    TNode<FixedArray> tmp97;
    TNode<FixedArray> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<Smi> tmp101;
    TNode<Smi> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<HeapObject> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    ca_.Bind(&block22, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp109;
    TNode<FixedArray> tmp110;
    TNode<Smi> tmp111;
    ca_.Bind(&block15, &tmp109, &tmp110, &tmp111);
    TNode<Smi> tmp112;
    USE(tmp112);
    tmp112 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp109, tmp112);
  }

  if (block16.is_used()) {
    TNode<Context> tmp113;
    TNode<FixedArray> tmp114;
    TNode<Smi> tmp115;
    ca_.Bind(&block16, &tmp113, &tmp114, &tmp115);
    TNode<BoolT> tmp116;
    USE(tmp116);
    tmp116 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp116});
    ca_.Goto(&block7, tmp113, tmp114, tmp115);
  }

  if (block7.is_used()) {
    TNode<Context> tmp117;
    TNode<FixedArray> tmp118;
    TNode<Smi> tmp119;
    ca_.Bind(&block7, &tmp117, &tmp118, &tmp119);
    TNode<Smi> tmp120;
    USE(tmp120);
    tmp120 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp121;
    USE(tmp121);
    tmp121 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp119}, TNode<Smi>{tmp120});
    ca_.Goto(&block4, tmp117, tmp118, tmp121);
  }

  if (block3.is_used()) {
    TNode<Context> tmp122;
    TNode<FixedArray> tmp123;
    TNode<Smi> tmp124;
    ca_.Bind(&block3, &tmp122, &tmp123, &tmp124);
    TNode<Smi> tmp125;
    USE(tmp125);
    tmp125 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp122, tmp125);
  }

  if (block1.is_used()) {
    TNode<Context> tmp126;
    TNode<Smi> tmp127;
    ca_.Bind(&block1, &tmp126, &tmp127);
    ca_.Goto(&block25, tmp126, tmp127);
  }

    TNode<Context> tmp128;
    TNode<Smi> tmp129;
    ca_.Bind(&block25, &tmp128, &tmp129);
  return TNode<Smi>{tmp129};
}

TNode<Smi> TestRedundantSmiCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Object, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Smi, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Smi, Object, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp1, tmp1, tmp2, tmp6, tmp7, tmp1, tmp2, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<FixedArray> tmp12;
    TNode<FixedArray> tmp13;
    TNode<FixedArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<HeapObject> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp24});
    TNode<HeapObject> tmp26;
    USE(tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    std::tie(tmp26, tmp27) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp18}, TNode<IntPtrT>{tmp25}).Flatten();
    TNode<Object>tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp26, tmp27});
    TNode<Smi> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = Cast_Smi_0(state_, TNode<Object>{tmp28}, &label0);
    ca_.Goto(&block11, tmp11, tmp12, tmp28, tmp28, tmp28, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp11, tmp12, tmp28, tmp28, tmp28);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp30;
    TNode<FixedArray> tmp31;
    TNode<FixedArray> tmp32;
    TNode<FixedArray> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block7, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    TNode<Context> tmp42;
    TNode<FixedArray> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    ca_.Bind(&block12, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<Smi> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp42, tmp47);
  }

  if (block11.is_used()) {
    TNode<Context> tmp48;
    TNode<FixedArray> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Smi> tmp53;
    ca_.Bind(&block11, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<Smi> tmp54;
    USE(tmp54);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp54 = Cast_Smi_0(state_, TNode<Object>{tmp50}, &label0);
    ca_.Goto(&block15, tmp48, tmp49, tmp50, tmp51, tmp53, tmp50, tmp54);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp48, tmp49, tmp50, tmp51, tmp53, tmp50);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp55;
    TNode<FixedArray> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Smi> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block16, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    VerifiedUnreachable_0(state_);
  }

  if (block15.is_used()) {
    TNode<Context> tmp61;
    TNode<FixedArray> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<Smi> tmp65;
    TNode<Object> tmp66;
    TNode<Smi> tmp67;
    ca_.Bind(&block15, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Smi> tmp68;
    USE(tmp68);
    tmp68 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp61, tmp68);
  }

  if (block1.is_used()) {
    TNode<Context> tmp69;
    TNode<Smi> tmp70;
    ca_.Bind(&block1, &tmp69, &tmp70);
    ca_.Goto(&block17, tmp69, tmp70);
  }

    TNode<Context> tmp71;
    TNode<Smi> tmp72;
    ca_.Bind(&block17, &tmp71, &tmp72);
  return TNode<Smi>{tmp72};
}

TNode<IntPtrT> TestGenericStruct1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp0, tmp0);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block3, &tmp3, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'box.value == 123' failed", "test/torque/test-torque.tq", 997);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 246);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp12, &block4, &block5, tmp6, tmp7, tmp10);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'boxbox.value.value == 246' failed", "test/torque/test-torque.tq", 999);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18);
    ca_.Goto(&block6, tmp18);
  }

    TNode<IntPtrT> tmp19;
    ca_.Bind(&block6, &tmp19);
  return TNode<IntPtrT>{tmp19};
}

TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 TestGenericStruct2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    std::tie(tmp2, tmp3) = TupleSwap_intptr_Smi_0(state_, TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp0}, TNode<Smi>{tmp1}}).Flatten();
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp5;
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    TNode<IntPtrT> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.fst == smiAndIntptr.snd' failed", "test/torque/test-torque.tq", 1018);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp13, &block4, &block5, tmp9, tmp10, tmp11, tmp12);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<IntPtrT> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.snd == smiAndIntptr.fst' failed", "test/torque/test-torque.tq", 1019);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp18, tmp19, tmp20, tmp21);
  }

    TNode<IntPtrT> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<IntPtrT> tmp25;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24, &tmp25);
  return TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0{TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp22}, TNode<Smi>{tmp23}}, TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{tmp24}, TNode<IntPtrT>{tmp25}}};
}

TNode<BoolT> BranchAndWriteResult_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x, TNode<SmiBox> p_box) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_box);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    TNode<SmiBox> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block4, &block5, tmp0, tmp1, tmp3);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp4;
    TNode<SmiBox> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp4, tmp5, tmp6, tmp7);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp8;
    TNode<SmiBox> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp8}, TNode<Smi>{tmp11});
    ca_.Goto(&block6, tmp8, tmp9, tmp10, tmp12);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp13;
    TNode<SmiBox> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Branch(tmp16, &block2, &block3, tmp13, tmp14);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp17;
    TNode<SmiBox> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp19}, tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp17, tmp18, tmp21);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp22;
    TNode<SmiBox> tmp23;
    ca_.Bind(&block3, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp23, tmp24}, tmp25);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp22, tmp23, tmp26);
  }

  if (block1.is_used()) {
    TNode<Smi> tmp27;
    TNode<SmiBox> tmp28;
    TNode<BoolT> tmp29;
    ca_.Bind(&block1, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block8, tmp27, tmp28, tmp29);
  }

    TNode<Smi> tmp30;
    TNode<SmiBox> tmp31;
    TNode<BoolT> tmp32;
    ca_.Bind(&block8, &tmp30, &tmp31, &tmp32);
  return TNode<BoolT>{tmp32};
}

void TestBranchOnBoolOptimization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_input) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_input);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<SmiBox> tmp3;
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp2));
    USE(tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = BranchAndWriteResult_0(state_, TNode<Smi>{tmp1}, TNode<SmiBox>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp5;
    TNode<Smi> tmp6;
    TNode<SmiBox> tmp7;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp9}, TNode<Smi>{tmp10});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp11});
    ca_.Goto(&block4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp12;
    TNode<Smi> tmp13;
    TNode<SmiBox> tmp14;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp16 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp15});
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp16}, TNode<Smi>{tmp17});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp18});
    ca_.Goto(&block4, tmp12, tmp13, tmp14);
  }

  if (block4.is_used()) {
    TNode<Context> tmp19;
    TNode<Smi> tmp20;
    TNode<SmiBox> tmp21;
    ca_.Bind(&block4, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block5, tmp19, tmp20);
  }

    TNode<Context> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block5, &tmp22, &tmp23);
}

void TestBitFieldLoad_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val, TNode<BoolT> p_expectedA, TNode<Uint16T> p_expectedB, TNode<Uint32T> p_expectedC, TNode<BoolT> p_expectedD) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, BoolT, Uint16T, Uint32T, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_val, p_expectedA, p_expectedB, p_expectedC, p_expectedD);

  if (block0.is_used()) {
    TNode<Uint8T> tmp0;
    TNode<BoolT> tmp1;
    TNode<Uint16T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<BoolT>tmp5 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::ABit>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp5}, TNode<BoolT>{tmp1});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Uint8T> tmp7;
    TNode<BoolT> tmp8;
    TNode<Uint16T> tmp9;
    TNode<Uint32T> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.a == expectedA' failed", "test/torque/test-torque.tq", 1058);
  }

  if (block2.is_used()) {
    TNode<Uint8T> tmp12;
    TNode<BoolT> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Uint16T>tmp17 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::BBits>(ca_.UncheckedCast<Word32T>(tmp12)));
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp14});
    ca_.Branch(tmp18, &block4, &block5, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Uint8T> tmp19;
    TNode<BoolT> tmp20;
    TNode<Uint16T> tmp21;
    TNode<Uint32T> tmp22;
    TNode<BoolT> tmp23;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.b == expectedB' failed", "test/torque/test-torque.tq", 1059);
  }

  if (block4.is_used()) {
    TNode<Uint8T> tmp24;
    TNode<BoolT> tmp25;
    TNode<Uint16T> tmp26;
    TNode<Uint32T> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block4, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Uint32T>tmp29 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::CBits>(ca_.UncheckedCast<Word32T>(tmp24)));
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp29}, TNode<Uint32T>{tmp27});
    ca_.Branch(tmp30, &block6, &block7, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Uint8T> tmp31;
    TNode<BoolT> tmp32;
    TNode<Uint16T> tmp33;
    TNode<Uint32T> tmp34;
    TNode<BoolT> tmp35;
    ca_.Bind(&block7, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.c == expectedC' failed", "test/torque/test-torque.tq", 1060);
  }

  if (block6.is_used()) {
    TNode<Uint8T> tmp36;
    TNode<BoolT> tmp37;
    TNode<Uint16T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<BoolT>tmp41 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::DBit>(ca_.UncheckedCast<Word32T>(tmp36)));
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp41}, TNode<BoolT>{tmp40});
    ca_.Branch(tmp42, &block8, &block9, tmp36, tmp37, tmp38, tmp39, tmp40);
  }

  if (block9.is_used()) {
    TNode<Uint8T> tmp43;
    TNode<BoolT> tmp44;
    TNode<Uint16T> tmp45;
    TNode<Uint32T> tmp46;
    TNode<BoolT> tmp47;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.d == expectedD' failed", "test/torque/test-torque.tq", 1061);
  }

  if (block8.is_used()) {
    TNode<Uint8T> tmp48;
    TNode<BoolT> tmp49;
    TNode<Uint16T> tmp50;
    TNode<Uint32T> tmp51;
    TNode<BoolT> tmp52;
    ca_.Bind(&block8, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Goto(&block10, tmp48, tmp49, tmp50, tmp51, tmp52);
  }

    TNode<Uint8T> tmp53;
    TNode<BoolT> tmp54;
    TNode<Uint16T> tmp55;
    TNode<Uint32T> tmp56;
    TNode<BoolT> tmp57;
    ca_.Bind(&block10, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
}

void TestBitFieldStore_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_val);

  if (block0.is_used()) {
    TNode<Uint8T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT>tmp1 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::ABit>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<Uint16T>tmp2 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::BBits>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<Uint32T>tmp3 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::CBits>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<BoolT>tmp4 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::DBit>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    TNode<Uint8T>tmp6 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<TorqueGeneratedTestBitFieldStructFields::ABit>(ca_.UncheckedCast<Word32T>(tmp0), ca_.UncheckedCast<Uint32T>(tmp5)));
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp6}, TNode<BoolT>{tmp7}, TNode<Uint16T>{tmp2}, TNode<Uint32T>{tmp3}, TNode<BoolT>{tmp4});
    TNode<Uint32T>tmp8 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::CBits>(ca_.UncheckedCast<Word32T>(tmp6)));
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp8});
    TNode<Int32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp10}, TNode<Int32T>{tmp9});
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp11});
    TNode<Uint8T>tmp13 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<TorqueGeneratedTestBitFieldStructFields::CBits>(ca_.UncheckedCast<Word32T>(tmp6), ca_.UncheckedCast<Uint32T>(tmp12)));
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp13}, TNode<BoolT>{tmp14}, TNode<Uint16T>{tmp2}, TNode<Uint32T>{tmp12}, TNode<BoolT>{tmp4});
    TNode<Uint16T>tmp15 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::BBits>(ca_.UncheckedCast<Word32T>(tmp13)));
    TNode<Uint32T>tmp16 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<TorqueGeneratedTestBitFieldStructFields::CBits>(ca_.UncheckedCast<Word32T>(tmp13)));
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp15}, TNode<Uint32T>{tmp16});
    TNode<Uint8T>tmp18 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<TorqueGeneratedTestBitFieldStructFields::DBit>(ca_.UncheckedCast<Word32T>(tmp13), ca_.UncheckedCast<Uint32T>(tmp17)));
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp12});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp18}, TNode<BoolT>{tmp19}, TNode<Uint16T>{tmp2}, TNode<Uint32T>{tmp12}, TNode<BoolT>{tmp20});
    ca_.Goto(&block2, tmp0);
  }

    TNode<Uint8T> tmp21;
    ca_.Bind(&block2, &tmp21);
}

void TestBitFieldUintptrOps_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_val2, TNode<UintPtrT> p_val3) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT, Uint32T, UintPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_val2, p_val3);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    TNode<UintPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<UintPtrT>tmp2 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::ABits>(ca_.UncheckedCast<Word32T>(tmp0)));
    TNode<UintPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Uint32T> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Uint32T> tmp7;
    TNode<UintPtrT> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "test/torque/test-torque.tq", 1103);
  }

  if (block2.is_used()) {
    TNode<Uint32T> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Uint32T> tmp11;
    TNode<UintPtrT> tmp12;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<UintPtrT>tmp13 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp11)));
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_uintptr_constexpr_int31_0(state_, 61);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp14});
    ca_.Branch(tmp15, &block4, &block5, tmp9, tmp10, tmp11, tmp12);
  }

  if (block5.is_used()) {
    TNode<Uint32T> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<Uint32T> tmp18;
    TNode<UintPtrT> tmp19;
    ca_.Bind(&block5, &tmp16, &tmp17, &tmp18, &tmp19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 61' failed", "test/torque/test-torque.tq", 1104);
  }

  if (block4.is_used()) {
    TNode<Uint32T> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<Uint32T> tmp22;
    TNode<UintPtrT> tmp23;
    ca_.Bind(&block4, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT>tmp24 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<TorqueGeneratedTestBitFieldStruct3Fields::CBit>(ca_.UncheckedCast<WordT>(tmp23)));
    ca_.Branch(tmp24, &block6, &block7, tmp20, tmp21, tmp22, tmp23);
  }

  if (block7.is_used()) {
    TNode<Uint32T> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<Uint32T> tmp27;
    TNode<UintPtrT> tmp28;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.c' failed", "test/torque/test-torque.tq", 1105);
  }

  if (block6.is_used()) {
    TNode<Uint32T> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<Uint32T> tmp31;
    TNode<UintPtrT> tmp32;
    ca_.Bind(&block6, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<Uint32T>tmp33 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32FromWord<TorqueGeneratedTestBitFieldStruct3Fields::DBits>(ca_.UncheckedCast<WordT>(tmp32)));
    TNode<Uint32T> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_uint32_constexpr_int31_0(state_, 500);
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp33}, TNode<Uint32T>{tmp34});
    ca_.Branch(tmp35, &block8, &block9, tmp29, tmp30, tmp31, tmp32);
  }

  if (block9.is_used()) {
    TNode<Uint32T> tmp36;
    TNode<UintPtrT> tmp37;
    TNode<Uint32T> tmp38;
    TNode<UintPtrT> tmp39;
    ca_.Bind(&block9, &tmp36, &tmp37, &tmp38, &tmp39);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.d == 500' failed", "test/torque/test-torque.tq", 1106);
  }

  if (block8.is_used()) {
    TNode<Uint32T> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Uint32T> tmp42;
    TNode<UintPtrT> tmp43;
    ca_.Bind(&block8, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<UintPtrT>tmp44 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWord<TorqueGeneratedTestBitFieldStruct3Fields::EBits>(ca_.UncheckedCast<WordT>(tmp43)));
    TNode<UintPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_uintptr_constexpr_int31_0(state_, 460);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp44}, TNode<UintPtrT>{tmp45});
    ca_.Branch(tmp46, &block10, &block11, tmp40, tmp41, tmp42, tmp43);
  }

  if (block11.is_used()) {
    TNode<Uint32T> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Uint32T> tmp49;
    TNode<UintPtrT> tmp50;
    ca_.Bind(&block11, &tmp47, &tmp48, &tmp49, &tmp50);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.e == 0x1cc' failed", "test/torque/test-torque.tq", 1107);
  }

  if (block10.is_used()) {
    TNode<Uint32T> tmp51;
    TNode<UintPtrT> tmp52;
    TNode<Uint32T> tmp53;
    TNode<UintPtrT> tmp54;
    ca_.Bind(&block10, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<UintPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_uintptr_constexpr_int31_0(state_, 16);
    TNode<Uint32T>tmp56 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWordInWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp53), ca_.UncheckedCast<UintPtrT>(tmp55)));
    TNode<UintPtrT>tmp57 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::ABits>(ca_.UncheckedCast<Word32T>(tmp56)));
    TNode<UintPtrT> tmp58;
    USE(tmp58);
    tmp58 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp57}, TNode<UintPtrT>{tmp58});
    ca_.Branch(tmp59, &block12, &block13, tmp51, tmp52, tmp56, tmp54);
  }

  if (block13.is_used()) {
    TNode<Uint32T> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<Uint32T> tmp62;
    TNode<UintPtrT> tmp63;
    ca_.Bind(&block13, &tmp60, &tmp61, &tmp62, &tmp63);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "test/torque/test-torque.tq", 1110);
  }

  if (block12.is_used()) {
    TNode<Uint32T> tmp64;
    TNode<UintPtrT> tmp65;
    TNode<Uint32T> tmp66;
    TNode<UintPtrT> tmp67;
    ca_.Bind(&block12, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<UintPtrT>tmp68 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp66)));
    TNode<UintPtrT> tmp69;
    USE(tmp69);
    tmp69 = FromConstexpr_uintptr_constexpr_int31_0(state_, 16);
    TNode<BoolT> tmp70;
    USE(tmp70);
    tmp70 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp68}, TNode<UintPtrT>{tmp69});
    ca_.Branch(tmp70, &block14, &block15, tmp64, tmp65, tmp66, tmp67);
  }

  if (block15.is_used()) {
    TNode<Uint32T> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<Uint32T> tmp73;
    TNode<UintPtrT> tmp74;
    ca_.Bind(&block15, &tmp71, &tmp72, &tmp73, &tmp74);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 16' failed", "test/torque/test-torque.tq", 1111);
  }

  if (block14.is_used()) {
    TNode<Uint32T> tmp75;
    TNode<UintPtrT> tmp76;
    TNode<Uint32T> tmp77;
    TNode<UintPtrT> tmp78;
    ca_.Bind(&block14, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<UintPtrT>tmp79 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp77)));
    TNode<UintPtrT> tmp80;
    USE(tmp80);
    tmp80 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp79}, TNode<UintPtrT>{tmp80});
    TNode<Uint32T>tmp82 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWordInWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp77), ca_.UncheckedCast<UintPtrT>(tmp81)));
    TNode<UintPtrT>tmp83 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::ABits>(ca_.UncheckedCast<Word32T>(tmp82)));
    TNode<UintPtrT> tmp84;
    USE(tmp84);
    tmp84 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp85;
    USE(tmp85);
    tmp85 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp83}, TNode<UintPtrT>{tmp84});
    ca_.Branch(tmp85, &block16, &block17, tmp75, tmp76, tmp82, tmp78);
  }

  if (block17.is_used()) {
    TNode<Uint32T> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<Uint32T> tmp88;
    TNode<UintPtrT> tmp89;
    ca_.Bind(&block17, &tmp86, &tmp87, &tmp88, &tmp89);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "test/torque/test-torque.tq", 1114);
  }

  if (block16.is_used()) {
    TNode<Uint32T> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<Uint32T> tmp92;
    TNode<UintPtrT> tmp93;
    ca_.Bind(&block16, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<UintPtrT>tmp94 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<TorqueGeneratedTestBitFieldStruct2Fields::BBits>(ca_.UncheckedCast<Word32T>(tmp92)));
    TNode<UintPtrT> tmp95;
    USE(tmp95);
    tmp95 = FromConstexpr_uintptr_constexpr_int31_0(state_, 17);
    TNode<BoolT> tmp96;
    USE(tmp96);
    tmp96 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp94}, TNode<UintPtrT>{tmp95});
    ca_.Branch(tmp96, &block18, &block19, tmp90, tmp91, tmp92, tmp93);
  }

  if (block19.is_used()) {
    TNode<Uint32T> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<Uint32T> tmp99;
    TNode<UintPtrT> tmp100;
    ca_.Bind(&block19, &tmp97, &tmp98, &tmp99, &tmp100);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 17' failed", "test/torque/test-torque.tq", 1115);
  }

  if (block18.is_used()) {
    TNode<Uint32T> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<Uint32T> tmp103;
    TNode<UintPtrT> tmp104;
    ca_.Bind(&block18, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<Uint32T> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_uint32_constexpr_int31_0(state_, 99);
    TNode<UintPtrT>tmp106 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).UpdateWord32InWord<TorqueGeneratedTestBitFieldStruct3Fields::DBits>(ca_.UncheckedCast<WordT>(tmp104), ca_.UncheckedCast<Uint32T>(tmp105)));
    TNode<UintPtrT> tmp107;
    USE(tmp107);
    tmp107 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1234);
    TNode<UintPtrT>tmp108 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).UpdateWord<TorqueGeneratedTestBitFieldStruct3Fields::EBits>(ca_.UncheckedCast<WordT>(tmp106), ca_.UncheckedCast<UintPtrT>(tmp107)));
    TNode<BoolT>tmp109 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<TorqueGeneratedTestBitFieldStruct3Fields::CBit>(ca_.UncheckedCast<WordT>(tmp108)));
    ca_.Branch(tmp109, &block20, &block21, tmp101, tmp102, tmp103, tmp108);
  }

  if (block21.is_used()) {
    TNode<Uint32T> tmp110;
    TNode<UintPtrT> tmp111;
    TNode<Uint32T> tmp112;
    TNode<UintPtrT> tmp113;
    ca_.Bind(&block21, &tmp110, &tmp111, &tmp112, &tmp113);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.c' failed", "test/torque/test-torque.tq", 1119);
  }

  if (block20.is_used()) {
    TNode<Uint32T> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<Uint32T> tmp116;
    TNode<UintPtrT> tmp117;
    ca_.Bind(&block20, &tmp114, &tmp115, &tmp116, &tmp117);
    TNode<Uint32T>tmp118 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32FromWord<TorqueGeneratedTestBitFieldStruct3Fields::DBits>(ca_.UncheckedCast<WordT>(tmp117)));
    TNode<Uint32T> tmp119;
    USE(tmp119);
    tmp119 = FromConstexpr_uint32_constexpr_int31_0(state_, 99);
    TNode<BoolT> tmp120;
    USE(tmp120);
    tmp120 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp118}, TNode<Uint32T>{tmp119});
    ca_.Branch(tmp120, &block22, &block23, tmp114, tmp115, tmp116, tmp117);
  }

  if (block23.is_used()) {
    TNode<Uint32T> tmp121;
    TNode<UintPtrT> tmp122;
    TNode<Uint32T> tmp123;
    TNode<UintPtrT> tmp124;
    ca_.Bind(&block23, &tmp121, &tmp122, &tmp123, &tmp124);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.d == 99' failed", "test/torque/test-torque.tq", 1120);
  }

  if (block22.is_used()) {
    TNode<Uint32T> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<Uint32T> tmp127;
    TNode<UintPtrT> tmp128;
    ca_.Bind(&block22, &tmp125, &tmp126, &tmp127, &tmp128);
    TNode<UintPtrT>tmp129 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWord<TorqueGeneratedTestBitFieldStruct3Fields::EBits>(ca_.UncheckedCast<WordT>(tmp128)));
    TNode<UintPtrT> tmp130;
    USE(tmp130);
    tmp130 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1234);
    TNode<BoolT> tmp131;
    USE(tmp131);
    tmp131 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp129}, TNode<UintPtrT>{tmp130});
    ca_.Branch(tmp131, &block24, &block25, tmp125, tmp126, tmp127, tmp128);
  }

  if (block25.is_used()) {
    TNode<Uint32T> tmp132;
    TNode<UintPtrT> tmp133;
    TNode<Uint32T> tmp134;
    TNode<UintPtrT> tmp135;
    ca_.Bind(&block25, &tmp132, &tmp133, &tmp134, &tmp135);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.e == 1234' failed", "test/torque/test-torque.tq", 1121);
  }

  if (block24.is_used()) {
    TNode<Uint32T> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<Uint32T> tmp138;
    TNode<UintPtrT> tmp139;
    ca_.Bind(&block24, &tmp136, &tmp137, &tmp138, &tmp139);
    ca_.Goto(&block26, tmp136, tmp137);
  }

    TNode<Uint32T> tmp140;
    TNode<UintPtrT> tmp141;
    ca_.Bind(&block26, &tmp140, &tmp141);
}

TNode<Smi> LoadInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<InternalClass> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<InternalClass> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<InternalClass> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<InternalClass> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

void Method_InternalClass_Flip_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_this, compiler::CodeAssemblerLabel* label_NotASmi) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_Smi_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp2);
    }
  }

  if (block4.is_used()) {
    TNode<InternalClass> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block4, &tmp4, &tmp5);
    ca_.Goto(label_NotASmi);
  }

  if (block3.is_used()) {
    TNode<InternalClass> tmp6;
    TNode<Number> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp11 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp10});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp6, tmp9}, tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp12}, tmp8);
    ca_.Goto(&block5, tmp6);
  }

    TNode<InternalClass> tmp13;
    ca_.Bind(&block5, &tmp13);
}

TNode<Smi> LoadSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TorqueStructReference_Smi_0 Method_SmiPair_GetA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    ca_.Goto(&block2, tmp0, tmp0, tmp1);
  }

    TNode<SmiPair> tmp2;
    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4);
  return TorqueStructReference_Smi_0{TNode<HeapObject>{tmp3}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}};
}

TNode<Smi> LoadSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TF_BUILTIN(GenericBuiltinTest_Smi_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TNode<Object> GenericMacroTest_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__param);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Object>{tmp3};
}

TNode<Object> GenericMacroTestWithLabels_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param, compiler::CodeAssemblerLabel* label__X) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__param);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block3, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp2, &tmp3);
  return TNode<Object>{tmp3};
}

TNode<Object> IncrementIfSmi_NumberOrFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    ca_.Goto(&block1, tmp2, ca_.UncheckedCast<HeapObject>(tmp3));
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    ca_.Goto(&block1, tmp5, tmp10);
  }

  if (block1.is_used()) {
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block1, &tmp11, &tmp12);
    ca_.Goto(&block6, tmp11, tmp12);
  }

    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block6, &tmp13, &tmp14);
  return TNode<Object>{tmp14};
}

TNode<Smi> ExampleGenericOverload_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

TNode<Object> ExampleGenericOverload_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Object>{tmp2};
}

TNode<BoolT> Is_JSArray_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Smi, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Smi, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Smi> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Smi> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Smi> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

void InitializeFieldsFromIterator_Object_TestIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructTestIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, IntPtrT, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, IntPtrT, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_target.object, p_target.offset, p_target.length, p_originIterator.count);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp6, tmp3);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Smi> tmp10;
    TNode<HeapObject> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp15, &block3, &block4, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    ca_.Branch(tmp24, &block9, &block10, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Smi> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Smi> tmp32;
    ca_.Bind(&block9, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block4, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Smi> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<Smi> tmp40;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp37}, TNode<IntPtrT>{tmp38}).Flatten();
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp43});
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp40}, TNode<Smi>{tmp45});
    TNode<Smi> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp40}, TNode<Smi>{tmp47});
    ca_.Branch(tmp48, &block16, &block17, tmp33, tmp34, tmp35, tmp36, tmp37, tmp44, tmp39, tmp46, tmp41, tmp42, tmp41, tmp42);
  }

  if (block16.is_used()) {
    TNode<HeapObject> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Smi> tmp52;
    TNode<HeapObject> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Smi> tmp56;
    TNode<HeapObject> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<HeapObject> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block16, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<HeapObject> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Smi> tmp64;
    TNode<HeapObject> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<Smi> tmp68;
    TNode<HeapObject> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<HeapObject> tmp71;
    TNode<IntPtrT> tmp72;
    ca_.Bind(&block17, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<Oddball> tmp73;
    USE(tmp73);
    tmp73 = TheHole_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp71, tmp72}, tmp73);
    ca_.Goto(&block5, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<Smi> tmp77;
    TNode<HeapObject> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<Smi> tmp81;
    ca_.Bind(&block4, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    ca_.Goto(&block18, tmp74, tmp75, tmp76, tmp77);
  }

    TNode<HeapObject> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Smi> tmp85;
    ca_.Bind(&block18, &tmp82, &tmp83, &tmp84, &tmp85);
}

void Swap_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Smi_0 p_a, TorqueStructReference_Smi_0 p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a.object, p_a.offset, p_b.object, p_b.offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1}, tmp5);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp4);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<HeapObject> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
}

TorqueStructTestTuple_Smi_intptr_0 TupleSwap_intptr_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructTestTuple_intptr_Smi_0 p_tuple) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_tuple.fst, p_tuple.snd);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp1, tmp0);
  }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{tmp4}, TNode<IntPtrT>{tmp5}};
}

}  // namespace internal
}  // namespace v8

