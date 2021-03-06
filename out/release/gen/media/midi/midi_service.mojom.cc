// media/midi/midi_service.mojom.cc is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4056)
#pragma warning(disable:4065)
#pragma warning(disable:4756)
#endif

#include "media/midi/midi_service.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/hash/md5_constexpr.h"
#include "base/logging.h"
#include "base/run_loop.h"
#include "base/task/common/task_annotator.h"
#include "mojo/public/cpp/bindings/lib/generated_code_util.h"
#include "mojo/public/cpp/bindings/lib/message_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/unserialized_message_context.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"

#include "media/midi/midi_service.mojom-params-data.h"
#include "media/midi/midi_service.mojom-shared-message-ids.h"

#include "media/midi/midi_service.mojom-import-headers.h"


#ifndef MEDIA_MIDI_MIDI_SERVICE_MOJOM_JUMBO_H_
#define MEDIA_MIDI_MIDI_SERVICE_MOJOM_JUMBO_H_
#include "mojo/public/cpp/base/time_mojom_traits.h"
#endif
namespace midi {
namespace mojom {
PortInfo::PortInfo()
    : id(),
      manufacturer(),
      name(),
      version(),
      state() {}

PortInfo::PortInfo(
    const std::string& id_in,
    const std::string& manufacturer_in,
    const std::string& name_in,
    const std::string& version_in,
    PortState state_in)
    : id(std::move(id_in)),
      manufacturer(std::move(manufacturer_in)),
      name(std::move(name_in)),
      version(std::move(version_in)),
      state(std::move(state_in)) {}

PortInfo::~PortInfo() = default;
size_t PortInfo::Hash(size_t seed) const {
  seed = mojo::internal::Hash(seed, this->id);
  seed = mojo::internal::Hash(seed, this->manufacturer);
  seed = mojo::internal::Hash(seed, this->name);
  seed = mojo::internal::Hash(seed, this->version);
  seed = mojo::internal::Hash(seed, this->state);
  return seed;
}

bool PortInfo::Validate(
    const void* data,
    mojo::internal::ValidationContext* validation_context) {
  return Data_::Validate(data, validation_context);
}
const char MidiSessionClient::Name_[] = "midi.mojom.MidiSessionClient";

MidiSessionClientProxy::MidiSessionClientProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void MidiSessionClientProxy::AddInputPort(
    PortInfoPtr in_info) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::AddInputPort");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_AddInputPort_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_AddInputPort_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  typename decltype(params->info)::BaseType::BufferWriter
      info_writer;
  mojo::internal::Serialize<::midi::mojom::PortInfoDataView>(
      in_info, buffer, &info_writer, &serialization_context);
  params->info.Set(
      info_writer.is_null() ? nullptr : info_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->info.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null info in MidiSessionClient.AddInputPort request");
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("AddInputPort");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::AddOutputPort(
    PortInfoPtr in_info) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::AddOutputPort");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_AddOutputPort_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_AddOutputPort_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  typename decltype(params->info)::BaseType::BufferWriter
      info_writer;
  mojo::internal::Serialize<::midi::mojom::PortInfoDataView>(
      in_info, buffer, &info_writer, &serialization_context);
  params->info.Set(
      info_writer.is_null() ? nullptr : info_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->info.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null info in MidiSessionClient.AddOutputPort request");
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("AddOutputPort");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::SetInputPortState(
    uint32_t in_port, PortState in_state) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::SetInputPortState");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_SetInputPortState_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_SetInputPortState_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  params->port = in_port;
  mojo::internal::Serialize<::midi::mojom::PortState>(
      in_state, &params->state);
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("SetInputPortState");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::SetOutputPortState(
    uint32_t in_port, PortState in_state) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::SetOutputPortState");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_SetOutputPortState_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_SetOutputPortState_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  params->port = in_port;
  mojo::internal::Serialize<::midi::mojom::PortState>(
      in_state, &params->state);
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("SetOutputPortState");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::SessionStarted(
    Result in_result) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::SessionStarted");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_SessionStarted_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_SessionStarted_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  mojo::internal::Serialize<::midi::mojom::Result>(
      in_result, &params->result);
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("SessionStarted");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::AcknowledgeSentData(
    uint32_t in_bytes) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::AcknowledgeSentData");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_AcknowledgeSentData_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_AcknowledgeSentData_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  params->bytes = in_bytes;
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("AcknowledgeSentData");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

void MidiSessionClientProxy::DataReceived(
    uint32_t in_port, const std::vector<uint8_t>& in_data, ::base::TimeTicks in_timestamp) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionClient::DataReceived");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionClient_DataReceived_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionClient_DataReceived_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  params->port = in_port;
  typename decltype(params->data)::BaseType::BufferWriter
      data_writer;
  const mojo::internal::ContainerValidateParams data_validate_params(
      0, false, nullptr);
  mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
      in_data, buffer, &data_writer, &data_validate_params,
      &serialization_context);
  params->data.Set(
      data_writer.is_null() ? nullptr : data_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->data.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null data in MidiSessionClient.DataReceived request");
  typename decltype(params->timestamp)::BaseType::BufferWriter
      timestamp_writer;
  mojo::internal::Serialize<::mojo_base::mojom::TimeTicksDataView>(
      in_timestamp, buffer, &timestamp_writer, &serialization_context);
  params->timestamp.Set(
      timestamp_writer.is_null() ? nullptr : timestamp_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->timestamp.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null timestamp in MidiSessionClient.DataReceived request");
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionClient::Name_);
  message.set_method_name("DataReceived");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

// static
bool MidiSessionClientStubDispatch::Accept(
    MidiSessionClient* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kMidiSessionClient_AddInputPort_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::AddInputPort",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::AddInputPort");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_AddInputPort_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_AddInputPort_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      PortInfoPtr p_info{};
      MidiSessionClient_AddInputPort_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success && !input_data_view.ReadInfo(&p_info))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 0, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->AddInputPort(
std::move(p_info));
      return true;
    }
    case internal::kMidiSessionClient_AddOutputPort_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::AddOutputPort",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::AddOutputPort");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_AddOutputPort_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_AddOutputPort_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      PortInfoPtr p_info{};
      MidiSessionClient_AddOutputPort_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success && !input_data_view.ReadInfo(&p_info))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 1, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->AddOutputPort(
std::move(p_info));
      return true;
    }
    case internal::kMidiSessionClient_SetInputPortState_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::SetInputPortState",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::SetInputPortState");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_SetInputPortState_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_SetInputPortState_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      uint32_t p_port{};
      PortState p_state{};
      MidiSessionClient_SetInputPortState_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success)
        p_port = input_data_view.port();
      if (success && !input_data_view.ReadState(&p_state))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 2, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->SetInputPortState(
std::move(p_port), 
std::move(p_state));
      return true;
    }
    case internal::kMidiSessionClient_SetOutputPortState_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::SetOutputPortState",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::SetOutputPortState");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_SetOutputPortState_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_SetOutputPortState_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      uint32_t p_port{};
      PortState p_state{};
      MidiSessionClient_SetOutputPortState_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success)
        p_port = input_data_view.port();
      if (success && !input_data_view.ReadState(&p_state))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 3, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->SetOutputPortState(
std::move(p_port), 
std::move(p_state));
      return true;
    }
    case internal::kMidiSessionClient_SessionStarted_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::SessionStarted",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::SessionStarted");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_SessionStarted_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_SessionStarted_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      Result p_result{};
      MidiSessionClient_SessionStarted_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success && !input_data_view.ReadResult(&p_result))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 4, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->SessionStarted(
std::move(p_result));
      return true;
    }
    case internal::kMidiSessionClient_AcknowledgeSentData_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::AcknowledgeSentData",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::AcknowledgeSentData");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_AcknowledgeSentData_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_AcknowledgeSentData_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      uint32_t p_bytes{};
      MidiSessionClient_AcknowledgeSentData_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success)
        p_bytes = input_data_view.bytes();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 5, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->AcknowledgeSentData(
std::move(p_bytes));
      return true;
    }
    case internal::kMidiSessionClient_DataReceived_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionClient::DataReceived",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionClient::DataReceived");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionClient_DataReceived_Params_Data* params =
          reinterpret_cast<internal::MidiSessionClient_DataReceived_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      uint32_t p_port{};
      std::vector<uint8_t> p_data{};
      ::base::TimeTicks p_timestamp{};
      MidiSessionClient_DataReceived_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success)
        p_port = input_data_view.port();
      if (success && !input_data_view.ReadData(&p_data))
        success = false;
      if (success && !input_data_view.ReadTimestamp(&p_timestamp))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionClient::Name_, 6, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->DataReceived(
std::move(p_port), 
std::move(p_data), 
std::move(p_timestamp));
      return true;
    }
  }
  return false;
}

