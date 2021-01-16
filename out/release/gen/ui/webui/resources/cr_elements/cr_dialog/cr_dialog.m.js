// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-dialog' is a component for showing a modal dialog. If the
 * dialog is closed via close(), a 'close' event is fired. If the dialog is
 * canceled via cancel(), a 'cancel' event is fired followed by a 'close' event.
 *
 * Additionally clients can get a reference to the internal native <dialog> via
 * calling getNative() and inspecting the |returnValue| property inside
 * the 'close' event listener to determine whether it was canceled or just
 * closed, where a truthy value means success, and a falsy value means it was
 * canceled.
 *
 * Note that <cr-dialog> wrapper itself always has 0x0 dimensions, and
 * specifying width/height on <cr-dialog> directly will have no effect on the
 * internal native <dialog>. Instead use cr-dialog::part(dialog) to specify
 * width/height (as well as other available mixins to style other parts of the
 * dialog contents).
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {assert} from '../../js/assert.m.js';
import {CrContainerShadowBehavior} from '../cr_container_shadow_behavior.m.js';
import '../cr_icon_button/cr_icon_button.m.js';
import '../cr_icons_css.m.js';
import '../hidden_style_css.m.js';
import '../shared_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style cr-icons">
      dialog {
        --scroll-border-color: var(--paper-grey-300);
        --scroll-border: 1px solid var(--scroll-border-color);
        border: 0;
        border-radius: 8px;
        bottom: 50%;
        box-shadow: 0 0 16px rgba(0, 0, 0, 0.12),
                    0 16px 16px rgba(0, 0, 0, 0.24);
        color: inherit;
        overflow-y: hidden;
        padding: 0;
        top: 50%;
        width: 512px;

        /* Avoid using the mixin. Use ::part(dialog) instead.
         * Necessary for backward compatibility with Polymer1/SDv0 (only used by
         * OOBE). TODO(crbug.com/955194): Remove this once fixed.*/
        @apply --cr-dialog-native;
      }

      @media (prefers-color-scheme: dark) {
        dialog {
          --scroll-border-color: var(--google-grey-refresh-700);
          background-color: var(--google-grey-900);
          /* Note: the colors in linear-gradient() are intentionally the same to
           * add a 4% white layer on top of the fully opaque background-color. */
          background-image: linear-gradient(rgba(255, 255, 255, .04),
                                            rgba(255, 255, 255, .04));
        }
      }

      dialog[open] #content-wrapper {
        /* Keep max-height within viewport, and flex content accordingly. */
        display: flex;
        flex-direction: column;
        max-height: 100vh;
        overflow: auto;
      }

      /* When needing to flex, force .body-container alone to shrink. */
      .top-container,
      :host ::slotted([slot=button-container]),
      :host ::slotted([slot=footer]) {
        flex-shrink: 0;
      }

      dialog::backdrop {
        background-color: rgba(0, 0, 0, 0.6);
        bottom: 0;
        left: 0;
        position: fixed;
        right: 0;
        top: 0;
      }

      :host ::slotted([slot=body]) {
        color: var(--cr-secondary-text-color);
        padding: 0 20px;
      }

      :host ::slotted([slot=title]) {
        color: var(--cr-primary-text-color);
        flex: 1;
        font-size: calc(15 / 13 * 100%);
        line-height: 1;
        padding-bottom: 16px;
        padding-inline-end: 20px;
        padding-inline-start: 20px;
        padding-top: 20px;
      }

      :host ::slotted([slot=button-container]) {
        display: flex;
        justify-content: flex-end;
        padding-bottom: 16px;
        padding-inline-end: 16px;
        padding-inline-start: 16px;
        padding-top: 24px;
      }

      :host ::slotted([slot=footer]) {
        border-bottom-left-radius: inherit;
        border-bottom-right-radius: inherit;
        border-top: 1px solid #dbdbdb;
        margin: 0;
        padding: 16px 20px;
      }

      @media (prefers-color-scheme: dark) {
        :host ::slotted([slot=footer]) {
          border-top-color: var(--cr-separator-color);
        }
      }

      .body-container {
        box-sizing: border-box;
        display: flex;
        flex-direction: column;
        min-height: 1.375rem; /* Minimum reasonably usable height. */
        overflow: auto;
      }

      :host {
        --transparent-border: 1px solid transparent;
      }

      /* Cr Dialog uses borders instead of box-shadows. */
      #cr-container-shadow-top {
        border-bottom: var(--cr-dialog-body-border-top,
            var(--transparent-border));
      }

      #cr-container-shadow-bottom {
        border-bottom: var(--cr-dialog-body-border-bottom,
            var(--transparent-border));
      }

      #cr-container-shadow-top.has-shadow,
      #cr-container-shadow-bottom.has-shadow {
        border-bottom: var(--scroll-border);
      }

      .top-container {
        align-items: flex-start;
        display: flex;
        min-height: var(--cr-dialog-top-container-min-height, 31px);
      }

      .title-container {
        display: flex;
        flex: 1;
        outline: none;
      }

      #close {
        align-self: flex-start;
        margin-inline-end: 4px;
        margin-top: 4px;
      }
    </style>
    <dialog id="dialog" on-close="onNativeDialogClose_"
        on-cancel="onNativeDialogCancel_" part="dialog" aria-labelledby="title">
      <!-- This wrapper is necessary, such that the "pulse" animation is not
        erroneously played when the user clicks on the outer-most scrollbar. -->
      <div id="content-wrapper" part="wrapper">
        <div class="top-container">
          <div id="title" class="title-container" tabindex="-1">
            <slot name="title"></slot>
          </div>
          <cr-icon-button id="close" class="icon-clear"
              hidden$="[[!showCloseButton]]" aria-label$="[[closeText]]"
              on-click="cancel" on-keypress="onCloseKeypress_">
          </cr-icon-button>
        </div>
        <slot name="header"></slot>
        <div class="body-container" id="container" show-bottom-shadow
            part="body-container">
          <slot name="body"></slot>
        </div>
        <slot name="button-container"></slot>
        <slot name="footer"></slot>
      </div>
    </dialog>
