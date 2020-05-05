#include "ManufacturerDetails.h"
#include <string.h>
void ManufacturerDetails::copy(const char* _nameofManufacturerDetails,const char* _modelofCar,unsigned _year)
{
	nameofManufactuter = new char[strlen(_nameofManufacturerDetails) + 1];
	strcpy(nameofManufactuter, _nameofManufacturerDetails);
	modelofCar = new char[strlen(_modelofCar) + 1];
	strcpy(modelofCar, _modelofCar);
	if (_year > 2020 || _year < 1885)
		year = 1885;
	else
		year = _year;
}
void ManufacturerDetails::del()
{
	delete[] nameofManufactuter;
	delete[] modelofCar;
}
ManufacturerDetails::ManufacturerDetails(const char* _nameofManufacturerDetails, const char* _modelofCar, unsigned _year) 
{
	copy(_nameofManufacturerDetails, _modelofCar, _year);
}
ManufacturerDetails::ManufacturerDetails(const ManufacturerDetails& other)
{
	copy(other.nameofManufactuter, other.modelofCar, other.year);
}
ManufacturerDetails& ManufacturerDetails::operator=(const ManufacturerDetails& other)
{
	if (this != &other)
	{
		del();
		copy(other.nameofManufactuter, other.modelofCar, other.year);
	}
	return *this;
}
ManufacturerDetails::~ManufacturerDetails()
{
	del();
}
void ManufacturerDetails::printManufacturer() const
{
	cout << nameofManufactuter << " " << modelofCar << " " << year << endl;
}
ManufacturerDetails::ManufacturerDetails() 
: 
  year(1885)
{
	nameofManufactuter = new char[1];
	strcpy(nameofManufactuter, "");
	modelofCar = new char[1];
	strcpy(modelofCar, "");
}