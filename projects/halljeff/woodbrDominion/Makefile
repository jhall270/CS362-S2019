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


unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c dominion.h dominion.o rngs.o
	gcc -o unittest1 dominion.o unittest1.c rngs.o $(CFLAGS)
	echo "unittests1.c" > tests.out
	./unittest1 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest2 dominion.o unittest2.c rngs.o $(CFLAGS)
	echo "unittests2.c" >> tests.out
	./unittest2 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest3 dominion.o unittest3.c rngs.o $(CFLAGS)
	echo "unittests3.c" >> tests.out
	./unittest3 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o unittest4 dominion.o unittest4.c rngs.o $(CFLAGS)
	echo "unittests4.c" >> tests.out
	./unittest4 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest1 dominion.o cardtest1.c rngs.o $(CFLAGS)
	echo "cardtest1.c" >> tests.out
	./cardtest1 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest2 dominion.o cardtest2.c rngs.o $(CFLAGS)
	echo "cardtest2.c" >> tests.out
	./cardtest2 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest3 dominion.o cardtest3.c rngs.o $(CFLAGS)
	echo "cardtest3.c" >> tests.out
	./cardtest3 >> tests.out
	gcov dominion.c >> tests.out

	gcc -o cardtest4 dominion.o cardtest4.c rngs.o $(CFLAGS)
	echo "cardtest4.c" >> tests.out
	./cardtest4 >> tests.out
	gcov dominion.c >> tests.out

	cp dominion.c.gcov dominion.c_STATEMENT.gcov

	echo "Additional Coverage information" >> tests.out
	gcov -b -c dominion.c >> tests.out

	echo "Coverage data saved as dominion.c_STATEMENT.gcov dominion.c_BRANCH.gcov" >> tests.out
	cp dominion.c.gcov dominion.c_BRANCH.gcov


randomtestresults: dominion.h dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard1.c" > randomtestresults.out
	./randomtestcard1 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard2.c" > randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

	gcc -o randomtestcard3 randomtestcard3.c dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard3.c" > randomtestresults.out
	./randomtestcard3 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

	cp dominion.c.gcov dominion.c_STATEMENT.gcov

	echo "Additional Coverage information" >> randomtestresults.out
	gcov -b -c dominion.c >> randomtestresults.out
	echo "Coverage data saved as dominion.c_STATEMENT.gcov dominion.c_BRANCH.gcov" >> randomtestresults.out
	cp dominion.c.gcov dominion.c_BRANCH.gcov
