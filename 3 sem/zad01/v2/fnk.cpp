#include "fnk.hpp"

void Czlowiek::dodaj()
{
	cout << "Podaj imie: " << endl;
	cin >> imie;
	
	cout << "Podaj nazwisko: " << endl;
	cin >> nazwisko;
	
	cout << "Na ktorym jest roku?: " << endl;
	cin >> rok;
	
	cout << "W ktorej grupie?: " << endl;
	cin >> grupa;	
}

void Czlowiek::wypisz()
{
	cout << "Imie studenta " << imie << endl;	
	cout << "Nazwisko studenta " << nazwisko << endl;	
	cout << "Uczy sie na " << rok <<" roku w "<< grupa << " grupie" << endl;	
	
}

