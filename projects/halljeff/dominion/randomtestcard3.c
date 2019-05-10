//random tester for salvager

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


void randTestSalvager(){
    struct gameState s, o;
    int i, j, numCards, player, returnval, n, isTrash, trashedCard;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    
    //random number of players
    n=randInt(2,4);

    //random initialization of game
    initializeGame(n, k, 324564, &s);
    s.numPlayers=n;

    //reset each player cards, build deck and hand
    for(i=0; i<s.numPlayers; i++){
        //hand
        numCards = randInt(2,8);
        s.handCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.hand[i][j]=randInt(curse, treasure_map);
        }

        //deck
        numCards = randInt(5,25);
        s.deckCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.deck[i][j]=randInt(curse, treasure_map);
        }

        s.discardCount[i]=0;
        s.playedCardCount=0;
    }

    //make sure has card in hand to play
    s.whoseTurn=0;
    if(s.handCount[0]==0){
        s.handCount[0]++;
    }
    s.hand[0][0]=salvager;

    //salvager card has option to trash a card
    isTrash = randInt(0,1);

    if(isTrash){
        trashedCard = randInt(0, s.handCount[0]-1);
    }


    //make test oracle, copy s to o
    memcpy(&o,&s,sizeof(s));
    

    //TEST ORACLE 
    //add smithy changes to test oracle
    //move 3 cards from deck to hand
    player = o.whoseTurn;

    //optional trash card
    if(isTrash){
        o.coins = o.coins + getCost(handCard(trashedCard, &o));
        o.handCount[player]--;
    }

    //add 1 buy
    o.numBuys++;

    //discard salvager from hand
    o.handCount[player]--;
    o.discardCount[player]++;


    //play salvager card with struct s
    if(isTrash){
        returnval = cardEffect(salvager, trashedCard, 0, 0, &s, 0, 0);
    }
    else{
        returnval = cardEffect(salvager, 0, 0, 0, &s, 0, 0);
    }


    assertTrue(returnval, 0);

    //compare player cards
    for(i=0; i<s.numPlayers; i++){
        assertTrue(o.handCount[i],s.handCount[i]);  
        assertTrue(o.deckCount[i],s.deckCount[i]);
        assertTrue(o.discardCount[i],s.discardCount[i]);       
    }    

}


int main(){
    int count;
    srand (time (NULL));
    for(count=0; count < 1000; count++){
        printf("Test run %d\n", count);
        randTestSalvager();
    }
    return 0;
}