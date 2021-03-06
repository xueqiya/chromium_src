// services/device/public/mojom/nfc.mojom-shared.h is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_DEVICE_PUBLIC_MOJOM_NFC_MOJOM_SHARED_H_
#define SERVICES_DEVICE_PUBLIC_MOJOM_NFC_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "base/containers/flat_map.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/device/public/mojom/nfc.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/interface_serialization.h"






namespace device {
namespace mojom {
class NDEFErrorDataView;

class NDEFRecordDataView;

class NDEFMessageDataView;

class NDEFWriteOptionsDataView;

class NDEFScanOptionsDataView;



}  // namespace mojom
}  // namespace device

namespace mojo {
namespace internal {

template <>
struct MojomTypeTraits<::device::mojom::NDEFErrorDataView> {
  using Data = ::device::mojom::internal::NDEFError_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::kStruct;
};

template <>
struct MojomTypeTraits<::device::mojom::NDEFRecordDataView> {
  using Data = ::device::mojom::internal::NDEFRecord_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::kStruct;
};

template <>
struct MojomTypeTraits<::device::mojom::NDEFMessageDataView> {
  using Data = ::device::mojom::internal::NDEFMessage_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::kStruct;
};

template <>
struct MojomTypeTraits<::device::mojom::NDEFWriteOptionsDataView> {
  using Data = ::device::mojom::internal::NDEFWriteOptions_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::kStruct;
};

template <>
struct MojomTypeTraits<::device::mojom::NDEFScanOptionsDataView> {
  using Data = ::device::mojom::internal::NDEFScanOptions_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::kStruct;
};

}  // namespace internal
}  // namespace mojo


namespace device {
namespace mojom {


enum class NDEFErrorType : int32_t {
  
  NOT_ALLOWED,
  
  NOT_SUPPORTED,
  
  NOT_READABLE,
  
  NOT_FOUND,
  
  INVALID_MESSAGE,
  
  OPERATION_CANCELLED,
  
  CANNOT_CANCEL,
  
  IO_ERROR,
  kMinValue = 0,
  kMaxValue = 7,
};

 std::ostream& operator<<(std::ostream& os, NDEFErrorType value);
inline bool IsKnownEnumValue(NDEFErrorType value) {
  return internal::NDEFErrorType_Data::IsKnownValue(
      static_cast<int32_t>(value));
}


enum class NDEFRecordTypeCategory : int32_t {
  
  kStandardized,
  
  kExternal,
  
  kLocal,
  kMinValue = 0,
  kMaxValue = 2,
};

 std::ostream& operator<<(std::ostream& os, NDEFRecordTypeCategory value);
inline bool IsKnownEnumValue(NDEFRecordTypeCategory value) {
  return internal::NDEFRecordTypeCategory_Data::IsKnownValue(
      static_cast<int32_t>(value));
}
// Interface base classes. They are used for type safety check.
class NFCInterfaceBase {};

using NFCPtrDataView =
    mojo::InterfacePtrDataView<NFCInterfaceBase>;
using NFCRequestDataView =
    mojo::InterfaceRequestDataView<NFCInterfaceBase>;
using NFCAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<NFCInterfaceBase>;
using NFCAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<NFCInterfaceBase>;
class NFCClientInterfaceBase {};

using NFCClientPtrDataView =
    mojo::InterfacePtrDataView<NFCClientInterfaceBase>;
using NFCClientRequestDataView =
    mojo::InterfaceRequestDataView<NFCClientInterfaceBase>;
using NFCClientAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<NFCClientInterfaceBase>;
using NFCClientAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<NFCClientInterfaceBase>;
class NDEFErrorDataView {
 public:
  NDEFErrorDataView() {}

