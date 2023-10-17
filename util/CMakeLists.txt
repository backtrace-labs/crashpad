set(CRASHPAD_UTIL_LIBRARY_FILES
    ./backtrace/crash_loop_detection.cc
    ./backtrace/crash_loop_detection.h
    ./file/delimited_file_reader.cc
    ./file/delimited_file_reader.h
    ./file/directory_reader.h
    ./file/file_helper.cc
    ./file/file_helper.h
    ./file/file_io.cc
    ./file/file_io.h
    ./file/file_reader.cc
    ./file/file_reader.h
    ./file/file_seeker.cc
    ./file/file_seeker.h
    ./file/file_writer.cc
    ./file/file_writer.h
    ./file/filesystem.h
    ./file/output_stream_file_writer.cc
    ./file/output_stream_file_writer.h
    ./file/scoped_remove_file.cc
    ./file/scoped_remove_file.h
    ./file/string_file.cc
    ./file/string_file.h
    ./misc/address_sanitizer.h
    ./misc/address_types.h
    ./misc/arraysize.h
    ./misc/as_underlying_type.h
    ./misc/capture_context_test_util.h
    ./misc/capture_context.h
    ./misc/clock.h
    ./misc/elf_note_types.h
    ./misc/from_pointer_cast.h
    ./misc/implicit_cast.h
    ./misc/initialization_state_dcheck.cc
    ./misc/initialization_state_dcheck.h
    ./misc/initialization_state.h
    ./misc/lexing.cc
    ./misc/lexing.h
    ./misc/memory_sanitizer.h
    ./misc/metrics.cc
    ./misc/metrics.h
    ./misc/no_cfi_icall.h
    ./misc/paths.h
    ./misc/pdb_structures.cc
    ./misc/pdb_structures.h
    ./misc/random_string.cc
    ./misc/random_string.h
    ./misc/range_set.cc
    ./misc/range_set.h
    ./misc/reinterpret_bytes.cc
    ./misc/reinterpret_bytes.h
    ./misc/scoped_forbid_return.cc
    ./misc/scoped_forbid_return.h
    ./misc/symbolic_constants_common.h
    ./misc/time.h
    ./misc/tri_state.h
    ./misc/uuid.cc
    ./misc/uuid.h
    ./misc/zlib.cc
    ./misc/zlib.h
    ./net/http_body_gzip.cc
    ./net/http_body_gzip.h
    ./net/http_body.cc
    ./net/http_body.h
    ./net/http_headers.h
    ./net/http_multipart_builder.cc
    ./net/http_multipart_builder.h
    ./net/http_transport.cc
    ./net/http_transport.h
    ./net/url.cc
    ./net/url.h
    ./numeric/checked_address_range.cc
    ./numeric/checked_address_range.h
    ./numeric/checked_range.h
    ./numeric/checked_vm_address_range.h
    ./numeric/in_range_cast.h
    ./numeric/int128.h
    ./numeric/safe_assignment.h
    ./process/process_id.h
    ./process/process_memory_native.h
    ./process/process_memory_range.cc
    ./process/process_memory_range.h
    ./process/process_memory.cc
    ./process/process_memory.h
    ./stdlib/aligned_allocator.cc
    ./stdlib/aligned_allocator.h
    ./stdlib/map_insert.h
    ./stdlib/objc.h
    ./stdlib/string_number_conversion.cc
    ./stdlib/string_number_conversion.h
    ./stdlib/strlcpy.cc
    ./stdlib/strlcpy.h
    ./stdlib/strnlen.cc
    ./stdlib/strnlen.h
    ./stdlib/thread_safe_vector.h
    ./stream/base94_output_stream.cc
    ./stream/base94_output_stream.h
    ./stream/file_encoder.cc
    ./stream/file_encoder.h
    ./stream/file_output_stream.cc
    ./stream/file_output_stream.h
    ./stream/log_output_stream.cc
    ./stream/log_output_stream.h
    ./stream/output_stream_interface.h
    ./stream/test_output_stream.cc
    ./stream/test_output_stream.h
    ./stream/zlib_output_stream.cc
    ./stream/zlib_output_stream.h
    ./string/split_string.cc
    ./string/split_string.h
    ./synchronization/semaphore.h
    ./thread/stoppable.h
    ./thread/thread_log_messages.cc
    ./thread/thread_log_messages.h
    ./thread/thread.cc
    ./thread/thread.h
    ./thread/worker_thread.cc
    ./thread/worker_thread.h
)

