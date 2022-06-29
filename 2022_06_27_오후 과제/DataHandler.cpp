#include "DataHandler.h"
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <fstream> 
#include <string>


// �Է� ���� �����Ϳ� ���� ������� ũ�⸸ŭ �ʱ�ȭ ���� �ȵ��� �� �� ���� ������ ��� ���´�.
// �Ű� ���� ����
DataHandler::DataHandler() {

	ifstream  data("ANSIData.csv");
	string line;
	//int cnt = 0;
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
		//myDatas[cnt] = new AccidentData(tmpsido, tmpsigungu, tmpdatas);
		//cnt++;
		myDatas.push_back(new AccidentData(tmpsido, tmpsigungu, tmpdatas));
	}
}

char DataHandler::PrintMenu()
{
	char button;
	std::cout << " [1] : ������ ��� ��Ȳ����" << std::endl;
	std::cout << " [2] : ���� ������ ��� ��Ȳ �հ�" << std::endl;
	std::cout << " [3] : ���� ��� ��Ȳ����" << std::endl;
	while (true) {
		button = _getch();
		if (button == '1' || button == '2' || button == '3')
			return button;
	}
}

void DataHandler::PrintListBar()
{
	std::cout << endl;
	std::cout << "[�õ�]  [�ñ���]  [�ͳξ�]  [������]  [��������]  [������]  [��Ÿ���Ϸ�]";
	std::cout << "[�����γ�]  [����Ⱦ�ܺ���]  [�����κα�]  [ö��ǳθ�]  [��Ÿ]  [�Ҹ�]" << std::endl;
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
	// �迭�� ��ȯ �޾ұ� ������ �ش� ���� ������ �ּҰ� ���´�. ������ �������ؼ��� �迭�� ���ڸ��� ����ؾ��Ѵ�.
	for (int j = 0; j < 11; j++)
		printf("%3d", myDatas[line]->Getdatas()[j]);
	cout << "  ";
	cout << endl;
}


// ������
void DataHandler::DisplayNum_1()
{
	string data;
	std::cout << " �������� �˻����ּ��� : ";
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

	cout << " ������ : [ESC]\t\t �����ϱ� : [ENTER]" << endl;
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
	std::cout << " ���ϸ��� �Է��ϼ��� : ";
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
	std::cout << " ���� �Ϸ�" << endl;
}

void DataHandler::DisplayNum_2() 
{
	int sum[50]; // �� �κ� ���ͷ� �ٲ� �� ������ ?
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

	cout << " ������ : [ESC]\t\t �����ϱ� : [ENTER]" << endl;
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
	std::cout << " ���ϸ��� �Է��ϼ��� : ";
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
	std::cout << " ���� �Ϸ�" << endl;
	Savefile.close();
}




void DataHandler::DisplayNum_3()
{
	for (int i = 0; i < myDatas.size(); i++)
	{
		PrintDataSingleLine(i);
	}
	DataHandler::PrintListBar();

	cout << " ������ : [ESC]\t\t �����ϱ� : [ENTER]" << endl;
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
	std::cout << " ���ϸ��� �Է��ϼ��� : ";
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
	std::cout << " ���� �Ϸ�" << endl;
}