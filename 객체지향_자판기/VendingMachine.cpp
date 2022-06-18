#define _CRT_SECURE_NO_WARNINGS
#include "VendingMachine.h"
#include "string.h"
#include <iostream>

using VendingMahing1::VendingMachine;
using namespace std;



void VendingMachine::AddDrink(char *name1, int price1, int num1, char *name2, int price2, int num2, char *name3,
	int price3, int num3, char *name4, int price4, int num4 )
{
	strcpy(drink[0].drinkName, name1);
	drink[0].price = price1;
	drink[0].numOfdrink = num1;
	drink[0].buttonNumber = 0;

	strcpy(drink[1].drinkName, name2);
	drink[1].price = price2;
	drink[1].numOfdrink = num2;
	drink[1].buttonNumber = 1;

	strcpy(drink[2].drinkName, name3);
	drink[2].price = price3;
	drink[2].numOfdrink = num3;
	drink[2].buttonNumber = 2;

	strcpy(drink[3].drinkName, name4);
	drink[3].price = price4;
	drink[3].numOfdrink = num4;
	drink[3].buttonNumber = 3;
}

void VendingMachine::SetMoney(int money)
{
	if (money > 0) {
		this->money = this->money + money;
	}
}

int VendingMachine::GetMoney() 
{
	return this->money;
}

void VendingMachine::PrintDrinkList()
{
	for (int i = 0; i < NUM_MAX; i++) 
	{
		std::cout << " [" << drink[i].buttonNumber << "] ";
		std::cout << " " << drink[i].drinkName << "\r\t\t";
		std::cout << " " << drink[i].price << "원";
		std::cout << " " << std::endl;
	}
}

void VendingMachine::PushDrink(const int num)
{
	if (this-> money >= drink[num].price || drink[num].numOfdrink >= 1)
	{
		money = money - drink[num].price;
		drink[num].numOfdrink = drink[num].numOfdrink - 1;
	}
}

void VendingMachine::PrintPushDrink(const int num) {
	if (this->money < drink[num].price) {
		cout << "\n 돈이 부족 합니다.\n";
	}
	else if (drink[num].numOfdrink >= 1)
	{	
		cout << endl;
		cout << " 음료가 나왔습니다. ====> [" << drink[num].drinkName << "]";
		//cout << " : 남은" << drink[num].drinkName << "는" << drink[num].numOfdrink << "개";
		cout << endl;
	}
	else if (drink[num].numOfdrink <= 0)
		cout << " 해당 번호의 음료가 없습니다.\n";
}

//typedef struct
//{
//	char drinkName[NAME_LEN_MAX];
//	int price;
//	int numOfdrink;
//  int buttonNumber;
//} DRINK;