// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../hidden_style_css.m.js';
import '../shared_vars_css.m.js';
import {CrRadioButtonBehavior} from './cr_radio_button_behavior.m.js';
import './cr_radio_button_style_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-radio-button-style cr-hidden-style"></style>

    <div aria-checked$="[[getAriaChecked_(checked)]]"
        aria-describedby="slotted-content"
        aria-disabled$="[[getAriaDisabled_(disabled)]]"
        aria-labelledby="label"
        class="disc-wrapper"
        id="button"
        role="radio"
        tabindex$="[[buttonTabIndex_]]"
        on-keydown="onInputKeydown_">
      <div class="disc-border"></div>
      <div class="disc"></div>
    </div>

    <div id="labelWrapper">
      <span id="label" hidden$="[[!label]]" aria-hidden="true">[[label]]</span>
      <span id="slotted-content">
        <slot></slot>
      </span>
    </div>
<!--_html_template_end_-->`,
  is: 'cr-radio-button',

  behaviors: [
    CrRadioButtonBehavior,
  ],
});
