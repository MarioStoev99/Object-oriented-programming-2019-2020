#pragma once
#include "Publication.h"
class PublicationText : public Publication
{
private : 
	void createFileName(String&, bool) const;
	void printInfoinHTMLFile(ostream&) const;
public :
	PublicationText(String = "",String = "", int = 0);
	Publication* clone();
	void generatePost(bool) const;
};

