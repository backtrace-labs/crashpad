set(CRASHPAD_MINI_CHROMIUM_LIBRARY_FILES
    mini_chromium/base/atomicops_internals_atomicword_compat.h
    mini_chromium/base/atomicops_internals_portable.h
    mini_chromium/base/atomicops.h
    mini_chromium/base/auto_reset.h
    mini_chromium/base/bit_cast.h
    mini_chromium/base/check_op.h
    mini_chromium/base/check.h
    mini_chromium/base/compiler_specific.h
    mini_chromium/base/cxx17_backports.h
    mini_chromium/base/debug/alias.cc
    mini_chromium/base/debug/alias.h
    mini_chromium/base/files/file_path.cc
    mini_chromium/base/files/file_path.h
    mini_chromium/base/files/file_util.h
    mini_chromium/base/files/scoped_file.cc
    mini_chromium/base/files/scoped_file.h
    mini_chromium/base/format_macros.h
    mini_chromium/base/logging.cc
    mini_chromium/base/logging.h
    mini_chromium/base/memory/free_deleter.h
    mini_chromium/base/memory/page_size.h
    mini_chromium/base/memory/scoped_policy.h
    mini_chromium/base/metrics/histogram_functions.h
    mini_chromium/base/metrics/histogram_macros.h
    mini_chromium/base/metrics/persistent_histogram_allocator.h
    mini_chromium/base/notreached.h
    mini_chromium/base/numerics/checked_math_impl.h
    mini_chromium/base/numerics/checked_math.h
    mini_chromium/base/numerics/clamped_math_impl.h
    mini_chromium/base/numerics/clamped_math.h
    mini_chromium/base/numerics/safe_conversions_arm_impl.h
    mini_chromium/base/numerics/safe_conversions_impl.h
    mini_chromium/base/numerics/safe_conversions.h
    mini_chromium/base/numerics/safe_math_arm_impl.h
    mini_chromium/base/numerics/safe_math_clang_gcc_impl.h
    mini_chromium/base/numerics/safe_math_shared_impl.h
    mini_chromium/base/numerics/safe_math.h
    mini_chromium/base/process/memory.cc
    mini_chromium/base/process/memory.h
    mini_chromium/base/rand_util.cc
    mini_chromium/base/rand_util.h
    mini_chromium/base/scoped_clear_last_error.h
    mini_chromium/base/scoped_generic.h
    mini_chromium/base/strings/string_number_conversions.cc
    mini_chromium/base/strings/string_number_conversions.h
    mini_chromium/base/strings/string_piece.h
    mini_chromium/base/strings/string_util.cc
    mini_chromium/base/strings/string_util.h
    mini_chromium/base/strings/stringprintf.cc
    mini_chromium/base/strings/stringprintf.h
    mini_chromium/base/strings/sys_string_conversions.h
    mini_chromium/base/strings/utf_string_conversion_utils.cc
    mini_chromium/base/strings/utf_string_conversion_utils.h
    mini_chromium/base/strings/utf_string_conversions.cc
    mini_chromium/base/strings/utf_string_conversions.h
    mini_chromium/base/synchronization/condition_variable.h
    mini_chromium/base/synchronization/lock_impl.h
    mini_chromium/base/synchronization/lock.cc
    mini_chromium/base/synchronization/lock.h
    mini_chromium/base/sys_byteorder.h
    mini_chromium/base/template_util.h
    mini_chromium/base/third_party/icu/icu_utf.cc
    mini_chromium/base/third_party/icu/icu_utf.h
    mini_chromium/base/threading/thread_local_storage.cc
    mini_chromium/base/threading/thread_local_storage.h
    mini_chromium/build/build_config.h
    mini_chromium/build/buildflag.h
    mini_chromium/testing/platform_test.h
)

if (UNIX)
    list(APPEND CRASHPAD_MINI_CHROMIUM_LIBRARY_FILES
        mini_chromium/base/files/file_util_posix.cc
        mini_chromium/base/memory/page_size_posix.cc
        mini_chromium/base/posix/eintr_wrapper.h
        mini_chromium/base/posix/safe_strerror.cc
        mini_chromium/base/posix/safe_strerror.h
        mini_chromium/base/strings/string_util_posix.h
        mini_chromium/base/synchronization/condition_variable_posix.cc
        mini_chromium/base/synchronization/lock_impl_posix.cc
        mini_chromium/base/threading/thread_local_storage_posix.cc
    )
endif (UNIX)

if (APPLE)
    list(APPEND CRASHPAD_MINI_CHROMIUM_LIBRARY_FILES
        mini_chromium/base/mac/close_nocancel.cc
        mini_chromium/base/mac/foundation_util.h
        mini_chromium/base/mac/foundation_util.mm
        mini_chromium/base/mac/mach_logging.cc
        mini_chromium/base/mac/mach_logging.h
        mini_chromium/base/mac/scoped_cftyperef.h
        mini_chromium/base/mac/scoped_ioobject.h
        mini_chromium/base/mac/scoped_launch_data.h
        mini_chromium/base/mac/scoped_mach_port.cc
        mini_chromium/base/mac/scoped_mach_port.h
        mini_chromium/base/mac/scoped_mach_vm.cc
        mini_chromium/base/mac/scoped_mach_vm.h
        mini_chromium/base/mac/scoped_nsautorelease_pool.h
        mini_chromium/base/mac/scoped_nsautorelease_pool.mm
        mini_chromium/base/mac/scoped_nsobject.h
        mini_chromium/base/mac/scoped_typeref.h
        mini_chromium/base/strings/sys_string_conversions_mac.mm
    )
endif (APPLE)

if (WIN32)
    list(APPEND CRASHPAD_MINI_CHROMIUM_LIBRARY_FILES
        mini_chromium/base/memory/page_size_win.cc
        mini_chromium/base/scoped_clear_last_error_win.cc
        mini_chromium/base/strings/string_util_win.cc
        mini_chromium/base/strings/string_util_win.h
        mini_chromium/base/synchronization/lock_impl_win.cc
        mini_chromium/base/threading/thread_local_storage_win.cc
    )
endif (WIN32)

add_library(mini_chromium OBJECT ${CRASHPAD_MINI_CHROMIUM_LIBRARY_FILES})
target_compile_features(mini_chromium PUBLIC cxx_std_14)
target_include_directories(mini_chromium PUBLIC mini_chromium)

if (APPLE)
    target_link_libraries(mini_chromium PUBLIC
        "-framework ApplicationServices"
        "-framework CoreFoundation"
        "-framework Foundation"
        "-framework IOKit"
        "-framework Security"
    )
endif (APPLE)

if (ANDROID)
    target_link_libraries(mini_chromium PUBLIC log)
endif (ANDROID)

if (WIN32)
    target_compile_definitions(mini_chromium PUBLIC _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(mini_chromium PUBLIC NOMINMAX)
    target_compile_definitions(mini_chromium PUBLIC UNICODE)
    target_compile_definitions(mini_chromium PUBLIC WIN32_LEAN_AND_MEAN)
endif (WIN32)
