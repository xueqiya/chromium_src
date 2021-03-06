// media/mojo/mojom/video_decoder.mojom-blink.h is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_MOJOM_VIDEO_DECODER_MOJOM_BLINK_H_
#define MEDIA_MOJO_MOJOM_VIDEO_DECODER_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/macros.h"
#include "base/optional.h"

#include "mojo/public/cpp/bindings/mojo_buildflags.h"
#if BUILDFLAG(MOJO_TRACE_ENABLED)
#include "base/trace_event/trace_event.h"
#endif
#include "mojo/public/cpp/bindings/clone_traits.h"
#include "mojo/public/cpp/bindings/equals_traits.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "media/mojo/mojom/video_decoder.mojom-shared.h"
#include "media/mojo/mojom/video_decoder.mojom-blink-forward.h"
#include "gpu/ipc/common/sync_token.mojom-blink.h"
#include "media/mojo/mojom/media_log.mojom-blink.h"
#include "media/mojo/mojom/media_types.mojom-blink.h"
#include "mojo/public/mojom/base/unguessable_token.mojom-blink.h"
#include "ui/gfx/geometry/mojom/geometry.mojom-blink.h"
#include "ui/gfx/mojom/color_space.mojom-blink.h"

#include "mojo/public/cpp/bindings/lib/wtf_clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/blink/renderer/platform/wtf/hash_functions.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"


#include "mojo/public/cpp/bindings/lib/native_enum_serialization.h"
#include "mojo/public/cpp/bindings/lib/native_struct_serialization.h"
#include "third_party/blink/public/platform/web_common.h"




namespace media {
namespace mojom {
namespace blink {

class VideoFrameHandleReleaserProxy;

template <typename ImplRefTraits>
class VideoFrameHandleReleaserStub;

class VideoFrameHandleReleaserRequestValidator;


class BLINK_PLATFORM_EXPORT VideoFrameHandleReleaser
    : public VideoFrameHandleReleaserInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Base_ = VideoFrameHandleReleaserInterfaceBase;
  using Proxy_ = VideoFrameHandleReleaserProxy;

  template <typename ImplRefTraits>
  using Stub_ = VideoFrameHandleReleaserStub<ImplRefTraits>;

  using RequestValidator_ = VideoFrameHandleReleaserRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kReleaseVideoFrameMinVersion = 0,
  };
  virtual ~VideoFrameHandleReleaser() {}

  
  virtual void ReleaseVideoFrame(const ::base::UnguessableToken& release_token, const ::gpu::SyncToken& release_sync_token) = 0;
};

class VideoDecoderProxy;

template <typename ImplRefTraits>
class VideoDecoderStub;

class VideoDecoderRequestValidator;
class VideoDecoderResponseValidator;


class BLINK_PLATFORM_EXPORT VideoDecoder
    : public VideoDecoderInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = true;
  static constexpr bool HasSyncMethods_ = false;

  using Base_ = VideoDecoderInterfaceBase;
  using Proxy_ = VideoDecoderProxy;

  template <typename ImplRefTraits>
  using Stub_ = VideoDecoderStub<ImplRefTraits>;

  using RequestValidator_ = VideoDecoderRequestValidator;
  using ResponseValidator_ = VideoDecoderResponseValidator;
  enum MethodMinVersions : uint32_t {
    kGetSupportedConfigsMinVersion = 0,
    kConstructMinVersion = 0,
    kInitializeMinVersion = 0,
    kDecodeMinVersion = 0,
    kResetMinVersion = 0,
    kOnOverlayInfoChangedMinVersion = 0,
  };
  virtual ~VideoDecoder() {}


  using GetSupportedConfigsCallback = base::OnceCallback<void(WTF::HashMap<VideoDecoderImplementation, WTF::Vector<SupportedVideoDecoderConfigPtr>>)>;
  
  virtual void GetSupportedConfigs(GetSupportedConfigsCallback callback) = 0;

  
  virtual void Construct(mojo::PendingAssociatedRemote<VideoDecoderClient> client, mojo::PendingAssociatedRemote<::media::mojom::blink::MediaLog> media_log, mojo::PendingReceiver<VideoFrameHandleReleaser> video_frame_handle_releaser, mojo::ScopedDataPipeConsumerHandle decoder_buffer_pipe, CommandBufferIdPtr command_buffer_id, VideoDecoderImplementation implementation, const ::gfx::ColorSpace& target_color_space) = 0;


