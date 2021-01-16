// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE SCHEMA DEFINITION AND DESCRIPTION IN
//   field_trial_testing_config_schema.json
//   fieldtrial_testing_config.json
// DO NOT EDIT.

#include "fieldtrial_testing_config.h"

namespace variations {


const char* const array_kFieldTrialConfig_enable_features_244[] = {
      "use-new-media-cache",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_296[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_296[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_266[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_296,
      1,
      array_kFieldTrialConfig_form_factors_296,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_244,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_243[] = {
      "HistoryManipulationIntervention",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_295[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_295[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_265[] = {
    {
      "HistoryManipulationIntervention",
      array_kFieldTrialConfig_platforms_295,
      2,
      array_kFieldTrialConfig_form_factors_295,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_243,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_242[] = {
      "WebViewWakeMetricsService",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_294[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_294[] = {
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_264[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_294,
      1,
      array_kFieldTrialConfig_form_factors_294,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_242,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_241[] = {
      "WebRtcHybridAgc",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_95[] = {
      {
        "saturation_margin",
        "5",
      },
      {
        "use_peaks_not_rms",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_293[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_293[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_263[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_293,
      1,
      array_kFieldTrialConfig_form_factors_293,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_95,
      2,
      array_kFieldTrialConfig_enable_features_241,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_292[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_292[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_262[] = {
    {
      "pacing_factor:1.0,trust_vp8:true,trust_vp9:true,video_hysteresis:1.2,bitrate_adjuster:true,vp8_s0_boost:false",
      array_kFieldTrialConfig_platforms_292,
      1,
      array_kFieldTrialConfig_form_factors_292,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_291[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_291[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_261[] = {
    {
      "Enabled,vp8_br:10kbps,vp9_br:29kbps",
      array_kFieldTrialConfig_platforms_291,
      2,
      array_kFieldTrialConfig_form_factors_291,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_290[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_290[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_260[] = {
    {
      "2_V1",
      array_kFieldTrialConfig_platforms_290,
      2,
      array_kFieldTrialConfig_form_factors_290,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_289[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_289[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_259[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_289,
      1,
      array_kFieldTrialConfig_form_factors_289,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_288[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_288[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_258[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_288,
      1,
      array_kFieldTrialConfig_form_factors_288,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_240[] = {
      "WebRTC-EnableWebRtcEcdsa",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_287[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_287[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_257[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_287,
      1,
      array_kFieldTrialConfig_form_factors_287,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_240,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_286[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_286[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_256[] = {
    {
      "QueueSize:800,MinBitrate:30000",
      array_kFieldTrialConfig_platforms_286,
      2,
      array_kFieldTrialConfig_form_factors_286,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_285[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_285[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_255[] = {
    {
      "persist,limit:3s,fraction:.8,interval:1s",
      array_kFieldTrialConfig_platforms_285,
      2,
      array_kFieldTrialConfig_form_factors_285,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_284[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_284[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_254[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_284,
      2,
      array_kFieldTrialConfig_form_factors_284,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_283[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_283[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_253[] = {
    {
      "Enabled-85",
      array_kFieldTrialConfig_platforms_283,
      1,
      array_kFieldTrialConfig_form_factors_283,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_282[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_282[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_252[] = {
    {
      "SwitchEnabled",
      array_kFieldTrialConfig_platforms_282,
      1,
      array_kFieldTrialConfig_form_factors_282,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_239[] = {
      "WebPaymentsPerMethodCanMakePaymentQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_281[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_281[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_251[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_281,
      1,
      array_kFieldTrialConfig_form_factors_281,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_239,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_94[] = {
      {
        "blocklist_additions",
        "00060000:e,fffd:e,ed5f25a4:e",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_280[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_280[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_250[] = {
    {
      "TestGroup",
      array_kFieldTrialConfig_platforms_280,
      1,
      array_kFieldTrialConfig_form_factors_280,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_94,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_23[] = {
      "AutoplayIgnoreWebAudio",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_279[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_279[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_249[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_279,
      1,
      array_kFieldTrialConfig_form_factors_279,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_23,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_238[] = {
      "AdjustWebApkInstallationSpace",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_93[] = {
      {
        "webapk_extra_installation_space_mb",
        "100",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_278[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_278[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_248[] = {
    {
      "EnabledLaunch",
      array_kFieldTrialConfig_platforms_278,
      1,
      array_kFieldTrialConfig_form_factors_278,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_93,
      1,
      array_kFieldTrialConfig_enable_features_238,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_237[] = {
      "UseSurfaceLayerForVideo",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_277[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_277[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_247[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_277,
      1,
      array_kFieldTrialConfig_form_factors_277,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_237,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_236[] = {
      "MojoVideoCapture",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_276[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_276[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_246[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_276,
      1,
      array_kFieldTrialConfig_form_factors_276,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_236,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_22[] = {
      "WebAssemblyBaseline",
};
const char* const array_kFieldTrialConfig_enable_features_235[] = {
      "WebAssemblyTiering",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_275[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_275[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_21[] = {
      "WebAssemblyTiering",
};
const char* const array_kFieldTrialConfig_enable_features_234[] = {
      "WebAssemblyBaseline",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_274[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_274[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_233[] = {
      "WebAssemblyBaseline",
      "WebAssemblyTiering",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_273[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_273[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_245[] = {
    {
      "Tiering",
      array_kFieldTrialConfig_platforms_273,
      1,
      array_kFieldTrialConfig_form_factors_273,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_233,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Liftoff",
      array_kFieldTrialConfig_platforms_274,
      1,
      array_kFieldTrialConfig_form_factors_274,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_234,
      1,
      array_kFieldTrialConfig_disable_features_21,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "TurboFan",
      array_kFieldTrialConfig_platforms_275,
      1,
      array_kFieldTrialConfig_form_factors_275,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_235,
      1,
      array_kFieldTrialConfig_disable_features_22,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_232[] = {
      "WasmCodeCache",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_272[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_272[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_244[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_272,
      1,
      array_kFieldTrialConfig_form_factors_272,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_232,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_231[] = {
      "IsolatedCodeCache",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_271[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_271[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_243[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_271,
      1,
      array_kFieldTrialConfig_form_factors_271,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_231,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_20[] = {
      "V8LowMemoryModeForSubframes",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_270[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_270[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_230[] = {
      "V8LowMemoryModeForSubframes",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_269[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_269[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_242[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_269,
      1,
      array_kFieldTrialConfig_form_factors_269,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_230,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_270,
      1,
      array_kFieldTrialConfig_form_factors_270,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_20,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_229[] = {
      "V8ConcurrentInlining",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_268[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_268[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const char* const array_kFieldTrialConfig_disable_features_19[] = {
      "V8ConcurrentInlining",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_267[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_267[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_241[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_267,
      2,
      array_kFieldTrialConfig_form_factors_267,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_19,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_268,
      2,
      array_kFieldTrialConfig_form_factors_268,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_229,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_228[] = {
      "UsernameFirstFlow",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_266[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_266[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_240[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_266,
      1,
      array_kFieldTrialConfig_form_factors_266,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_228,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_227[] = {
      "UseRegistrableDomainInNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_265[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_265[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_239[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_265,
      2,
      array_kFieldTrialConfig_form_factors_265,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_227,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_226[] = {
      "UseInProgressDownloadManagerForDownloadService",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_264[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_264[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_238[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_264,
      1,
      array_kFieldTrialConfig_form_factors_264,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_226,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_92[] = {
      {
        "min_required_storage_for_update_mb",
        "500",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_263[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_263[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_237[] = {
    {
      "StorageRequired500",
      array_kFieldTrialConfig_platforms_263,
      1,
      array_kFieldTrialConfig_form_factors_263,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_92,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_18[] = {
      "SharingDeriveVapidKey",
      "SyncDeviceInfoInTransportMode",
};
const char* const array_kFieldTrialConfig_enable_features_225[] = {
      "SharingUseDeviceInfo",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_262[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_262[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_236[] = {
    {
      "UseDeviceInfoEnabled",
      array_kFieldTrialConfig_platforms_262,
      1,
      array_kFieldTrialConfig_form_factors_262,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_225,
      1,
      array_kFieldTrialConfig_disable_features_18,
      2,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_224[] = {
      "SharingDeviceExpiration",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_91[] = {
      {
        "SharingDeviceExpirationHours",
        "24",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_261[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_261[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_235[] = {
    {
      "Enabled_24",
      array_kFieldTrialConfig_platforms_261,
      1,
      array_kFieldTrialConfig_form_factors_261,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_91,
      1,
      array_kFieldTrialConfig_enable_features_224,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_17[] = {
      "UkmReportNoisedUserBirthYearAndGender",
};
const char* const array_kFieldTrialConfig_enable_features_223[] = {
      "DemographicMetricsReporting",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_260[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_260[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_234[] = {
    {
      "UMA_Enabled",
      array_kFieldTrialConfig_platforms_260,
      1,
      array_kFieldTrialConfig_form_factors_260,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_223,
      1,
      array_kFieldTrialConfig_disable_features_17,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_222[] = {
      "Ukm",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_90[] = {
      {
        "RecordSessionId",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_259[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_259[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_233[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_259,
      1,
      array_kFieldTrialConfig_form_factors_259,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_90,
      1,
      array_kFieldTrialConfig_enable_features_222,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_221[] = {
      "TrustedDOMTypes",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_258[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_258[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_232[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_258,
      2,
      array_kFieldTrialConfig_form_factors_258,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_221,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_89[] = {
      {
        "server_params",
        "smrd",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_257[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_257[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_231[] = {
    {
      "SmartRendering",
      array_kFieldTrialConfig_platforms_257,
      1,
      array_kFieldTrialConfig_form_factors_257,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_89,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_220[] = {
      "TranslateRankerEnforcement",
      "TranslateRankerQuery",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_88[] = {
      {
        "translate-ranker-model-url",
        "https://www.gstatic.com/chrome/intelligence/assist/ranker/models/translate/android/translate_ranker_model_android_20170918.pb.bin",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_256[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_256[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_230[] = {
    {
      "Enforcement20170918",
      array_kFieldTrialConfig_platforms_256,
      1,
      array_kFieldTrialConfig_form_factors_256,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_88,
      1,
      array_kFieldTrialConfig_enable_features_220,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_219[] = {
      "TranslateCompactUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_87[] = {
      {
        "translate_tab_default_text_color",
        "1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_255[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_255[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_229[] = {
    {
      "DarkerColor",
      array_kFieldTrialConfig_platforms_255,
      1,
      array_kFieldTrialConfig_form_factors_255,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_87,
      1,
      array_kFieldTrialConfig_enable_features_219,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_218[] = {
      "ThrottleDelayable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_86[] = {
      {
        "EffectiveConnectionType1",
        "3G",
      },
      {
        "MaxDelayableRequests1",
        "8",
      },
      {
        "NonDelayableWeight1",
        "3.0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_254[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_254[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_228[] = {
    {
      "MaxDelayable_3g_8_Weight3_20190215",
      array_kFieldTrialConfig_platforms_254,
      1,
      array_kFieldTrialConfig_form_factors_254,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_86,
      3,
      array_kFieldTrialConfig_enable_features_218,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_217[] = {
      "TextFragmentAnchor",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_253[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_253[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_227[] = {
    {
      "Enabled_20191216",
      array_kFieldTrialConfig_platforms_253,
      2,
      array_kFieldTrialConfig_form_factors_253,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_217,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_216[] = {
      "TabToGTSAnimation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_85[] = {
      {
        "zooming-min-memory-mb",
        "2048",
      },
      {
        "zooming-min-sdk-version",
        "23",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_252[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_252[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_226[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_252,
      1,
      array_kFieldTrialConfig_form_factors_252,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_85,
      2,
      array_kFieldTrialConfig_enable_features_216,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_215[] = {
      "IPH_TabGroupsYourTabsTogether",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_84[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:iph_tabgroups_grouped_card;comparator:==0;window:30;storage:365",
      },
      {
        "event_trigger2",
        "name:iph_tabgroups_grouped_card;comparator:<2;window:90;storage:365",
      },
      {
        "event_used",
        "name:tabgroups_dummy;comparator:==0;window:1;storage:1",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_251[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_251[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_225[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_251,
      1,
      array_kFieldTrialConfig_form_factors_251,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_84,
      5,
      array_kFieldTrialConfig_enable_features_215,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_214[] = {
      "IPH_TabGroupsTapToSeeAnotherTab",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_83[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:iph_tabgroups_strip;comparator:==0;window:30;storage:365",
      },
      {
        "event_trigger2",
        "name:iph_tabgroups_strip;comparator:<2;window:90;storage:365",
      },
      {
        "event_used",
        "name:tabgroups_dummy;comparator:==0;window:1;storage:1",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_250[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_250[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_224[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_250,
      1,
      array_kFieldTrialConfig_form_factors_250,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_83,
      5,
      array_kFieldTrialConfig_enable_features_214,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_213[] = {
      "IPH_TabGroupsQuicklyComparePages",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_82[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:iph_tabgroups_longtap;comparator:==0;window:30;storage:365",
      },
      {
        "event_trigger2",
        "name:iph_tabgroups_longtap;comparator:<2;window:90;storage:365",
      },
      {
        "event_used",
        "name:tabgroups_dummy;comparator:==0;window:1;storage:1",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_249[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_249[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_223[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_249,
      1,
      array_kFieldTrialConfig_form_factors_249,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_82,
      5,
      array_kFieldTrialConfig_enable_features_213,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_212[] = {
      "IPH_TabGroupsDragAndDrop",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_81[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:iph_tabgroups_drag_and_drop;comparator:==0;window:30;storage:365",
      },
      {
        "event_trigger2",
        "name:iph_tabgroups_drag_and_drop;comparator:<2;window:90;storage:365",
      },
      {
        "event_used",
        "name:tab_drag_and_drop_to_group;comparator:==0;window:365;storage:365",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_248[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_248[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_222[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_248,
      1,
      array_kFieldTrialConfig_form_factors_248,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_81,
      5,
      array_kFieldTrialConfig_enable_features_212,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_211[] = {
      "TabGridLayoutAndroid",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_80[] = {
      {
        "tab_grid_layout_android_new_tab",
        "NewTabVariation",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_247[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_247[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_221[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_247,
      1,
      array_kFieldTrialConfig_form_factors_247,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_80,
      1,
      array_kFieldTrialConfig_enable_features_211,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_210[] = {
      "SyncUSSPasswords",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_246[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_246[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_220[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_246,
      1,
      array_kFieldTrialConfig_form_factors_246,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_210,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_209[] = {
      "SyncUSSNigori",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_245[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_245[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_219[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_245,
      1,
      array_kFieldTrialConfig_form_factors_245,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_209,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_208[] = {
      "SyncUSSBookmarks",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_244[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_244[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_218[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_244,
      1,
      array_kFieldTrialConfig_form_factors_244,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_208,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_207[] = {
      "stop-non-timers-in-background",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_243[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_243[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_217[] = {
    {
      "Experiment",
      array_kFieldTrialConfig_platforms_243,
      1,
      array_kFieldTrialConfig_form_factors_243,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_207,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_206[] = {
      "stop-loading-in-background",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_242[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_242[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_216[] = {
    {
      "Experiment",
      array_kFieldTrialConfig_platforms_242,
      1,
      array_kFieldTrialConfig_form_factors_242,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_206,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_205[] = {
      "StaticHostQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_241[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_241[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_215[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_241,
      2,
      array_kFieldTrialConfig_form_factors_241,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_205,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_204[] = {
      "SqlSkipPreload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_240[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_240[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_214[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_240,
      1,
      array_kFieldTrialConfig_form_factors_240,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_204,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_203[] = {
      "SplitCacheByNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_239[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_239[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_213[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_239,
      2,
      array_kFieldTrialConfig_form_factors_239,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_203,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_202[] = {
      "SimpleCachePrefetchExperiment2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_79[] = {
      {
        "TrailerPrefetchHint",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_238[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_238[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_212[] = {
    {
      "Enabled0",
      array_kFieldTrialConfig_platforms_238,
      1,
      array_kFieldTrialConfig_form_factors_238,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_79,
      1,
      array_kFieldTrialConfig_enable_features_202,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_201[] = {
      "SharedClipboardUI",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_237[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_237[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_211[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_237,
      1,
      array_kFieldTrialConfig_form_factors_237,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_201,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_200[] = {
      "ServiceWorkerOnUI",
      "ServiceWorkerPrefersUnusedProcess",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_236[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_236[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_210[] = {
    {
      "Enabled_Ui_Ps3",
      array_kFieldTrialConfig_platforms_236,
      2,
      array_kFieldTrialConfig_form_factors_236,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_200,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_199[] = {
      "ServiceManagerForBackgroundPrefetch",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_235[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_235[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_209[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_235,
      1,
      array_kFieldTrialConfig_form_factors_235,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_199,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_198[] = {
      "ServiceGroupImportance",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_234[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_234[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_208[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_234,
      1,
      array_kFieldTrialConfig_form_factors_234,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_198,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_197[] = {
      "SearchEnginePromo.ExistingDevice",
      "SearchEnginePromo.NewDevice",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_233[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_233[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_207[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_233,
      1,
      array_kFieldTrialConfig_form_factors_233,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_197,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_196[] = {
      "ResamplingScrollEvents",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_78[] = {
      {
        "predictor",
        "linear_resampling",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_232[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_232[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_206[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_232,
      1,
      array_kFieldTrialConfig_form_factors_232,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_78,
      1,
      array_kFieldTrialConfig_enable_features_196,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_195[] = {
      "ScriptStreamingOnPreload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_231[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_231[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_205[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_231,
      1,
      array_kFieldTrialConfig_form_factors_231,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_195,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_194[] = {
      "CookieDeprecationMessages",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_230[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_230[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_204[] = {
    {
      "EnabledLaunch",
      array_kFieldTrialConfig_platforms_230,
      2,
      array_kFieldTrialConfig_form_factors_230,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_194,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_193[] = {
      "CookiesWithoutSameSiteMustBeSecure",
      "SameSiteByDefaultCookies",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_229[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_229[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_203[] = {
    {
      "LaxByDefaultAndNoneRequiresSecure",
      array_kFieldTrialConfig_platforms_229,
      2,
      array_kFieldTrialConfig_form_factors_229,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_193,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_192[] = {
      "SafeBrowsingUseLocalBlacklistsV2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_77[] = {
      {
        "local_blacklists_update_interval_in_secs",
        "900",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_228[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_228[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_202[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_228,
      1,
      array_kFieldTrialConfig_form_factors_228,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_77,
      1,
      array_kFieldTrialConfig_enable_features_192,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_227[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_227[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_191[] = {
      "ThreatDomDetailsTagAttributes",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_76[] = {
      {
        "tag_attribute_csv",
        "div,data-google-query-id,div,id,iframe,id",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_226[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_226[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_201[] = {
    {
      "AdIdentifiers",
      array_kFieldTrialConfig_platforms_226,
      1,
      array_kFieldTrialConfig_form_factors_226,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_76,
      1,
      array_kFieldTrialConfig_enable_features_191,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Default",
      array_kFieldTrialConfig_platforms_227,
      1,
      array_kFieldTrialConfig_form_factors_227,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_16[] = {
      "SafeBrowsingSuspiciousSiteTriggerQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_225[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_225[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_190[] = {
      "SafeBrowsingSuspiciousSiteTriggerQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_75[] = {
      {
        "suspicious_site_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_224[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_224[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_200[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_224,
      1,
      array_kFieldTrialConfig_form_factors_224,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_75,
      1,
      array_kFieldTrialConfig_enable_features_190,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_225,
      1,
      array_kFieldTrialConfig_form_factors_225,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_16,
      1,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_223[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_223[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_15[] = {
      "CanShowScoutOptIn",
      "OnlyShowScoutOptIn",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_222[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_222[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_189[] = {
      "CanShowScoutOptIn",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_221[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_221[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_199[] = {
    {
      "CanShowScoutOptInGroup2",
      array_kFieldTrialConfig_platforms_221,
      1,
      array_kFieldTrialConfig_form_factors_221,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_189,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control2",
      array_kFieldTrialConfig_platforms_222,
      1,
      array_kFieldTrialConfig_form_factors_222,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_15,
      2,
      NULL,
      NULL,
      0,
    },
    {
      "Default",
      array_kFieldTrialConfig_platforms_223,
      1,
      array_kFieldTrialConfig_form_factors_223,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_188[] = {
      "SafeBrowsingRealTimeUrlLookupEnabled",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_74[] = {
      {
        "SafeBrowsingRealTimeUrlLookupMemoryThresholdMb",
        "4096",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_220[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_220[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_198[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_220,
      1,
      array_kFieldTrialConfig_form_factors_220,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_74,
      1,
      array_kFieldTrialConfig_enable_features_188,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_187[] = {
      "SafeBrowsingSendPasswordReusePing",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_219[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_219[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_197[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_219,
      1,
      array_kFieldTrialConfig_form_factors_219,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_187,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_186[] = {
      "SafeBrowsingSendOnFocusPing",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_218[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_218[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_196[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_218,
      1,
      array_kFieldTrialConfig_form_factors_218,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_186,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_185[] = {
      "SafeBrowsingPasswordProtectionForSavedPasswords",
      "SafeBrowsingPasswordProtectionShowDomainsForSavedPasswords",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_217[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_217[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_195[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_217,
      1,
      array_kFieldTrialConfig_form_factors_217,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_185,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_184[] = {
      "SafeBrowsingCommittedInterstitials",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_216[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_216[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_194[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_216,
      1,
      array_kFieldTrialConfig_form_factors_216,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_184,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_215[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_215[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_73[] = {
      {
        "enabled",
        "true",
      },
      {
        "types_to_check",
        "0,1,3,6,7,8,9,10,11,13,14,15",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_214[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_214[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_193[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_214,
      1,
      array_kFieldTrialConfig_form_factors_214,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_73,
      2,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_215,
      1,
      array_kFieldTrialConfig_form_factors_215,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_213[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_213[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_14[] = {
      "SafeBrowsingAdSamplerTrigger",
      "SafeBrowsingTriggerThrottlerDailyQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_212[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_212[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_183[] = {
      "SafeBrowsingAdSamplerTrigger",
      "SafeBrowsingTriggerThrottlerDailyQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_72[] = {
      {
        "safe_browsing_ad_sampler_frequency_denominator",
        "1000",
      },
      {
        "trigger_type_and_quota_csv",
        "2,10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_211[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_211[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_192[] = {
    {
      "AdSampler_NormalRate",
      array_kFieldTrialConfig_platforms_211,
      1,
      array_kFieldTrialConfig_form_factors_211,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_72,
      2,
      array_kFieldTrialConfig_enable_features_183,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_212,
      1,
      array_kFieldTrialConfig_form_factors_212,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_14,
      2,
      NULL,
      NULL,
      0,
    },
    {
      "Default",
      array_kFieldTrialConfig_platforms_213,
      1,
      array_kFieldTrialConfig_form_factors_213,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_182[] = {
      "SafeBrowsingAdRedirectTrigger",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_71[] = {
      {
        "ad_redirect_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_210[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_210[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_191[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_210,
      1,
      array_kFieldTrialConfig_form_factors_210,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_71,
      1,
      array_kFieldTrialConfig_enable_features_182,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_181[] = {
      "SafeBrowsingAdPopupTrigger",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_70[] = {
      {
        "ad_popup_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_209[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_209[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_190[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_209,
      1,
      array_kFieldTrialConfig_form_factors_209,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_70,
      1,
      array_kFieldTrialConfig_enable_features_181,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_180[] = {
      "RevampedContextMenu",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_208[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_208[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_189[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_208,
      1,
      array_kFieldTrialConfig_form_factors_208,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_180,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_179[] = {
      "ResourceLoadingHints",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_207[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_207[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_188[] = {
    {
      "Enabled2",
      array_kFieldTrialConfig_platforms_207,
      1,
      array_kFieldTrialConfig_form_factors_207,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_179,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_178[] = {
      "NetworkErrorLogging",
      "Reporting",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_206[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_206[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_187[] = {
    {
      "ReportingAndNELEnabled",
      array_kFieldTrialConfig_platforms_206,
      1,
      array_kFieldTrialConfig_form_factors_206,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_178,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_205[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_205[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_69[] = {
      {
        "sendingThreshold",
        "1.0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_204[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_204[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_186[] = {
    {
      "ShowAndPossiblySend",
      array_kFieldTrialConfig_platforms_204,
      1,
      array_kFieldTrialConfig_form_factors_204,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_69,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "DontShowAndDontSend",
      array_kFieldTrialConfig_platforms_205,
      1,
      array_kFieldTrialConfig_form_factors_205,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_177[] = {
      "ReorderBookmarks",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_203[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_203[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_185[] = {
    {
      "ReorderBookmarks",
      array_kFieldTrialConfig_platforms_203,
      1,
      array_kFieldTrialConfig_form_factors_203,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_177,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_68[] = {
      {
        "wake_up_duration_ms",
        "5",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_202[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_202[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_184[] = {
    {
      "RendererSchedulerWakeUpThrottling",
      array_kFieldTrialConfig_platforms_202,
      1,
      array_kFieldTrialConfig_form_factors_202,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_68,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_201[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_201[] = {
      Study::PLATFORM_ANDROID,
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_200[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_200[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_183[] = {
    {
      "AdaBoost",
      array_kFieldTrialConfig_platforms_200,
      1,
      array_kFieldTrialConfig_form_factors_200,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_201,
      1,
      array_kFieldTrialConfig_form_factors_201,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_176[] = {
      "QuotaExpandPoolSize",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_67[] = {
      {
        "PerHostRatio",
        "0.75",
      },
      {
        "PoolSizeRatio",
        "0.8",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_199[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_199[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_182[] = {
    {
      "Enabled_Pool_Four_Fifths_Origin_ThreeQuarters_20190710",
      array_kFieldTrialConfig_platforms_199,
      1,
      array_kFieldTrialConfig_form_factors_199,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_67,
      2,
      array_kFieldTrialConfig_enable_features_176,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_175[] = {
      "QueryInOmnibox",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_198[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_198[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_181[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_198,
      1,
      array_kFieldTrialConfig_form_factors_198,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_175,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_174[] = {
      "QuicDoesNotUseFeatures",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_66[] = {
      {
        "connection_options",
        "5RTO,ACKD",
      },
      {
        "enable_quic",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_197[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_197[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_180[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_197,
      2,
      array_kFieldTrialConfig_form_factors_197,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_66,
      2,
      array_kFieldTrialConfig_enable_features_174,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_173[] = {
      "ProtoDBSharedMigration",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_65[] = {
      {
        "migrate_BudgetManager",
        "true",
      },
      {
        "migrate_CachedImageFetcherDatabase",
        "true",
      },
      {
        "migrate_DomDistillerStore",
        "true",
      },
      {
        "migrate_DownloadDB",
        "true",
      },
      {
        "migrate_DownloadService",
        "true",
      },
      {
        "migrate_FeatureEngagementTrackerAvailabilityStore",
        "true",
      },
      {
        "migrate_FeatureEngagementTrackerEventStore",
        "true",
      },
      {
        "migrate_FeedContentDatabase",
        "true",
      },
      {
        "migrate_FeedJournalDatabase",
        "true",
      },
      {
        "migrate_NTPSnippetImages",
        "true",
      },
      {
        "migrate_NTPSnippets",
        "true",
      },
      {
        "migrate_NotificationSchedulerIcons",
        "true",
      },
      {
        "migrate_NotificationSchedulerImpressions",
        "true",
      },
      {
        "migrate_NotificationSchedulerNotifications",
        "true",
      },
      {
        "migrate_PreviewsHintCacheStore",
        "true",
      },
      {
        "migrate_PrintJobDatabase",
        "true",
      },
      {
        "migrate_StrikeService",
        "true",
      },
      {
        "migrate_UsageStatsSuspension",
        "true",
      },
      {
        "migrate_UsageStatsTokenMapping",
        "true",
      },
      {
        "migrate_UsageStatsWebsiteEvent",
        "true",
      },
      {
        "migrate_VideoDecodeStatsDB",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_196[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_196[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_179[] = {
    {
      "Enabled3",
      array_kFieldTrialConfig_platforms_196,
      2,
      array_kFieldTrialConfig_form_factors_196,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_65,
      21,
      array_kFieldTrialConfig_enable_features_173,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_64[] = {
      {
        "progress-bar-animation",
        "smooth-indeterminate",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_195[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_195[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_178[] = {
    {
      "SmoothIndeterminateAnimation",
      array_kFieldTrialConfig_platforms_195,
      1,
      array_kFieldTrialConfig_form_factors_195,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_64,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_172[] = {
      "ProfileSyncServiceUsesThreadPool",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_194[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_194[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_177[] = {
    {
      "Enabled_20191112",
      array_kFieldTrialConfig_platforms_194,
      1,
      array_kFieldTrialConfig_form_factors_194,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_172,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_171[] = {
      "ProactivelyThrottleLowPriorityRequests",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_63[] = {
      {
        "http_rtt_multiplier_for_proactive_throttling_2G",
        "1.0",
      },
      {
        "http_rtt_multiplier_for_proactive_throttling_3G",
        "1.0",
      },
      {
        "http_rtt_multiplier_for_proactive_throttling_Slow-2G",
        "1.0",
      },
      {
        "queued_requests_dispatch_periodicity_ms",
        "5",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_193[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_193[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_176[] = {
    {
      "Enabled_20190722",
      array_kFieldTrialConfig_platforms_193,
      1,
      array_kFieldTrialConfig_form_factors_193,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_63,
      4,
      array_kFieldTrialConfig_enable_features_171,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_170[] = {
      "ProactivelySwapBrowsingInstance",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_192[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_192[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_175[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_192,
      1,
      array_kFieldTrialConfig_form_factors_192,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_170,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_169[] = {
      "PrivacySettingsRedesign",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_191[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_191[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_174[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_191,
      2,
      array_kFieldTrialConfig_form_factors_191,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_169,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_168[] = {
      "PrioritizedSimpleCacheTasks",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_190[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_190[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_173[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_190,
      1,
      array_kFieldTrialConfig_form_factors_190,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_168,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_167[] = {
      "NoScriptPreviews",
      "OptimizationHints",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_189[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_189[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_172[] = {
    {
      "NoScriptWithWhiteList2",
      array_kFieldTrialConfig_platforms_189,
      1,
      array_kFieldTrialConfig_form_factors_189,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_167,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_166[] = {
      "AndroidOmniboxPreviewsBadge",
      "LitePageServerPreviews",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_62[] = {
      {
        "availability",
        "any",
      },
      {
        "blacklisted_path_suffixes",
        ".apk,.avi,.gif,.gifv,.jpeg,.jpg,.mp3,.mp4,.mpeg,.pdf,.png,.webm,.webp",
      },
      {
        "event_preview_loaded",
        "name:preview_page_load;comparator:>=1;window:90;storage:360",
      },
      {
        "event_trigger",
        "name:previews_verbose_iph_triggered;comparator:<2;window:90;storage:360",
      },
      {
        "event_used",
        "name:previews_verbose_status_opened;comparator:==0;window:90;storage:360",
      },
      {
        "override_pagehints",
        "true",
      },
      {
        "session_rate",
        "==0",
      },
      {
        "tracking_only",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_188[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_188[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_171[] = {
    {
      "Enabled_OverridePH_20190221",
      array_kFieldTrialConfig_platforms_188,
      1,
      array_kFieldTrialConfig_form_factors_188,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_62,
      8,
      array_kFieldTrialConfig_enable_features_166,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_165[] = {
      "PrerenderFallbackToPreconnect",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_187[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_187[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_170[] = {
    {
      "Enabled_20190410",
      array_kFieldTrialConfig_platforms_187,
      1,
      array_kFieldTrialConfig_form_factors_187,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_165,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_164[] = {
      "PreloadMetadataLazyLoad",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_186[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_186[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_169[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_186,
      1,
      array_kFieldTrialConfig_form_factors_186,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_164,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_163[] = {
      "GWSPrefetchHoldback",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_185[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_185[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_168[] = {
    {
      "Enabled_threshold_1_holdback_20190521",
      array_kFieldTrialConfig_platforms_185,
      1,
      array_kFieldTrialConfig_form_factors_185,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_163,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_162[] = {
      "PreconnectOnDidFinishNavigation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_61[] = {
      {
        "delay_after_commit_in_ms",
        "3000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_184[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_184[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_167[] = {
    {
      "Enabled_3_seconds",
      array_kFieldTrialConfig_platforms_184,
      1,
      array_kFieldTrialConfig_form_factors_184,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_61,
      1,
      array_kFieldTrialConfig_enable_features_162,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_60[] = {
      {
        "config_url",
        "https://www.gstatic.com/chrome/wifiprefetch/precache_config_g20",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_183[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_183[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_166[] = {
    {
      "EnabledCGRUV20b",
      array_kFieldTrialConfig_platforms_183,
      1,
      array_kFieldTrialConfig_form_factors_183,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_60,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_161[] = {
      "PhysicalWeb",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_182[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_182[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_165[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_182,
      1,
      array_kFieldTrialConfig_form_factors_182,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_161,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_160[] = {
      "pwa-persistent-notification",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_181[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_181[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_164[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_181,
      1,
      array_kFieldTrialConfig_form_factors_181,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_160,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_159[] = {
      "PersistentHistograms",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_59[] = {
      {
        "send_unreported_metrics",
        "yes",
      },
      {
        "storage",
        "MappedFile",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_180[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_180[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_163[] = {
    {
      "EnabledOnDisk5",
      array_kFieldTrialConfig_platforms_180,
      1,
      array_kFieldTrialConfig_form_factors_180,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_59,
      2,
      array_kFieldTrialConfig_enable_features_159,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_158[] = {
      "ModalPermissionPrompts",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_179[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_179[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_162[] = {
    {
      "ModalToggleEnabled",
      array_kFieldTrialConfig_platforms_179,
      1,
      array_kFieldTrialConfig_form_factors_179,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_158,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_157[] = {
      "BlockPromptsIfDismissedOften",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_178[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_178[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_161[] = {
    {
      "BlockPromptsEnabled",
      array_kFieldTrialConfig_platforms_178,
      1,
      array_kFieldTrialConfig_form_factors_178,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_157,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_156[] = {
      "AlwaysAllowJustInTimePaymentApp",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_177[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_177[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_160[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_177,
      1,
      array_kFieldTrialConfig_form_factors_177,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_156,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_155[] = {
      "PauseBrowserInitiatedHeavyTrafficForP2P",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_58[] = {
      {
        "throttled_traffic_annotation_tags",
        "727528,727478",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_176[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_176[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_159[] = {
    {
      "Enabled_20190712",
      array_kFieldTrialConfig_platforms_176,
      1,
      array_kFieldTrialConfig_form_factors_176,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_58,
      1,
      array_kFieldTrialConfig_enable_features_155,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_154[] = {
      "PassiveMixedContentWarning",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_175[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_175[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_158[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_175,
      1,
      array_kFieldTrialConfig_form_factors_175,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_154,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_153[] = {
      "AutoupgradeMixedContent",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_57[] = {
      {
        "mode",
        "no-images",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_174[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_174[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_157[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_174,
      1,
      array_kFieldTrialConfig_form_factors_174,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_57,
      1,
      array_kFieldTrialConfig_enable_features_153,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_152[] = {
      "PassiveEventListenersDueToFling",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_173[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_173[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_156[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_173,
      1,
      array_kFieldTrialConfig_form_factors_173,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_152,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_151[] = {
      "PassiveDocumentWheelEventListeners",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_172[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_172[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_155[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_172,
      1,
      array_kFieldTrialConfig_form_factors_172,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_151,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_150[] = {
      "PassiveDocumentEventListeners",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_171[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_171[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_154[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_171,
      1,
      array_kFieldTrialConfig_form_factors_171,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_150,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_149[] = {
      "PartitionConnectionsByNetworkIsolationKey",
      "PartitionHttpServerPropertiesByNetworkIsolationKey",
      "PartitionSSLSessionsByNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_170[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_170[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_153[] = {
    {
      "PartitionConnectionsAndSSLSessionsAndQuic",
      array_kFieldTrialConfig_platforms_170,
      1,
      array_kFieldTrialConfig_form_factors_170,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_149,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_148[] = {
      "ParallelDownloading",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_56[] = {
      {
        "min_slice_size",
        "1365333",
      },
      {
        "parallel_request_delay",
        "0",
      },
      {
        "parallel_request_remaining_time",
        "2",
      },
      {
        "request_count",
        "3",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_169[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_169[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_152[] = {
    {
      "ThreeRequests_Enabled",
      array_kFieldTrialConfig_platforms_169,
      1,
      array_kFieldTrialConfig_form_factors_169,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_56,
      4,
      array_kFieldTrialConfig_enable_features_148,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_147[] = {
      "UseParallelRequestsForQUIC",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_168[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_168[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_146[] = {
      "UseParallelRequestsForHTTP2",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_167[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_167[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_151[] = {
    {
      "EnableHTTP2",
      array_kFieldTrialConfig_platforms_167,
      1,
      array_kFieldTrialConfig_form_factors_167,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_146,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnableQuic",
      array_kFieldTrialConfig_platforms_168,
      1,
      array_kFieldTrialConfig_form_factors_168,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_147,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_145[] = {
      "PaintHolding",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_166[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_166[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_150[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_166,
      1,
      array_kFieldTrialConfig_form_factors_166,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_145,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_144[] = {
      "ClickToOpenPDFPlaceholder",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_165[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_165[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_149[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_165,
      1,
      array_kFieldTrialConfig_form_factors_165,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_144,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_143[] = {
      "OverflowIconsForMediaControls",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_164[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_164[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_148[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_164,
      1,
      array_kFieldTrialConfig_form_factors_164,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_143,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_142[] = {
      "OutOfBlinkCors",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_55[] = {
      {
        "extra-safelisted-request-headers",
        "x-googapps-allowed-domains,youtube-restrict",
      },
      {
        "extra-safelisted-request-headers-for-enterprise",
        "x-googapps-allowed-domains,youtube-restrict",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_163[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_163[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_147[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_163,
      2,
      array_kFieldTrialConfig_form_factors_163,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_55,
      2,
      array_kFieldTrialConfig_enable_features_142,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_141[] = {
      "OptimizationTargetPrediction",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_54[] = {
      {
        "fetch_random_max_delay_secs",
        "60",
      },
      {
        "max_effective_connection_type_for_navigation_hints_fetch",
        "4G",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_162[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_162[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_146[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_162,
      1,
      array_kFieldTrialConfig_form_factors_162,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_54,
      2,
      array_kFieldTrialConfig_enable_features_141,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_140[] = {
      "OmniboxSearchEngineLogo",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_53[] = {
      {
        "rounded_edges",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_161[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_161[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_145[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_161,
      1,
      array_kFieldTrialConfig_form_factors_161,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_53,
      1,
      array_kFieldTrialConfig_enable_features_140,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_139[] = {
      "OmniboxPreserveDefaultMatchAgainstAsyncUpdate",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_160[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_160[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_144[] = {
    {
      "Beta_Enabled",
      array_kFieldTrialConfig_platforms_160,
      1,
      array_kFieldTrialConfig_form_factors_160,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_139,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_138[] = {
      "OmniboxOnDeviceHeadProvider",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_159[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_159[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_143[] = {
    {
      "Beta_OnDeviceHeadSuggest_Enabled",
      array_kFieldTrialConfig_platforms_159,
      1,
      array_kFieldTrialConfig_form_factors_159,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_138,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_137[] = {
      "OmniboxDisplayTitleForCurrentUrl",
      "OmniboxUIExperimentHideSteadyStateUrlScheme",
      "OmniboxUIExperimentHideSteadyStateUrlTrivialSubdomains",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_158[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_158[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_142[] = {
    {
      "AndroidExperiments",
      array_kFieldTrialConfig_platforms_158,
      1,
      array_kFieldTrialConfig_form_factors_158,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_137,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_136[] = {
      "OmniboxAssistantVoiceSearch",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_157[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_157[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_141[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_157,
      1,
      array_kFieldTrialConfig_form_factors_157,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_136,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_135[] = {
      "OfflinePagesSharing",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_156[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_156[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_140[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_156,
      1,
      array_kFieldTrialConfig_form_factors_156,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_135,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_134[] = {
      "KeepPrefetchedContentSuggestions",
      "OfflinePagesPrefetching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_155[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_155[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_139[] = {
    {
      "Enabled_Holdback",
      array_kFieldTrialConfig_platforms_155,
      1,
      array_kFieldTrialConfig_form_factors_155,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_134,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_133[] = {
      "OfflinePagesInDownloadHomeOpenInCct",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_154[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_154[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_138[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_154,
      1,
      array_kFieldTrialConfig_form_factors_154,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_133,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_132[] = {
      "OfflinePagesShowAlternateDinoPage",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_153[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_153[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_137[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_153,
      1,
      array_kFieldTrialConfig_form_factors_153,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_132,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_131[] = {
      "OfflinePagesDescriptivePendingStatus",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_152[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_152[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_136[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_152,
      1,
      array_kFieldTrialConfig_form_factors_152,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_131,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_130[] = {
      "OfflinePagesCTV2",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_151[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_151[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_135[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_151,
      1,
      array_kFieldTrialConfig_form_factors_151,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_130,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_129[] = {
      "OfflinePagesAsyncDownload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_150[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_150[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_134[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_150,
      1,
      array_kFieldTrialConfig_form_factors_150,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_129,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_128[] = {
      "OfflineIndicator",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_52[] = {
      {
        "bottom_offline_indicator",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_149[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_149[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_127[] = {
      "OfflineIndicator",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_51[] = {
      {
        "bottom_offline_indicator",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_148[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_148[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_133[] = {
    {
      "EnabledBottom",
      array_kFieldTrialConfig_platforms_148,
      1,
      array_kFieldTrialConfig_form_factors_148,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_51,
      1,
      array_kFieldTrialConfig_enable_features_127,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledTop",
      array_kFieldTrialConfig_platforms_149,
      1,
      array_kFieldTrialConfig_form_factors_149,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_52,
      1,
      array_kFieldTrialConfig_enable_features_128,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_126[] = {
      "AutofillUpstream",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_147[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_147[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_132[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_147,
      1,
      array_kFieldTrialConfig_form_factors_147,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_126,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_125[] = {
      "OmniboxNewAnswerLayout",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_146[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_146[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_131[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_146,
      1,
      array_kFieldTrialConfig_form_factors_146,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_125,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_124[] = {
      "NavigationPredictorMultiplePrerenders",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_50[] = {
      {
        "prerender_limit",
        "5",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_145[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_145[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_130[] = {
    {
      "Enabled_Limit_5",
      array_kFieldTrialConfig_platforms_145,
      1,
      array_kFieldTrialConfig_form_factors_145,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_50,
      1,
      array_kFieldTrialConfig_enable_features_124,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_123[] = {
      "NavigationPredictor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_49[] = {
      {
        "area_rank_scale",
        "0",
      },
      {
        "clickable_space_scale",
        "1040",
      },
      {
        "contains_image_scale",
        "787000",
      },
      {
        "iframe_link_total_scale",
        "0",
      },
      {
        "image_link_total_scale",
        "-11600",
      },
      {
        "increment_link_total_scale",
        "36100",
      },
      {
        "is_in_iframe_scale",
        "0",
      },
      {
        "is_same_host_scale",
        "918000",
      },
      {
        "is_url_incremented_scale",
        "4790000",
      },
      {
        "link_total_scale",
        "-19700",
      },
      {
        "median_link_location_scale",
        "-3",
      },
      {
        "normalize_scores",
        "false",
      },
      {
        "prefetch_after_preconnect",
        "true",
      },
      {
        "prefetch_url_score_threshold",
        "2250000",
      },
      {
        "ratio_area_scale",
        "13000",
      },
      {
        "ratio_distance_root_top_scale",
        "-15",
      },
      {
        "same_origin_link_total_scale",
        "3110",
      },
      {
        "viewport_height_scale",
        "-50",
      },
      {
        "viewport_width_scale",
        "76",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_144[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_144[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_129[] = {
    {
      "Enabled_Logistic_Precision_15_M79_20191029",
      array_kFieldTrialConfig_platforms_144,
      1,
      array_kFieldTrialConfig_form_factors_144,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_49,
      19,
      array_kFieldTrialConfig_enable_features_123,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_48[] = {
      {
        "version",
        "5_shortname-control",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_143[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_143[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_47[] = {
      {
        "version",
        "5_shortname",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_142[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_142[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_13[] = {
      "UsePopularSitesSuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_141[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_141[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_122[] = {
      "UsePopularSitesSuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_140[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_140[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_128[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_140,
      1,
      array_kFieldTrialConfig_form_factors_140,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_122,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_141,
      1,
      array_kFieldTrialConfig_form_factors_141,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_13,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledShortNamesHoldbackControl",
      array_kFieldTrialConfig_platforms_142,
      1,
      array_kFieldTrialConfig_form_factors_142,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_47,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledShortNamesHoldback",
      array_kFieldTrialConfig_platforms_143,
      1,
      array_kFieldTrialConfig_form_factors_143,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_48,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_121[] = {
      "NTPLaunchAfterInactivity",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_46[] = {
      {
        "delay_in_mins",
        "60",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_139[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_139[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_127[] = {
    {
      "OneHourDelay",
      array_kFieldTrialConfig_platforms_139,
      1,
      array_kFieldTrialConfig_form_factors_139,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_46,
      1,
      array_kFieldTrialConfig_enable_features_121,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_120[] = {
      "UseMultiloginEndpoint",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_138[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_138[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_126[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_138,
      1,
      array_kFieldTrialConfig_form_factors_138,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_120,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_12[] = {
      "MergeBlockingNonBlockingPools",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_137[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_137[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_125[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_137,
      1,
      array_kFieldTrialConfig_form_factors_137,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_12,
      1,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_136[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_136[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_124[] = {
    {
      "DBWindow5000Frames_20190225",
      array_kFieldTrialConfig_platforms_136,
      1,
      array_kFieldTrialConfig_form_factors_136,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_119[] = {
      "LsdPermissionPrompt",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_135[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_135[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_123[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_135,
      1,
      array_kFieldTrialConfig_form_factors_135,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_119,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_118[] = {
      "LowerJavaScriptPriorityWhenForceDeferred",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_134[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_134[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_122[] = {
    {
      "Enabled_20190905",
      array_kFieldTrialConfig_platforms_134,
      1,
      array_kFieldTrialConfig_form_factors_134,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_118,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_117[] = {
      "LowPriorityIframes",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_45[] = {
      {
        "max_effective_connection_type_threshold",
        "4G",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_133[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_133[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_121[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_133,
      1,
      array_kFieldTrialConfig_form_factors_133,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_45,
      1,
      array_kFieldTrialConfig_enable_features_117,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_116[] = {
      "LegacyTLSWarnings",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_132[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_132[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_120[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_132,
      1,
      array_kFieldTrialConfig_form_factors_132,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_116,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_115[] = {
      "LegacySymantecPKI",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_131[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_131[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_119[] = {
    {
      "Enabled_20181012",
      array_kFieldTrialConfig_platforms_131,
      1,
      array_kFieldTrialConfig_form_factors_131,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_115,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_114[] = {
      "IPH_KeyboardAccessoryPaymentFilling",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_44[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:keyboard_accessory_payment_filling_iph_trigger;comparator:<1;window:90;storage:360",
      },
      {
        "event_used",
        "name:keyboard_accessory_payment_suggestion_accepted;comparator:<2;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_130[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_130[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_118[] = {
    {
      "Payment_IPH_Enabled",
      array_kFieldTrialConfig_platforms_130,
      1,
      array_kFieldTrialConfig_form_factors_130,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_44,
      4,
      array_kFieldTrialConfig_enable_features_114,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_113[] = {
      "IPH_KeyboardAccessoryPasswordFilling",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_43[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:keyboard_accessory_password_filling_iph_trigger;comparator:<1;window:90;storage:360",
      },
      {
        "event_used",
        "name:keyboard_accessory_password_suggestion_accepted;comparator:<2;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_129[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_129[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_117[] = {
    {
      "Password_IPH_Enabled",
      array_kFieldTrialConfig_platforms_129,
      1,
      array_kFieldTrialConfig_form_factors_129,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_43,
      4,
      array_kFieldTrialConfig_enable_features_113,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_112[] = {
      "IPH_KeyboardAccessoryAddressFilling",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_42[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:keyboard_accessory_address_filling_iph_trigger;comparator:<1;window:90;storage:360",
      },
      {
        "event_used",
        "name:keyboard_accessory_address_suggestion_accepted;comparator:<2;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_128[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_128[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_116[] = {
    {
      "Address_IPH_Enabled",
      array_kFieldTrialConfig_platforms_128,
      1,
      array_kFieldTrialConfig_form_factors_128,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_42,
      4,
      array_kFieldTrialConfig_enable_features_112,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_111[] = {
      "SetLowPriorityForBeacon",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_127[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_127[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_115[] = {
    {
      "Enabled_20191107",
      array_kFieldTrialConfig_platforms_127,
      2,
      array_kFieldTrialConfig_form_factors_127,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_111,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_110[] = {
      "site-isolation-for-password-sites",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_126[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_126[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_114[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_126,
      1,
      array_kFieldTrialConfig_form_factors_126,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_110,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_125[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_125[] = {
      Study::PLATFORM_ANDROID,
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_124[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_124[] = {
      Study::PLATFORM_ANDROID,
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_123[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_123[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_113[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_123,
      1,
      array_kFieldTrialConfig_form_factors_123,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_124,
      1,
      array_kFieldTrialConfig_form_factors_124,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_125,
      1,
      array_kFieldTrialConfig_form_factors_125,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_109[] = {
      "InterestFeedContentSuggestions",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_41[] = {
      {
        "feed_ui_enabled",
        "true",
      },
      {
        "init_feed_after_startup",
        "false",
      },
      {
        "snippets_enabled",
        "true",
      },
      {
        "spinner_delay",
        "500",
      },
      {
        "spinner_minimum_show_time",
        "0",
      },
      {
        "storage_miss_threshold",
        "100",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_122[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_122[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_112[] = {
    {
      "EnabledLargerImagesAndSnippets",
      array_kFieldTrialConfig_platforms_122,
      1,
      array_kFieldTrialConfig_form_factors_122,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_41,
      6,
      array_kFieldTrialConfig_enable_features_109,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_121[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_121[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_111[] = {
    {
      "InstantAppsEnabled",
      array_kFieldTrialConfig_platforms_121,
      1,
      array_kFieldTrialConfig_form_factors_121,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_11[] = {
      "HighPriorityDatabaseTaskType",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_120[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_120[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_108[] = {
      "HighPriorityDatabaseTaskType",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_119[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_119[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_110[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_119,
      1,
      array_kFieldTrialConfig_form_factors_119,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_108,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_120,
      1,
      array_kFieldTrialConfig_form_factors_120,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_11,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_107[] = {
      "IncognitoDynamicQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_40[] = {
      {
        "IncognitoQuotaRatioLowerBound",
        "0.1",
      },
      {
        "IncognitoQuotaRatioUpperBound",
        "0.2",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_118[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_118[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_109[] = {
    {
      "WideRange",
      array_kFieldTrialConfig_platforms_118,
      1,
      array_kFieldTrialConfig_form_factors_118,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_40,
      2,
      array_kFieldTrialConfig_enable_features_107,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_106[] = {
      "IPH_IdentityDisc",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_39[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:iph_identity_disc_triggered;comparator:<1;window:360;storage:360",
      },
      {
        "event_used",
        "name:identity_disc_used;comparator:<1;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_117[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_117[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_108[] = {
    {
      "IdentityDiscIPH",
      array_kFieldTrialConfig_platforms_117,
      1,
      array_kFieldTrialConfig_form_factors_117,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_39,
      4,
      array_kFieldTrialConfig_enable_features_106,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_105[] = {
      "IDBTombstoneDeletion",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_116[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_116[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_107[] = {
    {
      "TombstoneDeletion",
      array_kFieldTrialConfig_platforms_116,
      1,
      array_kFieldTrialConfig_form_factors_116,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_105,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_104[] = {
      "HeapProfilerReporting",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_38[] = {
      {
        "sampling-rate",
        "1000000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_115[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_115[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_106[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_115,
      1,
      array_kFieldTrialConfig_form_factors_115,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_38,
      1,
      array_kFieldTrialConfig_enable_features_104,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_103[] = {
      "HarfBuzzPdfSubsetter",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_114[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_114[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_105[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_114,
      2,
      array_kFieldTrialConfig_form_factors_114,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_103,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_102[] = {
      "MarkHttpAs",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_37[] = {
      {
        "treatment",
        "danger-warning",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_113[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_113[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_104[] = {
    {
      "enabled",
      array_kFieldTrialConfig_platforms_113,
      1,
      array_kFieldTrialConfig_form_factors_113,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_37,
      1,
      array_kFieldTrialConfig_enable_features_102,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_101[] = {
      "GwpAsanMalloc",
      "GwpAsanPartitionAlloc",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_36[] = {
      {
        "AllocationSamplingRange",
        "16",
      },
      {
        "MaxAllocations",
        "70",
      },
      {
        "MaxMetadata",
        "255",
      },
      {
        "ProcessSamplingBoost2",
        "10",
      },
      {
        "ProcessSamplingProbability",
        "0.015",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_112[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_112[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_103[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_112,
      2,
      array_kFieldTrialConfig_form_factors_112,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_36,
      5,
      array_kFieldTrialConfig_enable_features_101,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_100[] = {
      "GpuWatchdogV2",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_111[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_111[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_102[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_111,
      1,
      array_kFieldTrialConfig_form_factors_111,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_100,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_99[] = {
      "GpuScheduler",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_110[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_110[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_101[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_110,
      1,
      array_kFieldTrialConfig_form_factors_110,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_99,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_10[] = {
      "EnableGpuRasterizationViewportRestriction",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_109[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_109[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_100[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_109,
      2,
      array_kFieldTrialConfig_form_factors_109,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_10,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_98[] = {
      "OverscrollHistoryNavigation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_35[] = {
      {
        "overscroll_history_navigation_bottom_sheet",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_108[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_108[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_99[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_108,
      1,
      array_kFieldTrialConfig_form_factors_108,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_35,
      1,
      array_kFieldTrialConfig_enable_features_98,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_97[] = {
      "GamepadPollingInterval",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_34[] = {
      {
        "interval-ms",
        "4",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_107[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_107[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_98[] = {
    {
      "EnabledGamepadPolling250Hz",
      array_kFieldTrialConfig_platforms_107,
      2,
      array_kFieldTrialConfig_form_factors_107,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_34,
      1,
      array_kFieldTrialConfig_enable_features_97,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_96[] = {
      "freeze-background-tab-on-network-idle",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_33[] = {
      {
        "DelayForBackgroundAndNetworkIdleTabFreezingMills",
        "180000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_106[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_106[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_95[] = {
      "freeze-background-tab-on-network-idle",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_32[] = {
      {
        "DelayForBackgroundAndNetworkIdleTabFreezingMills",
        "60000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_105[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_105[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_97[] = {
    {
      "enable_1min",
      array_kFieldTrialConfig_platforms_105,
      1,
      array_kFieldTrialConfig_form_factors_105,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_32,
      1,
      array_kFieldTrialConfig_enable_features_95,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "enable_3min",
      array_kFieldTrialConfig_platforms_106,
      1,
      array_kFieldTrialConfig_form_factors_106,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_33,
      1,
      array_kFieldTrialConfig_enable_features_96,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_94[] = {
      "ForbidSyncXHRInPageDismissal",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_104[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_104[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_96[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_104,
      1,
      array_kFieldTrialConfig_form_factors_104,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_94,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_93[] = {
      "FontSrcLocalMatching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_103[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_103[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_95[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_103,
      2,
      array_kFieldTrialConfig_form_factors_103,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_93,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_92[] = {
      "FilterAdsOnAbusiveSites",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_102[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_102[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_94[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_102,
      1,
      array_kFieldTrialConfig_form_factors_102,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_92,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_91[] = {
      "FCMInvalidations",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_101[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_101[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_93[] = {
    {
      "Enabled_FCMInvalidations_20190507",
      array_kFieldTrialConfig_platforms_101,
      2,
      array_kFieldTrialConfig_form_factors_101,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_91,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_90[] = {
      "ExploreSites",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_31[] = {
      {
        "denseVariation",
        "titleBottom",
      },
      {
        "exp",
        "games-top",
      },
      {
        "mostLikelyVariation",
        "groupedIcon",
      },
      {
        "variation",
        "mostLikelyTile",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_100[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_100[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_92[] = {
    {
      "WithDenseBottom",
      array_kFieldTrialConfig_platforms_100,
      1,
      array_kFieldTrialConfig_form_factors_100,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_31,
      4,
      array_kFieldTrialConfig_enable_features_90,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_89[] = {
      "ExpectCTReporting",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_99[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_99[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_91[] = {
    {
      "ExpectCTReportingEnabled",
      array_kFieldTrialConfig_platforms_99,
      1,
      array_kFieldTrialConfig_form_factors_99,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_89,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_88[] = {
      "ScrollToExpandPaymentHandler",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_98[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_98[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_90[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_98,
      1,
      array_kFieldTrialConfig_form_factors_98,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_88,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_87[] = {
      "EphemeralTabUsingBottomSheet",
      "IPH_EphemeralTab",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_30[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:ephemeral_tab_triggered;comparator:<2;window:90;storage:90",
      },
      {
        "event_used",
        "name:ephemeral_tab_used;comparator:==0;window:90;storage:90",
      },
      {
        "session_rate",
        "any",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_97[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_97[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_89[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_97,
      1,
      array_kFieldTrialConfig_form_factors_97,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_30,
      4,
      array_kFieldTrialConfig_enable_features_87,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_86[] = {
      "SafetyTip",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_29[] = {
      {
        "editdistance",
        "false",
      },
      {
        "editdistance_siteengagement",
        "true",
      },
      {
        "topsites",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_96[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_96[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_88[] = {
    {
      "UIEnabled",
      array_kFieldTrialConfig_platforms_96,
      1,
      array_kFieldTrialConfig_form_factors_96,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_29,
      3,
      array_kFieldTrialConfig_enable_features_86,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_85[] = {
      "EnableHistoryFaviconsGoogleServerQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_95[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_95[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_87[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_95,
      2,
      array_kFieldTrialConfig_form_factors_95,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_85,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_84[] = {
      "DynamicExpectCT",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_94[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_94[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_86[] = {
    {
      "DynamicExpectCTEnabled",
      array_kFieldTrialConfig_platforms_94,
      1,
      array_kFieldTrialConfig_form_factors_94,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_84,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_83[] = {
      "DownloadsUi",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_93[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_93[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_85[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_93,
      1,
      array_kFieldTrialConfig_form_factors_93,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_83,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_82[] = {
      "DownloadsLocationChange",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_92[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_92[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_84[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_92,
      1,
      array_kFieldTrialConfig_form_factors_92,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_82,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_81[] = {
      "DownloadsAutoResumptionNative",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_91[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_91[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_83[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_91,
      1,
      array_kFieldTrialConfig_form_factors_91,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_81,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_80[] = {
      "ServiceManagerForDownload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_90[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_90[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_82[] = {
    {
      "Enabled_20191111",
      array_kFieldTrialConfig_platforms_90,
      1,
      array_kFieldTrialConfig_form_factors_90,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_80,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_79[] = {
      "AllowDownloadResumptionWithoutStrongValidators",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_28[] = {
      {
        "download_validation_length",
        "1024",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_89[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_89[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_81[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_89,
      1,
      array_kFieldTrialConfig_form_factors_89,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_28,
      1,
      array_kFieldTrialConfig_enable_features_79,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_78[] = {
      "DownloadRename",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_88[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_88[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_80[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_88,
      1,
      array_kFieldTrialConfig_form_factors_88,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_78,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_77[] = {
      "DownloadProgressInfoBar",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_27[] = {
      {
        "speeding_up_message_enabled",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_87[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_87[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_79[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_87,
      1,
      array_kFieldTrialConfig_form_factors_87,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_27,
      1,
      array_kFieldTrialConfig_enable_features_77,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_76[] = {
      "UseDownloadOfflineContentProvider",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_86[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_86[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_78[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_86,
      1,
      array_kFieldTrialConfig_form_factors_86,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_76,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_75[] = {
      "DownloadHomeV2",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_85[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_85[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_77[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_85,
      1,
      array_kFieldTrialConfig_form_factors_85,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_75,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_26[] = {
      {
        "show_more_button",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_84[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_84[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_76[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_84,
      1,
      array_kFieldTrialConfig_form_factors_84,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_26,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_74[] = {
      "DnsOverHttps",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_83[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_83[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_75[] = {
    {
      "Enabled_crbug1006105",
      array_kFieldTrialConfig_platforms_83,
      1,
      array_kFieldTrialConfig_form_factors_83,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_74,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_73[] = {
      "DirectActions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_82[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_82[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_74[] = {
    {
      "DirectActions",
      array_kFieldTrialConfig_platforms_82,
      1,
      array_kFieldTrialConfig_form_factors_82,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_73,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_9[] = {
      "FtpProtocol",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_81[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_81[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_73[] = {
    {
      "WithoutFtpSupport",
      array_kFieldTrialConfig_platforms_81,
      2,
      array_kFieldTrialConfig_form_factors_81,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_9,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_72[] = {
      "DefaultEnableOopRasterization",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_80[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_80[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_72[] = {
    {
      "DefaultEnableOopRasterization",
      array_kFieldTrialConfig_platforms_80,
      2,
      array_kFieldTrialConfig_form_factors_80,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_72,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_71[] = {
      "DecodeJpeg420ImagesToYUV",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_79[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_79[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_71[] = {
    {
      "Experiment",
      array_kFieldTrialConfig_platforms_79,
      2,
      array_kFieldTrialConfig_form_factors_79,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_71,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_70[] = {
      "DataReductionProxyLowMemoryDevicePromo",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_78[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_78[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_70[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_78,
      1,
      array_kFieldTrialConfig_form_factors_78,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_70,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_77[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_77[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_69[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_77,
      1,
      array_kFieldTrialConfig_form_factors_77,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_69[] = {
      "DataReductionProxyBlockOnBadGatewayResponse",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_76[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_76[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_68[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_76,
      1,
      array_kFieldTrialConfig_form_factors_76,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_69,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_68[] = {
      "IPH_DataSaverMilestonePromo",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_25[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:data_saver_milestone_promo_iph_would_have_triggered;comparator:<2;window:90;storage:360",
      },
      {
        "event_used",
        "name:data_saver_milestone_promo;comparator:<2;window:90;storage:360",
      },
      {
        "session_rate",
        "==0",
      },
      {
        "x_milestone_promo_data_savings_in_megabytes",
        "1024;100",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_75[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_75[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_67[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_75,
      1,
      array_kFieldTrialConfig_form_factors_75,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_25,
      5,
      array_kFieldTrialConfig_enable_features_68,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_67[] = {
      "CopylessPaste",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_74[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_74[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_66[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_74,
      1,
      array_kFieldTrialConfig_form_factors_74,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_67,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_66[] = {
      "ContextualSearchDefinitions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_73[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_73[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_65[] = {
    {
      "ContextualSearchDefinitions",
      array_kFieldTrialConfig_platforms_73,
      1,
      array_kFieldTrialConfig_form_factors_73,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_66,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_65[] = {
      "ContextualSearchMlTapSuppression",
      "ContextualSearchRankerQuery",
      "ContextualSearchSecondTap",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_24[] = {
      {
        "contextual-search-ranker-model-url",
        "https://www.gstatic.com/chrome/intelligence/assist/ranker/models/contextual_search/test_ranker_model_20171109_short_words_v2.pb.bin",
      },
      {
        "enable_bar_overlap_suppression",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_72[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_72[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_64[] = {
    {
      "SuppressionExperiment",
      array_kFieldTrialConfig_platforms_72,
      1,
      array_kFieldTrialConfig_form_factors_72,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_24,
      2,
      array_kFieldTrialConfig_enable_features_65,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_64[] = {
      "ContextMenuSearchWithGoogleLens",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_23[] = {
      {
        "minAgsaVersionName",
        "10.65",
      },
      {
        "useSearchByImageText",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_71[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_71[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_63[] = {
    {
      "ContextMenuSearchWithGoogleLensActivateSearchByImageTextDisabled",
      array_kFieldTrialConfig_platforms_71,
      1,
      array_kFieldTrialConfig_form_factors_71,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_23,
      2,
      array_kFieldTrialConfig_enable_features_64,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_63[] = {
      "ContentIndexingNTP",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_70[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_70[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_62[] = {
    {
      "ContentIndexingNTP",
      array_kFieldTrialConfig_platforms_70,
      1,
      array_kFieldTrialConfig_form_factors_70,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_63,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_62[] = {
      "ContentIndexingDownloadHome",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_69[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_69[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_61[] = {
    {
      "ContentIndexingDownloadHome",
      array_kFieldTrialConfig_platforms_69,
      1,
      array_kFieldTrialConfig_form_factors_69,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_62,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_61[] = {
      "ContentCapture",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_22[] = {
      {
        "task_long_delay_in_milliseconds",
        "5000",
      },
      {
        "task_short_delay_in_milliseconds",
        "500",
      },
      {
        "use_node_id",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_68[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_68[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_60[] = {
    {
      "ContentCaptureUseTextHolder",
      array_kFieldTrialConfig_platforms_68,
      2,
      array_kFieldTrialConfig_form_factors_68,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_22,
      3,
      array_kFieldTrialConfig_enable_features_61,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_60[] = {
      "ClipboardMaximumAge",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_21[] = {
      {
        "UIClipboardMaximumAge",
        "600",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_67[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_67[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_59[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_67,
      1,
      array_kFieldTrialConfig_form_factors_67,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_21,
      1,
      array_kFieldTrialConfig_enable_features_60,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_59[] = {
      "StartSurfaceAndroid",
      "TabSwitcherOnReturn",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_20[] = {
      {
        "start_surface_variation",
        "single",
      },
      {
        "tab_switcher_on_return_time_ms",
        "3600000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_66[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_66[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_58[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_66,
      1,
      array_kFieldTrialConfig_form_factors_66,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_20,
      2,
      array_kFieldTrialConfig_enable_features_59,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_58[] = {
      "ChromeSmartSelection",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_65[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_65[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_57[] = {
    {
      "Enabled_Launch",
      array_kFieldTrialConfig_platforms_65,
      1,
      array_kFieldTrialConfig_form_factors_65,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_58,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_57[] = {
      "CacheStorageSequence",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_64[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_64[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_56[] = {
    {
      "Enabled1",
      array_kFieldTrialConfig_platforms_64,
      1,
      array_kFieldTrialConfig_form_factors_64,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_57,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_56[] = {
      "CacheStorageHighPriorityMatch",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_63[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_63[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_55[] = {
    {
      "Enabled4",
      array_kFieldTrialConfig_platforms_63,
      1,
      array_kFieldTrialConfig_form_factors_63,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_56,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_55[] = {
      "CacheStorageEagerReading",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_62[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_62[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_54[] = {
    {
      "Enabled2",
      array_kFieldTrialConfig_platforms_62,
      1,
      array_kFieldTrialConfig_form_factors_62,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_55,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_61[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_61[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_53[] = {
    {
      "DetachTimeFg16x",
      array_kFieldTrialConfig_platforms_61,
      1,
      array_kFieldTrialConfig_form_factors_61,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_54[] = {
      "BlockPromptsIfIgnoredOften",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_60[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_60[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_52[] = {
    {
      "BlockPromptsIfIgnoredOften",
      array_kFieldTrialConfig_platforms_60,
      1,
      array_kFieldTrialConfig_form_factors_60,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_54,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_8[] = {
      "BlinkSchedulerPrioritizeCompositingUntilBeginMainFrame",
      "BlinkSchedulerVeryHighPriorityForCompositingAlternating",
      "PrioritizeBootstrapTasks",
      "PrioritizeCompositingAndLoadingDuringEarlyLoading",
};
const char* const array_kFieldTrialConfig_enable_features_53[] = {
      "BlinkSchedulerVeryHighPriorityForCompositingAfterDelay",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_19[] = {
      {
        "CompositingDelayLength",
        "100",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_59[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_59[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_51[] = {
    {
      "VeryHighPriorityForCompositingAfterDelay100",
      array_kFieldTrialConfig_platforms_59,
      1,
      array_kFieldTrialConfig_form_factors_59,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_19,
      1,
      array_kFieldTrialConfig_enable_features_53,
      1,
      array_kFieldTrialConfig_disable_features_8,
      4,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_52[] = {
      "BlinkSchedulerDisableNonTouchstartInputHeuristics",
      "BlinkSchedulerDisableTouchstartInputHeuristics",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_58[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_58[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_50[] = {
    {
      "NoAllHeuristics",
      array_kFieldTrialConfig_platforms_58,
      1,
      array_kFieldTrialConfig_form_factors_58,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_52,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_7[] = {
      "BlinkSchedulerHighestPriorityForCompostingAfterInput",
};
const char* const array_kFieldTrialConfig_enable_features_51[] = {
      "BlinkSchedulerPrioritizeCompositingAfterInput",
      "BlinkSchedulerUseExplicitSignalForTriggeringCompositingPrioritization",
      "BlinkSchedulerUseWillBeginMainFrameForCompositingPrioritization",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_18[] = {
      {
        "number_of_tasks",
        "1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_57[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_57[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_49[] = {
    {
      "ExplicitSignals_1task_high",
      array_kFieldTrialConfig_platforms_57,
      1,
      array_kFieldTrialConfig_form_factors_57,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_18,
      1,
      array_kFieldTrialConfig_enable_features_51,
      3,
      array_kFieldTrialConfig_disable_features_7,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_50[] = {
      "BlinkSchedulerHighPriorityInputOnCompositorThread",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_56[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_56[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_48[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_56,
      1,
      array_kFieldTrialConfig_form_factors_56,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_50,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_49[] = {
      "BlinkSchedulerWorkerThrottling",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_17[] = {
      {
        "max_budget_ms",
        "1000",
      },
      {
        "max_delay_ms",
        "60000",
      },
      {
        "recovery_rate",
        "0.01",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_55[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_55[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_47[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_55,
      1,
      array_kFieldTrialConfig_form_factors_55,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_17,
      3,
      array_kFieldTrialConfig_enable_features_49,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_48[] = {
      "LayoutNG",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_54[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_54[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_46[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_54,
      1,
      array_kFieldTrialConfig_form_factors_54,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_48,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_47[] = {
      "AutofillUseServerCVCPrediction",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_53[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_53[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_45[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_53,
      2,
      array_kFieldTrialConfig_form_factors_53,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_47,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_46[] = {
      "AutofillUseMobileLabelDisambiguation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_16[] = {
      {
        "variant",
        "show-all",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_52[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_52[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_44[] = {
    {
      "Enabled_ShowAll",
      array_kFieldTrialConfig_platforms_52,
      2,
      array_kFieldTrialConfig_form_factors_52,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_16,
      1,
      array_kFieldTrialConfig_enable_features_46,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_45[] = {
      "AutofillUpstreamEditableExpirationDate",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_51[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_51[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_43[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_51,
      1,
      array_kFieldTrialConfig_form_factors_51,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_45,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_44[] = {
      "AutofillUpstreamEditableCardholderName",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_50[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_50[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_42[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_50,
      1,
      array_kFieldTrialConfig_form_factors_50,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_44,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_43[] = {
      "AutofillTokenPrefixMatching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_49[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_49[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_41[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_49,
      2,
      array_kFieldTrialConfig_form_factors_49,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_43,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_42[] = {
      "AutofillEnforceMinRequiredFieldsForUpload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_48[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_48[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_6[] = {
      "AutofillEnforceMinRequiredFieldsForUpload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_47[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_47[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_40[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_47,
      1,
      array_kFieldTrialConfig_form_factors_47,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_6,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_48,
      1,
      array_kFieldTrialConfig_form_factors_48,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_42,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_5[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_46[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_46[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_41[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_45[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_45[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_4[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_44[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_44[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_3[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_43[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_43[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_39[] = {
    {
      "Enabled_AllSmallForms",
      array_kFieldTrialConfig_platforms_43,
      1,
      array_kFieldTrialConfig_form_factors_43,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_3,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Enabled_NoSmallAddressForms",
      array_kFieldTrialConfig_platforms_44,
      1,
      array_kFieldTrialConfig_form_factors_44,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_4,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Control_NoSmallForms",
      array_kFieldTrialConfig_platforms_45,
      1,
      array_kFieldTrialConfig_form_factors_45,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_41,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Default_Enabled_NoSmallAddressForms",
      array_kFieldTrialConfig_platforms_46,
      1,
      array_kFieldTrialConfig_form_factors_46,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_5,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_40[] = {
      "AutofillServerCommunication",
      "AutofillUseApi",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_15[] = {
      {
        "autofill-server-url",
        "https://content-autofill.googleapis.com/",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_42[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_42[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_38[] = {
    {
      "API_Enabled",
      array_kFieldTrialConfig_platforms_42,
      2,
      array_kFieldTrialConfig_form_factors_42,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_15,
      1,
      array_kFieldTrialConfig_enable_features_40,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_39[] = {
      "AutofillRefreshStyleAndroid",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_41[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_41[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_37[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_41,
      1,
      array_kFieldTrialConfig_form_factors_41,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_39,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_38[] = {
      "AutofillPruneSuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_40[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_40[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_36[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_40,
      2,
      array_kFieldTrialConfig_form_factors_40,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_38,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_2[] = {
      "AutofillProfileClientValidation ",
};
const char* const array_kFieldTrialConfig_enable_features_37[] = {
      "AutofillProfileServerValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_39[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_39[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_36[] = {
      "AutofillProfileClientValidation",
      "AutofillProfileServerValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_38[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_38[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_disable_features_1[] = {
      "AutofillProfileServerValidation",
};
const char* const array_kFieldTrialConfig_enable_features_35[] = {
      "AutofillProfileClientValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_37[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_37[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_35[] = {
    {
      "EnabledClient_20190211",
      array_kFieldTrialConfig_platforms_37,
      1,
      array_kFieldTrialConfig_form_factors_37,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_35,
      1,
      array_kFieldTrialConfig_disable_features_1,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledClientServer_20190211",
      array_kFieldTrialConfig_platforms_38,
      1,
      array_kFieldTrialConfig_form_factors_38,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_36,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledServer_20190211",
      array_kFieldTrialConfig_platforms_39,
      1,
      array_kFieldTrialConfig_form_factors_39,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_37,
      1,
      array_kFieldTrialConfig_disable_features_2,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_34[] = {
      "AutofillNoLocalSaveOnUnmaskSuccess",
      "AutofillNoLocalSaveOnUploadSuccess",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_36[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_36[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_34[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_36,
      1,
      array_kFieldTrialConfig_form_factors_36,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_34,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_33[] = {
      "AutofillMetadataUploads",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_35[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_35[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_33[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_35,
      1,
      array_kFieldTrialConfig_form_factors_35,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_33,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_32[] = {
      "AutofillKeyboardAccessory",
      "AutofillManualFallbackAndroid",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_34[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_34[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_32[] = {
    {
      "Enabled_Full_20191119",
      array_kFieldTrialConfig_platforms_34,
      1,
      array_kFieldTrialConfig_form_factors_34,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_32,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_33[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_33[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_31[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_33,
      1,
      array_kFieldTrialConfig_form_factors_33,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_31[] = {
      "AutofillEnableCompanyName",
      "AutofillRejectCompanyBirthyear",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_32[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_32[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_30[] = {
    {
      "RejectBirthyearAsCompany",
      array_kFieldTrialConfig_platforms_32,
      1,
      array_kFieldTrialConfig_form_factors_32,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_31,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_30[] = {
      "AsyncDns",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_31[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_31[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_29[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_31,
      1,
      array_kFieldTrialConfig_form_factors_31,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_30,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_29[] = {
      "AssumeOverlapAfterFixedOrStickyPosition",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_30[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_30[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_28[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_30,
      2,
      array_kFieldTrialConfig_form_factors_30,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_29,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_28[] = {
      "AppendFrameOriginToNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_29[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_29[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_27[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_29,
      2,
      array_kFieldTrialConfig_form_factors_29,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_28,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_27[] = {
      "TouchToFillAndroid",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_14[] = {
      {
        "show_confirmation_button",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_28[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_28[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_26[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_28,
      1,
      array_kFieldTrialConfig_form_factors_28,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_14,
      1,
      array_kFieldTrialConfig_enable_features_27,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_26[] = {
      "EnablePerfettoSystemTracing",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_27[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_27[] = {
      Study::PLATFORM_ANDROID,
      Study::PLATFORM_ANDROID_WEBVIEW,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_25[] = {
    {
      "EnablePerfettoSystemTracing",
      array_kFieldTrialConfig_platforms_27,
      2,
      array_kFieldTrialConfig_form_factors_27,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_26,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_25[] = {
      "AndroidSurfaceControl",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_26[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_26[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_24[] = {
    {
      "EnableAndroidSurfaceControl",
      array_kFieldTrialConfig_platforms_26,
      1,
      array_kFieldTrialConfig_form_factors_26,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_25,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_0[] = {
      "AndroidSpellChecker",
};
const char* const array_kFieldTrialConfig_enable_features_24[] = {
      "AndroidSpellCheckerNonLowEnd",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_25[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_25[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_23[] = {
    {
      "Enabled_NonLowEnd",
      array_kFieldTrialConfig_platforms_25,
      1,
      array_kFieldTrialConfig_form_factors_25,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_24,
      1,
      array_kFieldTrialConfig_disable_features_0,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features[] = {
      "PictureInPictureAPI",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_24[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_24[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_22[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_24,
      1,
      array_kFieldTrialConfig_form_factors_24,
      0,
      base::nullopt,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_23[] = {
      "PasswordManagerOnboardingAndroid",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_13[] = {
      {
        "story",
        "safety",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_23[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_23[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_21[] = {
    {
      "EnabledWithSafetyStory",
      array_kFieldTrialConfig_platforms_23,
      1,
      array_kFieldTrialConfig_form_factors_23,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_13,
      1,
      array_kFieldTrialConfig_enable_features_23,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_22[] = {
      "AndroidNightMode",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_12[] = {
      {
        "u'default_light_theme",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_22[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_22[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_20[] = {
    {
      "Enabled_20190503",
      array_kFieldTrialConfig_platforms_22,
      1,
      array_kFieldTrialConfig_form_factors_22,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_12,
      1,
      array_kFieldTrialConfig_enable_features_22,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_21[] = {
      "BackgroundMediaRendererHasModerateBinding",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_21[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_21[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_19[] = {
    {
      "ModerateBindingInBackground",
      array_kFieldTrialConfig_platforms_21,
      1,
      array_kFieldTrialConfig_form_factors_21,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_21,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_20[] = {
      "InlineUpdateFlow",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_11[] = {
      {
        "flow",
        "best_effort",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_20[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_20[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_18[] = {
    {
      "Enabled_NoNotification",
      array_kFieldTrialConfig_platforms_20,
      1,
      array_kFieldTrialConfig_form_factors_20,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_11,
      1,
      array_kFieldTrialConfig_enable_features_20,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_19[] = {
      "IPH_QuietNotificationPrompts",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_10[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:tabgroups_dummy;comparator:any;window:1;storage:1",
      },
      {
        "event_used",
        "name:tabgroups_dummy;comparator:any;window:1;storage:1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_19[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_19[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_17[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_19,
      1,
      array_kFieldTrialConfig_form_factors_19,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_10,
      3,
      array_kFieldTrialConfig_enable_features_19,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_18[] = {
      "IPH_TranslateMenuButton",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_9[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:translate_menu_button_iph_triggered;comparator:<2;window:30;storage:360",
      },
      {
        "event_trigger_delay",
        "name:translate_menu_button_iph_triggered;comparator:<1;window:1;storage:360",
      },
      {
        "event_used",
        "name:translate_menu_button_clicked;comparator:==0;window:90;storage:360",
      },
      {
        "session_rate",
        "==0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_18[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_18[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_16[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_18,
      1,
      array_kFieldTrialConfig_form_factors_18,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_9,
      5,
      array_kFieldTrialConfig_enable_features_18,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_17[] = {
      "IPH_DownloadSettings",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_8[] = {
      {
        "availability",
        "any",
      },
      {
        "event_settings_accessed",
        "name:download_settings_access_through_download_home;comparator:==0;window:60;storage:360",
      },
      {
        "event_trigger",
        "name:download_settings_iph_trigger;comparator:any;window:90;storage:360",
      },
      {
        "event_used",
        "name:download_settings_opened;comparator:any;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_17[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_17[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_15[] = {
    {
      "Tracking",
      array_kFieldTrialConfig_platforms_17,
      1,
      array_kFieldTrialConfig_form_factors_17,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_8,
      5,
      array_kFieldTrialConfig_enable_features_17,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_16[] = {
      "IPH_DownloadPageScreenshot",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_7[] = {
      {
        "availability",
        "any",
      },
      {
        "event_screenshot_taken",
        "name:screenshot_taken_chrome_in_foreground;comparator:>=1;window:90;storage:360",
      },
      {
        "event_trigger",
        "name:download_page_iph_would_have_triggered;comparator:==0;window:90;storage:360",
      },
      {
        "event_used",
        "name:download_page_started;comparator:==0;window:90;storage:360",
      },
      {
        "session_rate",
        "<=1",
      },
      {
        "tracking_only",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_16[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_16[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_14[] = {
    {
      "EnabledTracking",
      array_kFieldTrialConfig_platforms_16,
      1,
      array_kFieldTrialConfig_form_factors_16,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_7,
      6,
      array_kFieldTrialConfig_enable_features_16,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_15[] = {
      "IPH_DownloadPage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_6[] = {
      {
        "availability",
        ">=14",
      },
      {
        "event_1",
        "name:user_has_seen_dino;comparator:>=1;window:90;storage:360",
      },
      {
        "event_trigger",
        "name:download_page_iph_trigger;comparator:==0;window:90;storage:360",
      },
      {
        "event_used",
        "name:download_page_started;comparator:==0;window:90;storage:360",
      },
      {
        "session_rate",
        "<0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_15[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_15[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_13[] = {
    {
      "Tracking",
      array_kFieldTrialConfig_platforms_15,
      1,
      array_kFieldTrialConfig_form_factors_15,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_6,
      5,
      array_kFieldTrialConfig_enable_features_15,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_14[] = {
      "IPH_DownloadInfoBarDownloadsAreFaster",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_5[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:download_infobar_downloads_are_faster_iph_trigger;comparator:==0;window:90;storage:360",
      },
      {
        "event_used",
        "name:download_completed;comparator:any;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_14[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_14[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_12[] = {
    {
      "Tracking",
      array_kFieldTrialConfig_platforms_14,
      1,
      array_kFieldTrialConfig_form_factors_14,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_5,
      4,
      array_kFieldTrialConfig_enable_features_14,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_13[] = {
      "IPH_DownloadInfoBarDownloadContinuing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_4[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:download_infobar_download_continuing_iph_trigger;comparator:==0;window:90;storage:360",
      },
      {
        "event_used",
        "name:download_home_opened;comparator:any;window:90;storage:360",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_13[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_13[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_11[] = {
    {
      "Tracking",
      array_kFieldTrialConfig_platforms_13,
      1,
      array_kFieldTrialConfig_form_factors_13,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_4,
      4,
      array_kFieldTrialConfig_enable_features_13,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_12[] = {
      "IPH_ContextualSearchWebSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_3[] = {
      {
        "availability",
        ">=14",
      },
      {
        "event_1",
        "name:web_search_performed;comparator:>=1;window:90;storage:90",
      },
      {
        "event_2",
        "name:contextual_search_web_search_iph_trigger;comparator:<2;window:680;storage:680",
      },
      {
        "event_3",
        "name:contextual_search_panel_opened;comparator:>0;window:680;storage:680",
      },
      {
        "event_trigger",
        "name:contextual_search_web_search_iph_trigger;comparator:==0;window:90;storage:680",
      },
      {
        "event_used",
        "name:contextual_search_panel_opened;comparator:==0;window:30;storage:90",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_12[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_12[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_10[] = {
    {
      "WebSearchExperiment",
      array_kFieldTrialConfig_platforms_12,
      1,
      array_kFieldTrialConfig_form_factors_12,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_3,
      7,
      array_kFieldTrialConfig_enable_features_12,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_11[] = {
      "IPH_ContextualSearchPromoteTap",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_2[] = {
      {
        "availability",
        ">=14",
      },
      {
        "event_1",
        "name:contextual_search_panel_opened;comparator:>=2;window:90;storage:90",
      },
      {
        "event_2",
        "name:contextual_search_promote_tap_iph_trigger;comparator:<2;window:680;storage:680",
      },
      {
        "event_trigger",
        "name:contextual_search_promote_tap_iph_trigger;comparator:==0;window:90;storage:680",
      },
      {
        "event_used",
        "name:contextual_search_panel_opened_after_tap;comparator:==0;window:30;storage:90",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_11[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_11[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_9[] = {
    {
      "PromoteTapExperiment",
      array_kFieldTrialConfig_platforms_11,
      1,
      array_kFieldTrialConfig_form_factors_11,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_2,
      6,
      array_kFieldTrialConfig_enable_features_11,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_10[] = {
      "IPH_ContextualSearchPromotePanelOpen",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_1[] = {
      {
        "availability",
        ">=14",
      },
      {
        "event_1",
        "name:contextual_search_promote_panel_open_iph_trigger;comparator:<2;window:680;storage:680",
      },
      {
        "event_2",
        "name:contextual_search_panel_opened;comparator:<3;window:90;storage:90",
      },
      {
        "event_trigger",
        "name:contextual_search_promote_panel_open_iph_trigger;comparator:==0;window:90;storage:680",
      },
      {
        "event_used",
        "name:contextual_search_panel_opened_for_entity;comparator:==0;window:90;storage:90",
      },
      {
        "session_rate",
        "<1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_10[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_10[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_8[] = {
    {
      "PromotePanelOpeningExperiment",
      array_kFieldTrialConfig_platforms_10,
      1,
      array_kFieldTrialConfig_form_factors_10,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_1,
      6,
      array_kFieldTrialConfig_enable_features_10,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_9[] = {
      "OmniboxEnableClipboardProviderTextSuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_9[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_9[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_7[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_9,
      1,
      array_kFieldTrialConfig_form_factors_9,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_9,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_8[] = {
      "OmniboxRemoveSuggestionsFromClipboard",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_8[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_8[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_6[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_8,
      1,
      array_kFieldTrialConfig_form_factors_8,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_8,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_7[] = {
      "AndroidAIAFetching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_7[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_7[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_5[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_7,
      1,
      array_kFieldTrialConfig_form_factors_7,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_7,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_6[] = {
      "CCTBackgroundTab",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_6[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_6[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_4[] = {
    {
      "AmpBackgroundTab",
      array_kFieldTrialConfig_platforms_6,
      1,
      array_kFieldTrialConfig_form_factors_6,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_6,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_5[] = {
      "AllowClientHintsToThirdParty",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_5[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_5[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_3[] = {
    {
      "AllowClientHintsToThirdParty",
      array_kFieldTrialConfig_platforms_5,
      1,
      array_kFieldTrialConfig_form_factors_5,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_5,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_4[] = {
      "AddToHomescreenMessaging",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_0[] = {
      {
        "include_no_download_required",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_4[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_4[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features_3[] = {
      "AddToHomescreenMessaging",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params[] = {
      {
        "include_no_download_required",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_3[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_3[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_2[] = {
    {
      "Install app",
      array_kFieldTrialConfig_platforms_3,
      1,
      array_kFieldTrialConfig_form_factors_3,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params,
      1,
      array_kFieldTrialConfig_enable_features_3,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Install app (no download required)",
      array_kFieldTrialConfig_platforms_4,
      1,
      array_kFieldTrialConfig_form_factors_4,
      0,
      base::nullopt,
      array_kFieldTrialConfig_params_0,
      1,
      array_kFieldTrialConfig_enable_features_4,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_2[] = {
      "AdTagging",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_2[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_2[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_1[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_2,
      1,
      array_kFieldTrialConfig_form_factors_2,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_2,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_1[] = {
      "AImageReaderVideoOutput",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_1[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_1[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_0[] = {
    {
      "Use_AImageReaderVideoOutput_V2",
      array_kFieldTrialConfig_platforms_1,
      1,
      array_kFieldTrialConfig_form_factors_1,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_1,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_0[] = {
      "AImageReaderMediaPlayer",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_0[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_0[] = {
      Study::PLATFORM_ANDROID,
};
const char* const array_kFieldTrialConfig_enable_features[] = {
      "AImageReaderMediaPlayer",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms[] = {
      Study::PLATFORM_ANDROID,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments[] = {
    {
      "Use_AImageReaderMediaPlayer_V2",
      array_kFieldTrialConfig_platforms,
      1,
      array_kFieldTrialConfig_form_factors,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Use_AImageReaderMediaPlayer_V3",
      array_kFieldTrialConfig_platforms_0,
      1,
      array_kFieldTrialConfig_form_factors_0,
      0,
      base::nullopt,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_0,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingStudy array_kFieldTrialConfig_studies[] = {
  {
    "AImageReaderMediaPlayer",
    array_kFieldTrialConfig_experiments,
    2,
  },
  {
    "AImageReaderVideoOutput",
    array_kFieldTrialConfig_experiments_0,
    1,
  },
  {
    "AdTagging",
    array_kFieldTrialConfig_experiments_1,
    1,
  },
  {
    "AddToHomescreenMessaging",
    array_kFieldTrialConfig_experiments_2,
    2,
  },
  {
    "AllowClientHintsToThirdParty",
    array_kFieldTrialConfig_experiments_3,
    1,
  },
  {
    "AmpBackgroundTab",
    array_kFieldTrialConfig_experiments_4,
    1,
  },
  {
    "AndroidAIAFetching",
    array_kFieldTrialConfig_experiments_5,
    1,
  },
  {
    "AndroidClipboardSuggestionsRemoval",
    array_kFieldTrialConfig_experiments_6,
    1,
  },
  {
    "AndroidClipboardTextSuggestions",
    array_kFieldTrialConfig_experiments_7,
    1,
  },
  {
    "AndroidInProductHelpContextualSearchPromotePanelOpen",
    array_kFieldTrialConfig_experiments_8,
    1,
  },
  {
    "AndroidInProductHelpContextualSearchPromoteTap",
    array_kFieldTrialConfig_experiments_9,
    1,
  },
  {
    "AndroidInProductHelpContextualSearchWebSearch",
    array_kFieldTrialConfig_experiments_10,
    1,
  },
  {
    "AndroidInProductHelpDownloadInfoBarDownloadContinuing",
    array_kFieldTrialConfig_experiments_11,
    1,
  },
  {
    "AndroidInProductHelpDownloadInfoBarDownloadsAreFaster",
    array_kFieldTrialConfig_experiments_12,
    1,
  },
  {
    "AndroidInProductHelpDownloadPage",
    array_kFieldTrialConfig_experiments_13,
    1,
  },
  {
    "AndroidInProductHelpDownloadPageScreenshot",
    array_kFieldTrialConfig_experiments_14,
    1,
  },
  {
    "AndroidInProductHelpDownloadSettings",
    array_kFieldTrialConfig_experiments_15,
    1,
  },
  {
    "AndroidInProductHelpManualTranslate",
    array_kFieldTrialConfig_experiments_16,
    1,
  },
  {
    "AndroidInProductHelpQuietNotificationPrompts",
    array_kFieldTrialConfig_experiments_17,
    1,
  },
  {
    "AndroidInlineUpdateFlowStudy",
    array_kFieldTrialConfig_experiments_18,
    1,
  },
  {
    "AndroidMediaProcessPriority",
    array_kFieldTrialConfig_experiments_19,
    1,
  },
  {
    "AndroidNightMode",
    array_kFieldTrialConfig_experiments_20,
    1,
  },
  {
    "AndroidPasswordManagerOnboarding",
    array_kFieldTrialConfig_experiments_21,
    1,
  },
  {
    "AndroidPictureInPictureAPI",
    array_kFieldTrialConfig_experiments_22,
    1,
  },
  {
    "AndroidSpellChecker",
    array_kFieldTrialConfig_experiments_23,
    1,
  },
  {
    "AndroidSurfaceControl",
    array_kFieldTrialConfig_experiments_24,
    1,
  },
  {
    "AndroidSystemTracing",
    array_kFieldTrialConfig_experiments_25,
    1,
  },
  {
    "AndroidTouchToFill",
    array_kFieldTrialConfig_experiments_26,
    1,
  },
  {
    "AppendFrameOriginToNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_27,
    1,
  },
  {
    "AssumeOverlapAfterFixedOrStickyPosition",
    array_kFieldTrialConfig_experiments_28,
    1,
  },
  {
    "AsyncDns",
    array_kFieldTrialConfig_experiments_29,
    1,
  },
  {
    "AutofillCompany",
    array_kFieldTrialConfig_experiments_30,
    1,
  },
  {
    "AutofillFieldMetadata",
    array_kFieldTrialConfig_experiments_31,
    1,
  },
  {
    "AutofillKeyboardAccessory",
    array_kFieldTrialConfig_experiments_32,
    1,
  },
  {
    "AutofillMetadataUploads",
    array_kFieldTrialConfig_experiments_33,
    1,
  },
  {
    "AutofillNoLocalSaveOnUnmaskOrUploadSuccess",
    array_kFieldTrialConfig_experiments_34,
    1,
  },
  {
    "AutofillProfileValidation",
    array_kFieldTrialConfig_experiments_35,
    3,
  },
  {
    "AutofillPruneSuggestions",
    array_kFieldTrialConfig_experiments_36,
    1,
  },
  {
    "AutofillRefreshStyleAndroid",
    array_kFieldTrialConfig_experiments_37,
    1,
  },
  {
    "AutofillServerBehaviors",
    array_kFieldTrialConfig_experiments_38,
    1,
  },
  {
    "AutofillSmallFormSupport",
    array_kFieldTrialConfig_experiments_39,
    4,
  },
  {
    "AutofillSmallFormUploads",
    array_kFieldTrialConfig_experiments_40,
    2,
  },
  {
    "AutofillTokenPrefixMatching",
    array_kFieldTrialConfig_experiments_41,
    1,
  },
  {
    "AutofillUpstreamEditableCardholderName",
    array_kFieldTrialConfig_experiments_42,
    1,
  },
  {
    "AutofillUpstreamEditableExpirationDate",
    array_kFieldTrialConfig_experiments_43,
    1,
  },
  {
    "AutofillUseMobileLabelDisambiguation",
    array_kFieldTrialConfig_experiments_44,
    1,
  },
  {
    "AutofillUseServerCVCPrediction",
    array_kFieldTrialConfig_experiments_45,
    1,
  },
  {
    "BlinkLayoutNG",
    array_kFieldTrialConfig_experiments_46,
    1,
  },
  {
    "BlinkSchedulerDedicatedWorkerThrottling",
    array_kFieldTrialConfig_experiments_47,
    1,
  },
  {
    "BlinkSchedulerHighPriorityInputOnCompositorThread",
    array_kFieldTrialConfig_experiments_48,
    1,
  },
  {
    "BlinkSchedulerPrioritizeCompositingAfterInput",
    array_kFieldTrialConfig_experiments_49,
    1,
  },
  {
    "BlinkSchedulerRemoveInputUseCaseHeuristics",
    array_kFieldTrialConfig_experiments_50,
    1,
  },
  {
    "BlinkSchedulerVeryHighPriorityForCompositingExperiments",
    array_kFieldTrialConfig_experiments_51,
    1,
  },
  {
    "BlockPromptsIfIgnoredOften",
    array_kFieldTrialConfig_experiments_52,
    1,
  },
  {
    "BrowserScheduler",
    array_kFieldTrialConfig_experiments_53,
    1,
  },
  {
    "CacheStorageEagerReading",
    array_kFieldTrialConfig_experiments_54,
    1,
  },
  {
    "CacheStorageHighPriorityMatch",
    array_kFieldTrialConfig_experiments_55,
    1,
  },
  {
    "CacheStorageSequence",
    array_kFieldTrialConfig_experiments_56,
    1,
  },
  {
    "ChromeSmartSelection",
    array_kFieldTrialConfig_experiments_57,
    1,
  },
  {
    "ChromeStart",
    array_kFieldTrialConfig_experiments_58,
    1,
  },
  {
    "ClipboardMaximumAge",
    array_kFieldTrialConfig_experiments_59,
    1,
  },
  {
    "ContentCapture",
    array_kFieldTrialConfig_experiments_60,
    1,
  },
  {
    "ContentIndexingDownloadHome",
    array_kFieldTrialConfig_experiments_61,
    1,
  },
  {
    "ContentIndexingNTP",
    array_kFieldTrialConfig_experiments_62,
    1,
  },
  {
    "ContextMenuSearchWithGoogleLensMultiArm",
    array_kFieldTrialConfig_experiments_63,
    1,
  },
  {
    "ContextualSearch",
    array_kFieldTrialConfig_experiments_64,
    1,
  },
  {
    "ContextualSearchDefinitions",
    array_kFieldTrialConfig_experiments_65,
    1,
  },
  {
    "CopylessPaste",
    array_kFieldTrialConfig_experiments_66,
    1,
  },
  {
    "DataCompressionProxyPromoVisibility",
    array_kFieldTrialConfig_experiments_67,
    1,
  },
  {
    "DataReductionProxyBlockOnBadGatewayResponse",
    array_kFieldTrialConfig_experiments_68,
    1,
  },
  {
    "DataReductionProxyFREPromo",
    array_kFieldTrialConfig_experiments_69,
    1,
  },
  {
    "DataReductionProxyLowMemoryDevicePromo",
    array_kFieldTrialConfig_experiments_70,
    1,
  },
  {
    "DecodeJpegToYuv",
    array_kFieldTrialConfig_experiments_71,
    1,
  },
  {
    "DefaultEnableOopRasterization",
    array_kFieldTrialConfig_experiments_72,
    1,
  },
  {
    "DeprecateFtp",
    array_kFieldTrialConfig_experiments_73,
    1,
  },
  {
    "DirectActions",
    array_kFieldTrialConfig_experiments_74,
    1,
  },
  {
    "DnsOverHttps",
    array_kFieldTrialConfig_experiments_75,
    1,
  },
  {
    "DownloadHomeMoreButton",
    array_kFieldTrialConfig_experiments_76,
    1,
  },
  {
    "DownloadHomeV2",
    array_kFieldTrialConfig_experiments_77,
    1,
  },
  {
    "DownloadOfflineContentProvider",
    array_kFieldTrialConfig_experiments_78,
    1,
  },
  {
    "DownloadProgressInfoBar",
    array_kFieldTrialConfig_experiments_79,
    1,
  },
  {
    "DownloadRename",
    array_kFieldTrialConfig_experiments_80,
    1,
  },
  {
    "DownloadResumptionWithoutStrongValidators",
    array_kFieldTrialConfig_experiments_81,
    1,
  },
  {
    "DownloadWithServicificationM77",
    array_kFieldTrialConfig_experiments_82,
    1,
  },
  {
    "DownloadsAutoResumptionNative",
    array_kFieldTrialConfig_experiments_83,
    1,
  },
  {
    "DownloadsLocationChange",
    array_kFieldTrialConfig_experiments_84,
    1,
  },
  {
    "DownloadsUi",
    array_kFieldTrialConfig_experiments_85,
    1,
  },
  {
    "DynamicExpectCT",
    array_kFieldTrialConfig_experiments_86,
    1,
  },
  {
    "EnableHistoryFaviconsGoogleServerQuery",
    array_kFieldTrialConfig_experiments_87,
    1,
  },
  {
    "EnableSafetyTipUI",
    array_kFieldTrialConfig_experiments_88,
    1,
  },
  {
    "EphemeralTab",
    array_kFieldTrialConfig_experiments_89,
    1,
  },
  {
    "ExpandablePaymentHandler",
    array_kFieldTrialConfig_experiments_90,
    1,
  },
  {
    "ExpectCTReporting",
    array_kFieldTrialConfig_experiments_91,
    1,
  },
  {
    "ExploreSitesDense",
    array_kFieldTrialConfig_experiments_92,
    1,
  },
  {
    "FCMInvalidations",
    array_kFieldTrialConfig_experiments_93,
    1,
  },
  {
    "FilterAdsOnAbusiveSites",
    array_kFieldTrialConfig_experiments_94,
    1,
  },
  {
    "FontSrcLocalMatching",
    array_kFieldTrialConfig_experiments_95,
    1,
  },
  {
    "ForbidSyncXHRInPageDismissal",
    array_kFieldTrialConfig_experiments_96,
    1,
  },
  {
    "FreezeBackgroundTabOnNetworkIdle",
    array_kFieldTrialConfig_experiments_97,
    2,
  },
  {
    "GamepadPollingInterval",
    array_kFieldTrialConfig_experiments_98,
    1,
  },
  {
    "GestureNavigation",
    array_kFieldTrialConfig_experiments_99,
    1,
  },
  {
    "GpuRasterizationViewportRestriction",
    array_kFieldTrialConfig_experiments_100,
    1,
  },
  {
    "GpuScheduler",
    array_kFieldTrialConfig_experiments_101,
    1,
  },
  {
    "GpuWatchdogV2",
    array_kFieldTrialConfig_experiments_102,
    1,
  },
  {
    "GwpAsanAndroid",
    array_kFieldTrialConfig_experiments_103,
    1,
  },
  {
    "HTTPDangerWarning",
    array_kFieldTrialConfig_experiments_104,
    1,
  },
  {
    "HarfBuzzPdfSubsetter",
    array_kFieldTrialConfig_experiments_105,
    1,
  },
  {
    "HeapProfiling",
    array_kFieldTrialConfig_experiments_106,
    1,
  },
  {
    "IDBTombstoneSweeper",
    array_kFieldTrialConfig_experiments_107,
    1,
  },
  {
    "IdentityDiscIPH",
    array_kFieldTrialConfig_experiments_108,
    1,
  },
  {
    "IncognitoDynamicQuota",
    array_kFieldTrialConfig_experiments_109,
    1,
  },
  {
    "IndexedDBHighPriority",
    array_kFieldTrialConfig_experiments_110,
    2,
  },
  {
    "InstantApps",
    array_kFieldTrialConfig_experiments_111,
    1,
  },
  {
    "InterestFeedContentSuggestions",
    array_kFieldTrialConfig_experiments_112,
    1,
  },
  {
    "InvalidationsGCMUpstream",
    array_kFieldTrialConfig_experiments_113,
    3,
  },
  {
    "IsolatePasswordSites",
    array_kFieldTrialConfig_experiments_114,
    1,
  },
  {
    "KeepaliveRequestPriority",
    array_kFieldTrialConfig_experiments_115,
    1,
  },
  {
    "KeyboardAccessoryAddressIPH",
    array_kFieldTrialConfig_experiments_116,
    1,
  },
  {
    "KeyboardAccessoryPasswordIPH",
    array_kFieldTrialConfig_experiments_117,
    1,
  },
  {
    "KeyboardAccessoryPaymentIPH",
    array_kFieldTrialConfig_experiments_118,
    1,
  },
  {
    "LegacySymantecPKI",
    array_kFieldTrialConfig_experiments_119,
    1,
  },
  {
    "LegacyTLSDeprecation",
    array_kFieldTrialConfig_experiments_120,
    1,
  },
  {
    "LowPriorityIframes2",
    array_kFieldTrialConfig_experiments_121,
    1,
  },
  {
    "LowerJavaScriptPriorityWhenForceDeferred",
    array_kFieldTrialConfig_experiments_122,
    1,
  },
  {
    "LsdPermissionPrompt",
    array_kFieldTrialConfig_experiments_123,
    1,
  },
  {
    "MediaCapabilitiesWithParameters",
    array_kFieldTrialConfig_experiments_124,
    1,
  },
  {
    "MergeBlockingNonBlockingPools",
    array_kFieldTrialConfig_experiments_125,
    1,
  },
  {
    "MirrorMultilogin",
    array_kFieldTrialConfig_experiments_126,
    1,
  },
  {
    "NTPLaunchAfterInactivity",
    array_kFieldTrialConfig_experiments_127,
    1,
  },
  {
    "NTPPopularSites",
    array_kFieldTrialConfig_experiments_128,
    4,
  },
  {
    "NavigationPredictor",
    array_kFieldTrialConfig_experiments_129,
    1,
  },
  {
    "NavigationPredictorMultiplePrerenders",
    array_kFieldTrialConfig_experiments_130,
    1,
  },
  {
    "NewAnswersLayoutAndroidOmniboxM74",
    array_kFieldTrialConfig_experiments_131,
    1,
  },
  {
    "OfferUploadCreditCards",
    array_kFieldTrialConfig_experiments_132,
    1,
  },
  {
    "OfflineIndicator",
    array_kFieldTrialConfig_experiments_133,
    2,
  },
  {
    "OfflinePagesAsyncLoading",
    array_kFieldTrialConfig_experiments_134,
    1,
  },
  {
    "OfflinePagesCctV2",
    array_kFieldTrialConfig_experiments_135,
    1,
  },
  {
    "OfflinePagesDescriptivePendingStatus",
    array_kFieldTrialConfig_experiments_136,
    1,
  },
  {
    "OfflinePagesDinoPageExperiment",
    array_kFieldTrialConfig_experiments_137,
    1,
  },
  {
    "OfflinePagesInDHOpenInCCT",
    array_kFieldTrialConfig_experiments_138,
    1,
  },
  {
    "OfflinePagesPrefetchingSuggestions",
    array_kFieldTrialConfig_experiments_139,
    1,
  },
  {
    "OfflinePagesSharing",
    array_kFieldTrialConfig_experiments_140,
    1,
  },
  {
    "OmniboxAssistantVoiceSearch",
    array_kFieldTrialConfig_experiments_141,
    1,
  },
  {
    "OmniboxBundledExperimentV1",
    array_kFieldTrialConfig_experiments_142,
    1,
  },
  {
    "OmniboxOnDeviceHeadSuggest",
    array_kFieldTrialConfig_experiments_143,
    1,
  },
  {
    "OmniboxPreserveDefaultMatchAgainstAsyncUpdate",
    array_kFieldTrialConfig_experiments_144,
    1,
  },
  {
    "OmniboxSearchEngineLogo",
    array_kFieldTrialConfig_experiments_145,
    1,
  },
  {
    "OptimizationTargetPrediction",
    array_kFieldTrialConfig_experiments_146,
    1,
  },
  {
    "OutOfBlinkCors",
    array_kFieldTrialConfig_experiments_147,
    1,
  },
  {
    "OverflowIconsForMediaControls",
    array_kFieldTrialConfig_experiments_148,
    1,
  },
  {
    "PDFClickToOpen",
    array_kFieldTrialConfig_experiments_149,
    1,
  },
  {
    "PaintHolding",
    array_kFieldTrialConfig_experiments_150,
    1,
  },
  {
    "ParallelDownloadWithQUICAndHTTP2",
    array_kFieldTrialConfig_experiments_151,
    2,
  },
  {
    "ParallelDownloading",
    array_kFieldTrialConfig_experiments_152,
    1,
  },
  {
    "PartitionConnectionsByNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_153,
    1,
  },
  {
    "PassiveDocumentEventListeners",
    array_kFieldTrialConfig_experiments_154,
    1,
  },
  {
    "PassiveDocumentWheelEventListeners",
    array_kFieldTrialConfig_experiments_155,
    1,
  },
  {
    "PassiveEventListenersDueToFling",
    array_kFieldTrialConfig_experiments_156,
    1,
  },
  {
    "PassiveMixedContentAutoupgrade",
    array_kFieldTrialConfig_experiments_157,
    1,
  },
  {
    "PassiveMixedContentWarning",
    array_kFieldTrialConfig_experiments_158,
    1,
  },
  {
    "PauseBrowserInitiatedHeavyTrafficForP2P",
    array_kFieldTrialConfig_experiments_159,
    1,
  },
  {
    "PaymentRequestAlwaysAllowJustInTimePaymentApp",
    array_kFieldTrialConfig_experiments_160,
    1,
  },
  {
    "PermissionPromptUIAndroid",
    array_kFieldTrialConfig_experiments_161,
    1,
  },
  {
    "PermissionPromptUIAndroidModal",
    array_kFieldTrialConfig_experiments_162,
    1,
  },
  {
    "PersistentHistograms",
    array_kFieldTrialConfig_experiments_163,
    1,
  },
  {
    "PersistentNotificationInStandalonePwa",
    array_kFieldTrialConfig_experiments_164,
    1,
  },
  {
    "PhysicalWeb",
    array_kFieldTrialConfig_experiments_165,
    1,
  },
  {
    "Precache",
    array_kFieldTrialConfig_experiments_166,
    1,
  },
  {
    "PreconnectOnDidFinishNavigation",
    array_kFieldTrialConfig_experiments_167,
    1,
  },
  {
    "PrefetchSRPAndroid",
    array_kFieldTrialConfig_experiments_168,
    1,
  },
  {
    "PreloadMetadataLazyLoad",
    array_kFieldTrialConfig_experiments_169,
    1,
  },
  {
    "PrerenderFallbackToPreconnect",
    array_kFieldTrialConfig_experiments_170,
    1,
  },
  {
    "PreviewsLitePageRedirect",
    array_kFieldTrialConfig_experiments_171,
    1,
  },
  {
    "PreviewsNoScript",
    array_kFieldTrialConfig_experiments_172,
    1,
  },
  {
    "PrioritizedSimpleCacheTasks",
    array_kFieldTrialConfig_experiments_173,
    1,
  },
  {
    "PrivacySettingsRedesignTest",
    array_kFieldTrialConfig_experiments_174,
    1,
  },
  {
    "ProactivelySwapBrowsingInstance",
    array_kFieldTrialConfig_experiments_175,
    1,
  },
  {
    "ProactivelyThrottleLowPriorityRequests",
    array_kFieldTrialConfig_experiments_176,
    1,
  },
  {
    "ProfileSyncServiceUsesThreadPool",
    array_kFieldTrialConfig_experiments_177,
    1,
  },
  {
    "ProgressBarAnimationAndroid",
    array_kFieldTrialConfig_experiments_178,
    1,
  },
  {
    "ProtoDBSharedMigration",
    array_kFieldTrialConfig_experiments_179,
    1,
  },
  {
    "QUIC",
    array_kFieldTrialConfig_experiments_180,
    1,
  },
  {
    "QueryInOmnibox",
    array_kFieldTrialConfig_experiments_181,
    1,
  },
  {
    "QuotaExpandPoolSize",
    array_kFieldTrialConfig_experiments_182,
    1,
  },
  {
    "ReaderModeUI",
    array_kFieldTrialConfig_experiments_183,
    2,
  },
  {
    "RendererSchedulerWakeUpThrottling",
    array_kFieldTrialConfig_experiments_184,
    1,
  },
  {
    "ReorderBookmarks",
    array_kFieldTrialConfig_experiments_185,
    1,
  },
  {
    "ReportCertificateErrors",
    array_kFieldTrialConfig_experiments_186,
    2,
  },
  {
    "ReportingAPIAndNetworkErrorLogging",
    array_kFieldTrialConfig_experiments_187,
    1,
  },
  {
    "ResourceLoadingHints",
    array_kFieldTrialConfig_experiments_188,
    1,
  },
  {
    "RevampedContextMenu",
    array_kFieldTrialConfig_experiments_189,
    1,
  },
  {
    "SafeBrowsingAdPopupTrigger",
    array_kFieldTrialConfig_experiments_190,
    1,
  },
  {
    "SafeBrowsingAdRedirectTrigger",
    array_kFieldTrialConfig_experiments_191,
    1,
  },
  {
    "SafeBrowsingAdSamplerTrigger",
    array_kFieldTrialConfig_experiments_192,
    3,
  },
  {
    "SafeBrowsingAndroid",
    array_kFieldTrialConfig_experiments_193,
    2,
  },
  {
    "SafeBrowsingCommittedInterstitials",
    array_kFieldTrialConfig_experiments_194,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionForSavedPasswordsAndroid",
    array_kFieldTrialConfig_experiments_195,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionOnFocusPingAndroid",
    array_kFieldTrialConfig_experiments_196,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionPasswordReusePingAndroid",
    array_kFieldTrialConfig_experiments_197,
    1,
  },
  {
    "SafeBrowsingRealTimeUrlLookupEnabledAndroid",
    array_kFieldTrialConfig_experiments_198,
    1,
  },
  {
    "SafeBrowsingScoutTransitionStudy",
    array_kFieldTrialConfig_experiments_199,
    3,
  },
  {
    "SafeBrowsingSuspiciousSiteTrigger",
    array_kFieldTrialConfig_experiments_200,
    2,
  },
  {
    "SafeBrowsingThreatDomDetailsTagAttributes",
    array_kFieldTrialConfig_experiments_201,
    2,
  },
  {
    "SafeBrowsingUseLocalBlacklistsV2",
    array_kFieldTrialConfig_experiments_202,
    1,
  },
  {
    "SameSiteByDefaultCookies_AndroidAw",
    array_kFieldTrialConfig_experiments_203,
    1,
  },
  {
    "SameSiteCookieMessages",
    array_kFieldTrialConfig_experiments_204,
    1,
  },
  {
    "ScriptStreamingOnPreload",
    array_kFieldTrialConfig_experiments_205,
    1,
  },
  {
    "ScrollResamplingRollout",
    array_kFieldTrialConfig_experiments_206,
    1,
  },
  {
    "SearchEnginePromo",
    array_kFieldTrialConfig_experiments_207,
    1,
  },
  {
    "ServiceGroupImportance",
    array_kFieldTrialConfig_experiments_208,
    1,
  },
  {
    "ServiceManagerForBackgroundPrefetch",
    array_kFieldTrialConfig_experiments_209,
    1,
  },
  {
    "ServiceWorkerStartupOptimizations",
    array_kFieldTrialConfig_experiments_210,
    1,
  },
  {
    "SharedClipboard",
    array_kFieldTrialConfig_experiments_211,
    1,
  },
  {
    "SimpleCacheTrailerPrefetchHint",
    array_kFieldTrialConfig_experiments_212,
    1,
  },
  {
    "SplitCacheByNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_213,
    1,
  },
  {
    "SqlSkipPreload",
    array_kFieldTrialConfig_experiments_214,
    1,
  },
  {
    "StaticHostQuota",
    array_kFieldTrialConfig_experiments_215,
    1,
  },
  {
    "StopLoadingInBackground",
    array_kFieldTrialConfig_experiments_216,
    1,
  },
  {
    "StopNonTimersInBackground",
    array_kFieldTrialConfig_experiments_217,
    1,
  },
  {
    "SyncUssBookmarks'",
    array_kFieldTrialConfig_experiments_218,
    1,
  },
  {
    "SyncUssNigori",
    array_kFieldTrialConfig_experiments_219,
    1,
  },
  {
    "SyncUssPasswords'",
    array_kFieldTrialConfig_experiments_220,
    1,
  },
  {
    "TabGridLayoutAndroid",
    array_kFieldTrialConfig_experiments_221,
    1,
  },
  {
    "TabGroupsDragAndDrop",
    array_kFieldTrialConfig_experiments_222,
    1,
  },
  {
    "TabGroupsQuicklyComparePages",
    array_kFieldTrialConfig_experiments_223,
    1,
  },
  {
    "TabGroupsTapToSeeAnotherTab",
    array_kFieldTrialConfig_experiments_224,
    1,
  },
  {
    "TabGroupsYourTabsTogether",
    array_kFieldTrialConfig_experiments_225,
    1,
  },
  {
    "TabToGTSAnimation",
    array_kFieldTrialConfig_experiments_226,
    1,
  },
  {
    "TextFragmentAnchor",
    array_kFieldTrialConfig_experiments_227,
    1,
  },
  {
    "ThrottleDelayable",
    array_kFieldTrialConfig_experiments_228,
    1,
  },
  {
    "TranslateCompactUI",
    array_kFieldTrialConfig_experiments_229,
    1,
  },
  {
    "TranslateRankerModelAndroid",
    array_kFieldTrialConfig_experiments_230,
    1,
  },
  {
    "TranslateServerStudy",
    array_kFieldTrialConfig_experiments_231,
    1,
  },
  {
    "TrustedTypes",
    array_kFieldTrialConfig_experiments_232,
    1,
  },
  {
    "UKM",
    array_kFieldTrialConfig_experiments_233,
    1,
  },
  {
    "UmaAndUkmDemographics",
    array_kFieldTrialConfig_experiments_234,
    1,
  },
  {
    "UnidoDeviceExpiration",
    array_kFieldTrialConfig_experiments_235,
    1,
  },
  {
    "UnidoOnSignIn",
    array_kFieldTrialConfig_experiments_236,
    1,
  },
  {
    "UpdateMenuItem",
    array_kFieldTrialConfig_experiments_237,
    1,
  },
  {
    "UseInProgressDownloadManagerForDownloadService",
    array_kFieldTrialConfig_experiments_238,
    1,
  },
  {
    "UseRegistrableDomainInNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_239,
    1,
  },
  {
    "UsernameFirstFlow",
    array_kFieldTrialConfig_experiments_240,
    1,
  },
  {
    "V8ConcurrentInlining",
    array_kFieldTrialConfig_experiments_241,
    2,
  },
  {
    "V8LowMemoryModeForSubframes",
    array_kFieldTrialConfig_experiments_242,
    2,
  },
  {
    "V8SiteIsolatedCodeCache",
    array_kFieldTrialConfig_experiments_243,
    1,
  },
  {
    "V8WasmCodeCache",
    array_kFieldTrialConfig_experiments_244,
    1,
  },
  {
    "V8WasmLiftoffMobile",
    array_kFieldTrialConfig_experiments_245,
    3,
  },
  {
    "VideoCaptureServiceAndroid",
    array_kFieldTrialConfig_experiments_246,
    1,
  },
  {
    "VideoSurfaceLayer",
    array_kFieldTrialConfig_experiments_247,
    1,
  },
  {
    "WebApkGooglePlay",
    array_kFieldTrialConfig_experiments_248,
    1,
  },
  {
    "WebAudioAutoplay",
    array_kFieldTrialConfig_experiments_249,
    1,
  },
  {
    "WebBluetoothBlocklist",
    array_kFieldTrialConfig_experiments_250,
    1,
  },
  {
    "WebPaymentsPerMethodCanMakePaymentQuota",
    array_kFieldTrialConfig_experiments_251,
    1,
  },
  {
    "WebRTC-Aec3FilterAnalyzerIncrementalAnalysisKillSwitch",
    array_kFieldTrialConfig_experiments_252,
    1,
  },
  {
    "WebRTC-Audio-NetEqDecelerationTargetLevelOffset",
    array_kFieldTrialConfig_experiments_253,
    1,
  },
  {
    "WebRTC-Audio-SendSideBwe",
    array_kFieldTrialConfig_experiments_254,
    1,
  },
  {
    "WebRTC-Bwe-MaxRttLimit",
    array_kFieldTrialConfig_experiments_255,
    1,
  },
  {
    "WebRTC-CongestionWindow",
    array_kFieldTrialConfig_experiments_256,
    1,
  },
  {
    "WebRTC-EnableWebRtcEcdsa",
    array_kFieldTrialConfig_experiments_257,
    1,
  },
  {
    "WebRTC-LocalIPPermissionCheck",
    array_kFieldTrialConfig_experiments_258,
    1,
  },
  {
    "WebRTC-Pacer-BlockAudio",
    array_kFieldTrialConfig_experiments_259,
    1,
  },
  {
    "WebRTC-VP8ConferenceTemporalLayers",
    array_kFieldTrialConfig_experiments_260,
    1,
  },
  {
    "WebRTC-Video-MinVideoBitrate",
    array_kFieldTrialConfig_experiments_261,
    1,
  },
  {
    "WebRTC-VideoRateControl",
    array_kFieldTrialConfig_experiments_262,
    1,
  },
  {
    "WebRtcHybridAgc",
    array_kFieldTrialConfig_experiments_263,
    1,
  },
  {
    "WebViewWakeMetricsService",
    array_kFieldTrialConfig_experiments_264,
    1,
  },
  {
    "history-manipulation-intervention",
    array_kFieldTrialConfig_experiments_265,
    1,
  },
  {
    "use-new-media-cache",
    array_kFieldTrialConfig_experiments_266,
    1,
  },
};
const FieldTrialTestingConfig kFieldTrialConfig = {
  array_kFieldTrialConfig_studies,
  268,
};

}  // namespace variations
