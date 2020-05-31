#include "PublicationLink.h"
PublicationLink::PublicationLink(String author,String content,int uniqueNumber) : Publication(author,content,uniqueNumber)
{}
Publication* PublicationLink::clone()
{
	return new PublicationLink(*this);
}
void PublicationLink::createFileName(String& filepath, bool allPosts) const
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
void PublicationLink::generatePost(bool allPosts) const
{
	String filepath;
	createFileName(filepath, allPosts);
	char newPath[100]; 
	AdditionalMethods::c_str(newPath, filepath);
	ofstream file;
	if (allPosts)
		file.open(newPath, ios::ate | ios::app);
	else
		file.open(newPath);
	printInfoinHTMLFile(file);
}
void PublicationLink::printInfoinHTMLFile(ostream& file) const
{
	file << "<!DOCTYPE html>" << endl << "<html>" << endl;
	file << "<body>" << endl << endl;
	file << "<p><a href=" << "'" << this->getContent() << "'";
	file << "> Click" << endl << endl << "</body>" << endl << "</html> " << endl;
}
