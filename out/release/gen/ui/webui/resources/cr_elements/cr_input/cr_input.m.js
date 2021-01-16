// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {assert} from '../../js/assert.m.js';
import {IronA11yAnnouncer} from 'chrome://resources/polymer/v3_0/iron-a11y-announcer/iron-a11y-announcer.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../hidden_style_css.m.js';
import '../shared_style_css.m.js';
import '../shared_vars_css.m.js';
import './cr_input_style_css.m.js';


/**
 * Input types supported by cr-input.
 * @type {!Set<string>}
 */
const SUPPORTED_INPUT_TYPES = new Set([
  'number',
  'password',
  'search',
  'text',
  'url',
]);

/**
 * @fileoverview 'cr-input' is a component similar to native input.
 *
 * Native input attributes that are currently supported by cr-inputs are:
 *   autofocus
 *   disabled
 *   max (only applicable when type="number")
 *   min (only applicable when type="number")
 *   maxlength
 *   minlength
 *   pattern
 *   placeholder
 *   readonly
 *   required
 *   tabindex
 *   type (see |SUPPORTED_INPUT_TYPES| above)
 *   value
 *
 * Additional attributes that you can use with cr-input:
 *   label
 *   auto-validate - triggers validation based on |pattern| and |required|,
 *                   whenever |value| changes.
 *   error-message - message displayed under the input when |invalid| is true.
 *   invalid
 *
 * You may pass an element into cr-input via [slot="suffix"] to be vertically
 * center-aligned with the input field, regardless of position of the label and
 * error-message. Example:
 *   <cr-input>
 *     <cr-button slot="suffix"></cr-button>
 *   </cr-input>
 */
Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style cr-input-style cr-shared-style">
      /*
        A 'suffix' element will be outside the underlined space, while a
        'prefix' element will be inside the underlined space by default.

        Regarding cr-input's width:
        When there's no element in the 'prefix' or 'suffix' slot, setting
        the width of cr-input as follows will work as expected:

          cr-input {
            width: 200px;
          }

        However, when there's an element in the 'suffix' and/or 'prefix'
        slot, setting the 'width' will dictate the total width of the input
        field *plus* the 'prefix' and 'suffix' elements. To set the width
        of the input field + 'prefix' when a 'suffix' is present, use
        --cr-input-width.

          cr-input {
            --cr-input-width: 200px;
          }
      */

      /* Disabled status should not impact suffix slot. */
      :host([disabled]) :-webkit-any(#label, #error, #input-container) {
        opacity: var(--cr-disabled-opacity);
        pointer-events: none;
      }

      /* Margin between <input> and <cr-button> in the 'suffix' slot */
      :host ::slotted(cr-button[slot=suffix]) {
        margin-inline-start: var(--cr-button-edge-spacing) !important;
      }

      :host([invalid]) #label {
        color: var(--cr-input-error-color);
      }

      #input {
        border-bottom: var(--cr-input-border-bottom, none);
      }

      #input::placeholder {
        color: var(--cr-input-placeholder-color);
        letter-spacing: var(--cr-input-placeholder-letter-spacing);
      }

      :host([invalid]) #input {
        caret-color: var(--cr-input-error-color);
      }

      :host([readonly]) #input {
        opacity: 0.6;
      }

      :host([invalid]) #underline {
        border-color: var(--cr-input-error-color);
      }

      /* Error styling below. */
      #error {
        /* Defaults to "display: block" and "visibility:hidden" to allocate
           space for error message, such that the page does not shift when
           error appears. For cr-inputs that can't be invalid, but are in a
           form with cr-inputs that can be invalid, this space is also desired
           in order to have consistent spacing.

           If spacing is not needed, apply "--cr-input-error-display: none". */
        color: var(--cr-input-error-color);
        display: var(--cr-input-error-display, block);
        font-size: var(--cr-form-field-label-font-size);
        height: var(--cr-form-field-label-height);
        line-height: var(--cr-form-field-label-line-height);
        margin: 8px 0;
        visibility: hidden;
      }

      :host([invalid]) #error {
        visibility: visible;
      }

      #row-container,
      #inner-input-container {
        align-items: center;
        display: flex;
        /* This will spread the input field and the suffix apart only if the
           host element width is intentionally set to something large. */
        justify-content: space-between;
        position: relative;
      }

      #input[type='search']::-webkit-search-cancel-button {
        -webkit-appearance: none;
      }

      :host-context([dir=rtl]) #input[type=url] {
        text-align: right;  /* csschecker-disable-line left-right */
      }

      #input[type=url] {
        direction: ltr;
      }
    </style>
    <div id="label" class="cr-form-field-label" hidden="[[!label]]"
        aria-hidden="true">
      [[label]]
    </div>
    <div id="row-container" part="row-container">
      <div id="input-container">
        <div id="inner-input-container">
          <slot name="prefix"></slot>
          <!-- Only attributes that are named inconsistently between html and js
              need to use attr$="", such as |tabindex| vs .tabIndex and
              |readonly| vs .readOnly. -->
          <input id="input" disabled="[[disabled]]" autofocus="[[autofocus]]"
              value="{{value::input}}" tabindex$="[[tabindex]]" type="[[type]]"
              readonly$="[[readonly]]" maxlength$="[[maxlength]]"
              pattern$="[[pattern]]" required="[[required]]"
              minlength$="[[minlength]]"
              aria-label$="[[getAriaLabel_(ariaLabel, label, placeholder)]]"
              aria-invalid$="[[getAriaInvalid_(invalid)]]"
              max="[[max]]" min="[[min]]" on-focus="onInputFocus_"
              on-blur="onInputBlur_" on-change="onInputChange_"
              on-keydown="onInputKeydown_" part="input">
        </div>
        <div id="underline"></div>
      </div>
      <slot name="suffix"></slot>
    </div>
    <!--
      Note: role="alert" is not working as expected because screen readers
      expect live regions to be in the DOM at time of document loading.
      cr-input will automatically fire iron-announce for the error message.
      Also aria-hidden="true" to avoid noise for screen reader users.
    -->
    <div id="error" aria-hidden="true">[[errorMessage]]</div>
