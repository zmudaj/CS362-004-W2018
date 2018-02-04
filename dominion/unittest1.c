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

    printf ("unittest1 - TESTING shuffle():\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.handCount[p] = handCount;                 // set the number of cards on hand
	//Copy deck one into a new deck
	printf("Creating copy of the first deck...\n");
	for (i = 0; i < G.deckCount[0]; i++)
	{
		G.deck[2][i] = G.deck[0][i];
	}
	// Shuffle the first deck
	printf("Shuffling first deck\n");
	shuffle(0, &G);
	//printf("deck count: %d", G.deckCount[0]);
	// check that the decks are different
	printf("Comparing decks to see how many cards where in the same place\n");
	int sameCardCount;
	for (i = 0; i < G.deckCount[0]; i++)
	{
		//printf("Deck 1 has %d, deck 2 has %d\n", G.deck[0][i], G.deck[2][i]);
		if (G.deck[2][i] == G.deck[0][i])
		{
			sameCardCount++;
		}
	}
#if (NOISY_TEST == 1)
    printf("The decks had %d cards in the same place\n", sameCardCount);
#endif
                /*assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
				*/
            //}

    printf("All tests passed!\n");
	
    return 0;
}
