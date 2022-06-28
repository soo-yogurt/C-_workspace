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
	// ���� ȭ��
	char PrintMenu();
	// �ݺ����� �����Ѵ�. ESC�� �����ָ� �ݺ����� ������.
	void ButtonEsc();
	// ��µ� �����Ϳ� ��ġ�� �´� � ���� ���ϴ��� �˷��ش�.
	void PrintListBar();
	// �Ű������� ���� �ش�Ǵ� ��ġ�� ������ ������ ����Ѵ�.
	void PrintDataSingleLine(int line);
	void DisplayNum_1();
	void DisplayNum_2();
	void DisplayNum_3();

	~DataHandler()
	{
		// delete[i] myDatas�� �ƴ� ����
		// �����Ҵ� �� ��ü�� AccidentData�� �ƴ� mpDatas ���� Ŭ�����̴�.
		/*for(int i = 0; i < DATALIST; i++)
			delete myDatas[i];*/
		for (int i = 0; i < myDatas.size(); i++)
			delete myDatas[i];

	}
	
};