  using InitializeCallback = base::OnceCallback<void(bool, bool, int32_t)>;
  
  virtual void Initialize(::media::mojom::blink::VideoDecoderConfigPtr config, bool low_delay, int32_t cdm_id, InitializeCallback callback) = 0;


  using DecodeCallback = base::OnceCallback<void(::media::mojom::blink::DecodeStatus)>;
  
  virtual void Decode(::media::mojom::blink::DecoderBufferPtr buffer, DecodeCallback callback) = 0;


  using ResetCallback = base::OnceCallback<void()>;
  
  virtual void Reset(ResetCallback callback) = 0;

  
  virtual void OnOverlayInfoChanged(OverlayInfoPtr overlay_info) = 0;
};

class VideoDecoderClientProxy;

template <typename ImplRefTraits>
class VideoDecoderClientStub;

class VideoDecoderClientRequestValidator;


class BLINK_PLATFORM_EXPORT VideoDecoderClient
    : public VideoDecoderClientInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Base_ = VideoDecoderClientInterfaceBase;
  using Proxy_ = VideoDecoderClientProxy;

  template <typename ImplRefTraits>
  using Stub_ = VideoDecoderClientStub<ImplRefTraits>;

  using RequestValidator_ = VideoDecoderClientRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kOnVideoFrameDecodedMinVersion = 0,
    kOnWaitingMinVersion = 0,
    kRequestOverlayInfoMinVersion = 0,
  };
  virtual ~VideoDecoderClient() {}

  
  virtual void OnVideoFrameDecoded(::media::mojom::blink::VideoFramePtr frame, bool can_read_without_stalling, const base::Optional<::base::UnguessableToken>& release_token) = 0;

  
  virtual void OnWaiting(::media::mojom::blink::WaitingReason reason) = 0;

  
  virtual void RequestOverlayInfo(bool restart_for_transitions) = 0;
};



class BLINK_PLATFORM_EXPORT VideoFrameHandleReleaserProxy
    : public VideoFrameHandleReleaser {
 public:
  using InterfaceType = VideoFrameHandleReleaser;

  explicit VideoFrameHandleReleaserProxy(mojo::MessageReceiverWithResponder* receiver);
  
  void ReleaseVideoFrame(const ::base::UnguessableToken& release_token, const ::gpu::SyncToken& release_sync_token) final;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};



class BLINK_PLATFORM_EXPORT VideoDecoderProxy
    : public VideoDecoder {
 public:
  using InterfaceType = VideoDecoder;

  explicit VideoDecoderProxy(mojo::MessageReceiverWithResponder* receiver);
  
  void GetSupportedConfigs(GetSupportedConfigsCallback callback) final;
  
  void Construct(mojo::PendingAssociatedRemote<VideoDecoderClient> client, mojo::PendingAssociatedRemote<::media::mojom::blink::MediaLog> media_log, mojo::PendingReceiver<VideoFrameHandleReleaser> video_frame_handle_releaser, mojo::ScopedDataPipeConsumerHandle decoder_buffer_pipe, CommandBufferIdPtr command_buffer_id, VideoDecoderImplementation implementation, const ::gfx::ColorSpace& target_color_space) final;
  
  void Initialize(::media::mojom::blink::VideoDecoderConfigPtr config, bool low_delay, int32_t cdm_id, InitializeCallback callback) final;
  
  void Decode(::media::mojom::blink::DecoderBufferPtr buffer, DecodeCallback callback) final;
  
  void Reset(ResetCallback callback) final;
  
  void OnOverlayInfoChanged(OverlayInfoPtr overlay_info) final;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};



