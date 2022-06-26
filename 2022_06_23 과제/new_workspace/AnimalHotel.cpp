#include <cstring>
#include <windows.h>
#include "AnimalHotel.h"



void AnimalHotel::CheckIn()
{
	int num1;
	char num2;
	static int i = 0;

	AnimalHotel::List();

	cout << "ȣ���� ����ּ���       [ ]\b\b";
	while (true) {
		cin >> num1;
		if ( ((num1 > 8) || num1 == 0) || (room[num1-1].checkin != 0))
			cout << "��ȣ�� ��Ȯ�� �Է����ּ���";
		else
			break;
	}

	while (true)
	{
		system("cls");
		cout << "� �������� �˷��ּ���" << endl;
		cout << " [1] �۸���" << endl;
		cout << " [2] �߿���" << endl;
		cout << "             [ ]\b\b";
		cin >> num2;
		if (num2 != '1' && num2 != '2')
		{
			cout << "1 �Ǵ� 2�� �������ּ���";
		}
		else
			break;
	}
	char* name = new char[50];


	system("cls");
	cout << " ���� ģ���� �̸��� �˷��ּ��� : ";
	cin >> name;

	if (num2 == '1') {
		room[num1 - 1].Guests = new Dog((const char*)name, "�۸���");
	}
	else if (num2 == '2') {
		room[num1 - 1].Guests = new Cat((const char*)name, "�߿���");
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
	cout << " ȣ���� �˷��ּ��� ";
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
			cout << "| " << i + 1 << "ȣ�� : ���                 " << endl;
		else if(room[i].checkin == 1)
		{
			cout << "| " << i + 1 << "ȣ�� : ";
			cout << room[i].Guests->GetType() << "(";
			cout << room[i].Guests->GetName() << ")" << endl;
		}
	}
	cout << "===============================" << endl;


}
