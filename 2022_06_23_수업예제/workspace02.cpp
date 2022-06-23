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
		cout << "�ɳ� ��Ḧ �Խ��ϴ�." << endl;
	}
	virtual void Sound()
	{
		cout << "�ɳ�" << endl;
	}
	virtual void ShowName() 
	{
		cout << "���� ����̰�, " << GetName() << "�Դϴ�." << endl; 
	}
};

class Dog : public Animal
{

public:
	Dog(const char* _name, const int _age) : Animal(_name, _age) {}
	// �� �̻� ����� ���� ������ virtual �� ��� �ȴ�.
	// �ٸ� ��� Ŭ������ �� �����Ͽ� Dog�� ����� ���̶��
	// virtual�� �ʿ��ϴ�.
	virtual ~Dog() {}
	void Eat()
	{
		cout << "�ο� ��Ḧ �Խ��ϴ�." << endl;
	}
	void Sound()
	{
		cout << "�۸�" << endl;
	}
	void ShowName() 
	{
		cout << "���� ��������, " << GetName() << "�Դϴ�." << endl;
	}
};


int main(void)
{
	Animal* dog01 = new Dog("������", 1);
	dog01->Eat();
	dog01->ShowName();
	dog01->Sound();

	Animal* cat01 = new Cat("�ٵ���", 2);
	cat01->Eat();
	cat01->ShowName();
	cat01->Sound();
	cat01->GetName();

	delete[] dog01;
	delete[] cat01;

	return 0;
}