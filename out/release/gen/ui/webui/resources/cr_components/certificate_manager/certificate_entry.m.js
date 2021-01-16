// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview An element that represents an SSL certificate entry.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_indicator.m.js';
import {CrPolicyIndicatorType} from 'chrome://resources/cr_elements/policy/cr_policy_indicator_behavior.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import './certificate_shared_css.m.js';
import './certificate_subentry.m.js';
import {CertificatesOrgGroup, CertificateType} from './certificates_browser_proxy.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="certificate-shared iron-flex">
      .expand-box {
        align-items: center;
        border-top: var(--cr-separator-line);
        display: flex;
        min-height: 48px;
        padding: 0 20px;
      }
    </style>
    <div class="expand-box">
      <div class="flex">[[model.id]]</div>
      <cr-policy-indicator indicator-type="[[getPolicyIndicatorType_(model)]]">
      </cr-policy-indicator>
      <cr-expand-button expanded="{{expanded_}}"
          alt="[[i18n('certificateManagerExpandA11yLabel')]]">
      </cr-expand-button>
    </div>
    <template is="dom-if" if="[[expanded_]]">
      <div class="list-frame">
        <template is="dom-repeat" items="[[model.subnodes]]">
          <certificate-subentry model="[[item]]"
              certificate-type="[[certificateType]]"
              is-last$="[[isLast_(index, model)]]">
          </certificate-subentry>
        </template>
      </div>
    </template>
<!--_html_template_end_-->`,
  is: 'certificate-entry',

  behaviors: [I18nBehavior],

  properties: {
    /** @type {!CertificatesOrgGroup} */
    model: Object,

    /** @type {!CertificateType} */
    certificateType: String,
  },

  /**
   * @param {number} index
   * @return {boolean} Whether the given index corresponds to the last sub-node.
   * @private
   */
  isLast_(index) {
    return index === this.model.subnodes.length - 1;
  },

  getPolicyIndicatorType_() {
    return this.model.containsPolicyCerts ? CrPolicyIndicatorType.USER_POLICY :
                                            CrPolicyIndicatorType.NONE;
  },
});
