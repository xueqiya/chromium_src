// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/toolbar/webui_tab_counter_button.h"

#include <memory>

#include "base/i18n/message_formatter.h"
#include "base/i18n/number_formatting.h"
#include "base/strings/utf_string_conversions.h"
#include "chrome/browser/themes/theme_properties.h"
#include "chrome/browser/ui/layout_constants.h"
#include "chrome/browser/ui/tabs/tab_strip_model.h"
#include "chrome/browser/ui/tabs/tab_strip_model_observer.h"
#include "chrome/browser/ui/view_ids.h"
#include "chrome/browser/ui/views/chrome_typography.h"
#include "chrome/browser/ui/views/chrome_view_class_properties.h"
#include "chrome/browser/ui/views/feature_promos/feature_promo_colors.h"
#include "chrome/browser/ui/views/toolbar/toolbar_ink_drop_util.h"
#include "chrome/grit/generated_resources.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/theme_provider.h"
#include "ui/gfx/animation/multi_animation.h"
#include "ui/gfx/animation/slide_animation.h"
#include "ui/gfx/animation/tween.h"
#include "ui/gfx/color_palette.h"
#include "ui/views/animation/ink_drop.h"
#include "ui/views/animation/ink_drop_highlight.h"
#include "ui/views/controls/label.h"
#include "ui/views/layout/flex_layout.h"
#include "ui/views/layout/layout_provider.h"
#include "ui/views/view_class_properties.h"

namespace {

constexpr int kDesiredBorderHeight = 22;
// TODO(999557): Change this to 32 when the font is changed to Roboto.
constexpr int kDoubleDigitWidth = 30;
constexpr int kOffscreenLabelDistance = 16;

constexpr base::TimeDelta kFirstPartDuration =
    base::TimeDelta::FromMilliseconds(100);

// Animates the label and border. |border_view_| does a little bounce. At the
// peak of |border_view_|'s bounce, the |disappearing_label_| begins to scroll
// away in the same direction and is replaced with |appearing_label_|, which
// shows the new number of tabs. This animation is played upside-down when a tab
// is added vs. removed.
class TabCounterAnimator : public gfx::AnimationDelegate {
 public:
  TabCounterAnimator(views::View* appearing_label,
                     views::View* disappearing_label,
                     views::View* border_view)
      : appearing_label_(appearing_label),
        disappearing_label_(disappearing_label),
        label_animation_(
            std::vector<gfx::MultiAnimation::Part>{
                // Stay in place.
                gfx::MultiAnimation::Part(kFirstPartDuration,
                                          gfx::Tween::Type::ZERO),
                // Swap out to the new label.
                gfx::MultiAnimation::Part(
                    base::TimeDelta::FromMilliseconds(200),
                    gfx::Tween::Type::EASE_IN_OUT)},
            gfx::MultiAnimation::kDefaultTimerInterval),
        border_view_(border_view),
        border_animation_(
            std::vector<gfx::MultiAnimation::Part>{
                gfx::MultiAnimation::Part(kFirstPartDuration,
                                          gfx::Tween::Type::EASE_OUT),
                gfx::MultiAnimation::Part(
                    base::TimeDelta::FromMilliseconds(150),
                    gfx::Tween::Type::EASE_IN_OUT),
                gfx::MultiAnimation::Part(base::TimeDelta::FromMilliseconds(50),
                                          gfx::Tween::Type::EASE_IN_OUT)},
            gfx::MultiAnimation::kDefaultTimerInterval) {
    label_animation_.set_delegate(this);
    label_animation_.set_continuous(false);

    border_animation_.set_delegate(this);
    border_animation_.set_continuous(false);
  }
  ~TabCounterAnimator() override = default;

  void Animate(bool increasing) {
    increasing_ = increasing;

    border_animation_.Stop();
    border_animation_.Start();
    label_animation_.Stop();
    label_animation_.Start();
    AnimationProgressed(&label_animation_);
  }

