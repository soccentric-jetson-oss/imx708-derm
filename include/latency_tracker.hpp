// SPDX-License-Identifier: GPL-2.0-only
/*
 * latency_tracker.hpp - Pipeline latency instrumentation
 *
 * Tracks per-stage latency for the 7-stage skin imaging pipeline:
 * capture, registration, segmentation, feature extraction, fusion,
 * control, and display.
 */

#ifndef LATENCY_TRACKER_H
#define LATENCY_TRACKER_H

#include <string>
#include <vector>
#include <iostream>
#include <chrono>

/// @brief Tracks and reports per-stage latency for the imaging pipeline.
class LatencyTracker {
public:
    /// @brief Start timing a new pipeline stage.
    void start_stage(const std::string& name);

    /// @brief End timing the current stage and record latency.
    void end_stage();

    /// @brief Print latency report and clear all stages.
    void report();

private:
    struct Stage {
        std::string name;
        double latency_ms{0};
        std::chrono::steady_clock::time_point start;
    };
    std::vector<Stage> stages_;
};

#endif // LATENCY_TRACKER_H
