#pragma once
#include "Publication.h"
class PublicationLink : public Publication
{
private : 
	void createFileName(String&, bool) const;
	void printInfoinHTMLFile(ostream&) const;
public : 
	PublicationLink(String = "",String = "",int = 0);
	Publication* clone();
	void generatePost(bool) const;
};

