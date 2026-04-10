cmake_minimum_required(VERSION 3.20)
project(logger_demo C)

set(CMAKE_C_STANDARD 17)

add_executable(logger_demo
    main.c
    src/writer.c
    src/formatter.c
    src/logger.c
)

target_include_directories(logger_demo PRIVATE include)