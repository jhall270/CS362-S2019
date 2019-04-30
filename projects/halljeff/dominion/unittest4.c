#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

//testing getWinners() function


void assertTrue(int* expected, int* actual){
    int i;
    for(i=0; i<4; i++){
        if(expected[i] != actual[i]){
            printf("FAIL index %d --",i);
            printf("Expected:%d Actual:%d\n",expected[i], actual[i]);
            //return;
        }
        else{
            printf("PASS index %d --",i);
            printf("Expected:%d Actual:%d\n",expected[i], actual[i]);
        }
    }

    //printf("PASS \n");

}



void testGetWinners(){
    struct gameState s;

    int players[4]={-1,-1,-1,-1}; //intitialize to bad values, so can check get rewritten
    int expected[4]={1,0,0,0};

    s.numPlayers=2;
    s.deckCount[0]=1;
    s.deckCount[1]=1;
    s.whoseTurn=1; //all players completed current round

    s.deck[0][0]=duchy;
    s.deck[1][0]=estate;

    //test 1, player zero should win
    getWinners(players,&s);
    assertTrue(expected,players);


    //test2, player 0,1 tie
    s.deck[0][0]=duchy;
    s.deck[1][0]=duchy;    
    expected[0]=1;
    expected[1]=1;
    getWinners(players,&s);
    assertTrue(expected,players);

    //test3, 4 way tie
    s.numPlayers=4;
    s.whoseTurn=3; //all players completed current round
    s.deckCount[2]=1;
    s.deckCount[3]=1;    
    s.deck[2][0]=duchy;
    s.deck[3][0]=duchy;
    expected[2]=1;
    expected[3]=1;
    getWinners(players,&s);
    assertTrue(expected,players);
}


int main(){
    testGetWinners();
    return 0;
}