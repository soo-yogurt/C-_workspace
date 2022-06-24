#pragma once
#include <cstring>
#pragma warning(disable:4996)

class Car
{
private:
	int carNumber;
	char* type;

public:
	Car(const int _carNumber, const char * _type)
	{
		carNumber = _carNumber;
		type = new char[strlen(_type) + 1];
		strcpy(type, _type);
	}
	~Car() {}

	void SetType(const char* _type);
};



class Suv : public Car
{

private:


public:
	Suv(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{
		Car::SetType((const char*)"SUV");
	}
	~Suv() {}
	
};

class Saloon : public Car
{


public:
	Saloon(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{}
	~Saloon() {}



};