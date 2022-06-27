#include <iostream>
#include <sstream> // 스트링 형태의 문자열에 접근
#include <fstream> // 파일 접근
#include <string>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("example.csv"); // 지정한 경로에서 해당 파일을 연다. 파일이 없다면 생성부터해준다.
	myfile << "a,b,c\n";// 파일에 문자열을 입력한다.
	myfile << "c,s,v\n";
	myfile << "1,2,3,456\n";
	myfile.close();	// 파일을 저장한다.


	ifstream  data("example.csv");
	string line; // 스트링 변수 생성
	while (std::getline(data, line)) // data 파일에서 읽은 자료를 line에 초기화 한다.
	{
		stringstream lineStream(line);
		string cell;
		while (std::getline(lineStream, cell, ','))
		{
			cout << cell << "**" << endl;
		}
	}
	
	return 0;

}