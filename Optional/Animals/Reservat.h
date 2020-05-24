#include "Animal.h"
#include "Bear.h"
#include "Deer.h"
#pragma once
class Reservat
{
private : 
	Animal** animals = nullptr;
	size_t size;
	size_t cap;

	void copy(const Reservat&);
	void resize();
	void del();

	void bubbleSort();
public : 
	Reservat();
	Reservat(const Reservat&);
	Reservat& operator=(const Reservat&);
	~Reservat();
	void addAnimal(Animal*);
	void printTheBestFive();
};

