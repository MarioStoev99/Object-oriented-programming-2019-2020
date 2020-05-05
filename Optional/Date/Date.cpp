#include <iostream>
#include "Date.h"

using namespace std;
Date::Date()
{
	day = 01;
	month = 01;
	year = 2000;
}
Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}
void Date::print() const
{
	cout << day << " " << month << " " << year << endl;
}
void  Date::isLeapYear() const
{
	if (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0))
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
}
void Date::increaseDate(int number)
{
	while (number != 0)
	{
		day++;
		number--;
		if (month == 1 || month == 3 || month == 5 ||
			month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day == 32)
			{
				month++;
				day = 1;
				if (month == 13)
				{
					month = 1;
					year++;
				}
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day == 31)
			{
				month++;
				day = 1;
			}
		}
		if (month == 2)
		{
			if (day == 29)
			{
				month++;
				day = 1;
			}
		}
	}
}
void Date::daystoChristmas(Date d)
{
	unsigned cnt = 1;
	while (!(d.day == 23 && d.month == 6))
	{
		d.day++;
		cnt++;
		if (d.month == 1 || d.month == 3 || d.month == 5 ||
			d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
		{
			if (d.day == 32)
			{
				d.month++;
				d.day = 1;
			}
		}
		if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		{
			if (d.day == 31)
			{
				d.month++;
				d.day = 1;
			}
		}
		if (d.month == 2)
		{
			if (d.day == 29)
			{
				d.month++;
				d.day = 1;
			}
		}
	}
	cout << "Ostavat  : " << cnt << " dena do rd-to ti" << endl;
}
void Date::isLaterThen(Date date) const
{
	if (year > date.year)
	{
		cout << "true" << endl;
		return;
	}
	else if (year == date.year)
	{
		if (month > date.month)
		{
			cout << "true" << endl;
			return;
		}
		else if (month == date.month)
		{
			if (day > date.day)
			{
				cout << "true" << endl;
				return;
			}
		}
	}
	else
		cout << "false" << endl;
}
Date getDiferrence(Date d1, Date d2)
{
	int number;
	Date d3;
	number = d1.getDay() - d2.getDay();
	d3.setDay(number);
	number = d1.getMonth() - d2.getMonth();
	d3.setMonth(number);
	number = d1.getYear() - d2.getYear();
	d3.setYear(number);
	return d3;
}