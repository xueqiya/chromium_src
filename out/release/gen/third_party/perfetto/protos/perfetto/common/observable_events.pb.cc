// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/common/observable_events.proto

#include "protos/perfetto/common/observable_events.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto;
namespace perfetto {
namespace protos {
class ObservableEvents_DataSourceInstanceStateChangeDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ObservableEvents_DataSourceInstanceStateChange> _instance;
} _ObservableEvents_DataSourceInstanceStateChange_default_instance_;
class ObservableEventsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ObservableEvents> _instance;
} _ObservableEvents_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_ObservableEvents_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ObservableEvents_default_instance_;
    new (ptr) ::perfetto::protos::ObservableEvents();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::perfetto::protos::ObservableEvents::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ObservableEvents_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_ObservableEvents_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto}, {
      &scc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto.base,}};

static void InitDefaultsscc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ObservableEvents_DataSourceInstanceStateChange_default_instance_;
    new (ptr) ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto}, {}};

namespace perfetto {
namespace protos {
bool ObservableEvents_Type_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ObservableEvents_Type_strings[2] = {};

static const char ObservableEvents_Type_names[] =
  "TYPE_DATA_SOURCES_INSTANCES"
  "TYPE_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ObservableEvents_Type_entries[] = {
  { {ObservableEvents_Type_names + 0, 27}, 1 },
  { {ObservableEvents_Type_names + 27, 16}, 0 },
};

static const int ObservableEvents_Type_entries_by_number[] = {
  1, // 0 -> TYPE_UNSPECIFIED
  0, // 1 -> TYPE_DATA_SOURCES_INSTANCES
};

const std::string& ObservableEvents_Type_Name(
    ObservableEvents_Type value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ObservableEvents_Type_entries,
          ObservableEvents_Type_entries_by_number,
          2, ObservableEvents_Type_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ObservableEvents_Type_entries,
      ObservableEvents_Type_entries_by_number,
      2, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ObservableEvents_Type_strings[idx].get();
}
bool ObservableEvents_Type_Parse(
    const std::string& name, ObservableEvents_Type* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ObservableEvents_Type_entries, 2, name, &int_value);
  if (success) {
    *value = static_cast<ObservableEvents_Type>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr ObservableEvents_Type ObservableEvents::TYPE_UNSPECIFIED;
constexpr ObservableEvents_Type ObservableEvents::TYPE_DATA_SOURCES_INSTANCES;
constexpr ObservableEvents_Type ObservableEvents::Type_MIN;
constexpr ObservableEvents_Type ObservableEvents::Type_MAX;
constexpr int ObservableEvents::Type_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
bool ObservableEvents_DataSourceInstanceState_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ObservableEvents_DataSourceInstanceState_strings[2] = {};

static const char ObservableEvents_DataSourceInstanceState_names[] =
  "DATA_SOURCE_INSTANCE_STATE_STARTED"
  "DATA_SOURCE_INSTANCE_STATE_STOPPED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ObservableEvents_DataSourceInstanceState_entries[] = {
  { {ObservableEvents_DataSourceInstanceState_names + 0, 34}, 2 },
  { {ObservableEvents_DataSourceInstanceState_names + 34, 34}, 1 },
};

static const int ObservableEvents_DataSourceInstanceState_entries_by_number[] = {
  1, // 1 -> DATA_SOURCE_INSTANCE_STATE_STOPPED
  0, // 2 -> DATA_SOURCE_INSTANCE_STATE_STARTED
};

const std::string& ObservableEvents_DataSourceInstanceState_Name(
    ObservableEvents_DataSourceInstanceState value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ObservableEvents_DataSourceInstanceState_entries,
          ObservableEvents_DataSourceInstanceState_entries_by_number,
          2, ObservableEvents_DataSourceInstanceState_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ObservableEvents_DataSourceInstanceState_entries,
      ObservableEvents_DataSourceInstanceState_entries_by_number,
      2, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ObservableEvents_DataSourceInstanceState_strings[idx].get();
}
bool ObservableEvents_DataSourceInstanceState_Parse(
    const std::string& name, ObservableEvents_DataSourceInstanceState* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ObservableEvents_DataSourceInstanceState_entries, 2, name, &int_value);
  if (success) {
    *value = static_cast<ObservableEvents_DataSourceInstanceState>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DATA_SOURCE_INSTANCE_STATE_STOPPED;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DATA_SOURCE_INSTANCE_STATE_STARTED;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DataSourceInstanceState_MIN;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DataSourceInstanceState_MAX;
constexpr int ObservableEvents::DataSourceInstanceState_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void ObservableEvents_DataSourceInstanceStateChange::InitAsDefaultInstance() {
}
class ObservableEvents_DataSourceInstanceStateChange::_Internal {
 public:
  using HasBits = decltype(std::declval<ObservableEvents_DataSourceInstanceStateChange>()._has_bits_);
  static void set_has_producer_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_data_source_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_state(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

ObservableEvents_DataSourceInstanceStateChange::ObservableEvents_DataSourceInstanceStateChange()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
}
ObservableEvents_DataSourceInstanceStateChange::ObservableEvents_DataSourceInstanceStateChange(const ObservableEvents_DataSourceInstanceStateChange& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  producer_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_producer_name()) {
    producer_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.producer_name_);
  }
  data_source_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_data_source_name()) {
    data_source_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_source_name_);
  }
  state_ = from.state_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
}

void ObservableEvents_DataSourceInstanceStateChange::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto.base);
  producer_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_source_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  state_ = 1;
}

