#pragma once
#include "Engine.h"
#include "VisualDetails.h"
#include "ManufacturerDetails.h"
const size_t MAX = 1024;
class Car
{
private :
	Engine engineDetails;
	VisualDetails visualDetails;
	ManufacturerDetails manufacturerDetails;
	unsigned price;
	bool isnewCar;
public :
	Car();
	Car(const Engine&,const VisualDetails&,const ManufacturerDetails&, unsigned, bool);
	void print() const;
	void setCar();
	int getPrice() const { return price; }
};

