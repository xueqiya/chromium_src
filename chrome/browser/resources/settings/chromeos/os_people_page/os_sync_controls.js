// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

(function() {

/**
 * Names of the individual data type properties to be cached from
 * settings.OsSyncPrefs when the user checks 'Sync All'.
 * @type {!Array<string>}
 */
const SyncPrefsIndividualDataTypes = [
  'osAppsSynced',
  'osPreferencesSynced',
  'wifiConfigurationsSynced',

  // Note: Wallpaper uses a different naming scheme because it's stored as its
  // own separate pref instead of through the sync service.
  'wallpaperEnabled',
];

/**
 * @fileoverview
 * 'os-sync-controls' contains all OS sync data type controls.
 */
Polymer({
  is: 'os-sync-controls',

  behaviors: [
    settings.RouteObserverBehavior,
    WebUIListenerBehavior,
  ],

  properties: {
    hidden: {
      type: Boolean,
      value: true,
      computed: 'syncControlsHidden_(osSyncPrefs)',
      reflectToAttribute: true,
    },

    /**
     * Whether the OS sync feature is enabled. This object does not directly
     * manipulate prefs so we can defer turning on OS sync until the user
     * navigates away from the page.
     */
    osSyncFeatureEnabled: Boolean,

    /**
     * The current OS sync preferences. Cached so we can restore individual
     * toggle state when turning "sync everything" on and off, without affecting
     * the underlying chrome prefs.
     * @type {settings.OsSyncPrefs|undefined}
     */
    osSyncPrefs: Object,

    /** @private */
    areDataTypeTogglesDisabled_: {
      type: Boolean,
      value: true,
      computed: `computeDataTypeTogglesDisabled_(osSyncFeatureEnabled,
          osSyncPrefs.syncAllOsTypes)`,
    },
  },

  /** @private {?settings.OsSyncBrowserProxy} */
  browserProxy_: null,

  /**
   * Caches the individually selected synced data types. This is used to
   * be able to restore the selections after checking and unchecking Sync All.
   * @private {?Object}
   */
  cachedOsSyncPrefs_: null,

  /** @override */
  created() {
    this.browserProxy_ = settings.OsSyncBrowserProxyImpl.getInstance();
  },

  /** @override */
  attached() {
    this.addWebUIListener(
        'os-sync-prefs-changed', this.handleOsSyncPrefsChanged_.bind(this));
  },

  /**
   * settings.RouteObserverBehavior
   * @param {!settings.Route|undefined} newRoute
   * @param {!settings.Route|undefined} oldRoute
   * @protected
   */
  currentRouteChanged(newRoute, oldRoute) {
    if (newRoute == settings.routes.OS_SYNC) {
      this.browserProxy_.didNavigateToOsSyncPage();
    }
    if (oldRoute == settings.routes.OS_SYNC) {
      this.browserProxy_.didNavigateAwayFromOsSyncPage();
    }
  },

  /**
   * Handler for when the sync preferences are updated.
   * @private
   */
  handleOsSyncPrefsChanged_(osSyncFeatureEnabled, osSyncPrefs) {
    this.osSyncFeatureEnabled = osSyncFeatureEnabled;
    this.osSyncPrefs = osSyncPrefs;

    // If the feature is disabled the checkboxes appear toggled off, regardless
    // of the underlying chrome pref.
    if (!this.osSyncFeatureEnabled) {
      this.set('osSyncPrefs.syncAllOsTypes', false);
      for (const dataType of SyncPrefsIndividualDataTypes) {
        this.set(['osSyncPrefs', dataType], false);
      }
    }

    // If apps are not registered or synced, force wallpaper off.
    if (!this.osSyncPrefs.osAppsRegistered || !this.osSyncPrefs.osAppsSynced) {
      this.set('osSyncPrefs.wallpaperEnabled', false);
    }
  },

  /** @private */
  onTurnOnSyncButtonClick_() {
    this.browserProxy_.setOsSyncFeatureEnabled(true);
  },

  /** @private */
  onTurnOffSyncButtonClick_() {
    this.browserProxy_.setOsSyncFeatureEnabled(false);
  },

  /**
   * Handler for when the sync all data types checkbox is changed.
   * @param {!Event} event
   * @private
   */
  onSyncAllOsTypesChanged_(event) {
    if (event.target.checked) {
      this.set('osSyncPrefs.syncAllOsTypes', true);

      // Cache the previously selected preference before checking every box.
      this.cachedOsSyncPrefs_ = {};
      for (const dataType of SyncPrefsIndividualDataTypes) {
        // These are all booleans, so this shallow copy is sufficient.
        this.cachedOsSyncPrefs_[dataType] = this.osSyncPrefs[dataType];

        this.set(['osSyncPrefs', dataType], true);
      }
    } else if (this.cachedOsSyncPrefs_) {
      // Restore the previously selected preference.
      for (const dataType of SyncPrefsIndividualDataTypes) {
        this.set(['osSyncPrefs', dataType], this.cachedOsSyncPrefs_[dataType]);
      }
    }

    this.sendOsSyncDatatypes_();
  },

  /**
   * Handler for when any sync data type checkbox is changed.
   * @private
   */
  onSingleSyncDataTypeChanged_() {
    this.sendOsSyncDatatypes_();
  },

  /**
   * Handler for changes to the apps sync state; apps have a special handler
   * instead of relying on onSingleSyncDataTypeChanged_() because wallpaper has
   * a dependency on apps.
   * @private
   */
  onAppsSyncedChanged_() {
    this.set('osSyncPrefs.wallpaperEnabled', this.osSyncPrefs.osAppsSynced);

    this.onSingleSyncDataTypeChanged_();
  },

  /**
   * Sends the osSyncPrefs dictionary back to the C++ handler.
   * @private
   */
  sendOsSyncDatatypes_() {
    assert(this.osSyncPrefs);
    this.browserProxy_.setOsSyncDatatypes(this.osSyncPrefs);
  },

  /**
   * @return {boolean} Whether the sync data type toggles should be disabled.
   * @private
   */
  computeDataTypeTogglesDisabled_() {
    return !this.osSyncFeatureEnabled ||
        (this.osSyncPrefs !== undefined && this.osSyncPrefs.syncAllOsTypes);
  },

  /**
   * @return {boolean} Whether the sync controls are hidden.
   * @private
   */
  syncControlsHidden_() {
    // Hide everything until the initial prefs are received from C++,
    // otherwise there is a visible layout reshuffle on first load.
    return !this.osSyncPrefs;
  },

  /**
   * @return {boolean} Whether the wallpaper checkbox and label should be
   *     disabled.
   * @private
   */
  shouldWallpaperSyncSectionBeDisabled_() {
    return this.areDataTypeTogglesDisabled_ || !this.osSyncPrefs ||
        !this.osSyncPrefs.osAppsSynced;
  },
});
})();
