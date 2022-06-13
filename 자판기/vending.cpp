#include<iostream>
#include<stdio.h>
#include<stdint.h>


using namespace std;


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

int main(void)
{
	// 자판기에 들어간 금액과 구매 할 음료 번호
	int money = 0;
	int juice_number;


	JUICE juice[4] = {
		// 이름, 가격, 수량, 번호
		{"코코팜", 2000, 5, 1},
		{"코카콜라", 1500, 2, 2},
		{"솔의눈", 1000, 10, 3},
		{"팹시제로", 2000, 5, 4}
	};




	while (1) {
		// 자판기에 있는 음료의 종류를 출력한다.
		JuiceList(juice);

		cout << "돈을 넣어주세요 : ";
		cin >> money;
		system("cls");


		if (money == -1000) {
			// 미완성
			printf("음료수 종류를 추가합니다.");
		}
		else if (money > 0) {
			while (1) {
				if (money < 1000) {
					Return_to_money();
					break;
				}
				else if (Check_count(juice) == -1) {
					Return_to_money_2();
					break;
				}
				//구매 할 수 있는 음료 목록을 출력한다.
				JuiceList(juice, money);

				while (1) {
					while (1) {
						cout << "구입할 음료 번호를 눌려주세요 ";
						cout << "[ ]\b\b";
						cin >> juice_number;
						// juice_number가 구조체의 번호보다 1크기때문에 1 빼준다.
						juice_number--;
						if (juice_number >= sizeof(JUICE) / 6) {
							cout << "없는 메뉴입니다.\n";
						}
						else {
							break;
						}
					}
					// 자판기에 남아 있는 돈을 나타낸다.
					money = Remaining_amount(juice, juice_number, money);

					
					system("cls");
					//구매한 음료의 수량을 하나 뺀다.
					Count_Juice(juice, juice_number);
					JuiceList(juice, money);
					//사용자가 구매한 음료를 나타낸다.
					Print_Juice(juice, juice_number);

					//돈이 부족하거나 음료가 모두 소진했을 경우 처리하는 부분
					if (money < 1000) {
						Return_to_money();
						break;
					}
					else if (Check_count(juice) == -1) {
						Return_to_money_2();
						break;
					}
				}

				
			}
		}
	}
	return 0;
}

// 구입할 수 있는 음료 목록
void JuiceList(JUICE *juice) 
{
	cout << "음료 목록" << endl;
	cout << "==========================================================================\n";
	cout << "음료 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout <<"\n금액 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0)
			cout<<"  " << juice[i].price << "원" <<"\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}

void JuiceList(JUICE* juice, int money) {
	cout << "구입할 수 있는 음료 목록" << "                          " << "투입한 금액 : " << money << "원" << endl;
	cout << "==========================================================================\n";
	cout << "음료 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price)) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n금액 >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price))
			cout <<"  " << juice[i].price << "원" <<"\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}


int Remaining_amount(JUICE* juice, int number, int money) {

	return money - juice[number].price;
}

void Print_Juice(JUICE* juice, int number)
{
	number++;
	for (int i = 0; i <= sizeof(JUICE) / 6; i++) {
		if (number == juice[i].menu_number)
			cout <<juice[i].juice_name<<"이(가) 나왔습니다."<<endl;
	}
}

void Return_to_money_2()
{
	system("cls");
	printf("                        음료가 모두 소진되었습니다. 금액을 반환합니다.\r");
}


void Return_to_money() 
{
	system("cls");
	printf("                                                    금액을 반환합니다.\r");
}

int Check_count(JUICE* juice) 
{
	int ck = 1;
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count == 0)
			ck = -1;
		else if (juice[i].count != 0) {
			ck = 1;
			break;
		}
	}

	return ck;
}

void Check_juice(JUICE* juice, int *juice_number)
{
	if (*juice_number > sizeof(JUICE) / 6) {
		cout << "없는 메뉴입니다.\n";
	}

}


void Count_Juice(JUICE* juice, int number) {
	juice[number].count -= 1;
}