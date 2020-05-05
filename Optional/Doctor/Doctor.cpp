#include "Doctor.h"
#include <iostream>
#include <string.h>
using namespace std;

Date::Date()
{
	day = 11;
	month = 2;
	year = 1999;
}
Date::Date(unsigned _day, unsigned _month, unsigned _year)
{
	day = _day;
	month = _month;
	year = _year;
}
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(unsigned _day) { day = _day; }
void Date::setMonth(unsigned _month) { month = _month; }
void Date::setYear(unsigned _year) { year = _year; }
void Date::print() const
{
	cout << day << "|" << month << "|" << year << endl;
}
const char* Person::getName() const { return name; }
Date Person::getDate() const { return date; }
unsigned Person::getVisitedCount() const { return visitedCount; }
void Person::printPerson() const
{
	cout << name << " " << visitedCount << endl;
	date.print();
}
Person::Person()
{
	strcpy(name, "Mario");
	Date();
	visitedCount = 4;
}
Person::Person(const char* _name,Date _date, unsigned _visitedCount)
{
	strcpy(name, _name);
	date = _date;
	visitedCount = _visitedCount;
}
Doctor::Doctor(const char* _doctorName,unsigned _registeredPersons)
{
	strcpy(doctorName, _doctorName);
	registeredPersons = _registeredPersons;
}
void Doctor::registeredPerson(Person& person,unsigned index)
{
	if (index < 0 || index > registeredPersons)
		return;
	persons[index++] = person;
}
void Doctor::print() const
{
	for (int i = 0; i < registeredPersons; i++)
	{
		persons[i].printPerson();
	}
}
int Doctor::average() const
{
	int sum = 0;
	for (int i = 0; i < registeredPersons; i++)
	{
		sum += persons[i].getVisitedCount();
	}
	return sum / registeredPersons;
}
void Doctor::printUpper(unsigned number) const
{
	for (int i = 0; i < registeredPersons; i++)
	{
		if (persons[i].getVisitedCount() > number)
		{
			persons[i].printPerson();
		}
	}
}
