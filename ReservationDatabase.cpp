#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"ReservationDatabase.h"

using namespace std;

ReservationDatabase::ReservationDatabase() {
	ifstream inFile("Reservations.dat", ios::in | ios::binary);
	if (!inFile) {
		cout << "File could not be opened.\n";
		system("pause");
		exit(1);
	}
	inFile.seekg(0, ios::end);
	int count = inFile.tellg() / sizeof(Reservation);
	inFile.seekg(0, ios::beg);
	Reservation temp;
	for (int i = 0; i < count; i++) {
		inFile.read(reinterpret_cast<char*>(&temp), sizeof(Reservation));
		reservation.push_back(temp);
	}
	inFile.close();
}

ReservationDatabase::~ReservationDatabase() {
	ofstream outFile("Reservations.dat", ios::out | ios::binary);
	if (!outFile) {
		cout << "File could not be opened!\n";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < reservation.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&reservation[i]), sizeof(Reservation));
	outFile.close();
}
void ReservationDatabase::pushback(Reservation source) {
	reservation.push_back(source);
}
void  ReservationDatabase::cancel(int Num, string password) {
	bool complete = 0;
	for (int i = 0; i < reservation.size(); i++) {
		if (reservation[i].getReservationNo() == Num && reservation[i].getPassword() == password) {
			reservation.erase(reservation.begin() + i);
			complete = 1;
			break;
		}
	}
	if (!complete) {
		cout << "\nThe reservation could not be found.\n\n";
	}
	else
		cout << "\nThis reservation has been cancelled.\n\n";
}
Reservation ReservationDatabase::search(int Num, string password, bool& found) {
	for (int i = 0; i < reservation.size(); i++) {
		if (reservation[i].getReservationNo() == Num && reservation[i].getPassword() == password) {
			reservation[i].display();
			found = 1;
			return reservation[i];
		}
	}
}
bool ReservationDatabase::empty() {
	return (reservation.empty());
}