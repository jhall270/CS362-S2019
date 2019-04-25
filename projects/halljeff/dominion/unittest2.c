#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"



void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}



//TESTING fullDeckCount()

void testFullDeckCount(){
    struct gameState s;
    int i;

    //player 0, 0 cards
    s.deckCount[0]=0;
    s.handCount[0]=0;
    s.discardCount[0]=0;

    //player 1, three cards
    s.deckCount[1]=1;
    s.handCount[1]=1;
    s.discardCount[1]=1;

    s.deck[1][0]=salvager;
    s.hand[1][0]=mine;
    s.discard[1][0]=adventurer;

    //player 0, any card should have zero count
    assertTrue(0,fullDeckCount(0,salvager,&s));
    assertTrue(0,fullDeckCount(0,copper,&s));

    //player 1, 
    assertTrue(0,fullDeckCount(1,copper,&s));
    assertTrue(1,fullDeckCount(1,salvager,&s));
    assertTrue(1,fullDeckCount(1,mine,&s));
    assertTrue(1,fullDeckCount(1,adventurer,&s));

}


int main(){
    testFullDeckCount();
    return 0;
}