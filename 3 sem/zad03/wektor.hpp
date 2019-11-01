#include <iostream>
#include "punkt.hpp"

using namespace std;

class Wektor {
	
	float mA, mB, mC;
	
public:
	Wektor(){ mA = 0, mB = 0, mC = 0; }
	Wektor(Punkt&, Punkt&);
	~Wektor() { cout << "Usunieto wektor" << endl; };
	void przedstaw();
	float dl();
};
