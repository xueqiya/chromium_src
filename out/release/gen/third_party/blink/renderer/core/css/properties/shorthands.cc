// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/properties/templates/css_properties.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/properties/css_property_methods.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5



#include "third_party/blink/renderer/core/css/properties/shorthands.h"

#include "third_party/blink/renderer/core/css/css_custom_ident_value.h"
#include "third_party/blink/renderer/core/css/css_identifier_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value_mappings.h"
#include "third_party/blink/renderer/core/css/css_value_list.h"
#include "third_party/blink/renderer/core/css/css_value_pair.h"
#include "third_party/blink/renderer/core/css/properties/css_direction_aware_resolver.h"
#include "third_party/blink/renderer/core/css/properties/style_building_utils.h"
#include "third_party/blink/renderer/core/css/resolver/font_builder.h"
#include "third_party/blink/renderer/core/css/resolver/style_builder_converter.h"
#include "third_party/blink/renderer/core/css/resolver/style_resolver_state.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/style/computed_style.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/core/style/svg_computed_style.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {
namespace css_shorthand {

// animation



const char* Animation::GetPropertyName() const {
  return "animation";
}

const WTF::AtomicString& Animation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation"));
  return name;
}

const char* Animation::GetJSPropertyName() const {
  return "animation";
}



 // background



const char* Background::GetPropertyName() const {
  return "background";
}

const WTF::AtomicString& Background::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background"));
  return name;
}

const char* Background::GetJSPropertyName() const {
  return "background";
}



 // background-position



const char* BackgroundPosition::GetPropertyName() const {
  return "background-position";
}

const WTF::AtomicString& BackgroundPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-position"));
  return name;
}

const char* BackgroundPosition::GetJSPropertyName() const {
  return "backgroundPosition";
}



 // background-repeat



const char* BackgroundRepeat::GetPropertyName() const {
  return "background-repeat";
}

const WTF::AtomicString& BackgroundRepeat::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-repeat"));
  return name;
}

const char* BackgroundRepeat::GetJSPropertyName() const {
  return "backgroundRepeat";
}



 // border



const char* Border::GetPropertyName() const {
  return "border";
}

const WTF::AtomicString& Border::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border"));
  return name;
}

const char* Border::GetJSPropertyName() const {
  return "border";
}



 // border-block

CSSExposure BorderBlock::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderBlock::GetPropertyName() const {
  return "border-block";
}

const WTF::AtomicString& BorderBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block"));
  return name;
}

const char* BorderBlock::GetJSPropertyName() const {
  return "borderBlock";
}



 // border-block-color

CSSExposure BorderBlockColor::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderBlockColor::GetPropertyName() const {
  return "border-block-color";
}

const WTF::AtomicString& BorderBlockColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-color"));
  return name;
}

const char* BorderBlockColor::GetJSPropertyName() const {
  return "borderBlockColor";
}



 // border-block-end



const char* BorderBlockEnd::GetPropertyName() const {
  return "border-block-end";
}

const WTF::AtomicString& BorderBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end"));
  return name;
}

const char* BorderBlockEnd::GetJSPropertyName() const {
  return "borderBlockEnd";
}

const CSSProperty& BorderBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderGroup());
}


 // border-block-start



const char* BorderBlockStart::GetPropertyName() const {
  return "border-block-start";
}

const WTF::AtomicString& BorderBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start"));
  return name;
}

const char* BorderBlockStart::GetJSPropertyName() const {
  return "borderBlockStart";
}

const CSSProperty& BorderBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderGroup());
}


 // border-block-style

CSSExposure BorderBlockStyle::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderBlockStyle::GetPropertyName() const {
  return "border-block-style";
}

const WTF::AtomicString& BorderBlockStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-style"));
  return name;
}

const char* BorderBlockStyle::GetJSPropertyName() const {
  return "borderBlockStyle";
}



 // border-block-width

CSSExposure BorderBlockWidth::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderBlockWidth::GetPropertyName() const {
  return "border-block-width";
}

