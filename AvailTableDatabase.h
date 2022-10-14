#pragma once
#include<vector>
#include"AvailTable.h"
using namespace std;
class AvailTableDatabase {
public:
	AvailTableDatabase();
	~AvailTableDatabase();
	void push_back(AvailTable val);
	void increase(Date date, int time, int count);
	void decrease(Date date, int time, int count);
	bool dayAvail(Date date, int count);
	void displaytime(int count, int time);
	Date getdate(int code);
private:
	vector<AvailTable> availtable;
};