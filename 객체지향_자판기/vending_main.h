#pragma once
using namespace std;
typedef struct {
	char drinkName[10];
	int price;
	int numOfdrink;
}DRINK;

void AddDrink(DRINK *drink) {

	//strcpy(drink[0].drinkName, "코카콜라");
	//strcpy(drink[1].drinkName, "팹시제로");
	//strcpy(drink[2].drinkName, "사이다");
	//strcpy(drink[3].drinkName, "스프라이트");

	//*drink[0]->numOfdrink = 10;
	//drink[1]->numOfdrink = 10;
	//drink[2]->numOfdrink = 10;
	//drink[3]->numOfdrink = 10;

	//drink[0]->price = 2000;
	//drink[1]->price = 1500;
	//drink[2]->price = 1500;
	//drink[3]->price = 1500;
}


void AddDrink(DRINK* drink1, DRINK* drink2, DRINK* drink3, DRINK* drink4) {

	strcpy(drink1->drinkName, "코카콜라");
	strcpy(drink2->drinkName, "팹시제로");
	strcpy(drink3->drinkName, "사이다");
	strcpy(drink4->drinkName, "스프라이트");
	cout << sizeof(DRINK);
	drink1->numOfdrink = 10;
	drink2->numOfdrink = 10;
	drink3->numOfdrink = 10;
	drink4->numOfdrink = 10;


	drink1->price = 2000;
	drink2->price = 1500;
	drink3->price = 1500;
	drink4->price = 1500;

}