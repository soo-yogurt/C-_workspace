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
	std::cout << " [1] : 시도별 사고 현황보기" << std::endl;
	std::cout << " [2] : 시군구 별 사고 현황보기" << std::endl;
	std::cout << " [3] : 검색하기 " << std::endl;
	while (true) {
		button = _getch();
		if(button == '1' || button == '2' || button == '3')
			return button;
	}
}


void DataHandler::PrintListBar()
{
	std::cout << "[시도]  [시군구]  [터널안]  [교량위]  [고가도로위]  [하차도]  [기타단일로]";
	std::cout << "[교차로내]  [차로횡단보도]  [교차로부근]  [철길건널목]  [기타]  [불명]" << std::endl;
}
// 시도별 현황
void DataHandler::DisplayNum_1()
{
	DataHandler:PrintListBar();
}
// 시구군별 현황
void DataHandler::DisplayNum_2() 
{
	DataHandler:PrintListBar();
}
// 검색하기
void DataHandler::DisplayNum_3()
{
	string data;
	char esc;
	DataHandler:PrintListBar();
	std::cout << "지역을 검색해주세요 : ";
	std::cin >> data;
	for (int i = 0; i < DATALIST; i++)
	{
		if (myDatas[i]->Getsigungu() == "중구")
			cout << myDatas[i]->Getdatas()[i] << "  ";
		if (myDatas[i]->Getsido() == (string)data)
			cout << myDatas[i]->Getdatas()[1] << "  ";
	}


}

void DataHandler::ButtonEsc()
{
	char esc;
	while (true)
	{
		esc = _getch();
		if (esc == 27)
			break;
	}
}