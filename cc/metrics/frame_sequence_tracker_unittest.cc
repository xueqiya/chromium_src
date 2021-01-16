// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/metrics/frame_sequence_tracker.h"

#include <vector>

#include "base/macros.h"
#include "base/test/metrics/histogram_tester.h"
#include "cc/metrics/compositor_frame_reporting_controller.h"
#include "components/viz/common/frame_sinks/begin_frame_args.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "ui/gfx/presentation_feedback.h"

namespace cc {

namespace {

const char* ParseNumber(const char* str, uint64_t* retvalue) {
  uint64_t number = 0;
  for (; *str >= '0' && *str <= '9'; ++str) {
    number *= 10;
    number += *str - '0';
  }
  *retvalue = number;
  return str;
}

}  // namespace

class FrameSequenceTrackerTest : public testing::Test {
 public:
  const uint32_t kImplDamage = 0x1;
  const uint32_t kMainDamage = 0x2;

  FrameSequenceTrackerTest()
      : compositor_frame_reporting_controller_(
            std::make_unique<CompositorFrameReportingController>()),
        collection_(/* is_single_threaded=*/false,
                    compositor_frame_reporting_controller_.get()) {
    collection_.StartSequence(FrameSequenceTrackerType::kTouchScroll);
    tracker_ = collection_.GetTrackerForTesting(
        FrameSequenceTrackerType::kTouchScroll);
  }
  ~FrameSequenceTrackerTest() override = default;

  void CreateNewTracker() {
    collection_.StartSequence(FrameSequenceTrackerType::kTouchScroll);
    tracker_ = collection_.GetTrackerForTesting(
        FrameSequenceTrackerType::kTouchScroll);
  }

  viz::BeginFrameArgs CreateBeginFrameArgs(
      uint64_t source_id,
      uint64_t sequence_number,
      base::TimeTicks now = base::TimeTicks::Now()) {
    auto interval = base::TimeDelta::FromMilliseconds(16);
    auto deadline = now + interval;
    return viz::BeginFrameArgs::Create(BEGINFRAME_FROM_HERE, source_id,
                                       sequence_number, now, deadline, interval,
                                       viz::BeginFrameArgs::NORMAL);
  }

  void StartImplAndMainFrames(const viz::BeginFrameArgs& args) {
    collection_.NotifyBeginImplFrame(args);
    collection_.NotifyBeginMainFrame(args);
  }

  uint32_t DispatchCompleteFrame(const viz::BeginFrameArgs& args,
                                 uint32_t damage_type,
                                 bool has_missing_content = false) {
    StartImplAndMainFrames(args);

    if (damage_type & kImplDamage) {
      if (!(damage_type & kMainDamage)) {
        collection_.NotifyMainFrameCausedNoDamage(args);
      } else {
        collection_.NotifyMainFrameProcessed(args);
      }
      uint32_t frame_token = NextFrameToken();
      collection_.NotifySubmitFrame(frame_token, has_missing_content,
                                    viz::BeginFrameAck(args, true), args);
      collection_.NotifyFrameEnd(args);
      return frame_token;
    } else {
      collection_.NotifyImplFrameCausedNoDamage(
          viz::BeginFrameAck(args, false));
      collection_.NotifyMainFrameCausedNoDamage(args);
      collection_.NotifyFrameEnd(args);
    }
    return 0;
  }

  uint32_t NextFrameToken() {
    static uint32_t frame_token = 0;
    return ++frame_token;
  }

  // Check whether a type of tracker exists in |frame_trackers_| or not.
  bool TrackerExists(FrameSequenceTrackerType type) const {
    return collection_.frame_trackers_.contains(type);
  }

