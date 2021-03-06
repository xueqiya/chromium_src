// services/tracing/public/mojom/tracing_service.mojom-shared-internal.h is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_TRACING_PUBLIC_MOJOM_TRACING_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_TRACING_PUBLIC_MOJOM_TRACING_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "services/tracing/public/mojom/perfetto_service.mojom-shared-internal.h"
#include "services/tracing/public/mojom/traced_process.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/interfaces/bindings/native_struct.mojom-shared-internal.h"
#include "base/component_export.h"



namespace mojo {
namespace internal {
class ValidationContext;
}
}
namespace tracing {
namespace mojom {
namespace internal {
class ClientInfo_Data;

#pragma pack(push, 1)
class COMPONENT_EXPORT(TRACING_MOJOM_SHARED) ClientInfo_Data {
 public:
  class BufferWriter {
   public:
    BufferWriter() = default;

    void Allocate(mojo::internal::Buffer* serialization_buffer) {
      serialization_buffer_ = serialization_buffer;
      index_ = serialization_buffer_->Allocate(sizeof(ClientInfo_Data));
      new (data()) ClientInfo_Data();
    }

    bool is_null() const { return !serialization_buffer_; }
    ClientInfo_Data* data() {
      DCHECK(!is_null());
      return serialization_buffer_->Get<ClientInfo_Data>(index_);
    }
    ClientInfo_Data* operator->() { return data(); }

   private:
    mojo::internal::Buffer* serialization_buffer_ = nullptr;
    size_t index_ = 0;

    DISALLOW_COPY_AND_ASSIGN(BufferWriter);
  };

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t pid;
  mojo::internal::Interface_Data process;
  uint8_t padfinal_[4];

 private:
  ClientInfo_Data();
  ~ClientInfo_Data() = delete;
};
static_assert(sizeof(ClientInfo_Data) == 24,
              "Bad sizeof(ClientInfo_Data)");
// Used by ClientInfo::WrapAsMessage to lazily serialize the struct.
template <typename UserType, typename DataView>
struct ClientInfo_UnserializedMessageContext
    : public mojo::internal::UnserializedMessageContext {
 public:
  static const mojo::internal::UnserializedMessageContext::Tag kMessageTag;

  ClientInfo_UnserializedMessageContext(
    uint32_t message_name,
    uint32_t message_flags,
    UserType input)
      : mojo::internal::UnserializedMessageContext(&kMessageTag, message_name, message_flags)
      , user_data_(std::move(input)) {}
  ~ClientInfo_UnserializedMessageContext() override = default;

  UserType TakeData() {
    return std::move(user_data_);
  }

 private:
  // mojo::internal::UnserializedMessageContext:
  void Serialize(mojo::internal::SerializationContext* context,
                 mojo::internal::Buffer* buffer) override {
    ClientInfo_Data::BufferWriter writer;
    mojo::internal::Serialize<DataView>(user_data_, buffer, &writer, context);
  }

  UserType user_data_;
};

template <typename UserType, typename DataView>
const mojo::internal::UnserializedMessageContext::Tag
    ClientInfo_UnserializedMessageContext<UserType, DataView>::kMessageTag = {};

#pragma pack(pop)

}  // namespace internal
}  // namespace mojom
}  // namespace tracing

#endif  // SERVICES_TRACING_PUBLIC_MOJOM_TRACING_SERVICE_MOJOM_SHARED_INTERNAL_H_