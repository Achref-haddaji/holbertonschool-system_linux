#ifndef CLS_H
#define CLS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <stdint.h>
#include <time.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list structure
 * for Holberton project
 */
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;

/* SINGLY LINKED LIST functions */
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *h);

/* Handlig errors functions */
void error_handler(char *directory);

/* hls functions */
void display_diractory(list_t *file_names, int *op);
void display_option(list_t *head, int *op, int mult);
void show_local(char *head, int *op);
void condition_overload(struct dirent *read, int *op);
void print_long_format(struct dirent *read);
void print_one_by_line(char *read, int *op);
list_t *handle_args(int argc, char const *argv[], int *op);

/* STRINGS UTILITYS - handling strings functions. */
int _strcmp(char const *s1, char *s2);
char *_strncpy(char *dest, char const *src, int n);
int _strlen(char const *s);
char *_strcpy(char *dest, char const *src);
char *_strdup(const char *str);

#endif
