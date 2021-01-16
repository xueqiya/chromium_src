// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_CHILD_ACCOUNTS_CHILD_USER_SERVICE_H_
#define CHROME_BROWSER_CHROMEOS_CHILD_ACCOUNTS_CHILD_USER_SERVICE_H_

#include <memory>
#include <string>

#include "chrome/browser/chromeos/child_accounts/time_limits/app_activity_report_interface.h"
#include "chrome/browser/chromeos/child_accounts/time_limits/web_time_limit_interface.h"
#include "components/keyed_service/core/keyed_service.h"

namespace base {
class TimeDelta;
}  // namespace base

namespace content {
class BrowserContext;
}  // namespace content

namespace enterprise_management {
class ChildStatusReportRequest;
}  // namespace enterprise_management

class GURL;

namespace chromeos {
namespace app_time {
class AppTimeController;
class WebTimeLimitEnforcer;
}  // namespace app_time

// Facade that exposes child user related functionality on Chrome OS.
// TODO(crbug.com/1022231): Migrate ConsumerStatusReportingService,
// EventBasedStatusReporting and ScreenTimeController to ChildUserService.
class ChildUserService : public KeyedService,
                         public app_time::WebTimeLimitInterface,
                         public app_time::AppActivityReportInterface {
 public:
  // Used for tests to get internal implementation details.
  class TestApi {
   public:
    explicit TestApi(ChildUserService* service);
    ~TestApi();

    app_time::WebTimeLimitEnforcer* web_time_enforcer();
    app_time::AppTimeController* app_time_controller();

   private:
    ChildUserService* const service_;
  };

  explicit ChildUserService(content::BrowserContext* context);
  ChildUserService(const ChildUserService&) = delete;
  ChildUserService& operator=(const ChildUserService&) = delete;
  ~ChildUserService() override;

  // app_time::WebTimeLimitInterface:
  void PauseWebActivity(const std::string& app_id) override;
  void ResumeWebActivity(const std::string& app_id) override;

  // app_time::AppActivityReportInterface:
  app_time::AppActivityReportInterface::ReportParams GenerateAppActivityReport(
      enterprise_management::ChildStatusReportRequest* report) const override;
  void AppActivityReportSubmitted(
      base::Time report_generation_timestamp) override;

  // Returns whether web time limit was reached for child user.
  // Always returns false if per-app times limits feature is disabled.
  bool WebTimeLimitReached() const;

  // Returns whether given |url| can be used without any time restrictions.
  // Viewing of whitelisted |url| does not count towards usage web time.
  // Always returns false if per-app times limits feature is disabled.
  bool WebTimeLimitWhitelistedURL(const GURL& url) const;

  // Returns time limit set for using the web on a given day.
  // Should only be called if |features::kPerAppTimeLimits| and
  // |features::kWebTimeLimits| features are enabled.
  base::TimeDelta GetWebTimeLimit() const;

 private:
  // KeyedService:
  void Shutdown() override;

  std::unique_ptr<app_time::AppTimeController> app_time_controller_;
};

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_CHILD_ACCOUNTS_CHILD_USER_SERVICE_H_
