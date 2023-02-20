#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handler - handle the SIGQUIT signal
 * @signum: signal number
 */
void handler(int signum)
{
printf("SIGQUIT sent by %d\n", signum);
}

/**
 * trace_signal_sender - trace signal sender
 * Return: 0 on success, -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_handler = handler;
	.sa_flags = SA_SIGINFO;

	if (sigaction(SIGQUIT, &act, NULL) < 0)
		return (-1);

	return (0);
}
