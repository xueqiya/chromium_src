import 'chrome://resources/cr_elements/shared_style_css.m.js';
const template = document.createElement('template');
template.innerHTML = `
<dom-module id="certificate-shared" assetpath="chrome://resources/">
  <template>
    <style include="cr-shared-style">
      /* .list-frame and .list-item match the styling in settings_shared_css. */
      .list-frame {
        align-items: center;
        display: block;
        padding-inline-end: 20px;
        padding-inline-start: 60px;
      }

      .list-item {
        align-items: center;
        display: flex;
        min-height: 48px;
      }

      .list-item.underbar {
        border-bottom: var(--cr-separator-line);
      }

      .list-item.selected {
        font-weight: 500;
      }

      .list-item > .start {
        flex: 1;
      }
    </style>
  </template>
</dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));