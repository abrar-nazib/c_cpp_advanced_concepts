cmake_minimum_required(VERSION 3.20)
project(shape_demo C)

set(CMAKE_C_STANDARD 17)

add_executable(shape_demo
    main.c
    src/shape.c
    src/circle.c
    src/rectangle.c
    src/triangle.c
)

target_include_directories(shape_demo PRIVATE include src)
target_link_libraries(shape_demo PRIVATE m)