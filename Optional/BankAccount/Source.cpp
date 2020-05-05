#include "BankAccount.h"
#include <iostream>

using namespace std;

int main()
{
	BankAccount account("Mario", 1234, 1500);
	account.print();
	account.pushMoney(500);
	account.print();
	account.popMoney(300);
	account.print();
	return 0;
}