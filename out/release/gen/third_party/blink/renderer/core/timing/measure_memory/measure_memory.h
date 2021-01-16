// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MeasureMemoryEntry;

class CORE_EXPORT MeasureMemory : public IDLDictionaryBase {
 public:
  static MeasureMemory* Create() { return MakeGarbageCollected<MeasureMemory>(); }

  MeasureMemory();
  virtual ~MeasureMemory();

  bool hasCurrent() const { return current_; }
  MeasureMemoryEntry* current() const {
    return current_;
  }
  void setCurrent(MeasureMemoryEntry*);

  bool hasOther() const { return has_other_; }
  const HeapVector<Member<MeasureMemoryEntry>>& other() const {
    DCHECK(has_other_);
    return other_;
  }
  void setOther(const HeapVector<Member<MeasureMemoryEntry>>&);

  bool hasTotal() const { return total_; }
  MeasureMemoryEntry* total() const {
    return total_;
  }
  void setTotal(MeasureMemoryEntry*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_other_ = false;

  Member<MeasureMemoryEntry> current_;
  HeapVector<Member<MeasureMemoryEntry>> other_;
  Member<MeasureMemoryEntry> total_;

  friend class V8MeasureMemory;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_
