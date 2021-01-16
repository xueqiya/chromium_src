// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/css/style_cascade_slots.h"

#include "third_party/blink/renderer/core/css/resolver/style_resolver_state.h"
#include "third_party/blink/renderer/core/style/computed_style.h"

namespace blink {

namespace {

const CSSProperty& ResolveDirectionAware(
    const CSSProperty& property,
    const StyleResolverState& state) {
  const CSSProperty& resolved = property.ResolveDirectionAwareProperty(
      state.Style()->Direction(), state.Style()->GetWritingMode());
  DCHECK_NE(&property, &resolved);
  return resolved;
}

}  // anonymous namespace

bool StyleCascadeSlots::Set(const CSSProperty& property,
                            Priority priority,
                            const StyleResolverState& state,
                            AllowDefault allow_default) {
  switch (property.PropertyID()) {
    // Slots:
    case CSSPropertyID::kWritingMode:
      if (priority < writing_mode_)
        return false;
      writing_mode_ = priority;
      return true;
    case CSSPropertyID::kZoom:
      if (priority < zoom_)
        return false;
      zoom_ = priority;
      return true;
    case CSSPropertyID::kBorderBottomColor:
      if (priority < border_bottom_color_)
        return false;
      border_bottom_color_ = priority;
      return true;
    case CSSPropertyID::kBorderBottomStyle:
      if (priority < border_bottom_style_)
        return false;
      border_bottom_style_ = priority;
      return true;
    case CSSPropertyID::kBorderBottomWidth:
      if (priority < border_bottom_width_)
        return false;
      border_bottom_width_ = priority;
      return true;
    case CSSPropertyID::kBorderImageOutset:
      if (priority < border_image_outset_)
        return false;
      border_image_outset_ = priority;
      return true;
    case CSSPropertyID::kBorderImageRepeat:
      if (priority < border_image_repeat_)
        return false;
      border_image_repeat_ = priority;
      return true;
    case CSSPropertyID::kBorderImageSlice:
      if (priority < border_image_slice_)
        return false;
      border_image_slice_ = priority;
      return true;
    case CSSPropertyID::kBorderImageSource:
      if (priority < border_image_source_)
        return false;
      border_image_source_ = priority;
      return true;
    case CSSPropertyID::kBorderImageWidth:
      if (priority < border_image_width_)
        return false;
      border_image_width_ = priority;
      return true;
    case CSSPropertyID::kBorderLeftColor:
      if (priority < border_left_color_)
        return false;
      border_left_color_ = priority;
      return true;
    case CSSPropertyID::kBorderLeftStyle:
      if (priority < border_left_style_)
        return false;
      border_left_style_ = priority;
      return true;
    case CSSPropertyID::kBorderLeftWidth:
      if (priority < border_left_width_)
        return false;
      border_left_width_ = priority;
      return true;
    case CSSPropertyID::kBorderRightColor:
      if (priority < border_right_color_)
        return false;
      border_right_color_ = priority;
      return true;
    case CSSPropertyID::kBorderRightStyle:
      if (priority < border_right_style_)
        return false;
      border_right_style_ = priority;
      return true;
    case CSSPropertyID::kBorderRightWidth:
      if (priority < border_right_width_)
        return false;
      border_right_width_ = priority;
      return true;
    case CSSPropertyID::kBorderTopColor:
      if (priority < border_top_color_)
        return false;
      border_top_color_ = priority;
      return true;
    case CSSPropertyID::kBorderTopStyle:
      if (priority < border_top_style_)
        return false;
      border_top_style_ = priority;
      return true;
    case CSSPropertyID::kBorderTopWidth:
      if (priority < border_top_width_)
        return false;
      border_top_width_ = priority;
      return true;
    case CSSPropertyID::kBottom:
      if (priority < bottom_)
        return false;
      bottom_ = priority;
      return true;
    case CSSPropertyID::kContainIntrinsicHeight:
      if (priority < contain_intrinsic_height_)
        return false;
      contain_intrinsic_height_ = priority;
      return true;
    case CSSPropertyID::kContainIntrinsicWidth:
      if (priority < contain_intrinsic_width_)
        return false;
      contain_intrinsic_width_ = priority;
      return true;
    case CSSPropertyID::kHeight:
      if (priority < height_)
        return false;
      height_ = priority;
      return true;
    case CSSPropertyID::kInternalVisitedBorderBottomColor:
      if (priority < internal_visited_border_bottom_color_)
        return false;
      internal_visited_border_bottom_color_ = priority;
      return true;
    case CSSPropertyID::kInternalVisitedBorderLeftColor:
      if (priority < internal_visited_border_left_color_)
        return false;
      internal_visited_border_left_color_ = priority;
      return true;
    case CSSPropertyID::kInternalVisitedBorderRightColor:
      if (priority < internal_visited_border_right_color_)
        return false;
      internal_visited_border_right_color_ = priority;
      return true;
    case CSSPropertyID::kInternalVisitedBorderTopColor:
      if (priority < internal_visited_border_top_color_)
        return false;
      internal_visited_border_top_color_ = priority;
      return true;
    case CSSPropertyID::kLeft:
      if (priority < left_)
        return false;
      left_ = priority;
      return true;
    case CSSPropertyID::kMarginBottom:
      if (priority < margin_bottom_)
        return false;
      margin_bottom_ = priority;
      return true;
    case CSSPropertyID::kMarginLeft:
      if (priority < margin_left_)
        return false;
      margin_left_ = priority;
      return true;
    case CSSPropertyID::kMarginRight:
      if (priority < margin_right_)
        return false;
      margin_right_ = priority;
      return true;
    case CSSPropertyID::kMarginTop:
      if (priority < margin_top_)
        return false;
      margin_top_ = priority;
      return true;
    case CSSPropertyID::kMaxHeight:
      if (priority < max_height_)
        return false;
      max_height_ = priority;
      return true;
    case CSSPropertyID::kMaxWidth:
      if (priority < max_width_)
        return false;
      max_width_ = priority;
      return true;
    case CSSPropertyID::kMinHeight:
      if (priority < min_height_)
        return false;
      min_height_ = priority;
      return true;
    case CSSPropertyID::kMinWidth:
      if (priority < min_width_)
        return false;
      min_width_ = priority;
      return true;
    case CSSPropertyID::kOverflowX:
      if (priority < overflow_x_)
        return false;
      overflow_x_ = priority;
      return true;
    case CSSPropertyID::kOverflowY:
      if (priority < overflow_y_)
        return false;
      overflow_y_ = priority;
      return true;
    case CSSPropertyID::kOverscrollBehaviorX:
      if (priority < overscroll_behavior_x_)
        return false;
      overscroll_behavior_x_ = priority;
      return true;
    case CSSPropertyID::kOverscrollBehaviorY:
      if (priority < overscroll_behavior_y_)
        return false;
      overscroll_behavior_y_ = priority;
      return true;
    case CSSPropertyID::kPaddingBottom:
      if (priority < padding_bottom_)
        return false;
      padding_bottom_ = priority;
      return true;
    case CSSPropertyID::kPaddingLeft:
      if (priority < padding_left_)
        return false;
      padding_left_ = priority;
      return true;
    case CSSPropertyID::kPaddingRight:
      if (priority < padding_right_)
        return false;
      padding_right_ = priority;
      return true;
    case CSSPropertyID::kPaddingTop:
      if (priority < padding_top_)
        return false;
      padding_top_ = priority;
      return true;
    case CSSPropertyID::kRight:
      if (priority < right_)
        return false;
      right_ = priority;
      return true;
    case CSSPropertyID::kScrollMarginBottom:
      if (priority < scroll_margin_bottom_)
        return false;
      scroll_margin_bottom_ = priority;
      return true;
    case CSSPropertyID::kScrollMarginLeft:
      if (priority < scroll_margin_left_)
        return false;
      scroll_margin_left_ = priority;
      return true;
    case CSSPropertyID::kScrollMarginRight:
      if (priority < scroll_margin_right_)
        return false;
      scroll_margin_right_ = priority;
      return true;
    case CSSPropertyID::kScrollMarginTop:
      if (priority < scroll_margin_top_)
        return false;
      scroll_margin_top_ = priority;
      return true;
    case CSSPropertyID::kScrollPaddingBottom:
      if (priority < scroll_padding_bottom_)
        return false;
      scroll_padding_bottom_ = priority;
      return true;
    case CSSPropertyID::kScrollPaddingLeft:
      if (priority < scroll_padding_left_)
        return false;
      scroll_padding_left_ = priority;
      return true;
    case CSSPropertyID::kScrollPaddingRight:
      if (priority < scroll_padding_right_)
        return false;
      scroll_padding_right_ = priority;
      return true;
    case CSSPropertyID::kScrollPaddingTop:
      if (priority < scroll_padding_top_)
        return false;
      scroll_padding_top_ = priority;
      return true;
    case CSSPropertyID::kTop:
      if (priority < top_)
        return false;
      top_ = priority;
      return true;
    case CSSPropertyID::kWidth:
      if (priority < width_)
        return false;
      width_ = priority;
      return true;
    // Properties which use slots:
    case CSSPropertyID::kInternalEffectiveZoom:
      if (priority < zoom_)
        return false;
      zoom_ = priority;
      return true;
    case CSSPropertyID::kWebkitWritingMode:
      if (priority < writing_mode_)
        return false;
      writing_mode_ = priority;
      return true;
    case CSSPropertyID::kWebkitBorderImage:
      if (priority < border_image_outset_)
        return false;
      if (priority < border_image_repeat_)
        return false;
      if (priority < border_image_slice_)
        return false;
      if (priority < border_image_source_)
        return false;
      if (priority < border_image_width_)
        return false;
      border_image_outset_ = priority;
      border_image_repeat_ = priority;
      border_image_slice_ = priority;
      border_image_source_ = priority;
      border_image_width_ = priority;
      return true;
    // Direction-aware properties:
    case CSSPropertyID::kBlockSize:
    case CSSPropertyID::kBorderBlockEndColor:
    case CSSPropertyID::kBorderBlockEndStyle:
    case CSSPropertyID::kBorderBlockEndWidth:
    case CSSPropertyID::kBorderBlockStartColor:
    case CSSPropertyID::kBorderBlockStartStyle:
    case CSSPropertyID::kBorderBlockStartWidth:
    case CSSPropertyID::kBorderInlineEndColor:
    case CSSPropertyID::kBorderInlineEndStyle:
    case CSSPropertyID::kBorderInlineEndWidth:
    case CSSPropertyID::kBorderInlineStartColor:
    case CSSPropertyID::kBorderInlineStartStyle:
    case CSSPropertyID::kBorderInlineStartWidth:
    case CSSPropertyID::kContainIntrinsicBlockSize:
    case CSSPropertyID::kContainIntrinsicInlineSize:
    case CSSPropertyID::kInlineSize:
    case CSSPropertyID::kInsetBlockEnd:
    case CSSPropertyID::kInsetBlockStart:
    case CSSPropertyID::kInsetInlineEnd:
    case CSSPropertyID::kInsetInlineStart:
    case CSSPropertyID::kInternalVisitedBorderBlockEndColor:
    case CSSPropertyID::kInternalVisitedBorderBlockStartColor:
    case CSSPropertyID::kInternalVisitedBorderInlineEndColor:
    case CSSPropertyID::kInternalVisitedBorderInlineStartColor:
    case CSSPropertyID::kMarginBlockEnd:
    case CSSPropertyID::kMarginBlockStart:
    case CSSPropertyID::kMarginInlineEnd:
    case CSSPropertyID::kMarginInlineStart:
    case CSSPropertyID::kMaxBlockSize:
    case CSSPropertyID::kMaxInlineSize:
    case CSSPropertyID::kMinBlockSize:
    case CSSPropertyID::kMinInlineSize:
    case CSSPropertyID::kOverflowBlock:
    case CSSPropertyID::kOverflowInline:
    case CSSPropertyID::kOverscrollBehaviorBlock:
    case CSSPropertyID::kOverscrollBehaviorInline:
    case CSSPropertyID::kPaddingBlockEnd:
    case CSSPropertyID::kPaddingBlockStart:
    case CSSPropertyID::kPaddingInlineEnd:
    case CSSPropertyID::kPaddingInlineStart:
    case CSSPropertyID::kScrollMarginBlockEnd:
    case CSSPropertyID::kScrollMarginBlockStart:
    case CSSPropertyID::kScrollMarginInlineEnd:
    case CSSPropertyID::kScrollMarginInlineStart:
    case CSSPropertyID::kScrollPaddingBlockEnd:
    case CSSPropertyID::kScrollPaddingBlockStart:
    case CSSPropertyID::kScrollPaddingInlineEnd:
    case CSSPropertyID::kScrollPaddingInlineStart:
      return Set(ResolveDirectionAware(property, state),
          priority, state, AllowDefault::kNo);
    default:
      // If you hit this DCHECK, you may need to mark the properties resolved
      // to by css-logical properties as 'is_slot:true' in css_properties.json5.
      DCHECK_EQ(allow_default, AllowDefault::kYes);
      return true;
  }
}

}  // namespace blink
