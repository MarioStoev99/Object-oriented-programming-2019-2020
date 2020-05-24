#include "PredatorAnimal.h"

PredatorAnimal::PredatorAnimal(String _name, double _coef, double _biteForce, int _speed)
	: Animal(_name,_coef),biteForce(_biteForce),speed(_speed)
{}