/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
	int j;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("unittest2 - TESTING fullDeckCount():\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.handCount[p] = handCount;                 // set the number of cards on hand

	int copperCount, curseCount, estateCount;

	copperCount = fullDeckCount(1, 4, &G);
#if (NOISY_TEST == 1)
	printf("copperCount = %d, expected = 7\n", copperCount);
#endif
	assert(copperCount == 7); // check if the number of coins is correct
	
	curseCount = fullDeckCount(1, 0, &G);
#if (NOISY_TEST == 1)
	printf("curseCount = %d, expected = 0\n", curseCount);
#endif
	assert(curseCount == 0); // check if the number of coins is correct

	estateCount = fullDeckCount(1, 1, &G);
#if (NOISY_TEST == 1)
	printf("estateCount = %d, expected = 3\n", estateCount);
#endif
	assert(estateCount == 3); // check if the number of coins is correct
	
    printf("All tests passed!\n");
	
    return 0;
}
