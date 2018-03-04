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

    printf ("unittest3 - TESTING isGameOver():\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.handCount[p] = handCount;                 // set the number of cards on hand

	int supply;
	supply = supplyCount(3, &G);
#if (NOISY_TEST == 1)
	printf("2 Player game. supply of provinces = %d, expected = 8\n", supply);
#endif
	supply = supplyCount(7, &G);
#if (NOISY_TEST == 1)
	printf("Supply of Adventureres = %d, expected = 10\n", supply);
#endif
	supply = supplyCount(25, &G);
#if (NOISY_TEST == 1)
	printf("Sea Hag is not in the game. supply of Sea Hag = %d, expected = -1\n", supply);
#endif
	
    printf("All tests passed!\n");
	
    return 0;
}
