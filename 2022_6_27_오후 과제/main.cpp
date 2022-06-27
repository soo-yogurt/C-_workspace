#include <iostream>
#include <sstream> 
#include <fstream> 
#include <string>
#include "AccidentData.h"

using namespace std;

int main()
{
	AccidentData * myDatas[229];

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
				if(cell == "-")
					tmpdatas[idx - 2] = 0;
				else
					tmpdatas[idx - 2] = stoi(cell);
			}
			idx++;
		}
		myDatas[cnt] = new AccidentData(tmpsido, tmpsigungu, tmpdatas);
		cnt++;
	
	}

	//for (int i = 0; i < 229; i++)
	//{
	//	if(myDatas[i]->Getsigungu() == "중구")
	//		cout << myDatas[i]->Getdatas()[1] << endl;
	//}

	cout << "==================================" << endl;
	cout << " [1] 시도별 검색" << endl;
	cout << " [2] 시도군 별 검색" << endl;
	cout << " [3] 사망자 수 합"

	
	return 0;

}