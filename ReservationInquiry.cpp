#include"ReservationInquiry.h"

extern int type[13];

ReservationInquiry::ReservationInquiry(ReservationDatabase& reservationDatabase, AvailTableDatabase& availTableDatabase)
	:reservationDatabase(reservationDatabase), availTableDatabase(availTableDatabase)
{}

ReservationInquiry::~ReservationInquiry(){}

void ReservationInquiry::excute(){
	if (reservationDatabase.empty()) {
		cout << "\nNo bookings.\n\n";
		return;
	}
	
	cout << "\nEnter reservation number: ";
	int number;
	cin >> number;
	cin.ignore();

	cout << "\nEnter reservation password: ";
	string password;
	getline(cin, password);
	
	bool found = 0;
	Reservation temp = reservationDatabase.search(number, password, found);

	if (found) {
		char choise;
		do {
			cout << "\nCancel this reservation? ( y / n ) ";
			cin >> choise;
		} while (choise != 'y' && choise != 'n');

		if (choise == 'y') {
			reservationDatabase.cancel(number, password);
			availTableDatabase.decrease(temp.getDate(), temp.getTimecode(), type[temp.getCustomers()]);
		}
		else {
			cout << endl;
			return;
		}
	}
	else {
		cout << "\nBookings could not be found.\n\n";
		return;
	}
}