#include "Dog.h"
#include <iostream>

using namespace std;

char* Dog::GetType()
{
	return type;
}

void Dog::Sound()
{
	cout << "�п�" << endl;
}

void Dog::Eat()
{
	cout << "�п� ��Ḧ �Խ��ϴ�." << endl;
}