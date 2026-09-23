# NvPerf Core

This repository provides the C headers necessary to interface with the NvPerf
Core API which powers the
[NVIDIA Nsight Perf SDK for AI](https://github.com/NVIDIA/nsight-perf-sdk-for-ai).

Separate headers are provided for each of the supported target APIs, which
consist of CUDA, OpenGL, EGL, Vulkan, D3D11, and D3D12. Supported platforms are
x86-64 for Windows and both x86-64 and AArch64 for Linux.

## Getting Started

This repository does not contain any setup instructions or sample
applications. For setup please refer to the instructions in the
[NVIDIA Nsight Perf SDK for AI](https://github.com/NVIDIA/nsight-perf-sdk-for-ai)
repository.

## Releases

Prebuilt binaries of the NvPerf Core runtime library are available on
the
[releases page](https://github.com/NVIDIA/nvperf-core/releases)
for each tagged release version of NvPerf Core. The checksums of all binary
files corresponding to the current release are listed in the `SHA256SUMS` file,
which can be verified by running the `sha256sum --check ./SHA256SUMS`
command.

## Contributions

This project is currently not accepting contributions. See
[CONTRIBUTING.md](CONTRIBUTING.md).

## Security

Do not report potential security vulnerabilities through GitHub Issues. Follow
the private reporting process in [SECURITY.md](SECURITY.md).

## License

The NVIDIA-authored headers are licensed under the Apache License, Version 2.0.
The prebuilt runtime libraries are proprietary NVIDIA software governed by the
NVIDIA Nsight Perf SDK EULA. See [LICENSING.md](LICENSING.md) for the exact
license boundary and links to both license texts.
