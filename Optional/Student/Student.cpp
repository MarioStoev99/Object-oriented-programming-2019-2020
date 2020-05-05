#include <iostream>
#include "Student.h"
#include <string.h>

using namespace std;

Student::Student()
{
	facultyNumber = 45536;
	strcpy(this->name, "Mario");
	strcpy(this->major, "Informatics");
	group = 1;
}
bool isValid(int number)
{
	unsigned cnt = 0;
	while (number != 0)
	{
		cnt++;
		number /= 10;
	}
	if (cnt != 5)
		return false;
	return true;
}
bool isValidMajor(const char* major)
{
	const char* constMajors[5] = { "Informatics","Computer Science","Software Engineering",
							"Mathematics and Informatics","Mathematics" };
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(major, constMajors[i]) == 0)
			return true;
	}
	return false;
}
Student::Student(unsigned _facultyNumber, char* _name, char* _major, int _group)
{
	if (isValid(_facultyNumber))
	{
		facultyNumber = _facultyNumber;
	}
	else
		facultyNumber = 0;

	strcpy(name, _name);
	if (isValidMajor(_major))
	{
		strcpy(major, _major);
	}
	else
		strcpy(major, "Major Not Chosen");
	if (group >= 1 && group <= 8)
		group = _group;
	else
		group = 0;
}
void Student::setMajor(char* newMajor) { strcpy(major, newMajor); }
void Student::setGroup(int newGroup) { group = newGroup; }
void Student::print() const
{
	cout << getfacultyNumber() << " " << getName() << " "
		<< getMajor() << " " << getGroup() << endl;
}
void Student::readfromConsole()
{
	do
	{
		cout << "Vuvedete fn : ";
		cin >> facultyNumber;
	} while (!isValid(facultyNumber));
	cout << "Vuvedete ime : ";
	cin.get();
	cin.getline(name, 51);
	do
	{
		cout << "Vuvedete specialnost";
		cin.getline(major, 31);
	} while (!isValidMajor(major));
	cout << "vuvedete grupa : ";
	cin >> group;
}
StudentList::StudentList(unsigned cap)
{
	for (int i = 0; i < size; i++)
	{
		this -> students[i] = students[i];
		this->cap = cap;
	}
}
StudentList::StudentList(const StudentList& other)
{

}
StudentList::~StudentList()
{
	delete[] students;
}
void StudentList::addStudent(const StudentList& s)
{
	if (cap < size)
	{
		students[size++] = s;
	}
}