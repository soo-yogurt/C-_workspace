#define _CRT_SECURE_NO_WARNINGS
#include "VendingMachine.h"
#include "string.h"
#include <iostream>

using VendingMahing1::VendingMachine;



void VendingMachine::InitMembers(char *name1, int price1, int num1, char *name2, int price2, int num2, char *name3,
	int price3, int num3, char *name4, int price4, int num4 )
{
	strcpy(drink[0].drinkName, name1);
	drink[0].price = price1;
	drink[0].numOfdrink = num1;

	strcpy(drink[1].drinkName, name2);
	drink[1].price = price2;
	drink[1].numOfdrink = num2;

	strcpy(drink[2].drinkName, name3);
	drink[2].price = price3;
	drink[2].numOfdrink = num3;

	strcpy(drink[3].drinkName, name4);
	drink[3].price = price4;
	drink[3].numOfdrink = num4;

}

void VendingMachine::SetMoney(int money)
{
	this->money = money;
}

int VendingMachine::GetMoney() 
{
	return this->money;
}

void PushDrink() 
{



}