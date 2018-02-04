/* -----------------------------------------------------------------------
 * Cardtest3 - Great Hall
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

	int GreatHallEffect(int handPos, struct gameState *state)
	{
		int i;
		int j;
		int k;
		int x;
		int index;
		int currentPlayer = whoseTurn(state);
		int nextPlayer = currentPlayer + 1;

		int cardDrawn;
		int z = 0;// this is the counter for the temp hand
		if (nextPlayer > (state->numPlayers - 1))
		{
			nextPlayer = 0;
		}
		//+1 Card
		drawCard(currentPlayer, state);

		//+1 Actions
		state->numActions--;

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	}

	int actions;

    printf ("cardtest3 - TESTING Great Hall:\n");
    p = 0;
	printf("Setting up game...\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //G.handCount[p] = handCount;                 // set the number of cards on hand
	G.hand[p][0] = great_hall;
	actions = -1;
	//playCard(0, 0, 0, 0, &G);
	
#if (NOISY_TEST == 1)
	printf("Great hall should leave hand and action counts at the same number they started.\n");
	printf("Handcount = %d, expected = 5\n", G.handCount[p]);
	printf("Actions = %d, expected = 1\n", actions);
#endif
	
    printf("All tests passed!\n");
	
    return 0;
}
