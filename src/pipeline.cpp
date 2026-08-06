// SPDX-License-Identifier: GPL-2.0-only
/**
 * @file pipeline.cpp
 * @brief Skin imaging pipeline implementation
 *
 * Implements the 7-stage pipeline with OpenCV operations:
 * 1. Capture (simulated)
 * 2. Registration (affine warp)
 * 3. Segmentation (HSV thresholding)
 * 4. Feature extraction (moments)
 * 5. Fusion (weighted blend)
 * 6. Control (PWM signal generation)
 * 7. Display handoff
 *
 * @copyright Copyright (c) 2026 SoC Centric LLC
 * @author Sandesh Ghimire
 */

#include "pipeline.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void run_pipeline_stage(const cv::Mat& frame, LatencyTracker& lt, int frame_num) {
    std::cout << "\n--- Frame " << frame_num << " ---\n";

    // Stage 1: Capture (simulated sensor read)
    lt.start_stage("Capture");
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    lt.end_stage();

    // Stage 2: Registration (affine transform for motion compensation)
    lt.start_stage("Registration");
    cv::Mat registered;
    cv::warpAffine(frame, registered,
                   cv::getRotationMatrix2D(cv::Point2f(960, 540), 0.5, 1.0),
                   frame.size());
    lt.end_stage();

    // Stage 3: Segmentation (HSV skin-color thresholding)
    lt.start_stage("Segmentation");
    cv::Mat hsv, mask;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
    cv::inRange(hsv, cv::Scalar(0, 20, 60), cv::Scalar(20, 150, 200), mask);
    lt.end_stage();

    // Stage 4: Feature extraction (contour moments)
    lt.start_stage("Feature Extraction");
    cv::Moments m = cv::moments(mask, true);
    double area = m.m00;
    std::cout << "  ROI area: " << area << " pixels\n";
    lt.end_stage();

    // Stage 5: Fusion (weighted blending of original + registered)
    lt.start_stage("Fusion");
    cv::Mat fused;
    cv::addWeighted(frame, 0.5, registered, 0.5, 0, fused);
    lt.end_stage();

    // Stage 6: Control (translate feature state to PWM)
    lt.start_stage("Control");
    int pwm_value = static_cast<int>(area / 1000);
    std::cout << "  Control signal: PWM=" << pwm_value << "\n";
    lt.end_stage();

    // Stage 7: Display handoff
    lt.start_stage("Display Handoff");
    std::cout << "  Display handoff: " << frame.cols << "x" << frame.rows << "\n";
    lt.end_stage();

    lt.report();
}