// static
bool MidiSessionClientStubDispatch::AcceptWithResponder(
    MidiSessionClient* impl,
    mojo::Message* message,
    std::unique_ptr<mojo::MessageReceiverWithStatus> responder) {
  switch (message->header()->name) {
    case internal::kMidiSessionClient_AddInputPort_Name: {
      break;
    }
    case internal::kMidiSessionClient_AddOutputPort_Name: {
      break;
    }
    case internal::kMidiSessionClient_SetInputPortState_Name: {
      break;
    }
    case internal::kMidiSessionClient_SetOutputPortState_Name: {
      break;
    }
    case internal::kMidiSessionClient_SessionStarted_Name: {
      break;
    }
    case internal::kMidiSessionClient_AcknowledgeSentData_Name: {
      break;
    }
    case internal::kMidiSessionClient_DataReceived_Name: {
      break;
    }
  }
  return false;
}


static const mojo::internal::GenericValidationInfo kMidiSessionClientValidationInfo[] = {
    {&internal::MidiSessionClient_AddInputPort_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_AddOutputPort_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_SetInputPortState_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_SetOutputPortState_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_SessionStarted_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_AcknowledgeSentData_Params_Data::Validate,
     nullptr /* no response */},
    {&internal::MidiSessionClient_DataReceived_Params_Data::Validate,
     nullptr /* no response */},
};

