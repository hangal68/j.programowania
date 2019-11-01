#ifndef _kebab_hpp_
#define _kebab_hpp_

#include <stdio.h>

enum typ {walec, prostokat, trojkat};

struct KebabW{
	
	float masa;
	float wysokosc;
	float promien;
};

struct KebabP{

	float masa;
	float wysokosc;
	float szerokosc;
	float glebokosc;
};

struct KebabT{

	float masa;
	float wysokosc;
	float krawedz;
};

union KebabU{
	
	KebabW KebW;
	KebabP KebP;
	KebabT KebT;
};

struct Kebab{
	typ ksztalt;
	KebabU rodzaj;
};


Kebab *wczytaj_dane (FILE *we, size_t &rozmiar);
void oblicz_statystyke (const Kebab *tk, size_t n);
#endif
