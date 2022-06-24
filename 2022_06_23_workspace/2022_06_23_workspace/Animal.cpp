#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Animal.h"
#include "string.h"

using namespace std;

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//

int Animal::GetAge()
{
	return age;
}

char* Animal::GetName()
{
	return this->name;
}

char* Animal::GetType()
{
	return type;
}


void Animal::SetName(char* _name)
{
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Animal::SetType(const char* _type)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
}


//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//



void Cat::Sound()
{
	cout << " �ɳ�" << endl;
}

void Cat::Sound2()
{
	cout << " �ɳ� �ִٺ�" << endl;
}

void Cat::Sound3()
{
	cout << " �ɳ� �ȳ�" << endl;
}

void Cat::Eat()
{
	cout << " �ɳ� ��Ḧ �Խ��ϴ�." << endl;
}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//


void Dog::Eat()
{
	cout << " �п� ��Ḧ �Խ��ϴ�." << endl;
}

void Dog::Sound()
{
	cout << " �п�" << endl;
}

void Dog::Sound2()
{
	cout << " �п� �ִٺ�" << endl;
}

void Dog::Sound3()
{
	cout << " �п� �ȳ�" << endl;
}


