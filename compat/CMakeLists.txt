set(CRASHPAD_COMPAT_LIBRARY_FILES
    ./linux/signal.h
    ./mac/Availability.h
    ./mac/AvailabilityVersions.h
    ./mac/kern/exc_resource.h
    ./mac/mach-o/loader.h
    ./mac/mach/i386/thread_state.h
    ./mac/mach/mach.h
    ./mac/sys/resource.h
    ./non_win/dbghelp.h
    ./non_win/minwinbase.h
    ./non_win/timezoneapi.h
    ./non_win/verrsrc.h
    ./non_win/windows.h
    ./non_win/winnt.h
)

if (ANDROID)
    list(APPEND CRASHPAD_COMPAT_LIBRARY_FILES
        ./android/dlfcn_internal.cc
        ./android/dlfcn_internal.h
        ./android/elf.h
        ./android/linux/elf.h
        ./android/linux/prctl.h
        ./android/linux/ptrace.h
        ./android/sched.h
        ./android/sys/epoll.cc
        ./android/sys/epoll.h
        ./android/sys/mman_mmap.cc
        ./android/sys/mman.h
        ./android/sys/syscall.h
        ./android/sys/user.h
        ./linux/sys/mman_memfd_create.cc
        ./linux/sys/mman.h
        ./linux/sys/ptrace.h
        ./linux/sys/user.h
    )
endif(ANDROID)

if (WIN32)
    list(APPEND CRASHPAD_COMPAT_LIBRARY_FILES
        ./win/getopt.h
        ./win/strings.cc
        ./win/strings.h
        ./win/sys/time.h
        ./win/sys/types.h
        ./win/time.cc
        ./win/time.h
        ./win/winbase.h
        ./win/winnt.h
        ./win/winternl.h
    )
endif (WIN32)

add_library(compat_incl INTERFACE)
add_library(compat OBJECT)
set_target_properties(compat PROPERTIES LINKER_LANGUAGE CXX)

target_sources(compat PRIVATE ${CRASHPAD_COMPAT_LIBRARY_FILES})
target_link_libraries(compat PUBLIC util compat_incl)

if (LINUX)
    target_include_directories(compat_incl INTERFACE linux)
    target_include_directories(compat_incl INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
endif (LINUX)

if (ANDROID)
    target_include_directories(compat_incl INTERFACE android)
endif (ANDROID)

if (WIN32)
    target_include_directories(compat_incl INTERFACE win)
else ()
    target_include_directories(compat_incl INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
endif (WIN32)

# Installation
include(GNUInstallDirs)
install(TARGETS compat compat_incl
  EXPORT compat
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/crashpad/compat"
    COMPONENT backtrace_crashpad
  PRIVATE_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/crashpad/compat"
    COMPONENT backtrace_crashpad
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    COMPONENT backtrace_crashpad
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad
    NAMELINK_COMPONENT backtrace_crashpad
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT backtrace_crashpad)
install(EXPORT compat
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  NAMESPACE backtrace::crashpad
  COMPONENT backtrace_crashpad)