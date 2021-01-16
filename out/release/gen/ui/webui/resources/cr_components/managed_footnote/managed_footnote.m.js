// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview Polymer element for indicating that this user is managed by
 * their organization. This component uses the |isManaged| boolean in
 * loadTimeData, and the |managedByOrg| i18n string.
 *
 * If |isManaged| is false, this component is hidden. If |isManaged| is true, it
 * becomes visible.
 */

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../../cr_elements/icons.m.js';
import '../../cr_elements/shared_vars_css.m.js';
import {I18nBehavior} from '../../js/i18n_behavior.m.js';
import {loadTimeData} from '../../js/load_time_data.m.js';
import {WebUIListenerBehavior} from '../../js/web_ui_listener_behavior.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        align-items: center;
        border-top: 1px solid var(--cr-separator-color);
        color: var(--cr-secondary-text-color);
        display: none;
        /* Should be 13px when <html> font-size is 16px */
        font-size: 0.8125rem;
        justify-content: center;
        padding: 0 24px;
      }

      :host([is-managed_]) {
        display: flex;
      }

      a[href] {
        color: var(--cr-link-color);
        text-decoration: none;
      }

      iron-icon {
        align-self: flex-start;
        flex-shrink: 0;
        height: 20px;
        padding-inline-end: var(--managed-footnote-icon-padding, 8px);
        width: 20px;
      }
    </style>

    <template is="dom-if" if="[[isManaged_]]">
      <iron-icon icon="cr:domain"></iron-icon>
      <div id="content"
          inner-h-t-m-l="[[getManagementString_(showDeviceInfo)]]">
      </div>
    </template>
<!--_html_template_end_-->`,
  is: 'managed-footnote',

  behaviors: [I18nBehavior, WebUIListenerBehavior],

  properties: {
    /**
     * Whether the user is managed by their organization through enterprise
     * policies.
     * @type {boolean}
     * @private
     */
    isManaged_: {
      reflectToAttribute: true,
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('isManaged');
      },
    },

    /**
     * Whether the device should be indicated as managed rather than the
     * browser.
     * @type {boolean}
     */
    showDeviceInfo: {
      type: Boolean,
      value: false,
    }
  },

  /** @override */
  ready() {
    this.addWebUIListener('is-managed-changed', managed => {
      loadTimeData.overrideValues({isManaged: managed});
      this.isManaged_ = managed;
    });
  },

  /**
   * @return {string} Message to display to the user.
   * @private
   */
  getManagementString_() {
    // <if expr="chromeos">
    if (this.showDeviceInfo) {
      return this.i18nAdvanced('deviceManagedByOrg');
    }
    // </if>
    return this.i18nAdvanced('browserManagedByOrg');
  },
});

chrome.send('observeManagedUI');
