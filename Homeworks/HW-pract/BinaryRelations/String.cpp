#include "String.h"

void String::copy(const String& other)
{
	str = new char[strlen(other.str)];
	for (int i = 0; i < other.size; i++)
		str[i] = other.str[i];
	this->size = other.size;
}
void String::resize(int index)
{
	char* newStr = new char[index];
	for (int i = 0; i < size; i++)
	{
		newStr[i] = str[i];
	}
	delete[] str;
	str = newStr;
	size = index;
}
void String::del()
{
	delete[] str;
}
String::String(const char* _str)
{
	if (_str == nullptr)
	{
		size = 0;
		str = new char[1];
		str[size] = 0;
	}
	size = strlen(_str);
	str = new char[size];
	for (int i = 0; i < size; i++)
		str[i] = _str[i];
}
String::String(const String& other)
{
	copy(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
String::~String()
{
	del();
}
int String::lenght() const
{
	return size;
}
ostream& operator<<(ostream& out, const String& s)
{
	for (int i = 0; i < s.size; i++)
		out << s.str[i];
	return out;
}
istream& getline(istream& in, String& s, char c)
{
	char buff[MAX];
	in.getline(buff, MAX, c);
	s.size = strlen(buff);
	s.str = new char[s.size];
	for (int i = 0; i < s.size; i++)
		s.str[i] = buff[i];
	return in;
}
istream& operator>>(istream& in, String& s)
{
	char buff[MAX];
	in.getline(buff, MAX);
	s.size = strlen(buff);
	s.str = new char[s.size];
	for (int i = 0; i < s.size; i++)
		s.str[i] = buff[i];
	return in;
}
String& String::operator+=(const String& s)
{
	size_t len = size + s.size;
	char* newData = new char[len];
	for (int i = 0; i < size; i++)
	{
		newData[i] = str[i];
	}
	for (int i = 0; i < s.size; i++)
	{
		newData[size++] = s.str[i];
	}
	delete[] str;
	str = newData;
	return *this;
}
String operator+(const String& first, const String& second)
{
	String result = first;
	result += second;
	return result;
}
bool String::operator==(const String& s) const
{
	unsigned len = (size > s.size) ? size : s.size;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != s.str[i])
			return false;
	}
	return true;
}
bool String::operator!=(const String& s) const
{
	return !(str == s.str);
}
void String::erase(size_t pos, unsigned n)
{
	assert(n <= size);
	unsigned len = 0;
	char* newData = new char[size - n];
	bool searchingPos = false;
	unsigned cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == pos)
			searchingPos = true;
		if (searchingPos != true)
			newData[len++] = str[i];
		else
		{
			cnt++;
			if (cnt == n)
				searchingPos = false;
		}
	}
	delete[] str;
	str = newData;
	size = len;
}
bool String::empty() const
{
	return size == 0;
}
void String::pop_back()
{
	erase(lenght() - 1, 1);
}
char& String::operator[](size_t index)
{
	return str[index];
}
int stoi(String s)
{
	int digit = 0;
	for (int i = 0; i < s.lenght(); i++)
	{
		digit = digit * 10 + s[i] - '0';
	}
	return digit;
}
