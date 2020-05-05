#include "User.h"
#include <fstream>
#pragma once
const size_t MAX_CHALLENGES_AND_PERFORMANCES = 65535;
class StayHomeChallenges
{
private :
	Challenge challenges[MAX_CAP];
	size_t challengeCount;
	User* users = nullptr;
	size_t cap;
	size_t size;
	static unsigned challengeOrPerform;
	void del();
	void resize();
	void addUser(User&);
	void printUsers() const;
	void registrationUser(const char*,unsigned index);
	void challengePropriety(const char*, unsigned index);
	bool isRegistered(const char*);
	void printChallenges() const;
	int findPosChallenge(const char*) const;
	void eraseEmailAndCaller(const char*,char*,char*,unsigned&,bool&);
	void performers(const char*, char*,const char*, unsigned,bool&);
	void putChallengeinChallengesArray(const char*);
	void putChallenge(const char*,const char*);
	void profileInfo(const char*) const;
	void finishChallenge(const char*, unsigned);
	bool isExistSuchUser(const char*, int, double,unsigned&) const;
	void changeRating(const char*, double);
	bool isReachLimit() const;
	void bubbleSort(TypeSorts);
	void choice(size_t,size_t,TypeSorts,bool&);
	void newestSort(size_t, size_t,bool&);
	void oldestSort(size_t, size_t,bool&);
	void mostpopularSort(size_t, size_t,bool&);
	void deserializationUsers();
	void chargeSizeFromTxtFile(ifstream&, unsigned&);
	void chargeIdFromTxtFile(ifstream&,size_t);
	void chargeNameFromTxtFile(ifstream&,size_t);
	void chargeAgeFromTxtFile(ifstream&,size_t);
	void chargeEmailFromTxtFile(ifstream&,size_t);
	void serializationUsers() const;
	void deserializationChallenges();
	streampos getFileSize(ifstream&);
	void serializationChallenges() const;
public :
	StayHomeChallenges();
	StayHomeChallenges(const StayHomeChallenges&) = delete;
	StayHomeChallenges& operator=(const StayHomeChallenges&) = delete;
	~StayHomeChallenges();
	void startApp();
};

