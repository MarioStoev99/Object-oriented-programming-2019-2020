#pragma once
#include "String.h"
#include <iostream>
using namespace std;
class AdditionalMethods
{
public : 
	
	static String getString(String&);
	static int getAge(String);
	static int countSpaces(String temp);
	static void commandForThreeSpaces(String&,String&, String&, String&, int&);
	static void commandForTwoSpaces(String&,String&, String&, String&);
	static bool isDigit(String);
	static String itos(unsigned);
	static int cntDigit(unsigned);
	static void c_str(char* ,String);
};

