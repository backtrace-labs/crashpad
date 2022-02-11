set(CRASHPAD_MINIDUMP_LIBRARY_FILES
    ./minidump_annotation_writer.cc
    ./minidump_annotation_writer.h
    ./minidump_byte_array_writer.cc
    ./minidump_byte_array_writer.h
    ./minidump_context_writer.cc
    ./minidump_context_writer.h
    ./minidump_context.h
    ./minidump_crashpad_info_writer.cc
    ./minidump_crashpad_info_writer.h
    ./minidump_exception_writer.cc
    ./minidump_exception_writer.h
    ./minidump_extensions.cc
    ./minidump_extensions.h
    ./minidump_file_writer.cc
    ./minidump_file_writer.h
    ./minidump_handle_writer.cc
    ./minidump_handle_writer.h
    ./minidump_memory_info_writer.cc
    ./minidump_memory_info_writer.h
    ./minidump_memory_writer.cc
    ./minidump_memory_writer.h
    ./minidump_misc_info_writer.cc
    ./minidump_misc_info_writer.h
    ./minidump_module_crashpad_info_writer.cc
    ./minidump_module_crashpad_info_writer.h
    ./minidump_module_writer.cc
    ./minidump_module_writer.h
    ./minidump_rva_list_writer.cc
    ./minidump_rva_list_writer.h
    ./minidump_simple_string_dictionary_writer.cc
    ./minidump_simple_string_dictionary_writer.h
    ./minidump_stream_writer.cc
    ./minidump_stream_writer.h
    ./minidump_string_writer.cc
    ./minidump_string_writer.h
    ./minidump_system_info_writer.cc
    ./minidump_system_info_writer.h
    ./minidump_thread_id_map.cc
    ./minidump_thread_id_map.h
    ./minidump_thread_writer.cc
    ./minidump_thread_writer.h
    ./minidump_unloaded_module_writer.cc
    ./minidump_unloaded_module_writer.h
    ./minidump_user_extension_stream_data_source.cc
    ./minidump_user_extension_stream_data_source.h
    ./minidump_user_stream_writer.cc
    ./minidump_user_stream_writer.h
    ./minidump_writable.cc
    ./minidump_writable.h
    ./minidump_writer_util.cc
    ./minidump_writer_util.h
    # ./minidump_annotation_writer_test.cc
    # ./minidump_byte_array_writer_test.cc
    # ./minidump_context_writer_test.cc
    # ./minidump_crashpad_info_writer_test.cc
    # ./minidump_exception_writer_test.cc
    # ./minidump_file_writer_test.cc
    # ./minidump_handle_writer_test.cc
    # ./minidump_memory_info_writer_test.cc
    # ./minidump_memory_writer_test.cc
    # ./minidump_misc_info_writer_test.cc
    # ./minidump_module_crashpad_info_writer_test.cc
    # ./minidump_module_writer_test.cc
    # ./minidump_rva_list_writer_test.cc
    # ./minidump_simple_string_dictionary_writer_test.cc
    # ./minidump_string_writer_test.cc
    # ./minidump_system_info_writer_test.cc
    # ./minidump_thread_id_map_test.cc
    # ./minidump_thread_writer_test.cc
    # ./minidump_unloaded_module_writer_test.cc
    # ./minidump_user_stream_writer_test.cc
    # ./minidump_writable_test.cc
    # ./test/minidump_byte_array_writer_test_util.cc
    # ./test/minidump_byte_array_writer_test_util.h
    # ./test/minidump_context_test_util.cc
    # ./test/minidump_context_test_util.h
    # ./test/minidump_file_writer_test_util.cc
    # ./test/minidump_file_writer_test_util.h
    # ./test/minidump_memory_writer_test_util.cc
    # ./test/minidump_memory_writer_test_util.h
    # ./test/minidump_rva_list_test_util.cc
    # ./test/minidump_rva_list_test_util.h
    # ./test/minidump_string_writer_test_util.cc
    # ./test/minidump_string_writer_test_util.h
    # ./test/minidump_user_extension_stream_util.cc
    # ./test/minidump_user_extension_stream_util.h
    # ./test/minidump_writable_test_util.cc
    # ./test/minidump_writable_test_util.h
)

add_library(minidump STATIC ${CRASHPAD_MINIDUMP_LIBRARY_FILES})
target_compile_features(minidump PUBLIC cxx_std_14)
target_include_directories(minidump PRIVATE ..)
target_link_libraries(minidump PUBLIC mini_chromium compat)

if (LINUX)
    target_link_libraries(minidump PUBLIC snapshot)
endif (LINUX)
