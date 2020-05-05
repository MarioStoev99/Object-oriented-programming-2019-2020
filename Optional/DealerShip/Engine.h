#include <iostream>
using namespace std;
#pragma once
enum typeofEngine{UNKNOWN = -1,PETROL,DIESEL,HYBRID,ELECTRIC,INVALID};
class Engine
{
private :
	unsigned horsePower;
	unsigned weight;
	typeofEngine type;
public:
	Engine(unsigned = 100,unsigned = 100,typeofEngine = DIESEL);
	Engine();
	void printEngine() const;
	void setEngine(unsigned,unsigned,typeofEngine);
};

