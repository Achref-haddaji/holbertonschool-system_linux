#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int handle_signal(void);
void (*current_handler_signal(void))(int);
void print_hello(int sig);
void set_print_hello(void);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);
void handler(int sig, siginfo_t *info, void *ucontext);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);

#endif /* SIGNALS_H */
