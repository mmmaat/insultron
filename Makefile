CC=g++
BIN=insultron
SRC=src/insultron.cpp src/main.cpp
INC=include/insultron.h
FLAGS=-std=c++11 -Wall -O2 -I./include

.PHONY: all clean

all: $(SRC) $(INC)
	$(CC) -o $(BIN) $(SRC) $(FLAGS)

clean:
	rm -f $(BIN)
