set(CRASHPAD_SNAPSHOT_LIBRARY_FILES
    ./annotation_snapshot.cc
    ./annotation_snapshot.h
    ./capture_memory.cc
    ./capture_memory.h
    ./cpu_architecture.h
    ./cpu_context.cc
    ./cpu_context.h
    ./crashpad_info_client_options.cc
    ./crashpad_info_client_options.h
    ./crashpad_types/image_annotation_reader.cc
    ./crashpad_types/image_annotation_reader.h
    ./exception_snapshot.h
    ./handle_snapshot.cc
    ./handle_snapshot.h
    ./memory_map_region_snapshot.h
    ./memory_snapshot_generic.h
    ./memory_snapshot.cc
    ./memory_snapshot.h
    ./minidump/exception_snapshot_minidump.cc
    ./minidump/exception_snapshot_minidump.h
    ./minidump/memory_snapshot_minidump.cc
    ./minidump/memory_snapshot_minidump.h
    ./minidump/minidump_annotation_reader.cc
    ./minidump/minidump_annotation_reader.h
    ./minidump/minidump_context_converter.cc
    ./minidump/minidump_context_converter.h
    ./minidump/minidump_simple_string_dictionary_reader.cc
    ./minidump/minidump_simple_string_dictionary_reader.h
    ./minidump/minidump_stream.h
    ./minidump/minidump_string_list_reader.cc
    ./minidump/minidump_string_list_reader.h
    ./minidump/minidump_string_reader.cc
    ./minidump/minidump_string_reader.h
    ./minidump/module_snapshot_minidump.cc
    ./minidump/module_snapshot_minidump.h
    ./minidump/process_snapshot_minidump.cc
    ./minidump/process_snapshot_minidump.h
    ./minidump/system_snapshot_minidump.cc
    ./minidump/system_snapshot_minidump.h
    ./minidump/thread_snapshot_minidump.cc
    ./minidump/thread_snapshot_minidump.h
    ./module_snapshot.h
    ./process_snapshot.h
    ./sanitized/memory_snapshot_sanitized.cc
    ./sanitized/memory_snapshot_sanitized.h
    ./sanitized/module_snapshot_sanitized.cc
    ./sanitized/module_snapshot_sanitized.h
    ./sanitized/sanitization_information.cc
    ./sanitized/sanitization_information.h
    ./sanitized/thread_snapshot_sanitized.cc
    ./sanitized/thread_snapshot_sanitized.h
    ./snapshot_constants.h
    ./system_snapshot.h
    ./thread_snapshot.h
    ./unloaded_module_snapshot.cc
    ./unloaded_module_snapshot.h
    ./x86/cpuid_reader.cc
    ./x86/cpuid_reader.h
)

if (APPLE)
    list (APPEND CRASHPAD_SNAPSHOT_LIBRARY_FILES
        ./mac/cpu_context_mac.cc
        ./mac/cpu_context_mac.h
        ./mac/exception_snapshot_mac.cc
        ./mac/exception_snapshot_mac.h
        ./mac/mach_o_image_annotations_reader.cc
        ./mac/mach_o_image_annotations_reader.h
        ./mac/mach_o_image_reader.cc
        ./mac/mach_o_image_reader.h
        ./mac/mach_o_image_segment_reader.cc
        ./mac/mach_o_image_segment_reader.h
        ./mac/mach_o_image_symbol_table_reader.cc
        ./mac/mach_o_image_symbol_table_reader.h
        ./mac/module_snapshot_mac.cc
        ./mac/module_snapshot_mac.h
        ./mac/process_reader_mac.cc
        ./mac/process_reader_mac.h
        ./mac/process_snapshot_mac.cc
        ./mac/process_snapshot_mac.h
        ./mac/process_types.cc
        ./mac/process_types.h
        ./mac/process_types/custom.cc
        ./mac/process_types/flavors.h
        ./mac/process_types/internal.h
        ./mac/process_types/traits.h
        ./mac/system_snapshot_mac.cc
        ./mac/system_snapshot_mac.h
        ./mac/thread_snapshot_mac.cc
        ./mac/thread_snapshot_mac.h
    )
