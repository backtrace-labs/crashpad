cmake_minimum_required(VERSION 3.10)
project(demo_linux LANGUAGES CXX)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(crashpad)
endif ()

add_executable(demo_linux demo.cpp)
target_compile_features(demo_linux PRIVATE cxx_std_14)
target_link_libraries(demo_linux PRIVATE client)
