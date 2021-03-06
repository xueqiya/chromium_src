// components/page_load_metrics/common/page_load_metrics.mojom-test-utils.h is auto generated by mojom_bindings_generator.py, do not edit

// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAGE_LOAD_METRICS_COMMON_PAGE_LOAD_METRICS_MOJOM_TEST_UTILS_H_
#define COMPONENTS_PAGE_LOAD_METRICS_COMMON_PAGE_LOAD_METRICS_MOJOM_TEST_UTILS_H_

#include "components/page_load_metrics/common/page_load_metrics.mojom.h"


namespace page_load_metrics {
namespace mojom {


class  PageLoadMetricsInterceptorForTesting : public PageLoadMetrics {
  virtual PageLoadMetrics* GetForwardingInterface() = 0;
  void UpdateTiming(PageLoadTimingPtr page_load_timing, PageLoadMetadataPtr page_load_metadata, PageLoadFeaturesPtr new_features, std::vector<ResourceDataUpdatePtr> resources, FrameRenderDataUpdatePtr render_data, CpuTimingPtr cpu_load_timing, DeferredResourceCountsPtr new_deferred_resource_data) override;
};
class  PageLoadMetricsAsyncWaiter {
 public:
  explicit PageLoadMetricsAsyncWaiter(PageLoadMetrics* proxy);
  ~PageLoadMetricsAsyncWaiter();

 private:
  PageLoadMetrics* const proxy_;

  DISALLOW_COPY_AND_ASSIGN(PageLoadMetricsAsyncWaiter);
};




}  // namespace mojom
}  // namespace page_load_metrics

#endif  // COMPONENTS_PAGE_LOAD_METRICS_COMMON_PAGE_LOAD_METRICS_MOJOM_TEST_UTILS_H_