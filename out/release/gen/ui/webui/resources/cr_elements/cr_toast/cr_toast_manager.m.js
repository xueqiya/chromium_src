// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {IronA11yAnnouncer} from 'chrome://resources/polymer/v3_0/iron-a11y-announcer/iron-a11y-announcer.js';
import {assert} from '../../js/assert.m.js';
import '../../js/cr.m.js';
import '../../js/event_tracker.m.js';
import './cr_toast.m.js';

  /* eslint-disable */
  /** @private {?CrToastManagerElement} */
  let toastManagerInstance = null;
  /* eslint-enable */

  /** @return {!CrToastManagerElement} */
  export function getToastManager() {
    return assert(toastManagerInstance);
  }

  /** @param {?CrToastManagerElement} instance */
  function setInstance(instance) {
    assert(!instance || !toastManagerInstance);
    toastManagerInstance = instance;
  }

  /**
   * @fileoverview Element which shows toasts with optional undo button.
   */
  // eslint-disable-next-line
  export let CrToastManagerElement = Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      #content {
        display: flex;
        flex: 1;
      }

      .collapsible {
        overflow: hidden;
        text-overflow: ellipsis;
      }

      span {
        white-space: pre;
      }

      .elided-text {
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }
    </style>
    <cr-toast id="toast" duration="[[duration]]">
      <div id="content" class="elided-text"></div>
      <slot></slot>
    </cr-toast>
<!--_html_template_end_-->`,
    is: 'cr-toast-manager',

    properties: {
      duration: {
        type: Number,
        value: 0,
      },
    },

    /** @return {boolean} */
    get isToastOpen() {
      return this.$.toast.open;
    },

    /** @override */
    attached() {
      setInstance(this);
    },

    /** @override */
    detached() {
      setInstance(null);
    },

    /** @param {string} label The label to display inside the toast. */
    show(label) {
      this.$.content.textContent = label;
      this.showInternal_();
    },

    /**
     * Shows the toast, making certain text fragments collapsible.
     * @param {!Array<!{value: string, collapsible: boolean}>} pieces
     */
    showForStringPieces(pieces) {
      const content = this.$.content;
      content.textContent = '';
      pieces.forEach(function(p) {
        if (p.value.length === 0) {
          return;
        }

        const span = document.createElement('span');
        span.textContent = p.value;
        if (p.collapsible) {
          span.classList.add('collapsible');
        }

        content.appendChild(span);
      });

      this.showInternal_();
    },

    /** @private */
    showInternal_() {
      IronA11yAnnouncer.requestAvailability();
      this.fire('iron-announce', {
        text: this.$.content.textContent,
      });
      this.$.toast.show();
    },

    hide() {
      this.$.toast.hide();
    },
  });

