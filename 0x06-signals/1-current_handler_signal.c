#include "signals.h"

/**
 * current_handler_signal - retrieves the current handler of SIGINT
 * Return: pointer to signal handler function
 */
void (*current_handler_signal(void))(int)
{
	/* function to retrieve the current handler of the SIGINT signal */

	sig_t handler;

	/* Declare a variable to hold the current signal handler */

	handler = signal(SIGINT, SIG_IGN);

	/* Set the signal handler for SIGINT to SIG_IGN */

	if (handler == SIG_ERR || signal(SIGINT, handler) == SIG_ERR)
		return (NULL);

	return (handler);

	/* Return a pointer to the current signal handler */
}
