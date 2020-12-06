add_library(
    algo
    graphics/window.cpp
    graphics/window.h
    graphics/shader.h
    )

target_include_directories(algo PUBLIC graphics)
