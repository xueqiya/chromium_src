// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.tasks.tab_management;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Rect;
import android.graphics.RectF;
import android.support.v7.widget.RecyclerView.ViewHolder;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.VisibleForTesting;

import org.chromium.base.Callback;
import org.chromium.base.metrics.RecordUserAction;
import org.chromium.base.supplier.ObservableSupplier;
import org.chromium.chrome.browser.ChromeTabbedActivity;
import org.chromium.chrome.browser.MenuOrKeyboardActionController;
import org.chromium.chrome.browser.compositor.layouts.content.TabContentManager;
import org.chromium.chrome.browser.flags.ChromeFeatureList;
import org.chromium.chrome.browser.flags.FeatureUtilities;
import org.chromium.chrome.browser.fullscreen.ChromeFullscreenManager;
import org.chromium.chrome.browser.lifecycle.ActivityLifecycleDispatcher;
import org.chromium.chrome.browser.lifecycle.Destroyable;
import org.chromium.chrome.browser.share.ShareDelegate;
import org.chromium.chrome.browser.tab.Tab;
import org.chromium.chrome.browser.tabmodel.TabCreatorManager;
import org.chromium.chrome.browser.tabmodel.TabList;
import org.chromium.chrome.browser.tabmodel.TabModelSelector;
import org.chromium.chrome.browser.tasks.pseudotab.TabAttributeCache;
import org.chromium.chrome.browser.tasks.tab_management.suggestions.TabSuggestionsOrchestrator;
import org.chromium.chrome.browser.ui.messages.snackbar.SnackbarManager;
import org.chromium.chrome.tab_ui.R;
import org.chromium.ui.modelutil.PropertyModel;
import org.chromium.ui.modelutil.PropertyModelChangeProcessor;
import org.chromium.ui.resources.dynamics.DynamicResourceLoader;

import java.util.ArrayList;
import java.util.List;

/**
 * Parent coordinator that is responsible for showing a grid or carousel of tabs for the main
 * TabSwitcher UI.
 */
