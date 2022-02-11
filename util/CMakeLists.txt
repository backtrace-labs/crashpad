set(CRASHPAD_UTIL_LIBRARY_FILES
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
    ./misc/capture_context_broken.cc
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
    ./net/http_transport_test_server.cc
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
    # ./file/delimited_file_reader_test.cc
    # ./file/directory_reader_test.cc
    # ./file/file_io_test.cc
    # ./file/file_reader_test.cc
    # ./file/filesystem_test.cc
    # ./file/string_file_test.cc
    # ./fuchsia/koid_utilities.cc
    # ./fuchsia/koid_utilities.h
    # ./fuchsia/scoped_task_suspend.cc
    # ./fuchsia/scoped_task_suspend.h
    # ./fuchsia/traits.h
    # ./ios/ios_intermediate_dump_data.cc
    # ./ios/ios_intermediate_dump_data.h
    # ./ios/ios_intermediate_dump_format.h
    # ./ios/ios_intermediate_dump_list.cc
    # ./ios/ios_intermediate_dump_list.h
    # ./ios/ios_intermediate_dump_map.cc
    # ./ios/ios_intermediate_dump_map.h
    # ./ios/ios_intermediate_dump_object.cc
    # ./ios/ios_intermediate_dump_object.h
    # ./ios/ios_intermediate_dump_reader_test.cc
    # ./ios/ios_intermediate_dump_reader.cc
    # ./ios/ios_intermediate_dump_reader.h
    # ./ios/ios_intermediate_dump_writer_test.cc
    # ./ios/ios_intermediate_dump_writer.cc
    # ./ios/ios_intermediate_dump_writer.h
    # ./ios/ios_system_data_collector.h
    # ./ios/raw_logging.cc
    # ./ios/raw_logging.h
    # ./ios/scoped_vm_read_test.cc
    # ./ios/scoped_vm_read.cc
    # ./ios/scoped_vm_read.h
    # ./misc/arraysize_test.cc
    # ./misc/capture_context_test_util_fuchsia.cc
    # ./misc/capture_context_test.cc
    # ./misc/clock_test.cc
    # ./misc/from_pointer_cast_test.cc
    # ./misc/initialization_state_dcheck_test.cc
    # ./misc/initialization_state_test.cc
    # ./misc/no_cfi_icall_test.cc
    # ./misc/paths_fuchsia.cc
    # ./misc/paths_test.cc
    # ./misc/random_string_test.cc
    # ./misc/range_set_test.cc
    # ./misc/reinterpret_bytes_test.cc
    # ./misc/scoped_forbid_return_test.cc
    # ./misc/time_test.cc
    # ./misc/uuid_test.cc
    # ./net/http_body_gzip_test.cc
    # ./net/http_body_test_util.cc
    # ./net/http_body_test_util.h
    # ./net/http_body_test.cc
    # ./net/http_multipart_builder_test.cc
    # ./net/http_transport_test.cc
    # ./net/url_test.cc
    # ./numeric/checked_address_range_test.cc
    # ./numeric/checked_range_test.cc
    # ./numeric/in_range_cast_test.cc
    # ./numeric/int128_test.cc
    # ./process/process_memory_fuchsia.cc
    # ./process/process_memory_fuchsia.h
    # ./process/process_memory_range_test.cc
    # ./process/process_memory_sanitized_test.cc
    # ./process/process_memory_test.cc
    # ./stdlib/aligned_allocator_test.cc
    # ./stdlib/map_insert_test.cc
    # ./stdlib/string_number_conversion_test.cc
    # ./stdlib/strlcpy_test.cc
    # ./stdlib/strnlen_test.cc
    # ./stdlib/thread_safe_vector_test.cc
    # ./stream/base94_output_stream_test.cc
    # ./stream/file_encoder_test.cc
    # ./stream/log_output_stream_test.cc
    # ./stream/zlib_output_stream_test.cc
    # ./string/split_string_test.cc
    # ./synchronization/semaphore_test.cc
    # ./thread/thread_log_messages_test.cc
    # ./thread/thread_test.cc
    # ./thread/worker_thread_test.cc
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
        # ./mac/checked_mach_address_range_test.cc
        # ./mac/sysctl_test.cc
        # ./mac/xattr_test.cc
        # ./mach/bootstrap_test.cc
        # ./mach/child_port_handshake_test.cc
        # ./mach/child_port_server_test.cc
        # ./mach/child_port_types.h
        # ./mach/composite_mach_message_server_test.cc
        # ./mach/exc_client_variants_test.cc
        # ./mach/exc_server_variants_test.cc
        # ./mach/exception_behaviors_test.cc
        # ./mach/exception_ports_test.cc
        # ./mach/exception_types_test.cc
        # ./mach/mach_extensions_test.cc
        # ./mach/mach_message_server_test.cc
        # ./mach/mach_message_test.cc
        # ./mach/notify_server_test.cc
        # ./mach/scoped_task_suspend_test.cc
        # ./mach/symbolic_constants_mach_test.cc
        # ./mach/task_for_pid.cc
        # ./mach/task_for_pid.h
        # ./misc/capture_context_test_util_mac.cc
        # ./process/process_memory_mac_test.cc
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
        ./posix/double_fork_and_exec.cc
        ./posix/double_fork_and_exec.h
        ./posix/process_info.h
        ./posix/scoped_dir.cc
        ./posix/scoped_dir.h
        ./posix/signals.cc
        ./posix/signals.h
        ./process/process_memory_sanitized.cc
        ./process/process_memory_sanitized.h
        ./synchronization/semaphore_posix.cc
        ./thread/thread_posix.cc
        # ./posix/drop_privileges.cc
        # ./posix/drop_privileges.h
        # ./posix/process_info_test.cc
        # ./posix/scoped_mmap_test.cc
        # ./posix/scoped_mmap.h
        # ./posix/signals_test.cc
        # ./posix/symbolic_constants_posix_test.cc
        # ./posix/symbolic_constants_posix.cc
        # ./posix/symbolic_constants_posix.h
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
        ./misc/paths_linux.cc
        ./misc/time_linux.cc
        ./net/http_transport_libcurl.cc
        ./net/http_transport_socket.cc
        ./posix/process_info_linux.cc
        ./posix/scoped_mmap.cc
        ./process/process_memory_linux.cc
        ./process/process_memory_linux.h
        # ./linux/address_types.h
        # ./linux/auxiliary_vector_test.cc
        # ./linux/checked_linux_address_range.h
        # ./linux/exception_information.h
        # ./linux/initial_signal_dispositions.cc
        # ./linux/initial_signal_dispositions.h
        # ./linux/memory_map_test.cc
        # ./linux/proc_stat_reader_test.cc
        # ./linux/proc_task_reader_test.cc
        # ./linux/ptrace_broker_test.cc
        # ./linux/ptrace_connection.h
        # ./linux/ptracer_test.cc
        # ./linux/scoped_ptrace_attach_test.cc
        # ./linux/socket_test.cc
        # ./linux/traits.h
        # ./misc/capture_context_test_util_linux.cc
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
        ./win/safe_terminate_process_broken.cc
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
        # ./misc/capture_context_test_util_win.cc
        # ./win/command_line_test.cc
        # ./win/critical_section_with_debug_info_test.cc
        # ./win/exception_handler_server_test.cc
        # ./win/get_function_test.cc
        # ./win/handle_test.cc
        # ./win/initial_client_data_test.cc
        # ./win/loader_lock_test_dll.cc
        # ./win/loader_lock_test.cc
        # ./win/process_info_test_child.cc
        # ./win/process_info_test.cc
        # ./win/registration_protocol_win_test.cc
        # ./win/safe_terminate_process_test_child.cc
        # ./win/safe_terminate_process_test.cc
        # ./win/scoped_process_suspend_test.cc
        # ./win/session_end_watcher_test.cc
    )
