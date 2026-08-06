// SPDX-License-Identifier: GPL-2.0-only
/**
 * @file latency_tracker.cpp
 * @brief Pipeline latency instrumentation implementation
 *
 * Tracks per-stage latency for the 7-stage skin imaging pipeline.
 *
 * @copyright Copyright (c) 2026 SoC Centric LLC
 * @author Sandesh Ghimire
 */

#include "latency_tracker.hpp"

void LatencyTracker::start_stage(const std::string& name) {
    Stage s;
    s.name = name;
    s.start = std::chrono::steady_clock::now();
    stages_.push_back(s);
}

void LatencyTracker::end_stage() {
    if (stages_.empty()) return;
    auto& s = stages_.back();
    auto end = std::chrono::steady_clock::now();
    s.latency_ms = std::chrono::duration<double, std::milli>(end - s.start).count();
}

void LatencyTracker::report() {
    std::cout << "\n=== Latency Report ===\n";
    double total = 0;
    for (auto& s : stages_) {
        total += s.latency_ms;
        std::cout << "  " << s.name << ": " << s.latency_ms << " ms\n";
    }
    std::cout << "  TOTAL: " << total << " ms\n";
    stages_.clear();
}
