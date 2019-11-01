#include "fnk.hpp"


int main()
{	
	Czlowiek pierwszy, drugi, trzeci;
	stack<Czlowiek> stos;
	
	pierwszy.dodaj();
	drugi.dodaj();
	trzeci.dodaj();
	
	stos.push(trzeci);
	stos.push(drugi);
	stos.push(pierwszy);
	
	while( !stos.empty() )
	{
		
		stos.top().wypisz();
		stos.pop();
		
	}
	
	return 0;
}
