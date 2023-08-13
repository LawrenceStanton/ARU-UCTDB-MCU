FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.27.2"

COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

RUN apt update && export DEBIAN_FRONTEND=noninteractive \
    && apt -y remove gcc-arm-none-eabi \
    && apt -y install --no-install-recommends openocd \
    && apt -y install --no-install-recommends clang-format \
    && apt -y upgrade

RUN apt -y install --no-install-recommends wget make xz-utils
RUN apt -y install --no-install-recommends cpio libncurses5

RUN wget https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi.tar.xz -O gcc-arm-none-eabi.tar.xz

RUN mkdir gcc-arm-none-eabi && tar xvf gcc-arm-none-eabi.tar.xz -C gcc-arm-none-eabi --strip-components 1
RUN rm gcc-arm-none-eabi.tar.xz
ENV PATH="/gcc-arm-none-eabi/bin:${PATH}"