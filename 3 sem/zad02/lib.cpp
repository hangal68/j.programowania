#include "lib.hpp"

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


void Date::readDate()
{

	cout << "Podaj dzien: " << endl;
	cin >> day;
	cout << "Podaj miesiac: " << endl;
	cin >> month;
	cout << "Podaj rok: " << endl;
	cin >> year;
	
}

void Date::printDate()
{

	cout << day << "." << month << "." << year << endl;
	
}

int Date::ret_day()
{
	return day;	
}
int Date::ret_month()
{
	return month;	
}
int Date::ret_year()
{
	return year;	
}

int count(int mt[], cmp d)
{
	int days_left = 0;
	for(int i = d.months[0] + 1; i < d.months[1]; i++)
	{
		days_left += months[i-1];
		//cout<<days_left<<endl;
	}
	if(d.months[0] != d.months[1])
	{
		days_left += months[d.months[0]-1]  - d.days[0] + d.days[1];	
	}else
	{
		days_left +=d.days[1] - d.days[0];
	}	
	return days_left;
	
}
