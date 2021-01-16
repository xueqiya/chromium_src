// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-toggle' is a component for showing an on/off switch. It
 * fires a 'change' event *only* when its state changes as a result of a user
 * interaction. Besides just clicking the element, its state can be changed by
 * dragging (pointerdown+pointermove) the element towards the desired direction.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {PaperRippleBehavior} from 'chrome://resources/polymer/v3_0/paper-behaviors/paper-ripple-behavior.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        --cr-toggle-checked-bar-color: var(--google-blue-600);
        --cr-toggle-checked-button-color: var(--google-blue-600);
        --cr-toggle-checked-ripple-color:
            rgba(var(--google-blue-600-rgb), .2);
        --cr-toggle-unchecked-bar-color: var(--google-grey-400);
        --cr-toggle-unchecked-button-color: white;
        --cr-toggle-unchecked-ripple-color:
            rgba(var(--google-grey-600-rgb), .15);
        -webkit-tap-highlight-color: transparent;
        cursor: pointer;
        display: block;
        min-width: 34px;
        outline: none;
        position: relative;
        width: 34px;
      }

      @media (prefers-color-scheme: dark) {
        :host {
          --cr-toggle-checked-bar-color: var(--google-blue-refresh-300);
          --cr-toggle-checked-button-color: var(--google-blue-refresh-300);
          --cr-toggle-checked-ripple-color:
              rgba(var(--google-blue-refresh-300-rgb), .4);
          --cr-toggle-unchecked-bar-color: var(--google-grey-refresh-500);
          --cr-toggle-unchecked-button-color: var(--google-grey-refresh-300);
          --cr-toggle-unchecked-ripple-color:
              rgba(var(--google-grey-refresh-300-rgb), .4);
        }
      }
      /* Keep the prefers-color-scheme and [dark] rules the same. */
      :host([dark]) {
        --cr-toggle-checked-bar-color: var(--google-blue-refresh-300);
        --cr-toggle-checked-button-color: var(--google-blue-refresh-300);
        --cr-toggle-checked-ripple-color:
            rgba(var(--google-blue-refresh-300-rgb), .4);
        --cr-toggle-unchecked-bar-color: var(--google-grey-refresh-500);
        --cr-toggle-unchecked-button-color: var(--google-grey-refresh-300);
        --cr-toggle-unchecked-ripple-color:
            rgba(var(--google-grey-refresh-300-rgb), .4);
      }

      :host([disabled]) {
        cursor: initial;
        opacity: var(--cr-disabled-opacity);
        pointer-events: none;
      }

      #bar {
        background-color: var(--cr-toggle-unchecked-bar-color);
        border-radius: 8px;
        height: 12px;
        left: 3px;
        position: absolute;
        top: 2px;
        transition: background-color linear 80ms;
        width: 28px;
        z-index: 0;
      }

      :host([checked]) #bar {
        background-color: var(--cr-toggle-checked-bar-color);
        opacity: 0.5;
      }

      #knob {
        background-color: var(--cr-toggle-unchecked-button-color);
        border-radius: 50%;
        box-shadow: 0 1px 3px 0 rgba(0, 0, 0, .4);
        display: block;
        height: 16px;
        position: relative;
        transition: transform linear 80ms, background-color linear 80ms;
        width: 16px;
        z-index: 1;
      }

      :host([checked]) #knob {
        background-color: var(--cr-toggle-checked-button-color);
        transform: translate3d(18px, 0, 0);
      }

      :host-context([dir=rtl]):host([checked]) #knob {
        transform: translate3d(-18px, 0, 0);
      }

      paper-ripple {
        --paper-ripple-opacity: 1;
        color: var(--cr-toggle-unchecked-ripple-color);
        height: 40px;
        left: -12px;
        pointer-events: none;
        top: -12px;
        transition: color linear 80ms;
        width: 40px;
      }

      :host([checked]) paper-ripple {
        color: var(--cr-toggle-checked-ripple-color);
      }

      :host-context([dir=rtl]) paper-ripple {
        left: auto;
        right: -12px;
      }
    </style>
    <span id="bar"></span>
    <span id="knob"></span>
