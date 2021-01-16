// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-profile-avatar-selector' is an element that displays
 * profile avatar icons and allows an avatar to be selected.
 */

/**
 * @typedef {{url: string,
 *            label: string,
 *            isGaiaAvatar: (boolean|undefined),
 *            selected: (boolean|undefined)}}
 */
let AvatarIcon;

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../cr_button/cr_button.m.js';
import '../shared_vars_css.m.js';
import {getImage} from '../../js/icon.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './cr_profile_avatar_selector_grid.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        --avatar-size: 96px;
        --avatar-spacing: 24px;
        display: inline-flex;
      }

      #avatar-grid .avatar {
        --avatar-focus-color: var(--google-grey-refresh-700);
        --avatar-gap-color: white;
        --avatar-gap-width: 2px;
        --avatar-selected-color: var(--google-blue-500);

        background-position: center;
        background-repeat: no-repeat;
        border: 1px solid var(--paper-grey-300);
        border-radius: 100%;
        box-shadow: 0 0 0 var(--avatar-gap-width) var(--avatar-gap-color),
            0 0 0 calc(var(--avatar-gap-width) + var(--avatar-outline-width))
                var(--avatar-outline-color);
        display: flex;
        height: var(--avatar-size);
        margin: calc(var(--avatar-spacing) / 2);
        min-width: 0;
        padding: 0;
        transition: none !important;  /* Polymer's :host([animated]) rule. */
        width: var(--avatar-size);
      }

      @media (prefers-color-scheme: dark) {
        #avatar-grid .avatar {
          --avatar-focus-color: var(--google-grey-refresh-500);
          --avatar-gap-color: var(--google-grey-800);
          --avatar-selected-color: var(--google-blue-refresh-300);
        }
      }

      #avatar-grid .avatar.iron-selected {
        --avatar-outline-color: var(--avatar-selected-color);
        --avatar-outline-width: 2px !important;  /* Overrides rule below. */
        border-color: var(--avatar-selected-color);
      }

      :host-context(.focus-outline-visible) #avatar-grid
          .avatar:not(.iron-selected):focus {
        --avatar-outline-color: var(--avatar-focus-color);
        --avatar-outline-width: 1px;
      }

      cr-button {
        background-size: var(--avatar-size);
      }
    </style>
    <cr-profile-avatar-selector-grid id="avatar-grid"
        ignore-modified-key-events="[[ignoreModifiedKeyEvents]]">
      <template is="dom-repeat" items="[[avatars]]">
        <cr-button class$="avatar [[getSelectedClass_(item.selected)]]"
            title="[[item.label]]"
            style$="background-image: [[getIconImageSet_(item.url)]]"
            on-click="onAvatarTap_">
        </cr-button>
      </template>
    </cr-profile-avatar-selector-grid>
<!--_html_template_end_-->`,
  is: 'cr-profile-avatar-selector',

  properties: {
    /**
     * The list of profile avatar URLs and labels.
     * @type {!Array<!AvatarIcon>}
     */
    avatars: {
      type: Array,
      value() {
        return [];
      }
    },

    /**
     * The currently selected profile avatar icon, if any.
     * @type {?AvatarIcon}
     */
    selectedAvatar: {
      type: Object,
      notify: true,
    },

    /** @private {?HTMLElement} */
    selectedAvatarElement_: Object,

    ignoreModifiedKeyEvents: {
      type: Boolean,
      value: false,
    },
  },

  /** @private */
  getSelectedClass_(isSelected) {
    // TODO(dpapad): Rename 'iron-selected' to 'selected' now that this CSS
    // class is not assigned by any iron-* behavior.
    return isSelected ? 'iron-selected' : '';
  },

  /**
   * @param {string} iconUrl
   * @return {string} A CSS image-set for multiple scale factors.
   * @private
   */
  getIconImageSet_(iconUrl) {
    return getImage(iconUrl);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onAvatarTap_(e) {
    // Manual selection for profile creation
    if (this.selectedAvatarElement_) {
      this.selectedAvatarElement_.classList.remove('iron-selected');
    }
    this.selectedAvatarElement_ = /** @type {!HTMLElement} */ (e.target);
    this.selectedAvatarElement_.classList.add('iron-selected');

    // |selectedAvatar| is set to pass back selection to the owner of this
    // component.
    this.selectedAvatar =
        /** @type {!{model: {item: !AvatarIcon}}} */ (e).model.item;
  },
});
