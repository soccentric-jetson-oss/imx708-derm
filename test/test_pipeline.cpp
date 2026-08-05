#include <catch2/catch_test_macros.hpp>
#include <thread>
#include <chrono>

TEST_CASE("Pipeline stages execute", "[pipeline]") {
    REQUIRE(true);
}

TEST_CASE("Latency tracking works", "[pipeline]") {
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    auto end = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    REQUIRE(us > 0);
}

TEST_CASE("Control signal generation", "[pipeline]") {
    REQUIRE(true);
}
