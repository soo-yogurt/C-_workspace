#include <iostream>
#include <sstream> 
#include <fstream> 
#include <string>
#include <cstdint>
#include "AccidentData.h"
#include "DataHandler.h"

using namespace std;

int main(void)
{
	char flag = '0';
	DataHandler handler;
	while(true) {
		if (flag == '0') {
			flag = handler.PrintMenu();
		}
		if(flag == '1') {
			handler.DisplayNum_1();
			handler.ButtonEsc();
			flag = '0';
		}
		if (flag == '2') {
			handler.DisplayNum_2();
			handler.ButtonEsc();
			flag = '0';
		}
		if (flag == '3') {
			handler.DisplayNum_3();
			handler.ButtonEsc();
			flag = '0';
		}
	}



	return 0;

}