#include "User.h"
User::User(const string _userName,const string _password,bool _isAdministrator)
{
	userName = _userName;
	password = _password;
	isAdministrator = _isAdministrator;
}
void User::print() const
{
	cout << userName << " " << password << " " << isAdministrator << endl;
}