if (APPLE)
    list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
        ./mac/checked_mach_address_range.h
        ./mac/launchd.h
        ./mac/mac_util.cc
        ./mac/mac_util.h
        ./mac/service_management.cc
        ./mac/service_management.h
        ./mac/sysctl.cc
        ./mac/sysctl.h
        ./mac/xattr.cc
        ./mac/xattr.h
        ./mach/bootstrap.cc
        ./mach/bootstrap.h
        ./mach/child_port_handshake.cc
        ./mach/child_port_handshake.h
        ./mach/child_port_server.cc
        ./mach/child_port_server.h
        ./mach/composite_mach_message_server.cc
        ./mach/composite_mach_message_server.h
        ./mach/exc_client_variants.cc
        ./mach/exc_client_variants.h
        ./mach/exc_server_variants.cc
        ./mach/exc_server_variants.h
        ./mach/exception_behaviors.cc
        ./mach/exception_behaviors.h
        ./mach/exception_ports.cc
        ./mach/exception_ports.h
        ./mach/exception_types.cc
        ./mach/exception_types.h
        ./mach/mach_extensions.cc
        ./mach/mach_extensions.h
        ./mach/mach_message_server.cc
        ./mach/mach_message_server.h
        ./mach/mach_message.cc
        ./mach/mach_message.h
        ./mach/notify_server.cc
        ./mach/notify_server.h
        ./mach/scoped_task_suspend.cc
        ./mach/scoped_task_suspend.h
        ./mach/symbolic_constants_mach.cc
        ./mach/symbolic_constants_mach.h
        ./misc/clock_mac.cc
        ./misc/paths_mac.cc
        ./net/http_transport_mac.mm
        ./posix/process_info_mac.cc
        ./process/process_memory_mac.cc
        ./process/process_memory_mac.h
        ./synchronization/semaphore_mac.cc
    )
endif (APPLE)

if (UNIX)
    list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
        ./file/directory_reader_posix.cc
        ./file/file_io_posix.cc
        ./file/filesystem_posix.cc
        ./misc/clock_posix.cc
        ./misc/time.cc
        ./posix/close_multiple.cc
        ./posix/close_multiple.h
        ./posix/close_stdio.cc
        ./posix/close_stdio.h
        ./posix/process_info.h
        ./posix/scoped_dir.cc
        ./posix/scoped_dir.h
        ./posix/signals.cc
        ./posix/signals.h
        ./posix/spawn_subprocess.cc
        ./posix/spawn_subprocess.h
        ./process/process_memory_sanitized.cc
        ./process/process_memory_sanitized.h
        ./synchronization/semaphore_posix.cc
        ./thread/thread_posix.cc
    )
endif (UNIX)

if (LINUX)
    list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
        ./linux/auxiliary_vector.cc
        ./linux/auxiliary_vector.h
        ./linux/direct_ptrace_connection.cc
        ./linux/direct_ptrace_connection.h
        ./linux/exception_handler_client.cc
        ./linux/exception_handler_client.h
        ./linux/exception_handler_protocol.cc
        ./linux/exception_handler_protocol.h
        ./linux/memory_map.cc
        ./linux/memory_map.h
        ./linux/proc_stat_reader.cc
        ./linux/proc_stat_reader.h
        ./linux/proc_task_reader.cc
        ./linux/proc_task_reader.h
        ./linux/ptrace_broker.cc
        ./linux/ptrace_broker.h
        ./linux/ptrace_client.cc
        ./linux/ptrace_client.h
        ./linux/ptracer.cc
        ./linux/ptracer.h
        ./linux/scoped_pr_set_dumpable.cc
        ./linux/scoped_pr_set_dumpable.h
        ./linux/scoped_pr_set_ptracer.cc
        ./linux/scoped_pr_set_ptracer.h
        ./linux/scoped_ptrace_attach.cc
        ./linux/scoped_ptrace_attach.h
        ./linux/socket.cc
        ./linux/socket.h
        ./linux/thread_info.cc
        ./linux/thread_info.h
        ./misc/capture_context_linux.S
        ./misc/paths_linux.cc
        ./misc/time_linux.cc
        ./posix/process_info_linux.cc
        ./posix/scoped_mmap.cc
        ./process/process_memory_linux.cc
        ./process/process_memory_linux.h
    )
