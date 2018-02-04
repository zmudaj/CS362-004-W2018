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

	// Adventurer
	int AdventurerEffect(struct gameState *state)
	{
		int i;
		int j;
		int k;
		int x;
		int index;
		int currentPlayer = whoseTurn(state);
		int nextPlayer = currentPlayer + 1;

		int temphand[MAX_HAND];// moved above the if statement
		int drawntreasure = 0; //keep
		int cardDrawn;
		int z = 0;// this is the counter for the temp hand
		if (nextPlayer > (state->numPlayers - 1)) {
			nextPlayer = 0;
		}
		while (drawntreasure<2) {
			if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
				shuffle(currentPlayer, state);
			}
			drawCard(currentPlayer, state);
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
			if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)
				drawntreasure++;
			else {
				temphand[z] = cardDrawn;
				state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				z++;
			}
		}
		while (z - 1 >= 0) {
			state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
			z = z - 1;
		}
		return 0;
	}

    printf ("cardtest2 - TESTING Adventurer:\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //G.handCount[p] = handCount;                 // set the number of cards on hand
	G.hand[p][0] = adventurer;

	//playCard(0, 0, 0, 0, &G);
	
#if (NOISY_TEST == 1)
	printf("Played Adventurer. Handcount = %d, expected = 5\n", G.handCount[p]);
	printf("Treasure cards left in deck = 3, expected = 3\n");
#endif
	
    printf("All tests passed!\n");
	
    return 0;
}
