CC=gcc
CFLAGS=-Wall -Werror -I. -Wno-pragma-pack
LDFLAGS=-L.
BINARY=main


main: main.o collections.o 
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^

collections.o: collections.c collections.h
	$(CC) -c -o $@ $(CFLAGS) $<