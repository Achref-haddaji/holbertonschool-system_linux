#include "strace.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 * Return: EXIT_SUCCESS or error.
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	// check if enough arguments are provided
	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	// flush stdout buffer
	setbuf(stdout, NULL);

	// fork the current process
	child_pid = fork();
	if (child_pid == 0)
	{
		// allow tracing of the child process
		ptrace(PTRACE_TRACEME, child_pid, NULL, NULL);

		// stop the child process until parent resumes execution
		raise(SIGSTOP);

		// execute the requested command with its arguments
		execve(argv[1], &(argv[1]), env);
	}
	else
	{
		wait(&status);

		// check if child process exited
		if (WIFEXITED(status))
			return (0);

		ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);

		// loop until child process exits
		while (wait(&status) && !WIFEXITED(status))
		{
			memset(&regs, 0, sizeof(regs));

			ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);

			// if flag is set, print the result of the system call
			if (flag)
				(printf(" = %#lx\n", (unsigned long)regs.rax), flag = 0);

			// check if the process stopped due to a system call
			if (WSTOPSIG(status) == SIGTRAP && (long)regs.rax == -38)
				(printf("%s",
					(char *)syscalls_64_g[(unsigned long)regs.orig_rax].name),
				 flag = 1);

			ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		}

		// print the result of the last system call before child process exits
		printf(" = ?\n");
	}

	return (0);
}
