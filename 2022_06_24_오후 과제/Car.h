#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
//#pragma warning(disable:4996)

class Car
{
private:
	int carNumber;
	char * type;

public:
	Car()
	{
		carNumber = 0;
		type = NULL;
	}
	Car(const int _carNumber)
	{
		carNumber = _carNumber;
		type = NULL;
	}

	Car(const int _carNumber, const char * _type)
	{
		carNumber = _carNumber;
		type = new char[strlen(_type) + 1];
		strcpy(type, _type);
	}
	virtual~Car() 
	{
		delete[] type;
	}

	void SetCarNumber(const int _carNuber);
	void SetType(const char* _type);
	char* GetType();
	int GetCarNumber();
};



class Suv : public Car
{

private:


public:
	Suv() : Car() {}
	Suv(const int _carNumber) : Car(_carNumber)
	{
		SetType((const char*)"SUV");
	}
	Suv(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{}
	~Suv() {}
	
};

class Saloon : public Car
{


public:
	Saloon() : Car() {}
	Saloon(const int _carNumber) : Car(_carNumber)
	{
		SetType((const char*)"½Â¿ë");
	}
	Saloon(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{}
	~Saloon() {}



};