#include "ParkTower.h"
#include <iostream>
#include <conio.h>

using namespace std;

void ParkingTower::DisplayMenu()
{
	cout << "====================================================\n";
	cout << endl;
	cout << "     [1] �԰�       [2] ���       [3] ������Ȳ" << endl;
	cout << endl;
	cout << "====================================================\n";

}

void ParkingTower::Checkin()
{
	int flag = 0;
	int i, myCarNum;
	char myCarType;

	for (i = 0; i< 8; i++) 
	{
		if (parkingSpace[i].GetCarNumber() == 0)
			break;
		else if (i == 7) {
			flag++;
			cout << "���� ������ �����ϴ�." << endl;
		}
	}

	if (flag == 0) {
		cout << " ���� ��ȣ�� �Է����ּ��� : ";
		cin >> myCarNum;

		while (true) {
			cout << " ���� ������ �Է����ּ��� : [1] SUV    [2] �¿�" << endl;
			myCarType = _getch();

			if (myCarType == '1') {				
			//	parkingSpace[i] = Suv(myCarNum, (const char*)"SUV");
				parkingSpace[i] = Suv(myCarNum);
				PrintSuccessMessage();
				break;
			}
			else if (myCarType == '2') {
				parkingSpace[i] = Saloon(myCarNum);
			//	parkingSpace[i] = Saloon(myCarNum, (const char*)"�¿�");
				PrintSuccessMessage();
				break;
			}
			else {
				cout << " 1 �Ǵ� 2�� �Է����ּ���" << endl;
				continue;
			}
		}
	}
}

void ParkingTower::DisplsyParkingSpace()
{
	char esc;
	cout << "=================== [ 8 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[7].GetType() << endl;
	cout << "\n=================== [ 7 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[6].GetType() << endl;
	cout << "\n=================== [ 6 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[5].GetType() << endl;
	cout << "\n=================== [ 5 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[4].GetType() << endl;
	cout << "\n=================== [ 4 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[3].GetType() << endl;
	cout << "\n=================== [ 3 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[2].GetType() << endl;
	cout << "\n=================== [ 2 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[1].GetType() << endl;
	cout << "\n=================== [ 1 floor ] ====================\n\n";
	cout << "                     " << parkingSpace[0].GetType() << endl;
	cout << "\n====================================================\n";
	cout << "\n                                               [ESC]\n";
	while (true) {
		esc = _getch();
		if (esc == 27)
			break;
	}
}
void ParkingTower::PrintSuccessMessage() {
	cout << " ��ſ� �Ϸ� �Ǽ���" << endl;
}


void ParkingTower::CheckOut() 
{
	int i, myCarNumber;
	int flag = 0;
	
	cout << " �� ��ȣ�� �Է����ּ���" << endl << " ";
	cin >> myCarNumber;

	for (i = 0; i < 8; i++)
	{
		
		if (parkingSpace[i].GetCarNumber() == myCarNumber && myCarNumber != 0) {
			break;
		}
		else if (i == 7)
			flag = 1;
	}
	if (flag == 0) {
		cout << " " << parkingSpace[i].GetCarNumber() << "(" << parkingSpace[i].GetType() << ")";
		parkingSpace[i].SetCarNumber((int)0);
		parkingSpace[i].SetType((const char*)"NULL");
		PrintSuccessMessage();
	}
	if (flag == 1) {
		cout << " �ش� ������ �����ϴ�." << endl;
	}
}