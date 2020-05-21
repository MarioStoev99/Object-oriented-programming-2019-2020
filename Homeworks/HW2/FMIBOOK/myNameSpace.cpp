#include "myNameSpace.h"
String myNameSpace::getString(String& command)
{
	String temp = command;
	unsigned cnt = 0;
	for (int i = 0; temp[i] != ' ' && i < temp.lenght(); i++)
		cnt++;
	command.erase(0, cnt);
	temp.erase(cnt, temp.lenght() - cnt);
	return temp;
}
bool myNameSpace::isDigit(String s)
{
	for (int i = 0; i < s.lenght(); i++)
	{
		if (s[0] < '0' || s[0] > '9')
			return false;
	}
	return true;
}
int myNameSpace::getAge(String s)
{
	if (!isDigit(s))
		return -1;
	int age = stoi(s);
	if (age < 0)
		throw exception("invalid age");
	return age;
}
int myNameSpace::countSpaces(String temp)
{
	int cnt = 0;
	for (int i = 0; i < temp.lenght() - 1; i++)
	{
		if (temp[i] == ' ')
			cnt++;
	}
	return cnt;
}
void myNameSpace::commandForThreeSpaces(String& command,String& actor, String& action, String& subject, int& age)
{
	actor = myNameSpace::getString(command);
	command.erase(0, 1);
	action = myNameSpace::getString(command);
	command.erase(0, 1);
	subject = myNameSpace::getString(command);
	command.erase(0, 1);
	age = myNameSpace::getAge(command);
}
void myNameSpace::commandForTwoSpaces(String& command,String& actor, String& action, String& subject)
{
	actor = myNameSpace::getString(command);
	command.erase(0, 1);
	action = myNameSpace::getString(command);
	command.erase(0, 1);
	subject = myNameSpace::getString(command);
}