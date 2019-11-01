#include "point.hpp"

Point::Point(float ax, float ay)
{
	x = ax;
	y = ay;
	
	counter ++;	
}

void Point::ile_pkt()
{
	cout<< "Jest " << counter << " punktow!" << endl;
}

void Point::info()
{
	cout << "Punkt (" << x << ";" << y << ")" <<endl;
}

void Point::policz_y(float A, float B, float C, float xD)
{
	float yD = A * xD * xD + B * xD + C;
	y = yD;
}


