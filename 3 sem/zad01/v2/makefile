CC = g++
CFLAGS = -Wall -pedantic -O2 -std=c++14
program01: main.o fnk.o
		$(CC) -o program01 main.o fnk.o $(CFLAGS)
main.o:	main.cpp fnk.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
fnk.o:	fnk.cpp fnk.hpp
		$(CC) -o fnk.o -c fnk.cpp $(CFLAGS)
clean:
		rm *.o
