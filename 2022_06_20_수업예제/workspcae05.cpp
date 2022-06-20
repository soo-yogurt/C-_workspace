#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Animal
{
private:
	char* name;
	int age;
public:

	Animal(char* _name, int _age)
	{
		int len = strlen(_name);
		name = new char[len + 1];
		strcpy(name, _name);
		age = _age;
	}
	void Eat()
	{
		cout << "»ç·á¸¦ ¸Ô½À´Ï´Ù." << endl;
	}
	~Animal()
	{
		delete[] name;
	}
};


class Dog : public Animal
{
public:
	Dog(char* _name, int age) : Animal(_name, age)
	{

	}

	void Bark()
	{
		cout << "¿Ð¿Ð" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(char* _name, int age) : Animal(_name, age)
	{

	}

	void Bark()
	{
		cout << "¾ß¿Ë" << endl;
	}
};


//int main(void)
//{
//	Animal a ((char*)"BB", 0);
//	a.Eat();
//	Cat c((char*)"cc", 1);
//	c.Bark();
//
//
//	return 0;
//}