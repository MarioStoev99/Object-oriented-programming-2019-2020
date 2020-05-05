#include "Team.h"
#include <time.h>
#include <stdlib.h>
#pragma once
class FootballTournament
{
private : 
	Team* teams = nullptr;
	unsigned cap;
	unsigned size;
	void copy(const FootballTournament&);
	void del();
	void resize();
	bool checkValidTeams();
	void mySwap(unsigned,unsigned);
	unsigned battleGround(unsigned, unsigned);
	void removeSalary();
public : 
	FootballTournament();
	FootballTournament(const FootballTournament&);
	FootballTournament& operator=(const FootballTournament&);
	~FootballTournament();
	void print() const;
	void addTeam(const Team&);
	void suddenDeath();
	void printPointSystem() const;
	void removeTeam();
};

