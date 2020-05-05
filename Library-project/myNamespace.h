#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace myNameSpace
{
	bool isDigit(char c);
	void initAccount(string& username, string& password);
	void initFileName(string& buffer);
	bool hasSpace(string temp);
	void readNickAndPassFromFile(ifstream& file, string& username, string& password);
	bool isExistAccountinFile(ifstream& file, const string username, const string password);
	bool isValidOptionAdd(string& buffer, const string temp);
	bool isValidOptionRemove(string& buffer, const string temp);
	bool isValidOperation(string& buffer, string temp);
	void checkAdminPasswordAndUsername(bool& isLogin);
}

