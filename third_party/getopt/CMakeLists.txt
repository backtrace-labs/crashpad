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
    add_compile_definitions(
        $<$<CONFIG:Debug>:_ITERATOR_DEBUG_LEVEL=0>
    )
endif (WIN32 AND STATIC_RUNTIME)

add_library(crashpad_getopt OBJECT)

if (WIN32 AND STATIC_RUNTIME)
    set_target_properties(crashpad_getopt PROPERTIES STATIC_LIBRARY_OPTIONS "/NODEFAULTLIB;")
endif (WIN32 AND STATIC_RUNTIME)

target_sources(crashpad_getopt PRIVATE
    ${CRASHPAD_GETOPT_LIBRARY_FILES})
target_compile_features(crashpad_getopt PUBLIC cxx_std_14)
target_include_directories(crashpad_getopt PUBLIC crashpad_getopt)

