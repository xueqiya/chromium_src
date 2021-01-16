// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"

#include "third_party/blink/renderer/core/origin_trials/origin_trial_context.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"

namespace blink {

using TrialToFeaturesMap = HashMap<String, Vector<OriginTrialFeature>>;

namespace {

const TrialToFeaturesMap& GetTrialToFeaturesMap() {
  // The object needs to be thread-safe because service workers can call this
  // function as well.
  DEFINE_THREAD_SAFE_STATIC_LOCAL(TrialToFeaturesMap, trial_to_features_map, ());
  if (trial_to_features_map.IsEmpty()) {
    trial_to_features_map.Set("FeaturePolicyReporting",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kFeaturePolicyReporting,  }));
    trial_to_features_map.Set("BuiltInModuleKvStorage",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kBuiltInModuleKvStorage,  }));
    trial_to_features_map.Set("PageFreezeOptIn",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPageFreezeOptIn,  }));
    trial_to_features_map.Set("PerMethodCanMakePaymentQuota",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPerMethodCanMakePaymentQuota,  }));
    trial_to_features_map.Set("PointerLockOptions",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPointerLockOptions,  }));
    trial_to_features_map.Set("WebComponentsV0",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kCustomElementsV0,OriginTrialFeature::kHTMLImports,OriginTrialFeature::kShadowDOMV0,  }));
    trial_to_features_map.Set("DisableHardwareNoiseSuppression",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kDisableHardwareNoiseSuppression,  }));
    trial_to_features_map.Set("ContentIndex",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kContentIndex,  }));
    trial_to_features_map.Set("HrefTranslate",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kHrefTranslate,  }));
    trial_to_features_map.Set("PageFreezeOptOut",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPageFreezeOptOut,  }));
    trial_to_features_map.Set("PriorityHints",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPriorityHints,  }));
    trial_to_features_map.Set("DisplayLocking",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kDisplayLocking,  }));
    trial_to_features_map.Set("FrobulateDeprecation",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kOriginTrialsSampleAPIDeprecation,  }));
    trial_to_features_map.Set("RtcAudioJitterBufferMaxPackets",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kRtcAudioJitterBufferMaxPackets,  }));
    trial_to_features_map.Set("UnsizedMediaPolicy",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kUnsizedMediaPolicy,  }));
    trial_to_features_map.Set("SkipAd",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kSkipAd,  }));
    trial_to_features_map.Set("AutoPictureInPicture",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kAutoPictureInPicture,  }));
    trial_to_features_map.Set("SignatureBasedIntegrity",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kSignatureBasedIntegrity,  }));
    trial_to_features_map.Set("FrobulateImplied",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kOriginTrialsSampleAPIImplied,  }));
    trial_to_features_map.Set("ExperimentalJSProfiler",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kExperimentalJSProfiler,  }));
    trial_to_features_map.Set("WebNFC",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kWebNFC,  }));
    trial_to_features_map.Set("RTCQuicTransport",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kRTCIceTransportExtension,OriginTrialFeature::kRTCQuicTransport,  }));
    trial_to_features_map.Set("SignedExchangeSubresourcePrefetch",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kSignedExchangeSubresourcePrefetch,  }));
    trial_to_features_map.Set("ExperimentalAutoplayDynamicDelegation",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kExperimentalAutoplayDynamicDelegation,  }));
    trial_to_features_map.Set("NotificationTriggers",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kNotificationTriggers,  }));
    trial_to_features_map.Set("TextFragmentIdentifiers",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kTextFragmentIdentifiers,  }));
    trial_to_features_map.Set("ContactsManagerExtraProperties",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kContactsManagerExtraProperties,  }));
    trial_to_features_map.Set("WebScheduler",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kWebScheduler,  }));
    trial_to_features_map.Set("CacheStorageCodeCacheHint",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kCacheStorageCodeCacheHint,  }));
    trial_to_features_map.Set("AllowSyncXHRInPageDismissal",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kAllowSyncXHRInPageDismissal,  }));
    trial_to_features_map.Set("SmsReceiver",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kSmsReceiver,  }));
    trial_to_features_map.Set("ForceTouchEventFeatureDetectionForInspector",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kTouchEventFeatureDetection,  }));
    trial_to_features_map.Set("FrobulateInvalidOS",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS,  }));
    trial_to_features_map.Set("WebAssemblyThreads",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kWebAssemblyThreads,  }));
    trial_to_features_map.Set("EventTiming",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kEventTiming,  }));
    trial_to_features_map.Set("PNaCl",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kPNaCl,  }));
    trial_to_features_map.Set("ExperimentalIsInputPending",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kExperimentalIsInputPending,  }));
    trial_to_features_map.Set("NativeFileSystem",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kNativeFileSystem,  }));
    trial_to_features_map.Set("RtcAudioJitterBufferRtxHandling",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kRtcAudioJitterBufferRtxHandling,  }));
    trial_to_features_map.Set("WakeLock",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kWakeLock,  }));
    trial_to_features_map.Set("AnimationWorklet",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kAnimationWorklet,OriginTrialFeature::kScrollTimeline,  }));
    trial_to_features_map.Set("AccessibilityExposeARIAAnnotations",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kAccessibilityExposeARIAAnnotations,  }));
    trial_to_features_map.Set("WebSocketStream",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kWebSocketStream,  }));
    trial_to_features_map.Set("RTCStatsRelativePacketArrivalDelay",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay,  }));
    trial_to_features_map.Set("FrobulateNavigation",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kOriginTrialsSampleAPINavigation,  }));
    trial_to_features_map.Set("Serial",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kSerial,  }));
    trial_to_features_map.Set("BuiltInModuleInfra",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kBuiltInModuleInfra,  }));
    trial_to_features_map.Set("UnoptimizedImagePolicies",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kUnoptimizedImagePolicies,  }));
    trial_to_features_map.Set("Frobulate",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kOriginTrialsSampleAPI,  }));
    // For testing
    trial_to_features_map.Set("This trial does not exist",
                              Vector<OriginTrialFeature>({OriginTrialFeature::kNonExisting}));
  }
  return trial_to_features_map;
}

} // namespace

