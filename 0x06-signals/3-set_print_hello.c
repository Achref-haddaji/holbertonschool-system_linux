#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
/**
 * print_hello - print a message when detacted the ctr-c
 * @n: is the signum
 * Return:  void
 */

void print_hello(int n __attribute__((unused)))
{
	printf("Hello :)\n");
}

/**
 * set_print_hello - detacted the ctr-c
 * Return:  void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
