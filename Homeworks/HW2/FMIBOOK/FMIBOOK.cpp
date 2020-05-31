#include <iostream>
#include "Application.h"
using namespace std;
int main()
{
	try
	{
		Application app;
		app.startApp();
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	return 0;
}
