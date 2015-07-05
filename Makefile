CC=g++
CFLAGS=-Wall

all: exploder

exploder: fibonacci_exploder.cpp
	$(CC) -std=c++11 -pthread $(CFLAGS) fibonacci_exploder.cpp -o bench
