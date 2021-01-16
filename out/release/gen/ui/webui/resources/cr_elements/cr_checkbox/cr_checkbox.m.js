// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-checkbox' is a component similar to native checkbox. It
 * fires a 'change' event *only* when its state changes as a result of a user
 * interaction. By default it assumes there will be child(ren) passed in to be
 * used as labels. If no label will be provided, a .no-label class should be
 * added to hide the spacing between the checkbox and the label container.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {PaperRippleBehavior} from 'chrome://resources/polymer/v3_0/paper-behaviors/paper-ripple-behavior.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        -webkit-tap-highlight-color: transparent;
        align-items: center;
        cursor: pointer;
        display: flex;
        outline: none;
        user-select: none;

        /* Sizes. */
        --cr-checkbox-border-size: 2px;
        --cr-checkbox-size: 16px;
        --cr-checkbox-ripple-size: 40px;

        /* Derived sizes (offsets). */
        --cr-checkbox-ripple-offset: calc(var(--cr-checkbox-size)/2 -
            var(--cr-checkbox-ripple-size)/2 - var(--cr-checkbox-border-size));

        /* --cr-checked-color automatically flips for light/dark mode. */
        --cr-checkbox-checked-box-color: var(--cr-checked-color);
        --cr-checkbox-ripple-checked-color: var(--cr-checked-color);

        /* Light mode colors. */
        --cr-checkbox-checked-ripple-opacity: .2;
        --cr-checkbox-mark-color: white;
        --cr-checkbox-ripple-unchecked-color: var(--google-grey-900);
        --cr-checkbox-unchecked-box-color: var(--google-grey-refresh-700);
        --cr-checkbox-unchecked-ripple-opacity: .15;
      }

      @media (prefers-color-scheme: dark) {
        :host {
          /* Dark mode colors. */
          --cr-checkbox-checked-ripple-opacity: .4;
          --cr-checkbox-mark-color: var(--google-grey-900);
          --cr-checkbox-ripple-unchecked-color: var(--google-grey-refresh-500);
          --cr-checkbox-unchecked-box-color: var(--google-grey-refresh-500);
          --cr-checkbox-unchecked-ripple-opacity: .4;
        }
      }

      :host([disabled]) {
        cursor: initial;
        opacity: var(--cr-disabled-opacity);
        pointer-events: none;
      }

      #checkbox {
        background: none;
        border: var(--cr-checkbox-border-size) solid
            var(--cr-checkbox-unchecked-box-color);
        border-radius: 2px;
        box-sizing: border-box;
        cursor: pointer;
        display: block;
        flex-shrink: 0;
        height: var(--cr-checkbox-size);
        margin: 0;
        outline: none;
        padding: 0;
        position: relative;
        transform: none;  /* Checkboxes shouldn't flip even in RTL. */
        width: var(--cr-checkbox-size);
      }

      #checkmark {
        border-color: var(--cr-checkbox-mark-color);
        border-style: solid;
        border-width: 0 2px 2px 0;
        content: '';
        display: block;
        height: 73%;
        transform: scale(0) rotate(45deg);
        transform-origin: 100% 80%;
        width: 36%;
      }

      :host-context([dir='rtl']) #checkmark {
        transform-origin: 50% 14%;
      }

      :host([checked]) #checkbox {
        background: var(--cr-checkbox-checked-box-color);
        border-color: var(--cr-checkbox-checked-box-color);
      }

      :host([checked]) #checkmark {
        transform: scale(1) rotate(45deg);
        /* Only animate when showing checkmark. */
        transition: transform 140ms ease-out;
      }

      paper-ripple {
        --paper-ripple-opacity: var(--cr-checkbox-ripple-opacity,
            var(--cr-checkbox-unchecked-ripple-opacity));
        color: var(--cr-checkbox-ripple-unchecked-color);
        height: var(--cr-checkbox-ripple-size);
        left: var(--cr-checkbox-ripple-offset);
        pointer-events: none;
        top: var(--cr-checkbox-ripple-offset);
        transition: color linear 80ms;
        width: var(--cr-checkbox-ripple-size);
      }

      :host([checked]) paper-ripple {
        --paper-ripple-opacity: var(--cr-checkbox-ripple-opacity,
            var(--cr-checkbox-checked-ripple-opacity));
        color: var(--cr-checkbox-ripple-checked-color);
      }

      :host-context([dir=rtl]) paper-ripple {
        left: auto;
        right: var(--cr-checkbox-ripple-offset);
      }

      #label-container {
        color: var(--cr-checkbox-label-color, var(--cr-primary-text-color));
        padding-inline-start: var(--cr-checkbox-label-padding-start, 20px);
        white-space: normal;
      }

      :host(.no-label) #label-container {
        display: none;
      }

      /* Hidden from UI, but not screen readers. */
      #ariaDescription {
        height: 0;
        overflow: hidden;
        width: 0;
      }
    </style>
    <div id="checkbox" tabindex$="[[tabIndex]]" role="checkbox"
        on-keydown="onKeyDown_" on-keyup="onKeyUp_" aria-disabled="false"
        aria-checked="false" aria-labelledby="label-container"
        aria-describedby="ariaDescription">
      <span id="checkmark"></span>
    </div>
    <div id="label-container" aria-hidden="true" part="label-container">
      <slot></slot>
    </div>
    <div id="ariaDescription">[[ariaDescription]]</div>
