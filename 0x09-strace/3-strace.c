#include "strace.h"

void syscall_param(struct user_regs_struct registers);

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

   if (argc < 2)
   {
      printf("Usage: %s command [args...]\n", argv[0]);
      return (EXIT_FAILURE);
   }
   setbuf(stdout, NULL);
   child_pid = fork();
   if (child_pid == -1)
   {
      dprintf(STDERR_FILENO, "Fork fail: %d\n", errno);
      exit(-1);
   }
   if (child_pid == 0)
   {
      ptrace(PTRACE_TRACEME, child_pid, NULL, NULL);
      raise(SIGSTOP);
      execve(argv[1], &(argv[1]), env);
   }
   else
   {
      wait(&status);
      if (WIFEXITED(status))
         return (0);
      ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
      while (wait(&status) && !WIFEXITED(status))
      {
         memset(&regs, 0, sizeof(regs));
         ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);
         if (flag)
            (printf(") = %#lx\n", (unsigned long)regs.rax), flag = 0);
         if (WSTOPSIG(status) == SIGTRAP && (long)regs.rax == -38)
            (printf("%s(",
                    (char *)syscalls_64_g[(unsigned long)regs.orig_rax].name),
             syscall_param(regs), flag = 1);
         ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
      }
      printf(") = ?\n");
   }
   return (0);
}

/**
 * syscall_param - print the parametres of a given syscall
 * @regs: struct with the register syscall
 * Return: nothing
 */
void syscall_param(struct user_regs_struct regs)
{
   unsigned long parameter[6] = {0};
   size_t nb_params, i = 0;

   parameter[0] = (unsigned long)regs.rdi;
   parameter[1] = (unsigned long)regs.rsi;
   parameter[2] = (unsigned long)regs.rdx;
   parameter[3] = (unsigned long)regs.r10;
   parameter[4] = (unsigned long)regs.r8;
   parameter[5] = (unsigned long)regs.r9;

   nb_params = syscalls_64_g[(unsigned long)regs.orig_rax].nb_params;

   while (i < nb_params)
   {
      if (i > 0)
         printf(", ");
      if (syscalls_64_g[(unsigned long)regs.orig_rax].params[i] == VARARGS)
         printf("...");
      else if (syscalls_64_g[(unsigned long)regs.orig_rax].params[i] != VOID)
         printf("%#lx", parameter[i]);
      i++;
   }
}
