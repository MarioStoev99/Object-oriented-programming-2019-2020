#pragma once
#include "Animal.h"
class HerbivorousAnimal : virtual public Animal
{
protected : 
	int typeofGrass;
public : 
	HerbivorousAnimal(String = "", double = 0, int = 0);
};

