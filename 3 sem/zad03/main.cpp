#include <iostream>
#include "wektor.hpp"

int main()
{
	char wybor;
	do{
	
		float x1,x2,y1,y2,z1,z2;
			cout << "Podaj wsp. punktu 1" <<endl;
			cin >> x1 >> y1 >> z1;
			cout << "Podaj wsp. punktu 2" <<endl;
			cin >> x2 >> y2 >> z2;
		
		Punkt p1(x1,y1,z1);
		Punkt p2(x2,y2,z2);
		
		
		cout << "Punkt 1 " << endl;
		p1.przedstaw();
		cout << "Punkt 2 " << endl;
		p2.przedstaw();
		
		
		Wektor w(p1,p2);
		cout << "Wektor" <<endl;
		w.przedstaw();
		float dlugosc_w = w.dl();
		cout << " Dlugosc wektora" << dlugosc_w << endl;
		
		
		cout << "Jeszcze raz? y/n" << endl;
		cin >> wybor;
	}while(wybor == 121);
	
	return 0;
}
