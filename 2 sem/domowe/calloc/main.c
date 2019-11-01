#include <stdio.h>
#include <stdlib.h>

int main()
{
	short int ile = 0;
	FILE *plik = fopen("in.txt","r+");
	fscanf(plik,"%hd",&ile);
	
	int *liczby = (int*)calloc(sizeof(int),ile);
	if(!plik) puts("blad\n");

	for(int i = 0; i<ile;i++)
	{	
		fscanf(plik,"%d",&liczby[i]);
	}
	fclose(plik);
	// srednia
	double suma = 0;
	for(int i = 0;i<ile;i++)
	{
		suma += liczby[i];	
	}
	double srednia = suma/ile;
	int MAX = liczby[0];
	int MIN = liczby[0];
	for(int i = 1;i<ile;i++)
	{
		if(liczby[i] > MAX)
			MAX = liczby[i];
		if(liczby[i] < MIN)
			MIN = liczby[i];
	}
	free(liczby);
	
	printf("Srednia z %d liczb wynosi %f, liczba najwieksza to %d, a najmniejsza %d",ile,srednia,MAX,MIN);
	return 0;
}
