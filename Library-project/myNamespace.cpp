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
	char c;
	unsigned cnt = 0;
	while (true)
	{
		c = _getch();
		if (c == '\r')
			break;
		else if (c == '\b')
		{
			if (cnt > 0)
			{
				cnt--;
				password.pop_back();
				cout << '\b' << " " << '\b';
			}
		}
		else
		{
			cnt++;
			cout << "*";
			password += c;
		}
	}
	cout << endl;
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
			system("cls");
			cout << "invalid admin nickname or password.If you want try again please write 'y',else write 'n'" << endl;
			cin >> c;
			cin.ignore();
			system("cls");
		}
	} while (c == 'y');
}
bool myNameSpace::possibleSorts(string& buffer)
{
	if (buffer.compare(0, 5, "title") == 0)
	{
		buffer.erase(0, 5);
		return true;
	}
	if (buffer.compare(0, 6, "author") == 0)
	{
		buffer.erase(0, 6);
		return true;
	}
	if (buffer.compare(0, 4, "year") == 0)
	{
		buffer.erase(0, 4);
		return true;
	}
	if (buffer.compare(0, 6, "rating") == 0)
	{
		buffer.erase(0, 6);
		return true;
	}
	return false;
}
bool myNameSpace::isDescorAsc(string& buffer)
{
	if (buffer.size() > 5)
		return false;
	if (buffer.size() == 0)
		return true;
	buffer.erase(0, 1);
	if (buffer.compare(0, 4, "desc") == 0)
		return true;
	if (buffer.compare(0, 3, "asc") == 0)
		return true;
	return false;
}
string myNameSpace::booksFindOptions(string& option)
{
	if (option.compare(0, 5, "title") == 0)
	{
		option.erase(0, 6);
		return "title";
	}
	else if (option.compare(0, 6, "author") == 0)
	{
		option.erase(0, 7);
		return "author";
	}
	else if (option.compare(0, 3, "tag") == 0)
	{
		option.erase(0, 3);
		return "tag";
	}
	else
		return "error";
}