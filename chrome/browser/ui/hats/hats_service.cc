// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/hats/hats_service.h"

#include <utility>

#include "base/metrics/field_trial_params.h"
#include "base/metrics/histogram_macros.h"
#include "base/rand_util.h"
#include "base/util/values/values_util.h"
#include "base/values.h"
#include "base/version.h"
#include "chrome/browser/browser_process.h"
#include "chrome/browser/prefs/incognito_mode_prefs.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/profiles/profiles_state.h"
#include "chrome/browser/ui/browser_finder.h"
#include "chrome/browser/ui/browser_window.h"
#include "chrome/common/chrome_features.h"
#include "chrome/common/pref_names.h"
#include "components/content_settings/core/browser/cookie_settings.h"
#include "components/content_settings/core/browser/website_settings_registry.h"
#include "components/content_settings/core/common/content_settings.h"
#include "components/content_settings/core/common/features.h"
#include "components/content_settings/core/common/pref_names.h"
#include "components/metrics_services_manager/metrics_services_manager.h"
#include "components/prefs/pref_registry_simple.h"
#include "components/prefs/scoped_user_pref_update.h"
#include "components/version_info/version_info.h"
#include "net/base/network_change_notifier.h"

constexpr char kHatsSurveyTriggerSatisfaction[] = "satisfaction";
constexpr char kHatsSurveyTriggerSettings[] = "settings";
constexpr char kHatsSurveyTriggerSettingsPrivacy[] = "settings-privacy";

namespace {

const base::Feature* survey_features[] = {
    &features::kHappinessTrackingSurveysForDesktop,
    &features::kHappinessTrackingSurveysForDesktopSettings,
    &features::kHappinessTrackingSurveysForDesktopSettingsPrivacy};

// Which survey we're triggering
constexpr char kHatsSurveyTrigger[] = "survey";

constexpr char kHatsSurveyProbability[] = "probability";

constexpr char kHatsSurveyEnSiteID[] = "en_site_id";

constexpr double kHatsSurveyProbabilityDefault = 0;

constexpr char kHatsSurveyEnSiteIDDefault[] = "ty52vxwjrabfvhusawtrmkmx6m";

constexpr base::TimeDelta kMinimumTimeBetweenSurveyStarts =
    base::TimeDelta::FromDays(60);

constexpr base::TimeDelta kMinimumProfileAge = base::TimeDelta::FromDays(30);

// Preferences Data Model
// The kHatsSurveyMetadata pref points to a dictionary.
// The valid keys and value types for this dictionary are as follows:
// [trigger].last_major_version        ---> Integer
// [trigger].last_survey_started_time  ---> Time

std::string GetMajorVersionPath(const std::string& trigger) {
  return trigger + ".last_major_version";
}

std::string GetLastSurveyStartedTime(const std::string& trigger) {
  return trigger + ".last_survey_started_time";
}

constexpr char kHatsShouldShowSurveyReasonHistogram[] =
    "Feedback.HappinessTrackingSurvey.ShouldShowSurveyReason";

// These values are persisted to logs. Entries should not be renumbered and
// numeric values should never be reused.
enum class ShouldShowSurveyReasons {
  kYes = 0,
  kNoOffline = 1,
  kNoLastSessionCrashed = 2,
  kNoReceivedSurveyInCurrentMilestone = 3,
  kNoProfileTooNew = 4,
  kNoLastSurveyTooRecent = 5,
  kNoBelowProbabilityLimit = 6,
  kNoTriggerStringMismatch = 7,
  kNoNotRegularBrowser = 8,
  kNoIncognitoDisabled = 9,
  kNoCookiesBlocked = 10,
  kNoThirdPartyCookiesBlocked = 11,
  kMaxValue = kNoThirdPartyCookiesBlocked,
};

}  // namespace

HatsService::SurveyMetadata::SurveyMetadata() = default;
HatsService::SurveyMetadata::~SurveyMetadata() = default;

