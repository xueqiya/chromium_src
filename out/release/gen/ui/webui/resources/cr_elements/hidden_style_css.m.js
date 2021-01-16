import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
const template = document.createElement('template');
template.innerHTML = `
<dom-module id="cr-hidden-style" assetpath="chrome://resources/">
  <template>
    <style>
      /* Included here so we don't have to include "iron-positioning" in every
       * stylesheet. See crbug.com/498405. */
      [hidden],
      :host([hidden]) {
        display: none !important;
      }
    </style>
  </template>
</dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));