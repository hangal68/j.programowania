#include <iostream>

using namespace std;

class Date {
	int year;
	int month;
	int day;
	
	public:
	void readDate();
	void printDate();
	int ret_day();
	int ret_month();
	int ret_year();
};

struct cmp{
	
	int days[2];
	int months[2];
	int years[2];
	
};
int count(int mt[], cmp d); //do dni i miesiecy
int count(); // do lat