<!--_html_template_end_-->`,
  is: 'cr-checkbox',

  behaviors: [
    PaperRippleBehavior,
  ],

  properties: {
    checked: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'checkedChanged_',
      notify: true,
    },

    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'disabledChanged_',
    },

    ariaDescription: String,

    tabIndex: {
      type: Number,
      value: 0,
      observer: 'onTabIndexChanged_',
    },
  },

  listeners: {
    blur: 'hideRipple_',
    click: 'onClick_',
    focus: 'showRipple_',
    up: 'hideRipple_',
  },

  /** @override */
  ready() {
    this.removeAttribute('unresolved');
  },

  focus() {
    this.$.checkbox.focus();
  },

  /** @return {!Element} */
  getFocusableElement() {
    return this.$.checkbox;
  },

  /** @private */
  checkedChanged_() {
    this.$.checkbox.setAttribute(
        'aria-checked', this.checked ? 'true' : 'false');
  },

  /**
   * @param {boolean} current
   * @param {boolean} previous
   * @private
   */
  disabledChanged_(current, previous) {
    if (previous === undefined && !this.disabled) {
      return;
    }

    this.tabIndex = this.disabled ? -1 : 0;
    this.$.checkbox.setAttribute(
        'aria-disabled', this.disabled ? 'true' : 'false');
  },

  /** @private */
  showRipple_() {
    this.getRipple().showAndHoldDown();
  },

  /** @private */
  hideRipple_() {
    this.getRipple().clear();
  },

  /**
   * @param {!Event} e
   * @private
   */
  onClick_(e) {
    if (this.disabled || e.target.tagName === 'A') {
      return;
    }

    // Prevent |click| event from bubbling. It can cause parents of this
    // elements to erroneously re-toggle this control.
    e.stopPropagation();
    e.preventDefault();

    this.checked = !this.checked;
    this.fire('change', this.checked);
  },

  /**
   * @param {!KeyboardEvent} e
   * @private
   */
  onKeyDown_(e) {
    if (e.key !== ' ' && e.key !== 'Enter') {
      return;
    }

    e.preventDefault();
    e.stopPropagation();
    if (e.repeat) {
      return;
    }

    if (e.key === 'Enter') {
      this.click();
    }
  },

  /**
   * @param {!KeyboardEvent} e
   * @private
   */
  onKeyUp_(e) {
    if (e.key === ' ' || e.key === 'Enter') {
      e.preventDefault();
      e.stopPropagation();
    }

    if (e.key === ' ') {
      this.click();
    }
  },

  /** @private */
  onTabIndexChanged_() {
    // :host shouldn't have a tabindex because it's set on #checkbox.
    this.removeAttribute('tabindex');
  },

  // customize the element's ripple
  _createRipple() {
    this._rippleContainer = this.$.checkbox;
    const ripple = PaperRippleBehavior._createRipple();
    ripple.id = 'ink';
    ripple.setAttribute('recenters', '');
    ripple.classList.add('circle', 'toggle-ink');
    return ripple;
  },
});
