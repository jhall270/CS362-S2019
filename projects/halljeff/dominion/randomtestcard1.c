//random tester for adventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
    int i, j, numCards, player;



    s.numPlayers=randInt(2,4);
    s.whoseTurn=randInt(1,s.numPlayers);

    //each player, build deck and hand
    for(i=0; i<s.numPlayers; i++){
        //hand
        numCards = randInt(1,8);
        s.handCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.hand[i][j]=randInt(curse, treasure_map);
        }

        //deck
        numCards = randInt(1,12);
        s.deckCount[i]=numCards;
        for(j=0; j<numCards; j++){
            s.deck[i][j]=randInt(curse, treasure_map);
        }
    }
    
    //make sure players whose turn it is has adventurer
    s.discardCount[s.whoseTurn]=0;
    s.playedCardCount=0;
    s.handCount[s.whoseTurn]++;
    s.hand[s.whoseTurn][s.handCount[s.whoseTurn]-1]=adventurer;


    //make test oracle, copy s to o
    memcpy(&o,&s,sizeof(s));
    
    //add adventurer changes to test oracle
    player = o.whoseTurn;
    i=o.deckCount[player]-1;
    int treasuresFound=0;
    while(i>0 && treasuresFound < 2){
        if(o.deck[player][i] == gold || o.deck[player][i] == silver || o.deck[player][i] == copper){
            o.hand[player][o.handCount[player]] = o.deck[player][i];
            o.handCount[player]++;
        }
        else{
            o.discard[player][o.discardCount[player]] = o.deck[player][i];
            o.discardCount[player]++;
        }
        o.handCount[player]--;
    }

    //state structs s and o should be identical
    assertTrue(memcmp(&s,&o, sizeof(s)), 0);


}


int main(){
    int count;
    srand (time (NULL));
    for(count=0; count < 1000; count++){
        randTestAdventurer();
    }
    return 0;
}