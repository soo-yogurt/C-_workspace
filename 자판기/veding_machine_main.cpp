#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include "vending_machine.h"


using namespace std;

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




int Remaining_amount(JUICE* juice, int number, int money) {
	if (juice[number].count > 0) {
		return money - juice[number].price;
	}
	else {
		return money;
	}
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




void Count_Juice(JUICE* juice, int number) {
	juice[number].count -= 1;
}


// 처음에는 malloc과 scanf를 이용해서 사용자가 음료의 종류를 자유롭게 정할수 있게
// 하려 했지만 과제인 자판기와 의미가 맞지 않는다고 생각한다.
// 따라서 기존 음료수 자리에 다른 음료수와 교채하거나 음료수를 다 마실경우 채워 넣을 수
// 있게 고민해보겠다.
