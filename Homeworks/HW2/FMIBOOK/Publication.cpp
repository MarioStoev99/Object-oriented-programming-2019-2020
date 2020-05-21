#include "Publication.h"

Publication::Publication(String _author,String _content,int _uniqueNumber)
{
	author = _author;
	content = _content;
	uniqueNumber = _uniqueNumber;
}
ostream& operator<<(ostream& out, const Publication& p)
{
	return out << p.author << " " << p.content << " " << p.uniqueNumber << endl;
}