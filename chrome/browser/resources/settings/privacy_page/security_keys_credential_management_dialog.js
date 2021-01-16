// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-security-keys-credential-management-dialog' is a
 * dialog for viewing and erasing credentials stored on a security key.
 */

cr.define('settings', function() {
  /** @enum {string} */
  const CredentialManagementDialogPage = {
    INITIAL: 'initial',
    PIN_PROMPT: 'pinPrompt',
    CREDENTIALS: 'credentials',
    ERROR: 'error',
  };

  Polymer({
    is: 'settings-security-keys-credential-management-dialog',

    behaviors: [
      I18nBehavior,
      WebUIListenerBehavior,
    ],

    properties: {
      /**
       * The ID of the element currently shown in the dialog.
       * @private {!settings.CredentialManagementDialogPage}
       */
      dialogPage_: {
        type: String,
        value: CredentialManagementDialogPage.INITIAL,
        observer: 'dialogPageChanged_',
      },

      /**
       * The list of credentials displayed in the dialog.
       * @private {!Array<!settings.Credential>}
       */
      credentials_: Array,

      /**
       * The message displayed on the "error" dialog page.
       * @private
       */
      errorMsg_: String,

      /** @private */
      cancelButtonVisible_: Boolean,

      /** @private */
      confirmButtonVisible_: Boolean,

      /** @private */
      confirmButtonDisabled_: Boolean,

      /** @private */
      confirmButtonLabel_: String,

      /** @private */
      closeButtonVisible_: Boolean,

      /** @private */
      deleteInProgress_: Boolean,
    },

    /** @private {?settings.SecurityKeysCredentialBrowserProxy} */
    browserProxy_: null,

    /** @private {?Set<string>} */
    checkedCredentialIds_: null,

    /** @override */
    attached() {
      this.$.dialog.showModal();
      this.addWebUIListener(
          'security-keys-credential-management-finished',
          this.onError_.bind(this));
      this.checkedCredentialIds_ = new Set();
      this.browserProxy_ =
          settings.SecurityKeysCredentialBrowserProxyImpl.getInstance();
      this.browserProxy_.startCredentialManagement().then(() => {
        this.dialogPage_ = CredentialManagementDialogPage.PIN_PROMPT;
      });
    },

    /**
     * @private
     * @param {string} error
     */
    onError_(error) {
      this.errorMsg_ = error;
      this.dialogPage_ = CredentialManagementDialogPage.ERROR;
    },

    /** @private */
    submitPIN_() {
      // Disable the confirm button to prevent concurrent submissions.
      this.confirmButtonDisabled_ = true;

      this.$.pin.trySubmit(pin => this.browserProxy_.providePIN(pin))
          .then(
              () => {
                // Leave confirm button disabled while enumerating credentials.
                this.browserProxy_.enumerateCredentials().then(
                    this.onCredentials_.bind(this));
              },
              () => {
                // Wrong PIN.
                this.confirmButtonDisabled_ = false;
              });
    },

    /**
     * @private
     * @param {!Array<!settings.Credential>} credentials
     */
    onCredentials_(credentials) {
      if (!credentials.length) {
        this.onError_(
            this.i18n('securityKeysCredentialManagementNoCredentials'));
        return;
      }
      this.credentials_ = credentials;
      this.$.credentialList.fire('iron-resize');
      this.dialogPage_ = CredentialManagementDialogPage.CREDENTIALS;
    },

    /** @private */
    dialogPageChanged_() {
      switch (this.dialogPage_) {
        case CredentialManagementDialogPage.INITIAL:
          this.cancelButtonVisible_ = true;
          this.confirmButtonVisible_ = false;
          this.closeButtonVisible_ = false;
          break;
        case CredentialManagementDialogPage.PIN_PROMPT:
          this.cancelButtonVisible_ = true;
          this.confirmButtonLabel_ = this.i18n('continue');
          this.confirmButtonDisabled_ = false;
          this.confirmButtonVisible_ = true;
          this.closeButtonVisible_ = false;
          this.$.pin.focus();
          break;
        case CredentialManagementDialogPage.CREDENTIALS:
          this.cancelButtonVisible_ = true;
          this.confirmButtonLabel_ = this.i18n('delete');
          this.confirmButtonDisabled_ = true;
          this.confirmButtonVisible_ = true;
          this.closeButtonVisible_ = false;
          break;
        case CredentialManagementDialogPage.ERROR:
          this.cancelButtonVisible_ = false;
          this.confirmButtonVisible_ = false;
          this.closeButtonVisible_ = true;
          break;
        default:
          assertNotReached();
      }
      this.fire('credential-management-dialog-ready-for-testing');
    },

    /** @private */
    confirmButtonClick_() {
      switch (this.dialogPage_) {
        case CredentialManagementDialogPage.PIN_PROMPT:
          this.submitPIN_();
          break;
        case CredentialManagementDialogPage.CREDENTIALS:
          this.deleteSelectedCredentials_();
          break;
        default:
          assertNotReached();
      }
    },

    /** @private */
    close_() {
      this.$.dialog.close();
    },

    /**
     * Stringifies the user entity of a Credential for display in the dialog.
     * @private
     * @param {!settings.Credential} credential
     * @return {string}
     */
    formatUser_(credential) {
      if (this.isEmpty_(credential.userDisplayName)) {
        return credential.userName;
      }
      return `${credential.userDisplayName} (${credential.userName})`;
    },

    /** @private */
    onDialogClosed_() {
      this.browserProxy_.close();
    },

    /**
     * @private
     * @param {?string} str
     * @return {boolean} Whether this credential has been selected for removal.
     */
    isEmpty_(str) {
      return !str || str.length == 0;
    },

    /**
     * @param {!Event} e
     * @private
     */
    onIronSelect_(e) {
      // Prevent this event from bubbling since it is unnecessarily triggering
      // the listener within settings-animated-pages.
      e.stopPropagation();
    },

    /**
     * Handler for checking or unchecking a credential.
     * @param {!Event} e
     * @private
     */
    checkedCredentialsChanged_(e) {
      const credentialId = e.target.dataset.id;
      if (e.target.checked) {
        this.checkedCredentialIds_.add(credentialId);
      } else {
        this.checkedCredentialIds_.delete(credentialId);
      }
      this.confirmButtonDisabled_ = this.checkedCredentialIds_.size == 0;
    },

    /**
     * @private
     * @param {string} credentialId
     * @return {boolean} true if the checkbox for |credentialId| is checked
     */
    credentialIsChecked_(credentialId) {
      return this.checkedCredentialIds_.has(credentialId);
    },

    /** @private */
    deleteSelectedCredentials_() {
      assert(this.dialogPage_ == CredentialManagementDialogPage.CREDENTIALS);
      assert(this.credentials_ && this.credentials_.length > 0);
      assert(this.checkedCredentialIds_.size > 0);

      this.confirmButtonDisabled_ = true;
      this.deleteInProgress_ = true;
      this.browserProxy_
          .deleteCredentials(Array.from(this.checkedCredentialIds_))
          .then((err) => {
            this.confirmButtonDisabled_ = false;
            this.deleteInProgress_ = false;
            this.onError_(err);
          });
    },
  });

  // #cr_define_end
  return {
    CredentialManagementDialogPage: CredentialManagementDialogPage,
  };
});
