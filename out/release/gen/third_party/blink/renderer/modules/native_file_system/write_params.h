// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_WRITE_PARAMS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_WRITE_PARAMS_H_

#include "third_party/blink/renderer/bindings/core/v8/array_buffer_or_array_buffer_view_or_blob_or_usv_string.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/fileapi/blob.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_typed_array.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT WriteParams : public IDLDictionaryBase {
 public:
  static WriteParams* Create() { return MakeGarbageCollected<WriteParams>(); }

  WriteParams();
  virtual ~WriteParams();

  bool hasData() const { return !data_.IsNull(); }
  const ArrayBufferOrArrayBufferViewOrBlobOrUSVString& data() const {
    return data_;
  }
  void setData(const ArrayBufferOrArrayBufferViewOrBlobOrUSVString&);
  void setDataToNull();

  bool hasPosition() const { return has_position_; }
  uint64_t position() const {
    DCHECK(has_position_);
    return position_;
  }
  inline void setPosition(uint64_t);
  inline void setPositionToNull();

  bool hasSize() const { return has_size_; }
  uint64_t size() const {
    DCHECK(has_size_);
    return size_;
  }
  inline void setSize(uint64_t);
  inline void setSizeToNull();

  bool hasType() const { return !type_.IsNull(); }
  const String& type() const {
    return type_;
  }
  inline void setType(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_position_ = false;
  bool has_size_ = false;

  ArrayBufferOrArrayBufferViewOrBlobOrUSVString data_;
  uint64_t position_;
  uint64_t size_;
  String type_;

  friend class V8WriteParams;
};

void WriteParams::setPosition(uint64_t value) {
  position_ = value;
  has_position_ = true;
}

void WriteParams::setPositionToNull() {
  has_position_ = false;
}

void WriteParams::setSize(uint64_t value) {
  size_ = value;
  has_size_ = true;
}

void WriteParams::setSizeToNull() {
  has_size_ = false;
}

void WriteParams::setType(const String& value) {
  type_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_WRITE_PARAMS_H_
