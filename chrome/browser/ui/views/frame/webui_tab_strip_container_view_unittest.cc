// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/frame/webui_tab_strip_container_view.h"
#include <utility>

#include "base/command_line.h"
#include "base/test/scoped_feature_list.h"
#include "chrome/browser/extensions/extension_tab_util.h"
#include "chrome/browser/ui/ui_features.h"
#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/frame/test_with_browser_view.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "chrome/browser/ui/webui/tab_strip/tab_strip_ui.h"
#include "chrome/common/chrome_switches.h"
#include "chrome/test/base/test_browser_window.h"
#include "content/public/common/drop_data.h"
#include "ui/base/test/material_design_controller_test_api.h"
#include "ui/base/ui_base_switches.h"

class WebUITabStripContainerViewTest : public TestWithBrowserView {
 public:
  template <typename... Args>
  explicit WebUITabStripContainerViewTest(Args... args)
      : TestWithBrowserView(args...), touch_mode_(true) {
    // Both the switch and |touch_mode_| are necessary since
    // MaterialDesignController::Initialize() gets called at different
    // times on different platforms.
    base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
        switches::kTopChromeTouchUi, switches::kTopChromeTouchUiEnabled);
    feature_override_.InitAndEnableFeature(features::kWebUITabStrip);
  }

  ~WebUITabStripContainerViewTest() override = default;

 private:
  base::test::ScopedFeatureList feature_override_;
  ui::test::MaterialDesignControllerTestAPI touch_mode_;
};

TEST_F(WebUITabStripContainerViewTest, TabStripStartsClosed) {
  EXPECT_TRUE(WebUITabStripContainerView::UseTouchableTabStrip());
  ASSERT_NE(nullptr, browser_view()->webui_tab_strip());
  EXPECT_FALSE(browser_view()->webui_tab_strip()->GetVisible());
}

TEST_F(WebUITabStripContainerViewTest, TouchModeTransition) {
  EXPECT_TRUE(WebUITabStripContainerView::UseTouchableTabStrip());
  EXPECT_NE(nullptr, browser_view()->webui_tab_strip());
  EXPECT_FALSE(browser_view()->IsTabStripVisible());

  ui::test::MaterialDesignControllerTestAPI disable_touch_mode(false);
  browser_view()->Layout();
  EXPECT_FALSE(WebUITabStripContainerView::UseTouchableTabStrip());
  EXPECT_TRUE(browser_view()->IsTabStripVisible());

  ui::test::MaterialDesignControllerTestAPI reenable_touch_mode(true);
  browser_view()->Layout();
  EXPECT_TRUE(WebUITabStripContainerView::UseTouchableTabStrip());
  EXPECT_FALSE(browser_view()->IsTabStripVisible());
  ASSERT_NE(nullptr, browser_view()->webui_tab_strip());
}

TEST_F(WebUITabStripContainerViewTest, ButtonsPresentInToolbar) {
  ASSERT_NE(nullptr,
            browser_view()->webui_tab_strip()->tab_counter_for_testing());
  EXPECT_TRUE(browser_view()->toolbar()->Contains(
      browser_view()->webui_tab_strip()->tab_counter_for_testing()));
}

TEST_F(WebUITabStripContainerViewTest, PreventsInvalidTabDrags) {
  content::DropData empty_drop_data;
  EXPECT_FALSE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, empty_drop_data, blink::kWebDragOperationMove));

  content::DropData invalid_drop_data;
  invalid_drop_data.custom_data.insert(std::make_pair(
      base::ASCIIToUTF16(kWebUITabIdDataType), base::ASCIIToUTF16("3000")));
  EXPECT_FALSE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, invalid_drop_data, blink::kWebDragOperationMove));

  AddTab(browser(), GURL("http://foo"));
  int valid_tab_id = extensions::ExtensionTabUtil::GetTabId(
      browser()->tab_strip_model()->GetWebContentsAt(0));
  content::DropData valid_drop_data;
  valid_drop_data.custom_data.insert(
      std::make_pair(base::ASCIIToUTF16(kWebUITabIdDataType),
                     base::NumberToString16(valid_tab_id)));
  EXPECT_TRUE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, valid_drop_data, blink::kWebDragOperationMove));
}

TEST_F(WebUITabStripContainerViewTest, PreventsInvalidGroupDrags) {
  content::DropData invalid_drop_data;
  invalid_drop_data.custom_data.insert(
      std::make_pair(base::ASCIIToUTF16(kWebUITabGroupIdDataType),
                     base::ASCIIToUTF16("not a real group")));
  EXPECT_FALSE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, invalid_drop_data, blink::kWebDragOperationMove));

  AddTab(browser(), GURL("http://foo"));
  tab_groups::TabGroupId group_id =
      browser()->tab_strip_model()->AddToNewGroup({0});
  content::DropData valid_drop_data;
  valid_drop_data.custom_data.insert(
      std::make_pair(base::ASCIIToUTF16(kWebUITabGroupIdDataType),
                     base::ASCIIToUTF16(group_id.ToString())));
  EXPECT_TRUE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, valid_drop_data, blink::kWebDragOperationMove));

  // Another group from a different profile.
  std::unique_ptr<BrowserWindow> new_window(
      std::make_unique<TestBrowserWindow>());
  std::unique_ptr<Browser> new_browser =
      CreateBrowser(browser()->profile()->GetOffTheRecordProfile(),
                    browser()->type(), false, new_window.get());
  AddTab(new_browser.get(), GURL("http://foo"));

  tab_groups::TabGroupId new_group_id =
      new_browser.get()->tab_strip_model()->AddToNewGroup({0});
  content::DropData different_profile_drop_data;
  different_profile_drop_data.custom_data.insert(
      std::make_pair(base::ASCIIToUTF16(kWebUITabGroupIdDataType),
                     base::ASCIIToUTF16(new_group_id.ToString())));
  EXPECT_FALSE(
      browser_view()->webui_tab_strip()->web_view_for_testing()->CanDragEnter(
          nullptr, different_profile_drop_data, blink::kWebDragOperationMove));

  // Close all tabs before destructing.
  new_browser.get()->tab_strip_model()->CloseAllTabs();
}

class WebUITabStripDevToolsTest : public WebUITabStripContainerViewTest {
 public:
  WebUITabStripDevToolsTest()
      : WebUITabStripContainerViewTest(Browser::TYPE_DEVTOOLS) {}
  ~WebUITabStripDevToolsTest() override = default;
};

// Regression test for crbug.com/1010247.
TEST_F(WebUITabStripDevToolsTest, DevToolsWindowHasNoTabStrip) {
  EXPECT_EQ(nullptr, browser_view()->webui_tab_strip());

  ui::test::MaterialDesignControllerTestAPI disable_touch_mode(false);
  ui::test::MaterialDesignControllerTestAPI reenable_touch_mode(true);
  EXPECT_EQ(nullptr, browser_view()->webui_tab_strip());
}
