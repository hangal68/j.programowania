#include "lib.hpp"



int main()
{
	
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	Date d1,d2;
	cmp diff;
	d1.readDate();
	d2.readDate();
	
	cout << "Sprawdzam daty: " << endl;
	d1.printDate();
	d2.printDate();
	if(d1.ret_month() > d2.ret_month())
	{
		diff.days[1] = d1.ret_day();
		diff.months[1] = d1.ret_month();
		diff.days[0] = d2.ret_day();
		diff.months[0] = d2.ret_month();
		
	}else if(d2.ret_month() > d1.ret_month())
	{
		diff.days[1] = d2.ret_day();
		diff.months[1] = d2.ret_month();
		diff.days[0] = d1.ret_day();
		diff.months[0] = d1.ret_month();
	}else if(d1.ret_month() == d2.ret_month())
	{
		if(d1.ret_day() > d2.ret_day())
		{
			diff.days[1] = d1.ret_day();
			diff.months[1] = d1.ret_month();
			diff.days[0] = d2.ret_day();
			diff.months[0] = d2.ret_month();
		}else 
		{
			diff.days[1] = d2.ret_day();
			diff.months[1] = d2.ret_month();
			diff.days[0] = d1.ret_day();
			diff.months[0] = d1.ret_month();
		}
	}	
	
	cout << count(months, diff) << endl;
	



	return 0;
}
///
