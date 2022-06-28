#pragma once
#include "AccidentData.h"
constexpr auto DATALIST = 229;

class DataHandler
{
	AccidentData * myDatas[DATALIST];
public:
	DataHandler();
	char PrintMenu();
	void ButtonEsc();
	void PrintListBar();
	void DisplayNum_1();
	void DisplayNum_2();
	void DisplayNum_3();
	~DataHandler()
	{
		for(int i = 0; i < DATALIST; i++)
			delete myDatas[i];
	}
};

