set(CRASHPAD_ZLIB_LIBRARY_FILES
    ./zlib_crashpad.h
    ./zlib/adler32.c
    ./zlib/compress.c
    ./zlib/crc_folding.c
    ./zlib/crc32.c
    ./zlib/crc32.h
    ./zlib/deflate.c
    ./zlib/deflate.h
    ./zlib/fill_window_sse.c
    ./zlib/gzclose.c
    ./zlib/gzguts.h
    ./zlib/gzlib.c
    ./zlib/gzread.c
    ./zlib/gzwrite.c
    ./zlib/infback.c
    ./zlib/inffast.c
    ./zlib/inffast.h
    ./zlib/inffixed.h
    ./zlib/inflate.c
    ./zlib/inflate.h
    ./zlib/inftrees.c
    ./zlib/inftrees.h
    ./zlib/names.h
    ./zlib/trees.c
    ./zlib/trees.h
    ./zlib/uncompr.c
    ./zlib/zconf.h
    ./zlib/zlib.h
    ./zlib/zutil.c
    ./zlib/zutil.h
)

if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "(x86_64)|(AMD64)")
    list(APPEND CRASHPAD_ZLIB_LIBRARY_FILES
        ./zlib/x86.c
    )
endif ()

add_library(zlib STATIC)
target_sources(zlib PRIVATE
    ${CRASHPAD_ZLIB_LIBRARY_FILES}
)
target_compile_features(zlib PUBLIC cxx_std_14)

target_compile_definitions(zlib PUBLIC CRASHPAD_ZLIB_SOURCE_EMBEDDED)
target_compile_definitions(zlib PUBLIC ZLIB_CONST)
target_compile_definitions(zlib PUBLIC HAVE_STDARG_H)

target_include_directories(zlib PUBLIC .. zlib)
