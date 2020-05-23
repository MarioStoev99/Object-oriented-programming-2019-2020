#include "myNameSpace.h"

String AdditionalMethods::getString(String& command)
{
	String temp = command;
	unsigned cnt = 0;
	for (int i = 0; temp[i] != ' ' && i < temp.lenght(); i++)
		cnt++;
	command.erase(0, cnt);
	temp.erase(cnt, temp.lenght() - cnt);
	return temp;
}
bool AdditionalMethods::isDigit(String s)
{
	for (int i = 0; i < s.lenght(); i++)
	{
		if (s[0] < '0' || s[0] > '9')
			return false;
	}
	return true;
}
int AdditionalMethods::getAge(String s)
{
	if (!isDigit(s))
		return -1;
	int age = stoi(s);
	if (age < 0)
		throw exception("invalid age");
	return age;
}
int AdditionalMethods::countSpaces(String temp)
{
	int cnt = 0;
	for (int i = 0; i < temp.lenght() - 1; i++)
	{
		if (temp[i] == ' ')
			cnt++;
	}
	return cnt;
}
void AdditionalMethods::commandForThreeSpaces(String& command,String& actor, String& action, String& subject, int& age)
{
	actor = AdditionalMethods::getString(command);
	command.erase(0, 1);
	action = AdditionalMethods::getString(command);
	command.erase(0, 1);
	subject = AdditionalMethods::getString(command);
	command.erase(0, 1);
	age = AdditionalMethods::getAge(command);
}
void AdditionalMethods::commandForTwoSpaces(String& command,String& actor, String& action, String& subject)
{
	actor = AdditionalMethods::getString(command);
	command.erase(0, 1);
	action = AdditionalMethods::getString(command);
	command.erase(0, 1);
	subject = AdditionalMethods::getString(command);
}
int AdditionalMethods::cntDigit(unsigned number)
{
	int cnt = 0;
	while (number)
	{
		cnt++;
		number /= 10;
	}
	return cnt;
}
String AdditionalMethods::itos(unsigned number)
{
	int cnt = cntDigit(number);
	String temp;
	temp.resize(cnt);
	for (int i = cnt - 1; i >= 0; i--)
	{
		temp[i] = (number % 10) + '0';
		number /= 10;
	}
	return temp;
}
void AdditionalMethods::c_str(char* temp,String filepath)
{
	int i;
	for (i = 0; i < filepath.lenght(); i++)
	{
		temp[i] = filepath[i];
	}
	temp[i] = '\0';
}