// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_clipboard_item_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8ClipboardItemOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "raw",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8ClipboardItemOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ClipboardItemOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8ClipboardItemOptionsKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> raw_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&raw_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (raw_value.IsEmpty() || raw_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool raw_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, raw_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRaw(raw_cpp_value);
  }
}

v8::Local<v8::Value> ClipboardItemOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ClipboardItemOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ClipboardItemOptions(const ClipboardItemOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8ClipboardItemOptionsKeys(isolate);
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

  v8::Local<v8::Value> raw_value;
  bool raw_has_value_or_default = false;
  if (impl->hasRaw()) {
    raw_value = v8::Boolean::New(isolate, impl->raw());
    raw_has_value_or_default = true;
  } else {
    raw_value = v8::Boolean::New(isolate, false);
    raw_has_value_or_default = true;
  }
  if (raw_has_value_or_default &&
      !create_property(0, raw_value)) {
    return false;
  }

  return true;
}

ClipboardItemOptions* NativeValueTraits<ClipboardItemOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ClipboardItemOptions* impl = MakeGarbageCollected<ClipboardItemOptions>();
  V8ClipboardItemOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
