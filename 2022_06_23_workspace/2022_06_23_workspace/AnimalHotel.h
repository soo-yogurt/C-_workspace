#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<cstring>
#include<cstdint>
#include "Animal.h"
using namespace std;

// 호텔 클레스에서 어떻게 해야 Animal 클래스의 정보를 사용할 수 있을지 잘모르겠습니다.

class AnimalHotel
{
	enum {
		LASTROOMNUMBER = 8
	};

	// 호텔측에서 가지고 있어야하는 손님 정보라는 생각으로 작성하였다.
	typedef struct {
		char* name;
		char* type;
	}GUEST;

	typedef struct {
		int roomNum;
		GUEST guest;
	}ROOM;

private:
	ROOM* room = new ROOM[LASTROOMNUMBER];
public:
	AnimalHotel()
	{
		// 빈방인지 아닌지 손님의 이름을 보고 확인한다. 이름이 0이면 빈방
		memset(room, 0, sizeof(ROOM) * LASTROOMNUMBER);
		// 호실 번호를 정하는 부분이다. 1호실 2호실... 으로 사용하고  있기 때문에 현재 코드에서는 크게 의미 없다.
		// 편의에 따라 101호 102호등으로 바꾸기 위해 작성하였다.
		for (int i = 0; i < 8; i++)
			room[i].roomNum = i + 1;
	}
	~AnimalHotel()
	{
		delete[] room;
	}

	
	void CheckIn(const int room, const char* _name, const char* _type); // 입실에 필요한 정보를 받아 체크인
	int checkRoom(); // 사용자가 비어있는 방만 고를 수 있게 해준다.
	char* CheckOut(); // 호실을 말하면 체크아웃을 할 수 있다.
	void FrontDesk();// 시작 메뉴를 불러온다.
	void List(); // 호실별로 입실 현황을 알려준다.

};