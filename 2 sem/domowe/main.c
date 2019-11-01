#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double *wczytaj_dane(int *n);
double *licz_boki(const double *tab, int *n);
double licz_obw( const double *tab, int *n);
void zapisz(double *obw, int *n);


int main()
{
	int n = 0;
	
	double *tab = wczytaj_dane(&n);
	
	double *boki = licz_boki(tab, &n);
	
	
	double obw = licz_obw(boki , &n);
	
	zapisz(&obw, &n);
	
	free(tab);
	free(boki);
	return 0;
}

double *wczytaj_dane(int *n)
{	int ile;
	puts("Podaj liczbe wierzcholkow");
	scanf("%d",&ile);
	double *tab = (double*)calloc(2 * ile,sizeof(double)); //2 razy ile bo najpierw x a potem y
	
	puts("Podaj wsp wieszcholkow, najpierw x a potem y");
	
	for(int i = 0; i < ile; i++)
	{
		scanf("%lf", &tab[i]); //wczyta x
		scanf("%lf", &tab[i+1]); // y
	}
	
	*n = ile;
	return tab;
	
}


double *licz_boki(const double *tab, int *n)
{

	int n_bok = *n;
	double *boki = (double*)calloc(2 * n_bok,sizeof(double));
	
	for(int i = 0; i < n_bok - 1; i++)
	{
		boki[i] = sqrt((tab[i+2] - tab[i]) * (tab[i+2] - tab[i]) + (tab[i+3] - tab[i+1]) * (tab[i+3] - tab[i+1]));
				
	}
	
	return boki;
	
}


double licz_obw( const double *tab, int *n)
{
	int k = *n;
	double obw;
	
	for(int i = 0; i < k;i++)
	{
		obw += tab[i];
	}
	
	printf("obwod wynosi: %f\n", obw);
	return obw;
}


void zapisz(double *obw , int *n)
{
	
	FILE *plik = fopen("wynik.txt", "r+");
	
	fprintf(plik,"wielokat ma %ls wierzcholkow, a jego obwod to %lf",n,obw);

	
	
	
	fclose(plik);
}
