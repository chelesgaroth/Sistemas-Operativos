CC = gcc

CFlags = -O2 -Wall

output: main0.o guiao0.o
	gcc -o output main0.o guiao0.o

main0.o: main0.c 
	gcc -c -o main0.o main0.c

guiao0.o: guiao0.c guiao0.h
	gcc -c -o guiao0.o guiao0.c

clean:
	rm output *.o

