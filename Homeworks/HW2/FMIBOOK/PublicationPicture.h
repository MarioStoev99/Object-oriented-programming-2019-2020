#pragma once
#include "Publication.h"
class PublicationPicture : public Publication
{
public : 
	PublicationPicture(String = "",String = "",int = 0);
	Publication* clone();
};

