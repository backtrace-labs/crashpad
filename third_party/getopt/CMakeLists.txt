set(CRASHPAD_GETOPT_LIBRARY_FILES
    getopt.cc
    getopt.h
)

if (WIN32 AND STATIC_RUNTIME)
    add_compile_options(
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:MinSizeRel>:/MT>
        $<$<CONFIG:Release>:/MT>
        $<$<CONFIG:RelWithDebInfo>:/MT>
    )
endif (WIN32 AND STATIC_RUNTIME)

add_library(crashpad_getopt OBJECT)
target_sources(crashpad_getopt PRIVATE
    ${CRASHPAD_GETOPT_LIBRARY_FILES})
target_compile_features(crashpad_getopt PUBLIC cxx_std_14)
target_include_directories(crashpad_getopt PUBLIC crashpad_getopt)