<!--_html_template_end_-->`,
  is: 'cr-dialog',

  behaviors: [CrContainerShadowBehavior],

  properties: {
    open: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    /**
     * Alt-text for the dialog close button.
     */
    closeText: String,

    /**
     * True if the dialog should remain open on 'popstate' events. This is used
     * for navigable dialogs that have their separate navigation handling code.
     */
    ignorePopstate: {
      type: Boolean,
      value: false,
    },

    /**
     * True if the dialog should ignore 'Enter' keypresses.
     */
    ignoreEnterKey: {
      type: Boolean,
      value: false,
    },

    /**
     * True if the dialog should consume 'keydown' events. If ignoreEnterKey
     * is true, 'Enter' key won't be consumed.
     */
    consumeKeydownEvent: {
      type: Boolean,
      value: false,
    },

    /**
     * True if the dialog should not be able to be cancelled, which will prevent
     * 'Escape' key presses from closing the dialog.
     */
    noCancel: {
      type: Boolean,
      value: false,
    },

    // True if dialog should show the 'X' close button.
    showCloseButton: {
      type: Boolean,
      value: false,
    },

    showOnAttach: {
      type: Boolean,
      value: false,
    },
  },

  listeners: {
    'pointerdown': 'onPointerdown_',
  },

  /** @private {?IntersectionObserver} */
  intersectionObserver_: null,

  /** @private {?MutationObserver} */
  mutationObserver_: null,

  /** @private {?Function} */
  boundKeydown_: null,

  /** @override */
  ready() {
    // If the active history entry changes (i.e. user clicks back button),
    // all open dialogs should be cancelled.
    window.addEventListener('popstate', function() {
      if (!this.ignorePopstate && this.$.dialog.open) {
        this.cancel();
      }
    }.bind(this));

    if (!this.ignoreEnterKey) {
      this.addEventListener('keypress', this.onKeypress_.bind(this));
    }
  },

  /** @override */
  attached() {
    const mutationObserverCallback = function() {
      if (this.$.dialog.open) {
        this.enableShadowBehavior(true);
        this.addKeydownListener_();
      } else {
        this.enableShadowBehavior(false);
        this.removeKeydownListener_();
      }
    }.bind(this);

    this.mutationObserver_ = new MutationObserver(mutationObserverCallback);

    this.mutationObserver_.observe(this.$.dialog, {
      attributes: true,
      attributeFilter: ['open'],
    });

    // In some cases dialog already has the 'open' attribute by this point.
    mutationObserverCallback();
    if (this.showOnAttach) {
      this.showModal();
    }
  },

  /** @override */
  detached() {
    this.removeKeydownListener_();
    if (this.mutationObserver_) {
      this.mutationObserver_.disconnect();
      this.mutationObserver_ = null;
    }
  },

  /** @private */
  addKeydownListener_() {
    if (!this.consumeKeydownEvent) {
      return;
    }

    this.boundKeydown_ = this.boundKeydown_ || this.onKeydown_.bind(this);

    this.addEventListener('keydown', this.boundKeydown_);

    // Sometimes <body> is key event's target and in that case the event
    // will bypass cr-dialog. We should consume those events too in order to
    // behave modally. This prevents accidentally triggering keyboard commands.
    document.body.addEventListener('keydown', this.boundKeydown_);
  },

  /** @private */
  removeKeydownListener_() {
    if (!this.boundKeydown_) {
      return;
    }

    this.removeEventListener('keydown', this.boundKeydown_);
    document.body.removeEventListener('keydown', this.boundKeydown_);
    this.boundKeydown_ = null;
  },

  showModal() {
    this.$.dialog.showModal();
    assert(this.$.dialog.open);
    this.open = true;
    this.fire('cr-dialog-open');
  },

  cancel() {
    this.fire('cancel');
    this.$.dialog.close();
    assert(!this.$.dialog.open);
    this.open = false;
  },

  close() {
    this.$.dialog.close('success');
    assert(!this.$.dialog.open);
    this.open = false;
  },

  /**
   * Set the title of the dialog for a11y reader.
   * @param {string} title Title of the dialog.
   */
  setTitleAriaLabel(title) {
    this.$.dialog.removeAttribute('aria-labelledby');
    this.$.dialog.setAttribute('aria-label', title);
  },

  /**
   * @private
   * @param {Event} e
   */
  onCloseKeypress_(e) {
    // Because the dialog may have a default Enter key handler, prevent
    // keypress events from bubbling up from this element.
    e.stopPropagation();
  },

  /**
   * @param {!Event} e
   * @private
   */
  onNativeDialogClose_(e) {
    // Ignore any 'close' events not fired directly by the <dialog> element.
    if (e.target !== this.getNative()) {
      return;
    }

    // TODO(dpapad): This is necessary to make the code work both for Polymer 1
    // and Polymer 2. Remove once migration to Polymer 2 is completed.
    e.stopPropagation();

    // Catch and re-fire the 'close' event such that it bubbles across Shadow
    // DOM v1.
    this.fire('close');
  },

  /**
   * @param {!Event} e
   * @private
   */
  onNativeDialogCancel_(e) {
    // Ignore any 'cancel' events not fired directly by the <dialog> element.
    if (e.target !== this.getNative()) {
      return;
    }

    if (this.noCancel) {
      e.preventDefault();
      return;
    }

    // When the dialog is dismissed using the 'Esc' key, need to manually update
    // the |open| property (since close() is not called).
    this.open = false;

    // Catch and re-fire the native 'cancel' event such that it bubbles across
    // Shadow DOM v1.
    this.fire('cancel');
  },

  /**
   * Expose the inner native <dialog> for some rare cases where it needs to be
   * directly accessed (for example to programmatically setheight/width, which
   * would not work on the wrapper).
   * @return {!HTMLDialogElement}
   */
  getNative() {
    return /** @type {!HTMLDialogElement} */ (this.$.dialog);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onKeypress_(e) {
    if (e.key !== 'Enter') {
      return;
    }

    // Accept Enter keys from either the dialog itself, or a child cr-input,
    // considering that the event may have been retargeted, for example if the
    // cr-input is nested inside another element. Also exclude inputs of type
    // 'search', since hitting 'Enter' on a search field most likely intends to
    // trigger searching.
    const accept = e.target === this ||
        e.composedPath().some(
            el => el.tagName === 'CR-INPUT' && el.type !== 'search');
    if (!accept) {
      return;
    }
    const actionButton =
        this.querySelector('.action-button:not([disabled]):not([hidden])');
    if (actionButton) {
      actionButton.click();
      e.preventDefault();
    }
  },

  /**
   * @param {!Event} e
   * @private
   */
  onKeydown_(e) {
    assert(this.consumeKeydownEvent);

    if (!this.getNative().open) {
      return;
    }

    if (this.ignoreEnterKey && e.key === 'Enter') {
      return;
    }

    // Stop propagation to behave modally.
    e.stopPropagation();
  },

  /** @param {!PointerEvent} e */
  onPointerdown_(e) {
    // Only show pulse animation if user left-clicked outside of the dialog
    // contents.
    if (e.button !== 0 || e.composedPath()[0].tagName !== 'DIALOG') {
      return;
    }

    this.$.dialog.animate(
        [
          {transform: 'scale(1)', offset: 0},
          {transform: 'scale(1.02)', offset: 0.4},
          {transform: 'scale(1.02)', offset: 0.6},
          {transform: 'scale(1)', offset: 1},
        ],
        /** @type {!KeyframeAnimationOptions} */ ({
          duration: 180,
          easing: 'ease-in-out',
          iterations: 1,
        }));

    // Prevent any text from being selected within the dialog when clicking in
    // the backdrop area.
    e.preventDefault();
  },

  focus() {
    this.$$('.title-container').focus();
  },
});
