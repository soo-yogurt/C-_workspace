#include <iostream>
#include <sstream> // ��Ʈ�� ������ ���ڿ��� ����
#include <fstream> // ���� ����
#include <string>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("example.csv"); // ������ ��ο��� �ش� ������ ����. ������ ���ٸ� �����������ش�.
	myfile << "a,b,c\n";// ���Ͽ� ���ڿ��� �Է��Ѵ�.
	myfile << "c,s,v\n";
	myfile << "1,2,3,456\n";
	myfile.close();	// ������ �����Ѵ�.


	ifstream  data("example.csv");
	string line; // ��Ʈ�� ���� ����
	while (std::getline(data, line)) // data ���Ͽ��� ���� �ڷḦ line�� �ʱ�ȭ �Ѵ�.
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