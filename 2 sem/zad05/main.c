#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *wczytaj_dane (FILE *we, size_t *n);
void analiza (const float *dane, size_t n, float *m, float *s);
unsigned *histogram (const float *dane, size_t n, float hmin, float hmax, unsigned nbin);
void wyswietl_histogram (FILE *wy, const unsigned *histogram, float hmin, float hmax, unsigned nbin);


int main(int argc, char *arg[])
{
	if(argc != 2)
	{
		printf("blad w argumencie");
		exit(1);
	}
	unsigned nbin = atoi(arg[1]);
	
	size_t n;
	float m;
	float s;

	
	float *tablica = wczytaj_dane(stdin,&n);

	analiza(tablica,n,&m,&s); // liczbymy srednia i odchylenie
	printf("%f\n",s);		
	float hmin = m - 3*s;
	float hmax = m + 3*s;	
	
	unsigned *hist = histogram(tablica,n,hmin,hmax,nbin);
	
	wyswietl_histogram(stdout,hist,hmin,hmax,nbin);
	
	return 0;
}

float *wczytaj_dane (FILE *we, size_t *n)
{
	float rozmiar = 0;
	fscanf(we,"%f",&rozmiar);
	*n = (size_t)rozmiar;
	float *tab = (float*)malloc(sizeof(float) * rozmiar);
	
	for(int i = 0; i<rozmiar;i++)
	{
		fscanf(stdin,"%f",&tab[i]);
	}
	return tab;
}

void analiza (const float *dane, size_t n, float *m, float *s)
{
	float suma = 0;
	float suma_s = 0;
	for(int i = 0; i<n;i++)
	{
		suma += dane[i];
	}
	
	*m = suma/n; //srednia
	for(int i = 0; i<n;i++)
	{
		suma_s += (&dane[i] - m)*(&dane[i] - m);
	}
	
	*s = sqrt(1.0/(n-1.0)*suma_s);
}

unsigned *histogram (const float *dane, size_t n, float hmin, float hmax, unsigned nbin)
{
	unsigned *hist = (unsigned*)calloc(sizeof(unsigned),nbin);
	
	for(int i = 0; i<n;i++)
	{
		unsigned a = (dane[i]-hmin)/(hmax-hmin)*nbin;
		hist[a]++;
		
		if(a<hmin)
		{hist[0]++;}
		if(a>hmax)
		{hist[nbin-1]++;}
	}	
	
	return hist;
}

void wyswietl_histogram (FILE *wy, const unsigned *histogram, float hmin, float hmax, unsigned nbin)
{
	float srednia = (hmax - hmin)/nbin;
	
	
	for(int i=0;i<nbin;i++)
	{
		float srodek = srednia*i +srednia/2 +hmin;
	
	fprintf(wy,"%f\t %d\n",srodek,histogram[i]);
	
	}
	
}
