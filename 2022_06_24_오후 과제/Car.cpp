#include "Car.h"


void Car::SetType(const char* _type)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
}

void Car::SetCarNumber(const int _carNumber)
{
	this->carNumber = _carNumber;
}

char* Car::GetType()
{
	return this->type;
}

int Car::GetCarNumber()
{
	return this->carNumber;
}