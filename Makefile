CC = gcc

all: threadbin

threadbin: main.c
	gcc -pthread -o threadbin main.c -W -Wall -pedantic

.PHONY: clean run

run:
	./threadbin

clean:
	rm -rf threadbin