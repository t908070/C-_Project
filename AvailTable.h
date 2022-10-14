#pragma once
#include"Date.h"
class AvailTable {
public:
	AvailTable();
	AvailTable(Date& right);
	bool is_avail(int count);
	bool timeis_avail(int time);
	void increase(int time, int count);
	void decrease(int time, int count);
	Date getdate();
	void displayAvail(int count);

private:
	Date date;
	int numAvailTables[4][6];
	int type[13] = { 0,1,1,2,2,3,4,4,0,0,5,5,5 };
	char times[4][8] = { "", "11:30", "14:30", "17:30" };
};