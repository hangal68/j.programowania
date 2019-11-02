#ifndef _point_hpp
#define _point_hpp

#include <iostream>

using namespace std;

class Point {
	
	float x,y;
	static int counter;
public:
	friend class Parabola;
	friend class Prosta;
	Point(float ax = 0, float ay = 0);
	~Point(){ counter --; }
	void info();
	void policz_y(float A, float B, float C, float xD);
	static void ile_pkt();
};


#endif

