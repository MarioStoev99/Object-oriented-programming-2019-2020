#include <iostream>
#include "String.h"
using namespace std;
#pragma once
class User
{
protected:
	String name;
	int age;
	bool isBlocked;
	unsigned posts;
public:
	User(const String = "", int = 1);
	virtual ~User() = default;

	void setName(String _name) { name = _name; }
	void setBlocked(bool blocked) { isBlocked = blocked; }
	void setPosts() { posts += 1; }
	unsigned getPosts() const { return posts; }
	String getName() const { return name; }
	bool getIsBlocked() const { return isBlocked; }
	int getAge() const { return age; }

	virtual User* clone();
	friend ostream& operator<<(ostream&, const User&);
};
ostream& operator<<(ostream&, const User&);