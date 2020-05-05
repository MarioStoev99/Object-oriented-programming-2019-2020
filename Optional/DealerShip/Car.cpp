#include "Car.h"

Car::Car(const Engine& _engine,const VisualDetails& _visual,const ManufacturerDetails& _manufacturer, unsigned _price, bool _isNew) : 
	engineDetails(_engine), 
	visualDetails(_visual),
	manufacturerDetails(_manufacturer),
	price(_price),
	isnewCar(_isNew)
{}
Car::Car() : engineDetails(100,100,UNKNOWN), 
			 visualDetails(5,true,""), 
			 manufacturerDetails("","",1885),
			 price(20000),
			 isnewCar(true)
{}
void Car::print() const
{
	engineDetails.printEngine();
	manufacturerDetails.printManufacturer();
	visualDetails.printVisual();
	cout << price << " " << isnewCar << endl;
}
void Car::setCar()
{
	char buffer[MAX_SIZE];
	unsigned power, weight,type;
	cin >> power >> weight >> type;
	engineDetails.setEngine(power,weight,(typeofEngine)type);
	cin.get();
	cin.getline(buffer, MAX_SIZE);
	visualDetails.setColor(buffer);
	visualDetails.setSpoiler();
}