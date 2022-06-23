#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Animal
{
	char * name;
	int age;

public:
	Animal(const char *_name, const int _age)
	{
		int len = strlen(_name);
		name = new char[len + 1];
		strcpy(name, _name);
		age = _age;
	}
	virtual ~Animal() {
		delete[] name;
	}
	virtual void Eat() {}
	virtual void Sound() {}
	virtual void ShowName() {}

	char * GetName()
	{
		return name;
	}
};


class Cat : public Animal
{


public:
	Cat(const char* _name, const int _age)
		: Animal(_name, _age)
	{}
	virtual ~Cat() {
		
	}

	virtual void Eat()
	{
		cout << "냥냥 사료를 먹습니다." << endl;
	}
	virtual void Sound()
	{
		cout << "냥냥" << endl;
	}
	virtual void ShowName() 
	{
		cout << "저는 고양이고, " << GetName() << "입니다." << endl; 
	}
};

class Dog : public Animal
{

public:
	Dog(const char* _name, const int _age) : Animal(_name, _age) {}
	// 더 이상 상속이 없기 때문에 virtual 이 없어도 된다.
	// 다만 상속 클래스를 더 생성하여 Dog를 상속할 것이라면
	// virtual이 필요하다.
	virtual ~Dog() {}
	void Eat()
	{
		cout << "왁왁 사료를 먹습니다." << endl;
	}
	void Sound()
	{
		cout << "멍멍" << endl;
	}
	void ShowName() 
	{
		cout << "저는 강아지고, " << GetName() << "입니다." << endl;
	}
};


int main(void)
{
	Animal* dog01 = new Dog("누렁이", 1);
	dog01->Eat();
	dog01->ShowName();
	dog01->Sound();

	Animal* cat01 = new Cat("바둑이", 2);
	cat01->Eat();
	cat01->ShowName();
	cat01->Sound();
	cat01->GetName();

	delete[] dog01;
	delete[] cat01;

	return 0;
}