#include "DealerShip.h"
void DealerShip::copy(const DealerShip& other)
{
	size = other.size;
	cap = other.cap;
	for (int i = 0; i < other.size; i++)
	{
		cars[i] = other.cars[i];
	}
}
void DealerShip::del()
{
	delete[] cars;
}
DealerShip::DealerShip(unsigned _cap)
{
	size = 0;
	cap = _cap;
	cars = new Car[_cap];
}
DealerShip::DealerShip(const DealerShip& other)
{
	copy(other);
}
DealerShip& DealerShip::operator=(const DealerShip& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
void DealerShip::print() const
{
	for (int i = 0; i < size; i++)
	{
		cars[i].print();
	}
}
DealerShip::~DealerShip()
{
	del();
}
void DealerShip::addObject(const Car& car)
{
	if (size == cap)
		resize();
	cars[size++] = car;
}
void DealerShip::resize()
{
	Car* newa = new Car[cap * 2];
	for (int i = 0; i < size; i++)
		newa[i] = cars[i];
	del();
	cars = newa;
	cap *= 2;
}
Car DealerShip::mostExpensiveCar()
{
	Car c = cars[0];
	for (int i = 0; i < size; i++)
	{
		if (cars[i].getPrice() > c.getPrice())
			c = cars[i];
	}
	return c;
}