#pragma once
class BankAccount
{
private :
	char* name;
	unsigned cardNumber;
	unsigned currentSum;
	void copy(const char*, unsigned, unsigned);
public :
	BankAccount(const char*,unsigned,unsigned);
	~BankAccount();
	BankAccount& operator=(const BankAccount&);
	BankAccount(const BankAccount&);
	void print() const;
	void pushMoney(unsigned);
	void popMoney(unsigned);
};

