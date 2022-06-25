#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ParkTower.h"
#include "Car.h"

#define TEST0
//#define TEST1
using namespace std;


#ifdef TEST0
int main(void) {

	char MenuButton;
	ParkingTower parkTower;

	while (true) {
		MenuButton = 0;
		parkTower.DisplayMenu();
		MenuButton = _getch();
	

		if (MenuButton == '1') {
			parkTower.Checkin();
		}

		if (MenuButton == '2') 
		{
			parkTower.CheckOut();
		}

		if (MenuButton == '3') {
			parkTower.DisplsyParkingSpace();
		}
	}
	return 0;
}
#endif TEST0
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

#endif TEST1