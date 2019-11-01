CXX=g++
CXXFLAGS=-O2 -Wall -pedantic -std=c++14
LIBS=

kol2:	main.o	mnk.o
		$(CXX) -o kol2 main.o mnk.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp mnk.hpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
mnk.o:	mnk.cpp mnk.hpp
		$(CXX) -o mnk.o -c mnk.cpp $(CXXFLAGS)
clean:
		rm *.o
