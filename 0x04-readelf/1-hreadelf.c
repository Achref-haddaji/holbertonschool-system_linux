#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - read ELF file with exeve
 * @argc: number of args
 * @argv: args  passed to program
 * @env:  the environment
 * Return: -1 in fail and 0 in success
 */
int main(int argc, char **argv, char **env)
{
	char *command[] = {"/usr/bin/readelf", "-W", "-S", "", NULL};

	(void)argc;
	command[3] = argv[1];
	if (execve("/usr/bin/readelf", command, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
