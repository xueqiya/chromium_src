// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "build/build_config.h"

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

#include "third_party/blink/renderer/platform/wtf/assertions.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

RuntimeEnabledFeatures::Backup::Backup()
  :     accelerated_2d_canvas_(RuntimeEnabledFeatures::Accelerated2dCanvasEnabled())
,
        accelerated_small_canvases_(RuntimeEnabledFeatures::AcceleratedSmallCanvasesEnabled())
,
        accessibility_expose_aria_annotations_(RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabledByRuntimeFlag())
,
        accessibility_expose_display_none_(RuntimeEnabledFeatures::AccessibilityExposeDisplayNoneEnabled())
,
        accessibility_object_model_(RuntimeEnabledFeatures::AccessibilityObjectModelEnabled())
,
        address_space_(RuntimeEnabledFeatures::AddressSpaceEnabled())
,
        ad_tagging_(RuntimeEnabledFeatures::AdTaggingEnabled())
,
        allow_activation_delegation_attr_(RuntimeEnabledFeatures::AllowActivationDelegationAttrEnabled())
,
        allow_content_initiated_data_url_navigations_(RuntimeEnabledFeatures::AllowContentInitiatedDataUrlNavigationsEnabled())
,
        allow_sync_xhr_in_page_dismissal_(RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabledByRuntimeFlag())
,
        animation_worklet_(RuntimeEnabledFeatures::AnimationWorkletEnabledByRuntimeFlag())
,
        aom_aria_properties_(RuntimeEnabledFeatures::AOMAriaPropertiesEnabled())
,
        aom_aria_relationship_properties_(RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled())
,
        aspect_ratio_from_width_and_height_(RuntimeEnabledFeatures::AspectRatioFromWidthAndHeightEnabled())
,
        async_clipboard_(RuntimeEnabledFeatures::AsyncClipboardEnabled())
,
        audio_output_devices_(RuntimeEnabledFeatures::AudioOutputDevicesEnabled())
,
        audio_video_tracks_(RuntimeEnabledFeatures::AudioVideoTracksEnabled())
,
        audio_worklet_realtime_thread_(RuntimeEnabledFeatures::AudioWorkletRealtimeThreadEnabled())
,
        auto_lazy_load_on_reloads_(RuntimeEnabledFeatures::AutoLazyLoadOnReloadsEnabled())
,
        automatic_lazy_frame_loading_(RuntimeEnabledFeatures::AutomaticLazyFrameLoadingEnabled())
,
        automatic_lazy_image_loading_(RuntimeEnabledFeatures::AutomaticLazyImageLoadingEnabled())
,
        automation_controlled_(RuntimeEnabledFeatures::AutomationControlledEnabled())
,
        auto_picture_in_picture_(RuntimeEnabledFeatures::AutoPictureInPictureEnabledByRuntimeFlag())
,
        autoplay_ignores_web_audio_(RuntimeEnabledFeatures::AutoplayIgnoresWebAudioEnabled())
,
        back_forward_cache_(RuntimeEnabledFeatures::BackForwardCacheEnabled())
,
        background_fetch_(RuntimeEnabledFeatures::BackgroundFetchEnabled())
,
        background_video_track_optimization_(RuntimeEnabledFeatures::BackgroundVideoTrackOptimizationEnabled())
,
        badging_(RuntimeEnabledFeatures::BadgingEnabled())
,
        bidi_caret_affinity_(RuntimeEnabledFeatures::BidiCaretAffinityEnabled())
,
        blink_runtime_call_stats_(RuntimeEnabledFeatures::BlinkRuntimeCallStatsEnabled())
,
        blob_read_methods_(RuntimeEnabledFeatures::BlobReadMethodsEnabled())
,
        block_credentialed_subresources_(RuntimeEnabledFeatures::BlockCredentialedSubresourcesEnabled())
,
        block_html_parser_on_style_sheets_(RuntimeEnabledFeatures::BlockHTMLParserOnStyleSheetsEnabled())
,
        blocking_downloads_in_sandbox_(RuntimeEnabledFeatures::BlockingDownloadsInSandboxEnabled())
,
        blocking_focus_without_user_activation_(RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled())
,
        browser_verified_user_activation_keyboard_(RuntimeEnabledFeatures::BrowserVerifiedUserActivationKeyboardEnabled())
,
        browser_verified_user_activation_mouse_(RuntimeEnabledFeatures::BrowserVerifiedUserActivationMouseEnabled())
,
        built_in_module_all_(RuntimeEnabledFeatures::BuiltInModuleAllEnabled())
,
        built_in_module_infra_(RuntimeEnabledFeatures::BuiltInModuleInfraEnabledByRuntimeFlag())
,
        built_in_module_kv_storage_(RuntimeEnabledFeatures::BuiltInModuleKvStorageEnabledByRuntimeFlag())
,
        built_in_module_switch_element_(RuntimeEnabledFeatures::BuiltInModuleSwitchElementEnabled())
,
        cache_inline_script_code_(RuntimeEnabledFeatures::CacheInlineScriptCodeEnabled())
,
        cache_storage_code_cache_hint_(RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabledByRuntimeFlag())
,
        canvas_2d_context_lost_restored_(RuntimeEnabledFeatures::Canvas2dContextLostRestoredEnabled())
,
        canvas_2d_image_chromium_(RuntimeEnabledFeatures::Canvas2dImageChromiumEnabled())
,
        canvas_2d_scroll_path_into_view_(RuntimeEnabledFeatures::Canvas2dScrollPathIntoViewEnabled())
,
        canvas_color_management_(RuntimeEnabledFeatures::CanvasColorManagementEnabled())
,
        canvas_hit_region_(RuntimeEnabledFeatures::CanvasHitRegionEnabled())
,
        canvas_image_smoothing_(RuntimeEnabledFeatures::CanvasImageSmoothingEnabled())
,
        click_pointer_event_(RuntimeEnabledFeatures::ClickPointerEventEnabled())
,
        click_retargetting_(RuntimeEnabledFeatures::ClickRetargettingEnabled())
,
        cloneable_native_file_system_handles_(RuntimeEnabledFeatures::CloneableNativeFileSystemHandlesEnabled())
,
        composite_after_paint_(RuntimeEnabledFeatures::CompositeAfterPaintEnabled())
,
        composited_selection_update_(RuntimeEnabledFeatures::CompositedSelectionUpdateEnabled())
,
        compositor_touch_action_(RuntimeEnabledFeatures::CompositorTouchActionEnabled())
,
        computed_accessibility_info_(RuntimeEnabledFeatures::ComputedAccessibilityInfoEnabled())
,
        consolidated_movement_xy_(RuntimeEnabledFeatures::ConsolidatedMovementXYEnabled())
,
        contacts_manager_(RuntimeEnabledFeatures::ContactsManagerEnabled())
,
        contacts_manager_extra_properties_(RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabledByRuntimeFlag())
,
        content_index_(RuntimeEnabledFeatures::ContentIndexEnabledByRuntimeFlag())
,
        context_menu_(RuntimeEnabledFeatures::ContextMenuEnabled())
,
        cookie_deprecation_messages_(RuntimeEnabledFeatures::CookieDeprecationMessagesEnabled())
,
        cookie_store_document_(RuntimeEnabledFeatures::CookieStoreDocumentEnabled())
,
        cookie_store_worker_(RuntimeEnabledFeatures::CookieStoreWorkerEnabled())
,
        cookies_without_same_site_must_be_secure_(RuntimeEnabledFeatures::CookiesWithoutSameSiteMustBeSecureEnabled())
,
        cooperative_scheduling_(RuntimeEnabledFeatures::CooperativeSchedulingEnabled())
,
        cors_rfc_1918_(RuntimeEnabledFeatures::CorsRFC1918Enabled())
,
        css_3_text_(RuntimeEnabledFeatures::CSS3TextEnabled())
,
        css_3_text_break_anywhere_(RuntimeEnabledFeatures::CSS3TextBreakAnywhereEnabled())
,
        css_additive_animations_(RuntimeEnabledFeatures::CSSAdditiveAnimationsEnabled())
,
        css_calc_as_int_(RuntimeEnabledFeatures::CSSCalcAsIntEnabled())
,
        css_cascade_(RuntimeEnabledFeatures::CSSCascadeEnabled())
,
        css_color_scheme_(RuntimeEnabledFeatures::CSSColorSchemeEnabled())
,
        css_color_scheme_ua_rendering_(RuntimeEnabledFeatures::CSSColorSchemeUARenderingEnabled())
,
        css_focus_visible_(RuntimeEnabledFeatures::CSSFocusVisibleEnabled())
,
        css_font_size_adjust_(RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled())
,
        css_hex_alpha_color_(RuntimeEnabledFeatures::CSSHexAlphaColorEnabled())
,
        css_independent_transform_properties_(RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled())
,
        css_intrinsic_size_(RuntimeEnabledFeatures::CSSIntrinsicSizeEnabled())
,
        css_layout_api_(RuntimeEnabledFeatures::CSSLayoutAPIEnabled())
,
        css_logical_(RuntimeEnabledFeatures::CSSLogicalEnabled())
,
        css_logical_overflow_(RuntimeEnabledFeatures::CSSLogicalOverflowEnabled())
,
        css_marker_pseudo_element_(RuntimeEnabledFeatures::CSSMarkerPseudoElementEnabled())
,
        css_mask_source_type_(RuntimeEnabledFeatures::CSSMaskSourceTypeEnabled())
,
        css_modules_(RuntimeEnabledFeatures::CSSModulesEnabled())
,
        css_offset_path_ray_(RuntimeEnabledFeatures::CSSOffsetPathRayEnabled())
,
        css_offset_path_ray_contain_(RuntimeEnabledFeatures::CSSOffsetPathRayContainEnabled())
,
        css_offset_position_anchor_(RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled())
,
        cssom_view_scroll_coordinates_(RuntimeEnabledFeatures::CSSOMViewScrollCoordinatesEnabled())
,
        css_paint_api_arguments_(RuntimeEnabledFeatures::CSSPaintAPIArgumentsEnabled())
,
        css_picture_in_picture_(RuntimeEnabledFeatures::CSSPictureInPictureEnabled())
,
        css_pseudo_is_(RuntimeEnabledFeatures::CSSPseudoIsEnabled())
,
        css_pseudo_where_(RuntimeEnabledFeatures::CSSPseudoWhereEnabled())
,
        css_render_subtree_(RuntimeEnabledFeatures::CSSRenderSubtreeEnabled())
,
        css_snap_size_(RuntimeEnabledFeatures::CSSSnapSizeEnabled())
,
        css_variables_2_(RuntimeEnabledFeatures::CSSVariables2Enabled())
,
        css_variables_2_at_property_(RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled())
,
        css_variables_2_image_values_(RuntimeEnabledFeatures::CSSVariables2ImageValuesEnabled())
,
        css_variables_2_transform_values_(RuntimeEnabledFeatures::CSSVariables2TransformValuesEnabled())
,
        css_viewport_(RuntimeEnabledFeatures::CSSViewportEnabled())
,
        custom_element_default_style_(RuntimeEnabledFeatures::CustomElementDefaultStyleEnabled())
,
        custom_elements_v0_(RuntimeEnabledFeatures::CustomElementsV0EnabledByRuntimeFlag())
,
        custom_state_pseudo_class_(RuntimeEnabledFeatures::CustomStatePseudoClassEnabled())
,
        database_(RuntimeEnabledFeatures::DatabaseEnabled())
,
        decode_jpeg_420_images_to_yuv_(RuntimeEnabledFeatures::DecodeJpeg420ImagesToYUVEnabled())
,
        decode_lossy_web_p_images_to_yuv_(RuntimeEnabledFeatures::DecodeLossyWebPImagesToYUVEnabled())
,
        desktop_capture_disable_local_echo_control_(RuntimeEnabledFeatures::DesktopCaptureDisableLocalEchoControlEnabled())
,
        disable_hardware_noise_suppression_(RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabledByRuntimeFlag())
,
        disallow_document_access_(RuntimeEnabledFeatures::DisallowDocumentAccessEnabled())
,
        discard_input_to_moving_iframes_(RuntimeEnabledFeatures::DiscardInputToMovingIframesEnabled())
,
        display_cutout_api_(RuntimeEnabledFeatures::DisplayCutoutAPIEnabled())
,
        display_locking_(RuntimeEnabledFeatures::DisplayLockingEnabledByRuntimeFlag())
,
        document_cookie_(RuntimeEnabledFeatures::DocumentCookieEnabled())
,
        document_domain_(RuntimeEnabledFeatures::DocumentDomainEnabled())
,
        document_policy_(RuntimeEnabledFeatures::DocumentPolicyEnabled())
,
        document_write_(RuntimeEnabledFeatures::DocumentWriteEnabled())
,
        edit_context_(RuntimeEnabledFeatures::EditContextEnabled())
,
        editing_ng_(RuntimeEnabledFeatures::EditingNGEnabled())
,
        embedded_vtt_stylesheets_(RuntimeEnabledFeatures::EmbeddedVTTStylesheetsEnabled())
,
        encrypted_media_encryption_scheme_query_(RuntimeEnabledFeatures::EncryptedMediaEncryptionSchemeQueryEnabled())
,
        encrypted_media_hdcp_policy_check_(RuntimeEnabledFeatures::EncryptedMediaHdcpPolicyCheckEnabled())
,
        encrypted_media_persistent_usage_record_session_(RuntimeEnabledFeatures::EncryptedMediaPersistentUsageRecordSessionEnabled())
,
        enter_key_hint_attribute_(RuntimeEnabledFeatures::EnterKeyHintAttributeEnabled())
,
        event_timing_(RuntimeEnabledFeatures::EventTimingEnabledByRuntimeFlag())
,
        exec_command_in_java_script_(RuntimeEnabledFeatures::ExecCommandInJavaScriptEnabled())
,
        expensive_background_timer_throttling_(RuntimeEnabledFeatures::ExpensiveBackgroundTimerThrottlingEnabled())
,
        experimental_autoplay_dynamic_delegation_(RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabledByRuntimeFlag())
,
        experimental_content_security_policy_features_(RuntimeEnabledFeatures::ExperimentalContentSecurityPolicyFeaturesEnabled())
,
        experimental_is_input_pending_(RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabledByRuntimeFlag())
,
        experimental_js_profiler_(RuntimeEnabledFeatures::ExperimentalJSProfilerEnabledByRuntimeFlag())
,
        experimental_productivity_features_(RuntimeEnabledFeatures::ExperimentalProductivityFeaturesEnabled())
,
        extended_text_metrics_(RuntimeEnabledFeatures::ExtendedTextMetricsEnabled())
,
        extra_webgl_video_texture_metadata_(RuntimeEnabledFeatures::ExtraWebGLVideoTextureMetadataEnabled())
,
        fallback_cursor_mode_(RuntimeEnabledFeatures::FallbackCursorModeEnabled())
,
        feature_policy_for_client_hints_(RuntimeEnabledFeatures::FeaturePolicyForClientHintsEnabled())
,
        feature_policy_for_sandbox_(RuntimeEnabledFeatures::FeaturePolicyForSandboxEnabled())
,
        feature_policy_java_script_interface_(RuntimeEnabledFeatures::FeaturePolicyJavaScriptInterfaceEnabled())
,
        feature_policy_reporting_(RuntimeEnabledFeatures::FeaturePolicyReportingEnabledByRuntimeFlag())
,
        feature_policy_vibrate_feature_(RuntimeEnabledFeatures::FeaturePolicyVibrateFeatureEnabled())
,
        fetch_metadata_(RuntimeEnabledFeatures::FetchMetadataEnabled())
,
        fetch_metadata_destination_(RuntimeEnabledFeatures::FetchMetadataDestinationEnabled())
,
        file_handling_(RuntimeEnabledFeatures::FileHandlingEnabled())
,
        file_system_(RuntimeEnabledFeatures::FileSystemEnabled())
,
        flat_tree_style_recalc_(RuntimeEnabledFeatures::FlatTreeStyleRecalcEnabled())
,
        focusless_spatial_navigation_(RuntimeEnabledFeatures::FocuslessSpatialNavigationEnabled())
,
        font_src_local_matching_(RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled())
,
        forced_colors_(RuntimeEnabledFeatures::ForcedColorsEnabled())
,
        force_defer_script_intervention_(RuntimeEnabledFeatures::ForceDeferScriptInterventionEnabled())
,
        force_eager_measure_memory_(RuntimeEnabledFeatures::ForceEagerMeasureMemoryEnabled())
,
        force_overlay_fullscreen_video_(RuntimeEnabledFeatures::ForceOverlayFullscreenVideoEnabled())
,
        force_synchronous_html_parsing_(RuntimeEnabledFeatures::ForceSynchronousHTMLParsingEnabled())
,
        force_taller_select_popup_(RuntimeEnabledFeatures::ForceTallerSelectPopupEnabled())
,
        fractional_mouse_event_(RuntimeEnabledFeatures::FractionalMouseEventEnabled())
,
        fractional_scroll_offsets_(RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled())
,
        freeze_frames_on_visibility_(RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled())
,
        gamepad_button_axis_events_(RuntimeEnabledFeatures::GamepadButtonAxisEventsEnabled())
,
        get_display_media_(RuntimeEnabledFeatures::GetDisplayMediaEnabled())
,
        group_effect_(RuntimeEnabledFeatures::GroupEffectEnabled())
,
        href_translate_(RuntimeEnabledFeatures::HrefTranslateEnabledByRuntimeFlag())
,
        html_imports_(RuntimeEnabledFeatures::HTMLImportsEnabledByRuntimeFlag())
,
        idb_observer_(RuntimeEnabledFeatures::IDBObserverEnabled())
,
        idb_relaxed_durability_(RuntimeEnabledFeatures::IDBRelaxedDurabilityEnabled())
,
        idle_detection_(RuntimeEnabledFeatures::IdleDetectionEnabled())
,
        ignore_cross_origin_window_when_named_access_on_window_(RuntimeEnabledFeatures::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled())
,
        image_orientation_(RuntimeEnabledFeatures::ImageOrientationEnabled())
,
        implicit_root_scroller_(RuntimeEnabledFeatures::ImplicitRootScrollerEnabled())
,
        import_maps_(RuntimeEnabledFeatures::ImportMapsEnabled())
,
        inert_attribute_(RuntimeEnabledFeatures::InertAttributeEnabled())
,
        input_multiple_fields_ui_(RuntimeEnabledFeatures::InputMultipleFieldsUIEnabled())
,
        installed_app_(RuntimeEnabledFeatures::InstalledAppEnabled())
,
        intersection_observer_document_scrolling_element_root_(RuntimeEnabledFeatures::IntersectionObserverDocumentScrollingElementRootEnabled())
,
        intersection_observer_v_2_(RuntimeEnabledFeatures::IntersectionObserverV2Enabled())
,
        invisible_dom_(RuntimeEnabledFeatures::InvisibleDOMEnabled())
,
        isolated_code_cache_(RuntimeEnabledFeatures::IsolatedCodeCacheEnabled())
,
        isolated_world_csp_(RuntimeEnabledFeatures::IsolatedWorldCSPEnabled())
,
        keyboard_focusable_scrollers_(RuntimeEnabledFeatures::KeyboardFocusableScrollersEnabled())
,
        lang_attribute_aware_form_control_ui_(RuntimeEnabledFeatures::LangAttributeAwareFormControlUIEnabled())
,
        lang_client_hint_header_(RuntimeEnabledFeatures::LangClientHintHeaderEnabled())
,
        layout_ng_(RuntimeEnabledFeatures::LayoutNGEnabled())
,
        layout_ng_block_fragmentation_(RuntimeEnabledFeatures::LayoutNGBlockFragmentationEnabled())
,
        layout_ng_fieldset_(RuntimeEnabledFeatures::LayoutNGFieldsetEnabled())
,
        layout_ng_flex_box_(RuntimeEnabledFeatures::LayoutNGFlexBoxEnabled())
,
        layout_ng_fragment_item_(RuntimeEnabledFeatures::LayoutNGFragmentItemEnabled())
,
        layout_ng_fragment_paint_(RuntimeEnabledFeatures::LayoutNGFragmentPaintEnabled())
,
        layout_ng_line_cache_(RuntimeEnabledFeatures::LayoutNGLineCacheEnabled())
,
        layout_ng_table_(RuntimeEnabledFeatures::LayoutNGTableEnabled())
,
        lazy_frame_loading_(RuntimeEnabledFeatures::LazyFrameLoadingEnabled())
,
        lazy_frame_visible_load_time_metrics_(RuntimeEnabledFeatures::LazyFrameVisibleLoadTimeMetricsEnabled())
,
        lazy_image_loading_(RuntimeEnabledFeatures::LazyImageLoadingEnabled())
,
        lazy_image_loading_metadata_fetch_(RuntimeEnabledFeatures::LazyImageLoadingMetadataFetchEnabled())
,
        lazy_image_visible_load_time_metrics_(RuntimeEnabledFeatures::LazyImageVisibleLoadTimeMetricsEnabled())
,
        lazy_initialize_media_controls_(RuntimeEnabledFeatures::LazyInitializeMediaControlsEnabled())
,
        legacy_windows_d_write_font_fallback_(RuntimeEnabledFeatures::LegacyWindowsDWriteFontFallbackEnabled())
,
        link_system_colors_(RuntimeEnabledFeatures::LinkSystemColorsEnabled())
,
        manual_slotting_(RuntimeEnabledFeatures::ManualSlottingEnabled())
,
        mathml_core_(RuntimeEnabledFeatures::MathMLCoreEnabled())
,
        measure_memory_(RuntimeEnabledFeatures::MeasureMemoryEnabled())
,
        media_capabilities_encoding_info_(RuntimeEnabledFeatures::MediaCapabilitiesEncodingInfoEnabled())
,
        media_capabilities_encrypted_media_(RuntimeEnabledFeatures::MediaCapabilitiesEncryptedMediaEnabled())
,
        media_capabilities_spatial_audio_(RuntimeEnabledFeatures::MediaCapabilitiesSpatialAudioEnabled())
,
        media_capture_(RuntimeEnabledFeatures::MediaCaptureEnabled())
,
        media_capture_depth_video_kind_(RuntimeEnabledFeatures::MediaCaptureDepthVideoKindEnabled())
,
        media_capture_pan_tilt_(RuntimeEnabledFeatures::MediaCapturePanTiltEnabled())
,
        media_cast_overlay_button_(RuntimeEnabledFeatures::MediaCastOverlayButtonEnabled())
,
        media_controls_expand_gesture_(RuntimeEnabledFeatures::MediaControlsExpandGestureEnabled())
,
        media_controls_overlay_play_button_(RuntimeEnabledFeatures::MediaControlsOverlayPlayButtonEnabled())
