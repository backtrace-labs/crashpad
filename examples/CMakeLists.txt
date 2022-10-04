
if (APPLE)
    add_subdirectory(macos/demo)
endif (APPLE)
    
if (WIN32)
    add_subdirectory(windows/demo)
    add_subdirectory(windows/qt-window-app)
endif (WIN32)
    
if (LINUX)
    add_subdirectory(linux/demo)
    add_subdirectory(linux/crash_loop_detection)
endif (LINUX)
