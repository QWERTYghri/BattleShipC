/*
 * main.c file for battleship c
 *
 * Holds all the code for the project
 *
 * @QWERTYghri
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/* Definitions */
#define MAX_GRID	( ( uint32_t ) 8 )
#define SHOW_NUM	( ( uint32_t ) 0 )
#define MAX_TRIES	( ( uint32_t ) 4 )
#define MAX_STR_IN	( ( uint32_t ) 50 )
#define BASE_10		( ( uint32_t ) 10 )

char gameGrid[MAX_GRID][MAX_GRID];

/* Func prototypes */
int32_t getStrNum ( void )
{
	char tmpBuf[MAX_STR_IN];

	if ( !fgets ( tmpBuf, MAX_STR_IN, stdin ) )
		return -1;

	return ( ( int32_t ) strtol ( tmpBuf, NULL, BASE_10 ) );
}

void initGrid ( void )
{
	uint32_t y, x;

	for ( y = 0; y < MAX_GRID; y++ )
	{
		for ( x = 0; x < MAX_GRID; x++ )
		{
			gameGrid[y][x] = 'O';

			if (  )
				gameGrid[y][x] = '0' + x;
		}
	}
	gameGrid[0][0] = 'X';
}

void printGrid ( void )
{
	uint32_t y, x;

	for ( y = 0; y < MAX_GRID; y++ )
	{
		for ( x = 0; x < MAX_GRID; x++ )
		{
			printf ( "%c ", gameGrid[y][x] );
		}
		putchar ( '\n' );
	}
}


int main ( void )
{
	initGrid ();
	printGrid ();
	return 0;
}
