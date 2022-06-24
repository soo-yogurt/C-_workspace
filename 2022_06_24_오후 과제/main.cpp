#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ParkTower.h"
#include "Car.h"

using namespace std;

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