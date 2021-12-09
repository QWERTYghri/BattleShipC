
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>


/* const vals */
#define BOARD_SZ 5
#define RNG_SD 4
#define BUF_SIZ 50

#define MAX_IN 4
#define MIN_IN 1

/* global vars */

unsigned char layOut[BOARD_SZ][BOARD_SZ] =
{
	{'X','1','2','3','4'},
	{'1','o','o','o','o'},
	{'2','o','o','o','o'},
	{'3','o','o','o','o'},
	{'4','o','o','o','o'}
};

/* functions */

/* print contents of layOut 2D Array */
void drawBoard(void) {
	int32_t i1,
		i2;

	for(i1 = 0; i1 < BOARD_SZ; i1++) {
		for(i2 = 0; i2 < BOARD_SZ; i2++) {
			printf("%c ", layOut[i1][i2]);
		}
		printf("\n");
	}
}

/* generate random and check if it's 0 to increment because lazy */
int32_t GenRnd(void) {
	int32_t rnd;

	srand(time(NULL));
	rnd = rand() % RNG_SD;

	return (rnd == 0) ? rnd:rnd++;
}

/* get and input and cast to an integer to prevent from malformed input */ 
int32_t GetInput(void) {
	char input[BUF_SIZ];
	int32_t val = 0;

	fgets(input,BUF_SIZ,stdin);

	val = atoi((char*)input); 

	return val;
}	

/* input a character into the board */
void inputBoard(int32_t x, int32_t y) {
	layOut[x][y] = 'x';
}

/* clear the values in 2D array out of the 0 range back to 'o' */
void clearBoard(void) {
	int32_t i1,
		i2;

	for(i1 = 1; i1 < BOARD_SZ; i1++) {
		for(i2 = 1; i2 < BOARD_SZ; i2++) {
			layOut[i1][i2] = 'o';
		}
	}
}

/* Validates the parameters if they're within the MAX/MIN bounds */
int32_t ValRndV(int32_t x, int32_t y) {
	if( x <= MIN_IN || x >= MAX_IN || y <= MIN_IN || x >= MAX_IN ) {
		perror("Improper input :c rip");
		return -1;
	}

	return 0;
}

/* main */

int main(void) {


	/* variable data for game 
	 * rndX : random x val board
	 * rndY : random y val board
	 * roundCnt: a variabe to hold rounds
	 * inpX : input for x
	 * inpY	: input for Y
	 */

	int32_t rndX = 0,
		rndY = 0,
		rndCnt = 0,
		inpX = 0,
		inpY = 0,
		pnt = 0;


	while(1) {
		printf("|| BattleShip C game ||\n\n");

		rndX = GenRnd();
		rndY = GenRnd();
		rndCnt = ROUND_AMNT;
		
		while(rndCnt != 0) {
			drawBoard();

			while(1) {

				printf("\n\nX : ");
				inpX = GetInput();

				printf("\n\nY : ");
				inpY = GetInput();
			
				if(ValRndV(rndX, rndY) != 0) {
					break;
				}

				break;
			}
			inputBoard(inpY, inpX);

			if(inpX == rndX && inpY == rndY) {
				printf("\nPoints : %d\n", ++pnt);
			} else {
				printf("\nLossed! Rounds left: %d\n",--rndCnt);
			}
		}

		rndCnt = ROUND_AMNT;
		clearBoard();
	}

	return 0;
}
