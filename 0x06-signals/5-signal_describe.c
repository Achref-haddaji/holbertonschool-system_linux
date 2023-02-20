#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "signals.h"
/**
 * main - descreption of signum
 *@argc: number of arguments
 *@argv: command line arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
		return (EXIT_SUCCESS);
	}
}
