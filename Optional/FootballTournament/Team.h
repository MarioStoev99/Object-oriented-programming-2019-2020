#include "SoftwareEngineer.h"
#pragma once
class Team
{
private : 
	const static unsigned CAP = 2;
	SoftwareEngineer engineers[CAP];
	unsigned size;
	unsigned totalPoints;
public : 
	Team();
	void print() const;
	void addObject(const SoftwareEngineer&);
	bool isnotValidTeam() const;
	bool haveChiefPlayers() const;
	void printPairNames() const;
	unsigned getTeamPoints();
	void setTeamPoints(unsigned _points) { totalPoints += _points; };
	unsigned setLooseTeamSalary();
	void setTeamSalary(unsigned);
};