bool origin_trials::IsTrialValid(const String& trial_name) {
  return GetTrialToFeaturesMap().Contains(trial_name);
}

bool origin_trials::IsTrialEnabledForInsecureContext(const String& trial_name) {
  if (trial_name == "WebComponentsV0") {
    return true;
  }
  if (trial_name == "WebComponentsV0") {
    return true;
  }
  if (trial_name == "FrobulateDeprecation") {
    return true;
  }
  if (trial_name == "WebComponentsV0") {
    return true;
  }
  return false;
}

OriginTrialType origin_trials::GetTrialType(OriginTrialFeature feature) {
  switch (feature) {
    case OriginTrialFeature::kCustomElementsV0:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kHTMLImports:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
      return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kShadowDOMV0:
      return OriginTrialType::kDeprecation;
    default:
      return OriginTrialType::kDefault;
  }
}

const Vector<OriginTrialFeature>& origin_trials::FeaturesForTrial(const String& trial_name) {
  DCHECK(IsTrialValid(trial_name));
  return GetTrialToFeaturesMap().find(trial_name)->value;
}

Vector<OriginTrialFeature> origin_trials::GetImpliedFeatures(OriginTrialFeature feature) {
  if (feature == OriginTrialFeature::kOriginTrialsSampleAPI) {
    Vector<OriginTrialFeature> implied_features = {OriginTrialFeature::kOriginTrialsSampleAPIImplied,};
    return implied_features;
  }
  if (feature == OriginTrialFeature::kBuiltInModuleKvStorage) {
    Vector<OriginTrialFeature> implied_features = {OriginTrialFeature::kBuiltInModuleInfra,};
    return implied_features;
  }
  if (feature == OriginTrialFeature::kAnimationWorklet) {
    Vector<OriginTrialFeature> implied_features = {OriginTrialFeature::kScrollTimeline,};
    return implied_features;
  }
  if (feature == OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS) {
    Vector<OriginTrialFeature> implied_features = {OriginTrialFeature::kOriginTrialsSampleAPIImplied,};
    return implied_features;
  }
  return Vector<OriginTrialFeature>();
}

