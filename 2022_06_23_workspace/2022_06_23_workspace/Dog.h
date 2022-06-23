#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Animal.h"
#include<iostream>

class Dog : public Animal
{
	char* type;

public:
	Dog(char* name, int age) : Animal(name, age)
	{
		int len = strlen("Dog");
		type = new char[len + 1];
		strcpy(type, "Dog");
	}
	~Dog(){
		delete[] type;
	}

	char* GetType();
	void Sound();
	void Eat();
};