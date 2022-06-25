#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#pragma warning(disable:4996)


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
	virtual char* GetType();
	int GetCarNumber();
};


class Suv : public Car
{

public:
	Suv() : Car() {}
	Suv(const int _carNumber) : Car(_carNumber)
	{
		Car::SetType("SUV");
	}
	Suv(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{}
	~Suv() {}
	
	char* GetType();

};

class Sedan : public Car
{


public:
	Sedan() : Car() {}
	Sedan(const int _carNumber) : Car(_carNumber)
	{
		Car::SetType("Sedan");
	}
	Sedan(const int _carNumber, const char* _type) : Car(_carNumber, _type)
	{}
	~Sedan() {}

	char* GetType();

};