else () # NOT APPLE
    list(APPEND CRASHPAD_SNAPSHOT_LIBRARY_FILES
        ./crashpad_types/crashpad_info_reader.cc
        ./crashpad_types/crashpad_info_reader.h
    )
endif (APPLE)

if (UNIX)
    list(APPEND CRASHPAD_SNAPSHOT_LIBRARY_FILES
        ./posix/timezone.cc
        ./posix/timezone.h
        ./sanitized/process_snapshot_sanitized.cc
        ./sanitized/process_snapshot_sanitized.h
    )
endif (UNIX)

if (LINUX)
    list(APPEND CRASHPAD_SNAPSHOT_LIBRARY_FILES
        ./elf/elf_dynamic_array_reader.cc
        ./elf/elf_dynamic_array_reader.h
        ./elf/elf_image_reader.cc
        ./elf/elf_image_reader.h
        ./elf/elf_symbol_table_reader.cc
        ./elf/elf_symbol_table_reader.h
        ./elf/module_snapshot_elf.cc
        ./elf/module_snapshot_elf.h
        ./linux/capture_memory_delegate_linux.cc
        ./linux/capture_memory_delegate_linux.h
        ./linux/cpu_context_linux.cc
        ./linux/cpu_context_linux.h
        ./linux/debug_rendezvous.cc
        ./linux/debug_rendezvous.h
        ./linux/exception_snapshot_linux.cc
        ./linux/exception_snapshot_linux.h
        ./linux/process_reader_linux.cc
        ./linux/process_reader_linux.h
        ./linux/process_snapshot_linux.cc
        ./linux/process_snapshot_linux.h
        ./linux/system_snapshot_linux.cc
        ./linux/system_snapshot_linux.h
        ./linux/thread_snapshot_linux.cc
        ./linux/thread_snapshot_linux.h
    )
endif (LINUX)

if (WIN32)
    list(APPEND CRASHPAD_SNAPSHOT_LIBRARY_FILES
        ./win/capture_memory_delegate_win.cc
        ./win/capture_memory_delegate_win.h
        ./win/cpu_context_win.cc
        ./win/cpu_context_win.h
        ./win/exception_snapshot_win.cc
        ./win/exception_snapshot_win.h
        ./win/memory_map_region_snapshot_win.cc
        ./win/memory_map_region_snapshot_win.h
        ./win/module_snapshot_win.cc
        ./win/module_snapshot_win.h
        ./win/pe_image_annotations_reader.cc
        ./win/pe_image_annotations_reader.h
        ./win/pe_image_reader.cc
        ./win/pe_image_reader.h
        ./win/pe_image_resource_reader.cc
        ./win/pe_image_resource_reader.h
        ./win/process_reader_win.cc
        ./win/process_reader_win.h
        ./win/process_snapshot_win.cc
        ./win/process_snapshot_win.h
        ./win/process_subrange_reader.cc
        ./win/process_subrange_reader.h
        ./win/system_snapshot_win.cc
        ./win/system_snapshot_win.h
        ./win/thread_snapshot_win.cc
        ./win/thread_snapshot_win.h
    )
endif (WIN32)

add_library(snapshot OBJECT ${CRASHPAD_SNAPSHOT_LIBRARY_FILES})

if (ANDROID)
    target_compile_features(snapshot PUBLIC cxx_std_17)
else()
    target_compile_features(snapshot PUBLIC cxx_std_14)
endif()

target_include_directories(snapshot PRIVATE ..)
target_link_libraries(snapshot PUBLIC mini_chromium util compat client)

if (WIN32)
    target_link_libraries(snapshot PUBLIC powrprof)
endif (WIN32)
