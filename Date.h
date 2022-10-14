#pragma once
#include<ostream>

using std::ostream;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void operator++();
	Date operator+(int count);
	bool operator==(Date right);
	bool leapYear();
private:
	int year;
	int month;
	int day;
};