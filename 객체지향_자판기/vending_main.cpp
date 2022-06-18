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

	// ����ڰ� ���ϴ� ���Ḧ �Է��ϱ� ���� ����ü 2���� ���� �Ҵ翴��. 
	DRINK * carbonatedDrink = new DRINK[DRINK_NUM];
	DRINK * jucie = new DRINK[DRINK_NUM];

	// ����ü�� �ʱ�ȭ �ϱ� ���� �Լ�
	DrinkBox(carbonatedDrink, jucie);

	//Ŭ���� ��ü 2���� �����Ͽ���. 0 = > ź�� , 1 = > ����
	VendingMahing1::VendingMachine Drink[2];

	// ������ �ʱ�ȭ�� ����ü�� ������ ��ü�� �ֱ� ���� �Լ�
	// ����ü�� �ѹ��� �ְ� �;��µ� ����� ���� �ϳ��� �Ű������� �����Ͽ���.
	Drink[0].AddDrink(carbonatedDrink[0].drinkName, carbonatedDrink[0].price, carbonatedDrink[0].numOfdrink,
		carbonatedDrink[1].drinkName, carbonatedDrink[1].price, carbonatedDrink[1].numOfdrink,
		carbonatedDrink[2].drinkName, carbonatedDrink[2].price, carbonatedDrink[2].numOfdrink,
		carbonatedDrink[3].drinkName, carbonatedDrink[3].price, carbonatedDrink[3].numOfdrink);
	Drink[1].AddDrink(jucie[0].drinkName, jucie[0].price, jucie[0].numOfdrink,
		jucie[1].drinkName, jucie[1].price, jucie[1].numOfdrink,
		jucie[2].drinkName, jucie[2].price, jucie[2].numOfdrink,
		jucie[3].drinkName, jucie[3].price, jucie[3].numOfdrink);

	// main���� ������ ����ü�� ����� ������ ������ �����Ͽ���.
	delete[]carbonatedDrink;
	delete[]jucie;


	while (true)
	{
		//���Ǳ� ����
		if(flag == 0) 
		{
			system("cls");
			MachineNumber = Display_ChoiceVendingMachine();
			system("cls");
			if(MachineNumber == 0)
				cout << " ź������ ���Ǳ⸦ �����߽��ϴ�.";
			else
				cout << " �����ֽ� ���Ǳ⸦ �����߽��ϴ�.";

			flag = 1;
		}
		//�� �ֱ�
		if (flag == 1)
		{
			int money;
			cout << " ���� �־��ּ���" << " =====> " << " ";
			cin >> money;
			Drink[MachineNumber].SetMoney(money);
			system("cls");
			flag = 2;
		}

		//���� ����
		if (flag == 2)
		{
			int drinkNum;
			Drink[MachineNumber].PrintDrinkList();
			cout << "                                                   ";
			cout << "���� �� : " << Drink[MachineNumber].GetMoney() << "��" << endl;
			cout << "\n [0] ~ [3] ������� �������ּ��� /\n";
			cout << " [5] �� �� �ֱ� / [6] �� ��ȯ�ϱ� / [7] ó������ ���ư���\n =====>[ ]\b\b";
			if (Drink[MachineNumber].CheckingAccounts() == false)
			{
				Drink[MachineNumber].SetMoney();
				cout << " 3�� ��ó��ȭ������ ���ư��ϴ�.\n";
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
					cout << " �ٽ� �Է����ּ���";
					cout << " ���ڸ� �Է����ּ��� =====> [ ]\b\b";
				}
				else {
					system("cls");
					Drink[MachineNumber].PrintDrinkList();
					cout << "                                                   ";
					cout << "���� �� : " << Drink[MachineNumber].GetMoney() << "��" << endl;
					Drink[MachineNumber].PrintPushDrink(drinkNum);
					Drink[MachineNumber].PushDrink(drinkNum);
					cout << "\n [0] ~ [3] ������� �������ּ��� /\n";
					cout << " [5] �� �� �ֱ� / [6] �� ��ȯ�ϱ� / [7] ó������ ���ư���\n =====>[ ]\b\b";
					if (Drink[MachineNumber].CheckingAccounts() == false)
					{
						Drink[MachineNumber].SetMoney();
						cout << " 4�� ��ó��ȭ������ ���ư��ϴ�.\n";
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
	cout << " [���Ǳ� ����]\n";
	Line();
	cout << " [0��] ź�����Ǳ� / [1��] �����ֽ����Ǳ�\n" << endl;
	cout << " ���ڸ� �Է����ּ��� [ ]\b\b";
	cin >> num;
	while (true) {
		cout << endl;
		if (num == '0' || num == '1')
			return (int) num - '0';
		else {
			cout << endl;
			cout << " �ٽ� �Է����ּ���" << endl;
			cout << " ���ڸ� �Է����ּ��� =====> [ ]\b\b";
			cin >> num;
		}
	}
	Line();
}

void DrinkBox(DRINK* drink, DRINK* jucie) {
	strcpy(drink[0].drinkName, "��ī�ݶ�");
	strcpy(drink[1].drinkName, "�ս�����");
	strcpy(drink[2].drinkName, "���̴�");
	strcpy(drink[3].drinkName, "��������Ʈ");

	drink[0].numOfdrink = 10;
	drink[1].numOfdrink = 10;
	drink[2].numOfdrink = 10;
	drink[3].numOfdrink = 10;

	drink[0].price = 2000;
	drink[1].price = 1500;
	drink[2].price = 1500;
	drink[3].price = 1500;


	strcpy(jucie[0].drinkName, "����ֽ�");
	strcpy(jucie[1].drinkName, "���ڳ��ֽ�");
	strcpy(jucie[2].drinkName, "�����ֽ�");
	strcpy(jucie[3].drinkName, "Ű���ֽ�");

	jucie[0].numOfdrink = 10;
	jucie[1].numOfdrink = 10;
	jucie[2].numOfdrink = 10;
	jucie[3].numOfdrink = 10;

	jucie[0].price = 2000;
	jucie[1].price = 2500;
	jucie[2].price = 2000;
	jucie[3].price = 3000;
}
