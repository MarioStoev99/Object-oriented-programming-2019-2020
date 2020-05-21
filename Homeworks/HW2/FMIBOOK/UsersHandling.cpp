#include "UsersHandling.h"

void UsersHandling::resize()
{
	User** newUsers = new User * [cap * 2];
	for (int i = 0; i < size; i++)
		newUsers[i] = users[i];
	delete[] users;
	users = newUsers;
	cap *= 2;
}
void UsersHandling::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete users[i];
	}
	delete[] users;
}
void UsersHandling::copy(const UsersHandling& other)
{
	users = new User * [other.cap];
	for (int i = 0; i < size; i++)
		users[i] = other.users[i]->clone();
	cap = other.cap;
	size = other.size;
}
UsersHandling::UsersHandling() : cap(2), size(0)
{
	User* newMember = new Administrator("Admin", 33);
	users = new User * [cap];
	users[size++] = newMember;
}
UsersHandling::UsersHandling(const UsersHandling& other)
{
	copy(other);
}
UsersHandling& UsersHandling::operator=(const UsersHandling& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
UsersHandling::~UsersHandling()
{
	clear();
}
void UsersHandling::addMember(User* newMember)
{
	if (size >= cap)
		resize();
	users[size++] = newMember;
	cout << newMember->getName() << " created" << endl;
}
void UsersHandling::removeMember(String name, int age)
{
	for (int i = 0; i < size; i++)
	{
		if (name == users[i]->getName())
		{
			cout << users[i]->getName() << " removed" << endl;
			swap(users[i], users[size - 1]);
			size--;
			return;
		}
	}
}
void UsersHandling::info() const
{
	printTotalUsers();
	printOldestAndYongestPerson();
	printBlockedUsers();
}
void UsersHandling::printOldestAndYongestPerson() const
{
	if (size == 0)
		return;
	int maxAge = users[0]->getAge();
	int	minAge = users[0]->getAge();
	String youngest = users[0]->getName();
	String oldest = users[0]->getName();
	for (int i = 0; i < size; i++)
	{
		if (users[i]->getAge() > maxAge)
		{
			maxAge = users[i]->getAge();
			oldest = users[i]->getName();
		}
		if (users[i]->getAge() < minAge)
		{
			minAge = users[i]->getAge();
			youngest = users[i]->getName();
		}
	}
	cout << "oldest " << oldest << " " << maxAge << endl;
	cout << "youngest " << youngest << " " << minAge << endl;
}
void UsersHandling::printTotalUsers() const
{
	if (size == 0)
		return;
	cout << "There are " << size << " users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << users[i]->getName() << " - " << typeid(*users[i]).name();
		cout << ", " << users[i]->getPosts() << " posts" << endl;
	}
}
void UsersHandling::printBlockedUsers() const
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (users[i]->getIsBlocked() == 1)
		{
			cout << cnt + 1 << ")";
			cout << users[i]->getName() << " " << users[i]->getAge() << endl;
			cnt++;
		}
	}
	if (cnt == 0)
		cout << "There aren't any blocked users" << endl;
	else
		cout << "Total users block : " << cnt << endl;
}
int UsersHandling::findPosUserInArray(String user) const
{
	for (int i = 0; i < size; i++)
	{
		if (users[i]->getName() == user)
		{
			return i;
		}
	}
	return -1;
}
void UsersHandling::blockorUnblock(String actor, String subject, bool blockFlag) const
{
	int actorIndex = findPosUserInArray(actor);
	int subjectIndex = findPosUserInArray(subject);
	if (subjectIndex != -1 && actorIndex != -1)
	{
		bool firstCondition = (typeid(*users[actorIndex]) == typeid(Moderator));
		bool secondCondition = (typeid(*users[actorIndex]) == typeid(Administrator));
		if (firstCondition || secondCondition)
		{
			if (users[subjectIndex]->getIsBlocked() == blockFlag)
			{
				if (blockFlag == 1)
					cout << "This user has already blocked" << endl;
				else
					cout << "This user is unblock" << endl;
				return;
			}
			if (blockFlag == 1)
				cout << users[subjectIndex]->getName() << " blocked" << endl;
			else
				cout << users[subjectIndex]->getName() << " unblocked" << endl;
			users[subjectIndex]->setBlocked(blockFlag);
		}
		else
			cout << "Invalid operation" << endl;
	}
	else
		cout << "Invalid operation" << endl;
}
void UsersHandling::rename(String actor, String subject) const
{
	size_t index = 0;
	for (int i = 0; i < size; i++)
	{
		if (users[i]->getName() == actor)
		{
			index = i;
		}
		if (users[i]->getName() == subject)
		{
			cout << "This name has already exist.Try with another name!" << endl;
			return;
		}
	}
	cout << "User " << users[index]->getName() << " is now known as " << subject << endl;
	users[index]->setName(subject);
}
bool UsersHandling::blockUser(size_t index) const
{
	return users[index]->getIsBlocked();
}
bool UsersHandling::haveRights(size_t index) const
{
	return typeid(*users[index]) == typeid(Administrator) ||
		   typeid(*users[index]) == typeid(Moderator);
}
void UsersHandling::increasePersonalPosts(size_t index)
{
	users[index]->setPosts();
}
