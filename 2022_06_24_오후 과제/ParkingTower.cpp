#include "ParkingTower.h"
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

//#define DEBUG

void ParkingTower::DisplayMenu()
{
	PrintOpenMessage();
	cout << "====================================================\n";
	cout << endl;
	cout << "     [1] 입고       [2] 출고       [3] 주차현황" << endl;
	cout << endl;
	cout << "====================================================\n";

}

void ParkingTower::PrintSuccessMessage() {
	cout << " Succed Parking" << endl;
}
void ParkingTower::PrintOpenMessage()
{
	cout << " 문이 열립니다." << endl;
}
void ParkingTower::PrintClosedMessage()
{
	cout << " 문이 닫힙니다." << endl;
}
void ParkingTower::PrintNiceDay()
{
	cout << " Have a nice day" << endl;
}


//#define TEST1 클래서 생성 종류에 따라 다른 코드를 짜고 이해하기(미완성)
#ifdef DEBUG




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
			cout << " 차량 종류를 입력해주세요 : [1] SUV    [2] Sedan" << endl;
			myCarType = _getch();

			if (myCarType == '1') {				
				parkingSpace[i].SetType("SUV");
				parkingSpace[i].SetCarNumber(myCarNum);
				PrintClosedMessage();
				PrintSuccessMessage();
				break;
			}
			else if (myCarType == '2') {
				parkingSpace[i].SetType("Sedan");
				parkingSpace[i].SetCarNumber(myCarNum);
				PrintClosedMessage();
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



void ParkingTower::ParkingCheck()
{ 
	int i;
	char *p1, *p2;
	int countCar = 0;
	int countSuv = 0;
	int countSaloon = 0;


	for (i = 0; i < 8; i++)
	{
		p1 = strstr(parkingSpace[i].GetType(), (char*)"SUV");
		p2 = strstr(parkingSpace[i].GetType(), (char*)"Sedan");

		if (p1 != 0) {
			countCar++;
			countSaloon++;
		}
		if (p2 != 0) {
			countSaloon++;
			countCar++;
		}
	}
			
	cout << "[주차된 자동차 수] : (" << countCar << "/8)" << "   \n[SUV] : " << countSuv << "대";
	cout << "               [Sedan] : " << countSaloon << "대" << endl;
}




void ParkingTower::DisplsyParkingSpace()
{
	char esc;

	ParkingCheck();
	cout << "=================== [ 4 floor ] ====================\n\n";
	cout << "              " << parkingSpace[7].GetType() << "             " << parkingSpace[6].GetType() << endl;
	cout << "\n=================== [ 3 floor ] ====================\n\n";
	cout << "              " << parkingSpace[5].GetType() << "             " << parkingSpace[4].GetType() << endl;
	cout << "\n=================== [ 2 floor ] ====================\n\n";
	cout << "              " << parkingSpace[3].GetType() << "             " << parkingSpace[2].GetType() << endl;
	cout << "\n=================== [ 1 floor ] ====================\n\n";
	cout << "              " << parkingSpace[1].GetType() << "             " << parkingSpace[0].GetType() << endl;
	cout << "\n====================================================\n";
	cout << "\n                                               [ESC]\n";

	while (true) {
		esc = _getch();
		if (esc == 27)
			break;
	}
}



void ParkingTower::CheckOut() 
{
	int i, myCarNumber;
	int flag = 0;
	

	PrintClosedMessage();
	cout << " 차 번호를 입력해주세요 : ";
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
		cout << " 출고 : " << parkingSpace[i].GetCarNumber() << "(" << parkingSpace[i].GetType() << ")\n";
		parkingSpace[i].SetCarNumber((int)0);
		parkingSpace[i].SetType((const char*)"NULL");
		PrintOpenMessage();
	}
	if (flag == 1) {
		cout << " 해당 차량이 없습니다." << endl;
	}
}
#else DEBUG

