// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/gpu_driver_bug_list_autogen.h"

#include "gpu/config/gpu_driver_bug_list_arrays_and_structs_autogen.h"
#include "gpu/config/gpu_driver_bug_list_exceptions_autogen.h"

namespace gpu {

const GpuControlList::Entry kGpuDriverBugListEntries[] = {
{
1,  // id
"Imagination driver doesn't like uploading lots of buffer data constantly",
base::size(kFeatureListForWorkaroundsEntry1),  // features size
kFeatureListForWorkaroundsEntry1,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry1),  // CrBugs size
kCrBugsForWorkaroundsEntry1,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry1,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry1_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
2,  // id
"ARM driver doesn't like uploading lots of buffer data constantly",
base::size(kFeatureListForWorkaroundsEntry2),  // features size
kFeatureListForWorkaroundsEntry2,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry2),  // CrBugs size
kCrBugsForWorkaroundsEntry2,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry2,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry2_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
6,  // id
"Restore scissor on FBO change with Qualcomm GPUs on older versions of Android",
base::size(kFeatureListForWorkaroundsEntry6),  // features size
kFeatureListForWorkaroundsEntry6,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry6),  // CrBugs size
kCrBugsForWorkaroundsEntry6,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.3", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry6,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry6_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
19,  // id
"Disable depth textures on older Qualcomm GPUs (legacy blacklist entry, original problem unclear)",
base::size(kFeatureListForWorkaroundsEntry19),  // features size
kFeatureListForWorkaroundsEntry19,  // features
base::size(kDisabledExtensionsForEntry19),  // DisabledExtensions size
kDisabledExtensionsForEntry19,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry19),  // CrBugs size
kCrBugsForWorkaroundsEntry19,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry19,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry19_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
21,  // id
"Vivante GPUs are buggy with context switching",
base::size(kFeatureListForWorkaroundsEntry21),  // features size
kFeatureListForWorkaroundsEntry21,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry21),  // CrBugs size
kCrBugsForWorkaroundsEntry21,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry21,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry21_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
22,  // id
"Imagination drivers are buggy with context switching",
base::size(kFeatureListForWorkaroundsEntry22),  // features size
kFeatureListForWorkaroundsEntry22,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry22),  // CrBugs size
kCrBugsForWorkaroundsEntry22,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry22,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry22_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
24,  // id
"Mali-4xx drivers throw an error when a buffer object's size is set to 0",
base::size(kFeatureListForWorkaroundsEntry24),  // features size
kFeatureListForWorkaroundsEntry24,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry24),  // CrBugs size
kCrBugsForWorkaroundsEntry24,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry24,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry24_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
31,  // id
"The Mali-3xx/4xx/Txxx driver does not guarantee flush ordering",
base::size(kFeatureListForWorkaroundsEntry31),  // features size
kFeatureListForWorkaroundsEntry31,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry31),  // CrBugs size
kCrBugsForWorkaroundsEntry31,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry31,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry31_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
32,  // id
"Share groups are not working on (older?) Broadcom drivers",
base::size(kFeatureListForWorkaroundsEntry32),  // features size
kFeatureListForWorkaroundsEntry32,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry32),  // CrBugs size
kCrBugsForWorkaroundsEntry32,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry32,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry32_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
33,  // id
"Share group-related crashes and poor context switching perf on Imagination drivers",
base::size(kFeatureListForWorkaroundsEntry33),  // features size
kFeatureListForWorkaroundsEntry33,  // features
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
&kGLStringsForWorkaroundsEntry33,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry33_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
34,  // id
"Share groups are not working on (older?) Vivante drivers",
base::size(kFeatureListForWorkaroundsEntry34),  // features size
kFeatureListForWorkaroundsEntry34,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry34),  // CrBugs size
kCrBugsForWorkaroundsEntry34,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry34,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry34_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
35,  // id
"Share-group related crashes on older NVIDIA drivers",
base::size(kFeatureListForWorkaroundsEntry35),  // features size
kFeatureListForWorkaroundsEntry35,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry35),  // CrBugs size
kCrBugsForWorkaroundsEntry35,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.3", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry35,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry35_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
38,  // id
"Non-virtual contexts on Qualcomm sometimes cause out-of-order frames",
base::size(kFeatureListForWorkaroundsEntry38),  // features size
kFeatureListForWorkaroundsEntry38,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry38),  // CrBugs size
kCrBugsForWorkaroundsEntry38,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry38,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry38_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
40,  // id
"Framebuffer discarding causes flickering on old ARM drivers",
base::size(kFeatureListForWorkaroundsEntry40),  // features size
kFeatureListForWorkaroundsEntry40,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry40),  // CrBugs size
kCrBugsForWorkaroundsEntry40,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry40,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry40_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
42,  // id
"Framebuffer discarding causes flickering on older IMG drivers",
base::size(kFeatureListForWorkaroundsEntry42),  // features size
kFeatureListForWorkaroundsEntry42,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry42),  // CrBugs size
kCrBugsForWorkaroundsEntry42,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry42,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry42_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
43,  // id
"Framebuffer discarding doesn't accept trivial attachments on Vivante",
base::size(kFeatureListForWorkaroundsEntry43),  // features size
kFeatureListForWorkaroundsEntry43,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry43),  // CrBugs size
kCrBugsForWorkaroundsEntry43,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry43,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry43_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
49,  // id
"The first draw operation from an idle state is slow",
base::size(kFeatureListForWorkaroundsEntry49),  // features size
kFeatureListForWorkaroundsEntry49,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry49),  // CrBugs size
kCrBugsForWorkaroundsEntry49,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry49,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry49_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
54,  // id
"Clear uniforms before first program use on all platforms",
base::size(kFeatureListForWorkaroundsEntry54),  // features size
kFeatureListForWorkaroundsEntry54,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry54),  // CrBugs size
kCrBugsForWorkaroundsEntry54,  // CrBugs
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
&kMoreForEntry54_619971032,  // more data
},
base::size(kExceptionsForEntry54),  // exceptions count
kExceptionsForEntry54,  // exceptions
},
{
71,  // id
"Vivante's support of OES_standard_derivatives is buggy",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry71),  // DisabledExtensions size
kDisabledExtensionsForEntry71,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry71),  // CrBugs size
kCrBugsForWorkaroundsEntry71,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry71,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry71_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
72,  // id
"Use virtual contexts on NVIDIA with GLES 3.1",
base::size(kFeatureListForWorkaroundsEntry72),  // features size
kFeatureListForWorkaroundsEntry72,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry72),  // CrBugs size
kCrBugsForWorkaroundsEntry72,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry72,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry72_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
74,  // id
"Testing EGL sync fences was broken on most Qualcomm drivers",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry74),  // DisabledExtensions size
kDisabledExtensionsForEntry74,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry74),  // CrBugs size
kCrBugsForWorkaroundsEntry74,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry74,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry74_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
75,  // id
"Mali-4xx support of EXT_multisampled_render_to_texture is buggy on Android < 4.3",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry75),  // DisabledExtensions size
kDisabledExtensionsForEntry75,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry75),  // CrBugs size
kCrBugsForWorkaroundsEntry75,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.3", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry75,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry75_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
76,  // id
"Testing EGL sync fences was broken on IMG",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry76),  // DisabledExtensions size
kDisabledExtensionsForEntry76,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry76),  // CrBugs size
kCrBugsForWorkaroundsEntry76,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry76,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry76_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
77,  // id
"Testing fences was broken on Mali ES2 drivers",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry77),  // DisabledExtensions size
kDisabledExtensionsForEntry77,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry77),  // CrBugs size
kCrBugsForWorkaroundsEntry77,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry77,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry77_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
78,  // id
"Testing fences was broken on Broadcom drivers",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry78),  // DisabledExtensions size
kDisabledExtensionsForEntry78,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry78),  // CrBugs size
kCrBugsForWorkaroundsEntry78,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "4.4.4", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry78,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry78_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
82,  // id
"PBO mappings segfault on certain older Qualcomm drivers",
base::size(kFeatureListForWorkaroundsEntry82),  // features size
kFeatureListForWorkaroundsEntry82,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry82),  // CrBugs size
kCrBugsForWorkaroundsEntry82,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.3", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry82,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry82_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
88,  // id
"Always rewrite vec/mat constructors to be consistent",
base::size(kFeatureListForWorkaroundsEntry88),  // features size
kFeatureListForWorkaroundsEntry88,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry88),  // CrBugs size
kCrBugsForWorkaroundsEntry88,  // CrBugs
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
&kMoreForEntry88_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
91,  // id
"ETC1 non-power-of-two sized textures crash older IMG drivers",
base::size(kFeatureListForWorkaroundsEntry91),  // features size
kFeatureListForWorkaroundsEntry91,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry91),  // CrBugs size
kCrBugsForWorkaroundsEntry91,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry91,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry91_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
93,  // id
"The GL implementation on the Android emulator has problems with PBOs.",
base::size(kFeatureListForWorkaroundsEntry93),  // features size
kFeatureListForWorkaroundsEntry93,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry93),  // CrBugs size
kCrBugsForWorkaroundsEntry93,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry93,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry93_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
94,  // id
"Disable EGL_KHR_wait_sync on NVIDIA with GLES 3.1",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry94),  // DisabledExtensions size
kDisabledExtensionsForEntry94,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry94),  // CrBugs size
kCrBugsForWorkaroundsEntry94,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, "5.0.2", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry94,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry94_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
95,  // id
"glClear does not always work on these drivers",
base::size(kFeatureListForWorkaroundsEntry95),  // features size
kFeatureListForWorkaroundsEntry95,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry95),  // CrBugs size
kCrBugsForWorkaroundsEntry95,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry95,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry95_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
97,  // id
"Multisampling has poor performance in Intel BayTrail",
base::size(kFeatureListForWorkaroundsEntry97),  // features size
kFeatureListForWorkaroundsEntry97,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry97),  // CrBugs size
kCrBugsForWorkaroundsEntry97,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry97,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry97_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
98,  // id
"PowerVR SGX 540 drivers throw GL_OUT_OF_MEMORY error when a buffer object's size is set to 0",
base::size(kFeatureListForWorkaroundsEntry98),  // features size
kFeatureListForWorkaroundsEntry98,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry98),  // CrBugs size
kCrBugsForWorkaroundsEntry98,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry98,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry98_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
99,  // id
"Qualcomm driver before Lollipop deletes egl sync objects after context destruction",
base::size(kFeatureListForWorkaroundsEntry99),  // features size
kFeatureListForWorkaroundsEntry99,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry99),  // CrBugs size
kCrBugsForWorkaroundsEntry99,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.0.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry99,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry99_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
102,  // id
"Adreno 420 driver loses FBO attachment contents on bound FBO deletion",
base::size(kFeatureListForWorkaroundsEntry102),  // features size
kFeatureListForWorkaroundsEntry102,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry102),  // CrBugs size
kCrBugsForWorkaroundsEntry102,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, "5.0.2", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry102,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry102_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
103,  // id
"Adreno 420 driver drops draw calls after FBO invalidation",
base::size(kFeatureListForWorkaroundsEntry103),  // features size
kFeatureListForWorkaroundsEntry103,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry103),  // CrBugs size
kCrBugsForWorkaroundsEntry103,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry103,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry103_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
104,  // id
"EXT_occlusion_query_boolean hangs on MediaTek MT8135 pre-Lollipop",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry104),  // DisabledExtensions size
kDisabledExtensionsForEntry104,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.0.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry104,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry104_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
105,  // id
"Framebuffer discarding causes corruption on Mali-4xx",
base::size(kFeatureListForWorkaroundsEntry105),  // features size
kFeatureListForWorkaroundsEntry105,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry105),  // CrBugs size
kCrBugsForWorkaroundsEntry105,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry105,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry105_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
106,  // id
"EXT_occlusion_query_boolean hangs on PowerVR SGX 544 (IMG) drivers",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry106),  // DisabledExtensions size
kDisabledExtensionsForEntry106,  // DisabledExtensions
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
&kGLStringsForWorkaroundsEntry106,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry106_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
107,  // id
"Workaround IMG PowerVR G6xxx drivers bugs",
base::size(kFeatureListForWorkaroundsEntry107),  // features size
kFeatureListForWorkaroundsEntry107,  // features
base::size(kDisabledExtensionsForEntry107),  // DisabledExtensions size
kDisabledExtensionsForEntry107,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry107),  // CrBugs size
kCrBugsForWorkaroundsEntry107,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, "5.0.0", "5.1.99"},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry107,  // driver info
&kGLStringsForWorkaroundsEntry107,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry107_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
110,  // id
"EGL Sync server causes crashes on Adreno 2xx and 3xx drivers",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry110),  // DisabledExtensions size
kDisabledExtensionsForEntry110,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry110),  // CrBugs size
kCrBugsForWorkaroundsEntry110,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry110,  // driver info
&kGLStringsForWorkaroundsEntry110,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry110_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
112,  // id
"EXT_disjoint_timer_query fails after 2 queries on adreno 3xx in lollypop",
base::size(kFeatureListForWorkaroundsEntry112),  // features size
kFeatureListForWorkaroundsEntry112,  // features
base::size(kDisabledExtensionsForEntry112),  // DisabledExtensions size
kDisabledExtensionsForEntry112,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry112),  // CrBugs size
kCrBugsForWorkaroundsEntry112,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, "5.0.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry112,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry112_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
113,  // id
"EXT_disjoint_timer_query fails after 256 queries on adreno 4xx",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry113),  // DisabledExtensions size
kDisabledExtensionsForEntry113,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry113),  // CrBugs size
kCrBugsForWorkaroundsEntry113,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry113,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry113_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
115,  // id
"glGetIntegerv with GL_GPU_DISJOINT_EXT causes GL_INVALID_ENUM error",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry115),  // DisabledExtensions size
kDisabledExtensionsForEntry115,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry115),  // CrBugs size
kCrBugsForWorkaroundsEntry115,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry115,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry115_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
116,  // id
"Adreno 420 support for EXT_multisampled_render_to_texture is buggy on Android < 5.1",
base::size(kFeatureListForWorkaroundsEntry116),  // features size
kFeatureListForWorkaroundsEntry116,  // features
base::size(kDisabledExtensionsForEntry116),  // DisabledExtensions size
kDisabledExtensionsForEntry116,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry116),  // CrBugs size
kCrBugsForWorkaroundsEntry116,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.1", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry116,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry116_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
117,  // id
"GL_KHR_blend_equation_advanced breaks blending on Adreno 4xx",
base::size(kFeatureListForWorkaroundsEntry117),  // features size
kFeatureListForWorkaroundsEntry117,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry117),  // CrBugs size
kCrBugsForWorkaroundsEntry117,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry117,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry117_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
119,  // id
"Context lost recovery often fails on Mali-400/450 on Android.",
base::size(kFeatureListForWorkaroundsEntry119),  // features size
kFeatureListForWorkaroundsEntry119,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry119),  // CrBugs size
kCrBugsForWorkaroundsEntry119,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry119,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry119_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
120,  // id
"CHROMIUM_copy_texture is slow on Mali pre-Lollipop",
base::size(kFeatureListForWorkaroundsEntry120),  // features size
kFeatureListForWorkaroundsEntry120,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry120),  // CrBugs size
kCrBugsForWorkaroundsEntry120,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.0.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry120,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry120_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
125,  // id
"glFinish doesn't clear caches on Android",
base::size(kFeatureListForWorkaroundsEntry125),  // features size
kFeatureListForWorkaroundsEntry125,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry125),  // CrBugs size
kCrBugsForWorkaroundsEntry125,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry125,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry125_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
126,  // id
"Program binaries contain incorrect bound attribute locations on Adreno 3xx GPUs",
base::size(kFeatureListForWorkaroundsEntry126),  // features size
kFeatureListForWorkaroundsEntry126,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry126),  // CrBugs size
kCrBugsForWorkaroundsEntry126,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry126,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry126_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
127,  // id
"Android Adreno crashes on binding incomplete cube map texture to FBO",
base::size(kFeatureListForWorkaroundsEntry127),  // features size
kFeatureListForWorkaroundsEntry127,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry127),  // CrBugs size
kCrBugsForWorkaroundsEntry127,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry127,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry127_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
132,  // id
"On Intel GPUs MSAA performance is not acceptable for GPU rasterization",
base::size(kFeatureListForWorkaroundsEntry132),  // features size
kFeatureListForWorkaroundsEntry132,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry132),  // CrBugs size
kCrBugsForWorkaroundsEntry132,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryActive,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry132_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
133,  // id
"CHROMIUM_copy_texture with 1MB copy per flush to avoid unwanted cache growth on Adreno",
base::size(kFeatureListForWorkaroundsEntry133),  // features size
kFeatureListForWorkaroundsEntry133,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry133),  // CrBugs size
kCrBugsForWorkaroundsEntry133,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry133,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry133_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
134,  // id
"glReadPixels fails on FBOs with SRGB_ALPHA textures",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry134),  // DisabledExtensions size
kDisabledExtensionsForEntry134,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry134),  // CrBugs size
kCrBugsForWorkaroundsEntry134,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry134,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry134_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
137,  // id
"NVIDIA fails glReadPixels from incomplete cube map texture",
base::size(kFeatureListForWorkaroundsEntry137),  // features size
kFeatureListForWorkaroundsEntry137,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry137),  // CrBugs size
kCrBugsForWorkaroundsEntry137,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry137,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry137_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
138,  // id
"NVIDIA drivers before 346 lack features in NV_path_rendering and related extensions to implement driver level path rendering.",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry138),  // DisabledExtensions size
kDisabledExtensionsForEntry138,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry138),  // CrBugs size
kCrBugsForWorkaroundsEntry138,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry138,  // driver info
&kGLStringsForWorkaroundsEntry138,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry138_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
140,  // id
"glReadPixels fails on FBOs with SRGB_ALPHA textures, Nexus 5X",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry140),  // DisabledExtensions size
kDisabledExtensionsForEntry140,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry140),  // CrBugs size
kCrBugsForWorkaroundsEntry140,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry140,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry140_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
145,  // id
"EGLImage ref counting across EGLContext/threads is broken",
base::size(kFeatureListForWorkaroundsEntry145),  // features size
kFeatureListForWorkaroundsEntry145,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry145),  // CrBugs size
kCrBugsForWorkaroundsEntry145,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry145,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry145_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
147,  // id
"Limit max texure size to 4096 on all of Android",
base::size(kFeatureListForWorkaroundsEntry147),  // features size
kFeatureListForWorkaroundsEntry147,  // features
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
&kMoreForEntry147_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
157,  // id
"Testing fences was broken on Mali ES2 drivers for specific phone models",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry157),  // DisabledExtensions size
kDisabledExtensionsForEntry157,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry157),  // CrBugs size
kCrBugsForWorkaroundsEntry157,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry157,  // GL strings
&kMachineModelInfoForEntry157,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry157_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
162,  // id
"Framebuffer discarding not useful on NVIDIA Kepler architecture and later",
base::size(kFeatureListForWorkaroundsEntry162),  // features size
kFeatureListForWorkaroundsEntry162,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry162),  // CrBugs size
kCrBugsForWorkaroundsEntry162,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry162,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry162_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
165,  // id
"Unpacking overlapping rows from unpack buffers is unstable on NVIDIA GL driver",
base::size(kFeatureListForWorkaroundsEntry165),  // features size
kFeatureListForWorkaroundsEntry165,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry165),  // CrBugs size
kCrBugsForWorkaroundsEntry165,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry165,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry165_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
174,  // id
"Adreno 4xx support for EXT_multisampled_render_to_texture is buggy on Android 7.0",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry174),  // DisabledExtensions size
kDisabledExtensionsForEntry174,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry174),  // CrBugs size
kCrBugsForWorkaroundsEntry174,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, "7.0.0", "7.0.99"},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry174,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry174_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
175,  // id
"Adreno 5xx support for EXT_multisampled_render_to_texture is buggy on Android < 7.0",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry175),  // DisabledExtensions size
kDisabledExtensionsForEntry175,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry175),  // CrBugs size
kCrBugsForWorkaroundsEntry175,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "7.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry175,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry175_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
176,  // id
"glClear does not work on Acer Predator GT-810",
base::size(kFeatureListForWorkaroundsEntry176),  // features size
kFeatureListForWorkaroundsEntry176,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry176),  // CrBugs size
kCrBugsForWorkaroundsEntry176,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry176,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry176_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
178,  // id
"GL_KHR_blend_equation_advanced is incorrectly implemented on Intel BayTrail on KitKat",
base::size(kFeatureListForWorkaroundsEntry178),  // features size
kFeatureListForWorkaroundsEntry178,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry178),  // CrBugs size
kCrBugsForWorkaroundsEntry178,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "5.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry178,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry178_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
180,  // id
"eglCreateImageKHR fails for one component textures on PowerVR",
base::size(kFeatureListForWorkaroundsEntry180),  // features size
kFeatureListForWorkaroundsEntry180,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry180),  // CrBugs size
kCrBugsForWorkaroundsEntry180,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry180,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry180_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
182,  // id
"Frequent hang in glClear on old android versions on Mali-T7xx",
base::size(kFeatureListForWorkaroundsEntry182),  // features size
kFeatureListForWorkaroundsEntry182,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry182),  // CrBugs size
kCrBugsForWorkaroundsEntry182,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "6.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry182,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry182_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
192,  // id
"Decode and encode before generateMipmap for srgb format textures on os except macosx",
base::size(kFeatureListForWorkaroundsEntry192),  // features size
kFeatureListForWorkaroundsEntry192,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry192),  // CrBugs size
kCrBugsForWorkaroundsEntry192,  // CrBugs
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
&kMoreForEntry192_619971032,  // more data
},
base::size(kExceptionsForEntry192),  // exceptions count
kExceptionsForEntry192,  // exceptions
},
{
200,  // id
"ES3 support is unreliable on some older drivers",
base::size(kFeatureListForWorkaroundsEntry200),  // features size
kFeatureListForWorkaroundsEntry200,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry200),  // CrBugs size
kCrBugsForWorkaroundsEntry200,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "4.4", nullptr},  // os_version
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
&kMoreForEntry200_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
205,  // id
"Adreno 5xx support for EXT_multisampled_render_to_texture is buggy on Android 7.1",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry205),  // DisabledExtensions size
kDisabledExtensionsForEntry205,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry205),  // CrBugs size
kCrBugsForWorkaroundsEntry205,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, "7.1.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry205,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry205_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
206,  // id
"Disable KHR_blend_equation_advanced until cc shaders are updated",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry206),  // DisabledExtensions size
kDisabledExtensionsForEntry206,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry206),  // CrBugs size
kCrBugsForWorkaroundsEntry206,  // CrBugs
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
&kMoreForEntry206_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
212,  // id
"Program binaries don't contain transform feedback varyings on Qualcomm GPUs",
base::size(kFeatureListForWorkaroundsEntry212),  // features size
kFeatureListForWorkaroundsEntry212,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry212),  // CrBugs size
kCrBugsForWorkaroundsEntry212,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry212,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry212_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
213,  // id
"The Mali-Gxx driver does not guarantee flush ordering",
base::size(kFeatureListForWorkaroundsEntry213),  // features size
kFeatureListForWorkaroundsEntry213,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry213),  // CrBugs size
kCrBugsForWorkaroundsEntry213,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry213,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry213_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
214,  // id
"Some Adreno 3xx don't setup scissor state correctly when FBO0 is bound, nor support MSAA properly.",
base::size(kFeatureListForWorkaroundsEntry214),  // features size
kFeatureListForWorkaroundsEntry214,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry214),  // CrBugs size
kCrBugsForWorkaroundsEntry214,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry214,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry214_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
215,  // id
"Fake no-op GPU driver bug workaround for testing",
base::size(kFeatureListForWorkaroundsEntry215),  // features size
kFeatureListForWorkaroundsEntry215,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry215),  // CrBugs size
kCrBugsForWorkaroundsEntry215,  // CrBugs
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
&kMoreForEntry215_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
216,  // id
"Pack parameters work incorrectly with pack buffer bound",
base::size(kFeatureListForWorkaroundsEntry216),  // features size
kFeatureListForWorkaroundsEntry216,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry216),  // CrBugs size
kCrBugsForWorkaroundsEntry216,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry216,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry216_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
217,  // id
"Alignment works incorrectly with unpack buffer bound",
base::size(kFeatureListForWorkaroundsEntry217),  // features size
kFeatureListForWorkaroundsEntry217,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry217),  // CrBugs size
kCrBugsForWorkaroundsEntry217,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry217,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry217_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
218,  // id
"Certain Adreno 4xx and 5xx drivers often crash in glProgramBinary.",
base::size(kFeatureListForWorkaroundsEntry218),  // features size
kFeatureListForWorkaroundsEntry218,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry218),  // CrBugs size
kCrBugsForWorkaroundsEntry218,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry218,  // driver info
&kGLStringsForWorkaroundsEntry218,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry218_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
221,  // id
"Very large instanced draw calls crash on some Adreno 3xx drivers",
base::size(kFeatureListForWorkaroundsEntry221),  // features size
kFeatureListForWorkaroundsEntry221,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry221),  // CrBugs size
kCrBugsForWorkaroundsEntry221,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry221,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry221_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
231,  // id
"Multisampled color renderbuffers can't be resized on Qualcomm 4xx/5xx",
base::size(kFeatureListForWorkaroundsEntry231),  // features size
kFeatureListForWorkaroundsEntry231,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry231),  // CrBugs size
kCrBugsForWorkaroundsEntry231,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry231,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry231_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
237,  // id
"eglSwapBuffers intermittently fails on Android when app goes to background",
base::size(kFeatureListForWorkaroundsEntry237),  // features size
kFeatureListForWorkaroundsEntry237,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry237),  // CrBugs size
kCrBugsForWorkaroundsEntry237,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "9.0", nullptr},  // os_version
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
&kMoreForEntry237_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
240,  // id
"glGetQueryObject(GL_QUERY_RESULT_AVAILABLE) blocks unexpectedly on Adreno",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry240),  // DisabledExtensions size
kDisabledExtensionsForEntry240,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry240),  // CrBugs size
kCrBugsForWorkaroundsEntry240,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "8.1", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry240,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry240_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
241,  // id
"On Intel GPUs MSAA performance is not acceptable for GPU rasterization. Duplicate of 132 for Android",
base::size(kFeatureListForWorkaroundsEntry241),  // features size
kFeatureListForWorkaroundsEntry241,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry241),  // CrBugs size
kCrBugsForWorkaroundsEntry241,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry241,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry241_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
242,  // id
"Code produced by local variable initialization often triggers crashes in Marshmallow Adreno driver",
base::size(kFeatureListForWorkaroundsEntry242),  // features size
kFeatureListForWorkaroundsEntry242,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry242),  // CrBugs size
kCrBugsForWorkaroundsEntry242,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "7.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry242,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry242_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
246,  // id
"Code produced by initializing variables using loops can trigger crashes on some Adreno drivers.",
base::size(kFeatureListForWorkaroundsEntry246),  // features size
kFeatureListForWorkaroundsEntry246,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry246),  // CrBugs size
kCrBugsForWorkaroundsEntry246,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry246,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry246_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
247,  // id
"EXT_disjoint_timer_query is broken on Samsung Galaxy S6",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry247),  // DisabledExtensions size
kDisabledExtensionsForEntry247,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry247),  // CrBugs size
kCrBugsForWorkaroundsEntry247,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry247,  // GL strings
&kMachineModelInfoForEntry247,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry247_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
251,  // id
"Vivante GPUs shader cache breaks rendering",
base::size(kFeatureListForWorkaroundsEntry251),  // features size
kFeatureListForWorkaroundsEntry251,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry251),  // CrBugs size
kCrBugsForWorkaroundsEntry251,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry251,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry251_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
256,  // id
"Don't expose disjoint_timer_query extensions to WebGL unless site isolation is enabled",
0,  // feature size
nullptr,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
base::size(kDisabledWebGLExtensionsForEntry256),  // DisabledWebGLExtensions size
kDisabledWebGLExtensionsForEntry256,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry256),  // CrBugs size
kCrBugsForWorkaroundsEntry256,  // CrBugs
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
&kMoreForEntry256_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
257,  // id
"Fake entry for testing disabling of WebGL extensions",
0,  // feature size
nullptr,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
base::size(kDisabledWebGLExtensionsForEntry257),  // DisabledWebGLExtensions size
kDisabledWebGLExtensionsForEntry257,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry257),  // CrBugs size
kCrBugsForWorkaroundsEntry257,  // CrBugs
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
&kMoreForEntry257_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
260,  // id
"eglClientWaitSyncKHR with nonzero timeout waits too long",
base::size(kFeatureListForWorkaroundsEntry260),  // features size
kFeatureListForWorkaroundsEntry260,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry260),  // CrBugs size
kCrBugsForWorkaroundsEntry260,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "8.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry260,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry260_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
262,  // id
"Program fails in PowerVR*GX6250 drivers if gl_Position is not set",
base::size(kFeatureListForWorkaroundsEntry262),  // features size
kFeatureListForWorkaroundsEntry262,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry262),  // CrBugs size
kCrBugsForWorkaroundsEntry262,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry262,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry262_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
263,  // id
"Program fails in PowerVR SGX54x drivers if gl_Position is not set",
base::size(kFeatureListForWorkaroundsEntry263),  // features size
kFeatureListForWorkaroundsEntry263,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry263),  // CrBugs size
kCrBugsForWorkaroundsEntry263,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry263,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry263_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
264,  // id
"Program fails in PowerVR G6200 drivers if gl_Position is not set",
base::size(kFeatureListForWorkaroundsEntry264),  // features size
kFeatureListForWorkaroundsEntry264,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry264),  // CrBugs size
kCrBugsForWorkaroundsEntry264,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry264,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry264_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
266,  // id
"Crash in gl::GLApiBase::glGetQueryObjectui64vFn with NetEase devices ",
base::size(kFeatureListForWorkaroundsEntry266),  // features size
kFeatureListForWorkaroundsEntry266,  // features
base::size(kDisabledExtensionsForEntry266),  // DisabledExtensions size
kDisabledExtensionsForEntry266,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry266),  // CrBugs size
kCrBugsForWorkaroundsEntry266,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry266,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry266_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
268,  // id
"Limit MSAA to 4x on Android devices",
base::size(kFeatureListForWorkaroundsEntry268),  // features size
kFeatureListForWorkaroundsEntry268,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry268),  // CrBugs size
kCrBugsForWorkaroundsEntry268,  // CrBugs
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
&kMoreForEntry268_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
271,  // id
"Frequent crashes in glClear on Mali-T7xx on N with driver 12.1.01alp0",
base::size(kFeatureListForWorkaroundsEntry271),  // features size
kFeatureListForWorkaroundsEntry271,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry271),  // CrBugs size
kCrBugsForWorkaroundsEntry271,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "8.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry271,  // driver info
&kGLStringsForWorkaroundsEntry271,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry271_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
272,  // id
"A deleted query id for GL_TIMESTAMP cannot be reused for other query targets",
base::size(kFeatureListForWorkaroundsEntry272),  // features size
kFeatureListForWorkaroundsEntry272,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry272),  // CrBugs size
kCrBugsForWorkaroundsEntry272,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry272,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry272_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
273,  // id
"Frequent crashes on Adreno (TM) on L and below",
base::size(kFeatureListForWorkaroundsEntry273),  // features size
kFeatureListForWorkaroundsEntry273,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry273),  // CrBugs size
kCrBugsForWorkaroundsEntry273,  // CrBugs
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
&kMoreForEntry273_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
280,  // id
"ReadPixels is broken with EXT_multisampled_render_to_texture on recent Adreno drivers.",
base::size(kFeatureListForWorkaroundsEntry280),  // features size
kFeatureListForWorkaroundsEntry280,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry280),  // CrBugs size
kCrBugsForWorkaroundsEntry280,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry280,  // driver info
&kGLStringsForWorkaroundsEntry280,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry280_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
289,  // id
"Fake entry for testing command buffer init failures on ES 2.0",
base::size(kFeatureListForWorkaroundsEntry289),  // features size
kFeatureListForWorkaroundsEntry289,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry289),  // CrBugs size
kCrBugsForWorkaroundsEntry289,  // CrBugs
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
&kMoreForEntry289_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
290,  // id
"Round down glBindBufferRange size to a multiple of 4 on Qualcomm Adreno GPUs for uniform buffers",
base::size(kFeatureListForWorkaroundsEntry290),  // features size
kFeatureListForWorkaroundsEntry290,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry290),  // CrBugs size
kCrBugsForWorkaroundsEntry290,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry290,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry290_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
292,  // id
"adjust src/dst region if blitting pixels outside framebuffer on Android NVIDIA",
base::size(kFeatureListForWorkaroundsEntry292),  // features size
kFeatureListForWorkaroundsEntry292,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry292),  // CrBugs size
kCrBugsForWorkaroundsEntry292,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry292,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry292_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
293,  // id
"Frequent crashes in glClear on Android N with driver 12.0.04rel0",
base::size(kFeatureListForWorkaroundsEntry293),  // features size
kFeatureListForWorkaroundsEntry293,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry293),  // CrBugs size
kCrBugsForWorkaroundsEntry293,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "8.0", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry293,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry293_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
299,  // id
"Context lost recovery often fails on PowerVR Rogue GE8* GPUs on Android.",
base::size(kFeatureListForWorkaroundsEntry299),  // features size
kFeatureListForWorkaroundsEntry299,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry299),  // CrBugs size
kCrBugsForWorkaroundsEntry299,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry299,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry299_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
306,  // id
"Program binaries don't contain transform feedback varyings on Mali GPUs",
base::size(kFeatureListForWorkaroundsEntry306),  // features size
kFeatureListForWorkaroundsEntry306,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry306),  // CrBugs size
kCrBugsForWorkaroundsEntry306,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry306,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry306_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
312,  // id
"Crash on Mali-T8x when using glTexImage2D",
base::size(kFeatureListForWorkaroundsEntry312),  // features size
kFeatureListForWorkaroundsEntry312,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry312),  // CrBugs size
kCrBugsForWorkaroundsEntry312,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry312,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry312_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
314,  // id
"Crash on Adreno when using GL_EXT_shader_framebuffer_fetch",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry314),  // DisabledExtensions size
kDisabledExtensionsForEntry314,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry314),  // CrBugs size
kCrBugsForWorkaroundsEntry314,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry314,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry314_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
315,  // id
"Disable GL_MESA_framebuffer_flip_y for desktop GL",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry315),  // DisabledExtensions size
kDisabledExtensionsForEntry315,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry315),  // CrBugs size
kCrBugsForWorkaroundsEntry315,  // CrBugs
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
&kMoreForEntry315_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
320,  // id
"Remove dynamic indexing for swizzled vectors on Android",
base::size(kFeatureListForWorkaroundsEntry320),  // features size
kFeatureListForWorkaroundsEntry320,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry320),  // CrBugs size
kCrBugsForWorkaroundsEntry320,  // CrBugs
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
&kMoreForEntry320_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
334,  // id
"NVidia drivers seem corrupt memory when all siblings of eglImage are destroyed",
base::size(kFeatureListForWorkaroundsEntry334),  // features size
kFeatureListForWorkaroundsEntry334,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry334),  // CrBugs size
kCrBugsForWorkaroundsEntry334,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry334,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry334_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
335,  // id
"Disable AImageReader on ARM GPUs",
base::size(kFeatureListForWorkaroundsEntry335),  // features size
kFeatureListForWorkaroundsEntry335,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry335),  // CrBugs size
kCrBugsForWorkaroundsEntry335,  // CrBugs
{
GpuControlList::kOsAndroid,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, "10", nullptr},  // os_version
0x00,  // vendor_id
0,  // DeviceIDs size
nullptr,  // DeviceIDs
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry335,  // GL strings
nullptr,  // machine model info
0,  // gpu_series size
nullptr,  // gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry335_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
};
const size_t kGpuDriverBugListEntryCount = 112;
}  // namespace gpu
