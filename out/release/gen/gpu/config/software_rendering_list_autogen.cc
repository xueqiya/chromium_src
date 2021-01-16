// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/software_rendering_list_autogen.h"

#include "gpu/config/software_rendering_list_arrays_and_structs_autogen.h"
#include "gpu/config/software_rendering_list_exceptions_autogen.h"

namespace gpu {

const GpuControlList::Entry kSoftwareRenderingListEntries[] = {
{
4,  // id
"The Intel Mobile 945 Express family of chipsets is not compatible with WebGL",
base::size(kFeatureListForSoftwareEntry4),  // features size
kFeatureListForSoftwareEntry4,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry4),  // CrBugs size
kCrBugsForSoftwareEntry4,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
base::size(kDeviceIDsForSoftwareEntry4),  // DeviceIDs size
kDeviceIDsForSoftwareEntry4,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry4_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
8,  // id
"NVIDIA GeForce FX Go5200 is assumed to be buggy",
base::size(kFeatureListForSoftwareEntry8),  // features size
kFeatureListForSoftwareEntry8,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry8),  // CrBugs size
kCrBugsForSoftwareEntry8,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
base::size(kDeviceIDsForSoftwareEntry8),  // DeviceIDs size
kDeviceIDsForSoftwareEntry8,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry8_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
53,  // id
"The Intel GMA500 is too slow for Stage3D",
base::size(kFeatureListForSoftwareEntry53),  // features size
kFeatureListForSoftwareEntry53,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry53),  // CrBugs size
kCrBugsForSoftwareEntry53,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
base::size(kDeviceIDsForSoftwareEntry53),  // DeviceIDs size
kDeviceIDsForSoftwareEntry53,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry53_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
76,  // id
"WebGL is disabled on Android unless the GPU runs in a separate process or reset notification is supported",
base::size(kFeatureListForSoftwareEntry76),  // features size
kFeatureListForSoftwareEntry76,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry76_1043157500,  // more data
},
base::size(kExceptionsForEntry76),  // exceptions count
kExceptionsForEntry76,  // exceptions
},
{
96,  // id
"Blacklist GPU raster/canvas on all except known good GPUs and newer Android releases",
base::size(kFeatureListForSoftwareEntry96),  // features size
kFeatureListForSoftwareEntry96,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry96),  // CrBugs size
kCrBugsForSoftwareEntry96,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry96_1043157500,  // more data
},
base::size(kExceptionsForEntry96),  // exceptions count
kExceptionsForEntry96,  // exceptions
},
{
100,  // id
"GPU rasterization and canvas is blacklisted on Nexus 10",
base::size(kFeatureListForSoftwareEntry100),  // features size
kFeatureListForSoftwareEntry100,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry100),  // CrBugs size
kCrBugsForSoftwareEntry100,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry100,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry100_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
102,  // id
"Accelerated 2D canvas and Ganesh broken on Galaxy Tab 2",
base::size(kFeatureListForSoftwareEntry102),  // features size
kFeatureListForSoftwareEntry102,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry102),  // CrBugs size
kCrBugsForSoftwareEntry102,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry102,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry102_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
104,  // id
"GPU raster broken on PowerVR Rogue",
base::size(kFeatureListForSoftwareEntry104),  // features size
kFeatureListForSoftwareEntry104,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry104),  // CrBugs size
kCrBugsForSoftwareEntry104,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForSoftwareEntry104,  // driver info
&kGLStringsForSoftwareEntry104,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry104_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
105,  // id
"GPU raster broken on PowerVR SGX even on Lollipop",
base::size(kFeatureListForSoftwareEntry105),  // features size
kFeatureListForSoftwareEntry105,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry105),  // CrBugs size
kCrBugsForSoftwareEntry105,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry105,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry105_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
106,  // id
"GPU raster broken on ES2-only Adreno 3xx drivers",
base::size(kFeatureListForSoftwareEntry106),  // features size
kFeatureListForSoftwareEntry106,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry106),  // CrBugs size
kCrBugsForSoftwareEntry106,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry106,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry106_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
108,  // id
"GPU rasterization image color broken on Vivante",
base::size(kFeatureListForSoftwareEntry108),  // features size
kFeatureListForSoftwareEntry108,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry108),  // CrBugs size
kCrBugsForSoftwareEntry108,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry108,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry108_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
109,  // id
"MediaCodec on Adreno 330 / 4.2.2 doesn't always send FORMAT_CHANGED",
base::size(kFeatureListForSoftwareEntry109),  // features size
kFeatureListForSoftwareEntry109,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry109),  // CrBugs size
kCrBugsForSoftwareEntry109,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "4.2.2", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForSoftwareEntry109,  // driver info
&kGLStringsForSoftwareEntry109,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry109_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
117,  // id
"MediaCodec on Vivante hangs in MediaCodec often",
base::size(kFeatureListForSoftwareEntry117),  // features size
kFeatureListForSoftwareEntry117,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry117),  // CrBugs size
kCrBugsForSoftwareEntry117,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry117,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry117_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
118,  // id
"webgl/canvas crashy on imporperly parsed vivante driver",
base::size(kFeatureListForSoftwareEntry118),  // features size
kFeatureListForSoftwareEntry118,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry118),  // CrBugs size
kCrBugsForSoftwareEntry118,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry118,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry118_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
133,  // id
"MediaCodec on VideoCore IV HW crashes on JB",
base::size(kFeatureListForSoftwareEntry133),  // features size
kFeatureListForSoftwareEntry133,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry133),  // CrBugs size
kCrBugsForSoftwareEntry133,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry133,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry133_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
140,  // id
"MSAA and depth texture buggy on Adreno 3xx, also disable WebGL2",
base::size(kFeatureListForSoftwareEntry140),  // features size
kFeatureListForSoftwareEntry140,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry140),  // CrBugs size
kCrBugsForSoftwareEntry140,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry140,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry140_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
147,  // id
"GPU raster broken on Mali-T760 on KitKat",
base::size(kFeatureListForSoftwareEntry147),  // features size
kFeatureListForSoftwareEntry147,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry147),  // CrBugs size
kCrBugsForSoftwareEntry147,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry147,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry147_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
148,  // id
"VideoCore V has corrupt rendering with GPU Rasterization",
base::size(kFeatureListForSoftwareEntry148),  // features size
kFeatureListForSoftwareEntry148,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry148),  // CrBugs size
kCrBugsForSoftwareEntry148,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry148,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry148_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
149,  // id
"Adreno 420 support for EXT_multisampled_render_to_texture is buggy on Android < 5.1",
base::size(kFeatureListForSoftwareEntry149),  // features size
kFeatureListForSoftwareEntry149,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForSoftwareEntry149),  // CrBugs size
kCrBugsForSoftwareEntry149,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.1", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForSoftwareEntry149,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry149_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
152,  // id
"Test entry where all features except WebGL blacklisted",
base::size(kFeatureListForSoftwareEntry152),  // features size
kFeatureListForSoftwareEntry152,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry152_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
153,  // id
"Test entry where WebGL is blacklisted",
base::size(kFeatureListForSoftwareEntry153),  // features size
kFeatureListForSoftwareEntry153,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry153_1043157500,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
154,  // id
"Protected video decoding with swap chain is for Windows and Intel only",
base::size(kFeatureListForSoftwareEntry154),  // features size
kFeatureListForSoftwareEntry154,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry154_1043157500,  // more data
},
base::size(kExceptionsForEntry154),  // exceptions count
kExceptionsForEntry154,  // exceptions
},
};
const size_t kSoftwareRenderingListEntryCount = 22;
}  // namespace gpu
