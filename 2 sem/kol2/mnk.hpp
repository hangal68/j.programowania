#ifndef _mnk_hpp_
#define _mnk_hpp_
#include <stdio.h>
#include <stdlib.h>

struct PunktXYF{
	
	float x;
	float y;
	float f;
};

struct DaneXYF{
	
	int rozmiar;
	PunktXYF *tab;
	
};

DaneXYF wczytaj_dane (FILE *we);
void dopasowanie_mnk (DaneXYF dane, double &a, double &b);
void wypisz_dane (FILE *wy, DaneXYF dane);

#endif
