// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_HANDLER_RESPONSE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_HANDLER_RESPONSE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class PaymentAddressInit;

class MODULES_EXPORT PaymentHandlerResponse : public IDLDictionaryBase {
 public:
  static PaymentHandlerResponse* Create() { return MakeGarbageCollected<PaymentHandlerResponse>(); }

  PaymentHandlerResponse();
  virtual ~PaymentHandlerResponse();

  bool hasDetails() const { return !(details_.IsEmpty() || details_.IsNull() || details_.IsUndefined()); }
  ScriptValue details() const {
    return details_;
  }
  void setDetails(ScriptValue);

  bool hasMethodName() const { return !method_name_.IsNull(); }
  const String& methodName() const {
    return method_name_;
  }
  inline void setMethodName(const String&);

  bool hasPayerEmail() const { return !payer_email_.IsNull(); }
  const String& payerEmail() const {
    return payer_email_;
  }
  inline void setPayerEmail(const String&);
  inline void setPayerEmailToNull();

  bool hasPayerName() const { return !payer_name_.IsNull(); }
  const String& payerName() const {
    return payer_name_;
  }
  inline void setPayerName(const String&);
  inline void setPayerNameToNull();

  bool hasPayerPhone() const { return !payer_phone_.IsNull(); }
  const String& payerPhone() const {
    return payer_phone_;
  }
  inline void setPayerPhone(const String&);
  inline void setPayerPhoneToNull();

  bool hasShippingAddress() const { return shipping_address_; }
  PaymentAddressInit* shippingAddress() const {
    return shipping_address_;
  }
  void setShippingAddress(PaymentAddressInit*);

  bool hasShippingOption() const { return !shipping_option_.IsNull(); }
  const String& shippingOption() const {
    return shipping_option_;
  }
  inline void setShippingOption(const String&);
  inline void setShippingOptionToNull();

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:

  ScriptValue details_;
  String method_name_;
  String payer_email_;
  String payer_name_;
  String payer_phone_;
  Member<PaymentAddressInit> shipping_address_;
  String shipping_option_;

  friend class V8PaymentHandlerResponse;
};

void PaymentHandlerResponse::setMethodName(const String& value) {
  method_name_ = value;
}

void PaymentHandlerResponse::setPayerEmail(const String& value) {
  payer_email_ = value;
}

void PaymentHandlerResponse::setPayerEmailToNull() {
  payer_email_ = String();
}

void PaymentHandlerResponse::setPayerName(const String& value) {
  payer_name_ = value;
}

void PaymentHandlerResponse::setPayerNameToNull() {
  payer_name_ = String();
}

void PaymentHandlerResponse::setPayerPhone(const String& value) {
  payer_phone_ = value;
}

void PaymentHandlerResponse::setPayerPhoneToNull() {
  payer_phone_ = String();
}

void PaymentHandlerResponse::setShippingOption(const String& value) {
  shipping_option_ = value;
}

void PaymentHandlerResponse::setShippingOptionToNull() {
  shipping_option_ = String();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_HANDLER_RESPONSE_H_
