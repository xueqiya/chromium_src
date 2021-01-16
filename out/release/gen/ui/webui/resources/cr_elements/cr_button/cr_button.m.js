// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-button' is a button which displays slotted elements. It can
 * be interacted with like a normal button using click as well as space and
 * enter to effectively click the button and fire a 'click' event.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {FocusOutlineManager} from '../../js/cr/ui/focus_outline_manager.m.js';
import {PaperRippleBehavior} from 'chrome://resources/polymer/v3_0/paper-behaviors/paper-ripple-behavior.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../hidden_style_css.m.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style">
      :host {
        --active-shadow-rgb: var(--google-grey-800-rgb);
        --active-shadow-action-rgb: var(--google-blue-refresh-500-rgb);
        --bg-action: var(--google-blue-600);
        --border-color: var(--google-grey-refresh-300);
        --disabled-bg-action: var(--google-grey-refresh-100);
        --disabled-bg: white;
        --disabled-border-color: var(--google-grey-refresh-100);
        --focus-shadow-color: rgba(var(--google-blue-600-rgb), .4);
        --hover-bg-action: rgba(var(--google-blue-600-rgb), .9);
        --hover-bg-color: rgba(var(--google-blue-refresh-500-rgb), .04);
        --hover-border-color: var(--google-blue-refresh-100);
        --hover-shadow-action-rgb: var(--google-blue-refresh-500-rgb);
        --ink-color-action: white;
        /* Blue-ish color used either as a background or as a text color,
         * depending on the type of button. */
        --ink-color: var(--google-blue-600);
        --ripple-opacity-action: .32;
        --ripple-opacity: .1;
        --text-color-action: white;
        --text-color: var(--google-blue-600);
      }

      @media (prefers-color-scheme: dark) {
        :host {
          /* Only in dark. */
          --active-bg: black linear-gradient(rgba(255, 255, 255, .06),
                                             rgba(255, 255, 255, .06));
          --active-shadow-rgb: 0, 0, 0;
          --active-shadow-action-rgb: var(--google-blue-refresh-500-rgb);
          --bg-action: var(--google-blue-refresh-300);
          --border-color: var(--google-grey-refresh-700);
          --disabled-bg-action: var(--google-grey-800);
          /* TODO(dbeam): get --disabled-bg from Namrata. */
          --disabled-bg: transparent;
          --disabled-border-color: var(--google-grey-800);
          --focus-shadow-color: rgba(var(--google-blue-refresh-300-rgb), .5);
          --hover-bg-action: var(--bg-action)
              linear-gradient(rgba(0, 0, 0, .08), rgba(0, 0, 0, .08));
          --hover-bg-color: rgba(var(--google-blue-refresh-300-rgb), .08);
          --ink-color-action: black;
          --ink-color: var(--google-blue-refresh-300);
          --ripple-opacity-action: .16;
          --ripple-opacity: .16;
          --text-color-action: var(--google-grey-900);
          --text-color: var(--google-blue-refresh-300);
        }
      }

      :host {
        --paper-ripple-opacity: var(--ripple-opacity);
        -webkit-tap-highlight-color: transparent;
        align-items: center;
        border: 1px solid var(--border-color);
        border-radius: 4px;
        box-sizing: border-box;
        color: var(--text-color);
        cursor: pointer;
        display: inline-flex;
        flex-shrink: 0;
        font-weight: 500;
        height: var(--cr-button-height);
        justify-content: center;
        min-width: 5.14em;
        outline-width: 0;
        padding: 8px 16px;
        position: relative;
        user-select: none;
      }

      :host-context(.focus-outline-visible):host(:focus) {
        box-shadow: 0 0 0 2px var(--focus-shadow-color);
      }

      :host(:active) {
        background: var(--active-bg);
        box-shadow:
            0 1px 2px 0 rgba(var(--active-shadow-rgb), .3),
            0 3px 6px 2px rgba(var(--active-shadow-rgb), .15);
      }

      :host(:hover) {
        background-color: var(--hover-bg-color);
      }

      @media (prefers-color-scheme: light) {
        :host(:hover) {
          border-color: var(--hover-border-color);
        }
      }

      :host(.action-button) {
        --ink-color: var(--ink-color-action);
        --paper-ripple-opacity: var(--ripple-opacity-action);
        background-color: var(--bg-action);
        border: none;
        color: var(--text-color-action);
      }

      :host(.action-button:active) {
        box-shadow:
            0 1px 2px 0 rgba(var(--active-shadow-action-rgb), .3),
            0 3px 6px 2px rgba(var(--active-shadow-action-rgb), .15);
      }

      :host(.action-button:hover) {
        background: var(--hover-bg-action);
      }

      @media (prefers-color-scheme: light) {
        :host(.action-button:not(:active):hover) {
          box-shadow:
              0 1px 2px 0 rgba(var(--hover-shadow-action-rgb), .3),
              0 1px 3px 1px rgba(var(--hover-shadow-action-rgb), .15);
        }
      }

      :host([disabled]) {
        background-color: var(--disabled-bg);
        border-color: var(--disabled-border-color);
        color: var(--google-grey-600);
        cursor: auto;
        pointer-events: none;
      }

      :host(.action-button[disabled]) {
        background-color: var(--disabled-bg-action);
        border-color: transparent;
      }

      /* cancel-button is meant to be used within a cr-dialog */
      :host(.cancel-button) {
        margin-inline-end: 8px;
      }

      :host(.action-button),
      :host(.cancel-button) {
        line-height: 154%;
      }

      paper-ripple {
        color: var(--ink-color);
        height: var(--paper-ripple-height);
        width: var(--paper-ripple-width);
        /* Fallback to 0 to match the values in paper-ripple.html. Falls back
         * to null without this. */
        left: var(--paper-ripple-left, 0);
        top: var(--paper-ripple-top, 0);
      }
    </style>
    <slot></slot>
