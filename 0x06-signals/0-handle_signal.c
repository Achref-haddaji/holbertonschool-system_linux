#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * sigint_handler - signal handler function
 * @signum: the signal number
 **/
void sigint_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
 * handle_signal - function to set a handler for the SIGINT signal
 * Return: 0 on success, -1 on error
 **/
int handle_signal(void)
{
	if (signal(SIGINT, sigint_handler) == SIG_ERR) /* if an error, return -1 */
	{
		return (-1);
	}

	return (0); /* if the signal handler was set successfully, return 0 */
}