,
        media_document_download_button_(RuntimeEnabledFeatures::MediaDocumentDownloadButtonEnabled())
,
        media_element_volume_greater_than_one_(RuntimeEnabledFeatures::MediaElementVolumeGreaterThanOneEnabled())
,
        media_engagement_bypass_autoplay_policies_(RuntimeEnabledFeatures::MediaEngagementBypassAutoplayPoliciesEnabled())
,
        media_latency_hint_(RuntimeEnabledFeatures::MediaLatencyHintEnabled())
,
        media_query_navigation_controls_(RuntimeEnabledFeatures::MediaQueryNavigationControlsEnabled())
,
        media_query_shape_(RuntimeEnabledFeatures::MediaQueryShapeEnabled())
,
        media_session_(RuntimeEnabledFeatures::MediaSessionEnabled())
,
        media_session_position_(RuntimeEnabledFeatures::MediaSessionPositionEnabled())
,
        media_session_seeking_(RuntimeEnabledFeatures::MediaSessionSeekingEnabled())
,
        media_source_experimental_(RuntimeEnabledFeatures::MediaSourceExperimentalEnabled())
,
        media_source_in_workers_(RuntimeEnabledFeatures::MediaSourceInWorkersEnabled())
,
        media_source_new_abort_and_duration_(RuntimeEnabledFeatures::MediaSourceNewAbortAndDurationEnabled())
,
        media_source_stable_(RuntimeEnabledFeatures::MediaSourceStableEnabled())
,
        meta_color_scheme_(RuntimeEnabledFeatures::MetaColorSchemeEnabled())
,
        middle_click_autoscroll_(RuntimeEnabledFeatures::MiddleClickAutoscrollEnabled())
,
        mobile_layout_theme_(RuntimeEnabledFeatures::MobileLayoutThemeEnabled())
,
        module_dedicated_worker_(RuntimeEnabledFeatures::ModuleDedicatedWorkerEnabled())
,
        module_service_worker_(RuntimeEnabledFeatures::ModuleServiceWorkerEnabled())
,
        module_shared_worker_(RuntimeEnabledFeatures::ModuleSharedWorkerEnabled())
,
        mojo_js_(RuntimeEnabledFeatures::MojoJSEnabled())
,
        mojo_js_test_(RuntimeEnabledFeatures::MojoJSTestEnabled())
,
        mouse_subframe_no_implicit_capture_(RuntimeEnabledFeatures::MouseSubframeNoImplicitCaptureEnabled())
,
        native_file_system_(RuntimeEnabledFeatures::NativeFileSystemEnabledByRuntimeFlag())
,
        navigator_content_utils_(RuntimeEnabledFeatures::NavigatorContentUtilsEnabled())
,
        navigator_language_in_insecure_context_(RuntimeEnabledFeatures::NavigatorLanguageInInsecureContextEnabled())
,
        net_info_downlink_max_(RuntimeEnabledFeatures::NetInfoDownlinkMaxEnabled())
,
        never_slow_mode_(RuntimeEnabledFeatures::NeverSlowModeEnabled())
,
        new_remote_playback_pipeline_(RuntimeEnabledFeatures::NewRemotePlaybackPipelineEnabled())
,
        new_system_colors_(RuntimeEnabledFeatures::NewSystemColorsEnabled())
,
        no_idle_encoding_for_web_tests_(RuntimeEnabledFeatures::NoIdleEncodingForWebTestsEnabled())
,
        notification_constructor_(RuntimeEnabledFeatures::NotificationConstructorEnabled())
,
        notification_content_image_(RuntimeEnabledFeatures::NotificationContentImageEnabled())
,
        notifications_(RuntimeEnabledFeatures::NotificationsEnabled())
,
        notification_triggers_(RuntimeEnabledFeatures::NotificationTriggersEnabledByRuntimeFlag())
,
        off_main_thread_css_paint_(RuntimeEnabledFeatures::OffMainThreadCSSPaintEnabled())
,
        offscreen_canvas_commit_(RuntimeEnabledFeatures::OffscreenCanvasCommitEnabled())
,
        on_device_change_(RuntimeEnabledFeatures::OnDeviceChangeEnabled())
,
        orientation_event_(RuntimeEnabledFeatures::OrientationEventEnabled())
,
        origin_trials_sample_api_(RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabledByRuntimeFlag())
,
        origin_trials_sample_api_dependent_(RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabledByRuntimeFlag())
,
        origin_trials_sample_api_deprecation_(RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag())
,
        origin_trials_sample_api_implied_(RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag())
,
        origin_trials_sample_api_invalid_os_(RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag())
,
        origin_trials_sample_api_navigation_(RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabledByRuntimeFlag())
,
        out_of_blink_cors_(RuntimeEnabledFeatures::OutOfBlinkCorsEnabled())
,
        overflow_icons_for_media_controls_(RuntimeEnabledFeatures::OverflowIconsForMediaControlsEnabled())
,
        overscroll_customization_(RuntimeEnabledFeatures::OverscrollCustomizationEnabled())
,
        page_freeze_opt_in_(RuntimeEnabledFeatures::PageFreezeOptInEnabledByRuntimeFlag())
,
        page_freeze_opt_out_(RuntimeEnabledFeatures::PageFreezeOptOutEnabledByRuntimeFlag())
,
        page_popup_(RuntimeEnabledFeatures::PagePopupEnabled())
,
        paint_under_invalidation_checking_(RuntimeEnabledFeatures::PaintUnderInvalidationCheckingEnabled())
,
        passive_document_event_listeners_(RuntimeEnabledFeatures::PassiveDocumentEventListenersEnabled())
,
        passive_document_wheel_event_listeners_(RuntimeEnabledFeatures::PassiveDocumentWheelEventListenersEnabled())
,
        pass_paint_visual_rect_to_compositor_(RuntimeEnabledFeatures::PassPaintVisualRectToCompositorEnabled())
,
        password_reveal_(RuntimeEnabledFeatures::PasswordRevealEnabled())
,
        payment_app_(RuntimeEnabledFeatures::PaymentAppEnabled())
,
        payment_handler_change_payment_method_(RuntimeEnabledFeatures::PaymentHandlerChangePaymentMethodEnabled())
,
        payment_handler_handles_shipping_and_contact_(RuntimeEnabledFeatures::PaymentHandlerHandlesShippingAndContactEnabled())
,
        payment_method_change_event_(RuntimeEnabledFeatures::PaymentMethodChangeEventEnabled())
,
        payment_request_(RuntimeEnabledFeatures::PaymentRequestEnabled())
,
        payment_request_merchant_validation_event_(RuntimeEnabledFeatures::PaymentRequestMerchantValidationEventEnabled())
,
        payment_retry_(RuntimeEnabledFeatures::PaymentRetryEnabled())
,
        performance_manager_instrumentation_(RuntimeEnabledFeatures::PerformanceManagerInstrumentationEnabled())
,
        periodic_background_sync_(RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled())
,
        per_method_can_make_payment_quota_(RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag())
,
        permission_delegation_(RuntimeEnabledFeatures::PermissionDelegationEnabled())
,
        permissions_(RuntimeEnabledFeatures::PermissionsEnabled())
,
        permissions_request_revoke_(RuntimeEnabledFeatures::PermissionsRequestRevokeEnabled())
,
        picture_in_picture_(RuntimeEnabledFeatures::PictureInPictureEnabled())
,
        picture_in_picture_api_(RuntimeEnabledFeatures::PictureInPictureAPIEnabled())
,
        picture_in_picture_v_2_(RuntimeEnabledFeatures::PictureInPictureV2Enabled())
,
        p_na_cl_(RuntimeEnabledFeatures::PNaClEnabledByRuntimeFlag())
,
        pointer_lock_options_(RuntimeEnabledFeatures::PointerLockOptionsEnabledByRuntimeFlag())
,
        pointer_raw_update_(RuntimeEnabledFeatures::PointerRawUpdateEnabled())
,
        portals_(RuntimeEnabledFeatures::PortalsEnabled())
,
        post_animation_frame_(RuntimeEnabledFeatures::PostAnimationFrameEnabled())
,
        precise_memory_info_(RuntimeEnabledFeatures::PreciseMemoryInfoEnabled())
,
        predicted_events_(RuntimeEnabledFeatures::PredictedEventsEnabled())
,
        prefixed_video_fullscreen_(RuntimeEnabledFeatures::PrefixedVideoFullscreenEnabled())
,
        presentation_(RuntimeEnabledFeatures::PresentationEnabled())
,
        print_browser_(RuntimeEnabledFeatures::PrintBrowserEnabled())
,
        priority_hints_(RuntimeEnabledFeatures::PriorityHintsEnabledByRuntimeFlag())
,
        push_messaging_(RuntimeEnabledFeatures::PushMessagingEnabled())
,
        push_messaging_subscription_change_(RuntimeEnabledFeatures::PushMessagingSubscriptionChangeEnabled())
,
        quic_transport_(RuntimeEnabledFeatures::QuicTransportEnabled())
,
        raw_clipboard_(RuntimeEnabledFeatures::RawClipboardEnabled())
,
        reduced_referrer_granularity_(RuntimeEnabledFeatures::ReducedReferrerGranularityEnabled())
,
        remote_playback_(RuntimeEnabledFeatures::RemotePlaybackEnabled())
,
        remote_playback_backend_(RuntimeEnabledFeatures::RemotePlaybackBackendEnabled())
,
        resize_observer_updates_(RuntimeEnabledFeatures::ResizeObserverUpdatesEnabled())
,
        restrict_app_cache_to_secure_contexts_(RuntimeEnabledFeatures::RestrictAppCacheToSecureContextsEnabled())
,
        restrict_automatic_lazy_frame_loading_to_data_saver_(RuntimeEnabledFeatures::RestrictAutomaticLazyFrameLoadingToDataSaverEnabled())
,
        restrict_automatic_lazy_image_loading_to_data_saver_(RuntimeEnabledFeatures::RestrictAutomaticLazyImageLoadingToDataSaverEnabled())
,
        restricted_webkit_appearance_(RuntimeEnabledFeatures::RestrictedWebkitAppearanceEnabled())
,
        rtc_audio_jitter_buffer_max_packets_(RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag())
,
        rtc_audio_jitter_buffer_rtx_handling_(RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabledByRuntimeFlag())
,
        rtc_dtls_transport_(RuntimeEnabledFeatures::RTCDtlsTransportEnabled())
,
        rtc_ice_transport_extension_(RuntimeEnabledFeatures::RTCIceTransportExtensionEnabledByRuntimeFlag())
,
        rtc_quic_transport_(RuntimeEnabledFeatures::RTCQuicTransportEnabledByRuntimeFlag())
,
        rtc_sctp_transport_(RuntimeEnabledFeatures::RTCSctpTransportEnabled())
,
        rtc_stats_relative_packet_arrival_delay_(RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag())
,
        rtc_svc_scalability_mode_(RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled())
,
        rtc_unified_plan_(RuntimeEnabledFeatures::RTCUnifiedPlanEnabled())
,
        rtc_unified_plan_by_default_(RuntimeEnabledFeatures::RTCUnifiedPlanByDefaultEnabled())
,
        same_site_by_default_cookies_(RuntimeEnabledFeatures::SameSiteByDefaultCookiesEnabled())
,
        screen_enumeration_(RuntimeEnabledFeatures::ScreenEnumerationEnabled())
,
        scripted_speech_recognition_(RuntimeEnabledFeatures::ScriptedSpeechRecognitionEnabled())
,
        scripted_speech_synthesis_(RuntimeEnabledFeatures::ScriptedSpeechSynthesisEnabled())
,
        script_streaming_on_preload_(RuntimeEnabledFeatures::ScriptStreamingOnPreloadEnabled())
,
        scroll_customization_(RuntimeEnabledFeatures::ScrollCustomizationEnabled())
,
        scroll_snap_after_layout_(RuntimeEnabledFeatures::ScrollSnapAfterLayoutEnabled())
,
        scroll_timeline_(RuntimeEnabledFeatures::ScrollTimelineEnabledByRuntimeFlag())
,
        scroll_top_left_interop_(RuntimeEnabledFeatures::ScrollTopLeftInteropEnabled())
,
        send_beacon_throw_for_blob_with_non_simple_type_(RuntimeEnabledFeatures::SendBeaconThrowForBlobWithNonSimpleTypeEnabled())
,
        send_mouse_events_disabled_form_controls_(RuntimeEnabledFeatures::SendMouseEventsDisabledFormControlsEnabled())
,
        sensor_extra_classes_(RuntimeEnabledFeatures::SensorExtraClassesEnabled())
,
        serial_(RuntimeEnabledFeatures::SerialEnabledByRuntimeFlag())
,
        service_worker_client_lifecycle_state_(RuntimeEnabledFeatures::ServiceWorkerClientLifecycleStateEnabled())
,
        service_worker_fetch_event_worker_timing_(RuntimeEnabledFeatures::ServiceWorkerFetchEventWorkerTimingEnabled())
,
        set_root_scroller_(RuntimeEnabledFeatures::SetRootScrollerEnabled())
,
        shadow_dom_v0_(RuntimeEnabledFeatures::ShadowDOMV0EnabledByRuntimeFlag())
,
        shadow_piercing_descendant_combinator_(RuntimeEnabledFeatures::ShadowPiercingDescendantCombinatorEnabled())
,
        shape_detection_(RuntimeEnabledFeatures::ShapeDetectionEnabled())
,
        shared_array_buffer_(RuntimeEnabledFeatures::SharedArrayBufferEnabled())
,
        shared_worker_(RuntimeEnabledFeatures::SharedWorkerEnabled())
,
        signature_based_integrity_(RuntimeEnabledFeatures::SignatureBasedIntegrityEnabledByRuntimeFlag())
,
        signed_exchange_prefetch_cache_for_navigations_(RuntimeEnabledFeatures::SignedExchangePrefetchCacheForNavigationsEnabled())
,
        signed_exchange_subresource_prefetch_(RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabledByRuntimeFlag())
,
        skip_ad_(RuntimeEnabledFeatures::SkipAdEnabledByRuntimeFlag())
,
        skip_touch_event_filter_(RuntimeEnabledFeatures::SkipTouchEventFilterEnabled())
,
        sms_receiver_(RuntimeEnabledFeatures::SmsReceiverEnabledByRuntimeFlag())
,
        stable_blink_features_(RuntimeEnabledFeatures::StableBlinkFeaturesEnabled())
,
        stacked_css_property_animations_(RuntimeEnabledFeatures::StackedCSSPropertyAnimationsEnabled())
,
        storage_access_api_(RuntimeEnabledFeatures::StorageAccessAPIEnabled())
,
        storage_quota_details_(RuntimeEnabledFeatures::StorageQuotaDetailsEnabled())
,
        strict_mime_types_for_workers_(RuntimeEnabledFeatures::StrictMimeTypesForWorkersEnabled())
,
        surface_embedding_features_(RuntimeEnabledFeatures::SurfaceEmbeddingFeaturesEnabled())
,
        text_fragment_identifiers_(RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag())
,
        timer_throttling_for_background_tabs_(RuntimeEnabledFeatures::TimerThrottlingForBackgroundTabsEnabled())
,
        timer_throttling_for_hidden_frames_(RuntimeEnabledFeatures::TimerThrottlingForHiddenFramesEnabled())
,
        touch_event_feature_detection_(RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag())
,
        track_layout_passes_per_block_(RuntimeEnabledFeatures::TrackLayoutPassesPerBlockEnabled())
,
        transferable_streams_(RuntimeEnabledFeatures::TransferableStreamsEnabled())
,
        translate_service_(RuntimeEnabledFeatures::TranslateServiceEnabled())
,
        trusted_dom_types_(RuntimeEnabledFeatures::TrustedDOMTypesEnabled())
,
        unclosed_form_control_is_invalid_(RuntimeEnabledFeatures::UnclosedFormControlIsInvalidEnabled())
,
        unified_pointer_capture_in_blink_(RuntimeEnabledFeatures::UnifiedPointerCaptureInBlinkEnabled())
,
        unified_touch_adjustment_(RuntimeEnabledFeatures::UnifiedTouchAdjustmentEnabled())
,
        unoptimized_image_policies_(RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabledByRuntimeFlag())
,
        unsized_media_policy_(RuntimeEnabledFeatures::UnsizedMediaPolicyEnabledByRuntimeFlag())
,
        update_hover_at_begin_frame_(RuntimeEnabledFeatures::UpdateHoverAtBeginFrameEnabled())
,
        user_activation_api_(RuntimeEnabledFeatures::UserActivationAPIEnabled())
,
        user_activation_post_message_transfer_(RuntimeEnabledFeatures::UserActivationPostMessageTransferEnabled())
,
        user_activation_same_origin_visibility_(RuntimeEnabledFeatures::UserActivationSameOriginVisibilityEnabled())
,
        user_agent_client_hint_(RuntimeEnabledFeatures::UserAgentClientHintEnabled())
,
        use_windows_system_colors_(RuntimeEnabledFeatures::UseWindowsSystemColorsEnabled())
,
        v8_idle_tasks_(RuntimeEnabledFeatures::V8IdleTasksEnabled())
,
        video_auto_fullscreen_(RuntimeEnabledFeatures::VideoAutoFullscreenEnabled())
,
        video_fullscreen_detection_(RuntimeEnabledFeatures::VideoFullscreenDetectionEnabled())
,
        video_fullscreen_orientation_lock_(RuntimeEnabledFeatures::VideoFullscreenOrientationLockEnabled())
,
        video_playback_quality_(RuntimeEnabledFeatures::VideoPlaybackQualityEnabled())
,
        video_request_animation_frame_(RuntimeEnabledFeatures::VideoRequestAnimationFrameEnabled())
,
        video_rotate_to_fullscreen_(RuntimeEnabledFeatures::VideoRotateToFullscreenEnabled())
,
        visibility_collapse_column_(RuntimeEnabledFeatures::VisibilityCollapseColumnEnabled())
,
        wake_lock_(RuntimeEnabledFeatures::WakeLockEnabledByRuntimeFlag())
,
        wasm_code_cache_(RuntimeEnabledFeatures::WasmCodeCacheEnabled())
,
        web_animations_api_(RuntimeEnabledFeatures::WebAnimationsAPIEnabled())
,
        web_animations_svg_(RuntimeEnabledFeatures::WebAnimationsSVGEnabled())
,
        web_assembly_threads_(RuntimeEnabledFeatures::WebAssemblyThreadsEnabledByRuntimeFlag())
,
        web_auth_(RuntimeEnabledFeatures::WebAuthEnabled())
,
        web_authentication_feature_policy_(RuntimeEnabledFeatures::WebAuthenticationFeaturePolicyEnabled())
,
        web_bluetooth_(RuntimeEnabledFeatures::WebBluetoothEnabled())
,
        web_bluetooth_scanning_(RuntimeEnabledFeatures::WebBluetoothScanningEnabled())
,
        web_codecs_(RuntimeEnabledFeatures::WebCodecsEnabled())
,
        webgl2_compute_context_(RuntimeEnabledFeatures::WebGL2ComputeContextEnabled())
,
        webgl_draft_extensions_(RuntimeEnabledFeatures::WebGLDraftExtensionsEnabled())
,
        webgl_image_chromium_(RuntimeEnabledFeatures::WebGLImageChromiumEnabled())
,
        webgpu_(RuntimeEnabledFeatures::WebGPUEnabled())
,
        web_hid_(RuntimeEnabledFeatures::WebHIDEnabled())
,
        web_nfc_(RuntimeEnabledFeatures::WebNFCEnabledByRuntimeFlag())
,
        web_scheduler_(RuntimeEnabledFeatures::WebSchedulerEnabledByRuntimeFlag())
,
        web_share_(RuntimeEnabledFeatures::WebShareEnabled())
,
        web_share_v_2_(RuntimeEnabledFeatures::WebShareV2Enabled())
,
        websocket_stream_(RuntimeEnabledFeatures::WebSocketStreamEnabledByRuntimeFlag())
,
        web_usb_(RuntimeEnabledFeatures::WebUSBEnabled())
,
        web_usb_on_dedicated_workers_(RuntimeEnabledFeatures::WebUSBOnDedicatedWorkersEnabled())
,
        web_vtt_regions_(RuntimeEnabledFeatures::WebVTTRegionsEnabled())
,
        web_xr_(RuntimeEnabledFeatures::WebXREnabled())
,
        web_xr_ar_module_(RuntimeEnabledFeatures::WebXRARModuleEnabled())
,
        web_xr_hit_test_(RuntimeEnabledFeatures::WebXRHitTestEnabled())
,
        web_xr_hit_test_entity_types_(RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled())
,
        web_xr_incubations_(RuntimeEnabledFeatures::WebXRIncubationsEnabled())
,
        window_placement_(RuntimeEnabledFeatures::WindowPlacementEnabled())
,
        writable_file_stream_(RuntimeEnabledFeatures::WritableFileStreamEnabled())
,
        xslt_(RuntimeEnabledFeatures::XSLTEnabled())
 {}

