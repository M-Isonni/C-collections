CC=gcc
CFLAGS=-Wall -Werror -I. -Wno-pragma-pack
LDFLAGS=-L.
BINARY=main


main: main.o list.o 
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^

list.o: list.c list.h
	$(CC) -c -o $@ $(CFLAGS) $<