CC=clang
CFLAGS=-Wall -Wextra -std=c2x -pedantic
VPATH=./day1:./day2

d1: day1.c
	$(CC) $(CFLAGS) -o ./day1/day1.out ./day1/day1.c

d2: day2.c
	$(CC) $(CFLAGS) -o ./day2/day2.out ./day2/day2.c