<!--_html_template_end_-->`,
  is: 'cr-toggle',

  behaviors: [PaperRippleBehavior],

  properties: {
    checked: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'checkedChanged_',
      notify: true,
    },

    dark: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'disabledChanged_',
    },
  },

  hostAttributes: {
    'aria-disabled': 'false',
    'aria-pressed': 'false',
    role: 'button',
    tabindex: 0,
  },

  listeners: {
    blur: 'hideRipple_',
    click: 'onClick_',
    focus: 'onFocus_',
    keydown: 'onKeyDown_',
    keyup: 'onKeyUp_',
    pointerdown: 'onPointerDown_',
    pointerup: 'onPointerUp_',
  },

  /** @private {?Function} */
  boundPointerMove_: null,

  /**
   * Number of pixels required to move to consider the pointermove event as
   * intentional.
   * @type {number}
   */
  MOVE_THRESHOLD_PX: 5,

  /**
   * Whether the state of the toggle has already taken into account by
   * |pointeremove| handlers. Used in the 'click' handler.
   * @private {boolean}
   */
  handledInPointerMove_: false,

  /** @override */
  attached() {
    const direction =
        this.matches(':host-context([dir=rtl]) cr-toggle') ? -1 : 1;

    this.boundPointerMove_ = (e) => {
      // Prevent unwanted text selection to occur while moving the pointer, this
      // is important.
      e.preventDefault();

      const diff = e.clientX - this.pointerDownX_;
      if (Math.abs(diff) < this.MOVE_THRESHOLD_PX) {
        return;
      }

      this.handledInPointerMove_ = true;

      const shouldToggle = (diff * direction < 0 && this.checked) ||
          (diff * direction > 0 && !this.checked);
      if (shouldToggle) {
        this.toggleState_(/* fromKeyboard= */ false);
      }
    };
  },

  /** @private */
  checkedChanged_() {
    this.setAttribute('aria-pressed', this.checked ? 'true' : 'false');
  },

  /** @private */
  disabledChanged_() {
    this.setAttribute('tabindex', this.disabled ? -1 : 0);
    this.setAttribute('aria-disabled', this.disabled ? 'true' : 'false');
  },

  /** @private */
  onFocus_() {
    this.getRipple().showAndHoldDown();
  },

  /** @private */
  hideRipple_() {
    this.getRipple().clear();
  },

  /** @private */
  onPointerUp_() {
    this.removeEventListener('pointermove', this.boundPointerMove_);
    this.hideRipple_();
  },

  /**
   * @param {!PointerEvent} e
   * @private
   */
  onPointerDown_(e) {
    // Don't do anything if this was not a primary button click or touch event.
    if (e.button !== 0) {
      return;
    }

    // This is necessary to have follow up pointer events fire on |this|, even
    // if they occur outside of its bounds.
    this.setPointerCapture(e.pointerId);
    this.pointerDownX_ = e.clientX;
    this.handledInPointerMove_ = false;
    this.addEventListener('pointermove', this.boundPointerMove_);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onClick_(e) {
    // Prevent |click| event from bubbling. It can cause parents of this
    // elements to erroneously re-toggle this control.
    e.stopPropagation();
    e.preventDefault();

    // User gesture has already been taken care of inside |pointermove|
    // handlers, Do nothing here.
    if (this.handledInPointerMove_) {
      return;
    }

    // If no pointermove event fired, then user just clicked on the
    // toggle button and therefore it should be toggled.
    this.toggleState_(/* fromKeyboard= */ false);
  },

  /**
   * @param {boolean} fromKeyboard
   * @private
   */
  toggleState_(fromKeyboard) {
    // Ignore cases where the 'click' or 'keypress' handlers are triggered while
    // disabled.
    if (this.disabled) {
      return;
    }

    if (!fromKeyboard) {
      this.hideRipple_();
    }

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
      this.toggleState_(/* fromKeyboard= */ true);
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
      this.toggleState_(/* fromKeyboard= */ true);
    }
  },

  // customize the element's ripple
  _createRipple() {
    this._rippleContainer = this.$.knob;
    const ripple = PaperRippleBehavior._createRipple();
    ripple.id = 'ink';
    ripple.setAttribute('recenters', '');
    ripple.classList.add('circle', 'toggle-ink');
    return ripple;
  },
});
