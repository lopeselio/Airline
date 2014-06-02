/*
Ross Andreucetti
58432481
ross.andreucetti2@mail.dcu.ie
*/

#include "Reservation.h"
#include <iostream>
#include <string>
#include <list>

class Passenger
{
	string name;		//the passengers name
	string contactInfo;  //their contact info
	public:string passengerNo;		//unique 4 digit Code A123
	list <Reservation> reservations; // list to keep track of passengers bookings
	list <Reservation>::iterator i;
public:

	void getInfo();				//will prompt the user to enter the passengers name and contact info
	void makeReservation(string flightNum,bool longHaul,double basePrice);		//will call the make reservation by calling the reservation methof of the same name
	void cancelReservation(string flightNum);		//as buisness class passengers can cancel their reservatiion, this method will alow that to be so
	void printInfo();
};


void Passenger::getInfo()
{
	string dummy;
	getline(cin, dummy);
	cout << "Enter the passengers name: " << endl;
	getline(cin,name);	//prompt user to enter name and read it
	cout << "Enter their contact number: " << endl;
	cin >> contactInfo;		//prompt user to enter passengers contact info and read
	cout << "Enter their passenger number(A123): " << endl;
	cin >> passengerNo;		//prompt user to enter passengers contact info and read

}

void Passenger::makeReservation(string flightNum,bool longHaul,double basePrice) //calls the makeRes methods and stores it in our list
{
	Reservation r;
	r.makeReservation(flightNum,longHaul,basePrice);
	reservations.push_back(r);
}


void Passenger::cancelReservation(string flightNum)
{

	for(i = reservations.begin();i!=reservations.end();i++)		//cancels reservations, causes a crash..
	{
		Reservation r = *i;
		if(r.flightNum.compare(flightNum)==0)
		{
			if(r.business)
				cout << "Flight Cancelled, €"<<r.price << " refunded"<<endl;
			else
				cout<<"Flight Cancelled"<<endl;
			i=reservations.erase(i);
			break;

		}

	}
}

void Passenger::printInfo()  //just prints out passneger data  and reservations data.
{
	cout << "This passengers details are...." << endl;
	cout << "Name = " << name << endl;
	cout << "ContactInfo = " << contactInfo << endl;
	cout << "There reservation details are...." << endl;
	for(i = reservations.begin();i!=reservations.end();i++)
	{
		Reservation r = *i;
		r.showReservation();
	}

	cout << "\n";

}

