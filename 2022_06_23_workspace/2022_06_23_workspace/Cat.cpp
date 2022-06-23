#include "Cat.h"
#include <iostream>

using namespace std;

char* Cat::GetType()
{
	return type;
}


void Cat::Sound()
{
	cout << "냥냥" << endl;
}

void Cat::Eat()
{
	cout << "냥냥 사료를 먹습니다." << endl;
}