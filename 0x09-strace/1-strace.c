#include "strace.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	// check if command is provided
	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	setbuf(stdout, NULL);
	child_pid = fork();
	if (child_pid == 0)
	{
		ptrace(PTRACE_TRACEME, child_pid, NULL, NULL);
		raise(SIGSTOP);
		execve(argv[1], &(argv[1]), env); // execute command with arguments
	}
	else // parent process
	{
		wait(&status);
		if (WIFEXITED(status)) // check if child process exits normally
			return (EXIT_SUCCESS);
		ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status)) // wait for child process to stop and check if it exits normally
		{
			if (flag) // check if a syscall name was printed in previous iteration
				(printf("\n"), flag = 0);
			memset(&regs, 0, sizeof(regs)); // clear register values
			ptrace(PTRACE_GETREGS, child_pid, NULL, &regs); // get register values of the traced child process
			if (WSTOPSIG(status) == SIGTRAP && (long)regs.rax == -38) // check if syscall is being made
			{
				flag = 1; // set flag to indicate syscall name is printed
				printf("%s", (char *)syscalls_64_g[(unsigned long)regs.orig_rax].name); // print syscall name
			}
			ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
