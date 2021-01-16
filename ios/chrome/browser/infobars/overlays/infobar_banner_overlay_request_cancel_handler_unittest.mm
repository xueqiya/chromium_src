// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/infobars/overlays/infobar_banner_overlay_request_cancel_handler.h"

#include "components/infobars/core/infobar.h"
#include "ios/chrome/browser/infobars/infobar_manager_impl.h"
#import "ios/chrome/browser/infobars/overlays/fake_infobar_overlay_request_factory.h"
#import "ios/chrome/browser/infobars/overlays/infobar_overlay_request_inserter.h"
#include "ios/chrome/browser/infobars/overlays/overlay_request_infobar_util.h"
#include "ios/chrome/browser/infobars/test/fake_infobar_delegate.h"
#import "ios/chrome/browser/infobars/test/fake_infobar_ios.h"
#import "ios/chrome/browser/overlays/public/common/infobars/infobar_overlay_request_config.h"
#include "ios/chrome/browser/overlays/public/overlay_request.h"
#include "ios/chrome/browser/overlays/public/overlay_request_queue.h"
#include "ios/chrome/browser/overlays/test/fake_overlay_user_data.h"
#import "ios/web/public/test/fakes/test_navigation_manager.h"
#import "ios/web/public/test/fakes/test_web_state.h"
#include "testing/platform_test.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

using infobars::InfoBar;
using infobars::InfoBarDelegate;
using infobars::InfoBarManager;

// Test fixture for InfobarBannerOverlayRequestCancelHandler.
class InfobarBannerOverlayRequestCancelHandlerTest : public PlatformTest {
 public:
  InfobarBannerOverlayRequestCancelHandlerTest() {
    // Set up WebState and InfoBarManager.
    web_state_.SetNavigationManager(
        std::make_unique<web::TestNavigationManager>());
    InfobarOverlayRequestInserter::CreateForWebState(
        &web_state_, std::make_unique<FakeInfobarOverlayRequestFactory>());
    InfoBarManagerImpl::CreateForWebState(&web_state_);
  }

  OverlayRequestQueue* queue() {
    return OverlayRequestQueue::FromWebState(&web_state_,
                                             OverlayModality::kInfobarBanner);
  }
  InfoBarManager* manager() {
    return InfoBarManagerImpl::FromWebState(&web_state_);
  }
  InfobarOverlayRequestInserter* inserter() {
    return InfobarOverlayRequestInserter::FromWebState(&web_state_);
  }

  // Returns the InfoBar used to create the front request in queue().
  InfoBar* GetFrontRequestInfobar() {
    OverlayRequest* front_request = queue()->front_request();
    return front_request ? GetOverlayRequestInfobar(front_request) : nullptr;
  }

 private:
  web::TestWebState web_state_;
};

// Tests that the request is replaced if its corresponding InfoBar is replaced
// in its manager.
TEST_F(InfobarBannerOverlayRequestCancelHandlerTest,
       CancelForInfobarReplacement) {
  std::unique_ptr<InfoBar> first_passed_infobar =
      std::make_unique<FakeInfobarIOS>();
  InfoBar* first_infobar = first_passed_infobar.get();
  manager()->AddInfoBar(std::move(first_passed_infobar));
  inserter()->AddOverlayRequest(first_infobar, InfobarOverlayType::kBanner);
  ASSERT_EQ(first_infobar, GetFrontRequestInfobar());
  // Replace with a new infobar and verify that the request has been replaced.
  std::unique_ptr<InfoBar> second_passed_infobar =
      std::make_unique<FakeInfobarIOS>();
  InfoBar* second_infobar = second_passed_infobar.get();
  manager()->ReplaceInfoBar(first_infobar, std::move(second_passed_infobar));
  EXPECT_EQ(second_infobar, GetFrontRequestInfobar());
  EXPECT_EQ(1U, queue()->size());
}
