cmake_minimum_required(VERSION 3.20)
project(imx708-derm VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED COMPONENTS core imgproc video highgui)
find_package(Threads REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GSTREAMER gstreamer-1.0 gstreamer-app-1.0)

option(BUILD_TESTS "Build tests" ON)

add_executable(imx708-derm
    src/main.cpp
    src/pipeline.cpp
    src/capture.cpp
    src/registration.cpp
    src/segmentation.cpp
    src/features.cpp
    src/fusion.cpp
    src/control.cpp
    src/latency.cpp
)

target_include_directories(imx708-derm PRIVATE src)
target_link_libraries(imx708-derm PRIVATE
    ${OpenCV_LIBS}
    ${GSTREAMER_LIBRARIES}
    Threads::Threads
)

target_compile_options(imx708-derm PRIVATE -Wall -Wextra -O2)

if(BUILD_TESTS)
    enable_testing()
    add_test(NAME pipeline COMMAND imx708-derm --test)
endif()
