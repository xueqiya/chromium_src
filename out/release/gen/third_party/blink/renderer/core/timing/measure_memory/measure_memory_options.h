// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT MeasureMemoryOptions : public IDLDictionaryBase {
 public:
  static MeasureMemoryOptions* Create() { return MakeGarbageCollected<MeasureMemoryOptions>(); }

  MeasureMemoryOptions();
  virtual ~MeasureMemoryOptions();

  bool hasDetailed() const { return has_detailed_; }
  bool detailed() const {
    DCHECK(has_detailed_);
    return detailed_;
  }
  inline void setDetailed(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_detailed_ = false;

  bool detailed_;

  friend class V8MeasureMemoryOptions;
};

void MeasureMemoryOptions::setDetailed(bool value) {
  detailed_ = value;
  has_detailed_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_OPTIONS_H_
