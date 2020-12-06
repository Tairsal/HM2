CC = gcc
FLAG = -Wall -g

all: prog

prog: myBank.o main.o 
	$(CC) -o prog main.o myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAG) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAG) -c myBank.c



.PHONY: clean all

 clean:
	rm -f *.o prog