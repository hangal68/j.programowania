#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <allegro.h>
#include <math.h>
#include "arg.hpp"

Parametry AnalizujArgumenty( int argc, char *arg[])
{
	if(argc == 3)
	{
		Parametry parametr;
		
		
		if(strcmp("-b",arg[1]) == 0)
		{
			parametr.plik = fopen(arg[2],"r+");
			if(!parametr.plik)
			{
				puts("Nie udalo sie otworzyc pliku :( ");
			}else{
				parametr.bin = 1;
				parametr.txt = 0;			
				}
		}
		if(strcmp("-t",arg[1]) == 0)
		{
			//tutaj obsluga pliku binarnego
			
			parametr.bin = 0;
			parametr.txt = 1;			
		}else
		{
			puts("pierwszy parametr jest zly... ");
		}
		return parametr;
	}else if(argc != 3)
	{
		puts("zla liczba argumentow!");
	}
	
}


obiekty WczytajDaneTXT(FILE *plik)
{
	obiekty dane;
	obiekt *tab = NULL;
	int i = 0;
	
	float odl, kat, rozmiar;
	
	while(fscanf(plik,"%f %f %f", odl,kat,rozmiar) != EOF)
	{
		tab = (obiekt*)realloc(tab, sizeof(obiekt) * (i+1));
		
		tab[i].r = odl;
		tab[i].kat = kat;
		tab[i].rozmiar = rozmiar;
		
		i++;		
	}
	dane.tab = tab;
	dane.i = i;
	return dane;
}

float polozenieX(const obiekt &o)
{
	float fi = o.kat * 3.14159 / 180;
	float x = o.r * sin(fi);
	return x;
}

float polozenieY(const obiekt &o)
{
	float fi = o.kat * 3.14159 / 180;
	float y = o.r * sin(fi);
	return y;
}

void RysujRadar(const obiekty &o)
{
	allegro_init ();
	install_keyboard ();
	install_timer ();
	set_color_depth (32);
	set_gfx_mode (GFX_AUTODETECT_WINDOWED, 500, 500, 0, 0);
	set_window_title ("Radarex 3000");
	
	int green = makecol(18,168,105);
	int yellow = makecol(232,216,15);
	//tworzy okregi
	circle(screen,249,249,50,green);
	circle(screen,249,249,100,green);
	circle(screen,249,249,150,green);
	circle(screen,249,249,200,green);
	circle(screen,249,249,250,green);
	
	//tworzy obiekty
	for(int i = 0; i < o.i; i++)
	{
		float x =  polozenieX(o.tab[i]);
		float y =  polozenieY(o.tab[i]);
		int r =  (o.tab[i].rozmiar)/2;
		circlefill(screen,x, y,r,yellow);
				
	}
	
	readkey();
	
	
}
