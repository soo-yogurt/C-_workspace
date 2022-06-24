#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string.h>


class Animal
{

private:
	char* name;
	char* type;
	int age;
public:
	Animal()
	{
		name = NULL;
		type = NULL;
		age = 0;
	}
	Animal(const char* _name, const char* _type, const int age = 0)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);

		type = new char[strlen(_type) + 1];
		strcpy(type, _type);

		this->age = age;
	}

	virtual ~Animal()
	{
		delete[] name;
		delete[] type;
	}

	int GetAge();
	char* GetName();
	char* GetType();

	void SetName(char* _name); // 이름 입력하기
	void SetType(const char* _type); // 타입 입력가기

	virtual void Eat() {} // 밥먹기
	virtual void Sound() {} // 소리내기
	virtual void Sound2() {} // 있다봐
	virtual void Sound3() {} // 안녕
};



class Dog : public Animal
{

public:
	Dog() : Animal() {}
	Dog(const char* _name, const char* _type, const int age = 0) : Animal(_name, _type, age)
	{}
	~Dog() {}

	void Eat();
	void Sound();
	void Sound3();
	void Sound2();
};


class Cat : public Animal
{


public:
	Cat() : Animal() {}
	Cat(const char* _name, const char* _type, const int age = 0) : Animal(_name, _type, age)
	{}
	~Cat() {}

	void Eat();
	void Sound();
	void Sound2();
	void Sound3();
};