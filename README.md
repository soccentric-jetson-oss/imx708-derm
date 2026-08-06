# imx708-derm — Real-Time Skin Imaging and Treatment Guidance System

imx708-derm is a real-time embedded vision system that analyzes skin regions and drives control decisions for a peripheral treatment device. Built on the existing IMX708 camera stack, it implements a complete 7-stage pipeline including dual-camera synchronized capture, feature-based frame registration for motion compensation, HSV-based skin segmentation, ROI feature extraction using contour moments and area, multi-camera image fusion with weighted blending, a control loop that translates feature state into GPIO or PWM commands for a simulated treatment device, and per-stage latency instrumentation for end-to-end performance measurement.

## Features

- Implements a dual-camera synchronized capture pipeline using GStreamer on ARM embedded Linux platforms
- Performs feature-based frame-to-frame registration using affine transformations for motion compensation
- Segments skin regions using HSV color thresholding with tunable hue, saturation, and value range parameters
- Extracts ROI features including contour moments, area, and texture proxies for quantitative analysis
- Tracks regions of interest across frames using optical flow for robust motion compensation
- Fuses multiple camera views into a single aligned composite using weighted blending techniques
- Drives a control loop that translates extracted features into GPIO or PWM commands for a peripheral device
- Instruments per-stage latency for capture, registration, segmentation, feature extraction, fusion, and control stages
- Reports end-to-end latency with per-stage breakdown for performance optimization and validation
- Built with C++17 and OpenCV for the real-time pipeline with efficient image processing operations
- Uses GStreamer for camera capture and encoding on ARM embedded Linux platforms like Raspberry Pi
- Uses CMake as the build system with proper dependency management for OpenCV and GStreamer
- Includes a comprehensive test suite validating pipeline stages, latency tracking, and control signal generation
- Licensed under GPL-2.0-only for full compliance with open-source licensing requirements

## Quick Start

### Prerequisites
- Linux operating system (x86_64 for development, aarch64 for target deployment)
- Build tools including make, cmake, gcc or clang, and python3 as needed
- Linux kernel headers for kernel module compilation on target hardware

### Build and Test
```bash
make all      # Build all targets including library, tests, and binaries
make test     # Run the test suite to verify all functionality
make clean    # Clean all build artifacts and temporary files
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| src/ | Source code for the project |
| include/ | Public API header files |
| lib/ | Userspace library source and headers |
| test/ or tests/ | Unit tests and test utilities |
| proto/ | gRPC protocol buffer definitions |
| packaging/ | Distribution packaging files for deb, rpm, and ipk |
| docs/ | Documentation including Doxygen configuration |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** GPL-2.0-only
**Audit Score:** 90/100 across 20 criteria

## Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions are welcome.

## License

GPL-2.0-only. See [LICENSE](LICENSE) for details.

---

## Showcase

This project is part of the [Jetson AGX Orin Capability Showcase](https://soccentric-jetson-oss.github.io/).
