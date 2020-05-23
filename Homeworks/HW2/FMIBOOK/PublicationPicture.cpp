#include "PublicationPicture.h"
PublicationPicture::PublicationPicture(String author,String content,int uniqueNumber) : Publication(author,content,uniqueNumber)
{}
Publication* PublicationPicture::clone()
{
	return new PublicationPicture(*this);
}
void PublicationPicture::createFileName(String& filepath,bool allPosts) const
{
	filepath = "post";
	String idOrName;
	if (allPosts)
		idOrName += this->getName();
	else
		idOrName = AdditionalMethods::itos(this->getUniqueNumber());
	filepath += idOrName;
	filepath += ".html";
}
void PublicationPicture::generatePost(bool allPosts) const
{
	String filepath;
	createFileName(filepath,allPosts);
	char newPath[100];
	AdditionalMethods::c_str(newPath, filepath);
	ofstream file;
	if (allPosts)
		file.open(newPath, ios::ate | ios::app);
	else
		file.open(newPath);
	printInfoinHTMLFile(file);
}
void PublicationPicture::printInfoinHTMLFile(ostream& file) const
{
	file << "<!DOCTYPE html>" << endl << "<html>" << endl << "<body>" << endl << endl;
	file << "<h2>HTML Image</h2>" << endl;
	file << "<img src=" << "'" << this->getContent() << "'";
	file << "width=" << "'" << 250 << "'";
	file << "height=" << "'" << 300 << "'>" << endl << endl;
	file << "</body>" << endl << "</html> " << endl;
}