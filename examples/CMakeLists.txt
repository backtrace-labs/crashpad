
if (APPLE)
    add_subdirectory(macos/demo)
endif (APPLE)

if (WIN32)
    find_package(Qt5 COMPONENTS Widgets)

    add_subdirectory(windows/demo)
    if (Qt5_FOUND)
        add_subdirectory(windows/qt-window-app)
    endif ()
endif (WIN32)

if (LINUX)
    add_subdirectory(linux/demo)
    add_subdirectory(linux/crash_loop_detection)
endif (LINUX)
