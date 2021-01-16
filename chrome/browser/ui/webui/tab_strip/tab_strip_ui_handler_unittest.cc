// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/webui/tab_strip/tab_strip_ui_handler.h"

#include <memory>

#include "base/macros.h"
#include "base/optional.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/browser/extensions/extension_tab_util.h"
#include "chrome/browser/ui/tabs/tab_group_model.h"
#include "chrome/browser/ui/webui/tab_strip/tab_strip_ui_embedder.h"
#include "chrome/browser/ui/webui/tab_strip/tab_strip_ui_layout.h"
#include "chrome/test/base/browser_with_test_window_test.h"
#include "chrome/test/base/testing_profile_manager.h"
#include "components/tab_groups/tab_group_color.h"
#include "components/tab_groups/tab_group_id.h"
#include "components/tab_groups/tab_group_visual_data.h"
#include "content/public/browser/web_ui.h"
#include "content/public/test/test_web_ui.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "ui/base/accelerators/accelerator.h"
#include "ui/base/default_theme_provider.h"
#include "ui/base/theme_provider.h"
#include "ui/gfx/color_utils.h"
#include "ui/gfx/geometry/point.h"

namespace {

class TestTabStripUIHandler : public TabStripUIHandler {
 public:
  explicit TestTabStripUIHandler(content::WebUI* web_ui,
                                 Browser* browser,
                                 TabStripUIEmbedder* embedder)
      : TabStripUIHandler(browser, embedder) {
    set_web_ui(web_ui);
  }
};

class MockTabStripUIEmbedder : public TabStripUIEmbedder {
 public:
  MockTabStripUIEmbedder() : theme_provider_(new ui::DefaultThemeProvider()) {}
  MOCK_CONST_METHOD0(GetAcceleratorProvider, const ui::AcceleratorProvider*());
  MOCK_METHOD0(CloseContainer, void());
  MOCK_METHOD2(ShowContextMenuAtPoint,
               void(gfx::Point, std::unique_ptr<ui::MenuModel>));
  MOCK_METHOD0(GetLayout, TabStripUILayout());
  const ui::ThemeProvider* GetThemeProvider() override {
    return theme_provider_.get();
  }

 private:
  const std::unique_ptr<ui::ThemeProvider> theme_provider_;
};

}  // namespace

class TabStripUIHandlerTest : public BrowserWithTestWindowTest {
 public:
  TabStripUIHandlerTest() : web_ui_(new content::TestWebUI) {}
  void SetUp() override {
    BrowserWithTestWindowTest::SetUp();
    handler_ = std::make_unique<TestTabStripUIHandler>(web_ui(), browser(),
                                                       &mock_embedder_);
    handler()->AllowJavascriptForTesting();
    web_ui()->ClearTrackedCalls();
  }

  TabStripUIHandler* handler() { return handler_.get(); }
  content::TestWebUI* web_ui() { return web_ui_.get(); }

  void ExpectVisualDataDictionary(
      const tab_groups::TabGroupVisualData visual_data,
      const base::DictionaryValue* visual_data_dict) {
    std::string group_title;
    ASSERT_TRUE(visual_data_dict->GetString("title", &group_title));
    EXPECT_EQ(base::UTF16ToASCII(visual_data.title()), group_title);

    std::string group_color;
    ASSERT_TRUE(visual_data_dict->GetString("color", &group_color));
    EXPECT_EQ(color_utils::SkColorToRgbString(tab_groups::GetTabGroupColorSet()
                                                  .at(visual_data.color())
                                                  .light_theme_color),
              group_color);
  }

 protected:
  ::testing::NiceMock<MockTabStripUIEmbedder> mock_embedder_;

 private:
  std::unique_ptr<content::TestWebUI> web_ui_;
  std::unique_ptr<TestTabStripUIHandler> handler_;
  DISALLOW_COPY_AND_ASSIGN(TabStripUIHandlerTest);
};

