// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/infobars/overlays/infobar_overlay_request_inserter.h"

#include "components/infobars/core/infobar.h"
#include "ios/chrome/browser/infobars/infobar_manager_impl.h"
#import "ios/chrome/browser/infobars/overlays/fake_infobar_overlay_request_factory.h"
#import "ios/chrome/browser/infobars/test/fake_infobar_delegate.h"
#import "ios/chrome/browser/infobars/test/fake_infobar_ios.h"
#import "ios/chrome/browser/overlays/public/common/infobars/infobar_overlay_request_config.h"
#include "ios/chrome/browser/overlays/public/overlay_request.h"
#include "ios/chrome/browser/overlays/public/overlay_request_queue.h"
#import "ios/web/public/test/fakes/test_navigation_manager.h"
#import "ios/web/public/test/fakes/test_web_state.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "testing/platform_test.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

using infobars::InfoBar;
using infobars::InfoBarManager;

// Test fixture for InfobarOverlayRequestInserter.
class InfobarOverlayRequestInserterTest : public PlatformTest {
 public:
  InfobarOverlayRequestInserterTest() {
    web_state_.SetNavigationManager(
        std::make_unique<web::TestNavigationManager>());
    InfobarOverlayRequestInserter::CreateForWebState(
        &web_state_, std::make_unique<FakeInfobarOverlayRequestFactory>());
    InfoBarManagerImpl::CreateForWebState(&web_state_);
  }

  // Accessors.
  InfobarOverlayRequestInserter* inserter() {
    return InfobarOverlayRequestInserter::FromWebState(&web_state_);
  }
  InfoBarManager* manager() {
    return InfoBarManagerImpl::FromWebState(&web_state_);
  }
  OverlayRequestQueue* GetQueue(InfobarOverlayType type) {
    OverlayModality modality = type == InfobarOverlayType::kBanner
                                   ? OverlayModality::kInfobarBanner
                                   : OverlayModality::kInfobarModal;
    return OverlayRequestQueue::FromWebState(&web_state_, modality);
  }

  // Adds an InfoBar created with a test delegate to the manager.  Returns a
  // pointer to the added InfoBar.
  InfoBar* CreateInfobar() {
    std::unique_ptr<InfoBar> added_infobar = std::make_unique<FakeInfobarIOS>();
    InfoBar* infobar = added_infobar.get();
    manager()->AddInfoBar(std::move(added_infobar));
    return infobar;
  }

 private:
  web::TestWebState web_state_;
};

// Tests that the inserter adds banner OverlayRequests to the correct queue.
TEST_F(InfobarOverlayRequestInserterTest, InsertBanner) {
  OverlayRequestQueue* queue = GetQueue(InfobarOverlayType::kBanner);
  ASSERT_EQ(0U, queue->size());
  // Insert |infobar| at front of queue and check that the queue is updated
  // correctly.
  InfoBar* infobar = CreateInfobar();
  inserter()->AddOverlayRequest(infobar, InfobarOverlayType::kBanner);
  EXPECT_EQ(1U, queue->size());
  EXPECT_EQ(infobar, queue->front_request()
                         ->GetConfig<InfobarOverlayRequestConfig>()
                         ->infobar());
  // Insert |inserted_infobar| in front of |infobar| and check that it is now
  // the front request.
  InfoBar* inserted_infobar = CreateInfobar();
  inserter()->InsertOverlayRequest(inserted_infobar,
                                   InfobarOverlayType::kBanner, 0);
  EXPECT_EQ(2U, queue->size());
  EXPECT_EQ(inserted_infobar, queue->front_request()
                                  ->GetConfig<InfobarOverlayRequestConfig>()
                                  ->infobar());
}

// Tests that the inserter adds banner OverlayRequests to the correct queue.
TEST_F(InfobarOverlayRequestInserterTest, AddBanner) {
  OverlayRequestQueue* queue = GetQueue(InfobarOverlayType::kBanner);
  ASSERT_EQ(0U, queue->size());
  // Add |infobar| to the back of the queue and check that the it is updated
  // correctly.
  InfoBar* infobar = CreateInfobar();
  inserter()->AddOverlayRequest(infobar, InfobarOverlayType::kBanner);
  EXPECT_EQ(1U, queue->size());
  EXPECT_EQ(infobar, queue->front_request()
                         ->GetConfig<InfobarOverlayRequestConfig>()
                         ->infobar());
  // Add |second_infobar| in to the queue and check that it is second in the
  // queue.
  InfoBar* second_infobar = CreateInfobar();
  inserter()->AddOverlayRequest(second_infobar, InfobarOverlayType::kBanner);
  EXPECT_EQ(2U, queue->size());
  EXPECT_EQ(second_infobar, queue->GetRequest(1)
                                ->GetConfig<InfobarOverlayRequestConfig>()
                                ->infobar());
}