  void TestNotifyFramePresented() {
    collection_.StartSequence(FrameSequenceTrackerType::kCompositorAnimation);
    collection_.StartSequence(FrameSequenceTrackerType::kMainThreadAnimation);
    // The kTouchScroll tracker is created in the test constructor, and the
    // kUniversal tracker is created in the FrameSequenceTrackerCollection
    // constructor.
    EXPECT_EQ(collection_.frame_trackers_.size(), 3u);
    collection_.StartSequence(FrameSequenceTrackerType::kUniversal);
    EXPECT_EQ(collection_.frame_trackers_.size(), 4u);

    collection_.StopSequence(kCompositorAnimation);
    EXPECT_EQ(collection_.frame_trackers_.size(), 3u);
    EXPECT_TRUE(collection_.frame_trackers_.contains(
        FrameSequenceTrackerType::kMainThreadAnimation));
    EXPECT_TRUE(collection_.frame_trackers_.contains(
        FrameSequenceTrackerType::kTouchScroll));
    ASSERT_EQ(collection_.removal_trackers_.size(), 1u);
    EXPECT_EQ(collection_.removal_trackers_[0]->type_,
              FrameSequenceTrackerType::kCompositorAnimation);

    gfx::PresentationFeedback feedback;
    collection_.NotifyFramePresented(1u, feedback);
    // NotifyFramePresented should call ReportFramePresented on all the
    // |removal_trackers_|, which changes their termination_status_ to
    // kReadyForTermination. So at this point, the |removal_trackers_| should be
    // empty.
    EXPECT_TRUE(collection_.removal_trackers_.empty());
  }

  void ReportMetricsTest() {
    base::HistogramTester histogram_tester;

    // Test that there is no main thread frames expected.
    tracker_->impl_throughput().frames_expected = 100u;
    tracker_->impl_throughput().frames_produced = 85u;
    tracker_->ReportMetricsForTesting();
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.CompositorThread.TouchScroll", 1u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.MainThread.TouchScroll", 0u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.SlowerThread.TouchScroll", 1u);

    // Test that both are reported.
    tracker_->impl_throughput().frames_expected = 100u;
    tracker_->impl_throughput().frames_produced = 85u;
    tracker_->main_throughput().frames_expected = 150u;
    tracker_->main_throughput().frames_produced = 25u;
    tracker_->ReportMetricsForTesting();
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.CompositorThread.TouchScroll", 2u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.MainThread.TouchScroll", 1u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.SlowerThread.TouchScroll", 2u);

    // Test that none is reported.
    tracker_->main_throughput().frames_expected = 2u;
    tracker_->main_throughput().frames_produced = 1u;
    tracker_->impl_throughput().frames_expected = 2u;
    tracker_->impl_throughput().frames_produced = 1u;
    tracker_->ReportMetricsForTesting();
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.CompositorThread.TouchScroll", 2u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.MainThread.TouchScroll", 1u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.SlowerThread.TouchScroll", 2u);

    // Test the case where compositor and main thread have the same throughput.
    tracker_->impl_throughput().frames_expected = 120u;
    tracker_->impl_throughput().frames_produced = 118u;
    tracker_->main_throughput().frames_expected = 120u;
    tracker_->main_throughput().frames_produced = 118u;
    tracker_->ReportMetricsForTesting();
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.CompositorThread.TouchScroll", 3u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.MainThread.TouchScroll", 2u);
    histogram_tester.ExpectTotalCount(
        "Graphics.Smoothness.Throughput.SlowerThread.TouchScroll", 3u);
  }

