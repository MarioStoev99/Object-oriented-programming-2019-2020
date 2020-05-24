#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Animal
{
protected : 
	String name;
	double coef;
public : 
	Animal(const String = "", double = 0);
	virtual ~Animal() = default;

	virtual Animal* clone() = 0;
	virtual int getCoef() const = 0;
	virtual void print() const = 0;
};

