#include "PublicationPicture.h"
PublicationPicture::PublicationPicture(String author,String content,int uniqueNumber) : Publication(author,content,uniqueNumber)
{}
Publication* PublicationPicture::clone()
{
	return new PublicationPicture(*this);
}