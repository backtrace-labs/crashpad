set(CRASHPAD_GETOPT_LIBRARY_FILES
    getopt.cc
    getopt.h
)

add_library(crashpad_getopt OBJECT)
target_sources(crashpad_getopt PRIVATE
    ${CRASHPAD_GETOPT_LIBRARY_FILES})
target_compile_features(crashpad_getopt PUBLIC cxx_std_14)
target_include_directories(crashpad_getopt PUBLIC crashpad_getopt)

