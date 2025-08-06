CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/game.c src/user.c src/utils.c
OUT = bin/roulette

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f bin/roulette
