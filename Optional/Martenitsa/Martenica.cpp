#include "Martenica.h"

void Martenica::copy(const char* _name,const char* _wish,unsigned _lenght,unsigned _beads)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	wish = new char[strlen(_wish) + 1];
	strcpy(wish, _wish);
	lenght = _lenght;
	beads = _beads;
}
void Martenica::setName(const char* _name)
{
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}
void Martenica::setWish(const char* _wish)
{
	delete[] wish;
	wish = new char[strlen(_wish) + 1];
	strcpy(wish, _wish);
}
void Martenica::del()
{
	delete[] name;
	delete[] wish;
}
/*
Martenica::Martenica()
{
	char buffer[MAX_SIZE];
	cin.getline(buffer, MAX_SIZE);
	name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);
	cin.getline(buffer, MAX_SIZE);
	wish = new char[strlen(buffer) + 1];
	strcpy(wish, buffer);
	cin >> lenght >> beads;
}
*/
Martenica::Martenica(const char* name, const char* wish, unsigned lenght, unsigned beads)
{
	copy(name, wish, lenght, beads);
}
Martenica::Martenica(const Martenica& other)
{
	copy(other.name,other.wish,other.lenght,other.beads);
}
Martenica::~Martenica()
{
	del();
}
Martenica& Martenica::operator=(const Martenica& other)
{
	if (this != &other)
	{
		del();
		copy(other.name,other.wish,other.lenght,other.beads);
	}
	return *this;
}
void Martenica::print() const
{
	cout << name << " " << wish << " " << lenght << " " << beads << endl;
}
MartenicaContainer::MartenicaContainer(unsigned _size)
{
	size = _size;
}
/*
void MartenicaContainer::init()
{
	for (unsigned i = 0; i < size; i++)
	{
		Martenica p;
		martenici[i] = p;
	}
}
*/
void MartenicaContainer::addObject(const Martenica& other,unsigned index)
{
	if (index >= size || index < 0)
		return;
	if (other.getLenght() == 0)
		return;
	martenici[index] = other;
}
void MartenicaContainer::print() const
{
	for (int i = 0; i < size; i++)
		martenici[i].print();
}
void MartenicaContainer::getBestMartenica() const
{
	Martenica bestMartenitsa = martenici[0];
	for (int i = 1; i < size; i++)
	{
		if (martenici[i].getLenght() > bestMartenitsa.getLenght())
		{
			bestMartenitsa = martenici[i];
		}
		if (martenici[i].getLenght() == bestMartenitsa.getLenght())
		{
			if (martenici[i].getBeads() > bestMartenitsa.getBeads())
			{
				bestMartenitsa = martenici[i];
			}
		}
	}
	cout << " top martenicata e : " << endl;
	bestMartenitsa.print();
}
void MartenicaContainer::copy(unsigned i,unsigned j)
{
	Martenica p = martenici[i];
	martenici[i] = martenici[j];
	martenici[j] = p;
}
void MartenicaContainer::bubbleSort()
{
	bool changed = false;
	unsigned sorted = 0;
	do
	{
		changed = false;
		for (unsigned i = size - 1; i > sorted; i--)
		{
			if (martenici[i].getLenght() > martenici[i - 1].getLenght())
			{
				copy(i, i - 1);
				changed = true;
			}
			if (martenici[i].getLenght() == martenici[i - 1].getLenght())
			{
				if (martenici[i].getBeads() > martenici[i - 1].getBeads())
				{
					copy(i, i - 1);
					changed = true;
				}
			}
		}
		sorted++;
	} while (changed);
}
char MartenicaGeneterator::getrandChar()
{
	char c = 'A' + rand() % 24;
	return c;
}
void MartenicaGeneterator::randString(unsigned index)
{
	unsigned lenofName = rand() % 10;
	char buffer[MAX];
	int i;
	for (i = 0; i < lenofName; i++)
	{
		buffer[i] = getrandChar();
	}
	buffer[i] = '\0';
	martenica[index].setName(buffer);
}
void MartenicaGeneterator::randWish(unsigned index)
{
	unsigned lenofWish = rand() % 10;
	char buffer[MAX];
	int i;
	for (i = 0; i < lenofWish; i++)
	{
		buffer[i] = getrandChar();
	}
	buffer[i] = '\0';
	martenica[index].setWish(buffer);
}
MartenicaGeneterator::MartenicaGeneterator(unsigned _size)
{
	size = _size;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		martenica[i].setLenght(rand() % 30);
		martenica[i].setBeads(rand() % 30);
		randString(i);
		randWish(i);
	}
}
void MartenicaGeneterator::print() const
{
	for (int i = 0; i < size; i++)
		martenica[i].print();
}