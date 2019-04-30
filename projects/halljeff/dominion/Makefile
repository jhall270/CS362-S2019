CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe


unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c dominion.h dominion.c rngs.o
	gcc -o unittest1 dominion.c unittest1.c rngs.o $(CFLAGS)
	echo "unittests1.c" > tests.out
	./unittest1 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest2 dominion.c unittest2.c rngs.o $(CFLAGS)
	echo "unittests2.c" >> tests.out
	./unittest2 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest3 dominion.c unittest3.c rngs.o $(CFLAGS)
	echo "unittests3.c" >> tests.out
	./unittest3 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest4 dominion.c unittest4.c rngs.o $(CFLAGS)
	echo "unittests4.c" >> tests.out
	./unittest4 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest1 dominion.c cardtest1.c rngs.o $(CFLAGS)
	echo "cardtest1.c" >> tests.out
	./cardtest1 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest2 dominion.c cardtest2.c rngs.o $(CFLAGS)
	echo "cardtest2.c" >> tests.out
	./cardtest2 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest3 dominion.c cardtest3.c rngs.o $(CFLAGS)
	echo "cardtest3.c" >> tests.out
	./cardtest3 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest4 dominion.c cardtest4.c rngs.o $(CFLAGS)
	echo "cardtest4.c" >> tests.out
	./cardtest4 >> tests.out
	gcov dominion.c >> tests.out

	echo "Total Test Coverage information (All 8 test files together)" >> tests.out

	gcc -o unittest1 dominion.c unittest1.c rngs.o $(CFLAGS)
	gcc -o unittest2 dominion.c unittest2.c rngs.o $(CFLAGS)
	gcc -o unittest3 dominion.c unittest3.c rngs.o $(CFLAGS)
	gcc -o unittest4 dominion.c unittest4.c rngs.o $(CFLAGS)
	gcc -o cardtest1 dominion.c cardtest1.c rngs.o $(CFLAGS)
	gcc -o cardtest2 dominion.c cardtest2.c rngs.o $(CFLAGS)
	gcc -o cardtest3 dominion.c cardtest3.c rngs.o $(CFLAGS)
	gcc -o cardtest4 dominion.c cardtest4.c rngs.o $(CFLAGS)

	./unittest1 >> /dev/null
	./unittest2 >> /dev/null
	./unittest3 >> /dev/null
	./unittest4 >> /dev/null
	./cardtest1 >> /dev/null
	./cardtest2 >> /dev/null
	./cardtest3 >> /dev/null
	./cardtest4 >> /dev/null

	gcov dominion.c >> tests.out

