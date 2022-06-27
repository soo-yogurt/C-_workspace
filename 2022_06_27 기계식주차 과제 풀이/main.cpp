#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "Suv.h"
#include "Sedan.h"
#include "Car.h" 

// Car.h
// virtual �� ����Ͽ��� �Լ��� ������� ������ virtual�� ����Ͽ� �Ҹ��ڵ� ������־���Ѵ�.
// 
// 
// Car.cpp
// �ڷ����� (char*)�� ��ȯ �Ѵٴ� ���� ��ȯ ���������� ���� ���� �� �� �ִٴ�
// ���� �ǹ��Ѵ�. ������ ����� ������ ĳ���� �Ͽ��� ��ȯ �Ͽ��⶧���� ������ �Ұ����� �����̴�.
// ������ �ǹ̸� ��Ȯ�� �˷��ֱ� ���� �ڷ����� const char*�� �����Ͽ���.


// main.cpp
// delete�� ����� ��� üũ �ƿ� ���� delete �� 0�� �ٽ� �־ �ʱ�ȭ ���־���Ѵ�.
// 59, 60 �� ���� �߰�


using namespace std;
//#define DEBUG

#ifdef DEBUG

int main(void) {


	Car* ptr = new Sedan(1234);
	cout << ptr->GetNumber() << endl;
	cout << ptr->GetType() << endl;
	delete ptr;

	ptr = new Suv(4321);
	cout << ptr->GetNumber() << endl;
	cout << ptr->GetType() << endl;
	delete ptr;

	return 0;
}

#else
// delete�� ����� ��� üũ �ƿ� ���� delete �� 0�� �ٽ� �־ �ʱ�ȭ ���־���Ѵ�.
// 59, 60 �� ���� �߰�
int main(void) {


	Car* cars[8];
	// 0���� �ʱ�ȭ
	for (int i = 0; i < 8; i++)
	{
		cars[i] = 0;
	}

	cars[2] = new Sedan(1234);
	cars[6] = new Suv(4321);

	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ": ";
		if (cars[i] == 0)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << cars[i]->GetType() << endl;
		}
	}

	cout << " ==================== " << endl;
	delete cars[2];
	cars[2] = 0;

	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ": ";
		if (cars[i] == 0)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << cars[i]->GetType() << endl;
		}
	}

	return 0;
}

#endif DEBUG