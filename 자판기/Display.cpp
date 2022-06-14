#include<iostream>
#include "vending_machine.h"

using namespace std;

// 구입할 수 있는 음료 목록
void JuiceList(JUICE* juice)
{
	cout << "음료 목록" << endl;
	cout << "==========================================================================\n";
	cout << "음료 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n금액 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0)
			cout << "  " << juice[i].price << "원" << "\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}



void JuiceList(JUICE* juice, int money) {
	cout << "구입할 수 있는 음료 목록" << "                          " << "투입한 금액 : " << money << "원" << endl;
	cout << "==========================================================================\n";
	cout << "음료 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price)) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n금액 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price))
			cout << "  " << juice[i].price << "원" << "\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}



void Print_Juice(JUICE* juice, int number)
{
	number++;
	for (int i = 0; i <= sizeof(JUICE) / 6; i++) {
		if (number == juice[i].menu_number)
			cout << juice[i].juice_name << "이(가) 나왔습니다." << endl;
	}
}

void Return_to_money_2()
{
	system("cls");
	printf("                        음료가 모두 소진되었습니다. 금액을 반환합니다.\r");
}


void Return_to_money()
{
	system("cls");
	printf("                                                    금액을 반환합니다.\r");
}


void Check_juice(JUICE* juice, int* juice_number)
{
	if (*juice_number > sizeof(JUICE) / 6) {
		cout << "없는 메뉴입니다.\n";
	}

}