const WTF::AtomicString& BorderBlockWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-width"));
  return name;
}

const char* BorderBlockWidth::GetJSPropertyName() const {
  return "borderBlockWidth";
}



 // border-bottom



const char* BorderBottom::GetPropertyName() const {
  return "border-bottom";
}

const WTF::AtomicString& BorderBottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom"));
  return name;
}

const char* BorderBottom::GetJSPropertyName() const {
  return "borderBottom";
}



 // border-color



const char* BorderColor::GetPropertyName() const {
  return "border-color";
}

const WTF::AtomicString& BorderColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-color"));
  return name;
}

const char* BorderColor::GetJSPropertyName() const {
  return "borderColor";
}



 // border-image



const char* BorderImage::GetPropertyName() const {
  return "border-image";
}

const WTF::AtomicString& BorderImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image"));
  return name;
}

const char* BorderImage::GetJSPropertyName() const {
  return "borderImage";
}



 // border-inline

CSSExposure BorderInline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderInline::GetPropertyName() const {
  return "border-inline";
}

const WTF::AtomicString& BorderInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline"));
  return name;
}

const char* BorderInline::GetJSPropertyName() const {
  return "borderInline";
}



 // border-inline-color

CSSExposure BorderInlineColor::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderInlineColor::GetPropertyName() const {
  return "border-inline-color";
}

const WTF::AtomicString& BorderInlineColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-color"));
  return name;
}

const char* BorderInlineColor::GetJSPropertyName() const {
  return "borderInlineColor";
}



 // border-inline-end



const char* BorderInlineEnd::GetPropertyName() const {
  return "border-inline-end";
}

const WTF::AtomicString& BorderInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end"));
  return name;
}

const char* BorderInlineEnd::GetJSPropertyName() const {
  return "borderInlineEnd";
}

const CSSProperty& BorderInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderGroup());
}


 // border-inline-start



const char* BorderInlineStart::GetPropertyName() const {
  return "border-inline-start";
}

const WTF::AtomicString& BorderInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start"));
  return name;
}

const char* BorderInlineStart::GetJSPropertyName() const {
  return "borderInlineStart";
}

const CSSProperty& BorderInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderGroup());
}


 // border-inline-style

CSSExposure BorderInlineStyle::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderInlineStyle::GetPropertyName() const {
  return "border-inline-style";
}

const WTF::AtomicString& BorderInlineStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-style"));
  return name;
}

const char* BorderInlineStyle::GetJSPropertyName() const {
  return "borderInlineStyle";
}



 // border-inline-width

CSSExposure BorderInlineWidth::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* BorderInlineWidth::GetPropertyName() const {
  return "border-inline-width";
}

const WTF::AtomicString& BorderInlineWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-width"));
  return name;
}

const char* BorderInlineWidth::GetJSPropertyName() const {
  return "borderInlineWidth";
}



 // border-left



const char* BorderLeft::GetPropertyName() const {
  return "border-left";
}

const WTF::AtomicString& BorderLeft::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left"));
  return name;
}

const char* BorderLeft::GetJSPropertyName() const {
  return "borderLeft";
}



 // border-radius



const char* BorderRadius::GetPropertyName() const {
  return "border-radius";
}

const WTF::AtomicString& BorderRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-radius"));
  return name;
}

const char* BorderRadius::GetJSPropertyName() const {
  return "borderRadius";
}



 // border-right



const char* BorderRight::GetPropertyName() const {
  return "border-right";
}

const WTF::AtomicString& BorderRight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right"));
  return name;
}

const char* BorderRight::GetJSPropertyName() const {
  return "borderRight";
}



 // border-spacing



const char* BorderSpacing::GetPropertyName() const {
  return "border-spacing";
}

const WTF::AtomicString& BorderSpacing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-spacing"));
  return name;
}

const char* BorderSpacing::GetJSPropertyName() const {
  return "borderSpacing";
}



 // border-style



