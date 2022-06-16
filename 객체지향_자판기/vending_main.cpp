#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "vending_main.h"
#include "VendingMachine.h"

#define DRINK_NUM 4

using VendingMahing1::VendingMachine;

int main(void) {

	int moneyInVendingMachine = 10000;;

	DRINK * carbonatedDrink = new DRINK[DRINK_NUM];
	DRINK * jucie = new DRINK[DRINK_NUM];
	memset(carbonatedDrink, 0, sizeof(jucie) * 4);
	memset(jucie, 0, sizeof(jucie)*4);
	AddDrink(carbonatedDrink, jucie);

	VendingMachine CarbonatedDrink;
	VendingMachine JucieVending;

	CarbonatedDrink.InitMembers(const carbonatedDrink, moneyInVendingMachine);
	JucieVending.InitMembers(const jucie, moneyInVendingMachine);




	delete[]carbonatedDrink;
	delete[]jucie;


	return 0;
}

//https://kin.naver.com/qna/detail.naver?d1id=1&dirId=1040101&docId=409885683&qb=6rWs7KGw7LK0IOuwsOyXtCDrj5nsoIHtlaDri7k=&enc=utf8&section=kin.ext&rank=3&search_sort=0&spq=0