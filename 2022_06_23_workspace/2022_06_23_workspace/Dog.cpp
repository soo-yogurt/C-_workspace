#include "Dog.h"
#include <iostream>

using namespace std;

char* Dog::GetType()
{
	return type;
}

void Dog::Sound()
{
	cout << "¿Ð¿Ð" << endl;
}

void Dog::Eat()
{
	cout << "¿Ð¿Ð »ç·á¸¦ ¸Ô½À´Ï´Ù." << endl;
}