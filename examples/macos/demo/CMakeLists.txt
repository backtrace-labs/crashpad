cmake_minimum_required(VERSION 3.18)
project(demo_macos LANGUAGES CXX)

add_subdirectory(crashpad)

add_executable(demo_macos demo.cpp)
target_compile_features(demo_macos PRIVATE cxx_std_14)
target_link_libraries(demo_macos PRIVATE client)
