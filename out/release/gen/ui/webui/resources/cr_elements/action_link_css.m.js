import './shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

const template = document.createElement('template');
template.innerHTML = `
<dom-module id="action-link" assetpath="chrome://resources/">
  <template>
    <style>
      [is='action-link'] {
        cursor: pointer;
        display: inline-block;
        text-decoration: none;
      }

      [is='action-link'],
      [is='action-link']:active,
      [is='action-link']:hover,
      [is='action-link']:visited {
        color: var(--cr-link-color);
      }

      [is='action-link'][disabled] {
        color: var(--paper-grey-600);  /* TODO(dbeam): update for dark mode. */
        cursor: default;
        opacity: 0.65;
        pointer-events: none;
      }

      [is='action-link'].no-outline {
        outline: none;
      }
    </style>
  </template>
</dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));