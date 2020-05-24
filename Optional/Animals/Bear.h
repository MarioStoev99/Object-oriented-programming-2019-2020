#pragma once
#include "PredatorAnimal.h"
#include "ForestAnimal.h"
class Bear : public PredatorAnimal,public ForestAnimal
{
public : 
	Bear(String = "", double = 0, double = 0, int = 0, int = 0);
	Animal* clone();
	int getCoef() const;
	void print() const;
};

