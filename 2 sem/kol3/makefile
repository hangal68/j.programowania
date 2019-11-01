CC = g++
FLAGS = -Wall -pedantic -O2 -std=c++14
LIBS = `allegro-config --libs`
kol3:	main.o arg.o
	$(CC) -o kol3 main.o arg.o $(FLAGS) $(LIBS)
main.o:	main.cpp arg.hpp
	$(CC) -o main.o -c main.cpp $(FLAGS)
arg.o:	arg.cpp arg.hpp
	$(CC) -o arg.o -c arg.cpp $(FLAGS)

clean:	rm *.o
