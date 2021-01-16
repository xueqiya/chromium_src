// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-icon-button' is a button which displays an icon with a
 * ripple. It can be interacted with like a normal button using click as well as
 * space and enter to effectively click the button and fire a 'click' event.
 *
 * There are two sources to icons, cr-icons and iron-iconset-svg. The cr-icon's
 * are defined as background images with a reference to a resource file
 * associated with a CSS class name. The iron-icon's are defined as inline SVG's
 * under a key that is stored in a global map that is accessible to the
 * iron-icon element.
 *
 * Example of using a cr-icon:
 * <link rel="import" href="chrome://resources/cr_elements/cr_icons_css.html">
 * <dom-module id="module">
 *   <template>
 *     <style includes="cr-icons"></style>
 *     <cr-icon-button class="icon-class-name"></cr-icon-button>
 *   </template>
 * </dom-module>
 *
 * In general when an icon is specified using a class, the expectation is the
 * class will set an image to the --cr-icon-image variable.
 *
 * Example of using an iron-icon:
 * <link rel="import" href="chrome://resources/cr_elements/icons.html">
 * <cr-icon-button iron-icon="cr:icon-key"></cr-icon-button>
 *
 * The color of the icon can be overridden using CSS variables. When using
 * iron-icon both the fill and stroke can be overridden the variables:
 * --cr-icon-button-fill-color
 * --cr-icon-button-fill-color-focus
 * --cr-icon-button-stroke-color
 * --cr-icon-button-stroke-color-focus
 *
 * When not using iron-icon (ie. specifying --cr-icon-image), the icons support
 * one color and the 'stroke' variables are ignored.
 *
 * The '-focus' variables are used for opaque ripple support. This is enabled
 * when the 'a11y-enhanced' attribute on <html> is present.
 *
 * When using iron-icon's, more than one icon can be specified by setting
 * the |ironIcon| property to a comma-delimited list of keys.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import {PaperRippleBehavior} from 'chrome://resources/polymer/v3_0/paper-behaviors/paper-ripple-behavior.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        --cr-icon-button-fill-color: var(--google-grey-refresh-700);
        --cr-icon-button-fill-color-focus: white;
        --cr-icon-button-icon-start-offset: 0;
        --cr-icon-button-icon-size: 20px;
        --cr-icon-button-size: 36px;
        --cr-icon-button-height: var(--cr-icon-button-size);
        --cr-icon-button-transition: 150ms ease-in-out;
        --cr-icon-button-width: var(--cr-icon-button-size);
        /* Copied from paper-fab.html. Prevents square touch highlight. */
        -webkit-tap-highlight-color: transparent;
        border-radius: 4px;
        color: var(--cr-icon-button-stroke-color,
            var(--cr-icon-button-fill-color));
        cursor: pointer;
        display: inline-flex;
        flex-shrink: 0;
        height: var(--cr-icon-button-height);
        margin-inline-end: var(--cr-icon-button-margin-end,
            var(--cr-icon-ripple-margin));
        margin-inline-start: var(--cr-icon-button-margin-start);
        outline: none;
        user-select: none;
        vertical-align: middle;
        width: var(--cr-icon-button-width);
      }

      :host([disabled]) {
        cursor: initial;
        opacity: var(--cr-disabled-opacity);
        pointer-events: none;
      }

      :host(.no-overlap) {
        --cr-icon-button-margin-end: 0;
        --cr-icon-button-margin-start: 0;
      }

      :host-context([dir=rtl]) {
        transform: scaleX(-1);  /* Invert X: flip on the Y axis (aka mirror). */
      }

      :host(:not([iron-icon])) #maskedImage {
        -webkit-mask-image: var(--cr-icon-image);
        -webkit-mask-position: center;
        -webkit-mask-repeat: no-repeat;
        -webkit-mask-size: var(--cr-icon-button-icon-size);
        background-color: var(--cr-icon-button-fill-color);
        height: 100%;
        transition: background-color var(--cr-icon-button-transition);
        width: 100%;
        z-index: 1;
      }

      :host-context([a11y-enhanced]):host([ripple-showing_]) #maskedImage {
        background-color: var(--cr-icon-button-fill-color-focus);
      }

      #icon {
        align-items: center;
        border-radius: 4px;
        display: flex;
        height: 100%;
        justify-content: center;
        padding-inline-start: var(--cr-icon-button-icon-start-offset);
        /* The |_rippleContainer| must be position relative. */
        position: relative;
        width: 100%;
      }

      iron-icon {
        --iron-icon-fill-color: var(--cr-icon-button-fill-color);
        --iron-icon-stroke-color: var(--cr-icon-button-stroke-color, none);
        --iron-icon-height: var(--cr-icon-button-icon-size);
        --iron-icon-width: var(--cr-icon-button-icon-size);
        transition: fill var(--cr-icon-button-transition),
            stroke var(--cr-icon-button-transition);
        z-index: 1;
      }

      :host-context([a11y-enhanced]):host([ripple-showing_]) iron-icon {
        --iron-icon-fill-color: var(--cr-icon-button-fill-color-focus);
        --iron-icon-stroke-color: var(--cr-icon-button-stroke-color-focus,
            none);
      }

      paper-ripple {
        /* GG900 .15 is about GG700 .21 */
        --paper-ripple-opacity: var(--cr-icon-button-ripple-opacity, .21);
      }


      @media (prefers-color-scheme: dark) {
        :host {
          --cr-icon-button-fill-color: var(--google-grey-refresh-500);
          --cr-icon-button-fill-color-focus: var(--google-grey-900);
        }

        paper-ripple {
          --paper-ripple-opacity: var(--cr-icon-button-ripple-opacity, .4);
        }
      }

      :host-context([a11y-enhanced]) paper-ripple {
        --paper-ripple-opacity: 1;
        opacity: 0;
        transition: opacity var(--cr-icon-button-transition);
      }

      :host-context([a11y-enhanced]):host([ripple-showing_]) paper-ripple {
        opacity: 1;
      }
    </style>
    <div id="icon">
      <div id="maskedImage"></div>
    </div>
