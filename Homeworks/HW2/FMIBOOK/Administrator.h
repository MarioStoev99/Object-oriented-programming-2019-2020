#pragma once
#include "Moderator.h"

class Administrator : public Moderator
{
public : 
	Administrator(String = "", int = 1);
	User* clone();
};