class BLINK_PLATFORM_EXPORT VideoDecoderClientProxy
    : public VideoDecoderClient {
 public:
  using InterfaceType = VideoDecoderClient;

  explicit VideoDecoderClientProxy(mojo::MessageReceiverWithResponder* receiver);
  
  void OnVideoFrameDecoded(::media::mojom::blink::VideoFramePtr frame, bool can_read_without_stalling, const base::Optional<::base::UnguessableToken>& release_token) final;
  
  void OnWaiting(::media::mojom::blink::WaitingReason reason) final;
  
  void RequestOverlayInfo(bool restart_for_transitions) final;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};
class BLINK_PLATFORM_EXPORT VideoFrameHandleReleaserStubDispatch {
 public:
  static bool Accept(VideoFrameHandleReleaser* impl, mojo::Message* message);
  static bool AcceptWithResponder(
      VideoFrameHandleReleaser* impl,
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<VideoFrameHandleReleaser>>
class VideoFrameHandleReleaserStub
    : public mojo::MessageReceiverWithResponderStatus {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  VideoFrameHandleReleaserStub() {}
  ~VideoFrameHandleReleaserStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoFrameHandleReleaserStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoFrameHandleReleaserStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, std::move(responder));
  }

 private:
  ImplPointerType sink_;
};
class BLINK_PLATFORM_EXPORT VideoDecoderStubDispatch {
 public:
  static bool Accept(VideoDecoder* impl, mojo::Message* message);
  static bool AcceptWithResponder(
      VideoDecoder* impl,
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<VideoDecoder>>
class VideoDecoderStub
    : public mojo::MessageReceiverWithResponderStatus {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  VideoDecoderStub() {}
  ~VideoDecoderStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoDecoderStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoDecoderStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, std::move(responder));
  }

 private:
  ImplPointerType sink_;
};
class BLINK_PLATFORM_EXPORT VideoDecoderClientStubDispatch {
 public:
  static bool Accept(VideoDecoderClient* impl, mojo::Message* message);
  static bool AcceptWithResponder(
      VideoDecoderClient* impl,
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<VideoDecoderClient>>
class VideoDecoderClientStub
    : public mojo::MessageReceiverWithResponderStatus {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  VideoDecoderClientStub() {}
  ~VideoDecoderClientStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoDecoderClientStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      std::unique_ptr<mojo::MessageReceiverWithStatus> responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return VideoDecoderClientStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, std::move(responder));
  }

 private:
  ImplPointerType sink_;
};
class BLINK_PLATFORM_EXPORT VideoFrameHandleReleaserRequestValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};
class BLINK_PLATFORM_EXPORT VideoDecoderRequestValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};
class BLINK_PLATFORM_EXPORT VideoDecoderClientRequestValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};
class BLINK_PLATFORM_EXPORT VideoDecoderResponseValidator : public mojo::MessageReceiver {
 public:
  bool Accept(mojo::Message* message) override;
};










class BLINK_PLATFORM_EXPORT SupportedVideoDecoderConfig {
 public:
  template <typename T>
  using EnableIfSame = std::enable_if_t<std::is_same<SupportedVideoDecoderConfig, T>::value>;
  using DataView = SupportedVideoDecoderConfigDataView;
  using Data_ = internal::SupportedVideoDecoderConfig_Data;

  template <typename... Args>
  static SupportedVideoDecoderConfigPtr New(Args&&... args) {
    return SupportedVideoDecoderConfigPtr(
        base::in_place, std::forward<Args>(args)...);
  }

  template <typename U>
  static SupportedVideoDecoderConfigPtr From(const U& u) {
    return mojo::TypeConverter<SupportedVideoDecoderConfigPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, SupportedVideoDecoderConfig>::Convert(*this);
  }


  SupportedVideoDecoderConfig();

  SupportedVideoDecoderConfig(
      ::media::mojom::blink::VideoCodecProfile profile_min,
      ::media::mojom::blink::VideoCodecProfile profile_max,
      const ::blink::WebSize& coded_size_min,
      const ::blink::WebSize& coded_size_max,
      bool allow_encrypted,
      bool require_encrypted);

