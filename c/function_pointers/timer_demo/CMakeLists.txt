cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 17)

project(timer_demo)
add_executable(timer_demo 
    main.c
    src/timer_demo.c
)

target_include_directories(timer_demo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
