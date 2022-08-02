
if (APPLE)
    add_subdirectory(macos/demo)
endif (APPLE)
    
if (WIN32)
    add_subdirectory(windows/demo)
endif (WIN32)
    
if (LINUX)
    add_subdirectory(linux/demo)
endif (LINUX)