  ~SupportedVideoDecoderConfig();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = SupportedVideoDecoderConfigPtr>
  SupportedVideoDecoderConfigPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static WTF::Vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::SerializeImpl<
        SupportedVideoDecoderConfig::DataView, WTF::Vector<uint8_t>>(input);
  }

  template <typename UserType>
  static mojo::Message SerializeAsMessage(UserType* input) {
    return mojo::internal::SerializeAsMessageImpl<
        SupportedVideoDecoderConfig::DataView>(input);
  }

  // The returned Message is serialized only if the message is moved
  // cross-process or cross-language. Otherwise if the message is Deserialized
  // as the same UserType |input| will just be moved to |output| in
  // DeserializeFromMessage.
  template <typename UserType>
  static mojo::Message WrapAsMessage(UserType input) {
    return mojo::Message(std::make_unique<
        internal::SupportedVideoDecoderConfig_UnserializedMessageContext<
            UserType, SupportedVideoDecoderConfig::DataView>>(0, 0, std::move(input)));
  }

  template <typename UserType>
  static bool Deserialize(const void* data,
                          size_t data_num_bytes,
                          UserType* output) {
    return mojo::internal::DeserializeImpl<SupportedVideoDecoderConfig::DataView>(
        data, data_num_bytes, std::vector<mojo::ScopedHandle>(), output, Validate);
  }

  template <typename UserType>
  static bool Deserialize(const WTF::Vector<uint8_t>& input,
                          UserType* output) {
    return SupportedVideoDecoderConfig::Deserialize(
        input.size() == 0 ? nullptr : &input.front(), input.size(), output);
  }

  template <typename UserType>
  static bool DeserializeFromMessage(mojo::Message input,
                                     UserType* output) {
    auto context = input.TakeUnserializedContext<
        internal::SupportedVideoDecoderConfig_UnserializedMessageContext<
            UserType, SupportedVideoDecoderConfig::DataView>>();
    if (context) {
      *output = std::move(context->TakeData());
      return true;
    }
    input.SerializeIfNecessary();
    return mojo::internal::DeserializeImpl<SupportedVideoDecoderConfig::DataView>(
        input.payload(), input.payload_num_bytes(),
        std::move(*input.mutable_handles()), output, Validate);
  }

  
  ::media::mojom::blink::VideoCodecProfile profile_min;
  
  ::media::mojom::blink::VideoCodecProfile profile_max;
  
  ::blink::WebSize coded_size_min;
  
  ::blink::WebSize coded_size_max;
  
  bool allow_encrypted;
  
  bool require_encrypted;

 private:
  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);
};

// The comparison operators are templates, so they are only instantiated if they
// are used. Thus, the bindings generator does not need to know whether
// comparison operators are available for members.
template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>* = nullptr>
bool operator<(const T& lhs, const T& rhs);

template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>* = nullptr>
bool operator<=(const T& lhs, const T& rhs) {
  return !(rhs < lhs);
}

template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>* = nullptr>
bool operator>(const T& lhs, const T& rhs) {
  return rhs < lhs;
}

template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>* = nullptr>
bool operator>=(const T& lhs, const T& rhs) {
  return !(lhs < rhs);
}





class BLINK_PLATFORM_EXPORT CommandBufferId {
 public:
  template <typename T>
  using EnableIfSame = std::enable_if_t<std::is_same<CommandBufferId, T>::value>;
  using DataView = CommandBufferIdDataView;
  using Data_ = internal::CommandBufferId_Data;

  template <typename... Args>
  static CommandBufferIdPtr New(Args&&... args) {
    return CommandBufferIdPtr(
        base::in_place, std::forward<Args>(args)...);
  }

  template <typename U>
  static CommandBufferIdPtr From(const U& u) {
    return mojo::TypeConverter<CommandBufferIdPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, CommandBufferId>::Convert(*this);
  }


  CommandBufferId();

  CommandBufferId(
      const ::base::UnguessableToken& channel_token,
      int32_t route_id);

