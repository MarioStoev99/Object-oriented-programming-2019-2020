#include "Team.h"

Team::Team() : size(0),totalPoints(0)
{}
void Team::addObject(const SoftwareEngineer& player)
{
	if (size == CAP)
		return;
	engineers[size++] = player;
}
void Team::print() const
{
	for (int i = 0; i < 2; i++)
	{
		engineers[i].print();
	}
}
bool Team::isnotValidTeam() const
{
	for (int i = 0; i < 2; i++)
	{
		if (engineers[i].isnotValidEngineer())
		{
			return true;
		}
	}
	return false;
}
bool Team::haveChiefPlayers() const
{
	unsigned cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		if (engineers[i].isChiefPlayer())
			cnt++;
	}
	return cnt == 2;
}
void Team::printPairNames() const
{
	for (int i = 0; i < 2; i++)
	{
		cout << engineers[i].getName();
		if (i == 0)
			cout << " && ";
	}
	cout << endl;
}
unsigned Team::setLooseTeamSalary()
{
	unsigned profit = 0;
	for (int i = 0; i < 2; i++)
	{
		unsigned remainder = engineers[i].getSalary() * 0.05;
		profit += engineers[i].getSalary() * 0.05;
		engineers[i].setSalary(engineers[i].getSalary() - remainder);
	}
	return profit;
}
void Team::setTeamSalary(unsigned salary)
{
	for (int i = 0; i < 2; i++)
	{
		unsigned currentSalary = engineers[i].getSalary();
		engineers[i].setSalary(currentSalary + salary);
	}
}
unsigned Team::getTeamPoints()
{
	for (int i = 0; i < 2; i++)
	{
		totalPoints += engineers[i].getPoints();
	}
	return totalPoints;
}