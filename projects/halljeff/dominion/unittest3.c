#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

//testing scoreFor()


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:%d Actual:%d\n",expected, actual);
}



void testScoreFor(){
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

    //player 0, score 0
    assertTrue(0, scoreFor(0,&s));    

    s.deckCount[0]=1;
    s.handCount[0]=1;
    s.discardCount[0]=1;
    s.deck[0][0]=curse;
    s.hand[0][0]=curse;
    s.discard[0][0]=curse;
    //player 0, 3 curse, score -3
    assertTrue(-3, scoreFor(0,&s));  

    //player 1, 3 action cards, score 0
    assertTrue(0, scoreFor(1,&s));


    //player 1, 3 of each point cards 
    int pointCards[5]={estate, duchy, province, great_hall, gardens};

    s.deckCount[1]=5;
    s.handCount[1]=5;
    s.discardCount[1]=5;

    for(i=0; i<5; i++){
        s.deck[1][i]=pointCards[i];
        s.hand[1][i]=pointCards[i];
        s.discard[1][i]=pointCards[i];
    }

    //player 1, 3 of each point card, should be 36
    assertTrue(36,scoreFor(1,&s));




}


int main(){
    testScoreFor();
    return 0;
}