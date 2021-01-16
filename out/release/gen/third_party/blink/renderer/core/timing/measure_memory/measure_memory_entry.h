// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_ENTRY_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_ENTRY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class CORE_EXPORT MeasureMemoryEntry : public IDLDictionaryBase {
 public:
  static MeasureMemoryEntry* Create() { return MakeGarbageCollected<MeasureMemoryEntry>(); }

  MeasureMemoryEntry();
  virtual ~MeasureMemoryEntry();

  bool hasJSMemoryEstimate() const { return has_js_memory_estimate_; }
  uint64_t jsMemoryEstimate() const {
    DCHECK(has_js_memory_estimate_);
    return js_memory_estimate_;
  }
  inline void setJSMemoryEstimate(uint64_t);

  bool hasJSMemoryRange() const { return has_js_memory_range_; }
  const Vector<uint64_t>& jsMemoryRange() const {
    DCHECK(has_js_memory_range_);
    return js_memory_range_;
  }
  void setJSMemoryRange(const Vector<uint64_t>&);

  bool hasURL() const { return !url_.IsNull(); }
  const String& url() const {
    return url_;
  }
  inline void setURL(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_js_memory_estimate_ = false;
  bool has_js_memory_range_ = false;

  uint64_t js_memory_estimate_;
  Vector<uint64_t> js_memory_range_;
  String url_;

  friend class V8MeasureMemoryEntry;
};

void MeasureMemoryEntry::setJSMemoryEstimate(uint64_t value) {
  js_memory_estimate_ = value;
  has_js_memory_estimate_ = true;
}

void MeasureMemoryEntry::setURL(const String& value) {
  url_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_ENTRY_H_
