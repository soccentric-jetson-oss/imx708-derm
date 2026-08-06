# Dependencies

## Upstream Dependencies
- imx708-driver (kernel module for camera access)
- imx708-server (gRPC server for camera control)
- imx708-stereo (dual-camera synchronization)

## Build Dependencies
- CMake >= 3.20
- OpenCV >= 4.x (core, imgproc, video, highgui)
- GStreamer >= 1.18
- Threads (pthreads)

## Runtime Dependencies
- Raspberry Pi or Jetson (ARM embedded Linux)
- 2× IMX708 camera sensors (MIPI CSI-2)
- GPIO/peripheral device for control output

## Version Requirements
- GCC >= 9, Clang >= 10 (C/C++ projects)
- Python >= 3.9 (Python projects)
- CMake >= 3.20 (CMake projects)
- Linux kernel >= 5.15 (kernel modules)
