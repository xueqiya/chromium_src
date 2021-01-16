// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/nfc/ndef_reading_event_init.h"

#include "third_party/blink/renderer/modules/nfc/ndef_message_init.h"

namespace blink {

NDEFReadingEventInit::NDEFReadingEventInit() {
  setSerialNumber(WTF::g_empty_string);
}

NDEFReadingEventInit::~NDEFReadingEventInit() = default;

void NDEFReadingEventInit::setMessage(NDEFMessageInit* value) {
  message_ = value;
}

void NDEFReadingEventInit::Trace(blink::Visitor* visitor) {
  visitor->Trace(message_);
  EventInit::Trace(visitor);
}

}  // namespace blink
