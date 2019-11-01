#include "fnk.hpp"


int main()
{
	list<Czlowiek> lst;
	
	Czlowiek pierwszy, drugi, trzeci;
	list<Czlowiek>::iterator i;
	
	lst.push_back(pierwszy);	
	lst.push_back(drugi);	
	lst.push_back(trzeci);
	
	for(i = lst.begin(); i != lst.end(); i++)
	{
		i->dodaj();
	}
	
	
	for(i = lst.begin(); i != lst.end(); i++)
	{
		i->wypisz();
	}
	
	
	return 0;
}
