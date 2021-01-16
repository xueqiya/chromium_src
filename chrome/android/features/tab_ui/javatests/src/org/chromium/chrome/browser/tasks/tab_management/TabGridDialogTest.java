// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.tasks.tab_management;

import static android.support.test.espresso.Espresso.onView;
import static android.support.test.espresso.action.ViewActions.click;
import static android.support.test.espresso.assertion.ViewAssertions.doesNotExist;
import static android.support.test.espresso.assertion.ViewAssertions.matches;
import static android.support.test.espresso.intent.Intents.intended;
import static android.support.test.espresso.intent.matcher.BundleMatchers.hasEntry;
import static android.support.test.espresso.intent.matcher.IntentMatchers.hasAction;
import static android.support.test.espresso.intent.matcher.IntentMatchers.hasExtras;
import static android.support.test.espresso.intent.matcher.IntentMatchers.hasType;
import static android.support.test.espresso.matcher.RootMatchers.withDecorView;
import static android.support.test.espresso.matcher.ViewMatchers.isCompletelyDisplayed;
import static android.support.test.espresso.matcher.ViewMatchers.isDisplayed;
import static android.support.test.espresso.matcher.ViewMatchers.withId;
import static android.support.test.espresso.matcher.ViewMatchers.withParent;
import static android.support.test.espresso.matcher.ViewMatchers.withText;

import static org.hamcrest.Matchers.allOf;
import static org.hamcrest.Matchers.not;
import static org.hamcrest.core.IsEqual.equalTo;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.clickFirstCardFromTabSwitcher;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.clickFirstTabInDialog;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.closeFirstTabInDialog;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.createTabs;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.enterTabSwitcher;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.isShowingPopupTabList;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.mergeAllNormalTabsToAGroup;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.verifyShowingPopupTabList;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.verifyTabStripFaviconCount;
import static org.chromium.chrome.browser.tasks.tab_management.TabUiTestHelper.verifyTabSwitcherCardCount;

import android.content.Intent;
import android.graphics.Rect;
import android.support.test.espresso.Espresso;
import android.support.test.espresso.NoMatchingRootException;
import android.support.test.espresso.intent.Intents;
import android.support.test.espresso.intent.rule.IntentsTestRule;
import android.support.test.filters.MediumTest;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.TestRule;
import org.junit.runner.RunWith;

import org.chromium.base.test.util.CommandLineFlags;
import org.chromium.base.test.util.Restriction;
import org.chromium.chrome.browser.ChromeActivity;
import org.chromium.chrome.browser.ChromeSwitches;
import org.chromium.chrome.browser.ChromeTabbedActivity;
import org.chromium.chrome.browser.compositor.layouts.Layout;
import org.chromium.chrome.browser.flags.ChromeFeatureList;
import org.chromium.chrome.browser.flags.FeatureUtilities;
import org.chromium.chrome.features.start_surface.StartSurfaceLayout;
import org.chromium.chrome.tab_ui.R;
import org.chromium.chrome.test.ChromeJUnit4ClassRunner;
import org.chromium.chrome.test.ChromeTabbedActivityTestRule;
import org.chromium.chrome.test.util.browser.Features;
import org.chromium.content_public.browser.test.util.CriteriaHelper;
import org.chromium.content_public.browser.test.util.TestThreadUtils;
import org.chromium.ui.test.util.UiRestriction;

/** End-to-end tests for TabGridDialog component. */
@RunWith(ChromeJUnit4ClassRunner.class)
// clang-format off
@CommandLineFlags.Add({ChromeSwitches.DISABLE_FIRST_RUN_EXPERIENCE})
@Restriction(UiRestriction.RESTRICTION_TYPE_PHONE)
@Features.EnableFeatures({ChromeFeatureList.TAB_GROUPS_UI_IMPROVEMENTS_ANDROID})
public class TabGridDialogTest {
    // clang-format on

    private boolean mHasReceivedSourceRect;

    @Rule
    public ChromeTabbedActivityTestRule mActivityTestRule = new ChromeTabbedActivityTestRule();

    @Rule
    public TestRule mProcessor = new Features.InstrumentationProcessor();

    @Rule
    public IntentsTestRule<ChromeActivity> mShareActivityTestRule =
            new IntentsTestRule<>(ChromeActivity.class, false, false);

