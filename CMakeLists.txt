cmake_minimum_required(VERSION 3.20)
project(imx708-derm VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Compiler warnings ──────────────────────────────────────────────────
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

find_package(OpenCV REQUIRED COMPONENTS core imgproc video highgui)
find_package(Threads REQUIRED)

option(BUILD_TESTS "Build tests" ON)

# ── Library: imx708-core ──────────────────────────────────────────────
add_library(imx708-core STATIC
    src/pipeline.cpp
    src/latency_tracker.cpp
)
target_include_directories(imx708-core PUBLIC include)
target_link_libraries(imx708-core PUBLIC ${OpenCV_LIBS} Threads::Threads)

# ── Executable ─────────────────────────────────────────────────────────
add_executable(imx708-derm src/main.cpp)
target_include_directories(imx708-derm PRIVATE include)
target_link_libraries(imx708-derm PRIVATE imx708-core)

# ── Tests ──────────────────────────────────────────────────────────────
if(BUILD_TESTS)
    enable_testing()
    add_test(NAME pipeline COMMAND imx708-derm --test)
endif()

# ── Formatting & Linting ──────────────────────────────────────────────
find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    file(GLOB_RECURSE FORMAT_SOURCES src/*.cpp include/*.hpp)
    add_custom_target(format COMMAND ${CLANG_FORMAT} -i ${FORMAT_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    add_custom_target(format-check COMMAND ${CLANG_FORMAT} --dry-run --Werror ${FORMAT_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    file(GLOB_RECURSE LINT_SOURCES src/*.cpp include/*.hpp)
    add_custom_target(lint COMMAND ${CPPCHECK} --enable=all --inconclusive
        --suppress=missingIncludeSystem ${LINT_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# ── Documentation (Doxygen) ──────────────────────────────────────────────
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile @ONLY)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
