#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <fstream>
#include "myNamespace.h"
#include "User.h"
using namespace std;
class UsersHandling
{
private : 
	User* users = nullptr;
	size_t size;
	size_t cap;

	void copy(const UsersHandling&);
	void clear();
	void resize();
	void deserialize();
	void serialize() const;
	void print() const;
public : 
	void removeUser(const string);
	void addUsers(string buffer) const;
	bool isRegisteredinSystem(string username, string password) const;
	void eraseUsernameAndPass(string& username, string& password) const;
	void putinFile(string username, string password) const;

	UsersHandling();
	UsersHandling(const UsersHandling&);
	UsersHandling& operator=(const UsersHandling&);
	~UsersHandling();
};

