#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>
#include"MakeReservation.h"

using namespace std;

extern int type[13];

MakeReservation::MakeReservation(ReservationDatabase& reservationdatabase, AvailTableDatabase& availtabledatabase)
	:reservationdatabase(reservationdatabase), availtabledatabase(availtabledatabase)
{}

MakeReservation::~MakeReservation() {}

void MakeReservation::excute() {
	Reservation now;

	int count;
	do {
		cout << "\nEnter the number of customers (1 - 7, 10 - 12): ";
		cin >> count;
	} while (!((1 <= count && count <= 7) || (10 <= count && count <= 12)));
	now.setCustomers(count);

	cout << "\nChoose a date:\n";
	Date date;
	for (int i = 1, endline = 0; i < 31; i++) {
		availtabledatabase.push_back(AvailTable(date));
		if (availtabledatabase.dayAvail(date, count)) {
			cout << setw(2) << setfill(' ') << i << ". " << date << "  ";
			endline++;
		}
		if (endline % 4 == 0)
			cout << endl;
		++date;
	}
	cout << "\n?";
	int datecode;
	cin >> datecode;
	now.setDate(availtabledatabase.getdate(datecode));

	cout << "\nChoose a time:\n";
	availtabledatabase.displaytime(datecode - 1, count);
	cout << "\n?";
	int timecode;
	cin >> timecode;
	now.setTimecode(timecode);
	now.setTime(timecode);

	cin.ignore();

	cout << "\nEnter name: ";
	string name;
	getline(cin, name);
	now.setName(name);

	cout << "\nEnter mobile number: ";
	string mobileNumber;
	getline(cin, mobileNumber);
	now.setMobileNumber(mobileNumber);

	cout << "\nEnter email address: ";
	string email;
	getline(cin, email);
	now.setEmailAddress(email);

	cout << "\nEnter reservation password: ";
	string password;
	getline(cin, password);
	now.setPassword(password);

	now.setReservationNo(time(NULL));

	cout << endl;

	now.display();
	reservationdatabase.pushback(now);
	availtabledatabase.increase(now.getDate(), timecode, count);
	cout << "\nReservation completed.\n\n";
}