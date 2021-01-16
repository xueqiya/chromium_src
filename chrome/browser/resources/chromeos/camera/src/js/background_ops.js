// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// eslint-disable-next-line no-unused-vars
import {Intent} from './intent.js';
// eslint-disable-next-line no-unused-vars
import {PerfLogger} from './perf.js';

/**
 * Operations supported by foreground window.
 * @interface
 */
export class ForegroundOps {
  /**
   * Suspend foreground window.
   * @return {!Promise}
   * @abstract
   */
  async suspend() {}

  /**
   * Resume foreground window.
   * @abstract
   */
  resume() {}
}

/**
 * Operations supported by background window.
 * @interface
 */
export class BackgroundOps {
  /**
   * Sets the implementation of ForegroundOps from foreground window.
   * @param {!ForegroundOps} ops
   */
  bindForegroundOps(ops) {}

  /**
   * Gets intent associate with CCA Window object.
   * @return {?Intent}
   * @abstract
   */
  getIntent() {}

  /**
   * Gets the perf logger associate with CCA Window object.
   * @return {!PerfLogger}
   * @abstract
   */
  getPerfLogger() {}

  /**
   * Called by foreground window when it's active.
   * @abstract
   */
  notifyActivation() {}

  /**
   * Called by foreground window when it's suspended.
   * @abstract
   */
  notifySuspension() {}
}