  NDEFErrorDataView(
      internal::NDEFError_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadErrorType(UserType* output) const {
    auto data_value = data_->error_type;
    return mojo::internal::Deserialize<::device::mojom::NDEFErrorType>(
        data_value, output);
  }

  NDEFErrorType error_type() const {
    return static_cast<NDEFErrorType>(data_->error_type);
  }
  inline void GetErrorMessageDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadErrorMessage(UserType* output) {
    auto* pointer = data_->error_message.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::NDEFError_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class NDEFRecordDataView {
 public:
  NDEFRecordDataView() {}

  NDEFRecordDataView(
      internal::NDEFRecord_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadCategory(UserType* output) const {
    auto data_value = data_->category;
    return mojo::internal::Deserialize<::device::mojom::NDEFRecordTypeCategory>(
        data_value, output);
  }

  NDEFRecordTypeCategory category() const {
    return static_cast<NDEFRecordTypeCategory>(data_->category);
  }
  inline void GetRecordTypeDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadRecordType(UserType* output) {
    auto* pointer = data_->record_type.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetMediaTypeDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadMediaType(UserType* output) {
    auto* pointer = data_->media_type.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetIdDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadId(UserType* output) {
    auto* pointer = data_->id.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetEncodingDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadEncoding(UserType* output) {
    auto* pointer = data_->encoding.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetLangDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadLang(UserType* output) {
    auto* pointer = data_->lang.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetDataDataView(
      mojo::ArrayDataView<uint8_t>* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadData(UserType* output) {
    auto* pointer = data_->data.Get();
    return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
        pointer, output, context_);
  }
  inline void GetPayloadMessageDataView(
      NDEFMessageDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadPayloadMessage(UserType* output) {
    auto* pointer = data_->payload_message.Get();
    return mojo::internal::Deserialize<::device::mojom::NDEFMessageDataView>(
        pointer, output, context_);
  }
 private:
  internal::NDEFRecord_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class NDEFMessageDataView {
 public:
  NDEFMessageDataView() {}

  NDEFMessageDataView(
      internal::NDEFMessage_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetDataDataView(
      mojo::ArrayDataView<NDEFRecordDataView>* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadData(UserType* output) {
    auto* pointer = data_->data.Get();
    return mojo::internal::Deserialize<mojo::ArrayDataView<::device::mojom::NDEFRecordDataView>>(
        pointer, output, context_);
  }
 private:
  internal::NDEFMessage_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class NDEFWriteOptionsDataView {
 public:
  NDEFWriteOptionsDataView() {}

  NDEFWriteOptionsDataView(
      internal::NDEFWriteOptions_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data) {}

  bool is_null() const { return !data_; }
  bool ignore_read() const {
    return data_->ignore_read;
  }
  bool overwrite() const {
    return data_->overwrite;
  }
 private:
  internal::NDEFWriteOptions_Data* data_ = nullptr;
};

class NDEFScanOptionsDataView {
 public:
  NDEFScanOptionsDataView() {}

  NDEFScanOptionsDataView(
      internal::NDEFScanOptions_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetIdDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadId(UserType* output) {
    auto* pointer = data_->id.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetRecordTypeDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadRecordType(UserType* output) {
    auto* pointer = data_->record_type.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  inline void GetMediaTypeDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadMediaType(UserType* output) {
    auto* pointer = data_->media_type.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::NDEFScanOptions_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};



}  // namespace mojom
}  // namespace device

namespace std {

template <>
struct hash<::device::mojom::NDEFErrorType>
    : public mojo::internal::EnumHashImpl<::device::mojom::NDEFErrorType> {};

template <>
struct hash<::device::mojom::NDEFRecordTypeCategory>
    : public mojo::internal::EnumHashImpl<::device::mojom::NDEFRecordTypeCategory> {};

}  // namespace std

namespace mojo {


template <>
struct EnumTraits<::device::mojom::NDEFErrorType, ::device::mojom::NDEFErrorType> {
  static ::device::mojom::NDEFErrorType ToMojom(::device::mojom::NDEFErrorType input) { return input; }
  static bool FromMojom(::device::mojom::NDEFErrorType input, ::device::mojom::NDEFErrorType* output) {
    *output = input;
    return true;
  }
};

namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFErrorType, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = EnumTraits<::device::mojom::NDEFErrorType, UserType>;

  static void Serialize(UserType input, int32_t* output) {
    *output = static_cast<int32_t>(Traits::ToMojom(input));
  }

  static bool Deserialize(int32_t input, UserType* output) {
    return Traits::FromMojom(static_cast<::device::mojom::NDEFErrorType>(input), output);
  }
};

}  // namespace internal


template <>
struct EnumTraits<::device::mojom::NDEFRecordTypeCategory, ::device::mojom::NDEFRecordTypeCategory> {
  static ::device::mojom::NDEFRecordTypeCategory ToMojom(::device::mojom::NDEFRecordTypeCategory input) { return input; }
  static bool FromMojom(::device::mojom::NDEFRecordTypeCategory input, ::device::mojom::NDEFRecordTypeCategory* output) {
    *output = input;
    return true;
  }
};

namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFRecordTypeCategory, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = EnumTraits<::device::mojom::NDEFRecordTypeCategory, UserType>;

  static void Serialize(UserType input, int32_t* output) {
    *output = static_cast<int32_t>(Traits::ToMojom(input));
  }

  static bool Deserialize(int32_t input, UserType* output) {
    return Traits::FromMojom(static_cast<::device::mojom::NDEFRecordTypeCategory>(input), output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFErrorDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::device::mojom::NDEFErrorDataView, UserType>;

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::device::mojom::internal::NDEFError_Data::BufferWriter* output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return;
    (*output).Allocate(buffer);
    mojo::internal::Serialize<::device::mojom::NDEFErrorType>(
        Traits::error_type(input), &(*output)->error_type);
    decltype(Traits::error_message(input)) in_error_message = Traits::error_message(input);
    typename decltype((*output)->error_message)::BaseType::BufferWriter
        error_message_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_error_message, buffer, &error_message_writer, context);
    (*output)->error_message.Set(
        error_message_writer.is_null() ? nullptr : error_message_writer.data());
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        (*output)->error_message.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null error_message in NDEFError struct");
  }

  static bool Deserialize(::device::mojom::internal::NDEFError_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::device::mojom::NDEFErrorDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFRecordDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::device::mojom::NDEFRecordDataView, UserType>;

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::device::mojom::internal::NDEFRecord_Data::BufferWriter* output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return;
    (*output).Allocate(buffer);
    mojo::internal::Serialize<::device::mojom::NDEFRecordTypeCategory>(
        Traits::category(input), &(*output)->category);
    decltype(Traits::record_type(input)) in_record_type = Traits::record_type(input);
    typename decltype((*output)->record_type)::BaseType::BufferWriter
        record_type_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_record_type, buffer, &record_type_writer, context);
    (*output)->record_type.Set(
        record_type_writer.is_null() ? nullptr : record_type_writer.data());
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        (*output)->record_type.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null record_type in NDEFRecord struct");
    decltype(Traits::media_type(input)) in_media_type = Traits::media_type(input);
    typename decltype((*output)->media_type)::BaseType::BufferWriter
        media_type_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_media_type, buffer, &media_type_writer, context);
    (*output)->media_type.Set(
        media_type_writer.is_null() ? nullptr : media_type_writer.data());
    decltype(Traits::id(input)) in_id = Traits::id(input);
    typename decltype((*output)->id)::BaseType::BufferWriter
        id_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_id, buffer, &id_writer, context);
    (*output)->id.Set(
        id_writer.is_null() ? nullptr : id_writer.data());
    decltype(Traits::encoding(input)) in_encoding = Traits::encoding(input);
    typename decltype((*output)->encoding)::BaseType::BufferWriter
        encoding_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_encoding, buffer, &encoding_writer, context);
    (*output)->encoding.Set(
        encoding_writer.is_null() ? nullptr : encoding_writer.data());
    decltype(Traits::lang(input)) in_lang = Traits::lang(input);
    typename decltype((*output)->lang)::BaseType::BufferWriter
        lang_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_lang, buffer, &lang_writer, context);
    (*output)->lang.Set(
        lang_writer.is_null() ? nullptr : lang_writer.data());
    decltype(Traits::data(input)) in_data = Traits::data(input);
    typename decltype((*output)->data)::BaseType::BufferWriter
        data_writer;
    const mojo::internal::ContainerValidateParams data_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
        in_data, buffer, &data_writer, &data_validate_params,
        context);
    (*output)->data.Set(
        data_writer.is_null() ? nullptr : data_writer.data());
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        (*output)->data.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null data in NDEFRecord struct");
    decltype(Traits::payload_message(input)) in_payload_message = Traits::payload_message(input);
    typename decltype((*output)->payload_message)::BaseType::BufferWriter
        payload_message_writer;
    mojo::internal::Serialize<::device::mojom::NDEFMessageDataView>(
        in_payload_message, buffer, &payload_message_writer, context);
    (*output)->payload_message.Set(
        payload_message_writer.is_null() ? nullptr : payload_message_writer.data());
  }

  static bool Deserialize(::device::mojom::internal::NDEFRecord_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::device::mojom::NDEFRecordDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFMessageDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::device::mojom::NDEFMessageDataView, UserType>;

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::device::mojom::internal::NDEFMessage_Data::BufferWriter* output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return;
    (*output).Allocate(buffer);
    decltype(Traits::data(input)) in_data = Traits::data(input);
    typename decltype((*output)->data)::BaseType::BufferWriter
        data_writer;
    const mojo::internal::ContainerValidateParams data_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<::device::mojom::NDEFRecordDataView>>(
        in_data, buffer, &data_writer, &data_validate_params,
        context);
    (*output)->data.Set(
        data_writer.is_null() ? nullptr : data_writer.data());
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        (*output)->data.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null data in NDEFMessage struct");
  }

  static bool Deserialize(::device::mojom::internal::NDEFMessage_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::device::mojom::NDEFMessageDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFWriteOptionsDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::device::mojom::NDEFWriteOptionsDataView, UserType>;

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::device::mojom::internal::NDEFWriteOptions_Data::BufferWriter* output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return;
    (*output).Allocate(buffer);
    (*output)->ignore_read = Traits::ignore_read(input);
    (*output)->overwrite = Traits::overwrite(input);
  }

  static bool Deserialize(::device::mojom::internal::NDEFWriteOptions_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::device::mojom::NDEFWriteOptionsDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::device::mojom::NDEFScanOptionsDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::device::mojom::NDEFScanOptionsDataView, UserType>;

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::device::mojom::internal::NDEFScanOptions_Data::BufferWriter* output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return;
    (*output).Allocate(buffer);
    decltype(Traits::id(input)) in_id = Traits::id(input);
    typename decltype((*output)->id)::BaseType::BufferWriter
        id_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_id, buffer, &id_writer, context);
    (*output)->id.Set(
        id_writer.is_null() ? nullptr : id_writer.data());
    decltype(Traits::record_type(input)) in_record_type = Traits::record_type(input);
    typename decltype((*output)->record_type)::BaseType::BufferWriter
        record_type_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_record_type, buffer, &record_type_writer, context);
    (*output)->record_type.Set(
        record_type_writer.is_null() ? nullptr : record_type_writer.data());
    decltype(Traits::media_type(input)) in_media_type = Traits::media_type(input);
    typename decltype((*output)->media_type)::BaseType::BufferWriter
        media_type_writer;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_media_type, buffer, &media_type_writer, context);
    (*output)->media_type.Set(
        media_type_writer.is_null() ? nullptr : media_type_writer.data());
  }

  static bool Deserialize(::device::mojom::internal::NDEFScanOptions_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::device::mojom::NDEFScanOptionsDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal

}  // namespace mojo


namespace device {
namespace mojom {

inline void NDEFErrorDataView::GetErrorMessageDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->error_message.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void NDEFRecordDataView::GetRecordTypeDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->record_type.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFRecordDataView::GetMediaTypeDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->media_type.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFRecordDataView::GetIdDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->id.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFRecordDataView::GetEncodingDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->encoding.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFRecordDataView::GetLangDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->lang.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFRecordDataView::GetDataDataView(
    mojo::ArrayDataView<uint8_t>* output) {
  auto pointer = data_->data.Get();
  *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
}
inline void NDEFRecordDataView::GetPayloadMessageDataView(
    NDEFMessageDataView* output) {
  auto pointer = data_->payload_message.Get();
  *output = NDEFMessageDataView(pointer, context_);
}


inline void NDEFMessageDataView::GetDataDataView(
    mojo::ArrayDataView<NDEFRecordDataView>* output) {
  auto pointer = data_->data.Get();
  *output = mojo::ArrayDataView<NDEFRecordDataView>(pointer, context_);
}




inline void NDEFScanOptionsDataView::GetIdDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->id.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFScanOptionsDataView::GetRecordTypeDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->record_type.Get();
  *output = mojo::StringDataView(pointer, context_);
}
inline void NDEFScanOptionsDataView::GetMediaTypeDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->media_type.Get();
  *output = mojo::StringDataView(pointer, context_);
}



}  // namespace mojom
}  // namespace device

#endif  // SERVICES_DEVICE_PUBLIC_MOJOM_NFC_MOJOM_SHARED_H_