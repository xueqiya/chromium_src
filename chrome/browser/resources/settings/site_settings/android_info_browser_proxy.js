// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Type definition of AndroidAppsInfo entry. |playStoreEnabled| indicates that
 * Play Store is enabled. |settingsAppAvailable| indicates that Android settings
 * app is registered in the system.
 * @typedef {{
 *   playStoreEnabled: boolean,
 *   settingsAppAvailable: boolean,
 * }}
 * @see chrome/browser/ui/webui/settings/chromeos/android_apps_handler.cc
 */
let AndroidAppsInfo;

cr.define('settings', function() {
  /**
   * An object containing messages for web permissisions origin
   * and the messages multidevice feature state.
   *
   * @typedef {{origin: string,
   *            enabled: boolean}}
   */
  let AndroidSmsInfo;

  /** @interface */
  class AndroidInfoBrowserProxy {
    /**
     * Returns android messages info with messages feature state
     * and messages for web permissions origin.
     * @return {!Promise<!settings.AndroidSmsInfo>} Android SMS Info
     */
    getAndroidSmsInfo() {}

    requestAndroidAppsInfo() {}
  }

  /**
   * @implements {settings.AndroidInfoBrowserProxy}
   */
  class AndroidInfoBrowserProxyImpl {
    /** @override */
    getAndroidSmsInfo() {
      return cr.sendWithPromise('getAndroidSmsInfo');
    }

    /** @override */
    requestAndroidAppsInfo() {
      chrome.send('requestAndroidAppsInfo');
    }
  }

  cr.addSingletonGetter(AndroidInfoBrowserProxyImpl);

  // #cr_define_end
  return {
    AndroidInfoBrowserProxy: AndroidInfoBrowserProxy,
    AndroidInfoBrowserProxyImpl: AndroidInfoBrowserProxyImpl,
    AndroidSmsInfo: AndroidSmsInfo,
  };
});
