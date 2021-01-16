// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#ifndef GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
#define GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_

#include "gpu/config/gpu_driver_bug_workaround_type.h"

namespace gpu {
const int kFeatureListForWorkaroundsEntry1[1] = {
USE_CLIENT_SIDE_ARRAYS_FOR_STREAM_BUFFERS,
};

const uint32_t kCrBugsForWorkaroundsEntry1[1] = {
178093,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry1 = {
"Imagination.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry1_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry2[1] = {
USE_CLIENT_SIDE_ARRAYS_FOR_STREAM_BUFFERS,
};

const uint32_t kCrBugsForWorkaroundsEntry2[1] = {
178093,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry2 = {
"ARM.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry2_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry6[1] = {
RESTORE_SCISSOR_ON_FBO_CHANGE,
};

const uint32_t kCrBugsForWorkaroundsEntry6[2] = {
165493,
222018,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry6 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry6_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry19[1] = {
DISABLE_DEPTH_TEXTURE,
};

const char* const kDisabledExtensionsForEntry19[1] = {
"GL_OES_depth_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry19[1] = {
682075,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry19 = {
nullptr,
"Adreno \\(TM\\) [23].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry19_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry21[1] = {
UNBIND_FBO_ON_CONTEXT_SWITCH,
};

const uint32_t kCrBugsForWorkaroundsEntry21[2] = {
179250,
235935,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry21 = {
nullptr,
nullptr,
".*GL_VIV_shader_binary.*",
nullptr,
};

const GpuControlList::More kMoreForEntry21_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry22[1] = {
UNBIND_FBO_ON_CONTEXT_SWITCH,
};

const uint32_t kCrBugsForWorkaroundsEntry22[1] = {
230896,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry22 = {
"Imagination.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry22_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry24[1] = {
USE_NON_ZERO_SIZE_FOR_CLIENT_SIDE_STREAM_BUFFERS,
};

const uint32_t kCrBugsForWorkaroundsEntry24[1] = {
231082,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry24 = {
"ARM.*",
".*Mali-4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry24_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry31[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry31[6] = {
154715,
10068,
269829,
294779,
285292,
1018528,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry31 = {
"ARM.*",
"Mali-[T34].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry31_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry32[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry32[1] = {
179815,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry32 = {
"Broadcom.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry32_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry33[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry33 = {
"Imagination.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry33_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry34[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry34[3] = {
179250,
229643,
230896,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry34 = {
nullptr,
nullptr,
".*GL_VIV_shader_binary.*",
nullptr,
};

const GpuControlList::More kMoreForEntry34_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry35[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry35[1] = {
163464,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry35 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry35_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry38[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry38[3] = {
163464,
233612,
289461,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry38 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry38_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry40[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry40[1] = {
290876,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry40 = {
"ARM.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry40_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry42[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry42[2] = {
290876,
488463,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry42 = {
"Imagination.*",
"PowerVR SGX 5.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry42_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry43[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry43[1] = {
299494,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry43 = {
nullptr,
nullptr,
".*GL_VIV_shader_binary.*",
nullptr,
};

const GpuControlList::More kMoreForEntry43_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry49[1] = {
WAKE_UP_GPU_BEFORE_DRAWING,
};

const uint32_t kCrBugsForWorkaroundsEntry49[1] = {
309734,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry49 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry49_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry54[1] = {
CLEAR_UNIFORMS_BEFORE_FIRST_PROGRAM_USE,
};

const uint32_t kCrBugsForWorkaroundsEntry54[2] = {
124764,
349137,
};

const GpuControlList::More kMoreForEntry54_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry54_619971032Exception0 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry71[1] = {
"GL_OES_standard_derivatives",
};

const uint32_t kCrBugsForWorkaroundsEntry71[1] = {
368005,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry71 = {
nullptr,
nullptr,
".*GL_VIV_shader_binary.*",
nullptr,
};

const GpuControlList::More kMoreForEntry71_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry72[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry72[1] = {
369316,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry72 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry72_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "3.1", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry74[1] = {
"EGL_KHR_fence_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry74[2] = {
278606,
382686,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry74 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry74_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry75[1] = {
"GL_EXT_multisampled_render_to_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry75[1] = {
362435,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry75 = {
"ARM.*",
".*Mali-4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry75_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry76[1] = {
"EGL_KHR_fence_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry76[1] = {
371530,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry76 = {
"Imagination Technologies.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry76_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry77[1] = {
"EGL_KHR_fence_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry77[4] = {
378691,
373360,
371530,
398964,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry77 = {
"ARM.*",
"Mali.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry77_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry78[1] = {
"EGL_KHR_fence_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry78[3] = {
378691,
373360,
371530,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry78 = {
"Broadcom.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry78_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry82[1] = {
DISABLE_ASYNC_READPIXELS,
};

const uint32_t kCrBugsForWorkaroundsEntry82[1] = {
394510,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry82 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry82_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry88[1] = {
SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS,
};

const uint32_t kCrBugsForWorkaroundsEntry88[1] = {
398694,
};

const GpuControlList::More kMoreForEntry88_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry91[1] = {
ETC1_POWER_OF_TWO_ONLY,
};

const uint32_t kCrBugsForWorkaroundsEntry91[2] = {
150500,
414816,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry91 = {
"Imagination.*",
"PowerVR SGX 5.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry91_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry93[1] = {
DISABLE_ASYNC_READPIXELS,
};

const uint32_t kCrBugsForWorkaroundsEntry93[1] = {
340882,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry93 = {
"VMware.*",
"Gallium.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry93_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry94[1] = {
"EGL_KHR_wait_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry94[1] = {
433057,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry94 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry94_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "3.1", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry95[1] = {
GL_CLEAR_BROKEN,
};

const uint32_t kCrBugsForWorkaroundsEntry95[1] = {
421271,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry95 = {
"Imagination.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry95_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry97[1] = {
DISABLE_CHROMIUM_FRAMEBUFFER_MULTISAMPLE,
};

const uint32_t kCrBugsForWorkaroundsEntry97[1] = {
443517,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry97 = {
"Intel.*",
"Intel.*BayTrail",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry97_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry98[1] = {
USE_NON_ZERO_SIZE_FOR_CLIENT_SIDE_STREAM_BUFFERS,
};

const uint32_t kCrBugsForWorkaroundsEntry98[1] = {
451501,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry98 = {
"Imagination.*",
"PowerVR SGX 540",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry98_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry99[1] = {
IGNORE_EGL_SYNC_FAILURES,
};

const uint32_t kCrBugsForWorkaroundsEntry99[1] = {
453857,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry99 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry99_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry102[1] = {
UNBIND_ATTACHMENTS_ON_BOUND_RENDER_FBO_DELETE,
};

const uint32_t kCrBugsForWorkaroundsEntry102[1] = {
457027,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry102 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry102_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry103[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry103[1] = {
443060,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry103 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry103_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry104[1] = {
"GL_EXT_occlusion_query_boolean",
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry104 = {
"Imagination.*",
"PowerVR Rogue Han",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry104_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry105[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry105[2] = {
449488,
451230,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry105 = {
nullptr,
"Mali-4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry105_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry106[1] = {
"GL_EXT_occlusion_query_boolean",
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry106 = {
"Imagination.*",
"PowerVR SGX 544",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry106_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry107[1] = {
AVOID_EGL_IMAGE_TARGET_TEXTURE_REUSE,
};

const char* const kDisabledExtensionsForEntry107[1] = {
"EGL_KHR_wait_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry107[1] = {
480992,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry107 = {
nullptr,  // driver_vendor
{GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, "1.3", "1.4"},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry107 = {
"Imagination.*",
"PowerVR Rogue.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry107_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry110[1] = {
"EGL_KHR_wait_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry110[1] = {
482298,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry110 = {
nullptr,  // driver_vendor
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "95", nullptr},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry110 = {
"Qualcomm.*",
"Adreno \\(TM\\) [23].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry110_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry112[1] = {
DISABLE_TIMESTAMP_QUERIES,
};

const char* const kDisabledExtensionsForEntry112[2] = {
"GL_EXT_disjoint_timer_query",
"GL_EXT_disjoint_timer_query_webgl2",
};

const uint32_t kCrBugsForWorkaroundsEntry112[1] = {
477514,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry112 = {
"Qualcomm.*",
"Adreno \\(TM\\) 3.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry112_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry113[2] = {
"GL_EXT_disjoint_timer_query",
"GL_EXT_disjoint_timer_query_webgl2",
};

const uint32_t kCrBugsForWorkaroundsEntry113[1] = {
477514,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry113 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry113_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry115[1] = {
"GL_EXT_disjoint_timer_query",
};

const uint32_t kCrBugsForWorkaroundsEntry115[1] = {
462553,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry115 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry115_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry116[1] = {
DISABLE_CHROMIUM_FRAMEBUFFER_MULTISAMPLE,
};

const char* const kDisabledExtensionsForEntry116[1] = {
"GL_EXT_multisampled_render_to_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry116[2] = {
490379,
767913,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry116 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry116_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry117[1] = {
DISABLE_BLEND_EQUATION_ADVANCED,
};

const uint32_t kCrBugsForWorkaroundsEntry117[1] = {
488485,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry117 = {
"Qualcomm.*",
".*4\\d\\d",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry117_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry119[1] = {
EXIT_ON_CONTEXT_LOST,
};

const uint32_t kCrBugsForWorkaroundsEntry119[1] = {
496438,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry119 = {
"ARM.*",
".*Mali-4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry119_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry120[1] = {
MAX_COPY_TEXTURE_CHROMIUM_SIZE_262144,
};

const uint32_t kCrBugsForWorkaroundsEntry120[1] = {
498443,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry120 = {
"ARM.*",
"Mali.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry120_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry125[1] = {
UNBIND_EGL_CONTEXT_TO_FLUSH_DRIVER_CACHES,
};

const uint32_t kCrBugsForWorkaroundsEntry125[1] = {
509727,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry125 = {
nullptr,
"Adreno.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry125_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry126[1] = {
DISABLE_PROGRAM_CACHE,
};

const uint32_t kCrBugsForWorkaroundsEntry126[1] = {
510637,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry126 = {
nullptr,
"Adreno \\(TM\\) 3.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry126_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry127[1] = {
FORCE_CUBE_MAP_POSITIVE_X_ALLOCATION,
};

const uint32_t kCrBugsForWorkaroundsEntry127[1] = {
518889,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry127 = {
nullptr,
"Adreno.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry127_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry132[1] = {
MSAA_IS_SLOW,
};

const uint32_t kCrBugsForWorkaroundsEntry132[1] = {
527565,
};

const GpuControlList::More kMoreForEntry132_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry133[1] = {
MAX_COPY_TEXTURE_CHROMIUM_SIZE_1048576,
};

const uint32_t kCrBugsForWorkaroundsEntry133[1] = {
542478,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry133 = {
nullptr,
"Adreno.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry133_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry134[1] = {
"GL_EXT_sRGB",
};

const uint32_t kCrBugsForWorkaroundsEntry134[1] = {
550292,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry134 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry134_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry137[1] = {
FORCE_CUBE_COMPLETE,
};

const uint32_t kCrBugsForWorkaroundsEntry137[1] = {
518889,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry137 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry137_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry138[1] = {
"GL_NV_path_rendering",
};

const uint32_t kCrBugsForWorkaroundsEntry138[1] = {
344330,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry138 = {
nullptr,  // driver_vendor
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "346", nullptr},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry138 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry138_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry140[1] = {
"GL_EXT_sRGB",
};

const uint32_t kCrBugsForWorkaroundsEntry140[2] = {
550292,
565179,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry140 = {
"Qualcomm",
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry140_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry145[1] = {
BROKEN_EGL_IMAGE_REF_COUNTING,
};

const uint32_t kCrBugsForWorkaroundsEntry145[1] = {
585250,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry145 = {
"Qualcomm.*",
"Adreno \\(TM\\) [45].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry145_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry147[1] = {
MAX_TEXTURE_SIZE_LIMIT_4096,
};

const GpuControlList::More kMoreForEntry147_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry157[1] = {
"EGL_KHR_fence_sync",
};

const uint32_t kCrBugsForWorkaroundsEntry157[1] = {
589814,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry157 = {
"ARM.*",
"Mali.*",
nullptr,
nullptr,
};

const char* const kMachineModelNameForEntry157[2] = {
"SM-G361H",
"SM-G531H",
};

const GpuControlList::MachineModelInfo kMachineModelInfoForEntry157 = {
base::size(kMachineModelNameForEntry157),  // machine model name size
kMachineModelNameForEntry157,  // machine model names
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // machine model version
};

const GpuControlList::More kMoreForEntry157_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry162[1] = {
DISABLE_DISCARD_FRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry162[1] = {
601753,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry162 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry162_619971032 = {
GpuControlList::kGLTypeGLES,  // gl_type
{GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, "3.0", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry165[1] = {
UNPACK_OVERLAPPING_ROWS_SEPARATELY_UNPACK_BUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry165[1] = {
596774,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry165 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry165_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry174[1] = {
"GL_EXT_multisampled_render_to_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry174[1] = {
612474,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry174 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry174_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry175[1] = {
"GL_EXT_multisampled_render_to_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry175[1] = {
612474,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry175 = {
nullptr,
"Adreno \\(TM\\) 5.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry175_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry176[1] = {
GL_CLEAR_BROKEN,
};

const uint32_t kCrBugsForWorkaroundsEntry176[1] = {
633634,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry176 = {
"Intel.*",
".*Atom.*x5/x7.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry176_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry178[1] = {
DISABLE_BLEND_EQUATION_ADVANCED,
};

const uint32_t kCrBugsForWorkaroundsEntry178[1] = {
639470,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry178 = {
"Intel.*",
"Intel(R) HD Graphics for BayTrail",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry178_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry180[1] = {
AVOID_ONE_COMPONENT_EGL_IMAGES,
};

const uint32_t kCrBugsForWorkaroundsEntry180[2] = {
579060,
632461,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry180 = {
"Imagination.*",
"PowerVR .*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry180_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry182[1] = {
GL_CLEAR_BROKEN,
};

const uint32_t kCrBugsForWorkaroundsEntry182[1] = {
638691,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry182 = {
nullptr,
".*Mali-T7.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry182_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry192[1] = {
DECODE_ENCODE_SRGB_FOR_GENERATEMIPMAP,
};

const uint32_t kCrBugsForWorkaroundsEntry192[1] = {
634519,
};

const GpuControlList::More kMoreForEntry192_619971032 = {
GpuControlList::kGLTypeGL,  // gl_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.4", nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry192_619971032Exception0 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry200[1] = {
DISABLE_ES3_GL_CONTEXT,
};

const uint32_t kCrBugsForWorkaroundsEntry200[1] = {
657925,
};

const GpuControlList::More kMoreForEntry200_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry205[1] = {
"GL_EXT_multisampled_render_to_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry205[1] = {
663811,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry205 = {
nullptr,
"Adreno \\(TM\\) 5.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry205_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry206[2] = {
"GL_KHR_blend_equation_advanced",
"GL_KHR_blend_equation_advanced_coherent",
};

const uint32_t kCrBugsForWorkaroundsEntry206[1] = {
661715,
};

const GpuControlList::More kMoreForEntry206_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry212[1] = {
DISABLE_PROGRAM_CACHING_FOR_TRANSFORM_FEEDBACK,
};

const uint32_t kCrBugsForWorkaroundsEntry212[1] = {
658074,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry212 = {
nullptr,
"Adreno.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry212_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry213[1] = {
USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry213[1] = {
678508,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry213 = {
"ARM.*",
"Mali-G.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry213_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry214[2] = {
DISABLE_CHROMIUM_FRAMEBUFFER_MULTISAMPLE,
FORCE_UPDATE_SCISSOR_STATE_WHEN_BINDING_FBO0,
};

const uint32_t kCrBugsForWorkaroundsEntry214[5] = {
670607,
682075,
696627,
698197,
707839,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry214 = {
nullptr,
"Adreno \\(TM\\) 3.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry214_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry215[1] = {
USE_GPU_DRIVER_WORKAROUND_FOR_TESTING,
};

const uint32_t kCrBugsForWorkaroundsEntry215[1] = {
682912,
};

const GpuControlList::More kMoreForEntry215_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
1,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry216[1] = {
PACK_PARAMETERS_WORKAROUND_WITH_PACK_BUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry216[1] = {
698926,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry216 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry216_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry217[1] = {
UNPACK_ALIGNMENT_WORKAROUND_WITH_UNPACK_BUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry217[1] = {
698926,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry217 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry217_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry218[1] = {
DISABLE_PROGRAM_DISK_CACHE,
};

const uint32_t kCrBugsForWorkaroundsEntry218[1] = {
699122,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry218 = {
nullptr,  // driver_vendor
{GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, "103.0", nullptr},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry218 = {
nullptr,
"Adreno \\(TM\\) [45].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry218_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry221[1] = {
DISALLOW_LARGE_INSTANCED_DRAW,
};

const uint32_t kCrBugsForWorkaroundsEntry221[1] = {
701682,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry221 = {
nullptr,
"Adreno \\(TM\\) 3.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry221_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry231[1] = {
MULTISAMPLE_RENDERBUFFER_RESIZE_EMULATION,
};

const uint32_t kCrBugsForWorkaroundsEntry231[1] = {
696126,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry231 = {
nullptr,
"Adreno \\(TM\\) [45].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry231_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry237[1] = {
DONT_DISABLE_WEBGL_WHEN_COMPOSITOR_CONTEXT_LOST,
};

const uint32_t kCrBugsForWorkaroundsEntry237[1] = {
744678,
};

const GpuControlList::More kMoreForEntry237_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry240[2] = {
"GL_EXT_disjoint_timer_query",
"GL_EXT_disjoint_timer_query_webgl2",
};

const uint32_t kCrBugsForWorkaroundsEntry240[2] = {
750306,
764526,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry240 = {
nullptr,
"Adreno \\(TM\\) [345].*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry240_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry241[1] = {
MSAA_IS_SLOW,
};

const uint32_t kCrBugsForWorkaroundsEntry241[1] = {
759471,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry241 = {
"Intel.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry241_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry242[1] = {
DONT_INITIALIZE_UNINITIALIZED_LOCALS,
};

const uint32_t kCrBugsForWorkaroundsEntry242[1] = {
728271,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry242 = {
nullptr,
"Adreno \\(TM\\) 4.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry242_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry246[1] = {
DONT_USE_LOOPS_TO_INITIALIZE_VARIABLES,
};

const uint32_t kCrBugsForWorkaroundsEntry246[1] = {
784817,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry246 = {
nullptr,
"Adreno \\(TM\\) *",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry246_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry247[1] = {
"GL_EXT_disjoint_timer_query",
};

const uint32_t kCrBugsForWorkaroundsEntry247[1] = {
702980,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry247 = {
"ARM.*",
"Mali-T880",
nullptr,
nullptr,
};

const char* const kMachineModelNameForEntry247[1] = {
"SM-G930F",
};

const GpuControlList::MachineModelInfo kMachineModelInfoForEntry247 = {
base::size(kMachineModelNameForEntry247),  // machine model name size
kMachineModelNameForEntry247,  // machine model names
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // machine model version
};

const GpuControlList::More kMoreForEntry247_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry251[1] = {
DISABLE_PROGRAM_CACHE,
};

const uint32_t kCrBugsForWorkaroundsEntry251[1] = {
780498,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry251 = {
nullptr,
nullptr,
".*GL_VIV_shader_binary.*",
nullptr,
};

const GpuControlList::More kMoreForEntry251_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledWebGLExtensionsForEntry256[2] = {
"EXT_disjoint_timer_query",
"EXT_disjoint_timer_query_webgl2",
};

const uint32_t kCrBugsForWorkaroundsEntry256[1] = {
808744,
};

const GpuControlList::More kMoreForEntry256_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledWebGLExtensionsForEntry257[1] = {
"WEBGL_lose_context",
};

const uint32_t kCrBugsForWorkaroundsEntry257[1] = {
808744,
};

const GpuControlList::More kMoreForEntry257_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
2,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry260[1] = {
DONT_USE_EGLCLIENTWAITSYNC_WITH_TIMEOUT,
};

const uint32_t kCrBugsForWorkaroundsEntry260[1] = {
760389,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry260 = {
nullptr,
"Adreno \\(TM\\) 540",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry260_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry262[1] = {
INIT_GL_POSITION_IN_VERTEX_SHADER,
};

const uint32_t kCrBugsForWorkaroundsEntry262[2] = {
286468,
416670,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry262 = {
"Imagination.*",
"PowerVR.*GX6250",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry262_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry263[1] = {
INIT_GL_POSITION_IN_VERTEX_SHADER,
};

const uint32_t kCrBugsForWorkaroundsEntry263[2] = {
286468,
416670,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry263 = {
"Imagination.*",
"PowerVR SGX 54.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry263_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry264[1] = {
INIT_GL_POSITION_IN_VERTEX_SHADER,
};

const uint32_t kCrBugsForWorkaroundsEntry264[2] = {
286468,
416670,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry264 = {
"Imagination.*",
"PowerVR.*G6200.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry264_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry266[1] = {
DISABLE_TIMESTAMP_QUERIES,
};

const char* const kDisabledExtensionsForEntry266[2] = {
"GL_EXT_disjoint_timer_query",
"GL_EXT_disjoint_timer_query_webgl2",
};

const uint32_t kCrBugsForWorkaroundsEntry266[1] = {
828721,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry266 = {
"NetEase",
"MuMu GL.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry266_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry268[1] = {
MAX_MSAA_SAMPLE_COUNT_4,
};

const uint32_t kCrBugsForWorkaroundsEntry268[1] = {
797243,
};

const GpuControlList::More kMoreForEntry268_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry271[1] = {
GL_CLEAR_BROKEN,
};

const uint32_t kCrBugsForWorkaroundsEntry271[1] = {
860418,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry271 = {
nullptr,  // driver_vendor
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "12.1.01alp0", nullptr},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry271 = {
nullptr,
".*Mali-T7.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry271_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry272[1] = {
DISABLE_TIMESTAMP_QUERIES,
};

const uint32_t kCrBugsForWorkaroundsEntry272[1] = {
858879,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry272 = {
"Qualcomm.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry272_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry273[1] = {
USE_ES2_FOR_OOPR,
};

const uint32_t kCrBugsForWorkaroundsEntry273[2] = {
866613,
860021,
};

const GpuControlList::More kMoreForEntry273_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry280[1] = {
USE_COPYTEXIMAGE2D_INSTEAD_OF_READPIXELS_ON_MULTISAMPLED_TEXTURES,
};

const uint32_t kCrBugsForWorkaroundsEntry280[1] = {
890002,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry280 = {
nullptr,  // driver_vendor
{GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, "237.0", nullptr},  // driver_version
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry280 = {
nullptr,
"Adreno \\(TM\\) .*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry280_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry289[1] = {
DISABLE_ES3_GL_CONTEXT_FOR_TESTING,
};

const uint32_t kCrBugsForWorkaroundsEntry289[1] = {
923134,
};

const GpuControlList::More kMoreForEntry289_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
3,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry290[1] = {
ROUND_DOWN_UNIFORM_BIND_BUFFER_RANGE_SIZE,
};

const uint32_t kCrBugsForWorkaroundsEntry290[1] = {
906743,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry290 = {
nullptr,
"Adreno \\(TM\\) .*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry290_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry292[1] = {
ADJUST_SRC_DST_REGION_FOR_BLITFRAMEBUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry292[1] = {
830046,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry292 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry292_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry293[1] = {
GL_CLEAR_BROKEN,
};

const uint32_t kCrBugsForWorkaroundsEntry293[1] = {
931527,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry293 = {
nullptr,  // driver_vendor
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "12.0.04rel0", nullptr},  // driver_version
};

const GpuControlList::More kMoreForEntry293_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry299[1] = {
EXIT_ON_CONTEXT_LOST,
};

const uint32_t kCrBugsForWorkaroundsEntry299[1] = {
942106,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry299 = {
"Imagination.*",
"PowerVR Rogue GE8.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry299_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry306[1] = {
DISABLE_PROGRAM_CACHING_FOR_TRANSFORM_FEEDBACK,
};

const uint32_t kCrBugsForWorkaroundsEntry306[1] = {
961950,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry306 = {
"ARM.*",
"Mali.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry306_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry312[1] = {
PREFER_DRAW_TO_COPY,
};

const uint32_t kCrBugsForWorkaroundsEntry312[1] = {
991869,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry312 = {
nullptr,
".*Mali-T8.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry312_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry314[1] = {
"GL_EXT_shader_framebuffer_fetch",
};

const uint32_t kCrBugsForWorkaroundsEntry314[1] = {
1010338,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry314 = {
nullptr,
"Adreno.*",
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry314_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry315[1] = {
"GL_MESA_framebuffer_flip_y",
};

const uint32_t kCrBugsForWorkaroundsEntry315[1] = {
964010,
};

const GpuControlList::More kMoreForEntry315_619971032 = {
GpuControlList::kGLTypeGL,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry320[1] = {
REMOVE_DYNAMIC_INDEXING_OF_SWIZZLED_VECTOR,
};

const uint32_t kCrBugsForWorkaroundsEntry320[1] = {
709351,
};

const GpuControlList::More kMoreForEntry320_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry334[1] = {
DONT_DELETE_SOURCE_TEXTURE_FOR_EGL_IMAGE,
};

const uint32_t kCrBugsForWorkaroundsEntry334[1] = {
1052114,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry334 = {
"NVIDIA.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry334_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry335[1] = {
DISABLE_AIMAGEREADER,
};

const uint32_t kCrBugsForWorkaroundsEntry335[1] = {
1051705,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry335 = {
"ARM.*",
nullptr,
nullptr,
nullptr,
};

const GpuControlList::More kMoreForEntry335_619971032 = {
GpuControlList::kGLTypeNone,  // gl_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gl_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // pixel_shader_version
false,  // in_process_gpu
0,  // gl_reset_notification_strategy
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // direct_rendering_version
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // gpu_count
GpuControlList::kDontCare,  // hardware_overlay
0,  // test_group
GpuControlList::kDontCare,  // subpixel_font_rendering
};

}  // namespace gpu

#endif  // GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
