#include "Date.h"

int main()
{
	Date d1(31,3,2014);
	Date d2;
	d1.daystoChristmas(d1);
	//d1.isLaterThen(d2);
	Date result = getDiferrence(d1, d2);
	result.print();
	return 0;
}