endif (LINUX)

if (WIN32)
    list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
        ./file/directory_reader_win.cc
        ./file/file_io_win.cc
        ./file/filesystem_win.cc
        ./misc/clock_win.cc
        ./misc/paths_win.cc
        ./misc/time_win.cc
        ./net/http_transport_win.cc
        ./process/process_memory_win.cc
        ./process/process_memory_win.h
        ./synchronization/semaphore_win.cc
        ./thread/thread_win.cc
        ./win/address_types.h
        ./win/checked_win_address_range.h
        ./win/command_line.cc
        ./win/command_line.h
        ./win/context_wrappers.h
        ./win/critical_section_with_debug_info.cc
        ./win/critical_section_with_debug_info.h
        ./win/exception_handler_server.cc
        ./win/exception_handler_server.h
        ./win/get_function.cc
        ./win/get_function.h
        ./win/get_module_information.cc
        ./win/get_module_information.h
        ./win/handle.cc
        ./win/handle.h
        ./win/initial_client_data.cc
        ./win/initial_client_data.h
        ./win/loader_lock.cc
        ./win/loader_lock.h
        ./win/module_version.cc
        ./win/module_version.h
        ./win/nt_internals.cc
        ./win/nt_internals.h
        ./win/ntstatus_logging.cc
        ./win/ntstatus_logging.h
        ./win/process_info.cc
        ./win/process_info.h
        ./win/process_structs.h
        ./win/registration_protocol_win.cc
        ./win/registration_protocol_win.h
        ./win/safe_terminate_process.h
        ./win/scoped_handle.cc
        ./win/scoped_handle.h
        ./win/scoped_local_alloc.cc
        ./win/scoped_local_alloc.h
        ./win/scoped_process_suspend.cc
        ./win/scoped_process_suspend.h
        ./win/scoped_registry_key.h
        ./win/scoped_set_event.cc
        ./win/scoped_set_event.h
        ./win/session_end_watcher.cc
        ./win/session_end_watcher.h
        ./win/termination_codes.h
        ./win/traits.h
        ./win/xp_compat.h
    )
    if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
        list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
            ./misc/capture_context_win.asm
            ./win/safe_terminate_process.asm
        )
    elseif (${CMAKE_SYSTEM_PROCESSOR} MATCHES "(arm64)}(ARM64)")
        list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
            ./misc/capture_context_win_arm64.asm
        )
    endif ()
endif (WIN32)

if (LINUX)
    if (NOT DEFINED CRASHPAD_HTTPS_TRANSPORT)
        if (OPENSSL_FOUND)
            set(CRASHPAD_HTTPS_TRANSPORT "OPENSSL" CACHE STRING "HTTPS transport to use")
        else ()
            set(CRASHPAD_HTTPS_TRANSPORT "CURL" CACHE STRING "HTTPS transport to use")
        endif ()
    endif (NOT DEFINED CRASHPAD_HTTPS_TRANSPORT)

    if (CRASHPAD_HTTPS_TRANSPORT STREQUAL "OPENSSL")
        message (STATUS "Using OpenSSL for HTTPS transport")
        list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
            ./net/http_transport_socket.cc
        )
    elseif (CRASHPAD_HTTPS_TRANSPORT STREQUAL "CURL")
        message (STATUS "Using libcurl for HTTPS transport")
        list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
            ./net/http_transport_libcurl.cc
        )
    elseif (CRASHPAD_HTTPS_TRANSPORT STREQUAL "NONE")
        message (STATUS "HTTPS transport disabled (HTTP only)")
        list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
            ./net/http_transport_socket.cc
        )
    else ()
        message(FATAL_ERROR "Unknown HTTPS transport: ${CRASHPAD_HTTPS_TRANSPORT}")
    endif ()
endif (LINUX)

if (ANDROID)
    list(APPEND CRASHPAD_UTIL_LIBRARY_FILES
        ./backtrace/android_cert_store.cc
        ./backtrace/android_cert_store.h
        ./backtrace/certs_pem.h
    )
endif (ANDROID)

add_library(util OBJECT ${CRASHPAD_UTIL_LIBRARY_FILES})
target_compile_features(util PUBLIC cxx_std_17)

