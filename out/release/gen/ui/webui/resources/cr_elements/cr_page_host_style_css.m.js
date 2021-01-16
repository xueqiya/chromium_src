import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import './shared_vars_css.m.js';
const template = document.createElement('template');
template.innerHTML = `
<dom-module id="cr-page-host-style" assetpath="chrome://resources/">
  <template>
    <style>
      :host {
        color: var(--cr-primary-text-color);
        line-height: 154%; /* Apply 20px default line-height to all text. */
        overflow: hidden; /* Prevent double scroll bar bugs. */
        user-select: text;
      }
    </style>
  </template>
</dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));