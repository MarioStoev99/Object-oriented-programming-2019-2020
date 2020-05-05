#include "VisualDetails.h"
#include <string.h>
VisualDetails::VisualDetails(unsigned _numberofDoors, bool _haveSpoiler, const char* _color)
	: haveSpoiler(_haveSpoiler)
{
	strcpy(color, _color);
	if (_numberofDoors > 5)
		numberofDoors = 5;
	else
		numberofDoors = _numberofDoors;
}
VisualDetails::VisualDetails() : numberofDoors(5), haveSpoiler(true)
{
	strcpy(color, "");
}
void VisualDetails::printVisual() const
{
	cout << numberofDoors << " " << haveSpoiler << " " << color << endl;
} 