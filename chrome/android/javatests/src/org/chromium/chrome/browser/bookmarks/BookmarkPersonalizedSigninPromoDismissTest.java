// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.bookmarks;

import static android.support.test.espresso.Espresso.onView;
import static android.support.test.espresso.action.ViewActions.click;
import static android.support.test.espresso.assertion.ViewAssertions.doesNotExist;
import static android.support.test.espresso.assertion.ViewAssertions.matches;
import static android.support.test.espresso.matcher.ViewMatchers.isDisplayed;
import static android.support.test.espresso.matcher.ViewMatchers.withEffectiveVisibility;
import static android.support.test.espresso.matcher.ViewMatchers.withId;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import android.support.test.InstrumentationRegistry;
import android.support.test.espresso.matcher.ViewMatchers;
import android.support.test.filters.MediumTest;

import org.junit.After;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

import org.chromium.base.test.util.CommandLineFlags;
import org.chromium.chrome.R;
import org.chromium.chrome.browser.ChromeSwitches;
import org.chromium.chrome.browser.ChromeTabbedActivity;
import org.chromium.chrome.browser.signin.IdentityServicesProvider;
import org.chromium.chrome.browser.signin.SigninPromoController;
import org.chromium.chrome.browser.sync.SyncTestRule;
import org.chromium.chrome.test.ChromeJUnit4ClassRunner;
import org.chromium.chrome.test.util.BookmarkTestUtil;
import org.chromium.chrome.test.util.ChromeTabUtils;
import org.chromium.components.signin.ChromeSigninController;
import org.chromium.components.signin.metrics.SigninAccessPoint;
import org.chromium.components.sync.AndroidSyncSettings;
import org.chromium.content_public.browser.test.util.TestThreadUtils;

/**
 * Tests different scenarios when the bookmark personalized signin promo is not shown.
 */
@RunWith(ChromeJUnit4ClassRunner.class)
@CommandLineFlags.Add({ChromeSwitches.DISABLE_FIRST_RUN_EXPERIENCE})
public class BookmarkPersonalizedSigninPromoDismissTest {
    @Rule
    public final SyncTestRule mSyncTestRule = new SyncTestRule();

    @Before
    public void setUp() throws Exception {
        BookmarkPromoHeader.forcePromoStateForTests(null);
        BookmarkPromoHeader.setPrefPersonalizedSigninPromoDeclinedForTests(false);
        SigninPromoController.setSigninPromoImpressionsCountBookmarksForTests(0);
        mSyncTestRule.startMainActivityForSyncTest();
    }

    @After
    public void tearDown() {
        SigninPromoController.setSigninPromoImpressionsCountBookmarksForTests(0);
        BookmarkPromoHeader.setPrefPersonalizedSigninPromoDeclinedForTests(false);
    }

    @Test
    @MediumTest
    public void testPromoNotShownAfterBeingDismissed() {
        BookmarkTestUtil.showBookmarkManager(mSyncTestRule.getActivity());
        checkPrePromoStatus();
        onView(withId(R.id.signin_promo_view_container)).check(matches(isDisplayed()));
        onView(withId(R.id.signin_promo_close_button)).perform(click());
        onView(withId(R.id.signin_promo_view_container))
                .check(matches(withEffectiveVisibility(ViewMatchers.Visibility.GONE)));

        closeBookmarkManager();
        BookmarkTestUtil.showBookmarkManager(mSyncTestRule.getActivity());
        onView(withId(R.id.signin_promo_view_container)).check(doesNotExist());
    }

    private void closeBookmarkManager() {
        if (mSyncTestRule.getActivity().isTablet()) {
            ChromeTabbedActivity chromeTabbedActivity =
                    (ChromeTabbedActivity) mSyncTestRule.getActivity();
            ChromeTabUtils.closeCurrentTab(
                    InstrumentationRegistry.getInstrumentation(), chromeTabbedActivity);
        } else {
            onView(withId(R.id.close_menu_id)).perform(click());
        }
    }

    @Test
    @MediumTest
    public void testPromoNotExistWhenImpressionLimitReached() {
        SigninPromoController.setSigninPromoImpressionsCountBookmarksForTests(
                SigninPromoController.getMaxImpressionsBookmarksForTests());
        BookmarkTestUtil.showBookmarkManager(mSyncTestRule.getActivity());
        onView(withId(R.id.signin_promo_view_container)).check(doesNotExist());
    }

    @Test
    @MediumTest
    public void testPromoImpressionCountIncrementAfterDisplayingSigninPromo() {
        assertEquals(0, SigninPromoController.getSigninPromoImpressionsCountBookmarks());
        checkPrePromoStatus();
        BookmarkTestUtil.showBookmarkManager(mSyncTestRule.getActivity());
        onView(withId(R.id.signin_promo_view_container)).check(matches(isDisplayed()));
        assertEquals(1, SigninPromoController.getSigninPromoImpressionsCountBookmarks());
    }

    /**
     * TODO(https://crbug.com/1045480): The promo dismiss tests are flaky
     * This method is for temporary investigation of the problem.
     * It should be removed after we fix the flakiness.
     */
    private void checkPrePromoStatus() {
        assertTrue("Android master sync should be enabled!",
                AndroidSyncSettings.get().isMasterSyncEnabled());
        assertFalse("The user should not be signed in!", ChromeSigninController.get().isSignedIn());
        TestThreadUtils.runOnUiThreadBlocking(() -> {
            assertTrue("Signin should be allowed!",
                    IdentityServicesProvider.get().getSigninManager().isSignInAllowed());
        });
        assertTrue("Impression limit should not be reached!",
                SigninPromoController.hasNotReachedImpressionLimit(
                        SigninAccessPoint.BOOKMARK_MANAGER));
        assertFalse("Signin promo should not be declined!",
                BookmarkPromoHeader.wasPersonalizedSigninPromoDeclined());
    }
}
