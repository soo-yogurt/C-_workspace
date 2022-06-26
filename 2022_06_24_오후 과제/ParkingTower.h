#pragma once
#include "Car.h"
constexpr auto SPACE = 8;

//#define DEBUG
#ifdef DEBUG

class ParkingTower
{
	// 주차 공간... 
	Car* parkingSpace = new Car[SPACE];
	//Car * parkingSpace[SPACE];
public:
	// 체크인 함수에서 초기화를 하려고 했지만 DisplsyParkingSpace(); 함수에서
	// 체크인과 상관없이 모두 불러와야하기 때문에 생성자에서 모두 초기화하였다.
	ParkingTower()
	{
		for (int i = 0; i < 8; i++) {
			parkingSpace[i].SetCarNumber(0);
			parkingSpace[i].SetType("NULL");
			//parkingSpace[i]->SetCarNumber(0);
			//parkingSpace[i]->SetType("NULL");
		}
	}
	~ParkingTower()
	{
		delete[] parkingSpace;
	}
	
	void Checkin();
	void CheckOut();
	void DisplayMenu();
	void DisplsyParkingSpace();
	void PrintSuccessMessage();
	void ParkingCheck();
	void PrintOpenMessage();
	void PrintClosedMessage();

};

#else DEBUG

class ParkingTower
{
	// 주차 공간... 
	Car * parkingSpace[SPACE];

public:

	ParkingTower()
	{
		for (int i = 0; i < 8; i++) {
			parkingSpace[i] = new Car(0,"NULL");
		}
	}
	~ParkingTower() {}
	
	// 입고 함수
	void Checkin();
	// 출고 함수
	void CheckOut();
	// 시작화면
	void DisplayMenu();
	// 주차 현황 - 지도
	void DisplsyParkingSpace();
	// 주차 현황 - 숫자
	void ParkingCheck();

	// 설명 문구 // std::cout
	void PrintSuccessMessage();
	void PrintOpenMessage();
	void PrintClosedMessage();
	void PrintNiceDay();
};


#endif DEBUG
