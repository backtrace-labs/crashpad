cmake_minimum_required(VERSION 3.10)
project(backtrace_crashpad LANGUAGES C CXX ASM)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

find_package(ZLIB)

if (APPLE)
    find_package(PythonInterp 2.7 REQUIRED)
endif()

if (LINUX)
    find_package(Threads REQUIRED)
endif (LINUX)

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
    add_subdirectory(third_party/openssl-android-binary)
elseif (APPLE)
    # nothing
elseif (LINUX)
    find_package(CURL REQUIRED)
else()
    set(OPENSSL_USE_STATIC_LIBS TRUE)
    find_package(OpenSSL REQUIRED)
    find_package(CURL REQUIRED)
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

if (UNIX)
    add_custom_target(crashpad ALL
        COMMAND
            ${CMAKE_AR}
            rc
            libcrashpad.a
            $<TARGET_FILE:util>
            $<TARGET_FILE:client>
            $<TARGET_FILE:mini_chromium>
        DEPENDS
            util
            client
            mini_chromium
    )
endif (UNIX)
