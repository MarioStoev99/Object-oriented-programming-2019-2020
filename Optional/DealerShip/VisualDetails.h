#include <iostream>
using namespace std;
#pragma once
const size_t MAX_SIZE = 50;
class VisualDetails
{
private :
	unsigned numberofDoors;
	bool haveSpoiler;
	char color[MAX_SIZE + 1];
public :
	VisualDetails(unsigned = 5, bool = true, const char* = "");
	VisualDetails();
	void printVisual() const;
	void setColor(const char* _color) { strcpy(color, _color); }
	void setSpoiler() { !haveSpoiler; }
};

