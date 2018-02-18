CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestresults.out

randomtestresults.out: randomtestadventurer.c randomtestcard1.c randomtestcard2.c playdom.c rngs.c
	
	echo "randomtestadventurer.c:" >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	randomtestadventurer >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out
	
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	randomtestcard1 >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out
	
	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	randomtestcard2 >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out


clean:
	rm randomtestresults.out

cleanall: 
	rm randomtestresults.out randomtestadventurer randomtestcard1 randomtestcard2 *.gcda *.gcno *.gcov
