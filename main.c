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

#define MAX_GRID	( ( int32_t ) 8 ) /* note label will denote 1 - ( MAX_GRID - 1 ) */
#define SHOW_NUM	( ( int32_t ) 0 )
#define MAX_TRIES	( ( int32_t ) 4 )
#define MAX_STR_IN	( ( int32_t ) 50 )
#define BASE_10		( ( int32_t ) 10 )
#define LOW_RAND	( ( int32_t ) 1 )


char* gameGrid[MAX_GRID][MAX_GRID];
const char* intro = "A battleship C game v2";

/* Func prototypes */
int32_t getStrNum ( void )	/* Func to get an int from stdin */
{
	char tmpBuf[MAX_STR_IN];
	int32_t tempVal;

	printf ( "\nEnter a value: \n" );
	if ( !fgets ( tmpBuf, MAX_STR_IN, stdin ) )
		return -1;

	/* recursion if input is not valid, you could probably do a stack overflow here but welp */
	if ( ( tempVal = ( int32_t ) strtol ( tmpBuf, NULL, BASE_10 ) ) <= 0 || tempVal > MAX_GRID )
	{
		printf ( "Input is either too large or too small or invalid: Try again\n\n" );
		getStrNum ();
	}

	return tempVal;
}

/* sHITTY FUCKING CODE go kys */
char* retIntStrConv ( uint32_t val )
{
	char* str = ( char* ) malloc ( sizeof ( MAX_STR_IN ) ); /* Someone could make some gdb breakpoint
								   and do some funny stuff by altering
								   the return perhaps.*/	
	sprintf ( str, "%d", val );

	return str;
}
	
void initGrid ( void )		/* initialize the gameGrid */
{
	uint32_t y, x;

	for ( y = 0; y < MAX_GRID; y++ )
	{
		for ( x = 0; x < MAX_GRID; x++ )
		{
			/* kys wtf is this code */
			if ( y == 0 )
			{
				gameGrid[y][x] = retIntStrConv ( x );
			}
			else if ( x == 0 )
			{
				gameGrid[y][x] = retIntStrConv ( y );
			}
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

int32_t retRandRng ( void ) /* returns rand num from 1 - MAX_GRID */
{
	return LOW_RAND + rand() / (RAND_MAX / (MAX_GRID - LOW_RAND + 1) + 1);	
}

void clsGrid ( void )		/* Clear the board */
{
	uint32_t y, x;

	for ( y = 1; y < MAX_GRID; y++ )
	{
		for ( x = 1; x < MAX_GRID; x++ )
			gameGrid[y][x] = "O";
	}
}

int main ( void )
{
	int32_t rand1, rand2;
	int32_t tries = MAX_TRIES;
	int32_t inp1, inp2;
	int32_t score = 0;
	
	srand ( time ( NULL ) );
	printf ( "%s\n\n", intro );
	
	while ( 1 ) /* game loop */
	{
		initGrid ();
		clsGrid ();

		rand1 = retRandRng ();
		rand2 = retRandRng ();
		
		if ( SHOW_NUM )
			printf ( "\n%d %d\n", rand1, rand2 );
		
		while ( tries > 0 )
		{
			printGrid ();

			inp1 = getStrNum ();
			inp2 = getStrNum ();

			gameGrid[inp2][inp1] = "X";

			if ( inp1 == rand1 && inp2 == rand2 )
			{
				score++;
				printf ( "\n\nYou won\n" );

				break;
			}
			else
				printf ( "\n\nYou Lost\n" );

			tries--;

			if ( !tries )
				printf ( "\n\nFailed -5\n" );
		}

		printf ( "GAME ENDED\n\nScore : %d\n\n", score );

		tries = MAX_TRIES;

		fputs ( "\n\n\n\n\n\n\n\n\n\n", stdout );
	}

	return 0;
}
