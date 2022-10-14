#pragma once
#include<vector>
#include<string>
#include"Reservation.h"

using namespace std;

class ReservationDatabase {
	vector<Reservation> reservation;
public:
	ReservationDatabase();
	~ReservationDatabase();
	void pushback(Reservation source);
	Reservation search(int no, string password, bool &found);
	void cancel(int no, string password);
	bool empty();
};