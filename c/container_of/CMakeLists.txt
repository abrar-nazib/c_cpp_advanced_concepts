cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_STANDARD 17)

project(ContainerOfDemo C)

include_directories(include)

add_executable(container_of_demo
    src/main.c
    src/list.c
    src/task.c
)