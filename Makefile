# Memo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

001:	001.c
	$(CC) $(CFLAGS) $^ -o $@
