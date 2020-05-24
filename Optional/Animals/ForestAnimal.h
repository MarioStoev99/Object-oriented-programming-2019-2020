#pragma once
#include "Animal.h"
class ForestAnimal : virtual public Animal
{
protected : 
	int altitude;
public : 
	ForestAnimal(String = "", double = 0, int = 0);
};