  void GenerateSequence(const char* str) {
    const uint64_t source_id = 1;
    uint64_t current_frame = 0;
    while (*str) {
      const char command = *str++;
      uint64_t sequence = 0, dummy = 0;
      switch (command) {
        case 'b':
        case 'P':
        case 'n':
        case 's':
        case 'e':
        case 'E':
          ASSERT_EQ(*str, '(') << command;
          str = ParseNumber(++str, &sequence);
          ASSERT_EQ(*str, ')');
          ++str;
          break;

        case 'B':
        case 'N':
          ASSERT_EQ(*str, '(');
          str = ParseNumber(++str, &dummy);
          ASSERT_EQ(*str, ',');
          str = ParseNumber(++str, &sequence);
          ASSERT_EQ(*str, ')');
          ++str;
          break;

        case 'R':
          break;

        default:
          NOTREACHED() << command << str;
      }

      switch (command) {
        case 'b':
          current_frame = sequence;
          collection_.NotifyBeginImplFrame(
              CreateBeginFrameArgs(source_id, sequence));
          break;

        case 'P':
          collection_.NotifyFramePresented(
              sequence, {base::TimeTicks::Now(),
                         viz::BeginFrameArgs::DefaultInterval(), 0});
          break;

        case 'R':
          collection_.NotifyPauseFrameProduction();
          break;

        case 'n':
          collection_.NotifyImplFrameCausedNoDamage(
              viz::BeginFrameAck(source_id, sequence, false, 0));
          break;

        case 's': {
          auto frame_token = sequence;
          auto args = CreateBeginFrameArgs(source_id, current_frame);
          auto main_args = args;
          if (*str == 'S') {
            ++str;
            ASSERT_EQ(*str, '(');
            str = ParseNumber(++str, &sequence);
            ASSERT_EQ(*str, ')');
            ++str;
            main_args = CreateBeginFrameArgs(source_id, sequence);
          }
          collection_.NotifySubmitFrame(
              frame_token, /*has_missing_content=*/false,
              viz::BeginFrameAck(args, true), main_args);
          break;
        }

        case 'e':
          collection_.NotifyFrameEnd(CreateBeginFrameArgs(source_id, sequence));
          break;

        case 'E':
          collection_.NotifyMainFrameProcessed(
              CreateBeginFrameArgs(source_id, sequence));
          break;

        case 'B':
          collection_.NotifyBeginMainFrame(
              CreateBeginFrameArgs(source_id, sequence));
          break;

        case 'N':
          collection_.NotifyMainFrameCausedNoDamage(
              CreateBeginFrameArgs(source_id, sequence));
          break;

        default:
          NOTREACHED();
      }
    }
  }

  void ReportMetrics() { tracker_->ReportMetricsForTesting(); }

  base::TimeDelta TimeDeltaToReort() const {
    return tracker_->time_delta_to_report_;
  }

  unsigned NumberOfTrackers() const {
    return collection_.frame_trackers_.size();
  }
  unsigned NumberOfRemovalTrackers() const {
    return collection_.removal_trackers_.size();
  }

  uint64_t BeginImplFrameDataPreviousSequence() const {
    return tracker_->begin_impl_frame_data_.previous_sequence;
  }
  uint64_t BeginMainFrameDataPreviousSequence() const {
    return tracker_->begin_main_frame_data_.previous_sequence;
  }

  base::flat_set<uint32_t> IgnoredFrameTokens() const {
    return tracker_->ignored_frame_tokens_;
  }

  FrameSequenceMetrics::ThroughputData& ImplThroughput() const {
    return tracker_->impl_throughput();
  }
  FrameSequenceMetrics::ThroughputData& MainThroughput() const {
    return tracker_->main_throughput();
  }

  void SetTerminationStatus(FrameSequenceTracker::TerminationStatus status) {
    tracker_->termination_status_ = status;
  }

 protected:
  uint32_t number_of_frames_checkerboarded() const {
    return tracker_->metrics_->frames_checkerboarded();
  }

  std::unique_ptr<CompositorFrameReportingController>
      compositor_frame_reporting_controller_;
  FrameSequenceTrackerCollection collection_;
  FrameSequenceTracker* tracker_;
};

