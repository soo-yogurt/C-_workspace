#include "Cat.h"
#include <iostream>

using namespace std;

char* Cat::GetType()
{
	return type;
}


void Cat::Sound()
{
	cout << "�ɳ�" << endl;
}

void Cat::Eat()
{
	cout << "�ɳ� ��Ḧ �Խ��ϴ�." << endl;
}