  ~CommandBufferId();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = CommandBufferIdPtr>
  CommandBufferIdPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T, CommandBufferId::EnableIfSame<T>* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static WTF::Vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::SerializeImpl<
        CommandBufferId::DataView, WTF::Vector<uint8_t>>(input);
  }

  template <typename UserType>
  static mojo::Message SerializeAsMessage(UserType* input) {
    return mojo::internal::SerializeAsMessageImpl<
        CommandBufferId::DataView>(input);
  }

  // The returned Message is serialized only if the message is moved
  // cross-process or cross-language. Otherwise if the message is Deserialized
  // as the same UserType |input| will just be moved to |output| in
  // DeserializeFromMessage.
  template <typename UserType>
  static mojo::Message WrapAsMessage(UserType input) {
    return mojo::Message(std::make_unique<
        internal::CommandBufferId_UnserializedMessageContext<
            UserType, CommandBufferId::DataView>>(0, 0, std::move(input)));
  }

  template <typename UserType>
  static bool Deserialize(const void* data,
                          size_t data_num_bytes,
                          UserType* output) {
    return mojo::internal::DeserializeImpl<CommandBufferId::DataView>(
        data, data_num_bytes, std::vector<mojo::ScopedHandle>(), output, Validate);
  }

  template <typename UserType>
  static bool Deserialize(const WTF::Vector<uint8_t>& input,
                          UserType* output) {
    return CommandBufferId::Deserialize(
        input.size() == 0 ? nullptr : &input.front(), input.size(), output);
  }

  template <typename UserType>
  static bool DeserializeFromMessage(mojo::Message input,
                                     UserType* output) {
    auto context = input.TakeUnserializedContext<
        internal::CommandBufferId_UnserializedMessageContext<
            UserType, CommandBufferId::DataView>>();
    if (context) {
      *output = std::move(context->TakeData());
      return true;
    }
    input.SerializeIfNecessary();
    return mojo::internal::DeserializeImpl<CommandBufferId::DataView>(
        input.payload(), input.payload_num_bytes(),
        std::move(*input.mutable_handles()), output, Validate);
  }

  
  ::base::UnguessableToken channel_token;
  
  int32_t route_id;

 private:
  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);
};

// The comparison operators are templates, so they are only instantiated if they
// are used. Thus, the bindings generator does not need to know whether
// comparison operators are available for members.
template <typename T, CommandBufferId::EnableIfSame<T>* = nullptr>
bool operator<(const T& lhs, const T& rhs);

template <typename T, CommandBufferId::EnableIfSame<T>* = nullptr>
bool operator<=(const T& lhs, const T& rhs) {
  return !(rhs < lhs);
}

template <typename T, CommandBufferId::EnableIfSame<T>* = nullptr>
bool operator>(const T& lhs, const T& rhs) {
  return rhs < lhs;
}

template <typename T, CommandBufferId::EnableIfSame<T>* = nullptr>
bool operator>=(const T& lhs, const T& rhs) {
  return !(lhs < rhs);
}


template <typename StructPtrType>
SupportedVideoDecoderConfigPtr SupportedVideoDecoderConfig::Clone() const {
  return New(
      mojo::Clone(profile_min),
      mojo::Clone(profile_max),
      mojo::Clone(coded_size_min),
      mojo::Clone(coded_size_max),
      mojo::Clone(allow_encrypted),
      mojo::Clone(require_encrypted)
  );
}

template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>*>
bool SupportedVideoDecoderConfig::Equals(const T& other_struct) const {
  if (!mojo::Equals(this->profile_min, other_struct.profile_min))
    return false;
  if (!mojo::Equals(this->profile_max, other_struct.profile_max))
    return false;
  if (!mojo::Equals(this->coded_size_min, other_struct.coded_size_min))
    return false;
  if (!mojo::Equals(this->coded_size_max, other_struct.coded_size_max))
    return false;
  if (!mojo::Equals(this->allow_encrypted, other_struct.allow_encrypted))
    return false;
  if (!mojo::Equals(this->require_encrypted, other_struct.require_encrypted))
    return false;
  return true;
}

