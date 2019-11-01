#include "wektor.hpp"
#include <cmath>

Wektor::Wektor(Punkt &p1, Punkt &p2)
{
	
	mA = p2.mX - p1.mX;
	mB = p2.mY - p1.mY;
	mC = p2.mZ - p1.mZ;
	
}


void Wektor::przedstaw()
{
	
	cout<< "[ " << mA << " ; " <<  mB << " ; " <<  mC << " ]" << endl;
	
}

float Wektor::dl()
{
	
	float dl = sqrt( mA*mA + mB*mB + mC*mC );
	return dl;
	
}

