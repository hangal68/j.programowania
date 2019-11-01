#include <stdio.h>
#include <stdlib.h>
#include "mnk.hpp"



DaneXYF wczytaj_dane (FILE *we)
{
	 DaneXYF dane;
	 PunktXYF *tab = NULL;
	 int i = 0;
	 while(!feof(we))
	 {
		tab = (PunktXYF*)realloc(tab,sizeof(PunktXYF)*(i + 1));
		fscanf(we,"%f %f",&tab[i].x,&tab[i].y);
		i++; 
	 }
	dane.rozmiar = i;
	dane.tab = tab;
	return dane;
}

void dopasowanie_mnk (DaneXYF dane, double &a, double &b)
{
	int s = dane.rozmiar;
	double sx = 0, sy = 0, sxx = 0, syy = 0, sxy = 0;
	for(int i = 0; i < s; i++)
	{
		sx += dane.tab[i].x;
		sy += dane.tab[i].y;
		sxx += dane.tab[i].x*dane.tab[i].x;
		syy += dane.tab[i].y*dane.tab[i].y;
		sxy += dane.tab[i].x*dane.tab[i].y;		
	}
	double delta = s*sxx - sx*sx;
	
	a = (s*sxy - sx*sy) / delta;
	b = (sxx*sy - sx*sxy) / delta;
	
	for(int i = 0; i < s; i++)
	{
		dane.tab[i].f = a*dane.tab[i].x + b;
	}
	
	fprintf(stderr,"Parametr a = %lf \nParametr b = %lf\n",a,b);
	
}

void wypisz_dane (FILE *wy, DaneXYF dane)
{
		int n = dane.rozmiar;
		for(int i=0;i<n - 1;i++)
		{
			fprintf(wy,"%f %f %f\n",dane.tab[i].x,dane.tab[i].y,dane.tab[i].f);
		}
	
}

