/*
	Lukasz Sawicki
	298208
*/

#include <stdio.h>
#include <stdlib.h>
#include "mnk.hpp"
int main(int argc, char *arg[])
{
	FILE *we = stdin;    //tak niech beedzie domyslnie
	FILE *wy = stdout;
	if(argc == 3)
	{
		we = fopen(arg[1],"r");
		if(!we)
		{
			puts("wystapil blad");
			exit(1);
		}
		
		wy = fopen(arg[2],"w");
		if(!we)
		{
			puts("wystapil blad");
			exit(2);
		}
	}else if(argc != 1 && argc != 3)
	{
		puts("zla liczba elementow");
		exit(3);
	}

	
	double a = 0, b = 0;
	DaneXYF tab = wczytaj_dane(we);
	dopasowanie_mnk(tab,a,b);
	wypisz_dane(wy,tab);
	
	fclose(we);
	fclose(wy);
	free(tab.tab);
	return 0;
}