// Tests that the tracker works correctly when the source-id for the
// begin-frames change.
TEST_F(FrameSequenceTrackerTest, SourceIdChangeDuringSequence) {
  const uint64_t source_1 = 1;
  uint64_t sequence_1 = 0;

  // Dispatch some frames, both causing damage to impl/main, and both impl and
  // main providing damage to the frame.
  auto args_1 = CreateBeginFrameArgs(source_1, ++sequence_1);
  DispatchCompleteFrame(args_1, kImplDamage | kMainDamage);
  args_1 = CreateBeginFrameArgs(source_1, ++sequence_1);
  DispatchCompleteFrame(args_1, kImplDamage | kMainDamage);

  // Start a new tracker.
  CreateNewTracker();

  // Change the source-id, and start an impl frame. This time, the main-frame
  // does not provide any damage.
  const uint64_t source_2 = 2;
  uint64_t sequence_2 = 0;
  auto args_2 = CreateBeginFrameArgs(source_2, ++sequence_2);
  collection_.NotifyBeginImplFrame(args_2);
  collection_.NotifyBeginMainFrame(args_2);
  collection_.NotifyMainFrameCausedNoDamage(args_2);
  // Since the main-frame did not have any new damage from the latest
  // BeginFrameArgs, the submit-frame will carry the previous BeginFrameArgs
  // (from source_1);
  collection_.NotifySubmitFrame(NextFrameToken(), /*has_missing_content=*/false,
                                viz::BeginFrameAck(args_2, true), args_1);
}

TEST_F(FrameSequenceTrackerTest, UniversalTrackerCreation) {
  // The universal tracker should be explicitly created by the object that
  // manages the |collection_|
  EXPECT_FALSE(TrackerExists(FrameSequenceTrackerType::kUniversal));
}

TEST_F(FrameSequenceTrackerTest, UniversalTrackerRestartableAfterClearAll) {
  collection_.StartSequence(FrameSequenceTrackerType::kUniversal);
  EXPECT_TRUE(TrackerExists(FrameSequenceTrackerType::kUniversal));

  collection_.ClearAll();
  EXPECT_FALSE(TrackerExists(FrameSequenceTrackerType::kUniversal));

  collection_.StartSequence(FrameSequenceTrackerType::kUniversal);
  EXPECT_TRUE(TrackerExists(FrameSequenceTrackerType::kUniversal));
}

TEST_F(FrameSequenceTrackerTest, TestNotifyFramePresented) {
  TestNotifyFramePresented();
}

// Base case for checkerboarding: present a single frame with checkerboarding,
// followed by a non-checkerboard frame.
TEST_F(FrameSequenceTrackerTest, CheckerboardingSimple) {
  CreateNewTracker();

  const uint64_t source_1 = 1;
  uint64_t sequence_1 = 0;

  // Dispatch some frames, both causing damage to impl/main, and both impl and
  // main providing damage to the frame.
  auto args_1 = CreateBeginFrameArgs(source_1, ++sequence_1);
  bool has_missing_content = true;
  auto frame_token = DispatchCompleteFrame(args_1, kImplDamage | kMainDamage,
                                           has_missing_content);

  const auto interval = viz::BeginFrameArgs::DefaultInterval();
  gfx::PresentationFeedback feedback(base::TimeTicks::Now(), interval, 0);
  collection_.NotifyFramePresented(frame_token, feedback);

  // Submit another frame with no checkerboarding.
  has_missing_content = false;
  frame_token =
      DispatchCompleteFrame(CreateBeginFrameArgs(source_1, ++sequence_1),
                            kImplDamage | kMainDamage, has_missing_content);
  feedback =
      gfx::PresentationFeedback(base::TimeTicks::Now() + interval, interval, 0);
  collection_.NotifyFramePresented(frame_token, feedback);

  EXPECT_EQ(1u, number_of_frames_checkerboarded());
}

