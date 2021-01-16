// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/display/display_change_dialog.h"

#include "ash/public/cpp/shell_window_ids.h"
#include "ash/session/session_controller_impl.h"
#include "ash/shell.h"
#include "ash/strings/grit/ash_strings.h"
#include "base/bind.h"
#include "base/strings/strcat.h"
#include "base/strings/string_util.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/l10n/time_format.h"
#include "ui/base/ui_base_types.h"
#include "ui/views/border.h"
#include "ui/views/controls/label.h"
#include "ui/views/layout/fill_layout.h"
#include "ui/views/layout/layout_provider.h"
#include "ui/views/widget/widget.h"

namespace ash {

DisplayChangeDialog::DisplayChangeDialog(
    base::string16 window_title,
    base::string16 timeout_message_with_placeholder,
    base::OnceClosure on_accept_callback,
    CancelCallback on_cancel_callback)
    : window_title_(std::move(window_title)),
      timeout_message_with_placeholder_(
          std::move(timeout_message_with_placeholder)),
      on_cancel_callback_(std::move(on_cancel_callback)) {
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_OK, l10n_util::GetStringUTF16(IDS_ASH_CONFIRM_BUTTON));

  DialogDelegate::set_accept_callback(std::move(on_accept_callback));
  DialogDelegate::set_cancel_callback(base::BindOnce(
      &DisplayChangeDialog::OnCancelButtonClicked, base::Unretained(this)));

  SetLayoutManager(std::make_unique<views::FillLayout>());
  SetBorder(views::CreateEmptyBorder(
      views::LayoutProvider::Get()->GetDialogInsetsForContentType(
          views::TEXT, views::TEXT)));
  label_ =
      AddChildView(std::make_unique<views::Label>(GetRevertTimeoutString()));
  label_->SetMultiLine(true);

  views::Widget* widget = CreateDialogWidget(
      this, nullptr,
      Shell::GetContainer(Shell::GetPrimaryRootWindow(),
                          kShellWindowId_SystemModalContainer));
  widget->Show();

  timer_.Start(FROM_HERE, base::TimeDelta::FromSeconds(1), this,
               &DisplayChangeDialog::OnTimerTick);
}

DisplayChangeDialog::~DisplayChangeDialog() = default;

void DisplayChangeDialog::OnCancelButtonClicked() {
  timer_.Stop();
  std::move(on_cancel_callback_).Run(/*display_was_removed=*/false);
}

ui::ModalType DisplayChangeDialog::GetModalType() const {
  return ui::MODAL_TYPE_SYSTEM;
}

base::string16 DisplayChangeDialog::GetWindowTitle() const {
  return window_title_;
}

gfx::Size DisplayChangeDialog::CalculatePreferredSize() const {
  return gfx::Size(350, 100);
}

void DisplayChangeDialog::OnTimerTick() {
  if (--timeout_count_ == 0) {
    CancelDialog();
    return;
  }

  label_->SetText(GetRevertTimeoutString());
}

base::string16 DisplayChangeDialog::GetRevertTimeoutString() const {
  const base::string16 timer = ui::TimeFormat::Simple(
      ui::TimeFormat::FORMAT_DURATION, ui::TimeFormat::LENGTH_LONG,
      base::TimeDelta::FromSeconds(timeout_count_));
  return base::ReplaceStringPlaceholders(timeout_message_with_placeholder_,
                                         timer, /*offset=*/nullptr);
}

base::WeakPtr<DisplayChangeDialog> DisplayChangeDialog::GetWeakPtr() {
  return weak_factory_.GetWeakPtr();
}

}  // namespace ash
