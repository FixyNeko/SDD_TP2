CFLAGS=-Wall -Wextra -pedantic -g

SOURCES = pile.c main.c file.c truc.c

all: $(SOURCES)
	gcc $(CFLAGS) $^ -o main