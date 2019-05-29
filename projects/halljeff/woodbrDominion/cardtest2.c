#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

//testing adventurer card


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}


void testAdventurer(){
    struct gameState s;
    int returnval;
    
    s.numPlayers=2;
    s.whoseTurn=0;

    s.handCount[0]=1;
    s.hand[0][0]=adventurer;

    s.deckCount[0]=3;   
    s.deck[0][0]=copper;
    s.deck[0][1]=estate;
    s.deck[0][2]=copper;

    s.discardCount[0]=0;
    s.playedCardCount=0;

    //deck has two coins, 1 estate, hand only has adventurer
    //adventurer call should move two coins from deck into hand, discard estate from deck

    returnval = cardEffect(adventurer, 0, 0, 0, &s, 0, 0);
    assertTrue(0,returnval);    //valid call return 0

    //hand should have two coppers after call
    assertTrue(2,s.handCount[0]); 
    assertTrue(copper, s.hand[0][0]);
    assertTrue(copper, s.hand[0][1]);

    //deck should be empty
    assertTrue(0,s.deckCount[0]);

    //discard should have estate
    assertTrue(1, s.discardCount[0]);
    assertTrue(estate, s.discard[0][0]);

}


int main(){
    testAdventurer();
    return 0;
}