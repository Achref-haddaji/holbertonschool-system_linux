#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - implement the objdump
 * @argc: count of args
 * @argv: args passed to program
 * @env: the environment
 * Return: 1 or 0
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *command[] = {"./objdump", "-s", "-f", "", NULL};

	/* Set the fourth argument of the command to the input file name */
	command[3] = argv[1];

	/* Execute the objdump command with the modified command array */
	if (execve("/usr/bin/objdump", command, env) == -1)
	{
		perror("execv");  /* Print error message if execve fails */
		return (0);  /* Return 0 to indicate failure */
	}

	return (1);  /* Return 1 to indicate success */
}
