#pragma once
#include "Publication.h"
class PublicationText : public Publication
{
public :
	PublicationText(String = "",String = "", int = 0);
	Publication* clone();
};

