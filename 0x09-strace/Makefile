C= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99 -g

SRC0 = 0-strace.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = strace_0

SRC1 = 1-strace.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = strace_1

SRC2 = 2-strace.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = strace_2

SRC3 = 3-strace.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = strace_3

strace_0: syscalls.h $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

strace_1: syscalls.h $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

strace_2: syscalls.h $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

strace_3: syscalls.h $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(NAME3)
