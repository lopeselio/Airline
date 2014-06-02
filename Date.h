/*
Ross Andreucetti
58432481
ross.andreucetti2@mail.dcu.ie
*/

#include <iostream>

class Date
{
	int day;
	int month;
	int year;
public:
	void make(int, int, int);
	bool lessThan24(Date);
	void showDate();	//prints out the entered date
	
};

void Date::make(int d, int m, int y)  //this simple constructor assigns the parameter variables to the instanced variables
{
	day = d;
	month = m;
	year = y;
}


void Date::showDate()
{
	cout << day << "-" << month << "-" << year;		//prints out the date in a nice format

}