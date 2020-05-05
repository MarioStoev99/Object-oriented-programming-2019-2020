#include <iostream>
#include "Doctor.h"

using namespace std;

int main()
{
	Date date;
	Person person("Mario",date,5);
	Person person1("Petur", date, 3);
	//person.printPerson();
	Doctor doctor("Georgieva", 2);
	doctor.registeredPerson(person,0);
	doctor.registeredPerson(person1, 1);
	//doctor.print();
	//cout << doctor.average();
	doctor.printUpper(4);
	return 0;
}