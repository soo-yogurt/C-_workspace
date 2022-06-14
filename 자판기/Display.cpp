#include<iostream>
#include "vending_machine.h"

using namespace std;

// ������ �� �ִ� ���� ���
void JuiceList(JUICE* juice)
{
	cout << "���� ���" << endl;
	cout << "==========================================================================\n";
	cout << "���� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n�ݾ� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0)
			cout << "  " << juice[i].price << "��" << "\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}



void JuiceList(JUICE* juice, int money) {
	cout << "������ �� �ִ� ���� ���" << "                          " << "������ �ݾ� : " << money << "��" << endl;
	cout << "==========================================================================\n";
	cout << "���� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price)) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n�ݾ� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price))
			cout << "  " << juice[i].price << "��" << "\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}



void Print_Juice(JUICE* juice, int number)
{
	number++;
	for (int i = 0; i <= sizeof(JUICE) / 6; i++) {
		if (number == juice[i].menu_number)
			cout << juice[i].juice_name << "��(��) ���Խ��ϴ�." << endl;
	}
}

void Return_to_money_2()
{
	system("cls");
	printf("                        ���ᰡ ��� �����Ǿ����ϴ�. �ݾ��� ��ȯ�մϴ�.\r");
}


void Return_to_money()
{
	system("cls");
	printf("                                                    �ݾ��� ��ȯ�մϴ�.\r");
}


void Check_juice(JUICE* juice, int* juice_number)
{
	if (*juice_number > sizeof(JUICE) / 6) {
		cout << "���� �޴��Դϴ�.\n";
	}

}