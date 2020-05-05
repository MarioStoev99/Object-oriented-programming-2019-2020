#include "User.h"

void User::copy(const char* _name, const char* _email, int _age)
{
	if (_name == nullptr)
		throw logic_error("name == nullptr??");
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	if (_age > 90 || _age < 0)
		throw logic_error("Invalid age");
	age = _age;
	unsigned emailLen = strlen(_email);
	if (emailLen > 100)
		throw logic_error("The lenght of characters in email is > 100 symbols");
	strcpy(email, _email);
	id = rand() % RAND_MAX;
}
void User::del()
{
	delete[] name;
}
User::User(const char* name,const char* email,int age)
	: challengesSize(0)
{
	copy(name,email,age);
}
User::User(const User& other)
{
	if (this != &other)
	{
		copy(other.name, other.email, other.age);
	}
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		del();
		copy(other.name, other.email, other.age);
	}
	return *this;
}
User::~User()
{
	del();
}
ostream& operator<<(ostream& o, const User& user)
{
	o << user.id << " " << user.name << " " << user.email << " ";
	if (user.age == 0)
		o << "UNKNOWN" << endl;
	else
		o << user.age << endl;
	return o;
}
void User::printChallenges() const
{
	cout << "challenges : " << endl;
	for (int i = 0; i < challengesSize; i++)
	{
		cout << i << ")" << challenges[i] << endl;
	}
}
bool User::isExistinChallengeList(const char* challenge) const
{
	for (int i = 0; i < challengesSize; i++)
	{
		if (strcmp(challenges[i].getChallengeName(), challenge) == 0)
			return true;
	}
	return false;
}
void User::removeChallengeFromUserList(const char* challenge)
{
	for (int i = 0; i < challengesSize; i++)
	{
		if (strcmp(challenges[i].getChallengeName(), challenge) == 0)
		{
			swap(challenges[i], challenges[challengesSize - 1]);
			challengesSize--;
			return;
		}
	}
}
void User::setChallengeList(const char* _challenge)
{
	challenges[challengesSize++] = _challenge; 
}
void User::setName(const char* _name)
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}
void User::setEmail(const char* _email)
{
	unsigned len = strlen(_email);
	strncpy(email, _email, len);
	email[len] = '\0';
}