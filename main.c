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
#include <time.h>


/* Definitions */
#define MAX_GRID	( ( uint32_t ) 8 )
#define SHOW_NUM	( ( uint32_t ) 0 )
#define MAX_TRIES	( ( uint32_t ) 4 )
#define MAX_STR_IN	( ( uint32_t ) 50 )
#define BASE_10		( ( uint32_t ) 10 )
#define LOW_RAND	( ( uint32_t ) 1 )


char* gameGrid[MAX_GRID][MAX_GRID];
const char* intro = "A battleship C game v2";

/* Func prototypes */
int32_t getStrNum ( void )	/* Func to get an int from stdin */
{
	char tmpBuf[MAX_STR_IN];

	if ( !fgets ( tmpBuf, MAX_STR_IN, stdin ) )
		return -1;

	return ( ( int32_t ) strtol ( tmpBuf, NULL, BASE_10 ) );
}

void initGrid ( void )		/* initialize the gameGrid */
{
	uint32_t y, x;

	for ( y = 0; y < MAX_GRID; y++ )
	{
		for ( x = 0; x < MAX_GRID; x++ )
		{
			
		}
	}
	gameGrid[0][0] = "X";
}

void printGrid ( void )		/* Printing the grid to terminal */
{
	uint32_t y, x;

	for ( y = 0; y < MAX_GRID; y++ )
	{
		for ( x = 0; x < MAX_GRID; x++ )
		{
			printf ( "%s ", gameGrid[y][x] );
		}
		putchar ( '\n' );
	}
}

void retRandRng ( void ) /* returns rand num from 1 - MAX_GRID */
{
	return rand () % ( LOW_RAND, MAX_GRID + 1 ) + LOW_RAND;
}

void clsBoard ( void )		/* Clear the board */
{
	uint32_t y, x;

	for ( y = 1; y < MAX_GRID; y++ )
	{
		for ( x = 1; x < MAX_GRID; x++ )
			gameGrid[y][x] = "X";
	}
}

int main ( void )
{
	srand ( time ( NULL ) );

	int32_t rand1, rand2;
	int32_t tries = MAX_TRIES;


	printf ( "%s\n\n", intro );
	
	while ( 1 ) /* game loop */
	{
		rand1 = retRandRng ();
		rand2 = retRandRng ();
		
		while ( tries > 0 )
		{
					
		}
	}


	return 0;
}
