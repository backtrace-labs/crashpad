set(CRASHPAD_TOOLS_LIBRARY_FILES
    ./tool_support.cc
    ./tool_support.h
)

if (WIN32 AND STATIC_RUNTIME)
    add_compile_options(
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:MinSizeRel>:/MT>
        $<$<CONFIG:Release>:/MT>
        $<$<CONFIG:RelWithDebInfo>:/MT>
    )
endif (WIN32 AND STATIC_RUNTIME)

add_library(tools OBJECT ${CRASHPAD_TOOLS_LIBRARY_FILES})
target_compile_features(tools PUBLIC cxx_std_14)

target_include_directories(tools PUBLIC ..)
target_link_libraries(tools PUBLIC mini_chromium backtrace_common util compat snapshot)