void RuntimeEnabledFeatures::Backup::Restore() {
  RuntimeEnabledFeatures::SetAccelerated2dCanvasEnabled(accelerated_2d_canvas_);
  RuntimeEnabledFeatures::SetAcceleratedSmallCanvasesEnabled(accelerated_small_canvases_);
  RuntimeEnabledFeatures::SetAccessibilityExposeARIAAnnotationsEnabled(accessibility_expose_aria_annotations_);
  RuntimeEnabledFeatures::SetAccessibilityExposeDisplayNoneEnabled(accessibility_expose_display_none_);
  RuntimeEnabledFeatures::SetAccessibilityObjectModelEnabled(accessibility_object_model_);
  RuntimeEnabledFeatures::SetAddressSpaceEnabled(address_space_);
  RuntimeEnabledFeatures::SetAdTaggingEnabled(ad_tagging_);
  RuntimeEnabledFeatures::SetAllowActivationDelegationAttrEnabled(allow_activation_delegation_attr_);
  RuntimeEnabledFeatures::SetAllowContentInitiatedDataUrlNavigationsEnabled(allow_content_initiated_data_url_navigations_);
  RuntimeEnabledFeatures::SetAllowSyncXHRInPageDismissalEnabled(allow_sync_xhr_in_page_dismissal_);
  RuntimeEnabledFeatures::SetAnimationWorkletEnabled(animation_worklet_);
  RuntimeEnabledFeatures::SetAOMAriaPropertiesEnabled(aom_aria_properties_);
  RuntimeEnabledFeatures::SetAOMAriaRelationshipPropertiesEnabled(aom_aria_relationship_properties_);
  RuntimeEnabledFeatures::SetAspectRatioFromWidthAndHeightEnabled(aspect_ratio_from_width_and_height_);
  RuntimeEnabledFeatures::SetAsyncClipboardEnabled(async_clipboard_);
  RuntimeEnabledFeatures::SetAudioOutputDevicesEnabled(audio_output_devices_);
  RuntimeEnabledFeatures::SetAudioVideoTracksEnabled(audio_video_tracks_);
  RuntimeEnabledFeatures::SetAudioWorkletRealtimeThreadEnabled(audio_worklet_realtime_thread_);
  RuntimeEnabledFeatures::SetAutoLazyLoadOnReloadsEnabled(auto_lazy_load_on_reloads_);
  RuntimeEnabledFeatures::SetAutomaticLazyFrameLoadingEnabled(automatic_lazy_frame_loading_);
  RuntimeEnabledFeatures::SetAutomaticLazyImageLoadingEnabled(automatic_lazy_image_loading_);
  RuntimeEnabledFeatures::SetAutomationControlledEnabled(automation_controlled_);
  RuntimeEnabledFeatures::SetAutoPictureInPictureEnabled(auto_picture_in_picture_);
  RuntimeEnabledFeatures::SetAutoplayIgnoresWebAudioEnabled(autoplay_ignores_web_audio_);
  RuntimeEnabledFeatures::SetBackForwardCacheEnabled(back_forward_cache_);
  RuntimeEnabledFeatures::SetBackgroundFetchEnabled(background_fetch_);
  RuntimeEnabledFeatures::SetBackgroundVideoTrackOptimizationEnabled(background_video_track_optimization_);
  RuntimeEnabledFeatures::SetBadgingEnabled(badging_);
  RuntimeEnabledFeatures::SetBidiCaretAffinityEnabled(bidi_caret_affinity_);
  RuntimeEnabledFeatures::SetBlinkRuntimeCallStatsEnabled(blink_runtime_call_stats_);
  RuntimeEnabledFeatures::SetBlobReadMethodsEnabled(blob_read_methods_);
  RuntimeEnabledFeatures::SetBlockCredentialedSubresourcesEnabled(block_credentialed_subresources_);
  RuntimeEnabledFeatures::SetBlockHTMLParserOnStyleSheetsEnabled(block_html_parser_on_style_sheets_);
  RuntimeEnabledFeatures::SetBlockingDownloadsInSandboxEnabled(blocking_downloads_in_sandbox_);
  RuntimeEnabledFeatures::SetBlockingFocusWithoutUserActivationEnabled(blocking_focus_without_user_activation_);
  RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationKeyboardEnabled(browser_verified_user_activation_keyboard_);
  RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationMouseEnabled(browser_verified_user_activation_mouse_);
  RuntimeEnabledFeatures::SetBuiltInModuleAllEnabled(built_in_module_all_);
  RuntimeEnabledFeatures::SetBuiltInModuleInfraEnabled(built_in_module_infra_);
  RuntimeEnabledFeatures::SetBuiltInModuleKvStorageEnabled(built_in_module_kv_storage_);
  RuntimeEnabledFeatures::SetBuiltInModuleSwitchElementEnabled(built_in_module_switch_element_);
  RuntimeEnabledFeatures::SetCacheInlineScriptCodeEnabled(cache_inline_script_code_);
  RuntimeEnabledFeatures::SetCacheStorageCodeCacheHintEnabled(cache_storage_code_cache_hint_);
  RuntimeEnabledFeatures::SetCanvas2dContextLostRestoredEnabled(canvas_2d_context_lost_restored_);
  RuntimeEnabledFeatures::SetCanvas2dImageChromiumEnabled(canvas_2d_image_chromium_);
  RuntimeEnabledFeatures::SetCanvas2dScrollPathIntoViewEnabled(canvas_2d_scroll_path_into_view_);
  RuntimeEnabledFeatures::SetCanvasColorManagementEnabled(canvas_color_management_);
  RuntimeEnabledFeatures::SetCanvasHitRegionEnabled(canvas_hit_region_);
  RuntimeEnabledFeatures::SetCanvasImageSmoothingEnabled(canvas_image_smoothing_);
  RuntimeEnabledFeatures::SetClickPointerEventEnabled(click_pointer_event_);
  RuntimeEnabledFeatures::SetClickRetargettingEnabled(click_retargetting_);
  RuntimeEnabledFeatures::SetCloneableNativeFileSystemHandlesEnabled(cloneable_native_file_system_handles_);
  RuntimeEnabledFeatures::SetCompositeAfterPaintEnabled(composite_after_paint_);
  RuntimeEnabledFeatures::SetCompositedSelectionUpdateEnabled(composited_selection_update_);
  RuntimeEnabledFeatures::SetCompositorTouchActionEnabled(compositor_touch_action_);
  RuntimeEnabledFeatures::SetComputedAccessibilityInfoEnabled(computed_accessibility_info_);
  RuntimeEnabledFeatures::SetConsolidatedMovementXYEnabled(consolidated_movement_xy_);
  RuntimeEnabledFeatures::SetContactsManagerEnabled(contacts_manager_);
  RuntimeEnabledFeatures::SetContactsManagerExtraPropertiesEnabled(contacts_manager_extra_properties_);
  RuntimeEnabledFeatures::SetContentIndexEnabled(content_index_);
  RuntimeEnabledFeatures::SetContextMenuEnabled(context_menu_);
  RuntimeEnabledFeatures::SetCookieDeprecationMessagesEnabled(cookie_deprecation_messages_);
  RuntimeEnabledFeatures::SetCookieStoreDocumentEnabled(cookie_store_document_);
  RuntimeEnabledFeatures::SetCookieStoreWorkerEnabled(cookie_store_worker_);
  RuntimeEnabledFeatures::SetCookiesWithoutSameSiteMustBeSecureEnabled(cookies_without_same_site_must_be_secure_);
  RuntimeEnabledFeatures::SetCooperativeSchedulingEnabled(cooperative_scheduling_);
  RuntimeEnabledFeatures::SetCorsRFC1918Enabled(cors_rfc_1918_);
  RuntimeEnabledFeatures::SetCSS3TextEnabled(css_3_text_);
  RuntimeEnabledFeatures::SetCSS3TextBreakAnywhereEnabled(css_3_text_break_anywhere_);
  RuntimeEnabledFeatures::SetCSSAdditiveAnimationsEnabled(css_additive_animations_);
  RuntimeEnabledFeatures::SetCSSCalcAsIntEnabled(css_calc_as_int_);
  RuntimeEnabledFeatures::SetCSSCascadeEnabled(css_cascade_);
  RuntimeEnabledFeatures::SetCSSColorSchemeEnabled(css_color_scheme_);
  RuntimeEnabledFeatures::SetCSSColorSchemeUARenderingEnabled(css_color_scheme_ua_rendering_);
  RuntimeEnabledFeatures::SetCSSFocusVisibleEnabled(css_focus_visible_);
  RuntimeEnabledFeatures::SetCSSFontSizeAdjustEnabled(css_font_size_adjust_);
  RuntimeEnabledFeatures::SetCSSHexAlphaColorEnabled(css_hex_alpha_color_);
  RuntimeEnabledFeatures::SetCSSIndependentTransformPropertiesEnabled(css_independent_transform_properties_);
  RuntimeEnabledFeatures::SetCSSIntrinsicSizeEnabled(css_intrinsic_size_);
  RuntimeEnabledFeatures::SetCSSLayoutAPIEnabled(css_layout_api_);
  RuntimeEnabledFeatures::SetCSSLogicalEnabled(css_logical_);
  RuntimeEnabledFeatures::SetCSSLogicalOverflowEnabled(css_logical_overflow_);
  RuntimeEnabledFeatures::SetCSSMarkerPseudoElementEnabled(css_marker_pseudo_element_);
  RuntimeEnabledFeatures::SetCSSMaskSourceTypeEnabled(css_mask_source_type_);
  RuntimeEnabledFeatures::SetCSSModulesEnabled(css_modules_);
  RuntimeEnabledFeatures::SetCSSOffsetPathRayEnabled(css_offset_path_ray_);
  RuntimeEnabledFeatures::SetCSSOffsetPathRayContainEnabled(css_offset_path_ray_contain_);
  RuntimeEnabledFeatures::SetCSSOffsetPositionAnchorEnabled(css_offset_position_anchor_);
  RuntimeEnabledFeatures::SetCSSOMViewScrollCoordinatesEnabled(cssom_view_scroll_coordinates_);
  RuntimeEnabledFeatures::SetCSSPaintAPIArgumentsEnabled(css_paint_api_arguments_);
  RuntimeEnabledFeatures::SetCSSPictureInPictureEnabled(css_picture_in_picture_);
  RuntimeEnabledFeatures::SetCSSPseudoIsEnabled(css_pseudo_is_);
  RuntimeEnabledFeatures::SetCSSPseudoWhereEnabled(css_pseudo_where_);
  RuntimeEnabledFeatures::SetCSSRenderSubtreeEnabled(css_render_subtree_);
  RuntimeEnabledFeatures::SetCSSSnapSizeEnabled(css_snap_size_);
  RuntimeEnabledFeatures::SetCSSVariables2Enabled(css_variables_2_);
  RuntimeEnabledFeatures::SetCSSVariables2AtPropertyEnabled(css_variables_2_at_property_);
  RuntimeEnabledFeatures::SetCSSVariables2ImageValuesEnabled(css_variables_2_image_values_);
  RuntimeEnabledFeatures::SetCSSVariables2TransformValuesEnabled(css_variables_2_transform_values_);
  RuntimeEnabledFeatures::SetCSSViewportEnabled(css_viewport_);
  RuntimeEnabledFeatures::SetCustomElementDefaultStyleEnabled(custom_element_default_style_);
  RuntimeEnabledFeatures::SetCustomElementsV0Enabled(custom_elements_v0_);
  RuntimeEnabledFeatures::SetCustomStatePseudoClassEnabled(custom_state_pseudo_class_);
  RuntimeEnabledFeatures::SetDatabaseEnabled(database_);
  RuntimeEnabledFeatures::SetDecodeJpeg420ImagesToYUVEnabled(decode_jpeg_420_images_to_yuv_);
  RuntimeEnabledFeatures::SetDecodeLossyWebPImagesToYUVEnabled(decode_lossy_web_p_images_to_yuv_);
  RuntimeEnabledFeatures::SetDesktopCaptureDisableLocalEchoControlEnabled(desktop_capture_disable_local_echo_control_);
  RuntimeEnabledFeatures::SetDisableHardwareNoiseSuppressionEnabled(disable_hardware_noise_suppression_);
  RuntimeEnabledFeatures::SetDisallowDocumentAccessEnabled(disallow_document_access_);
  RuntimeEnabledFeatures::SetDiscardInputToMovingIframesEnabled(discard_input_to_moving_iframes_);
  RuntimeEnabledFeatures::SetDisplayCutoutAPIEnabled(display_cutout_api_);
  RuntimeEnabledFeatures::SetDisplayLockingEnabled(display_locking_);
  RuntimeEnabledFeatures::SetDocumentCookieEnabled(document_cookie_);
  RuntimeEnabledFeatures::SetDocumentDomainEnabled(document_domain_);
  RuntimeEnabledFeatures::SetDocumentPolicyEnabled(document_policy_);
  RuntimeEnabledFeatures::SetDocumentWriteEnabled(document_write_);
  RuntimeEnabledFeatures::SetEditContextEnabled(edit_context_);
  RuntimeEnabledFeatures::SetEditingNGEnabled(editing_ng_);
  RuntimeEnabledFeatures::SetEmbeddedVTTStylesheetsEnabled(embedded_vtt_stylesheets_);
  RuntimeEnabledFeatures::SetEncryptedMediaEncryptionSchemeQueryEnabled(encrypted_media_encryption_scheme_query_);
  RuntimeEnabledFeatures::SetEncryptedMediaHdcpPolicyCheckEnabled(encrypted_media_hdcp_policy_check_);
  RuntimeEnabledFeatures::SetEncryptedMediaPersistentUsageRecordSessionEnabled(encrypted_media_persistent_usage_record_session_);
  RuntimeEnabledFeatures::SetEnterKeyHintAttributeEnabled(enter_key_hint_attribute_);
  RuntimeEnabledFeatures::SetEventTimingEnabled(event_timing_);
  RuntimeEnabledFeatures::SetExecCommandInJavaScriptEnabled(exec_command_in_java_script_);
  RuntimeEnabledFeatures::SetExpensiveBackgroundTimerThrottlingEnabled(expensive_background_timer_throttling_);
  RuntimeEnabledFeatures::SetExperimentalAutoplayDynamicDelegationEnabled(experimental_autoplay_dynamic_delegation_);
  RuntimeEnabledFeatures::SetExperimentalContentSecurityPolicyFeaturesEnabled(experimental_content_security_policy_features_);
  RuntimeEnabledFeatures::SetExperimentalIsInputPendingEnabled(experimental_is_input_pending_);
  RuntimeEnabledFeatures::SetExperimentalJSProfilerEnabled(experimental_js_profiler_);
  RuntimeEnabledFeatures::SetExperimentalProductivityFeaturesEnabled(experimental_productivity_features_);
  RuntimeEnabledFeatures::SetExtendedTextMetricsEnabled(extended_text_metrics_);
  RuntimeEnabledFeatures::SetExtraWebGLVideoTextureMetadataEnabled(extra_webgl_video_texture_metadata_);
  RuntimeEnabledFeatures::SetFallbackCursorModeEnabled(fallback_cursor_mode_);
  RuntimeEnabledFeatures::SetFeaturePolicyForClientHintsEnabled(feature_policy_for_client_hints_);
  RuntimeEnabledFeatures::SetFeaturePolicyForSandboxEnabled(feature_policy_for_sandbox_);
  RuntimeEnabledFeatures::SetFeaturePolicyJavaScriptInterfaceEnabled(feature_policy_java_script_interface_);
  RuntimeEnabledFeatures::SetFeaturePolicyReportingEnabled(feature_policy_reporting_);
  RuntimeEnabledFeatures::SetFeaturePolicyVibrateFeatureEnabled(feature_policy_vibrate_feature_);
  RuntimeEnabledFeatures::SetFetchMetadataEnabled(fetch_metadata_);
  RuntimeEnabledFeatures::SetFetchMetadataDestinationEnabled(fetch_metadata_destination_);
  RuntimeEnabledFeatures::SetFileHandlingEnabled(file_handling_);
  RuntimeEnabledFeatures::SetFileSystemEnabled(file_system_);
  RuntimeEnabledFeatures::SetFlatTreeStyleRecalcEnabled(flat_tree_style_recalc_);
  RuntimeEnabledFeatures::SetFocuslessSpatialNavigationEnabled(focusless_spatial_navigation_);
  RuntimeEnabledFeatures::SetFontSrcLocalMatchingEnabled(font_src_local_matching_);
  RuntimeEnabledFeatures::SetForcedColorsEnabled(forced_colors_);
  RuntimeEnabledFeatures::SetForceDeferScriptInterventionEnabled(force_defer_script_intervention_);
  RuntimeEnabledFeatures::SetForceEagerMeasureMemoryEnabled(force_eager_measure_memory_);
  RuntimeEnabledFeatures::SetForceOverlayFullscreenVideoEnabled(force_overlay_fullscreen_video_);
  RuntimeEnabledFeatures::SetForceSynchronousHTMLParsingEnabled(force_synchronous_html_parsing_);
  RuntimeEnabledFeatures::SetForceTallerSelectPopupEnabled(force_taller_select_popup_);
  RuntimeEnabledFeatures::SetFractionalMouseEventEnabled(fractional_mouse_event_);
  RuntimeEnabledFeatures::SetFractionalScrollOffsetsEnabled(fractional_scroll_offsets_);
  RuntimeEnabledFeatures::SetFreezeFramesOnVisibilityEnabled(freeze_frames_on_visibility_);
  RuntimeEnabledFeatures::SetGamepadButtonAxisEventsEnabled(gamepad_button_axis_events_);
  RuntimeEnabledFeatures::SetGetDisplayMediaEnabled(get_display_media_);
  RuntimeEnabledFeatures::SetGroupEffectEnabled(group_effect_);
  RuntimeEnabledFeatures::SetHrefTranslateEnabled(href_translate_);
  RuntimeEnabledFeatures::SetHTMLImportsEnabled(html_imports_);
  RuntimeEnabledFeatures::SetIDBObserverEnabled(idb_observer_);
  RuntimeEnabledFeatures::SetIDBRelaxedDurabilityEnabled(idb_relaxed_durability_);
  RuntimeEnabledFeatures::SetIdleDetectionEnabled(idle_detection_);
  RuntimeEnabledFeatures::SetIgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled(ignore_cross_origin_window_when_named_access_on_window_);
  RuntimeEnabledFeatures::SetImageOrientationEnabled(image_orientation_);
  RuntimeEnabledFeatures::SetImplicitRootScrollerEnabled(implicit_root_scroller_);
  RuntimeEnabledFeatures::SetImportMapsEnabled(import_maps_);
  RuntimeEnabledFeatures::SetInertAttributeEnabled(inert_attribute_);
  RuntimeEnabledFeatures::SetInputMultipleFieldsUIEnabled(input_multiple_fields_ui_);
  RuntimeEnabledFeatures::SetInstalledAppEnabled(installed_app_);
  RuntimeEnabledFeatures::SetIntersectionObserverDocumentScrollingElementRootEnabled(intersection_observer_document_scrolling_element_root_);
  RuntimeEnabledFeatures::SetIntersectionObserverV2Enabled(intersection_observer_v_2_);
  RuntimeEnabledFeatures::SetInvisibleDOMEnabled(invisible_dom_);
  RuntimeEnabledFeatures::SetIsolatedCodeCacheEnabled(isolated_code_cache_);
  RuntimeEnabledFeatures::SetIsolatedWorldCSPEnabled(isolated_world_csp_);
  RuntimeEnabledFeatures::SetKeyboardFocusableScrollersEnabled(keyboard_focusable_scrollers_);
  RuntimeEnabledFeatures::SetLangAttributeAwareFormControlUIEnabled(lang_attribute_aware_form_control_ui_);
  RuntimeEnabledFeatures::SetLangClientHintHeaderEnabled(lang_client_hint_header_);
  RuntimeEnabledFeatures::SetLayoutNGEnabled(layout_ng_);
  RuntimeEnabledFeatures::SetLayoutNGBlockFragmentationEnabled(layout_ng_block_fragmentation_);
  RuntimeEnabledFeatures::SetLayoutNGFieldsetEnabled(layout_ng_fieldset_);
  RuntimeEnabledFeatures::SetLayoutNGFlexBoxEnabled(layout_ng_flex_box_);
  RuntimeEnabledFeatures::SetLayoutNGFragmentItemEnabled(layout_ng_fragment_item_);
  RuntimeEnabledFeatures::SetLayoutNGFragmentPaintEnabled(layout_ng_fragment_paint_);
  RuntimeEnabledFeatures::SetLayoutNGLineCacheEnabled(layout_ng_line_cache_);
  RuntimeEnabledFeatures::SetLayoutNGTableEnabled(layout_ng_table_);
  RuntimeEnabledFeatures::SetLazyFrameLoadingEnabled(lazy_frame_loading_);
  RuntimeEnabledFeatures::SetLazyFrameVisibleLoadTimeMetricsEnabled(lazy_frame_visible_load_time_metrics_);
  RuntimeEnabledFeatures::SetLazyImageLoadingEnabled(lazy_image_loading_);
  RuntimeEnabledFeatures::SetLazyImageLoadingMetadataFetchEnabled(lazy_image_loading_metadata_fetch_);
  RuntimeEnabledFeatures::SetLazyImageVisibleLoadTimeMetricsEnabled(lazy_image_visible_load_time_metrics_);
  RuntimeEnabledFeatures::SetLazyInitializeMediaControlsEnabled(lazy_initialize_media_controls_);
  RuntimeEnabledFeatures::SetLegacyWindowsDWriteFontFallbackEnabled(legacy_windows_d_write_font_fallback_);
  RuntimeEnabledFeatures::SetLinkSystemColorsEnabled(link_system_colors_);
  RuntimeEnabledFeatures::SetManualSlottingEnabled(manual_slotting_);
  RuntimeEnabledFeatures::SetMathMLCoreEnabled(mathml_core_);
  RuntimeEnabledFeatures::SetMeasureMemoryEnabled(measure_memory_);
  RuntimeEnabledFeatures::SetMediaCapabilitiesEncodingInfoEnabled(media_capabilities_encoding_info_);
  RuntimeEnabledFeatures::SetMediaCapabilitiesEncryptedMediaEnabled(media_capabilities_encrypted_media_);
  RuntimeEnabledFeatures::SetMediaCapabilitiesSpatialAudioEnabled(media_capabilities_spatial_audio_);
  RuntimeEnabledFeatures::SetMediaCaptureEnabled(media_capture_);
  RuntimeEnabledFeatures::SetMediaCaptureDepthVideoKindEnabled(media_capture_depth_video_kind_);
  RuntimeEnabledFeatures::SetMediaCapturePanTiltEnabled(media_capture_pan_tilt_);
  RuntimeEnabledFeatures::SetMediaCastOverlayButtonEnabled(media_cast_overlay_button_);
  RuntimeEnabledFeatures::SetMediaControlsExpandGestureEnabled(media_controls_expand_gesture_);
  RuntimeEnabledFeatures::SetMediaControlsOverlayPlayButtonEnabled(media_controls_overlay_play_button_);
  RuntimeEnabledFeatures::SetMediaDocumentDownloadButtonEnabled(media_document_download_button_);
  RuntimeEnabledFeatures::SetMediaElementVolumeGreaterThanOneEnabled(media_element_volume_greater_than_one_);
  RuntimeEnabledFeatures::SetMediaEngagementBypassAutoplayPoliciesEnabled(media_engagement_bypass_autoplay_policies_);
  RuntimeEnabledFeatures::SetMediaLatencyHintEnabled(media_latency_hint_);
  RuntimeEnabledFeatures::SetMediaQueryNavigationControlsEnabled(media_query_navigation_controls_);
  RuntimeEnabledFeatures::SetMediaQueryShapeEnabled(media_query_shape_);
  RuntimeEnabledFeatures::SetMediaSessionEnabled(media_session_);
  RuntimeEnabledFeatures::SetMediaSessionPositionEnabled(media_session_position_);
  RuntimeEnabledFeatures::SetMediaSessionSeekingEnabled(media_session_seeking_);
  RuntimeEnabledFeatures::SetMediaSourceExperimentalEnabled(media_source_experimental_);
  RuntimeEnabledFeatures::SetMediaSourceInWorkersEnabled(media_source_in_workers_);
  RuntimeEnabledFeatures::SetMediaSourceNewAbortAndDurationEnabled(media_source_new_abort_and_duration_);
  RuntimeEnabledFeatures::SetMediaSourceStableEnabled(media_source_stable_);
  RuntimeEnabledFeatures::SetMetaColorSchemeEnabled(meta_color_scheme_);
  RuntimeEnabledFeatures::SetMiddleClickAutoscrollEnabled(middle_click_autoscroll_);
  RuntimeEnabledFeatures::SetMobileLayoutThemeEnabled(mobile_layout_theme_);
  RuntimeEnabledFeatures::SetModuleDedicatedWorkerEnabled(module_dedicated_worker_);
  RuntimeEnabledFeatures::SetModuleServiceWorkerEnabled(module_service_worker_);
  RuntimeEnabledFeatures::SetModuleSharedWorkerEnabled(module_shared_worker_);
  RuntimeEnabledFeatures::SetMojoJSEnabled(mojo_js_);
  RuntimeEnabledFeatures::SetMojoJSTestEnabled(mojo_js_test_);
  RuntimeEnabledFeatures::SetMouseSubframeNoImplicitCaptureEnabled(mouse_subframe_no_implicit_capture_);
  RuntimeEnabledFeatures::SetNativeFileSystemEnabled(native_file_system_);
  RuntimeEnabledFeatures::SetNavigatorContentUtilsEnabled(navigator_content_utils_);
  RuntimeEnabledFeatures::SetNavigatorLanguageInInsecureContextEnabled(navigator_language_in_insecure_context_);
  RuntimeEnabledFeatures::SetNetInfoDownlinkMaxEnabled(net_info_downlink_max_);
  RuntimeEnabledFeatures::SetNeverSlowModeEnabled(never_slow_mode_);
  RuntimeEnabledFeatures::SetNewRemotePlaybackPipelineEnabled(new_remote_playback_pipeline_);
  RuntimeEnabledFeatures::SetNewSystemColorsEnabled(new_system_colors_);
  RuntimeEnabledFeatures::SetNoIdleEncodingForWebTestsEnabled(no_idle_encoding_for_web_tests_);
  RuntimeEnabledFeatures::SetNotificationConstructorEnabled(notification_constructor_);
  RuntimeEnabledFeatures::SetNotificationContentImageEnabled(notification_content_image_);
  RuntimeEnabledFeatures::SetNotificationsEnabled(notifications_);
  RuntimeEnabledFeatures::SetNotificationTriggersEnabled(notification_triggers_);
  RuntimeEnabledFeatures::SetOffMainThreadCSSPaintEnabled(off_main_thread_css_paint_);
  RuntimeEnabledFeatures::SetOffscreenCanvasCommitEnabled(offscreen_canvas_commit_);
  RuntimeEnabledFeatures::SetOnDeviceChangeEnabled(on_device_change_);
  RuntimeEnabledFeatures::SetOrientationEventEnabled(orientation_event_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPIEnabled(origin_trials_sample_api_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPIDependentEnabled(origin_trials_sample_api_dependent_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPIDeprecationEnabled(origin_trials_sample_api_deprecation_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPIImpliedEnabled(origin_trials_sample_api_implied_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPIInvalidOSEnabled(origin_trials_sample_api_invalid_os_);
  RuntimeEnabledFeatures::SetOriginTrialsSampleAPINavigationEnabled(origin_trials_sample_api_navigation_);
  RuntimeEnabledFeatures::SetOutOfBlinkCorsEnabled(out_of_blink_cors_);
  RuntimeEnabledFeatures::SetOverflowIconsForMediaControlsEnabled(overflow_icons_for_media_controls_);
  RuntimeEnabledFeatures::SetOverscrollCustomizationEnabled(overscroll_customization_);
  RuntimeEnabledFeatures::SetPageFreezeOptInEnabled(page_freeze_opt_in_);
  RuntimeEnabledFeatures::SetPageFreezeOptOutEnabled(page_freeze_opt_out_);
  RuntimeEnabledFeatures::SetPagePopupEnabled(page_popup_);
  RuntimeEnabledFeatures::SetPaintUnderInvalidationCheckingEnabled(paint_under_invalidation_checking_);
  RuntimeEnabledFeatures::SetPassiveDocumentEventListenersEnabled(passive_document_event_listeners_);
  RuntimeEnabledFeatures::SetPassiveDocumentWheelEventListenersEnabled(passive_document_wheel_event_listeners_);
  RuntimeEnabledFeatures::SetPassPaintVisualRectToCompositorEnabled(pass_paint_visual_rect_to_compositor_);
  RuntimeEnabledFeatures::SetPasswordRevealEnabled(password_reveal_);
  RuntimeEnabledFeatures::SetPaymentAppEnabled(payment_app_);
  RuntimeEnabledFeatures::SetPaymentHandlerChangePaymentMethodEnabled(payment_handler_change_payment_method_);
  RuntimeEnabledFeatures::SetPaymentHandlerHandlesShippingAndContactEnabled(payment_handler_handles_shipping_and_contact_);
  RuntimeEnabledFeatures::SetPaymentMethodChangeEventEnabled(payment_method_change_event_);
  RuntimeEnabledFeatures::SetPaymentRequestEnabled(payment_request_);
  RuntimeEnabledFeatures::SetPaymentRequestMerchantValidationEventEnabled(payment_request_merchant_validation_event_);
  RuntimeEnabledFeatures::SetPaymentRetryEnabled(payment_retry_);
  RuntimeEnabledFeatures::SetPerformanceManagerInstrumentationEnabled(performance_manager_instrumentation_);
  RuntimeEnabledFeatures::SetPeriodicBackgroundSyncEnabled(periodic_background_sync_);
  RuntimeEnabledFeatures::SetPerMethodCanMakePaymentQuotaEnabled(per_method_can_make_payment_quota_);
  RuntimeEnabledFeatures::SetPermissionDelegationEnabled(permission_delegation_);
  RuntimeEnabledFeatures::SetPermissionsEnabled(permissions_);
  RuntimeEnabledFeatures::SetPermissionsRequestRevokeEnabled(permissions_request_revoke_);
  RuntimeEnabledFeatures::SetPictureInPictureEnabled(picture_in_picture_);
  RuntimeEnabledFeatures::SetPictureInPictureAPIEnabled(picture_in_picture_api_);
  RuntimeEnabledFeatures::SetPictureInPictureV2Enabled(picture_in_picture_v_2_);
  RuntimeEnabledFeatures::SetPNaClEnabled(p_na_cl_);
  RuntimeEnabledFeatures::SetPointerLockOptionsEnabled(pointer_lock_options_);
  RuntimeEnabledFeatures::SetPointerRawUpdateEnabled(pointer_raw_update_);
  RuntimeEnabledFeatures::SetPortalsEnabled(portals_);
  RuntimeEnabledFeatures::SetPostAnimationFrameEnabled(post_animation_frame_);
  RuntimeEnabledFeatures::SetPreciseMemoryInfoEnabled(precise_memory_info_);
  RuntimeEnabledFeatures::SetPredictedEventsEnabled(predicted_events_);
  RuntimeEnabledFeatures::SetPrefixedVideoFullscreenEnabled(prefixed_video_fullscreen_);
  RuntimeEnabledFeatures::SetPresentationEnabled(presentation_);
  RuntimeEnabledFeatures::SetPrintBrowserEnabled(print_browser_);
  RuntimeEnabledFeatures::SetPriorityHintsEnabled(priority_hints_);
  RuntimeEnabledFeatures::SetPushMessagingEnabled(push_messaging_);
  RuntimeEnabledFeatures::SetPushMessagingSubscriptionChangeEnabled(push_messaging_subscription_change_);
  RuntimeEnabledFeatures::SetQuicTransportEnabled(quic_transport_);
  RuntimeEnabledFeatures::SetRawClipboardEnabled(raw_clipboard_);
  RuntimeEnabledFeatures::SetReducedReferrerGranularityEnabled(reduced_referrer_granularity_);
  RuntimeEnabledFeatures::SetRemotePlaybackEnabled(remote_playback_);
  RuntimeEnabledFeatures::SetRemotePlaybackBackendEnabled(remote_playback_backend_);
  RuntimeEnabledFeatures::SetResizeObserverUpdatesEnabled(resize_observer_updates_);
  RuntimeEnabledFeatures::SetRestrictAppCacheToSecureContextsEnabled(restrict_app_cache_to_secure_contexts_);
  RuntimeEnabledFeatures::SetRestrictAutomaticLazyFrameLoadingToDataSaverEnabled(restrict_automatic_lazy_frame_loading_to_data_saver_);
  RuntimeEnabledFeatures::SetRestrictAutomaticLazyImageLoadingToDataSaverEnabled(restrict_automatic_lazy_image_loading_to_data_saver_);
  RuntimeEnabledFeatures::SetRestrictedWebkitAppearanceEnabled(restricted_webkit_appearance_);
  RuntimeEnabledFeatures::SetRtcAudioJitterBufferMaxPacketsEnabled(rtc_audio_jitter_buffer_max_packets_);
  RuntimeEnabledFeatures::SetRtcAudioJitterBufferRtxHandlingEnabled(rtc_audio_jitter_buffer_rtx_handling_);
  RuntimeEnabledFeatures::SetRTCDtlsTransportEnabled(rtc_dtls_transport_);
  RuntimeEnabledFeatures::SetRTCIceTransportExtensionEnabled(rtc_ice_transport_extension_);
  RuntimeEnabledFeatures::SetRTCQuicTransportEnabled(rtc_quic_transport_);
  RuntimeEnabledFeatures::SetRTCSctpTransportEnabled(rtc_sctp_transport_);
  RuntimeEnabledFeatures::SetRTCStatsRelativePacketArrivalDelayEnabled(rtc_stats_relative_packet_arrival_delay_);
  RuntimeEnabledFeatures::SetRTCSvcScalabilityModeEnabled(rtc_svc_scalability_mode_);
  RuntimeEnabledFeatures::SetRTCUnifiedPlanEnabled(rtc_unified_plan_);
  RuntimeEnabledFeatures::SetRTCUnifiedPlanByDefaultEnabled(rtc_unified_plan_by_default_);
  RuntimeEnabledFeatures::SetSameSiteByDefaultCookiesEnabled(same_site_by_default_cookies_);
  RuntimeEnabledFeatures::SetScreenEnumerationEnabled(screen_enumeration_);
  RuntimeEnabledFeatures::SetScriptedSpeechRecognitionEnabled(scripted_speech_recognition_);
  RuntimeEnabledFeatures::SetScriptedSpeechSynthesisEnabled(scripted_speech_synthesis_);
  RuntimeEnabledFeatures::SetScriptStreamingOnPreloadEnabled(script_streaming_on_preload_);
  RuntimeEnabledFeatures::SetScrollCustomizationEnabled(scroll_customization_);
  RuntimeEnabledFeatures::SetScrollSnapAfterLayoutEnabled(scroll_snap_after_layout_);
  RuntimeEnabledFeatures::SetScrollTimelineEnabled(scroll_timeline_);
  RuntimeEnabledFeatures::SetScrollTopLeftInteropEnabled(scroll_top_left_interop_);
  RuntimeEnabledFeatures::SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(send_beacon_throw_for_blob_with_non_simple_type_);
  RuntimeEnabledFeatures::SetSendMouseEventsDisabledFormControlsEnabled(send_mouse_events_disabled_form_controls_);
  RuntimeEnabledFeatures::SetSensorExtraClassesEnabled(sensor_extra_classes_);
  RuntimeEnabledFeatures::SetSerialEnabled(serial_);
  RuntimeEnabledFeatures::SetServiceWorkerClientLifecycleStateEnabled(service_worker_client_lifecycle_state_);
  RuntimeEnabledFeatures::SetServiceWorkerFetchEventWorkerTimingEnabled(service_worker_fetch_event_worker_timing_);
  RuntimeEnabledFeatures::SetSetRootScrollerEnabled(set_root_scroller_);
  RuntimeEnabledFeatures::SetShadowDOMV0Enabled(shadow_dom_v0_);
  RuntimeEnabledFeatures::SetShadowPiercingDescendantCombinatorEnabled(shadow_piercing_descendant_combinator_);
  RuntimeEnabledFeatures::SetShapeDetectionEnabled(shape_detection_);
  RuntimeEnabledFeatures::SetSharedArrayBufferEnabled(shared_array_buffer_);
  RuntimeEnabledFeatures::SetSharedWorkerEnabled(shared_worker_);
  RuntimeEnabledFeatures::SetSignatureBasedIntegrityEnabled(signature_based_integrity_);
  RuntimeEnabledFeatures::SetSignedExchangePrefetchCacheForNavigationsEnabled(signed_exchange_prefetch_cache_for_navigations_);
  RuntimeEnabledFeatures::SetSignedExchangeSubresourcePrefetchEnabled(signed_exchange_subresource_prefetch_);
  RuntimeEnabledFeatures::SetSkipAdEnabled(skip_ad_);
  RuntimeEnabledFeatures::SetSkipTouchEventFilterEnabled(skip_touch_event_filter_);
  RuntimeEnabledFeatures::SetSmsReceiverEnabled(sms_receiver_);
  RuntimeEnabledFeatures::SetStableBlinkFeaturesEnabled(stable_blink_features_);
  RuntimeEnabledFeatures::SetStackedCSSPropertyAnimationsEnabled(stacked_css_property_animations_);
  RuntimeEnabledFeatures::SetStorageAccessAPIEnabled(storage_access_api_);
  RuntimeEnabledFeatures::SetStorageQuotaDetailsEnabled(storage_quota_details_);
  RuntimeEnabledFeatures::SetStrictMimeTypesForWorkersEnabled(strict_mime_types_for_workers_);
  RuntimeEnabledFeatures::SetSurfaceEmbeddingFeaturesEnabled(surface_embedding_features_);
  RuntimeEnabledFeatures::SetTextFragmentIdentifiersEnabled(text_fragment_identifiers_);
  RuntimeEnabledFeatures::SetTimerThrottlingForBackgroundTabsEnabled(timer_throttling_for_background_tabs_);
  RuntimeEnabledFeatures::SetTimerThrottlingForHiddenFramesEnabled(timer_throttling_for_hidden_frames_);
  RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled(touch_event_feature_detection_);
  RuntimeEnabledFeatures::SetTrackLayoutPassesPerBlockEnabled(track_layout_passes_per_block_);
  RuntimeEnabledFeatures::SetTransferableStreamsEnabled(transferable_streams_);
  RuntimeEnabledFeatures::SetTranslateServiceEnabled(translate_service_);
  RuntimeEnabledFeatures::SetTrustedDOMTypesEnabled(trusted_dom_types_);
  RuntimeEnabledFeatures::SetUnclosedFormControlIsInvalidEnabled(unclosed_form_control_is_invalid_);
  RuntimeEnabledFeatures::SetUnifiedPointerCaptureInBlinkEnabled(unified_pointer_capture_in_blink_);
  RuntimeEnabledFeatures::SetUnifiedTouchAdjustmentEnabled(unified_touch_adjustment_);
  RuntimeEnabledFeatures::SetUnoptimizedImagePoliciesEnabled(unoptimized_image_policies_);
  RuntimeEnabledFeatures::SetUnsizedMediaPolicyEnabled(unsized_media_policy_);
  RuntimeEnabledFeatures::SetUpdateHoverAtBeginFrameEnabled(update_hover_at_begin_frame_);
  RuntimeEnabledFeatures::SetUserActivationAPIEnabled(user_activation_api_);
  RuntimeEnabledFeatures::SetUserActivationPostMessageTransferEnabled(user_activation_post_message_transfer_);
  RuntimeEnabledFeatures::SetUserActivationSameOriginVisibilityEnabled(user_activation_same_origin_visibility_);
  RuntimeEnabledFeatures::SetUserAgentClientHintEnabled(user_agent_client_hint_);
  RuntimeEnabledFeatures::SetUseWindowsSystemColorsEnabled(use_windows_system_colors_);
  RuntimeEnabledFeatures::SetV8IdleTasksEnabled(v8_idle_tasks_);
  RuntimeEnabledFeatures::SetVideoAutoFullscreenEnabled(video_auto_fullscreen_);
  RuntimeEnabledFeatures::SetVideoFullscreenDetectionEnabled(video_fullscreen_detection_);
  RuntimeEnabledFeatures::SetVideoFullscreenOrientationLockEnabled(video_fullscreen_orientation_lock_);
  RuntimeEnabledFeatures::SetVideoPlaybackQualityEnabled(video_playback_quality_);
  RuntimeEnabledFeatures::SetVideoRequestAnimationFrameEnabled(video_request_animation_frame_);
  RuntimeEnabledFeatures::SetVideoRotateToFullscreenEnabled(video_rotate_to_fullscreen_);
  RuntimeEnabledFeatures::SetVisibilityCollapseColumnEnabled(visibility_collapse_column_);
  RuntimeEnabledFeatures::SetWakeLockEnabled(wake_lock_);
  RuntimeEnabledFeatures::SetWasmCodeCacheEnabled(wasm_code_cache_);
  RuntimeEnabledFeatures::SetWebAnimationsAPIEnabled(web_animations_api_);
  RuntimeEnabledFeatures::SetWebAnimationsSVGEnabled(web_animations_svg_);
  RuntimeEnabledFeatures::SetWebAssemblyThreadsEnabled(web_assembly_threads_);
  RuntimeEnabledFeatures::SetWebAuthEnabled(web_auth_);
  RuntimeEnabledFeatures::SetWebAuthenticationFeaturePolicyEnabled(web_authentication_feature_policy_);
  RuntimeEnabledFeatures::SetWebBluetoothEnabled(web_bluetooth_);
  RuntimeEnabledFeatures::SetWebBluetoothScanningEnabled(web_bluetooth_scanning_);
  RuntimeEnabledFeatures::SetWebCodecsEnabled(web_codecs_);
  RuntimeEnabledFeatures::SetWebGL2ComputeContextEnabled(webgl2_compute_context_);
  RuntimeEnabledFeatures::SetWebGLDraftExtensionsEnabled(webgl_draft_extensions_);
  RuntimeEnabledFeatures::SetWebGLImageChromiumEnabled(webgl_image_chromium_);
  RuntimeEnabledFeatures::SetWebGPUEnabled(webgpu_);
  RuntimeEnabledFeatures::SetWebHIDEnabled(web_hid_);
  RuntimeEnabledFeatures::SetWebNFCEnabled(web_nfc_);
  RuntimeEnabledFeatures::SetWebSchedulerEnabled(web_scheduler_);
  RuntimeEnabledFeatures::SetWebShareEnabled(web_share_);
  RuntimeEnabledFeatures::SetWebShareV2Enabled(web_share_v_2_);
  RuntimeEnabledFeatures::SetWebSocketStreamEnabled(websocket_stream_);
  RuntimeEnabledFeatures::SetWebUSBEnabled(web_usb_);
  RuntimeEnabledFeatures::SetWebUSBOnDedicatedWorkersEnabled(web_usb_on_dedicated_workers_);
  RuntimeEnabledFeatures::SetWebVTTRegionsEnabled(web_vtt_regions_);
  RuntimeEnabledFeatures::SetWebXREnabled(web_xr_);
  RuntimeEnabledFeatures::SetWebXRARModuleEnabled(web_xr_ar_module_);
  RuntimeEnabledFeatures::SetWebXRHitTestEnabled(web_xr_hit_test_);
  RuntimeEnabledFeatures::SetWebXRHitTestEntityTypesEnabled(web_xr_hit_test_entity_types_);
  RuntimeEnabledFeatures::SetWebXRIncubationsEnabled(web_xr_incubations_);
  RuntimeEnabledFeatures::SetWindowPlacementEnabled(window_placement_);
  RuntimeEnabledFeatures::SetWritableFileStreamEnabled(writable_file_stream_);
  RuntimeEnabledFeatures::SetXSLTEnabled(xslt_);
}

void RuntimeEnabledFeatures::SetStableFeaturesEnabled(bool enable) {
  SetAccelerated2dCanvasEnabled(enable);
  SetAcceleratedSmallCanvasesEnabled(enable);
  SetAllowContentInitiatedDataUrlNavigationsEnabled(enable);
  SetAOMAriaPropertiesEnabled(enable);
  SetAspectRatioFromWidthAndHeightEnabled(enable);
  SetAsyncClipboardEnabled(enable);
  SetAutomaticLazyFrameLoadingEnabled(enable);
  SetAutomaticLazyImageLoadingEnabled(enable);
  SetBackgroundFetchEnabled(enable);
  SetBackgroundVideoTrackOptimizationEnabled(enable);
  SetBadgingEnabled(enable);
  SetBlobReadMethodsEnabled(enable);
  SetBlockCredentialedSubresourcesEnabled(enable);
  SetCSS3TextBreakAnywhereEnabled(enable);
  SetCSSColorSchemeEnabled(enable);
  SetCSSHexAlphaColorEnabled(enable);
  SetCSSVariables2Enabled(enable);
  SetDatabaseEnabled(enable);
  SetDiscardInputToMovingIframesEnabled(enable);
  SetEncryptedMediaEncryptionSchemeQueryEnabled(enable);
  SetEncryptedMediaHdcpPolicyCheckEnabled(enable);
  SetEnterKeyHintAttributeEnabled(enable);
  SetExpensiveBackgroundTimerThrottlingEnabled(enable);
  SetFeaturePolicyJavaScriptInterfaceEnabled(enable);
  SetFetchMetadataEnabled(enable);
  SetFileSystemEnabled(enable);
  SetFlatTreeStyleRecalcEnabled(enable);
  SetHrefTranslateEnabled(enable);
  SetImageOrientationEnabled(enable);
  SetInstalledAppEnabled(enable);
  SetIntersectionObserverDocumentScrollingElementRootEnabled(enable);
  SetIntersectionObserverV2Enabled(enable);
  SetIsolatedCodeCacheEnabled(enable);
  SetLayoutNGEnabled(enable);
  SetLazyFrameLoadingEnabled(enable);
  SetLazyImageLoadingEnabled(enable);
  SetLinkSystemColorsEnabled(enable);
  SetMediaCapabilitiesEncryptedMediaEnabled(enable);
  SetMediaSessionEnabled(enable);
  SetMediaSessionPositionEnabled(enable);
  SetMediaSessionSeekingEnabled(enable);
  SetMediaSourceStableEnabled(enable);
  SetMetaColorSchemeEnabled(enable);
  SetModuleDedicatedWorkerEnabled(enable);
  SetNavigatorLanguageInInsecureContextEnabled(enable);
  SetNewSystemColorsEnabled(enable);
  SetNotificationsEnabled(enable);
  SetOffMainThreadCSSPaintEnabled(enable);
  SetPassiveDocumentEventListenersEnabled(enable);
  SetPassiveDocumentWheelEventListenersEnabled(enable);
  SetPaymentHandlerChangePaymentMethodEnabled(enable);
  SetPaymentHandlerHandlesShippingAndContactEnabled(enable);
  SetPaymentMethodChangeEventEnabled(enable);
  SetPaymentRetryEnabled(enable);
  SetPeriodicBackgroundSyncEnabled(enable);
  SetPermissionsEnabled(enable);
  SetPointerRawUpdateEnabled(enable);
  SetPredictedEventsEnabled(enable);
  SetPrefixedVideoFullscreenEnabled(enable);
  SetPresentationEnabled(enable);
  SetPushMessagingEnabled(enable);
  SetRemotePlaybackEnabled(enable);
  SetRestrictAppCacheToSecureContextsEnabled(enable);
  SetRestrictAutomaticLazyFrameLoadingToDataSaverEnabled(enable);
  SetRestrictAutomaticLazyImageLoadingToDataSaverEnabled(enable);
  SetRestrictedWebkitAppearanceEnabled(enable);
  SetRTCDtlsTransportEnabled(enable);
  SetRTCSctpTransportEnabled(enable);
  SetRTCUnifiedPlanEnabled(enable);
  SetScriptedSpeechRecognitionEnabled(enable);
  SetScriptedSpeechSynthesisEnabled(enable);
  SetScrollSnapAfterLayoutEnabled(enable);
  SetScrollTopLeftInteropEnabled(enable);
  SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(enable);
  SetSharedArrayBufferEnabled(enable);
  SetStableBlinkFeaturesEnabled(enable);
  SetStorageQuotaDetailsEnabled(enable);
  SetSurfaceEmbeddingFeaturesEnabled(enable);
  SetTextFragmentIdentifiersEnabled(enable);
  SetTimerThrottlingForBackgroundTabsEnabled(enable);
  SetTimerThrottlingForHiddenFramesEnabled(enable);
  SetTouchEventFeatureDetectionEnabled(enable);
  SetUnifiedPointerCaptureInBlinkEnabled(enable);
  SetUnifiedTouchAdjustmentEnabled(enable);
  SetUserActivationAPIEnabled(enable);
  SetUseWindowsSystemColorsEnabled(enable);
  SetVideoPlaybackQualityEnabled(enable);
  SetWebAuthEnabled(enable);
  SetWebUSBEnabled(enable);
  SetWebUSBOnDedicatedWorkersEnabled(enable);
  SetWebXREnabled(enable);
  SetWebXRARModuleEnabled(enable);
  SetWebXRHitTestEnabled(enable);
  SetXSLTEnabled(enable);

  // Platform-dependent features
#if defined(OS_ANDROID)
  SetCompositedSelectionUpdateEnabled(enable);
  SetContactsManagerEnabled(enable);
  SetMediaCaptureEnabled(enable);
  SetMediaControlsOverlayPlayButtonEnabled(enable);
  SetNetInfoDownlinkMaxEnabled(enable);
  SetNotificationContentImageEnabled(enable);
  SetOrientationEventEnabled(enable);
  SetRemotePlaybackBackendEnabled(enable);
  SetWebBluetoothEnabled(enable);
#endif

#if defined(OS_WIN)
  SetAudioOutputDevicesEnabled(enable);
  SetGetDisplayMediaEnabled(enable);
  SetInputMultipleFieldsUIEnabled(enable);
  SetNavigatorContentUtilsEnabled(enable);
  SetNotificationConstructorEnabled(enable);
  SetNotificationContentImageEnabled(enable);
  SetOnDeviceChangeEnabled(enable);
  SetPagePopupEnabled(enable);
  SetPictureInPictureAPIEnabled(enable);
  SetSharedWorkerEnabled(enable);
#endif

#if defined(OS_CHROMEOS)
  SetAudioOutputDevicesEnabled(enable);
  SetForceTallerSelectPopupEnabled(enable);
  SetGetDisplayMediaEnabled(enable);
  SetInputMultipleFieldsUIEnabled(enable);
  SetNavigatorContentUtilsEnabled(enable);
  SetNetInfoDownlinkMaxEnabled(enable);
  SetNotificationConstructorEnabled(enable);
  SetNotificationContentImageEnabled(enable);
  SetOnDeviceChangeEnabled(enable);
  SetPagePopupEnabled(enable);
  SetPictureInPictureAPIEnabled(enable);
  SetSharedWorkerEnabled(enable);
  SetWebBluetoothEnabled(enable);
#endif

#if defined(OS_MACOSX)
  SetAudioOutputDevicesEnabled(enable);
  SetGetDisplayMediaEnabled(enable);
  SetInputMultipleFieldsUIEnabled(enable);
  SetNavigatorContentUtilsEnabled(enable);
  SetNotificationConstructorEnabled(enable);
  SetOnDeviceChangeEnabled(enable);
  SetPagePopupEnabled(enable);
  SetPictureInPictureAPIEnabled(enable);
  SetSharedWorkerEnabled(enable);
  SetWebBluetoothEnabled(enable);
#endif

  // Default values for platforms not specifically handled above
#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
  SetAudioOutputDevicesEnabled(enable);
  SetGetDisplayMediaEnabled(enable);
  SetInputMultipleFieldsUIEnabled(enable);
  SetNavigatorContentUtilsEnabled(enable);
  SetNotificationConstructorEnabled(enable);
  SetNotificationContentImageEnabled(enable);
  SetOnDeviceChangeEnabled(enable);
  SetPagePopupEnabled(enable);
  SetPictureInPictureAPIEnabled(enable);
  SetSharedWorkerEnabled(enable);
#endif
}

void RuntimeEnabledFeatures::SetExperimentalFeaturesEnabled(bool enable) {
  SetAccessibilityExposeARIAAnnotationsEnabled(enable);
  SetAccessibilityObjectModelEnabled(enable);
  SetAddressSpaceEnabled(enable);
  SetAllowSyncXHRInPageDismissalEnabled(enable);
  SetAnimationWorkletEnabled(enable);
  SetAOMAriaRelationshipPropertiesEnabled(enable);
  SetAudioVideoTracksEnabled(enable);
  SetAudioWorkletRealtimeThreadEnabled(enable);
  SetAutoPictureInPictureEnabled(enable);
  SetBlockingFocusWithoutUserActivationEnabled(enable);
  SetCacheStorageCodeCacheHintEnabled(enable);
  SetCanvas2dContextLostRestoredEnabled(enable);
  SetCanvas2dScrollPathIntoViewEnabled(enable);
  SetCanvasColorManagementEnabled(enable);
  SetCanvasHitRegionEnabled(enable);
  SetCanvasImageSmoothingEnabled(enable);
  SetClickPointerEventEnabled(enable);
  SetClickRetargettingEnabled(enable);
  SetComputedAccessibilityInfoEnabled(enable);
  SetContentIndexEnabled(enable);
  SetContextMenuEnabled(enable);
  SetCookieDeprecationMessagesEnabled(enable);
  SetCookieStoreDocumentEnabled(enable);
  SetCookieStoreWorkerEnabled(enable);
  SetCSS3TextEnabled(enable);
  SetCSSAdditiveAnimationsEnabled(enable);
  SetCSSFocusVisibleEnabled(enable);
  SetCSSFontSizeAdjustEnabled(enable);
  SetCSSIndependentTransformPropertiesEnabled(enable);
  SetCSSIntrinsicSizeEnabled(enable);
  SetCSSLayoutAPIEnabled(enable);
  SetCSSLogicalEnabled(enable);
  SetCSSMarkerPseudoElementEnabled(enable);
  SetCSSMaskSourceTypeEnabled(enable);
  SetCSSModulesEnabled(enable);
  SetCSSOffsetPathRayEnabled(enable);
  SetCSSOffsetPathRayContainEnabled(enable);
  SetCSSOffsetPositionAnchorEnabled(enable);
  SetCSSOMViewScrollCoordinatesEnabled(enable);
  SetCSSPaintAPIArgumentsEnabled(enable);
  SetCSSPictureInPictureEnabled(enable);
  SetCSSPseudoIsEnabled(enable);
  SetCSSPseudoWhereEnabled(enable);
  SetCSSRenderSubtreeEnabled(enable);
  SetCSSSnapSizeEnabled(enable);
  SetCSSViewportEnabled(enable);
  SetCustomElementDefaultStyleEnabled(enable);
  SetCustomStatePseudoClassEnabled(enable);
  SetDesktopCaptureDisableLocalEchoControlEnabled(enable);
  SetDisableHardwareNoiseSuppressionEnabled(enable);
  SetDisallowDocumentAccessEnabled(enable);
  SetDisplayLockingEnabled(enable);
  SetDocumentPolicyEnabled(enable);
  SetEmbeddedVTTStylesheetsEnabled(enable);
  SetEventTimingEnabled(enable);
  SetExperimentalContentSecurityPolicyFeaturesEnabled(enable);
  SetExperimentalIsInputPendingEnabled(enable);
  SetExperimentalJSProfilerEnabled(enable);
  SetExperimentalProductivityFeaturesEnabled(enable);
  SetExtendedTextMetricsEnabled(enable);
  SetFeaturePolicyForClientHintsEnabled(enable);
  SetFeaturePolicyForSandboxEnabled(enable);
  SetFeaturePolicyReportingEnabled(enable);
  SetFetchMetadataDestinationEnabled(enable);
  SetForcedColorsEnabled(enable);
  SetFractionalScrollOffsetsEnabled(enable);
  SetFreezeFramesOnVisibilityEnabled(enable);
  SetGamepadButtonAxisEventsEnabled(enable);
  SetIDBObserverEnabled(enable);
  SetIDBRelaxedDurabilityEnabled(enable);
  SetIdleDetectionEnabled(enable);
  SetIgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabled(enable);
  SetImplicitRootScrollerEnabled(enable);
  SetInertAttributeEnabled(enable);
  SetInvisibleDOMEnabled(enable);
  SetKeyboardFocusableScrollersEnabled(enable);
  SetLangClientHintHeaderEnabled(enable);
  SetManualSlottingEnabled(enable);
  SetMathMLCoreEnabled(enable);
  SetMeasureMemoryEnabled(enable);
  SetMediaCapabilitiesEncodingInfoEnabled(enable);
  SetMediaCaptureDepthVideoKindEnabled(enable);
  SetMediaCapturePanTiltEnabled(enable);
  SetMediaQueryShapeEnabled(enable);
  SetMediaSourceExperimentalEnabled(enable);
  SetMediaSourceInWorkersEnabled(enable);
  SetMediaSourceNewAbortAndDurationEnabled(enable);
  SetNotificationTriggersEnabled(enable);
  SetOffscreenCanvasCommitEnabled(enable);
  SetOverscrollCustomizationEnabled(enable);
  SetPaymentAppEnabled(enable);
  SetPaymentRequestEnabled(enable);
  SetPaymentRequestMerchantValidationEventEnabled(enable);
  SetPerMethodCanMakePaymentQuotaEnabled(enable);
  SetPermissionsRequestRevokeEnabled(enable);
  SetPostAnimationFrameEnabled(enable);
  SetPriorityHintsEnabled(enable);
  SetPushMessagingSubscriptionChangeEnabled(enable);
  SetQuicTransportEnabled(enable);
  SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
  SetRtcAudioJitterBufferRtxHandlingEnabled(enable);
  SetRTCIceTransportExtensionEnabled(enable);
  SetRTCQuicTransportEnabled(enable);
  SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
  SetRTCSvcScalabilityModeEnabled(enable);
  SetScreenEnumerationEnabled(enable);
  SetScrollTimelineEnabled(enable);
  SetSendMouseEventsDisabledFormControlsEnabled(enable);
  SetSensorExtraClassesEnabled(enable);
  SetServiceWorkerClientLifecycleStateEnabled(enable);
  SetServiceWorkerFetchEventWorkerTimingEnabled(enable);
  SetSetRootScrollerEnabled(enable);
  SetShadowPiercingDescendantCombinatorEnabled(enable);
  SetShapeDetectionEnabled(enable);
  SetSignatureBasedIntegrityEnabled(enable);
  SetSignedExchangePrefetchCacheForNavigationsEnabled(enable);
  SetSignedExchangeSubresourcePrefetchEnabled(enable);
  SetSkipAdEnabled(enable);
  SetStackedCSSPropertyAnimationsEnabled(enable);
  SetStrictMimeTypesForWorkersEnabled(enable);
  SetTransferableStreamsEnabled(enable);
  SetTrustedDOMTypesEnabled(enable);
  SetUnclosedFormControlIsInvalidEnabled(enable);
  SetUnoptimizedImagePoliciesEnabled(enable);
  SetUnsizedMediaPolicyEnabled(enable);
  SetUserAgentClientHintEnabled(enable);
  SetVideoRequestAnimationFrameEnabled(enable);
  SetWakeLockEnabled(enable);
  SetWasmCodeCacheEnabled(enable);
  SetWebAnimationsAPIEnabled(enable);
  SetWebAnimationsSVGEnabled(enable);
  SetWebAssemblyThreadsEnabled(enable);
  SetWebAuthenticationFeaturePolicyEnabled(enable);
  SetWebBluetoothScanningEnabled(enable);
  SetWebGL2ComputeContextEnabled(enable);
  SetWebGLDraftExtensionsEnabled(enable);
  SetWebHIDEnabled(enable);
  SetWebNFCEnabled(enable);
  SetWebSchedulerEnabled(enable);
  SetWebShareEnabled(enable);
  SetWebShareV2Enabled(enable);
  SetWebSocketStreamEnabled(enable);
  SetWebVTTRegionsEnabled(enable);
  SetWebXRHitTestEntityTypesEnabled(enable);
  SetWebXRIncubationsEnabled(enable);
  SetWindowPlacementEnabled(enable);
  SetWritableFileStreamEnabled(enable);

  // Platform-dependent features
#if defined(OS_ANDROID)
  SetContactsManagerExtraPropertiesEnabled(enable);
  SetSmsReceiverEnabled(enable);
#endif

#if defined(OS_WIN)
  SetCloneableNativeFileSystemHandlesEnabled(enable);
  SetNativeFileSystemEnabled(enable);
  SetSerialEnabled(enable);
  SetSmsReceiverEnabled(enable);
  SetWebBluetoothEnabled(enable);
#endif

#if defined(OS_CHROMEOS)
  SetCloneableNativeFileSystemHandlesEnabled(enable);
  SetNativeFileSystemEnabled(enable);
  SetSerialEnabled(enable);
  SetSmsReceiverEnabled(enable);
#endif

#if defined(OS_MACOSX)
  SetCloneableNativeFileSystemHandlesEnabled(enable);
  SetNativeFileSystemEnabled(enable);
  SetSerialEnabled(enable);
  SetSmsReceiverEnabled(enable);
#endif

  // Default values for platforms not specifically handled above
#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
  SetCloneableNativeFileSystemHandlesEnabled(enable);
  SetNativeFileSystemEnabled(enable);
  SetSerialEnabled(enable);
  SetSmsReceiverEnabled(enable);
  SetWebBluetoothEnabled(enable);
#endif
}

void RuntimeEnabledFeatures::SetTestFeaturesEnabled(bool enable) {
  SetAccessibilityExposeDisplayNoneEnabled(enable);
  SetAdTaggingEnabled(enable);
  SetBlockingDownloadsInSandboxEnabled(enable);
  SetCompositorTouchActionEnabled(enable);
  SetCookiesWithoutSameSiteMustBeSecureEnabled(enable);
  SetCSSCalcAsIntEnabled(enable);
  SetCSSLogicalOverflowEnabled(enable);
  SetCSSVariables2ImageValuesEnabled(enable);
  SetCSSVariables2TransformValuesEnabled(enable);
  SetCustomElementsV0Enabled(enable);
  SetDecodeJpeg420ImagesToYUVEnabled(enable);
  SetDecodeLossyWebPImagesToYUVEnabled(enable);
  SetEditContextEnabled(enable);
  SetEncryptedMediaPersistentUsageRecordSessionEnabled(enable);
  SetExecCommandInJavaScriptEnabled(enable);
  SetGroupEffectEnabled(enable);
  SetHTMLImportsEnabled(enable);
  SetMediaCapabilitiesSpatialAudioEnabled(enable);
  SetMediaLatencyHintEnabled(enable);
  SetMiddleClickAutoscrollEnabled(enable);
  SetModuleServiceWorkerEnabled(enable);
  SetModuleSharedWorkerEnabled(enable);
  SetMojoJSEnabled(enable);
  SetMojoJSTestEnabled(enable);
  SetNoIdleEncodingForWebTestsEnabled(enable);
  SetPermissionDelegationEnabled(enable);
  SetPortalsEnabled(enable);
  SetResizeObserverUpdatesEnabled(enable);
  SetSameSiteByDefaultCookiesEnabled(enable);
  SetShadowDOMV0Enabled(enable);
  SetStorageAccessAPIEnabled(enable);
  SetWebCodecsEnabled(enable);

  // Platform-dependent features
#if defined(OS_ANDROID)
  SetCloneableNativeFileSystemHandlesEnabled(enable);
  SetInputMultipleFieldsUIEnabled(enable);
  SetNativeFileSystemEnabled(enable);
#endif

#if defined(OS_WIN)
  SetContactsManagerEnabled(enable);
  SetContactsManagerExtraPropertiesEnabled(enable);
#endif

#if defined(OS_CHROMEOS)
  SetContactsManagerEnabled(enable);
  SetContactsManagerExtraPropertiesEnabled(enable);
#endif

#if defined(OS_MACOSX)
  SetContactsManagerEnabled(enable);
  SetContactsManagerExtraPropertiesEnabled(enable);
  SetNotificationContentImageEnabled(enable);
#endif

  // Default values for platforms not specifically handled above
#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
  SetContactsManagerEnabled(enable);
  SetContactsManagerExtraPropertiesEnabled(enable);
#endif
}


void RuntimeEnabledFeatures::SetOriginTrialControlledFeaturesEnabled(bool enable) {
  SetAccessibilityExposeARIAAnnotationsEnabled(enable);
  SetAllowSyncXHRInPageDismissalEnabled(enable);
  SetAnimationWorkletEnabled(enable);
  SetAutoPictureInPictureEnabled(enable);
  SetBuiltInModuleInfraEnabled(enable);
  SetBuiltInModuleKvStorageEnabled(enable);
  SetCacheStorageCodeCacheHintEnabled(enable);
  SetContactsManagerExtraPropertiesEnabled(enable);
  SetContentIndexEnabled(enable);
  SetCustomElementsV0Enabled(enable);
  SetDisableHardwareNoiseSuppressionEnabled(enable);
  SetDisplayLockingEnabled(enable);
  SetEventTimingEnabled(enable);
  SetExperimentalAutoplayDynamicDelegationEnabled(enable);
  SetExperimentalIsInputPendingEnabled(enable);
  SetExperimentalJSProfilerEnabled(enable);
  SetFeaturePolicyReportingEnabled(enable);
  SetHrefTranslateEnabled(enable);
  SetHTMLImportsEnabled(enable);
  SetNativeFileSystemEnabled(enable);
  SetNotificationTriggersEnabled(enable);
  SetOriginTrialsSampleAPIEnabled(enable);
  SetOriginTrialsSampleAPIDependentEnabled(enable);
  SetOriginTrialsSampleAPIDeprecationEnabled(enable);
  SetOriginTrialsSampleAPIImpliedEnabled(enable);
  SetOriginTrialsSampleAPIInvalidOSEnabled(enable);
  SetOriginTrialsSampleAPINavigationEnabled(enable);
  SetPageFreezeOptInEnabled(enable);
  SetPageFreezeOptOutEnabled(enable);
  SetPerMethodCanMakePaymentQuotaEnabled(enable);
  SetPNaClEnabled(enable);
  SetPointerLockOptionsEnabled(enable);
  SetPriorityHintsEnabled(enable);
  SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
  SetRtcAudioJitterBufferRtxHandlingEnabled(enable);
  SetRTCIceTransportExtensionEnabled(enable);
  SetRTCQuicTransportEnabled(enable);
  SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
  SetScrollTimelineEnabled(enable);
  SetSerialEnabled(enable);
  SetShadowDOMV0Enabled(enable);
  SetSignatureBasedIntegrityEnabled(enable);
  SetSignedExchangeSubresourcePrefetchEnabled(enable);
  SetSkipAdEnabled(enable);
  SetSmsReceiverEnabled(enable);
  SetTextFragmentIdentifiersEnabled(enable);
  SetTouchEventFeatureDetectionEnabled(enable);
  SetUnoptimizedImagePoliciesEnabled(enable);
  SetUnsizedMediaPolicyEnabled(enable);
  SetWakeLockEnabled(enable);
  SetWebAssemblyThreadsEnabled(enable);
  SetWebNFCEnabled(enable);
  SetWebSchedulerEnabled(enable);
  SetWebSocketStreamEnabled(enable);
}

void RuntimeEnabledFeatures::SetFeatureEnabledFromString(
    const std::string& name, bool enable) {
  static const struct {
    const char* name;
    bool* setting;
  } kFeatures[] = {
    {"Accelerated2dCanvas", &is_accelerated_2d_canvas_enabled_},
    {"AcceleratedSmallCanvases", &is_accelerated_small_canvases_enabled_},
    {"AccessibilityExposeARIAAnnotations", &is_accessibility_expose_aria_annotations_enabled_},
    {"AccessibilityExposeDisplayNone", &is_accessibility_expose_display_none_enabled_},
    {"AccessibilityObjectModel", &is_accessibility_object_model_enabled_},
    {"AddressSpace", &is_address_space_enabled_},
    {"AdTagging", &is_ad_tagging_enabled_},
    {"AllowActivationDelegationAttr", &is_allow_activation_delegation_attr_enabled_},
    {"AllowContentInitiatedDataUrlNavigations", &is_allow_content_initiated_data_url_navigations_enabled_},
    {"AllowSyncXHRInPageDismissal", &is_allow_sync_xhr_in_page_dismissal_enabled_},
    {"AnimationWorklet", &is_animation_worklet_enabled_},
    {"AOMAriaProperties", &is_aom_aria_properties_enabled_},
    {"AOMAriaRelationshipProperties", &is_aom_aria_relationship_properties_enabled_},
    {"AspectRatioFromWidthAndHeight", &is_aspect_ratio_from_width_and_height_enabled_},
    {"AsyncClipboard", &is_async_clipboard_enabled_},
    {"AudioOutputDevices", &is_audio_output_devices_enabled_},
    {"AudioVideoTracks", &is_audio_video_tracks_enabled_},
    {"AudioWorkletRealtimeThread", &is_audio_worklet_realtime_thread_enabled_},
    {"AutoLazyLoadOnReloads", &is_auto_lazy_load_on_reloads_enabled_},
    {"AutomaticLazyFrameLoading", &is_automatic_lazy_frame_loading_enabled_},
    {"AutomaticLazyImageLoading", &is_automatic_lazy_image_loading_enabled_},
    {"AutomationControlled", &is_automation_controlled_enabled_},
    {"AutoPictureInPicture", &is_auto_picture_in_picture_enabled_},
    {"AutoplayIgnoresWebAudio", &is_autoplay_ignores_web_audio_enabled_},
    {"BackForwardCache", &is_back_forward_cache_enabled_},
    {"BackgroundFetch", &is_background_fetch_enabled_},
    {"BackgroundVideoTrackOptimization", &is_background_video_track_optimization_enabled_},
    {"Badging", &is_badging_enabled_},
    {"BidiCaretAffinity", &is_bidi_caret_affinity_enabled_},
    {"BlinkRuntimeCallStats", &is_blink_runtime_call_stats_enabled_},
    {"BlobReadMethods", &is_blob_read_methods_enabled_},
    {"BlockCredentialedSubresources", &is_block_credentialed_subresources_enabled_},
    {"BlockHTMLParserOnStyleSheets", &is_block_html_parser_on_style_sheets_enabled_},
    {"BlockingDownloadsInSandbox", &is_blocking_downloads_in_sandbox_enabled_},
    {"BlockingFocusWithoutUserActivation", &is_blocking_focus_without_user_activation_enabled_},
    {"BrowserVerifiedUserActivationKeyboard", &is_browser_verified_user_activation_keyboard_enabled_},
    {"BrowserVerifiedUserActivationMouse", &is_browser_verified_user_activation_mouse_enabled_},
    {"BuiltInModuleAll", &is_built_in_module_all_enabled_},
    {"BuiltInModuleInfra", &is_built_in_module_infra_enabled_},
    {"BuiltInModuleKvStorage", &is_built_in_module_kv_storage_enabled_},
    {"BuiltInModuleSwitchElement", &is_built_in_module_switch_element_enabled_},
    {"CacheInlineScriptCode", &is_cache_inline_script_code_enabled_},
    {"CacheStorageCodeCacheHint", &is_cache_storage_code_cache_hint_enabled_},
    {"Canvas2dContextLostRestored", &is_canvas_2d_context_lost_restored_enabled_},
    {"Canvas2dImageChromium", &is_canvas_2d_image_chromium_enabled_},
    {"Canvas2dScrollPathIntoView", &is_canvas_2d_scroll_path_into_view_enabled_},
    {"CanvasColorManagement", &is_canvas_color_management_enabled_},
    {"CanvasHitRegion", &is_canvas_hit_region_enabled_},
    {"CanvasImageSmoothing", &is_canvas_image_smoothing_enabled_},
    {"ClickPointerEvent", &is_click_pointer_event_enabled_},
    {"ClickRetargetting", &is_click_retargetting_enabled_},
    {"CloneableNativeFileSystemHandles", &is_cloneable_native_file_system_handles_enabled_},
    {"CompositeAfterPaint", &is_composite_after_paint_enabled_},
    {"CompositedSelectionUpdate", &is_composited_selection_update_enabled_},
    {"CompositorTouchAction", &is_compositor_touch_action_enabled_},
    {"ComputedAccessibilityInfo", &is_computed_accessibility_info_enabled_},
    {"ConsolidatedMovementXY", &is_consolidated_movement_xy_enabled_},
    {"ContactsManager", &is_contacts_manager_enabled_},
    {"ContactsManagerExtraProperties", &is_contacts_manager_extra_properties_enabled_},
    {"ContentIndex", &is_content_index_enabled_},
    {"ContextMenu", &is_context_menu_enabled_},
    {"CookieDeprecationMessages", &is_cookie_deprecation_messages_enabled_},
    {"CookieStoreDocument", &is_cookie_store_document_enabled_},
    {"CookieStoreWorker", &is_cookie_store_worker_enabled_},
    {"CookiesWithoutSameSiteMustBeSecure", &is_cookies_without_same_site_must_be_secure_enabled_},
    {"CooperativeScheduling", &is_cooperative_scheduling_enabled_},
    {"CorsRFC1918", &is_cors_rfc_1918_enabled_},
    {"CSS3Text", &is_css_3_text_enabled_},
    {"CSS3TextBreakAnywhere", &is_css_3_text_break_anywhere_enabled_},
    {"CSSAdditiveAnimations", &is_css_additive_animations_enabled_},
    {"CSSCalcAsInt", &is_css_calc_as_int_enabled_},
    {"CSSCascade", &is_css_cascade_enabled_},
    {"CSSColorScheme", &is_css_color_scheme_enabled_},
    {"CSSColorSchemeUARendering", &is_css_color_scheme_ua_rendering_enabled_},
    {"CSSFocusVisible", &is_css_focus_visible_enabled_},
    {"CSSFontSizeAdjust", &is_css_font_size_adjust_enabled_},
    {"CSSHexAlphaColor", &is_css_hex_alpha_color_enabled_},
    {"CSSIndependentTransformProperties", &is_css_independent_transform_properties_enabled_},
    {"CSSIntrinsicSize", &is_css_intrinsic_size_enabled_},
    {"CSSLayoutAPI", &is_css_layout_api_enabled_},
    {"CSSLogical", &is_css_logical_enabled_},
    {"CSSLogicalOverflow", &is_css_logical_overflow_enabled_},
    {"CSSMarkerPseudoElement", &is_css_marker_pseudo_element_enabled_},
    {"CSSMaskSourceType", &is_css_mask_source_type_enabled_},
    {"CSSModules", &is_css_modules_enabled_},
    {"CSSOffsetPathRay", &is_css_offset_path_ray_enabled_},
    {"CSSOffsetPathRayContain", &is_css_offset_path_ray_contain_enabled_},
    {"CSSOffsetPositionAnchor", &is_css_offset_position_anchor_enabled_},
    {"CSSOMViewScrollCoordinates", &is_cssom_view_scroll_coordinates_enabled_},
    {"CSSPaintAPIArguments", &is_css_paint_api_arguments_enabled_},
    {"CSSPictureInPicture", &is_css_picture_in_picture_enabled_},
    {"CSSPseudoIs", &is_css_pseudo_is_enabled_},
    {"CSSPseudoWhere", &is_css_pseudo_where_enabled_},
    {"CSSRenderSubtree", &is_css_render_subtree_enabled_},
    {"CSSSnapSize", &is_css_snap_size_enabled_},
    {"CSSVariables2", &is_css_variables_2_enabled_},
    {"CSSVariables2AtProperty", &is_css_variables_2_at_property_enabled_},
    {"CSSVariables2ImageValues", &is_css_variables_2_image_values_enabled_},
    {"CSSVariables2TransformValues", &is_css_variables_2_transform_values_enabled_},
    {"CSSViewport", &is_css_viewport_enabled_},
    {"CustomElementDefaultStyle", &is_custom_element_default_style_enabled_},
    {"CustomElementsV0", &is_custom_elements_v0_enabled_},
    {"CustomStatePseudoClass", &is_custom_state_pseudo_class_enabled_},
    {"Database", &is_database_enabled_},
    {"DecodeJpeg420ImagesToYUV", &is_decode_jpeg_420_images_to_yuv_enabled_},
    {"DecodeLossyWebPImagesToYUV", &is_decode_lossy_web_p_images_to_yuv_enabled_},
    {"DesktopCaptureDisableLocalEchoControl", &is_desktop_capture_disable_local_echo_control_enabled_},
    {"DisableHardwareNoiseSuppression", &is_disable_hardware_noise_suppression_enabled_},
    {"DisallowDocumentAccess", &is_disallow_document_access_enabled_},
    {"DiscardInputToMovingIframes", &is_discard_input_to_moving_iframes_enabled_},
    {"DisplayCutoutAPI", &is_display_cutout_api_enabled_},
    {"DisplayLocking", &is_display_locking_enabled_},
    {"DocumentCookie", &is_document_cookie_enabled_},
    {"DocumentDomain", &is_document_domain_enabled_},
    {"DocumentPolicy", &is_document_policy_enabled_},
    {"DocumentWrite", &is_document_write_enabled_},
    {"EditContext", &is_edit_context_enabled_},
    {"EditingNG", &is_editing_ng_enabled_},
    {"EmbeddedVTTStylesheets", &is_embedded_vtt_stylesheets_enabled_},
    {"EncryptedMediaEncryptionSchemeQuery", &is_encrypted_media_encryption_scheme_query_enabled_},
    {"EncryptedMediaHdcpPolicyCheck", &is_encrypted_media_hdcp_policy_check_enabled_},
    {"EncryptedMediaPersistentUsageRecordSession", &is_encrypted_media_persistent_usage_record_session_enabled_},
    {"EnterKeyHintAttribute", &is_enter_key_hint_attribute_enabled_},
    {"EventTiming", &is_event_timing_enabled_},
    {"ExecCommandInJavaScript", &is_exec_command_in_java_script_enabled_},
    {"ExpensiveBackgroundTimerThrottling", &is_expensive_background_timer_throttling_enabled_},
    {"ExperimentalAutoplayDynamicDelegation", &is_experimental_autoplay_dynamic_delegation_enabled_},
    {"ExperimentalContentSecurityPolicyFeatures", &is_experimental_content_security_policy_features_enabled_},
    {"ExperimentalIsInputPending", &is_experimental_is_input_pending_enabled_},
    {"ExperimentalJSProfiler", &is_experimental_js_profiler_enabled_},
    {"ExperimentalProductivityFeatures", &is_experimental_productivity_features_enabled_},
    {"ExtendedTextMetrics", &is_extended_text_metrics_enabled_},
    {"ExtraWebGLVideoTextureMetadata", &is_extra_webgl_video_texture_metadata_enabled_},
    {"FallbackCursorMode", &is_fallback_cursor_mode_enabled_},
    {"FeaturePolicyForClientHints", &is_feature_policy_for_client_hints_enabled_},
    {"FeaturePolicyForSandbox", &is_feature_policy_for_sandbox_enabled_},
    {"FeaturePolicyJavaScriptInterface", &is_feature_policy_java_script_interface_enabled_},
    {"FeaturePolicyReporting", &is_feature_policy_reporting_enabled_},
    {"FeaturePolicyVibrateFeature", &is_feature_policy_vibrate_feature_enabled_},
    {"FetchMetadata", &is_fetch_metadata_enabled_},
    {"FetchMetadataDestination", &is_fetch_metadata_destination_enabled_},
    {"FileHandling", &is_file_handling_enabled_},
    {"FileSystem", &is_file_system_enabled_},
    {"FlatTreeStyleRecalc", &is_flat_tree_style_recalc_enabled_},
    {"FocuslessSpatialNavigation", &is_focusless_spatial_navigation_enabled_},
    {"FontSrcLocalMatching", &is_font_src_local_matching_enabled_},
    {"ForcedColors", &is_forced_colors_enabled_},
    {"ForceDeferScriptIntervention", &is_force_defer_script_intervention_enabled_},
    {"ForceEagerMeasureMemory", &is_force_eager_measure_memory_enabled_},
    {"ForceOverlayFullscreenVideo", &is_force_overlay_fullscreen_video_enabled_},
    {"ForceSynchronousHTMLParsing", &is_force_synchronous_html_parsing_enabled_},
    {"ForceTallerSelectPopup", &is_force_taller_select_popup_enabled_},
    {"FractionalMouseEvent", &is_fractional_mouse_event_enabled_},
    {"FractionalScrollOffsets", &is_fractional_scroll_offsets_enabled_},
    {"FreezeFramesOnVisibility", &is_freeze_frames_on_visibility_enabled_},
    {"GamepadButtonAxisEvents", &is_gamepad_button_axis_events_enabled_},
    {"GetDisplayMedia", &is_get_display_media_enabled_},
    {"GroupEffect", &is_group_effect_enabled_},
    {"HrefTranslate", &is_href_translate_enabled_},
    {"HTMLImports", &is_html_imports_enabled_},
    {"IDBObserver", &is_idb_observer_enabled_},
    {"IDBRelaxedDurability", &is_idb_relaxed_durability_enabled_},
    {"IdleDetection", &is_idle_detection_enabled_},
    {"IgnoreCrossOriginWindowWhenNamedAccessOnWindow", &is_ignore_cross_origin_window_when_named_access_on_window_enabled_},
    {"ImageOrientation", &is_image_orientation_enabled_},
    {"ImplicitRootScroller", &is_implicit_root_scroller_enabled_},
    {"ImportMaps", &is_import_maps_enabled_},
    {"InertAttribute", &is_inert_attribute_enabled_},
    {"InputMultipleFieldsUI", &is_input_multiple_fields_ui_enabled_},
    {"InstalledApp", &is_installed_app_enabled_},
    {"IntersectionObserverDocumentScrollingElementRoot", &is_intersection_observer_document_scrolling_element_root_enabled_},
    {"IntersectionObserverV2", &is_intersection_observer_v_2_enabled_},
    {"InvisibleDOM", &is_invisible_dom_enabled_},
    {"IsolatedCodeCache", &is_isolated_code_cache_enabled_},
    {"IsolatedWorldCSP", &is_isolated_world_csp_enabled_},
    {"KeyboardFocusableScrollers", &is_keyboard_focusable_scrollers_enabled_},
    {"LangAttributeAwareFormControlUI", &is_lang_attribute_aware_form_control_ui_enabled_},
    {"LangClientHintHeader", &is_lang_client_hint_header_enabled_},
    {"LayoutNG", &is_layout_ng_enabled_},
    {"LayoutNGBlockFragmentation", &is_layout_ng_block_fragmentation_enabled_},
    {"LayoutNGFieldset", &is_layout_ng_fieldset_enabled_},
    {"LayoutNGFlexBox", &is_layout_ng_flex_box_enabled_},
    {"LayoutNGFragmentItem", &is_layout_ng_fragment_item_enabled_},
    {"LayoutNGFragmentPaint", &is_layout_ng_fragment_paint_enabled_},
    {"LayoutNGLineCache", &is_layout_ng_line_cache_enabled_},
    {"LayoutNGTable", &is_layout_ng_table_enabled_},
    {"LazyFrameLoading", &is_lazy_frame_loading_enabled_},
    {"LazyFrameVisibleLoadTimeMetrics", &is_lazy_frame_visible_load_time_metrics_enabled_},
    {"LazyImageLoading", &is_lazy_image_loading_enabled_},
    {"LazyImageLoadingMetadataFetch", &is_lazy_image_loading_metadata_fetch_enabled_},
    {"LazyImageVisibleLoadTimeMetrics", &is_lazy_image_visible_load_time_metrics_enabled_},
    {"LazyInitializeMediaControls", &is_lazy_initialize_media_controls_enabled_},
    {"LegacyWindowsDWriteFontFallback", &is_legacy_windows_d_write_font_fallback_enabled_},
    {"LinkSystemColors", &is_link_system_colors_enabled_},
    {"ManualSlotting", &is_manual_slotting_enabled_},
    {"MathMLCore", &is_mathml_core_enabled_},
    {"MeasureMemory", &is_measure_memory_enabled_},
    {"MediaCapabilitiesEncodingInfo", &is_media_capabilities_encoding_info_enabled_},
    {"MediaCapabilitiesEncryptedMedia", &is_media_capabilities_encrypted_media_enabled_},
    {"MediaCapabilitiesSpatialAudio", &is_media_capabilities_spatial_audio_enabled_},
    {"MediaCapture", &is_media_capture_enabled_},
    {"MediaCaptureDepthVideoKind", &is_media_capture_depth_video_kind_enabled_},
    {"MediaCapturePanTilt", &is_media_capture_pan_tilt_enabled_},
    {"MediaCastOverlayButton", &is_media_cast_overlay_button_enabled_},
    {"MediaControlsExpandGesture", &is_media_controls_expand_gesture_enabled_},
    {"MediaControlsOverlayPlayButton", &is_media_controls_overlay_play_button_enabled_},
    {"MediaDocumentDownloadButton", &is_media_document_download_button_enabled_},
    {"MediaElementVolumeGreaterThanOne", &is_media_element_volume_greater_than_one_enabled_},
    {"MediaEngagementBypassAutoplayPolicies", &is_media_engagement_bypass_autoplay_policies_enabled_},
    {"MediaLatencyHint", &is_media_latency_hint_enabled_},
    {"MediaQueryNavigationControls", &is_media_query_navigation_controls_enabled_},
    {"MediaQueryShape", &is_media_query_shape_enabled_},
    {"MediaSession", &is_media_session_enabled_},
    {"MediaSessionPosition", &is_media_session_position_enabled_},
    {"MediaSessionSeeking", &is_media_session_seeking_enabled_},
    {"MediaSourceExperimental", &is_media_source_experimental_enabled_},
    {"MediaSourceInWorkers", &is_media_source_in_workers_enabled_},
    {"MediaSourceNewAbortAndDuration", &is_media_source_new_abort_and_duration_enabled_},
    {"MediaSourceStable", &is_media_source_stable_enabled_},
    {"MetaColorScheme", &is_meta_color_scheme_enabled_},
    {"MiddleClickAutoscroll", &is_middle_click_autoscroll_enabled_},
    {"MobileLayoutTheme", &is_mobile_layout_theme_enabled_},
    {"ModuleDedicatedWorker", &is_module_dedicated_worker_enabled_},
    {"ModuleServiceWorker", &is_module_service_worker_enabled_},
    {"ModuleSharedWorker", &is_module_shared_worker_enabled_},
    {"MojoJS", &is_mojo_js_enabled_},
    {"MojoJSTest", &is_mojo_js_test_enabled_},
    {"MouseSubframeNoImplicitCapture", &is_mouse_subframe_no_implicit_capture_enabled_},
    {"NativeFileSystem", &is_native_file_system_enabled_},
    {"NavigatorContentUtils", &is_navigator_content_utils_enabled_},
    {"NavigatorLanguageInInsecureContext", &is_navigator_language_in_insecure_context_enabled_},
    {"NetInfoDownlinkMax", &is_net_info_downlink_max_enabled_},
    {"NeverSlowMode", &is_never_slow_mode_enabled_},
    {"NewRemotePlaybackPipeline", &is_new_remote_playback_pipeline_enabled_},
    {"NewSystemColors", &is_new_system_colors_enabled_},
    {"NoIdleEncodingForWebTests", &is_no_idle_encoding_for_web_tests_enabled_},
    {"NotificationConstructor", &is_notification_constructor_enabled_},
    {"NotificationContentImage", &is_notification_content_image_enabled_},
    {"Notifications", &is_notifications_enabled_},
    {"NotificationTriggers", &is_notification_triggers_enabled_},
    {"OffMainThreadCSSPaint", &is_off_main_thread_css_paint_enabled_},
    {"OffscreenCanvasCommit", &is_offscreen_canvas_commit_enabled_},
    {"OnDeviceChange", &is_on_device_change_enabled_},
    {"OrientationEvent", &is_orientation_event_enabled_},
    {"OriginTrialsSampleAPI", &is_origin_trials_sample_api_enabled_},
    {"OriginTrialsSampleAPIDependent", &is_origin_trials_sample_api_dependent_enabled_},
    {"OriginTrialsSampleAPIDeprecation", &is_origin_trials_sample_api_deprecation_enabled_},
    {"OriginTrialsSampleAPIImplied", &is_origin_trials_sample_api_implied_enabled_},
    {"OriginTrialsSampleAPIInvalidOS", &is_origin_trials_sample_api_invalid_os_enabled_},
    {"OriginTrialsSampleAPINavigation", &is_origin_trials_sample_api_navigation_enabled_},
    {"OutOfBlinkCors", &is_out_of_blink_cors_enabled_},
    {"OverflowIconsForMediaControls", &is_overflow_icons_for_media_controls_enabled_},
    {"OverscrollCustomization", &is_overscroll_customization_enabled_},
    {"PageFreezeOptIn", &is_page_freeze_opt_in_enabled_},
    {"PageFreezeOptOut", &is_page_freeze_opt_out_enabled_},
    {"PagePopup", &is_page_popup_enabled_},
    {"PaintUnderInvalidationChecking", &is_paint_under_invalidation_checking_enabled_},
    {"PassiveDocumentEventListeners", &is_passive_document_event_listeners_enabled_},
    {"PassiveDocumentWheelEventListeners", &is_passive_document_wheel_event_listeners_enabled_},
    {"PassPaintVisualRectToCompositor", &is_pass_paint_visual_rect_to_compositor_enabled_},
    {"PasswordReveal", &is_password_reveal_enabled_},
    {"PaymentApp", &is_payment_app_enabled_},
    {"PaymentHandlerChangePaymentMethod", &is_payment_handler_change_payment_method_enabled_},
    {"PaymentHandlerHandlesShippingAndContact", &is_payment_handler_handles_shipping_and_contact_enabled_},
    {"PaymentMethodChangeEvent", &is_payment_method_change_event_enabled_},
    {"PaymentRequest", &is_payment_request_enabled_},
    {"PaymentRequestMerchantValidationEvent", &is_payment_request_merchant_validation_event_enabled_},
    {"PaymentRetry", &is_payment_retry_enabled_},
    {"PerformanceManagerInstrumentation", &is_performance_manager_instrumentation_enabled_},
    {"PeriodicBackgroundSync", &is_periodic_background_sync_enabled_},
    {"PerMethodCanMakePaymentQuota", &is_per_method_can_make_payment_quota_enabled_},
    {"PermissionDelegation", &is_permission_delegation_enabled_},
    {"Permissions", &is_permissions_enabled_},
    {"PermissionsRequestRevoke", &is_permissions_request_revoke_enabled_},
    {"PictureInPicture", &is_picture_in_picture_enabled_},
    {"PictureInPictureAPI", &is_picture_in_picture_api_enabled_},
    {"PictureInPictureV2", &is_picture_in_picture_v_2_enabled_},
    {"PNaCl", &is_p_na_cl_enabled_},
    {"PointerLockOptions", &is_pointer_lock_options_enabled_},
    {"PointerRawUpdate", &is_pointer_raw_update_enabled_},
    {"Portals", &is_portals_enabled_},
    {"PostAnimationFrame", &is_post_animation_frame_enabled_},
    {"PreciseMemoryInfo", &is_precise_memory_info_enabled_},
    {"PredictedEvents", &is_predicted_events_enabled_},
    {"PrefixedVideoFullscreen", &is_prefixed_video_fullscreen_enabled_},
    {"Presentation", &is_presentation_enabled_},
    {"PrintBrowser", &is_print_browser_enabled_},
    {"PriorityHints", &is_priority_hints_enabled_},
    {"PushMessaging", &is_push_messaging_enabled_},
    {"PushMessagingSubscriptionChange", &is_push_messaging_subscription_change_enabled_},
    {"QuicTransport", &is_quic_transport_enabled_},
    {"RawClipboard", &is_raw_clipboard_enabled_},
    {"ReducedReferrerGranularity", &is_reduced_referrer_granularity_enabled_},
    {"RemotePlayback", &is_remote_playback_enabled_},
    {"RemotePlaybackBackend", &is_remote_playback_backend_enabled_},
    {"ResizeObserverUpdates", &is_resize_observer_updates_enabled_},
    {"RestrictAppCacheToSecureContexts", &is_restrict_app_cache_to_secure_contexts_enabled_},
    {"RestrictAutomaticLazyFrameLoadingToDataSaver", &is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_},
    {"RestrictAutomaticLazyImageLoadingToDataSaver", &is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_},
    {"RestrictedWebkitAppearance", &is_restricted_webkit_appearance_enabled_},
    {"RtcAudioJitterBufferMaxPackets", &is_rtc_audio_jitter_buffer_max_packets_enabled_},
    {"RtcAudioJitterBufferRtxHandling", &is_rtc_audio_jitter_buffer_rtx_handling_enabled_},
    {"RTCDtlsTransport", &is_rtc_dtls_transport_enabled_},
    {"RTCIceTransportExtension", &is_rtc_ice_transport_extension_enabled_},
    {"RTCQuicTransport", &is_rtc_quic_transport_enabled_},
    {"RTCSctpTransport", &is_rtc_sctp_transport_enabled_},
    {"RTCStatsRelativePacketArrivalDelay", &is_rtc_stats_relative_packet_arrival_delay_enabled_},
    {"RTCSvcScalabilityMode", &is_rtc_svc_scalability_mode_enabled_},
    {"RTCUnifiedPlan", &is_rtc_unified_plan_enabled_},
    {"RTCUnifiedPlanByDefault", &is_rtc_unified_plan_by_default_enabled_},
    {"SameSiteByDefaultCookies", &is_same_site_by_default_cookies_enabled_},
    {"ScreenEnumeration", &is_screen_enumeration_enabled_},
    {"ScriptedSpeechRecognition", &is_scripted_speech_recognition_enabled_},
    {"ScriptedSpeechSynthesis", &is_scripted_speech_synthesis_enabled_},
    {"ScriptStreamingOnPreload", &is_script_streaming_on_preload_enabled_},
    {"ScrollCustomization", &is_scroll_customization_enabled_},
    {"ScrollSnapAfterLayout", &is_scroll_snap_after_layout_enabled_},
    {"ScrollTimeline", &is_scroll_timeline_enabled_},
    {"ScrollTopLeftInterop", &is_scroll_top_left_interop_enabled_},
    {"SendBeaconThrowForBlobWithNonSimpleType", &is_send_beacon_throw_for_blob_with_non_simple_type_enabled_},
    {"SendMouseEventsDisabledFormControls", &is_send_mouse_events_disabled_form_controls_enabled_},
    {"SensorExtraClasses", &is_sensor_extra_classes_enabled_},
    {"Serial", &is_serial_enabled_},
    {"ServiceWorkerClientLifecycleState", &is_service_worker_client_lifecycle_state_enabled_},
    {"ServiceWorkerFetchEventWorkerTiming", &is_service_worker_fetch_event_worker_timing_enabled_},
    {"SetRootScroller", &is_set_root_scroller_enabled_},
    {"ShadowDOMV0", &is_shadow_dom_v0_enabled_},
    {"ShadowPiercingDescendantCombinator", &is_shadow_piercing_descendant_combinator_enabled_},
    {"ShapeDetection", &is_shape_detection_enabled_},
    {"SharedArrayBuffer", &is_shared_array_buffer_enabled_},
    {"SharedWorker", &is_shared_worker_enabled_},
    {"SignatureBasedIntegrity", &is_signature_based_integrity_enabled_},
    {"SignedExchangePrefetchCacheForNavigations", &is_signed_exchange_prefetch_cache_for_navigations_enabled_},
    {"SignedExchangeSubresourcePrefetch", &is_signed_exchange_subresource_prefetch_enabled_},
    {"SkipAd", &is_skip_ad_enabled_},
    {"SkipTouchEventFilter", &is_skip_touch_event_filter_enabled_},
    {"SmsReceiver", &is_sms_receiver_enabled_},
    {"StableBlinkFeatures", &is_stable_blink_features_enabled_},
    {"StackedCSSPropertyAnimations", &is_stacked_css_property_animations_enabled_},
    {"StorageAccessAPI", &is_storage_access_api_enabled_},
    {"StorageQuotaDetails", &is_storage_quota_details_enabled_},
    {"StrictMimeTypesForWorkers", &is_strict_mime_types_for_workers_enabled_},
    {"SurfaceEmbeddingFeatures", &is_surface_embedding_features_enabled_},
    {"TextFragmentIdentifiers", &is_text_fragment_identifiers_enabled_},
    {"TimerThrottlingForBackgroundTabs", &is_timer_throttling_for_background_tabs_enabled_},
    {"TimerThrottlingForHiddenFrames", &is_timer_throttling_for_hidden_frames_enabled_},
    {"TouchEventFeatureDetection", &is_touch_event_feature_detection_enabled_},
    {"TrackLayoutPassesPerBlock", &is_track_layout_passes_per_block_enabled_},
    {"TransferableStreams", &is_transferable_streams_enabled_},
    {"TranslateService", &is_translate_service_enabled_},
    {"TrustedDOMTypes", &is_trusted_dom_types_enabled_},
    {"UnclosedFormControlIsInvalid", &is_unclosed_form_control_is_invalid_enabled_},
    {"UnifiedPointerCaptureInBlink", &is_unified_pointer_capture_in_blink_enabled_},
    {"UnifiedTouchAdjustment", &is_unified_touch_adjustment_enabled_},
    {"UnoptimizedImagePolicies", &is_unoptimized_image_policies_enabled_},
    {"UnsizedMediaPolicy", &is_unsized_media_policy_enabled_},
    {"UpdateHoverAtBeginFrame", &is_update_hover_at_begin_frame_enabled_},
    {"UserActivationAPI", &is_user_activation_api_enabled_},
    {"UserActivationPostMessageTransfer", &is_user_activation_post_message_transfer_enabled_},
    {"UserActivationSameOriginVisibility", &is_user_activation_same_origin_visibility_enabled_},
    {"UserAgentClientHint", &is_user_agent_client_hint_enabled_},
    {"UseWindowsSystemColors", &is_use_windows_system_colors_enabled_},
    {"V8IdleTasks", &is_v8_idle_tasks_enabled_},
    {"VideoAutoFullscreen", &is_video_auto_fullscreen_enabled_},
    {"VideoFullscreenDetection", &is_video_fullscreen_detection_enabled_},
    {"VideoFullscreenOrientationLock", &is_video_fullscreen_orientation_lock_enabled_},
    {"VideoPlaybackQuality", &is_video_playback_quality_enabled_},
    {"VideoRequestAnimationFrame", &is_video_request_animation_frame_enabled_},
    {"VideoRotateToFullscreen", &is_video_rotate_to_fullscreen_enabled_},
    {"VisibilityCollapseColumn", &is_visibility_collapse_column_enabled_},
    {"WakeLock", &is_wake_lock_enabled_},
    {"WasmCodeCache", &is_wasm_code_cache_enabled_},
    {"WebAnimationsAPI", &is_web_animations_api_enabled_},
    {"WebAnimationsSVG", &is_web_animations_svg_enabled_},
    {"WebAssemblyThreads", &is_web_assembly_threads_enabled_},
    {"WebAuth", &is_web_auth_enabled_},
    {"WebAuthenticationFeaturePolicy", &is_web_authentication_feature_policy_enabled_},
    {"WebBluetooth", &is_web_bluetooth_enabled_},
    {"WebBluetoothScanning", &is_web_bluetooth_scanning_enabled_},
    {"WebCodecs", &is_web_codecs_enabled_},
    {"WebGL2ComputeContext", &is_webgl2_compute_context_enabled_},
    {"WebGLDraftExtensions", &is_webgl_draft_extensions_enabled_},
    {"WebGLImageChromium", &is_webgl_image_chromium_enabled_},
    {"WebGPU", &is_webgpu_enabled_},
    {"WebHID", &is_web_hid_enabled_},
    {"WebNFC", &is_web_nfc_enabled_},
    {"WebScheduler", &is_web_scheduler_enabled_},
    {"WebShare", &is_web_share_enabled_},
    {"WebShareV2", &is_web_share_v_2_enabled_},
    {"WebSocketStream", &is_websocket_stream_enabled_},
    {"WebUSB", &is_web_usb_enabled_},
    {"WebUSBOnDedicatedWorkers", &is_web_usb_on_dedicated_workers_enabled_},
    {"WebVTTRegions", &is_web_vtt_regions_enabled_},
    {"WebXR", &is_web_xr_enabled_},
    {"WebXRARModule", &is_web_xr_ar_module_enabled_},
    {"WebXRHitTest", &is_web_xr_hit_test_enabled_},
    {"WebXRHitTestEntityTypes", &is_web_xr_hit_test_entity_types_enabled_},
    {"WebXRIncubations", &is_web_xr_incubations_enabled_},
    {"WindowPlacement", &is_window_placement_enabled_},
    {"WritableFileStream", &is_writable_file_stream_enabled_},
    {"XSLT", &is_xslt_enabled_},
  };
  for (const auto& feature : kFeatures) {
    if (name == feature.name) {
      *feature.setting = enable;
      return;
    }
  }
  DLOG(ERROR) << "RuntimeEnabledFeature not recognized: " << name;
}


bool RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kAccessibilityExposeARIAAnnotations);
}


bool RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::AllowSyncXHRInPageDismissalEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kAllowSyncXHRInPageDismissal);
}


bool RuntimeEnabledFeatures::AnimationWorkletEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::AnimationWorkletEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kAnimationWorklet);
}


