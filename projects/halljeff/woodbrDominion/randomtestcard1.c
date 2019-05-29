//random tester for adventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}

int randInt(int l, int r){
    return (rand() % (r-l+1))  + l;
}


void randTestAdventurer(){
    struct gameState s, o;
    int i, j, numCards, player, returnval, n;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    
    n=randInt(2,4);

    //initialize the game state, number of players random [2,4]
    initializeGame(n, k, 324564, &s);
    s.numPlayers=n;

    //each player, build deck and hand
    for(i=0; i<s.numPlayers; i++){
        //hand generation
        numCards = randInt(2,8);
        s.handCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.hand[i][j]=randInt(curse, treasure_map);
        }

        //deck generation
        numCards = randInt(5,25);
        s.deckCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.deck[i][j]=randInt(curse, treasure_map);
        }

        s.discardCount[i]=0;
        s.playedCardCount=0;
    }

    
    s.whoseTurn=0;
    if(s.handCount[0]==0){
        s.handCount[0]++;
    }
    s.hand[0][0]=adventurer;


    //make test oracle, copy s to o
    memcpy(&o,&s,sizeof(s));
    
    //add adventurer changes to test oracle
    player = o.whoseTurn;
    int treasuresFound=0;
    
    while(o.deckCount[player]>0 && treasuresFound < 2){
        if(o.deck[player][o.deckCount[player]] == gold || o.deck[player][o.deckCount[player]] == silver || o.deck[player][o.deckCount[player]] == copper){
            o.handCount[player]++;
            treasuresFound++;
        }
        else{
            o.discardCount[player]++;
        }
        o.deckCount[player]--;
    }


    //play adventurer card with struct s
    returnval = cardEffect(adventurer, 0, 0, 0, &s, 0, 0);

    assertTrue(returnval, 0);

    //compare player cards
    for(i=0; i<s.numPlayers; i++){
        assertTrue(o.handCount[i],s.handCount[i]);  
        assertTrue(o.deckCount[i],s.deckCount[i]);      
    }    

}


int main(){
    int count;
    srand (time (NULL));
    for(count=0; count < 1000; count++){
        printf("Test run %d\n", count);
        randTestAdventurer();
    }
    return 0;
}