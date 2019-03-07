CFLAGS=-Wall -Wextra -pedantic -ansi -g

SOURCES = pile.c main.c file.c

all: $(SOURCES)
	gcc $(CFLAGS) $^ -o main