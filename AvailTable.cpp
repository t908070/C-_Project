#include"AvailTable.h"
#include<iostream>
using namespace std;
AvailTable::AvailTable()
	: date(),
	numAvailTables()
{
}
AvailTable::AvailTable(Date& right) {
	date = right;
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 6; j++)
			numAvailTables[i][j] = 0;
}
void AvailTable::increase(int time, int count) {
	numAvailTables[time][type[count]]++;
}
void AvailTable::decrease(int time, int count) {
	numAvailTables[time][type[count]]--;
}
bool AvailTable::is_avail(int count) {
	for (int i = 1; i < 4; i++) {
		if (numAvailTables[i][type[count]] < 2)
			return true;
	}
	return false;
}
void AvailTable::displayAvail(int count) {
	for (int i = 1; i < 4; i++) {
		if (numAvailTables[i][type[count]] < 2) {
			cout << i << ". " << times[i] << endl;
		}
	}
}
Date AvailTable::getdate() {
	return date;
}