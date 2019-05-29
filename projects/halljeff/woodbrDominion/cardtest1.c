#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

//testing smithy card


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}


void testSmithy(){
    struct gameState s;
    int returnval;
    
    s.numPlayers=2;
    s.handCount[0]=1;
    s.deckCount[0]=3;
    s.hand[0][0]=smithy;
    s.deck[0][0]=copper;
    s.deck[0][1]=copper;
    s.deck[0][2]=copper;
    s.discardCount[0]=0;
    s.playedCardCount=0;


    s.whoseTurn=0;
    returnval = cardEffect(smithy, 0, 0, 0, &s, 0, 0);
    assertTrue(0,returnval);    //valid call return 0
    assertTrue(3,s.handCount[0]); //add 3 cards, handcout 4
    //smithy should be moved to played cards
    assertTrue(smithy, s.playedCards[s.playedCardCount-1]);

}


int main(){
    testSmithy();
    return 0;
}