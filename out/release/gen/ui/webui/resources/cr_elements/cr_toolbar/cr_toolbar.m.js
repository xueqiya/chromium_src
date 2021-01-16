// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {afterNextRender, html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '../cr_icon_button/cr_icon_button.m.js';
import '../cr_icons_css.m.js';
import './cr_toolbar_search_field.m.js';
import '../hidden_style_css.m.js';
import '../icons.m.js';
import '../shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-media-query/iron-media-query.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-icons cr-hidden-style">
      :host {
        align-items: center;
        background-color: var(--cr-toolbar-background-color);
        color: #fff;
        display: flex;
        height: var(--cr-toolbar-height);
      }

      @media (prefers-color-scheme: dark) {
        :host {
          border-bottom: var(--cr-separator-line);
          box-sizing: border-box;
          color: var(--cr-secondary-text-color);
        }
      }

      h1 {
        flex: 1;
        font-size: 123%;
        font-weight: var(--cr-toolbar-header-font-weight, 400);
        letter-spacing: .25px;
        line-height: normal;
        margin-inline-start: 6px;
        padding-inline-end: 12px;
      }

      @media (prefers-color-scheme: dark) {
        h1 {
          color: var(--cr-primary-text-color);
        }
      }

      #leftContent {
        position: relative;
        transition: opacity 100ms;
      }

      #leftSpacer {
        align-items: center;
        box-sizing: border-box;
        display: flex;
        /* 12px to match #rightSpacer + 6px to align with icons in menus. */
        padding-inline-start: calc(12px + 6px);
        width: var(--cr-toolbar-left-spacer-width, auto);
      }

      cr-icon-button {
        --cr-icon-button-fill-color-focus: var(--cr-toolbar-background-color);
        --cr-icon-button-size: 32px;
        min-width: 32px;
      }

      @media (prefers-color-scheme: light) {
        cr-icon-button {
          --cr-icon-button-fill-color: currentColor;
        }
      }

      #centeredContent {
        display: flex;
        flex: 1 1 0;
        justify-content: center;
      }

      #rightSpacer {
        padding-inline-end: 12px;
      }

      :host([narrow]) #centeredContent {
        justify-content: flex-end;
      }

      :host([has-overlay]) {
        transition: visibility var(--cr-toolbar-overlay-animation-duration);
        visibility: hidden;
      }

      :host([narrow][showing-search_]) #leftContent {
        opacity: 0;
        position: absolute;
      }

      :host(:not([narrow])) #leftContent {
        flex: 1 1 var(--cr-toolbar-field-margin, 0);
      }

      :host(:not([narrow])) #centeredContent {
        flex-basis: var(--cr-toolbar-center-basis, 0);
      }

      :host(:not([narrow])) #rightContent {
        flex: 1 1 0;
        text-align: end;
      }

      #menuPromo {
        align-items: center;
        background: #616161;
        border-radius: 2px;
        color: white;
        display: flex;
        font-size: 92.3%;
        font-weight: 500;
        opacity: 0;
        padding-bottom: 6px;
        padding-inline-end: 12px;
        padding-inline-start: 8px;
        padding-top: 6px;
        position: absolute;
        top: var(--cr-toolbar-height);
        white-space: nowrap;
        z-index: 2;
      }

      #menuPromo::before {
        background: inherit;
        /* Up arrow. 105% in Y coordinates fixes glitch at 110/125% zoom. */
        clip-path: polygon(0 105%, 100% 105%, 50% 0);
        content: '';
        display: block;
        height: 6px;
        left: 10px;
        position: absolute;
        top: -6px;
        width: 12px;
      }

      :host-context([dir=rtl]) #menuPromo::before {
        left: auto;
        right: 10px;
      }

      #closePromo {
        -webkit-appearance: none;
        background: none;
        border: none;
        color: inherit;
        font-size: 20px;  /* Shouldn't change if default font-size changes. */
        line-height: 20px;
        margin-inline-start: 12px;
        padding: 0;
        width: 20px;
      }
    </style>
    <div id="leftContent">
      <div id="leftSpacer">
        <!-- Note: showing #menuPromo relies on this dom-if being [restamp]. -->
        <template is="dom-if" if="[[showMenu]]" restamp>
          <cr-icon-button id="menuButton" class="no-overlap"
              iron-icon="cr20:menu" on-click="onMenuTap_"
              aria-label$="[[menuLabel]]"
              title="[[titleIfNotShowMenuPromo_(menuLabel, showMenuPromo)]]">
          </cr-icon-button>
          <template is="dom-if" if="[[showMenuPromo]]">
            <div id="menuPromo" role="tooltip">
              [[menuPromo]]
              <button id="closePromo" on-click="onClosePromoTap_"
                  aria-label$="[[closeMenuPromo]]">&#x2715;</button>
            </paper-tooltip>
          </template>
        </template>
        <h1>[[pageName]]</h1>
      </div>
    </div>

    <div id="centeredContent" hidden$="[[!showSearch]]">
      <cr-toolbar-search-field id="search" narrow="[[narrow]]"
          label="[[searchPrompt]]" clear-label="[[clearLabel]]"
          spinner-active="[[spinnerActive]]"
          showing-search="{{showingSearch_}}">
      </cr-toolbar-search-field>
      <iron-media-query query="(max-width: [[narrowThreshold]]px)"
          query-matches="{{narrow}}">
      </iron-media-query>
    </div>

    <div id="rightContent">
      <div id="rightSpacer">
        <slot></slot>
      </div>
    </div>
