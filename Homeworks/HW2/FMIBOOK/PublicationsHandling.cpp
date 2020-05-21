#include "PublicationsHandling.h"

unsigned PublicationsHandling::id;

void PublicationsHandling::resize()
{
	Publication** newPublications = new Publication * [cap * 2];
	for (int i = 0; i < size; i++)
		newPublications[i] = publications[i];
	delete[] publications;
	publications = newPublications;
	cap *= 2;
}
void PublicationsHandling::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete publications[i];
	}
	delete[] publications;
}
void PublicationsHandling::copy(const PublicationsHandling& other)
{
	publications = new Publication * [other.cap];
	for (int i = 0; i < size; i++)
		publications[i] = other.publications[i]->clone();
	cap = other.cap;
	size = other.size;
}
PublicationsHandling::PublicationsHandling() : size(0),cap(2)
{
	publications = new Publication * [cap];
}
PublicationsHandling::PublicationsHandling(const PublicationsHandling& other)
{
	copy(other);
}
PublicationsHandling& PublicationsHandling::operator=(const PublicationsHandling& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
PublicationsHandling::~PublicationsHandling()
{
	clear();
}
void PublicationsHandling::addPublication(Publication* pub)
{
	if (size >= cap)
		resize();
	publications[size++] = pub;
	cout << "Post " << id << " created" << endl;
	pub->setUniqueNumber(id++);
}
void PublicationsHandling::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << *publications[i];
	}
}
bool PublicationsHandling::correctUserRemove(String name, int id) const
{
	for (int i = 0; i < size; i++)
	{
		bool findName = (publications[i]->getName() == name);
		bool findId = (publications[i]->getUniqueNumber() == id);
		if (findName && findId)
			return true;
	}
	return false;
}
void PublicationsHandling::removePost(int id)
{
	for (int i = 0; i < size; i++)
	{
		bool compareId = publications[i]->getUniqueNumber() == id;
		if (compareId)
		{
			swap(publications[i], publications[size - 1]);
			size--;
			cout << "Post " << id << " removed" << endl;
			return;
		}
	}
	cout << "No such post" << endl;
}
void PublicationsHandling::removeUsersPosts(String name)
{
	int i = 0;
	while(i != size)
	{
		bool findPos = (publications[i]->getName() == name);
		if (findPos)
		{
			swap(publications[i], publications[size - 1]);
			size--;
		}
		else
			i++;
	}
}
unsigned PublicationsHandling::countOfPersonalUserPosts(String name) const
{
	unsigned cnt = 0;
	for (int i = 0; i < size; i++)
	{
		bool findUser = (publications[i]->getName() == name);
		if (findUser)
			cnt++;
	}
	return cnt;
}