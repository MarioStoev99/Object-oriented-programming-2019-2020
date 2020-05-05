#pragma once
class Student
{
private :
	unsigned facultyNumber;
	char name[51];
	char major[33];
	int group;
public :
	Student();
	Student(unsigned,char*,char*,int);
	unsigned getfacultyNumber() const { return facultyNumber; }
	const char* getName() const { return name; }
	const char* getMajor() const { return major; }
	int getGroup() const { return group; }
	void setMajor(char*);
	void setGroup(int);
	void print() const;
	void readfromConsole();
};
bool isValid(int number);
bool isValidMajor(const char* major);

class StudentList
{
private : 
	Student* students = nullptr;
	unsigned cap;
	unsigned size;
public : 
	StudentList(unsigned cap);
	StudentList(const StudentList&);
	StudentList& operator=(const StudentList&);
	~StudentList();
	void addStudent(const Student& student);
};
