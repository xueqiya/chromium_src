// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'cr-expand-button' is a chrome-specific wrapper around a button that toggles
 * between an opened (expanded) and closed state.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {focusWithoutInk} from '../../js/cr/ui/focus_without_ink.m.js';
import '../cr_icon_button/cr_icon_button.m.js';
import '../icons.m.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        align-items: center;
        cursor: pointer;
        display: flex;
        outline: none;
      }

      :host([disabled]) {
        opacity: 0.65;
        pointer-events: none;
      }

      :host([disabled]) cr-icon-button {
        display: var(--cr-expand-button-disabled-display, initial);
      }

      #label {
        flex: 1;
        padding: var(--cr-section-vertical-padding) 0;
      }

      cr-icon-button {
        --cr-icon-button-size: var(--cr-expand-button-size, 36px);
      }
    </style>

    <div id="label"><slot></slot></div>
    <cr-icon-button id="icon" aria-labelledby="label" disabled="[[disabled]]"
        tabindex="[[tabIndex]]"></cr-icon-button>
<!--_html_template_end_-->`,
  is: 'cr-expand-button',

  properties: {
    /**
     * If true, the button is in the expanded state and will show the
     * 'expand-less' icon. If false, the button shows the 'expand-more' icon.
     */
    expanded: {
      type: Boolean,
      value: false,
      notify: true,
      observer: 'onExpandedChange_',
    },

    /**
     * If true, the button will be disabled and grayed out.
     */
    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    /** A11y text descriptor for this control. */
    alt: {
      type: String,
      observer: 'onAltChange_',
    },

    tabIndex: {
      type: Number,
      value: 0,
    },
  },

  observers: [
    'updateAriaExpanded_(disabled, expanded)',
  ],

  listeners: {
    click: 'toggleExpand_',
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

  /** @private */
  onAltChange_() {
    if (this.alt) {
      this.$.icon.removeAttribute('aria-labelledby');
      this.$.icon.setAttribute('aria-label', this.alt);
    } else {
      this.$.icon.removeAttribute('aria-label');
      this.$.icon.setAttribute('aria-labelledby', 'label');
    }
  },

  /** @private */
  onExpandedChange_() {
    this.$.icon.ironIcon = this.expanded ? 'cr:expand-less' : 'cr:expand-more';
  },

  /**
   * @param {!Event} event
   * @private
   */
  toggleExpand_(event) {
    // Prevent |click| event from bubbling. It can cause parents of this
    // elements to erroneously re-toggle this control.
    event.stopPropagation();
    event.preventDefault();

    this.scrollIntoViewIfNeeded();
    this.expanded = !this.expanded;
    focusWithoutInk(this.$.icon);
  },

  /** @private */
  updateAriaExpanded_() {
    if (this.disabled) {
      this.$.icon.removeAttribute('aria-expanded');
    } else {
      this.$.icon.setAttribute('aria-expanded', this.expanded);
    }
  },
});
