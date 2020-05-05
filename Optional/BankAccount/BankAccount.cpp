#include "BankAccount.h"
#include <iostream>
#include <string.h>
using namespace std;

void BankAccount::copy(const char* _name, unsigned _cardNumber, unsigned _currentSum)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	cardNumber = _cardNumber;
	currentSum = _currentSum;
}
BankAccount::BankAccount(const char* name,unsigned cardNumber,unsigned currentSum)
{
	copy(name,cardNumber,currentSum);
}
BankAccount::~BankAccount()
{
	delete[] name;
}
BankAccount::BankAccount(const BankAccount& other)
{
	copy(other.name, other.cardNumber, other.currentSum);
}
BankAccount& BankAccount::operator=(const BankAccount& other)
{
	if (this != &other)
	{
		delete[] name;
		copy(other.name, other.cardNumber, other.currentSum);
	}
	return *this;
}
void BankAccount::print() const
{
	cout << name << " " << cardNumber << " " << currentSum << endl;
}
void BankAccount::pushMoney(unsigned sum)
{
	currentSum += sum;
}
void BankAccount::popMoney(unsigned sum)
{
	if (currentSum - sum < 0)
		return;
	else
		currentSum -= sum;
}