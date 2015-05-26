CC=g++
BIN=insultron
SRC=src/*.cpp
FLAGS=-std=c++11 -Wall -O2 -I./include

.PHONY: all clean

all: $(SRC)
	$(CC) -o $(BIN) $(SRC) $(FLAGS)

clean:
	rm -f $(BIN)
