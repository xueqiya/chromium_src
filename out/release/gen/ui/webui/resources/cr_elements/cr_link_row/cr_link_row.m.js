// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * A link row is a UI element similar to a button, though usually wider than a
 * button (taking up the whole 'row'). The name link comes from the intended use
 * of this element to take the user to another page in the app or to an external
 * page (somewhat like an HTML link).
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../cr_icon_button/cr_icon_button.m.js';
import '../hidden_style_css.m.js';
import '../icons.m.js';
import '../shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style">
      :host {
        align-items: center;
        align-self: stretch;
        box-sizing: border-box;
        cursor: pointer;
        display: flex;
        flex: 1;
        font-family: inherit;
        font-size: 100%;  /* Specifically for Mac OSX, harmless elsewhere. */
        line-height: 154%;  /* 20px. */
        margin: 0;
        min-height: var(--cr-section-min-height);
        outline: none;
        padding: 0;
      }

      :host(:not([embedded])) {
        padding: 0 var(--cr-section-padding);
      }

      :host([disabled]) {
        color: var(--paper-grey-500);
        cursor: auto;
        pointer-events: none;
      }

      #startIcon {
        --iron-icon-fill-color: var(--cr-link-row-start-icon-color,
            var(--google-grey-refresh-700));
        display: flex;
        flex-shrink: 0;
        padding-inline-end: var(--cr-icon-button-margin-start);
        width: var(--cr-link-row-icon-width, var(--cr-icon-size));
      }

      @media (prefers-color-scheme: dark) {
        #startIcon {
          --iron-icon-fill-color: var(--cr-link-row-start-icon-color,
              var(--google-grey-refresh-500));
        }
      }

      #labelWrapper {
        flex: 1;
        flex-basis: 0.000000001px;
        padding-bottom: var(--cr-section-vertical-padding);
        padding-top: var(--cr-section-vertical-padding);
        text-align: start;
      }

      #label,
      #subLabel {
        display: flex;
      }

      #subLabel {
        @apply --cr-secondary-text;
      }
    </style>
    <iron-icon id="startIcon" icon="[[startIcon]]" hidden="[[!startIcon]]"
        aria-hidden="true">
    </iron-icon>
    <div id="labelWrapper" hidden="[[hideLabelWrapper_]]">
      <div id="label" class="label" aria-hidden="true">
        [[label]]
        <slot name="label"></slot>
      </div>
      <div id="subLabel" class="secondary label" aria-hidden="true">
        [[subLabel]]
        <slot name="sub-label"></slot>
      </div>
    </div>
    <slot></slot>
    <cr-icon-button id="icon" iron-icon="[[getIcon_(external)]]" role="link"
        aria-roledescription$="[[roleDescription]]" aria-describedby="subLabel"
        aria-labelledby="label" disabled="[[disabled]]"></cr-icon-button>
<!--_html_template_end_-->`,
  is: 'cr-link-row',

  properties: {
    startIcon: {
      type: String,
      value: '',
    },

    label: {
      type: String,
      value: '',
    },

    subLabel: {
      type: String,
      /* Value used for noSubLabel attribute. */
      value: '',
    },

    disabled: {
      type: Boolean,
      reflectToAttribute: true,
    },

    external: {
      type: Boolean,
      value: false,
    },

    usingSlottedLabel: {
      type: Boolean,
      value: false,
    },

    roleDescription: String,

    /** @private */
    hideLabelWrapper_: {
      type: Boolean,
      computed: 'computeHideLabelWrapper_(label, usingSlottedLabel)',
    },
  },

  /** @type {boolean} */
  get noink() {
    return this.$.icon.noink;
  },

  /** @type {boolean} */
  set noink(value) {
    this.$.icon.noink = value;
  },

  focus() {
    this.$.icon.focus();
  },

  /**
   * @return {boolean}
   * @private
   */
  computeHideLabelWrapper_() {
    return !(this.label || this.usingSlottedLabel);
  },

  /**
   * @return {string}
   * @private
   */
  getIcon_() {
    return this.external ? 'cr:open-in-new' : 'cr:arrow-right';
  },
});
