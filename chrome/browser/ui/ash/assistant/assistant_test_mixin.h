// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_ASH_ASSISTANT_ASSISTANT_TEST_MIXIN_H_
#define CHROME_BROWSER_UI_ASH_ASSISTANT_ASSISTANT_TEST_MIXIN_H_

#include <memory>
#include <string>

#include "base/macros.h"
#include "base/test/scoped_feature_list.h"
#include "base/time/time.h"
#include "chrome/browser/ui/ash/assistant/test/fake_s3_server.h"
#include "chrome/test/base/mixin_based_in_process_browser_test.h"
#include "ui/events/keycodes/keyboard_codes_posix.h"

class PrefService;

namespace ash {
class AssistantTestApi;
}  // namespace ash

namespace chromeos {
namespace assistant {

class FakeS3Server;
class LoggedInUserMixin;

// Default wait time before we conclude the wait actions have timed out.
constexpr base::TimeDelta kDefaultWaitTimeout =
    base::TimeDelta::FromSeconds(10);

// Creates everything required to test the Assistant in browser tests.
// This includes:
//     - Installing a fake Gaia server so the test user is able to use the
//       Assistant.
//     - Setting up a fake S3 server to spoof fake interactions.
//     - Enabling the Assistant service.
//     - Disabling all Assistant animations.
//
// See definition of |chromeos::assistant::FakeS3Server| for an explanation of
// the different modes the fake S3 server can run in (specified by passing
// |FakeS3Mode| into the constructor).
class AssistantTestMixin : public InProcessBrowserTestMixin {
 public:
  AssistantTestMixin(InProcessBrowserTestMixinHost* host,
                     InProcessBrowserTest* test_base,
                     net::EmbeddedTestServer* embedded_test_server,
                     FakeS3Mode mode);
  ~AssistantTestMixin() override;

  // InProcessBrowserTestMixin overrides:
  void SetUpCommandLine(base::CommandLine* command_line) override;
  void SetUpOnMainThread() override;
  void TearDownOnMainThread() override;

  // Starts the Assistant service and wait until it is ready to process
  // queries. Should be called as the first action in every test.
  void StartAssistantAndWaitForReady(
      base::TimeDelta wait_timeout = kDefaultWaitTimeout);

  // Changes the user setting controlling whether the user prefers voice or
  // keyboard.
  void SetPreferVoice(bool prefer_voice);

  // Submits a text query. Can only be used when the Assistant UI is visible and
  // displaying the query input text field.
  void SendTextQuery(const std::string& query);

  // Waits until a card response is rendered that contains the given text.
  // If |expected_response| is not received in |wait_timeout|, this will fail
  // the test.
  void ExpectCardResponse(const std::string& expected_response,
                          base::TimeDelta wait_timeout = kDefaultWaitTimeout);

  // Waits until a text response is rendered that contains the given text.
  // If |expected_response| is not received in |wait_timeout|, this will fail
  // the test.
  void ExpectTextResponse(const std::string& expected_response,
                          base::TimeDelta wait_timeout = kDefaultWaitTimeout);

  // Same as above but checks if any of the given responses are encountered.
  void ExpectAnyOfTheseTextResponses(
      const std::vector<std::string>& expected_responses,
      base::TimeDelta wait_timeout = kDefaultWaitTimeout);

  // Presses the Assistant key, which will toggle the Assistant UI.
  void PressAssistantKey();

  // Returns true if the Assistant UI is currently visible.
  bool IsVisible();

 private:
  PrefService* GetUserPreferences();
  void SendKeyPress(ui::KeyboardCode key);
  void DisableAssistant();
  void DisableWarmerWelcome();

  base::test::ScopedFeatureList scoped_feature_list_;
  FakeS3Server fake_s3_server_;
  FakeS3Mode mode_;
  std::unique_ptr<ash::AssistantTestApi> test_api_;
  std::unique_ptr<LoggedInUserMixin> user_mixin_;

  DISALLOW_COPY_AND_ASSIGN(AssistantTestMixin);
};

}  // namespace assistant
}  // namespace chromeos

#endif  // CHROME_BROWSER_UI_ASH_ASSISTANT_ASSISTANT_TEST_MIXIN_H_
