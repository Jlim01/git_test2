# SLAM

SLAM in Docker within CI/CD pipeline.

---

## 1. Mid-term Request 1

![badge-open3d](https://github.com/junekimdev/kdt-ad4-team5-week17-18/actions/workflows/build_docker_open3d.yml/badge.svg)
![badge-stella](https://github.com/junekimdev/kdt-ad4-team5-week17-18/actions/workflows/build_docker_stella-vslam.yml/badge.svg)

## 2. Mid-term Request 2

![badge-team5](https://github.com/junekimdev/kdt-ad4-team5-week17-18/actions/workflows/build_docker_team5.yml/badge.svg)

---

## User Guide

### Prerequisites

- docker
- nvidia-docker
- x11-xserver-utils

### Prepare Data

1. Get dataset from RGBD camera (e.g. Intel Realsense)
2. Put them into `~/dataset/`

> #### Dataset Directory Structure
>
> - dataset/
>   - color/
>     - 00000.png (5 digit)
>   - depth/
>     - 00000.png (5 digit)

### Get Docker Image

```bash
docker pull ghcr.io/junekimdev/kdt-ad4-team5-week17-18:team5-x.x
```

### Run Docker Image

```bash
xhost +
docker run --rm --gpus all --ipc=host --net=host --privileged -e DISPLAY=unix$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v <dataset_dir>:/dataset -e NVIDIA_DRIVER_CAPABILITIES=all ghcr.io/junekimdev/kdt-ad4-team5-week17-18:team5-x.x
```