HatsService::HatsService(Profile* profile) : profile_(profile) {
  for (auto* survey_feature : survey_features) {
    survey_configs_by_triggers_.emplace(
        base::FeatureParam<std::string>(survey_feature, kHatsSurveyTrigger, "")
            .Get(),
        SurveyConfig(
            base::FeatureParam<double>(survey_feature, kHatsSurveyProbability,
                                       kHatsSurveyProbabilityDefault)
                .Get(),
            base::FeatureParam<std::string>(survey_feature, kHatsSurveyEnSiteID,
                                            kHatsSurveyEnSiteIDDefault)
                .Get()));
  }
  // Ensure a default survey exists (for demo purpose).
  if (survey_configs_by_triggers_.find(kHatsSurveyTriggerSatisfaction) ==
      survey_configs_by_triggers_.end()) {
    survey_configs_by_triggers_.emplace(
        kHatsSurveyTriggerSatisfaction,
        SurveyConfig(kHatsSurveyProbabilityDefault,
                     kHatsSurveyEnSiteIDDefault));
  }
}

HatsService::~HatsService() = default;

// static
void HatsService::RegisterProfilePrefs(PrefRegistrySimple* registry) {
  registry->RegisterDictionaryPref(prefs::kHatsSurveyMetadata);
}

void HatsService::LaunchSurvey(const std::string& trigger) {
  if (ShouldShowSurvey(trigger)) {
    Browser* browser = chrome::FindLastActive();
    // Never show HaTS bubble for Incognito mode.
    if (browser && browser->is_type_normal() &&
        profiles::IsRegularOrGuestSession(browser)) {
      // Incognito mode needs to be enabled to create an off-the-record profile
      // for HaTS dialog.
      if (IncognitoModePrefs::GetAvailability(profile_->GetPrefs()) ==
          IncognitoModePrefs::DISABLED) {
        UMA_HISTOGRAM_ENUMERATION(
            kHatsShouldShowSurveyReasonHistogram,
            ShouldShowSurveyReasons::kNoIncognitoDisabled);
        return;
      }

      // HaTS cannot be accessed when cookies are blocked.
      if (profile_->GetPrefs()->GetInteger(
              content_settings::WebsiteSettingsRegistry::GetInstance()
                  ->Get(ContentSettingsType::COOKIES)
                  ->default_value_pref_name()) == CONTENT_SETTING_BLOCK) {
        UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                                  ShouldShowSurveyReasons::kNoCookiesBlocked);
        return;
      }

      // HaTS cannot be accessed when third-party cookies are blocked.
      // TODO(crbug/1056654): Confirm whether third-party cookie blocking in
      // incognito mode should affect HaTS.
      if (profile_->GetPrefs()->GetBoolean(prefs::kBlockThirdPartyCookies) ||
          (base::FeatureList::IsEnabled(
               content_settings::kImprovedCookieControls) &&
           static_cast<content_settings::CookieControlsMode>(
               profile_->GetPrefs()->GetInteger(prefs::kCookieControlsMode)) !=
               content_settings::CookieControlsMode::kOff)) {
        UMA_HISTOGRAM_ENUMERATION(
            kHatsShouldShowSurveyReasonHistogram,
            ShouldShowSurveyReasons::kNoThirdPartyCookiesBlocked);
        return;
      }

      UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                                ShouldShowSurveyReasons::kYes);
      browser->window()->ShowHatsBubble(
          survey_configs_by_triggers_.at(trigger).en_site_id_);

      DictionaryPrefUpdate update(profile_->GetPrefs(),
                                  prefs::kHatsSurveyMetadata);
      base::DictionaryValue* pref_data = update.Get();
      pref_data->SetIntPath(GetMajorVersionPath(trigger),
                            version_info::GetVersion().components()[0]);
      pref_data->SetPath(GetLastSurveyStartedTime(trigger),
                         util::TimeToValue(base::Time::Now()));
    } else {
      UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                                ShouldShowSurveyReasons::kNoNotRegularBrowser);
    }
  }
}

