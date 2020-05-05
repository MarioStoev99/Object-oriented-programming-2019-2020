#include "namespace.h"
bool functions::isValidOption(const char* temp,unsigned& index,const char* regOrChallenge)
{
	int i;
	for (i = 0; temp[i] != ' ' && temp[i] != '\0'; i++)
	{
		if (temp[i+index] != regOrChallenge[i])
			return false;
	}
	index = i + 1;
	if (temp[index - 1] == '\0')
		return false;
	return true;
}
void functions::eraseWord(const char* temp, char* name,unsigned& index)
{
	int i;
	int j = 0;
	for (i = index; temp[i] != ' ' && temp[i] != '\0'; i++)
	{
		name[j++] = temp[i];
	}
	name[j] = '\0';
	index = i + 1;
}
void functions::charToInt(const char* temp,int& age,unsigned& index)
{
	age = 0;
	int i;
	for (i = index; temp[i] != ' ' && temp[i] != '\0'; i++)
	{
		age = age*10 + temp[i] - '0';
	}
	index = i + 1;
}
bool functions::isDigit(char c)
{
	return c >= '0' && c <= '9' || c == '-';
}
TypeSorts functions::getType(const char* type)
{
	if (strcmp(type, "newest") == 0)
		return TypeSorts::newest;
	else if (strcmp(type, "oldest") == 0)
		return TypeSorts::oldest;
	else if (strcmp(type, "most_popular") == 0)
		return TypeSorts::most_popular;
	else
		return TypeSorts::UNKNOWN;
}
