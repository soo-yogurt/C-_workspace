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

// ������ �� �ִ� ���� ���
void JuiceList(JUICE *juice) 
{
	cout << "���� ���" << endl;
	cout << "==========================================================================\n";
	cout << "���� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout <<"\n�ݾ� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if (juice[i].count > 0)
			cout<<"  " << juice[i].price << "��" <<"\t";
	}
	cout << endl;
	cout << "==========================================================================\n";
}

void JuiceList(JUICE* juice, int money) {
	cout << "������ �� �ִ� ���� ���" << "                          " << "������ �ݾ� : " << money << "��" << endl;
	cout << "==========================================================================\n";
	cout << "���� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price)) {
			printf("[%d]", juice[i].menu_number);
			cout << juice[i].juice_name << "\t";
		}
	}
	cout << "\n�ݾ� >>\t";
	for (int i = 0; i < sizeof(JUICE) / 6; i++) {
		if ((juice[i].count > 0) && (money >= juice[i].price))
			cout <<"  " << juice[i].price << "��" <<"\t";
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
			cout <<juice[i].juice_name<<"��(��) ���Խ��ϴ�."<<endl;
	}
}

void Return_to_money_2()
{
	system("cls");
	printf("                        ���ᰡ ��� �����Ǿ����ϴ�. �ݾ��� ��ȯ�մϴ�.\r");
}


void Return_to_money() 
{
	system("cls");
	printf("                                                    �ݾ��� ��ȯ�մϴ�.\r");
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
		cout << "���� �޴��Դϴ�.\n";
	}

}


void Count_Juice(JUICE* juice, int number) {
	juice[number].count -= 1;
}