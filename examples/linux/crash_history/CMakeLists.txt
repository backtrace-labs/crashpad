cmake_minimum_required(VERSION 3.10)
project(crash_history_linux LANGUAGES CXX)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(crashpad)
endif ()

add_executable(crash_history_linux crash_history.cpp)
target_compile_features(crash_history_linux PRIVATE cxx_std_14)
target_link_libraries(crash_history_linux PRIVATE client)
