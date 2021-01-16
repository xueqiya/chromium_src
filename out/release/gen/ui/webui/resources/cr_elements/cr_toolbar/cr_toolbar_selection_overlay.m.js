// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview Element which displays the number of selected items with
 * Cancel/Delete buttons, designed to be used as an overlay on top of
 * <cr-toolbar>. See <history-toolbar> for an example usage.
 *
 * Note that the embedder is expected to set position: relative to make the
 * absolute positioning of this element work, and the cr-toolbar should have the
 * has-overlay attribute set when its overlay is shown to prevent access through
 * tab-traversal.
 */

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../cr_button/cr_button.m.js';
import '../cr_icon_button/cr_icon_button.m.js';
import '../icons.m.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        background-color: white;
        border-bottom: 1px solid var(--google-grey-300);
        bottom: 0;
        color: var(--cr-primary-text-color);
        display: flex;
        left: 0;
        opacity: 0;
        padding-inline-start: var(--cr-toolbar-field-margin, 0);
        pointer-events: none;
        position: absolute;
        right: 0;
        top: 0;
        transition: opacity var(--cr-toolbar-overlay-animation-duration),
                    visibility var(--cr-toolbar-overlay-animation-duration);
        visibility: hidden;
      }

      @media (prefers-color-scheme: dark) {
        :host {
          background-color: var(--google-grey-900);
          background-image: linear-gradient(rgba(255, 255, 255, .04),
                                            rgba(255, 255, 255, .04));
          border-bottom-color: var(--cr-separator-color);
        }
      }

      :host([show]) {
        opacity: 1;
        pointer-events: initial;
        visibility: initial;
      }

      #overlay-content {
        align-items: center;
        display: flex;
        flex: 1;
        margin: 0 auto;
        max-width: var(--selection-overlay-max-width, initial);
        padding: 0 var(--selection-overlay-padding, 24px);
      }

      cr-button {
        margin-inline-start: 8px;
      }

      #number-selected {
        flex: 1;
      }


      cr-icon-button {
        height: 36px;
        margin-inline-end: 24px;
        margin-inline-start: 2px;
        width: 36px;
      }
    </style>
    <template is="dom-if" if="[[hasShown_]]">
      <div id="overlay-content">
        <cr-icon-button title="[[cancelLabel]]" iron-icon="cr:clear"
            on-click="onClearSelectionClick_"></cr-icon-button>
        <div id="number-selected">[[selectionLabel_]]</div>
        <cr-button on-click="onClearSelectionClick_">[[cancelLabel]]</cr-button>
        <cr-button id="delete" on-click="onDeleteClick_"
            disabled="[[deleteDisabled]]">
          [[deleteLabel]]
        </cr-button>
      </div>
    </template>
<!--_html_template_end_-->`,
  is: 'cr-toolbar-selection-overlay',

  properties: {
    show: {
      type: Boolean,
      observer: 'onShowChanged_',
      reflectToAttribute: true,
    },

    deleteLabel: String,

    cancelLabel: String,

    selectionLabel: String,

    deleteDisabled: Boolean,

    /** @private */
    hasShown_: Boolean,

    /** @private */
    selectionLabel_: String,
  },

  observers: [
    'updateSelectionLabel_(show, selectionLabel)',
  ],

  /** @return {HTMLElement} */
  get deleteButton() {
    return /** @type {HTMLElement} */ (this.$$('#delete'));
  },

  /** @private */
  onClearSelectionClick_() {
    this.fire('clear-selected-items');
  },

  /** @private */
  onDeleteClick_() {
    this.fire('delete-selected-items');
  },

  /** @private */
  updateSelectionLabel_() {
    // Do this update in a microtask to ensure |show| and |selectionLabel|
    // are both updated.
    this.debounce('updateSelectionLabel_', () => {
      this.selectionLabel_ =
          this.show ? this.selectionLabel : this.selectionLabel_;
    });
  },

  /** @private */
  onShowChanged_() {
    if (this.show) {
      this.hasShown_ = true;
    }
  },
});