<!--_html_template_end_-->`,
  is: 'cr-icon-button',

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

    ironIcon: {
      type: String,
      observer: 'onIronIconChanged_',
      reflectToAttribute: true,
    },

    /** @private */
    rippleShowing_: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },
  },

  hostAttributes: {
    'aria-disabled': 'false',
    role: 'button',
    tabindex: 0,
  },

  listeners: {
    blur: 'hideRipple_',
    click: 'onClick_',
    down: 'showRipple_',
    focus: 'showRipple_',
    keydown: 'onKeyDown_',
    keyup: 'onKeyUp_',
    pointerdown: 'ensureRipple',
    up: 'hideRipple_',
  },

  /** @private */
  hideRipple_() {
    if (this.hasRipple()) {
      this.getRipple().clear();
      this.rippleShowing_ = false;
    }
  },

  /** @private */
  showRipple_() {
    if (!this.noink && !this.disabled) {
      this.getRipple().showAndHoldDown();
      this.rippleShowing_ = true;
    }
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
    this.setAttribute('aria-disabled', this.disabled ? 'true' : 'false');
    this.setAttribute('tabindex', this.disabled ? '-1' : '0');
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

  /** @private */
  onIronIconChanged_() {
    this.shadowRoot.querySelectorAll('iron-icon').forEach(el => el.remove());
    if (!this.ironIcon) {
      return;
    }
    const icons = (this.ironIcon || '').split(',');
    icons.forEach(icon => {
      const element = document.createElement('iron-icon');
      element.icon = icon;
      this.$.icon.appendChild(element);
    });
    if (!this.hasRipple()) {
      return;
    }
    if (icons.length > 1) {
      this.getRipple().classList.remove('circle');
    } else {
      this.getRipple().classList.add('circle');
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

  // customize the element's ripple
  _createRipple() {
    this._rippleContainer = this.$.icon;
    const ripple = PaperRippleBehavior._createRipple();
    ripple.id = 'ink';
    ripple.setAttribute('recenters', '');
    if (!(this.ironIcon || '').includes(',')) {
      ripple.classList.add('circle');
    }
    return ripple;
  },
});
