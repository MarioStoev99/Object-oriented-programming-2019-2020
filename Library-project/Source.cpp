#include "Library.h"

int main()
{
	try
	{
		Library l1;
		l1.openAPP();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}