CC=gcc
INCDIRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g  $(OPT)

CFILES=playGame.c player.o
OBJECTS=player.o playGame.o

BINARY=playGame

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# regular expression where % is a wildcard
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
