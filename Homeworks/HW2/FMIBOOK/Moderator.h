#pragma once
#include "User.h"
class Moderator : public User
{
public : 
	Moderator(String = "", int = 1);
	void setBlockFlag(bool flag) { isBlocked = flag; }
	User* clone();
};