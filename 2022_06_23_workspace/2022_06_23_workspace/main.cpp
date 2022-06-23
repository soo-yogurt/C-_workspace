#include<iostream>
#include<conio.h>
#include<windows.h>
#include "AnimalHotel.h"
#include "Animal.h"


#define LASTROOMNUMBER 8
using namespace std;



int main(void)
{
	int button;
	Animal* dog00 = new Dog();
	Animal* cat00 = new Cat();
	AnimalHotel hotel;


	while (true) {
		button = 0;
		hotel.FrontDesk();
		cin >> button;

		while(button == 3){
			hotel.List();
			cout << "                           [esc]";
			char back = _getch();
			if (back == 27)
				break;
		}

		if (button == 1) {
			char num;
			int roomNum;
			system("cls");
			roomNum = hotel.checkRoom();
			while (true)
			{
				system("cls");
				cout << "어떤 동물인지 알려주세요" << endl;
				cout << " [1] 멍멍이" << endl;
				cout << " [2] 야옹이" << endl;
				cout << "             [ ]\b\b";
				cin >> num;
				if (num != '1' && num != '2')
				{
					cout << "1 또는 2를 선택해주세요";
				}
				else
					break;
			}
			char* name = new char[50];
			char* tpye1 = new char[4];
			system("cls");
			cout << " 동물 친구의 이름을 알려주세요 : ";
			cin >> name;
			if (num == '1') {
				dog00->SetName(name);
				tpye1 = dog00->GetType();
				hotel.CheckIn(roomNum, name, tpye1);
				dog00->Sound2();
			}
			else if (num == '2') {
				cat00->SetName(name);
				tpye1 = cat00->GetType();
				hotel.CheckIn(roomNum, name, tpye1);
				cat00->Sound2();
			}
			Sleep(1000);
			delete[] name;
			delete[] tpye1;
			button = 0;
		}
		if (button == 2)
		{
			if (hotel.CheckOut() == "Dog")
				dog00->Sound3();
			else
				cat00->Sound3();
			Sleep(1000);
		}
	}
	return 0;
}


