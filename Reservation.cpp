#include<iostream>
#include<iomanip>
#include"Reservation.h"

using namespace std;

extern char times[4][6];

Reservation::Reservation() {}

Reservation::~Reservation() {}

void Reservation::setName(string source) {
	int length = source.size();
	for (int i = 0; i < length; i++)
		name[i] = source[i];
	name[length] = '\0';
}

void Reservation::setMobileNumber(string source) {
	int length = source.size();
	for (int i = 0; i < length; i++)
		mobileNumber[i] = source[i];
	mobileNumber[length] = '\0';
}
void Reservation::setEmailAddress(string source) {
	int length = source.size();
	for (int i = 0; i < length; i++)
		emailAddress[i] = source[i];
	emailAddress[length] = '\0';
}

void Reservation::setPassword(string source) {
	int length = source.size();
	for (int i = 0; i < length; i++)
		password[i] = source[i];
	password[length] = '\0';
}

void Reservation::setDate(Date source) { date = source; }

void Reservation::setTime(int code) { 
	for (int i = 0; i < 5; i++)
		time[i] = times[code][i];
	time[5] = '\0';
}

void Reservation::setCustomers(int count) { customers = count; }

void Reservation::setReservationNo(int no) { reservationNo = no; }

void Reservation::setTimecode(int source) { timecode = source; }

int Reservation::getReservationNo() { return reservationNo; }

string Reservation::getPassword() { return password; }

Date Reservation::getDate() {return date;}

int Reservation::getTimecode() { return timecode; }

int Reservation::getCustomers() { return customers; }

void Reservation::display() {
	cout << " Mobile No.      Name          Date     Time                         Email";
	cout << "    No of Customers    Password    Reservation No.\n ";
	cout << setw(10) << setfill(' ') << mobileNumber << setw(10) << setfill(' ') << name << "    " << date << "    " 
		<< time << setw(30) << setfill(' ') << emailAddress
		<< setw(19) << setfill(' ') << customers << setw(12) << setfill(' ') << password 
		<< setw(19) << setfill(' ') << reservationNo << endl;
}