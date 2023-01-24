#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - impliment the readelf
 * @argc: count of args
 * @argv: args  passed to program
 * @env:  the environment
 * Return: 1 or 0
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *command[] = {"/usr/bin/readelf", "-W", "-S", "", NULL};

	command[3] = argv[1];
	if (execve("/usr/bin/readelf", command, env) == -1)
	{
		perror("execv");
		return (0);
	}
	return (1);
}
