#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vending_main.h"
#include "VendingMachine.h"
#include <conio.h>
#include <windows.h>
#include <stdint.h>

#define DRINK_NUM 4


int main(void) {
	int MachineNumber;

	uint8_t flag = 0;

	// 사용자가 원하는 음료를 입력하기 위해 구조체 2개를 동적 할당였다. 
	DRINK * carbonatedDrink = new DRINK[DRINK_NUM];
	DRINK * jucie = new DRINK[DRINK_NUM];

	// 구조체를 초기화 하기 위한 함수
	DrinkBox(carbonatedDrink, jucie);

	//클래스 객체 2개를 생성하였다. 0 = > 탄산 , 1 = > 과일
	VendingMahing1::VendingMachine Drink[2];

	// 위에서 초기화한 구조체를 생성한 객체에 넣기 위한 함수
	// 구조체를 한번에 넣고 싶었는데 방법을 몰라 하나씩 매개변수로 선언하였다.
	Drink[0].AddDrink(carbonatedDrink[0].drinkName, carbonatedDrink[0].price, carbonatedDrink[0].numOfdrink,
		carbonatedDrink[1].drinkName, carbonatedDrink[1].price, carbonatedDrink[1].numOfdrink,
		carbonatedDrink[2].drinkName, carbonatedDrink[2].price, carbonatedDrink[2].numOfdrink,
		carbonatedDrink[3].drinkName, carbonatedDrink[3].price, carbonatedDrink[3].numOfdrink);
	Drink[1].AddDrink(jucie[0].drinkName, jucie[0].price, jucie[0].numOfdrink,
		jucie[1].drinkName, jucie[1].price, jucie[1].numOfdrink,
		jucie[2].drinkName, jucie[2].price, jucie[2].numOfdrink,
		jucie[3].drinkName, jucie[3].price, jucie[3].numOfdrink);

	// main에서 선언한 구조체는 사용이 끝났기 때문에 제거하였다.
	delete[]carbonatedDrink;
	delete[]jucie;


	while (true)
	{
		//자판기 선택
		if(flag == 0) 
		{
			system("cls");
			MachineNumber = Display_ChoiceVendingMachine();
			system("cls");
			if(MachineNumber == 0)
				cout << " 탄산음료 자판기를 선택했습니다.";
			else
				cout << " 과일주스 자판기를 선택했습니다.";

			flag = 1;
		}
		//돈 넣기
		if (flag == 1)
		{
			int money;
			cout << " 돈을 넣어주세요" << " =====> " << " ";
			cin >> money;
			Drink[MachineNumber].SetMoney(money);
			system("cls");
			flag = 2;
		}

		//음료 선택
		if (flag == 2)
		{
			int drinkNum;
			Drink[MachineNumber].PrintDrinkList();
			cout << "                                                   ";
			cout << "남은 돈 : " << Drink[MachineNumber].GetMoney() << "원" << endl;
			cout << "\n [0] ~ [3] 음료수를 선택해주세요 /\n";
			cout << " [5] 돈 더 넣기 / [6] 돈 반환하기 / [7] 처음으로 돌아가기\n =====>[ ]\b\b";
			if (Drink[MachineNumber].CheckingAccounts() == false)
			{
				Drink[MachineNumber].SetMoney();
				cout << " 3초 후처음화면으로 돌아갑니다.\n";
				flag = 0;
				Sleep(3000);
			}
			while (flag == 2) {
				cin >> drinkNum;
				cout << "\n";
				if (drinkNum == 5)
					flag = 1;
				else if (drinkNum == 6)
				{
					Drink[MachineNumber].SetMoney();
					system("cls");
					break;
				}
				else if (drinkNum == 7) 
				{
					flag = 0;
					Drink[MachineNumber].SetMoney();
				}
				else if (drinkNum < 0 || drinkNum > 5) {
					cout << " 다시 입력해주세요";
					cout << " 숫자를 입력해주세요 =====> [ ]\b\b";
				}
				else {
					system("cls");
					Drink[MachineNumber].PrintDrinkList();
					cout << "                                                   ";
					cout << "남은 돈 : " << Drink[MachineNumber].GetMoney() << "원" << endl;
					Drink[MachineNumber].PrintPushDrink(drinkNum);
					Drink[MachineNumber].PushDrink(drinkNum);
					cout << "\n [0] ~ [3] 음료수를 선택해주세요 /\n";
					cout << " [5] 돈 더 넣기 / [6] 돈 반환하기 / [7] 처음으로 돌아가기\n =====>[ ]\b\b";
					if (Drink[MachineNumber].CheckingAccounts() == false)
					{
						Drink[MachineNumber].SetMoney();
						cout << " 4초 후처음화면으로 돌아갑니다.\n";
						flag = 0;
						Sleep(4000);
					}
				}
			}
		}
	}
	return 0;
}


void Line() 
{
	cout << "======================================================================\n";
}

int Display_ChoiceVendingMachine() {
	char num;
	Line();
	cout << " [자판기 선택]\n";
	Line();
	cout << " [0번] 탄산자판기 / [1번] 과일주스자판기\n" << endl;
	cout << " 숫자를 입력해주세요 [ ]\b\b";
	cin >> num;
	while (true) {
		cout << endl;
		if (num == '0' || num == '1')
			return (int) num - '0';
		else {
			cout << endl;
			cout << " 다시 입력해주세요" << endl;
			cout << " 숫자를 입력해주세요 =====> [ ]\b\b";
			cin >> num;
		}
	}
	Line();
}

void DrinkBox(DRINK* drink, DRINK* jucie) {
	strcpy(drink[0].drinkName, "코카콜라");
	strcpy(drink[1].drinkName, "팹시제로");
	strcpy(drink[2].drinkName, "사이다");
	strcpy(drink[3].drinkName, "스프라이트");

	drink[0].numOfdrink = 10;
	drink[1].numOfdrink = 10;
	drink[2].numOfdrink = 10;
	drink[3].numOfdrink = 10;

	drink[0].price = 2000;
	drink[1].price = 1500;
	drink[2].price = 1500;
	drink[3].price = 1500;


	strcpy(jucie[0].drinkName, "사과주스");
	strcpy(jucie[1].drinkName, "코코넛주스");
	strcpy(jucie[2].drinkName, "포도주스");
	strcpy(jucie[3].drinkName, "키위주스");

	jucie[0].numOfdrink = 10;
	jucie[1].numOfdrink = 10;
	jucie[2].numOfdrink = 10;
	jucie[3].numOfdrink = 10;

	jucie[0].price = 2000;
	jucie[1].price = 2500;
	jucie[2].price = 2000;
	jucie[3].price = 3000;
}
