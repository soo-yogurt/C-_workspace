#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>


using namespace std;


class Person
{
	char* name;
	int age;

public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	explicit Person(const Person& copy)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
		age = (copy.age);
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}

	void ShowPersonInfo();

};

//int main(void)
//{
//	Person man1((char*)"Lee dong woo", 29);
//	Person man2(man1);
//	man1.ShowPersonInfo();
//	man2.ShowPersonInfo();
//	return 0;
//}

void Person::ShowPersonInfo()
{
	cout << "이름: " << name << endl;
	cout << "나이: " << age << endl;
}