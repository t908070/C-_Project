#include<iostream>
#include<iomanip>
#include<ctime>
#include"Date.h"

using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() {
	int second = time(NULL);

	int secondPerYear = 24 * 60 * 60 * 365;

	year = 1970;

	while (second > secondPerYear) {
		if (leapYear())
			secondPerYear += 24 * 60 * 60;
		else
			secondPerYear = 24 * 60 * 60 * 365;
		second -= secondPerYear;
		year++;
	}

	if (leapYear())
		days[2]++;

	month = 1;
	
	int secondPerMonth = 24 * 60 * 60 * days[month];

	while (second > secondPerMonth) {
		second -= secondPerMonth; 
		month++;
		secondPerMonth = 24 * 60 * 60 * days[month];
	}

	int secondPerDay = 24 * 60 * 60;

	day = 1;

	while (second > secondPerDay) {
		second -= secondPerDay;
		day++;
	}
	day++;
}

int Date::getYear() const { return year; }

int Date::getMonth() const { return month; }

int Date::getDay() const { return day; }

void Date::operator++() {
	if (day == days[month]) {
		day = 1;
		if (month == 12) {
			month = 1;
			year++;
		}
		else
			month++;
	}
	else
		day++;
}

bool Date::leapYear() {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& output, const Date& d)
{
	output << setw(4) << d.year << "/" << setfill('0') << setw(2) << d.month
		<< '/' << setw(2) << d.day;

	return output;
}

Date Date::operator+(int count) {
	day += count;
	while (day > days[month]) {
		day -= days[month];
		if (month == 12) {
			year++;
			month = 1;
		}
		else
			month++;
	}
	return *this;
}

bool Date::operator==(Date right) {
	return (year == right.getYear() && month == right.getMonth() && day == right.getDay());
}