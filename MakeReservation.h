#pragma once
#include"ReservationDatabase.h"
#include"AvailTableDatabase.h"

class MakeReservation {
	ReservationDatabase& reservationdatabase;
	AvailTableDatabase& availtabledatabase;
public:
	MakeReservation(ReservationDatabase& reservationdatabase, AvailTableDatabase& availtabledatabase);
	~MakeReservation();
	void excute();
};