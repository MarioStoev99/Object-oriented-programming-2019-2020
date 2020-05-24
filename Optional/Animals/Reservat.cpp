#include "Reservat.h"
void Reservat::copy(const Reservat& other)
{
	animals = new Animal * [cap];
	for (int i = 0; i < size; i++)
		animals[i] = other.animals[i]->clone();
	size = other.size;
	cap = other.cap;
}
void Reservat::del()
{
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}
	delete[] animals;
}
void Reservat::resize()
{
	Animal** newAnimals = new Animal * [cap * 2];
	for (int i = 0; i < size; i++)
		newAnimals[i] = animals[i];
	delete[] animals;
	animals = newAnimals;
	cap *= 2;
}
Reservat::Reservat() : cap(2),size(0)
{
	animals = new Animal * [cap];
}
Reservat::Reservat(const Reservat& other)
{
	copy(other);
}
Reservat& Reservat::operator=(const Reservat& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
Reservat::~Reservat()
{
	del();
}
void Reservat::addAnimal(Animal* animal)
{
	if (size >= cap)
		resize();
	animals[size++] = animal;
}
void Reservat::bubbleSort()
{
	bool changed = false;
	unsigned sorted = 0;
	do
	{
		changed = false;
		for (unsigned i = size - 1; i > sorted; i--)
		{
			if (animals[i]->getCoef() > animals[i - 1]->getCoef())
			{
				swap(animals[i], animals[i - 1]);
				changed = true;
			}
			sorted++;
		}
	} while (changed);
}
void Reservat::printTheBestFive() 
{
	bubbleSort();
	for (int i = 0; i < size && i < 5; i++)
	{
		animals[i]->print();
	}
}