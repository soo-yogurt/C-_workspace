#pragma once
#include<string.h>
#include<iostream>
using namespace std;
typedef struct {
	char drinkName[10];
	int price;
	int numOfdrink;
}DRINK;

void DrinkBox(DRINK* drink, DRINK* jucie);
int Display_ChoiceVendingMachine();
void Line();
