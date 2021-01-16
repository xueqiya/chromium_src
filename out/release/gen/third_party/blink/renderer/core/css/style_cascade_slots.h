// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_STYLE_CASCADE_SLOTS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_STYLE_CASCADE_SLOTS_H_

#include "third_party/blink/renderer/core/css/resolver/style_cascade.h"

namespace blink {

class CSSProperty;
class StyleResolverState;

class CORE_EXPORT StyleCascadeSlots {
  STACK_ALLOCATED();
  using Priority = StyleCascade::Priority;
 public:
  // The default behavior for Set is to do nothing and return 'true'.
  // By using AllowDefault::kNo, we'll instead hit a DCHECK if the default
  // behavior is used, which is useful for direction-aware properties.
  enum class AllowDefault { kNo, kYes };

  // Attempt to set the slots associated with the given property to the given
  // priority. If the incoming priority is higher or equal to the priority
  // in each associated slot, the Set will succeed. Otheriwse, it will fail.
  //
  // If there are no slots for the given property, Set will succeed.
  bool Set(const CSSProperty&,
           Priority,
           const StyleResolverState&,
           AllowDefault allow_default = AllowDefault::kYes);
 private:
  Priority writing_mode_;
  Priority zoom_;
  Priority border_bottom_color_;
  Priority border_bottom_style_;
  Priority border_bottom_width_;
  Priority border_image_outset_;
  Priority border_image_repeat_;
  Priority border_image_slice_;
  Priority border_image_source_;
  Priority border_image_width_;
  Priority border_left_color_;
  Priority border_left_style_;
  Priority border_left_width_;
  Priority border_right_color_;
  Priority border_right_style_;
  Priority border_right_width_;
  Priority border_top_color_;
  Priority border_top_style_;
  Priority border_top_width_;
  Priority bottom_;
  Priority contain_intrinsic_height_;
  Priority contain_intrinsic_width_;
  Priority height_;
  Priority internal_visited_border_bottom_color_;
  Priority internal_visited_border_left_color_;
  Priority internal_visited_border_right_color_;
  Priority internal_visited_border_top_color_;
  Priority left_;
  Priority margin_bottom_;
  Priority margin_left_;
  Priority margin_right_;
  Priority margin_top_;
  Priority max_height_;
  Priority max_width_;
  Priority min_height_;
  Priority min_width_;
  Priority overflow_x_;
  Priority overflow_y_;
  Priority overscroll_behavior_x_;
  Priority overscroll_behavior_y_;
  Priority padding_bottom_;
  Priority padding_left_;
  Priority padding_right_;
  Priority padding_top_;
  Priority right_;
  Priority scroll_margin_bottom_;
  Priority scroll_margin_left_;
  Priority scroll_margin_right_;
  Priority scroll_margin_top_;
  Priority scroll_padding_bottom_;
  Priority scroll_padding_left_;
  Priority scroll_padding_right_;
  Priority scroll_padding_top_;
  Priority top_;
  Priority width_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_STYLE_CASCADE_SLOTS_H_
