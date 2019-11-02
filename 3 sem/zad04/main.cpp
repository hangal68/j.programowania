#include "parabola.hpp"
#include "prosta.hpp"

int Point::counter = 0;
int Parabola::counter = 0;
int Prosta::counter = 0;

int main()
{
	float x1, x2, x3, y1, y2, y3;
	
	cout << "Witamy w PARABOLEX 3000" << endl;
	cout << "Podaj trzy punkty: (x,y)" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	Point *p1 = new Point(x1,y1);
	Point *p2 = new Point(x2,y2);
	Point *p3 = new Point(x3,y3);
	
	p1->info();
	p2->info();
	p3->info();

	Parabola *Parabolka = new Parabola(*p1,*p2,*p3);
	Parabolka->info();
	
	
	cout << "Podaj punkt (x) liczenia stycznej" << endl;
	float xD;
	cin >> xD;
	Point *p4 = new Point(xD);
	//p4->policz_y(Parabolka->A, Parabolka->B, Parabolka->C, xD);
	cout << "Punkt stycznosci: " << endl;
	p4->info();
	
	Prosta *pr1 = new Prosta;
	pr1->policz_styczna(*p4, *Parabolka);
	cout << "Prosta styczna do punktu stycznosci " << endl;
	pr1->info();
	
	
	
	delete Parabolka;
	delete p1; delete p2; delete p3, delete p4;
	delete pr1;

	return 0;
}



/*
	mimo przyjazni funkca policz_y nie dziala
	w klasie parabola trzeba dodac funkcje float get_A(), float get_B() itd ktore beda zwracały wartosc wspolczynnikow A B C, i ich uzyjemy jako wartosc do p4->policz_y();
	linijka 31 bez komentarza nie dziala, mozna to rozwazac w wyzje wymioniony sposob

	jesli nie uda sie przeprowadzic paraboli program ma zakonczyc dzialanie!
*/