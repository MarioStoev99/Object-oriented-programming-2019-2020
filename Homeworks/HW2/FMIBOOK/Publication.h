#include "String.h"
#include <fstream>
#include "AdditionalStaticMethods.h"
#pragma once
class Publication
{
private : 
	String content;
	String author;
	int uniqueNumber;
public : 
	Publication(String = "",String = "",int = 0);
	virtual ~Publication() = default;

	virtual Publication* clone() = 0;
	virtual void generatePost(bool) const = 0;

	String getName() const { return author; }
	String getContent() const { return content; }
	int getUniqueNumber() const { return uniqueNumber; }
	void setUniqueNumber(int _uniqueNumber) { uniqueNumber = _uniqueNumber; }
	friend ostream& operator<<(ostream&, const Publication&);
};
ostream& operator<<(ostream&, const Publication&);

