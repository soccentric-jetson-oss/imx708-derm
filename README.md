# imx708-derm — Real-Time Skin Imaging & Treatment Guidance System

Portfolio project demonstrating real-time embedded vision for medical skin imaging.
Built on the IMX708 camera stack (driver, server, GUI).

## Architecture

```
IMX708 Sensor ──► GStreamer Capture ──► OpenCV Pipeline ──► Control Output
                      │                      │                    │
                 Dual-camera sync       Registration         GPIO/PWM to
                                      Segmentation         peripheral device
                                      Feature Extraction
                                      Motion Compensation
                                      Image Fusion
```

## Pipeline Stages

1. **Capture** — Dual IMX708 synchronized capture via GStreamer
2. **Registration** — Feature-based or optical-flow frame-to-frame registration
3. **Segmentation** — Classical CV (color/texture thresholding, GrabCut) or lightweight DNN
4. **Feature Extraction** — Texture, color, geometric features from segmented ROI
5. **Motion Compensation** — Optical-flow tracking across frames
6. **Fusion** — Multi-camera view alignment and composite
7. **Control Loop** — Feature state → peripheral command (GPIO/PWM/servo)
8. **Latency Instrumentation** — Per-stage timing logged end-to-end

## JD Coverage

| JD Requirement | Project Mapping |
|----------------|-----------------|
| Real-time CV for medical skin imaging | Core pipeline with measured latency |
| Image registration & segmentation | Frame registration + ROI segmentation |
| Feature extraction | Texture/color/geometric feature vectors |
| Motion compensation | Optical-flow ROI tracking |
| Multi-camera fusion | Dual-camera synchronized capture + alignment |
| Embedded → peripheral control | GPIO/PWM control loop with latency logging |
| C/C++ and Python | C++ pipeline + Python tooling |
| Embedded Linux, ARM, GStreamer, OpenCV | Pi-based ARM target with GStreamer + OpenCV |

## Quick Start

```bash
# Build the C++ pipeline
mkdir build && cd build && cmake .. && make

# Run with dual camera
./bin/imx708-derm --device0 /dev/video0 --device1 /dev/video1

# Run calibration
python3 tools/calibrate.py
```

## License: GPL-2.0-only
