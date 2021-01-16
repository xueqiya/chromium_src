// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview A dialog prompting the user for a decryption password such that
 * a previously exported personal certificate can be imported.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import './certificate_shared_css.m.js';
import {CertificatesBrowserProxy, CertificatesBrowserProxyImpl} from './certificates_browser_proxy.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="certificate-shared">
      cr-input {
        --cr-input-error-display: none;
      }
    </style>
    <cr-dialog id="dialog" close-text="[[i18n('close')]]">
      <div slot="title">
        [[i18n('certificateManagerDecryptPasswordTitle')]]
      </div>
      <div slot="body">
        <cr-input type="password" id="password"
            label="[[i18n('certificateManagerPassword')]]"
            value="{{password_}}" autofocus>
        </cr-input>
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onCancelTap_">
          [[i18n('cancel')]]
        </cr-button>
        <cr-button id="ok" class="action-button" on-click="onOkTap_">
          [[i18n('ok')]]
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,
  is: 'certificate-password-decryption-dialog',

  behaviors: [I18nBehavior],

  properties: {
    /** @private */
    password_: {
      type: String,
      value: '',
    },
  },

  /** @private {?CertificatesBrowserProxy} */
  browserProxy_: null,

  /** @override */
  ready() {
    this.browserProxy_ =
        CertificatesBrowserProxyImpl.getInstance();
  },

  /** @override */
  attached() {
    /** @type {!CrDialogElement} */ (this.$.dialog).showModal();
  },

  /** @private */
  onCancelTap_() {
    /** @type {!CrDialogElement} */ (this.$.dialog).close();
  },

  /** @private */
  onOkTap_() {
    this.browserProxy_.importPersonalCertificatePasswordSelected(this.password_)
        .then(
            () => {
              /** @type {!CrDialogElement} */ (this.$.dialog).close();
            },
            error => {
              /** @type {!CrDialogElement} */ (this.$.dialog).close();
              this.fire('certificates-error', {error: error, anchor: null});
            });
  },
});
