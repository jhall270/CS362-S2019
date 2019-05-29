#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

//testing sea hag card


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}


void testSeaHag(){
    struct gameState s;
    int returnval;
    
    s.numPlayers=2;   
    s.numActions=0;

    //player 1 has sea_hag in hand
    s.handCount[1]=1;
    s.hand[1][0]=sea_hag;

    //player 0 has two cards in deck, 0 in discard
    s.handCount[0]=0;
    s.deckCount[0]=2;   
    s.deck[0][0]=copper;
    s.deck[0][1]=estate;
    s.discardCount[0]=0;

    s.discardCount[0]=0;
    s.playedCardCount=0;

    //player 1 plays sea_hag, should add curse to player 0
    s.whoseTurn=1;

    returnval = cardEffect(sea_hag, 0, 0, 0, &s, 0, 0);
    assertTrue(0,returnval);    //valid call return 0

    //player 0 top of deck is discarded
    assertTrue(1,s.discardCount[0]);
    assertTrue(estate, s.discard[0][0]);

    //player 0 top of deck replaced with curse
    assertTrue(2, s.deckCount[0]);
    assertTrue(curse, s.deck[0][1]); 


}


int main(){
    testSeaHag();
    return 0;
}