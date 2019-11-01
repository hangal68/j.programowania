#include <stdio.h>

int main()
{
	char name[20];
	int num[20];  //tablica wczytach liczb
	int num2[20]; //tablica kwadratow
	int num3[20]; //tablica szescianow
	
	puts("Podaj nazwe pliku: ");	
	scanf("%s",name);
	
	FILE *plik = fopen(name,"r+");
	if(!plik) puts("error");
		else{
	for(int i = 0; i<20; i++)
		{
				fscanf(plik,"%i",&num[i]);			
		}
		
	
	//liczymy kwadrat i szescian
	
	for(int i = 0;i<20;i++)
		{
			num2[i] = num[i]*num[i];
			num3[i] = num[i]*num[i]*num[i];
		}
		
	//zapis danych
	FILE *out = fopen("out.txt","a+");
	
		fprintf(out,"\n%s\n\n",name);
	for(int i = 0; i<20;i++)
		{
			fprintf(out,"%i | %i\n ",num2[i],num3[i]);
		}
		

	fclose(out);
	fclose(plik);
	return 0;
}}
