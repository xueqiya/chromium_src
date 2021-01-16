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

TF_BUILTIN(ArrayFrom, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext, JSArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, Object, Symbol, NativeContext> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, Object, Symbol, NativeContext, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, Object, Symbol, NativeContext, JSReceiver> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, Object, Object, NativeContext> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, Object, Object, NativeContext, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, JSReceiver, Object, Map, NativeContext> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, JSReceiver, Object, Map, NativeContext, JSReceiver> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object, NativeContext, Object, NativeContext, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object, NativeContext, JSReceiver, Object, Object, Smi, Object> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object, Object> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi, JSReceiver, Object, Object, JSReceiver, Smi, Object, NativeContext, Object> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, JSReceiver, JSReceiver, Object, Map, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Object, Object, NativeContext> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Object, Object, NativeContext, JSReceiver> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Object> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi, Object, Object> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi, Object, Object> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi, Object, Object> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, Object, BoolT, JSReceiver, Number, JSReceiver, Smi> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<JSFunction> tmp13;
    USE(tmp13);
    tmp13 = GetArrayFunction_0(state_, TNode<Context>{tmp10});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp11}, TNode<HeapObject>{tmp13});
    ca_.Goto(&block5, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp14);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<BoolT> tmp20;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block5, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Branch(tmp28, &block1, &block2, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp29;
    TNode<RawPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block1, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp29}, TNode<RawPtrT>{tmp30}, TNode<IntPtrT>{tmp31}}, TNode<IntPtrT>{tmp34});
    TNode<JSArray> tmp36;
    USE(tmp36);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp36 = IteratorBuiltinsAssembler(state_).FastIterableToList(TNode<Context>{tmp32}, TNode<Object>{tmp35}, &label0);
    ca_.Goto(&block8, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35, tmp32, tmp36);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35, tmp32);
    }
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp37;
    TNode<RawPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<NativeContext> tmp43;
    ca_.Bind(&block9, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block2, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp44;
    TNode<RawPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<NativeContext> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<NativeContext> tmp50;
    TNode<JSArray> tmp51;
    ca_.Bind(&block8, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    arguments.PopAndReturn(tmp51);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    ca_.Bind(&block2, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<IntPtrT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp57});
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    TNode<IntPtrT> tmp61;
    USE(tmp61);
    tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp61});
    TNode<Oddball> tmp63;
    USE(tmp63);
    tmp63 = Undefined_0(state_);
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp60}, TNode<HeapObject>{tmp63});
    ca_.Branch(tmp64, &block10, &block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp58, tmp60, tmp62, tmp56, ca_.Uninitialized<BoolT>());
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp65;
    TNode<RawPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<NativeContext> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<Object> tmp72;
    TNode<Object> tmp73;
    TNode<BoolT> tmp74;
    ca_.Bind(&block10, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<BoolT> tmp75;
    USE(tmp75);
    tmp75 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block12, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp75);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp76;
    TNode<RawPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<NativeContext> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<BoolT> tmp85;
    ca_.Bind(&block11, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp82});
    TNode<BoolT> tmp87;
    USE(tmp87);
    tmp87 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp86});
    ca_.Branch(tmp87, &block13, &block14, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp88;
    TNode<RawPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<NativeContext> tmp91;
    TNode<Object> tmp92;
    TNode<Object> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<BoolT> tmp97;
    ca_.Bind(&block13, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp91}, MessageTemplate::kCalledNonCallable, TNode<Object>{tmp94});
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp98;
    TNode<RawPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<NativeContext> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<BoolT> tmp107;
    ca_.Bind(&block14, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block12, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp108);
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<NativeContext> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<Object> tmp115;
    TNode<Object> tmp116;
    TNode<Object> tmp117;
    TNode<BoolT> tmp118;
    ca_.Bind(&block12, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    TNode<Symbol> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).IteratorSymbolConstant();
    TNode<JSReceiver> tmp120;
    USE(tmp120);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp120 = GetMethod_0(state_, TNode<Context>{tmp112}, TNode<Object>{tmp114}, TNode<Name>{tmp119}, &label0, &label1, &result_1_0);
    ca_.Goto(&block19, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp114, tmp119, tmp112, tmp120);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp114, tmp119, tmp112);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block21, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp114, tmp119, tmp112, result_1_0.value());
    }
  }

  if (block20.is_used()) {
    TNode<RawPtrT> tmp121;
    TNode<RawPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<NativeContext> tmp124;
    TNode<Object> tmp125;
    TNode<Object> tmp126;
    TNode<Object> tmp127;
    TNode<Object> tmp128;
    TNode<Object> tmp129;
    TNode<BoolT> tmp130;
    TNode<Object> tmp131;
    TNode<Symbol> tmp132;
    TNode<NativeContext> tmp133;
    ca_.Bind(&block20, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<JSReceiver> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp124}, TNode<Object>{tmp126});
    TNode<Number> tmp135;
    USE(tmp135);
    tmp135 = GetLengthProperty_0(state_, TNode<Context>{tmp124}, TNode<Object>{tmp134});
    TNode<JSReceiver> tmp136;
    USE(tmp136);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp136 = Cast_Constructor_1(state_, TNode<Context>{tmp124}, TNode<Object>{tmp129}, &label0);
    ca_.Goto(&block49, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp134, tmp135, ca_.Uninitialized<JSReceiver>(), tmp129, tmp129, tmp124, tmp136);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block50, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp134, tmp135, ca_.Uninitialized<JSReceiver>(), tmp129, tmp129, tmp124);
    }
  }

  if (block21.is_used()) {
    TNode<RawPtrT> tmp137;
    TNode<RawPtrT> tmp138;
    TNode<IntPtrT> tmp139;
    TNode<NativeContext> tmp140;
    TNode<Object> tmp141;
    TNode<Object> tmp142;
    TNode<Object> tmp143;
    TNode<Object> tmp144;
    TNode<Object> tmp145;
    TNode<BoolT> tmp146;
    TNode<Object> tmp147;
    TNode<Symbol> tmp148;
    TNode<NativeContext> tmp149;
    TNode<Object> tmp150;
    ca_.Bind(&block21, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp140}, MessageTemplate::kIteratorSymbolNonCallable);
  }

  if (block19.is_used()) {
    TNode<RawPtrT> tmp151;
    TNode<RawPtrT> tmp152;
    TNode<IntPtrT> tmp153;
    TNode<NativeContext> tmp154;
    TNode<Object> tmp155;
    TNode<Object> tmp156;
    TNode<Object> tmp157;
    TNode<Object> tmp158;
    TNode<Object> tmp159;
    TNode<BoolT> tmp160;
    TNode<Object> tmp161;
    TNode<Symbol> tmp162;
    TNode<NativeContext> tmp163;
    TNode<JSReceiver> tmp164;
    ca_.Bind(&block19, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164);
    TNode<JSReceiver> tmp165;
    USE(tmp165);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp165 = Cast_Constructor_1(state_, TNode<Context>{tmp154}, TNode<Object>{tmp159}, &label0);
    ca_.Goto(&block24, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp164, ca_.Uninitialized<JSReceiver>(), tmp159, tmp159, tmp154, tmp165);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp164, ca_.Uninitialized<JSReceiver>(), tmp159, tmp159, tmp154);
    }
  }

  if (block25.is_used()) {
    TNode<RawPtrT> tmp166;
    TNode<RawPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<NativeContext> tmp169;
    TNode<Object> tmp170;
    TNode<Object> tmp171;
    TNode<Object> tmp172;
    TNode<Object> tmp173;
    TNode<Object> tmp174;
    TNode<BoolT> tmp175;
    TNode<JSReceiver> tmp176;
    TNode<JSReceiver> tmp177;
    TNode<Object> tmp178;
    TNode<Object> tmp179;
    TNode<NativeContext> tmp180;
    ca_.Bind(&block25, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180);
    TNode<Number> tmp181;
    USE(tmp181);
    tmp181 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<JSArray> tmp182;
    USE(tmp182);
    tmp182 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{tmp169}, TNode<Number>{tmp181});
    ca_.Goto(&block22, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp182, tmp178);
  }

  if (block24.is_used()) {
    TNode<RawPtrT> tmp183;
    TNode<RawPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<NativeContext> tmp186;
    TNode<Object> tmp187;
    TNode<Object> tmp188;
    TNode<Object> tmp189;
    TNode<Object> tmp190;
    TNode<Object> tmp191;
    TNode<BoolT> tmp192;
    TNode<JSReceiver> tmp193;
    TNode<JSReceiver> tmp194;
    TNode<Object> tmp195;
    TNode<Object> tmp196;
    TNode<NativeContext> tmp197;
    TNode<JSReceiver> tmp198;
    ca_.Bind(&block24, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198);
    TNode<JSReceiver> tmp199;
    USE(tmp199);
    tmp199 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp186}, TNode<JSReceiver>{tmp198});
    ca_.Goto(&block22, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp199, tmp195);
  }

  if (block22.is_used()) {
    TNode<RawPtrT> tmp200;
    TNode<RawPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<NativeContext> tmp203;
    TNode<Object> tmp204;
    TNode<Object> tmp205;
    TNode<Object> tmp206;
    TNode<Object> tmp207;
    TNode<Object> tmp208;
    TNode<BoolT> tmp209;
    TNode<JSReceiver> tmp210;
    TNode<JSReceiver> tmp211;
    TNode<Object> tmp212;
    ca_.Bind(&block22, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212);
    TNode<JSReceiver> tmp213;
    USE(tmp213);
    TNode<Object> tmp214;
    USE(tmp214);
    std::tie(tmp213, tmp214) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp203}, TNode<Object>{tmp205}, TNode<Object>{tmp210}).Flatten();
    TNode<Map> tmp215;
    USE(tmp215);
    tmp215 = GetIteratorResultMap_0(state_, TNode<Context>{tmp203});
    TNode<Smi> tmp216;
    USE(tmp216);
    tmp216 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block28, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp213, tmp214, tmp215, tmp216);
  }

  if (block28.is_used()) {
    TNode<RawPtrT> tmp217;
    TNode<RawPtrT> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<NativeContext> tmp220;
    TNode<Object> tmp221;
    TNode<Object> tmp222;
    TNode<Object> tmp223;
    TNode<Object> tmp224;
    TNode<Object> tmp225;
    TNode<BoolT> tmp226;
    TNode<JSReceiver> tmp227;
    TNode<JSReceiver> tmp228;
    TNode<JSReceiver> tmp229;
    TNode<Object> tmp230;
    TNode<Map> tmp231;
    TNode<Smi> tmp232;
    ca_.Bind(&block28, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232);
    TNode<BoolT> tmp233;
    USE(tmp233);
    tmp233 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp233, &block26, &block27, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232);
  }

  if (block26.is_used()) {
    TNode<RawPtrT> tmp234;
    TNode<RawPtrT> tmp235;
    TNode<IntPtrT> tmp236;
    TNode<NativeContext> tmp237;
    TNode<Object> tmp238;
    TNode<Object> tmp239;
    TNode<Object> tmp240;
    TNode<Object> tmp241;
    TNode<Object> tmp242;
    TNode<BoolT> tmp243;
    TNode<JSReceiver> tmp244;
    TNode<JSReceiver> tmp245;
    TNode<JSReceiver> tmp246;
    TNode<Object> tmp247;
    TNode<Map> tmp248;
    TNode<Smi> tmp249;
    ca_.Bind(&block26, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249);
    TNode<JSReceiver> tmp250;
    USE(tmp250);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp250 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp237}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp246}, TNode<Object>{tmp247}}, TNode<Map>{tmp248}, &label0);
    ca_.Goto(&block35, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, ca_.Uninitialized<JSReceiver>(), tmp246, tmp247, tmp248, tmp237, tmp250);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block36, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, ca_.Uninitialized<JSReceiver>(), tmp246, tmp247, tmp248, tmp237);
    }
  }

  if (block32.is_used()) {
    TNode<RawPtrT> tmp251;
    TNode<RawPtrT> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<NativeContext> tmp254;
    TNode<Object> tmp255;
    TNode<Object> tmp256;
    TNode<Object> tmp257;
    TNode<Object> tmp258;
    TNode<Object> tmp259;
    TNode<BoolT> tmp260;
    TNode<JSReceiver> tmp261;
    TNode<JSReceiver> tmp262;
    TNode<JSReceiver> tmp263;
    TNode<Object> tmp264;
    TNode<Map> tmp265;
    TNode<Smi> tmp266;
    ca_.Bind(&block32, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266);
    CodeStubAssembler(state_).FailAssert("Torque assert 'k < kMaxSafeInteger' failed", "src/builtins/array-from.tq", 81);
  }

  if (block31.is_used()) {
    TNode<RawPtrT> tmp267;
    TNode<RawPtrT> tmp268;
    TNode<IntPtrT> tmp269;
    TNode<NativeContext> tmp270;
    TNode<Object> tmp271;
    TNode<Object> tmp272;
    TNode<Object> tmp273;
    TNode<Object> tmp274;
    TNode<Object> tmp275;
    TNode<BoolT> tmp276;
    TNode<JSReceiver> tmp277;
    TNode<JSReceiver> tmp278;
    TNode<JSReceiver> tmp279;
    TNode<Object> tmp280;
    TNode<Map> tmp281;
    TNode<Smi> tmp282;
    ca_.Bind(&block31, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282);
  }

  if (block36.is_used()) {
    TNode<RawPtrT> tmp283;
    TNode<RawPtrT> tmp284;
    TNode<IntPtrT> tmp285;
    TNode<NativeContext> tmp286;
    TNode<Object> tmp287;
    TNode<Object> tmp288;
    TNode<Object> tmp289;
    TNode<Object> tmp290;
    TNode<Object> tmp291;
    TNode<BoolT> tmp292;
    TNode<JSReceiver> tmp293;
    TNode<JSReceiver> tmp294;
    TNode<JSReceiver> tmp295;
    TNode<Object> tmp296;
    TNode<Map> tmp297;
    TNode<Smi> tmp298;
    TNode<JSReceiver> tmp299;
    TNode<JSReceiver> tmp300;
    TNode<Object> tmp301;
    TNode<Map> tmp302;
    TNode<NativeContext> tmp303;
    ca_.Bind(&block36, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303);
    CodeStubAssembler(state_).SetPropertyLength(TNode<Context>{tmp286}, TNode<Object>{tmp294}, TNode<Number>{tmp298});
    arguments.PopAndReturn(tmp294);
  }

  if (block35.is_used()) {
    TNode<RawPtrT> tmp304;
    TNode<RawPtrT> tmp305;
    TNode<IntPtrT> tmp306;
    TNode<NativeContext> tmp307;
    TNode<Object> tmp308;
    TNode<Object> tmp309;
    TNode<Object> tmp310;
    TNode<Object> tmp311;
    TNode<Object> tmp312;
    TNode<BoolT> tmp313;
    TNode<JSReceiver> tmp314;
    TNode<JSReceiver> tmp315;
    TNode<JSReceiver> tmp316;
    TNode<Object> tmp317;
    TNode<Map> tmp318;
    TNode<Smi> tmp319;
    TNode<JSReceiver> tmp320;
    TNode<JSReceiver> tmp321;
    TNode<Object> tmp322;
    TNode<Map> tmp323;
    TNode<NativeContext> tmp324;
    TNode<JSReceiver> tmp325;
    ca_.Bind(&block35, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325);
    TNode<Object> tmp326;
    USE(tmp326);
    tmp326 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp307}, TNode<JSReceiver>{tmp325}, TNode<Map>{tmp318});
    ca_.Branch(tmp313, &block37, &block38, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp325, tmp326, ca_.Uninitialized<Object>());
  }

  if (block37.is_used()) {
    TNode<RawPtrT> tmp327;
    TNode<RawPtrT> tmp328;
    TNode<IntPtrT> tmp329;
    TNode<NativeContext> tmp330;
    TNode<Object> tmp331;
    TNode<Object> tmp332;
    TNode<Object> tmp333;
    TNode<Object> tmp334;
    TNode<Object> tmp335;
    TNode<BoolT> tmp336;
    TNode<JSReceiver> tmp337;
    TNode<JSReceiver> tmp338;
    TNode<JSReceiver> tmp339;
    TNode<Object> tmp340;
    TNode<Map> tmp341;
    TNode<Smi> tmp342;
    TNode<JSReceiver> tmp343;
    TNode<Object> tmp344;
    TNode<Object> tmp345;
    ca_.Bind(&block37, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345);
    TNode<JSReceiver> tmp346;
    USE(tmp346);
    compiler::CodeAssemblerExceptionHandlerLabel catch347__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch347__label);
    tmp346 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp330}, TNode<Object>{tmp333});
    }
    if (catch347__label.is_used()) {
      compiler::CodeAssemblerLabel catch347_skip(&ca_);
      ca_.Goto(&catch347_skip);
      TNode<Object> catch347_exception_object;
      ca_.Bind(&catch347__label, &catch347_exception_object);
      ca_.Goto(&block42, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp330, tmp333, tmp330, catch347_exception_object);
      ca_.Bind(&catch347_skip);
    }
    TNode<Object> tmp348;
    USE(tmp348);
    compiler::CodeAssemblerExceptionHandlerLabel catch349__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch349__label);
    tmp348 = CodeStubAssembler(state_).Call(TNode<Context>{tmp330}, TNode<Object>{tmp346}, TNode<Object>{tmp334}, TNode<Object>{tmp344}, TNode<Object>{tmp342});
    }
    if (catch349__label.is_used()) {
      compiler::CodeAssemblerLabel catch349_skip(&ca_);
      ca_.Goto(&catch349_skip);
      TNode<Object> catch349_exception_object;
      ca_.Bind(&catch349__label, &catch349_exception_object);
      ca_.Goto(&block43, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp330, tmp346, tmp334, tmp344, tmp342, catch349_exception_object);
      ca_.Bind(&catch349_skip);
    }
    ca_.Goto(&block39, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp348);
  }

  if (block42.is_used()) {
    TNode<RawPtrT> tmp350;
    TNode<RawPtrT> tmp351;
    TNode<IntPtrT> tmp352;
    TNode<NativeContext> tmp353;
    TNode<Object> tmp354;
    TNode<Object> tmp355;
    TNode<Object> tmp356;
    TNode<Object> tmp357;
    TNode<Object> tmp358;
    TNode<BoolT> tmp359;
    TNode<JSReceiver> tmp360;
    TNode<JSReceiver> tmp361;
    TNode<JSReceiver> tmp362;
    TNode<Object> tmp363;
    TNode<Map> tmp364;
    TNode<Smi> tmp365;
    TNode<JSReceiver> tmp366;
    TNode<Object> tmp367;
    TNode<Object> tmp368;
    TNode<NativeContext> tmp369;
    TNode<Object> tmp370;
    TNode<NativeContext> tmp371;
    TNode<Object> tmp372;
    ca_.Bind(&block42, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372);
    ca_.Goto(&block41, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362, tmp363, tmp364, tmp365, tmp366, tmp367, tmp368, tmp372);
  }

  if (block43.is_used()) {
    TNode<RawPtrT> tmp373;
    TNode<RawPtrT> tmp374;
    TNode<IntPtrT> tmp375;
    TNode<NativeContext> tmp376;
    TNode<Object> tmp377;
    TNode<Object> tmp378;
    TNode<Object> tmp379;
    TNode<Object> tmp380;
    TNode<Object> tmp381;
    TNode<BoolT> tmp382;
    TNode<JSReceiver> tmp383;
    TNode<JSReceiver> tmp384;
    TNode<JSReceiver> tmp385;
    TNode<Object> tmp386;
    TNode<Map> tmp387;
    TNode<Smi> tmp388;
    TNode<JSReceiver> tmp389;
    TNode<Object> tmp390;
    TNode<Object> tmp391;
    TNode<NativeContext> tmp392;
    TNode<JSReceiver> tmp393;
    TNode<Object> tmp394;
    TNode<Object> tmp395;
    TNode<Smi> tmp396;
    TNode<Object> tmp397;
    ca_.Bind(&block43, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397);
    ca_.Goto(&block41, tmp373, tmp374, tmp375, tmp376, tmp377, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp397);
  }

  if (block41.is_used()) {
    TNode<RawPtrT> tmp398;
    TNode<RawPtrT> tmp399;
    TNode<IntPtrT> tmp400;
    TNode<NativeContext> tmp401;
    TNode<Object> tmp402;
    TNode<Object> tmp403;
    TNode<Object> tmp404;
    TNode<Object> tmp405;
    TNode<Object> tmp406;
    TNode<BoolT> tmp407;
    TNode<JSReceiver> tmp408;
    TNode<JSReceiver> tmp409;
    TNode<JSReceiver> tmp410;
    TNode<Object> tmp411;
    TNode<Map> tmp412;
    TNode<Smi> tmp413;
    TNode<JSReceiver> tmp414;
    TNode<Object> tmp415;
    TNode<Object> tmp416;
    TNode<Object> tmp417;
    ca_.Bind(&block41, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417);
    IteratorBuiltinsAssembler(state_).IteratorCloseOnException(TNode<Context>{tmp401}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp410}, TNode<Object>{tmp411}}, TNode<Object>{tmp417});
  }

  if (block38.is_used()) {
    TNode<RawPtrT> tmp418;
    TNode<RawPtrT> tmp419;
    TNode<IntPtrT> tmp420;
    TNode<NativeContext> tmp421;
    TNode<Object> tmp422;
    TNode<Object> tmp423;
    TNode<Object> tmp424;
    TNode<Object> tmp425;
    TNode<Object> tmp426;
    TNode<BoolT> tmp427;
    TNode<JSReceiver> tmp428;
    TNode<JSReceiver> tmp429;
    TNode<JSReceiver> tmp430;
    TNode<Object> tmp431;
    TNode<Map> tmp432;
    TNode<Smi> tmp433;
    TNode<JSReceiver> tmp434;
    TNode<Object> tmp435;
    TNode<Object> tmp436;
    ca_.Bind(&block38, &tmp418, &tmp419, &tmp420, &tmp421, &tmp422, &tmp423, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431, &tmp432, &tmp433, &tmp434, &tmp435, &tmp436);
    ca_.Goto(&block39, tmp418, tmp419, tmp420, tmp421, tmp422, tmp423, tmp424, tmp425, tmp426, tmp427, tmp428, tmp429, tmp430, tmp431, tmp432, tmp433, tmp434, tmp435, tmp435);
  }

  if (block39.is_used()) {
    TNode<RawPtrT> tmp437;
    TNode<RawPtrT> tmp438;
    TNode<IntPtrT> tmp439;
    TNode<NativeContext> tmp440;
    TNode<Object> tmp441;
    TNode<Object> tmp442;
    TNode<Object> tmp443;
    TNode<Object> tmp444;
    TNode<Object> tmp445;
    TNode<BoolT> tmp446;
    TNode<JSReceiver> tmp447;
    TNode<JSReceiver> tmp448;
    TNode<JSReceiver> tmp449;
    TNode<Object> tmp450;
    TNode<Map> tmp451;
    TNode<Smi> tmp452;
    TNode<JSReceiver> tmp453;
    TNode<Object> tmp454;
    TNode<Object> tmp455;
    ca_.Bind(&block39, &tmp437, &tmp438, &tmp439, &tmp440, &tmp441, &tmp442, &tmp443, &tmp444, &tmp445, &tmp446, &tmp447, &tmp448, &tmp449, &tmp450, &tmp451, &tmp452, &tmp453, &tmp454, &tmp455);
    TNode<Object> tmp456;
    compiler::CodeAssemblerExceptionHandlerLabel catch457__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch457__label);
    tmp456 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp440, tmp448, tmp452, tmp455);
    USE(tmp456);
    }
    if (catch457__label.is_used()) {
      compiler::CodeAssemblerLabel catch457_skip(&ca_);
      ca_.Goto(&catch457_skip);
      TNode<Object> catch457_exception_object;
      ca_.Bind(&catch457__label, &catch457_exception_object);
      ca_.Goto(&block46, tmp437, tmp438, tmp439, tmp440, tmp441, tmp442, tmp443, tmp444, tmp445, tmp446, tmp447, tmp448, tmp449, tmp450, tmp451, tmp452, tmp453, tmp454, tmp455, tmp448, tmp452, tmp455, tmp440, catch457_exception_object);
      ca_.Bind(&catch457_skip);
    }
    TNode<Smi> tmp458;
    USE(tmp458);
    tmp458 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp459;
    USE(tmp459);
    tmp459 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp452}, TNode<Smi>{tmp458});
    ca_.Goto(&block28, tmp437, tmp438, tmp439, tmp440, tmp441, tmp442, tmp443, tmp444, tmp445, tmp446, tmp447, tmp448, tmp449, tmp450, tmp451, tmp459);
  }

  if (block46.is_used()) {
    TNode<RawPtrT> tmp460;
    TNode<RawPtrT> tmp461;
    TNode<IntPtrT> tmp462;
    TNode<NativeContext> tmp463;
    TNode<Object> tmp464;
    TNode<Object> tmp465;
    TNode<Object> tmp466;
    TNode<Object> tmp467;
    TNode<Object> tmp468;
    TNode<BoolT> tmp469;
    TNode<JSReceiver> tmp470;
    TNode<JSReceiver> tmp471;
    TNode<JSReceiver> tmp472;
    TNode<Object> tmp473;
    TNode<Map> tmp474;
    TNode<Smi> tmp475;
    TNode<JSReceiver> tmp476;
    TNode<Object> tmp477;
    TNode<Object> tmp478;
    TNode<JSReceiver> tmp479;
    TNode<Smi> tmp480;
    TNode<Object> tmp481;
    TNode<NativeContext> tmp482;
    TNode<Object> tmp483;
    ca_.Bind(&block46, &tmp460, &tmp461, &tmp462, &tmp463, &tmp464, &tmp465, &tmp466, &tmp467, &tmp468, &tmp469, &tmp470, &tmp471, &tmp472, &tmp473, &tmp474, &tmp475, &tmp476, &tmp477, &tmp478, &tmp479, &tmp480, &tmp481, &tmp482, &tmp483);
    IteratorBuiltinsAssembler(state_).IteratorCloseOnException(TNode<Context>{tmp463}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp472}, TNode<Object>{tmp473}}, TNode<Object>{tmp483});
  }

  if (block27.is_used()) {
    TNode<RawPtrT> tmp484;
    TNode<RawPtrT> tmp485;
    TNode<IntPtrT> tmp486;
    TNode<NativeContext> tmp487;
    TNode<Object> tmp488;
    TNode<Object> tmp489;
    TNode<Object> tmp490;
    TNode<Object> tmp491;
    TNode<Object> tmp492;
    TNode<BoolT> tmp493;
    TNode<JSReceiver> tmp494;
    TNode<JSReceiver> tmp495;
    TNode<JSReceiver> tmp496;
    TNode<Object> tmp497;
    TNode<Map> tmp498;
    TNode<Smi> tmp499;
    ca_.Bind(&block27, &tmp484, &tmp485, &tmp486, &tmp487, &tmp488, &tmp489, &tmp490, &tmp491, &tmp492, &tmp493, &tmp494, &tmp495, &tmp496, &tmp497, &tmp498, &tmp499);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block50.is_used()) {
    TNode<RawPtrT> tmp500;
    TNode<RawPtrT> tmp501;
    TNode<IntPtrT> tmp502;
    TNode<NativeContext> tmp503;
    TNode<Object> tmp504;
    TNode<Object> tmp505;
    TNode<Object> tmp506;
    TNode<Object> tmp507;
    TNode<Object> tmp508;
    TNode<BoolT> tmp509;
    TNode<JSReceiver> tmp510;
    TNode<Number> tmp511;
    TNode<JSReceiver> tmp512;
    TNode<Object> tmp513;
    TNode<Object> tmp514;
    TNode<NativeContext> tmp515;
    ca_.Bind(&block50, &tmp500, &tmp501, &tmp502, &tmp503, &tmp504, &tmp505, &tmp506, &tmp507, &tmp508, &tmp509, &tmp510, &tmp511, &tmp512, &tmp513, &tmp514, &tmp515);
    TNode<JSArray> tmp516;
    USE(tmp516);
    tmp516 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{tmp503}, TNode<Number>{tmp511});
    ca_.Goto(&block47, tmp500, tmp501, tmp502, tmp503, tmp504, tmp505, tmp506, tmp507, tmp508, tmp509, tmp510, tmp511, tmp516, tmp513);
  }

  if (block49.is_used()) {
    TNode<RawPtrT> tmp517;
    TNode<RawPtrT> tmp518;
    TNode<IntPtrT> tmp519;
    TNode<NativeContext> tmp520;
    TNode<Object> tmp521;
    TNode<Object> tmp522;
    TNode<Object> tmp523;
    TNode<Object> tmp524;
    TNode<Object> tmp525;
    TNode<BoolT> tmp526;
    TNode<JSReceiver> tmp527;
    TNode<Number> tmp528;
    TNode<JSReceiver> tmp529;
    TNode<Object> tmp530;
    TNode<Object> tmp531;
    TNode<NativeContext> tmp532;
    TNode<JSReceiver> tmp533;
    ca_.Bind(&block49, &tmp517, &tmp518, &tmp519, &tmp520, &tmp521, &tmp522, &tmp523, &tmp524, &tmp525, &tmp526, &tmp527, &tmp528, &tmp529, &tmp530, &tmp531, &tmp532, &tmp533);
    TNode<JSReceiver> tmp534;
    USE(tmp534);
    tmp534 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp520}, TNode<JSReceiver>{tmp533}, TNode<Object>{tmp528});
    ca_.Goto(&block47, tmp517, tmp518, tmp519, tmp520, tmp521, tmp522, tmp523, tmp524, tmp525, tmp526, tmp527, tmp528, tmp534, tmp530);
  }

  if (block47.is_used()) {
    TNode<RawPtrT> tmp535;
    TNode<RawPtrT> tmp536;
    TNode<IntPtrT> tmp537;
    TNode<NativeContext> tmp538;
    TNode<Object> tmp539;
    TNode<Object> tmp540;
    TNode<Object> tmp541;
    TNode<Object> tmp542;
    TNode<Object> tmp543;
    TNode<BoolT> tmp544;
    TNode<JSReceiver> tmp545;
    TNode<Number> tmp546;
    TNode<JSReceiver> tmp547;
    TNode<Object> tmp548;
    ca_.Bind(&block47, &tmp535, &tmp536, &tmp537, &tmp538, &tmp539, &tmp540, &tmp541, &tmp542, &tmp543, &tmp544, &tmp545, &tmp546, &tmp547, &tmp548);
    TNode<Smi> tmp549;
    USE(tmp549);
    tmp549 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block53, tmp535, tmp536, tmp537, tmp538, tmp539, tmp540, tmp541, tmp542, tmp543, tmp544, tmp545, tmp546, tmp547, tmp549);
  }

  if (block53.is_used()) {
    TNode<RawPtrT> tmp550;
    TNode<RawPtrT> tmp551;
    TNode<IntPtrT> tmp552;
    TNode<NativeContext> tmp553;
    TNode<Object> tmp554;
    TNode<Object> tmp555;
    TNode<Object> tmp556;
    TNode<Object> tmp557;
    TNode<Object> tmp558;
    TNode<BoolT> tmp559;
    TNode<JSReceiver> tmp560;
    TNode<Number> tmp561;
    TNode<JSReceiver> tmp562;
    TNode<Smi> tmp563;
    ca_.Bind(&block53, &tmp550, &tmp551, &tmp552, &tmp553, &tmp554, &tmp555, &tmp556, &tmp557, &tmp558, &tmp559, &tmp560, &tmp561, &tmp562, &tmp563);
    TNode<BoolT> tmp564;
    USE(tmp564);
    tmp564 = NumberIsLessThan_0(state_, TNode<Number>{tmp563}, TNode<Number>{tmp561});
    ca_.Branch(tmp564, &block51, &block52, tmp550, tmp551, tmp552, tmp553, tmp554, tmp555, tmp556, tmp557, tmp558, tmp559, tmp560, tmp561, tmp562, tmp563);
  }

  if (block51.is_used()) {
    TNode<RawPtrT> tmp565;
    TNode<RawPtrT> tmp566;
    TNode<IntPtrT> tmp567;
    TNode<NativeContext> tmp568;
    TNode<Object> tmp569;
    TNode<Object> tmp570;
    TNode<Object> tmp571;
    TNode<Object> tmp572;
    TNode<Object> tmp573;
    TNode<BoolT> tmp574;
    TNode<JSReceiver> tmp575;
    TNode<Number> tmp576;
    TNode<JSReceiver> tmp577;
    TNode<Smi> tmp578;
    ca_.Bind(&block51, &tmp565, &tmp566, &tmp567, &tmp568, &tmp569, &tmp570, &tmp571, &tmp572, &tmp573, &tmp574, &tmp575, &tmp576, &tmp577, &tmp578);
    TNode<Object> tmp579;
    USE(tmp579);
    tmp579 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp568}, TNode<Object>{tmp575}, TNode<Object>{tmp578});
    ca_.Branch(tmp574, &block54, &block55, tmp565, tmp566, tmp567, tmp568, tmp569, tmp570, tmp571, tmp572, tmp573, tmp574, tmp575, tmp576, tmp577, tmp578, tmp579, ca_.Uninitialized<Object>());
  }

  if (block54.is_used()) {
    TNode<RawPtrT> tmp580;
    TNode<RawPtrT> tmp581;
    TNode<IntPtrT> tmp582;
    TNode<NativeContext> tmp583;
    TNode<Object> tmp584;
    TNode<Object> tmp585;
    TNode<Object> tmp586;
    TNode<Object> tmp587;
    TNode<Object> tmp588;
    TNode<BoolT> tmp589;
    TNode<JSReceiver> tmp590;
    TNode<Number> tmp591;
    TNode<JSReceiver> tmp592;
    TNode<Smi> tmp593;
    TNode<Object> tmp594;
    TNode<Object> tmp595;
    ca_.Bind(&block54, &tmp580, &tmp581, &tmp582, &tmp583, &tmp584, &tmp585, &tmp586, &tmp587, &tmp588, &tmp589, &tmp590, &tmp591, &tmp592, &tmp593, &tmp594, &tmp595);
    TNode<JSReceiver> tmp596;
    USE(tmp596);
    tmp596 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp583}, TNode<Object>{tmp586});
    TNode<Object> tmp597;
    USE(tmp597);
    tmp597 = CodeStubAssembler(state_).Call(TNode<Context>{tmp583}, TNode<Object>{tmp596}, TNode<Object>{tmp587}, TNode<Object>{tmp594}, TNode<Object>{tmp593});
    ca_.Goto(&block56, tmp580, tmp581, tmp582, tmp583, tmp584, tmp585, tmp586, tmp587, tmp588, tmp589, tmp590, tmp591, tmp592, tmp593, tmp594, tmp597);
  }

  if (block55.is_used()) {
    TNode<RawPtrT> tmp598;
    TNode<RawPtrT> tmp599;
    TNode<IntPtrT> tmp600;
    TNode<NativeContext> tmp601;
    TNode<Object> tmp602;
    TNode<Object> tmp603;
    TNode<Object> tmp604;
    TNode<Object> tmp605;
    TNode<Object> tmp606;
    TNode<BoolT> tmp607;
    TNode<JSReceiver> tmp608;
    TNode<Number> tmp609;
    TNode<JSReceiver> tmp610;
    TNode<Smi> tmp611;
    TNode<Object> tmp612;
    TNode<Object> tmp613;
    ca_.Bind(&block55, &tmp598, &tmp599, &tmp600, &tmp601, &tmp602, &tmp603, &tmp604, &tmp605, &tmp606, &tmp607, &tmp608, &tmp609, &tmp610, &tmp611, &tmp612, &tmp613);
    ca_.Goto(&block56, tmp598, tmp599, tmp600, tmp601, tmp602, tmp603, tmp604, tmp605, tmp606, tmp607, tmp608, tmp609, tmp610, tmp611, tmp612, tmp612);
  }

  if (block56.is_used()) {
    TNode<RawPtrT> tmp614;
    TNode<RawPtrT> tmp615;
    TNode<IntPtrT> tmp616;
    TNode<NativeContext> tmp617;
    TNode<Object> tmp618;
    TNode<Object> tmp619;
    TNode<Object> tmp620;
    TNode<Object> tmp621;
    TNode<Object> tmp622;
    TNode<BoolT> tmp623;
    TNode<JSReceiver> tmp624;
    TNode<Number> tmp625;
    TNode<JSReceiver> tmp626;
    TNode<Smi> tmp627;
    TNode<Object> tmp628;
    TNode<Object> tmp629;
    ca_.Bind(&block56, &tmp614, &tmp615, &tmp616, &tmp617, &tmp618, &tmp619, &tmp620, &tmp621, &tmp622, &tmp623, &tmp624, &tmp625, &tmp626, &tmp627, &tmp628, &tmp629);
    TNode<Object> tmp630;
    tmp630 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp617, tmp626, tmp627, tmp629);
    USE(tmp630);
    TNode<Smi> tmp631;
    USE(tmp631);
    tmp631 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp632;
    USE(tmp632);
    tmp632 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp627}, TNode<Smi>{tmp631});
    ca_.Goto(&block53, tmp614, tmp615, tmp616, tmp617, tmp618, tmp619, tmp620, tmp621, tmp622, tmp623, tmp624, tmp625, tmp626, tmp632);
  }

  if (block52.is_used()) {
    TNode<RawPtrT> tmp633;
    TNode<RawPtrT> tmp634;
    TNode<IntPtrT> tmp635;
    TNode<NativeContext> tmp636;
    TNode<Object> tmp637;
    TNode<Object> tmp638;
    TNode<Object> tmp639;
    TNode<Object> tmp640;
    TNode<Object> tmp641;
    TNode<BoolT> tmp642;
    TNode<JSReceiver> tmp643;
    TNode<Number> tmp644;
    TNode<JSReceiver> tmp645;
    TNode<Smi> tmp646;
    ca_.Bind(&block52, &tmp633, &tmp634, &tmp635, &tmp636, &tmp637, &tmp638, &tmp639, &tmp640, &tmp641, &tmp642, &tmp643, &tmp644, &tmp645, &tmp646);
    CodeStubAssembler(state_).SetPropertyLength(TNode<Context>{tmp636}, TNode<Object>{tmp645}, TNode<Number>{tmp644});
    arguments.PopAndReturn(tmp645);
  }
}

TNode<JSReceiver> Cast_Constructor_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSReceiver> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_Constructor_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSReceiver> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSReceiver>{tmp20};
}

TNode<JSReceiver> UnsafeCast_Callable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
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
    TNode<JSReceiver> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSReceiver>{tmp9};
}

}  // namespace internal
}  // namespace v8

