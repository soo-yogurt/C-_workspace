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
	cout << " ³É³É ¾È³ç" << endl;
}
void Cat::Sound2()
{
	cout << " ³É³É ÀÖ´ÙºÁ" << endl;
}
void Cat::Sound()
{
	cout << " ³É³É" << endl;
}

void Cat::Eat()
{
	cout << " ³É³É »ç·á¸¦ ¸Ô½À´Ï´Ù." << endl;
}

char* Cat::GetType(){
	return type;
}




void Dog::Sound()
{
	cout << " ¿Ð¿Ð" << endl;
}

void Dog::Eat()
{
	cout << " ¿Ð¿Ð »ç·á¸¦ ¸Ô½À´Ï´Ù." << endl;
}


char* Dog::GetType()
{
	return type;
}

void Dog::Sound3()
{
	cout << " ¿Ð¿Ð ¾È³ç" << endl;
}
void Dog::Sound2()
{
	cout << " ¿Ð¿Ð ÀÖ´ÙºÁ" << endl;
}