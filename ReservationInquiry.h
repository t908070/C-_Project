#pragma once
#include<iostream>
#include<string>
#include"ReservationDatabase.h"
#include"AvailTableDatabase.h"

using namespace std;

class ReservationInquiry {
	ReservationDatabase& reservationDatabase;
	AvailTableDatabase& availTableDatabase;
public:
	ReservationInquiry(ReservationDatabase& reservationDatabase, AvailTableDatabase& availTableDatabase);
	~ReservationInquiry();
	void excute();
};