const char* BorderStyle::GetPropertyName() const {
  return "border-style";
}

const WTF::AtomicString& BorderStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-style"));
  return name;
}

const char* BorderStyle::GetJSPropertyName() const {
  return "borderStyle";
}



 // border-top



const char* BorderTop::GetPropertyName() const {
  return "border-top";
}

const WTF::AtomicString& BorderTop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top"));
  return name;
}

const char* BorderTop::GetJSPropertyName() const {
  return "borderTop";
}



 // border-width



const char* BorderWidth::GetPropertyName() const {
  return "border-width";
}

const WTF::AtomicString& BorderWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-width"));
  return name;
}

const char* BorderWidth::GetJSPropertyName() const {
  return "borderWidth";
}



 // column-rule



const char* ColumnRule::GetPropertyName() const {
  return "column-rule";
}

const WTF::AtomicString& ColumnRule::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule"));
  return name;
}

const char* ColumnRule::GetJSPropertyName() const {
  return "columnRule";
}



 // columns



const char* Columns::GetPropertyName() const {
  return "columns";
}

const WTF::AtomicString& Columns::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("columns"));
  return name;
}

const char* Columns::GetJSPropertyName() const {
  return "columns";
}



 // contain-intrinsic-size

CSSExposure ContainIntrinsicSize::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSIntrinsicSizeEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ContainIntrinsicSize::GetPropertyName() const {
  return "contain-intrinsic-size";
}

const WTF::AtomicString& ContainIntrinsicSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-size"));
  return name;
}

const char* ContainIntrinsicSize::GetJSPropertyName() const {
  return "containIntrinsicSize";
}



 // flex



const char* Flex::GetPropertyName() const {
  return "flex";
}

const WTF::AtomicString& Flex::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex"));
  return name;
}

const char* Flex::GetJSPropertyName() const {
  return "flex";
}



 // flex-flow



const char* FlexFlow::GetPropertyName() const {
  return "flex-flow";
}

const WTF::AtomicString& FlexFlow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-flow"));
  return name;
}

const char* FlexFlow::GetJSPropertyName() const {
  return "flexFlow";
}



 // font



const char* Font::GetPropertyName() const {
  return "font";
}

const WTF::AtomicString& Font::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font"));
  return name;
}

const char* Font::GetJSPropertyName() const {
  return "font";
}



 // font-variant



const char* FontVariant::GetPropertyName() const {
  return "font-variant";
}

const WTF::AtomicString& FontVariant::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant"));
  return name;
}

const char* FontVariant::GetJSPropertyName() const {
  return "fontVariant";
}



 // gap



const char* Gap::GetPropertyName() const {
  return "gap";
}

const WTF::AtomicString& Gap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("gap"));
  return name;
}

const char* Gap::GetJSPropertyName() const {
  return "gap";
}



 // grid



const char* Grid::GetPropertyName() const {
  return "grid";
}

const WTF::AtomicString& Grid::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid"));
  return name;
}

const char* Grid::GetJSPropertyName() const {
  return "grid";
}



 // grid-area



const char* GridArea::GetPropertyName() const {
  return "grid-area";
}

const WTF::AtomicString& GridArea::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-area"));
  return name;
}

const char* GridArea::GetJSPropertyName() const {
  return "gridArea";
}



 // grid-column



const char* GridColumn::GetPropertyName() const {
  return "grid-column";
}

const WTF::AtomicString& GridColumn::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column"));
  return name;
}

const char* GridColumn::GetJSPropertyName() const {
  return "gridColumn";
}



 // grid-column-gap



const char* GridColumnGap::GetPropertyName() const {
  return "grid-column-gap";
}

const WTF::AtomicString& GridColumnGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-gap"));
  return name;
}

const char* GridColumnGap::GetJSPropertyName() const {
  return "gridColumnGap";
}



 // grid-gap



const char* GridGap::GetPropertyName() const {
  return "grid-gap";
}

