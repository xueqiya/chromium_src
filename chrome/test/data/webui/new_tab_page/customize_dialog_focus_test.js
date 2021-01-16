// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://new-tab-page/customize_dialog.js';

import {keydown} from 'chrome://test/new_tab_page/test_support.js';
import {flushTasks} from 'chrome://test/test_util.m.js';

suite('NewTabPageCustomizeDialogFocusTest', () => {
  /** @type {!CustomizeDialogElement} */
  let customizeDialog;

  setup(async () => {
    PolymerTest.clearBody();

    customizeDialog = document.createElement('ntp-customize-dialog');
    document.body.appendChild(customizeDialog);
    await flushTasks();
  });

  test('space selects focused menu item', async () => {
    // Arrange.
    const menuItem = customizeDialog.shadowRoot.querySelector(
        '.menu-item[page-name="themes"');
    menuItem.focus();

    // Act.
    keydown(menuItem, ' ');

    // Assert.
    assertEquals(customizeDialog.$.menu.selected, 'themes');
  });

  test('enter selects focused menu item', async () => {
    // Arrange.
    const menuItem = customizeDialog.shadowRoot.querySelector(
        '.menu-item[page-name="shortcuts"');
    menuItem.focus();

    // Act.
    keydown(menuItem, 'Enter');

    // Assert.
    assertEquals(customizeDialog.$.menu.selected, 'shortcuts');
  });
});