  void LayoutIfAnimating() {
    if (!border_animation_.is_animating() && !label_animation_.is_animating())
      return;

    // |border_view_| does a hop (if |increasing_| is false) or a dip (if true).
    int border_y_delta = 0;
    switch (border_animation_.current_part_index()) {
      case 0:
        // Move away.
        border_y_delta = gfx::Tween::IntValueBetween(
            border_animation_.GetCurrentValue(), 0, GetBorderTargetYDelta());
        break;
      case 1:
        // Return, slightly overshooting the start position.
        border_y_delta = gfx::Tween::IntValueBetween(
            border_animation_.GetCurrentValue(), GetBorderTargetYDelta(),
            GetBorderOvershootYDelta());
        break;
      case 2:
        // Return back to the start position.
        border_y_delta = gfx::Tween::IntValueBetween(
            border_animation_.GetCurrentValue(), GetBorderOvershootYDelta(), 0);
        break;
      default:
        NOTREACHED();
    }
    border_view_->SetY(GetBorderStartingY() + border_y_delta);

    // |appearing_label_| scrolls into view - from above if |increasing_|
    // is false, and from below otherwise.
    const int appearing_label_position =
        gfx::Tween::IntValueBetween(label_animation_.GetCurrentValue(),
                                    GetAppearingLabelStartPosition(), 0);
    appearing_label_->SetY(appearing_label_position - border_y_delta);

    // |disappearing_label_| scrolls out of view - out the bottom if
    // |increasing_| is false, and from below otherwise.
    const int disappearing_label_position =
        gfx::Tween::IntValueBetween(label_animation_.GetCurrentValue(), 0,
                                    GetDisappearingLabelTargetPosition());
    disappearing_label_->SetY(disappearing_label_position - border_y_delta);
  }

  // AnimationDelegate:
  void AnimationProgressed(const gfx::Animation* animation) override {
    LayoutIfAnimating();
  }

  void AnimationEnded(const gfx::Animation* animation) override {
    LayoutIfAnimating();
  }

 private:
  int GetBorderTargetYDelta() const { return increasing_ ? 4 : -4; }

  int GetBorderOvershootYDelta() const { return increasing_ ? -2 : 2; }

  int GetAppearingLabelStartPosition() const {
    return increasing_ ? -kOffscreenLabelDistance : kOffscreenLabelDistance;
  }

  int GetDisappearingLabelTargetPosition() const {
    // We want to exit out the opposite side that |appearing_label_| entered
    // from.
    return -GetAppearingLabelStartPosition();
  }

  int GetBorderStartingY() const {
    // When at rest, |border_view_| should be vertically centered within its
    // container.
    views::View* border_container = border_view_->parent();
    int border_available_space = border_container->GetLocalBounds().height();
    return (border_available_space - border_view_->GetLocalBounds().height()) /
           2;
  }

  // The label that will be animated into view, showing the new value.
  views::View* const appearing_label_;
  // The label that will be animated out of view, showing the old value.
  views::View* const disappearing_label_;
  gfx::MultiAnimation label_animation_;

  views::View* const border_view_;
  gfx::MultiAnimation border_animation_;

  // True if the counter is currently animating an increase in the displayed
  // number. The animation is played one way to show a decrease, and upside
  // down from that to show an increase.
  bool increasing_ = false;

