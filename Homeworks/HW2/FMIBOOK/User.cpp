#include "User.h"

User::User(const String _name, int _age)
{
	name = _name;
	if (_age <= 0)
		throw exception("invalid age");
	age = _age;
	isBlocked = 0;
	posts = 0;
}
ostream& operator<<(ostream& out, const User& u)
{
	return out << u.name << " " << u.age << endl;
}
User* User::clone()
{
	return new User(*this);
}