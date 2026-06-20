# C++ Bazel Project Template

<p align="center">
  <img src="https://img.shields.io/badge/language-C++-blue" />
  <img src="https://img.shields.io/badge/build-Bazel-green" />
  <img src="https://img.shields.io/badge/container-Docker-blue" />
  <img src="https://img.shields.io/badge/license-MIT-lightgrey" />
</p>

A compact engineering template for starting C++ projects with Bazel. It provides
an opinionated project skeleton, Docker-based development environments, platform
configuration, and examples for wiring common native dependencies into Bazel.

This repository is intentionally a **project template**, not an algorithm
library. The `//main:hello_world` target is kept as the first clone-and-run
check: after cloning the repository, users should be able to build and run this
small executable to verify the toolchain, Bazel workspace, and dependency
wrappers.

## Contents

- [What is included](#what-is-included)
- [Repository layout](#repository-layout)
- [Quick start](#quick-start)
- [Docker workflow](#docker-workflow)
- [How to extend it](#how-to-extend-it)
- [Platform notes](#platform-notes)
- [License](#license)
- [中文说明](#中文说明)

## What is included

- A minimal Bazel workspace for C++ projects.
- `rules_cc` setup and C++17 build defaults.
- A simple `//main:hello_world` executable for first-run verification.
- Dockerfiles for Ubuntu x86_64 and Ubuntu arm64 development environments.
- Platform switches for x86_64 / aarch64 dependency selection.
- Bazel wrappers for common C++ dependencies:
  - OpenCV
  - Eigen
  - Ceres
  - glog
  - ONNX Runtime

## Repository layout

```text
.
├── WORKSPACE
├── .bazelrc
├── .bazelversion
├── config/
│   └── BUILD
├── docker/
│   ├── Dockerfile.ubuntu-arm64
│   └── Dockerfile.ubuntu-x86_64
├── main/
│   ├── BUILD
│   └── hello_world.cc
├── scripts/
│   ├── build_docker.sh
│   └── run_docker.sh
└── thirdparty/
    ├── ceres.BUILD
    ├── eigen.BUILD
    ├── glog.BUILD
    ├── onnxruntime.BUILD
    ├── onnxruntime_aarch64.BUILD
    └── opencv.BUILD
```

## Quick start

Build the sample target:

```bash
bazel build //main:hello_world
```

Run it:

```bash
bazel run //main:hello_world
```

On aarch64 platforms, select the aarch64 dependency path:

```bash
bazel run //main:hello_world --define cpu=aarch64
```

## Docker workflow

Build an x86_64 Ubuntu image:

```bash
scripts/build_docker.sh ubuntu-x86_64
```

Build an arm64 Ubuntu image:

```bash
scripts/build_docker.sh ubuntu-arm64
```

Enter the container:

```bash
scripts/run_docker.sh ubuntu-x86_64
```

Then run the Bazel target inside the container:

```bash
bazel run //main:hello_world
```

## How to extend it

A typical new project can start from this template by following these steps:

1. Keep `WORKSPACE`, `.bazelrc`, `.bazelversion`, `config/`, `docker/`, and
   `thirdparty/` as the engineering foundation.
2. Replace `main/hello_world.cc` with your own first executable after verifying
   that the template builds locally.
3. Add new C++ libraries with `cc_library` targets and depend on them from your
   application binaries.
4. Add or adjust `new_local_repository` / `http_archive` entries when your
   project needs more native dependencies.
5. Keep Docker images as the reproducible development environment when system
   dependencies become non-trivial.

## Platform notes

The OpenCV, Eigen, Ceres, and glog wrappers use Bazel `new_local_repository`
entries pointing to `/usr`. This is simple and works well inside the provided
Ubuntu Docker images, but non-Ubuntu systems may need to adjust the local
repository paths or package layout.

ONNX Runtime is fetched through `http_archive`:

- x86_64: `onnxruntime-linux-x64-gpu-1.15.0`
- aarch64: `onnxruntime-linux-aarch64-1.15.0`

The template pins Bazel through `.bazelversion` for Bazelisk users.

## License

MIT License.

## 中文说明

这是一个面向 C++ 工程开发的 Bazel 项目模板。它不是算法库，核心价值是给新项目
提供一套最小可运行的工程骨架，包括 Bazel 工作区、Docker 开发环境、跨架构配置，
以及常见 C++ 原生依赖的接入示例。

`//main:hello_world` 是保留给用户 clone 后立即编译和运行的检查程序：它会打印
hello 信息，并依次验证 OpenCV / Eigen / Ceres / ONNX Runtime 的基础链接与初始化。

如果后续要基于这个模板开发正式项目，建议先确认 `hello_world` 能跑通，再逐步替换
`main/` 下的示例代码，并把真实业务逻辑拆成独立的 `cc_library` 和 `cc_binary`。
