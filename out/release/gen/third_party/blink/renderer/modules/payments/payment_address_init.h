// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_ADDRESS_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_ADDRESS_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class MODULES_EXPORT PaymentAddressInit : public IDLDictionaryBase {
 public:
  static PaymentAddressInit* Create() { return MakeGarbageCollected<PaymentAddressInit>(); }

  PaymentAddressInit();
  virtual ~PaymentAddressInit();

  bool hasAddressLine() const { return has_address_line_; }
  const Vector<String>& addressLine() const {
    DCHECK(has_address_line_);
    return address_line_;
  }
  void setAddressLine(const Vector<String>&);

  bool hasCity() const { return !city_.IsNull(); }
  const String& city() const {
    return city_;
  }
  inline void setCity(const String&);

  bool hasCountry() const { return !country_.IsNull(); }
  const String& country() const {
    return country_;
  }
  inline void setCountry(const String&);

  bool hasDependentLocality() const { return !dependent_locality_.IsNull(); }
  const String& dependentLocality() const {
    return dependent_locality_;
  }
  inline void setDependentLocality(const String&);

  bool hasOrganization() const { return !organization_.IsNull(); }
  const String& organization() const {
    return organization_;
  }
  inline void setOrganization(const String&);

  bool hasPhone() const { return !phone_.IsNull(); }
  const String& phone() const {
    return phone_;
  }
  inline void setPhone(const String&);

  bool hasPostalCode() const { return !postal_code_.IsNull(); }
  const String& postalCode() const {
    return postal_code_;
  }
  inline void setPostalCode(const String&);

  bool hasRecipient() const { return !recipient_.IsNull(); }
  const String& recipient() const {
    return recipient_;
  }
  inline void setRecipient(const String&);

  bool hasRegion() const { return !region_.IsNull(); }
  const String& region() const {
    return region_;
  }
  inline void setRegion(const String&);

  bool hasSortingCode() const { return !sorting_code_.IsNull(); }
  const String& sortingCode() const {
    return sorting_code_;
  }
  inline void setSortingCode(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(blink::Visitor*) override;

 private:
  bool has_address_line_ = false;

  Vector<String> address_line_;
  String city_;
  String country_;
  String dependent_locality_;
  String organization_;
  String phone_;
  String postal_code_;
  String recipient_;
  String region_;
  String sorting_code_;

  friend class V8PaymentAddressInit;
};

void PaymentAddressInit::setCity(const String& value) {
  city_ = value;
}

void PaymentAddressInit::setCountry(const String& value) {
  country_ = value;
}

void PaymentAddressInit::setDependentLocality(const String& value) {
  dependent_locality_ = value;
}

void PaymentAddressInit::setOrganization(const String& value) {
  organization_ = value;
}

void PaymentAddressInit::setPhone(const String& value) {
  phone_ = value;
}

void PaymentAddressInit::setPostalCode(const String& value) {
  postal_code_ = value;
}

void PaymentAddressInit::setRecipient(const String& value) {
  recipient_ = value;
}

void PaymentAddressInit::setRegion(const String& value) {
  region_ = value;
}

void PaymentAddressInit::setSortingCode(const String& value) {
  sorting_code_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_PAYMENT_ADDRESS_INIT_H_
