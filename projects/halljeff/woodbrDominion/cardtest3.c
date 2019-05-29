#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

//testing village card


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}


void testVillage(){
    struct gameState s;
    int returnval;
    
    s.numPlayers=2;
    s.whoseTurn=0;
    s.numActions=0;

    s.handCount[0]=1;
    s.hand[0][0]=village;

    s.deckCount[0]=2;   
    s.deck[0][0]=copper;
    s.deck[0][1]=estate;

    s.discardCount[0]=0;
    s.playedCardCount=0;


    returnval = cardEffect(village, 0, 0, 0, &s, 0, 0);
    assertTrue(0,returnval);    //valid call return 0

    //2 actions after call
    assertTrue(2,s.numActions);
    //deck has 1 less card
    
    //hand has 1 more card - 1 card played = 1 card count, 
    assertTrue(1,s.handCount[0]);
    assertTrue(estate, s.hand[0][0]); //card at top of deck should be in hand
    assertTrue(1,s.deckCount[0]); //deck should have 1 card left

    //discard should have played village card
    assertTrue(1, s.discardCount[0]);
    assertTrue(village, s.discard[0][0]);

}


int main(){
    testVillage();
    return 0;
}