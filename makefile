cc = gcc

ship: main.c
	$(cc) -o ship main.c config/config.h config/config.c -Wall -std=c99
