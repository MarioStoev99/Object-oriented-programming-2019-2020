#include "PublicationLink.h"
PublicationLink::PublicationLink(String author,String content,int uniqueNumber) : Publication(author,content,uniqueNumber)
{}
Publication* PublicationLink::clone()
{
	return new PublicationLink(*this);
}