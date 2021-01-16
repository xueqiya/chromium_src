// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/timing/measure_memory/measure_memory_entry.h"

namespace blink {

MeasureMemoryEntry::MeasureMemoryEntry() {
}

MeasureMemoryEntry::~MeasureMemoryEntry() = default;

void MeasureMemoryEntry::setJSMemoryRange(const Vector<uint64_t>& value) {
  js_memory_range_ = value;
  has_js_memory_range_ = true;
}

void MeasureMemoryEntry::Trace(blink::Visitor* visitor) {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
