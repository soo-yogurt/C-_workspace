#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>


class Animal
{
private:
	char* name;
	int age;

public:
	Animal() 
	{
		name = NULL;
		age = 0;
	}
	Animal(const char * name, const int age = 0)
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
	virtual char* GetType() 
	{
		return 0;
	}
	void SetName(char* _name);
	virtual void Sound3() {}
	virtual void Sound2() {}
};



class Dog : public Animal
{
	char* type;
public:
	Dog(const char* name, const int age) : Animal(name, age)
	{
		int len = strlen("Dog");
		type = new char[len + 1];
		strcpy(type, "Dog");
	}
	Dog() : Animal()
	{
		int len = strlen("Dog");
		type = new char[len + 1];
		strcpy(type, "Dog");
	}
	~Dog() {
		delete[] type;
	}

	char* GetType();
	void Sound();
	void Eat();
	void Sound3();
	void Sound2();
};


class Cat : public Animal
{
	char* type;
public:
	Cat(const char* name, const int age) : Animal(name, age)
	{
		int len = strlen("Cat");
		type = new char[len + 1];
		strcpy(type, "Cat");

	}
	Cat() : Animal()
	{
		int len = strlen("Cat");
		type = new char[len + 1];
		strcpy(type, "Cat");
	}

	~Cat() {
		delete[] type;
	}
	void Sound3();
	void Sound2();
	char* GetType();
	void Sound();
	void Eat();

};