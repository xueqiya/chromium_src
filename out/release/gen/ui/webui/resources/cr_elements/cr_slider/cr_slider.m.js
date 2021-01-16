// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'cr-slider' is a slider component used to select a number from
 * a continuous or discrete range of numbers.
 */
import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {PaperRippleBehavior} from 'chrome://resources/polymer/v3_0/paper-behaviors/paper-ripple-behavior.js';
import '../../js/cr.m.js';
import {EventTracker} from '../../js/event_tracker.m.js';
import '../hidden_style_css.m.js';
import '../shared_vars_css.m.js';

  /**
   * The |value| is the corresponding value that the current slider tick is
   * associated with. The string |label| is shown in the UI as the label for the
   * current slider value. The |ariaValue| number is used for aria-valuemin,
   * aria-valuemax, and aria-valuenow, and is optional. If missing, |value| will
   * be used instead.
   * @typedef {{
   *   value: number,
   *   label: string,
   *   ariaValue: (number|undefined),
   * }}
   */
  export let SliderTick;

  /**
   * @param {number} min
   * @param {number} max
   * @param {number} value
   * @return {number}
   */
  function clamp(min, max, value) {
    return Math.min(max, Math.max(min, value));
  }

  /**
   * @param {!(SliderTick|number)} tick
   * @return {number}
   */
  function getAriaValue(tick) {
    if (Number.isFinite(/** @type {number} */ (tick))) {
      return /** @type {number} */ (tick);
    } else if (tick.ariaValue !== undefined) {
      return /** @type {number} */ (tick.ariaValue);
    } else {
      return tick.value;
    }
  }

  /**
   * The following are the events emitted from cr-slider.
   *
   * cr-slider-value-changed: fired when updating slider via the UI.
   * dragging-changed: fired on pointer down and on pointer up.
   */
  Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style">
      :host {
        --cr-slider-active-color: var(--google-blue-600);
        --cr-slider-container-color: rgba(var(--google-blue-600-rgb), .24);
        --cr-slider-container-disabled-color:
            rgba(var(--google-grey-600-rgb), .24);
        --cr-slider-disabled-color: var(--google-grey-600);
        --cr-slider-knob-color-rgb: var(--google-blue-600-rgb);
        --cr-slider-knob-disabled-color: white;
        --cr-slider-marker-active-color: rgba(255, 255, 255, .54);
        --cr-slider-marker-color: rgba(26, 115, 232, .54);
        --cr-slider-marker-disabled-color: rgba(128, 134, 139, .54);
        --cr-slider-position-transition: 80ms ease;
        --cr-slider-ripple-color: rgba(var(--cr-slider-knob-color-rgb), .25);

        -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
        cursor: default;
        height: 32px;
        outline: none;
        padding: 0 16px;
        user-select: none;
      }

      @media (prefers-color-scheme: dark) {
        :host {
          --cr-slider-active-color: var(--google-blue-refresh-300);
          --cr-slider-container-color:
              rgba(var(--google-blue-refresh-500-rgb), .48);
          --cr-slider-container-disabled-color:
              rgba(var(--google-grey-600-rgb), .48);
          /* --cr-slider-disabled-color is the same in dark mode (GG600). */
          --cr-slider-knob-color-rgb: var(--google-blue-refresh-300-rgb);
          --cr-slider-knob-disabled-color:
              var(--google-grey-900-white-4-percent);
          --cr-slider-marker-active-color: var(--google-blue-refresh-300);
          --cr-slider-marker-color: var(--google-blue-refresh-300);
          --cr-slider-marker-disabled-color: rgba(255, 255, 255, .54);
          --cr-slider-ripple-color: rgba(var(--cr-slider-knob-color-rgb), .4);
        }
      }

      :host([dragging]) {
        touch-action: none;
      }

      #container,
      #bar {
        /* Using border instead of background-color to address pixel rounding
           at low zoom levels (e.g. 33%). The browser will round border widths
           to a minimum of 1px.*/
        border-top-style: solid;
        border-top-width: 2px;
      }

      #container {
        border-top-color: var(--cr-slider-container-color);
        position: relative;
        top: 16px;
      }

      #container > div {
        position: absolute;
      }

      #markers,
      #bar {
        top: -2px;
      }

      #markers {
        display: flex;
        flex-direction: row;
        left: 0;
        pointer-events: none;
        right: 0;
      }

      .active-marker,
      .inactive-marker {
        flex: 1;
      }

      #markers::before,
      #markers::after,
      .active-marker::after,
      .inactive-marker::after {
        border-radius: 50%;
        content: '';
        display: block;
        height: 2px;
        margin-inline-start: -1px;
        width: 2px;
      }

      #markers::before,
      .active-marker::after {
        background-color: var(--cr-slider-marker-active-color);
      }

      #markers::after,
      .inactive-marker::after {
        background-color: var(--cr-slider-marker-color);
      }

      #bar {
        border-top-color: var(--cr-slider-active-color);
      }

      :host([transiting_]) #bar {
        transition: width var(--cr-slider-position-transition);
      }

      #knobAndLabel {
        top: -1px;
      }

      :host([transiting_]) #knobAndLabel {
        transition: margin-inline-start var(--cr-slider-position-transition);
      }

      #knob {
        background-color: rgb(var(--cr-slider-knob-color-rgb));
        border-radius: 50%;
        box-shadow: 0 1px 3px 0 rgba(0, 0, 0, .4);
        height: 10px;
        outline: none;
        transform: translate(-50%, -50%);
        width: 10px;
      }

      :host([is-rtl_]) #knob {
        transform: translate(50%, -50%);
      }

      #label {
        background: rgb(var(--cr-slider-knob-color-rgb));
        border-radius: .75em;
        bottom: 22px;
        color: white;  /* Same for dark and light mode. */
        font-size: 12px;
        line-height: 1.5em;
        opacity: 0;
        /* TODO(crbug.com/980856): Remove workaround after rendering bug is
         * fixed. */
        outline: 1px transparent solid;
        padding: 0 .67em;
        position: absolute;
        transform: translateX(-50%);
        transition: opacity 80ms ease-in-out;
        white-space: nowrap;
      }

      :host([is-rtl_]) #label {
        transform: translateX(50%);
      }

      :host(:hover) #label,
      :host([show-label_]) #label {
        opacity: 1;
      }

      paper-ripple {
        --paper-ripple-opacity: 1;  /* Opacity in each color's alpha. */
        color: var(--cr-slider-ripple-color);
        height: 32px;
        left: -11px;
        pointer-events: none;
        top: -11px;
        transition: color linear 80ms;
        width: 32px;
      }

      :host([is-rtl_]) paper-ripple {
        left: auto;
        right: -11px;
      }

      :host([disabled_]) {
        pointer-events: none;
      }

      :host([disabled_]) #container {
        border-top-color: var(--cr-slider-container-disabled-color);
      }

      :host([disabled_]) #bar {
        border-top-color: var(--cr-slider-disabled-color);
      }

      :host([disabled_]) .inactive-marker::after,
      :host([disabled_]) #markers::after {
        background-color: var(--cr-slider-marker-disabled-color);
      }

      :host([disabled_]) #knob {
        background-color: var(--cr-slider-disabled-color);
        border: 2px solid var(--cr-slider-knob-disabled-color);
        box-shadow: unset;
      }
    </style>
    <div id="container" hidden>
      <div id="bar"></div>
      <div id="markers" hidden$="[[!markerCount]]">
        <template is="dom-repeat" items="[[getMarkers_(markerCount)]]">
          <div class$="[[getMarkerClass_(index, value, min, max,
                                         markerCount)]]"></div>
        </template>
      </div>
      <div id="knobAndLabel" on-transitionend="onTransitionEnd_">
        <div id="knob"></div>
        <div id="label">[[label_]]</div>
      </div>
    </div>