<!--_html_template_end_-->`,
  is: 'cr-button',

  behaviors: [
    PaperRippleBehavior,
  ],

  properties: {
    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'disabledChanged_',
    },

    /**
     * Flag used for formatting ripples on circle shaped cr-buttons.
     * @private
     */
    circleRipple: {
      type: Boolean,
      value: false,
    },
  },

  hostAttributes: {
    'aria-disabled': 'false',
    role: 'button',
    tabindex: 0,
  },

  listeners: {
    click: 'onClick_',
    keydown: 'onKeyDown_',
    keyup: 'onKeyUp_',
    pointerdown: 'onPointerDown_',
    tap: 'onTap_',
  },

  /** @private {Set<number>} */
  timeoutIds_: null,

  /** @override */
  ready() {
    FocusOutlineManager.forDocument(document);
    this.timeoutIds_ = new Set();
  },

  /** @override */
  detached() {
    this.timeoutIds_.forEach(clearTimeout);
    this.timeoutIds_.clear();
  },

  /**
   * @param {!Function} fn
   * @param {number=} delay
   * @private
   */
  setTimeout_(fn, delay) {
    if (!this.isConnected) {
      return;
    }
    const id = setTimeout(() => {
      this.timeoutIds_.delete(id);
      fn();
    }, delay);
    this.timeoutIds_.add(id);
  },

  /**
   * @param {boolean} newValue
   * @param {boolean} oldValue
   * @private
   */
  disabledChanged_(newValue, oldValue) {
    if (!newValue && oldValue === undefined) {
      return;
    }
    if (this.disabled) {
      this.blur();
    }
    this.setAttribute('aria-disabled', Boolean(this.disabled));
    this.setAttribute('tabindex', this.disabled ? -1 : 0);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onClick_(e) {
    if (this.disabled) {
      e.stopImmediatePropagation();
    }
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

    this.getRipple().uiDownAction();
    if (e.key === 'Enter') {
      this.click();
      // Delay was chosen manually as a good time period for the ripple to be
      // visible.
      this.setTimeout_(() => this.getRipple().uiUpAction(), 100);
    }
  },

  /**
   * @param {!KeyboardEvent} e
   * @private
   */
  onKeyUp_(e) {
    if (e.key !== ' ' && e.key !== 'Enter') {
      return;
    }

    e.preventDefault();
    e.stopPropagation();

    if (e.key === ' ') {
      this.click();
      this.getRipple().uiUpAction();
    }
  },

  /** @private */
  onPointerDown_() {
    this.ensureRipple();
  },

  /**
   * Need to handle tap events to enable tap events for where they are still
   * used with |button.addEventListener('tap', handler)|.
   * TODO(crbug.com/812035): Remove function and listener after Chrome OS no
   *     longer uses tap event at least with addEventListener().
   * @private
   */
  onTap_() {},

  /**
   * Customize the element's ripple. Overriding the '_createRipple' function
   * from PaperRippleBehavior.
   * @return {PaperRippleElement}
   */
  _createRipple() {
    const ripple = PaperRippleBehavior._createRipple();

    if (this.circleRipple) {
      ripple.setAttribute('center', '');
      ripple.classList.add('circle');
    }

    return ripple;
  },
});
