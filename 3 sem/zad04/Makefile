CXX=g++
CXXFLAGS=-O2 -Wall -pedantic -std=c++14
LIBS=

parabola:	main.o	point.o	parabola.o prosta.o
		$(CXX) -o parabola main.o point.o	parabola.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp point.hpp	parabola.hpp prosta.hpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
point.o:	point.cpp point.hpp
		$(CXX) -o point.o -c point.cpp $(CXXFLAGS)
parabola.o:	parabola.cpp parabola.hpp
		$(CXX) -o parabola.o -c parabola.cpp $(CXXFLAGS)
prosta.o:	prosta.cpp prosta.hpp
		$(CXX) -o prosta.o -c prosta.cpp $(CXXFLAGS)
clean:
		rm *.o

