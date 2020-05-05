#include <iostream>
#include <fstream>
using namespace std;

#pragma once
class Tank
{
private :
	char* name;
	unsigned shotPower;
	int lifePoint;
	void copy(const char*,unsigned,int);
	void del();
public :
	Tank(const char* = " ", unsigned = 0, int = 0);
	Tank(const Tank&);
	Tank& operator=(const Tank&);
	~Tank();
	void setName(const char* _name)
	{
		del();
		char* name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	void setshotPower(unsigned _shotPower) { shotPower = _shotPower; }
	void setlifePoint(unsigned _lifePoint) { lifePoint = _lifePoint; }
	const char* getName() const { return name; }
	int getshotPower() const { return shotPower; }
	int getlifePoint() const { return lifePoint; }
	void print() const;
};
class Army
{
private:
	const static unsigned CAP = 20;
	Tank tanks[CAP];
	unsigned size;
public:
	Army(unsigned);
	void addTank(const Tank&,unsigned);
	void print() const;
	void attack(Tank&);
	void serialize() const;
	void deserialize();
};