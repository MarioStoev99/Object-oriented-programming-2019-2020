#pragma once
#include "Publication.h"
class PublicationsHandling
{
private : 
	Publication** publications = nullptr;
	size_t size;
	size_t cap;
	static unsigned id;
	void copy(const PublicationsHandling&);
	void resize();
	void clear();
public :
	PublicationsHandling();
	PublicationsHandling(const PublicationsHandling&);
	PublicationsHandling& operator=(const PublicationsHandling&);
	~PublicationsHandling();
	
	// help functions
	bool correctUserRemove(String name, int id) const;
	void print() const;
	// tasks
	void addPublication(Publication*);
	void removePost(int);
	void removeUsersPosts(String);
	unsigned countOfPersonalUserPosts(String) const;
};