const WTF::AtomicString& GridGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-gap"));
  return name;
}

const char* GridGap::GetJSPropertyName() const {
  return "gridGap";
}



 // grid-row



const char* GridRow::GetPropertyName() const {
  return "grid-row";
}

const WTF::AtomicString& GridRow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row"));
  return name;
}

const char* GridRow::GetJSPropertyName() const {
  return "gridRow";
}



 // grid-row-gap



const char* GridRowGap::GetPropertyName() const {
  return "grid-row-gap";
}

const WTF::AtomicString& GridRowGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-gap"));
  return name;
}

const char* GridRowGap::GetJSPropertyName() const {
  return "gridRowGap";
}



 // grid-template



const char* GridTemplate::GetPropertyName() const {
  return "grid-template";
}

const WTF::AtomicString& GridTemplate::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template"));
  return name;
}

const char* GridTemplate::GetJSPropertyName() const {
  return "gridTemplate";
}



 // inset

CSSExposure Inset::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Inset::GetPropertyName() const {
  return "inset";
}

const WTF::AtomicString& Inset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset"));
  return name;
}

const char* Inset::GetJSPropertyName() const {
  return "inset";
}



 // inset-block

CSSExposure InsetBlock::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetBlock::GetPropertyName() const {
  return "inset-block";
}

const WTF::AtomicString& InsetBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-block"));
  return name;
}

const char* InsetBlock::GetJSPropertyName() const {
  return "insetBlock";
}



 // inset-inline

CSSExposure InsetInline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetInline::GetPropertyName() const {
  return "inset-inline";
}

const WTF::AtomicString& InsetInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-inline"));
  return name;
}

const char* InsetInline::GetJSPropertyName() const {
  return "insetInline";
}



 // list-style



const char* ListStyle::GetPropertyName() const {
  return "list-style";
}

const WTF::AtomicString& ListStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style"));
  return name;
}

const char* ListStyle::GetJSPropertyName() const {
  return "listStyle";
}



 // margin



const char* Margin::GetPropertyName() const {
  return "margin";
}

const WTF::AtomicString& Margin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin"));
  return name;
}

const char* Margin::GetJSPropertyName() const {
  return "margin";
}



 // margin-block

CSSExposure MarginBlock::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* MarginBlock::GetPropertyName() const {
  return "margin-block";
}

const WTF::AtomicString& MarginBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-block"));
  return name;
}

const char* MarginBlock::GetJSPropertyName() const {
  return "marginBlock";
}



 // margin-inline

CSSExposure MarginInline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* MarginInline::GetPropertyName() const {
  return "margin-inline";
}

const WTF::AtomicString& MarginInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-inline"));
  return name;
}

const char* MarginInline::GetJSPropertyName() const {
  return "marginInline";
}



 // marker



const char* Marker::GetPropertyName() const {
  return "marker";
}

const WTF::AtomicString& Marker::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker"));
  return name;
}

const char* Marker::GetJSPropertyName() const {
  return "marker";
}



 // offset



const char* Offset::GetPropertyName() const {
  return "offset";
}

const WTF::AtomicString& Offset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset"));
  return name;
}

const char* Offset::GetJSPropertyName() const {
  return "offset";
}



 // outline



const char* Outline::GetPropertyName() const {
  return "outline";
}

const WTF::AtomicString& Outline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline"));
  return name;
}

const char* Outline::GetJSPropertyName() const {
  return "outline";
}



 // overflow



const char* Overflow::GetPropertyName() const {
  return "overflow";
}

const WTF::AtomicString& Overflow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow"));
  return name;
}

const char* Overflow::GetJSPropertyName() const {
  return "overflow";
}



 // overscroll-behavior



const char* OverscrollBehavior::GetPropertyName() const {
  return "overscroll-behavior";
}

const WTF::AtomicString& OverscrollBehavior::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior"));
  return name;
}

