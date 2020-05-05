#include "Car.h"
#pragma once
class DealerShip
{
private :
	Car* cars = nullptr;
	unsigned cap;
	unsigned size;
	void copy(const DealerShip&);
	void del();
	void resize();
public :
	DealerShip(unsigned);
	DealerShip(const DealerShip&);
	DealerShip& operator=(const DealerShip&);
	~DealerShip();
	void print() const;
	void addObject(const Car&);
	Car mostExpensiveCar();
};