bool MidiSessionClientRequestValidator::Accept(mojo::Message* message) {
  const char* name = ::midi::mojom::MidiSessionClient::Name_;
  return mojo::internal::ValidateRequestGenericPacked(message, name, kMidiSessionClientValidationInfo);
}

const char MidiSessionProvider::Name_[] = "midi.mojom.MidiSessionProvider";

MidiSessionProviderProxy::MidiSessionProviderProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void MidiSessionProviderProxy::StartSession(
    mojo::PendingReceiver<MidiSession> in_receiver, mojo::PendingRemote<MidiSessionClient> in_client) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSessionProvider::StartSession");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSessionProvider_StartSession_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSessionProvider_StartSession_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  mojo::internal::Serialize<mojo::InterfaceRequestDataView<::midi::mojom::MidiSessionInterfaceBase>>(
      in_receiver, &params->receiver, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->receiver),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid receiver in MidiSessionProvider.StartSession request");
  mojo::internal::Serialize<mojo::InterfacePtrDataView<::midi::mojom::MidiSessionClientInterfaceBase>>(
      in_client, &params->client, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->client),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid client in MidiSessionProvider.StartSession request");
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSessionProvider::Name_);
  message.set_method_name("StartSession");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

// static
bool MidiSessionProviderStubDispatch::Accept(
    MidiSessionProvider* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kMidiSessionProvider_StartSession_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSessionProvider::StartSession",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSessionProvider::StartSession");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSessionProvider_StartSession_Params_Data* params =
          reinterpret_cast<internal::MidiSessionProvider_StartSession_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      mojo::PendingReceiver<MidiSession> p_receiver{};
      mojo::PendingRemote<MidiSessionClient> p_client{};
      MidiSessionProvider_StartSession_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success) {
        p_receiver =
            input_data_view.TakeReceiver<decltype(p_receiver)>();
      }
      if (success) {
        p_client =
            input_data_view.TakeClient<decltype(p_client)>();
      }
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSessionProvider::Name_, 0, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->StartSession(
std::move(p_receiver), 
std::move(p_client));
      return true;
    }
  }
  return false;
}

// static
bool MidiSessionProviderStubDispatch::AcceptWithResponder(
    MidiSessionProvider* impl,
    mojo::Message* message,
    std::unique_ptr<mojo::MessageReceiverWithStatus> responder) {
  switch (message->header()->name) {
    case internal::kMidiSessionProvider_StartSession_Name: {
      break;
    }
  }
  return false;
}


static const mojo::internal::GenericValidationInfo kMidiSessionProviderValidationInfo[] = {
    {&internal::MidiSessionProvider_StartSession_Params_Data::Validate,
     nullptr /* no response */},
};

bool MidiSessionProviderRequestValidator::Accept(mojo::Message* message) {
  const char* name = ::midi::mojom::MidiSessionProvider::Name_;
  return mojo::internal::ValidateRequestGenericPacked(message, name, kMidiSessionProviderValidationInfo);
}

const char MidiSession::Name_[] = "midi.mojom.MidiSession";

