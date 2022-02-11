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
    # ./zlib/adler32_simd.c
    # ./zlib/adler32_simd.h
    # ./zlib/chromeconf.h
    # ./zlib/contrib/bench/zlib_bench.cc
    # ./zlib/contrib/minizip/crypt.h
    # ./zlib/contrib/minizip/ioapi.c
    # ./zlib/contrib/minizip/ioapi.h
    # ./zlib/contrib/minizip/iowin32.c
    # ./zlib/contrib/minizip/iowin32.h
    # ./zlib/contrib/minizip/miniunz.c
    # ./zlib/contrib/minizip/minizip.c
    # ./zlib/contrib/minizip/mztools.c
    # ./zlib/contrib/minizip/mztools.h
    # ./zlib/contrib/minizip/unzip.c
    # ./zlib/contrib/minizip/unzip.h
    # ./zlib/contrib/minizip/zip.c
    # ./zlib/contrib/minizip/zip.h
    # ./zlib/contrib/optimizations/chunkcopy.h
    # ./zlib/contrib/optimizations/inffast_chunk.c
    # ./zlib/contrib/optimizations/inffast_chunk.h
    # ./zlib/contrib/optimizations/inflate.c
    # ./zlib/contrib/optimizations/insert_string.h
    # ./zlib/contrib/optimizations/slide_hash_neon.h
    # ./zlib/contrib/tests/fuzzers/deflate_fuzzer.cc
    # ./zlib/contrib/tests/fuzzers/deflate_set_dictionary_fuzzer.cc
    # ./zlib/contrib/tests/fuzzers/inflate_fuzzer.cc
    # ./zlib/contrib/tests/fuzzers/streaming_inflate_fuzzer.cc
    # ./zlib/contrib/tests/fuzzers/uncompress_fuzzer.cc
    # ./zlib/contrib/tests/infcover.cc
    # ./zlib/contrib/tests/infcover.h
    # ./zlib/contrib/tests/run_all_unittests.cc
    # ./zlib/contrib/tests/utils_unittest.cc
    # ./zlib/cpu_features.c
    # ./zlib/cpu_features.h
    # ./zlib/crc32_simd.c
    # ./zlib/crc32_simd.h
    # ./zlib/google/compression_utils_portable.cc
    # ./zlib/google/compression_utils_portable.h
    # ./zlib/google/compression_utils_unittest.cc
    # ./zlib/google/compression_utils.cc
    # ./zlib/google/compression_utils.h
    # ./zlib/google/test/data/test/foo/bar/.hidden
    # ./zlib/google/zip_internal.cc
    # ./zlib/google/zip_internal.h
    # ./zlib/google/zip_reader_unittest.cc
    # ./zlib/google/zip_reader.cc
    # ./zlib/google/zip_reader.h
    # ./zlib/google/zip_unittest.cc
    # ./zlib/google/zip_writer.cc
    # ./zlib/google/zip_writer.h
    # ./zlib/google/zip.cc
    # ./zlib/google/zip.h
    # ./zlib/README.chromium
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
