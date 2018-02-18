#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	printf("Running random tests for Smithy\n");
	int testsToRun = 1000;
	int counter;
	int testsPassed = 0;
	int testsFailed = 0;
	for (counter = 0; counter < testsToRun; counter++)
	{ 
		struct gameState G;
		int result, randVal = 0, player = 1, handCount, deckCount;
		int k[10] = {adventurer, great_hall, ambassador, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		// Set up random game components
		
		int numPlayers = rand() % 4;
		int gameSeed = rand() % 5000;
			
		
		//initializes Gamestate
		initializeGame(numPlayers, k, gameSeed, &G);
		
		randVal = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;
		handCount = randVal;
		//printf("DEBUG: getting to part 1\n");
		randVal = rand() % MAX_DECK;
		G.deckCount[player] = randVal;
		deckCount = randVal;
			
		//printf("DEBUG: getting to part 2\n");
		G.discardCount[player] = rand() % MAX_DECK;

		// Determine pre card-played values
		int handCountBefore = G.handCount[player];
		//int discardBefore = 0;
		//int discardAfter = 0;
		int index;
		//printf("DEBUG: getting to part 3\n");
		
		//printf("DEBUG: getting to part 4\n");

		// Play the card
		cardEffect(smithy, 1, 1, 1, &G, 1, 1);

		// Determine post card played values

		int handCountAfter = G.handCount[player];
		//printf("Debug: handCountBefore = %d, handCountAfter = %d\n", handCountBefore, handCountAfter);
		
		if (handCountBefore == handCountAfter)
		{
			testsPassed++;
		}
		else
		{
			testsFailed++;
		}
		//printf("DEBUG: getting to part 5\n");
	}
	printf("Done testing Smithy!\n");
	printf("%d passed and %d failed of 1000 tests\n", testsPassed, testsFailed);
}
