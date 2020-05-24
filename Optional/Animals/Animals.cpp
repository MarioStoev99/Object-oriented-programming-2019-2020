#include <iostream>
#include "Reservat.h"
int main()
{
	Reservat r;
	r.addAnimal(new Bear("Pesho", 2, 2, 4, 4));
	r.addAnimal(new Deer("Marko", 3, 5, 7));
	r.addAnimal(new Bear("Gosho", 4, 4, 6, 6));
	r.addAnimal(new Deer("Krasi", 5, 5, 9));
	r.addAnimal(new Bear("Tosho", 3, 5, 2, 4));
	r.printTheBestFive();
	return  0;
}
