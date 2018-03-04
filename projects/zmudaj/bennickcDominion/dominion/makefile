CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: testresults.out

testresults.out: randomtestadventurer.c randomtestcard1.c randomtestcard2.c playdom.c rngs.c unittest1.c unittest2.c unittest3.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c playdom.c rngs.c
	
	echo "randomtestadventurer.c:" >> testresults.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	randomtestadventurer >> testresults.out
	gcov dominion.c -b >> testresults.out
	
	echo "randomtestcard1.c:" >> testresults.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	randomtestcard1 >> testresults.out
	gcov dominion.c -b >> testresults.out
	
	echo "randomtestcard2.c:" >> testresults.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	randomtestcard2 >> testresults.out
	gcov dominion.c -b >> testresults.out
	
	echo "unittest1.c:" >> testresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	unittest1 >> testresults.out
	gcov unittest1.c -b >> testresults.out
	
	echo "unittest2.c:" >> testresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	unittest2 >> testresults.out
	gcov unittest2.c -b >> testresults.out
	
	echo "unittest3.c:" >> testresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	unittest3 >> testresults.out
	gcov unittest3.c -b >> testresults.out
	
	echo "unittest4.c:" >> testresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
	unittest4 >> testresults.out
	gcov unittest4.c -b >> testresults.out
	
	echo "cardtest1.c:" >> testresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
	cardtest1 >> testresults.out
	gcov cardtest1.c -b >> testresults.out

	echo "cardtest2.c:" >> testresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c $(CFLAGS)
	cardtest2 >> testresults.out
	gcov cardtest2.c -b >> testresults.out

	echo "cardtest3.c:" >> testresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c $(CFLAGS)
	cardtest3 >> testresults.out
	gcov cardtest3.c -b >> testresults.out

	echo "cardtest4.c:" >> testresults.out
	gcc -o cardtest4 cardtest4.c dominion.c rngs.c $(CFLAGS)
	cardtest4 >> testresults.out
	gcov cardtest4.c -b >> testresults.out


clean:
	rm testresults.out

cleanall: 
	rm testresults.out randomtestadventurer randomtestcard1 randomtestcard2 unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov
