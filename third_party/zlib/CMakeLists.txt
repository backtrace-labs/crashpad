set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

set(VERSION "1.2.13.1")

include(CheckTypeSize)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckCSourceCompiles)

#
# Check to see if we have large file support
#
set(CMAKE_REQUIRED_DEFINITIONS -D_LARGEFILE64_SOURCE=1)
# We add these other definitions here because CheckTypeSize.cmake
# in CMake 2.4.x does not automatically do so and we want
# compatibility with CMake 2.4.x.
if(HAVE_SYS_TYPES_H)
    list(APPEND CMAKE_REQUIRED_DEFINITIONS -DHAVE_SYS_TYPES_H)
endif()
if(HAVE_STDINT_H)
    list(APPEND CMAKE_REQUIRED_DEFINITIONS -DHAVE_STDINT_H)
endif()
if(HAVE_STDDEF_H)
    list(APPEND CMAKE_REQUIRED_DEFINITIONS -DHAVE_STDDEF_H)
endif()
check_type_size(off64_t OFF64_T)
if(HAVE_OFF64_T)
   add_definitions(-D_LARGEFILE64_SOURCE=1)
endif()
set(CMAKE_REQUIRED_DEFINITIONS) # clear variable

#
# Check for fseeko
#
check_function_exists(fseeko HAVE_FSEEKO)
if(NOT HAVE_FSEEKO)
    add_definitions(-DNO_FSEEKO)
endif()

#
# Check for unistd.h
#
check_include_file(unistd.h Z_HAVE_UNISTD_H)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif()

set(ZLIB_PUBLIC_HDRS
    ./zlib/zconf.h
    ./zlib/zlib.h
)
set(ZLIB_PRIVATE_HDRS
    ./zlib/crc32.h
    ./zlib/deflate.h
    ./zlib/gzguts.h
    ./zlib/inffast.h
    ./zlib/inffixed.h
    ./zlib/inflate.h
    ./zlib/inftrees.h
    ./zlib/trees.h
    ./zlib/zutil.h
)
set(ZLIB_SRCS
    ./zlib/adler32.c
    ./zlib/compress.c
    ./zlib/crc32.c
    ./zlib/deflate.c
    ./zlib/gzclose.c
    ./zlib/gzlib.c
    ./zlib/gzread.c
    ./zlib/gzwrite.c
    ./zlib/inflate.c
    ./zlib/infback.c
    ./zlib/inftrees.c
    ./zlib/inffast.c
    ./zlib/trees.c
    ./zlib/uncompr.c
    ./zlib/zutil.c
)

add_library(zlib STATIC ${ZLIB_SRCS} ${ZLIB_PUBLIC_HDRS} ${ZLIB_PRIVATE_HDRS})
