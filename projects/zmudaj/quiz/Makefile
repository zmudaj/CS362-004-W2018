CC=gcc
CFLAGS=-Wall -g -O -I. -MMD
PROGS=testme

all: $(PROGS)
testme: testme.o 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	/bin/rm -f $(PROGS) *.o a.out
