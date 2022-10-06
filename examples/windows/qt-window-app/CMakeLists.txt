cmake_minimum_required(VERSION 3.17)

# project(qt_window_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(crashpad)
endif ()

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    backtrace.cpp
    backtrace.hpp
    backtrace.qrc
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
)

add_executable(qt_window_app ${PROJECT_SOURCES})

target_link_libraries(qt_window_app PRIVATE Qt5::Gui Qt5::Core Qt5::Widgets client)
target_compile_features(qt_window_app PRIVATE cxx_std_17)

if (WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/app.rc")
    set_target_properties(qt_window_app PROPERTIES WIN32_EXECUTABLE TRUE)
    target_sources(qt_window_app PRIVATE ${APP_ICON_RESOURCE_WINDOWS})
endif ()
