#include "FootballTournament.h"

void FootballTournament::copy(const FootballTournament& other)
{
	Team* teams = new Team[other.cap];
	for (int i = 0; i < other.size; i++)
	{
		teams[i] = other.teams[i];
	}
	size = other.size;
	cap = other.cap;
}
void FootballTournament::del()
{
	delete[] teams;
}
void FootballTournament::resize()
{
	Team* newTeams = new Team[cap * 2];
	for (int i = 0; i < size; i++)
		newTeams[i] = teams[i];
	del();
	teams = newTeams;
	cap *= 2;
}
FootballTournament::FootballTournament() : size(0) , cap(4)
{
	teams = new Team[cap];
}
FootballTournament::FootballTournament(const FootballTournament& other)
{
	copy(other);
}
FootballTournament& FootballTournament::operator=(const FootballTournament& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
FootballTournament::~FootballTournament()
{
	del();
}
void FootballTournament::print() const
{
	for (int i = 0; i < size; i++)
	{
		teams[i].print();
	}
}
void FootballTournament::addTeam(const Team& team)
{
	if (size == cap)
		resize();
	if (team.isnotValidTeam())
	{
		cout << "Invalid Team,please try again!!!" << endl;
		return;
	}
	if (team.haveChiefPlayers())
	{
		cout << "Two chief player.Try again";
		return;
	}
	teams[size++] = team;
}
bool FootballTournament::checkValidTeams() 
{
	if (size <= 3)
	{
		cout << "need more teams ";
		return false;
	}
	if (size % 2 != 0)
	{
		cout << "last team will be remove" << endl;
		size--;
	}
}
void FootballTournament::mySwap(unsigned x,unsigned y)
{
	Team t = teams[x];
	teams[x] = teams[y];
	teams[y] = t;
}
unsigned FootballTournament::battleGround(unsigned x, unsigned y)
{
	bool doYouWantToStartDuel;
	do
	{
		cout << "Iskate li duelyt da zapochne ?" << endl;
		cout << "Za da zapochne napishete stoinost != ot 0" << endl;
		cin >> doYouWantToStartDuel;
	} while (!doYouWantToStartDuel);
	const unsigned dice = 6;
	unsigned pointX = 0;
	unsigned pointY = 0;
	int i = 0;
	while (i < 3)
	{
		unsigned sumofTeamX = 0;
		unsigned sumofTeamY = 0;
		for (int j = 0; j < 3; j++)
		{
			unsigned resultofThrow = rand() % dice + 1;
			teams[x].setTeamPoints(resultofThrow);
			sumofTeamX += resultofThrow;
			resultofThrow = rand() % dice + 1;
			teams[y].setTeamPoints(resultofThrow);
			sumofTeamY += resultofThrow;
		}
		if (sumofTeamX > sumofTeamY)
		{
			cout << "the winner of round " << i + 1 <<
				" is team : ";
			teams[x].printPairNames();
			pointX++;
			i++;
			if (pointX == 2)
			{
				cout << "the winner of game is team ";
				teams[x].printPairNames();
				return y;
			}
		}
		else if (sumofTeamX < sumofTeamY)
		{
			cout << "the winner of round " << i + 1 <<
				" is team ";
			teams[y].printPairNames();
			pointY++;
			i++;
			if (pointY == 2)
			{
				cout << "the winner of game is team : ";
				teams[y].printPairNames();
				return x;
			}
		}
	}
}
void FootballTournament::removeSalary()
{
	unsigned profit = 0;
	for (int i = 1; i < size; i++)
	{
		profit = teams[i].setLooseTeamSalary();
	}
	profit /= 2;
	teams[0].setTeamSalary(profit);
}
void FootballTournament::suddenDeath()
{
	if (!checkValidTeams())
		return;
	char str1[1000];
	char str[6] = "start";
	do
	{
		cout << "Molq,napishete 'start',za da zapochne turniryt : ";
		cin.getline(str1, 6);
	} while (strcmp(str, str1) != 0);
	srand(time(nullptr));
	for (int i = 0; i < size; i++)
	{
		unsigned index = rand() % (size - i);
		mySwap(index, size - 1 - i);
	}
	for (int i = 0; i < size; i++)
	{
		teams[i].print();
	}
	unsigned len = size;
	while (len != 1)
	{
		for (int i = 0; i < len / 2; i++)
		{
			unsigned lost = battleGround(i, i + 1);
			if (lost == i)
				mySwap(i, i + 1);
			mySwap(i + 1, len - 1 - i);
		}
		len /= 2;
	}
	removeSalary();
	for (int i = 0; i < size; i++)
	{
		teams[i].print();
	}
	cout << "And again the winner is : ";
	teams[0].printPairNames();
}
void FootballTournament::printPointSystem() const
{
	for (int i = 0; i < size; i++)
	{
		cout << "Team ";
		teams[i].printPairNames();
		cout << " have " << teams[i].getTeamPoints() << " points" << endl;
	}
}
void FootballTournament::removeTeam()
{
	size--;
}