endif (WIN32)


add_library(util STATIC ${CRASHPAD_UTIL_LIBRARY_FILES})
target_compile_features(util PUBLIC cxx_std_14)

if (APPLE)
#
# TODO KQ
#
    set(def_relative_files "exc.defs" "mach_exc.defs" "notify.defs")
    set(input_files "${CMAKE_CURRENT_LIST_DIR}/mach/child_port.defs")

    foreach(x ${def_relative_files})
        # CMAKE_OSX_SYSROOT may be empty (e.g. for Makefile generators),
        # in this case files will be taken from root.
        set(full_path "${CMAKE_OSX_SYSROOT}/usr/include/mach/${x}")
        if(NOT EXISTS "${full_path}")
            message(FATAL_ERROR "File not found: ${full_path}")
        endif()
        list(APPEND input_files "${full_path}")
    endforeach()

    message("INPUT ${input_files}")

    set(output_dir "${CMAKE_CURRENT_BINARY_DIR}/util/mach")
    file(MAKE_DIRECTORY "${output_dir}")
    # target_include_directories(util PRIVATE ${output_dir})
    get_property(archs TARGET util PROPERTY OSX_ARCHITECTURES)
    if(NOT archs)
        if(IOS)
            set(archs "arm64")
        else()
            set(archs "x86_64")
        endif()
    endif()
    message("Archs: ${archs}")
    list(TRANSFORM archs PREPEND "--arch=")

    set(includes
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        "${CMAKE_CURRENT_SOURCE_DIR}/../compat/mac"
    )

    list(TRANSFORM includes PREPEND "--include=")

    if(CMAKE_OSX_SYSROOT)
        set(sdk --sdk ${CMAKE_OSX_SYSROOT})
    endif()

    foreach(input ${input_files})
        get_filename_component(name_we "${input}" NAME_WE)
        message("name_we: ${name_we}")
        set(output_files "")
        foreach(suffix "User.c" "Server.c" ".h" "Server.h")
            list(APPEND output_files "${output_dir}/${name_we}${suffix}")
        endforeach()
        message("${PYTHON_EXECUTABLE} "
            "${CMAKE_CURRENT_SOURCE_DIR}/mach/mig.py "
            "${archs} ${sdk} ${includes} ${input} ${output_files}")
        add_custom_command(
            OUTPUT
            ${output_files}
            COMMAND
            "${PYTHON_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/mach/mig.py" ${archs} ${sdk} ${includes} "${input}" ${output_files}
            DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/mach/mig.py" "${input}"
        )
        target_sources(util PRIVATE ${output_files})
    endforeach()
    target_include_directories(util PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/")
    target_link_libraries(util PUBLIC bsm)
#
# END TODO KQ
#
endif(APPLE)

if (ANDROID)
    target_link_libraries(util PUBLIC openssl-android-binary compat)
endif (ANDROID)

if (UNIX)
    target_link_libraries(util PUBLIC dl)
endif (UNIX)

if (WIN32)
    target_link_libraries(util PUBLIC compat winhttp version)
endif (WIN32)

target_include_directories(util PUBLIC ..)
target_link_libraries(util PUBLIC mini_chromium ZLIB::ZLIB backtrace_common)

if (LINUX AND NOT ANDROID)
    if (CURL_FOUND)
        target_link_libraries(util PUBLIC curl)
    endif (CURL_FOUND)

    if (OPENSSL_FOUND)
        target_compile_definitions(util PUBLIC CRASHPAD_USE_BORINGSSL)
        target_link_libraries(util PUBLIC OpenSSL::SSL OpenSSL::Crypto)
    endif (OPENSSL_FOUND)
endif (LINUX AND NOT ANDROID)
