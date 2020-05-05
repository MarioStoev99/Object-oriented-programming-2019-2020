#include "SoftwareEngineer.h"

void SoftwareEngineer::copy(const char* _name, Position _pos, unsigned _salary,unsigned _point)
{
	if (name == nullptr)
	{
		name = new char[1];
		strcpy(name,"");
	}
	else
	{
		name = new char[strlen(name) + 1];
		strcpy(name, _name);
	}
	pos = _pos;
	salary = _salary;
	point = _point;
}
void SoftwareEngineer::del()
{
	delete[] name;
}
SoftwareEngineer::SoftwareEngineer(const char* name, Position pos, unsigned salary,unsigned point)
{
	copy(name, pos, salary,point); 
}
SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other)
{
	copy(other.name, other.pos, other.salary,other.point);
}
SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other)
{
	if (this != &other)
	{
		del();
		copy(other.name, other.pos, other.salary,other.point);
	}
	return *this;
}
SoftwareEngineer::~SoftwareEngineer()
{
	del();
}
void SoftwareEngineer::print() const
{
	cout << "position : ";
	switch (pos)
	{
		case Intern: cout << "Intern" << endl; break;
		case JuniorDeveloper: cout << "JuniorDeveloper" << endl; break;
		case MediumDeveloper: cout << "MediumDeveloper" << endl; break;
		case SeniorDeveloper: cout << "SeniorDeveloper" << endl; break;
		case ChiefTechnicalOfficer: cout << "ChiefTechnicalOfficer" << endl; break;
		case ChiefExecutiveOfficer: cout << "ChiefExecutiveOfficer" << endl; break;
		default:cout << "Unknown" << endl;
	}
	cout << "name : "  << name << endl;
	cout << "salary : " << " " << salary << endl;
}
bool SoftwareEngineer::isnotValidEngineer() const
{
	if (strcmp(name, "") == 0)
	{
		return true;
	}
	if (pos != Intern &&
		pos != JuniorDeveloper &&
		pos != MediumDeveloper &&
		pos != SeniorDeveloper &&
		pos != ChiefTechnicalOfficer &&
		pos != ChiefExecutiveOfficer)
	{
		return true;
	}
	return false;
}
bool SoftwareEngineer::isChiefPlayer() const
{
	return (pos == ChiefTechnicalOfficer) || (pos == ChiefExecutiveOfficer);
}