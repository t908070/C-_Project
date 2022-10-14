#include<fstream>
#include<iostream>
#include"AvailTableDatabase.h"


using namespace std;
AvailTableDatabase::AvailTableDatabase() {
	ifstream inFile("AvailTables.dat", ios::in | ios::binary);
	if (!inFile) {
		cout << "File could not be opened.\n";
		system("pause");
		exit(1);
	}
	inFile.seekg(0, ios::end);
	int count = inFile.tellg() / sizeof(AvailTable);
	inFile.seekg(0, ios::beg);
	AvailTable temp;
	for (int i = 0; i < count; i++) {
		inFile.read(reinterpret_cast<char*>(&temp), sizeof(AvailTable));
		availtable.push_back(temp);
	}
	inFile.close();
}

AvailTableDatabase::~AvailTableDatabase() {
	ofstream outFile("AvailTables.dat", ios::out | ios::binary);
	if (!outFile) {
		cout << "File could not be opened!\n";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < availtable.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&availtable[i]), sizeof(AvailTable));
	outFile.close();
}
void AvailTableDatabase::push_back(AvailTable source) {
	for (int i = 0; i < availtable.size(); i++)
		if (availtable[i].getdate() == source.getdate())
			return;
	availtable.push_back(source);
}
bool AvailTableDatabase::dayAvail(Date date, int count) {
	for (int i = 0; i < availtable.size(); i++) {
		if (availtable[i].getdate() == date) {
			return availtable[i].is_avail(count);
		}
	}
}
void AvailTableDatabase::displaytime(int count, int time) {
	availtable[count].displayAvail(time);
}
void AvailTableDatabase::increase(Date date, int time, int count) {
	for (int i = 0; i < availtable.size(); i++) {
		if (availtable[i].getdate() == date) {
			availtable[i].increase(time, count);
			break;
		}
	}
}
void AvailTableDatabase::decrease(Date date, int timecode, int type) {
	for (int i = 0; i < availtable.size(); i++)
		if (date == availtable[i].getdate()) {
			availtable[i].decrease(timecode, type);
			break;
		}
}
Date AvailTableDatabase::getdate(int code) {
	return availtable[code - 1].getdate();
}