const char* OverscrollBehavior::GetJSPropertyName() const {
  return "overscrollBehavior";
}



 // padding



const char* Padding::GetPropertyName() const {
  return "padding";
}

const WTF::AtomicString& Padding::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding"));
  return name;
}

const char* Padding::GetJSPropertyName() const {
  return "padding";
}



 // padding-block

CSSExposure PaddingBlock::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* PaddingBlock::GetPropertyName() const {
  return "padding-block";
}

const WTF::AtomicString& PaddingBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-block"));
  return name;
}

const char* PaddingBlock::GetJSPropertyName() const {
  return "paddingBlock";
}



 // padding-inline

CSSExposure PaddingInline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* PaddingInline::GetPropertyName() const {
  return "padding-inline";
}

const WTF::AtomicString& PaddingInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-inline"));
  return name;
}

const char* PaddingInline::GetJSPropertyName() const {
  return "paddingInline";
}



 // page-break-after



const char* PageBreakAfter::GetPropertyName() const {
  return "page-break-after";
}

const WTF::AtomicString& PageBreakAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("page-break-after"));
  return name;
}

const char* PageBreakAfter::GetJSPropertyName() const {
  return "pageBreakAfter";
}



 // page-break-before



const char* PageBreakBefore::GetPropertyName() const {
  return "page-break-before";
}

const WTF::AtomicString& PageBreakBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("page-break-before"));
  return name;
}

const char* PageBreakBefore::GetJSPropertyName() const {
  return "pageBreakBefore";
}



 // page-break-inside



const char* PageBreakInside::GetPropertyName() const {
  return "page-break-inside";
}

const WTF::AtomicString& PageBreakInside::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("page-break-inside"));
  return name;
}

const char* PageBreakInside::GetJSPropertyName() const {
  return "pageBreakInside";
}



 // place-content



const char* PlaceContent::GetPropertyName() const {
  return "place-content";
}

const WTF::AtomicString& PlaceContent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("place-content"));
  return name;
}

const char* PlaceContent::GetJSPropertyName() const {
  return "placeContent";
}



 // place-items



const char* PlaceItems::GetPropertyName() const {
  return "place-items";
}

const WTF::AtomicString& PlaceItems::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("place-items"));
  return name;
}

const char* PlaceItems::GetJSPropertyName() const {
  return "placeItems";
}



 // place-self



const char* PlaceSelf::GetPropertyName() const {
  return "place-self";
}

const WTF::AtomicString& PlaceSelf::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("place-self"));
  return name;
}

const char* PlaceSelf::GetJSPropertyName() const {
  return "placeSelf";
}



 // scroll-margin



const char* ScrollMargin::GetPropertyName() const {
  return "scroll-margin";
}

const WTF::AtomicString& ScrollMargin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin"));
  return name;
}

const char* ScrollMargin::GetJSPropertyName() const {
  return "scrollMargin";
}



 // scroll-margin-block



const char* ScrollMarginBlock::GetPropertyName() const {
  return "scroll-margin-block";
}

const WTF::AtomicString& ScrollMarginBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-block"));
  return name;
}

const char* ScrollMarginBlock::GetJSPropertyName() const {
  return "scrollMarginBlock";
}



 // scroll-margin-inline



const char* ScrollMarginInline::GetPropertyName() const {
  return "scroll-margin-inline";
}

const WTF::AtomicString& ScrollMarginInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-inline"));
  return name;
}

const char* ScrollMarginInline::GetJSPropertyName() const {
  return "scrollMarginInline";
}



 // scroll-padding



const char* ScrollPadding::GetPropertyName() const {
  return "scroll-padding";
}

const WTF::AtomicString& ScrollPadding::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding"));
  return name;
}

const char* ScrollPadding::GetJSPropertyName() const {
  return "scrollPadding";
}



 // scroll-padding-block



const char* ScrollPaddingBlock::GetPropertyName() const {
  return "scroll-padding-block";
}