TEST_F(TabStripUIHandlerTest, GroupClosedEvent) {
  AddTab(browser(), GURL("http://foo"));
  tab_groups::TabGroupId expected_group_id =
      browser()->tab_strip_model()->AddToNewGroup({0});
  browser()->tab_strip_model()->RemoveFromGroup({0});

  const content::TestWebUI::CallData& data = *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", data.function_name());

  std::string event_name;
  ASSERT_TRUE(data.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-closed", event_name);

  std::string actual_group_id;
  ASSERT_TRUE(data.arg2()->GetAsString(&actual_group_id));
  EXPECT_EQ(expected_group_id.ToString(), actual_group_id);
}

TEST_F(TabStripUIHandlerTest, GroupStateChangedEvents) {
  AddTab(browser(), GURL("http://foo/1"));
  AddTab(browser(), GURL("http://foo/2"));

  // Add one of the tabs to a group to test for a tab-group-state-changed event.
  tab_groups::TabGroupId expected_group_id =
      browser()->tab_strip_model()->AddToNewGroup({0, 1});

  const content::TestWebUI::CallData& grouped_data =
      *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", grouped_data.function_name());

  std::string event_name;
  ASSERT_TRUE(grouped_data.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-state-changed", event_name);

  int expected_tab_id = extensions::ExtensionTabUtil::GetTabId(
      browser()->tab_strip_model()->GetWebContentsAt(1));
  int actual_tab_id;
  ASSERT_TRUE(grouped_data.arg2()->GetAsInteger(&actual_tab_id));
  EXPECT_EQ(expected_tab_id, actual_tab_id);

  int index;
  ASSERT_TRUE(grouped_data.arg3()->GetAsInteger(&index));
  EXPECT_EQ(1, index);

  std::string actual_group_id;
  ASSERT_TRUE(grouped_data.arg4()->GetAsString(&actual_group_id));
  EXPECT_EQ(expected_group_id.ToString(), actual_group_id);

  // Remove the tab from the group to test for a tab-group-state-changed event.
  browser()->tab_strip_model()->RemoveFromGroup({1});
  const content::TestWebUI::CallData& ungrouped_data =
      *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", ungrouped_data.function_name());
  ASSERT_TRUE(ungrouped_data.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-state-changed", event_name);
  ASSERT_TRUE(ungrouped_data.arg2()->GetAsInteger(&actual_tab_id));
  EXPECT_EQ(expected_tab_id, actual_tab_id);
  ASSERT_TRUE(ungrouped_data.arg3()->GetAsInteger(&index));
  EXPECT_EQ(1, index);
  EXPECT_EQ(nullptr, ungrouped_data.arg4());
}

TEST_F(TabStripUIHandlerTest, GroupMovedEvents) {
  // Create a tab group and a few other tabs to allow the group to move.
  AddTab(browser(), GURL("http://foo/1"));
  AddTab(browser(), GURL("http://foo/2"));
  AddTab(browser(), GURL("http://foo/3"));
  AddTab(browser(), GURL("http://foo/4"));
  tab_groups::TabGroupId expected_group_id =
      browser()->tab_strip_model()->AddToNewGroup({0, 1});

  // Select all the tabs in the group.
  ui::ListSelectionModel selection;
  selection.AddIndexToSelection(0);
  selection.AddIndexToSelection(1);
  selection.set_active(0);
  browser()->tab_strip_model()->SetSelectionFromModel(selection);

  web_ui()->ClearTrackedCalls();

  // Move the selected tabs to later in the tab strip. This should result in
  // a single event that is fired to indicate the entire group has moved.
  int expected_index = 2;
  browser()->tab_strip_model()->MoveSelectedTabsTo(expected_index);

  EXPECT_EQ(1U, web_ui()->call_data().size());

  const content::TestWebUI::CallData& grouped_data =
      *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", grouped_data.function_name());

  std::string event_name;
  ASSERT_TRUE(grouped_data.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-moved", event_name);

  std::string actual_group_id;
  ASSERT_TRUE(grouped_data.arg2()->GetAsString(&actual_group_id));
  EXPECT_EQ(expected_group_id.ToString(), actual_group_id);

  int actual_index;
  ASSERT_TRUE(grouped_data.arg3()->GetAsInteger(&actual_index));
  EXPECT_EQ(expected_index, actual_index);

  web_ui()->ClearTrackedCalls();

  // Move the selected tabs to earlier in the tab strip. This should also
  // result in a single event that is fired to indicate the entire group has
  // moved.
  expected_index = 1;
  browser()->tab_strip_model()->MoveSelectedTabsTo(expected_index);

  EXPECT_EQ(1U, web_ui()->call_data().size());

  const content::TestWebUI::CallData& grouped_data2 =
      *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", grouped_data2.function_name());
  ASSERT_TRUE(grouped_data2.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-moved", event_name);
  ASSERT_TRUE(grouped_data2.arg2()->GetAsString(&actual_group_id));
  EXPECT_EQ(expected_group_id.ToString(), actual_group_id);
  ASSERT_TRUE(grouped_data2.arg3()->GetAsInteger(&actual_index));
  EXPECT_EQ(expected_index, actual_index);
}

TEST_F(TabStripUIHandlerTest, GetGroupVisualData) {
  AddTab(browser(), GURL("http://foo/1"));
  AddTab(browser(), GURL("http://foo/2"));
  tab_groups::TabGroupId group1 =
      browser()->tab_strip_model()->AddToNewGroup({0});
  const tab_groups::TabGroupVisualData group1_visuals(
      base::ASCIIToUTF16("Group 1"), tab_groups::TabGroupColorId::kGreen);
  browser()
      ->tab_strip_model()
      ->group_model()
      ->GetTabGroup(group1)
      ->SetVisualData(group1_visuals);
  tab_groups::TabGroupId group2 =
      browser()->tab_strip_model()->AddToNewGroup({1});
  const tab_groups::TabGroupVisualData group2_visuals(
      base::ASCIIToUTF16("Group 2"), tab_groups::TabGroupColorId::kCyan);
  browser()
      ->tab_strip_model()
      ->group_model()
      ->GetTabGroup(group2)
      ->SetVisualData(group2_visuals);

  base::ListValue args;
  args.AppendString("callback-id");
  handler()->HandleGetGroupVisualData(&args);

  const content::TestWebUI::CallData& data = *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIResponse", data.function_name());

  std::string callback_id;
  ASSERT_TRUE(data.arg1()->GetAsString(&callback_id));
  EXPECT_EQ("callback-id", callback_id);

  bool success = false;
  ASSERT_TRUE(data.arg2()->GetAsBoolean(&success));
  EXPECT_TRUE(success);

  const base::DictionaryValue* returned_data;
  ASSERT_TRUE(data.arg3()->GetAsDictionary(&returned_data));

  const base::DictionaryValue* group1_dict;
  ASSERT_TRUE(returned_data->GetDictionary(group1.ToString(), &group1_dict));
  ExpectVisualDataDictionary(group1_visuals, group1_dict);

  const base::DictionaryValue* group2_dict;
  ASSERT_TRUE(returned_data->GetDictionary(group2.ToString(), &group2_dict));
  ExpectVisualDataDictionary(group2_visuals, group2_dict);
}

TEST_F(TabStripUIHandlerTest, GroupVisualDataChangedEvent) {
  AddTab(browser(), GURL("http://foo"));
  tab_groups::TabGroupId expected_group_id =
      browser()->tab_strip_model()->AddToNewGroup({0});
  const tab_groups::TabGroupVisualData new_visual_data(
      base::ASCIIToUTF16("My new title"), tab_groups::TabGroupColorId::kGreen);
  browser()
      ->tab_strip_model()
      ->group_model()
      ->GetTabGroup(expected_group_id)
      ->SetVisualData(new_visual_data);

  const content::TestWebUI::CallData& data = *web_ui()->call_data().back();
  EXPECT_EQ("cr.webUIListenerCallback", data.function_name());

  std::string event_name;
  ASSERT_TRUE(data.arg1()->GetAsString(&event_name));
  EXPECT_EQ("tab-group-visuals-changed", event_name);

  std::string actual_group_id;
  ASSERT_TRUE(data.arg2()->GetAsString(&actual_group_id));
  EXPECT_EQ(expected_group_id.ToString(), actual_group_id);

  const base::DictionaryValue* visual_data;
  ASSERT_TRUE(data.arg3()->GetAsDictionary(&visual_data));
  ExpectVisualDataDictionary(new_visual_data, visual_data);
}

TEST_F(TabStripUIHandlerTest, GroupTab) {
  // Add a tab inside of a group.
  AddTab(browser(), GURL("http://foo"));
  tab_groups::TabGroupId group_id =
      browser()->tab_strip_model()->AddToNewGroup({0});

  // Add another tab, and try to group it.
  AddTab(browser(), GURL("http://foo"));
  base::ListValue args;
  args.AppendInteger(extensions::ExtensionTabUtil::GetTabId(
      browser()->tab_strip_model()->GetWebContentsAt(0)));
  args.AppendString(group_id.ToString());
  handler()->HandleGroupTab(&args);

  ASSERT_EQ(group_id, browser()->tab_strip_model()->GetTabGroupForTab(0));
}

TEST_F(TabStripUIHandlerTest, MoveGroup) {
  AddTab(browser(), GURL("http://foo/1"));
  AddTab(browser(), GURL("http://foo/2"));
  tab_groups::TabGroupId group_id =
      browser()->tab_strip_model()->AddToNewGroup({0});

  // Move the group to index 1.
  int new_index = 1;
  base::ListValue args;
  args.AppendString(group_id.ToString());
  args.AppendInteger(new_index);
  handler()->HandleMoveGroup(&args);

  std::vector<int> tabs_in_group = browser()
                                       ->tab_strip_model()
                                       ->group_model()
                                       ->GetTabGroup(group_id)
                                       ->ListTabs();
  ASSERT_EQ(new_index, tabs_in_group.front());
  ASSERT_EQ(new_index, tabs_in_group.back());
}

TEST_F(TabStripUIHandlerTest, MoveGroupAcrossWindows) {
  AddTab(browser(), GURL("http://foo"));

  // Create a new window with the same profile, and add a group to it.
  std::unique_ptr<BrowserWindow> new_window(CreateBrowserWindow());
  std::unique_ptr<Browser> new_browser =
      CreateBrowser(profile(), browser()->type(), false, new_window.get());
  AddTab(new_browser.get(), GURL("http://foo"));
  AddTab(new_browser.get(), GURL("http://foo"));
  tab_groups::TabGroupId group_id =
      new_browser.get()->tab_strip_model()->AddToNewGroup({0, 1});

  // Create some visual data to make sure it gets transferred.
  const tab_groups::TabGroupVisualData visual_data(
      base::ASCIIToUTF16("My group"), tab_groups::TabGroupColorId::kGreen);
  new_browser.get()
      ->tab_strip_model()
      ->group_model()
      ->GetTabGroup(group_id)
      ->SetVisualData(visual_data);

  content::WebContents* moved_contents1 =
      new_browser.get()->tab_strip_model()->GetWebContentsAt(0);
  content::WebContents* moved_contents2 =
      new_browser.get()->tab_strip_model()->GetWebContentsAt(1);

  int new_index = -1;
  base::ListValue args;
  args.AppendString(group_id.ToString());
  args.AppendInteger(new_index);
  handler()->HandleMoveGroup(&args);

  ASSERT_EQ(0U, new_browser.get()
                    ->tab_strip_model()
                    ->group_model()
                    ->ListTabGroups()
                    .size());
  ASSERT_EQ(moved_contents1, browser()->tab_strip_model()->GetWebContentsAt(1));
  ASSERT_EQ(moved_contents2, browser()->tab_strip_model()->GetWebContentsAt(2));

  base::Optional<tab_groups::TabGroupId> new_group_id =
      browser()->tab_strip_model()->GetTabGroupForTab(1);
  ASSERT_TRUE(new_group_id.has_value());
  ASSERT_EQ(browser()->tab_strip_model()->GetTabGroupForTab(1),
            browser()->tab_strip_model()->GetTabGroupForTab(2));

  const tab_groups::TabGroupVisualData* new_visual_data =
      browser()
          ->tab_strip_model()
          ->group_model()
          ->GetTabGroup(new_group_id.value())
          ->visual_data();
  ASSERT_EQ(visual_data.title(), new_visual_data->title());
  ASSERT_EQ(visual_data.color(), new_visual_data->color());
}

TEST_F(TabStripUIHandlerTest, MoveGroupAcrossProfiles) {
  AddTab(browser(), GURL("http://foo"));

  TestingProfile* different_profile =
      profile_manager()->CreateTestingProfile("different_profile");
  std::unique_ptr<BrowserWindow> new_window(CreateBrowserWindow());
  std::unique_ptr<Browser> new_browser = CreateBrowser(
      different_profile, browser()->type(), false, new_window.get());
  AddTab(new_browser.get(), GURL("http://foo"));
  tab_groups::TabGroupId group_id =
      new_browser.get()->tab_strip_model()->AddToNewGroup({0});

  int new_index = -1;
  base::ListValue args;
  args.AppendString(group_id.ToString());
  args.AppendInteger(new_index);
  handler()->HandleMoveGroup(&args);

  ASSERT_TRUE(
      new_browser.get()->tab_strip_model()->group_model()->ContainsTabGroup(
          group_id));

  // Close all tabs before destructing.
  new_browser.get()->tab_strip_model()->CloseAllTabs();
}

TEST_F(TabStripUIHandlerTest, UngroupTab) {
  // Add a tab inside of a group.
  AddTab(browser(), GURL("http://foo"));
  browser()->tab_strip_model()->AddToNewGroup({0});

  // Add another tab at index 1, and try to group it.
  base::ListValue args;
  args.AppendInteger(extensions::ExtensionTabUtil::GetTabId(
      browser()->tab_strip_model()->GetWebContentsAt(0)));
  handler()->HandleUngroupTab(&args);

  ASSERT_FALSE(browser()->tab_strip_model()->GetTabGroupForTab(0).has_value());
}
