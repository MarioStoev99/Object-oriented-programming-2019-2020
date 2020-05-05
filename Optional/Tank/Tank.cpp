#include "Tank.h"
void Tank::copy(const char* _name, unsigned _shotPower, int _lifePoint)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	shotPower = _shotPower;
	lifePoint = _lifePoint;
}
void Tank::del()
{
	delete[] name;
}
Tank::Tank(const char* name,unsigned shotPower,int lifePoint)
{
	copy(name, shotPower, lifePoint);
}
Tank::Tank(const Tank& other)
{
	copy(other.name, other.shotPower, other.lifePoint);
}
Tank& Tank::operator=(const Tank& other)
{
	if (this != &other)
	{
		del();
		copy(other.name, other.shotPower, other.lifePoint);
	}
	return *this;
}
Tank::~Tank()
{
	del();
}
void Tank::print() const
{
	cout << name << " " << shotPower << " " << lifePoint << endl;
}
Army::Army(unsigned _size)
{
	size = _size;
}
void Army::addTank(const Tank& other,unsigned index)
{
	if (index > CAP || index < 0)
		return;
	tanks[index] = other;
}
void Army::print() const
{
	for (int i = 0; i < size; i++)
	{
		tanks[i].print();
	}
}
void Army::attack(Tank& other)
{
	unsigned totalAttack = 0;
	unsigned maxShots = 0;
	for (int i = 0; i < size; i++)
	{
		totalAttack += tanks[i].getshotPower();
	}
	if (totalAttack < other.getlifePoint())
	{
		cout << "tankyt e prekaleno silen da bie cqlata armiq" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			other.setlifePoint(other.getlifePoint() - tanks[i].getshotPower());
			maxShots++;
			if (other.getlifePoint() < 0) 
				break;
		}
	}
	cout << "tankyt e svalen sys : " << maxShots << " iztrela" << endl;
}
void Army::serialize() const
{
	ofstream file("file.bin", ios::binary);
	if (!file.is_open())
	{
		cout << "file could not found";
		return;
	}
	file.write((const char*)&size, sizeof(unsigned));
	for (int i = 0; i < size; i++)
	{
		if (!file.good())
		{
			cout << "not good" << endl;
			return;
		}
		file.write((const char*)&tanks[i], sizeof(Tank));
	}
	file.close();
}

void Army::deserialize()
{
	unsigned size = 0;
	ifstream file("file.bin", ios::binary);
	if (!file.is_open())
	{
		cout << "not opened file";
		return;
	}
	file.read((char*)&size, sizeof(unsigned));
	for (int i = 0; i < size; i++)
	{
		if (!file.good())
		{
			cout << "im not good";
			return;
		}
		file.read((char*)&tanks[i], sizeof(Tank));
	}
	for (int i = 0; i < size; i++)
	{
		tanks[i].print();
	}
}