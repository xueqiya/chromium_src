// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/metrics/compositor_frame_reporter.h"

#include <string>

#include "base/metrics/histogram_macros.h"
#include "base/stl_util.h"
#include "base/strings/strcat.h"
#include "base/trace_event/trace_event.h"
#include "cc/base/rolling_time_delta_history.h"
#include "cc/metrics/frame_sequence_tracker.h"
#include "cc/metrics/latency_ukm_reporter.h"

namespace cc {
namespace {

using StageType = CompositorFrameReporter::StageType;
using BlinkBreakdown = CompositorFrameReporter::BlinkBreakdown;
using VizBreakdown = CompositorFrameReporter::VizBreakdown;

constexpr int kDroppedFrameReportTypeCount =
    static_cast<int>(CompositorFrameReporter::DroppedFrameReportType::
                         kDroppedFrameReportTypeCount);
constexpr int kStageTypeCount = static_cast<int>(StageType::kStageTypeCount);
constexpr int kAllBreakdownCount =
    static_cast<int>(VizBreakdown::kBreakdownCount) +
    static_cast<int>(BlinkBreakdown::kBreakdownCount);

constexpr int kVizBreakdownInitialIndex = kStageTypeCount;
constexpr int kBlinkBreakdownInitialIndex =
    kVizBreakdownInitialIndex + static_cast<int>(VizBreakdown::kBreakdownCount);

// For each possible FrameSequenceTrackerType there will be a UMA histogram
// plus one for general case.
constexpr int kFrameSequenceTrackerTypeCount =
    static_cast<int>(FrameSequenceTrackerType::kMaxType) + 1;

// Names for CompositorFrameReporter::StageType, which should be updated in case
// of changes to the enum.
constexpr const char* GetStageName(int stage_type_index) {
  switch (stage_type_index) {
    case static_cast<int>(StageType::kBeginImplFrameToSendBeginMainFrame):
      return "BeginImplFrameToSendBeginMainFrame";
    case static_cast<int>(StageType::kSendBeginMainFrameToCommit):
      return "SendBeginMainFrameToCommit";
    case static_cast<int>(StageType::kCommit):
      return "Commit";
    case static_cast<int>(StageType::kEndCommitToActivation):
      return "EndCommitToActivation";
    case static_cast<int>(StageType::kActivation):
      return "Activation";
    case static_cast<int>(StageType::kEndActivateToSubmitCompositorFrame):
      return "EndActivateToSubmitCompositorFrame";
    case static_cast<int>(
        StageType::kSubmitCompositorFrameToPresentationCompositorFrame):
      return "SubmitCompositorFrameToPresentationCompositorFrame";
    case static_cast<int>(StageType::kTotalLatency):
      return "TotalLatency";
    case static_cast<int>(VizBreakdown::kSubmitToReceiveCompositorFrame) +
        kVizBreakdownInitialIndex:
      return "SubmitCompositorFrameToPresentationCompositorFrame."
             "SubmitToReceiveCompositorFrame";
    case static_cast<int>(VizBreakdown::kReceivedCompositorFrameToStartDraw) +
        kVizBreakdownInitialIndex:
      return "SubmitCompositorFrameToPresentationCompositorFrame."
             "ReceivedCompositorFrameToStartDraw";
    case static_cast<int>(VizBreakdown::kStartDrawToSwapEnd) +
        kVizBreakdownInitialIndex:
      return "SubmitCompositorFrameToPresentationCompositorFrame."
             "StartDrawToSwapEnd";
    case static_cast<int>(VizBreakdown::kSwapEndToPresentationCompositorFrame) +
        kVizBreakdownInitialIndex:
      return "SubmitCompositorFrameToPresentationCompositorFrame."
             "SwapEndToPresentationCompositorFrame";
    case static_cast<int>(BlinkBreakdown::kHandleInputEvents) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.HandleInputEvents";
    case static_cast<int>(BlinkBreakdown::kAnimate) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.Animate";
    case static_cast<int>(BlinkBreakdown::kStyleUpdate) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.StyleUpdate";
    case static_cast<int>(BlinkBreakdown::kLayoutUpdate) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.LayoutUpdate";
    case static_cast<int>(BlinkBreakdown::kPrepaint) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.Prepaint";
    case static_cast<int>(BlinkBreakdown::kComposite) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.Composite";
    case static_cast<int>(BlinkBreakdown::kPaint) + kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.Paint";
    case static_cast<int>(BlinkBreakdown::kScrollingCoordinator) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.ScrollingCoordinator";
    case static_cast<int>(BlinkBreakdown::kCompositeCommit) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.CompositeCommit";
    case static_cast<int>(BlinkBreakdown::kUpdateLayers) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.UpdateLayers";
    case static_cast<int>(BlinkBreakdown::kBeginMainSentToStarted) +
        kBlinkBreakdownInitialIndex:
      return "SendBeginMainFrameToCommit.BeginMainSentToStarted";
    default:
      return "";
  }
}

// Names for CompositorFrameReporter::DroppedFrameReportType, which should be
// updated in case of changes to the enum.
constexpr const char* kReportTypeNames[]{"", "DroppedFrame."};

static_assert(base::size(kReportTypeNames) == kDroppedFrameReportTypeCount,
              "Compositor latency report types has changed.");

// This value should be recalculated in case of changes to the number of values
// in CompositorFrameReporter::DroppedFrameReportType or in
// CompositorFrameReporter::StageType
constexpr int kMaxHistogramIndex = kDroppedFrameReportTypeCount *
                                   kFrameSequenceTrackerTypeCount *
                                   (kStageTypeCount + kAllBreakdownCount);
constexpr int kHistogramMin = 1;
constexpr int kHistogramMax = 350000;
constexpr int kHistogramBucketCount = 50;

bool ShouldReportLatencyMetricsForSequenceType(
    FrameSequenceTrackerType sequence_type) {
  return sequence_type != FrameSequenceTrackerType::kUniversal;
}

std::string HistogramName(const int report_type_index,
                          FrameSequenceTrackerType frame_sequence_tracker_type,
                          const int stage_type_index) {
  DCHECK_LE(frame_sequence_tracker_type, FrameSequenceTrackerType::kMaxType);
  DCHECK(
      ShouldReportLatencyMetricsForSequenceType(frame_sequence_tracker_type));
  const char* tracker_type_name =
      FrameSequenceTracker::GetFrameSequenceTrackerTypeName(
          frame_sequence_tracker_type);
  DCHECK(tracker_type_name);
  return base::StrCat({"CompositorLatency.",
                       kReportTypeNames[report_type_index], tracker_type_name,
                       *tracker_type_name ? "." : "",
                       GetStageName(stage_type_index)});
}

}  // namespace

CompositorFrameReporter::CompositorFrameReporter(
    const base::flat_set<FrameSequenceTrackerType>* active_trackers,
    const viz::BeginFrameId& id,
    LatencyUkmReporter* latency_ukm_reporter,
    bool is_single_threaded)
    : frame_id_(id),
      is_single_threaded_(is_single_threaded),
      active_trackers_(active_trackers),
      latency_ukm_reporter_(latency_ukm_reporter) {}

CompositorFrameReporter::~CompositorFrameReporter() {
  TerminateReporter();
}

CompositorFrameReporter::StageData::StageData() = default;
CompositorFrameReporter::StageData::StageData(StageType stage_type,
                                              base::TimeTicks start_time,
                                              base::TimeTicks end_time)
    : stage_type(stage_type), start_time(start_time), end_time(end_time) {}
CompositorFrameReporter::StageData::StageData(const StageData&) = default;
CompositorFrameReporter::StageData::~StageData() = default;

void CompositorFrameReporter::StartStage(
    CompositorFrameReporter::StageType stage_type,
    base::TimeTicks start_time) {
  if (frame_termination_status_ != FrameTerminationStatus::kUnknown)
    return;
  EndCurrentStage(start_time);
  if (stage_history_.empty()) {
    // Use first stage's start timestamp to ensure correct event nesting.
    TRACE_EVENT_NESTABLE_ASYNC_BEGIN_WITH_TIMESTAMP1(
        "cc,benchmark", "PipelineReporter", TRACE_ID_LOCAL(this), start_time,
        "is_single_threaded", is_single_threaded_);
  }
  current_stage_.stage_type = stage_type;
  current_stage_.start_time = start_time;
  int stage_type_index = static_cast<int>(current_stage_.stage_type);
  CHECK_LT(stage_type_index, static_cast<int>(StageType::kStageTypeCount));
  CHECK_GE(stage_type_index, 0);
  TRACE_EVENT_NESTABLE_ASYNC_BEGIN_WITH_TIMESTAMP0(
      "cc,benchmark", GetStageName(stage_type_index), TRACE_ID_LOCAL(this),
      start_time);
}

void CompositorFrameReporter::EndCurrentStage(base::TimeTicks end_time) {
  if (current_stage_.start_time == base::TimeTicks())
    return;
  int stage_type_index = static_cast<int>(current_stage_.stage_type);
  CHECK_LT(stage_type_index, static_cast<int>(StageType::kStageTypeCount));
  CHECK_GE(stage_type_index, 0);
  TRACE_EVENT_NESTABLE_ASYNC_END_WITH_TIMESTAMP0(
      "cc,benchmark", GetStageName(stage_type_index), TRACE_ID_LOCAL(this),
      end_time);
  current_stage_.end_time = end_time;
  stage_history_.push_back(current_stage_);
  current_stage_.start_time = base::TimeTicks();
}

void CompositorFrameReporter::DroppedFrame() {
  report_type_ = DroppedFrameReportType::kDroppedFrame;
}

void CompositorFrameReporter::TerminateFrame(
    FrameTerminationStatus termination_status,
    base::TimeTicks termination_time) {
  // If the reporter is already terminated, (possibly as a result of no damage)
  // then we don't need to do anything here, otherwise the reporter will be
  // terminated.
  if (frame_termination_status_ != FrameTerminationStatus::kUnknown)
    return;
  frame_termination_status_ = termination_status;
  frame_termination_time_ = termination_time;
  EndCurrentStage(frame_termination_time_);
}

void CompositorFrameReporter::OnFinishImplFrame(base::TimeTicks timestamp) {
  DCHECK(!did_finish_impl_frame_);

  did_finish_impl_frame_ = true;
  impl_frame_finish_time_ = timestamp;
}

void CompositorFrameReporter::OnAbortBeginMainFrame() {
  did_abort_main_frame_ = true;
}

void CompositorFrameReporter::SetBlinkBreakdown(
    std::unique_ptr<BeginMainFrameMetrics> blink_breakdown,
    base::TimeTicks begin_main_start) {
  DCHECK(blink_breakdown_.paint.is_zero());
  if (blink_breakdown)
    blink_breakdown_ = *blink_breakdown;
  else
    blink_breakdown_ = BeginMainFrameMetrics();

  DCHECK(begin_main_frame_start_.is_null());
  begin_main_frame_start_ = begin_main_start;
}

void CompositorFrameReporter::SetVizBreakdown(
    const viz::FrameTimingDetails& viz_breakdown) {
  DCHECK(viz_breakdown_.received_compositor_frame_timestamp.is_null());
  viz_breakdown_ = viz_breakdown;
}

void CompositorFrameReporter::TerminateReporter() {
  if (frame_termination_status_ == FrameTerminationStatus::kUnknown)
    TerminateFrame(FrameTerminationStatus::kUnknown, base::TimeTicks::Now());
  DCHECK_EQ(current_stage_.start_time, base::TimeTicks());
  bool report_latency = false;
  const char* termination_status_str = nullptr;
  switch (frame_termination_status_) {
    case FrameTerminationStatus::kPresentedFrame:
      report_latency = true;
      termination_status_str = "presented_frame";
      break;
    case FrameTerminationStatus::kDidNotPresentFrame:
      report_latency = true;
      DroppedFrame();
      termination_status_str = "did_not_present_frame";
      break;
    case FrameTerminationStatus::kReplacedByNewReporter:
      report_latency = true;
      DroppedFrame();
      termination_status_str = "replaced_by_new_reporter_at_same_stage";
      break;
    case FrameTerminationStatus::kDidNotProduceFrame:
      termination_status_str = "did_not_produce_frame";
      break;
    case FrameTerminationStatus::kUnknown:
      termination_status_str = "terminated_before_ending";
      break;
  }

  // If we don't have any stage data, we haven't emitted the corresponding start
  // event, so skip emitting the end event, too.
  if (!stage_history_.empty()) {
    const char* submission_status_str =
        report_type_ == DroppedFrameReportType::kDroppedFrame
            ? "dropped_frame"
            : "non_dropped_frame";
    TRACE_EVENT_NESTABLE_ASYNC_END_WITH_TIMESTAMP2(
        "cc,benchmark", "PipelineReporter", TRACE_ID_LOCAL(this),
        frame_termination_time_, "termination_status", termination_status_str,
        "compositor_frame_submission_status", submission_status_str);
  }

  // Only report histograms if the frame was presented.
  if (report_latency) {
    DCHECK(stage_history_.size());
    stage_history_.emplace_back(StageType::kTotalLatency,
                                stage_history_.front().start_time,
                                stage_history_.back().end_time);
    ReportStageHistograms();
  }
}

void CompositorFrameReporter::ReportStageHistograms() const {
  for (const StageData& stage : stage_history_) {
    ReportStageHistogramWithBreakdown(stage);

    for (const auto& frame_sequence_tracker_type : *active_trackers_) {
      // Report stage breakdowns.
      ReportStageHistogramWithBreakdown(stage, frame_sequence_tracker_type);
    }
  }
  if (latency_ukm_reporter_) {
    latency_ukm_reporter_->ReportLatencyUkm(report_type_, stage_history_,
                                            active_trackers_, viz_breakdown_);
  }
}

void CompositorFrameReporter::ReportStageHistogramWithBreakdown(
    const CompositorFrameReporter::StageData& stage,
    FrameSequenceTrackerType frame_sequence_tracker_type) const {
  if (!ShouldReportLatencyMetricsForSequenceType(frame_sequence_tracker_type))
    return;
  base::TimeDelta stage_delta = stage.end_time - stage.start_time;
  ReportHistogram(frame_sequence_tracker_type,
                  static_cast<int>(stage.stage_type), stage_delta);
  switch (stage.stage_type) {
    case StageType::kSendBeginMainFrameToCommit:
      ReportBlinkBreakdowns(stage.start_time, frame_sequence_tracker_type);
      break;
    case StageType::kSubmitCompositorFrameToPresentationCompositorFrame:
      ReportVizBreakdowns(stage.start_time, frame_sequence_tracker_type);
      break;
    default:
      break;
  }
}

void CompositorFrameReporter::ReportBlinkBreakdowns(
    base::TimeTicks start_time,
    FrameSequenceTrackerType frame_sequence_tracker_type) const {
  std::vector<std::pair<BlinkBreakdown, base::TimeDelta>> breakdowns = {
      {BlinkBreakdown::kHandleInputEvents,
       blink_breakdown_.handle_input_events},
      {BlinkBreakdown::kAnimate, blink_breakdown_.animate},
      {BlinkBreakdown::kStyleUpdate, blink_breakdown_.style_update},
      {BlinkBreakdown::kLayoutUpdate, blink_breakdown_.layout_update},
      {BlinkBreakdown::kPrepaint, blink_breakdown_.prepaint},
      {BlinkBreakdown::kComposite, blink_breakdown_.composite},
      {BlinkBreakdown::kPaint, blink_breakdown_.paint},
      {BlinkBreakdown::kScrollingCoordinator,
       blink_breakdown_.scrolling_coordinator},
      {BlinkBreakdown::kCompositeCommit, blink_breakdown_.composite_commit},
      {BlinkBreakdown::kUpdateLayers, blink_breakdown_.update_layers},
      {BlinkBreakdown::kBeginMainSentToStarted,
       begin_main_frame_start_ - start_time}};

  for (const auto& pair : breakdowns) {
    ReportHistogram(frame_sequence_tracker_type,
                    kBlinkBreakdownInitialIndex + static_cast<int>(pair.first),
                    pair.second);
  }
}

void CompositorFrameReporter::ReportVizBreakdowns(
    base::TimeTicks start_time,
    FrameSequenceTrackerType frame_sequence_tracker_type) const {
  // Check if viz_breakdown is set. Testing indicates that sometimes the
  // received_compositor_frame_timestamp can be earlier than the given
  // start_time. Avoid reporting negative times.
  if (viz_breakdown_.received_compositor_frame_timestamp.is_null() ||
      viz_breakdown_.received_compositor_frame_timestamp < start_time) {
    return;
  }
  base::TimeDelta submit_to_receive_compositor_frame_delta =
      viz_breakdown_.received_compositor_frame_timestamp - start_time;
  ReportHistogram(
      frame_sequence_tracker_type,
      kVizBreakdownInitialIndex +
          static_cast<int>(VizBreakdown::kSubmitToReceiveCompositorFrame),
      submit_to_receive_compositor_frame_delta);

  if (viz_breakdown_.draw_start_timestamp.is_null())
    return;
  base::TimeDelta received_compositor_frame_to_start_draw_delta =
      viz_breakdown_.draw_start_timestamp -
      viz_breakdown_.received_compositor_frame_timestamp;
  ReportHistogram(
      frame_sequence_tracker_type,
      kVizBreakdownInitialIndex +
          static_cast<int>(VizBreakdown::kReceivedCompositorFrameToStartDraw),
      received_compositor_frame_to_start_draw_delta);

  if (viz_breakdown_.swap_timings.is_null())
    return;
  base::TimeDelta start_draw_to_swap_end_delta =
      viz_breakdown_.swap_timings.swap_end -
      viz_breakdown_.draw_start_timestamp;

  ReportHistogram(frame_sequence_tracker_type,
                  kVizBreakdownInitialIndex +
                      static_cast<int>(VizBreakdown::kStartDrawToSwapEnd),
                  start_draw_to_swap_end_delta);

  base::TimeDelta swap_end_to_presentation_compositor_frame_delta =
      viz_breakdown_.presentation_feedback.timestamp -
      viz_breakdown_.swap_timings.swap_end;

  ReportHistogram(
      frame_sequence_tracker_type,
      kVizBreakdownInitialIndex +
          static_cast<int>(VizBreakdown::kSwapEndToPresentationCompositorFrame),
      swap_end_to_presentation_compositor_frame_delta);
}

void CompositorFrameReporter::ReportHistogram(
    FrameSequenceTrackerType frame_sequence_tracker_type,
    const int stage_type_index,
    base::TimeDelta time_delta) const {
  const int report_type_index = static_cast<int>(report_type_);
  const int frame_sequence_tracker_type_index =
      static_cast<int>(frame_sequence_tracker_type);
  const int histogram_index =
      (stage_type_index * kFrameSequenceTrackerTypeCount +
       frame_sequence_tracker_type_index) *
          kDroppedFrameReportTypeCount +
      report_type_index;

  CHECK_LT(stage_type_index, kStageTypeCount + kAllBreakdownCount);
  CHECK_GE(stage_type_index, 0);
  CHECK_LT(report_type_index, kDroppedFrameReportTypeCount);
  CHECK_GE(report_type_index, 0);
  CHECK_LT(histogram_index, kMaxHistogramIndex);
  CHECK_GE(histogram_index, 0);

  STATIC_HISTOGRAM_POINTER_GROUP(
      HistogramName(report_type_index, frame_sequence_tracker_type,
                    stage_type_index),
      histogram_index, kMaxHistogramIndex,
      AddTimeMicrosecondsGranularity(time_delta),
      base::Histogram::FactoryGet(
          HistogramName(report_type_index, frame_sequence_tracker_type,
                        stage_type_index),
          kHistogramMin, kHistogramMax, kHistogramBucketCount,
          base::HistogramBase::kUmaTargetedHistogramFlag));
}
}  // namespace cc
