set(CRASHPAD_TOOLS_LIBRARY_FILES
    ./tool_support.cc
    ./tool_support.h
)

add_library(tools OBJECT ${CRASHPAD_TOOLS_LIBRARY_FILES})
target_compile_features(tools PUBLIC cxx_std_14)

target_include_directories(tools PUBLIC ..)
target_link_libraries(tools PUBLIC mini_chromium backtrace_common util compat snapshot)
