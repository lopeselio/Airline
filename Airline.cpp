/*
Ross Andreucetti
58432481
ross.andreucetti2@mail.dcu.ie
*/


#include <iostream>			//Imports the packages used in this part of program
#include "Passenger.h"
#include "Flight.h"
#include <list>

list<Passenger> passengers;	//List flights and passengers which act as memory
list<Flight> flights;
list<Passenger>::iterator i;//Iterators for the two lists.
list<Flight>::iterator j;

bool flightExist(string flightNo)		//These method will be used to query our lists to see if a certain flight or passenger is contained in them.
{
	for(j = flights.begin();j != flights.end(); j++)
	{
		Flight tmp = *j;
		if(flightNo.compare(tmp.flightNo)==0)
			return true;
	}
	return false;
}
bool passengerExist(string passNo)
{
	for(i = passengers.begin();i != passengers.end(); i++)
	{
		Passenger tmp = *i;
		if(passNo.compare(tmp.passengerNo)==0)
			return true;
	}
	return false;
}

int main()		//main method
{
	int response;	//this will be used for making selections from menu
	cout << "Welcome to CA212 Airlines." <<endl;
	while(response!=0)
	{
		string passNum;		//used for holding passenger and Flight numbers
		string flightNum;
		cout << "================================================="<<endl;
		cout << "Main Menu:" << endl;
		cout << "Press 1 to create a new Flight." << endl;						//very simple GUI
		cout << "Press 2 to cancel an existing Flight." << endl;
		cout << "Press 3 to see details of a Flight" << endl;
		cout << "Press 4 to input information of a new Passenger." << endl;
		cout << "Press 5 to book a Passenger onto a Flight." << endl;
		cout << "Press 6 to show all Reservations for a passenger." << endl;
		cout << "Press 7 to cancel a Passenger's Reservation." << endl;
		cout << "Press 0 to exit." << endl;
		cout << "================================================="<< endl;
		
		cin >> response;
		switch(response)
		{
			case 1:{		//calls our create flight method from Flight class and stores the new flight in list
				Flight f;
				f.createFlight();
				flights.push_back(f);
				break;}

			case 2:{
				cout <<"Enter Flight Num(AB123):";	//used to cancel a flight by removing it from our list.
				cin >> flightNum;
				if(flightExist(flightNum))
				{
					j = flights.erase(j);
					cout << "Flight " << flightNum <<" has been removed."<<endl;
				}
				else
					cout << "Flight " << flightNum <<" not found."<<endl;
				break;}
			case 3:{
				cout <<"Enter Flight Number(AB123):";		//Used for looking up flight details given a flight number.
				cin >> flightNum;
				if(flightExist(flightNum))
				{
					Flight tmp = *j;
					tmp.showFlight();
				}
				else
					cout << "Flight " << flightNum <<" not found."<<endl;
				break;}
			case 4:{		
				Passenger p;	//takes information for a new passenger and saves it to list
				p.getInfo();
				passengers.push_back(p);
				break;}
			case 5:{
				cout <<"Enter Passenger Number(A123):";	//this is used to book a passenger onto a flight
				cin >> passNum;
				cout <<"Enter Flight Number(AB123):";
				cin >> flightNum;
				if(passengerExist(passNum))	//check if passenger exits
				{
					if(flightExist(flightNum))		//check if flight exists
					{
						Passenger p = *i;
						Flight f = *j;
						if(f.longHaul&&f.seatsLeft>0)	//adds passenger to flight if requirments are met
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;//adjust variables
							*i =p;	//updates lists
							*j=f;
						}
						else if(f.seatsLeft>0)	//used for shorthaul flights
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;
							*i =p;
							*j=f;
						}
						else
							cout << "Flight is Full"<<endl;	//error messages
					}
					else
						cout << "Flight " << flightNum <<" not found."<<endl;
				}
				else
					cout<<"Passenger Number not found"<<endl;
				break;}
			
			case 6:{
				cout <<"Enter Passenger Number(A123):";	//checks to see what flights a passenger is booked onto
				cin >> passNum;
				if(passengerExist(passNum))
				{
					Passenger p = *i;
					p.printInfo();
				}
				else
					cout<<"Passenger Number not found"<<endl;
				break;}
			
			case 7:{
				cout <<"Enter Passenger Number(A123):";		//used for removing a passenger from a flight
				cin >> passNum;
				cout <<"Enter Flight Number(AB123):";
				cin >> flightNum;
				if(passengerExist(passNum))
				{
					if(flightExist(flightNum))
					{
						Passenger p = *i;
						Flight f = *j;
						p.cancelReservation(flightNum);
						f.seatsLeft++;		//increments seats available
					}
					else
						cout << "Flight " << flightNum <<" not found. Flight may have been cancelled!"<<endl;
				}
				else
					cout<<"Passenger Number not found"<<endl;
				break;}
				
		}
	}
	return 0;
}
