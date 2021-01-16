// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features_test_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/assertions.h"

namespace blink {

template <bool (&getter)(), void (&setter)(bool)>
class ScopedRuntimeEnabledFeatureForTest {
 public:
  ScopedRuntimeEnabledFeatureForTest(bool enabled)
      : enabled_(enabled), original_(getter()) {
    setter(enabled);
  }

  ~ScopedRuntimeEnabledFeatureForTest() {
    CHECK_EQ(enabled_, getter());
    setter(original_);
  }

 private:
  bool enabled_;
  bool original_;
};

typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::Accelerated2dCanvasEnabled,
    RuntimeEnabledFeatures::SetAccelerated2dCanvasEnabled>
    ScopedAccelerated2dCanvasForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AcceleratedSmallCanvasesEnabled,
    RuntimeEnabledFeatures::SetAcceleratedSmallCanvasesEnabled>
    ScopedAcceleratedSmallCanvasesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetAccessibilityExposeARIAAnnotationsEnabled>
    ScopedAccessibilityExposeARIAAnnotationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AccessibilityExposeDisplayNoneEnabled,
    RuntimeEnabledFeatures::SetAccessibilityExposeDisplayNoneEnabled>
    ScopedAccessibilityExposeDisplayNoneForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AccessibilityObjectModelEnabled,
    RuntimeEnabledFeatures::SetAccessibilityObjectModelEnabled>
    ScopedAccessibilityObjectModelForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AddressSpaceEnabled,
    RuntimeEnabledFeatures::SetAddressSpaceEnabled>
    ScopedAddressSpaceForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AdTaggingEnabled,
    RuntimeEnabledFeatures::SetAdTaggingEnabled>
    ScopedAdTaggingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AllowActivationDelegationAttrEnabled,
    RuntimeEnabledFeatures::SetAllowActivationDelegationAttrEnabled>
    ScopedAllowActivationDelegationAttrForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AllowContentInitiatedDataUrlNavigationsEnabled,
    RuntimeEnabledFeatures::SetAllowContentInitiatedDataUrlNavigationsEnabled>
    ScopedAllowContentInitiatedDataUrlNavigationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetAllowSyncXHRInPageDismissalEnabled>
    ScopedAllowSyncXHRInPageDismissalForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AnimationWorkletEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetAnimationWorkletEnabled>
    ScopedAnimationWorkletForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AOMAriaPropertiesEnabled,
    RuntimeEnabledFeatures::SetAOMAriaPropertiesEnabled>
    ScopedAOMAriaPropertiesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled,
    RuntimeEnabledFeatures::SetAOMAriaRelationshipPropertiesEnabled>
    ScopedAOMAriaRelationshipPropertiesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AspectRatioFromWidthAndHeightEnabled,
    RuntimeEnabledFeatures::SetAspectRatioFromWidthAndHeightEnabled>
    ScopedAspectRatioFromWidthAndHeightForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AsyncClipboardEnabled,
    RuntimeEnabledFeatures::SetAsyncClipboardEnabled>
    ScopedAsyncClipboardForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AudioOutputDevicesEnabled,
    RuntimeEnabledFeatures::SetAudioOutputDevicesEnabled>
    ScopedAudioOutputDevicesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AudioVideoTracksEnabled,
    RuntimeEnabledFeatures::SetAudioVideoTracksEnabled>
    ScopedAudioVideoTracksForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AudioWorkletRealtimeThreadEnabled,
    RuntimeEnabledFeatures::SetAudioWorkletRealtimeThreadEnabled>
    ScopedAudioWorkletRealtimeThreadForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutoLazyLoadOnReloadsEnabled,
    RuntimeEnabledFeatures::SetAutoLazyLoadOnReloadsEnabled>
    ScopedAutoLazyLoadOnReloadsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutomaticLazyFrameLoadingEnabled,
    RuntimeEnabledFeatures::SetAutomaticLazyFrameLoadingEnabled>
    ScopedAutomaticLazyFrameLoadingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutomaticLazyImageLoadingEnabled,
    RuntimeEnabledFeatures::SetAutomaticLazyImageLoadingEnabled>
    ScopedAutomaticLazyImageLoadingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutomationControlledEnabled,
    RuntimeEnabledFeatures::SetAutomationControlledEnabled>
    ScopedAutomationControlledForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutoPictureInPictureEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetAutoPictureInPictureEnabled>
    ScopedAutoPictureInPictureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::AutoplayIgnoresWebAudioEnabled,
    RuntimeEnabledFeatures::SetAutoplayIgnoresWebAudioEnabled>
    ScopedAutoplayIgnoresWebAudioForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BackForwardCacheEnabled,
    RuntimeEnabledFeatures::SetBackForwardCacheEnabled>
    ScopedBackForwardCacheForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BackgroundFetchEnabled,
    RuntimeEnabledFeatures::SetBackgroundFetchEnabled>
    ScopedBackgroundFetchForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BackgroundVideoTrackOptimizationEnabled,
    RuntimeEnabledFeatures::SetBackgroundVideoTrackOptimizationEnabled>
    ScopedBackgroundVideoTrackOptimizationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BadgingEnabled,
    RuntimeEnabledFeatures::SetBadgingEnabled>
    ScopedBadgingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BidiCaretAffinityEnabled,
    RuntimeEnabledFeatures::SetBidiCaretAffinityEnabled>
    ScopedBidiCaretAffinityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlinkRuntimeCallStatsEnabled,
    RuntimeEnabledFeatures::SetBlinkRuntimeCallStatsEnabled>
    ScopedBlinkRuntimeCallStatsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlobReadMethodsEnabled,
    RuntimeEnabledFeatures::SetBlobReadMethodsEnabled>
    ScopedBlobReadMethodsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlockCredentialedSubresourcesEnabled,
    RuntimeEnabledFeatures::SetBlockCredentialedSubresourcesEnabled>
    ScopedBlockCredentialedSubresourcesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlockHTMLParserOnStyleSheetsEnabled,
    RuntimeEnabledFeatures::SetBlockHTMLParserOnStyleSheetsEnabled>
    ScopedBlockHTMLParserOnStyleSheetsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlockingDownloadsInSandboxEnabled,
    RuntimeEnabledFeatures::SetBlockingDownloadsInSandboxEnabled>
    ScopedBlockingDownloadsInSandboxForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled,
    RuntimeEnabledFeatures::SetBlockingFocusWithoutUserActivationEnabled>
    ScopedBlockingFocusWithoutUserActivationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BrowserVerifiedUserActivationKeyboardEnabled,
    RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationKeyboardEnabled>
    ScopedBrowserVerifiedUserActivationKeyboardForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BrowserVerifiedUserActivationMouseEnabled,
    RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationMouseEnabled>
    ScopedBrowserVerifiedUserActivationMouseForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BuiltInModuleAllEnabled,
    RuntimeEnabledFeatures::SetBuiltInModuleAllEnabled>
    ScopedBuiltInModuleAllForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BuiltInModuleInfraEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetBuiltInModuleInfraEnabled>
    ScopedBuiltInModuleInfraForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BuiltInModuleKvStorageEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetBuiltInModuleKvStorageEnabled>
    ScopedBuiltInModuleKvStorageForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::BuiltInModuleSwitchElementEnabled,
    RuntimeEnabledFeatures::SetBuiltInModuleSwitchElementEnabled>
    ScopedBuiltInModuleSwitchElementForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CacheInlineScriptCodeEnabled,
    RuntimeEnabledFeatures::SetCacheInlineScriptCodeEnabled>
    ScopedCacheInlineScriptCodeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetCacheStorageCodeCacheHintEnabled>
    ScopedCacheStorageCodeCacheHintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::Canvas2dContextLostRestoredEnabled,
    RuntimeEnabledFeatures::SetCanvas2dContextLostRestoredEnabled>
    ScopedCanvas2dContextLostRestoredForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::Canvas2dImageChromiumEnabled,
    RuntimeEnabledFeatures::SetCanvas2dImageChromiumEnabled>
    ScopedCanvas2dImageChromiumForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::Canvas2dScrollPathIntoViewEnabled,
    RuntimeEnabledFeatures::SetCanvas2dScrollPathIntoViewEnabled>
    ScopedCanvas2dScrollPathIntoViewForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CanvasColorManagementEnabled,
    RuntimeEnabledFeatures::SetCanvasColorManagementEnabled>
    ScopedCanvasColorManagementForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CanvasHitRegionEnabled,
    RuntimeEnabledFeatures::SetCanvasHitRegionEnabled>
    ScopedCanvasHitRegionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CanvasImageSmoothingEnabled,
    RuntimeEnabledFeatures::SetCanvasImageSmoothingEnabled>
    ScopedCanvasImageSmoothingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ClickPointerEventEnabled,
    RuntimeEnabledFeatures::SetClickPointerEventEnabled>
    ScopedClickPointerEventForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ClickRetargettingEnabled,
    RuntimeEnabledFeatures::SetClickRetargettingEnabled>
    ScopedClickRetargettingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CloneableNativeFileSystemHandlesEnabled,
    RuntimeEnabledFeatures::SetCloneableNativeFileSystemHandlesEnabled>
    ScopedCloneableNativeFileSystemHandlesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CompositeAfterPaintEnabled,
    RuntimeEnabledFeatures::SetCompositeAfterPaintEnabled>
    ScopedCompositeAfterPaintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CompositedSelectionUpdateEnabled,
    RuntimeEnabledFeatures::SetCompositedSelectionUpdateEnabled>
    ScopedCompositedSelectionUpdateForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CompositorTouchActionEnabled,
    RuntimeEnabledFeatures::SetCompositorTouchActionEnabled>
    ScopedCompositorTouchActionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ComputedAccessibilityInfoEnabled,
    RuntimeEnabledFeatures::SetComputedAccessibilityInfoEnabled>
    ScopedComputedAccessibilityInfoForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ConsolidatedMovementXYEnabled,
    RuntimeEnabledFeatures::SetConsolidatedMovementXYEnabled>
    ScopedConsolidatedMovementXYForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ContactsManagerEnabled,
    RuntimeEnabledFeatures::SetContactsManagerEnabled>
    ScopedContactsManagerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetContactsManagerExtraPropertiesEnabled>
    ScopedContactsManagerExtraPropertiesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ContentIndexEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetContentIndexEnabled>
    ScopedContentIndexForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ContextMenuEnabled,
    RuntimeEnabledFeatures::SetContextMenuEnabled>
    ScopedContextMenuForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CookieDeprecationMessagesEnabled,
    RuntimeEnabledFeatures::SetCookieDeprecationMessagesEnabled>
    ScopedCookieDeprecationMessagesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CookieStoreDocumentEnabled,
    RuntimeEnabledFeatures::SetCookieStoreDocumentEnabled>
    ScopedCookieStoreDocumentForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CookieStoreWorkerEnabled,
    RuntimeEnabledFeatures::SetCookieStoreWorkerEnabled>
    ScopedCookieStoreWorkerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CookiesWithoutSameSiteMustBeSecureEnabled,
    RuntimeEnabledFeatures::SetCookiesWithoutSameSiteMustBeSecureEnabled>
    ScopedCookiesWithoutSameSiteMustBeSecureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CooperativeSchedulingEnabled,
    RuntimeEnabledFeatures::SetCooperativeSchedulingEnabled>
    ScopedCooperativeSchedulingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CorsRFC1918Enabled,
    RuntimeEnabledFeatures::SetCorsRFC1918Enabled>
    ScopedCorsRFC1918ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSS3TextEnabled,
    RuntimeEnabledFeatures::SetCSS3TextEnabled>
    ScopedCSS3TextForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSS3TextBreakAnywhereEnabled,
    RuntimeEnabledFeatures::SetCSS3TextBreakAnywhereEnabled>
    ScopedCSS3TextBreakAnywhereForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSAdditiveAnimationsEnabled,
    RuntimeEnabledFeatures::SetCSSAdditiveAnimationsEnabled>
    ScopedCSSAdditiveAnimationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSCalcAsIntEnabled,
    RuntimeEnabledFeatures::SetCSSCalcAsIntEnabled>
    ScopedCSSCalcAsIntForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSCascadeEnabled,
    RuntimeEnabledFeatures::SetCSSCascadeEnabled>
    ScopedCSSCascadeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSColorSchemeEnabled,
    RuntimeEnabledFeatures::SetCSSColorSchemeEnabled>
    ScopedCSSColorSchemeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSColorSchemeUARenderingEnabled,
    RuntimeEnabledFeatures::SetCSSColorSchemeUARenderingEnabled>
    ScopedCSSColorSchemeUARenderingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSFocusVisibleEnabled,
    RuntimeEnabledFeatures::SetCSSFocusVisibleEnabled>
    ScopedCSSFocusVisibleForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled,
    RuntimeEnabledFeatures::SetCSSFontSizeAdjustEnabled>
    ScopedCSSFontSizeAdjustForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSHexAlphaColorEnabled,
    RuntimeEnabledFeatures::SetCSSHexAlphaColorEnabled>
    ScopedCSSHexAlphaColorForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled,
    RuntimeEnabledFeatures::SetCSSIndependentTransformPropertiesEnabled>
    ScopedCSSIndependentTransformPropertiesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSIntrinsicSizeEnabled,
    RuntimeEnabledFeatures::SetCSSIntrinsicSizeEnabled>
    ScopedCSSIntrinsicSizeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSLayoutAPIEnabled,
    RuntimeEnabledFeatures::SetCSSLayoutAPIEnabled>
    ScopedCSSLayoutAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSLogicalEnabled,
    RuntimeEnabledFeatures::SetCSSLogicalEnabled>
    ScopedCSSLogicalForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSLogicalOverflowEnabled,
    RuntimeEnabledFeatures::SetCSSLogicalOverflowEnabled>
    ScopedCSSLogicalOverflowForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSMarkerPseudoElementEnabled,
    RuntimeEnabledFeatures::SetCSSMarkerPseudoElementEnabled>
    ScopedCSSMarkerPseudoElementForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSMaskSourceTypeEnabled,
    RuntimeEnabledFeatures::SetCSSMaskSourceTypeEnabled>
    ScopedCSSMaskSourceTypeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSModulesEnabled,
    RuntimeEnabledFeatures::SetCSSModulesEnabled>
    ScopedCSSModulesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSOffsetPathRayEnabled,
    RuntimeEnabledFeatures::SetCSSOffsetPathRayEnabled>
    ScopedCSSOffsetPathRayForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSOffsetPathRayContainEnabled,
    RuntimeEnabledFeatures::SetCSSOffsetPathRayContainEnabled>
    ScopedCSSOffsetPathRayContainForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled,
    RuntimeEnabledFeatures::SetCSSOffsetPositionAnchorEnabled>
    ScopedCSSOffsetPositionAnchorForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSOMViewScrollCoordinatesEnabled,
    RuntimeEnabledFeatures::SetCSSOMViewScrollCoordinatesEnabled>
    ScopedCSSOMViewScrollCoordinatesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSPaintAPIArgumentsEnabled,
    RuntimeEnabledFeatures::SetCSSPaintAPIArgumentsEnabled>
    ScopedCSSPaintAPIArgumentsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSPictureInPictureEnabled,
    RuntimeEnabledFeatures::SetCSSPictureInPictureEnabled>
    ScopedCSSPictureInPictureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSPseudoIsEnabled,
    RuntimeEnabledFeatures::SetCSSPseudoIsEnabled>
    ScopedCSSPseudoIsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSPseudoWhereEnabled,
    RuntimeEnabledFeatures::SetCSSPseudoWhereEnabled>
    ScopedCSSPseudoWhereForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSRenderSubtreeEnabled,
    RuntimeEnabledFeatures::SetCSSRenderSubtreeEnabled>
    ScopedCSSRenderSubtreeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSSnapSizeEnabled,
    RuntimeEnabledFeatures::SetCSSSnapSizeEnabled>
    ScopedCSSSnapSizeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSVariables2Enabled,
    RuntimeEnabledFeatures::SetCSSVariables2Enabled>
    ScopedCSSVariables2ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled,
    RuntimeEnabledFeatures::SetCSSVariables2AtPropertyEnabled>
    ScopedCSSVariables2AtPropertyForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSVariables2ImageValuesEnabled,
    RuntimeEnabledFeatures::SetCSSVariables2ImageValuesEnabled>
    ScopedCSSVariables2ImageValuesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSVariables2TransformValuesEnabled,
    RuntimeEnabledFeatures::SetCSSVariables2TransformValuesEnabled>
    ScopedCSSVariables2TransformValuesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CSSViewportEnabled,
    RuntimeEnabledFeatures::SetCSSViewportEnabled>
    ScopedCSSViewportForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CustomElementDefaultStyleEnabled,
    RuntimeEnabledFeatures::SetCustomElementDefaultStyleEnabled>
    ScopedCustomElementDefaultStyleForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CustomElementsV0EnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetCustomElementsV0Enabled>
    ScopedCustomElementsV0ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::CustomStatePseudoClassEnabled,
    RuntimeEnabledFeatures::SetCustomStatePseudoClassEnabled>
    ScopedCustomStatePseudoClassForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DatabaseEnabled,
    RuntimeEnabledFeatures::SetDatabaseEnabled>
    ScopedDatabaseForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DecodeJpeg420ImagesToYUVEnabled,
    RuntimeEnabledFeatures::SetDecodeJpeg420ImagesToYUVEnabled>
    ScopedDecodeJpeg420ImagesToYUVForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DecodeLossyWebPImagesToYUVEnabled,
    RuntimeEnabledFeatures::SetDecodeLossyWebPImagesToYUVEnabled>
    ScopedDecodeLossyWebPImagesToYUVForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DesktopCaptureDisableLocalEchoControlEnabled,
    RuntimeEnabledFeatures::SetDesktopCaptureDisableLocalEchoControlEnabled>
    ScopedDesktopCaptureDisableLocalEchoControlForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetDisableHardwareNoiseSuppressionEnabled>
    ScopedDisableHardwareNoiseSuppressionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DisallowDocumentAccessEnabled,
    RuntimeEnabledFeatures::SetDisallowDocumentAccessEnabled>
    ScopedDisallowDocumentAccessForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DiscardInputToMovingIframesEnabled,
    RuntimeEnabledFeatures::SetDiscardInputToMovingIframesEnabled>
    ScopedDiscardInputToMovingIframesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DisplayCutoutAPIEnabled,
    RuntimeEnabledFeatures::SetDisplayCutoutAPIEnabled>
    ScopedDisplayCutoutAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DisplayLockingEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetDisplayLockingEnabled>
    ScopedDisplayLockingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DocumentCookieEnabled,
    RuntimeEnabledFeatures::SetDocumentCookieEnabled>
    ScopedDocumentCookieForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DocumentDomainEnabled,
    RuntimeEnabledFeatures::SetDocumentDomainEnabled>
    ScopedDocumentDomainForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DocumentPolicyEnabled,
    RuntimeEnabledFeatures::SetDocumentPolicyEnabled>
    ScopedDocumentPolicyForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::DocumentWriteEnabled,
    RuntimeEnabledFeatures::SetDocumentWriteEnabled>
    ScopedDocumentWriteForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EditContextEnabled,
    RuntimeEnabledFeatures::SetEditContextEnabled>
    ScopedEditContextForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EditingNGEnabled,
    RuntimeEnabledFeatures::SetEditingNGEnabled>
    ScopedEditingNGForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EmbeddedVTTStylesheetsEnabled,
    RuntimeEnabledFeatures::SetEmbeddedVTTStylesheetsEnabled>
    ScopedEmbeddedVTTStylesheetsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EncryptedMediaEncryptionSchemeQueryEnabled,
    RuntimeEnabledFeatures::SetEncryptedMediaEncryptionSchemeQueryEnabled>
    ScopedEncryptedMediaEncryptionSchemeQueryForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EncryptedMediaHdcpPolicyCheckEnabled,
    RuntimeEnabledFeatures::SetEncryptedMediaHdcpPolicyCheckEnabled>
    ScopedEncryptedMediaHdcpPolicyCheckForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EncryptedMediaPersistentUsageRecordSessionEnabled,
    RuntimeEnabledFeatures::SetEncryptedMediaPersistentUsageRecordSessionEnabled>
    ScopedEncryptedMediaPersistentUsageRecordSessionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EnterKeyHintAttributeEnabled,
    RuntimeEnabledFeatures::SetEnterKeyHintAttributeEnabled>
    ScopedEnterKeyHintAttributeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::EventTimingEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetEventTimingEnabled>
    ScopedEventTimingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExecCommandInJavaScriptEnabled,
    RuntimeEnabledFeatures::SetExecCommandInJavaScriptEnabled>
    ScopedExecCommandInJavaScriptForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExpensiveBackgroundTimerThrottlingEnabled,
    RuntimeEnabledFeatures::SetExpensiveBackgroundTimerThrottlingEnabled>
    ScopedExpensiveBackgroundTimerThrottlingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetExperimentalAutoplayDynamicDelegationEnabled>
    ScopedExperimentalAutoplayDynamicDelegationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExperimentalContentSecurityPolicyFeaturesEnabled,
    RuntimeEnabledFeatures::SetExperimentalContentSecurityPolicyFeaturesEnabled>
    ScopedExperimentalContentSecurityPolicyFeaturesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetExperimentalIsInputPendingEnabled>
    ScopedExperimentalIsInputPendingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExperimentalJSProfilerEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetExperimentalJSProfilerEnabled>
    ScopedExperimentalJSProfilerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExperimentalProductivityFeaturesEnabled,
    RuntimeEnabledFeatures::SetExperimentalProductivityFeaturesEnabled>
    ScopedExperimentalProductivityFeaturesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExtendedTextMetricsEnabled,
    RuntimeEnabledFeatures::SetExtendedTextMetricsEnabled>
    ScopedExtendedTextMetricsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ExtraWebGLVideoTextureMetadataEnabled,
    RuntimeEnabledFeatures::SetExtraWebGLVideoTextureMetadataEnabled>
    ScopedExtraWebGLVideoTextureMetadataForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FallbackCursorModeEnabled,
    RuntimeEnabledFeatures::SetFallbackCursorModeEnabled>
    ScopedFallbackCursorModeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FeaturePolicyForClientHintsEnabled,
    RuntimeEnabledFeatures::SetFeaturePolicyForClientHintsEnabled>
    ScopedFeaturePolicyForClientHintsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FeaturePolicyForSandboxEnabled,
    RuntimeEnabledFeatures::SetFeaturePolicyForSandboxEnabled>
    ScopedFeaturePolicyForSandboxForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FeaturePolicyJavaScriptInterfaceEnabled,
    RuntimeEnabledFeatures::SetFeaturePolicyJavaScriptInterfaceEnabled>
    ScopedFeaturePolicyJavaScriptInterfaceForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FeaturePolicyReportingEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetFeaturePolicyReportingEnabled>
    ScopedFeaturePolicyReportingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FeaturePolicyVibrateFeatureEnabled,
    RuntimeEnabledFeatures::SetFeaturePolicyVibrateFeatureEnabled>
    ScopedFeaturePolicyVibrateFeatureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FetchMetadataEnabled,
    RuntimeEnabledFeatures::SetFetchMetadataEnabled>
    ScopedFetchMetadataForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FetchMetadataDestinationEnabled,
    RuntimeEnabledFeatures::SetFetchMetadataDestinationEnabled>
    ScopedFetchMetadataDestinationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FileHandlingEnabled,
    RuntimeEnabledFeatures::SetFileHandlingEnabled>
    ScopedFileHandlingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FileSystemEnabled,
    RuntimeEnabledFeatures::SetFileSystemEnabled>
    ScopedFileSystemForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FlatTreeStyleRecalcEnabled,
    RuntimeEnabledFeatures::SetFlatTreeStyleRecalcEnabled>
    ScopedFlatTreeStyleRecalcForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FocuslessSpatialNavigationEnabled,
    RuntimeEnabledFeatures::SetFocuslessSpatialNavigationEnabled>
    ScopedFocuslessSpatialNavigationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled,
    RuntimeEnabledFeatures::SetFontSrcLocalMatchingEnabled>
    ScopedFontSrcLocalMatchingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForcedColorsEnabled,
    RuntimeEnabledFeatures::SetForcedColorsEnabled>
    ScopedForcedColorsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForceDeferScriptInterventionEnabled,
    RuntimeEnabledFeatures::SetForceDeferScriptInterventionEnabled>
    ScopedForceDeferScriptInterventionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForceEagerMeasureMemoryEnabled,
    RuntimeEnabledFeatures::SetForceEagerMeasureMemoryEnabled>
    ScopedForceEagerMeasureMemoryForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForceOverlayFullscreenVideoEnabled,
    RuntimeEnabledFeatures::SetForceOverlayFullscreenVideoEnabled>
    ScopedForceOverlayFullscreenVideoForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForceSynchronousHTMLParsingEnabled,
    RuntimeEnabledFeatures::SetForceSynchronousHTMLParsingEnabled>
    ScopedForceSynchronousHTMLParsingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ForceTallerSelectPopupEnabled,
    RuntimeEnabledFeatures::SetForceTallerSelectPopupEnabled>
    ScopedForceTallerSelectPopupForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FractionalMouseEventEnabled,
    RuntimeEnabledFeatures::SetFractionalMouseEventEnabled>
    ScopedFractionalMouseEventForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled,
    RuntimeEnabledFeatures::SetFractionalScrollOffsetsEnabled>
    ScopedFractionalScrollOffsetsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled,
    RuntimeEnabledFeatures::SetFreezeFramesOnVisibilityEnabled>
    ScopedFreezeFramesOnVisibilityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::GamepadButtonAxisEventsEnabled,
    RuntimeEnabledFeatures::SetGamepadButtonAxisEventsEnabled>
    ScopedGamepadButtonAxisEventsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::GetDisplayMediaEnabled,
    RuntimeEnabledFeatures::SetGetDisplayMediaEnabled>
    ScopedGetDisplayMediaForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::GroupEffectEnabled,
    RuntimeEnabledFeatures::SetGroupEffectEnabled>
    ScopedGroupEffectForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::HrefTranslateEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetHrefTranslateEnabled>
    ScopedHrefTranslateForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::HTMLImportsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetHTMLImportsEnabled>
    ScopedHTMLImportsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IDBObserverEnabled,
    RuntimeEnabledFeatures::SetIDBObserverEnabled>
    ScopedIDBObserverForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IDBRelaxedDurabilityEnabled,
    RuntimeEnabledFeatures::SetIDBRelaxedDurabilityEnabled>
    ScopedIDBRelaxedDurabilityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IdleDetectionEnabled,
    RuntimeEnabledFeatures::SetIdleDetectionEnabled>
    ScopedIdleDetectionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled,
    RuntimeEnabledFeatures::SetIgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled>
    ScopedIgnoreCrossOriginWindowWhenNamedAccessOnWindowForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ImageOrientationEnabled,
    RuntimeEnabledFeatures::SetImageOrientationEnabled>
    ScopedImageOrientationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ImplicitRootScrollerEnabled,
    RuntimeEnabledFeatures::SetImplicitRootScrollerEnabled>
    ScopedImplicitRootScrollerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ImportMapsEnabled,
    RuntimeEnabledFeatures::SetImportMapsEnabled>
    ScopedImportMapsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::InertAttributeEnabled,
    RuntimeEnabledFeatures::SetInertAttributeEnabled>
    ScopedInertAttributeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::InputMultipleFieldsUIEnabled,
    RuntimeEnabledFeatures::SetInputMultipleFieldsUIEnabled>
    ScopedInputMultipleFieldsUIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::InstalledAppEnabled,
    RuntimeEnabledFeatures::SetInstalledAppEnabled>
    ScopedInstalledAppForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IntersectionObserverDocumentScrollingElementRootEnabled,
    RuntimeEnabledFeatures::SetIntersectionObserverDocumentScrollingElementRootEnabled>
    ScopedIntersectionObserverDocumentScrollingElementRootForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IntersectionObserverV2Enabled,
    RuntimeEnabledFeatures::SetIntersectionObserverV2Enabled>
    ScopedIntersectionObserverV2ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::InvisibleDOMEnabled,
    RuntimeEnabledFeatures::SetInvisibleDOMEnabled>
    ScopedInvisibleDOMForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IsolatedCodeCacheEnabled,
    RuntimeEnabledFeatures::SetIsolatedCodeCacheEnabled>
    ScopedIsolatedCodeCacheForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::IsolatedWorldCSPEnabled,
    RuntimeEnabledFeatures::SetIsolatedWorldCSPEnabled>
    ScopedIsolatedWorldCSPForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::KeyboardFocusableScrollersEnabled,
    RuntimeEnabledFeatures::SetKeyboardFocusableScrollersEnabled>
    ScopedKeyboardFocusableScrollersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LangAttributeAwareFormControlUIEnabled,
    RuntimeEnabledFeatures::SetLangAttributeAwareFormControlUIEnabled>
    ScopedLangAttributeAwareFormControlUIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LangClientHintHeaderEnabled,
    RuntimeEnabledFeatures::SetLangClientHintHeaderEnabled>
    ScopedLangClientHintHeaderForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGEnabled,
    RuntimeEnabledFeatures::SetLayoutNGEnabled>
    ScopedLayoutNGForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGBlockFragmentationEnabled,
    RuntimeEnabledFeatures::SetLayoutNGBlockFragmentationEnabled>
    ScopedLayoutNGBlockFragmentationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGFieldsetEnabled,
    RuntimeEnabledFeatures::SetLayoutNGFieldsetEnabled>
    ScopedLayoutNGFieldsetForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGFlexBoxEnabled,
    RuntimeEnabledFeatures::SetLayoutNGFlexBoxEnabled>
    ScopedLayoutNGFlexBoxForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGFragmentItemEnabled,
    RuntimeEnabledFeatures::SetLayoutNGFragmentItemEnabled>
    ScopedLayoutNGFragmentItemForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGFragmentPaintEnabled,
    RuntimeEnabledFeatures::SetLayoutNGFragmentPaintEnabled>
    ScopedLayoutNGFragmentPaintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGLineCacheEnabled,
    RuntimeEnabledFeatures::SetLayoutNGLineCacheEnabled>
    ScopedLayoutNGLineCacheForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LayoutNGTableEnabled,
    RuntimeEnabledFeatures::SetLayoutNGTableEnabled>
    ScopedLayoutNGTableForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyFrameLoadingEnabled,
    RuntimeEnabledFeatures::SetLazyFrameLoadingEnabled>
    ScopedLazyFrameLoadingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyFrameVisibleLoadTimeMetricsEnabled,
    RuntimeEnabledFeatures::SetLazyFrameVisibleLoadTimeMetricsEnabled>
    ScopedLazyFrameVisibleLoadTimeMetricsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyImageLoadingEnabled,
    RuntimeEnabledFeatures::SetLazyImageLoadingEnabled>
    ScopedLazyImageLoadingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyImageLoadingMetadataFetchEnabled,
    RuntimeEnabledFeatures::SetLazyImageLoadingMetadataFetchEnabled>
    ScopedLazyImageLoadingMetadataFetchForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyImageVisibleLoadTimeMetricsEnabled,
    RuntimeEnabledFeatures::SetLazyImageVisibleLoadTimeMetricsEnabled>
    ScopedLazyImageVisibleLoadTimeMetricsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LazyInitializeMediaControlsEnabled,
    RuntimeEnabledFeatures::SetLazyInitializeMediaControlsEnabled>
    ScopedLazyInitializeMediaControlsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LegacyWindowsDWriteFontFallbackEnabled,
    RuntimeEnabledFeatures::SetLegacyWindowsDWriteFontFallbackEnabled>
    ScopedLegacyWindowsDWriteFontFallbackForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::LinkSystemColorsEnabled,
    RuntimeEnabledFeatures::SetLinkSystemColorsEnabled>
    ScopedLinkSystemColorsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ManualSlottingEnabled,
    RuntimeEnabledFeatures::SetManualSlottingEnabled>
    ScopedManualSlottingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MathMLCoreEnabled,
    RuntimeEnabledFeatures::SetMathMLCoreEnabled>
    ScopedMathMLCoreForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MeasureMemoryEnabled,
    RuntimeEnabledFeatures::SetMeasureMemoryEnabled>
    ScopedMeasureMemoryForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCapabilitiesEncodingInfoEnabled,
    RuntimeEnabledFeatures::SetMediaCapabilitiesEncodingInfoEnabled>
    ScopedMediaCapabilitiesEncodingInfoForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCapabilitiesEncryptedMediaEnabled,
    RuntimeEnabledFeatures::SetMediaCapabilitiesEncryptedMediaEnabled>
    ScopedMediaCapabilitiesEncryptedMediaForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCapabilitiesSpatialAudioEnabled,
    RuntimeEnabledFeatures::SetMediaCapabilitiesSpatialAudioEnabled>
    ScopedMediaCapabilitiesSpatialAudioForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCaptureEnabled,
    RuntimeEnabledFeatures::SetMediaCaptureEnabled>
    ScopedMediaCaptureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCaptureDepthVideoKindEnabled,
    RuntimeEnabledFeatures::SetMediaCaptureDepthVideoKindEnabled>
    ScopedMediaCaptureDepthVideoKindForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCapturePanTiltEnabled,
    RuntimeEnabledFeatures::SetMediaCapturePanTiltEnabled>
    ScopedMediaCapturePanTiltForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaCastOverlayButtonEnabled,
    RuntimeEnabledFeatures::SetMediaCastOverlayButtonEnabled>
    ScopedMediaCastOverlayButtonForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaControlsExpandGestureEnabled,
    RuntimeEnabledFeatures::SetMediaControlsExpandGestureEnabled>
    ScopedMediaControlsExpandGestureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaControlsOverlayPlayButtonEnabled,
    RuntimeEnabledFeatures::SetMediaControlsOverlayPlayButtonEnabled>
    ScopedMediaControlsOverlayPlayButtonForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaDocumentDownloadButtonEnabled,
    RuntimeEnabledFeatures::SetMediaDocumentDownloadButtonEnabled>
    ScopedMediaDocumentDownloadButtonForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaElementVolumeGreaterThanOneEnabled,
    RuntimeEnabledFeatures::SetMediaElementVolumeGreaterThanOneEnabled>
    ScopedMediaElementVolumeGreaterThanOneForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaEngagementBypassAutoplayPoliciesEnabled,
    RuntimeEnabledFeatures::SetMediaEngagementBypassAutoplayPoliciesEnabled>
    ScopedMediaEngagementBypassAutoplayPoliciesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaLatencyHintEnabled,
    RuntimeEnabledFeatures::SetMediaLatencyHintEnabled>
    ScopedMediaLatencyHintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaQueryNavigationControlsEnabled,
    RuntimeEnabledFeatures::SetMediaQueryNavigationControlsEnabled>
    ScopedMediaQueryNavigationControlsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaQueryShapeEnabled,
    RuntimeEnabledFeatures::SetMediaQueryShapeEnabled>
    ScopedMediaQueryShapeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSessionEnabled,
    RuntimeEnabledFeatures::SetMediaSessionEnabled>
    ScopedMediaSessionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSessionPositionEnabled,
    RuntimeEnabledFeatures::SetMediaSessionPositionEnabled>
    ScopedMediaSessionPositionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSessionSeekingEnabled,
    RuntimeEnabledFeatures::SetMediaSessionSeekingEnabled>
    ScopedMediaSessionSeekingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSourceExperimentalEnabled,
    RuntimeEnabledFeatures::SetMediaSourceExperimentalEnabled>
    ScopedMediaSourceExperimentalForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSourceInWorkersEnabled,
    RuntimeEnabledFeatures::SetMediaSourceInWorkersEnabled>
    ScopedMediaSourceInWorkersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSourceNewAbortAndDurationEnabled,
    RuntimeEnabledFeatures::SetMediaSourceNewAbortAndDurationEnabled>
    ScopedMediaSourceNewAbortAndDurationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MediaSourceStableEnabled,
    RuntimeEnabledFeatures::SetMediaSourceStableEnabled>
    ScopedMediaSourceStableForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MetaColorSchemeEnabled,
    RuntimeEnabledFeatures::SetMetaColorSchemeEnabled>
    ScopedMetaColorSchemeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MiddleClickAutoscrollEnabled,
    RuntimeEnabledFeatures::SetMiddleClickAutoscrollEnabled>
    ScopedMiddleClickAutoscrollForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MobileLayoutThemeEnabled,
    RuntimeEnabledFeatures::SetMobileLayoutThemeEnabled>
    ScopedMobileLayoutThemeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ModuleDedicatedWorkerEnabled,
    RuntimeEnabledFeatures::SetModuleDedicatedWorkerEnabled>
    ScopedModuleDedicatedWorkerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ModuleServiceWorkerEnabled,
    RuntimeEnabledFeatures::SetModuleServiceWorkerEnabled>
    ScopedModuleServiceWorkerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ModuleSharedWorkerEnabled,
    RuntimeEnabledFeatures::SetModuleSharedWorkerEnabled>
    ScopedModuleSharedWorkerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MojoJSEnabled,
    RuntimeEnabledFeatures::SetMojoJSEnabled>
    ScopedMojoJSForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MojoJSTestEnabled,
    RuntimeEnabledFeatures::SetMojoJSTestEnabled>
    ScopedMojoJSTestForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::MouseSubframeNoImplicitCaptureEnabled,
    RuntimeEnabledFeatures::SetMouseSubframeNoImplicitCaptureEnabled>
    ScopedMouseSubframeNoImplicitCaptureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NativeFileSystemEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetNativeFileSystemEnabled>
    ScopedNativeFileSystemForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NavigatorContentUtilsEnabled,
    RuntimeEnabledFeatures::SetNavigatorContentUtilsEnabled>
    ScopedNavigatorContentUtilsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NavigatorLanguageInInsecureContextEnabled,
    RuntimeEnabledFeatures::SetNavigatorLanguageInInsecureContextEnabled>
    ScopedNavigatorLanguageInInsecureContextForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NetInfoDownlinkMaxEnabled,
    RuntimeEnabledFeatures::SetNetInfoDownlinkMaxEnabled>
    ScopedNetInfoDownlinkMaxForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NeverSlowModeEnabled,
    RuntimeEnabledFeatures::SetNeverSlowModeEnabled>
    ScopedNeverSlowModeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NewRemotePlaybackPipelineEnabled,
    RuntimeEnabledFeatures::SetNewRemotePlaybackPipelineEnabled>
    ScopedNewRemotePlaybackPipelineForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NewSystemColorsEnabled,
    RuntimeEnabledFeatures::SetNewSystemColorsEnabled>
    ScopedNewSystemColorsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NoIdleEncodingForWebTestsEnabled,
    RuntimeEnabledFeatures::SetNoIdleEncodingForWebTestsEnabled>
    ScopedNoIdleEncodingForWebTestsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NotificationConstructorEnabled,
    RuntimeEnabledFeatures::SetNotificationConstructorEnabled>
    ScopedNotificationConstructorForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NotificationContentImageEnabled,
    RuntimeEnabledFeatures::SetNotificationContentImageEnabled>
    ScopedNotificationContentImageForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NotificationsEnabled,
    RuntimeEnabledFeatures::SetNotificationsEnabled>
    ScopedNotificationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::NotificationTriggersEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetNotificationTriggersEnabled>
    ScopedNotificationTriggersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OffMainThreadCSSPaintEnabled,
    RuntimeEnabledFeatures::SetOffMainThreadCSSPaintEnabled>
    ScopedOffMainThreadCSSPaintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OffscreenCanvasCommitEnabled,
    RuntimeEnabledFeatures::SetOffscreenCanvasCommitEnabled>
    ScopedOffscreenCanvasCommitForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OnDeviceChangeEnabled,
    RuntimeEnabledFeatures::SetOnDeviceChangeEnabled>
    ScopedOnDeviceChangeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OrientationEventEnabled,
    RuntimeEnabledFeatures::SetOrientationEventEnabled>
    ScopedOrientationEventForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPIEnabled>
    ScopedOriginTrialsSampleAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPIDependentEnabled>
    ScopedOriginTrialsSampleAPIDependentForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPIDeprecationEnabled>
    ScopedOriginTrialsSampleAPIDeprecationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPIImpliedEnabled>
    ScopedOriginTrialsSampleAPIImpliedForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPIInvalidOSEnabled>
    ScopedOriginTrialsSampleAPIInvalidOSForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetOriginTrialsSampleAPINavigationEnabled>
    ScopedOriginTrialsSampleAPINavigationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OutOfBlinkCorsEnabled,
    RuntimeEnabledFeatures::SetOutOfBlinkCorsEnabled>
    ScopedOutOfBlinkCorsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OverflowIconsForMediaControlsEnabled,
    RuntimeEnabledFeatures::SetOverflowIconsForMediaControlsEnabled>
    ScopedOverflowIconsForMediaControlsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::OverscrollCustomizationEnabled,
    RuntimeEnabledFeatures::SetOverscrollCustomizationEnabled>
    ScopedOverscrollCustomizationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PageFreezeOptInEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPageFreezeOptInEnabled>
    ScopedPageFreezeOptInForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PageFreezeOptOutEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPageFreezeOptOutEnabled>
    ScopedPageFreezeOptOutForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PagePopupEnabled,
    RuntimeEnabledFeatures::SetPagePopupEnabled>
    ScopedPagePopupForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaintUnderInvalidationCheckingEnabled,
    RuntimeEnabledFeatures::SetPaintUnderInvalidationCheckingEnabled>
    ScopedPaintUnderInvalidationCheckingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PassiveDocumentEventListenersEnabled,
    RuntimeEnabledFeatures::SetPassiveDocumentEventListenersEnabled>
    ScopedPassiveDocumentEventListenersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PassiveDocumentWheelEventListenersEnabled,
    RuntimeEnabledFeatures::SetPassiveDocumentWheelEventListenersEnabled>
    ScopedPassiveDocumentWheelEventListenersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PassPaintVisualRectToCompositorEnabled,
    RuntimeEnabledFeatures::SetPassPaintVisualRectToCompositorEnabled>
    ScopedPassPaintVisualRectToCompositorForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PasswordRevealEnabled,
    RuntimeEnabledFeatures::SetPasswordRevealEnabled>
    ScopedPasswordRevealForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentAppEnabled,
    RuntimeEnabledFeatures::SetPaymentAppEnabled>
    ScopedPaymentAppForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentHandlerChangePaymentMethodEnabled,
    RuntimeEnabledFeatures::SetPaymentHandlerChangePaymentMethodEnabled>
    ScopedPaymentHandlerChangePaymentMethodForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentHandlerHandlesShippingAndContactEnabled,
    RuntimeEnabledFeatures::SetPaymentHandlerHandlesShippingAndContactEnabled>
    ScopedPaymentHandlerHandlesShippingAndContactForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentMethodChangeEventEnabled,
    RuntimeEnabledFeatures::SetPaymentMethodChangeEventEnabled>
    ScopedPaymentMethodChangeEventForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentRequestEnabled,
    RuntimeEnabledFeatures::SetPaymentRequestEnabled>
    ScopedPaymentRequestForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentRequestMerchantValidationEventEnabled,
    RuntimeEnabledFeatures::SetPaymentRequestMerchantValidationEventEnabled>
    ScopedPaymentRequestMerchantValidationEventForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PaymentRetryEnabled,
    RuntimeEnabledFeatures::SetPaymentRetryEnabled>
    ScopedPaymentRetryForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PerformanceManagerInstrumentationEnabled,
    RuntimeEnabledFeatures::SetPerformanceManagerInstrumentationEnabled>
    ScopedPerformanceManagerInstrumentationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled,
    RuntimeEnabledFeatures::SetPeriodicBackgroundSyncEnabled>
    ScopedPeriodicBackgroundSyncForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPerMethodCanMakePaymentQuotaEnabled>
    ScopedPerMethodCanMakePaymentQuotaForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PermissionDelegationEnabled,
    RuntimeEnabledFeatures::SetPermissionDelegationEnabled>
    ScopedPermissionDelegationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PermissionsEnabled,
    RuntimeEnabledFeatures::SetPermissionsEnabled>
    ScopedPermissionsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PermissionsRequestRevokeEnabled,
    RuntimeEnabledFeatures::SetPermissionsRequestRevokeEnabled>
    ScopedPermissionsRequestRevokeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PictureInPictureEnabled,
    RuntimeEnabledFeatures::SetPictureInPictureEnabled>
    ScopedPictureInPictureForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PictureInPictureAPIEnabled,
    RuntimeEnabledFeatures::SetPictureInPictureAPIEnabled>
    ScopedPictureInPictureAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PictureInPictureV2Enabled,
    RuntimeEnabledFeatures::SetPictureInPictureV2Enabled>
    ScopedPictureInPictureV2ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PNaClEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPNaClEnabled>
    ScopedPNaClForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PointerLockOptionsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPointerLockOptionsEnabled>
    ScopedPointerLockOptionsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PointerRawUpdateEnabled,
    RuntimeEnabledFeatures::SetPointerRawUpdateEnabled>
    ScopedPointerRawUpdateForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PortalsEnabled,
    RuntimeEnabledFeatures::SetPortalsEnabled>
    ScopedPortalsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PostAnimationFrameEnabled,
    RuntimeEnabledFeatures::SetPostAnimationFrameEnabled>
    ScopedPostAnimationFrameForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PreciseMemoryInfoEnabled,
    RuntimeEnabledFeatures::SetPreciseMemoryInfoEnabled>
    ScopedPreciseMemoryInfoForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PredictedEventsEnabled,
    RuntimeEnabledFeatures::SetPredictedEventsEnabled>
    ScopedPredictedEventsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PrefixedVideoFullscreenEnabled,
    RuntimeEnabledFeatures::SetPrefixedVideoFullscreenEnabled>
    ScopedPrefixedVideoFullscreenForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PresentationEnabled,
    RuntimeEnabledFeatures::SetPresentationEnabled>
    ScopedPresentationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PrintBrowserEnabled,
    RuntimeEnabledFeatures::SetPrintBrowserEnabled>
    ScopedPrintBrowserForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PriorityHintsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetPriorityHintsEnabled>
    ScopedPriorityHintsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PushMessagingEnabled,
    RuntimeEnabledFeatures::SetPushMessagingEnabled>
    ScopedPushMessagingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::PushMessagingSubscriptionChangeEnabled,
    RuntimeEnabledFeatures::SetPushMessagingSubscriptionChangeEnabled>
    ScopedPushMessagingSubscriptionChangeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::QuicTransportEnabled,
    RuntimeEnabledFeatures::SetQuicTransportEnabled>
    ScopedQuicTransportForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RawClipboardEnabled,
    RuntimeEnabledFeatures::SetRawClipboardEnabled>
    ScopedRawClipboardForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ReducedReferrerGranularityEnabled,
    RuntimeEnabledFeatures::SetReducedReferrerGranularityEnabled>
    ScopedReducedReferrerGranularityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RemotePlaybackEnabled,
    RuntimeEnabledFeatures::SetRemotePlaybackEnabled>
    ScopedRemotePlaybackForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RemotePlaybackBackendEnabled,
    RuntimeEnabledFeatures::SetRemotePlaybackBackendEnabled>
    ScopedRemotePlaybackBackendForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ResizeObserverUpdatesEnabled,
    RuntimeEnabledFeatures::SetResizeObserverUpdatesEnabled>
    ScopedResizeObserverUpdatesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RestrictAppCacheToSecureContextsEnabled,
    RuntimeEnabledFeatures::SetRestrictAppCacheToSecureContextsEnabled>
    ScopedRestrictAppCacheToSecureContextsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RestrictAutomaticLazyFrameLoadingToDataSaverEnabled,
    RuntimeEnabledFeatures::SetRestrictAutomaticLazyFrameLoadingToDataSaverEnabled>
    ScopedRestrictAutomaticLazyFrameLoadingToDataSaverForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RestrictAutomaticLazyImageLoadingToDataSaverEnabled,
    RuntimeEnabledFeatures::SetRestrictAutomaticLazyImageLoadingToDataSaverEnabled>
    ScopedRestrictAutomaticLazyImageLoadingToDataSaverForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RestrictedWebkitAppearanceEnabled,
    RuntimeEnabledFeatures::SetRestrictedWebkitAppearanceEnabled>
    ScopedRestrictedWebkitAppearanceForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetRtcAudioJitterBufferMaxPacketsEnabled>
    ScopedRtcAudioJitterBufferMaxPacketsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetRtcAudioJitterBufferRtxHandlingEnabled>
    ScopedRtcAudioJitterBufferRtxHandlingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCDtlsTransportEnabled,
    RuntimeEnabledFeatures::SetRTCDtlsTransportEnabled>
    ScopedRTCDtlsTransportForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCIceTransportExtensionEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetRTCIceTransportExtensionEnabled>
    ScopedRTCIceTransportExtensionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCQuicTransportEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetRTCQuicTransportEnabled>
    ScopedRTCQuicTransportForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCSctpTransportEnabled,
    RuntimeEnabledFeatures::SetRTCSctpTransportEnabled>
    ScopedRTCSctpTransportForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetRTCStatsRelativePacketArrivalDelayEnabled>
    ScopedRTCStatsRelativePacketArrivalDelayForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled,
    RuntimeEnabledFeatures::SetRTCSvcScalabilityModeEnabled>
    ScopedRTCSvcScalabilityModeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCUnifiedPlanEnabled,
    RuntimeEnabledFeatures::SetRTCUnifiedPlanEnabled>
    ScopedRTCUnifiedPlanForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::RTCUnifiedPlanByDefaultEnabled,
    RuntimeEnabledFeatures::SetRTCUnifiedPlanByDefaultEnabled>
    ScopedRTCUnifiedPlanByDefaultForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SameSiteByDefaultCookiesEnabled,
    RuntimeEnabledFeatures::SetSameSiteByDefaultCookiesEnabled>
    ScopedSameSiteByDefaultCookiesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScreenEnumerationEnabled,
    RuntimeEnabledFeatures::SetScreenEnumerationEnabled>
    ScopedScreenEnumerationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScriptedSpeechRecognitionEnabled,
    RuntimeEnabledFeatures::SetScriptedSpeechRecognitionEnabled>
    ScopedScriptedSpeechRecognitionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScriptedSpeechSynthesisEnabled,
    RuntimeEnabledFeatures::SetScriptedSpeechSynthesisEnabled>
    ScopedScriptedSpeechSynthesisForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScriptStreamingOnPreloadEnabled,
    RuntimeEnabledFeatures::SetScriptStreamingOnPreloadEnabled>
    ScopedScriptStreamingOnPreloadForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScrollCustomizationEnabled,
    RuntimeEnabledFeatures::SetScrollCustomizationEnabled>
    ScopedScrollCustomizationForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScrollSnapAfterLayoutEnabled,
    RuntimeEnabledFeatures::SetScrollSnapAfterLayoutEnabled>
    ScopedScrollSnapAfterLayoutForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScrollTimelineEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetScrollTimelineEnabled>
    ScopedScrollTimelineForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ScrollTopLeftInteropEnabled,
    RuntimeEnabledFeatures::SetScrollTopLeftInteropEnabled>
    ScopedScrollTopLeftInteropForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SendBeaconThrowForBlobWithNonSimpleTypeEnabled,
    RuntimeEnabledFeatures::SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled>
    ScopedSendBeaconThrowForBlobWithNonSimpleTypeForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SendMouseEventsDisabledFormControlsEnabled,
    RuntimeEnabledFeatures::SetSendMouseEventsDisabledFormControlsEnabled>
    ScopedSendMouseEventsDisabledFormControlsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SensorExtraClassesEnabled,
    RuntimeEnabledFeatures::SetSensorExtraClassesEnabled>
    ScopedSensorExtraClassesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SerialEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetSerialEnabled>
    ScopedSerialForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ServiceWorkerClientLifecycleStateEnabled,
    RuntimeEnabledFeatures::SetServiceWorkerClientLifecycleStateEnabled>
    ScopedServiceWorkerClientLifecycleStateForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ServiceWorkerFetchEventWorkerTimingEnabled,
    RuntimeEnabledFeatures::SetServiceWorkerFetchEventWorkerTimingEnabled>
    ScopedServiceWorkerFetchEventWorkerTimingForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SetRootScrollerEnabled,
    RuntimeEnabledFeatures::SetSetRootScrollerEnabled>
    ScopedSetRootScrollerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ShadowDOMV0EnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetShadowDOMV0Enabled>
    ScopedShadowDOMV0ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ShadowPiercingDescendantCombinatorEnabled,
    RuntimeEnabledFeatures::SetShadowPiercingDescendantCombinatorEnabled>
    ScopedShadowPiercingDescendantCombinatorForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::ShapeDetectionEnabled,
    RuntimeEnabledFeatures::SetShapeDetectionEnabled>
    ScopedShapeDetectionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SharedArrayBufferEnabled,
    RuntimeEnabledFeatures::SetSharedArrayBufferEnabled>
    ScopedSharedArrayBufferForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SharedWorkerEnabled,
    RuntimeEnabledFeatures::SetSharedWorkerEnabled>
    ScopedSharedWorkerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SignatureBasedIntegrityEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetSignatureBasedIntegrityEnabled>
    ScopedSignatureBasedIntegrityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SignedExchangePrefetchCacheForNavigationsEnabled,
    RuntimeEnabledFeatures::SetSignedExchangePrefetchCacheForNavigationsEnabled>
    ScopedSignedExchangePrefetchCacheForNavigationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetSignedExchangeSubresourcePrefetchEnabled>
    ScopedSignedExchangeSubresourcePrefetchForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SkipAdEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetSkipAdEnabled>
    ScopedSkipAdForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SkipTouchEventFilterEnabled,
    RuntimeEnabledFeatures::SetSkipTouchEventFilterEnabled>
    ScopedSkipTouchEventFilterForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SmsReceiverEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetSmsReceiverEnabled>
    ScopedSmsReceiverForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::StableBlinkFeaturesEnabled,
    RuntimeEnabledFeatures::SetStableBlinkFeaturesEnabled>
    ScopedStableBlinkFeaturesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::StackedCSSPropertyAnimationsEnabled,
    RuntimeEnabledFeatures::SetStackedCSSPropertyAnimationsEnabled>
    ScopedStackedCSSPropertyAnimationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::StorageAccessAPIEnabled,
    RuntimeEnabledFeatures::SetStorageAccessAPIEnabled>
    ScopedStorageAccessAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::StorageQuotaDetailsEnabled,
    RuntimeEnabledFeatures::SetStorageQuotaDetailsEnabled>
    ScopedStorageQuotaDetailsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::StrictMimeTypesForWorkersEnabled,
    RuntimeEnabledFeatures::SetStrictMimeTypesForWorkersEnabled>
    ScopedStrictMimeTypesForWorkersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::SurfaceEmbeddingFeaturesEnabled,
    RuntimeEnabledFeatures::SetSurfaceEmbeddingFeaturesEnabled>
    ScopedSurfaceEmbeddingFeaturesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetTextFragmentIdentifiersEnabled>
    ScopedTextFragmentIdentifiersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TimerThrottlingForBackgroundTabsEnabled,
    RuntimeEnabledFeatures::SetTimerThrottlingForBackgroundTabsEnabled>
    ScopedTimerThrottlingForBackgroundTabsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TimerThrottlingForHiddenFramesEnabled,
    RuntimeEnabledFeatures::SetTimerThrottlingForHiddenFramesEnabled>
    ScopedTimerThrottlingForHiddenFramesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled>
    ScopedTouchEventFeatureDetectionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TrackLayoutPassesPerBlockEnabled,
    RuntimeEnabledFeatures::SetTrackLayoutPassesPerBlockEnabled>
    ScopedTrackLayoutPassesPerBlockForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TransferableStreamsEnabled,
    RuntimeEnabledFeatures::SetTransferableStreamsEnabled>
    ScopedTransferableStreamsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TranslateServiceEnabled,
    RuntimeEnabledFeatures::SetTranslateServiceEnabled>
    ScopedTranslateServiceForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::TrustedDOMTypesEnabled,
    RuntimeEnabledFeatures::SetTrustedDOMTypesEnabled>
    ScopedTrustedDOMTypesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UnclosedFormControlIsInvalidEnabled,
    RuntimeEnabledFeatures::SetUnclosedFormControlIsInvalidEnabled>
    ScopedUnclosedFormControlIsInvalidForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UnifiedPointerCaptureInBlinkEnabled,
    RuntimeEnabledFeatures::SetUnifiedPointerCaptureInBlinkEnabled>
    ScopedUnifiedPointerCaptureInBlinkForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UnifiedTouchAdjustmentEnabled,
    RuntimeEnabledFeatures::SetUnifiedTouchAdjustmentEnabled>
    ScopedUnifiedTouchAdjustmentForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetUnoptimizedImagePoliciesEnabled>
    ScopedUnoptimizedImagePoliciesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UnsizedMediaPolicyEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetUnsizedMediaPolicyEnabled>
    ScopedUnsizedMediaPolicyForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UpdateHoverAtBeginFrameEnabled,
    RuntimeEnabledFeatures::SetUpdateHoverAtBeginFrameEnabled>
    ScopedUpdateHoverAtBeginFrameForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UserActivationAPIEnabled,
    RuntimeEnabledFeatures::SetUserActivationAPIEnabled>
    ScopedUserActivationAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UserActivationPostMessageTransferEnabled,
    RuntimeEnabledFeatures::SetUserActivationPostMessageTransferEnabled>
    ScopedUserActivationPostMessageTransferForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UserActivationSameOriginVisibilityEnabled,
    RuntimeEnabledFeatures::SetUserActivationSameOriginVisibilityEnabled>
    ScopedUserActivationSameOriginVisibilityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UserAgentClientHintEnabled,
    RuntimeEnabledFeatures::SetUserAgentClientHintEnabled>
    ScopedUserAgentClientHintForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::UseWindowsSystemColorsEnabled,
    RuntimeEnabledFeatures::SetUseWindowsSystemColorsEnabled>
    ScopedUseWindowsSystemColorsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::V8IdleTasksEnabled,
    RuntimeEnabledFeatures::SetV8IdleTasksEnabled>
    ScopedV8IdleTasksForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoAutoFullscreenEnabled,
    RuntimeEnabledFeatures::SetVideoAutoFullscreenEnabled>
    ScopedVideoAutoFullscreenForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoFullscreenDetectionEnabled,
    RuntimeEnabledFeatures::SetVideoFullscreenDetectionEnabled>
    ScopedVideoFullscreenDetectionForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoFullscreenOrientationLockEnabled,
    RuntimeEnabledFeatures::SetVideoFullscreenOrientationLockEnabled>
    ScopedVideoFullscreenOrientationLockForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoPlaybackQualityEnabled,
    RuntimeEnabledFeatures::SetVideoPlaybackQualityEnabled>
    ScopedVideoPlaybackQualityForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoRequestAnimationFrameEnabled,
    RuntimeEnabledFeatures::SetVideoRequestAnimationFrameEnabled>
    ScopedVideoRequestAnimationFrameForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VideoRotateToFullscreenEnabled,
    RuntimeEnabledFeatures::SetVideoRotateToFullscreenEnabled>
    ScopedVideoRotateToFullscreenForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::VisibilityCollapseColumnEnabled,
    RuntimeEnabledFeatures::SetVisibilityCollapseColumnEnabled>
    ScopedVisibilityCollapseColumnForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WakeLockEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetWakeLockEnabled>
    ScopedWakeLockForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WasmCodeCacheEnabled,
    RuntimeEnabledFeatures::SetWasmCodeCacheEnabled>
    ScopedWasmCodeCacheForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebAnimationsAPIEnabled,
    RuntimeEnabledFeatures::SetWebAnimationsAPIEnabled>
    ScopedWebAnimationsAPIForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebAnimationsSVGEnabled,
    RuntimeEnabledFeatures::SetWebAnimationsSVGEnabled>
    ScopedWebAnimationsSVGForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebAssemblyThreadsEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetWebAssemblyThreadsEnabled>
    ScopedWebAssemblyThreadsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebAuthEnabled,
    RuntimeEnabledFeatures::SetWebAuthEnabled>
    ScopedWebAuthForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebAuthenticationFeaturePolicyEnabled,
    RuntimeEnabledFeatures::SetWebAuthenticationFeaturePolicyEnabled>
    ScopedWebAuthenticationFeaturePolicyForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebBluetoothEnabled,
    RuntimeEnabledFeatures::SetWebBluetoothEnabled>
    ScopedWebBluetoothForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebBluetoothScanningEnabled,
    RuntimeEnabledFeatures::SetWebBluetoothScanningEnabled>
    ScopedWebBluetoothScanningForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebCodecsEnabled,
    RuntimeEnabledFeatures::SetWebCodecsEnabled>
    ScopedWebCodecsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebGL2ComputeContextEnabled,
    RuntimeEnabledFeatures::SetWebGL2ComputeContextEnabled>
    ScopedWebGL2ComputeContextForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebGLDraftExtensionsEnabled,
    RuntimeEnabledFeatures::SetWebGLDraftExtensionsEnabled>
    ScopedWebGLDraftExtensionsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebGLImageChromiumEnabled,
    RuntimeEnabledFeatures::SetWebGLImageChromiumEnabled>
    ScopedWebGLImageChromiumForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebGPUEnabled,
    RuntimeEnabledFeatures::SetWebGPUEnabled>
    ScopedWebGPUForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebHIDEnabled,
    RuntimeEnabledFeatures::SetWebHIDEnabled>
    ScopedWebHIDForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebNFCEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetWebNFCEnabled>
    ScopedWebNFCForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebSchedulerEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetWebSchedulerEnabled>
    ScopedWebSchedulerForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebShareEnabled,
    RuntimeEnabledFeatures::SetWebShareEnabled>
    ScopedWebShareForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebShareV2Enabled,
    RuntimeEnabledFeatures::SetWebShareV2Enabled>
    ScopedWebShareV2ForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebSocketStreamEnabledByRuntimeFlag,
    RuntimeEnabledFeatures::SetWebSocketStreamEnabled>
    ScopedWebSocketStreamForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebUSBEnabled,
    RuntimeEnabledFeatures::SetWebUSBEnabled>
    ScopedWebUSBForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebUSBOnDedicatedWorkersEnabled,
    RuntimeEnabledFeatures::SetWebUSBOnDedicatedWorkersEnabled>
    ScopedWebUSBOnDedicatedWorkersForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebVTTRegionsEnabled,
    RuntimeEnabledFeatures::SetWebVTTRegionsEnabled>
    ScopedWebVTTRegionsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebXREnabled,
    RuntimeEnabledFeatures::SetWebXREnabled>
    ScopedWebXRForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebXRARModuleEnabled,
    RuntimeEnabledFeatures::SetWebXRARModuleEnabled>
    ScopedWebXRARModuleForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebXRHitTestEnabled,
    RuntimeEnabledFeatures::SetWebXRHitTestEnabled>
    ScopedWebXRHitTestForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled,
    RuntimeEnabledFeatures::SetWebXRHitTestEntityTypesEnabled>
    ScopedWebXRHitTestEntityTypesForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WebXRIncubationsEnabled,
    RuntimeEnabledFeatures::SetWebXRIncubationsEnabled>
    ScopedWebXRIncubationsForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WindowPlacementEnabled,
    RuntimeEnabledFeatures::SetWindowPlacementEnabled>
    ScopedWindowPlacementForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::WritableFileStreamEnabled,
    RuntimeEnabledFeatures::SetWritableFileStreamEnabled>
    ScopedWritableFileStreamForTest;
typedef ScopedRuntimeEnabledFeatureForTest<
    RuntimeEnabledFeatures::XSLTEnabled,
    RuntimeEnabledFeatures::SetXSLTEnabled>
    ScopedXSLTForTest;
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
