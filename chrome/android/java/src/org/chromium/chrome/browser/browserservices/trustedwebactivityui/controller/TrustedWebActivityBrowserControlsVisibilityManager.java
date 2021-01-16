// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.browserservices.trustedwebactivityui.controller;

import androidx.annotation.Nullable;
import androidx.annotation.VisibleForTesting;

import org.chromium.chrome.browser.browserservices.BrowserServicesIntentDataProvider;
import org.chromium.chrome.browser.customtabs.CloseButtonVisibilityManager;
import org.chromium.chrome.browser.customtabs.content.CustomTabActivityTabProvider;
import org.chromium.chrome.browser.customtabs.content.TabObserverRegistrar;
import org.chromium.chrome.browser.customtabs.content.TabObserverRegistrar.CustomTabTabObserver;
import org.chromium.chrome.browser.customtabs.features.toolbar.CustomTabToolbarCoordinator;
import org.chromium.chrome.browser.dependency_injection.ActivityScope;
import org.chromium.chrome.browser.ssl.SecurityStateModel;
import org.chromium.chrome.browser.tab.Tab;
import org.chromium.chrome.browser.webapps.WebDisplayMode;
import org.chromium.chrome.browser.webapps.WebappExtras;
import org.chromium.components.security_state.ConnectionSecurityLevel;
import org.chromium.content_public.common.BrowserControlsState;

import javax.inject.Inject;

/**
 * Updates the browser controls state based on whether the browser is in TWA mode and the page's
 * security level.
 */
@ActivityScope
public class TrustedWebActivityBrowserControlsVisibilityManager {
    static final @BrowserControlsState int DEFAULT_BROWSER_CONTROLS_STATE =
            BrowserControlsState.BOTH;

    private final TabObserverRegistrar mTabObserverRegistrar;
    private final CustomTabActivityTabProvider mTabProvider;
    private final CustomTabToolbarCoordinator mToolbarCoordinator;
    private final CloseButtonVisibilityManager mCloseButtonVisibilityManager;

    private boolean mInTwaMode;
    private boolean mShowBrowserControlsInTwaMode;
    private boolean mShowBrowserControlsForChildTab;

    private @BrowserControlsState int mBrowserControlsState = DEFAULT_BROWSER_CONTROLS_STATE;

    private final CustomTabTabObserver mTabObserver = new CustomTabTabObserver() {
        @Override
        public void onSSLStateUpdated(Tab tab) {
            updateBrowserControlsState();
            updateCloseButtonVisibility();
        }

        @Override
        public void onObservingDifferentTab(@Nullable Tab tab) {
            updateBrowserControlsState();
            updateCloseButtonVisibility();
        }
    };

    @Inject
    public TrustedWebActivityBrowserControlsVisibilityManager(
            TabObserverRegistrar tabObserverRegistrar, CustomTabActivityTabProvider tabProvider,
            CustomTabToolbarCoordinator toolbarCoordinator,
            CloseButtonVisibilityManager closeButtonVisibilityManager,
            BrowserServicesIntentDataProvider intentDataProvider) {
        mTabObserverRegistrar = tabObserverRegistrar;
        mTabProvider = tabProvider;
        mToolbarCoordinator = toolbarCoordinator;
        mCloseButtonVisibilityManager = closeButtonVisibilityManager;

        WebappExtras webappExtras = intentDataProvider.getWebappExtras();
        mShowBrowserControlsForChildTab = (webappExtras != null);
        mShowBrowserControlsInTwaMode =
                (webappExtras != null && webappExtras.displayMode == WebDisplayMode.MINIMAL_UI);
    }

    /**
     * Should be called when the browser enters and exits TWA mode.
     */
    public void updateIsInTwaMode(boolean inTwaMode) {
        if (mInTwaMode == inTwaMode) return;

        mInTwaMode = inTwaMode;

        updateBrowserControlsState();
        updateCloseButtonVisibility();

        if (mInTwaMode) {
            mTabObserverRegistrar.registerActivityTabObserver(mTabObserver);
        } else {
            mTabObserverRegistrar.unregisterActivityTabObserver(mTabObserver);
        }
    }

    private void updateBrowserControlsState() {
        @BrowserControlsState
        int newBrowserControlsState = computeBrowserControlsState(mTabProvider.getTab());
        if (mBrowserControlsState == newBrowserControlsState) return;

        mBrowserControlsState = newBrowserControlsState;
        mToolbarCoordinator.setBrowserControlsState(mBrowserControlsState);

        if (mBrowserControlsState == BrowserControlsState.BOTH) {
            // Force showing the controls for a bit when leaving Trusted Web Activity
            // mode.
            mToolbarCoordinator.showToolbarTemporarily();
        }
    }

    private void updateCloseButtonVisibility() {
        // Show close button if toolbar is not visible, so that during the in and off-scope
        // transitions we avoid button flickering when toolbar is appearing/disappearing.
        boolean closeButtonVisibility =
                shouldShowBrowserControlsAndCloseButton(mTabProvider.getTab())
                || (mBrowserControlsState == BrowserControlsState.HIDDEN);

        mCloseButtonVisibilityManager.setVisibility(closeButtonVisibility);
    }

    private boolean shouldShowBrowserControlsAndCloseButton(@Nullable Tab tab) {
        return !mInTwaMode || (isChildTab(tab) && mShowBrowserControlsForChildTab);
    }

    private @BrowserControlsState int computeBrowserControlsState(@Nullable Tab tab) {
        // Force browser controls to show when the security level is dangerous for consistency with
        // TabStateBrowserControlsVisibilityDelegate.
        if (tab != null && getSecurityLevel(tab) == ConnectionSecurityLevel.DANGEROUS) {
            return BrowserControlsState.SHOWN;
        }

        if (mInTwaMode && mShowBrowserControlsInTwaMode) {
            return BrowserControlsState.BOTH;
        }

        return shouldShowBrowserControlsAndCloseButton(tab) ? BrowserControlsState.BOTH
                                                            : BrowserControlsState.HIDDEN;
    }

    private boolean isChildTab(@Nullable Tab tab) {
        return tab != null && tab.getParentId() != Tab.INVALID_TAB_ID;
    }

    @ConnectionSecurityLevel
    @VisibleForTesting
    int getSecurityLevel(Tab tab) {
        return SecurityStateModel.getSecurityLevelForWebContents(tab.getWebContents());
    }
}
