/*
Ross Andreucetti
58432481
ross.andreucetti2@mail.dcu.ie
*/

#include <iostream>
#include <string>
#include "Date.h"

class Flight
{
	string depCity;		//where flight is going and coming from
	string arrCity;
	int	depTime;		//time and dates of flight
	int arrTime;
	Date depDate;
	Date arrDate;
	public:string flightNo;		//flight number
	bool longHaul;	
	public:int capacity;
	public:int seatsLeft;
	double basePrice;		//basic price

	public:
		void createFlight();		//our methods
		void cancelFlight();
		void showFlight();
};

	void Flight:: createFlight()		//this is used to create a new flight and assigns correct values to variables
	{
		int tempDay;		//used for inputing date
		int tempMonth;
		int tempYear;

		string dummy;		//used to clearinput buffer
		getline(cin, dummy);
		cout << "Enter the city of Departure: ";
		getline(cin,depCity);
		
	
		cout << "Enter the city of Arrival: ";
		getline(cin,arrCity);
		
		cout << "Please enter time of Departure(HHMM)" << endl;
		cin >> depTime;
		cout << "Please enter time of Arrival(HHMM)" << endl;
		cin >> arrTime;
		
		cout << "Please enter Date of Departure(DD MM YYYY)" << endl;
		cin >> tempDay;
		cin >> tempMonth;
		cin >> tempYear;   //read in the data
		depDate.make(tempDay, tempMonth, tempYear);
		
		cout << "Please enter Date of Arrival(DD MM YYYY)" << endl;
		cin >> tempDay;
		cin >> tempMonth;
		cin >> tempYear;   //read in the data
		arrDate.make(tempDay, tempMonth, tempYear);
		
		cout << "Please enter Flight number (AB123)" << endl;
		cin >> flightNo;

		string result;
		cout << "Is this flight longhaul? (y/n)" << endl;
		cin >> result;
		if(result.compare("y")==0)//checks if flight is long haul or not
		{
			longHaul = true;
			capacity = 300;
			seatsLeft = capacity;
		}
		else
		{
			longHaul = false;
			capacity = 120;
			seatsLeft = capacity;
		}
		cout << "Please enter the base price for this flight(XXX.XX)"<<endl;
		cin >> basePrice;


	}

	void Flight:: showFlight()		//used to print out details of a certain flight
	{
		cout << depCity << " to " << arrCity << endl;
		
		cout << "Departing at: " << depTime << " ";
		depDate.showDate();
		cout <<endl;

		cout << "Arriving at: " << arrTime <<" ";
		arrDate.showDate();
		cout << endl;
		
		cout << "Flight No: " << flightNo << endl;
		cout << "Base Price: " << basePrice << endl;
		cout << seatsLeft <<"/"<<capacity<<" seats remaining."<<endl;
	}
