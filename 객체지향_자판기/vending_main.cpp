#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "vending_main.h"

#define DRINK_NUM 4



int main(void) {

	//char *jucieName1 = new char[10];
	//strcpy(jucieName1, "코카콜라");
	//char *juc

	
	DRINK *drink[DRINK_NUM];
	for (int i = 0; i < DRINK_NUM; i++) 
		drink[i] = new DRINK;
	
	memset(drink, 0, sizeof(drink));

	



	AddDrink(drink[0], drink[1], drink[2], drink[3]);


	cout << sizeof(drink);

	for (int i = 0; i < DRINK_NUM; i++)
		delete[] drink[i];


	return 0;
}

//https://kin.naver.com/qna/detail.naver?d1id=1&dirId=1040101&docId=409885683&qb=6rWs7KGw7LK0IOuwsOyXtCDrj5nsoIHtlaDri7k=&enc=utf8&section=kin.ext&rank=3&search_sort=0&spq=0