bool RuntimeEnabledFeatures::AutoPictureInPictureEnabled(const FeatureContext* context) {
  if (!RuntimeEnabledFeatures::PictureInPictureAPIEnabled(context))
    return false;
  if (RuntimeEnabledFeatures::AutoPictureInPictureEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kAutoPictureInPicture);
}


bool RuntimeEnabledFeatures::BuiltInModuleInfraEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::BuiltInModuleInfraEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kBuiltInModuleInfra);
}


bool RuntimeEnabledFeatures::BuiltInModuleKvStorageEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::BuiltInModuleKvStorageEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kBuiltInModuleKvStorage);
}


bool RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kCacheStorageCodeCacheHint);
}


bool RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kContactsManagerExtraProperties);
}


bool RuntimeEnabledFeatures::ContentIndexEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ContentIndexEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kContentIndex);
}


bool RuntimeEnabledFeatures::CustomElementsV0Enabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::CustomElementsV0EnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kCustomElementsV0);
}


bool RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kDisableHardwareNoiseSuppression);
}


bool RuntimeEnabledFeatures::DisplayLockingEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::DisplayLockingEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kDisplayLocking);
}


bool RuntimeEnabledFeatures::EventTimingEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::EventTimingEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kEventTiming);
}


bool RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ExperimentalAutoplayDynamicDelegationEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kExperimentalAutoplayDynamicDelegation);
}