// Present a single frame with checkerboarding, followed by a non-checkerboard
// frame after a few vsyncs.
TEST_F(FrameSequenceTrackerTest, CheckerboardingMultipleFrames) {
  CreateNewTracker();

  const uint64_t source_1 = 1;
  uint64_t sequence_1 = 0;

  // Dispatch some frames, both causing damage to impl/main, and both impl and
  // main providing damage to the frame.
  auto args_1 = CreateBeginFrameArgs(source_1, ++sequence_1);
  bool has_missing_content = true;
  auto frame_token = DispatchCompleteFrame(args_1, kImplDamage | kMainDamage,
                                           has_missing_content);

  const auto interval = viz::BeginFrameArgs::DefaultInterval();
  gfx::PresentationFeedback feedback(base::TimeTicks::Now(), interval, 0);
  collection_.NotifyFramePresented(frame_token, feedback);

  // Submit another frame with no checkerboarding.
  has_missing_content = false;
  frame_token =
      DispatchCompleteFrame(CreateBeginFrameArgs(source_1, ++sequence_1),
                            kImplDamage | kMainDamage, has_missing_content);
  feedback = gfx::PresentationFeedback(base::TimeTicks::Now() + interval * 3,
                                       interval, 0);
  collection_.NotifyFramePresented(frame_token, feedback);

  EXPECT_EQ(3u, number_of_frames_checkerboarded());
}

// Present multiple checkerboarded frames, followed by a non-checkerboard
// frame.
TEST_F(FrameSequenceTrackerTest, MultipleCheckerboardingFrames) {
  CreateNewTracker();

  const uint32_t kFrames = 3;
  const uint64_t source_1 = 1;
  uint64_t sequence_1 = 0;

  // Submit |kFrames| number of frames with checkerboarding.
  std::vector<uint32_t> frames;
  for (uint32_t i = 0; i < kFrames; ++i) {
    auto args_1 = CreateBeginFrameArgs(source_1, ++sequence_1);
    bool has_missing_content = true;
    auto frame_token = DispatchCompleteFrame(args_1, kImplDamage | kMainDamage,
                                             has_missing_content);
    frames.push_back(frame_token);
  }

  base::TimeTicks present_now = base::TimeTicks::Now();
  const auto interval = viz::BeginFrameArgs::DefaultInterval();
  for (auto frame_token : frames) {
    gfx::PresentationFeedback feedback(present_now, interval, 0);
    collection_.NotifyFramePresented(frame_token, feedback);
    present_now += interval;
  }

  // Submit another frame with no checkerboarding.
  bool has_missing_content = false;
  auto frame_token =
      DispatchCompleteFrame(CreateBeginFrameArgs(source_1, ++sequence_1),
                            kImplDamage | kMainDamage, has_missing_content);
  gfx::PresentationFeedback feedback(present_now, interval, 0);
  collection_.NotifyFramePresented(frame_token, feedback);

  EXPECT_EQ(kFrames, number_of_frames_checkerboarded());
}

TEST_F(FrameSequenceTrackerTest, ReportMetrics) {
  ReportMetricsTest();
}

TEST_F(FrameSequenceTrackerTest, ReportMetricsAtFixedInterval) {
  const uint64_t source = 1;
  uint64_t sequence = 0;
  base::TimeDelta first_time_delta = base::TimeDelta::FromSeconds(1);
  auto args = CreateBeginFrameArgs(source, ++sequence,
                                   base::TimeTicks::Now() + first_time_delta);

  // args.frame_time is less than 5s of the tracker creation time, so won't
  // schedule this tracker to report its throughput.
  collection_.NotifyBeginImplFrame(args);
  collection_.NotifyImplFrameCausedNoDamage(viz::BeginFrameAck(args, false));
  collection_.NotifyFrameEnd(args);

  EXPECT_EQ(NumberOfTrackers(), 1u);
  EXPECT_EQ(NumberOfRemovalTrackers(), 0u);

  ImplThroughput().frames_expected += 101;
  // Now args.frame_time is 5s since the tracker creation time, so this tracker
  // should be scheduled to report its throughput.
  args = CreateBeginFrameArgs(source, ++sequence,
                              args.frame_time + TimeDeltaToReort());
  collection_.NotifyBeginImplFrame(args);
  collection_.NotifyImplFrameCausedNoDamage(viz::BeginFrameAck(args, false));
  collection_.NotifyFrameEnd(args);
  EXPECT_EQ(NumberOfTrackers(), 1u);
  EXPECT_EQ(NumberOfRemovalTrackers(), 1u);
}

