set(CRASHPAD_TOOLS_LIBRARY_FILES
    ./base94_encoder.cc
    ./crashpad_database_util.cc
    ./crashpad_http_upload.cc
    ./tool_support.cc
    ./tool_support.h
    # ./generate_dump.cc
    # ./run_with_crashpad.cc
)

if (APPLE)
    list(APPEND CRASHPAD_TOOLS_LIBRARY_FILES
        ./mac/catch_exception_tool.cc
        ./mac/exception_port_tool.cc
    )
endif (APPLE)

add_library(tools STATIC ${CRASHPAD_TOOLS_LIBRARY_FILES})
target_compile_features(tools PUBLIC cxx_std_14)

target_include_directories(tools PUBLIC ..)
target_link_libraries(tools PUBLIC mini_chromium backtrace_common compat)

