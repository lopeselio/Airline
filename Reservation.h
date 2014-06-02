/*
Ross Andreucetti
58432481
ross.andreucetti2@mail.dcu.ie
*/

#include <iostream>
#include <string>
using namespace std;


class Reservation  //this is the reservation class used by passenger to make a booking
{
	public: string flightNum;			//the number of the flight
	string seatPosition;	//the seat position, aile, middle, window
	bool business;			//true if business, flase otherwise
	int bags;
	double price;

public:

	void makeReservation(string flightNum,bool longHaul,double basePrice);	//this method fills the reservation details
	void showReservation();	//this method shows the data entered

};

void Reservation::makeReservation(string flightNo,bool longHaul,double basePrice)  //this method promps the user to enter the data above
{
	flightNum = flightNo;
	if(longHaul)//sees if the flight is long haul
	{
		string response;
		cout << "Would you like business class? (y/n)";
		cin >> response;
		if(response.compare("y")==0)
			business = true;
		else
			business = false;
		if(business)
		{
			cout << "Would you like an aisle or window seat?(aisle/window)";//choice of seat
			cin >> seatPosition;
			price = basePrice*2;//sets appropriate price
			bags = 3;
		}
		else
		{
			cout << "Would you like an aisle,middle or window seat?(aisle/middle/window)";
			cin >> seatPosition;
			cout << "You may carry one bag free of charge, would you like to take more at €25/ea? (0-2)";
			cin >> bags;
			price = basePrice + bags*25;//sets price for extra luggage
			cout << "Flight " <<flightNum<< " booked."<<endl; 
		}
	}
	else
	{
		cout << "Would you like an aisle,middle or window seat?(aisle/middle/window)";
		cin >> seatPosition;
		cout << "You may carry some bags at €15/ea? (x)";
		cin >> bags;
		price = basePrice + bags*15;
		cout << "Flight " <<flightNum<< " booked."<<endl; 
		business = false;
	}
}


void Reservation::showReservation()		//show the data in this reservation class
{
	cout <<"--------------------------------------------------"<<endl; 
	cout << "Flight number: "  << flightNum << endl;
	cout << "Seat position: " << seatPosition << endl;
	if(business)
		cout<< "Business: Yes"<<endl;
	else
		cout<< "Business: No"<<endl;
	cout << "Bags: "<<bags<<endl;
	cout << "Price :€"<<price<<endl;;
}