TEST_F(FrameSequenceTrackerTest, ReportWithoutBeginImplFrame) {
  const uint64_t source = 1;
  uint64_t sequence = 0;

  auto args = CreateBeginFrameArgs(source, ++sequence);
  collection_.NotifyBeginMainFrame(args);

  EXPECT_EQ(BeginImplFrameDataPreviousSequence(), 0u);
  // Call to ReportBeginMainFrame should early exit.
  EXPECT_EQ(BeginMainFrameDataPreviousSequence(), 0u);

  uint32_t frame_token = NextFrameToken();
  collection_.NotifySubmitFrame(frame_token, false,
                                viz::BeginFrameAck(args, true), args);

  // Call to ReportSubmitFrame should early exit.
  EXPECT_TRUE(IgnoredFrameTokens().contains(frame_token));

  gfx::PresentationFeedback feedback;
  collection_.NotifyFramePresented(frame_token, feedback);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, MainFrameTracking) {
  const uint64_t source = 1;
  uint64_t sequence = 0;

  auto args = CreateBeginFrameArgs(source, ++sequence);
  auto frame_1 = DispatchCompleteFrame(args, kImplDamage | kMainDamage);

  args = CreateBeginFrameArgs(source, ++sequence);
  auto frame_2 = DispatchCompleteFrame(args, kImplDamage);

  gfx::PresentationFeedback feedback;
  collection_.NotifyFramePresented(frame_1, feedback);
  collection_.NotifyFramePresented(frame_2, feedback);
}

TEST_F(FrameSequenceTrackerTest, MainFrameNoDamageTracking) {
  const uint64_t source = 1;
  uint64_t sequence = 0;

  const auto first_args = CreateBeginFrameArgs(source, ++sequence);
  DispatchCompleteFrame(first_args, kImplDamage | kMainDamage);

  // Now, start the next frame, but for main, respond with the previous args.
  const auto second_args = CreateBeginFrameArgs(source, ++sequence);
  StartImplAndMainFrames(second_args);

  uint32_t frame_token = NextFrameToken();
  collection_.NotifySubmitFrame(frame_token, /*has_missing_content=*/false,
                                viz::BeginFrameAck(second_args, true),
                                first_args);
  collection_.NotifyFrameEnd(second_args);

  // Start and submit the next frame, with no damage from main.
  auto args = CreateBeginFrameArgs(source, ++sequence);
  collection_.NotifyBeginImplFrame(args);
  frame_token = NextFrameToken();
  collection_.NotifySubmitFrame(frame_token, /*has_missing_content=*/false,
                                viz::BeginFrameAck(args, true), first_args);
  collection_.NotifyFrameEnd(args);

  // Now, submit a frame with damage from main from |second_args|.
  collection_.NotifyMainFrameProcessed(second_args);
  args = CreateBeginFrameArgs(source, ++sequence);
  StartImplAndMainFrames(args);
  frame_token = NextFrameToken();
  collection_.NotifySubmitFrame(frame_token, /*has_missing_content=*/false,
                                viz::BeginFrameAck(args, true), second_args);
  collection_.NotifyFrameEnd(args);
}

TEST_F(FrameSequenceTrackerTest, BeginMainFrameSubmit) {
  // Start with a bunch of frames so that the metric does get reported at the
  // end of the test.
  ImplThroughput().frames_expected = 98u;
  ImplThroughput().frames_produced = 98u;
  MainThroughput().frames_expected = 98u;
  MainThroughput().frames_produced = 98u;

  const char sequence[] = "b(1)B(0,1)n(1)e(1)b(2)E(1)B(1,2)s(1)S(1)e(2)P(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 99u);
  EXPECT_EQ(MainThroughput().frames_expected, 100u);

  base::HistogramTester histogram_tester;
  ReportMetrics();

  const char metric[] = "Graphics.Smoothness.Throughput.MainThread.TouchScroll";
  histogram_tester.ExpectTotalCount(metric, 1u);
  EXPECT_THAT(histogram_tester.GetAllSamples(metric),
              testing::ElementsAre(base::Bucket(99, 1)));
}

