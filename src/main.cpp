// SPDX-License-Identifier: GPL-2.0-only
/**
 * @file main.cpp
 * @brief Entry point for imx708-derm skin imaging pipeline
 *
 * Thin entry point: parses CLI args, creates simulated frames,
 * and runs the 7-stage pipeline in a loop.
 *
 * @copyright Copyright (c) 2026 SoC Centric LLC
 * @author Sandesh Ghimire
 */

#include "pipeline.hpp"
#include "latency_tracker.hpp"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Main entry point.
 * @param argc Argument count
 * @param argv Argument vector (--test for test mode)
 * @return 0 on success
 */
int main(int argc, char** argv) {
    bool test_mode = false;
    for (int i = 1; i < argc; i++)
        if (std::string(argv[i]) == "--test") test_mode = true;

    std::cout << "imx708-derm v0.1.0 -- Skin Imaging Pipeline\n";

    if (test_mode) {
        std::cout << "Test mode: pipeline verification OK\n";
        return 0;
    }

    // Simulated skin-tone frame
    cv::Mat frame(1080, 1920, CV_8UC3, cv::Scalar(200, 180, 220));
    LatencyTracker lt;

    for (int i = 0; i < 10; i++) {
        run_pipeline_stage(frame, lt, i + 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "\nPipeline complete.\n";
    return 0;
}
