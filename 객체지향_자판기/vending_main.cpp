#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vending_main.h"
#include "VendingMachine.h"
#include <conio.h>
#include <windows.h>

#define DRINK_NUM 4

//using VendingMahing1::VendingMachine;

int main(void) {

	DRINK * carbonatedDrink = new DRINK[DRINK_NUM];
	DRINK * jucie = new DRINK[DRINK_NUM];
	memset(carbonatedDrink, 0, sizeof(jucie) * 4);
	memset(jucie, 0, sizeof(jucie)*4);
	DrinkBox(carbonatedDrink, jucie);

	VendingMahing1::VendingMachine CarbonatedDrink;
	VendingMahing1::VendingMachine JucieVending;

	CarbonatedDrink.InitMembers(carbonatedDrink[0].drinkName, carbonatedDrink[0].price, carbonatedDrink[0].numOfdrink,
		carbonatedDrink[1].drinkName, carbonatedDrink[1].price, carbonatedDrink[1].numOfdrink,
		carbonatedDrink[2].drinkName, carbonatedDrink[2].price, carbonatedDrink[2].numOfdrink,
		carbonatedDrink[3].drinkName, carbonatedDrink[3].price, carbonatedDrink[3].numOfdrink);
	JucieVending.InitMembers(jucie[0].drinkName, jucie[0].price, jucie[0].numOfdrink,
		jucie[1].drinkName, jucie[1].price, jucie[1].numOfdrink,
		jucie[2].drinkName, jucie[2].price, jucie[2].numOfdrink,
		jucie[3].drinkName, jucie[3].price, jucie[3].numOfdrink);

	delete[]carbonatedDrink;
	delete[]jucie;

	while(true)
	{
		system("cls");
		if(Display_ChoiceVendingMachine() == 1){
			cout << " 탄산음료 자판기를 선택했습니다.";
			cout << " 돈을 넣어주세요" << endl <<" ";
			int money;
			cin >> money;
			CarbonatedDrink.SetMoney(money);

		}
		else {
			cout << " 과일주스 자판기를 선택했습니다.";
			cout << " 돈을 넣어주세요" << endl << " ";
			int money;
			cin >> money;
			JucieVending.SetMoney(money);


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
	cout << endl;
	Line();
	cout << " 자판기를 선택해주세요. [1번] 탄산자판기 [2번] 과일주스자판기" << endl;
	cout << " 숫자를 입력해주세요 =====> [ ]\b\b";
	num = _getch();
	while (true) {
		cout << endl;
		if (num == '1' || num == '2')
			return num - '0';
		else {
			cout << endl;
			cout << " 다시 입력해주세요" << endl;
			cout << " 숫자를 입력해주세요 =====> [ ]\b\b";
			num = _getch();
		}
	}
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

//https://kin.naver.com/qna/detail.naver?d1id=1&dirId=1040101&docId=409885683&qb=6rWs7KGw7LK0IOuwsOyXtCDrj5nsoIHtlaDri7k=&enc=utf8&section=kin.ext&rank=3&search_sort=0&spq=0