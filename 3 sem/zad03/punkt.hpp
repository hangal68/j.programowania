#include <iostream>

using namespace std;

class Punkt {
	
	float mX, mY, mZ;
public:
	Punkt(){ mX = 0, mZ = 0, mY = 0 ;}
	Punkt(float, float, float);
	~Punkt(){ cout << "Usunieto punkt" <<endl; };
	void przedstaw();
	
	friend class Wektor;
};
