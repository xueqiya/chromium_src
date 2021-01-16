// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class AbortSignal;

class MODULES_EXPORT SchedulerPostTaskOptions : public IDLDictionaryBase {
 public:
  static SchedulerPostTaskOptions* Create() { return MakeGarbageCollected<SchedulerPostTaskOptions>(); }

  SchedulerPostTaskOptions();
  virtual ~SchedulerPostTaskOptions();

  bool hasDelay() const { return has_delay_; }
  int32_t delay() const {
    DCHECK(has_delay_);
    return delay_;
  }
  inline void setDelay(int32_t);

  bool hasPriority() const { return !priority_.IsNull(); }
  const String& priority() const {
    return priority_;
  }
  inline void setPriority(const String&);
  inline void setPriorityToNull();

  bool hasSignal() const { return has_signal_; }
  AbortSignal* signal() const {
    return signal_;
  }
  inline void setSignal(AbortSignal*);
  inline void setSignalToNull();

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_delay_ = false;
  bool has_signal_ = false;

  int32_t delay_;
  String priority_;
  Member<AbortSignal> signal_;

  friend class V8SchedulerPostTaskOptions;
};

void SchedulerPostTaskOptions::setDelay(int32_t value) {
  delay_ = value;
  has_delay_ = true;
}

void SchedulerPostTaskOptions::setPriority(const String& value) {
  priority_ = value;
}

void SchedulerPostTaskOptions::setPriorityToNull() {
  priority_ = String();
}

void SchedulerPostTaskOptions::setSignal(AbortSignal* value) {
  signal_ = value;
  has_signal_ = true;
}

void SchedulerPostTaskOptions::setSignalToNull() {
  signal_ = Member<AbortSignal>();
  has_signal_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SCHEDULER_SCHEDULER_POST_TASK_OPTIONS_H_
