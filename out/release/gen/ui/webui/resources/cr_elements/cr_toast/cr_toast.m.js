// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
/**
 * @fileoverview A lightweight toast.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        --cr-toast-background: #323232;
        --cr-toast-button-color: var(--google-blue-300);
        --cr-toast-text-color: #fff;
      }

      @media (prefers-color-scheme: dark) {
        :host {
          --cr-toast-background: var(--google-grey-900)
              linear-gradient(rgba(255, 255, 255, .06), rgba(255, 255, 255, .06));
          --cr-toast-button-color: var(--google-blue-refresh-300);
          --cr-toast-text-color: var(--google-grey-200);
        }
      }

      :host {
        align-items: center;
        background: var(--cr-toast-background);
        border-radius: 4px;
        bottom: 0;
        box-shadow: 0 2px 4px 0 rgba(0, 0, 0, 0.28);
        box-sizing: border-box;
        display: flex;
        margin: 24px;
        max-width: 568px;
        min-height: 52px;
        min-width: 288px;
        opacity: 0;
        padding: 0 24px;
        position: fixed;
        transform: translateY(100px);
        transition: opacity 300ms, transform 300ms, visibility 300ms;
        visibility: hidden;
        z-index: 1;
      }

      :host([open]) {
        opacity: 1;
        transform: translateY(0);
        visibility: visible;
      }

      /* Note: this doesn't work on slotted text nodes. Something like
       * <cr-toast>hey!</cr-toast> wont get the right text color. */
      :host ::slotted(*) {
        color: var(--cr-toast-text-color);
      }

      :host ::slotted(cr-button) {
        background-color: transparent !important;
        border: none !important;
        color: var(--cr-toast-button-color) !important;
        margin-inline-start: 32px !important;
        min-width: 52px !important;
        padding: 8px !important;
      }

      :host ::slotted(cr-button:hover) {
        background-color: transparent !important;
      }
    </style>
    <slot></slot>
<!--_html_template_end_-->`,
  is: 'cr-toast',

  properties: {
    duration: {
      type: Number,
      value: 0,
    },

    open: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },
  },

  hostAttributes: {
    'role': 'alert',
  },

  observers: ['resetAutoHide_(duration, open)'],

  /** @private {number|null} */
  hideTimeoutId_: null,

  /**
   * Cancels existing auto-hide, and sets up new auto-hide.
   * @private
   */
  resetAutoHide_() {
    if (this.hideTimeoutId_ !== null) {
      window.clearTimeout(this.hideTimeoutId_);
      this.hideTimeoutId_ = null;
    }

    if (this.open && this.duration !== 0) {
      this.hideTimeoutId_ = window.setTimeout(() => {
        this.open = false;
      }, this.duration);
    }
  },

  /**
   * Shows the toast and auto-hides after |this.duration| milliseconds has
   * passed. If the toast is currently being shown, any preexisting auto-hide
   * is cancelled and replaced with a new auto-hide.
   *
   * If |this.duration| is set to 0, the toast will remain open indefinitely.
   * The caller is responsible for hiding the toast.
   *
   * When |duration| is passed in the non-negative number, |this.duration|
   * is updated to that value.
   * @param {number=} duration
   */
  show(duration) {
    // |this.resetAutoHide_| is called whenever |this.duration| or |this.open|
    // is changed. If neither is changed, we will still need to reset auto-hide.
    let shouldResetAutoHide = true;

    if (typeof (duration) !== 'undefined' && duration >= 0 &&
        this.duration !== duration) {
      this.duration = duration;
      shouldResetAutoHide = false;
    }

    if (!this.open) {
      this.open = true;
      shouldResetAutoHide = false;
    }

    if (shouldResetAutoHide) {
      this.resetAutoHide_();
    }
  },

  /**
   * Hides the toast.
   */
  hide() {
    this.open = false;
  },
});
