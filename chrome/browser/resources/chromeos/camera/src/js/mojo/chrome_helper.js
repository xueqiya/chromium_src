// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * The singleton instance of ChromeHelper. Initialized by the first
 * invocation of getInstance().
 * @type {?ChromeHelper}
 */
let instance = null;

/**
 * Communicates with Chrome.
 */
export class ChromeHelper {
  /**
   * @public
   */
  constructor() {
    /**
     * An interface remote that is used to communicate with Chrome.
     * @type {!chromeosCamera.mojom.CameraAppHelperRemote}
     */
    this.remote_ = chromeosCamera.mojom.CameraAppHelper.getRemote(true);
  }

  /**
   * Checks if the device is under tablet mode currently.
   * @return {!Promise<boolean>}
   */
  async isTabletMode() {
    return await this.remote_.isTabletMode().then(({isTabletMode}) => {
      return isTabletMode;
    });
  }

  /**
   * Triggers the begin of event tracing in Chrome.
   * @param {string} event Name of the event.
   */
  startTracing(event) {
    this.remote_.startPerfEventTrace(event);
  }

  /**
   * Triggers the end of event tracing in Chrome.
   * @param {string} event Name of the event.
   */
  stopTracing(event) {
    this.remote_.stopPerfEventTrace(event);
  }

  /**
   * Checks return value from |handleCameraResult|.
   * @param {string} caller Caller identifier.
   * @param {Promise<{isSuccess: boolean}>|null} value
   * @return {!Promise}
   */
  async checkReturn_(caller, value) {
    const ret = await value;
    if (ret === null) {
      console.error(`Return null from calling intent ${caller}.`);
      return;
    }
    if (!ret.isSuccess) {
      console.error(`Return not isSuccess from calling intent ${caller}.`);
    }
  }

  /**
   * Notifies ARC++ to finish the intent.
   * @param {number} intentId Intent id of the intent to be finished.
   * @return {!Promise}
   */
  async finish(intentId) {
    const ret = this.remote_.handleCameraResult(
        intentId, arc.mojom.CameraIntentAction.FINISH, []);
    await this.checkReturn_('finish()', ret);
  }

  /**
   * Notifies ARC++ to cancel the intent.
   * @param {number} intentId Intent id of the intent to be canceled.
   * @return {!Promise}
   */
  async cancel(intentId) {
    const ret = this.remote_.handleCameraResult(
        intentId, arc.mojom.CameraIntentAction.CANCEL, []);
    await this.checkReturn_('cancel()', ret);
  }

  /**
   * Forces casting type from Uint8Array to !Array<number>.
   * @param {!Uint8Array} data
   * @return {!Array<number>}
   * @suppress {checkTypes}
   * @private
   */
  static castResultType_(data) {
    return data;
  }

  /**
   * Notifies ARC++ to append data to intent result.
   * @param {number} intentId Intent id of the intent to be appended data to.
   * @param {!Uint8Array} data The data to be appended to intent result.
   * @return {!Promise}
   */
  async appendData(intentId, data) {
    const ret = this.remote_.handleCameraResult(
        intentId, arc.mojom.CameraIntentAction.APPEND_DATA,
        this.constructor.castResultType_(data));
    await this.checkReturn_('appendData()', ret);
  }

  /**
   * Notifies ARC++ to clear appended intent result data.
   * @param {number} intentId Intent id of the intent to be cleared its result.
   * @return {!Promise}
   */
  async clearData(intentId) {
    const ret = this.remote_.handleCameraResult(
        intentId, arc.mojom.CameraIntentAction.CLEAR_DATA, []);
    await this.checkReturn_('clearData()', ret);
  }

  /**
   * Creates a new instance of ChromeHelper if it is not set. Returns the
   *     exist instance.
   * @return {!ChromeHelper} The singleton instance.
   */
  static getInstance() {
    if (instance === null) {
      instance = new ChromeHelper();
    }
    return instance;
  }
}