void HatsService::SetSurveyMetadataForTesting(
    const HatsService::SurveyMetadata& metadata) {
  const std::string& trigger = kHatsSurveyTriggerSatisfaction;
  DictionaryPrefUpdate update(profile_->GetPrefs(), prefs::kHatsSurveyMetadata);
  base::DictionaryValue* pref_data = update.Get();
  if (!metadata.last_major_version.has_value() &&
      !metadata.last_survey_started_time.has_value()) {
    pref_data->RemovePath(trigger);
  }

  if (metadata.last_major_version.has_value()) {
    pref_data->SetIntPath(GetMajorVersionPath(trigger),
                          *metadata.last_major_version);
  } else {
    pref_data->RemovePath(GetMajorVersionPath(trigger));
  }

  if (metadata.last_survey_started_time.has_value()) {
    pref_data->SetPath(GetLastSurveyStartedTime(trigger),
                       util::TimeToValue(*metadata.last_survey_started_time));
  } else {
    pref_data->RemovePath(GetLastSurveyStartedTime(trigger));
  }
}

bool HatsService::ShouldShowSurvey(const std::string& trigger) const {
  // Survey should not be loaded if the corresponding survey config is
  // unavailable.
  if (survey_configs_by_triggers_.find(trigger) ==
      survey_configs_by_triggers_.end()) {
    UMA_HISTOGRAM_ENUMERATION(
        kHatsShouldShowSurveyReasonHistogram,
        ShouldShowSurveyReasons::kNoTriggerStringMismatch);
    return false;
  }

  if (base::FeatureList::IsEnabled(
          features::kHappinessTrackingSurveysForDesktopDemo)) {
    // Always show the survey in demo mode.
    return true;
  }

  // Survey can not be loaded and shown if there is no network connection.
  if (net::NetworkChangeNotifier::IsOffline()) {
    UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                              ShouldShowSurveyReasons::kNoOffline);
    return false;
  }

  bool consent_given =
      g_browser_process->GetMetricsServicesManager()->IsMetricsConsentGiven();
  if (!consent_given)
    return false;

  if (profile_->GetLastSessionExitType() == Profile::EXIT_CRASHED) {
    UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                              ShouldShowSurveyReasons::kNoLastSessionCrashed);
    return false;
  }

  const base::DictionaryValue* pref_data =
      profile_->GetPrefs()->GetDictionary(prefs::kHatsSurveyMetadata);
  base::Optional<int> last_major_version =
      pref_data->FindIntPath(GetMajorVersionPath(trigger));
  if (last_major_version.has_value() &&
      static_cast<uint32_t>(*last_major_version) ==
          version_info::GetVersion().components()[0]) {
    UMA_HISTOGRAM_ENUMERATION(
        kHatsShouldShowSurveyReasonHistogram,
        ShouldShowSurveyReasons::kNoReceivedSurveyInCurrentMilestone);
    return false;
  }

  base::Time now = base::Time::Now();

  if ((now - profile_->GetCreationTime()) < kMinimumProfileAge) {
    UMA_HISTOGRAM_ENUMERATION(kHatsShouldShowSurveyReasonHistogram,
                              ShouldShowSurveyReasons::kNoProfileTooNew);
    return false;
  }

  base::Optional<base::Time> last_survey_started_time =
      util::ValueToTime(pref_data->FindPath(GetLastSurveyStartedTime(trigger)));
  if (last_survey_started_time.has_value()) {
    base::TimeDelta elapsed_time_since_last_start =
        now - *last_survey_started_time;
    if (elapsed_time_since_last_start < kMinimumTimeBetweenSurveyStarts) {
      UMA_HISTOGRAM_ENUMERATION(
          kHatsShouldShowSurveyReasonHistogram,
          ShouldShowSurveyReasons::kNoLastSurveyTooRecent);
      return false;
    }
  }

  auto probability_ = survey_configs_by_triggers_.at(trigger).probability_;
  bool should_show_survey = base::RandDouble() < probability_;
  if (!should_show_survey) {
    UMA_HISTOGRAM_ENUMERATION(
        kHatsShouldShowSurveyReasonHistogram,
        ShouldShowSurveyReasons::kNoBelowProbabilityLimit);
  }

  return should_show_survey;
}