void ParkingTower::Checkin()
{
	int flag = 0;
	int i, myCarNum;
	char myCarType;

	for (i = 0; i < 8; i++)
	{
		if (parkingSpace[i]->GetCarNumber() == 0)
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
			cout << " 차량 종류를 입력해주세요 : [1] SUV    [2] Sedan" << endl;
			myCarType = _getch();

			if (myCarType == '1') {
				parkingSpace[i] = new Suv(myCarNum);
				PrintClosedMessage();
				PrintSuccessMessage();
				break;
			}
			else if (myCarType == '2') {
				parkingSpace[i] = new Sedan(myCarNum);
				PrintClosedMessage();
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



void ParkingTower::ParkingCheck()
{
	int i;
	char* p1, * p2;
	int countCar = 0;
	int countSuv = 0;
	int countSaloon = 0;

	for (i = 0; i < 8; i++)
	{
		p1 = strstr(parkingSpace[i]->GetType(), (char*)"SUV");
		p2 = strstr(parkingSpace[i]->GetType(), (char*)"Sedan");

		if (p1 != 0) {
			countCar++;
			countSaloon++;
		}
		if (p2 != 0) {
			countSaloon++;
			countCar++;
		}
	}

	cout << "[주차된 자동차 수] : (" << countCar << "/8)" << "   \n[SUV] : " << countSuv << "대";
	cout << "               [Sedan] : " << countSaloon << "대" << endl;
}


void ParkingTower::DisplsyParkingSpace()
{
	char esc;

	ParkingCheck();
	cout << "=================== [ 4 floor ] ====================\n\n";
	cout << "              " << parkingSpace[7]->GetType() << "(" << parkingSpace[7]->GetCarNumber();
	cout << ")             " << parkingSpace[6]->GetType() << "(" << parkingSpace[7]->GetCarNumber() << ")" << endl;
	cout << "\n=================== [ 3 floor ] ====================\n\n";
	cout << "              " << parkingSpace[5]->GetType() << "(" << parkingSpace[5]->GetCarNumber();
	cout <<	")             " << parkingSpace[4]->GetType() << "(" << parkingSpace[4]->GetCarNumber() << ")" << endl;
	cout << "\n=================== [ 2 floor ] ====================\n\n";
	cout << "              " << parkingSpace[3]->GetType() << "(" << parkingSpace[3]->GetCarNumber();
	cout << ")             " << parkingSpace[2]->GetType() << "(" << parkingSpace[2]->GetCarNumber() << ")" << endl;
	cout << "\n=================== [ 1 floor ] ====================\n\n";
	cout << "              " << parkingSpace[1]->GetType() << "(" << parkingSpace[1]->GetCarNumber();
	cout << ")             " << parkingSpace[0]->GetType() << "(" << parkingSpace[0]->GetCarNumber() << ")" << endl;
	cout << "\n====================================================\n";
	cout << "\n                                               [ESC]\n";

	while (true) {
		esc = _getch();
		if (esc == 27)
			break;
	}
}

void ParkingTower::CheckOut()
{
	int i, myCarNumber;
	int flag = 0;


	PrintClosedMessage();
	cout << " 차 번호를 입력해주세요 : ";
	cin >> myCarNumber;

	for (i = 0; i < 8; i++)
	{

		if (parkingSpace[i]->GetCarNumber() == myCarNumber && myCarNumber != 0) {
			break;
		}
		else if (i == 7)
			flag = 1;
	}
	if (flag == 0) {
		cout << " 출고 : " << parkingSpace[i]->GetCarNumber() << "(" << parkingSpace[i]->GetType() << ")\n";
		parkingSpace[i]->SetCarNumber((int)0);
		parkingSpace[i]->SetType((const char*)"NULL");
		PrintOpenMessage();
		PrintNiceDay();
	}
	if (flag == 1) {
		cout << " 해당 차량이 없습니다." << endl;
	}
}

#endif DEBUG