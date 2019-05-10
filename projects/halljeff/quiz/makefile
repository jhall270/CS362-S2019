default: testme.c
	gcc -o testme testme.c -Wall -fpic -coverage -lm -std=c99
	./testme
	gcov testme
	gcov -b testme

clean: 
	rm testme *.gcda *.gcno *.gcov