#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "signals.h"
#define unused __attribute__((unused))

/**
 * handler - msg handlerS
 *@info: pointer of stracter sa_sigaction
 *@unused: __attribute__((unused))
 */
void handler(int sig unused, siginfo_t *info, void *ucontext unused)
{
	printf("SIGQUIT sent by %i\n", info->si_pid);
	fflush(stdout);
}

/**
 * trace_signal_sender - catch the interprtur ctr-\
 *
 * Return:0 if success or -1 if failure
 */
int trace_signal_sender(void)
{
	struct sigaction action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;

	return (sigaction(SIGQUIT, &action, NULL));
}
