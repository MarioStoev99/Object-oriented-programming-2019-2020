#include "HerbivorousAnimal.h"

HerbivorousAnimal::HerbivorousAnimal(String _name, double _coef, int _typeofGrass) 
	: Animal(_name,_coef) , typeofGrass(_typeofGrass)
{}