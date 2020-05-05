#pragma once

#include <iostream>
#include "namespace.h"
#include "status.h"
using namespace std;
using namespace functions;

const size_t CHALLENGE_NAME = 32;
class Challenge
{
private :
	char challengeName[CHALLENGE_NAME];
	double rating;
	unsigned submitCount;
	Status status;
public : 
	Challenge(const char* = "",double = 0,unsigned = 0,Status = Status::_new);
	friend ostream& operator<<(ostream&, const Challenge&);
	const char* getChallengeName() const { return challengeName; }
	unsigned getSubmitCount() const { return submitCount; }
	double getRating() const { return rating; }
	Status getStatus() const { return status; }
	void setRating(double);
	void setSubmitCount(unsigned _submitCount) { submitCount = _submitCount; }
	void setStatus(Status _status) { status = _status; }
	void printStatus() const;
};
ostream& operator<<(ostream&, const Challenge&);