const WTF::AtomicString& ScrollPaddingBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-block"));
  return name;
}

const char* ScrollPaddingBlock::GetJSPropertyName() const {
  return "scrollPaddingBlock";
}



 // scroll-padding-inline



const char* ScrollPaddingInline::GetPropertyName() const {
  return "scroll-padding-inline";
}

const WTF::AtomicString& ScrollPaddingInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-inline"));
  return name;
}

const char* ScrollPaddingInline::GetJSPropertyName() const {
  return "scrollPaddingInline";
}



 // text-decoration



const char* TextDecoration::GetPropertyName() const {
  return "text-decoration";
}

const WTF::AtomicString& TextDecoration::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration"));
  return name;
}

const char* TextDecoration::GetJSPropertyName() const {
  return "textDecoration";
}



 // transition



const char* Transition::GetPropertyName() const {
  return "transition";
}

const WTF::AtomicString& Transition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition"));
  return name;
}

const char* Transition::GetJSPropertyName() const {
  return "transition";
}



 // -webkit-column-break-after



const char* WebkitColumnBreakAfter::GetPropertyName() const {
  return "-webkit-column-break-after";
}

const WTF::AtomicString& WebkitColumnBreakAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-break-after"));
  return name;
}

const char* WebkitColumnBreakAfter::GetJSPropertyName() const {
  return "webkitColumnBreakAfter";
}



 // -webkit-column-break-before



const char* WebkitColumnBreakBefore::GetPropertyName() const {
  return "-webkit-column-break-before";
}

const WTF::AtomicString& WebkitColumnBreakBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-break-before"));
  return name;
}

const char* WebkitColumnBreakBefore::GetJSPropertyName() const {
  return "webkitColumnBreakBefore";
}



 // -webkit-column-break-inside



const char* WebkitColumnBreakInside::GetPropertyName() const {
  return "-webkit-column-break-inside";
}

const WTF::AtomicString& WebkitColumnBreakInside::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-break-inside"));
  return name;
}

const char* WebkitColumnBreakInside::GetJSPropertyName() const {
  return "webkitColumnBreakInside";
}



 // -webkit-mask



const char* WebkitMask::GetPropertyName() const {
  return "-webkit-mask";
}

const WTF::AtomicString& WebkitMask::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask"));
  return name;
}

const char* WebkitMask::GetJSPropertyName() const {
  return "webkitMask";
}



 // -webkit-mask-box-image



const char* WebkitMaskBoxImage::GetPropertyName() const {
  return "-webkit-mask-box-image";
}

const WTF::AtomicString& WebkitMaskBoxImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image"));
  return name;
}

const char* WebkitMaskBoxImage::GetJSPropertyName() const {
  return "webkitMaskBoxImage";
}



 // -webkit-mask-position



const char* WebkitMaskPosition::GetPropertyName() const {
  return "-webkit-mask-position";
}

const WTF::AtomicString& WebkitMaskPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-position"));
  return name;
}

const char* WebkitMaskPosition::GetJSPropertyName() const {
  return "webkitMaskPosition";
}



 // -webkit-mask-repeat



const char* WebkitMaskRepeat::GetPropertyName() const {
  return "-webkit-mask-repeat";
}

const WTF::AtomicString& WebkitMaskRepeat::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-repeat"));
  return name;
}

const char* WebkitMaskRepeat::GetJSPropertyName() const {
  return "webkitMaskRepeat";
}



 // -webkit-text-emphasis



const char* WebkitTextEmphasis::GetPropertyName() const {
  return "-webkit-text-emphasis";
}

const WTF::AtomicString& WebkitTextEmphasis::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis"));
  return name;
}

const char* WebkitTextEmphasis::GetJSPropertyName() const {
  return "webkitTextEmphasis";
}



 // -webkit-text-stroke



const char* WebkitTextStroke::GetPropertyName() const {
  return "-webkit-text-stroke";
}

const WTF::AtomicString& WebkitTextStroke::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-stroke"));
  return name;
}

