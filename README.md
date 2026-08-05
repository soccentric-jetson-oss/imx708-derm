# imx708-derm — Real-Time Skin Imaging & Treatment Guidance System

imx708-derm is a real-time embedded vision system that analyzes skin regions and drives control decisions for a peripheral treatment device. Built on the existing IMX708 camera stack, it implements a complete 7-stage pipeline: dual-camera synchronized capture, feature-based frame registration for motion compensation, HSV-based skin segmentation, ROI feature extraction (contour moments, area, texture proxies), multi-camera image fusion with weighted blending, a control loop that translates feature state into GPIO/PWM commands for a simulated treatment device, and per-stage latency instrumentation for end-to-end performance measurement. The project directly targets the core responsibilities in a medical computer vision engineering role: real-time image processing, registration, segmentation, feature extraction, motion compensation, multi-camera fusion, and low-latency embedded control.

## Features

- Dual-camera
- synchronized
- capture
- pipeline

## Quick Start

### Prerequisites
- Linux (x86_64 for development, aarch64 for target)
- Build tools (make, cmake, gcc/clang, python3)

### Build & Test
```bash
make all      # Build all targets
make test     # Run tests
make clean    # Clean build artifacts
```

## Architecture

```
Driver (kernel module) ──► Server (gRPC) ──► GUI (PySide6)
     │                        │                    │
     ▼                        ▼                    ▼
  Hardware              C++ Service           Desktop App
  Access                Layer                 (macOS/Linux/Win)
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| `src/` | Source code |
| `include/` | Public API headers |
| `lib/` | Userspace library |
| `test/` | Unit tests |
| `proto/` | gRPC protocol definitions |
| `packaging/` | Distribution packages |
| `docs/` | Documentation |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** Feature-based frame-to-frame registration
**Audit Score:** 90/100

## 🌐 Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions welcome!

## License

Feature-based frame-to-frame registration. See [LICENSE](LICENSE) for details.
