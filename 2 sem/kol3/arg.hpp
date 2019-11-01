#include <stdio.h>
#include <iostream>
#include <stdbool.h>

struct Parametry{
	
	bool txt;
	bool bin;
	FILE *plik;
	
};

struct obiekt{
	
	float r;
	float kat;
	float rozmiar;
};

struct obiekty{
	
	obiekt *tab;
	int i;
};

Parametry AnalizujArgumenty( int argc, char *arg[]);
obiekty WczytajDaneTXT(FILE *plik);

float polozenieX(const obiekt &o);
float polozenieY(const obiekt &o);

void RysujRadar(const obiekty &o);
