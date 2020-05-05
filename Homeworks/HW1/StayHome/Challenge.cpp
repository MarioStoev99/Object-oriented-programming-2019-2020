#include "Challenge.h"

Challenge::Challenge(const char* _challengeName,double _rating,unsigned _submitCount,Status _status)
{
	if (_challengeName == nullptr)
		throw logic_error("challengeName = nullptr!!");
	unsigned len = strlen(_challengeName);
	strncpy(challengeName,_challengeName,len);
	challengeName[len] = '\0';
	if (_rating > 10.0 || _rating < -5.0)
		throw logic_error("invalid rating");
	submitCount = _submitCount;
	rating = _rating;
	status = _status;
}
ostream& operator<<(ostream& o, const Challenge& challenge) 
{
	return o << challenge.challengeName << " " << challenge.submitCount
		<< " " << challenge.rating;
}
void Challenge::printStatus() const
{
	switch (status)
	{
		case Status::_new: cout << " new" << endl; break;
		case Status::quite_recently: cout << " quite recently" << endl; break;
		case Status::old:cout << " old" << endl; break;
	}
}
void Challenge::setRating(double _rating) 
{ 
	if (rating == 0)
		rating = _rating;
	else
		rating = (rating + _rating) / 2.0;
}