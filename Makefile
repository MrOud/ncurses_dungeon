CC=gcc
INCDIRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g -lncurses $(OPT) 

CFILES=playGame.c player.o dungeon.c curses_ui.c
OBJECTS=player.o playGame.o dungeon.o curses_ui.o

BINARY=playGame

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ -lncurses

# regular expression where % is a wildcard
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