<!--_html_template_end_-->`,
    is: 'cr-slider',

    behaviors: [
      PaperRippleBehavior,
    ],

    properties: {
      disabled: {
        type: Boolean,
        value: false,
      },

      /**
       * Internal representation of disabled depending on |disabled| and
       * |ticks|.
       * @private
       */
      disabled_: {
        type: Boolean,
        computed: 'computeDisabled_(disabled, ticks.*)',
        reflectToAttribute: true,
        observer: 'onDisabledChanged_',
      },

      dragging: {
        type: Boolean,
        value: false,
        notify: true,
        reflectToAttribute: true,
      },

      updatingFromKey: {
        type: Boolean,
        value: false,
        notify: true,
      },

      markerCount: {
        type: Number,
        value: 0,
      },

      max: {
        type: Number,
        value: 100,
      },

      min: {
        type: Number,
        value: 0,
      },

      /**
       * When set to false, the keybindings are not handled by this component,
       * for example when the owner of the component wants to set up its own
       * keybindings.
       */
      noKeybindings: {
        type: Boolean,
        value: false,
      },

      snaps: {
        type: Boolean,
        value: false,
      },

      /**
       * The data associated with each tick on the slider. Each element in the
       * array contains a value and the label corresponding to that value.
       * @type {!Array<SliderTick>|!Array<number>}
       */
      ticks: {
        type: Array,
        value: () => [],
      },

      value: Number,

      /** @private */
      label_: {
        type: String,
        value: '',
      },

      /** @private */
      showLabel_: {
        type: Boolean,
        value: false,
        reflectToAttribute: true,
      },

      /** @private */
      isRtl_: {
        type: Boolean,
        value: false,
        reflectToAttribute: true,
      },

      /**
       * |transiting_| is set to true when bar is touched or clicked. This
       * triggers a single position transition effect to take place for the
       * knob, bar and label. When the transition is complete, |transiting_| is
       * set to false resulting in no transition effect during dragging, manual
       * value updates and keyboard events.
       * @private
       */
      transiting_: {
        type: Boolean,
        value: false,
        reflectToAttribute: true,
      },
    },

    hostAttributes: {
      role: 'slider',
    },

    observers: [
      'onTicksChanged_(ticks.*)',
      'updateUi_(ticks.*, value, min, max)',
      'onValueMinMaxChange_(value, min, max)',
    ],

    listeners: {
      blur: 'hideRipple_',
      focus: 'showRipple_',
      keydown: 'onKeyDown_',
      keyup: 'onKeyUp_',
      pointerdown: 'onPointerDown_',
    },

    /** @private {Map<string, number>} */
    deltaKeyMap_: null,

    /** @private {EventTracker} */
    draggingEventTracker_: null,

    /** @override */
    attached() {
      this.isRtl_ = window.getComputedStyle(this)['direction'] === 'rtl';
      this.deltaKeyMap_ = new Map([
        ['ArrowDown', -1],
        ['ArrowUp', 1],
        ['PageDown', -1],
        ['PageUp', 1],
        ['ArrowLeft', this.isRtl_ ? 1 : -1],
        ['ArrowRight', this.isRtl_ ? -1 : 1],
      ]);
      this.draggingEventTracker_ = new EventTracker();
    },

    /**
     * @return {boolean}
     * @private
     */
    computeDisabled_() {
      return this.disabled || this.ticks.length === 1;
    },

    /**
     * When markers are displayed on the slider, they are evenly spaced across
     * the entire slider bar container and are rendered on top of the bar and
     * bar container. The location of the marks correspond to the discrete
     * values that the slider can have.
     * @return {!Array} The array items have no type since this is used to
     *     create |markerCount| number of markers.
     * @private
     */
    getMarkers_() {
      return new Array(Math.max(0, this.markerCount - 1));
    },

    /**
     * @param {number} index
     * @return {string}
     * @private
     */
    getMarkerClass_(index) {
      const currentStep = (this.markerCount - 1) * this.getRatio();
      return index < currentStep ? 'active-marker' : 'inactive-marker';
    },

    /**
     * The ratio is a value from 0 to 1.0 corresponding to a location along the
     * slider bar where 0 is the minimum value and 1.0 is the maximum value.
     * This is a helper function used to calculate the bar width, knob location
     * and label location.
     * @return {number}
     */
    getRatio() {
      return (this.value - this.min) / (this.max - this.min);
    },

    /**
     * Removes all event listeners related to dragging, and cancels ripple.
     * @param {number} pointerId
     * @private
     */
    stopDragging_(pointerId) {
      this.draggingEventTracker_.removeAll();
      this.releasePointerCapture(pointerId);
      this.dragging = false;
      this.hideRipple_();
    },

    /** @private */
    hideRipple_() {
      this.getRipple().clear();
      this.showLabel_ = false;
    },

    /** @private */
    showRipple_() {
      this.getRipple().showAndHoldDown();
      this.showLabel_ = true;
    },

    /** @private */
    onDisabledChanged_() {
      this.setAttribute('tabindex', this.disabled_ ? -1 : 0);
      this.blur();
    },

    /**
     * @param {!Event} event
     * @private
     */
    onKeyDown_(event) {
      if (this.disabled_ || this.noKeybindings) {
        return;
      }

      if (event.metaKey || event.shiftKey || event.altKey || event.ctrlKey) {
        return;
      }

      /** @type {number|undefined} */
      let newValue;
      if (event.key === 'Home') {
        newValue = this.min;
      } else if (event.key === 'End') {
        newValue = this.max;
      } else if (this.deltaKeyMap_.has(event.key)) {
        newValue = this.value + this.deltaKeyMap_.get(event.key);
      }

      if (newValue === undefined) {
        return;
      }

      this.updatingFromKey = true;
      if (this.updateValue_(newValue)) {
        this.fire('cr-slider-value-changed');
      }
      event.preventDefault();
      event.stopPropagation();
      this.showRipple_();
    },

    /**
     * @param {!Event} event
     * @private
     */
    onKeyUp_(event) {
      if (event.key === 'Home' || event.key === 'End' ||
          this.deltaKeyMap_.has(event.key)) {
        setTimeout(() => {
          this.updatingFromKey = false;
        });
      }
    },

    /**
     * When the left-mouse button is pressed, the knob location is updated and
     * dragging starts.
     * @param {!PointerEvent} event
     * @private
     */
    onPointerDown_(event) {
      if (this.disabled_ ||
          event.buttons !== 1 && event.pointerType === 'mouse') {
        return;
      }

      this.dragging = true;
      this.transiting_ = true;
      this.updateValueFromClientX_(event.clientX);
      this.showRipple_();

      this.setPointerCapture(event.pointerId);
      const stopDragging = this.stopDragging_.bind(this, event.pointerId);

      this.draggingEventTracker_.add(this, 'pointermove', e => {
        // Prevent unwanted text selection to occur while moving the pointer,
        // this is important.
        e.preventDefault();

        // If the left-button on the mouse is pressed by itself, then update.
        // Otherwise stop capturing the mouse events because the drag operation
        // is complete.
        if (e.buttons !== 1 && e.pointerType === 'mouse') {
          stopDragging();
          return;
        }
        this.updateValueFromClientX_(e.clientX);
      });
      this.draggingEventTracker_.add(this, 'pointercancel', stopDragging);
      this.draggingEventTracker_.add(this, 'pointerdown', stopDragging);
      this.draggingEventTracker_.add(this, 'pointerup', stopDragging);
      this.draggingEventTracker_.add(this, 'keydown', e => {
        if (e.key === 'Escape' || e.key === 'Tab' || e.key === 'Home' ||
            e.key === 'End' || this.deltaKeyMap_.has(e.key)) {
          stopDragging();
        }
      });
    },

    /** @private */
    onTicksChanged_() {
      if (this.ticks.length > 1) {
        this.snaps = true;
        this.max = this.ticks.length - 1;
        this.min = 0;
      }
      if (this.value !== undefined) {
        this.updateValue_(this.value);
      }
    },

    /** @private */
    onTransitionEnd_() {
      this.transiting_ = false;
    },

    /** @private */
    onValueMinMaxChange_() {
      if (this.value === undefined || this.min === undefined ||
          this.max === undefined) {
        return;
      }
      this.updateValue_(this.value);
    },

    /** @private */
    updateUi_() {
      const percent = `${this.getRatio() * 100}%`;
      this.$.bar.style.width = percent;
      this.$.knobAndLabel.style.marginInlineStart = percent;

      const ticks = this.ticks;
      const value = this.value;
      if (ticks && ticks.length > 0 && value >= 0 && value < ticks.length &&
          Number.isInteger(value)) {
        const tick = ticks[this.value];
        this.label_ = Number.isFinite(tick) ? '' : tick.label;
        const ariaValueNow = getAriaValue(tick);
        this.setAttribute('aria-valuetext', this.label_ || ariaValueNow);
        this.setAttribute('aria-valuenow', ariaValueNow);
        this.setAttribute('aria-valuemin', getAriaValue(ticks[0]));
        this.setAttribute('aria-valuemax', getAriaValue(ticks.slice(-1)[0]));
      } else {
        this.setAttribute('aria-valuetext', value);
        this.setAttribute('aria-valuenow', value);
        this.setAttribute('aria-valuemin', this.min);
        this.setAttribute('aria-valuemax', this.max);
      }
    },

    /**
     * @param {number} value
     * @return {boolean}
     * @private
     */
    updateValue_(value) {
      this.$.container.hidden = false;
      if (this.snaps) {
        // Skip update if |value| has not passed the next value .8 units away.
        // The value will update as the drag approaches the next value.
        if (Math.abs(this.value - value) < .8) {
          return false;
        }
        value = Math.round(value);
      }
      value = clamp(this.min, this.max, value);
      if (this.value === value) {
        return false;
      }
      this.value = value;
      return true;
    },

    /**
     * @param {number} clientX
     * @private
     */
    updateValueFromClientX_(clientX) {
      const rect = this.$.container.getBoundingClientRect();
      let ratio = (clientX - rect.left) / rect.width;
      if (this.isRtl_) {
        ratio = 1 - ratio;
      }
      if (this.updateValue_(ratio * (this.max - this.min) + this.min)) {
        this.fire('cr-slider-value-changed');
      }
    },

    _createRipple() {
      this._rippleContainer = this.$.knob;
      const ripple = PaperRippleBehavior._createRipple();
      ripple.id = 'ink';
      ripple.setAttribute('recenters', '');
      ripple.classList.add('circle', 'toggle-ink');
      return ripple;
    },
  });

