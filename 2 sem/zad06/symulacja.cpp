#include <stdio.h>
#include "symulacja.hpp"

double silaSprezyny(const Sprezyna &s)
{
	double deltax = s.m2->x - s.m1->x - s.l;
	
	double sila = (-1)*s.k*deltax;
	
	return sila;
}

double energia (const Sprezyna &s)
{
	double deltax = s.m2->x - s.m1->x - s.l;
	double ep = (s.k * deltax*deltax)/2;
	return ep;
}

double energia (const MasaPunktowa &m)
{
	double ek = (m.m*m.v*m.v)/2;
	
	return ek;
	
}
