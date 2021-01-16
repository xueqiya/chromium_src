// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/system/session/shutdown_confirmation_dialog.h"

#include <memory>
#include <utility>

#include "ash/public/cpp/shell_window_ids.h"
#include "ash/shell.h"
#include "ash/strings/grit/ash_strings.h"
#include "base/bind.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/ui_base_types.h"
#include "ui/views/border.h"
#include "ui/views/controls/label.h"
#include "ui/views/layout/fill_layout.h"
#include "ui/views/layout/layout_provider.h"
#include "ui/views/widget/widget.h"

namespace ash {

namespace {

// Default width of the dialog in DIPs.
constexpr int kDefaultWidth = 448;

}  // namespace

ShutdownConfirmationDialog::ShutdownConfirmationDialog(
    int window_title_text_id,
    int dialog_text_id,
    base::OnceClosure on_accept_callback,
    base::OnceClosure on_cancel_callback)
    : window_title_(l10n_util::GetStringUTF16(window_title_text_id)),
      on_accept_callback_(std::move(on_accept_callback)),
      on_cancel_callback_(std::move(on_cancel_callback)) {
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_OK,
      l10n_util::GetStringUTF16(IDS_ASH_SHUTDOWN_CONFIRMATION_OK_BUTTON));
  DialogDelegate::set_button_label(
      ui::DIALOG_BUTTON_CANCEL,
      l10n_util::GetStringUTF16(IDS_ASH_SHUTDOWN_CONFIRMATION_CANCEL_BUTTON));
  SetLayoutManager(std::make_unique<views::FillLayout>());
  SetBorder(views::CreateEmptyBorder(
      views::LayoutProvider::Get()->GetDialogInsetsForContentType(
          views::TEXT, views::TEXT)));

  label_ = new views::Label;
  label_->SetHorizontalAlignment(gfx::ALIGN_LEFT);
  label_->SetMultiLine(true);
  label_->SetText(l10n_util::GetStringUTF16(dialog_text_id));
  AddChildView(label_);

  // Parent the dialog widget to the PowerButtonAnimationContainer
  int container_id = kShellWindowId_PowerButtonAnimationContainer;
  views::Widget* widget = CreateDialogWidget(
      this, nullptr,
      Shell::GetContainer(ash::Shell::GetRootWindowForNewWindows(),
                          container_id));
  widget->Show();
}

ShutdownConfirmationDialog::~ShutdownConfirmationDialog() = default;

bool ShutdownConfirmationDialog::Accept() {
  std::move(on_accept_callback_).Run();
  return true;
}

bool ShutdownConfirmationDialog::Cancel() {
  std::move(on_cancel_callback_).Run();
  return true;
}

ui::ModalType ShutdownConfirmationDialog::GetModalType() const {
  return ui::MODAL_TYPE_SYSTEM;
}

base::string16 ShutdownConfirmationDialog::GetWindowTitle() const {
  return window_title_;
}

bool ShutdownConfirmationDialog::ShouldShowCloseButton() const {
  return false;
}

gfx::Size ShutdownConfirmationDialog::CalculatePreferredSize() const {
  return gfx::Size(
      kDefaultWidth,
      GetLayoutManager()->GetPreferredHeightForWidth(this, kDefaultWidth));
}

}  // namespace ash
