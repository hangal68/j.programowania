CXX=g++
CXXFLAGS=-O2 -Wall -pedantic -std=c++14
LIBS=

program05:	main.o	symulacja.o
		$(CXX) -o program05 main.o symulacja.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp symulacja.hpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
symulacja.o:	symulacja.cpp symulacja.hpp
		$(CXX) -o symulacja.o -c symulacja.cpp $(CXXFLAGS)
clean:
		rm *.o