// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_reading_event_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_event_init.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_message_init.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8NDEFReadingEventInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "message",
    "serialNumber",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8NDEFReadingEventInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, NDEFReadingEventInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): message.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8EventInit::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const v8::Eternal<v8::Name>* keys = eternalV8NDEFReadingEventInitKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> message_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&message_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (message_value.IsEmpty() || message_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member message is undefined.");
    return;
  } else {
    NDEFMessageInit* message_cpp_value = NativeValueTraits<NDEFMessageInit>::NativeValue(isolate, message_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMessage(message_cpp_value);
  }

  v8::Local<v8::Value> serial_number_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&serial_number_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (serial_number_value.IsEmpty() || serial_number_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<kTreatNullAndUndefinedAsNullString> serial_number_cpp_value = serial_number_value;
    if (!serial_number_cpp_value.Prepare(exception_state))
      return;
    impl->setSerialNumber(serial_number_cpp_value);
  }
}

v8::Local<v8::Value> NDEFReadingEventInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NDEFReadingEventInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NDEFReadingEventInit(const NDEFReadingEventInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8EventInit(impl, dictionary, creationContext, isolate))
    return false;

  const v8::Eternal<v8::Name>* keys = eternalV8NDEFReadingEventInitKeys(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> message_value;
  bool message_has_value_or_default = false;
  if (impl->hasMessage()) {
    message_value = ToV8(impl->message(), creationContext, isolate);
    message_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (message_has_value_or_default &&
      !create_property(0, message_value)) {
    return false;
  }

  v8::Local<v8::Value> serial_number_value;
  bool serial_number_has_value_or_default = false;
  if (impl->hasSerialNumber()) {
    serial_number_value = V8String(isolate, impl->serialNumber());
    serial_number_has_value_or_default = true;
  } else {
    serial_number_value = V8String(isolate, WTF::g_empty_string);
    serial_number_has_value_or_default = true;
  }
  if (serial_number_has_value_or_default &&
      !create_property(1, serial_number_value)) {
    return false;
  }

  return true;
}

NDEFReadingEventInit* NativeValueTraits<NDEFReadingEventInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  NDEFReadingEventInit* impl = MakeGarbageCollected<NDEFReadingEventInit>();
  V8NDEFReadingEventInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
