#include<iostream>
#include"MakeReservation.h"
#include"ReservationInquiry.h"

using namespace std;

char times[4][6] = { "","11:30","14:30","17:30" };
int type[13] = { 0, 1, 1, 2, 2, 3, 4, 4, 0, 0, 5, 5, 5 };

int main() {
	cout << "Welcome to Hi-Lai Harbour Taoyuan Location!\n\n";
	ReservationDatabase reservationDatabase;
	AvailTableDatabase availTableDatabase;
	MakeReservation makereservation(reservationDatabase, availTableDatabase);
	ReservationInquiry reservationInquiry(reservationDatabase, availTableDatabase);
	bool exit = 0;
	while (!exit)
	{
		cout << "1 - Book a Table\n";
		cout << "2 - My bookings\n";
		cout << "3 - End\n";

		cout << "\nEnter your choise: (1~3): ";

		int choise;
		cin >> choise;

		switch (choise)
		{
		case 1:
			makereservation.excute();
			break;
		case 2:
			reservationInquiry.excute();
			break;
		case 3:
			exit = 1;
			cout << endl;
			break;
		default:
			cout << "\nError.\n\n";
			break;
		}
	}
	system("pause");
}