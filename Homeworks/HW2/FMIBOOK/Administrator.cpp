#include "Administrator.h"

Administrator::Administrator(String _name,int _age) : Moderator(_name,_age)
{}
User* Administrator::clone()
{
	return new Administrator(*this);
}