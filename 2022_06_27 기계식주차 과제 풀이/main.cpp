#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "Suv.h"
#include "Sedan.h"
#include "Car.h" 

// Car.h
// virtual 을 사용하였기 함수를 만들었기 때문에 virtual을 사용하여 소멸자도 만들어주어야한다.
// 
// 
// Car.cpp
// 자료형이 (char*)를 반환 한다는 것은 반환 받은곳에서 값을 변경 할 수 있다는
// 것을 의미한다. 하지만 상수를 강제로 캐스팅 하였기 반환 하였기때문에 변경이 불가능한 상태이다.
// 때문에 의미를 정확히 알려주기 위해 자료형을 const char*로 변경하였다.


// main.cpp
// delete를 사용할 경우 체크 아웃 마다 delete 후 0을 다시 넣어서 초기화 해주어야한다.
// 59, 60 줄 내용 추가


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
// delete를 사용할 경우 체크 아웃 마다 delete 후 0을 다시 넣어서 초기화 해주어야한다.
// 59, 60 줄 내용 추가
int main(void) {


	Car* cars[8];
	// 0으로 초기화
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
			cout << "비어있음" << endl;
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
			cout << "비어있음" << endl;
		}
		else
		{
			cout << cars[i]->GetType() << endl;
		}
	}

	return 0;
}

#endif DEBUG