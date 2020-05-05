#include "StayHomeChallenges.h"
unsigned StayHomeChallenges::challengeOrPerform;
void StayHomeChallenges::del()
{
	delete[] users;
}
void StayHomeChallenges::resize()
{
	User* newUsers = new User[cap * 2];
	for (int i = 0; i < size; i++)
		newUsers[i] = users[i];
	del();
	users = newUsers;
	cap *= 2;
}
StayHomeChallenges::StayHomeChallenges() 
	: cap(2),size(0),challengeCount(0)
{
		users = new User[cap];
}
StayHomeChallenges::~StayHomeChallenges()
{
	del();
}
void StayHomeChallenges::startApp()
{
	while (true)
	{
		char temp[MAX_SIZE];
		char name[MAX_SIZE];
		unsigned index = 0;
		cin.getline(temp, MAX_SIZE);
		if (isValidOption(temp, index, "registration"))
		{
			registrationUser(temp, index);
		}
		else if (isValidOption(temp, index, "challenge"))
		{
			if (isReachLimit())
				return;
			challengePropriety(temp, index);
		}
		else if (isValidOption(temp, index, "profile_info"))
		{
			eraseWord(temp, name, index);
			profileInfo(name);
		}
		else if (isValidOption(temp, index, "finish"))
		{
			if (isReachLimit())
				return;
			finishChallenge(temp, index);
		}
		else if (isValidOption(temp, index, "list_by"))
		{
			eraseWord(temp, name, index);
			TypeSorts type = getType(name);
			if (type == TypeSorts::UNKNOWN)
			{
				cout << "invalid type Sort" << endl;
				continue;
			}
			bubbleSort(type);
			printChallenges();
		}
		else if (isValidOption(temp, index, "load"))
		{
			if (isValidOption(temp, index, "users.txt"))
				deserializationUsers();
			else if (isValidOption(temp, index, "challenges.bin"))
				deserializationChallenges();
			else
				cout << "bad command,try again" << endl;
		}
		else if (strcmp(temp, "exit") == 0)
		{
			serializationChallenges();
			serializationUsers();
			break;
		}
		else
			cout << "Invalid command,please try again!!" << endl;
	}
}
void StayHomeChallenges::addUser(User& user)
{
	if (size >= cap)
		resize();
	users[size++] = user;
}
void StayHomeChallenges::printUsers() const
{
	for (int i = 0; i < size; i++)
	{
		cout << users[i];
		users[i].printChallenges();
	}
}
void StayHomeChallenges::registrationUser(const char* temp,unsigned index)
{
	char name[MAX_SIZE] = "";
	char email[MAX_SIZE] = "";
	int age = 0;
	eraseWord(temp, name, index);
	if (temp[index - 1] != '\0' && isDigit(temp[index]))
		charToInt(temp, age, index);
	if (temp[index - 1] != '\0')
		eraseWord(temp, email, index);
	if (strcmp(email, "") == 0)
		strcpy(email, "UNKNOWN");
	User u1(name, email, age);
	addUser(u1);
}
void StayHomeChallenges::challengePropriety(const char* temp, unsigned index)
{
	char name[MAX_SIZE];
	char challenge[MAX_SIZE];
	bool error = false;
	eraseEmailAndCaller(temp, name, challenge, index,error);
	if (error == true)
		return;
	performers(temp, name,challenge, index,error);
	if (error == true)
		return;
	putChallengeinChallengesArray(challenge);
}
bool StayHomeChallenges::isRegistered(const char* _name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(users[i].getName(),_name) == 0)
			return true;
	}
	return false;
}
void StayHomeChallenges::printChallenges() const
{
	for (int i = 0; i < challengeCount; i++)
	{
		cout << challenges[i];
		challenges[i].printStatus();
	}
}
int StayHomeChallenges::findPosChallenge(const char* currentChallenge) const
{
	for (int i = 0; i < challengeCount; i++)
	{
		if (strcmp(challenges[i].getChallengeName(), currentChallenge) == 0)
			return i;
	}
	return -1;
}
void StayHomeChallenges::eraseEmailAndCaller(const char* temp,char* name,char* challenge, unsigned& index,bool& error) 
{
	eraseWord(temp, name, index);
	if (!isRegistered(name))
	{
		error = true;
		cout << "this user is not registered" << endl;
		return;
	}
	if (temp[index] != '#' || temp[index] == '\0')
	{
		error = true;
		cout << "invalid challenge.You skip '#' this character" << endl;
		return;
	}
	eraseWord(temp, challenge, index);
	if (temp[index - 1] == '\0')
	{	
		error = true;
		cout << "Invalid command.You need challenge someone" << endl;
		return;
	}
}
void StayHomeChallenges::performers(const char* temp, char* name,const char* challenge ,unsigned index,bool& error)
{
	while (temp[index - 1] != '\0')
	{
		eraseWord(temp, name, index);
		if (!isRegistered(name))
		{
			error = true;
			cout << "This name is not registered.You have another chance" << endl;
			return;
		}
		else
		{
			if (isRegistered(name))
			{
				putChallenge(name,challenge);
			}
		}
	}
}
void StayHomeChallenges::putChallengeinChallengesArray(const char* challenge)
{
	unsigned posInArrayChallenge = findPosChallenge(challenge);
	if (posInArrayChallenge == -1)
		challenges[challengeCount++] = Challenge(challenge);
	else
	{
		unsigned newSubmitCount = challenges[posInArrayChallenge].getSubmitCount() + 1;
		challenges[posInArrayChallenge].setSubmitCount(newSubmitCount);
		unsigned range = challenges[posInArrayChallenge].getSubmitCount();
		Status currentStatus = (challenges[posInArrayChallenge].getStatus());
		if (range >= 2 && range <= 10 && currentStatus == Status::_new)
			challenges[posInArrayChallenge].setStatus(Status::quite_recently);
		if (range > 10)
			challenges[posInArrayChallenge].setStatus(Status::old);
	}
}
void StayHomeChallenges::putChallenge(const char* name,const char* challenge)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(users[i].getName(), name) == 0)
		{
			if (!users[i].isExistinChallengeList(challenge))
				users[i].setChallengeList(challenge);
		}
	}
}
void StayHomeChallenges::profileInfo(const char* name) const
{
	bool isExist = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(users[i].getName(), name) == 0)
		{
			cout << users[i];
			isExist = true;
		}
	}
	if(!isExist)
		cout << "This user not exist in the system" << endl;
}
void StayHomeChallenges::finishChallenge(const char* temp, unsigned index)
{
	char challenge[MAX_SIZE];
	int id;
	unsigned userIndex;
	eraseWord(temp, challenge, index);
	charToInt(temp, id, index);
	double rating = atof(temp + index);
	if (rating > 10 || rating < -5)
		throw logic_error("Bad rating.The range is [-5;10]");
	if (!isExistSuchUser(challenge, id, rating, userIndex))
		cout << "Such id not exist.If you want try again" << endl;
	else
	{
		users[userIndex].removeChallengeFromUserList(challenge);
		changeRating(challenge,rating);
	}
}
bool StayHomeChallenges::isExistSuchUser(const char* challenge, int id, double rating,unsigned& userIndex) const
{
	for (int i = 0; i < size; i++)
	{
		if (users[i].getId() == id)
		{
			if (users[i].isExistinChallengeList(challenge))
			{
				userIndex = i;
				return true;
			}
		}
	}
	return false;
}
void StayHomeChallenges::changeRating(const char* challenge, double rating)
{
	for (int i = 0; i < challengeCount; i++)
	{
		if (strcmp(challenges[i].getChallengeName(), challenge) == 0)
		{
			challenges[i].setRating(rating);
			return;
		}
	}
}
bool StayHomeChallenges::isReachLimit() const
{
	challengeOrPerform++;
	if (challengeOrPerform > MAX_CHALLENGES_AND_PERFORMANCES)
	{
		cout << "The app reach the limit of challenges and permormances";
		return true;
	}
	return false;
}
void StayHomeChallenges::bubbleSort(TypeSorts type)
{
	bool changed = false;
	unsigned sorted = 0;
	do
	{
		changed = false;
		for (unsigned i = challengeCount - 1; i > sorted; i--)
		{
			choice(i, i - 1, type, changed);
		}
		sorted++;
	} while (changed);
}
void StayHomeChallenges::choice(size_t i, size_t j,TypeSorts type,bool& changed)
{
	switch (type)
	{
		case TypeSorts::newest: newestSort(i, j,changed); break;
		case TypeSorts::oldest: oldestSort(i, j,changed); break;
		case TypeSorts::most_popular: mostpopularSort(i, j,changed); break;
	}
}
void StayHomeChallenges::newestSort(size_t i, size_t j,bool& changed)
{
	if (challenges[i].getSubmitCount() < challenges[j].getSubmitCount())
	{
		swap(challenges[i], challenges[j]);
		changed = true;
	}
}
void StayHomeChallenges::oldestSort(size_t i, size_t j, bool& changed)
{
	if (challenges[i].getSubmitCount() > challenges[j].getSubmitCount())
	{
		swap(challenges[i], challenges[j]);
		changed = true;
	}
}
void StayHomeChallenges::mostpopularSort(size_t i, size_t j, bool& changed)
{
	if (challenges[i].getSubmitCount() > challenges[j].getSubmitCount())
	{
		swap(challenges[i], challenges[j]);
		changed = true;
	}
}
void StayHomeChallenges::deserializationUsers() 
{	
	ifstream file("users.txt");
	unsigned newSize;
	chargeSizeFromTxtFile(file, newSize);
	for (int i = 0; i < newSize; i++)
	{
		chargeIdFromTxtFile(file, i);
		chargeNameFromTxtFile(file, i);
		chargeAgeFromTxtFile(file, i);
		chargeEmailFromTxtFile(file, i);
	}
	size = newSize;
}
void StayHomeChallenges::chargeIdFromTxtFile(ifstream& file,size_t index)
{
	unsigned id;
	if (!file.good())
	{
		cout << "stream's not good" << endl;
		return;
	}
	file >> id;
	file.ignore();
	users[index].setId(id);
}
void StayHomeChallenges::chargeNameFromTxtFile(ifstream& file, size_t index)
{
	char buff[MAX_SIZE];
	file.getline(buff, MAX_SIZE, ' ');
	users[index].setName(buff);
}
void StayHomeChallenges::chargeAgeFromTxtFile(ifstream& file, size_t index)
{
	unsigned age;
	char buff[MAX_SIZE];
	file >> age;
	if (file.fail())
	{
		file.clear();
		file.getline(buff, MAX_SIZE, ' ');
		age = 0;
	}
	else
		file.ignore();
	users[index].setAge(age);
}
void StayHomeChallenges::chargeEmailFromTxtFile(ifstream& file, size_t index)
{
	char buff[MAX_SIZE];
	file.getline(buff, MAX_SIZE);
	users[index].setEmail(buff);
}
void StayHomeChallenges::chargeSizeFromTxtFile(ifstream& file, unsigned& newSize)
{
	file >> newSize;
	file.ignore();
	while (newSize >= cap)
		resize();
}
void StayHomeChallenges::serializationUsers() const
{
	ofstream file("users.txt");
	file << size << endl;
	for (int i = 0; i < size; i++)
	{
		file << users[i].getId() << " " << users[i].getName() << " ";
		if (users[i].getAge() == 0)
			file << "UNKNOWN ";
		else
			file << users[i].getAge() << " ";
		file << users[i].getEmail() << endl;
	}
}
streampos StayHomeChallenges::getFileSize(ifstream& file)
{
	int currPos = file.tellg();
	file.seekg(0, ios::end);
	streampos size = file.tellg();
	file.seekg(0, ios::beg);
	return size;
}
void StayHomeChallenges::deserializationChallenges()
{
	ifstream file("challenges.bin",ios::binary);
	streampos sizeofFile = getFileSize(file);
	file.read((char*)challenges, sizeofFile);
	challengeCount = sizeofFile / sizeof(Challenge);
}
void StayHomeChallenges::serializationChallenges() const
{
	ofstream file("challenges.bin", ios::binary);
	file.write((const char*)challenges,challengeCount*sizeof(Challenge));
}