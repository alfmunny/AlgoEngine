add_subdirectory(graphics)
add_subdirectory(algorithms)

target_include_directories(graphics PUBLIC graphics)
target_include_directories(algorithms PUBLIC graphics algorithms)
target_link_libraries(main PRIVATE ${CONAN_LIBS} graphics algorithms)