const char* WebkitTextStroke::GetJSPropertyName() const {
  return "webkitTextStroke";
}



 // -webkit-border-after



const char* WebkitBorderAfter::GetPropertyName() const {
  return "-webkit-border-after";
}

const WTF::AtomicString& WebkitBorderAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after"));
  return name;
}

const char* WebkitBorderAfter::GetJSPropertyName() const {
  return "webkitBorderAfter";
}
 // -webkit-border-before



const char* WebkitBorderBefore::GetPropertyName() const {
  return "-webkit-border-before";
}

const WTF::AtomicString& WebkitBorderBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before"));
  return name;
}

const char* WebkitBorderBefore::GetJSPropertyName() const {
  return "webkitBorderBefore";
}
 // -webkit-border-end



const char* WebkitBorderEnd::GetPropertyName() const {
  return "-webkit-border-end";
}

const WTF::AtomicString& WebkitBorderEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end"));
  return name;
}

const char* WebkitBorderEnd::GetJSPropertyName() const {
  return "webkitBorderEnd";
}
 // -webkit-border-start



const char* WebkitBorderStart::GetPropertyName() const {
  return "-webkit-border-start";
}

const WTF::AtomicString& WebkitBorderStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start"));
  return name;
}

const char* WebkitBorderStart::GetJSPropertyName() const {
  return "webkitBorderStart";
}
 // -epub-text-emphasis



const char* EpubTextEmphasis::GetPropertyName() const {
  return "-epub-text-emphasis";
}

const WTF::AtomicString& EpubTextEmphasis::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-emphasis"));
  return name;
}

const char* EpubTextEmphasis::GetJSPropertyName() const {
  return "epubTextEmphasis";
}
 // -webkit-animation



const char* WebkitAnimation::GetPropertyName() const {
  return "-webkit-animation";
}

const WTF::AtomicString& WebkitAnimation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation"));
  return name;
}

const char* WebkitAnimation::GetJSPropertyName() const {
  return "webkitAnimation";
}
 // -webkit-border-radius



const char* WebkitBorderRadius::GetPropertyName() const {
  return "-webkit-border-radius";
}

const WTF::AtomicString& WebkitBorderRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-radius"));
  return name;
}

const char* WebkitBorderRadius::GetJSPropertyName() const {
  return "webkitBorderRadius";
}
 // -webkit-column-rule



const char* WebkitColumnRule::GetPropertyName() const {
  return "-webkit-column-rule";
}

const WTF::AtomicString& WebkitColumnRule::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule"));
  return name;
}

const char* WebkitColumnRule::GetJSPropertyName() const {
  return "webkitColumnRule";
}
 // -webkit-columns



const char* WebkitColumns::GetPropertyName() const {
  return "-webkit-columns";
}

const WTF::AtomicString& WebkitColumns::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-columns"));
  return name;
}

const char* WebkitColumns::GetJSPropertyName() const {
  return "webkitColumns";
}
 // -webkit-flex



const char* WebkitFlex::GetPropertyName() const {
  return "-webkit-flex";
}

const WTF::AtomicString& WebkitFlex::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex"));
  return name;
}

const char* WebkitFlex::GetJSPropertyName() const {
  return "webkitFlex";
}
 // -webkit-flex-flow



const char* WebkitFlexFlow::GetPropertyName() const {
  return "-webkit-flex-flow";
}

const WTF::AtomicString& WebkitFlexFlow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-flow"));
  return name;
}

const char* WebkitFlexFlow::GetJSPropertyName() const {
  return "webkitFlexFlow";
}
 // -webkit-transition



const char* WebkitTransition::GetPropertyName() const {
  return "-webkit-transition";
}

const WTF::AtomicString& WebkitTransition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition"));
  return name;
}

const char* WebkitTransition::GetJSPropertyName() const {
  return "webkitTransition";
}
  
}  // namespace css_shorthand
}  // namespace blink