bool RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kExperimentalIsInputPending);
}


bool RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kExperimentalJSProfiler);
}


bool RuntimeEnabledFeatures::FeaturePolicyReportingEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::FeaturePolicyReportingEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kFeaturePolicyReporting);
}


bool RuntimeEnabledFeatures::HrefTranslateEnabled(const FeatureContext* context) {
  if (!RuntimeEnabledFeatures::TranslateServiceEnabled(context))
    return false;
  if (RuntimeEnabledFeatures::HrefTranslateEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kHrefTranslate);
}


bool RuntimeEnabledFeatures::HTMLImportsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::HTMLImportsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kHTMLImports);
}


bool RuntimeEnabledFeatures::NativeFileSystemEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::NativeFileSystemEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kNativeFileSystem);
}


bool RuntimeEnabledFeatures::NotificationTriggersEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::NotificationTriggersEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kNotificationTriggers);
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPI);
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabled(const FeatureContext* context) {
  if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(context))
    return false;
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabledByRuntimeFlag())
    return true;
  // The feature does not have an origin trial name and its runtime flag
  // is not enabled.
  return false;
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIDeprecation);
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIImplied);
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS);
}


bool RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPINavigation);
}


bool RuntimeEnabledFeatures::PageFreezeOptInEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PageFreezeOptInEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPageFreezeOptIn);
}


