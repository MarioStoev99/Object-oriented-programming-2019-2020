#include "Moderator.h"
Moderator::Moderator(String _name, int _age) : User(_name, _age)
{}
User* Moderator::clone()
{
	return new Moderator(*this);
}