cmake_minimum_required(VERSION 3.12)
project(backtrace_crashpad LANGUAGES C CXX)
cmake_policy(SET CMP0077 NEW)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (WIN32)
    enable_language(ASM_MASM)
else ()
    enable_language(ASM)
endif ()

if (APPLE)
    find_package(Python3 COMPONENTS Interpreter REQUIRED)
endif()

if (LINUX)
    find_package(Threads REQUIRED)
endif (LINUX)

find_package(ZLIB)

add_library(backtrace_common INTERFACE)

target_compile_definitions(backtrace_common INTERFACE
    MINI_CHROMIUM_INTERNAL_BUILDFLAG_VALUE_IS_CHROMEOS_ASH=MINI_CHROMIUM_INTERNAL_BUILDFLAG_VALUE_IS_CHROMEOS
    MINI_CHROMIUM_INTERNAL_BUILDFLAG_VALUE_IS_CHROMEOS_LACROS=MINI_CHROMIUM_INTERNAL_BUILDFLAG_VALUE_IS_CHROMEOS
)

if (NOT ZLIB_FOUND)
    add_subdirectory(third_party/zlib)
    add_library(ZLIB::ZLIB ALIAS zlib)
    target_compile_definitions(backtrace_common INTERFACE
        CRASHPAD_INCLUDES CRASHPAD_ZLIB_SOURCE_EMBEDDED)
else()
    target_compile_definitions(backtrace_common INTERFACE
        CRASHPAD_INCLUDES CRASHPAD_ZLIB_SOURCE_SYSTEM)
endif()

target_compile_definitions(backtrace_common INTERFACE
    CRASHPAD_LSS_SOURCE_EMBEDDED)

if (ANDROID)
    option(CRASHPAD_HTTPS_TRANSPORT "Crashpad HTTPS transport" "OPENSSL")
    if (CRASHPAD_HTTPS_TRANSPORT STREQUAL "OPENSSL")
        add_subdirectory(third_party/openssl-android-binary)
    endif()
elseif (APPLE)
    # do nothing
elseif (LINUX)
    find_package(CURL)
else()
    set(OPENSSL_USE_STATIC_LIBS TRUE)
    find_package(OpenSSL)
    find_package(CURL)
endif (ANDROID)

if (WIN32)
    add_subdirectory(third_party/getopt)
endif (WIN32)

add_subdirectory(util)
add_subdirectory(compat)
add_subdirectory(snapshot)
add_subdirectory(minidump)
add_subdirectory(third_party/mini_chromium)
add_subdirectory(client)
add_subdirectory(handler)
add_subdirectory(tools)

if (CRASHPAD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif (CRASHPAD_BUILD_EXAMPLES)
