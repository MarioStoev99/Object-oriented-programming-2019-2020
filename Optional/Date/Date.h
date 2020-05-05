#pragma once
class Date
{
private : 
	int day;
	int month;
	int year;
public : 
	Date();
	Date(int, int, int);
	void print() const;
	void increaseDate(int);
	void isLeapYear() const;
	void daystoChristmas(Date);
	void isLaterThen(Date) const;
	int getDay() { return day; } const
	int getMonth() { return month; } const
	int getYear() { return year; } const
	void setYear(int _year) { year = _year; }
	void setDay(int _day) { day = _day; }
	void setMonth(int _month) { month = _month; }
};
Date getDiferrence(Date, Date);