if (APPLE)
    set(DEF_FILES "exc.defs" "mach_exc.defs" "notify.defs")
    set(CHILD_PORT_DEFS "${CMAKE_CURRENT_LIST_DIR}/mach/child_port.defs")

    foreach (ONE_DEF_FILE ${DEF_FILES})
        set(ABSOLUTE_PATH_DEF "${CMAKE_OSX_SYSROOT}/usr/include/mach/${ONE_DEF_FILE}")
        if (NOT EXISTS ${ABSOLUTE_PATH_DEF})
            message(FATAL_ERROR "File does not exist: ${ABSOLUTE_PATH_DEF}")
        endif()
        list(APPEND CHILD_PORT_DEFS ${ABSOLUTE_PATH_DEF})
    endforeach()

    set(OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/util/mach")
    file(MAKE_DIRECTORY "${OUTPUT_PATH}")

    foreach(CPD ${CHILD_PORT_DEFS})
        get_filename_component(BASE_NAME "${CPD}" NAME_WE)
        set(OUTPUT_FILES "")
        foreach(SUFFIX "User.c" "Server.c" ".h" "Server.h")
            list(APPEND OUTPUT_FILES "${OUTPUT_PATH}/${BASE_NAME}${SUFFIX}")
        endforeach()

        if (${CMAKE_OSX_ARCHITECTURES})
            set(MIG_ARCH ${CMAKE_OSX_ARCHITECTURES})
        else()
            set(MIG_ARCH "arm64")
        endif()

        add_custom_command(
            OUTPUT
                ${OUTPUT_FILES}
            COMMAND
                "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/mach/mig.py"
                    "--arch" ${MIG_ARCH}
                    "--sdk" ${CMAKE_OSX_SYSROOT}
                    "--include=${CMAKE_CURRENT_SOURCE_DIR}/.."
                    "--include=${CMAKE_CURRENT_SOURCE_DIR}/../compat/mac"
                    ${CPD} ${OUTPUT_FILES}
            DEPENDS
                "${CMAKE_CURRENT_SOURCE_DIR}/mach/mig.py" "${CPD}"
        )
        target_sources(util PRIVATE ${OUTPUT_FILES})
    endforeach()
    target_include_directories(util PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/")
    target_link_libraries(util PUBLIC bsm)
endif (APPLE)


if (CRASHPAD_HTTPS_TRANSPORT STREQUAL "OPENSSL")
    if (NOT ANDROID)
        find_package(OpenSSL REQUIRED)
        target_compile_definitions(util PUBLIC CRASHPAD_USE_BORINGSSL)
        target_link_libraries(util PUBLIC OpenSSL::SSL OpenSSL::Crypto)
    else()
        target_link_libraries(util PUBLIC openssl-android-binary)
        target_compile_definitions(util PUBLIC CRASHPAD_USE_BORINGSSL)
    endif()
elseif (CRASHPAD_HTTPS_TRANSPORT STREQUAL "CURL")
    target_link_libraries(util PUBLIC CURL::libcurl)
endif ()

if (UNIX)
    target_link_libraries(util PUBLIC dl)
endif (UNIX)

if (WIN32)
    target_link_libraries(util PUBLIC winhttp version compat_incl)
endif (WIN32)

target_include_directories(util PUBLIC ..)
target_link_libraries(util PUBLIC mini_chromium ZLIB::ZLIB backtrace_common)

if (LINUX AND NOT ANDROID)
    if (OPENSSL_FOUND)
        target_compile_definitions(util PUBLIC CRASHPAD_USE_BORINGSSL)
        target_link_libraries(util PUBLIC OpenSSL::SSL OpenSSL::Crypto)
    endif (OPENSSL_FOUND)
endif (LINUX AND NOT ANDROID)

if (ANDROID)
    target_compile_definitions(util PUBLIC CRASHPAD_FLOCK_ALWAYS_SUPPORTED=0)
else ()
    target_compile_definitions(util PUBLIC CRASHPAD_FLOCK_ALWAYS_SUPPORTED=1)
endif ()

if (ANDROID)
    if (CRASHPAD_HTTPS_TRANSPORT STREQUAL "OPENSSL")
        # handled above
    elseif(CRASHPAD_HTTPS_TRANSPORT STREQUAL "NONE")
    else()
        message(FATAL_ERROR "Unknown value for CRASHPAD_HTTPS_TRANSPORT: ${CRASHPAD_HTTPS_TRANSPORT}")
    endif ()
endif (ANDROID)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(util PUBLIC -Wno-multichar)
endif ()
