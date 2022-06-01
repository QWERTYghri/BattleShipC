#
# The Makefile for battleship c
# Uses headers from dir [config]
# @QWERTYghri
#

CC	:= gcc
CFLAGS	:= -std=c90 -pedantic -Werror -Wall -O2

all: game


game: main.c
	$(CC) $(CFLAGS) -o $@ $^
