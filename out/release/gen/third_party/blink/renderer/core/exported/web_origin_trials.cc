// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/public/web/web_origin_trials.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/web/web_document.h"

namespace blink {

bool WebOriginTrials::isTrialEnabled(const WebDocument* web_document, const WebString& trial) {
  if (!web_document) return false;
  if (!origin_trials::IsTrialValid(trial))
    return false;
  const Vector<OriginTrialFeature>& features = origin_trials::FeaturesForTrial(trial);
  for (OriginTrialFeature feature : features) {
    switch (feature) {
      case OriginTrialFeature::kAccessibilityExposeARIAAnnotations:
        if (!RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kAllowSyncXHRInPageDismissal:
        if (!RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kAnimationWorklet:
        if (!RuntimeEnabledFeatures::AnimationWorkletEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kAutoPictureInPicture:
        if (!RuntimeEnabledFeatures::AutoPictureInPictureEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kBuiltInModuleInfra:
        if (!RuntimeEnabledFeatures::BuiltInModuleInfraEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kBuiltInModuleKvStorage:
        if (!RuntimeEnabledFeatures::BuiltInModuleKvStorageEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCacheStorageCodeCacheHint:
        if (!RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kContactsManagerExtraProperties:
        if (!RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kContentIndex:
        if (!RuntimeEnabledFeatures::ContentIndexEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kCustomElementsV0:
        if (!RuntimeEnabledFeatures::CustomElementsV0Enabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kDisableHardwareNoiseSuppression:
        if (!RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kDisplayLocking:
        if (!RuntimeEnabledFeatures::DisplayLockingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kEventTiming:
        if (!RuntimeEnabledFeatures::EventTimingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalAutoplayDynamicDelegation:
        if (!RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalIsInputPending:
        if (!RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kExperimentalJSProfiler:
        if (!RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kFeaturePolicyReporting:
        if (!RuntimeEnabledFeatures::FeaturePolicyReportingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kHrefTranslate:
        if (!RuntimeEnabledFeatures::HrefTranslateEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kHTMLImports:
        if (!RuntimeEnabledFeatures::HTMLImportsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kNativeFileSystem:
        if (!RuntimeEnabledFeatures::NativeFileSystemEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kNotificationTriggers:
        if (!RuntimeEnabledFeatures::NotificationTriggersEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPI:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
        if (!RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPageFreezeOptIn:
        if (!RuntimeEnabledFeatures::PageFreezeOptInEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPageFreezeOptOut:
        if (!RuntimeEnabledFeatures::PageFreezeOptOutEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
        if (!RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPNaCl:
        if (!RuntimeEnabledFeatures::PNaClEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPointerLockOptions:
        if (!RuntimeEnabledFeatures::PointerLockOptionsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kPriorityHints:
        if (!RuntimeEnabledFeatures::PriorityHintsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
        if (!RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRtcAudioJitterBufferRtxHandling:
        if (!RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCIceTransportExtension:
        if (!RuntimeEnabledFeatures::RTCIceTransportExtensionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCQuicTransport:
        if (!RuntimeEnabledFeatures::RTCQuicTransportEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
        if (!RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kScrollTimeline:
        if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSerial:
        if (!RuntimeEnabledFeatures::SerialEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kShadowDOMV0:
        if (!RuntimeEnabledFeatures::ShadowDOMV0Enabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSignatureBasedIntegrity:
        if (!RuntimeEnabledFeatures::SignatureBasedIntegrityEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSignedExchangeSubresourcePrefetch:
        if (!RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSkipAd:
        if (!RuntimeEnabledFeatures::SkipAdEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kSmsReceiver:
        if (!RuntimeEnabledFeatures::SmsReceiverEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTextFragmentIdentifiers:
        if (!RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kTouchEventFeatureDetection:
        if (!RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kUnoptimizedImagePolicies:
        if (!RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kUnsizedMediaPolicy:
        if (!RuntimeEnabledFeatures::UnsizedMediaPolicyEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWakeLock:
        if (!RuntimeEnabledFeatures::WakeLockEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebAssemblyThreads:
        if (!RuntimeEnabledFeatures::WebAssemblyThreadsEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebNFC:
        if (!RuntimeEnabledFeatures::WebNFCEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebScheduler:
        if (!RuntimeEnabledFeatures::WebSchedulerEnabled(*web_document))
          return false;
        break;
      case OriginTrialFeature::kWebSocketStream:
        if (!RuntimeEnabledFeatures::WebSocketStreamEnabled(*web_document))
          return false;
        break;
      default:
        break;
    }
  }
  return true;
}


} // namespace blink
