#include<iostream>
#include "Animal.h"


using namespace std;

void Animal::SetName(char * _name)
{
	int len = strlen(_name);
	this->name = new char[len + 1];
	strcpy(this->name, _name);
}

char* Animal::GetName()
{
	return this->name;
}
int Animal::GetAge()
{
	return age;
}


void Cat::Sound3()
{
	cout << " �ɳ� �ȳ�" << endl;
}
void Cat::Sound2()
{
	cout << " �ɳ� �ִٺ�" << endl;
}
void Cat::Sound()
{
	cout << " �ɳ�" << endl;
}

void Cat::Eat()
{
	cout << " �ɳ� ��Ḧ �Խ��ϴ�." << endl;
}

char* Cat::GetType(){
	return type;
}




void Dog::Sound()
{
	cout << " �п�" << endl;
}

void Dog::Eat()
{
	cout << " �п� ��Ḧ �Խ��ϴ�." << endl;
}


char* Dog::GetType()
{
	return type;
}

void Dog::Sound3()
{
	cout << " �п� �ȳ�" << endl;
}
void Dog::Sound2()
{
	cout << " �п� �ִٺ�" << endl;
}