#pragma once
class Car
{
	int number;
public:
	Car(int _num);

	virtual const char* GetType();
	int GetNumber();
	// virtual �� ����Ͽ��� ������ virtual�� ����Ͽ� �Ҹ��ڸ� ������־���Ѵ�.
	virtual ~Car() {}
};

