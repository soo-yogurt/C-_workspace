#include "ParkTower.h"
#include <iostream>
#include <conio.h>

using namespace std;

void ParkingTower::DisplayMenu()
{
	cout << "====================================================\n";
	cout << endl;
	cout << "     [1] 입고       [2] 출고       [3] 주차현황" << endl;
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
			cout << "주차 공간이 없습니다." << endl;
		}
	}

	if (flag == 0) {
		cout << " 차량 번호를 입력해주세요 : ";
		cin >> myCarNum;

		while (true) {
			cout << " 차량 종류를 입력해주세요 : [1] SUV    [2] 승용" << endl;
			myCarType = _getch();

			if (myCarType == '1') {				
			//	parkingSpace[i] = Suv(myCarNum, (const char*)"SUV");
				parkingSpace[i] = Suv(myCarNum);
				PrintSuccessMessage();
				break;
			}
			else if (myCarType == '2') {
				parkingSpace[i] = Saloon(myCarNum);
			//	parkingSpace[i] = Saloon(myCarNum, (const char*)"승용");
				PrintSuccessMessage();
				break;
			}
			else {
				cout << " 1 또는 2를 입력해주세요" << endl;
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
	cout << " 즐거운 하루 되세요" << endl;
}


void ParkingTower::CheckOut() 
{
	int i, myCarNumber;
	int flag = 0;
	
	cout << " 차 번호를 입력해주세요" << endl << " ";
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
		cout << " 해당 차량이 없습니다." << endl;
	}
}