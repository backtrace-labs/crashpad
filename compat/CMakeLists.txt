set(CRASHPAD_COMPAT_LIBRARY_FILES
    # ./non_mac/mach
    # ./non_mac/mach/machine.h
    # ./non_mac/mach/vm_prot.h
    # ./non_mac/mach/mach.h
    # ./non_mac/mach-o/loader.h
    ./non_elf/elf.h
    ./ios/mach
    ./mac/AvailabilityVersions.h
    ./mac/kern/exc_resource.h
    ./mac/Availability.h
    ./mac/sys/resource.h
    ./mac/mach
    ./mac/mach/i386/thread_state.h
    ./mac/mach/mach.h
    ./mac/mach-o/loader.h
    ./linux/signal.h
    ./non_win/winnt.h
    ./non_win/minwinbase.h
    ./non_win/windows.h
    ./non_win/verrsrc.h
    ./non_win/timezoneapi.h
    ./non_win/dbghelp.h
)

if (ANDROID)
    list(APPEND CRASHPAD_COMPAT_LIBRARY_FILES
        ./linux/sys/mman_memfd_create.cc
        ./linux/sys/mman.h
        ./linux/sys/user.h
        ./linux/sys/ptrace.h
        ./android/dlfcn_internal.cc
        ./android/dlfcn_internal.h
        ./android/elf.h
        ./android/sys/epoll.h
        ./android/sys/mman_mmap.cc
        ./android/sys/mman.h
        ./android/sys/user.h
        ./android/sys/epoll.cc
        ./android/sys/syscall.h
        ./android/linux/elf.h
        ./android/linux/prctl.h
        ./android/linux/ptrace.h
        ./android/sched.h
    )
endif(ANDROID)

if (WIN32)
    list(APPEND CRASHPAD_COMPAT_LIBRARY_FILES
        ./win/time.h
        ./win/winternl.h
        ./win/strings.cc
        ./win/winnt.h
        ./win/getopt.h
        ./win/strings.h
        ./win/sys/time.h
        ./win/sys/types.h
        ./win/time.cc
        ./win/winbase.h
    )
endif (WIN32)

add_library(compat INTERFACE)

if (NOT ${CMAKE_VERSION} VERSION_LESS "3.19.0")
    target_sources(compat PRIVATE ${CRASHPAD_COMPAT_LIBRARY_FILES})
endif()

if (ANDROID)
    target_include_directories(compat INTERFACE android)
    target_include_directories(compat INTERFACE linux)
    target_include_directories(compat INTERFACE non_win)
elseif (WIN32)
    # target_include_directories(compat INTERFACE .)
    target_include_directories(compat INTERFACE win)
    # target_include_directories(compat INTERFACE linux)
else ()
    target_include_directories(compat INTERFACE .)
    target_include_directories(compat INTERFACE non_win)
endif ()

