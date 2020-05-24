#include "Bear.h"

Bear::Bear(String _name, double _coef, double _biteForce, int _speed, int _altitude)
	: Animal(_name, _coef), PredatorAnimal(_name,_coef,_biteForce,_speed),ForestAnimal(_name,_coef,_altitude)
{}
Animal* Bear::clone()
{
	return new Bear(*this);
}
int Bear::getCoef() const
{
	return (biteForce * speed) / altitude;
}
void Bear::print() const
{
	cout << name << " " << coef << " " << biteForce << " " << speed << " " << altitude << endl;
}