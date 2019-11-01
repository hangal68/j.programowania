parabola.cpp

#include "parabola.hpp"
#include <iostream>
#include <math.h>

using namespace std


void Parabola::policz_parametry()
{
	
	A = 1;
	B = 1;
	C = 2;

}
Parabola::Parabola(Point &p1, Point &p2, Point &p3)
{
	policz_parametry();
	counter++;
}

void Parabola::info()
{
	cout << "Parabola: " << A << "x^2 + " << B << "x + " << C << endl;
}


