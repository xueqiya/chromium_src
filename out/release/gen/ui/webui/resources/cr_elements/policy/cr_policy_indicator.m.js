// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/** @fileoverview Polymer element for indicating policies by type. */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../hidden_style_css.m.js';
import {CrPolicyIndicatorBehavior, CrPolicyIndicatorType} from './cr_policy_indicator_behavior.m.js';
import './cr_tooltip_icon.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style"></style>
    <cr-tooltip-icon hidden$="[[!indicatorVisible]]"
        tooltip-text="[[indicatorTooltip_]]" icon-class="[[indicatorIcon]]"
        icon-aria-label="[[iconAriaLabel]]">
    </cr-tooltip-icon>
<!--_html_template_end_-->`,
  is: 'cr-policy-indicator',

  behaviors: [CrPolicyIndicatorBehavior],

  properties: {
    iconAriaLabel: String,

    /** @private {string} */
    indicatorTooltip_: {
      type: String,
      computed: 'getIndicatorTooltip_(indicatorType, indicatorSourceName)',
    },
  },

  /**
   * @param {!CrPolicyIndicatorType} indicatorType
   * @param {string} indicatorSourceName The name associated with the indicator.
   *     See chrome.settingsPrivate.PrefObject.controlledByName
   * @return {string} The tooltip text for |type|.
   */
  getIndicatorTooltip_(indicatorType, indicatorSourceName) {
    return this.getIndicatorTooltip(indicatorType, indicatorSourceName);
  },
});
