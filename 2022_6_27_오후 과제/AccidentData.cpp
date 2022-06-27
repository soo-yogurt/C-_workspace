#include "AccidentData.h"

AccidentData::AccidentData(string _sido, string _sigungu, int _data[11])
{
	sido = _sido;
	sigungu = _sigungu;
	for (int i = 0; i < 11; i++)
	{
		datas[i] = _data[i];
	}
}
string AccidentData::Getsido()
{
	return sido;
}
string AccidentData::Getsigungu()
{
	return sigungu;
}
int* AccidentData::Getdatas()
{
	return datas;
}
