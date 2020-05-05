#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class User
{
private : 
	string userName;
	string password;
	bool isAdministrator;
public :
	User(const string = "", const string = "", bool = false);
	void print() const;
	const string getName() const { return userName; }
	const string getPassword() const { return password; }
	void setName(string _userName) { userName = _userName;}
	void setPassword(string _password) { password = _password; }
};	



