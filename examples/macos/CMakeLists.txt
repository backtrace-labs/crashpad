cmake_minimum_required(VERSION 3.18)
project(demo LANGUAGES CXX)

add_subdirectory(crashpad)

add_executable(demo demo.cpp)
target_compile_features(tools PRIVATE cxx_std_14)
target_link_libraries(demo PRIVATE client)
