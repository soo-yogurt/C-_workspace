#pragma once
#include<string.h>
#include<iostream>
using namespace std;
typedef struct {
	char drinkName[10];
	int price;
	int numOfdrink;
}DRINK;
// carbonated
void AddDrink(DRINK *drink, DRINK *jucie) {
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
