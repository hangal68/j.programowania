#ifndef _symulacja_hpp_
#define _symulacja_hpp_

struct MasaPunktowa
{
	double m;
	double x;
	double v;
	
};

struct Sprezyna
{
	double k;
	double l;
	
	 MasaPunktowa *m1; //punkt z lewej
	 MasaPunktowa *m2; //punkt z prawej
	
};

// Deklaracje funkcji
double silaSprezyny (const Sprezyna &s);
double energia (const Sprezyna &s);
double energia (const MasaPunktowa &m);

#endif
