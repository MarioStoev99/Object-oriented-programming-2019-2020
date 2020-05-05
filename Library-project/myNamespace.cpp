#include "myNameSpace.h"

bool myNameSpace::isDigit(char c)
{
	return 	c >= '0' && c <= '9';
}
void myNameSpace::initAccount(string& username, string& password)
{
	cout << "Username : ";
	getline(cin, username);
	cout << "Password : ";
	getline(cin, password);
}
void myNameSpace::initFileName(string& buffer)
{
	getline(cin, buffer);
	buffer.append(".txt");
}
bool myNameSpace::hasSpace(string temp)
{
	for (int i = 1; i < temp.size() - 1; i++)
	{
		if (temp[i] == ' ')
			return true;
	}
	return false;
}
void myNameSpace::readNickAndPassFromFile(ifstream& file, string& username, string& password)
{
	getline(file, username, ' ');
	getline(file, password);
}
bool myNameSpace::isExistAccountinFile(ifstream& file, const string username, const string password)
{
	string usernameFromFile;
	string passwordFromFile;
	readNickAndPassFromFile(file, usernameFromFile, passwordFromFile);
	if (usernameFromFile == username && passwordFromFile == password)
		return true;
	else
		return false;
}
bool myNameSpace::isValidOptionAdd(string& buffer, const string temp)
{
	if (buffer.size() == 10)
		return false;
	if (buffer.compare(0, 10, temp) != 0)
		return false;
	buffer.erase(0, 10);
	return true;
}
bool myNameSpace::isValidOptionRemove(string& buffer, const string temp) 
{
	if (buffer.size() == 13)
		return false;
	if (buffer.compare(0, 13, temp) != 0)
		return false;
	buffer.erase(0, 13);
	return true;
}
bool myNameSpace::isValidOperation(string& buffer, string temp)
{
	if (buffer.compare(0, 11, temp) != 0)
		return false;
	buffer.erase(0, 11);
	return true;
}
void myNameSpace::checkAdminPasswordAndUsername(bool& isLogin)
{
	string adminUsername;
	string adminPass;
	char c;
	do
	{
		cout << "Please enter admin username and password" << endl;
		initAccount(adminUsername, adminPass);
		if (adminUsername == "admin" && adminPass == "i<3c++")
		{
			isLogin = true;
			system("cls");
			break;
		}
		else
		{
			cout << "invalid admin nickname or password.If you want try again please write 'y',else write 'n'" << endl;
			cin >> c;
			cin.ignore();
			system("cls");
		}
	} while (c == 'y');
}