#include <iostream>
#include <cassert>
using namespace std;
const size_t MAX = 1024;
#pragma once
class String
{
private:
	char* str;
	size_t size;

	void del();
	void copy(const String&);
public:
	// big 4
	String(const char* = "");
	String(const String&);
	String& operator=(const String&);
	~String();

	int lenght() const;
	friend ostream& operator<<(ostream&, const String&);
	friend istream& getline(istream&, String&, char);

	String& operator+=(const String&);
	friend String operator+(const String&, const String&);
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	void erase(size_t, unsigned);
	bool empty() const;
	void pop_back();
	char& operator[](size_t);
};
ostream& operator<<(ostream&, const String&);
istream& getline(istream&, String&, char = '\n');
String operator+(const String&, const String&);
int stoi(String);