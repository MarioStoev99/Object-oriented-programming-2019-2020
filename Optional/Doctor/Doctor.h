#pragma once
class Date
{
private :
	unsigned day;
	unsigned month;
	unsigned year;
public :
	Date();
	Date(unsigned, unsigned, unsigned);
	void print() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(unsigned);
	void setMonth(unsigned);
	void setYear(unsigned);
};
class Person
{
private :
	char name[24];
	Date date;
	unsigned visitedCount;
public :
	Person();
	Person(const char*,Date ,unsigned);
	const char* getName() const;
	Date getDate() const;
	unsigned getVisitedCount() const;
	void printPerson() const;
};
class Doctor
{
private :
	char doctorName[25];
	Person persons[50];
	unsigned registeredPersons;
public :
	Doctor(const char*,unsigned);
	void registeredPerson(Person&,unsigned);
	void print() const;
	int average() const;
	void printUpper(unsigned) const;
};

