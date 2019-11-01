CC = g++
CFLAGS = -Wall -pedantic -O2 -std=c++14
program02: main.o lib.o
		$(CC) -o program02 main.o lib.o $(CFLAGS)
main.o:	main.cpp lib.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
lib.o:	lib.cpp lib.hpp
		$(CC) -o lib.o -c lib.cpp $(CFLAGS)
clean:
		rm *.o
