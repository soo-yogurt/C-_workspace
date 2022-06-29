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
	// 반복문을 실행한다. ESC를 눌려주면 반복문이 끝난다.
	// 출력된 데이터에 위치에 맞다 어떤 값을 뜻하는지 알려준다.
	void PrintListBar();
	// 매개변수의 값에 해당되는 위치의 데이터 한줄을 출력한다.
	void PrintDataSingleLine(int line);
	void Menu1_SaveData(string local);
	void Menu2_SaveData(int* sum);
	void Menu3_SaveData();
	void DisplayNum_1();
	void DisplayNum_2();
	void DisplayNum_3();

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