<!--_html_template_end_-->`,
  is: 'cr-input',

  properties: {
    ariaLabel: {
      type: String,
      value: '',
    },

    autofocus: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    autoValidate: Boolean,

    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
      observer: 'disabledChanged_',
    },

    errorMessage: {
      type: String,
      value: '',
      observer: 'errorMessageChanged_',
    },

    /**
     * This is strictly used internally for styling, do not attempt to use
     * this to set focus.
     * @private
     */
    focused_: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    invalid: {
      type: Boolean,
      value: false,
      notify: true,
      reflectToAttribute: true,
    },

    max: {
      type: Number,
      reflectToAttribute: true,
    },

    min: {
      type: Number,
      reflectToAttribute: true,
    },

    maxlength: {
      type: Number,
      reflectToAttribute: true,
    },

    minlength: {
      type: Number,
      reflectToAttribute: true,
    },

    pattern: {
      type: String,
      reflectToAttribute: true,
    },

    label: {
      type: String,
      value: '',
    },

    placeholder: {
      type: String,
      value: null,
      observer: 'placeholderChanged_',
    },

    readonly: {
      type: Boolean,
      reflectToAttribute: true,
    },

    required: {
      type: Boolean,
      reflectToAttribute: true,
    },

    /** @type {?number} */
    tabindex: {
      type: Number,
      value: 0,
      reflectToAttribute: true,
    },

    type: {
      type: String,
      value: 'text',
      observer: 'onTypeChanged_',
    },

    value: {
      type: String,
      value: '',
      notify: true,
      observer: 'onValueChanged_',
    },
  },

  hostAttributes: {
    'aria-disabled': 'false',
  },

  listeners: {
    'focus': 'onFocus_',
    'pointerdown': 'onPointerDown_',
  },

  /** @private {?number} */
  originalTabIndex_: null,

  /** @override */
  attached() {
    // Run this for the first time in attached instead of in disabledChanged_
    // since this.tabindex might not be set yet then.
    if (this.disabled) {
      this.reconcileTabindex_();
    }
  },

  /** @private */
  onTypeChanged_() {
    // Check that the 'type' is one of the supported types.
    assert(SUPPORTED_INPUT_TYPES.has(this.type));
  },

  /** @return {!HTMLInputElement} */
  get inputElement() {
    return /** @type {!HTMLInputElement} */ (this.$.input);
  },

  /**
   * Returns the aria label to be used with the input element.
   * @return {string}
   * @private
   */
  getAriaLabel_(ariaLabel, label, placeholder) {
    return ariaLabel || label || placeholder;
  },

  /**
   * Returns 'true' or 'false' as a string for the aria-invalid attribute.
   * @return {string}
   * @private
   */
  getAriaInvalid_(invalid) {
    return invalid ? 'true' : 'false';
  },

  /** @private */
  disabledChanged_(current, previous) {
    this.setAttribute('aria-disabled', this.disabled ? 'true' : 'false');
    // In case input was focused when disabled changes.
    this.focused_ = false;

    // Don't change tabindex until after finished attaching, since this.tabindex
    // might not be intialized yet.
    if (previous !== undefined) {
      this.reconcileTabindex_();
    }
  },

  /**
   * Uses IronA11yAnnouncer to notify screen readers that an error is set.
   * @private
   */
  errorMessageChanged_() {
    IronA11yAnnouncer.requestAvailability();
    this.fire('iron-announce', {text: this.errorMessage});
  },

  /**
   * This helper function manipulates the tabindex based on disabled state. If
   * this element is disabled, this function will remember the tabindex and
   * unset it. If the element is enabled again, it will restore the tabindex
   * to it's previous value.
   * @private
   */
  reconcileTabindex_() {
    if (this.disabled) {
      this.recordAndUnsetTabIndex_();
    } else {
      this.restoreTabIndex_();
    }
  },

  /**
   * This is necessary instead of doing <input placeholder="[[placeholder]]">
   * because if this.placeholder is set to a truthy value then removed, it
   * would show "null" as placeholder.
   * @private
   */
  placeholderChanged_() {
    if (this.placeholder || this.placeholder === '') {
      this.inputElement.setAttribute('placeholder', this.placeholder);
    } else {
      this.inputElement.removeAttribute('placeholder');
    }
  },

  /** @private */
  onFocus_() {
    if (!this.focusInput()) {
      return;
    }
    // Always select the <input> element on focus. TODO(stevenjb/scottchen):
    // Native <input> elements only do this for keyboard focus, not when
    // focus() is called directly. Fix this? https://crbug.com/882612.
    this.inputElement.select();
  },

  /**
   * Focuses the input element.
   * TODO(crbug.com/882612): Replace this with focus() after resolving the text
   * selection issue described in onFocus_().
   * @return {boolean} Whether the <input> element was focused.
   */
  focusInput() {
    if (this.shadowRoot.activeElement === this.inputElement) {
      return false;
    }
    this.inputElement.focus();
    return true;
  },

  /** @private */
  recordAndUnsetTabIndex_() {
    // Don't change originalTabIndex_ if it just got changed.
    if (this.originalTabIndex_ === null) {
      this.originalTabIndex_ = this.tabindex;
    }

    this.tabindex = null;
  },

  /** @private */
  restoreTabIndex_() {
    this.tabindex = this.originalTabIndex_;
    this.originalTabIndex_ = null;
  },

  /**
   * Prevents clicking random spaces within cr-input but outside of <input>
   * from triggering focus.
   * @param {!Event} e
   * @private
   */
  onPointerDown_(e) {
    // Don't need to manipulate tabindex if cr-input is already disabled.
    if (this.disabled) {
      return;
    }

    // Should not mess with tabindex when <input> is clicked, otherwise <input>
    // will lose and regain focus, and replay the focus animation.
    if (e.path[0].tagName !== 'INPUT') {
      this.recordAndUnsetTabIndex_();
      setTimeout(() => {
        // Restore tabindex, unless disabled in the same cycle as pointerdown.
        if (!this.disabled) {
          this.restoreTabIndex_();
        }
      }, 0);
    }
  },

  /**
   * When shift-tab is pressed, first bring the focus to the host element.
   * This accomplishes 2 things:
   * 1) Host doesn't get focused when the browser moves the focus backward.
   * 2) focus now escaped the shadow-dom of this element, so that it'll
   *    correctly obey non-zero tabindex ordering of the containing document.
   * @private
   */
  onInputKeydown_(e) {
    if (e.shiftKey && e.key === 'Tab') {
      this.focus();
    }
  },

  /**
   * @param {string} newValue
   * @param {string} oldValue
   * @private
   */
  onValueChanged_(newValue, oldValue) {
    if (!newValue && !oldValue) {
      return;
    }
    if (this.autoValidate) {
      this.validate();
    }
  },

  /**
   * 'change' event fires when <input> value changes and user presses 'Enter'.
   * This function helps propagate it to host since change events don't
   * propagate across Shadow DOM boundary by default.
   * @param {!Event} e
   * @private
   */
  onInputChange_(e) {
    this.fire('change', {sourceEvent: e});
  },

  /** @private */
  onInputFocus_() {
    this.focused_ = true;
  },

  /** @private */
  onInputBlur_() {
    this.focused_ = false;
  },

  /**
   * Selects the text within the input. If no parameters are passed, it will
   * select the entire string. Either no params or both params should be passed.
   * Publicly, this function should be used instead of inputElement.select() or
   * manipulating inputElement.selectionStart/selectionEnd because the order of
   * execution between focus() and select() is sensitive.
   * @param {number=} start
   * @param {number=} end
   */
  select(start, end) {
    this.focusInput();
    if (start !== undefined && end !== undefined) {
      this.inputElement.setSelectionRange(start, end);
    } else {
      // Can't just pass one param.
      assert(start === undefined && end === undefined);
      this.inputElement.select();
    }
  },

  /** @return {boolean} */
  validate() {
    this.invalid = !this.inputElement.checkValidity();
    return !this.invalid;
  },
});
