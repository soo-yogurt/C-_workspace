#include "Car.h"


void Car::SetType(const char* _type)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
}

void Car::SetCarNumber(const int _carNumber)
{
	carNumber = _carNumber;
}

char* Car::GetType()
{
	return type;
}

int Car::GetCarNumber()
{
	return carNumber;
}


char* Suv::GetType()
{
	char* type = (char*)"SUV";
	return type;
}

char* Sedan::GetType()
{
	char* type = (char*)"Sedan";
	return type;
}