  DISALLOW_COPY_AND_ASSIGN(TabCounterAnimator);
};

class WebUITabCounterButton : public views::Button,
                              public TabStripModelObserver {
 public:
  explicit WebUITabCounterButton(views::ButtonListener* listener);
  ~WebUITabCounterButton() override;

  void UpdateText(int num_tabs);
  void UpdateColors();
  void Init(TabStripModel* model);

  // views::Button:
  void AfterPropertyChange(const void* key, int64_t old_value) override;
  void AddLayerBeneathView(ui::Layer* new_layer) override;
  void RemoveLayerBeneathView(ui::Layer* old_layer) override;
  void OnThemeChanged() override;
  void Layout() override;

  // TabStripModelObserver:
  void OnTabStripModelChanged(
      TabStripModel* tab_strip_model,
      const TabStripModelChange& change,
      const TabStripSelectionChange& selection) override;

  views::InkDropContainerView* ink_drop_container_;
  views::Label* appearing_label_;
  views::Label* disappearing_label_;
  views::View* border_view_;
  std::unique_ptr<TabCounterAnimator> animator_;

  base::Optional<int> last_num_tabs_ = base::nullopt;
  int num_tabs_ = 0;
};

WebUITabCounterButton::WebUITabCounterButton(views::ButtonListener* listener)
    : views::Button(listener) {}

WebUITabCounterButton::~WebUITabCounterButton() = default;

void WebUITabCounterButton::UpdateText(int num_tabs) {
  num_tabs_ = num_tabs;
  if (num_tabs_ == last_num_tabs_)
    return;

  // |disappearing_label_| should keep the text that was previously visible.
  disappearing_label_->SetText(appearing_label_->GetText());

  SetTooltipText(base::i18n::MessageFormatter::FormatWithNumberedArgs(
      l10n_util::GetStringUTF16(IDS_TOOLTIP_WEBUI_TAB_STRIP_TAB_COUNTER),
      num_tabs_));
  if (num_tabs_ < 100) {
    appearing_label_->SetText(base::FormatNumber(num_tabs_));
  } else {
    // In the triple-digit case, fall back to ':D' to match Android.
    appearing_label_->SetText(base::string16(base::ASCIIToUTF16(":D")));
  }

  InvalidateLayout();

  if (last_num_tabs_) {
    const bool increasing = last_num_tabs_.value() < num_tabs_;
    animator_->Animate(increasing);
  }
  last_num_tabs_ = num_tabs_;
}

void WebUITabCounterButton::UpdateColors() {
  const ui::ThemeProvider* theme_provider = GetThemeProvider();
  const SkColor toolbar_color =
      theme_provider ? theme_provider->GetColor(ThemeProperties::COLOR_TOOLBAR)
                     : gfx::kPlaceholderColor;
  appearing_label_->SetBackgroundColor(toolbar_color);
  disappearing_label_->SetBackgroundColor(toolbar_color);

  const SkColor normal_text_color =
      theme_provider
          ? theme_provider->GetColor(ThemeProperties::COLOR_TOOLBAR_BUTTON_ICON)
          : gfx::kPlaceholderColor;
  const SkColor current_text_color =
      GetProperty(kHasInProductHelpPromoKey)
          ? GetFeaturePromoHighlightColorForToolbar(theme_provider)
          : normal_text_color;

  appearing_label_->SetEnabledColor(current_text_color);
  disappearing_label_->SetEnabledColor(current_text_color);
  border_view_->SetBorder(views::CreateRoundedRectBorder(
      2,
      views::LayoutProvider::Get()->GetCornerRadiusMetric(
          views::EMPHASIS_MEDIUM),
      current_text_color));
}

void WebUITabCounterButton::Init(TabStripModel* tab_strip_model) {
  SetID(VIEW_ID_WEBUI_TAB_STRIP_TAB_COUNTER);

  SetProperty(views::kFlexBehaviorKey,
              views::FlexSpecification::ForSizeRule(
                  views::MinimumFlexSizeRule::kScaleToMinimum,
                  views::MaximumFlexSizeRule::kPreferred)
                  .WithOrder(1));

  const int button_height = GetLayoutConstant(TOOLBAR_BUTTON_HEIGHT);
  SetPreferredSize(gfx::Size(button_height, button_height));

  ink_drop_container_ =
      AddChildView(std::make_unique<views::InkDropContainerView>());
  ink_drop_container_->SetBoundsRect(GetLocalBounds());

  border_view_ = AddChildView(std::make_unique<views::View>());

  appearing_label_ = border_view_->AddChildView(std::make_unique<views::Label>(
      base::string16(), CONTEXT_WEB_UI_TAB_COUNTER));
  disappearing_label_ =
      border_view_->AddChildView(std::make_unique<views::Label>(
          base::string16(), CONTEXT_WEB_UI_TAB_COUNTER));

  animator_ = std::make_unique<TabCounterAnimator>(
      appearing_label_, disappearing_label_, border_view_);

  tab_strip_model->AddObserver(this);
  UpdateText(tab_strip_model->count());
}

void WebUITabCounterButton::AfterPropertyChange(const void* key,
                                                int64_t old_value) {
  if (key != kHasInProductHelpPromoKey)
    return;
  UpdateColors();
}

void WebUITabCounterButton::AddLayerBeneathView(ui::Layer* new_layer) {
  ink_drop_container_->AddLayerBeneathView(new_layer);
}

void WebUITabCounterButton::RemoveLayerBeneathView(ui::Layer* old_layer) {
  ink_drop_container_->RemoveLayerBeneathView(old_layer);
}

void WebUITabCounterButton::OnThemeChanged() {
  UpdateColors();
  ConfigureInkDropForToolbar(this);
}

void WebUITabCounterButton::Layout() {
  const int button_height = GetLocalBounds().height();
  const int inset_height = (button_height - kDesiredBorderHeight) / 2;
  const int border_width = (num_tabs_ >= 10 && num_tabs_ < 100)
                               ? kDoubleDigitWidth
                               : kDesiredBorderHeight;
  const int inset_width = (button_height - border_width) / 2;
  border_view_->SetBounds(inset_width, inset_height, border_width,
                          kDesiredBorderHeight);
  appearing_label_->SetBounds(0, 0, border_width, kDesiredBorderHeight);
  disappearing_label_->SetBounds(0, -kOffscreenLabelDistance, border_width,
                                 kDesiredBorderHeight);

  animator_->LayoutIfAnimating();
}

void WebUITabCounterButton::OnTabStripModelChanged(
    TabStripModel* tab_strip_model,
    const TabStripModelChange& change,
    const TabStripSelectionChange& selection) {
  UpdateText(tab_strip_model->count());
}

}  // namespace

std::unique_ptr<views::View> CreateWebUITabCounterButton(
    views::ButtonListener* listener,
    TabStripModel* tab_strip_model) {
  auto tab_counter = std::make_unique<WebUITabCounterButton>(listener);

  tab_counter->Init(tab_strip_model);

  return tab_counter;
}
