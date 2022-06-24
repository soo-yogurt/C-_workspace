#pragma once
#include "Car.h"
constexpr auto SPACE = 8;


class ParkingTower
{
	// 주차 공간... 
	Car* parkingSpace = new Car[SPACE];

public:
	ParkingTower()
	{
		for (int i = 0; i < 8; i++) {
			parkingSpace[i].SetCarNumber((int)0);
			parkingSpace[i].SetType("NULL");
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
	

};

