#pragma once
#include "Challenge.h"
#include "stdlib.h"
#include "time.h"
const size_t MAX_CAP = 1000;
const size_t MAX_EMAIL_SIZE = 10000;
class User
{
private :
	char* name;
	int age;
	unsigned id;
	char email[MAX_EMAIL_SIZE];
	size_t challengesSize;
	Challenge challenges[MAX_CAP];
	void copy(const char*, const char*, int);
	void del();
public : 
	User(const char* = "",const char* = "",int = 1);
	User(const User&);
	User& operator=(const User&);
	~User();
	friend ostream& operator<<(ostream&, const User&);
	void setId(unsigned _id) { id = _id;}
	void setName(const char*);
	void setAge(unsigned _age) { age = _age; }
	void setEmail(const char*);
	void setChallengeList(const char*);
	unsigned getId() const { return id; }
	const char* getName() const { return name; }
	const char* getEmail() const { return email; }
	int getAge() const { return age; }
	void printChallenges() const;
	bool isExistinChallengeList(const char*) const;
	void removeChallengeFromUserList(const char*);
};
ostream& operator<<(ostream&, const User&);
