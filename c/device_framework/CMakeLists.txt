cmake_minimum_required(VERSION 3.30)

project(DeviceFramework C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

add_executable(device_app
    src/main.c
    src/device.c
    src/network_device.c
    src/storage_device.c
)