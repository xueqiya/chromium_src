// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_write_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_abort_signal.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8NDEFWriteOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "ignoreRead",
    "overwrite",
    "signal",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8NDEFWriteOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, NDEFWriteOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8NDEFWriteOptionsKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> ignore_read_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&ignore_read_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (ignore_read_value.IsEmpty() || ignore_read_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool ignore_read_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, ignore_read_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setIgnoreRead(ignore_read_cpp_value);
  }

  v8::Local<v8::Value> overwrite_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&overwrite_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (overwrite_value.IsEmpty() || overwrite_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool overwrite_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, overwrite_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOverwrite(overwrite_cpp_value);
  }

  v8::Local<v8::Value> signal_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&signal_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (signal_value.IsEmpty() || signal_value->IsUndefined()) {
    // Do nothing.
  } else if (signal_value->IsNull()) {
    impl->setSignalToNull();
  } else {
    AbortSignal* signal_cpp_value = V8AbortSignal::ToImplWithTypeCheck(isolate, signal_value);
    if (!signal_cpp_value) {
      exception_state.ThrowTypeError("member signal is not of type AbortSignal.");
      return;
    }
    impl->setSignal(signal_cpp_value);
  }
}

v8::Local<v8::Value> NDEFWriteOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NDEFWriteOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NDEFWriteOptions(const NDEFWriteOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8NDEFWriteOptionsKeys(isolate);
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

  v8::Local<v8::Value> ignore_read_value;
  bool ignore_read_has_value_or_default = false;
  if (impl->hasIgnoreRead()) {
    ignore_read_value = v8::Boolean::New(isolate, impl->ignoreRead());
    ignore_read_has_value_or_default = true;
  } else {
    ignore_read_value = v8::Boolean::New(isolate, true);
    ignore_read_has_value_or_default = true;
  }
  if (ignore_read_has_value_or_default &&
      !create_property(0, ignore_read_value)) {
    return false;
  }

  v8::Local<v8::Value> overwrite_value;
  bool overwrite_has_value_or_default = false;
  if (impl->hasOverwrite()) {
    overwrite_value = v8::Boolean::New(isolate, impl->overwrite());
    overwrite_has_value_or_default = true;
  } else {
    overwrite_value = v8::Boolean::New(isolate, true);
    overwrite_has_value_or_default = true;
  }
  if (overwrite_has_value_or_default &&
      !create_property(1, overwrite_value)) {
    return false;
  }

  v8::Local<v8::Value> signal_value;
  bool signal_has_value_or_default = false;
  if (impl->hasSignal()) {
    signal_value = ToV8(impl->signal(), creationContext, isolate);
    signal_has_value_or_default = true;
  }
  if (signal_has_value_or_default &&
      !create_property(2, signal_value)) {
    return false;
  }

  return true;
}

NDEFWriteOptions* NativeValueTraits<NDEFWriteOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  NDEFWriteOptions* impl = MakeGarbageCollected<NDEFWriteOptions>();
  V8NDEFWriteOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
