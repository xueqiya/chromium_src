// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview A dialog prompting the user to encrypt a personal certificate
 * before it is exported to disk.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import './certificate_shared_css.m.js';
import {CertificatesBrowserProxy, CertificatesBrowserProxyImpl, CertificateSubnode} from './certificates_browser_proxy.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="certificate-shared">
      cr-input {
        --cr-input-error-display: none;
        margin-top: var(--cr-form-field-bottom-spacing);
      }

      .password-buttons {
        margin-bottom: 20px;
      }
    </style>
    <cr-dialog id="dialog" close-text="[[i18n('close')]]">
      <div slot="title">
        [[i18n('certificateManagerEncryptPasswordTitle')]]
      </div>
      <div slot="body">
        <div>[[i18n('certificateManagerEncryptPasswordDescription')]]</div>
        <div class="password-buttons">
          <cr-input type="password" value="{{password_}}" id="password"
              label="[[i18n('certificateManagerPassword')]]"
              on-input="validate_" autofocus></cr-input>
          <cr-input type="password"
              value="{{confirmPassword_}}" id="confirmPassword"
              label="[[i18n('certificateManagerConfirmPassword')]]"
              on-input="validate_"></cr-input>
        </div>
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onCancelTap_">
          [[i18n('cancel')]]
        </cr-button>
        <cr-button id="ok" class="action-button" on-click="onOkTap_" disabled>
          [[i18n('ok')]]
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,
  is: 'certificate-password-encryption-dialog',

  behaviors: [I18nBehavior],

  properties: {
    /** @type {!CertificateSubnode} */
    model: Object,

    /** @private */
    password_: {
      type: String,
      value: '',
    },

    /** @private */
    confirmPassword_: {
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
    this.browserProxy_.exportPersonalCertificatePasswordSelected(this.password_)
        .then(
            () => {
              this.$.dialog.close();
            },
            error => {
              this.$.dialog.close();
              this.fire('certificates-error', {error: error, anchor: null});
            });
  },

  /** @private */
  validate_() {
    const isValid =
        this.password_ !== '' && this.password_ === this.confirmPassword_;
    this.$.ok.disabled = !isValid;
  },
});
