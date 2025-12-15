CC=gcc
CFLAGS=-Wall -Wextra -g
LIBS=-lncurses

all: game_of_life

game_of_life: gameoflife.o lifelib.o
	$(CC) $(CFLAGS) -o game_of_life gameoflife.o lifelib.o $(LIBS)

gameoflife.o: gameoflife.c life.h
	$(CC) $(CFLAGS) -c gameoflife.c

lifelib.o: lifelib.c life.h
	$(CC) $(CFLAGS) -c lifelib.c

clean:
	rm -f *.o game_of_life
