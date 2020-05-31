#include "UsersHandling.h"

void UsersHandling::copy(const UsersHandling& other)
{
	users = new User[other.cap];
	for (int i = 0; i < other.size; i++)
		users[i] = other.users[i];
	size = other.size;
	cap = other.cap;
}
void UsersHandling::clear()
{
	delete[] users;
}
void UsersHandling::resize()
{
	User* newUsers = new User[cap * 2];
	for (int i = 0; i < size; i++)
		newUsers[i] = users[i];
	clear();
	users = newUsers;
	cap *= 2;
}
UsersHandling::UsersHandling() : size(0), cap(2)
{
	users = new User[cap];
}
UsersHandling::UsersHandling(const UsersHandling& other)
{
	copy(other);
}
UsersHandling& UsersHandling::operator=(const UsersHandling& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
UsersHandling::~UsersHandling()
{
	clear();
}
void UsersHandling::addUsers(string buffer)
{
	bool isLogin = false;
	string username = buffer;
	string password = buffer;
	eraseUsernameAndPass(username, password);
	deserialize();
	if (isRegisteredinSystem(username, password))
	{
		system("cls");
		cout << "This user is already registered in the system." << endl;
	}
	else
	{
		system("cls");
		AuxiliaryMethodsForAllClasses::checkAdminPasswordAndUsername(isLogin);
		system("cls");
		if (isLogin == true)
		{
			cout << "Successfully added nickname and password to list.Please choose an operation : " << endl;
			putinFile(username, password);
		}
		else
			cout << "Choose an operation below!" << endl;
	}
}
bool UsersHandling::isRegisteredinSystem(string username, string password) const
{
	ifstream file("users.txt");
	for(int i = 0;i < size;i++)
	{
		if (users[i].getName() == username && users[i].getPassword() == password)
			return true;
	}
	return false;
}
void UsersHandling::eraseUsernameAndPass(string& username, string& password) const
{
	assert(username[username.size() - 1] != ' ');
	assert(username[0] != ' ');
	assert(AuxiliaryMethodsForAllClasses::hasSpace(username) == true);
	while (username[username.size() - 1] != ' ')
		username.pop_back();
	username.pop_back();
	assert(username[username.size() - 1] != ' ');
	while (password[0] != ' ')
		password.erase(0, 1);
	password.erase(0, 1);
	assert(password[0] != ' ');
}
void UsersHandling::putinFile(string username, string password) const
{
	ofstream file("users.txt");
	if(!file.good())
		throw exception("The stream's not good");
	file << size + 1 << endl;
	for (int i = 0; i < size; i++)
	{
		if (!file.good())
			throw exception("The stream's not good");
		file << users[i].getName() << " " << users[i].getPassword() << endl;
	}
	file << username << " " << password << endl;
	file.close();
}
void UsersHandling::removeUser(const string removeUser)
{
	bool isLogin = false;
	AuxiliaryMethodsForAllClasses::checkAdminPasswordAndUsername(isLogin);
	if (isLogin)
	{
		deserialize();
		for (int i = 0; i < size; i++)
		{
			if (users[i].getName() == removeUser)
			{
				swap(users[i], users[size - 1]);
				size--;
				cout << "Successfilly you have removed user from list!" << endl;
				serialize();
				return;
			}
		}
	}
	cout << "This user doesn't exist.." << endl;
}
void UsersHandling::deserialize()
{
	string username, password;
	ifstream file("users.txt");
	unsigned len = 0;
	file >> len;
	file.ignore();
	while (len >= cap)
		resize();
	size = len;
	for(int i = 0;i < size;i++)
	{
		if (!file.good())
			throw exception("The stream's not good");
		AuxiliaryMethodsForAllClasses::readNickAndPassFromFile(file, username, password);
		users[i].setName(username);
		users[i].setPassword(password);
	}
}
void UsersHandling::serialize() const
{
	ofstream file("users.txt");
	file << size << endl;
	for (int i = 0; i < size; i++)
		file << users[i].getName() << " " << users[i].getPassword() << endl;
}
void UsersHandling::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << users[i].getName() << " " << users[i].getPassword() << endl;
	}
}