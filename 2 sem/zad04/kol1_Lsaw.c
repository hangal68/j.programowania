#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char *arg[])
{
	if((argc == 3 && strcmp(arg[2],"-S"))){
		if(argc != 4){	
		puts("niepoprawna ilosc argumentow");
		return 1;
		}}
		
		bool arg_good = false; // do sprawdzenia czy argumenty sa poprawne
		char wybor[4];
		strcpy(wybor,arg[2]);
		
		
	//licze linijki
	FILE *licz_plik = fopen(arg[1], "r");
		if(!licz_plik)
		{
			puts("nie ma takiego pliku");
			return 2;
		}
		int linijki = 0;
		while(!feof(licz_plik))
		{	float x,y;
			linijki ++;
			fscanf(licz_plik, "%f %f", &x, &y);
		}
		linijki --; // -- ze wzgledu na petle while i spoosb jej dzialania
		fclose(licz_plik);

//////////////////////	pochodna	/////////////////////////////
		if(!strcmp(wybor,"-P"))
		{
			arg_good = true;
			FILE *we = fopen(arg[1], "r");
			FILE *wy = fopen(arg[3], "w");
			if(!we)
			{
				fprintf(stderr,"Nie ma takiego pliku.");
				return 3;
			}
				if(!wy)
			{
				fprintf(stderr,"Nie moge utworzyc pliku na dysku.");
				return 4;
			}
		
			float x1=0;
			float y1=0;
			float x0=0;
			float y0=0;
		
			fscanf(we, "%f %f", &x0, &y0);
			
			while(!feof(we))
			{
				fscanf(we, "%f %f", &x1, &y1);
				fprintf(wy, "%f %f\n", x0, (y1-y0)/(x1-x0));
				x0=x1;
				y0=y1;
			}

			fclose(we);
			fclose(wy);
			}


//////////////////	calka	//////////////
		if(!strcmp(wybor,"-C"))
		{
			arg_good = true;
			FILE *we = fopen(arg[1], "r");
			FILE *wy = fopen(arg[3], "w");
			if(!we)
			{
				fprintf(stderr,"Nie ma takiego pliku.");
				return 5;
			}
				if(!wy)
			{
				fprintf(stderr,"Nie moge utworzyc pliku na dysku.");
				return 6;
			}
		
			float x1=0;
			float y1=0;
			float x0=0;
			float y0=0;
			float s = 0;
			
			fscanf(we, "%f %f", &x0, &y0);
			
			while(!feof(we))
			{
				fscanf(we, "%f %f", &x1, &y1);
				s += ((x1-x0)*(y1+y0))/2;
				fprintf(wy, "%f %f\n", x1, s);
			}

			fclose(we);
			fclose(wy);
		}
		
/////////////////	odchylenie	/////////////////			
		if(!strcmp(wybor,"-S"))
		{
			arg_good = true;
			FILE *we = fopen(arg[1], "r");
			if(!we)
			{
				fprintf(stderr,"Nie ma takiego pliku.");
				return 7;
			}
			
			float mi = 0;
			float sigma = 0;
			float s_roznic = 0;
			float suma_y = 0;
			float x = 0;
			float y = 0;
			
			for(int i = 0; i<linijki; i++)
			{
				fscanf(we, "%f %f", &x, &y);
				suma_y += y;
			}
			printf("%f",suma_y);
			
			mi = suma_y/linijki;
			
			for(int i = 0; i<linijki;i++)
			{
				fscanf(we, "%f %f", &x, &y);
				s_roznic += (y-mi)*(y-mi);
			}
			
			sigma = sqrt((1/(linijki-1))*s_roznic);
			
			printf("Wartosc srednia kolumny drugiej wynosi: %.4f,\na nieobciazony estymator odchylenia standardowego danych z drugiej kolumny: %.4f\n",suma_y/linijki,sigma);
			
			
			fclose(we);
		}
		
		if(arg_good == false)
		{puts("zly argument");
			return 0xA;
		}
		
	return 0;
}
