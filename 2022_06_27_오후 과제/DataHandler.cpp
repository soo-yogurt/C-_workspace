#include "DataHandler.h"
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <fstream> 
#include <string>


// 입력 받을 데이터에 따라 만들어진 크기만큼 초기화 될지 안될지 알 수 없기 때문에 경고가 나온다.
// 신경 쓰지 말자
DataHandler::DataHandler() {

	ifstream  data("ANSIData.csv");
	string line;
	//int cnt = 0;
	while (std::getline(data, line)) // data 파일에서 읽은 자료를 line에 초기화 한다.
	{
		stringstream lineStream(line);
		string cell;
		string tmpsido;
		string tmpsigungu;
		int tmpdatas[11];
		int idx = 0;
		while (std::getline(lineStream, cell, ','))
		{
			if (idx == 0)
			{
				tmpsido = cell;
			}
			else if (idx == 1)
			{
				tmpsigungu = cell;
			}
			else
			{
				if (cell == "-")
					tmpdatas[idx - 2] = 0;
				else
					tmpdatas[idx - 2] = stoi(cell);
			}
			idx++;
		}
		//myDatas[cnt] = new AccidentData(tmpsido, tmpsigungu, tmpdatas);
		//cnt++;
		myDatas.push_back(new AccidentData(tmpsido, tmpsigungu, tmpdatas));
	}
}

char DataHandler::PrintMenu()
{
	char button;
	std::cout << " [1] : 지역별 사고 현황보기" << std::endl;
	std::cout << " [2] : 전국 지역별 사고 현황 합계" << std::endl;
	std::cout << " [3] : 전국 사고 현황보기" << std::endl;
	while (true) {
		button = _getch();
		if (button == '1' || button == '2' || button == '3')
			return button;
	}
}

void DataHandler::PrintListBar()
{
	std::cout << endl;
	std::cout << "[시도]  [시군구]  [터널안]  [교량위]  [고가도로위]  [하차도]  [기타단일로]";
	std::cout << "[교차로내]  [차로횡단보도]  [교차로부근]  [철길건널목]  [기타]  [불명]" << std::endl;
}

void  DataHandler::PrintDataSingleLine(int line)
{
	cout << " " << myDatas[line]->Getsido() << "\t ";
	cout << myDatas[line]->Getsigungu();
	if (myDatas[line]->Getsigungu().size() < 5)
		cout << "  \t\t";
	else if (myDatas[line]->Getsigungu().size() < 7)
		cout << "\t\t";
	else
		cout << "\t";
	// 배열을 반환 받았기 때문에 해당 값을 읽으면 주소가 나온다. 내용을 보기위해서는 배열을 한자리씩 출력해야한다.
	for (int j = 0; j < 11; j++)
		printf("%3d", myDatas[line]->Getdatas()[j]);
	cout << "  ";
	cout << endl;
}


// 지역별
void DataHandler::DisplayNum_1()
{
	string data;
	std::cout << " 지역으로 검색해주세요 : ";
	std::cin >> data;
	for (int i = 0; i < myDatas.size(); i++)
	{
		if (myDatas[i]->Getsido() == data || myDatas[i]->Getsigungu() == data) {
			PrintDataSingleLine(i);
		}
	}
	DataHandler::PrintListBar();
	cout << endl;
	cout << endl;
	char ki;

	cout << " 나가기 : [ESC]\t\t 저장하기 : [ENTER]" << endl;
	while (true)
	{
		ki = _getch();
		if (ki == 27)
			break;
		else if (ki == 13) {
			Menu1_SaveData(data);
			break;
		}
	}
}

void DataHandler::Menu1_SaveData(string local)
{
	string fileName;
	std::cout << " 파일명을 입력하세요 : ";
	cin >> fileName;
	ofstream Savefile(fileName + ".csv");
	for (int i = 0; i < myDatas.size(); i++)
	{
		if ((myDatas[i]->Getsido() == local) || (myDatas[i]->Getsigungu() == local)) {
			Savefile << myDatas[i]->Getsido() + ", " + myDatas[i]->Getsigungu() + ", ";
			for (int j = 0; j < 11; j++) {
				Savefile << myDatas[i]->Getdatas()[j];
				Savefile << ", ";
			}
			Savefile << "\n";
		}
	}
	Savefile.close();
	std::cout << " 저장 완료" << endl;
}

void DataHandler::DisplayNum_2() 
{
	int sum[50]; // 이 부분 백터로 바꿀 수 없을까 ?
	int k = 0; 
	string sido;

	for (int i = 0; i < 50; i++)
		sum[i] = 0;
	sido = myDatas[0]->Getsido();
	cout << " " << myDatas[0]->Getsido() << "\t ";
	for (int i = 0; i < myDatas.size(); i++)
	{
		if (myDatas[i]->Getsido() == sido) {
			for (int j = 0; j < 11; j++) {
				sum[k] += myDatas[i]->Getdatas()[j];
			}
		}
		else {
			cout << sum[k];
			k++;
			cout << endl;
			sido = myDatas[i]->Getsido();
			cout << " " << myDatas[i]->Getsido() << "\t ";
		}	
		if (i + 1 == myDatas.size())
		{
			cout << sum[k];
			cout << endl;
		}
	}

	cout << " 나가기 : [ESC]\t\t 저장하기 : [ENTER]" << endl;
	while (true)
	{
		char ki;
		ki = _getch();
		if (ki == 27)
			break;
		else if (ki == 13) {
			Menu2_SaveData(&sum[0]);
			break;
		}
	}
}

void DataHandler::Menu2_SaveData(int *sum)
{
	string fileName;
	std::cout << " 파일명을 입력하세요 : ";
	cin >> fileName;
	ofstream Savefile(fileName + ".csv");
	
	int k = 0;
	string sido = myDatas[0]->Getsido();
	Savefile << myDatas[0]->Getsido();
	Savefile << ", ";
	for (int i = 0; i < myDatas.size(); i++) {
		if (sido == myDatas[i]->Getsido()) {}

		else {
			Savefile << sum[k];
			k++;
			Savefile << endl;
			Savefile << myDatas[i]->Getsido();
			sido = myDatas[i]->Getsido();
			Savefile << ", ";
		}
		if ((i + 1) == myDatas.size()) {
			Savefile << sum[k];
			Savefile << endl;
		}
	}
	std::cout << " 저장 완료" << endl;
	Savefile.close();
}




void DataHandler::DisplayNum_3()
{
	for (int i = 0; i < myDatas.size(); i++)
	{
		PrintDataSingleLine(i);
	}
	DataHandler::PrintListBar();

	cout << " 나가기 : [ESC]\t\t 저장하기 : [ENTER]" << endl;
	while (true)
	{
		char ki;
		ki = _getch();
		if (ki == 27)
			break;
		else if (ki == 13) {
			Menu3_SaveData();
			break;
		}
	}
}

void DataHandler::Menu3_SaveData()
{
	string fileName;
	std::cout << " 파일명을 입력하세요 : ";
	cin >> fileName;
	ofstream Savefile(fileName + ".csv");
	for (int i = 0; i < myDatas.size(); i++)
	{
		Savefile << myDatas[i]->Getsido() + ", " + myDatas[i]->Getsigungu() + ", ";
		for (int j = 0; j < 11; j++) {
			Savefile << myDatas[i]->Getdatas()[j];
			Savefile << ", ";
		}
		Savefile << "\n";
	}
	Savefile.close();
	std::cout << " 저장 완료" << endl;
}