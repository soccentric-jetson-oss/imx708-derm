// SPDX-License-Identifier: GPL-2.0-only
/*
 * pipeline.hpp - Skin imaging pipeline stages
 *
 * Defines the 7-stage pipeline: capture, registration, segmentation,
 * feature extraction, fusion, control, and display handoff.
 */

#ifndef PIPELINE_H
#define PIPELINE_H

#include <opencv2/opencv.hpp>
#include "latency_tracker.hpp"

/// @brief Runs one iteration of the 7-stage skin imaging pipeline.
/// @param frame Input frame (simulated skin-tone image)
/// @param lt    Latency tracker for instrumentation
/// @param frame_num Current frame number for logging
void run_pipeline_stage(const cv::Mat& frame, LatencyTracker& lt, int frame_num);

#endif // PIPELINE_H
