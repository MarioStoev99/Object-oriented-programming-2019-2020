#pragma once
#include "String.h"
#include <iostream>
using namespace std;
namespace myNameSpace
{
	String getString(String&);
	int getAge(String);
	int countSpaces(String temp);
	void commandForThreeSpaces(String&,String&, String&, String&, int&);
	void commandForTwoSpaces(String&,String&, String&, String&);
	bool isDigit(String);
};

