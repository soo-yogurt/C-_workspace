#pragma once
class Car
{
	int number;
public:
	Car(int _num);

	virtual const char* GetType();
	int GetNumber();
	// virtual 을 사용하였기 때문에 virtual을 사용하여 소멸자를 만들어주어야한다.
	virtual ~Car() {}
};

