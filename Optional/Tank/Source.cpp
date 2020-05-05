#include "Tank.h"
int main()
{
	Army tanks1(2);
	Army tanks(2);
	Tank t1("Mario", 100, 200);
	Tank t2("Petur", 50, 70);
	Tank t3("Kiro", 200, 200);
	tanks.addTank(t1, 0);
	tanks.addTank(t2, 1);
	//tanks.print();
	tanks1.deserialize();
	return 0;
}