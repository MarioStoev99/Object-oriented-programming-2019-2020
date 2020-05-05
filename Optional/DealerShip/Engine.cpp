#include "Engine.h"

Engine::Engine(unsigned _horsePower, unsigned _weight, typeofEngine _type)
	: horsePower(_horsePower), weight(_weight)
{
	if (_type != PETROL && _type != DIESEL &&
		_type != ELECTRIC && _type != HYBRID)
		type = INVALID;
	else
		type = _type;
}
Engine::Engine() : horsePower(100),weight(100),type(UNKNOWN)
{}
void Engine::printEngine() const
{
	cout << horsePower << " " << weight << " " << type << endl;
}
void Engine::setEngine(unsigned _horsePower,unsigned _weight,typeofEngine _type)
{
	horsePower = _horsePower;
	weight = _weight;
	type = _type;
}