// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import {assertNotReached} from '../../js/assert.m.js';
import {listenOnce} from '../../js/util.m.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host dialog {
        --drawer-width: 256px;
        --transition-timing: 200ms ease;
        background-color: #fff;
        border: none;
        bottom: 0;
        left: calc(-1 * var(--drawer-width));
        margin: 0;
        overflow: hidden;
        padding: 0;
        position: absolute;
        top: 0;
        transition: left var(--transition-timing);
        width: var(--drawer-width);
      }

      @media (prefers-color-scheme: dark) {
        :host dialog {
          background: var(--google-grey-900)
              linear-gradient(rgba(255, 255, 255, .04), rgba(255, 255, 255, .04));
        }
      }

      :host dialog,
      #container {
        height: 100%;
        word-break: break-word;
      }

      :host([show_]) dialog {
        left: 0;
      }

      :host([align=rtl]) dialog {
        left: auto;
        right: calc(-1 * var(--drawer-width));
        transition: right var(--transition-timing);
      }

      :host([show_][align=rtl]) dialog {
        right: 0;
      }

      :host dialog::backdrop {
        background: rgba(0, 0, 0, 0.5);
        bottom: 0;
        left: 0;
        opacity: 0;
        position: absolute;
        right: 0;
        top: 0;
        transition: opacity var(--transition-timing);
      }

      :host([show_]) dialog::backdrop {
        opacity: 1;
      }

      .drawer-header {
        align-items: center;
        border-bottom: var(--cr-separator-line);
        color: var(--cr-drawer-header-color, inherit);
        display: flex;
        font-size: 123.08%;  /* go to 16px from 13px */
        font-weight: var(--cr-drawer-header-font-weight, inherit);
        min-height: 56px;
        padding-inline-start: var(--cr-drawer-header-padding, 24px);
      }

      @media (prefers-color-scheme: dark) {
        .drawer-header {
          color: var(--cr-primary-text-color);
        }
      }

      #heading {
        outline: none;
      }

      #iconButton {
        cursor: pointer;
        margin-inline-end: 14px;
        margin-inline-start: 0;
        outline: none;
      }

      :host ::slotted(.drawer-content) {
        height: calc(100% - 56px);
        overflow: auto;
      }
    </style>
    <dialog id="dialog" on-cancel="onDialogCancel_" on-click="onDialogTap_"
        on-close="onDialogClose_">
      <div id="container" on-click="onContainerTap_">
        <div class="drawer-header">
          <!-- Hidden from a11y because this icon is decorative. Clicking closes
              the dialog, but screen reader users can do this by pressing ESC,
              so aria-hidden is OK here. -->
          <iron-icon id="iconButton" icon="[[iconName]]" on-click="onIconTap_"
              title="[[iconTitle]]" hidden="[[!iconName]]" aria-hidden="true">
          </iron-icon>
          <div id="heading" tabindex="-1">[[heading]]</div>
        </div>
        <slot></slot>
      </div>
    </dialog>
<!--_html_template_end_-->`,
  is: 'cr-drawer',

  properties: {
    heading: String,

    /** @private */
    show_: {
      type: Boolean,
      reflectToAttribute: true,
    },

    /** The alignment of the drawer on the screen ('ltr' or 'rtl'). */
    align: {
      type: String,
      value: 'ltr',
      reflectToAttribute: true,
    },

    /**
     * An iron-icon resource name, e.g. "cr20:menu". If null, no icon will
     * be shown.
     */
    iconName: {
      type: String,
      value: null,
    },

    /** Title attribute for the icon, if shown. */
    iconTitle: String,
  },

  /** @type {boolean} */
  get open() {
    return this.$.dialog.open;
  },

  set open(value) {
    assertNotReached('Cannot set |open|.');
  },

  /** Toggles the drawer open and close. */
  toggle() {
    if (this.open) {
      this.cancel();
    } else {
      this.openDrawer();
    }
  },

  /** Shows drawer and slides it into view. */
  openDrawer() {
    if (this.open) {
      return;
    }
    this.$.dialog.showModal();
    this.show_ = true;
    this.fire('cr-drawer-opening');
    listenOnce(this.$.dialog, 'transitionend', () => {
      this.fire('cr-drawer-opened');
    });
  },

  /**
   * Slides the drawer away, then closes it after the transition has ended. It
   * is up to the owner of this component to differentiate between close and
   * cancel.
   * @param {boolean} cancel
   */
  dismiss_(cancel) {
    if (!this.open) {
      return;
    }
    this.show_ = false;
    listenOnce(this.$.dialog, 'transitionend', () => {
      this.$.dialog.close(cancel ? 'canceled' : 'closed');
    });
  },

  cancel() {
    this.dismiss_(true);
  },

  close() {
    this.dismiss_(false);
  },

  /** @return {boolean} */
  wasCanceled() {
    return !this.open && this.$.dialog.returnValue === 'canceled';
  },

  /**
   * Handles a tap on the (optional) icon.
   * @param {!Event} event
   * @private
   */
  onIconTap_(event) {
    this.cancel();
  },

  /**
   * Stop propagation of a tap event inside the container. This will allow
   * |onDialogTap_| to only be called when clicked outside the container.
   * @param {!Event} event
   * @private
   */
  onContainerTap_(event) {
    event.stopPropagation();
  },

  /**
   * Close the dialog when tapped outside the container.
   * @private
   */
  onDialogTap_() {
    this.cancel();
  },

  /**
   * Overrides the default cancel machanism to allow for a close animation.
   * @param {!Event} event
   * @private
   */
  onDialogCancel_(event) {
    event.preventDefault();
    this.cancel();
  },

  /**
   * @param {!Event} event
   * @private
   */
  onDialogClose_(event) {
    // TODO(dpapad): This is necessary to make the code work both for Polymer 1
    // and Polymer 2. Remove once migration to Polymer 2 is completed.
    event.stopPropagation();

    // Catch and re-fire the 'close' event such that it bubbles across Shadow
    // DOM v1.
    this.fire('close');
  },
});
