# ATU-UCTDB-MCU

Example project firmware for [UCT African Robotics Unit](https://www.africanroboticsunit.com) demonstration, targeted for the UCT Development Board.

[![Licence](https://img.shields.io/github/license/LawrenceStanton/ARU-UCTDB-MCU?label=Licence)](LICENCE.md)
![latest tag](https://img.shields.io/github/v/tag/lawrencestanton/ARU-UCTDB-MCU?color=brightgreen&label=Tag)
[![CMake](https://github.com/LawrenceStanton/ARU-UCTDB-MCU/actions/workflows/cmake.yml/badge.svg)](https://github.com/LawrenceStanton/ARU-UCTDB-MCU/actions/workflows/cmake.yml)

## Overview

This project demonstrates the use of [CMake](https://cmake.org/), [Git Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules), the [GoogleTest](https://google.github.io/googletest/) C++ unit testing framework, and [GitHub Actions](https://github.com/features/actions) for developing an embedded systems project with modern practices for software development. The project makes use of the UCT Development Board with the STM32F051C6T6 Microcontroller and [TC74](https://www.microchip.com/en-us/product/tc74) I2C temperature sensor as an example peripheral.

## How to Use

> Caveats: The below Docker-based instructions prevent the project from connecting to a USB hardware debugger, and therefore building under these options will not be able to flash the firmware to the target.

### Docker

This project provides a suitable [Dockerfile](.devcontainer/Dockerfile) for building and testing. The Dockerfile is configured to use the [ARM Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm) for cross-compilation. Simply build this Dockerfile and run the container to get started.

### VS Code Dev Containers

Given the Dockerfile, this project is also configured to launch a [VS Code Dev Container](https://code.visualstudio.com/docs/remote/containers) with the required toolchain and dependencies. Simply open the project in VS Code and select the "Reopen in Container" option when prompted, or run the same VS Code command later.

### GitHub Codespaces

Given the compatibility with Dev Containers, this project may also be used with GitHub Codespaces. Simply navigate to the [GitHub Repository](https://github.com/LawrenceStanton/ARU-UCTDB-MCU) and select the "Code" button, then "Open with Codespaces". This will launch a Codespace with the required toolchain and dependencies.

### Local Toolchain

Given the caveats of Docker builds and USB devices, a local toolchain is necessary to build and flash to the UCT Development Board. To do so, insure the following dev dependencies are installed on your system path:

1. [CMake](https://cmake.org/)
2. [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
3. [GDB](https://www.gnu.org/software/gdb/)
4. [OpenOCD](https://openocd.org/) or [ST-Link](https://www.st.com/en/development-tools/stm32cubeide.html)

With the required dependencies installed, clone the repository locally:

```zsh
git clone --recurse-submodules https://github.com/LawrenceStanton/ARU-UCTDB-MCU
cd ARU-UCTDB-MCU
code .
```

## Building

This project uses CMake with configured [presets](CMakePresets.json) for building the project. To build the project, simply run the following command:

```zsh
cmake . --preset=[Configure Preset Name]
cmake --build . --preset=[Build Preset Name]
echo "For testing only:..."
ctest --preset=[Test Preset Name]
```

Where `[Preset Name]` is the name of the preset to use. The following presets are available:

* **Server:** Builds the project locally, enabling unit testing and code coverage.
* **Debug:** Builds the project with cross-compilation, generating binaries for flashing to the target.

Additional presets may be created by adding a `CMakeUserPresets.json` file and specifying options in the Configure, Build and Test Presets fields. A common example is to add a `Local` preset for building the project locally with consideration to the individual developer's system.
