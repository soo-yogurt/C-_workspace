#include "DataHandler.h"
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <fstream> 
#include <string>


DataHandler::DataHandler() {

	ifstream  data("ANSIData.csv");
	string line;
	int cnt = 0;
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
		myDatas[cnt] = new AccidentData(tmpsido, tmpsigungu, tmpdatas);
		cnt++;
	}
}



char DataHandler::PrintMenu()
{
	char button;
	std::cout << " [1] : 지역별 사고 현황보기" << std::endl;
	std::cout << " [2] : 전체 지역별 사고 현황 합계" << std::endl;
	std::cout << " [3] : 전체 사고 현황보기" << std::endl;
	while (true) {
		button = _getch();
		if(button == '1' || button == '2' || button == '3')
			return button;
	}
}

void DataHandler::PrintListBar()
{
	std::cout << endl;
	std::cout << "[시도]  [시군구]  [터널안]  [교량위]  [고가도로위]  [하차도]  [기타단일로]";
	std::cout << "[교차로내]  [차로횡단보도]  [교차로부근]  [철길건널목]  [기타]  [불명]" << std::endl;
}
// 지역별
void DataHandler::DisplayNum_1()
{
	string data;
	std::cout << " 지역으로 검색해주세요 : ";
	std::cin >> data;
	for (int i = 0; i < DATALIST; i++)
	{
		if (myDatas[i]->Getsido() == data || myDatas[i]->Getsigungu() == data) {
			cout << " " << myDatas[i]->Getsido() << "\t ";
			cout << myDatas[i]->Getsigungu();
			if (myDatas[i]->Getsigungu().size() < 5)
				cout << "  \t\t";
			else if (myDatas[i]->Getsigungu().size() < 7)
				cout << "\t\t";
			else
				cout << "\t";
			for (int j = 0; j < 11; j++)
				printf("%3d", myDatas[i]->Getdatas()[j]);
			cout << "  ";
			cout << endl;
		}
	}
	DataHandler::PrintListBar();
}

void DataHandler::DisplayNum_2() 
{
	int sum[50];
	int k = 0; 
	string sido;

	for (int i = 0; i < 50; i++)
		sum[i] = 0;
	sido = myDatas[0]->Getsido();
	cout << " " << myDatas[0]->Getsido() << "\t ";
	for (int i = 0; i < DATALIST; i++)
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
		if (i + 1 == DATALIST)
		{
			cout << sum[k];
		}
	}
	DataHandler::PrintListBar();
}

void DataHandler::DisplayNum_3()
{
	for (int i = 0; i < DATALIST; i++)
	{
		cout << " " << myDatas[i]->Getsido() << "\t ";
		cout << myDatas[i]->Getsigungu();
		if (myDatas[i]->Getsigungu().size() < 5)
			cout << "  \t\t";
		else if (myDatas[i]->Getsigungu().size() < 7)
			cout << "\t\t";
		else
			cout << "\t";
		for (int j = 0; j < 11; j++)
			printf("%3d", myDatas[i]->Getdatas()[j]);
		cout << "  ";
		cout << endl;
	}
	DataHandler::PrintListBar();
}

void DataHandler::ButtonEsc()
{
	char esc;
	cout << "\n [ESC]\n";
	while (true)
	{
		esc = _getch();
		if (esc == 27)
			break;
	}
}