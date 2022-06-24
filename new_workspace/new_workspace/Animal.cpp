#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Animal.h"
#include "string.h"

using namespace std;

//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天//

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


//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天//



void Cat::Sound()
{
	cout << " 傖傖" << endl;
}

void Cat::Sound2()
{
	cout << " 傖傖 氈棻瑭" << endl;
}

void Cat::Sound3()
{
	cout << " 傖傖 寰喟" << endl;
}

void Cat::Eat()
{
	cout << " 傖傖 餌猿蒂 詳蝗棲棻." << endl;
}



//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天//


void Dog::Eat()
{
	cout << " 諱諱 餌猿蒂 詳蝗棲棻." << endl;
}

void Dog::Sound()
{
	cout << " 諱諱" << endl;
}

void Dog::Sound2()
{
	cout << " 諱諱 氈棻瑭" << endl;
}

void Dog::Sound3()
{
	cout << " 諱諱 寰喟" << endl;
}


