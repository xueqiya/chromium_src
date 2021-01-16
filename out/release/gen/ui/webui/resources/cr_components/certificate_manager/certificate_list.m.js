// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'certificate-list' is an element that displays a list of
 * certificates.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import {assertNotReached} from 'chrome://resources/js/assert.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import './certificate_entry.m.js';
import {CertificateAction, CertificateActionEvent, CertificateActionEventDetail} from './certificate_manager_types.m.js';
import './certificate_shared_css.m.js';
import {CertificatesBrowserProxy, CertificatesBrowserProxyImpl, CertificateType, NewCertificateSubNode, CertificatesOrgGroup} from './certificates_browser_proxy.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="certificate-shared iron-flex">
      .button-box {
        align-items: center;
        display: flex;
        margin-bottom: 24px;
        min-height: 48px;
        padding: 0 20px;
      }

      /* TODO(aee): add platform conditional after crbug/964506 is fixed. */
      #importAndBind {
        margin-inline-start: 8px;
      }
    </style>
    <div class="button-box">
      <span class="flex">
          [[getDescription_(certificateType, certificates)]]</span>
      <cr-button id="import" on-click="onImportTap_"
          hidden="[[!canImport_(certificateType, importAllowed, isKiosk_)]]">
        [[i18n('certificateManagerImport')]]</cr-button>
<if expr="chromeos">
      <cr-button id="importAndBind" on-click="onImportAndBindTap_"
          hidden="[[!canImportAndBind_(certificateType, importAllowed,
                 isGuest_)]]">
        [[i18n('certificateManagerImportAndBind')]]</cr-button>
</if>
    </div>
    <template is="dom-repeat" items="[[certificates]]">
      <certificate-entry model="[[item]]"
          certificate-type="[[certificateType]]">
      </certificate-entry>
    </template>
<!--_html_template_end_-->`,
  is: 'certificate-list',

  properties: {
    /** @type {!Array<!CertificatesOrgGroup>} */
    certificates: {
      type: Array,
      value() {
        return [];
      },
    },

    /** @type {!CertificateType} */
    certificateType: String,

    /** @type {boolean} */
    importAllowed: Boolean,

    // 'if expr="chromeos"' here is breaking vulcanize. TODO(stevenjb/dpapad):
    // Restore after migrating to polymer-bundler, crbug.com/731881.
    /** @private */
    isGuest_: {
      type: Boolean,
      value() {
        return loadTimeData.valueExists('isGuest') &&
            loadTimeData.getBoolean('isGuest');
      },
    },

    /** @private */
    isKiosk_: {
      type: Boolean,
      value() {
        return loadTimeData.valueExists('isKiosk') &&
            loadTimeData.getBoolean('isKiosk');
      },
    },
  },

  behaviors: [I18nBehavior],

  /**
   * @return {string}
   * @private
   */
  getDescription_() {
    if (this.certificates.length === 0) {
      return this.i18n('certificateManagerNoCertificates');
    }

    switch (this.certificateType) {
      case CertificateType.PERSONAL:
        return this.i18n('certificateManagerYourCertificatesDescription');
      case CertificateType.SERVER:
        return this.i18n('certificateManagerServersDescription');
      case CertificateType.CA:
        return this.i18n('certificateManagerAuthoritiesDescription');
      case CertificateType.OTHER:
        return this.i18n('certificateManagerOthersDescription');
    }

    assertNotReached();
  },

  /**
   * @return {boolean}
   * @private
   */
  canImport_() {
    return !this.isKiosk_ && this.certificateType !== CertificateType.OTHER &&
        this.importAllowed;
  },

  // <if expr="chromeos">
  /**
   * @return {boolean}
   * @private
   */
  canImportAndBind_() {
    return !this.isGuest_ &&
        this.certificateType === CertificateType.PERSONAL && this.importAllowed;
  },
  // </if>

  /**
   * Handles a rejected Promise returned from |browserProxy_|.
   * @param {!HTMLElement} anchor
   * @param {*} error Expects {!CertificatesError|!CertificatesImportError}.
   * @private
   */
  onRejected_(anchor, error) {
    if (error === null) {
      // Nothing to do here. Null indicates that the user clicked "cancel" on
      // a native file chooser dialog.
      return;
    }

    // Otherwise propagate the error to the parents, such that a dialog
    // displaying the error will be shown.
    this.fire('certificates-error', {error: error, anchor: anchor});
  },


  /**
   * @param {?NewCertificateSubNode} subnode
   * @param {!HTMLElement} anchor
   * @private
   */
  dispatchImportActionEvent_(subnode, anchor) {
    this.fire(
        CertificateActionEvent,
        /** @type {!CertificateActionEventDetail} */ ({
          action: CertificateAction.IMPORT,
          subnode: subnode,
          certificateType: this.certificateType,
          anchor: anchor,
        }));
  },

  /**
   * @param {!Event} e
   * @private
   */
  onImportTap_(e) {
    this.handleImport_(false, /** @type {!HTMLElement} */ (e.target));
  },

  // <if expr="chromeos">
  /**
   * @private
   * @param {!Event} e
   */
  onImportAndBindTap_(e) {
    this.handleImport_(true, /** @type {!HTMLElement} */ (e.target));
  },
  // </if>

  /**
   * @param {boolean} useHardwareBacked
   * @param {!HTMLElement} anchor
   * @private
   */
  handleImport_(useHardwareBacked, anchor) {
    const browserProxy =
        CertificatesBrowserProxyImpl.getInstance();
    if (this.certificateType === CertificateType.PERSONAL) {
      browserProxy.importPersonalCertificate(useHardwareBacked)
          .then(showPasswordPrompt => {
            if (showPasswordPrompt) {
              this.dispatchImportActionEvent_(null, anchor);
            }
          }, this.onRejected_.bind(this, anchor));
    } else if (this.certificateType === CertificateType.CA) {
      browserProxy.importCaCertificate().then(certificateName => {
        this.dispatchImportActionEvent_({name: certificateName}, anchor);
      }, this.onRejected_.bind(this, anchor));
    } else if (this.certificateType === CertificateType.SERVER) {
      browserProxy.importServerCertificate().catch(
          this.onRejected_.bind(this, anchor));
    } else {
      assertNotReached();
    }
  },
});
