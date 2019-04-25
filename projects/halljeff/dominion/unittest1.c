#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"

//testing isGameOver() function


void assertTrue(int expected, int actual){
    if(expected == actual){
        printf("PASS ");
    }
    else{
        printf("FAIL ");
    }
    printf("Expected:&d Actual:&d\n",expected, actual);
}



void testIsGameOver(){
    struct gameState s;
    int i;

    //all supplies 0, game is over
    for(i=0;i<treasure_map+1; i++){
        s.supplyCount[i]=0;
    }
  
    assertTrue(1,isGameOver(&s));

    //all supplies>0, game not over
    for(i=0;i<treasure_map+1; i++){
        s.supplyCount[i]=1;
    }
    assertTrue(0,isGameOver(&s));

    //province card zero, game over
    s.supplyCount[province]=0;
    assertTrue(1,isGameOver(&s));

    
    for(i=0;i<treasure_map+1; i++){
        s.supplyCount[i]=1;
    }   

    //2 supplies other than province zero, game not over
    s.supplyCount[copper]=0;
    s.supplyCount[silver]=0;
    assertTrue(0,isGameOver(&s));

    //3 supplies other than province zero, game is over
    s.supplyCount[adventurer]=0;
    assertTrue(1,isGameOver(&s));
}


int main(){
    testIsGameOver();
    return 0;
}