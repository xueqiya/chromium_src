// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../cr_icon_button/cr_icon_button.m.js';
import '../cr_icons_css.m.js';
import {CrSearchFieldBehavior} from '../cr_search_field/cr_search_field_behavior.m.js';
import '../icons.m.js';
import '../shared_style_css.m.js';
import '../shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-spinner/paper-spinner-lite.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style cr-icons">
      :host {
        align-items: center;
        display: flex;
        height: 40px;
        transition: background-color 150ms cubic-bezier(0.4, 0, 0.2, 1),
            width 150ms cubic-bezier(0.4, 0, 0.2, 1);
        width: 44px;
      }

      [hidden] {
        display: none !important;
      }

      cr-icon-button {
        --cr-icon-button-fill-color-focus: var(
            --cr-toolbar-search-field-input-bg-color,
            var(--cr-toolbar-background-color));
        --cr-icon-button-size: 32px;
        margin: 6px;
      }

      @media (prefers-color-scheme: light) {
        cr-icon-button {
          --cr-icon-button-fill-color: var(
              --cr-toolbar-search-field-input-color,
              white);
        }
      }

      @media (prefers-color-scheme: dark) {
        cr-icon-button {
          --cr-icon-button-fill-color: var(
              --cr-toolbar-search-field-input-color,
              var(--google-grey-refresh-500));
        }
      }

      #icon {
        transition: margin 150ms, opacity 200ms;
      }

      #prompt {
        --cr-toolbar-search-field-prompt-opacity: .7;
        opacity: 0;
      }

      @media (prefers-color-scheme: dark) {
        #prompt {
          --cr-toolbar-search-field-prompt-opacity: 1;
        }
      }

      paper-spinner-lite {
        @apply --cr-icon-height-width;
        --paper-spinner-color:
            var(--cr-toolbar-search-field-input-color, white);
        margin: 0 6px;
        opacity: 0;
        padding: 6px;
        position: absolute;
      }

      paper-spinner-lite[active] {
        opacity: 1;
      }

      #prompt,
      paper-spinner-lite {
        transition: opacity 200ms;
      }

      /* Input field. */
      #searchTerm {
        -webkit-font-smoothing: antialiased;
        flex: 1;
        line-height: 185%;
        margin-inline-end: 2px;
        margin-inline-start: 2px;
        position: relative;
      }

      label {
        bottom: 0;
        cursor: text;
        left: 0;
        overflow: hidden;
        position: absolute;
        right: 0;
        top: 0;
        white-space: nowrap;
      }

      :host([has-search-text]) label {
        visibility: hidden;
      }

      input {
        -webkit-appearance: none;
        background: transparent;
        border: none;
        color: var(--cr-toolbar-search-field-input-color, white);
        font: inherit;
        outline: none;
        padding: 0;
        position: relative;
        width: 100%;
      }

      input[type='search']::-webkit-search-cancel-button {
        -webkit-appearance: none;
        margin: 0;
      }

      /** Wide layout. */
      :host(:not([narrow])) {
        background:
            var(--cr-toolbar-search-field-background, rgba(0, 0, 0, 0.22));
        border-radius:
            var(--cr-toolbar-search-field-border-radius, 2px);
        cursor: text;
        padding-inline-end: 0;
        width: var(--cr-toolbar-field-width, 680px);
      }

      :host(:not([narrow]):not([showing-search])) #icon {
        opacity: .7;
      }

      :host(:not([narrow])) #prompt {
        opacity: var(--cr-toolbar-search-field-prompt-opacity);
      }

      :host([narrow]:not([showing-search])) #searchTerm {
        display: none;
      }

      /* Search open. */
      :host([showing-search][spinner-active]) #icon {
        opacity: 0;
      }

      :host([narrow][showing-search]) {
        width: 100%;
      }

      :host([narrow][showing-search]) #icon,
      :host([narrow][showing-search]) paper-spinner-lite {
        margin-inline-start: 18px;  /* Line up with Menu icon. */
      }
    </style>
    <template is="dom-if" id="spinnerTemplate">
      <paper-spinner-lite active="[[isSpinnerShown_]]">
      </paper-spinner-lite>
    </template>
    <cr-icon-button id="icon" iron-icon="cr:search" title="[[label]]"
        tabindex$="[[computeIconTabIndex_(narrow, hasSearchText)]]"
        aria-hidden$="[[computeIconAriaHidden_(narrow, hasSearchText)]]">
    </cr-icon-button>
    <div id="searchTerm">
      <label id="prompt" for="searchInput" aria-hidden="true">[[label]]</label>
      <input id="searchInput"
          aria-labelledby="prompt"
          type="search"
          on-input="onSearchTermInput"
          on-search="onSearchTermSearch"
          on-keydown="onSearchTermKeydown_"
          on-focus="onInputFocus_"
          on-blur="onInputBlur_"
          autofocus
          spellcheck="false">
    </div>
    <template is="dom-if" if="[[hasSearchText]]">
      <cr-icon-button id="clearSearch" iron-icon="cr:cancel"
          title="[[clearLabel]]" on-click="clearSearch_"></cr-icon-button>
    </template>
