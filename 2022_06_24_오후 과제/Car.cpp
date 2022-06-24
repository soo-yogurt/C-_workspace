#include "Car.h"


void Car::SetType(const char* _type)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
}

