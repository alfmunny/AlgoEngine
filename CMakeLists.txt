cmake_minimum_required (VERSION 3.16.3)

project(AlgoEngine)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(main main.cpp)
add_subdirectory(src)