    @Before
    public void setUp() {
        FeatureUtilities.setGridTabSwitcherEnabledForTesting(true);
        FeatureUtilities.setTabGroupsAndroidEnabledForTesting(true);
        mActivityTestRule.startMainActivityFromLauncher();
        Layout layout = mActivityTestRule.getActivity().getLayoutManager().getOverviewLayout();
        assertTrue(layout instanceof StartSurfaceLayout);
        CriteriaHelper.pollUiThread(mActivityTestRule.getActivity()
                                            .getTabModelSelector()
                                            .getTabModelFilterProvider()
                                            .getCurrentTabModelFilter()::isTabModelRestored);
    }

    @After
    public void tearDown() {
        FeatureUtilities.setGridTabSwitcherEnabledForTesting(null);
        FeatureUtilities.setTabGroupsAndroidEnabledForTesting(null);
    }

    @Test
    @MediumTest
    public void testBackPressCloseDialog() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);
        // Open dialog from tab switcher and verify dialog is showing correct content.
        openDialogFromTabSwitcherAndVerify(cta, 2);

        // Press back and dialog should be hidden.
        Espresso.pressBack();
        CriteriaHelper.pollInstrumentationThread(() -> !isDialogShowing(cta));

        verifyTabSwitcherCardCount(cta, 1);

        // Enter first tab page.
        assertTrue(cta.getLayoutManager().overviewVisible());
        clickFirstCardFromTabSwitcher(cta);
        clickFirstTabInDialog(cta);
        // Open dialog from tab strip and verify dialog is showing correct content.
        openDialogFromStripAndVerify(cta, 2);

        // Press back and dialog should be hidden.
        Espresso.pressBack();
        CriteriaHelper.pollInstrumentationThread(() -> !isDialogShowing(cta));
    }

    @Test
    @MediumTest
    public void testDisableTabGroupsContinuation() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Open dialog and verify dialog is showing correct content.
        openDialogFromTabSwitcherAndVerify(cta, 2);

        // Verify TabGroupsContinuation related functionality is not exposed.
        verifyTabGroupsContinuation(cta, false);
    }

    @Test
    @MediumTest
    @Features.EnableFeatures(ChromeFeatureList.TAB_GROUPS_CONTINUATION_ANDROID)
    public void testEnableTabGroupsContinuation() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Open dialog and verify dialog is showing correct content.
        openDialogFromTabSwitcherAndVerify(cta, 2);

        // Verify TabGroupsContinuation related functionality is exposed.
        verifyTabGroupsContinuation(cta, true);
    }

    @Test
    @MediumTest
    public void testTabGridDialogAnimation() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Add 400px top margin to the recyclerView.
        RecyclerView recyclerView = cta.findViewById(R.id.tab_list_view);
        float tabGridCardPadding = cta.getResources().getDimension(R.dimen.tab_list_card_padding);
        int deltaTopMargin = 400;
        ViewGroup.MarginLayoutParams params =
                (ViewGroup.MarginLayoutParams) recyclerView.getLayoutParams();
        params.topMargin += deltaTopMargin;
        TestThreadUtils.runOnUiThreadBlocking(() -> { recyclerView.setLayoutParams(params); });
        CriteriaHelper.pollUiThread(() -> !recyclerView.isComputingLayout());

        // Calculate expected values of animation source rect.
        mHasReceivedSourceRect = false;
        View parentView = cta.getCompositorViewHolder();
        Rect parentRect = new Rect();
        parentView.getGlobalVisibleRect(parentRect);
        Rect sourceRect = new Rect();
        recyclerView.getChildAt(0).getGlobalVisibleRect(sourceRect);
        // TODO(yuezhanggg): Figure out why the sourceRect.left is wrong after setting the margin.
        float expectedTop = sourceRect.top - parentRect.top + tabGridCardPadding;
        float expectedWidth = sourceRect.width() - 2 * tabGridCardPadding;
        float expectedHeight = sourceRect.height() - 2 * tabGridCardPadding;

        // Setup the callback to verify the animation source Rect.
        StartSurfaceLayout layout = (StartSurfaceLayout) cta.getLayoutManager().getOverviewLayout();
        TabSwitcher.TabDialogDelegation delegation =
                layout.getStartSurfaceForTesting().getTabDialogDelegate();
        delegation.setSourceRectCallbackForTesting((result -> {
            mHasReceivedSourceRect = true;
            assertTrue(expectedTop == result.top);
            assertTrue(expectedHeight == result.height());
            assertTrue(expectedWidth == result.width());
        }));

        TabUiTestHelper.clickFirstCardFromTabSwitcher(cta);
        CriteriaHelper.pollUiThread(() -> mHasReceivedSourceRect);
        CriteriaHelper.pollInstrumentationThread(() -> isDialogShowing(cta));
    }

    @Test
    @MediumTest
    public void testUndoClosureInDialog_GTS() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Open dialog and verify dialog is showing correct content.
        openDialogFromTabSwitcherAndVerify(cta, 2);

        // Click close button to close the first tab in group.
        closeFirstTabInDialog(cta);
        verifyShowingDialog(cta, 1);

        // Exit dialog, wait for the undo bar showing and undo the closure.
        TabUiTestHelper.clickScrimToExitDialog(cta);
        CriteriaHelper.pollInstrumentationThread(() -> !isDialogShowing(cta));
        CriteriaHelper.pollInstrumentationThread(this::verifyUndoBarShowingAndClickUndo);

        // Verify the undo has happened.
        onView(withId(R.id.tab_title)).check((v, noMatchException) -> {
            TextView textView = (TextView) v;
            assertEquals("2 tabs", textView.getText().toString());
        });
        openDialogFromTabSwitcherAndVerify(cta, 2);
    }

    @Test
    @MediumTest
    public void testUndoClosureInDialog_TabStrip() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Enter first tab page.
        assertTrue(cta.getLayoutManager().overviewVisible());
        clickFirstCardFromTabSwitcher(cta);
        clickFirstTabInDialog(cta);

        // Open dialog from tab strip and verify dialog is showing correct content.
        openDialogFromStripAndVerify(cta, 2);

        // Click close button to close the first tab in group.
        closeFirstTabInDialog(cta);
        verifyShowingDialog(cta, 1);

        // Exit dialog, wait for the undo bar showing and undo the closure.
        TabUiTestHelper.clickScrimToExitDialog(cta);
        CriteriaHelper.pollInstrumentationThread(() -> !isDialogShowing(cta));
        CriteriaHelper.pollInstrumentationThread(this::verifyUndoBarShowingAndClickUndo);

        // Verify the undo has happened.
        verifyTabStripFaviconCount(cta, 2);
        openDialogFromStripAndVerify(cta, 2);
    }

    @Test
    @MediumTest
    @Features.EnableFeatures(ChromeFeatureList.TAB_GROUPS_CONTINUATION_ANDROID)
    public void testDialogToolbarMenuShareGroup() throws InterruptedException {
        final ChromeTabbedActivity cta = mActivityTestRule.getActivity();
        createTabs(cta, false, 2);
        enterTabSwitcher(cta);
        verifyTabSwitcherCardCount(cta, 2);

        // Create a tab group.
        mergeAllNormalTabsToAGroup(cta);
        verifyTabSwitcherCardCount(cta, 1);

        // Open dialog and verify dialog is showing correct content.
        openDialogFromTabSwitcherAndVerify(cta, 2);

        // Click to show the menu and verify it.
        openDialogToolbarMenuAndVerify(cta);

        // Trigger the share sheet by clicking the share button and verify it.
        triggerShareGroupAndVerify(cta);
    }

    private void openDialogFromTabSwitcherAndVerify(ChromeTabbedActivity cta, int tabCount) {
        clickFirstCardFromTabSwitcher(cta);
        CriteriaHelper.pollInstrumentationThread(() -> isDialogShowing(cta));
        verifyShowingDialog(cta, tabCount);
    }

    private void openDialogFromStripAndVerify(ChromeTabbedActivity cta, int tabCount) {
        showDialogFromStrip(cta);
        CriteriaHelper.pollInstrumentationThread(() -> isDialogShowing(cta));
        verifyShowingDialog(cta, tabCount);
    }

    private void verifyShowingDialog(ChromeTabbedActivity cta, int tabCount) {
        verifyShowingPopupTabList(cta, tabCount);

        onView(allOf(withParent(withId(R.id.main_content)), withId(R.id.title)))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .check((v, noMatchException) -> {
                    if (noMatchException != null) throw noMatchException;

                    Assert.assertTrue(v instanceof EditText);
                    EditText titleText = (EditText) v;
                    String title = cta.getResources().getQuantityString(
                            R.plurals.bottom_tab_grid_title_placeholder, tabCount, tabCount);
                    Assert.assertEquals(title, titleText.getText().toString());
                    assertFalse(v.isFocused());
                });
    }

    private boolean isDialogShowing(ChromeTabbedActivity cta) {
        return isShowingPopupTabList(cta);
    }

    private void showDialogFromStrip(ChromeTabbedActivity cta) {
        assertFalse(cta.getLayoutManager().overviewVisible());
        onView(withId(R.id.toolbar_left_button)).perform(click());
    }

    private void verifyTabGroupsContinuation(ChromeTabbedActivity cta, boolean isEnabled) {
        assertEquals(isEnabled, FeatureUtilities.isTabGroupsAndroidContinuationEnabled());

        // Verify whether the menu button exists.
        onView(withId(R.id.toolbar_menu_button))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .check(isEnabled ? matches(isDisplayed()) : doesNotExist());

        // Try to grab focus of the title text field by clicking on it.
        onView(allOf(withParent(withId(R.id.main_content)), withId(R.id.title)))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .perform(click());
        onView(allOf(withParent(withId(R.id.main_content)), withId(R.id.title)))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .check((v, noMatchException) -> {
                    if (noMatchException != null) throw noMatchException;

                    // Verify if we can grab focus on the editText or not.
                    assertEquals(isEnabled, v.isFocused());
                });
    }

    private boolean verifyUndoBarShowingAndClickUndo() {
        boolean isShowing = true;
        try {
            onView(withId(R.id.snackbar_button)).check(matches(isCompletelyDisplayed()));
            onView(withId(R.id.snackbar_button)).perform(click());
        } catch (NoMatchingRootException | AssertionError e) {
            isShowing = false;
        } catch (Exception e) {
            assert false : "error when verifying undo snack bar.";
        }
        return isShowing;
    }

    private void openDialogToolbarMenuAndVerify(ChromeTabbedActivity cta) {
        onView(withId(R.id.toolbar_menu_button))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .perform(click());
        onView(withId(R.id.tab_switcher_action_menu_list))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .check((v, noMatchException) -> {
                    if (noMatchException != null) throw noMatchException;
                    Assert.assertTrue(v instanceof ListView);
                    ListView listView = (ListView) v;
                    assertEquals(2, listView.getCount());
                    verifyTabGridDialogToolbarMenuItem(listView, 0,
                            cta.getString(R.string.tab_grid_dialog_toolbar_remove_from_group));
                    verifyTabGridDialogToolbarMenuItem(listView, 1,
                            cta.getString(R.string.tab_grid_dialog_toolbar_share_group));
                });
    }

    private void verifyTabGridDialogToolbarMenuItem(ListView listView, int index, String text) {
        View menuItemView = listView.getChildAt(index);
        TextView menuItemText = menuItemView.findViewById(R.id.menu_item);
        assertEquals(text, menuItemText.getText());
    }

    private void selectTabGridDialogToolbarMenuItem(ChromeTabbedActivity cta, String buttonText) {
        onView(withText(buttonText))
                .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                .perform(click());
    }

    private void triggerShareGroupAndVerify(ChromeTabbedActivity cta) {
        Intents.init();
        selectTabGridDialogToolbarMenuItem(cta, "Share group");
        // For K and below, we show share dialog; for L and above, we send intent and trigger system
        // share sheet. See ShareSheetMediator.ShareSheetDelegate for more info.
        if (TabUiTestHelper.isKitKatAndBelow()) {
            onView(withId(R.id.action_bar_root))
                    .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                    .check(matches(isDisplayed()));
            onView(withId(R.id.contentPanel))
                    .inRoot(withDecorView(not(cta.getWindow().getDecorView())))
                    .check(matches(isDisplayed()));
        } else {
            intended(allOf(hasAction(equalTo(Intent.ACTION_CHOOSER)),
                    hasExtras(hasEntry(equalTo(Intent.EXTRA_INTENT),
                            allOf(hasAction(equalTo(Intent.ACTION_SEND)),
                                    hasType("text/plain"))))));
        }
        Intents.release();
    }
}