public class TabSwitcherCoordinator
        implements Destroyable, TabSwitcher, TabSwitcher.TabListDelegate,
                   TabSwitcher.TabDialogDelegation, TabSwitcherMediator.ResetHandler {
    // TODO(crbug.com/982018): Rename 'COMPONENT_NAME' so as to add different metrics for carousel
    // tab switcher.
    static final String COMPONENT_NAME = "GridTabSwitcher";
    private static boolean sAppendedMessagesForTesting;
    private final PropertyModelChangeProcessor mContainerViewChangeProcessor;
    private final ActivityLifecycleDispatcher mLifecycleDispatcher;
    private final MenuOrKeyboardActionController mMenuOrKeyboardActionController;
    private final TabListCoordinator mTabListCoordinator;
    private final TabSwitcherMediator mMediator;
    private final MultiThumbnailCardProvider mMultiThumbnailCardProvider;
    private final TabGridDialogCoordinator mTabGridDialogCoordinator;
    private final TabSelectionEditorCoordinator mTabSelectionEditorCoordinator;
    private final UndoGroupSnackbarController mUndoGroupSnackbarController;
    private final TabModelSelector mTabModelSelector;
    private final @TabListCoordinator.TabListMode int mMode;
    private final MessageCardProviderCoordinator mMessageCardProviderCoordinator;
    private TabSuggestionsOrchestrator mTabSuggestionsOrchestrator;
    private NewTabTileCoordinator mNewTabTileCoordinator;
    private TabAttributeCache mTabAttributeCache;

    private final MenuOrKeyboardActionController
            .MenuOrKeyboardActionHandler mTabSwitcherMenuActionHandler =
            new MenuOrKeyboardActionController.MenuOrKeyboardActionHandler() {
                @Override
                public boolean handleMenuOrKeyboardAction(int id, boolean fromMenu) {
                    if (id == R.id.menu_group_tabs) {
                        mTabSelectionEditorCoordinator.getController().show(
                                mTabModelSelector.getTabModelFilterProvider()
                                        .getCurrentTabModelFilter()
                                        .getTabsWithNoOtherRelatedTabs());
                        RecordUserAction.record("MobileMenuGroupTabs");
                        return true;
                    }
                    return false;
                }
            };
    private TabGridIphItemCoordinator mTabGridIphItemCoordinator;

    public TabSwitcherCoordinator(Context context, ActivityLifecycleDispatcher lifecycleDispatcher,
            TabModelSelector tabModelSelector, TabContentManager tabContentManager,
            DynamicResourceLoader dynamicResourceLoader, ChromeFullscreenManager fullscreenManager,
            TabCreatorManager tabCreatorManager,
            MenuOrKeyboardActionController menuOrKeyboardActionController,
            SnackbarManager.SnackbarManageable snackbarManageable, ViewGroup container,
            ObservableSupplier<ShareDelegate> shareDelegateSupplier,
            @TabListCoordinator.TabListMode int mode) {
        mMode = mode;
        mTabModelSelector = tabModelSelector;

        PropertyModel containerViewModel = new PropertyModel(TabListContainerProperties.ALL_KEYS);

        mTabSelectionEditorCoordinator = new TabSelectionEditorCoordinator(
                context, container, tabModelSelector, tabContentManager, null);

        mMediator = new TabSwitcherMediator(this, containerViewModel, tabModelSelector,
                fullscreenManager, container, mTabSelectionEditorCoordinator.getController(),
                tabContentManager, mode);

        mMultiThumbnailCardProvider =
                new MultiThumbnailCardProvider(context, tabContentManager, tabModelSelector);

        TabListMediator.TitleProvider titleProvider = tab -> {
            int numRelatedTabs = tabModelSelector.getTabModelFilterProvider()
                                         .getCurrentTabModelFilter()
                                         .getRelatedTabList(tab.getId())
                                         .size();
            if (numRelatedTabs == 1) return tab.getTitle();
            return context.getResources().getQuantityString(
                    R.plurals.bottom_tab_grid_title_placeholder, numRelatedTabs, numRelatedTabs);
        };

        mTabListCoordinator =
                new TabListCoordinator(mode, context, tabModelSelector, mMultiThumbnailCardProvider,
                        titleProvider, true, mMediator::getCreateGroupButtonOnClickListener,
                        mMediator, null, TabProperties.UiType.CLOSABLE, null, container,
                        dynamicResourceLoader, true, COMPONENT_NAME);
        mContainerViewChangeProcessor = PropertyModelChangeProcessor.create(containerViewModel,
                mTabListCoordinator.getContainerView(), TabListContainerViewBinder::bind);

        mMessageCardProviderCoordinator = new MessageCardProviderCoordinator(context,
                (identifier)
                        -> mTabListCoordinator.removeSpecialListItem(
                                TabProperties.UiType.MESSAGE, identifier));

        if (FeatureUtilities.isTabGroupsAndroidUiImprovementsEnabled()) {
            mTabGridDialogCoordinator = new TabGridDialogCoordinator(context, tabModelSelector,
                    tabContentManager, tabCreatorManager,
                    ((ChromeTabbedActivity) context).getCompositorViewHolder(), this, mMediator,
                    this::getTabGridDialogAnimationSourceView,
                    mTabListCoordinator.getTabGroupTitleEditor(), shareDelegateSupplier);

            mUndoGroupSnackbarController =
                    new UndoGroupSnackbarController(context, tabModelSelector, snackbarManageable);

            mMediator.setTabGridDialogController(mTabGridDialogCoordinator.getDialogController());
        } else {
            mTabGridDialogCoordinator = null;
            mUndoGroupSnackbarController = null;
        }

        if (FeatureUtilities.isTabGroupsAndroidUiImprovementsEnabled()
                && mode == TabListCoordinator.TabListMode.GRID
                && !TabSwitcherMediator.isShowingTabsInMRUOrder()) {
            mTabGridIphItemCoordinator = new TabGridIphItemCoordinator(
                    context, mTabListCoordinator.getContainerView(), container);
            mMediator.setIphProvider(mTabGridIphItemCoordinator.getIphProvider());
        }

        if (mode == TabListCoordinator.TabListMode.GRID) {
            if (ChromeFeatureList.isEnabled(ChromeFeatureList.CLOSE_TAB_SUGGESTIONS)) {
                mTabListCoordinator.registerItemType(TabProperties.UiType.MESSAGE, () -> {
                    return (ViewGroup) LayoutInflater.from(context).inflate(
                            R.layout.tab_grid_message_card_item, container, false);
                }, MessageCardViewBinder::bind);

                mTabSuggestionsOrchestrator =
                        new TabSuggestionsOrchestrator(mTabModelSelector, lifecycleDispatcher);
                TabSuggestionMessageService tabSuggestionMessageService =
                        new TabSuggestionMessageService(context, tabModelSelector,
                                mTabSelectionEditorCoordinator.getController());
                mTabSuggestionsOrchestrator.addObserver(tabSuggestionMessageService);
                mMessageCardProviderCoordinator.subscribeMessageService(
                        tabSuggestionMessageService);
            }

            if (ChromeFeatureList
                            .getFieldTrialParamByFeature(ChromeFeatureList.TAB_GRID_LAYOUT_ANDROID,
                                    "tab_grid_layout_android_new_tab_tile")
                            .equals("NewTabTile")) {
                mNewTabTileCoordinator =
                        new NewTabTileCoordinator(tabModelSelector, tabCreatorManager);
                mTabListCoordinator.registerItemType(TabProperties.UiType.NEW_TAB_TILE, () -> {
                    return (ViewGroup) LayoutInflater.from(context).inflate(
                            R.layout.new_tab_tile_card_item, container, false);
                }, NewTabTileViewBinder::bind);
            }
        }

        if (TabUiFeatureUtilities.isSearchTermChipEnabled()
                && mode != TabListCoordinator.TabListMode.CAROUSEL) {
            mTabAttributeCache = new TabAttributeCache(mTabModelSelector);
        }

        mMenuOrKeyboardActionController = menuOrKeyboardActionController;
        mMenuOrKeyboardActionController.registerMenuOrKeyboardActionHandler(
                mTabSwitcherMenuActionHandler);

        mLifecycleDispatcher = lifecycleDispatcher;
        mLifecycleDispatcher.register(this);
    }

    @VisibleForTesting
    public static boolean hasAppendedMessagesForTesting() {
        return sAppendedMessagesForTesting;
    }

    // TabSwitcher implementation.
    @Override
    public void setOnTabSelectingListener(OnTabSelectingListener listener) {
        mMediator.setOnTabSelectingListener(listener);
    }

    @Override
    public Controller getController() {
        return mMediator;
    }

    @Override
    public TabListDelegate getTabListDelegate() {
        return this;
    }

    @Override
    public TabDialogDelegation getTabGridDialogDelegation() {
        return this;
    }

    @Override
    public int getTabListTopOffset() {
        return mTabListCoordinator.getTabListTopOffset();
    }

    @Override
    public int getListModeForTesting() {
        return mMode;
    }

    @Override
    public boolean prepareOverview() {
        boolean quick = mMediator.prepareOverview();
        mTabListCoordinator.prepareOverview();
        return quick;
    }

    @Override
    public void postHiding() {
        mTabListCoordinator.postHiding();
        mMediator.postHiding();
    }

    @Override
    @NonNull
    public Rect getThumbnailLocationOfCurrentTab(boolean forceUpdate) {
        if (mTabGridDialogCoordinator != null && mTabGridDialogCoordinator.isVisible()) {
            assert forceUpdate;
            Rect thumbnail = mTabGridDialogCoordinator.getGlobalLocationOfCurrentThumbnail();
            // Adjust to the relative coordinate.
            Rect root = mTabListCoordinator.getRecyclerViewLocation();
            thumbnail.offset(-root.left, -root.top);
            return thumbnail;
        }
        if (forceUpdate) mTabListCoordinator.updateThumbnailLocation();
        return mTabListCoordinator.getThumbnailLocationOfCurrentTab();
    }

    // TabListDelegate implementation.
    @Override
    public int getResourceId() {
        return mTabListCoordinator.getResourceId();
    }

    @Override
    public long getLastDirtyTimeForTesting() {
        return mTabListCoordinator.getLastDirtyTimeForTesting();
    }

    @Override
    @VisibleForTesting
    public void setBitmapCallbackForTesting(Callback<Bitmap> callback) {
        TabListMediator.ThumbnailFetcher.sBitmapCallbackForTesting = callback;
    }

    @Override
    @VisibleForTesting
    public int getBitmapFetchCountForTesting() {
        return TabListMediator.ThumbnailFetcher.sFetchCountForTesting;
    }

    @Override
    @VisibleForTesting
    public int getSoftCleanupDelayForTesting() {
        return mMediator.getSoftCleanupDelayForTesting();
    }

    @Override
    @VisibleForTesting
    public int getCleanupDelayForTesting() {
        return mMediator.getCleanupDelayForTesting();
    }

    // TabDialogDelegation implementation.
    @Override
    @VisibleForTesting
    public void setSourceRectCallbackForTesting(Callback<RectF> callback) {
        TabGridDialogParent.setSourceRectCallbackForTesting(callback);
    }

    // ResetHandler implementation.
    @Override
    public boolean resetWithTabList(@Nullable TabList tabList, boolean quickMode, boolean mruMode) {
        sAppendedMessagesForTesting = false;
        List<Tab> tabs = null;
        if (tabList != null) {
            tabs = new ArrayList<>();
            for (int i = 0; i < tabList.getCount(); i++) {
                tabs.add(tabList.getTabAt(i));
            }
        }

        mMediator.registerFirstMeaningfulPaintRecorder();
        boolean showQuickly = mTabListCoordinator.resetWithListOfTabs(tabs, quickMode, mruMode);
        if (showQuickly) {
            mTabListCoordinator.removeSpecialListItem(TabProperties.UiType.NEW_TAB_TILE, 0);
        }

        int cardsCount = tabs == null ? 0 : tabs.size();
        if (tabs != null && mNewTabTileCoordinator != null) {
            mTabListCoordinator.addSpecialListItem(tabs.size(), TabProperties.UiType.NEW_TAB_TILE,
                    mNewTabTileCoordinator.getModel());
            cardsCount += 1;
        }
        if (tabs != null && tabs.size() > 0) appendMessagesTo(cardsCount);

        return showQuickly;
    }

    private void appendMessagesTo(int index) {
        List<MessageCardProviderMediator.Message> messages =
                mMessageCardProviderCoordinator.getMessageItems();
        for (int i = 0; i < messages.size(); i++) {
            mTabListCoordinator.addSpecialListItem(
                    index + i, TabProperties.UiType.MESSAGE, messages.get(i).model);
        }
        if (messages.size() > 0) sAppendedMessagesForTesting = true;
    }

    private View getTabGridDialogAnimationSourceView(int tabId) {
        int index = mTabListCoordinator.indexOfTab(tabId);
        // TODO(crbug.com/999372): This is band-aid fix that will show basic fade-in/fade-out
        // animation when we cannot find the animation source view holder. This is happening due to
        // current group id in TabGridDialog can not be indexed in TabListModel, which should never
        // happen. Remove this when figure out the actual cause.
        ViewHolder sourceViewHolder =
                mTabListCoordinator.getContainerView().findViewHolderForAdapterPosition(index);
        if (sourceViewHolder == null) return null;
        return sourceViewHolder.itemView;
    }

    @Override
    public void softCleanup() {
        mTabListCoordinator.softCleanup();
    }

    // ResetHandler implementation.
    @Override
    public void destroy() {
        mMenuOrKeyboardActionController.unregisterMenuOrKeyboardActionHandler(
                mTabSwitcherMenuActionHandler);
        mTabListCoordinator.destroy();
        mMessageCardProviderCoordinator.destroy();
        mContainerViewChangeProcessor.destroy();
        if (mTabGridDialogCoordinator != null) {
            mTabGridDialogCoordinator.destroy();
        }
        if (mUndoGroupSnackbarController != null) {
            mUndoGroupSnackbarController.destroy();
        }
        if (mTabGridIphItemCoordinator != null) {
            mTabGridIphItemCoordinator.destroy();
        }
        if (mNewTabTileCoordinator != null) {
            mNewTabTileCoordinator.destroy();
        }
        mMultiThumbnailCardProvider.destroy();
        mTabSelectionEditorCoordinator.destroy();
        mMediator.destroy();
        mLifecycleDispatcher.unregister(this);
        if (mTabAttributeCache != null) {
            mTabAttributeCache.destroy();
        }
    }
}
