#include <stdio.h>

void *thread_entry(void *arg)
{
    char *message = (char *)arg;
    printf("%s\n", message);
    return NULL;
}
