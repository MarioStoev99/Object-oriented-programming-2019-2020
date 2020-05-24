#pragma once
#include "Animal.h"
class PredatorAnimal : virtual public Animal
{
protected : 
	double biteForce;
	int speed;
public : 
	PredatorAnimal(String = "", double = 0,double = 0, int = 0);
};

