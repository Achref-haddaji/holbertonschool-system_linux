#include "signals.h"
/**
 * main - set a handler for the signal SIGINT
 * @argc: count argv
 * @argv: arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
