#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include "Animal.h"
using namespace std;

// ȣ�� Ŭ�������� ��� �ؾ� Animal Ŭ������ ������ ����� �� ������ �߸𸣰ڽ��ϴ�.


class AnimalHotel
{
	enum {
		LASTROOM = 8
	};

	struct ROOM {
		int checkin = 0;
		Animal* Guests;
	};


private:
	ROOM room[LASTROOM];

public:
	AnimalHotel() {}
	~AnimalHotel()
	{}

	// �Խǿ� �ʿ��� ������ �޾� üũ��
	void CheckIn();

	// ȣ���� ���ϸ� üũ�ƿ��� �� �� �ִ�.
	void CheckOut();

	// ���� �޴��� �ҷ��´�.
	void FrontDesk();

	// ȣ�� ���� �Խ��� �˷��ش�.
	void List();

};