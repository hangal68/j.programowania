#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kebab.hpp"


Kebab *wczytaj_dane (FILE *we, size_t &rozmiar)
{
	Kebab *tab = NULL;
	int i = 0;
	char c[2]; // T W lub P
	
	while(fscanf(we,"%s",c) != EOF)
	{
		tab = (Kebab*)realloc(tab,sizeof(Kebab)*(i + 1));

		if(c[0] == 'W')
		{
			tab[i].ksztalt = walec;	
			fscanf(we,"%f %f %f",&tab[i].rodzaj.KebW.masa, &tab[i].rodzaj.KebW.wysokosc, &tab[i].rodzaj.KebW.promien);					
		}else if(c[0] == 'P')
		{
				fscanf(we,"%f",&tab[i].rodzaj.KebP.masa);
				fscanf(we,"%f",&tab[i].rodzaj.KebP.wysokosc);
				fscanf(we,"%f",&tab[i].rodzaj.KebP.szerokosc);
				fscanf(we,"%f",&tab[i].rodzaj.KebP.glebokosc);
				tab[i].ksztalt = prostokat;
			fscanf(we,"%f %f %f %f",&tab[i].rodzaj.KebP.masa, &tab[i].rodzaj.KebP.wysokosc, &tab[i].rodzaj.KebP.szerokosc,&tab[i].rodzaj.KebP.glebokosc );
		}else if(c[0] == 'T')
		{
				fscanf(we,"%f",&tab[i].rodzaj.KebT.masa);
				fscanf(we,"%f",&tab[i].rodzaj.KebT.wysokosc);
				fscanf(we,"%f",&tab[i].rodzaj.KebT.krawedz);
				tab[i].ksztalt = trojkat;
			fscanf(we,"%f %f %f",&tab[i].rodzaj.KebT.masa, &tab[i].rodzaj.KebT.wysokosc, &tab[i].rodzaj.KebT.krawedz );
		}
		i++;		
	}
	rozmiar = i;
	return tab;	
}



void oblicz_statystyke (const Kebab *tk, size_t n){
	
	int liczba_W = 0;
	int liczba_P = 0;
	int liczba_T = 0;
	float obj = 0;
	float pi = 3.14159;
	float masa = 0;
	
	//liczymy wysokosc kazdego stosu
	
	for(size_t i = 0; i < n; i++)
	{
		if(tk[i].ksztalt == walec)
		{
			liczba_W++;
			obj += pi * tk[i].rodzaj.KebW.promien * tk[i].rodzaj.KebW.promien * tk[i].rodzaj.KebW.wysokosc;
			masa += tk[i].rodzaj.KebW.masa;
		}else if(tk[i].ksztalt == prostokat){
			
			liczba_P++;
			obj += tk[i].rodzaj.KebP.wysokosc * tk[i].rodzaj.KebP.szerokosc * tk[i].rodzaj.KebP.glebokosc;
			masa += tk[i].rodzaj.KebP.masa;
		}else if(tk[i].ksztalt == trojkat){
			
			liczba_T++;
			obj += (tk[i].rodzaj.KebT.krawedz * tk[i].rodzaj.KebT.krawedz * 1.71)/4 * tk[i].rodzaj.KebT.wysokosc;
			masa += tk[i].rodzaj.KebT.masa;
		}
		
	}
	//srednia wykosc stosu
	float srednia;
	srednia = (liczba_W + liczba_P + liczba_T)/3;
	
	//wysweit wszystko
	
	printf("Kebabow walcowych jest: %i sztuk, natomiast kebabow prostopadlosciennych klienci zamowili %i sztuk, a graniastoslupow jedynie %i\n",liczba_W,liczba_P,liczba_T);
	printf("Srednia wyskoksc stosow: %f",srednia);
	printf("\nCalkowita objetosc kebabow to %f, a masa to %f \n Grubasy...\n",obj,masa);
}

