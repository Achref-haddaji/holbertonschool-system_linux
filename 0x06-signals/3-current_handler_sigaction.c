#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/**
 * current_handler_sigaction - Retrieves the current handler of SIGINT
 * Return: Pointer to signal handler function
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction current_sig;

	sigaction(SIGINT, NULL, &current_sig);
	return (current_sig.sa_handler);
}
