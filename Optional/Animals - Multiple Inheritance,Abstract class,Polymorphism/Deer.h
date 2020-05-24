#pragma once
#include "ForestAnimal.h"
#include "HerbivorousAnimal.h"
class Deer : public ForestAnimal, public HerbivorousAnimal
{
public : 
	Deer(String = "", double = 0, int = 0, int = 0);
	Animal* clone();
	int getCoef() const;
	void print() const;
};

