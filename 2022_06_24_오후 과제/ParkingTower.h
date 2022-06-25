#pragma once
#include "Car.h"
constexpr auto SPACE = 8;

//#define DEBUG
#ifdef DEBUG

class ParkingTower
{
	// ���� ����... 
	Car* parkingSpace = new Car[SPACE];
	//Car * parkingSpace[SPACE];
public:
	// üũ�� �Լ����� �ʱ�ȭ�� �Ϸ��� ������ DisplsyParkingSpace(); �Լ�����
	// üũ�ΰ� ������� ��� �ҷ��;��ϱ� ������ �����ڿ��� ��� �ʱ�ȭ�Ͽ���.
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
	// ���� ����... 
	Car * parkingSpace[SPACE];
public:

	ParkingTower()
	{
		for (int i = 0; i < 8; i++) {
			parkingSpace[i] = new Car();
		}
	}
	~ParkingTower() {}
	
	void Checkin();
	void CheckOut();
	void DisplayMenu();
	void DisplsyParkingSpace();
	void PrintSuccessMessage();
	void ParkingCheck();
	void PrintOpenMessage();
	void PrintClosedMessage();

};


#endif DEBUG
