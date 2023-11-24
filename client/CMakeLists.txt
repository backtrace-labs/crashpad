set(CRASHPAD_CLIENT_LIBRARY_FILES
    annotation_list.cc
    annotation_list.h
    annotation.cc
    annotation.h
    crash_report_database.cc
    crash_report_database.h
    crashpad_client.h
    crashpad_info.cc
    crashpad_info.h
    ios_handler
    prune_crash_reports.cc
    prune_crash_reports.h
    settings.cc
    settings.h
    simple_address_range_bag.h
    simple_string_dictionary.h
    simulate_crash.h
)

if (APPLE)
    list(APPEND CRASHPAD_CLIENT_LIBRARY_FILES
        crash_report_database_mac.mm
        crashpad_client_mac.cc
        simulate_crash_mac.cc
        simulate_crash_mac.h
    )
endif (APPLE)

if (LINUX)
    list(APPEND CRASHPAD_CLIENT_LIBRARY_FILES
        client_argv_handling.cc
        client_argv_handling.h
        crash_report_database_generic.cc
        crashpad_client_linux.cc
        crashpad_info_note.S
        pthread_create_linux.cc
    )
endif (LINUX)

if (WIN32)
    list(APPEND CRASHPAD_CLIENT_LIBRARY_FILES
        crash_report_database_win.cc
        crashpad_client_win.cc
    )
endif (WIN32)

add_library(client STATIC ${CRASHPAD_CLIENT_LIBRARY_FILES})

target_compile_features(client PUBLIC cxx_std_14)

target_link_libraries(client PUBLIC mini_chromium util compat)
target_include_directories(client PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

if (LINUX)
    target_link_libraries(client PUBLIC Threads::Threads)
endif (LINUX)

# Installation
include(GNUInstallDirs)
install(TARGETS client
  EXPORT client
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/backtrace/crashpad/client"
    COMPONENT backtrace_crashpad
  PRIVATE_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/backtrace/crashpad/client"
    COMPONENT backtrace_crashpad
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    COMPONENT backtrace_crashpad
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad
    NAMELINK_COMPONENT backtrace_crashpad
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad)
install(EXPORT client
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  NAMESPACE backtrace::crashpad
  COMPONENT backtrace_crashpad)
