// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../icons.m.js';
import '../shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/paper-tooltip/paper-tooltip.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        display: flex;  /* Position independently from the line-height. */
      }

      paper-tooltip {
        --paper-tooltip: var(--cr-tooltip);
      }

      iron-icon {
        --iron-icon-width: var(--cr-icon-size);
        --iron-icon-height: var(--cr-icon-size);
      }
    </style>
    <iron-icon id="indicator" tabindex="0" aria-label$="[[iconAriaLabel]]"
        aria-describedby="tooltip" icon="[[iconClass]]"></iron-icon>
    <paper-tooltip id="tooltip" for="indicator" position="[[tooltipPosition]]"
        fit-to-visible-bounds part="tooltip">
      [[tooltipText]]
    </paper-tooltip>
<!--_html_template_end_-->`,
  is: 'cr-tooltip-icon',

  properties: {
    iconAriaLabel: String,

    iconClass: String,

    tooltipText: String,

    /** Position of tooltip popup related to the icon. */
    tooltipPosition: {
      type: String,
      value: 'top',
    }
  },

  /** @return {!Element} */
  getFocusableElement() {
    return this.$.indicator;
  },
});