bool RuntimeEnabledFeatures::PageFreezeOptOutEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PageFreezeOptOutEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPageFreezeOptOut);
}


bool RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPerMethodCanMakePaymentQuota);
}


bool RuntimeEnabledFeatures::PNaClEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PNaClEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPNaCl);
}


bool RuntimeEnabledFeatures::PointerLockOptionsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PointerLockOptionsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPointerLockOptions);
}


bool RuntimeEnabledFeatures::PriorityHintsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::PriorityHintsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kPriorityHints);
}


bool RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kRtcAudioJitterBufferMaxPackets);
}


bool RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::RtcAudioJitterBufferRtxHandlingEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kRtcAudioJitterBufferRtxHandling);
}


bool RuntimeEnabledFeatures::RTCIceTransportExtensionEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::RTCIceTransportExtensionEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kRTCIceTransportExtension);
}


bool RuntimeEnabledFeatures::RTCQuicTransportEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::RTCQuicTransportEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kRTCQuicTransport);
}


bool RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay);
}


bool RuntimeEnabledFeatures::ScrollTimelineEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ScrollTimelineEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kScrollTimeline);
}


bool RuntimeEnabledFeatures::SerialEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::SerialEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kSerial);
}


bool RuntimeEnabledFeatures::ShadowDOMV0Enabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::ShadowDOMV0EnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kShadowDOMV0);
}