template <typename T, SupportedVideoDecoderConfig::EnableIfSame<T>*>
bool operator<(const T& lhs, const T& rhs) {
  if (lhs.profile_min < rhs.profile_min)
    return true;
  if (rhs.profile_min < lhs.profile_min)
    return false;
  if (lhs.profile_max < rhs.profile_max)
    return true;
  if (rhs.profile_max < lhs.profile_max)
    return false;
  if (lhs.coded_size_min < rhs.coded_size_min)
    return true;
  if (rhs.coded_size_min < lhs.coded_size_min)
    return false;
  if (lhs.coded_size_max < rhs.coded_size_max)
    return true;
  if (rhs.coded_size_max < lhs.coded_size_max)
    return false;
  if (lhs.allow_encrypted < rhs.allow_encrypted)
    return true;
  if (rhs.allow_encrypted < lhs.allow_encrypted)
    return false;
  if (lhs.require_encrypted < rhs.require_encrypted)
    return true;
  if (rhs.require_encrypted < lhs.require_encrypted)
    return false;
  return false;
}
template <typename StructPtrType>
CommandBufferIdPtr CommandBufferId::Clone() const {
  return New(
      mojo::Clone(channel_token),
      mojo::Clone(route_id)
  );
}

template <typename T, CommandBufferId::EnableIfSame<T>*>
bool CommandBufferId::Equals(const T& other_struct) const {
  if (!mojo::Equals(this->channel_token, other_struct.channel_token))
    return false;
  if (!mojo::Equals(this->route_id, other_struct.route_id))
    return false;
  return true;
}

template <typename T, CommandBufferId::EnableIfSame<T>*>
bool operator<(const T& lhs, const T& rhs) {
  if (lhs.channel_token < rhs.channel_token)
    return true;
  if (rhs.channel_token < lhs.channel_token)
    return false;
  if (lhs.route_id < rhs.route_id)
    return true;
  if (rhs.route_id < lhs.route_id)
    return false;
  return false;
}


}  // namespace blink
}  // namespace mojom
}  // namespace media

namespace mojo {


template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::media::mojom::blink::SupportedVideoDecoderConfig::DataView,
                                         ::media::mojom::blink::SupportedVideoDecoderConfigPtr> {
  static bool IsNull(const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) { return !input; }
  static void SetToNull(::media::mojom::blink::SupportedVideoDecoderConfigPtr* output) { output->reset(); }

  static decltype(::media::mojom::blink::SupportedVideoDecoderConfig::profile_min) profile_min(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->profile_min;
  }

  static decltype(::media::mojom::blink::SupportedVideoDecoderConfig::profile_max) profile_max(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->profile_max;
  }

  static const decltype(::media::mojom::blink::SupportedVideoDecoderConfig::coded_size_min)& coded_size_min(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->coded_size_min;
  }

  static const decltype(::media::mojom::blink::SupportedVideoDecoderConfig::coded_size_max)& coded_size_max(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->coded_size_max;
  }

  static decltype(::media::mojom::blink::SupportedVideoDecoderConfig::allow_encrypted) allow_encrypted(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->allow_encrypted;
  }

  static decltype(::media::mojom::blink::SupportedVideoDecoderConfig::require_encrypted) require_encrypted(
      const ::media::mojom::blink::SupportedVideoDecoderConfigPtr& input) {
    return input->require_encrypted;
  }

  static bool Read(::media::mojom::blink::SupportedVideoDecoderConfig::DataView input, ::media::mojom::blink::SupportedVideoDecoderConfigPtr* output);
};


template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::media::mojom::blink::CommandBufferId::DataView,
                                         ::media::mojom::blink::CommandBufferIdPtr> {
  static bool IsNull(const ::media::mojom::blink::CommandBufferIdPtr& input) { return !input; }
  static void SetToNull(::media::mojom::blink::CommandBufferIdPtr* output) { output->reset(); }

  static const decltype(::media::mojom::blink::CommandBufferId::channel_token)& channel_token(
      const ::media::mojom::blink::CommandBufferIdPtr& input) {
    return input->channel_token;
  }

  static decltype(::media::mojom::blink::CommandBufferId::route_id) route_id(
      const ::media::mojom::blink::CommandBufferIdPtr& input) {
    return input->route_id;
  }

  static bool Read(::media::mojom::blink::CommandBufferId::DataView input, ::media::mojom::blink::CommandBufferIdPtr* output);
};

}  // namespace mojo

#endif  // MEDIA_MOJO_MOJOM_VIDEO_DECODER_MOJOM_BLINK_H_