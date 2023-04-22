#include "syscalls.h"
#include "strace.h"

/**
 * main - The main function of the strace program
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @argp: Argument pointers
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[], char *argp[])
{
	/* Declare variables */
	int process_s = 0;                      // Process status
	struct user_regs_struct regs;           // Registers structure
	pid_t child_process = 0;                // Child process ID

	/* Check if there are enough arguments */
	if (argc < 2)
	{
		printf("./strace_0 command [args...]\n");
		return (1);
	}

	/* Disable buffering on stdout */
	setbuf(stdout, NULL);

	/* Create a new process */
	child_process = fork();
	if (child_process == 0)  // Child process
	{
		/* Enable tracing of the child process */
		ptrace(PTRACE_TRACEME, child_process, NULL, NULL);

		/* Stop the child process */
		raise(SIGSTOP);

		/* Execute the given command */
		execve(argv[1], &(argv[1]), argp);
	}
	else  // Parent process
	{
		/* Wait for the child process to change state */
		wait(&process_s);

		/* Check if the child process has exited */
		if (WIFEXITED(process_s))
			return (0);

		/* Begin tracing the system calls made by the child process */
		ptrace(PTRACE_SYSCALL, child_process, NULL, NULL);

		/* Continuously trace the child process until it exits */
		while (wait(&process_s) && !WIFEXITED(process_s))
		{
			/* Get the current register values of the child process */
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child_process, NULL, &regs);

			/* If the process was stopped by a system call, print the system call number */
			if (WSTOPSIG(process_s) == SIGTRAP && (long) regs.rax == -38)
				printf("%lu\n", (unsigned long) regs.orig_rax);

			/* Continue tracing the child process */
			ptrace(PTRACE_SYSCALL, child_process, NULL, NULL);
		}
	}

	return (0);
}
