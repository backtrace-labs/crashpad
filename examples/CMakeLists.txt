
if (APPLE)
    add_subdirectory(macos/demo)
endif (APPLE)

find_package(Qt5 COMPONENTS Widgets)

if (WIN32)
    add_subdirectory(windows/demo)
    if (Qt5_FOUND)
        add_subdirectory(windows/qt-window-app)
    endif ()
endif (WIN32)

if (LINUX)
    add_subdirectory(linux/demo)
    add_subdirectory(linux/crash_loop_detection)
endif (LINUX)
