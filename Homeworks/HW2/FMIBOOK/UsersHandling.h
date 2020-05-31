#include "Administrator.h"
#include "PublicationsHandling.h"

#pragma once
class UsersHandling
{
private : 
	User** users = nullptr;
	size_t cap;
	size_t size;

	void resize();
	void copy(const UsersHandling&);
	void clear(); 

	void printOldestAndYongestPerson() const;
	void printTotalUsers() const;
	void printBlockedUsers() const;
public : 
	// Big 4
	UsersHandling();
	UsersHandling(const UsersHandling&);
	UsersHandling& operator=(const UsersHandling&);
	~UsersHandling();

	void addMember(User*);
	void removeMember(String, int);
	void info() const;
	void blockorUnblock(String, String, bool) const;
	void rename(String, String) const;

	// help functions
	int findPosUserInArray(String) const;
	bool blockUser(size_t) const;
	bool haveRights(size_t,bool) const;
	void increasePersonalPosts(size_t);
};