ObservableEvents_DataSourceInstanceStateChange::~ObservableEvents_DataSourceInstanceStateChange() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  SharedDtor();
}

void ObservableEvents_DataSourceInstanceStateChange::SharedDtor() {
  producer_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_source_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ObservableEvents_DataSourceInstanceStateChange::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ObservableEvents_DataSourceInstanceStateChange& ObservableEvents_DataSourceInstanceStateChange::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ObservableEvents_DataSourceInstanceStateChange_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto.base);
  return *internal_default_instance();
}


void ObservableEvents_DataSourceInstanceStateChange::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      producer_name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      data_source_name_.ClearNonDefaultToEmptyNoArena();
    }
    state_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ObservableEvents_DataSourceInstanceStateChange::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string producer_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_producer_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string data_source_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_data_source_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::perfetto::protos::ObservableEvents_DataSourceInstanceState_IsValid(val))) {
            set_state(static_cast<::perfetto::protos::ObservableEvents_DataSourceInstanceState>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(3, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool ObservableEvents_DataSourceInstanceStateChange::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string producer_name = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_producer_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string data_source_name = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_data_source_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (24 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::perfetto::protos::ObservableEvents_DataSourceInstanceState_IsValid(value)) {
            set_state(static_cast< ::perfetto::protos::ObservableEvents_DataSourceInstanceState >(value));
          } else {
            unknown_fields_stream.WriteVarint32(24u);
            unknown_fields_stream.WriteVarint32(
                static_cast<::PROTOBUF_NAMESPACE_ID::uint32>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ObservableEvents_DataSourceInstanceStateChange::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string producer_name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->producer_name(), output);
  }

  // optional string data_source_name = 2;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->data_source_name(), output);
  }

  // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      3, this->state(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
}

size_t ObservableEvents_DataSourceInstanceStateChange::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional string producer_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->producer_name());
    }

    // optional string data_source_name = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->data_source_name());
    }

    // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->state());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObservableEvents_DataSourceInstanceStateChange::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ObservableEvents_DataSourceInstanceStateChange*>(
      &from));
}

void ObservableEvents_DataSourceInstanceStateChange::MergeFrom(const ObservableEvents_DataSourceInstanceStateChange& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      producer_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.producer_name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      data_source_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_source_name_);
    }
    if (cached_has_bits & 0x00000004u) {
      state_ = from.state_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ObservableEvents_DataSourceInstanceStateChange::CopyFrom(const ObservableEvents_DataSourceInstanceStateChange& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObservableEvents_DataSourceInstanceStateChange::IsInitialized() const {
  return true;
}

void ObservableEvents_DataSourceInstanceStateChange::InternalSwap(ObservableEvents_DataSourceInstanceStateChange* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  producer_name_.Swap(&other->producer_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  data_source_name_.Swap(&other->data_source_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(state_, other->state_);
}

std::string ObservableEvents_DataSourceInstanceStateChange::GetTypeName() const {
  return "perfetto.protos.ObservableEvents.DataSourceInstanceStateChange";
}


// ===================================================================

void ObservableEvents::InitAsDefaultInstance() {
}
class ObservableEvents::_Internal {
 public:
  using HasBits = decltype(std::declval<ObservableEvents>()._has_bits_);
};

ObservableEvents::ObservableEvents()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:perfetto.protos.ObservableEvents)
}
ObservableEvents::ObservableEvents(const ObservableEvents& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      instance_state_changes_(from.instance_state_changes_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObservableEvents)
}

void ObservableEvents::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ObservableEvents_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto.base);
}

ObservableEvents::~ObservableEvents() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObservableEvents)
  SharedDtor();
}

void ObservableEvents::SharedDtor() {
}

void ObservableEvents::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ObservableEvents& ObservableEvents::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ObservableEvents_protos_2fperfetto_2fcommon_2fobservable_5fevents_2eproto.base);
  return *internal_default_instance();
}


void ObservableEvents::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObservableEvents)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  instance_state_changes_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ObservableEvents::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(add_instance_state_changes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 10);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool ObservableEvents::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:perfetto.protos.ObservableEvents)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
                input, add_instance_state_changes()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:perfetto.protos.ObservableEvents)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:perfetto.protos.ObservableEvents)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ObservableEvents::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:perfetto.protos.ObservableEvents)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->instance_state_changes_size()); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessage(
      1,
      this->instance_state_changes(static_cast<int>(i)),
      output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:perfetto.protos.ObservableEvents)
}

size_t ObservableEvents::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObservableEvents)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->instance_state_changes_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          this->instance_state_changes(static_cast<int>(i)));
    }
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObservableEvents::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ObservableEvents*>(
      &from));
}

void ObservableEvents::MergeFrom(const ObservableEvents& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObservableEvents)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  instance_state_changes_.MergeFrom(from.instance_state_changes_);
}

void ObservableEvents::CopyFrom(const ObservableEvents& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObservableEvents)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObservableEvents::IsInitialized() const {
  return true;
}

void ObservableEvents::InternalSwap(ObservableEvents* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  CastToBase(&instance_state_changes_)->InternalSwap(CastToBase(&other->instance_state_changes_));
}

std::string ObservableEvents::GetTypeName() const {
  return "perfetto.protos.ObservableEvents";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange* Arena::CreateMaybeMessage< ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange >(Arena* arena) {
  return Arena::CreateInternal< ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObservableEvents* Arena::CreateMaybeMessage< ::perfetto::protos::ObservableEvents >(Arena* arena) {
  return Arena::CreateInternal< ::perfetto::protos::ObservableEvents >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
