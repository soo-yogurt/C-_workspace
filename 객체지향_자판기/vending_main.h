#pragma once
using namespace std;
typedef struct {
	char drinkName[10];
	int price;
	int numOfdrink;
}DRINK;

void AddDrink(DRINK *drink) {

	//strcpy(drink[0].drinkName, "��ī�ݶ�");
	//strcpy(drink[1].drinkName, "�ս�����");
	//strcpy(drink[2].drinkName, "���̴�");
	//strcpy(drink[3].drinkName, "��������Ʈ");

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

	strcpy(drink1->drinkName, "��ī�ݶ�");
	strcpy(drink2->drinkName, "�ս�����");
	strcpy(drink3->drinkName, "���̴�");
	strcpy(drink4->drinkName, "��������Ʈ");
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