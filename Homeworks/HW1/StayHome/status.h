#pragma once
#include <iostream>
using namespace std;
enum class Status
{
	_new,
	quite_recently,
	old 
};

enum class TypeSorts
{
	UNKNOWN = -1,
	newest,
	oldest,
	most_popular
};