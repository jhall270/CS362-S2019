#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

//testing int updateCoins(int player, struct gameState *state, int bonus)

int updateCoins(int player, struct gameState *state, int bonus);

void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}



void testUpdateCoins(){
    struct gameState s;

    //player 0, 0 cards
    s.deckCount[0]=0;
    s.handCount[0]=0;
    s.discardCount[0]=0;

    //player 1, three non-coin cards
    s.deckCount[1]=1;
    s.handCount[1]=1;
    s.discardCount[1]=1;

    s.deck[1][0]=salvager;
    s.hand[1][0]=mine;
    s.discard[1][0]=adventurer;

    //player 0, no cards, coin 0
    updateCoins(0, &s,0);
    assertTrue(0,s.coins);

    //player 0, no cards, 1 bonus, coin 1
    updateCoins(0, &s,1);
    assertTrue(1,s.coins);

    //player 1, 3 action cards, coin 0
    updateCoins(1, &s,0);
    assertTrue(0,s.coins);


    s.handCount[1]=3;
    s.hand[1][0]=copper;
    s.hand[1][1]=silver;
    s.hand[1][2]=gold;

    //player 1, 1 each of copper, silver, gold, value 6
    updateCoins(1, &s,0);
    assertTrue(6, s.coins);

}


int main(){
    testUpdateCoins();
    return 0;
}