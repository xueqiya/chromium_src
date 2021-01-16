#ifdef OBJECT_PRINT
#include "src/objects/objects.h"

#include <iosfwd>

#include "torque-generated/internal-class-definitions-tq-inl.h"
#include "src/objects/struct-inl.h"

#include "src/objects/template-objects-inl.h"

namespace v8 {
namespace internal {
template <>
void TorqueGeneratedStruct<Struct, HeapObject>::StructPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedStruct");
  os << "\n";
}

template <>
void TorqueGeneratedBreakPoint<BreakPoint, Struct>::BreakPointPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedBreakPoint");
  os << "\n - id: " << Brief(this->id());
  os << "\n - condition: " << Brief(this->condition());
  os << "\n";
}

template <>
void TorqueGeneratedBreakPointInfo<BreakPointInfo, Struct>::BreakPointInfoPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedBreakPointInfo");
  os << "\n - source_position: " << Brief(this->source_position());
  os << "\n - break_points: " << Brief(this->break_points());
  os << "\n";
}

template <>
void TorqueGeneratedEnumCache<EnumCache, Struct>::EnumCachePrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedEnumCache");
  os << "\n - keys: " << Brief(this->keys());
  os << "\n - indices: " << Brief(this->indices());
  os << "\n";
}

template <>
void TorqueGeneratedPropertyDescriptorObject<PropertyDescriptorObject, Struct>::PropertyDescriptorObjectPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedPropertyDescriptorObject");
  os << "\n - flags: " << Brief(this->flags());
  os << "\n - value: " << Brief(this->value());
  os << "\n - get: " << Brief(this->get());
  os << "\n - set: " << Brief(this->set());
  os << "\n";
}

template <>
void TorqueGeneratedTuple2<Tuple2, Struct>::Tuple2Print(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedTuple2");
  os << "\n - value1: " << Brief(this->value1());
  os << "\n - value2: " << Brief(this->value2());
  os << "\n";
}

template <>
void TorqueGeneratedCachedTemplateObject<CachedTemplateObject, Struct>::CachedTemplateObjectPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedCachedTemplateObject");
  os << "\n - slot_id: " << Brief(this->slot_id());
  os << "\n - template_object: " << Brief(this->template_object());
  os << "\n - next: " << Brief(this->next());
  os << "\n";
}

template <>
void TorqueGeneratedTemplateObjectDescription<TemplateObjectDescription, Struct>::TemplateObjectDescriptionPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedTemplateObjectDescription");
  os << "\n - raw_strings: " << Brief(this->raw_strings());
  os << "\n - cooked_strings: " << Brief(this->cooked_strings());
  os << "\n";
}

template <>
void TorqueGeneratedInternalClass<InternalClass, Struct>::InternalClassPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedInternalClass");
  os << "\n - a: " << Brief(this->a());
  os << "\n - b: " << Brief(this->b());
  os << "\n";
}

template <>
void TorqueGeneratedSmiPair<SmiPair, Struct>::SmiPairPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedSmiPair");
  os << "\n - a: " << Brief(this->a());
  os << "\n - b: " << Brief(this->b());
  os << "\n";
}

template <>
void TorqueGeneratedSmiBox<SmiBox, Struct>::SmiBoxPrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedSmiBox");
  os << "\n - value: " << Brief(this->value());
  os << "\n - unrelated: " << Brief(this->unrelated());
  os << "\n";
}

template <>
void TorqueGeneratedSortState<SortState, Struct>::SortStatePrint(std::ostream& os) {
  this->PrintHeader(os, "TorqueGeneratedSortState");
  os << "\n - receiver: " << Brief(this->receiver());
  os << "\n - initialReceiverMap: " << Brief(this->initialReceiverMap());
  os << "\n - initialReceiverLength: " << Brief(this->initialReceiverLength());
  os << "\n - userCmpFn: " << Brief(this->userCmpFn());
  os << "\n - sortComparePtr: " << Brief(this->sortComparePtr());
  os << "\n - loadFn: " << Brief(this->loadFn());
  os << "\n - storeFn: " << Brief(this->storeFn());
  os << "\n - deleteFn: " << Brief(this->deleteFn());
  os << "\n - canUseSameAccessorFn: " << Brief(this->canUseSameAccessorFn());
  os << "\n - minGallop: " << Brief(this->minGallop());
  os << "\n - pendingRunsSize: " << Brief(this->pendingRunsSize());
  os << "\n - pendingRuns: " << Brief(this->pendingRuns());
  os << "\n - workArray: " << Brief(this->workArray());
  os << "\n - tempArray: " << Brief(this->tempArray());
  os << "\n - sortLength: " << Brief(this->sortLength());
  os << "\n - numberOfUndefined: " << Brief(this->numberOfUndefined());
  os << "\n";
}

}  // namespace internal
}  // namespace v8
#endif  // OBJECT_PRINT