<!--_html_template_end_-->`,
  is: 'cr-toolbar-search-field',

  behaviors: [CrSearchFieldBehavior],

  properties: {
    narrow: {
      type: Boolean,
      reflectToAttribute: true,
    },

    showingSearch: {
      type: Boolean,
      value: false,
      notify: true,
      observer: 'showingSearchChanged_',
      reflectToAttribute: true
    },

    // Prompt text to display in the search field.
    label: String,

    // Tooltip to display on the clear search button.
    clearLabel: String,

    // When true, show a loading spinner to indicate that the backend is
    // processing the search. Will only show if the search field is open.
    spinnerActive: {type: Boolean, reflectToAttribute: true},

    /** @private */
    isSpinnerShown_: {
      type: Boolean,
      computed: 'computeIsSpinnerShown_(spinnerActive, showingSearch)'
    },

    /** @private */
    searchFocused_: {type: Boolean, value: false},
  },

  listeners: {
    // Deliberately uses 'click' instead of 'tap' to fix crbug.com/624356.
    'click': 'showSearch_',
  },

  /** @return {!HTMLInputElement} */
  getSearchInput() {
    return /** @type {!HTMLInputElement} */ (this.$.searchInput);
  },

  /** @return {boolean} */
  isSearchFocused() {
    return this.searchFocused_;
  },

  showAndFocus() {
    this.showingSearch = true;
    this.focus_();
  },

  onSearchTermInput() {
    CrSearchFieldBehavior.onSearchTermInput.call(this);
    this.showingSearch = this.hasSearchText || this.isSearchFocused();
  },

  /** @private */
  focus_() {
    this.getSearchInput().focus();
  },

  /**
   * @param {boolean} narrow
   * @return {number}
   * @private
   */
  computeIconTabIndex_(narrow) {
    return narrow && !this.hasSearchText ? 0 : -1;
  },

  /**
   * @param {boolean} narrow
   * @return {string}
   * @private
   */
  computeIconAriaHidden_(narrow) {
    return Boolean(!narrow || this.hasSearchText).toString();
  },

  /**
   * @return {boolean}
   * @private
   */
  computeIsSpinnerShown_() {
    const showSpinner = this.spinnerActive && this.showingSearch;
    if (showSpinner) {
      this.$.spinnerTemplate.if = true;
    }
    return showSpinner;
  },

  /** @private */
  onInputFocus_() {
    this.searchFocused_ = true;
  },

  /** @private */
  onInputBlur_() {
    this.searchFocused_ = false;
    if (!this.hasSearchText) {
      this.showingSearch = false;
    }
  },

  /** @private */
  onSearchTermKeydown_(e) {
    if (e.key === 'Escape') {
      this.showingSearch = false;
    }
  },

  /**
   * @param {Event} e
   * @private
   */
  showSearch_(e) {
    if (e.target !== this.$.clearSearch) {
      this.showingSearch = true;
    }
  },

  /**
   * @param {Event} e
   * @private
   */
  clearSearch_(e) {
    this.setValue('');
    this.focus_();
    this.spinnerActive = false;
  },

  /**
   * @param {boolean} current
   * @param {boolean|undefined} previous
   * @private
   */
  showingSearchChanged_(current, previous) {
    // Prevent unnecessary 'search-changed' event from firing on startup.
    if (previous === undefined) {
      return;
    }

    if (this.showingSearch) {
      this.focus_();
      return;
    }

    this.setValue('');
    this.getSearchInput().blur();
  },
});
