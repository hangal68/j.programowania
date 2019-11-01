#include "punkt.hpp"

Punkt::Punkt(float X, float Y, float Z)
{

	mX = X;
	mY = Y;
	mZ = Z;
	
}

void Punkt::przedstaw()
{
	
	cout<< "( " << mX << " ; " <<  mY << " ; " <<  mZ << " ) " << endl;
	
}
