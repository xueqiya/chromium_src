// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_

#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/platform/wtf/text/string_view.h"
#include <string.h>

namespace blink {

enum class AtRuleDescriptorID {
  Invalid = 0,
  FontDisplay = 1,
  FontFamily = 2,
  FontFeatureSettings = 3,
  FontStretch = 4,
  FontStyle = 5,
  FontVariant = 6,
  FontWeight = 7,
  Height = 8,
  Inherits = 9,
  InitialValue = 10,
  MaxHeight = 11,
  MaxWidth = 12,
  MaxZoom = 13,
  MinHeight = 14,
  MinWidth = 15,
  MinZoom = 16,
  Orientation = 17,
  Src = 18,
  Syntax = 19,
  UnicodeRange = 20,
  UserZoom = 21,
  Width = 22,
  Zoom = 23,
};

const int numAtRuleDescriptors = 24;

const char* getValueName(AtRuleDescriptorID);

AtRuleDescriptorID AsAtRuleDescriptorID(StringView string);

CSSPropertyID AtRuleDescriptorIDAsCSSPropertyID(AtRuleDescriptorID);
AtRuleDescriptorID CSSPropertyIDAsAtRuleDescriptor(CSSPropertyID id);

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
