#include <iostream>
using namespace std;
#pragma once
class ManufacturerDetails
{
private :
	char* nameofManufactuter;
	char* modelofCar;
	unsigned year;
	void copy(const char*,const char*,unsigned);
	void del();
public :
	ManufacturerDetails(const char* = "",const char* = "",unsigned = 1885);
	ManufacturerDetails();
	ManufacturerDetails(const ManufacturerDetails&);
	ManufacturerDetails& operator=(const ManufacturerDetails&);
	~ManufacturerDetails();
	void printManufacturer() const;
};

