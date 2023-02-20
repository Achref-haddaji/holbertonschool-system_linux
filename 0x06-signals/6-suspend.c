#include "signals.h"
/**
 * sigcall - print the signal
 * @sig: the signal
 */
void sigcall(int sig)
{
	printf("Caught %d\n", sig);
	fflush(stdout);
}
/**
 * main - set a handler for the signal SIGINT
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	struct sigaction new_sig;

	new_sig.sa_handler = sigcall;
	sigaction(SIGINT, &new_sig, NULL);
	pause();
	puts("Signal received");
	return (EXIT_SUCCESS);
}
