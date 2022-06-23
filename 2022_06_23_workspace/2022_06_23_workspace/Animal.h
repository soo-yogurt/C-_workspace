#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>

class Animal
{
private:
	char* name;
	int age;

public:
	Animal(char * name, int age)
	{
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);

		this->age = age;
	}

	virtual ~Animal()
	{
		delete[] name;
	}

	char* GetName();
	int GetAge();
	virtual void Sound (){}
	virtual void Eat() {}
};
