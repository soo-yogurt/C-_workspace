#include <iostream>
#include <sstream> 
#include <fstream> 
#include <string>
#include <cstdint>
#include <windows.h>
#include "AccidentData.h"
#include "DataHandler.h"

using namespace std;

int main(void)
{
	char flag = '0';
	DataHandler handler;
	while(true) {
		if (flag == '0') {
			system("cls");
			flag = handler.PrintMenu();
		}
		if(flag == '1') {
			handler.DisplayNum_1();
			Sleep(1500);
		}
		if (flag == '2') {
			handler.DisplayNum_2();
			Sleep(1500);
		}
		if (flag == '3') {
			handler.DisplayNum_3();
			Sleep(1500);
		}
		flag = '0';
	}
	return 0;
}