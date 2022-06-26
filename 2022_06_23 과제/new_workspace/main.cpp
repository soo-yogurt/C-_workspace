#include <iostream>
#include <windows.h>
#include <conio.h>
#include "AnimalHotel.h"
#include "Animal.h"


#define LASTROOMNUMBER 8
using namespace std;

int main(void)
{
	int button;
	AnimalHotel hotel;

	while (true) {
		hotel.FrontDesk();
		cin >> button;

		if (button == 3) {
			hotel.List();
			cout << "                           [esc]";
			char back = _getch();
			if (back == 27)
				button = 0;
		}

		if (button == 1) {
			hotel.CheckIn();
			Sleep(1000);
			button = 0;
		}

		if (button == 2)
		{
			hotel.CheckOut();
			Sleep(1000);
			button = 0;
		}
	}
	return 0;
}