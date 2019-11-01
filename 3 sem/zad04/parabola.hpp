#ifndef _parabola_hpp_
#define _parabola_hpp_
#include "point.hpp"

class Parabola{
	
	float A, B, C;
	static int counter;
	friend class Point;
public:
	void policz_parametry();
	Parabola(Point p1, Point p2, Point p3);
	~Parabola(){ counter --;}
	void info();
	static void ile_parabol();
};

#endif
