/* -----------------------------------------------------------------------
 * Cardtest4 - Sea Hag
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
	int opponentTopOfDeck;
	int playerTopOfDeck;
	int SeaHagEffect(struct gameState *state)
	{
		int i;
		int currentPlayer = whoseTurn(state);
		int nextPlayer = currentPlayer + 1;

		if (nextPlayer > (state->numPlayers - 1)) {
			nextPlayer = 0;
		}
		for (i = 0; i < state->numPlayers; i++) {
			if (i == currentPlayer) {
				state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
				state->discardCount[i]++;
				state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
			}
		}
		return 0;
	}
	opponentTopOfDeck = 0;
	playerTopOfDeck = 1;

    printf ("cardtest4 - TESTING Sea Hag:\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //G.handCount[p] = handCount;                 // set the number of cards on hand
	G.hand[p][0] = sea_hag;

	//playCard(0, 0, 0, 0, &G);
	
#if (NOISY_TEST == 1)
	printf("Oppenents top card should be a curse. Test starts in initial game state so player's top of deck should not.\n");
	printf("Oponents top of deck is curse = %d, expected = 1\n", opponentTopOfDeck);
	printf("Players top of deck is not curse = %d, expected = 0\n", playerTopOfDeck);
#endif
	
    printf("All tests passed!\n");
	
    return 0;
}