bool RuntimeEnabledFeatures::SignatureBasedIntegrityEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::SignatureBasedIntegrityEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kSignatureBasedIntegrity);
}


bool RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::SignedExchangeSubresourcePrefetchEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kSignedExchangeSubresourcePrefetch);
}


bool RuntimeEnabledFeatures::SkipAdEnabled(const FeatureContext* context) {
  if (!RuntimeEnabledFeatures::MediaSessionEnabled(context))
    return false;
  if (RuntimeEnabledFeatures::SkipAdEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kSkipAd);
}


bool RuntimeEnabledFeatures::SmsReceiverEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::SmsReceiverEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kSmsReceiver);
}


bool RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kTextFragmentIdentifiers);
}


bool RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kTouchEventFeatureDetection);
}


bool RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::UnoptimizedImagePoliciesEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kUnoptimizedImagePolicies);
}


bool RuntimeEnabledFeatures::UnsizedMediaPolicyEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::UnsizedMediaPolicyEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kUnsizedMediaPolicy);
}


bool RuntimeEnabledFeatures::WakeLockEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::WakeLockEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kWakeLock);
}


bool RuntimeEnabledFeatures::WebAssemblyThreadsEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::WebAssemblyThreadsEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kWebAssemblyThreads);
}


bool RuntimeEnabledFeatures::WebNFCEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::WebNFCEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kWebNFC);
}


bool RuntimeEnabledFeatures::WebSchedulerEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::WebSchedulerEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kWebScheduler);
}


bool RuntimeEnabledFeatures::WebSocketStreamEnabled(const FeatureContext* context) {
  if (RuntimeEnabledFeatures::WebSocketStreamEnabledByRuntimeFlag())
    return true;
  return context && context->FeatureEnabled(OriginTrialFeature::kWebSocketStream);
}


