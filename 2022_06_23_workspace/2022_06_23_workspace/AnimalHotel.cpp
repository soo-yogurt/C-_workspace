#include <cstring>
#include <windows.h>
#include "AnimalHotel.h"



void AnimalHotel::CheckIn()
{
	int num1;
	char num2;
	static int i = 0;

	AnimalHotel::List();

	cout << "호실을 골라주세요       [ ]\b\b";
	while (true) {
		cin >> num1;
		if ( ((num1 > 8) || num1 == 0) || (room[num1-1].checkin != 0))
			cout << "번호를 정확히 입력해주세요";
		else
			break;
	}

	while (true)
	{
		system("cls");
		cout << "어떤 동물인지 알려주세요" << endl;
		cout << " [1] 멍멍이" << endl;
		cout << " [2] 야옹이" << endl;
		cout << "             [ ]\b\b";
		cin >> num2;
		if (num2 != '1' && num2 != '2')
		{
			cout << "1 또는 2를 선택해주세요";
		}
		else
			break;
	}
	char* name = new char[50];


	system("cls");
	cout << " 동물 친구의 이름을 알려주세요 : ";
	cin >> name;

	if (num2 == '1') {
		room[num1 - 1].Guests = new Dog((const char*)name, "멍멍이");
	}
	else if (num2 == '2') {
		room[num1 - 1].Guests = new Cat((const char*)name, "야옹이");
	}
	room[num1 - 1].checkin = 1;
	room[num1 - 1].Guests->Sound2();

	delete[] name;
}


void AnimalHotel::CheckOut()
{
	int roomNum;

	system("cls");
	AnimalHotel::List();
	cout << " 호실을 알려주세요 ";
	cin >> roomNum;
	room[roomNum - 1].checkin = 0;
	room[roomNum - 1].Guests->Sound3();


}


void AnimalHotel::FrontDesk()
{
	system("cls");
	cout << "===============================" << endl;
	cout << "|  [1] CheckIn                |" << endl;
	cout << "|                             |" << endl;
	cout << "|  [2] CheckOut               |" << endl;
	cout << "|                             |" << endl;
	cout << "|  [3] LIST                   |" << endl;
	cout << "===============================" << endl;
	cout << "                            [ ]\b\b";
}
void AnimalHotel::List()
{
	system("cls");
	cout << "===============================" << endl;
	for (int i = 0; i < 8; i++)
	{
		if (room[i].checkin == 0)
			cout << "| " << i + 1 << "호실 : 빈방                 " << endl;
		else if(room[i].checkin == 1)
		{
			cout << "| " << i + 1 << "호실 : ";
			cout << room[i].Guests->GetType() << "(";
			cout << room[i].Guests->GetName() << ")" << endl;
		}
	}
	cout << "===============================" << endl;


}
