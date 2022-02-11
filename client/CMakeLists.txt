set(CRASHPAD_CLIENT_LIBRARY_FILES
    # annotation_list_test.cc
    # annotation_test.cc
    # crash_report_database_generic.cc
    # crash_report_database_test.cc
    # crashpad_client_fuchsia.cc
    # crashpad_client_ios_test.mm
    # crashpad_client_ios.cc
    # crashpad_client_win_test.cc
    # crashpad_info_note.S
    # prune_crash_reports_test.cc
    # settings_test.cc
    # simple_address_range_bag_test.cc
    # simple_string_dictionary_test.cc
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
        # simulate_crash_mac_test.cc
        crash_report_database_mac.mm
        crashpad_client_mac.cc
        simulate_crash_mac.cc
        simulate_crash_mac.h
    )
endif (APPLE)

if (LINUX)
    list(APPEND CRASHPAD_CLIENT_LIBRARY_FILES
        # crashpad_client_linux_test.cc
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

target_link_libraries(client PUBLIC mini_chromium util)
target_include_directories(client PUBLIC ..)

if (LINUX)
    target_link_libraries(client PUBLIC Threads::Threads)
endif (LINUX)

