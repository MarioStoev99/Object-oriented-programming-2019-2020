#include "StayHomeChallenges.h"
int main()
{
	srand(time(NULL));
	StayHomeChallenges s1;
	try
	{
		s1.startApp();
	}
	catch (logic_error& e)
	{
		cout << "exeption : " << e.what();
	}
	catch (bad_alloc& e)
	{
		cout << "exeption : " << e.what();
	}
	catch (exception& e)
	{
		cout << "exeption : " << e.what();
	}
	return 0;
}