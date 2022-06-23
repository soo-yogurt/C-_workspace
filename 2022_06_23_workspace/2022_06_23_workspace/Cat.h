#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Animal.h"
#include<iostream>

class Cat : public Animal
{
	char* type;
public:
	Cat(char* name, int age) : Animal(name, age)
	{
		int len = strlen("Cat");
		type = new char[len + 1];
		strcpy(type, "Cat");
	}
	~Cat() {
		delete[] type;
	}

	char* GetType();
	void Sound();
	void Eat();
};