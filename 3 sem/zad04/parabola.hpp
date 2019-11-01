#ifndef _parabola_hpp_
#define _parabola_hpp_
#include "point.h"

class Parabola{
	
	float A, B, C;
	static int counter;
public:
	void policz_parametry();
	Parabola(Point p1, Point p2, Point p3);
	~Parabola(){ counter --;}
	void info();
	static void ile_parabol();
	friend class Point;
};

#endif
