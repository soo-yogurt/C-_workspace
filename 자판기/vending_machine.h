#ifndef __VENDING_MACHINE_H_
#define __VENDING_MACHINE_H_


typedef struct {

	char juice_name[10];
	int price;
	int count;
	int menu_number;

}JUICE;

void Return_to_money();
void Return_to_money_2();
void JuiceList(JUICE* juice);
void JuiceList(JUICE* juice, int money_sum);
int Remaining_amount(JUICE* juice, int number, int money);
void Print_Juice(JUICE* juice, int number);
void Check_juice(JUICE* juice, int* juice_number);
void Count_Juice(JUICE* juice, int number);
int Check_count(JUICE* juice);





#endif