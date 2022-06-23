#include "AnimalHotel.h"
#include <cstring>
#include <windows.h>


void AnimalHotel::CheckIn(const int _room, const char* _name, const char* _type)
{
	room[_room - 1].guest.name = new char[strlen(_name) + 1];
	strcpy(room[_room - 1].guest.name, _name);

	room[_room - 1].guest.type = new char[strlen(_type) + 1];
	strcpy(room[_room - 1].guest.type, _type);
}

int AnimalHotel::checkRoom()
{
	int num;
	AnimalHotel::List();
	cout << "호실을 골라주세요    [ ]\b\b";
	while (true) {
		cin >> num;
		if ((num !=0) &&(room[num-1].guest.name != 0))
			cout << "번호를 정확히 입력해주세요";
		else if (room[num - 1].guest.name == 0)
			return num;
	}

}

char* AnimalHotel::CheckOut()
{
	int roomNum;
	char * type;
	system("cls");
	AnimalHotel::List();
	cout << " 호실을 알려주세요 ";
	cin >> roomNum;
	type = room[roomNum - 1].guest.type;
	room[roomNum - 1].guest.name = NULL;
	room[roomNum - 1].guest.type = NULL;
	return type;
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
	int state[8];
	memset(state, 0, sizeof(state));
	for (int i = 0; i < 8; i++) {
		if (room[i].guest.name != 0)
			state[i] = 1;
	}

	cout << "===============================" << endl;
	for (int i = 0; i < 8; i++) 
	{
		if (state[i] == 0)
			cout << "| " << room[i].roomNum << "호실 : 빈방                 " << endl;
		else
			cout << "| " << room[i].roomNum << "호실 : " << room[i].guest.type << "(" << room[i].guest.name << ")" << endl;
	}
	cout << "===============================" << endl;
	
}



