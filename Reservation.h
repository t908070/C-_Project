#pragma once
#include<string>
#include"Date.h"

using std::string;

class Reservation {
	char name[8];
	char mobileNumber[8];
	char emailAddress[8];
	char password[8];
	Date date;
	char time[8];
	int customers;
	int reservationNo;
	int timecode;
public:
	Reservation();
	~Reservation();
	void setName(string source);
	void setMobileNumber(string source);
	void setEmailAddress(string source);
	void setPassword(string source);
	void setDate(Date source);
	void setTime(int code);
	void setCustomers(int count);
	void setReservationNo(int no);
	void setTimecode(int source);
	int getReservationNo();
	string getPassword();
	Date getDate();
	int getTimecode();
	int getCustomers();
	void display();
};