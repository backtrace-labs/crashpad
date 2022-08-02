cmake_minimum_required(VERSION 3.10)
project(demo_windows LANGUAGES CXX)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(crashpad)
endif ()

add_executable(demo_windows demo.cpp)
target_compile_features(demo_windows PRIVATE cxx_std_14)
target_link_libraries(demo_windows PRIVATE client)
