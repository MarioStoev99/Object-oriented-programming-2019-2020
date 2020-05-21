#include <iostream>
#include "User.h"
#include "String.h"
#include "myNameSpace.h"
#include "Application.h"
#include "PublicationText.h"
using namespace std;
int main()
{
	try
	{
		Application app;
		app.startApp();
	}
	catch (exception & e)
	{
		cout << "exception : " << e.what();
	}
	return 0;
}
