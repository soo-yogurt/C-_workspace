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
	int* Getdatas(); // 배열을 반환하기 위해서 포인트형 인트를 사용하였다.
};

