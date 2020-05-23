#pragma once
#include "Publication.h"
class PublicationPicture : public Publication
{
private : 
	void createFileName(String&,bool) const;
	void printInfoinHTMLFile(ostream&) const;
public : 
	PublicationPicture(String = "",String = "",int = 0);
	Publication* clone();
	void generatePost(bool) const;
};

