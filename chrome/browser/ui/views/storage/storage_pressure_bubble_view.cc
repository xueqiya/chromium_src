// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/storage/storage_pressure_bubble_view.h"

#include "base/feature_list.h"
#include "chrome/browser/ui/browser_list.h"
#include "chrome/browser/ui/bubble_anchor_util.h"
#include "chrome/browser/ui/views/chrome_layout_provider.h"
#include "chrome/browser/ui/views/frame/app_menu_button.h"
#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/frame/toolbar_button_provider.h"
#include "chrome/grit/generated_resources.h"
#include "components/url_formatter/elide_url.h"
#include "content/public/common/content_features.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/views/layout/box_layout.h"

namespace {

const char kAllSitesContentSettingsUrl[] = "chrome://settings/content/all";

}  // namespace

namespace chrome {

// static
void ShowStoragePressureBubble(const url::Origin origin) {
  StoragePressureBubbleView::ShowBubble(std::move(origin));
}

}  // namespace chrome

void StoragePressureBubbleView::ShowBubble(const url::Origin origin) {
  Browser* browser = BrowserList::GetInstance()->GetLastActive();
  if (!browser || !base::FeatureList::IsEnabled(features::kStoragePressureUI))
    return;

  StoragePressureBubbleView* bubble = new StoragePressureBubbleView(
      BrowserView::GetBrowserViewForBrowser(browser)
          ->toolbar_button_provider()
          ->GetAppMenuButton(),
      gfx::Rect(), browser, std::move(origin));
  views::BubbleDialogDelegateView::CreateBubble(bubble)->Show();
}

StoragePressureBubbleView::StoragePressureBubbleView(
    views::View* anchor_view,
    const gfx::Rect& anchor_rect,
    Browser* browser,
    const url::Origin origin)
    : BubbleDialogDelegateView(anchor_view, views::BubbleBorder::TOP_RIGHT),
      browser_(browser),
      origin_(std::move(origin)) {
  if (!anchor_view) {
    SetAnchorRect(anchor_rect);
    set_parent_window(
        platform_util::GetViewForWindow(browser->window()->GetNativeWindow()));
  }
  DialogDelegate::set_buttons(ui::DIALOG_BUTTON_OK);
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_OK,
      l10n_util::GetStringUTF16(
          IDS_SETTINGS_STORAGE_PRESSURE_BUBBLE_VIEW_BUTTON_LABEL));
  DialogDelegate::set_accept_callback(base::BindOnce(
      &StoragePressureBubbleView::OnDialogAccepted, base::Unretained(this)));
}

base::string16 StoragePressureBubbleView::GetWindowTitle() const {
  return l10n_util::GetStringUTF16(
      IDS_SETTINGS_STORAGE_PRESSURE_BUBBLE_VIEW_TITLE);
}

void StoragePressureBubbleView::OnDialogAccepted() {
  // TODO(ellyjones): What is this doing here? The widget's about to close
  // anyway?
  GetWidget()->Close();
  const GURL all_sites_gurl(kAllSitesContentSettingsUrl);
  NavigateParams params(browser_, all_sites_gurl,
                        ui::PAGE_TRANSITION_AUTO_TOPLEVEL);
  params.disposition = WindowOpenDisposition::NEW_FOREGROUND_TAB;
  Navigate(&params);
}

void StoragePressureBubbleView::Init() {
  ChromeLayoutProvider* provider = ChromeLayoutProvider::Get();
  SetLayoutManager(std::make_unique<views::BoxLayout>(
      views::BoxLayout::Orientation::kVertical, gfx::Insets(),
      provider->GetDistanceMetric(views::DISTANCE_UNRELATED_CONTROL_VERTICAL)));

  // Description text label.
  auto text_label = std::make_unique<views::Label>(l10n_util::GetStringFUTF16(
      IDS_SETTINGS_STORAGE_PRESSURE_BUBBLE_VIEW_MESSAGE,
      url_formatter::FormatOriginForSecurityDisplay(origin_)));
  text_label->SetMultiLine(true);
  text_label->SetLineHeight(20);
  text_label->SetHorizontalAlignment(gfx::ALIGN_LEFT);
  text_label->SizeToFit(
      provider->GetDistanceMetric(
          ChromeDistanceMetric::DISTANCE_BUBBLE_PREFERRED_WIDTH) -
      margins().width());
  AddChildView(std::move(text_label));
}
