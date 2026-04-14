cmake_minimum_required(VERSION 3.25)

project(function_pointers C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(function_pointers
	main.c
    src/library.c
)

target_include_directories(function_pointers PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
