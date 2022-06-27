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
	while (std::getline(data, line)) // data ���Ͽ��� ���� �ڷḦ line�� �ʱ�ȭ �Ѵ�.
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
	std::cout << " [1] : �õ��� ��� ��Ȳ����" << std::endl;
	std::cout << " [2] : �ñ��� �� ��� ��Ȳ����" << std::endl;
	std::cout << " [3] : �˻��ϱ� " << std::endl;
	while (true) {
		button = _getch();
		if(button == '1' || button == '2' || button == '3')
			return button;
	}
}


void DataHandler::PrintListBar()
{
	std::cout << "[�õ�]  [�ñ���]  [�ͳξ�]  [������]  [��������]  [������]  [��Ÿ���Ϸ�]";
	std::cout << "[�����γ�]  [����Ⱦ�ܺ���]  [�����κα�]  [ö��ǳθ�]  [��Ÿ]  [�Ҹ�]" << std::endl;
}
// �õ��� ��Ȳ
void DataHandler::DisplayNum_1()
{
	DataHandler:PrintListBar();
}
// �ñ����� ��Ȳ
void DataHandler::DisplayNum_2() 
{
	DataHandler:PrintListBar();
}
// �˻��ϱ�
void DataHandler::DisplayNum_3()
{
	string data;
	char esc;
	DataHandler:PrintListBar();
	std::cout << "������ �˻����ּ��� : ";
	std::cin >> data;
	for (int i = 0; i < DATALIST; i++)
	{
		if (myDatas[i]->Getsigungu() == "�߱�")
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