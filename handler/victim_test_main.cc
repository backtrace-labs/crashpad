#include <cstdio>
#include <cstdint>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "util/linux/exception_information.h"

void signal_handler(int signum, siginfo_t* siginfo, void*context)
{
    crashpad::ExceptionInformation ei;
    ei.siginfo_address = (uint64_t)siginfo;
    ei.context_address = (uint64_t)context;
    ei.thread_id = getpid();
    printf("Run crashpad_handler with these arguments to dump this process: \n");
    printf("--trace-parent-pid %d --trace-parent-with-exception %ld\n", getpid(), (intptr_t)&ei);
    while (true)
    {
        usleep(100);
    }
}

int main(int argc, char *argv[])
{
    char ptrace_scope = 0;

    FILE* ptrace_scope_file = fopen("/proc/sys/kernel/yama/ptrace_scope", "r");
    if (ptrace_scope_file != nullptr)
    {
      fread(&ptrace_scope, 1, 1, ptrace_scope_file);
      if (ptrace_scope != '0')
      {
        printf("Warning: /proc/sys/kernel/yama/ptrace_scope appears to be set to disable attaching to arbitrary processes.\n"
               "Write '1' to this file if you get ptrace access-denied errors attaching to this process\n\n");
      }
    }

    struct sigaction action;
    action.sa_sigaction = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    kill(getpid(), SIGUSR1);

    while (true)
    {
        usleep(100);
    }
} 
