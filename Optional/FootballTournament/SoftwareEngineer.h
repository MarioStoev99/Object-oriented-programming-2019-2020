#include <iostream>
#include <string.h>
using namespace std;
#pragma once
enum Position{Unknown = -1,Intern,JuniorDeveloper,MediumDeveloper,
	          SeniorDeveloper,ChiefTechnicalOfficer,
			  ChiefExecutiveOfficer};
class SoftwareEngineer
{
private : 
	char* name;
	Position pos;
	unsigned salary;
	unsigned point;
	void copy(const char*,Position,unsigned,unsigned);
	void del();
public :
	SoftwareEngineer(const char* = " ",Position = Unknown,unsigned = 0,unsigned = 0);
	SoftwareEngineer(const SoftwareEngineer&);
	SoftwareEngineer& operator=(const SoftwareEngineer&);
	~SoftwareEngineer();

	const char* getName() const { return name; }
	unsigned getSalary() const { return salary; }
	unsigned getPoints() const { return point; }
	void setSalary(unsigned _salary) { salary = _salary; }
	void print() const;
	bool isnotValidEngineer() const;
	bool isChiefPlayer() const;
};

