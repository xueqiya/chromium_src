// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/safe_browsing/prompt_for_scanning_modal_dialog.h"

#include <memory>

#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "chrome/browser/ui/views/chrome_layout_provider.h"
#include "chrome/common/url_constants.h"
#include "chrome/grit/generated_resources.h"
#include "components/constrained_window/constrained_window_views.h"
#include "components/strings/grit/components_strings.h"
#include "content/public/browser/web_contents.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/page_transition_types.h"
#include "ui/base/ui_base_types.h"
#include "ui/base/window_open_disposition.h"
#include "ui/views/controls/button/md_text_button.h"
#include "ui/views/controls/styled_label.h"
#include "ui/views/layout/grid_layout.h"
#include "ui/views/window/dialog_delegate.h"

namespace safe_browsing {

/*static*/
void PromptForScanningModalDialog::ShowForWebContents(
    content::WebContents* web_contents,
    base::OnceClosure accept_callback,
    base::OnceClosure open_now_callback) {
  constrained_window::ShowWebModalDialogViews(
      new PromptForScanningModalDialog(web_contents, std::move(accept_callback),
                                       std::move(open_now_callback)),
      web_contents);
}

PromptForScanningModalDialog::PromptForScanningModalDialog(
    content::WebContents* web_contents,
    base::OnceClosure accept_callback,
    base::OnceClosure open_now_callback)
    : web_contents_(web_contents),
      accept_callback_(std::move(accept_callback)),
      open_now_callback_(std::move(open_now_callback)) {
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_OK,
      l10n_util::GetStringUTF16(IDS_DEEP_SCANNING_INFO_DIALOG_ACCEPT_BUTTON));
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_CANCEL,
      l10n_util::GetStringUTF16(IDS_DEEP_SCANNING_INFO_DIALOG_CANCEL_BUTTON));
  auto open_now_button = views::MdTextButton::CreateSecondaryUiButton(
      this,
      l10n_util::GetStringUTF16(IDS_DEEP_SCANNING_INFO_DIALOG_OPEN_NOW_BUTTON));
  open_now_button_ = DialogDelegate::SetExtraView(std::move(open_now_button));

  set_margins(ChromeLayoutProvider::Get()->GetDialogInsetsForContentType(
      views::TEXT, views::TEXT));
  views::GridLayout* layout =
      SetLayoutManager(std::make_unique<views::GridLayout>());

  // Use a fixed maximum message width, so longer messages will wrap.
  const int kMaxMessageWidth = 400;
  views::ColumnSet* cs = layout->AddColumnSet(0);
  cs->AddColumn(views::GridLayout::LEADING, views::GridLayout::CENTER,
                views::GridLayout::kFixedSize, views::GridLayout::FIXED,
                kMaxMessageWidth, false);

  // Create the message label text.
  std::vector<size_t> offsets;
  base::string16 message_text = base::ReplaceStringPlaceholders(
      base::ASCIIToUTF16("$1 $2"),
      {l10n_util::GetStringUTF16(IDS_DEEP_SCANNING_INFO_DIALOG_MESSAGE),
       l10n_util::GetStringUTF16(IDS_LEARN_MORE)},
      &offsets);

  // Add the message label.
  auto label = std::make_unique<views::StyledLabel>(message_text, this);

  gfx::Range learn_more_range(offsets[1], message_text.length());
  views::StyledLabel::RangeStyleInfo link_style =
      views::StyledLabel::RangeStyleInfo::CreateForLink();
  label->AddStyleRange(learn_more_range, link_style);

  label->SetHorizontalAlignment(gfx::ALIGN_LEFT);
  label->SizeToFit(kMaxMessageWidth);
  layout->StartRow(views::GridLayout::kFixedSize, 0);
  layout->AddView(std::move(label));
}

PromptForScanningModalDialog::~PromptForScanningModalDialog() = default;

bool PromptForScanningModalDialog::IsDialogButtonEnabled(
    ui::DialogButton button) const {
  return (button == ui::DIALOG_BUTTON_OK || button == ui::DIALOG_BUTTON_CANCEL);
}

bool PromptForScanningModalDialog::Accept() {
  std::move(accept_callback_).Run();
  return true;
}

bool PromptForScanningModalDialog::Cancel() {
  return true;
}

bool PromptForScanningModalDialog::ShouldShowCloseButton() const {
  return false;
}

base::string16 PromptForScanningModalDialog::GetWindowTitle() const {
  return l10n_util::GetStringUTF16(IDS_DEEP_SCANNING_INFO_DIALOG_TITLE);
}

ui::ModalType PromptForScanningModalDialog::GetModalType() const {
  return ui::MODAL_TYPE_CHILD;
}

void PromptForScanningModalDialog::ButtonPressed(views::Button* sender,
                                                 const ui::Event& event) {
  if (sender == open_now_button_) {
    std::move(open_now_callback_).Run();
    CancelDialog();
  }
}

void PromptForScanningModalDialog::StyledLabelLinkClicked(
    views::StyledLabel* label,
    const gfx::Range& range,
    int event_flags) {
  web_contents_->OpenURL(content::OpenURLParams(
      GURL(chrome::kAdvancedProtectionDownloadLearnMoreURL),
      content::Referrer(), WindowOpenDisposition::NEW_FOREGROUND_TAB,
      ui::PAGE_TRANSITION_LINK, /*is_renderer_initiated=*/false));
}

}  // namespace safe_browsing
