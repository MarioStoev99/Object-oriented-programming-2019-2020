#include "Deer.h"

Deer::Deer(String _name, double _coef, int _altitude, int _typeofGrass)
	: Animal(_name,_coef),
	  ForestAnimal(_name,_coef,_altitude),
	  HerbivorousAnimal(_name,_coef,_typeofGrass)
{}
Animal* Deer::clone()
{
	return new Deer(*this);
}
int Deer::getCoef() const
{
	return typeofGrass / altitude;
}
void Deer::print() const
{
	cout << name << " " << coef << " " << altitude << " " << typeofGrass << endl;
}