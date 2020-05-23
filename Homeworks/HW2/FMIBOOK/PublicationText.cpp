#include "PublicationText.h"
PublicationText::PublicationText(String author,String content, int uniqueNumber) : Publication(author,content, uniqueNumber)
{}
Publication* PublicationText::clone()
{
	return new PublicationText(*this);
}
void PublicationText::createFileName(String& filepath, bool allPosts) const
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
void PublicationText::generatePost(bool allPosts) const
{
	String filepath;
	createFileName(filepath, allPosts);
	char newPath[100];
	AdditionalMethods::c_str(newPath, filepath);
	ofstream file;
	if(allPosts)
		file.open(newPath,ios::ate | ios::app);
	else
		file.open(newPath);
	printInfoinHTMLFile(file);
}

void PublicationText::printInfoinHTMLFile(ostream& file) const
{
	file << "<!DOCTYPE html>" << endl << "<html>" << endl;
	file << "<body>" << endl << endl;
	file << "<p>" << this->getContent() << endl << endl;
	file << "</body>" << endl << "</html> " << endl;
}