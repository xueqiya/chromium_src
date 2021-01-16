// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/websockets/websocket_stream_options.h"

#include "third_party/blink/renderer/core/dom/abort_signal.h"

namespace blink {

WebSocketStreamOptions::WebSocketStreamOptions() {
}

WebSocketStreamOptions::~WebSocketStreamOptions() = default;

void WebSocketStreamOptions::setProtocols(const Vector<String>& value) {
  protocols_ = value;
  has_protocols_ = true;
}

void WebSocketStreamOptions::Trace(blink::Visitor* visitor) {
  visitor->Trace(signal_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