MidiSessionProxy::MidiSessionProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void MidiSessionProxy::SendData(
    uint32_t in_port, const std::vector<uint8_t>& in_data, ::base::TimeTicks in_timestamp) {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
  TRACE_EVENT0("mojom", "midi::mojom::MidiSession::SendData");
#endif
  const bool kExpectsResponse = false;
  const bool kIsSync = false;
  
  const uint32_t kFlags =
      ((kExpectsResponse) ? mojo::Message::kFlagExpectsResponse : 0) |
      ((kIsSync) ? mojo::Message::kFlagIsSync : 0);
  
  mojo::Message message(
      internal::kMidiSession_SendData_Name, kFlags, 0, 0, nullptr);
  auto* buffer = message.payload_buffer();
  ::midi::mojom::internal::MidiSession_SendData_Params_Data::BufferWriter
      params;
  mojo::internal::SerializationContext serialization_context;
  params.Allocate(buffer);
  params->port = in_port;
  typename decltype(params->data)::BaseType::BufferWriter
      data_writer;
  const mojo::internal::ContainerValidateParams data_validate_params(
      0, false, nullptr);
  mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
      in_data, buffer, &data_writer, &data_validate_params,
      &serialization_context);
  params->data.Set(
      data_writer.is_null() ? nullptr : data_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->data.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null data in MidiSession.SendData request");
  typename decltype(params->timestamp)::BaseType::BufferWriter
      timestamp_writer;
  mojo::internal::Serialize<::mojo_base::mojom::TimeTicksDataView>(
      in_timestamp, buffer, &timestamp_writer, &serialization_context);
  params->timestamp.Set(
      timestamp_writer.is_null() ? nullptr : timestamp_writer.data());
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->timestamp.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null timestamp in MidiSession.SendData request");
  message.AttachHandlesFromSerializationContext(
      &serialization_context);

#if defined(ENABLE_IPC_FUZZER)
  message.set_interface_name(MidiSession::Name_);
  message.set_method_name("SendData");
#endif
  // This return value may be ignored as false implies the Connector has
  // encountered an error, which will be visible through other means.
  ignore_result(receiver_->Accept(&message));
}

// static
bool MidiSessionStubDispatch::Accept(
    MidiSession* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kMidiSession_SendData_Name: {
#if BUILDFLAG(MOJO_TRACE_ENABLED)
      TRACE_EVENT1(
          "mojom",
          "(Impl)midi::mojom::MidiSession::SendData",
          "message", message->name());
#endif
      static constexpr uint32_t kMessageHash = base::MD5Hash32Constexpr(
              "(Impl)midi::mojom::MidiSession::SendData");
      base::TaskAnnotator::ScopedSetIpcHash scoped_ipc_hash(kMessageHash);
      mojo::internal::MessageDispatchContext dispatch_context(message);

      DCHECK(message->is_serialized());
      internal::MidiSession_SendData_Params_Data* params =
          reinterpret_cast<internal::MidiSession_SendData_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.TakeHandlesFromMessage(message);
      bool success = true;
      uint32_t p_port{};
      std::vector<uint8_t> p_data{};
      ::base::TimeTicks p_timestamp{};
      MidiSession_SendData_ParamsDataView input_data_view(params, &serialization_context);
      
      if (success)
        p_port = input_data_view.port();
      if (success && !input_data_view.ReadData(&p_data))
        success = false;
      if (success && !input_data_view.ReadTimestamp(&p_timestamp))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            MidiSession::Name_, 0, false);
        return false;
      }
      // A null |impl| means no implementation was bound.
      DCHECK(impl);
      impl->SendData(
std::move(p_port), 
std::move(p_data), 
std::move(p_timestamp));
      return true;
    }
  }
  return false;
}

// static
bool MidiSessionStubDispatch::AcceptWithResponder(
    MidiSession* impl,
    mojo::Message* message,
    std::unique_ptr<mojo::MessageReceiverWithStatus> responder) {
  switch (message->header()->name) {
    case internal::kMidiSession_SendData_Name: {
      break;
    }
  }
  return false;
}


static const mojo::internal::GenericValidationInfo kMidiSessionValidationInfo[] = {
    {&internal::MidiSession_SendData_Params_Data::Validate,
     nullptr /* no response */},
};

bool MidiSessionRequestValidator::Accept(mojo::Message* message) {
  const char* name = ::midi::mojom::MidiSession::Name_;
  return mojo::internal::ValidateRequestGenericPacked(message, name, kMidiSessionValidationInfo);
}

}  // namespace mojom
}  // namespace midi

namespace mojo {


// static
bool StructTraits<::midi::mojom::PortInfo::DataView, ::midi::mojom::PortInfoPtr>::Read(
    ::midi::mojom::PortInfo::DataView input,
    ::midi::mojom::PortInfoPtr* output) {
  bool success = true;
  ::midi::mojom::PortInfoPtr result(::midi::mojom::PortInfo::New());
  
      if (success && !input.ReadId(&result->id))
        success = false;
      if (success && !input.ReadManufacturer(&result->manufacturer))
        success = false;
      if (success && !input.ReadName(&result->name))
        success = false;
      if (success && !input.ReadVersion(&result->version))
        success = false;
      if (success && !input.ReadState(&result->state))
        success = false;
  *output = std::move(result);
  return success;
}

}  // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif