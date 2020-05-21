#include "PublicationText.h"
PublicationText::PublicationText(String author,String content, int uniqueNumber) : Publication(author,content, uniqueNumber)
{}
Publication* PublicationText::clone()
{
	return new PublicationText(*this);
}