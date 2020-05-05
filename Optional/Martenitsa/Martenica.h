#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#pragma once
class Martenica
{
private :
	static unsigned const MAX_SIZE = 1024;
	char* name;
	char* wish;
	unsigned lenght;
	unsigned beads;
	void copy(const char*,const char*,unsigned,unsigned);
	void del();
public :
	Martenica(const char* = " ",const char* = " ",unsigned = 1,unsigned = 1);
	Martenica(const Martenica&);
	Martenica& operator=(const Martenica&);
	~Martenica();
	void setName(const char*);
	void setWish(const char*);
	void setLenght(unsigned _lenght) { lenght = _lenght; }
	void setBeads(unsigned _beads) { beads = _beads; }
	int getLenght() const { return lenght; }
	int getBeads() const { return beads; }
	void print() const;
};
class MartenicaContainer
{
private :
	static const unsigned MAX = 250;
	Martenica martenici[MAX];
	unsigned size;
	void copy(unsigned,unsigned);
public :
	MartenicaContainer(unsigned);
	void addObject(const Martenica&,unsigned index);
	//void init();
	void print() const;
	void getBestMartenica() const;
	void bubbleSort();
};
class MartenicaGeneterator
{
private :
	Martenica martenica[250];
	unsigned size;
	static const unsigned MAX = 1024;
	char getrandChar();
	void randString(unsigned);
	void randWish(unsigned);
public :
	MartenicaGeneterator(unsigned);
	void print() const;
};
