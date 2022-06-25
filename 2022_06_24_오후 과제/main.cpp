#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ParkingTower.h"
#include "Car.h"


//#define TEST1
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
		MenuButton = 0;
		parkingTower.DisplayMenu();
		MenuButton = _getch();


		if (MenuButton == '1') {
			parkingTower.Checkin();
		}

		if (MenuButton == '2')
		{
			parkingTower.CheckOut();
		}

		if (MenuButton == '3') {
			parkingTower.DisplsyParkingSpace();
		}
	}
	return 0;
}

#endif TEST1