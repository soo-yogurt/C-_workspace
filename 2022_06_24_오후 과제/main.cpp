#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ParkingTower.h"
#include "Car.h"


//#define TEST1 클래서 생성 종류에 따라 다른 코드를 짜고 이해하기(미완성)
using namespace std;


#ifdef TEST1
int main(void) {
	char MenuButton;
	ParkingTower* parkTower = new ParkingTower();

	while (true) {
		MenuButton = 0;
		parkTower->DisplayMenu();
		MenuButton = _getch();

		if (MenuButton == '1') {
			parkTower->Checkin();
		}

		if (MenuButton == '2')
		{
			parkTower->CheckOut();
		}

		if (MenuButton == '3') {
			parkTower->DisplsyParkingSpace();
		}
	}

	delete[] parkTower;
	return 0;
}


#else TEST1
int main(void) {

	char MenuButton;
	ParkingTower parkingTower;

	parkingTower.PrintOpenMessage();

	while (true) {
		system("cls");
		MenuButton = 0;
		parkingTower.DisplayMenu();
		MenuButton = _getch();


		if (MenuButton == '1') {
			system("cls");
			parkingTower.Checkin();
			Sleep(1000);
		}

		if (MenuButton == '2')
		{
			system("cls");
			parkingTower.CheckOut();
			Sleep(1000);
		}

		if (MenuButton == '3') {
			system("cls");
			parkingTower.DisplsyParkingSpace();
		}
	}
	return 0;
}

#endif TEST1