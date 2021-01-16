// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_queuing_strategy_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const v8::Eternal<v8::Name>* eternalV8QueuingStrategyInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "highWaterMark",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(
      kKeys, kKeys, base::size(kKeys));
}

void V8QueuingStrategyInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, QueuingStrategyInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    // Do nothing.
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const v8::Eternal<v8::Name>* keys = eternalV8QueuingStrategyInitKeys(isolate);
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> high_water_mark_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&high_water_mark_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (high_water_mark_value.IsEmpty() || high_water_mark_value->IsUndefined()) {
    // Do nothing.
  } else {
    ScriptValue high_water_mark_cpp_value = ScriptValue(isolate, high_water_mark_value);
    impl->setHighWaterMark(high_water_mark_cpp_value);
  }
}

v8::Local<v8::Value> QueuingStrategyInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8QueuingStrategyInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8QueuingStrategyInit(const QueuingStrategyInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const v8::Eternal<v8::Name>* keys = eternalV8QueuingStrategyInitKeys(isolate);
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

  v8::Local<v8::Value> high_water_mark_value;
  bool high_water_mark_has_value_or_default = false;
  if (impl->hasHighWaterMark()) {
    high_water_mark_value = impl->highWaterMark().V8Value();
    high_water_mark_has_value_or_default = true;
  }
  if (high_water_mark_has_value_or_default &&
      !create_property(0, high_water_mark_value)) {
    return false;
  }

  return true;
}

QueuingStrategyInit* NativeValueTraits<QueuingStrategyInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  QueuingStrategyInit* impl = MakeGarbageCollected<QueuingStrategyInit>();
  V8QueuingStrategyInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
