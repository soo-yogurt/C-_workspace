#pragma once
#include "AccidentData.h"
#include <vector>

//constexpr auto DATALIST = 229;

class DataHandler
{
	vector<AccidentData * > myDatas;
	//AccidentData * myDatas[DATALIST];
public:
	DataHandler();
	// 시작 화면
	char PrintMenu();
	// 출력된 데이터에 위치에 맞다 어떤 값을 뜻하는지 알려준다.
	void PrintListBar();
	// 해당되는 위치의 데이터 한줄을 출력한다.
	void PrintDataSingleLine(int line);
	void DisplayNum_1();
	void DisplayNum_2();
	void DisplayNum_3();

	// 아래의 3개 함수를 Display 함수와 함께 사용해야한다.
	// private 에 넣어야하는가 ?
	void Menu1_SaveData(string local);
	void Menu2_SaveData(vector<int> *sum);
	void Menu3_SaveData();

	~DataHandler()
	{
		// delete[i] myDatas가 아닌 이유
		// 동적할당 된 객체가 AccidentData가 아닌 mpDatas 안의 클래스이다.
		/*for(int i = 0; i < DATALIST; i++)
			delete myDatas[i];*/
		for (int i = 0; i < myDatas.size(); i++)
			delete myDatas[i];
	}
	
};