bool origin_trials::FeatureEnabledForOS(OriginTrialFeature feature) {
  switch (feature) {
    case OriginTrialFeature::kAccessibilityExposeARIAAnnotations:
      return true;
    case OriginTrialFeature::kAllowSyncXHRInPageDismissal:
      return true;
    case OriginTrialFeature::kAnimationWorklet:
      return true;
    case OriginTrialFeature::kAutoPictureInPicture:
      return true;
    case OriginTrialFeature::kBuiltInModuleInfra:
      return true;
    case OriginTrialFeature::kBuiltInModuleKvStorage:
      return true;
    case OriginTrialFeature::kCacheStorageCodeCacheHint:
      return true;
    case OriginTrialFeature::kContactsManagerExtraProperties:
#if defined(OS_ANDROID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kContentIndex:
#if defined(OS_ANDROID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kCustomElementsV0:
      return true;
    case OriginTrialFeature::kDisableHardwareNoiseSuppression:
      return true;
    case OriginTrialFeature::kDisplayLocking:
      return true;
    case OriginTrialFeature::kEventTiming:
      return true;
    case OriginTrialFeature::kExperimentalAutoplayDynamicDelegation:
      return true;
    case OriginTrialFeature::kExperimentalIsInputPending:
      return true;
    case OriginTrialFeature::kExperimentalJSProfiler:
      return true;
    case OriginTrialFeature::kFeaturePolicyReporting:
      return true;
    case OriginTrialFeature::kHrefTranslate:
      return true;
    case OriginTrialFeature::kHTMLImports:
      return true;
    case OriginTrialFeature::kNativeFileSystem:
#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kNotificationTriggers:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPI:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
      return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
#if defined(OS_INVALID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
      return true;
    case OriginTrialFeature::kPageFreezeOptIn:
      return true;
    case OriginTrialFeature::kPageFreezeOptOut:
      return true;
    case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
      return true;
    case OriginTrialFeature::kPNaCl:
      return true;
    case OriginTrialFeature::kPointerLockOptions:
      return true;
    case OriginTrialFeature::kPriorityHints:
      return true;
    case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
      return true;
    case OriginTrialFeature::kRtcAudioJitterBufferRtxHandling:
      return true;
    case OriginTrialFeature::kRTCIceTransportExtension:
      return true;
    case OriginTrialFeature::kRTCQuicTransport:
      return true;
    case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
      return true;
    case OriginTrialFeature::kScrollTimeline:
      return true;
    case OriginTrialFeature::kSerial:
      return true;
    case OriginTrialFeature::kShadowDOMV0:
      return true;
    case OriginTrialFeature::kSignatureBasedIntegrity:
      return true;
    case OriginTrialFeature::kSignedExchangeSubresourcePrefetch:
      return true;
    case OriginTrialFeature::kSkipAd:
      return true;
    case OriginTrialFeature::kSmsReceiver:
#if defined(OS_ANDROID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kTextFragmentIdentifiers:
      return true;
    case OriginTrialFeature::kTouchEventFeatureDetection:
      return true;
    case OriginTrialFeature::kUnoptimizedImagePolicies:
      return true;
    case OriginTrialFeature::kUnsizedMediaPolicy:
      return true;
    case OriginTrialFeature::kWakeLock:
      return true;
    case OriginTrialFeature::kWebAssemblyThreads:
      return true;
    case OriginTrialFeature::kWebNFC:
#if defined(OS_ANDROID)
      return true;
#else
      return false;
#endif
    case OriginTrialFeature::kWebScheduler:
      return true;
    case OriginTrialFeature::kWebSocketStream:
      return true;
    // For testing
    case OriginTrialFeature::kNonExisting:
      return true;
  }
}

} // namespace blink
