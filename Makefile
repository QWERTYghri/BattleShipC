#
# The Makefile for battleship c
# Uses headers from dir [config]
# @QWERTYghri
#

CC	:= gcc
CFLAGS	:= -std=c90 -pedantic -Werror -Wall

all: game.out


game.out: main.c config/conf.h
	$(CC) $(CFLAGS) -o $@ $^
