#include "signals.h"

/**
 * sigcall - print the signal
 * @sig: the signal
 *
 * Return: void
 */
void sigcall(int sig)
{
	printf("Gotcha! [%i]\n", sig); /* print the signal that was caught */
	fflush(stdout);
	/* flush the output buffer to ensure the message is printed immediately */
}

/**
 * handle_sigaction - set a handler for the signal SIGINT
 *
 * Return: 0 on success, -1 on failure
 */
int handle_sigaction(void)
{
	struct sigaction new_sig;

	new_sig.sa_handler = sigcall;
	/* set the signal handler to the sigcall function */

	if (sigaction(SIGINT, &new_sig, NULL) < 0)
	/* set the new handler for SIGINT signal */

		return (-1); /* return -1 on failure */
	return (0); /* return 0 on success */
}
