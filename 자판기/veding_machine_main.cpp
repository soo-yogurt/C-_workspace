#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include "vending_machine.h"


using namespace std;

int main(void)
{
	// ���Ǳ⿡ �� �ݾװ� ���� �� ���� ��ȣ
	int money = 0;
	int juice_number;


	JUICE juice[4] = {
		// �̸�, ����, ����, ��ȣ
		{"������", 2000, 5, 1},
		{"��ī�ݶ�", 1500, 2, 2},
		{"���Ǵ�", 1000, 10, 3},
		{"�ս�����", 2000, 5, 4}
	};




	while (1) {
		// ���Ǳ⿡ �ִ� ������ ������ ����Ѵ�.
		JuiceList(juice);

		cout << "���� �־��ּ��� : ";
		cin >> money;
		system("cls");


		if (money == -1000) {
			// �̿ϼ�
			printf("����� ������ �߰��մϴ�.");
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
				//���� �� �� �ִ� ���� ����� ����Ѵ�.
				JuiceList(juice, money);

				while (1) {
					while (1) {
						cout << "������ ���� ��ȣ�� �����ּ��� ";
						cout << "[ ]\b\b";
						cin >> juice_number;
						// juice_number�� ����ü�� ��ȣ���� 1ũ�⶧���� 1 ���ش�.
						juice_number--;
						if (juice_number >= sizeof(JUICE) / 6) {
							cout << "���� �޴��Դϴ�.\n";
						}
						else {
							break;
						}
					}
					// ���Ǳ⿡ ���� �ִ� ���� ��Ÿ����.
					money = Remaining_amount(juice, juice_number, money);

					
					system("cls");
					//������ ������ ������ �ϳ� ����.
					Count_Juice(juice, juice_number);
					JuiceList(juice, money);
					//����ڰ� ������ ���Ḧ ��Ÿ����.
					Print_Juice(juice, juice_number);

					//���� �����ϰų� ���ᰡ ��� �������� ��� ó���ϴ� �κ�
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


// ó������ malloc�� scanf�� �̿��ؼ� ����ڰ� ������ ������ �����Ӱ� ���Ҽ� �ְ�
// �Ϸ� ������ ������ ���Ǳ�� �ǹ̰� ���� �ʴ´ٰ� �����Ѵ�.
// ���� ���� ����� �ڸ��� �ٸ� ������� ��ä�ϰų� ������� �� ���ǰ�� ä�� ���� ��
// �ְ� ����غ��ڴ�.
