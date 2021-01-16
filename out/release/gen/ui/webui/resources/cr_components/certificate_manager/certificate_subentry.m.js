// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview certificate-subentry represents an SSL certificate sub-entry.
 */

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_lazy_render/cr_lazy_render.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_indicator.m.js';
import {CrPolicyIndicatorType} from 'chrome://resources/cr_elements/policy/cr_policy_indicator_behavior.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {CertificateAction, CertificateActionEvent, CertificateActionEventDetail} from './certificate_manager_types.m.js';
import './certificate_shared_css.m.js';
import {CertificatesBrowserProxy, CertificatesBrowserProxyImpl, CertificateType, CertificateSubnode} from './certificates_browser_proxy.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="certificate-shared cr-icons">
      .name {
        flex: auto;
      }

      .untrusted {
        color: var(--paper-red-700);
        font-weight: 500;
        margin-inline-end: 16px;
        text-transform: uppercase;
      }

      :host([is-last]) .list-item {
        border-bottom: none;
      }
    </style>
    <div class="list-item underbar">
      <div class="untrusted" hidden$="[[!model.untrusted]]">
        [[i18n('certificateManagerUntrusted')]]
      </div>
      <div class="name">[[model.name]]</div>
      <cr-policy-indicator indicator-type="[[getPolicyIndicatorType_(model)]]">
      </cr-policy-indicator>
      <cr-icon-button class="icon-more-vert" id="dots"
          title="[[i18n('moreActions')]]" on-click="onDotsTap_">
      </cr-icon-button>
      <cr-lazy-render id="menu">
        <template>
          <cr-action-menu role-description="[[i18n('menu')]]">
            <button class="dropdown-item" id="view"
                on-tap="onViewTap_">
              [[i18n('certificateManagerView')]]
            </button>
            <button class="dropdown-item" id="edit"
                hidden$="[[!canEdit_(model)]]"
                on-tap="onEditTap_">
              [[i18n('edit')]]
            </button>
            <button class="dropdown-item" id="export"
                hidden$="[[!canExport_(certificateType, model)]]"
                on-tap="onExportTap_">
              [[i18n('certificateManagerExport')]]
            </button>
            <button class="dropdown-item" id="delete"
                hidden$="[[!canDelete_(model)]]"
                on-tap="onDeleteTap_">
              [[i18n('certificateManagerDelete')]]
            </button>
          </cr-action-menu>
        </template>
      </cr-lazy-render>
    <div>
<!--_html_template_end_-->`,
  is: 'certificate-subentry',

  behaviors: [I18nBehavior],

  properties: {
    /** @type {!CertificateSubnode} */
    model: Object,

    /** @type {!CertificateType} */
    certificateType: String,
  },

  /** @private {CertificatesBrowserProxy} */
  browserProxy_: null,

  /** @override */
  created() {
    this.browserProxy_ =
        CertificatesBrowserProxyImpl.getInstance();
  },

  /**
   * Dispatches an event indicating which certificate action was tapped. It is
   * used by the parent of this element to display a modal dialog accordingly.
   * @param {!CertificateAction} action
   * @private
   */
  dispatchCertificateActionEvent_(action) {
    this.fire(
        CertificateActionEvent,
        /** @type {!CertificateActionEventDetail} */ ({
          action: action,
          subnode: this.model,
          certificateType: this.certificateType,
          anchor: this.$.dots,
        }));
  },

  /**
   * Handles the case where a call to the browser resulted in a rejected
   * promise.
   * @param {*} error Expects {?CertificatesError}.
   * @private
   */
  onRejected_(error) {
    if (error === null) {
      // Nothing to do here. Null indicates that the user clicked "cancel" on
      // the native file chooser dialog.
      return;
    }

    // Otherwise propagate the error to the parents, such that a dialog
    // displaying the error will be shown.
    this.fire('certificates-error', {error: error, anchor: this.$.dots});
  },

  /**
   * @param {!Event} event
   * @private
   */
  onViewTap_(event) {
    this.closePopupMenu_();
    this.browserProxy_.viewCertificate(this.model.id);
  },

  /**
   * @param {!Event} event
   * @private
   */
  onEditTap_(event) {
    this.closePopupMenu_();
    this.dispatchCertificateActionEvent_(CertificateAction.EDIT);
  },

  /**
   * @param {!Event} event
   * @private
   */
  onDeleteTap_(event) {
    this.closePopupMenu_();
    this.dispatchCertificateActionEvent_(CertificateAction.DELETE);
  },

  /**
   * @param {!Event} event
   * @private
   */
  onExportTap_(event) {
    this.closePopupMenu_();
    if (this.certificateType === CertificateType.PERSONAL) {
      this.browserProxy_.exportPersonalCertificate(this.model.id).then(() => {
        this.dispatchCertificateActionEvent_(CertificateAction.EXPORT_PERSONAL);
      }, this.onRejected_.bind(this));
    } else {
      this.browserProxy_.exportCertificate(this.model.id);
    }
  },

  /**
   * @param {!CertificateSubnode} model
   * @return {boolean} Whether the certificate can be edited.
   * @private
   */
  canEdit_(model) {
    return model.canBeEdited;
  },

  /**
   * @param {!CertificateType} certificateType
   * @param {!CertificateSubnode} model
   * @return {boolean} Whether the certificate can be exported.
   * @private
   */
  canExport_(certificateType, model) {
    if (certificateType === CertificateType.PERSONAL) {
      return model.extractable;
    }
    return true;
  },

  /**
   * @param {!CertificateSubnode} model
   * @return {boolean} Whether the certificate can be deleted.
   * @private
   */
  canDelete_(model) {
    return model.canBeDeleted;
  },

  /** @private */
  closePopupMenu_() {
    this.$$('cr-action-menu').close();
  },

  /** @private */
  onDotsTap_() {
    const actionMenu = /** @type {!CrActionMenuElement} */ (this.$.menu.get());
    actionMenu.showAt(this.$.dots);
  },

  /** @private */
  getPolicyIndicatorType_(model) {
    return model.policy ? CrPolicyIndicatorType.USER_POLICY :
                          CrPolicyIndicatorType.NONE;
  },
});
