#pragma once
#include <string>
using namespace std;
class AccidentData
{
private:
	string sido;
	string sigungu;
	int datas[11];
public:
	AccidentData(string sido, string sigungu, int _data[11]);
	string Getsido();
	string Getsigungu();
	int* Getdatas();
};

