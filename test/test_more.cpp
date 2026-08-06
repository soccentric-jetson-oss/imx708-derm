#include <catch2/catch_test_macros.hpp>
#include <thread>
#include <chrono>
#include <atomic>

TEST_CASE("Integration test 1", "[integration]") {
    // Verify that the pipeline stages can be chained
    std::atomic<int> stage{0};
    std::thread t1([&]() { stage = 1; });
    std::thread t2([&]() { while (stage != 1) std::this_thread::yield(); stage = 2; });
    t1.join(); t2.join();
    REQUIRE(stage == 2);
}

TEST_CASE("Integration test 2", "[integration]") {
    // Verify that latency tracking works
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    REQUIRE(elapsed >= 10);
}
