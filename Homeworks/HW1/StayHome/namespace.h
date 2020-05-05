#pragma once
#include <iostream>
#include <string.h>
#include "status.h"
using namespace std;
const size_t MAX_SIZE = 1024;
namespace functions
{
	bool isValidOption(const char*, unsigned&, const char*);
	void eraseWord(const char*, char*, unsigned&);
	bool isDigit(char c);
	void charToInt(const char*, int&, unsigned&);
	TypeSorts getType(const char*);
}