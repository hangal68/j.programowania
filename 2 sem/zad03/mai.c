#include <stdio.h>

	const short wsp[] = {1,10,3,30,9,90,27,76,81,34,49,5,50,15,53,45,62,38,89,17,73,51,25,56,75,71,31,19,93,57};
	int NRB[30];
	int first_four;
	int *p_NRB = NRB;
	char k;
	int numer;
	char nazwa[50];
	char bufor[50];
	int kontrolna = 0;
int main()
{
	puts("Wprowadz numer banku: ");
	
	for(int i = 0;i<26;)
	{
		k = getchar();
		if(k>=48 && k<=57)
		{
			*p_NRB ++ = k-48;
			i++;
		}

	}
	p_NRB -= 26; //wskaznik na pierwsze miejsce
	int *p2_NRB = NRB;
	p2_NRB +=2;
	//tworzenie NRB do obliczenia wielomianu
	NRB[28] = NRB[0];
	NRB[29] = NRB[1];
	for(int i = 0;i<24;i++)
	{
		*p_NRB ++ = *p2_NRB ++;
	}
	NRB[24] = 2;
	NRB[25] = 5; 
	NRB[26] = 2;
	NRB[27] = 1;
	
	//liczymy kontrolna
	for(int i = 0;i<30;i++)
	{
		kontrolna += NRB[29-i]*wsp[i];
	}
	
	//czy poprawna
	if(kontrolna % 97 == 1)
	{
		puts("Twoj numer rachunku jest poprawny\n");
	}else
	{
		puts("Niepoprawny nymer rachunku\n");
		return 1;
	}
	//printf("%d",kontrolna);
	first_four = 1000*NRB[0]+100*NRB[1]+10*NRB[2]+NRB[3];
	FILE *plik = fopen("dane.txt","r+");
	if(!plik)puts("nie otwarto");
	while(fscanf(plik,"%d",&numer) != EOF)
	{
		fscanf(plik,"%d",&numer);
		fgets(nazwa,50,plik);
		if(first_four == numer)
			{
				printf("Nazwa twojego banku to: %s",nazwa);
				break;
			}
	}
	fclose(plik);
	
	
	return 0;
}
