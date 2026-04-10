cmake_minimum_required(VERSION 3.15)
project(builder_pattern_demo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(builder_pattern_demo
    main.c
    counter.c
)

target_include_directories(builder_pattern_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
