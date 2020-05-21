#pragma once
#include "Publication.h"
class PublicationLink : public Publication
{
public : 
	PublicationLink(String = "",String = "",int = 0);
	Publication* clone();

};

