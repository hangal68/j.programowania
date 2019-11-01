#include <stdio.h>
#include <iostream>
#include <allegro.h>
#include "arg.hpp"

int main(int argc, char *arg[])
{
	Parametry parametr = AnalizujArgumenty(argc,arg);
	obiekty dane = WczytajDaneTXT(parametr.plik);
	RysujRadar(dane);
	
	
	
	
	return 0;
}

