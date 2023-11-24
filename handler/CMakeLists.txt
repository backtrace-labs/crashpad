set(CRASHPAD_HANDLER_LIBRARY_FILES
    crash_report_upload_thread.cc
    crash_report_upload_thread.h
    handler_main.cc
    minidump_to_upload_parameters.cc
    minidump_to_upload_parameters.h
    prune_crash_reports_thread.cc
    prune_crash_reports_thread.h
    user_stream_data_source.cc
    user_stream_data_source.h
)

if (APPLE)
    list(APPEND CRASHPAD_HANDLER_LIBRARY_FILES
        mac/crash_report_exception_handler.cc
        mac/crash_report_exception_handler.h
        mac/exception_handler_server.cc
        mac/exception_handler_server.h
        mac/file_limit_annotation.cc
        mac/file_limit_annotation.h
    )
endif (APPLE)

if (LINUX)
    list(APPEND CRASHPAD_HANDLER_LIBRARY_FILES
        linux/capture_snapshot.cc
        linux/capture_snapshot.h
        linux/crash_report_exception_handler.cc
        linux/exception_handler_server.cc
        linux/exception_handler_server.h
    )
endif (LINUX)

if (WIN32)
    list(APPEND CRASHPAD_HANDLER_LIBRARY_FILES
        win/crash_report_exception_handler.cc
        win/crash_report_exception_handler.h
    )
endif (WIN32)

if (ANDROID)
    list(APPEND CRASHPAD_HANDLER_LIBRARY_FILES
        crashpad_handler_main.cc
    )
endif (ANDROID)

add_executable(handler main.cc)
target_sources(handler PRIVATE ${CRASHPAD_HANDLER_LIBRARY_FILES})
target_compile_features(handler PUBLIC cxx_std_17)
target_include_directories(handler PRIVATE ..)
target_link_libraries(handler PRIVATE client tools compat snapshot minidump)

if (APPLE)
    target_link_libraries(handler PUBLIC -lbsm)
endif (APPLE)

if (WIN32)
    target_link_libraries(handler PUBLIC crashpad_getopt)
    set_target_properties(handler PROPERTIES WIN32_EXECUTABLE TRUE)

    add_executable(handler_console main.cc)
    target_sources(handler_console PRIVATE ${CRASHPAD_HANDLER_LIBRARY_FILES})
    target_compile_features(handler_console PUBLIC cxx_std_17)
    target_include_directories(handler_console PRIVATE ..)
    target_link_libraries(handler_console PRIVATE client tools compat snapshot minidump crashpad_getopt)
endif (WIN32)

if (ANDROID)
    if (CUSTOM_CRASHPAD_HANDLER_DESTINATION)
        add_custom_command(TARGET handler POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:handler>
            ${CUSTOM_CRASHPAD_HANDLER_DESTINATION}
        )
    endif (CUSTOM_CRASHPAD_HANDLER_DESTINATION)
endif (ANDROID)

# Installation
include(GNUInstallDirs)
install(TARGETS handler
  EXPORT handler
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/backtrace/handler"
    COMPONENT backtrace_crashpad
  PRIVATE_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/backtrace/handler"
    COMPONENT backtrace_crashpad
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    COMPONENT backtrace_crashpad
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad
    NAMELINK_COMPONENT backtrace_crashpad
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad)
install(EXPORT handler
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  NAMESPACE backtrace::crashpad
  COMPONENT backtrace_crashpad)