TEST_F(FrameSequenceTrackerTest, SimpleSequenceOneFrame) {
  const char sequence[] = "b(1)B(0,1)s(1)S(1)e(1)P(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
  EXPECT_EQ(MainThroughput().frames_produced, 1u);
}

TEST_F(FrameSequenceTrackerTest, SimpleSequenceOneFrameNoDamage) {
  const char sequence[] = "b(1)B(0,1)N(1,1)n(1)e(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);

  const char second_sequence[] = "b(2)B(1,2)n(2)N(2,2)e(2)";
  GenerateSequence(second_sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, MultipleNoDamageNotifications) {
  const char sequence[] = "b(1)n(1)n(1)e(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, MultipleNoDamageNotificationsFromMain) {
  const char sequence[] = "b(1)B(0,1)N(1,1)n(1)N(0,1)e(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, DelayedMainFrameNoDamage) {
  const char sequence[] = "b(1)B(0,1)n(1)e(1)b(2)n(2)e(2)b(3)N(0,1)n(3)e(3)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, DelayedMainFrameNoDamageFromOlderFrame) {
  // Start a sequence, and receive a 'no damage' from an earlier frame.
  const char second_sequence[] = "b(2)B(0,2)N(2,1)n(2)N(2,2)e(2)";
  GenerateSequence(second_sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, StateResetDuringSequence) {
  const char sequence[] = "b(1)B(0,1)n(1)N(1,1)Re(1)b(2)n(2)e(2)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, NoCompositorDamageSubmitFrame) {
  const char sequence[] = "b(1)n(1)B(0,1)s(1)S(1)e(1)P(1)b(2)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 2u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
  EXPECT_EQ(MainThroughput().frames_produced, 1u);
}

TEST_F(FrameSequenceTrackerTest, SequenceStateResetsDuringFrame) {
  const char sequence[] = "b(1)Rn(1)e(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 0u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);

  GenerateSequence("b(2)s(1)e(2)P(1)b(4)");
  EXPECT_EQ(ImplThroughput().frames_expected, 3u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
  EXPECT_EQ(MainThroughput().frames_produced, 0u);
}

TEST_F(FrameSequenceTrackerTest, BeginImplFrameBeforeTerminate) {
  const char sequence[] = "b(1)s(1)e(1)b(4)P(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 4u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
  collection_.StopSequence(FrameSequenceTrackerType::kTouchScroll);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
}

// b(2417)B(0,2417)E(2417)n(2417)N(2417,2417)
TEST_F(FrameSequenceTrackerTest, SequenceNumberReset) {
  const char sequence[] =
      "b(6)B(0,6)n(6)e(6)Rb(1)B(0,1)N(1,1)n(1)e(1)b(2)B(1,2)n(2)e(2)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, MainThroughputWithHighLatency) {
  const char sequence[] = "b(1)B(0,1)n(1)e(1)b(2)E(1)s(1)S(1)e(2)P(1)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(ImplThroughput().frames_produced, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 2u);
  EXPECT_EQ(MainThroughput().frames_produced, 1u);
}

#if DCHECK_IS_ON()
// These two tests ensures that when present a frame, the frames_received is
// the same as frames_processed. As long as there is no crash, the condition is
// true.
TEST_F(FrameSequenceTrackerTest, FramesProcessedMatch1) {
  const char sequence[] = "b(1)n(1)e(1)b(2)s(2)e(2)b(3)n(3)";
  GenerateSequence(sequence);
  collection_.StopSequence(FrameSequenceTrackerType::kTouchScroll);
  SetTerminationStatus(
      FrameSequenceTracker::TerminationStatus::kReadyForTermination);
  GenerateSequence("P(2)");
}

TEST_F(FrameSequenceTrackerTest, FramesProcessedMatch2) {
  const char sequence[] = "b(1)n(1)e(1)b(2)s(2)e(2)b(3)s(3)";
  GenerateSequence(sequence);
  collection_.StopSequence(FrameSequenceTrackerType::kTouchScroll);
  SetTerminationStatus(
      FrameSequenceTracker::TerminationStatus::kReadyForTermination);
  GenerateSequence("P(2)");
}
#endif

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage1) {
  const char sequence[] =
      "b(1)B(0,1)n(1)e(1)b(2)E(1)B(1,2)n(2)e(2)b(3)E(2)B(2,3)n(3)e(3)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  // At E(2), B(0,1) is treated no damage.
  EXPECT_EQ(MainThroughput().frames_expected, 2u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage2) {
  const char sequence[] =
      "b(1)B(0,1)n(1)e(1)b(2)E(1)B(1,2)n(2)e(2)b(3)n(3)e(3)b(4)n(4)e(4)b(8)E(2)"
      "B(8,8)n(8)e(8)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  // At E(2), B(0,1) is treated as no damage.
  EXPECT_EQ(MainThroughput().frames_expected, 7u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage3) {
  const char sequence[] =
      "b(34)B(0,34)n(34)e(34)b(35)n(35)e(35)b(36)E(34)n(36)e(36)b(39)s(1)e(39)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage4) {
  const char sequence[] =
      "b(9)B(0,9)n(9)Re(9)E(9)b(11)B(0,11)n(11)e(11)b(12)E(11)B(11,12)s(1)S(11)"
      "e(12)b(13)E(12)s(2)S(12)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 2u);
  EXPECT_EQ(MainThroughput().frames_expected, 2u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage5) {
  const char sequence[] =
      "b(1)B(0,1)E(1)s(1)S(1)e(1)b(2)n(2)e(2)b(3)B(1,3)n(3)e(3)E(3)b(4)B(3,4)n("
      "4)e(4)E(4)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  // At E(4), we treat B(1,3) as if it had no damage.
  EXPECT_EQ(MainThroughput().frames_expected, 3u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage6) {
  const char sequence[] =
      "b(1)B(0,1)E(1)s(1)S(1)e(1)b(2)B(1,2)E(2)n(2)N(2,2)e(2)b(3)B(0,3)E(3)n(3)"
      "N(3,3)e(3)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage7) {
  const char sequence[] =
      "b(8)B(0,8)n(8)e(8)b(9)E(8)B(8,9)E(9)s(1)S(8)e(9)b(10)s(2)S(9)e(10)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 2u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage8) {
  const char sequence[] =
      "b(18)B(0,18)E(18)n(18)N(18,18)Re(18)b(20)B(0,20)N(20,20)n(20)N(0,20)e("
      "20)b(21)B(0,21)E(21)s(1)S(21)e(21)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage9) {
  const char sequence[] =
      "b(78)n(78)Re(78)Rb(82)B(0,82)E(82)n(82)N(82,82)Re(82)b(86)B(0,86)E(86)n("
      "86)e(86)b(87)s(1)S(86)e(87)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 1u);
  EXPECT_EQ(MainThroughput().frames_expected, 1u);
}

TEST_F(FrameSequenceTrackerTest, OffScreenMainDamage10) {
  const char sequence[] =
      "b(2)B(0,2)E(2)n(2)N(2,2)e(2)b(3)B(0,3)E(3)n(3)N(3,3)e(3)b(4)B(0,4)E(4)n("
      "4)N(4,4)e(4)b(5)B(0,5)E(5)n(5)N(5,5)e(5)b(6)B(0,6)n(6)e(6)E(6)Rb(8)B(0,"
      "8)E(8)n(8)N(8,8)e(8)";
  GenerateSequence(sequence);
  EXPECT_EQ(ImplThroughput().frames_expected, 0u);
  EXPECT_EQ(MainThroughput().frames_expected, 0u);
}

}  // namespace cc