<!--_html_template_end_-->`,
  is: 'cr-toolbar',

  properties: {
    // Name to display in the toolbar, in titlecase.
    pageName: String,

    // Prompt text to display in the search field.
    searchPrompt: String,

    // Tooltip to display on the clear search button.
    clearLabel: String,

    // Tooltip to display on the menu button.
    menuLabel: String,

    // Promotional toolstip string, shown in narrow mode if showMenuPromo is
    // true.
    menuPromo: String,

    // Value is proxied through to cr-toolbar-search-field. When true,
    // the search field will show a processing spinner.
    spinnerActive: Boolean,

    // Controls whether the menu button is shown at the start of the menu.
    showMenu: {type: Boolean, value: false},

    // Whether to show menu promo tooltip.
    showMenuPromo: {
      type: Boolean,
      value: false,
    },

    // Controls whether the search field is shown.
    showSearch: {type: Boolean, value: true},

    // True when the toolbar is displaying in narrow mode.
    narrow: {
      type: Boolean,
      reflectToAttribute: true,
      readonly: true,
      notify: true,
    },

    /**
     * The threshold at which the toolbar will change from normal to narrow
     * mode, in px.
     */
    narrowThreshold: {
      type: Number,
      value: 900,
    },

    closeMenuPromo: String,

    /** @private */
    showingSearch_: {
      type: Boolean,
      reflectToAttribute: true,
    },
  },

  observers: [
    'possiblyShowMenuPromo_(showMenu, showMenuPromo, showingSearch_)',
  ],

  /** @return {!CrToolbarSearchFieldElement} */
  getSearchField() {
    return /** @type {!CrToolbarSearchFieldElement} */ (this.$.search);
  },

  /** @private */
  onClosePromoTap_() {
    this.fire('cr-toolbar-menu-promo-close');
  },

  /** @private */
  onMenuTap_() {
    this.fire('cr-toolbar-menu-tap');
  },

  /** @private */
  possiblyShowMenuPromo_() {
    afterNextRender(this, function() {
      if (this.showMenu && this.showMenuPromo && !this.showingSearch_) {
        // The call to animate can have 2 methods of passing the keyframes,
        // however as of the current closure version, only one of them is
        // supported. See https://crbug.com/987842 for more info.
        this.$$('#menuPromo')
            .animate(
                [{opacity: 0}, {opacity: 0.9}],
                /** @type {!KeyframeAnimationOptions} */ ({
                  duration: 500,
                  fill: 'forwards'
                }));
        this.fire('cr-toolbar-menu-promo-shown');
      }
    }.bind(this));
  },

  /**
   * @param {string} title
   * @param {boolean} showMenuPromo
   * @return {string} The title if the menu promo isn't showing, else "".
   */
  titleIfNotShowMenuPromo_(title, showMenuPromo) {
    return showMenuPromo ? '' : title;
  },
});
