#include "DealerShip.h"

int main()
{
	Engine ed(200, 200, PETROL);
	VisualDetails vd(5, true, "chernooo");
	ManufacturerDetails md("name", "model", 2020);
	Car car(ed, vd, md, 200, true);
	Engine e(200, 200, PETROL);
	VisualDetails v(5, true, "chernooo");
	ManufacturerDetails m("name", "model", 2020);
	Car car1(e, v, m, 2000000, true);
	DealerShip d(2);
	d.addObject(car);
	d.addObject(car1);
	Car c = d.mostExpensiveCar();
	c.print();
	//d.print();
	return 0;
}