bool RuntimeEnabledFeatures::is_accelerated_2d_canvas_enabled_ = true;
bool RuntimeEnabledFeatures::is_accelerated_small_canvases_enabled_ = true;
bool RuntimeEnabledFeatures::is_accessibility_expose_aria_annotations_enabled_ = false;
bool RuntimeEnabledFeatures::is_accessibility_expose_display_none_enabled_ = false;
bool RuntimeEnabledFeatures::is_accessibility_object_model_enabled_ = false;
bool RuntimeEnabledFeatures::is_address_space_enabled_ = false;
bool RuntimeEnabledFeatures::is_ad_tagging_enabled_ = false;
bool RuntimeEnabledFeatures::is_allow_activation_delegation_attr_enabled_ = false;
bool RuntimeEnabledFeatures::is_allow_content_initiated_data_url_navigations_enabled_ = true;
bool RuntimeEnabledFeatures::is_allow_sync_xhr_in_page_dismissal_enabled_ = false;
bool RuntimeEnabledFeatures::is_animation_worklet_enabled_ = false;
bool RuntimeEnabledFeatures::is_aom_aria_properties_enabled_ = true;
bool RuntimeEnabledFeatures::is_aom_aria_relationship_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_aspect_ratio_from_width_and_height_enabled_ = true;
bool RuntimeEnabledFeatures::is_async_clipboard_enabled_ = true;
bool RuntimeEnabledFeatures::is_audio_video_tracks_enabled_ = false;
bool RuntimeEnabledFeatures::is_audio_worklet_realtime_thread_enabled_ = false;
bool RuntimeEnabledFeatures::is_auto_lazy_load_on_reloads_enabled_ = false;
bool RuntimeEnabledFeatures::is_automatic_lazy_frame_loading_enabled_ = true;
bool RuntimeEnabledFeatures::is_automatic_lazy_image_loading_enabled_ = true;
bool RuntimeEnabledFeatures::is_automation_controlled_enabled_ = false;
bool RuntimeEnabledFeatures::is_auto_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeatures::is_autoplay_ignores_web_audio_enabled_ = false;
bool RuntimeEnabledFeatures::is_back_forward_cache_enabled_ = false;
bool RuntimeEnabledFeatures::is_background_fetch_enabled_ = true;
bool RuntimeEnabledFeatures::is_background_video_track_optimization_enabled_ = true;
bool RuntimeEnabledFeatures::is_badging_enabled_ = true;
bool RuntimeEnabledFeatures::is_bidi_caret_affinity_enabled_ = false;
bool RuntimeEnabledFeatures::is_blink_runtime_call_stats_enabled_ = false;
bool RuntimeEnabledFeatures::is_blob_read_methods_enabled_ = true;
bool RuntimeEnabledFeatures::is_block_credentialed_subresources_enabled_ = true;
bool RuntimeEnabledFeatures::is_block_html_parser_on_style_sheets_enabled_ = false;
bool RuntimeEnabledFeatures::is_blocking_downloads_in_sandbox_enabled_ = false;
bool RuntimeEnabledFeatures::is_blocking_focus_without_user_activation_enabled_ = false;
bool RuntimeEnabledFeatures::is_browser_verified_user_activation_keyboard_enabled_ = false;
bool RuntimeEnabledFeatures::is_browser_verified_user_activation_mouse_enabled_ = false;
bool RuntimeEnabledFeatures::is_built_in_module_all_enabled_ = false;
bool RuntimeEnabledFeatures::is_built_in_module_infra_enabled_ = false;
bool RuntimeEnabledFeatures::is_built_in_module_kv_storage_enabled_ = false;
bool RuntimeEnabledFeatures::is_built_in_module_switch_element_enabled_ = false;
bool RuntimeEnabledFeatures::is_cache_inline_script_code_enabled_ = false;
bool RuntimeEnabledFeatures::is_cache_storage_code_cache_hint_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_2d_context_lost_restored_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_2d_image_chromium_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_2d_scroll_path_into_view_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_color_management_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_hit_region_enabled_ = false;
bool RuntimeEnabledFeatures::is_canvas_image_smoothing_enabled_ = false;
bool RuntimeEnabledFeatures::is_click_pointer_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_click_retargetting_enabled_ = false;
bool RuntimeEnabledFeatures::is_composite_after_paint_enabled_ = false;
bool RuntimeEnabledFeatures::is_compositor_touch_action_enabled_ = false;
bool RuntimeEnabledFeatures::is_computed_accessibility_info_enabled_ = false;
bool RuntimeEnabledFeatures::is_consolidated_movement_xy_enabled_ = false;
bool RuntimeEnabledFeatures::is_content_index_enabled_ = false;
bool RuntimeEnabledFeatures::is_context_menu_enabled_ = false;
bool RuntimeEnabledFeatures::is_cookie_deprecation_messages_enabled_ = false;
bool RuntimeEnabledFeatures::is_cookie_store_document_enabled_ = false;
bool RuntimeEnabledFeatures::is_cookie_store_worker_enabled_ = false;
bool RuntimeEnabledFeatures::is_cookies_without_same_site_must_be_secure_enabled_ = false;
bool RuntimeEnabledFeatures::is_cooperative_scheduling_enabled_ = false;
bool RuntimeEnabledFeatures::is_cors_rfc_1918_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_3_text_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_3_text_break_anywhere_enabled_ = true;
bool RuntimeEnabledFeatures::is_css_additive_animations_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_calc_as_int_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_cascade_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_color_scheme_enabled_ = true;
bool RuntimeEnabledFeatures::is_css_color_scheme_ua_rendering_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_focus_visible_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_font_size_adjust_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_hex_alpha_color_enabled_ = true;
bool RuntimeEnabledFeatures::is_css_independent_transform_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_intrinsic_size_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_layout_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_logical_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_logical_overflow_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_marker_pseudo_element_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_mask_source_type_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_modules_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_offset_path_ray_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_offset_path_ray_contain_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_offset_position_anchor_enabled_ = false;
bool RuntimeEnabledFeatures::is_cssom_view_scroll_coordinates_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_paint_api_arguments_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_pseudo_is_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_pseudo_where_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_render_subtree_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_snap_size_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_variables_2_enabled_ = true;
bool RuntimeEnabledFeatures::is_css_variables_2_at_property_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_variables_2_image_values_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_variables_2_transform_values_enabled_ = false;
bool RuntimeEnabledFeatures::is_css_viewport_enabled_ = false;
bool RuntimeEnabledFeatures::is_custom_element_default_style_enabled_ = false;
bool RuntimeEnabledFeatures::is_custom_elements_v0_enabled_ = false;
bool RuntimeEnabledFeatures::is_custom_state_pseudo_class_enabled_ = false;
bool RuntimeEnabledFeatures::is_database_enabled_ = true;
bool RuntimeEnabledFeatures::is_decode_jpeg_420_images_to_yuv_enabled_ = false;
bool RuntimeEnabledFeatures::is_decode_lossy_web_p_images_to_yuv_enabled_ = false;
bool RuntimeEnabledFeatures::is_desktop_capture_disable_local_echo_control_enabled_ = false;
bool RuntimeEnabledFeatures::is_disable_hardware_noise_suppression_enabled_ = false;
bool RuntimeEnabledFeatures::is_disallow_document_access_enabled_ = false;
bool RuntimeEnabledFeatures::is_discard_input_to_moving_iframes_enabled_ = true;
bool RuntimeEnabledFeatures::is_display_cutout_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_display_locking_enabled_ = false;
bool RuntimeEnabledFeatures::is_document_cookie_enabled_ = false;
bool RuntimeEnabledFeatures::is_document_domain_enabled_ = false;
bool RuntimeEnabledFeatures::is_document_policy_enabled_ = false;
bool RuntimeEnabledFeatures::is_document_write_enabled_ = false;
bool RuntimeEnabledFeatures::is_edit_context_enabled_ = false;
bool RuntimeEnabledFeatures::is_editing_ng_enabled_ = false;
bool RuntimeEnabledFeatures::is_embedded_vtt_stylesheets_enabled_ = false;
bool RuntimeEnabledFeatures::is_encrypted_media_encryption_scheme_query_enabled_ = true;
bool RuntimeEnabledFeatures::is_encrypted_media_hdcp_policy_check_enabled_ = true;
bool RuntimeEnabledFeatures::is_encrypted_media_persistent_usage_record_session_enabled_ = false;
bool RuntimeEnabledFeatures::is_enter_key_hint_attribute_enabled_ = true;
bool RuntimeEnabledFeatures::is_event_timing_enabled_ = false;
bool RuntimeEnabledFeatures::is_exec_command_in_java_script_enabled_ = false;
bool RuntimeEnabledFeatures::is_expensive_background_timer_throttling_enabled_ = true;
bool RuntimeEnabledFeatures::is_experimental_autoplay_dynamic_delegation_enabled_ = false;
bool RuntimeEnabledFeatures::is_experimental_content_security_policy_features_enabled_ = false;
bool RuntimeEnabledFeatures::is_experimental_is_input_pending_enabled_ = false;
bool RuntimeEnabledFeatures::is_experimental_js_profiler_enabled_ = false;
bool RuntimeEnabledFeatures::is_experimental_productivity_features_enabled_ = false;
bool RuntimeEnabledFeatures::is_extended_text_metrics_enabled_ = false;
bool RuntimeEnabledFeatures::is_extra_webgl_video_texture_metadata_enabled_ = false;
bool RuntimeEnabledFeatures::is_fallback_cursor_mode_enabled_ = false;
bool RuntimeEnabledFeatures::is_feature_policy_for_client_hints_enabled_ = false;
bool RuntimeEnabledFeatures::is_feature_policy_for_sandbox_enabled_ = false;
bool RuntimeEnabledFeatures::is_feature_policy_java_script_interface_enabled_ = true;
bool RuntimeEnabledFeatures::is_feature_policy_reporting_enabled_ = false;
bool RuntimeEnabledFeatures::is_feature_policy_vibrate_feature_enabled_ = false;
bool RuntimeEnabledFeatures::is_fetch_metadata_enabled_ = true;
bool RuntimeEnabledFeatures::is_fetch_metadata_destination_enabled_ = false;
bool RuntimeEnabledFeatures::is_file_handling_enabled_ = false;
bool RuntimeEnabledFeatures::is_file_system_enabled_ = true;
bool RuntimeEnabledFeatures::is_flat_tree_style_recalc_enabled_ = true;
bool RuntimeEnabledFeatures::is_focusless_spatial_navigation_enabled_ = false;
bool RuntimeEnabledFeatures::is_font_src_local_matching_enabled_ = false;
bool RuntimeEnabledFeatures::is_forced_colors_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_defer_script_intervention_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_eager_measure_memory_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_overlay_fullscreen_video_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_synchronous_html_parsing_enabled_ = false;
bool RuntimeEnabledFeatures::is_fractional_mouse_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_fractional_scroll_offsets_enabled_ = false;
bool RuntimeEnabledFeatures::is_freeze_frames_on_visibility_enabled_ = false;
bool RuntimeEnabledFeatures::is_gamepad_button_axis_events_enabled_ = false;
bool RuntimeEnabledFeatures::is_group_effect_enabled_ = false;
bool RuntimeEnabledFeatures::is_href_translate_enabled_ = true;
bool RuntimeEnabledFeatures::is_html_imports_enabled_ = false;
bool RuntimeEnabledFeatures::is_idb_observer_enabled_ = false;
bool RuntimeEnabledFeatures::is_idb_relaxed_durability_enabled_ = false;
bool RuntimeEnabledFeatures::is_idle_detection_enabled_ = false;
bool RuntimeEnabledFeatures::is_ignore_cross_origin_window_when_named_access_on_window_enabled_ = false;
bool RuntimeEnabledFeatures::is_image_orientation_enabled_ = true;
bool RuntimeEnabledFeatures::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeatures::is_import_maps_enabled_ = false;
bool RuntimeEnabledFeatures::is_inert_attribute_enabled_ = false;
bool RuntimeEnabledFeatures::is_installed_app_enabled_ = true;
bool RuntimeEnabledFeatures::is_intersection_observer_document_scrolling_element_root_enabled_ = true;
bool RuntimeEnabledFeatures::is_intersection_observer_v_2_enabled_ = true;
bool RuntimeEnabledFeatures::is_invisible_dom_enabled_ = false;
bool RuntimeEnabledFeatures::is_isolated_code_cache_enabled_ = true;
bool RuntimeEnabledFeatures::is_isolated_world_csp_enabled_ = false;
bool RuntimeEnabledFeatures::is_keyboard_focusable_scrollers_enabled_ = false;
bool RuntimeEnabledFeatures::is_lang_attribute_aware_form_control_ui_enabled_ = false;
bool RuntimeEnabledFeatures::is_lang_client_hint_header_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_enabled_ = true;
bool RuntimeEnabledFeatures::is_layout_ng_block_fragmentation_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_fieldset_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_flex_box_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_fragment_item_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_fragment_paint_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_line_cache_enabled_ = false;
bool RuntimeEnabledFeatures::is_layout_ng_table_enabled_ = false;
bool RuntimeEnabledFeatures::is_lazy_frame_loading_enabled_ = true;
bool RuntimeEnabledFeatures::is_lazy_frame_visible_load_time_metrics_enabled_ = false;
bool RuntimeEnabledFeatures::is_lazy_image_loading_enabled_ = true;
bool RuntimeEnabledFeatures::is_lazy_image_loading_metadata_fetch_enabled_ = false;
bool RuntimeEnabledFeatures::is_lazy_image_visible_load_time_metrics_enabled_ = false;
bool RuntimeEnabledFeatures::is_lazy_initialize_media_controls_enabled_ = false;
bool RuntimeEnabledFeatures::is_legacy_windows_d_write_font_fallback_enabled_ = false;
bool RuntimeEnabledFeatures::is_link_system_colors_enabled_ = true;
bool RuntimeEnabledFeatures::is_manual_slotting_enabled_ = false;
bool RuntimeEnabledFeatures::is_mathml_core_enabled_ = false;
bool RuntimeEnabledFeatures::is_measure_memory_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_capabilities_encoding_info_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_capabilities_encrypted_media_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_capabilities_spatial_audio_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_capture_depth_video_kind_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_capture_pan_tilt_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_cast_overlay_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_controls_expand_gesture_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_document_download_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_element_volume_greater_than_one_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_engagement_bypass_autoplay_policies_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_latency_hint_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_query_navigation_controls_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_query_shape_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_session_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_session_position_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_session_seeking_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_source_experimental_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_source_in_workers_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_source_new_abort_and_duration_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_source_stable_enabled_ = true;
bool RuntimeEnabledFeatures::is_meta_color_scheme_enabled_ = true;
bool RuntimeEnabledFeatures::is_middle_click_autoscroll_enabled_ = false;
bool RuntimeEnabledFeatures::is_mobile_layout_theme_enabled_ = false;
bool RuntimeEnabledFeatures::is_module_dedicated_worker_enabled_ = true;
bool RuntimeEnabledFeatures::is_module_service_worker_enabled_ = false;
bool RuntimeEnabledFeatures::is_module_shared_worker_enabled_ = false;
bool RuntimeEnabledFeatures::is_mojo_js_enabled_ = false;
bool RuntimeEnabledFeatures::is_mojo_js_test_enabled_ = false;
bool RuntimeEnabledFeatures::is_mouse_subframe_no_implicit_capture_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_language_in_insecure_context_enabled_ = true;
bool RuntimeEnabledFeatures::is_never_slow_mode_enabled_ = false;
bool RuntimeEnabledFeatures::is_new_remote_playback_pipeline_enabled_ = false;
bool RuntimeEnabledFeatures::is_new_system_colors_enabled_ = true;
bool RuntimeEnabledFeatures::is_no_idle_encoding_for_web_tests_enabled_ = false;
bool RuntimeEnabledFeatures::is_notifications_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_triggers_enabled_ = false;
bool RuntimeEnabledFeatures::is_off_main_thread_css_paint_enabled_ = true;
bool RuntimeEnabledFeatures::is_offscreen_canvas_commit_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_dependent_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_deprecation_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_implied_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_invalid_os_enabled_ = false;
bool RuntimeEnabledFeatures::is_origin_trials_sample_api_navigation_enabled_ = false;
bool RuntimeEnabledFeatures::is_out_of_blink_cors_enabled_ = false;
bool RuntimeEnabledFeatures::is_overflow_icons_for_media_controls_enabled_ = false;
bool RuntimeEnabledFeatures::is_overscroll_customization_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_freeze_opt_in_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_freeze_opt_out_enabled_ = false;
bool RuntimeEnabledFeatures::is_paint_under_invalidation_checking_enabled_ = false;
bool RuntimeEnabledFeatures::is_passive_document_event_listeners_enabled_ = true;
bool RuntimeEnabledFeatures::is_passive_document_wheel_event_listeners_enabled_ = true;
bool RuntimeEnabledFeatures::is_pass_paint_visual_rect_to_compositor_enabled_ = false;
bool RuntimeEnabledFeatures::is_password_reveal_enabled_ = false;
bool RuntimeEnabledFeatures::is_payment_app_enabled_ = false;
bool RuntimeEnabledFeatures::is_payment_handler_change_payment_method_enabled_ = true;
bool RuntimeEnabledFeatures::is_payment_handler_handles_shipping_and_contact_enabled_ = true;
bool RuntimeEnabledFeatures::is_payment_method_change_event_enabled_ = true;
bool RuntimeEnabledFeatures::is_payment_request_enabled_ = false;
bool RuntimeEnabledFeatures::is_payment_request_merchant_validation_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_payment_retry_enabled_ = true;
bool RuntimeEnabledFeatures::is_performance_manager_instrumentation_enabled_ = false;
bool RuntimeEnabledFeatures::is_periodic_background_sync_enabled_ = true;
bool RuntimeEnabledFeatures::is_per_method_can_make_payment_quota_enabled_ = false;
bool RuntimeEnabledFeatures::is_permission_delegation_enabled_ = false;
bool RuntimeEnabledFeatures::is_permissions_enabled_ = true;
bool RuntimeEnabledFeatures::is_permissions_request_revoke_enabled_ = false;
bool RuntimeEnabledFeatures::is_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeatures::is_picture_in_picture_v_2_enabled_ = false;
bool RuntimeEnabledFeatures::is_p_na_cl_enabled_ = false;
bool RuntimeEnabledFeatures::is_pointer_lock_options_enabled_ = false;
bool RuntimeEnabledFeatures::is_pointer_raw_update_enabled_ = true;
bool RuntimeEnabledFeatures::is_portals_enabled_ = false;
bool RuntimeEnabledFeatures::is_post_animation_frame_enabled_ = false;
bool RuntimeEnabledFeatures::is_precise_memory_info_enabled_ = false;
bool RuntimeEnabledFeatures::is_predicted_events_enabled_ = true;
bool RuntimeEnabledFeatures::is_prefixed_video_fullscreen_enabled_ = true;
bool RuntimeEnabledFeatures::is_presentation_enabled_ = true;
bool RuntimeEnabledFeatures::is_print_browser_enabled_ = false;
bool RuntimeEnabledFeatures::is_priority_hints_enabled_ = false;
bool RuntimeEnabledFeatures::is_push_messaging_enabled_ = true;
bool RuntimeEnabledFeatures::is_push_messaging_subscription_change_enabled_ = false;
bool RuntimeEnabledFeatures::is_quic_transport_enabled_ = false;
bool RuntimeEnabledFeatures::is_raw_clipboard_enabled_ = false;
bool RuntimeEnabledFeatures::is_reduced_referrer_granularity_enabled_ = false;
bool RuntimeEnabledFeatures::is_remote_playback_enabled_ = true;
bool RuntimeEnabledFeatures::is_resize_observer_updates_enabled_ = false;
bool RuntimeEnabledFeatures::is_restrict_app_cache_to_secure_contexts_enabled_ = true;
bool RuntimeEnabledFeatures::is_restrict_automatic_lazy_frame_loading_to_data_saver_enabled_ = true;
bool RuntimeEnabledFeatures::is_restrict_automatic_lazy_image_loading_to_data_saver_enabled_ = true;
bool RuntimeEnabledFeatures::is_restricted_webkit_appearance_enabled_ = true;
bool RuntimeEnabledFeatures::is_rtc_audio_jitter_buffer_max_packets_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_audio_jitter_buffer_rtx_handling_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_dtls_transport_enabled_ = true;
bool RuntimeEnabledFeatures::is_rtc_ice_transport_extension_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_quic_transport_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_sctp_transport_enabled_ = true;
bool RuntimeEnabledFeatures::is_rtc_stats_relative_packet_arrival_delay_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_svc_scalability_mode_enabled_ = false;
bool RuntimeEnabledFeatures::is_rtc_unified_plan_enabled_ = true;
bool RuntimeEnabledFeatures::is_rtc_unified_plan_by_default_enabled_ = false;
bool RuntimeEnabledFeatures::is_same_site_by_default_cookies_enabled_ = false;
bool RuntimeEnabledFeatures::is_screen_enumeration_enabled_ = false;
bool RuntimeEnabledFeatures::is_scripted_speech_recognition_enabled_ = true;
bool RuntimeEnabledFeatures::is_scripted_speech_synthesis_enabled_ = true;
bool RuntimeEnabledFeatures::is_script_streaming_on_preload_enabled_ = false;
bool RuntimeEnabledFeatures::is_scroll_customization_enabled_ = false;
bool RuntimeEnabledFeatures::is_scroll_snap_after_layout_enabled_ = true;
bool RuntimeEnabledFeatures::is_scroll_timeline_enabled_ = false;
bool RuntimeEnabledFeatures::is_scroll_top_left_interop_enabled_ = true;
bool RuntimeEnabledFeatures::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = true;
bool RuntimeEnabledFeatures::is_send_mouse_events_disabled_form_controls_enabled_ = false;
bool RuntimeEnabledFeatures::is_sensor_extra_classes_enabled_ = false;
bool RuntimeEnabledFeatures::is_service_worker_client_lifecycle_state_enabled_ = false;
bool RuntimeEnabledFeatures::is_service_worker_fetch_event_worker_timing_enabled_ = false;
bool RuntimeEnabledFeatures::is_set_root_scroller_enabled_ = false;
bool RuntimeEnabledFeatures::is_shadow_dom_v0_enabled_ = false;
bool RuntimeEnabledFeatures::is_shadow_piercing_descendant_combinator_enabled_ = false;
bool RuntimeEnabledFeatures::is_shape_detection_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_array_buffer_enabled_ = true;
bool RuntimeEnabledFeatures::is_signature_based_integrity_enabled_ = false;
bool RuntimeEnabledFeatures::is_signed_exchange_prefetch_cache_for_navigations_enabled_ = false;
bool RuntimeEnabledFeatures::is_signed_exchange_subresource_prefetch_enabled_ = false;
bool RuntimeEnabledFeatures::is_skip_ad_enabled_ = false;
bool RuntimeEnabledFeatures::is_skip_touch_event_filter_enabled_ = false;
bool RuntimeEnabledFeatures::is_stable_blink_features_enabled_ = true;
bool RuntimeEnabledFeatures::is_stacked_css_property_animations_enabled_ = false;
bool RuntimeEnabledFeatures::is_storage_access_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_storage_quota_details_enabled_ = true;
bool RuntimeEnabledFeatures::is_strict_mime_types_for_workers_enabled_ = false;
bool RuntimeEnabledFeatures::is_surface_embedding_features_enabled_ = true;
bool RuntimeEnabledFeatures::is_text_fragment_identifiers_enabled_ = true;
bool RuntimeEnabledFeatures::is_timer_throttling_for_background_tabs_enabled_ = true;
bool RuntimeEnabledFeatures::is_timer_throttling_for_hidden_frames_enabled_ = true;
bool RuntimeEnabledFeatures::is_touch_event_feature_detection_enabled_ = true;
bool RuntimeEnabledFeatures::is_track_layout_passes_per_block_enabled_ = false;
bool RuntimeEnabledFeatures::is_transferable_streams_enabled_ = false;
bool RuntimeEnabledFeatures::is_translate_service_enabled_ = false;
bool RuntimeEnabledFeatures::is_trusted_dom_types_enabled_ = false;
bool RuntimeEnabledFeatures::is_unclosed_form_control_is_invalid_enabled_ = false;
bool RuntimeEnabledFeatures::is_unified_pointer_capture_in_blink_enabled_ = true;
bool RuntimeEnabledFeatures::is_unified_touch_adjustment_enabled_ = true;
bool RuntimeEnabledFeatures::is_unoptimized_image_policies_enabled_ = false;
bool RuntimeEnabledFeatures::is_unsized_media_policy_enabled_ = false;
bool RuntimeEnabledFeatures::is_update_hover_at_begin_frame_enabled_ = false;
bool RuntimeEnabledFeatures::is_user_activation_api_enabled_ = true;
bool RuntimeEnabledFeatures::is_user_activation_post_message_transfer_enabled_ = false;
bool RuntimeEnabledFeatures::is_user_activation_same_origin_visibility_enabled_ = false;
bool RuntimeEnabledFeatures::is_user_agent_client_hint_enabled_ = false;
bool RuntimeEnabledFeatures::is_use_windows_system_colors_enabled_ = true;
bool RuntimeEnabledFeatures::is_v8_idle_tasks_enabled_ = false;
bool RuntimeEnabledFeatures::is_video_auto_fullscreen_enabled_ = false;
bool RuntimeEnabledFeatures::is_video_fullscreen_detection_enabled_ = false;
bool RuntimeEnabledFeatures::is_video_fullscreen_orientation_lock_enabled_ = false;
bool RuntimeEnabledFeatures::is_video_playback_quality_enabled_ = true;
bool RuntimeEnabledFeatures::is_video_request_animation_frame_enabled_ = false;
bool RuntimeEnabledFeatures::is_video_rotate_to_fullscreen_enabled_ = false;
bool RuntimeEnabledFeatures::is_visibility_collapse_column_enabled_ = false;
bool RuntimeEnabledFeatures::is_wake_lock_enabled_ = false;
bool RuntimeEnabledFeatures::is_wasm_code_cache_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_animations_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_animations_svg_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_assembly_threads_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_auth_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_authentication_feature_policy_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_scanning_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_codecs_enabled_ = false;
bool RuntimeEnabledFeatures::is_webgl2_compute_context_enabled_ = false;
bool RuntimeEnabledFeatures::is_webgl_draft_extensions_enabled_ = false;
bool RuntimeEnabledFeatures::is_webgl_image_chromium_enabled_ = false;
bool RuntimeEnabledFeatures::is_webgpu_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_hid_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_scheduler_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_share_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_share_v_2_enabled_ = false;
bool RuntimeEnabledFeatures::is_websocket_stream_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_usb_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_usb_on_dedicated_workers_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_vtt_regions_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_xr_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_xr_ar_module_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_xr_hit_test_enabled_ = true;
bool RuntimeEnabledFeatures::is_web_xr_hit_test_entity_types_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_xr_incubations_enabled_ = false;
bool RuntimeEnabledFeatures::is_window_placement_enabled_ = false;
bool RuntimeEnabledFeatures::is_writable_file_stream_enabled_ = false;
bool RuntimeEnabledFeatures::is_xslt_enabled_ = true;

// Platform-dependent features
#if defined(OS_ANDROID)
bool RuntimeEnabledFeatures::is_audio_output_devices_enabled_ = false;
bool RuntimeEnabledFeatures::is_cloneable_native_file_system_handles_enabled_ = false;
bool RuntimeEnabledFeatures::is_composited_selection_update_enabled_ = true;
bool RuntimeEnabledFeatures::is_contacts_manager_enabled_ = true;
bool RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeatures::is_get_display_media_enabled_ = false;
bool RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_capture_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_ = true;
bool RuntimeEnabledFeatures::is_native_file_system_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_content_utils_enabled_ = false;
bool RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_constructor_enabled_ = false;
bool RuntimeEnabledFeatures::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeatures::is_on_device_change_enabled_ = false;
bool RuntimeEnabledFeatures::is_orientation_event_enabled_ = true;
bool RuntimeEnabledFeatures::is_page_popup_enabled_ = false;
bool RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeatures::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeatures::is_serial_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_worker_enabled_ = false;
bool RuntimeEnabledFeatures::is_sms_receiver_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_enabled_ = true;
#endif

#if defined(OS_WIN)
bool RuntimeEnabledFeatures::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeatures::is_cloneable_native_file_system_handles_enabled_ = false;
bool RuntimeEnabledFeatures::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeatures::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_native_file_system_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeatures::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeatures::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeatures::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeatures::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeatures::is_serial_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeatures::is_sms_receiver_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_enabled_ = false;
#endif

#if defined(OS_CHROMEOS)
bool RuntimeEnabledFeatures::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeatures::is_cloneable_native_file_system_handles_enabled_ = false;
bool RuntimeEnabledFeatures::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_ = true;
bool RuntimeEnabledFeatures::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_native_file_system_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeatures::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeatures::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeatures::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeatures::is_serial_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeatures::is_sms_receiver_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_enabled_ = true;
#endif

#if defined(OS_MACOSX)
bool RuntimeEnabledFeatures::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeatures::is_cloneable_native_file_system_handles_enabled_ = false;
bool RuntimeEnabledFeatures::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeatures::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_native_file_system_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeatures::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_content_image_enabled_ = false;
bool RuntimeEnabledFeatures::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeatures::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeatures::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeatures::is_serial_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeatures::is_sms_receiver_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_enabled_ = true;
#endif

// Default values for platforms not specifically handled above
#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
bool RuntimeEnabledFeatures::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeatures::is_cloneable_native_file_system_handles_enabled_ = false;
bool RuntimeEnabledFeatures::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeatures::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeatures::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeatures::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeatures::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeatures::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeatures::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeatures::is_native_file_system_enabled_ = false;
bool RuntimeEnabledFeatures::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeatures::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeatures::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeatures::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeatures::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeatures::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeatures::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeatures::is_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeatures::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeatures::is_serial_enabled_ = false;
bool RuntimeEnabledFeatures::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeatures::is_sms_receiver_enabled_ = false;
bool RuntimeEnabledFeatures::is_web_bluetooth_enabled_ = false;
#endif

} // namespace blink
