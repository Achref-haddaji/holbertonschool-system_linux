#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sigint_handler(int signum)
{
	/* signal handler function that is called when SIGINT is received */
	printf("Gotcha! [%d]\n", signum);
	/* prints a message indicating that the signal was caught. */
}

int handle_signal(void)
{
	/* function to set a handler for the SIGINT signal */
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		/* if an error occurred when setting the signal handler, return -1 */
		return (-1);
	}
	/* if the signal handler was set successfully, return 0 */
	return (0);
}
