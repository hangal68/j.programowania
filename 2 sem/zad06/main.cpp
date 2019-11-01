#include <stdio.h>
#include "symulacja.hpp"
int main()
{
	MasaPunktowa m1 = {10,0,0.5};
	MasaPunktowa m2 = {2,1,0};
	Sprezyna s = {200,1,&m1,&m2};
	
	double dt = 0.0001;
	
	for(double t = 0; t < 1.0;t += dt)
	{
		double am1 = (-1)*silaSprezyny(s)/m1.m;
		double am2 = silaSprezyny(s)/m2.m;
		
		m1.x += m1.v*dt;
		m2.x += m2.v*dt;
		
		m1.v += am1*dt;
		m2.v += am2*dt;
		double ec = energia(s) + energia(m1)+energia(m2);
		
		printf("%lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",t,m1.x,m2.x,m1.v,m2.v,ec);
	}
	
	return 0;
}
